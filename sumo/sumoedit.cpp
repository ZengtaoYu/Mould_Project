#include "sumoedit.h"
#include "ui_sumoedit.h"
#include "sumo/newworker.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QListView>
#include <QScroller>
#include <QAbstractItemView>
#include <QDebug>

// ==================== 构造函数和析构函数 ====================

SumoEdit::SumoEdit(QVariant id_value, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SumoEdit)
    , newWorker(nullptr)
    , curr_id(id_value.toString()) {
    ui->setupUi(this);
    initializeUI();
    if(!loadMoldData()) {
        QMessageBox::critical(this, "界面初始化", "模具数据加载失败，窗口将关闭", QMessageBox::Ok);
        close();
        return;
    }
}

SumoEdit::~SumoEdit() {
    if(newWorker) {
        newWorker->deleteLater();
        newWorker = nullptr;
    }
    delete ui;
}

// ==================== 事件处理 ====================

void SumoEdit::closeEvent(QCloseEvent *event) {
    Q_UNUSED(event);
    if(QWidget *target = m_windowMap.value(tr("添加员工"))) {
        if(!target->isHidden()) {
            target->close();
            target->deleteLater();
            m_windowMap.remove(tr("添加员工"));
        }
    }
    QMainWindow::closeEvent(event);
}

// ==================== 初始化相关方法 ====================

void SumoEdit::initializeUI() {
    QListView *listView = qobject_cast<QListView *>(ui->MachineComb->view());
    if(listView) {
        QScroller *scroller = QScroller::scroller(listView);
        if(scroller) {
            scroller->grabGesture(listView->viewport(), QScroller::LeftMouseButtonGesture);
            listView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        }
    }
}

bool SumoEdit::loadMoldData() {
    if(curr_id.isEmpty()) {
        QMessageBox::warning(this, "界面初始化", "模具编号为空", QMessageBox::Ok);
        return false;
    }
    QSqlQuery query;
    QString sql = "SELECT * FROM type_message WHERE 模具编号 = :mold_id";
    query.prepare(sql);
    query.bindValue(":mold_id", curr_id);
    if(!query.exec()) {
        QMessageBox::critical(this, "界面初始化",
            QString("模具数据查询失败：\n%1").arg(query.lastError().text()),
            QMessageBox::Ok);
        return false;
    }
    if(!query.next()) {
        QMessageBox::warning(this, "界面初始化", "未找到对应的模具数据", QMessageBox::Ok);
        return false;
    }
    // 加载基本信息
    ui->ProductName->setText(query.value("产品名称").toString());
    ui->MoldID->setText(query.value("模具编号").toString());
    ui->ProductID->setText(query.value("产品料号").toString());
    ui->ProductNum->setText(query.value("标准产量").toString());
    ui->ProductNum1->setText(query.value("剩余订单数1").toString());
    ui->ProductNum2->setText(query.value("剩余订单数2").toString());
    ui->KeepNum1->setText(query.value("定期保养模次数").toString());
    ui->KeepNum2->setText(query.value("大保养模次数").toString());
    ui->KeepNum3->setText(query.value("特定易损件管制模次数").toString());
    ui->OutNum->setText(query.value("穴数").toString());
    ui->LifeNum->setText(query.value("模具寿命冲次数").toString());
    // 加载机台列表
    QString machineField = query.value("机台").toString();
    if(!machineField.isEmpty()) {
        loadMachineList(machineField);
    }
    return true;
}

void SumoEdit::loadMachineList(const QString &machineField) {
    QStringList machineList = machineField.split("#", Qt::SkipEmptyParts);
    for(const QString &machine : machineList) {
        QString trimmedMachine = machine.trimmed();
        if(!trimmedMachine.isEmpty()) {
            ui->MachineComb->addItem("#" + trimmedMachine);
        }
    }
}

// ==================== 机台管理相关方法 ====================

QString SumoEdit::sanitizeMachineNumber(const QString &input) const {
    QString cleaned = input.trimmed();
    cleaned.remove("#");
    return cleaned;
}

