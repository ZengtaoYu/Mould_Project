#include "sumoadd.h"
#include "ui_sumoadd.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

// ==================== 构造函数和析构函数 ====================

SumoAdd::SumoAdd(QWidget *parent) : QMainWindow(parent), ui(new Ui::SumoAdd) {
    ui->setupUi(this);
}

SumoAdd::~SumoAdd() {
    delete ui;
}

// ==================== 事件处理 ====================

void SumoAdd::closeEvent(QCloseEvent *event) {
    setVisible(false);
    event->ignore();
}

// ==================== 公共槽函数 ====================

void SumoAdd::on_AddButton_clicked() {
    if(!validateInput()) {
        return;
    }
    QString moldId = ui->MoldID->text().trimmed();
    if(moldId.isEmpty()) {
        QMessageBox::warning(this, "添加模具", "请输入模具编号", QMessageBox::Cancel);
        return;
    }
    if(checkMoldIdExists(moldId)) {
        QMessageBox::warning(this, "添加模具", "模具编号重复", QMessageBox::Cancel);
        return;
    }
    if(!insertMoldData()) {
        return;
    }
    if(!createMoldTable(moldId)) {
        return;
    }
    QMessageBox::information(this, "添加模具", "模具添加成功", QMessageBox::Ok);
    emit mysignal();
    clearAndResetUI();
}

void SumoAdd::on_OutNum_returnPressed() {
    on_AddButton_clicked();
}

void SumoAdd::on_MoldID_returnPressed() {
    loadBomDataByMoldId();
}

void SumoAdd::on_ProductID_returnPressed() {
    loadBomDataByProductId();
}

// ==================== 输入验证 ====================

bool SumoAdd::validateInput() {
    QString moldId = ui->MoldID->text().trimmed();
    if(moldId.isEmpty()) {
        QMessageBox::warning(this, "添加模具", "请输入模具编号", QMessageBox::Cancel);
        return false;
    }
    QString keepNum1 = ui->KeepNum1->text().trimmed();
    if(keepNum1.isEmpty()) {
        QMessageBox::warning(this, "添加模具", "请输入定期保养模次数", QMessageBox::Cancel);
        return false;
    }
    if(!validateNumericField(keepNum1, "定期保养模次数")) {
        return false;
    }
    QString keepNum2 = ui->KeepNum2->text().trimmed();
    if(keepNum2.isEmpty()) {
        QMessageBox::warning(this, "添加模具", "请输入大保养模次数", QMessageBox::Cancel);
        return false;
    }
    if(!validateNumericField(keepNum2, "大保养模次数")) {
        return false;
    }
    QString keepNum3 = ui->KeepNum3->text().trimmed();
    if(keepNum3.isEmpty()) {
        QMessageBox::warning(this, "添加模具", "请输入特定易损件管制模次数", QMessageBox::Cancel);
        return false;
    }
    if(!validateNumericField(keepNum3, "特定易损件管制模次数")) {
        return false;
    }
    QString productNum = ui->ProductNum->text().trimmed();
    if(productNum.isEmpty()) {
        QMessageBox::warning(this, "添加模具", "请输入标准产量", QMessageBox::Cancel);
        return false;
    }
    if(!validateNumericField(productNum, "标准产量")) {
        return false;
    }
    QString productNum1 = ui->ProductNum1->text().trimmed();
    if(productNum1.isEmpty()) {
        QMessageBox::warning(this, "添加模具", "请输入定期保养剩余订单数", QMessageBox::Cancel);
        return false;
    }
    if(!validateNumericField(productNum1, "定期保养剩余订单数")) {
        return false;
    }
    QString productNum2 = ui->ProductNum2->text().trimmed();
    if(productNum2.isEmpty()) {
        QMessageBox::warning(this, "添加模具", "请输入大保养剩余订单数", QMessageBox::Cancel);
        return false;
    }
    if(!validateNumericField(productNum2, "大保养剩余订单数")) {
        return false;
    }
    QString lifeNum = ui->LifeNum->text().trimmed();
    if(lifeNum.isEmpty()) {
        QMessageBox::warning(this, "添加模具", "请输入模具设计寿命", QMessageBox::Cancel);
        return false;
    }
    if(!validateNumericField(lifeNum, "模具设计寿命")) {
        return false;
    }
    QString outNum = ui->OutNum->text().trimmed();
    if(outNum.isEmpty()) {
        QMessageBox::warning(this, "添加模具", "请输入穴数", QMessageBox::Cancel);
        return false;
    }
    if(!validateNumericField(outNum, "穴数")) {
        return false;
    }
    return true;
}

bool SumoAdd::validateNumericField(const QString &value, const QString &fieldName) {
    bool ok;
    double numValue = value.toDouble(&ok);
    if(!ok || numValue < 0) {
        QMessageBox::warning(this, "添加模具",
            QString("%1必须是有效的非负数").arg(fieldName),
            QMessageBox::Cancel);
        return false;
    }
    return true;
}

// ==================== 数据库操作 ====================

bool SumoAdd::checkMoldIdExists(const QString &moldId) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM type_message WHERE 模具编号 = :mold_id");
    query.bindValue(":mold_id", moldId);
    if(!query.exec()) {
        QMessageBox::warning(this, "添加模具",
            "模具数量查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    if(query.next()) {
        return query.value(0).toInt() > 0;
    }
    return false;
}

