#include "warehouseenter.h"
#include "ui_warehouseenter.h"
#include <QDebug>
#include <QSettings>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QScroller>
#include <QCompleter>
#include <QMessageBox>
#include <QFileDialog>
#include <QStyledItemDelegate>
#include <QListView>
#include <QAbstractItemView>
#include <QItemSelectionModel>
#include "xlsxdocument.h"

// 允许的表名白名单
static const QStringList ALLOWED_TABLE_NAMES = {"chonya_message", "chengxing_message", "cabinet_message", "mold_message", "enter_message", "information_message"};

WarehouseEnter::WarehouseEnter(QVariant part_value, QVariant mold_value, QVariant spare_value, QVariant cabinet_value,
    QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WarehouseEnter)
    , model(nullptr)
    , itemDelegate(new QStyledItemDelegate(this))
    , partvalue_(part_value)
    , moldvalue_(mold_value)
    , sparevalue_(spare_value)
    , cabinetvalue_(cabinet_value) {
    ui->setupUi(this);
    initializeUI();
    initializeScrollers();
    initializeFormat();
    initializeData();
    loadInitialData();
    ui->EnterTime->installEventFilter(this);
}

WarehouseEnter::~WarehouseEnter() {
    delete ui;
}

// ==================== 初始化方法 ====================

void WarehouseEnter::initializeUI() {
    ui->ExportButton->setText("导出\n记录");
    part = partvalue_.toString();
    if(part == "chengxing_message") {
        ui->ChangeButton->setChecked(true);
        ui->ChangeButton->setText("切换为冲压备件");
    }
    updateLabelText();
}

void WarehouseEnter::initializeScrollers() {
    QListView *moldListView = qobject_cast<QListView *>(ui->MoldCombo->view());
    if(moldListView) {
        setupScroller(moldListView);
    }
    QListView *cabinetListView = qobject_cast<QListView *>(ui->CabinetCombo->view());
    if(cabinetListView) {
        setupScroller(cabinetListView);
    }
    setupScroller(ui->SpareView);
}

void WarehouseEnter::initializeFormat() {
    Song12CB.setFontSize(12);
    Song12CB.setFontName("宋体");
    Song12CB.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    Song12CB.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    Song12CB.setBorderStyle(QXlsx::Format::BorderThin);
}

void WarehouseEnter::initializeData() {
    mold = moldvalue_.toString();
    QDateTime dateTime = QDateTime::currentDateTime();
    ui->EnterTime->setText(dateTime.toString("yyyy-MM-dd hh:mm:ss"));
    initializeCompleters();
    ui->MoldCombo->setCurrentText(mold);
    Find_ID(ui->MoldCombo->currentText());
    spare = sparevalue_.toString();
    updateLabelStyle();
    selectSpareInView();
}