bool SumoEdit::isMachineExists(const QString &machine) const {
    for(int i = 0; i < ui->MachineComb->count(); ++i) {
        if(ui->MachineComb->itemText(i) == machine) {
            return true;
        }
    }
    return false;
}

QString SumoEdit::buildMachineString(const QString &excludeMachine) const {
    QString result;
    for(int i = 0; i < ui->MachineComb->count(); ++i) {
        QString itemText = ui->MachineComb->itemText(i);
        if(itemText != excludeMachine) {
            result += itemText;
        }
    }
    return result;
}

bool SumoEdit::addMachine(const QString &machineNum) {
    if(!validateMoldId()) {
        return false;
    }
    QString cleanedMachine = sanitizeMachineNumber(machineNum);
    if(cleanedMachine.isEmpty()) {
        QMessageBox::warning(this, "添加机台", "请输入有效的机台号", QMessageBox::Ok);
        return false;
    }
    QString formattedMachine = "#" + cleanedMachine;
    if(isMachineExists(formattedMachine)) {
        QMessageBox::warning(this, "添加机台", "该机台已存在", QMessageBox::Ok);
        return false;
    }
    QString newMachineString = buildMachineString() + formattedMachine;
    if(!updateMachineData(newMachineString)) {
        return false;
    }
    ui->MachineComb->addItem(formattedMachine);
    ui->MachineNum->clear();
    QMessageBox::information(this, "添加机台", "机台添加成功", QMessageBox::Ok);
    return true;
}

bool SumoEdit::removeMachine() {
    if(!validateMoldId()) {
        return false;
    }
    if(ui->MachineComb->count() == 0) {
        QMessageBox::warning(this, "删除机台", "没有可删除的机台", QMessageBox::Ok);
        return false;
    }
    QString currentMachine = ui->MachineComb->currentText();
    if(currentMachine.isEmpty()) {
        QMessageBox::warning(this, "删除机台", "请选择要删除的机台", QMessageBox::Ok);
        return false;
    }
    QString newMachineString = buildMachineString(currentMachine);
    if(!updateMachineData(newMachineString)) {
        return false;
    }
    ui->MachineComb->removeItem(ui->MachineComb->currentIndex());
    QMessageBox::information(this, "删除机台", "机台删除成功", QMessageBox::Ok);
    return true;
}

// ==================== 数据验证相关方法 ====================

bool SumoEdit::validateMoldId() const {
    if(curr_id.isEmpty()) {
        QMessageBox::warning(const_cast<QWidget*>(static_cast<const QWidget*>(this)),
            "操作提示", "请选择模具", QMessageBox::Ok);
        return false;
    }
    return true;
}

bool SumoEdit::validateNumericInput(const QString &value, const QString &fieldName) const {
    QWidget *parent = const_cast<QWidget *>(static_cast<const QWidget*>(this));
    if(value.isEmpty()) {
        QMessageBox::warning(parent, "修改模具参数",
            QString("请输入%1").arg(fieldName),
            QMessageBox::Ok);
        return false;
    }
    bool ok;
    int numValue = value.toInt(&ok);
    if(!ok || numValue < 0) {
        QMessageBox::warning(parent, "修改模具参数",
            QString("%1必须是有效的非负整数").arg(fieldName),
            QMessageBox::Ok);
        return false;
    }
    return true;
}

bool SumoEdit::validateEditInputs() const {
    QWidget *parent = const_cast<QWidget *>(static_cast<const QWidget*>(this));
    if(!validateMoldId()) {
        return false;
    }
    if(ui->MoldID->text().isEmpty()) {
        QMessageBox::warning(parent, "修改模具参数", "请输入模具编号", QMessageBox::Ok);
        return false;
    }
    if(!validateNumericInput(ui->KeepNum1->text(), "定期保养模次数"))
        return false;
    if(!validateNumericInput(ui->KeepNum2->text(), "大保养模次数"))
        return false;
    if(!validateNumericInput(ui->KeepNum3->text(), "特定易损件管制模次数"))
        return false;
    if(!validateNumericInput(ui->ProductNum->text(), "标准产量"))
        return false;
    if(!validateNumericInput(ui->ProductNum1->text(), "定期保养剩余订单数"))
        return false;
    if(!validateNumericInput(ui->ProductNum2->text(), "大保养剩余订单数"))
        return false;
    if(!validateNumericInput(ui->LifeNum->text(), "模具设计寿命"))
        return false;
    if(!validateNumericInput(ui->OutNum->text(), "穴数"))
        return false;
    return true;
}

