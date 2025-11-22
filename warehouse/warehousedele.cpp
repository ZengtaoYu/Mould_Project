#include "warehousedele.h"
#include "ui_warehousedele.h"
#include <QSqlDatabase>

// 静态常量定义
const QString WarehouseDele::PART_STAMPING = "冲压";
const QString WarehouseDele::PART_FORMING = "成型";
const QString WarehouseDele::CABINET_SPARE = "备件货柜";
const QString WarehouseDele::CABINET_MOLD = "模具货柜";
const QString WarehouseDele::COLUMN_MOLD_ID = "模具编号";
const QString WarehouseDele::COLUMN_CABINET_NAME = "货柜名称";

// ==================== 构造函数和析构函数 ====================

WarehouseDele::WarehouseDele(QWidget *parent) : QMainWindow(parent), ui(new Ui::WarehouseDele) {
    ui->setupUi(this);
    part = PART_STAMPING;
    save = CABINET_SPARE;
    state = false;
    ui->ShowLabel->show();
    ui->NumLabel->show();
    ui->ChangeButtonc->hide();
    ui->ShowLabel->setText(part + "模具类别⬋");
    QScroller *pScroller = QScroller::scroller(ui->PIDView);
    pScroller->grabGesture(ui->PIDView->viewport(), QScroller::LeftMouseButtonGesture);
    ui->PIDView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    refreshMoldList();
}

WarehouseDele::~WarehouseDele() {
    delete ui;
}

// ==================== 工具函数 ====================

QString WarehouseDele::getSparePartTableName() const {
    return (part == PART_STAMPING) ? "chonya_message" : "chengxing_message";
}

QString WarehouseDele::getMoldTableName() const {
    return (part == PART_STAMPING) ? "chonya_mold" : "chengxing_mold";
}

QString WarehouseDele::getSparePartCabinetColumn() const {
    return "存放柜号";
}

QString WarehouseDele::getMoldCabinetColumn() const {
    return "存放货柜";
}

// ==================== 数据刷新函数 ====================

void WarehouseDele::Find_ID(const QString &sql, const QString &columnName) {
    QStandardItemModel *model = new QStandardItemModel(this);
    QSqlQuery query;
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "刷新数据", "数据查询失败：\n" + query.lastError().text(), QMessageBox::Cancel);
        delete model;
        return;
    }
    while(query.next()) {
        QStandardItem *item = new QStandardItem(query.value(columnName).toString());
        model->appendRow(item);
    }
    // 清理旧的model
    QAbstractItemModel *oldModel = ui->PIDView->model();
    ui->PIDView->setModel(model);
    if(oldModel && oldModel != model) {
        oldModel->deleteLater();
    }
}

void WarehouseDele::refreshMoldList() {
    QSqlQuery query;
    query.prepare("select 模具编号 from mold_message where 隶属部门 = :department");
    query.bindValue(":department", part);
    if(!query.exec()) {
        QMessageBox::warning(this, "刷新数据", "数据查询失败：\n" + query.lastError().text(), QMessageBox::Cancel);
        return;
    }
    QStandardItemModel *model = new QStandardItemModel(this);
    while(query.next()) {
        QStandardItem *item = new QStandardItem(query.value(COLUMN_MOLD_ID).toString());
        model->appendRow(item);
    }
    // 清理旧的model
    QAbstractItemModel *oldModel = ui->PIDView->model();
    ui->PIDView->setModel(model);
    if(oldModel && oldModel != model) {
        oldModel->deleteLater();
    }
    search = COLUMN_MOLD_ID;
}

void WarehouseDele::refreshCabinetList() {
    QString sql = "select 货柜名称 from cabinet_message order by 货柜名称 asc;";
    search = COLUMN_CABINET_NAME;
    Find_ID(sql, search);
}

void WarehouseDele::refreshContainerList() {
    QString sql = "select 货柜名称 from container_message order by 货柜名称 asc;";
    search = COLUMN_CABINET_NAME;
    Find_ID(sql, search);
}

// ==================== 删除相关函数 ====================

