#include "warehousemold.h"
#include "ui_warehousemold.h"

// 常量定义
const QString WarehouseMold::PART_CHENGXING = "chengxing_message";
const QString WarehouseMold::PART_CHONYA = "chonya_message";
const QString WarehouseMold::PART_NAME_CHENGXING = "成型";
const QString WarehouseMold::PART_NAME_CHONYA = "冲压";

WarehouseMold::WarehouseMold(QVariant part_value, QVariant mold_value, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::WarehouseMold), moldvalue_(mold_value) {
    ui->setupUi(this);
    part = part_value.toString();
    mold = mold_value.toString();
    initializeUI();
    setupScroller();
    loadMoldList();
    selectInitialMold(mold_value.toString());
    loadMoldDetails(mold);
}

WarehouseMold::~WarehouseMold() {
    delete ui;
}

QString WarehouseMold::getPartName() const {
    return (part == PART_CHENGXING) ? PART_NAME_CHENGXING : PART_NAME_CHONYA;
}

void WarehouseMold::initializeUI() {
    ui->PartCombo->addItems({PART_NAME_CHONYA, PART_NAME_CHENGXING});
    if(part == PART_CHENGXING) {
        ui->ChangeButton->setChecked(true);
        ui->ChangeButton->setText("切换为冲压模具");
    }
    if(mold.isEmpty()) {
        ui->Label1->setStyleSheet("color:red;");
    } else {
        ui->Label1->setStyleSheet("color:black;");
    }
}

void WarehouseMold::setupScroller() {
    QScroller *pScroller = QScroller::scroller(ui->MoldView);
    pScroller->grabGesture(ui->MoldView->viewport(), QScroller::LeftMouseButtonGesture);
    ui->MoldView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
}

void WarehouseMold::loadMoldList() {
    updateMoldView(getPartName());
}

void WarehouseMold::selectInitialMold(const QString &mold_value) {
    QAbstractItemModel *model = ui->MoldView->model();
    if(!model) {
        return;
    }
    QModelIndexList matches = model->match(model->index(0, 0), Qt::DisplayRole, mold_value, 1, Qt::MatchExactly);
    if(!matches.isEmpty()) {
        QModelIndex index = matches.first();
        ui->MoldView->selectionModel()->select(index, QItemSelectionModel::ClearAndSelect | QItemSelectionModel::Rows);
        ui->MoldView->scrollTo(index);
    }
}

