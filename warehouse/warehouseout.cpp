#include "warehouseout.h"
#include "ui_warehouseout.h"

#include <QDebug>
#include <QSettings>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QScroller>
#include <QCompleter>
#include <QMessageBox>
#include <QFileDialog>
#include <QListView>
#include <QAbstractItemView>
#include <QItemSelectionModel>
#include <QStyledItemDelegate>
#include "xlsxchart.h"
#include "xlsxworkbook.h"
#include "xlsxdocument.h"
#include "xlsxcellrange.h"
#include "xlsxrichstring.h"
#include "xlsxchartsheet.h"

// 常量定义
namespace {
const QString STYLE_SHEET =
    "QAbstractItemView{font: 18pt \"微软雅黑\";background-color:rgb(255,255,255);color:rgb(0,0,0);}"
    "QAbstractItemView::item:hover{background-color:rgb(0, 120, 212)}";
const QString TIME_FORMAT = "yyyy-MM-dd HH:mm:ss";
const QString PART_CHONYA = "chonya_message";
const QString PART_CHENGXING = "chengxing_message";
const QString DEPT_CHONYA = "冲压";
const QString DEPT_CHENGXING = "成型";
const int EXPORT_START_ROW = 4;
const int EXPORT_COLUMN_COUNT = 8;
}

WarehouseOut::WarehouseOut(QVariant part_value, QVariant mold_value, QVariant spare_value, QVariant cabinet_value,
    QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WarehouseOut)
    , model(nullptr)
    , itemDelegate(new QStyledItemDelegate(this)) {
    ui->setupUi(this);
    // 初始化滚动视图
    QListView *listView1 = qobject_cast<QListView *>(ui->MoldCombo->view());
    if(listView1) {
        QScroller *scroller1 = QScroller::scroller(listView1);
        scroller1->grabGesture(listView1->viewport(), QScroller::LeftMouseButtonGesture);
        listView1->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    }
    QScroller *pScroller = QScroller::scroller(ui->SpareView);
    pScroller->grabGesture(ui->SpareView->viewport(), QScroller::LeftMouseButtonGesture);
    ui->SpareView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    // 初始化Excel格式
    Song12CB.setFontSize(12);
    Song12CB.setFontName("宋体");
    Song12CB.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    Song12CB.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    Song12CB.setBorderStyle(QXlsx::Format::BorderThin);
    // 初始化UI
    ui->ExportButton->setText("导出\n记录");
    part = part_value.toString();
    mold = mold_value.toString();
    // 设置初始状态
    if(part == PART_CHENGXING) {
        ui->ChangeButton->setChecked(true);
        ui->ChangeButton->setText("切换为冲压备件");
        ui->Label3->setText("选择成型备件⬋");
    } else {
        ui->Label3->setText("选择冲压备件⬋");
    }
    spare = spare_value.toString();
    // 加载模具数据
    QString sql = QString("select 模具编号 from %1 order by 模具编号 asc;").arg(part);
    ui->MoldCombo->blockSignals(true);
    QStringList data = fetchData(sql);
    ui->MoldCombo->addItems(data);
    setupCompleter(data);
    ui->MoldCombo->setCurrentText(mold);
    ui->MoldCombo->blockSignals(false);
    // 查找并显示备件
    Find_ID(ui->MoldCombo->currentText());
    // 设置初始时间
    QDateTime dateTime = QDateTime::currentDateTime();
    ui->OutTime->setText(dateTime.toString(TIME_FORMAT));
    // 选择初始备件
    QAbstractItemModel *viewModel = ui->SpareView->model();
    if(viewModel) {
        QModelIndexList matches = viewModel->match(viewModel->index(0, 0), Qt::DisplayRole, spare, 1, Qt::MatchExactly);
        if(!matches.isEmpty()) {
            QModelIndex index = matches.first();
            ui->SpareView->selectionModel()->select(index, QItemSelectionModel::ClearAndSelect | QItemSelectionModel::Rows);
            ui->SpareView->scrollTo(index);
        }
    }
    // 设置标签样式
    if(spare.isEmpty()) {
        ui->Label3->setStyleSheet("color:red;");
    } else {
        ui->Label3->setStyleSheet("color:black;");
    }
    // 加载备件信息
    updateSpareInfo(mold, spare, cabinet_value.toString());
    ui->OutTime->installEventFilter(this);
}

