#include "chonyaedit.h"
#include "ui_chonyaedit.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QListView>
#include <QScroller>
#include <QCompleter>
#include <QStyledItemDelegate>
#include <QMovie>
#include <QAbstractItemView>

// 错误消息常量
namespace {
const QString ERROR_TITLE_INIT = "界面初始化";
const QString ERROR_TITLE_EDIT = "修改模具参数";
const QString ERROR_TITLE_ADD_MACHINE = "添加机台";
const QString ERROR_TITLE_DELETE_MACHINE = "删除机台";
const QString ERROR_TITLE_DELETE_USER = "删除员工";

const QString ERROR_MSG_MOLD_DATA_QUERY = "模具数据查询失败：\n";
const QString ERROR_MSG_MOLD_MACHINE_QUERY = "模具机台查询失败：\n";
const QString ERROR_MSG_USER_NAME_QUERY = "用户姓名查询失败：\n";
const QString ERROR_MSG_MOLD_DATA_UPDATE = "模具数据更新失败：\n";
const QString ERROR_MSG_MOLD_MACHINE_UPDATE = "模具机台更新失败：\n";
const QString ERROR_MSG_USER_INFO_DELETE = "员工信息列表删除失败：\n";
const QString ERROR_MSG_USER_DELETE = "员工删除失败：\n";

const QString SUCCESS_MSG_MOLD_EDIT = "模具参数修改成功";
const QString SUCCESS_MSG_MACHINE_ADD = "机台添加成功";
const QString SUCCESS_MSG_MACHINE_DELETE = "机台删除成功";
const QString SUCCESS_MSG_USER_DELETE = "员工删除成功";

const QString WARNING_MSG_SELECT_MOLD = "请选择模具";
const QString WARNING_MSG_INPUT_OUT_NUM = "请输入产品出数，若没有设定，可设置为1 * 1";
const QString WARNING_MSG_INPUT_LIFE_NUM = "请输入模具寿命冲次数，若没有设定，可设置为0";
const QString WARNING_MSG_INPUT_MOLD_ID = "请输入模具编号";
const QString WARNING_MSG_MACHINE_EXISTS = "该机台已存在";
const QString WARNING_MSG_SELECT_USER = "请选择员工";

const QString FILTER_NULL = "NULL";
const QString FILTER_NAME = "俞増涛";
}

ChonyaEdit::ChonyaEdit(QVariant id_value, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ChonyaEdit), idvalue_(id_value) {
    ui->setupUi(this);
    curr_id = id_value.toString();
    // 设置列表视图滚动
    setupListViewScroller(qobject_cast<QListView *>(ui->MachineComb->view()));
    setupListViewScroller(qobject_cast<QListView *>(ui->NameComb->view()));
    // 加载数据
    loadMoldData();
    loadMachineList();
    loadUserNameList();
    // 设置加载动画
    QMovie *movie = new QMovie(":/images/machine_load.gif");
    movie->setParent(this);
    ui->LoadingLabel->setMovie(movie);
    movie->start();
}

ChonyaEdit::~ChonyaEdit() {
    delete ui;
}

// 私有辅助函数实现
void ChonyaEdit::setupListViewScroller(QListView *listView) {
    if(!listView)
        return;
    QScroller *scroller = QScroller::scroller(listView);
    scroller->grabGesture(listView->viewport(), QScroller::LeftMouseButtonGesture);
    listView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
}

bool ChonyaEdit::executeQuery(QSqlQuery &query, const QString &errorTitle, const QString &errorMessage) {
    if(!query.exec()) {
        QMessageBox::warning(this, errorTitle, errorMessage + query.lastError().text(), QMessageBox::Cancel);
        return false;
    }
    return true;
}

void ChonyaEdit::loadMoldData() {
    QSqlQuery query;
    QString sql = "SELECT * FROM type_message WHERE 模具编号 = :mold_id";
    query.prepare(sql);
    query.bindValue(":mold_id", curr_id);
    if(!executeQuery(query, ERROR_TITLE_INIT, ERROR_MSG_MOLD_DATA_QUERY))
        return;
    if(query.next()) {
        ui->MoldID->setText(query.value("模具编号").toString());
        ui->ProductName->setText(query.value("产品名称").toString());
        ui->ProductID->setText(query.value("产品料号").toString());
        ui->OutNum_1->setText(query.value("出数1").toString());
        ui->OutNum_2->setText(query.value("出数2").toString());
        ui->LifeNum->setText(query.value("模具寿命冲次数").toString());
        ui->ProductStand->setText(query.value("材料规格").toString());
        ui->ControlStand->setCurrentText(query.value("管制标准").toString());
        ui->MoldID->setSelection(0, 0);
        ui->ProductStand->setSelection(0, 0);
    }
}