// ==================== 数据库操作相关方法 ====================

bool SumoEdit::updateMachineData(const QString &machineString) {
    QSqlQuery query;
    QString sql = "UPDATE type_message SET 机台 = :data_machine WHERE 模具编号 = :mold_id";
    query.prepare(sql);
    query.bindValue(":data_machine", machineString);
    query.bindValue(":mold_id", curr_id);
    if(!query.exec()) {
        QMessageBox::critical(this, "操作失败",
            QString("模具机台更新失败：\n%1").arg(query.lastError().text()),
            QMessageBox::Ok);
        return false;
    }
    return true;
}

bool SumoEdit::updateMoldData() {
    if(!validateEditInputs()) {
        return false;
    }
    QSqlQuery query;
    QString sql = "UPDATE type_message SET "
                  "产品料号 = :product_id, "
                  "产品名称 = :product_name, "
                  "穴数 = :out_num, "
                  "模具寿命冲次数 = :life_num, "
                  "定期保养模次数 = :keep_num1, "
                  "特定易损件管制模次数 = :keep_num3, "
                  "大保养模次数 = :keep_num2, "
                  "标准产量 = :product_num, "
                  "剩余订单数1 = :product_num1, "
                  "剩余订单数2 = :product_num2 "
                  "WHERE 模具编号 = :id_value";
    query.prepare(sql);
    query.bindValue(":product_id", ui->ProductID->toPlainText());
    query.bindValue(":product_name", ui->ProductName->toPlainText());
    query.bindValue(":out_num", ui->OutNum->text());
    query.bindValue(":life_num", ui->LifeNum->text());
    query.bindValue(":keep_num1", ui->KeepNum1->text());
    query.bindValue(":keep_num2", ui->KeepNum2->text());
    query.bindValue(":keep_num3", ui->KeepNum3->text());
    query.bindValue(":product_num", ui->ProductNum->text());
    query.bindValue(":product_num1", ui->ProductNum1->text());
    query.bindValue(":product_num2", ui->ProductNum2->text());
    query.bindValue(":id_value", curr_id);
    if(!query.exec()) {
        QMessageBox::critical(this, "修改模具参数",
            QString("模具数据更新失败：\n%1").arg(query.lastError().text()),
            QMessageBox::Ok);
        return false;
    }
    QMessageBox::information(this, "修改模具参数", "模具参数修改成功", QMessageBox::Ok);
    emit mysignal();
    return true;
}

// ==================== 槽函数 ====================

void SumoEdit::on_EditButton_clicked() {
    updateMoldData();
}

void SumoEdit::on_AddButton_clicked() {
    QString machineNum = ui->MachineNum->text();
    addMachine(machineNum);
}

void SumoEdit::on_MachineNum_returnPressed() {
    QString machineNum = ui->MachineNum->text();
    addMachine(machineNum);
}

void SumoEdit::on_DeleButton_clicked() {
    removeMachine();
}

void SumoEdit::on_NameButton_clicked() {
    if(newWorker) {
        if(!newWorker->isHidden()) {
            newWorker->raise();
            newWorker->activateWindow();
            return;
        } else {
            newWorker->deleteLater();
            newWorker = nullptr;
        }
    }
    newWorker = new NewWorker(this);
    newWorker->setWindowTitle("添加员工");
    m_windowMap.insert(tr("添加员工"), newWorker);
    newWorker->show();
}