WarehouseOut::~WarehouseOut() {
    delete ui;
}

QStringList WarehouseOut::fetchData(const QString &query) const {
    QStringList results;
    QSqlQuery sqlQuery;
    if(!sqlQuery.exec(query)) {
        return results;
    }
    while(sqlQuery.next()) {
        QString value = sqlQuery.value(0).toString();
        if(results.contains(value)) {
            continue;
        }
        int index = ui->MoldCombo->findText(value);
        if(index == -1) {
            results.append(value);
        }
    }
    return results;
}

void WarehouseOut::Find_ID(const QString &value) {
    // 删除旧的模型
    if(model) {
        model->deleteLater();
    }
    model = new QStandardItemModel(this);
    QSqlQuery query;
    query.prepare(QString("select 备件号 from %1 where 模具编号 = :mold_id;").arg(part));
    query.bindValue(":mold_id", value);
    if(!query.exec()) {
        return;
    }
    while(query.next()) {
        QStandardItem *item = new QStandardItem(query.value("备件号").toString());
        model->appendRow(item);
    }
    ui->SpareView->setModel(model);
}

void WarehouseOut::setupCompleter(const QStringList &data) {
    QCompleter *moldCompleter = new QCompleter(data, this);
    moldCompleter->setMaxVisibleItems(10);
    moldCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    moldCompleter->setCompletionMode(QCompleter::PopupCompletion);
    moldCompleter->setFilterMode(Qt::MatchContains);
    ui->MoldCombo->setCompleter(moldCompleter);
    moldCompleter->popup()->setItemDelegate(itemDelegate);
    moldCompleter->popup()->setStyleSheet(STYLE_SHEET);
}