bool SumoAdd::insertMoldData() {
    QSqlQuery query;
    query.prepare("INSERT INTO type_message (模具编号,产品料号,产品名称,穴数,模具寿命冲次数,"
                  "定期保养模次数,特定易损件管制模次数,大保养模次数,标准产量,剩余订单数1,"
                  "剩余订单数2,保养情况,机台) VALUES "
                  "(:mold_id, :product_id, :product_name, :out_num, :life_num, :keep_num1, "
                  ":keep_num3, :keep_num2, :product_num, :product_num1, :product_num2, "
                  ":keep_status, :machine_num)");
    query.bindValue(":mold_id", ui->MoldID->text().trimmed());
    query.bindValue(":product_id", ui->ProductID->text().trimmed());
    query.bindValue(":product_name", ui->ProductName->toPlainText().trimmed());
    query.bindValue(":out_num", ui->OutNum->text().trimmed());
    query.bindValue(":life_num", ui->LifeNum->text().trimmed());
    query.bindValue(":keep_num1", ui->KeepNum1->text().trimmed());
    query.bindValue(":keep_num2", ui->KeepNum2->text().trimmed());
    query.bindValue(":keep_num3", ui->KeepNum3->text().trimmed());
    query.bindValue(":product_num", ui->ProductNum->text().trimmed());
    query.bindValue(":product_num1", ui->ProductNum1->text().trimmed());
    query.bindValue(":product_num2", ui->ProductNum2->text().trimmed());
    query.bindValue(":keep_status", KEEP_STATUS_DEFAULT);
    QString machineNum = ui->MachineNum->text().trimmed();
    machineNum.remove("#");
    query.bindValue(":machine_num", "#" + machineNum);
    if(!query.exec()) {
        QMessageBox::warning(this, "添加模具",
            "模具数据插入失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    return true;
}

bool SumoAdd::createMoldTable(const QString &moldId) {
    QString tableName = moldId;
    tableName.replace("-", "_");
    QSqlQuery query;
    QString sql = QString("CREATE TABLE IF NOT EXISTS D%1 ("
                          "序号 INT PRIMARY KEY AUTO_INCREMENT, "
                          "日期 CHAR(20), "
                          "机台号 CHAR(5), "
                          "当日产量 FLOAT, "
                          "穴数 CHAR(10), "
                          "当日模次 INT, "
                          "累计模数 INT, "
                          "定期保养模累计数 INT, "
                          "剩余订单数1 INT, "
                          "大保养模累计数 INT, "
                          "剩余订单数2 INT, "
                          "特定易损件管制模累计数 INT, "
                          "模修 CHAR(10), "
                          "备注 CHAR(200)) "
                          "AUTO_INCREMENT=1").arg(tableName);
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "添加模具",
            "模具产量信息表创建失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    return true;
}

// ==================== BOM数据加载 ====================

void SumoAdd::loadBomDataByMoldId() {
    QString moldId = ui->MoldID->text().trimmed();
    if(moldId.isEmpty()) {
        return;
    }
    QSqlQuery query;
    query.prepare("SELECT * FROM bom_current_bom WHERE 模号 LIKE :mold_id");
    query.bindValue(":mold_id", "%" + moldId + "%");
    if(!query.exec()) {
        QMessageBox::warning(this, "载入信息",
            "BOM表数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        fillBomDataToUI(query);
        QMessageBox::information(this, "载入信息",
            "已将BOM表中的模号、产品料号、产品名称、标准穴数、标准产量、"
            "剩余订单数1、剩余订单数2更新到该页面",
            QMessageBox::Ok);
    }
}

void SumoAdd::loadBomDataByProductId() {
    QString productId = ui->ProductID->text().trimmed();
    if(productId.isEmpty()) {
        return;
    }
    QSqlQuery query;
    query.prepare("SELECT * FROM bom_current_bom WHERE 产品料号 LIKE :product_id");
    query.bindValue(":product_id", "%" + productId + "%");
    if(!query.exec()) {
        QMessageBox::warning(this, "载入信息",
            "BOM表数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        fillBomDataToUI(query);
        QMessageBox::information(this, "载入信息",
            "已将BOM表中的模号、产品料号、产品名称、标准穴数、标准产量、"
            "剩余订单数1、剩余订单数2更新到该页面",
            QMessageBox::Ok);
    }
}

void SumoAdd::fillBomDataToUI(const QSqlQuery &query) {
    ui->MoldID->setText(query.value("模号").toString());
    ui->ProductID->setText(query.value("产品料号").toString());
    ui->ProductName->setText(query.value("产品名称").toString());
    ui->OutNum->setText(query.value("标准穴数").toString());
    double dailyProduction = query.value("日产量（KPCS）").toString().toDouble();
    int roundedValue = qRound(dailyProduction);
    ui->ProductNum->setText(QString::number(roundedValue));
    int standardCavity = query.value("标准穴数").toInt();
    ui->ProductNum1->setText(QString::number(standardCavity * PRODUCT_NUM1_MULTIPLIER));
    ui->ProductNum2->setText(QString::number(standardCavity * PRODUCT_NUM2_MULTIPLIER));
}

// ==================== UI操作 ====================

void SumoAdd::clearAndResetUI() {
    ui->ProductName->clear();
    ui->ProductNum1->clear();
    ui->ProductNum2->clear();
    ui->ProductID->clear();
    ui->MoldID->clear();
    ui->MachineNum->clear();
    ui->ProductNum->clear();
    ui->OutNum->clear();
    ui->KeepNum1->setText(QString::number(DEFAULT_KEEP_NUM1));
    ui->KeepNum2->setText(QString::number(DEFAULT_KEEP_NUM2));
    ui->KeepNum3->setText(QString::number(DEFAULT_KEEP_NUM3));
    ui->LifeNum->setText(QString::number(DEFAULT_LIFE_NUM));
}
