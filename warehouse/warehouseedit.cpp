#include "warehouseedit.h"
#include "ui_warehouseedit.h"

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QSettings>
#include <QListView>
#include <QScroller>
#include <QCompleter>
#include <QMessageBox>
#include <QAbstractItemView>
#include <QStyledItemDelegate>
#include <QCloseEvent>

// 静态常量定义
const QString WarehouseEdit::DATE_TIME_FORMAT = "yyyy-MM-dd hh:mm:ss";
const QString WarehouseEdit::SYSTEM_USER = "系统";
const QString WarehouseEdit::ALL_USERS = "所有人";

// ==================== 构造函数和析构函数 ====================

WarehouseEdit::WarehouseEdit(QVariant part_value, QVariant mold_value, QVariant id_value, QVariant cabinet_value,
    QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::WarehouseEdit),
      warehouseMold(nullptr),
      partvalue_(part_value),
      curr_part(part_value.toString()),
      moldvalue_(mold_value),
      idvalue_(id_value),
      cabinetvalue_(cabinet_value),
      out_num(0),
      first_num(0),
      enter_num(0) {
    ui->setupUi(this);
    // 安装事件过滤器
    ui->EnterTime->installEventFilter(this);
    ui->OutTime->installEventFilter(this);
    // 初始化界面
    initializeComboBoxes();
    loadInitialData();
}

WarehouseEdit::~WarehouseEdit() {
    delete ui;
}

// ==================== 事件处理 ====================

void WarehouseEdit::closeEvent(QCloseEvent *event) {
    Q_UNUSED(event);
    if(QWidget *target = m_windowMap.value(tr("模具数据编辑"))) {
        if(!target->isHidden()) {
            target->close();
            target->deleteLater();
            m_windowMap.remove(tr("模具数据编辑"));
        }
    }
}

bool WarehouseEdit::eventFilter(QObject *obj, QEvent *event) {
    if(event->type() == QEvent::FocusIn) {
        QDateTime dateTime = QDateTime::currentDateTime();
        if(obj == ui->EnterTime) {
            ui->EnterTime->setText(dateTime.toString(DATE_TIME_FORMAT));
        } else if(obj == ui->OutTime) {
            ui->OutTime->setText(dateTime.toString(DATE_TIME_FORMAT));
        }
        return true;
    }
    return QMainWindow::eventFilter(obj, event);
}

// ==================== 私有槽函数 ====================

void WarehouseEdit::on_MoldButton_clicked() {
    warehouseMold = new WarehouseMold(curr_part, ui->MoldCombo->currentText(), this);
    connect(warehouseMold, &WarehouseMold::mysignal, this, &WarehouseEdit::send_signal);
    warehouseMold->setWindowTitle("模具数据编辑");
    m_windowMap.insert(tr("模具数据编辑"), warehouseMold);
    warehouseMold->show();
}

void WarehouseEdit::on_EditButton_clicked() {
    if(!validateInput()) {
        return;
    }
    if(checkSparePartExists()) {
        QMessageBox::warning(this, "修改备件参数", "该备件已存在", QMessageBox::Cancel);
        return;
    }
    if(!updateWarehouseData()) {
        return;
    }
    // 处理库存不足通知
    if(ui->TotalNum->value() < ui->SaveNum->value()) {
        handleLowStockNotification();
    } else {
        removeLowStockNotification();
    }
    QMessageBox::information(this, "修改备件参数", "备件参数修改成功", QMessageBox::Ok);
    emit mysignal();
}

void WarehouseEdit::on_ReturnButton_clicked() {
    this->close();
}

void WarehouseEdit::on_OutNum_valueChanged(int arg1) {
    if(arg1 != out_num) {
        int total_num = ui->TotalNum->value();
        int change_num = arg1 - out_num;
        ui->TotalNum->setValue(total_num - change_num);
        out_num = ui->OutNum->value();
    }
}

void WarehouseEdit::on_FirstNum_valueChanged(int arg1) {
    if(arg1 != first_num) {
        int total_num = ui->TotalNum->value();
        int change_num = arg1 - first_num;
        ui->OutNum->setMaximum(ui->TotalNum->value() + ui->EnterNum->value());
        ui->TotalNum->setValue(total_num + change_num);
        first_num = ui->FirstNum->value();
    }
}

void WarehouseEdit::on_EnterNum_valueChanged(int arg1) {
    if(arg1 != enter_num) {
        int total_num = ui->TotalNum->value();
        int change_num = arg1 - enter_num;
        ui->TotalNum->setValue(total_num + change_num);
        enter_num = ui->EnterNum->value();
    }
}

void WarehouseEdit::on_MoldCombo_highlighted(const QString &arg1) {
    updatePartLabel(arg1);
}