void WarehouseOut::updateSpareInfo(const QString &moldId, const QString &spareId, const QString &cabinet) {
    QSqlQuery query;
    query.prepare(
        QString("select * from %1 where 模具编号 = :mold and 备件号 = :spare and 存放柜号 = :cabinet").arg(part));
    query.bindValue(":mold", moldId);
    query.bindValue(":spare", spareId);
    query.bindValue(":cabinet", cabinet);
    if(!query.exec()) {
        QMessageBox::warning(this, "界面初始化", "模具数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        ui->SpareEdit->setText(spareId);
        ui->TotalNum->setText(query.value("总库存量").toString());
        ui->SaveNum->setText(query.value("安全库存").toString());
        ui->CabinetEdit->setText(query.value("存放柜号").toString());
    }
}

void WarehouseOut::on_MoldCombo_currentIndexChanged(const QString &arg1) {
    Find_ID(arg1);
    ui->SpareEdit->clear();
    ui->TotalNum->clear();
    ui->SaveNum->clear();
    ui->CabinetEdit->clear();
    ui->OutNum->setValue(1);
    spare.clear();
    ui->Label3->setStyleSheet("color:red;");
}

void WarehouseOut::on_SpareView_clicked(const QModelIndex &index) {
    mold = ui->MoldCombo->currentText();
    spare = index.data().toString();
    int sameCount = 0;
    int currentRow = 0;
    for(int row = 0; row < model->rowCount(); ++row) {
        QModelIndex currentIndex = model->index(row, 0);
        if(model->data(currentIndex).toString() == spare) {
            sameCount++;
            if(currentIndex.row() == index.row()) {
                currentRow = sameCount - 1;
            }
        }
    }
    QSqlQuery query;
    query.prepare(
        QString("select * from %1 where 模具编号 = :mold and 备件号 = :spare  order by id asc limit 1 offset %2").arg(
        part).arg(currentRow));
    query.bindValue(":mold", mold);
    query.bindValue(":spare", spare);
    if(!query.exec()) {
        QMessageBox::warning(this, "查询备件数据", "备件数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        ui->SpareEdit->setText(spare);
        ui->TotalNum->setText(query.value("总库存量").toString());
        ui->SaveNum->setText(query.value("安全库存").toString());
        ui->CabinetEdit->setText(query.value("存放柜号").toString());
        ui->Label3->setStyleSheet("color:black;");
    }
}

bool WarehouseOut::validateOutInput() {
    if(spare.isEmpty()) {
        QMessageBox::warning(this, "出库备件", "请选择备件", QMessageBox::Cancel);
        return false;
    }
    int outNum = ui->OutNum->value();
    if(outNum <= 0) {
        QMessageBox::warning(this, "出库备件", "出库数量必须大于0", QMessageBox::Cancel);
        return false;
    }
    int totalNum = ui->TotalNum->text().toInt();
    if(outNum > totalNum) {
        QMessageBox::warning(this, "出库备件", QString("出库数量不能超过总库存量（%1）").arg(totalNum),
            QMessageBox::Cancel);
        return false;
    }
    return true;
}

bool WarehouseOut::querySpareData(int &totalNum, int &enterNum, int &outNum) {
    QSqlQuery query;
    QString sql =
        QString("select 总库存量,累计入库,累计出库 from %1 where 模具编号 = :mold and 备件号 = :spare and 存放柜号 = :cabinet;").arg(
        part);
    query.prepare(sql);
    query.bindValue(":mold", mold);
    query.bindValue(":spare", spare);
    query.bindValue(":cabinet", ui->CabinetEdit->text());
    if(!query.exec()) {
        QMessageBox::warning(this, "出库备件", "备件数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    if(!query.next()) {
        QMessageBox::warning(this, "出库备件", "备件数据查询失败：未找到匹配的记录", QMessageBox::Cancel);
        return false;
    }
    totalNum = query.value("总库存量").toInt();
    enterNum = query.value("累计入库").toInt();
    outNum = query.value("累计出库").toInt();
    return true;
}

bool WarehouseOut::updateSpareInventory(int totalNum, int enterNum, int outNum) {
    QSqlQuery query;
    QString sql =
        QString("update %1 set 状态 = :status,总库存量 = :total_num,累计出库 = :out_num,出库时间 = :out_time where 模具编号 = :mold and 备件号 = :spare_id;").arg(
        part);
    query.prepare(sql);
    query.bindValue(":status", QString("入库：%1    出库：%2").arg(enterNum).arg(outNum + ui->OutNum->value()));
    query.bindValue(":total_num", totalNum - ui->OutNum->value());
    query.bindValue(":out_num", outNum + ui->OutNum->value());
    query.bindValue(":out_time", ui->OutTime->text());
    query.bindValue(":mold", mold);
    query.bindValue(":spare_id", spare);
    if(!query.exec()) {
        QMessageBox::warning(this, "出库备件", "备件数据更新失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    return true;
}

bool WarehouseOut::insertOutRecord(int outNum) {
    QSqlQuery query;
    QString sql =
        "insert into out_message (模具编号,备件号,出库数量,存放柜号,出库时间,隶属部门) values (:mold_id, :spare_id, :out_num, :cabinet, :out_time, :part);";
    query.prepare(sql);
    query.bindValue(":mold_id", mold);
    query.bindValue(":spare_id", spare);
    query.bindValue(":out_num", QString::number(outNum));
    query.bindValue(":cabinet", ui->CabinetEdit->text());
    query.bindValue(":out_time", ui->OutTime->text());
    QString dept = (part == PART_CHONYA) ? DEPT_CHONYA : DEPT_CHENGXING;
    query.bindValue(":part", dept);
    if(!query.exec()) {
        QMessageBox::warning(this, "出库备件", "备件出库数据添加失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    return true;
}

void WarehouseOut::insertLowStockWarning(int remainingNum) {
    QSqlQuery query;
    query.prepare("insert into information_message (日期,模具编号,备件号,发送用户,接收用户,完成情况,信息) select :date, :mold_id, :spare_id, :tuser, :ruser, :finished, :information where not exists (select 1 from information_message where 模具编号 = :mold_id and 备件号 = :spare_id and 接收用户 = :ruser)");
    QDateTime dateTime = QDateTime::currentDateTime();
    query.bindValue(":date", dateTime.toString(TIME_FORMAT));
    query.bindValue(":mold_id", ui->MoldCombo->currentText());
    query.bindValue(":spare_id", ui->SpareEdit->text());
    query.bindValue(":tuser", "系统");
    query.bindValue(":ruser", "所有人");
    query.bindValue(":finished", "1");
    QString dept = (part == PART_CHONYA) ? DEPT_CHONYA : DEPT_CHENGXING;
    int saveNum = ui->SaveNum->text().toInt();
    query.bindValue(":information", QString("备件剩余%1个，低于安全库存%2个，需要补货（%3）。").arg(
        remainingNum).arg(saveNum).arg(dept));
    if(!query.exec()) {
        QMessageBox::warning(this, "出库备件", "补货信息列表插入失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
    }
}

void WarehouseOut::showOutSuccess(int remainingNum) {
    QMessageBox::information(this, "出库备件", "备件出库成功", QMessageBox::Ok);
    ui->TotalNum->setText(QString::number(remainingNum));
    emit mysignal();
}

void WarehouseOut::on_OutButton_clicked() {
    // 验证输入
    if(!validateOutInput()) {
        return;
    }
    // 查询备件数据
    int totalNum = 0, enterNum = 0, outNum = 0;
    if(!querySpareData(totalNum, enterNum, outNum)) {
        return;
    }
    // 更新库存
    if(!updateSpareInventory(totalNum, enterNum, outNum)) {
        return;
    }
    // 插入出库记录
    int outValue = ui->OutNum->value();
    if(!insertOutRecord(outValue)) {
        return;
    }
    // 计算剩余数量
    int remainingNum = totalNum - outValue;
    int saveNum = ui->SaveNum->text().toInt();
    // 检查是否需要补货警告
    if(remainingNum < saveNum && saveNum > 0) {
        insertLowStockWarning(remainingNum);
    }
    // 显示成功消息
    showOutSuccess(remainingNum);
}

void WarehouseOut::on_ChangeButton_toggled(bool checked) {
    if(checked) {
        part = PART_CHENGXING;
        ui->Label3->setText("选择成型备件⬋");
        ui->ChangeButton->setText("切换为冲压备件");
    } else {
        part = PART_CHONYA;
        ui->Label3->setText("选择冲压备件⬋");
        ui->ChangeButton->setText("切换为成型备件");
    }
    ui->MoldCombo->clear();
    QString sql = QString("select 模具编号 from %1 order by 模具编号 asc;").arg(part);
    QStringList data = fetchData(sql);
    ui->MoldCombo->addItems(data);
    setupCompleter(data);
    Find_ID(ui->MoldCombo->currentText());
}

void WarehouseOut::on_ExportButton_clicked() {
    QSqlQuery query;
    QSettings config("userconfig.ini", QSettings::IniFormat);
    QXlsx::Document xlsx(":/ducument/out.xlsx");
    QString sql = "select * from out_message;";
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "导出出库记录", "出库数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    int row = EXPORT_START_ROW;
    while(query.next()) {
        xlsx.mergeCells(QString("F%1:G%1").arg(row), Song12CB);
        for(int i = 1; i < EXPORT_COLUMN_COUNT; i++) {
            int col = (i == 7) ? 8 : i;
            xlsx.write(row, col, query.value(i - 1).toString(), Song12CB);
        }
        row++;
    }
    QString fileName = QFileDialog::getSaveFileName(this, "导出出库记录",
            config.value("DOCUMENTCONFIG/DocumentPath").toString() + "模具备件出库记录表", "Excel Files (*.xlsx)");
    if(fileName.isEmpty()) {
        return;
    }
    QString file_temp = fileName.left(fileName.lastIndexOf('/')) + "/";
    config.setValue("DOCUMENTCONFIG/DocumentPath", file_temp);
    if(!fileName.endsWith(".xlsx")) {
        fileName.append(".xlsx");
    }
    if(!xlsx.saveAs(fileName)) {
        QMessageBox::critical(this, "导出出库记录", "模具备件出库记录表创建失败");
        return;
    }
    config.sync();
    QMessageBox::information(this, "导出出库记录", "模具备件出库记录表创建成功", QMessageBox::Ok);
}

bool WarehouseOut::eventFilter(QObject *obj, QEvent *event) {
    if(event->type() == QEvent::FocusIn) {
        if(obj == ui->OutTime) {
            QDateTime dateTime = QDateTime::currentDateTime();
            ui->OutTime->setText(dateTime.toString(TIME_FORMAT));
        }
        return true;
    }
    return QMainWindow::eventFilter(obj, event);
}

void WarehouseOut::on_ReturnButton_clicked() {
    this->close();
}