void ChonyaEdit::loadMachineList() {
    QSqlQuery query;
    QString sql = "SELECT 机台 FROM type_message WHERE 模具编号 = :mold_id";
    query.prepare(sql);
    query.bindValue(":mold_id", curr_id);
    if(!executeQuery(query, ERROR_TITLE_INIT, ERROR_MSG_MOLD_MACHINE_QUERY))
        return;
    while(query.next()) {
        QString machineField = query.value(0).toString();
        QStringList machineList = machineField.split("#", Qt::SkipEmptyParts);
        for(const QString &machine : machineList) {
            if(!machine.isEmpty()) {
                ui->MachineComb->addItem("#" + machine);
            }
        }
    }
}

void ChonyaEdit::loadUserNameList() {
    QSqlQuery query;
    QString sql = "SELECT name FROM user_message";
    query.prepare(sql);
    if(!executeQuery(query, ERROR_TITLE_INIT, ERROR_MSG_USER_NAME_QUERY))
        return;
    QStringList nameList;
    while(query.next()) {
        QString name = query.value(0).toString();
        if(name != FILTER_NULL && name != FILTER_NAME) {
            nameList.append(name);
        }
    }
    ui->NameComb->addItems(nameList);
    setupNameCompleter(nameList);
}

void ChonyaEdit::setupNameCompleter(const QStringList &nameList) {
    QStyledItemDelegate *delegate = new QStyledItemDelegate(this);
    QString style = "QAbstractItemView{font: 18pt \"微软雅黑\";background-color:rgb(255,255,255);color:rgb(0,0,0);}"
                    "QAbstractItemView::item:hover{background-color:rgb(0, 120, 212)}";
    QCompleter *completer = new QCompleter(nameList, this);
    completer->setMaxVisibleItems(10);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setCompletionMode(QCompleter::PopupCompletion);
    completer->setFilterMode(Qt::MatchContains);
    ui->NameComb->setCompleter(completer);
    completer->popup()->setItemDelegate(delegate);
    completer->popup()->setStyleSheet(style);
}

void ChonyaEdit::addMachine(const QString &machineNum) {
    if(curr_id.isEmpty()) {
        QMessageBox::warning(this, ERROR_TITLE_ADD_MACHINE, WARNING_MSG_SELECT_MOLD, QMessageBox::Cancel);
        return;
    }
    QString normalizedMachine = "#" + QString(machineNum).replace("#", "");
    // 检查机台是否已存在
    for(int i = 0; i < ui->MachineComb->count(); ++i) {
        if(ui->MachineComb->itemText(i) == normalizedMachine) {
            QMessageBox::warning(this, ERROR_TITLE_ADD_MACHINE, WARNING_MSG_MACHINE_EXISTS, QMessageBox::Cancel);
            return;
        }
    }
    // 使用QStringList提高字符串拼接效率
    QStringList machineList;
    for(int i = 0; i < ui->MachineComb->count(); ++i) {
        machineList.append(ui->MachineComb->itemText(i));
    }
    machineList.append(normalizedMachine);
    QString dataMachine = machineList.join("");
    // 更新数据库
    QSqlQuery query;
    QString sql = "UPDATE type_message SET 机台 = :data_machine WHERE 模具编号 = :mold_id";
    query.prepare(sql);
    query.bindValue(":data_machine", dataMachine);
    query.bindValue(":mold_id", curr_id);
    if(!executeQuery(query, ERROR_TITLE_ADD_MACHINE, ERROR_MSG_MOLD_MACHINE_UPDATE))
        return;
    QMessageBox::information(this, ERROR_TITLE_ADD_MACHINE, SUCCESS_MSG_MACHINE_ADD, QMessageBox::Ok);
    ui->MachineComb->addItem(normalizedMachine);
}

// 槽函数实现
void ChonyaEdit::on_AddButton_clicked() {
    QString machineNum = ui->MachineNum->text();
    if(machineNum.isEmpty()) {
        QMessageBox::warning(this, ERROR_TITLE_ADD_MACHINE, "请输入机台号", QMessageBox::Cancel);
        return;
    }
    addMachine(machineNum);
}

void ChonyaEdit::on_MachineNum_returnPressed() {
    QString machineNum = ui->MachineNum->text();
    if(machineNum.isEmpty()) {
        QMessageBox::warning(this, ERROR_TITLE_ADD_MACHINE, "请输入机台号", QMessageBox::Cancel);
        return;
    }
    addMachine(machineNum);
}