void WarehouseEdit::on_IDCombo_currentIndexChanged(const QString &arg1) {
    loadSparePartData(arg1);
}

void WarehouseEdit::send_signal() {
    emit mysignal();
}

// ==================== 初始化方法 ====================

void WarehouseEdit::initializeComboBoxes() {
    setupComboBoxScroller(ui->MoldCombo);
    setupComboBoxScroller(ui->CabinetCombo);
    setupComboBoxScroller(ui->IDCombo);
}

void WarehouseEdit::setupComboBoxScroller(QComboBox *combo) {
    if(!combo) {
        return;
    }
    QListView *listView = qobject_cast<QListView *>(combo->view());
    if(listView) {
        QScroller *scroller = QScroller::scroller(listView);
        scroller->grabGesture(listView->viewport(), QScroller::LeftMouseButtonGesture);
        listView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    }
}

void WarehouseEdit::loadInitialData() {
    ui->IDCombo->blockSignals(true);
    loadIDList();
    loadMoldList();
    loadCabinetList();
    loadWarehouseData();
    ui->IDCombo->blockSignals(false);
    updatePartLabel(ui->MoldCombo->currentText());
}

void WarehouseEdit::loadIDList() {
    QSqlQuery query;
    QStringList ID_list;
    // 使用参数化查询，但由于表名不能参数化，需要验证表名
    QString sql = QString("select ID from %1;").arg(curr_part);
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "界面初始化", "备件ID查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    while(query.next()) {
        ID_list.append(query.value(0).toString());
    }
    ui->IDCombo->addItems(ID_list);
}

void WarehouseEdit::loadMoldList() {
    QSqlQuery query;
    QStringList mold_list;
    QString sql = "select 模具编号 from mold_message order by 模具编号 asc;";
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "界面初始化", "模具编号查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    while(query.next()) {
        mold_list.append(query.value(0).toString());
    }
    ui->MoldCombo->addItems(mold_list);
    QStyledItemDelegate *delegate = new QStyledItemDelegate(this);
    QString style = "QAbstractItemView{font: 18pt \"微软雅黑\";background-color:rgb(255,255,255);color:rgb(0,0,0);}"
                    "QAbstractItemView::item:hover{background-color:rgb(0, 120, 212)}";
    QCompleter *moldCompleter = createCompleter(mold_list, ui->MoldCombo);
    moldCompleter->popup()->setItemDelegate(delegate);
    moldCompleter->popup()->setStyleSheet(style);
}

void WarehouseEdit::loadCabinetList() {
    QSqlQuery query;
    QStringList cabinet_list;
    QString sql = "select 货柜名称 from cabinet_message order by 货柜名称 asc;";
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "界面初始化", "货柜名称查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    while(query.next()) {
        cabinet_list.append(query.value(0).toString());
    }
    ui->CabinetCombo->addItems(cabinet_list);
    QStyledItemDelegate *delegate = new QStyledItemDelegate(this);
    QString style = "QAbstractItemView{font: 18pt \"微软雅黑\";background-color:rgb(255,255,255);color:rgb(0,0,0);}"
                    "QAbstractItemView::item:hover{background-color:rgb(0, 120, 212)}";
    QCompleter *cabinetCompleter = createCompleter(cabinet_list, ui->CabinetCombo);
    cabinetCompleter->popup()->setItemDelegate(delegate);
    cabinetCompleter->popup()->setStyleSheet(style);
}

