#include "chonyaadd.h"
#include "ui_chonyaadd.h"

// ==================== 构造函数和析构函数 ====================

ChonyaAdd::ChonyaAdd(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChonyaAdd)
    , m_movie(new QMovie(this)) {
    ui->setupUi(this);
    m_movie->setFileName(":/images/machine_load.gif");
    ui->LoadingLabel->setMovie(m_movie);
    m_movie->start();
}

ChonyaAdd::~ChonyaAdd() {
    delete ui;
}

// ==================== 私有槽函数 ====================

void ChonyaAdd::on_AddButton_clicked() {
    if(!validateInput()) {
        return;
    }
    if(!addMoldWithTransaction()) {
        return;
    }
    QMessageBox::information(this, "添加模具", "模具添加成功", QMessageBox::Ok);
    emit mysignal();
    clearForm();
}

void ChonyaAdd::on_MachineNum_returnPressed() {
    if(!validateInput()) {
        return;
    }
    if(!addMoldWithTransaction()) {
        return;
    }
    QMessageBox::information(this, "添加模具", "模具添加成功", QMessageBox::Ok);
    emit mysignal();
    clearForm();
}

void ChonyaAdd::on_MoldID_returnPressed() {
    QString moldId = ui->MoldID->text().trimmed();
    if(moldId.isEmpty()) {
        return;
    }
    loadBomData(moldId);
}

// ==================== 数据验证函数 ====================

bool ChonyaAdd::validateInput() {
    QString moldId = ui->MoldID->text().trimmed();
    if(moldId.isEmpty()) {
        QMessageBox::warning(this, "添加模具", "请输入模具编号", QMessageBox::Cancel);
        return false;
    }
    QString outNum1 = ui->OutNum_1->text().trimmed();
    QString outNum2 = ui->OutNum_2->text().trimmed();
    if(outNum1.isEmpty() || outNum2.isEmpty()) {
        QMessageBox::warning(this, "添加模具", "请输入产品出数，若没有设定，可设置为1 * 1",
            QMessageBox::Cancel);
        return false;
    }
    if(!validateNumericValue(outNum1, "出数1")) {
        return false;
    }
    if(!validateNumericValue(outNum2, "出数2")) {
        return false;
    }
    QString lifeNum = ui->LifeNum->text().trimmed();
    if(lifeNum.isEmpty()) {
        QMessageBox::warning(this, "添加模具", "请输入模具寿命冲次数", QMessageBox::Cancel);
        return false;
    }
    if(!validateNumericValue(lifeNum, "模具寿命冲次数")) {
        return false;
    }
    if(ui->ControlStand->currentText() == "NULL") {
        QMessageBox::StandardButton reply = QMessageBox::question(
                this, "模具管制标准",
                "确认不设置该模具的管制标准吗？后续可以在模具修改中设置。",
                QMessageBox::Yes | QMessageBox::Cancel);
        if(reply != QMessageBox::Yes) {
            return false;
        }
    }
    return true;
}

bool ChonyaAdd::validateNumericValue(const QString &value, const QString &fieldName) {
    bool ok;
    double numValue = value.toDouble(&ok);
    if(!ok || numValue <= 0) {
        QMessageBox::warning(this, "添加模具",
            QString("%1必须是大于0的有效数字").arg(fieldName),
            QMessageBox::Cancel);
        return false;
    }
    return true;
}

// ==================== 数据库操作函数 ====================

bool ChonyaAdd::checkMoldIdExists(const QString &moldId) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM type_message WHERE 模具编号 = :mold_id");
    query.bindValue(":mold_id", moldId);
    if(!query.exec()) {
        QMessageBox::warning(this, "添加模具",
            "查询模具数量失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    if(query.next() && query.value(0).toInt() > 0) {
        QMessageBox::warning(this, "添加模具", "模具编号重复", QMessageBox::Cancel);
        return false;
    }
    return true;
}