void WarehouseMold::updateMoldView(const QString &part_name) {
    // 释放旧模型
    QAbstractItemModel *oldModel = ui->MoldView->model();
    if(oldModel) {
        oldModel->deleteLater();
    }
    QStandardItemModel *model = new QStandardItemModel(this);
    QSqlQuery query;
    query.prepare("SELECT 模具编号 FROM mold_message WHERE 隶属部门 = :part_name");
    query.bindValue(":part_name", part_name);
    if(!query.exec()) {
        QMessageBox::warning(this, "模具列表加载", "模具列表查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        delete model;
        return;
    }
    while(query.next()) {
        QList<QStandardItem *> items;
        items.append(new QStandardItem(query.value(0).toString()));
        model->appendRow(items);
    }
    ui->MoldView->setModel(model);
}

void WarehouseMold::loadMoldDetails(const QString &mold_id) {
    if(mold_id.isEmpty()) {
        return;
    }
    QSqlQuery query;
    query.prepare("SELECT * FROM mold_message WHERE 模具编号 = :mold AND 隶属部门 = :part");
    query.bindValue(":mold", mold_id);
    query.bindValue(":part", getPartName());
    if(!query.exec()) {
        QMessageBox::warning(this, "模具数据查询", "模具数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        ui->Label1->setStyleSheet("color:black;");
        ui->MoldEdit->setText(query.value("模具编号").toString());
        ui->CustomEdit->setText(query.value("客户模号").toString());
        ui->PartCombo->setCurrentText(query.value("隶属部门").toString());
        ui->ProductEdit->setText(query.value("产品名称").toString());
        ui->MaterialEdit->setText(query.value("产品料号").toString());
        ui->DetailMaterial->setText(query.value("具体料号").toString());
        ui->DetailWork->setText(query.value("工站").toString());
        // 清除选择
        ui->ProductEdit->setSelection(0, 0);
        ui->MaterialEdit->setSelection(0, 0);
        ui->DetailMaterial->setSelection(0, 0);
        ui->DetailWork->setSelection(0, 0);
        // 查询备件数量
        int spareCount = getSpareCount(mold_id);
        ui->SpareNum->setText(QString::number(spareCount));
    }
}

int WarehouseMold::getSpareCount(const QString &mold_id) {
    QSqlQuery query;
    query.prepare(QString("SELECT COUNT(*) FROM %1 WHERE 模具编号 = :mold").arg(part));
    query.bindValue(":mold", mold_id);
    if(!query.exec()) {
        QMessageBox::warning(this, "备件数量查询", "备件数量查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return 0;
    }
    if(query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}

void WarehouseMold::searchMold(const QString &search_text) {
    // 释放旧模型
    QAbstractItemModel *oldModel = ui->MoldView->model();
    if(oldModel) {
        oldModel->deleteLater();
    }
    QStandardItemModel *model = new QStandardItemModel(this);
    QSqlQuery query;
    query.prepare("SELECT 模具编号 FROM mold_message WHERE 模具编号 LIKE :search_text AND 隶属部门 = :part_name");
    query.bindValue(":search_text", "%" + search_text + "%");
    query.bindValue(":part_name", getPartName());
    if(!query.exec()) {
        QMessageBox::warning(this, "模具搜索", "模具搜索失败：\n" + query.lastError().text(), QMessageBox::Cancel);
        delete model;
        return;
    }
    while(query.next()) {
        QList<QStandardItem *> items;
        items.append(new QStandardItem(query.value(0).toString()));
        model->appendRow(items);
    }
    ui->MoldView->setModel(model);
}

void WarehouseMold::on_MoldView_clicked(const QModelIndex &index) {
    mold = index.data().toString();
    loadMoldDetails(mold);
}

void WarehouseMold::on_EditButton_clicked() {
    if(mold.isEmpty()) {
        QMessageBox::warning(this, "模具参数修改", "请选择模具", QMessageBox::Cancel);
        return;
    }
    QSqlQuery query;
    query.prepare("UPDATE mold_message SET 模具编号 = :mold_id, 客户模号 = :custom_id, "
                  "产品名称 = :product_name, 产品料号 = :product_material, 隶属部门 = :part_id, "
                  "具体料号 = :detail_material, 工站 = :detail_work "
                  "WHERE 模具编号 = :mold AND 隶属部门 = :part");
    query.bindValue(":mold_id", ui->MoldEdit->text());
    query.bindValue(":custom_id", ui->CustomEdit->text());
    query.bindValue(":product_name", ui->ProductEdit->text());
    query.bindValue(":product_material", ui->MaterialEdit->text());
    query.bindValue(":detail_material", ui->DetailMaterial->text());
    query.bindValue(":detail_work", ui->DetailWork->text());
    query.bindValue(":part_id", ui->PartCombo->currentText());
    query.bindValue(":mold", mold);
    query.bindValue(":part", getPartName());
    if(!query.exec()) {
        QMessageBox::warning(this, "模具参数修改", "模具数据更新失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    // 更新备件表中的模具编号
    query.prepare(QString("UPDATE %1 SET 模具编号 = :mold_id WHERE 模具编号 = :mold").arg(part));
    query.bindValue(":mold_id", ui->MoldEdit->text());
    query.bindValue(":mold", mold);
    if(!query.exec()) {
        QMessageBox::warning(this, "模具参数修改", "备件表更新失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    QMessageBox::information(this, "模具参数修改", "模具参数修改成功", QMessageBox::Ok);
    updateMoldView(getPartName());
    emit mysignal();
}

void WarehouseMold::on_ChangeButton_toggled(bool checked) {
    if(checked) {
        part = PART_CHENGXING;
        ui->Label1->setText("选择成型模具⬋");
        ui->ChangeButton->setText("切换为冲压模具");
    } else {
        part = PART_CHONYA;
        ui->Label1->setText("选择冲压模具⬋");
        ui->ChangeButton->setText("切换为成型模具");
    }
    updateMoldView(getPartName());
}

void WarehouseMold::on_FindButton_clicked() {
    searchMold(ui->FMoldEdit->text());
}

void WarehouseMold::on_FMoldEdit_returnPressed() {
    searchMold(ui->FMoldEdit->text());
}

void WarehouseMold::on_ReturnButton_clicked() {
    this->close();
}