void WarehouseEnter::loadInitialData() {
    if(!validateTableName(part)) {
        QMessageBox::warning(this, "界面初始化", "无效的表名", QMessageBox::Cancel);
        return;
    }
    QSqlQuery query;
    QString sql =
        buildSafeQuery("select * from %1 where 模具编号 = :mold and 备件号 = :spare and 存放柜号 = :cabinet", part);
    query.prepare(sql);
    query.bindValue(":mold", mold);
    query.bindValue(":spare", spare);
    query.bindValue(":cabinet", cabinetvalue_.toString());
    if(!query.exec()) {
        QMessageBox::warning(this, "界面初始化", "模具数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        ui->SpareEdit->setText(spare);
        ui->TotalNum->setText(query.value("总库存量").toString());
        ui->SaveNum->setText(query.value("安全库存").toString());
        ui->CabinetCombo->setCurrentText(query.value("存放柜号").toString());
    }
}

void WarehouseEnter::initializeCompleters() {
    if(!validateTableName(part)) {
        return;
    }
    QString sql = buildSafeQuery("select 模具编号 from %1 order by 模具编号 asc", part);
    ui->MoldCombo->blockSignals(true);
    QStringList moldData = fetchData(sql);
    ui->MoldCombo->addItems(moldData);
    ui->MoldCombo->blockSignals(false);
    setupCompleter(ui->MoldCombo, moldData);
    QStringList cabinetData = fetchData("select 货柜名称 from cabinet_message order by 货柜名称 asc");
    ui->CabinetCombo->addItems(cabinetData);
    setupCompleter(ui->CabinetCombo, cabinetData);
}

// ==================== 辅助方法 ====================

void WarehouseEnter::setupScroller(QAbstractItemView *view) {
    if(!view) {
        return;
    }
    QScroller *scroller = QScroller::scroller(view);
    if(scroller) {
        scroller->grabGesture(view->viewport(), QScroller::LeftMouseButtonGesture);
        view->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    }
}

void WarehouseEnter::setupCompleter(QComboBox *comboBox, const QStringList &data) {
    if(!comboBox) {
        return;
    }
    QCompleter *completer = new QCompleter(data, this);
    completer->setMaxVisibleItems(10);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setCompletionMode(QCompleter::PopupCompletion);
    completer->setFilterMode(Qt::MatchContains);
    comboBox->setCompleter(completer);
    static const QString style =
        "QAbstractItemView{font: 18pt \"微软雅黑\";background-color:rgb(255,255,255);color:rgb(0,0,0);}"
        "QAbstractItemView::item:hover{background-color:rgb(0, 120, 212)}";
    completer->popup()->setItemDelegate(itemDelegate);
    completer->popup()->setStyleSheet(style);
}

QStringList WarehouseEnter::fetchData(const QString &query) {
    QStringList results;
    QSqlQuery sqlQuery;
    if(!sqlQuery.exec(query)) {
        return results;
    }
    while(sqlQuery.next()) {
        QString value = sqlQuery.value(0).toString();
        if(!results.contains(value)) {
            results.append(value);
        }
    }
    return results;
}

void WarehouseEnter::Find_ID(const QString &value) {
    if(!validateTableName(part)) {
        return;
    }
    if(model) {
        model->clear();
    } else {
        model = new QStandardItemModel(this);
    }
    QSqlQuery query;
    QString sql = buildSafeQuery("select 备件号 from %1 where 模具编号 = :mold_id", part);
    query.prepare(sql);
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

bool WarehouseEnter::validateTableName(const QString &tableName) {
    return ALLOWED_TABLE_NAMES.contains(tableName);
}

QString WarehouseEnter::buildSafeQuery(const QString &baseQuery, const QString &tableName) {
    if(!validateTableName(tableName)) {
        return QString();
    }
    return baseQuery.arg(tableName);
}

void WarehouseEnter::updateLabelText() {
    if(part == "chonya_message") {
        ui->Label3->setText("选择冲压备件⬋");
    } else {
        ui->Label3->setText("选择成型备件⬋");
    }
}

void WarehouseEnter::updateLabelStyle() {
    if(spare.isEmpty()) {
        ui->Label3->setStyleSheet("color:red;");
    } else {
        ui->Label3->setStyleSheet("color:black;");
    }
}

void WarehouseEnter::selectSpareInView() {
    if(spare.isEmpty()) {
        return;
    }
    QAbstractItemModel *currentModel = ui->SpareView->model();
    if(!currentModel) {
        return;
    }
    QModelIndexList matches = currentModel->match(
            currentModel->index(0, 0),
            Qt::DisplayRole,
            spare,
            1,
            Qt::MatchExactly
        );
    if(!matches.isEmpty()) {
        QModelIndex index = matches.first();
        ui->SpareView->selectionModel()->select(index, QItemSelectionModel::ClearAndSelect | QItemSelectionModel::Rows);
        ui->SpareView->scrollTo(index);
    }
}

void WarehouseEnter::handleEnterSuccess(int newTotalNum) {
    ui->TotalNum->setText(QString::number(newTotalNum));
    QMessageBox::information(this, "备件入库", "备件入库成功", QMessageBox::Ok);
    emit mysignal();
}

QString WarehouseEnter::getDepartmentName() const {
    return (part == "chonya_message") ? "冲压" : "成型";
}

// ==================== 槽函数 ====================

void WarehouseEnter::on_MoldCombo_currentIndexChanged(const QString &arg1) {
    Find_ID(arg1);
    ui->SpareEdit->clear();
    ui->TotalNum->clear();
    ui->SaveNum->clear();
    ui->CabinetCombo->setCurrentIndex(0);
    ui->EnterNum->setValue(1);
    spare.clear();
    ui->Label3->setStyleSheet("color:red;");
}

void WarehouseEnter::on_SpareView_clicked(const QModelIndex &index) {
    if(!model || !index.isValid()) {
        return;
    }
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
    if(!validateTableName(part)) {
        return;
    }
    QSqlQuery query;
    QString sql =
        buildSafeQuery("select * from %1 where 模具编号 = :mold and 备件号 = :spare order by id asc limit 1 offset %2",
            part);
    sql = sql.arg(currentRow);
    query.prepare(sql);
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
        ui->CabinetCombo->setCurrentText(query.value("存放柜号").toString());
        ui->Label3->setStyleSheet("color:black;");
    }
}

void WarehouseEnter::on_EnterButton_clicked() {
    if(spare.isEmpty()) {
        QMessageBox::warning(this, "备件入库", "请选择备件", QMessageBox::Cancel);
        return;
    }
    if(!ui->EnterNum->value()) {
        QMessageBox::warning(this, "备件入库", "请输入入库数量", QMessageBox::Cancel);
        return;
    }
    if(!validateTableName(part)) {
        QMessageBox::warning(this, "备件入库", "无效的表名", QMessageBox::Cancel);
        return;
    }
    QSqlQuery query;
    QString sql =
        buildSafeQuery("select 总库存量,累计入库,累计出库,存放柜号 from %1 where 模具编号 = :mold and 备件号 = :spare and 存放柜号 = :cabinet",
            part);
    query.prepare(sql);
    query.bindValue(":mold", mold);
    query.bindValue(":spare", spare);
    query.bindValue(":cabinet", ui->CabinetCombo->currentText());
    if(!query.exec()) {
        QMessageBox::warning(this, "备件入库", "备件数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        // 更新现有记录
        int totalNum = query.value("总库存量").toInt();
        int enterNum = query.value("累计入库").toInt();
        int outNum = query.value("累计出库").toInt();
        int newEnterNum = enterNum + ui->EnterNum->value();
        int newTotalNum = totalNum + ui->EnterNum->value();
        sql = buildSafeQuery("update %1 set 状态 = :status,总库存量 = :total_num,累计入库 = :enter_num,入库时间 = :enter_time where 模具编号 = :mold and 备件号 = :spare_id and 存放柜号 = :cabinet",
                part);
        query.prepare(sql);
        query.bindValue(":status", QString("入库：%1    出库：%2").arg(newEnterNum).arg(outNum));
        query.bindValue(":total_num", newTotalNum);
        query.bindValue(":enter_num", newEnterNum);
        query.bindValue(":enter_time", ui->EnterTime->text());
        query.bindValue(":mold", mold);
        query.bindValue(":spare_id", spare);
        query.bindValue(":cabinet", ui->CabinetCombo->currentText());
        if(!query.exec()) {
            QMessageBox::warning(this, "备件入库", "备件数据更新失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        }
        // 插入入库记录
        sql = "insert into enter_message (模具编号,备件号,入库数量,存放柜号,入库时间,隶属部门) values (:mold_id, :spare_id, :enter_num, :cabinet, :enter_time, :part)";
        query.prepare(sql);
        query.bindValue(":mold_id", mold);
        query.bindValue(":spare_id", spare);
        query.bindValue(":enter_num", ui->EnterNum->text());
        query.bindValue(":cabinet", ui->CabinetCombo->currentText());
        query.bindValue(":enter_time", ui->EnterTime->text());
        query.bindValue(":part", getDepartmentName());
        if(!query.exec()) {
            QMessageBox::warning(this, "备件入库", "入库数据插入失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        }
        // 如果库存达到安全库存，删除信息表中的记录
        if(newTotalNum >= ui->SaveNum->text().toInt()) {
            sql = "delete from information_message where 模具编号 = :mold_id and 备件号 = :spare_id";
            query.prepare(sql);
            query.bindValue(":mold_id", mold);
            query.bindValue(":spare_id", spare);
            if(!query.exec()) {
                QMessageBox::warning(this, "备件入库", "备件列表数据删除失败：\n" + query.lastError().text(),
                    QMessageBox::Cancel);
                return;
            }
        }
        handleEnterSuccess(newTotalNum);
    } else {
        // 插入新记录
        if(ui->SpareEdit->text().isEmpty()) {
            QMessageBox::warning(this, "备件入库", "请选择备件", QMessageBox::Cancel);
            return;
        }
        QString pid;
        QSqlQuery pidQuery;
        QString pidSql = QString("select PID from mold_message where 模具编号 = :mold_id");
        pidQuery.prepare(pidSql);
        pidQuery.bindValue(":mold_id", ui->MoldCombo->currentText());
        if(!pidQuery.exec()) {
            QMessageBox::warning(this, "备件入库", "模具PID查询失败：\n" + pidQuery.lastError().text(),
                QMessageBox::Cancel);
            return;
        }
        if(pidQuery.next()) {
            pid = pidQuery.value(0).toString();
        }
        sql = buildSafeQuery("insert into %1 (PID,模具编号,备件号,状态,安全库存,期初库存,总库存量,累计入库,累计出库,存放柜号) select :pid,:mold_id,:spare_id,'入库：0    出库：0',:save_num,'0','0','0','0',:cabinet where not exists (select 1 from chonya_message where 模具编号 = :mold_id and 备件号 = :spare_id and 存放柜号 = :cabinet)",
            part);
        query.prepare(sql);
        query.bindValue(":pid", pid);
        query.bindValue(":mold_id", ui->MoldCombo->currentText());
        query.bindValue(":spare_id", ui->SpareEdit->text());
        query.bindValue(":save_num", "0");
        query.bindValue(":cabinet", ui->CabinetCombo->currentText());
        if(!query.exec()) {
            QMessageBox::warning(this, "备件入库", "备件数据插入失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        }
        QMessageBox::information(this, "备件入库", "入库成功", QMessageBox::Ok);
        emit mysignal();
    }
}

void WarehouseEnter::on_ChangeButton_toggled(bool checked) {
    if(checked) {
        part = "chengxing_message";
        ui->Label3->setText("选择成型备件⬋");
        ui->ChangeButton->setText("切换为冲压备件");
    } else {
        part = "chonya_message";
        ui->Label3->setText("选择冲压备件⬋");
        ui->ChangeButton->setText("切换为成型备件");
    }
    ui->MoldCombo->clear();
    if(!validateTableName(part)) {
        return;
    }
    QString sql = buildSafeQuery("select 模具编号 from %1 order by 模具编号 asc", part);
    QStringList data = fetchData(sql);
    ui->MoldCombo->addItems(data);
    setupCompleter(ui->MoldCombo, data);
    Find_ID(ui->MoldCombo->currentText());
}

void WarehouseEnter::on_ExportButton_clicked() {
    const int START_ROW = 4;
    const int COLUMN_COUNT = 8;
    QSqlQuery query;
    QString fileName;
    QSettings config("userconfig.ini", QSettings::IniFormat);
    QXlsx::Document xlsx(":/ducument/enter.xlsx");
    QString sql = "select * from enter_message";
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "导出入库记录", "入库数据查找失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    int row = START_ROW;
    while(query.next()) {
        xlsx.mergeCells(QString("F%1:G%1").arg(row), Song12CB);
        for(int i = 1; i < COLUMN_COUNT; i++) {
            int column = (i == 7) ? 8 : i;
            xlsx.write(row, column, query.value(i - 1).toString(), Song12CB);
        }
        row++;
    }
    fileName = QFileDialog::getSaveFileName(
            this,
            "导出入库记录",
            config.value("DOCUMENTCONFIG/DocumentPath").toString() + "模具备件入库记录表",
            "Excel Files (*.xlsx)"
        );
    if(fileName.isEmpty()) {
        return;
    }
    QString filePath = fileName.left(fileName.lastIndexOf('/') + 1);
    config.setValue("DOCUMENTCONFIG/DocumentPath", filePath);
    if(!fileName.endsWith(".xlsx")) {
        fileName.append(".xlsx");
    }
    if(!xlsx.saveAs(fileName)) {
        QMessageBox::critical(this, "导出入库记录", "模具备件入库记录表创建失败：");
        return;
    }
    config.sync();
    QMessageBox::information(this, "导出入库记录", "入库记录导出成功", QMessageBox::Ok);
}

bool WarehouseEnter::eventFilter(QObject *obj, QEvent *event) {
    if(event->type() == QEvent::FocusIn && obj == ui->EnterTime) {
        QDateTime dateTime = QDateTime::currentDateTime();
        ui->EnterTime->setText(dateTime.toString("yyyy-MM-dd hh:mm:ss"));
        return true;
    }
    return QMainWindow::eventFilter(obj, event);
}

void WarehouseEnter::on_ReturnButton_clicked() {
    close();
}