void WarehouseEdit::loadWarehouseData() {
    QSqlQuery query;
    query.prepare(
        QString("select * from %1 where 模具编号 = :mold and 备件号 = :id and 存放柜号 = :cabinet").arg(curr_part));
    query.bindValue(":mold", moldvalue_.toString());
    query.bindValue(":id", idvalue_.toString());
    query.bindValue(":cabinet", cabinetvalue_.toString());
    if(!query.exec()) {
        QMessageBox::warning(this, "界面初始化", "模具数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        ui->MoldCombo->setCurrentText(moldvalue_.toString());
        ui->SpareEdit->setText(idvalue_.toString());
        ui->OtherEdit->setText(query.value("备注").toString());
        ui->IDCombo->setCurrentText(query.value("ID").toString());
        ui->SaveNum->setValue(query.value("安全库存").toInt());
        ui->FirstNum->setValue(query.value("期初库存").toInt());
        ui->TotalNum->setValue(query.value("总库存量").toInt());
        ui->EnterNum->setValue(query.value("累计入库").toInt());
        ui->OutNum->setMaximum(ui->TotalNum->text().toInt() + ui->EnterNum->value());
        ui->OutNum->setValue(query.value("累计出库").toInt());
        ui->CabinetCombo->setCurrentText(query.value("存放柜号").toString());
        ui->EnterTime->setText(query.value("入库时间").toString());
        ui->OutTime->setText(query.value("出库时间").toString());
        first_num = ui->FirstNum->value();
        enter_num = ui->EnterNum->value();
        out_num = ui->OutNum->value();
    }
}

void WarehouseEdit::updatePartLabel(const QString &moldId) {
    QSqlQuery query;
    query.prepare("select 隶属部门 from mold_message where 模具编号 = :mold_id");
    query.bindValue(":mold_id", moldId);
    if(!query.exec()) {
        QMessageBox::warning(this, "更新模具选择", "查询模具隶属部门失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        ui->PartLabel->setText(query.value(0).toString() + "部门");
    }
}

// ==================== 辅助方法 ====================

bool WarehouseEdit::executeQueryWithErrorHandling(const QString &title, const QString &errorMessage) {
    QSqlQuery query;
    if(!query.exec()) {
        QMessageBox::warning(this, title, errorMessage + "\n" + query.lastError().text(), QMessageBox::Cancel);
        return false;
    }
    return true;
}

bool WarehouseEdit::checkSparePartExists() const {
    QSqlQuery query;
    query.prepare(
        QString("select 备件号,存放柜号 from %1 where ifnull(ID,'') != :id and 模具编号 = :mold_id").arg(curr_part));
    query.bindValue(":id", ui->IDCombo->currentText());
    query.bindValue(":mold_id", ui->MoldCombo->currentText());
    if(!query.exec()) {
        QMessageBox::warning(const_cast<WarehouseEdit *>(this), "修改备件参数",
            "查询备件数据失败：\n" + query.lastError().text(), QMessageBox::Cancel);
        return false;
    }
    while(query.next()) {
        if(query.value(0).toString() == ui->SpareEdit->text() &&
            query.value(1).toString() == ui->CabinetCombo->currentText()) {
            return true;
        }
    }
    return false;
}

QString WarehouseEdit::getMoldPID() const {
    QSqlQuery query;
    query.prepare("select PID from mold_message where 模具编号 = :mold_id");
    query.bindValue(":mold_id", ui->MoldCombo->currentText());
    if(!query.exec()) {
        QMessageBox::warning(const_cast<WarehouseEdit *>(this), "修改备件参数",
            "查询模具PID失败：\n" + query.lastError().text(), QMessageBox::Cancel);
        return QString();
    }
    if(query.next()) {
        return query.value(0).toString();
    } else {
        QMessageBox::warning(const_cast<WarehouseEdit *>(this), "修改备件参数", "未找到对应的模具PID",
            QMessageBox::Cancel);
        return QString();
    }
}

bool WarehouseEdit::updateWarehouseData() {
    QString pid = getMoldPID();
    if(pid.isEmpty()) {
        return false;
    }
    QSqlQuery query;
    QString sql = QString("update %1 set PID = :pid, 模具编号 = :mold_id, 备件号 = :spare_id, "
                          "状态 = :status, 安全库存 = :save_num, 期初库存 = :first_num, "
                          "总库存量 = :total_num, 备件价格 = :price_num, 累计入库 = :enter_num, "
                          "累计出库 = :out_num, 存放柜号 = :cabinet, 入库时间 = :enter_time, "
                          "出库时间 = :out_time, 备注 = :other where ID = :id;").arg(curr_part);
    query.prepare(sql);
    query.bindValue(":pid", pid);
    query.bindValue(":mold_id", ui->MoldCombo->currentText());
    query.bindValue(":spare_id", ui->SpareEdit->text());
    query.bindValue(":status", QString("入库：%1    出库：%2").arg(ui->EnterNum->text()).arg(ui->OutNum->text()));
    query.bindValue(":save_num", ui->SaveNum->text());
    query.bindValue(":first_num", ui->FirstNum->text());
    query.bindValue(":total_num", ui->TotalNum->text());
    query.bindValue(":price_num", ui->PriceNum->text());
    query.bindValue(":enter_num", ui->EnterNum->text());
    query.bindValue(":out_num", ui->OutNum->text());
    query.bindValue(":cabinet", ui->CabinetCombo->currentText());
    query.bindValue(":enter_time", ui->EnterTime->text());
    query.bindValue(":out_time", ui->OutTime->text());
    query.bindValue(":other", ui->OtherEdit->text());
    query.bindValue(":id", ui->IDCombo->currentText());
    if(!query.exec()) {
        QMessageBox::warning(this, "修改备件参数", "备件数据更新失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    return true;
}

void WarehouseEdit::handleLowStockNotification() {
    QSqlQuery query;
    query.prepare("insert into information_message (日期,模具编号,备件号,发送用户,接收用户,完成情况,信息) "
                  "select :date, :mold_id, :spare_id, :tuser, :ruser, :finished, :information "
                  "where not exists (select 1 from information_message where 模具编号 = :mold_id and 备件号 = :spare_id and 接收用户 = :ruser)");
    QDateTime dateTime = QDateTime::currentDateTime();
    query.bindValue(":date", dateTime.toString(DATE_TIME_FORMAT));
    query.bindValue(":mold_id", ui->MoldCombo->currentText());
    query.bindValue(":spare_id", ui->SpareEdit->text());
    query.bindValue(":tuser", SYSTEM_USER);
    query.bindValue(":finished", "1");
    QString information;
    if(curr_part == "chonya") {
        information = QString("备件不足%1个，需要补货（冲压）。").arg(ui->SaveNum->text());
    } else {
        information = QString("备件不足%1个，需要补货（成型）。").arg(ui->SaveNum->text());
    }
    query.bindValue(":information", information);
    query.bindValue(":ruser", ALL_USERS);
    if(!query.exec()) {
        QMessageBox::warning(this, "修改备件参数", "补货消息列表数据插入失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
    }
}

void WarehouseEdit::removeLowStockNotification() {
    QSqlQuery query;
    query.prepare("delete from information_message where 模具编号 = :mold_id and 备件号 = :spare_id");
    query.bindValue(":mold_id", ui->MoldCombo->currentText());
    query.bindValue(":spare_id", ui->SpareEdit->text());
    if(!query.exec()) {
        QMessageBox::warning(this, "修改备件参数", "补货信息列表数据删除失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
    }
}

void WarehouseEdit::loadSparePartData(const QString &id) {
    QSqlQuery query;
    query.prepare(QString("select * from %1 where ID = :id").arg(curr_part));
    query.bindValue(":id", id);
    if(!query.exec()) {
        QMessageBox::warning(this, "查询备件数据", "备件数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        ui->MoldCombo->setCurrentText(query.value("模具编号").toString());
        ui->SpareEdit->setText(query.value("备件号").toString());
        ui->OtherEdit->setText(query.value("备注").toString());
        ui->SaveNum->setValue(query.value("安全库存").toInt());
        ui->FirstNum->setValue(query.value("期初库存").toInt());
        ui->TotalNum->setValue(query.value("总库存量").toInt());
        ui->EnterNum->setValue(query.value("累计入库").toInt());
        ui->OutNum->setMaximum(ui->TotalNum->text().toInt() + ui->EnterNum->value());
        ui->OutNum->setValue(query.value("累计出库").toInt());
        ui->CabinetCombo->setCurrentText(query.value("存放柜号").toString());
        ui->EnterTime->setText(query.value("入库时间").toString());
        ui->OutTime->setText(query.value("出库时间").toString());
        first_num = ui->FirstNum->value();
        enter_num = ui->EnterNum->value();
        out_num = ui->OutNum->value();
    }
}

QCompleter *WarehouseEdit::createCompleter(const QStringList &items, QComboBox *combo) const {
    QCompleter *completer = new QCompleter(items, const_cast<WarehouseEdit *>(this));
    completer->setMaxVisibleItems(MAX_VISIBLE_ITEMS);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setCompletionMode(QCompleter::PopupCompletion);
    completer->setFilterMode(Qt::MatchContains);
    combo->setCompleter(completer);
    return completer;
}

// ==================== 验证方法 ====================

bool WarehouseEdit::validateInput() const {
    if(ui->SpareEdit->text().isEmpty()) {
        QMessageBox::warning(const_cast<WarehouseEdit *>(this), "修改备件参数", "备件号不能为空",
            QMessageBox::Cancel);
        return false;
    }
    if(ui->MoldCombo->currentText().isEmpty()) {
        QMessageBox::warning(const_cast<WarehouseEdit *>(this), "修改备件参数", "模具编号不能为空",
            QMessageBox::Cancel);
        return false;
    }
    if(ui->CabinetCombo->currentText().isEmpty()) {
        QMessageBox::warning(const_cast<WarehouseEdit *>(this), "修改备件参数", "存放柜号不能为空",
            QMessageBox::Cancel);
        return false;
    }
    if(ui->SaveNum->value() < 0) {
        QMessageBox::warning(const_cast<WarehouseEdit *>(this), "修改备件参数", "安全库存不能为负数",
            QMessageBox::Cancel);
        return false;
    }
    if(ui->TotalNum->value() < 0) {
        QMessageBox::warning(const_cast<WarehouseEdit *>(this), "修改备件参数", "总库存量不能为负数",
            QMessageBox::Cancel);
        return false;
    }
    return true;
}