bool ChonyaAdd::insertMoldData() {
    QString moldId = ui->MoldID->text().trimmed();
    QString lifeNum = ui->LifeNum->text().trimmed();
    QString outNum1 = ui->OutNum_1->text().trimmed();
    QString outNum2 = ui->OutNum_2->text().trimmed();
    QString machineNum = "#" + ui->MachineNum->text().replace("#", "").trimmed();
    QSqlQuery query;
    query.prepare("INSERT INTO type_message (模具编号, 产品料号, 产品名称, 材料规格, "
                  "模具寿命冲次数, 出数1, 出数2, 保养情况, 管制标准, 机台) "
                  "VALUES (:mold_id, :product_id, :product_name, :product_stand, "
                  ":life_num, :out_num1, :out_num2, :keep_status, :control_stand, :machine_num)");
    query.bindValue(":mold_id", moldId);
    query.bindValue(":product_id", ui->ProductID->toPlainText());
    query.bindValue(":product_name", ui->ProductName->toPlainText());
    query.bindValue(":product_stand", ui->ProductStand->text());
    query.bindValue(":life_num", lifeNum);
    query.bindValue(":out_num1", outNum1);
    query.bindValue(":out_num2", outNum2);
    query.bindValue(":keep_status", "当前无需保养");
    query.bindValue(":control_stand", ui->ControlStand->currentText());
    query.bindValue(":machine_num", machineNum);
    if(!query.exec()) {
        QMessageBox::warning(this, "添加模具",
            "模具数据插入失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    return true;
}

bool ChonyaAdd::createMoldTable(const QString &moldId) {
    QString table = moldId;
    table.replace("-", "_");
    // 验证表名只包含安全字符（字母、数字、下划线）
    QRegExp safeTableName("^[a-zA-Z0-9_]+$");
    if(!safeTableName.exactMatch(table)) {
        QMessageBox::warning(this, "添加模具",
            "模具编号包含非法字符，无法创建数据表",
            QMessageBox::Cancel);
        return false;
    }
    // 由于表名不能使用参数绑定，需要字符串拼接
    // 但已通过上面的正则表达式验证确保安全性
    QSqlQuery query;
    QString sql = QString("CREATE TABLE IF NOT EXISTS D%1 ("
                          "序号 INT PRIMARY KEY AUTO_INCREMENT, "
                          "日期 CHAR(20), "
                          "机台号 CHAR(5), "
                          "当日产量 FLOAT, "
                          "累计冲次数 DOUBLE, "
                          "下料零件累计 DOUBLE, "
                          "关键易损件累计 DOUBLE, "
                          "成型零件累计 DOUBLE, "
                          "操作员 CHAR(10), "
                          "模修 CHAR(10), "
                          "备注 CHAR(200)) "
                          "AUTO_INCREMENT=1")
        .arg(table);
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "添加模具",
            "模具产量信息表创建失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    return true;
}

bool ChonyaAdd::addMoldWithTransaction() {
    QString moldId = ui->MoldID->text().trimmed();
    if(!checkMoldIdExists(moldId)) {
        return false;
    }
    if(!insertMoldData()) {
        return false;
    }
    if(!createMoldTable(moldId)) {
        return false;
    }
    return true;
}

// ==================== UI操作函数 ====================

void ChonyaAdd::clearForm() {
    ui->ProductName->clear();
    ui->ProductID->clear();
    ui->ProductStand->clear();
    ui->ControlStand->setCurrentIndex(0);
    ui->MoldID->clear();
    ui->OutNum_1->setText("1");
    ui->OutNum_2->setText("1");
    ui->LifeNum->setText("200");
}

void ChonyaAdd::loadBomData(const QString &moldId) {
    QSqlQuery query;
    query.prepare("SELECT * FROM bom_current_bom WHERE 厂内模号 LIKE :mold_id");
    query.bindValue(":mold_id", "%" + moldId + "%");
    if(!query.exec()) {
        QMessageBox::warning(this, "载入信息",
            "BOM表数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        ui->MoldID->setText(query.value("厂内模号").toString());
        ui->ProductID->setText(query.value("产品料号").toString());
        ui->ProductName->setText(query.value("产品名称").toString());
        ui->OutNum_1->setText(query.value("模具进料带数").toString());
        ui->OutNum_2->setText(query.value("模具出料带数").toString());
        ui->MoldID->setSelection(0, 0);
        QMessageBox::information(this, "载入信息",
            "已将BOM表中的厂内模号、产品料号、产品名称、"
            "模具进料带数、模具出料带数更新到该页面",
            QMessageBox::Ok);
    }
}