void ChonyaEdit::on_EditButton_clicked() {
    QString mold_id = ui->MoldID->text();
    QString life_num = ui->LifeNum->text();
    QString out_num1 = ui->OutNum_1->text();
    QString out_num2 = ui->OutNum_2->text();
    if(mold_id.isEmpty()) {
        QMessageBox::warning(this, ERROR_TITLE_EDIT, WARNING_MSG_INPUT_MOLD_ID, QMessageBox::Cancel);
        return;
    }
    if(out_num1.isEmpty() || out_num2.isEmpty()) {
        QMessageBox::warning(this, ERROR_TITLE_EDIT, WARNING_MSG_INPUT_OUT_NUM, QMessageBox::Cancel);
        return;
    }
    if(life_num.isEmpty()) {
        QMessageBox::warning(this, ERROR_TITLE_EDIT, WARNING_MSG_INPUT_LIFE_NUM, QMessageBox::Cancel);
        return;
    }
    QSqlQuery query;
    QString sql = "UPDATE type_message SET "
                  "产品料号 = :product_id, "
                  "产品名称 = :product_name, "
                  "材料规格 = :product_stand, "
                  "模具寿命冲次数 = :life_num, "
                  "出数1 = :out_num1, "
                  "出数2 = :out_num2, "
                  "管制标准 = :control_stand "
                  "WHERE 模具编号 = :id_value";
    query.prepare(sql);
    query.bindValue(":id_value", curr_id);
    query.bindValue(":life_num", life_num);
    query.bindValue(":out_num1", out_num1);
    query.bindValue(":out_num2", out_num2);
    query.bindValue(":product_stand", ui->ProductStand->text());
    query.bindValue(":product_id", ui->ProductID->toPlainText());
    query.bindValue(":product_name", ui->ProductName->toPlainText());
    query.bindValue(":control_stand", ui->ControlStand->currentText());
    if(!executeQuery(query, ERROR_TITLE_EDIT, ERROR_MSG_MOLD_DATA_UPDATE))
        return;
    QMessageBox::information(this, ERROR_TITLE_EDIT, SUCCESS_MSG_MOLD_EDIT, QMessageBox::Ok);
    emit mysignal();
}

void ChonyaEdit::on_DeleButton_clicked() {
    if(curr_id.isEmpty()) {
        QMessageBox::warning(this, ERROR_TITLE_DELETE_MACHINE, WARNING_MSG_SELECT_MOLD, QMessageBox::Cancel);
        return;
    }
    QString curr_machine = ui->MachineComb->currentText();
    // 使用QStringList提高字符串拼接效率
    QStringList machineList;
    for(int i = 0; i < ui->MachineComb->count(); ++i) {
        if(ui->MachineComb->itemText(i) != curr_machine) {
            machineList.append(ui->MachineComb->itemText(i));
        }
    }
    QString dataMachine = machineList.join("");
    QSqlQuery query;
    QString sql = "UPDATE type_message SET 机台 = :data_machine WHERE 模具编号 = :mold_id";
    query.prepare(sql);
    query.bindValue(":data_machine", dataMachine);
    query.bindValue(":mold_id", curr_id);
    if(!executeQuery(query, ERROR_TITLE_DELETE_MACHINE, ERROR_MSG_MOLD_MACHINE_UPDATE))
        return;
    QMessageBox::information(this, ERROR_TITLE_DELETE_MACHINE, SUCCESS_MSG_MACHINE_DELETE, QMessageBox::Ok);
    ui->MachineComb->removeItem(ui->MachineComb->currentIndex());
}

void ChonyaEdit::on_NameButton_clicked() {
    QString userName = ui->NameComb->currentText();
    if(userName.isEmpty()) {
        QMessageBox::warning(this, ERROR_TITLE_DELETE_USER, WARNING_MSG_SELECT_USER, QMessageBox::Cancel);
        return;
    }
    QString question = "您确定要删除 " + userName + " 吗？";
    int reply = QMessageBox::question(this, ERROR_TITLE_DELETE_USER, question, QMessageBox::Yes | QMessageBox::No);
    if(reply != QMessageBox::Yes)
        return;
    QSqlQuery query;
    // 删除员工信息列表
    query.prepare("DELETE FROM information_message WHERE 接收用户 = :user_id");
    query.bindValue(":user_id", userName);
    if(!executeQuery(query, ERROR_TITLE_DELETE_USER, ERROR_MSG_USER_INFO_DELETE))
        return;
    // 删除员工
    query.prepare("DELETE FROM user_message WHERE name = :user_id");
    query.bindValue(":user_id", userName);
    if(!executeQuery(query, ERROR_TITLE_DELETE_USER, ERROR_MSG_USER_DELETE))
        return;
    QMessageBox::information(this, ERROR_TITLE_DELETE_USER, SUCCESS_MSG_USER_DELETE, QMessageBox::Ok);
    int index = ui->NameComb->findText(userName);
    if(index >= 0) {
        ui->NameComb->removeItem(index);
    }
}