bool WarehouseDele::deleteMold() {
    if(id_value.isEmpty()) {
        QMessageBox::warning(this, "删除模具", "请选择模具", QMessageBox::Cancel);
        return false;
    }
    QString question = "您确定要删除 " + id_value + "(" + nameCount + "个备件) 吗？";
    int reply = QMessageBox::question(this, "删除模具", question, QMessageBox::Yes | QMessageBox::No);
    if(reply != QMessageBox::Yes) {
        return false;
    }
    QSqlDatabase::database().transaction();
    QSqlQuery query;
    QString sparePartTable = getSparePartTableName();
    // 删除备件数据
    query.prepare(QString("delete from %1 where 模具编号 = :mold_id").arg(sparePartTable));
    query.bindValue(":mold_id", id_value);
    if(!query.exec()) {
        QSqlDatabase::database().rollback();
        QMessageBox::warning(this, "删除模具", "备件数据删除失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    // 删除模具数据
    query.prepare("delete from mold_message where 模具编号 = :mold_id");
    query.bindValue(":mold_id", id_value);
    if(!query.exec()) {
        QSqlDatabase::database().rollback();
        QMessageBox::warning(this, "删除模具", "模具数据删除失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    // 删除模具信息列表数据
    query.prepare("delete from information_message where 模具编号 = :mold_id");
    query.bindValue(":mold_id", id_value);
    if(!query.exec()) {
        QSqlDatabase::database().rollback();
        QMessageBox::warning(this, "删除模具", "模具信息列表数据删除失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    QSqlDatabase::database().commit();
    QMessageBox::information(this, "删除模具", "模具删除成功", QMessageBox::Ok);
    refreshMoldList();
    ui->NumLabel->clear();
    id_value.clear();
    emit mysignal();
    return true;
}

bool WarehouseDele::deleteSparePartCabinet() {
    if(id_value.isEmpty()) {
        QMessageBox::warning(this, "删除备件货柜", "请选择货柜", QMessageBox::Cancel);
        return false;
    }
    QString question = "您确定要删除 " + id_value + "吗？";
    int reply = QMessageBox::question(this, "删除备件货柜", question, QMessageBox::Yes | QMessageBox::No);
    if(reply != QMessageBox::Yes) {
        return false;
    }
    QSqlDatabase::database().transaction();
    QSqlQuery query;
    // 删除货柜
    query.prepare("delete from cabinet_message where 货柜名称 = :cabinet");
    query.bindValue(":cabinet", id_value);
    if(!query.exec()) {
        QSqlDatabase::database().rollback();
        QMessageBox::warning(this, "删除备件货柜", "备件货柜数据删除失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    // 更新备件数据
    QString sparePartTable = getSparePartTableName();
    QString cabinetColumn = getSparePartCabinetColumn();
    query.prepare(QString("update %1 set %2 = NULL where %2 = :cabinet").arg(sparePartTable, cabinetColumn));
    query.bindValue(":cabinet", id_value);
    if(!query.exec()) {
        QSqlDatabase::database().rollback();
        QMessageBox::warning(this, "删除备件货柜", "备件货柜数据更新失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    QSqlDatabase::database().commit();
    QMessageBox::information(this, "删除备件货柜", "备件货柜删除成功", QMessageBox::Ok);
    refreshCabinetList();
    id_value.clear();
    emit mysignal();
    return true;
}

bool WarehouseDele::deleteMoldCabinet() {
    if(id_value.isEmpty()) {
        QMessageBox::warning(this, "删除模具货柜", "请选择货柜", QMessageBox::Cancel);
        return false;
    }
    QString question = "您确定要删除 " + id_value + "吗？";
    int reply = QMessageBox::question(this, "删除模具货柜", question, QMessageBox::Yes | QMessageBox::No);
    if(reply != QMessageBox::Yes) {
        return false;
    }
    QSqlDatabase::database().transaction();
    QSqlQuery query;
    // 删除货柜
    query.prepare("delete from container_message where 货柜名称 = :container");
    query.bindValue(":container", id_value);
    if(!query.exec()) {
        QSqlDatabase::database().rollback();
        QMessageBox::warning(this, "删除模具货柜", "模具货柜数据删除失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    // 更新模具数据
    QString moldTable = getMoldTableName();
    QString cabinetColumn = getMoldCabinetColumn();
    query.prepare(QString("update %1 set %2 = NULL where %2 = :container").arg(moldTable, cabinetColumn));
    query.bindValue(":container", id_value);
    if(!query.exec()) {
        QSqlDatabase::database().rollback();
        QMessageBox::warning(this, "删除模具货柜", "模具数据更新失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    QSqlDatabase::database().commit();
    QMessageBox::information(this, "删除模具货柜", "模具货柜删除成功", QMessageBox::Ok);
    refreshContainerList();
    id_value.clear();
    emit mysignal();
    return true;
}

// ==================== 添加相关函数 ====================

bool WarehouseDele::insertCabinet(const QString &tableName, const QString &cabinetName) {
    QSqlQuery query;
    QString sql =
        QString("insert into %1 (货柜名称) select :cabinet_name where not exists (select 1 from %1 where 货柜名称 = :cabinet_name)").arg(
        tableName);
    query.prepare(sql);
    query.bindValue(":cabinet_name", cabinetName);
    if(!query.exec()) {
        QMessageBox::warning(this, "添加货柜", "货柜数据插入失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    if(!query.numRowsAffected()) {
        QMessageBox::warning(this, "添加货柜", "该货柜已存在", QMessageBox::Cancel);
        return false;
    }
    return true;
}

void WarehouseDele::updateUIAfterAddCabinet(const QString &cabinetType) {
    QSettings config("userconfig.ini", QSettings::IniFormat);
    config.setValue("SELECTIONCONFIG/Select3", ui->CabinetEdit->text());
    config.sync();
    ui->Label1->hide();
    ui->NumLabel->hide();
    ui->ChangeButton->hide();
    ui->ShowLabel->setText(cabinetType + "⬋");
    search = COLUMN_CABINET_NAME;
    state = true;
    save = cabinetType;
    if(cabinetType == CABINET_SPARE) {
        refreshCabinetList();
    } else {
        refreshContainerList();
    }
    emit mysignal();
}

void WarehouseDele::addCabinet() {
    if(ui->CabinetEdit->text().isEmpty()) {
        QMessageBox::warning(this, "添加货柜", "请输入货柜名称", QMessageBox::Cancel);
        return;
    }
    QString tableName;
    QString cabinetType;
    if(save == CABINET_SPARE) {
        tableName = "cabinet_message";
        cabinetType = CABINET_SPARE;
    } else if(save == CABINET_MOLD) {
        tableName = "container_message";
        cabinetType = CABINET_MOLD;
    } else {
        return;
    }
    if(!insertCabinet(tableName, ui->CabinetEdit->text())) {
        return;
    }
    QMessageBox::information(this, "添加货柜", "货柜添加成功", QMessageBox::Ok);
    updateUIAfterAddCabinet(cabinetType);
}

// ==================== UI事件处理槽函数 ====================

void WarehouseDele::on_pushButton_1_clicked() {
    if(!state) {
        deleteMold();
    } else {
        if(save == CABINET_SPARE) {
            deleteSparePartCabinet();
        } else if(save == CABINET_MOLD) {
            deleteMoldCabinet();
        }
    }
}

void WarehouseDele::on_pushButton_2_clicked() {
    addCabinet();
}

void WarehouseDele::on_CabinetEdit_returnPressed() {
    addCabinet();
}

void WarehouseDele::on_pushButton_3_clicked() {
    id_value.clear();
    state = !state;
    ui->NumLabel->clear();
    if(state) {
        ui->Label1->hide();
        ui->NumLabel->hide();
        ui->ChangeButton->hide();
        ui->ChangeButtonc->show();
        ui->ShowLabel->setText(CABINET_SPARE + "⬋");
        refreshCabinetList();
    } else {
        ui->Label1->show();
        ui->NumLabel->show();
        ui->ChangeButton->show();
        ui->ChangeButtonc->hide();
        ui->ShowLabel->setText(part + "模具类别⬋");
        refreshMoldList();
    }
}

void WarehouseDele::on_ChangeButton_toggled(bool checked) {
    id_value.clear();
    if(checked) {
        part = PART_FORMING;
        ui->ChangeButton->setText("切换为冲压备件");
    } else {
        part = PART_STAMPING;
        ui->ChangeButton->setText("切换为成型备件");
    }
    ui->ShowLabel->setText(part + "模具类别⬋");
    refreshMoldList();
}

void WarehouseDele::on_ChangeButtonc_clicked(bool checked) {
    id_value.clear();
    if(checked) {
        save = CABINET_MOLD;
        ui->ChangeButtonc->setText("切换为备件货柜");
        refreshContainerList();
    } else {
        save = CABINET_SPARE;
        ui->ChangeButtonc->setText("切换为模具货柜");
        refreshCabinetList();
    }
    ui->ShowLabel->setText(save + "⬋");
}

void WarehouseDele::on_PIDView_clicked(const QModelIndex &index) {
    id_value = index.data().toString();
    if(state) {
        return;
    }
    QSqlQuery query;
    QString sparePartTable = getSparePartTableName();
    query.prepare(QString("select count(*) from %1 where 模具编号 = :mold_id").arg(sparePartTable));
    query.bindValue(":mold_id", id_value);
    if(!query.exec()) {
        QMessageBox::warning(this, "查询备件数据", "备件数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        nameCount = query.value(0).toString();
        ui->NumLabel->setText(nameCount);
    }
}
