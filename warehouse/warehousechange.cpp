#include "warehousechange.h"
#include "ui_warehousechange.h"

#include <QDebug>
#include <QMovie>
#include <QSqlQuery>
#include <QSqlError>
#include <QListView>
#include <QScroller>
#include <QCompleter>
#include <QMessageBox>
#include <QAbstractItemView>
#include <QStyledItemDelegate>

// ==================== 构造函数和析构函数 ====================

WarehouseChange::WarehouseChange(QVariant id_value, QVariant part_value, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WarehouseChange)
    , idvalue_(id_value)
    , partvalue_(part_value) {
    ui->setupUi(this);
    curr_id = id_value.toString();
    curr_part = part_value.toString();
    // 初始化加载动画
    QMovie *movie = new QMovie(this);
    movie->setFileName(":/images/machine_load.gif");
    ui->LoadingLabel->setMovie(movie);
    movie->start();
    // 设置容器下拉框的滚动效果
    QListView *listView1 = qobject_cast<QListView *>(ui->ContainerCombo->view());
    if(listView1) {
        QScroller *Scroller1 = QScroller::scroller(listView1);
        Scroller1->grabGesture(listView1->viewport(), QScroller::LeftMouseButtonGesture);
        listView1->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    }
    // 初始化容器下拉框
    if(!initializeContainerCombo()) {
        QMessageBox::critical(this, "界面初始化", "容器下拉框初始化失败，窗口将关闭。", QMessageBox::Ok);
        return;
    }
    // 加载模具数据
    if(!loadMoldData()) {
        QMessageBox::critical(this, "界面初始化", "模具数据加载失败，窗口将关闭。", QMessageBox::Ok);
        return;
    }
}

WarehouseChange::~WarehouseChange() {
    delete ui;
}

// ==================== 私有槽函数 ====================

void WarehouseChange::on_EditButton_clicked() {
    // 输入验证
    if(!validateInput()) {
        return;
    }
    // 使用参数化查询防止SQL注入
    QSqlQuery query;
    QString sql = QString("UPDATE %1 SET 产品料号 = :material_id, "
                          "模具尺寸 = :mould, "
                          "当前状态 = :status, "
                          "存放货柜 = :container "
                          "WHERE 模具编号 = :mold_id").arg(curr_part);
    query.prepare(sql);
    query.bindValue(":material_id", ui->ProductID->toPlainText());
    query.bindValue(":mould", ui->MouldEdit->text());
    query.bindValue(":status", ui->StatusCombo->currentText());
    query.bindValue(":container", ui->ContainerCombo->currentText());
    query.bindValue(":mold_id", curr_id);
    if(!query.exec()) {
        QMessageBox::warning(this, "模具参数修改",
            "模具数据更新失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    QMessageBox::information(this, "模具参数修改", "模具参数修改成功", QMessageBox::Ok);
    emit mysignal();
}

// ==================== 私有辅助函数 ====================

bool WarehouseChange::initializeContainerCombo() {
    QSqlQuery query;
    QStringList container_list;
    // 使用参数化查询
    query.prepare("SELECT 货柜名称 FROM container_message");
    if(!query.exec()) {
        QMessageBox::warning(this, "界面初始化",
            "货柜数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    while(query.next()) {
        container_list.append(query.value(0).toString());
    }
    ui->ContainerCombo->addItems(container_list);
    // 创建自动完成器
    QCompleter *containerCompleter = new QCompleter(container_list, this);
    containerCompleter->setMaxVisibleItems(10);
    containerCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    containerCompleter->setCompletionMode(QCompleter::PopupCompletion);
    containerCompleter->setFilterMode(Qt::MatchContains);
    ui->ContainerCombo->setCompleter(containerCompleter);
    // 设置样式委托
    QStyledItemDelegate *delegate = new QStyledItemDelegate(this);
    QString style = "QAbstractItemView{font: 18pt \"微软雅黑\";background-color:rgb(255,255,255);color:rgb(0,0,0);}"
                    "QAbstractItemView::item:hover{background-color:rgb(0, 120, 212)}";
    containerCompleter->popup()->setItemDelegate(delegate);
    containerCompleter->popup()->setStyleSheet(style);
    ui->ContainerCombo->setCurrentText("");
    return true;
}

bool WarehouseChange::loadMoldData() {
    QSqlQuery query;
    // 使用参数化查询防止SQL注入
    // 注意：表名不能使用参数化，需要验证curr_part的安全性
    QString sql = QString("SELECT * FROM %1 WHERE 模具编号 = :mold_id").arg(curr_part);
    query.prepare(sql);
    query.bindValue(":mold_id", curr_id);
    if(!query.exec()) {
        QMessageBox::warning(this, "界面初始化",
            "模具数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    if(query.next()) {
        ui->MoldID->setText(query.value("模具编号").toString());
        ui->ProductID->setText(query.value("产品料号").toString());
        ui->MouldEdit->setText(query.value("模具尺寸").toString());
        ui->StatusCombo->setCurrentText(query.value("当前状态").toString());
        ui->ContainerCombo->setCurrentText(query.value("存放货柜").toString());
        return true;
    }
    QMessageBox::warning(this, "界面初始化", "未找到对应的模具数据", QMessageBox::Cancel);
    return false;
}

bool WarehouseChange::executeQuery(const QString &sql, const QString &errorTitle) {
    QSqlQuery query;
    if(!query.exec(sql)) {
        QMessageBox::warning(this, errorTitle,
            "查询执行失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    return true;
}

bool WarehouseChange::validateInput() const {
    // 验证模具编号
    if(ui->MoldID->text().trimmed().isEmpty()) {
        QMessageBox::warning(const_cast<WarehouseChange*>(this), "输入验证",
            "模具编号不能为空", QMessageBox::Ok);
        return false;
    }
    // 验证产品料号
    if(ui->ProductID->toPlainText().trimmed().isEmpty()) {
        QMessageBox::warning(const_cast<WarehouseChange*>(this), "输入验证",
            "产品料号不能为空", QMessageBox::Ok);
        return false;
    }
    // 验证当前状态
    if(ui->StatusCombo->currentText().trimmed().isEmpty()) {
        QMessageBox::warning(const_cast<WarehouseChange*>(this), "输入验证",
            "当前状态不能为空", QMessageBox::Ok);
        return false;
    }
    return true;
}
