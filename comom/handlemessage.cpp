#include "handlemessage.h"
#include "ui_handlemessage.h"
#include "chonya/chonyaadd.h"
#include "chonya/chonyakeep.h"
#include "sumo/sumoadd.h"
#include "sumo/sumokeep.h"
#include "warehouse/warehouseadd.h"
#include "warehouse/warehouseenter.h"
#include "comom/handleworks.h"
#include "comom/emailwindow.h"
#include <QTableView>

// 常量定义
const int HandleMessage::EXCEL_START_ROW;
const int HandleMessage::COLUMN_COUNT_MOLD;
const int HandleMessage::COLUMN_COUNT_USER;

// ==================== 构造函数和析构函数 ====================

HandleMessage::HandleMessage(QVariant authority, QVariant name, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HandleMessage)
    , sumoAdd(nullptr)
    , sumoKeep(nullptr)
    , chonyaAdd(nullptr)
    , chonyaKeep(nullptr)
    , warehouseAdd(nullptr)
    , warehouseEnter(nullptr)
    , handleWorks(nullptr)
    , emailWin(nullptr)
    , standardModel1(nullptr)
    , standardModel2(nullptr)
    , namevalue_(name)
    , authvalue_(authority)
    , curr_name(name.toString())
    , curr_auth(authority.toBool()) {
    ui->setupUi(this);
    // 初始化滚动器
    QScroller *pScroller1 = QScroller::scroller(ui->SystemMessage);
    pScroller1->grabGesture(ui->SystemMessage->viewport(), QScroller::LeftMouseButtonGesture);
    ui->SystemMessage->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QScroller *pScroller2 = QScroller::scroller(ui->UserMessage);
    pScroller2->grabGesture(ui->UserMessage->viewport(), QScroller::LeftMouseButtonGesture);
    ui->UserMessage->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    // 初始化Excel格式
    Song12C.setFontSize(12);
    Song12C.setFontName("宋体");
    Song12C.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    Song12C.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    // 初始化UI
    ui->HandleButton1->setVisible(false);
    ui->HandleButton2->setVisible(false);
    // 刷新数据
    refresh_data();
}

HandleMessage::~HandleMessage() {
    // 释放数据模型
    delete standardModel1;
    delete standardModel2;
    // 释放窗口指针（Qt的父子关系会自动处理，但显式删除更安全）
    delete sumoAdd;
    delete sumoKeep;
    delete chonyaAdd;
    delete chonyaKeep;
    delete warehouseAdd;
    delete warehouseEnter;
    delete handleWorks;
    delete emailWin;
    // 释放UI
    delete ui;
}

// ==================== 事件处理 ====================

void HandleMessage::closeEvent(QCloseEvent *event) {
    Q_UNUSED(event);
    if(QWidget *target = m_windowMap.value(tr("发送邮件"))) {
        if(!target->isHidden()) {
            target->close();
            target->deleteLater();
            m_windowMap.remove(tr("发送邮件"));
        }
    }
    QMainWindow::closeEvent(event);
}

// ==================== 辅助函数 ====================

QString HandleMessage::getDatabaseName() const {
    QSqlDatabase currentDb = QSqlDatabase::database();
    return currentDb.databaseName();
}

bool HandleMessage::isMoldDatabase() const {
    QString dbName = getDatabaseName();
    return (dbName == "chonya" || dbName == "sumo");
}

bool HandleMessage::isWarehouseDatabase() const {
    return (getDatabaseName() == "warehouse");
}

QStandardItemModel *HandleMessage::createModelFromQuery(QSqlQuery &query, QTableView *view) {
    QSqlQueryModel *tempModel = new QSqlQueryModel(view);
    tempModel->setQuery(query);
    QStandardItemModel *model = new QStandardItemModel(tempModel->rowCount(), tempModel->columnCount(), this);
    // 复制数据
    for(int row = 0; row < tempModel->rowCount(); ++row) {
        for(int column = 0; column < tempModel->columnCount(); ++column) {
            QModelIndex index = tempModel->index(row, column);
            QVariant value = tempModel->data(index);
            model->setItem(row, column, new QStandardItem(value.toString()));
        }
    }
    // 复制表头
    for(int column = 0; column < tempModel->columnCount(); ++column) {
        QString columnName = tempModel->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
        model->setHeaderData(column, Qt::Horizontal, columnName);
    }
    delete tempModel;
    return model;
}

void HandleMessage::setupTableView(QTableView *view, int columnCount, const QList<int> &columnWidths) {
    view->horizontalHeader()->setVisible(true);
    view->verticalHeader()->setVisible(true);
    view->horizontalHeader()->setStretchLastSection(true);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->resizeRowsToContents();
    for(int i = 0; i < columnWidths.size() && i < columnCount; ++i) {
        view->setColumnWidth(i, columnWidths[i]);
    }
}

// ==================== 数据刷新 ====================

void HandleMessage::refresh_data() {
    // 释放旧模型
    delete standardModel1;
    delete standardModel2;
    standardModel1 = nullptr;
    standardModel2 = nullptr;
    QString sql;
    QString databaseName = getDatabaseName();
    // 查询系统消息
    if(isMoldDatabase()) {
        sql = "SELECT 日期,模具编号,模具性质,信息 FROM information_message "
              "WHERE 发送用户 = '系统' AND (接收用户 = :user_name OR 接收用户 = '所有人') AND 完成情况 = '1'";
    } else {
        sql = "SELECT 日期,模具编号,备件号,信息 FROM information_message "
              "WHERE 发送用户 = '系统' AND (接收用户 = :user_name OR 接收用户 = '所有人') AND 完成情况 = '1'";
    }
    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":user_name", curr_name);
    if(!query.exec()) {
        QMessageBox::warning(this, "刷新数据", "系统信息列表数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    standardModel1 = createModelFromQuery(query, ui->SystemMessage);
    if(standardModel1) {
        ui->SystemMessage->setModel(standardModel1);
        QList<int> widths = {130, 120, 120, 200};
        setupTableView(ui->SystemMessage, COLUMN_COUNT_MOLD, widths);
    }
    // 查询用户消息
    if(isMoldDatabase()) {
        sql = "SELECT 日期,模具编号,模具性质,发送用户,信息 FROM information_message "
              "WHERE IFNULL(发送用户,'') != '系统' AND (接收用户 = :user_name OR 接收用户 = '所有人') AND 完成情况 = '1'";
    } else {
        sql = "SELECT 日期,模具编号,备件号,发送用户,信息 FROM information_message "
              "WHERE IFNULL(发送用户,'') != '系统' AND (接收用户 = :user_name OR 接收用户 = '所有人') AND 完成情况 = '1'";
    }
    query.prepare(sql);
    query.bindValue(":user_name", curr_name);
    if(!query.exec()) {
        QMessageBox::warning(this, "刷新数据", "用户信息列表数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    standardModel2 = createModelFromQuery(query, ui->UserMessage);
    if(standardModel2) {
        ui->UserMessage->setModel(standardModel2);
        QList<int> widths = {130, 120, 120, 120, 200};
        setupTableView(ui->UserMessage, COLUMN_COUNT_USER, widths);
    }
    // 清空选择
    id_value1.clear();
    id_value2.clear();
}

// ==================== 任务状态更新 ====================

bool HandleMessage::updateTaskStatus(const QString &moldId, bool isSystemMessage) {
    if(moldId.isEmpty()) {
        QMessageBox::warning(this, "完成任务", "设置失败：\n请选择信息", QMessageBox::Cancel);
        return false;
    }
    QString question = QString("您确定要完成该任务(%1) 吗？").arg(moldId);
    int reply = QMessageBox::question(this, "完成任务", question, QMessageBox::Yes | QMessageBox::No);
    if(reply != QMessageBox::Yes) {
        return false;
    }
    QSqlQuery query;
    if(isSystemMessage) {
        query.prepare("UPDATE information_message SET 完成情况 = '0' WHERE 模具编号 = :mold_id AND 发送用户 = '系统'");
    } else {
        query.prepare("UPDATE information_message SET 完成情况 = '0' WHERE IFNULL(发送用户,'') != '系统' AND 模具编号 = :mold_id");
    }
    query.bindValue(":mold_id", moldId);
    if(!query.exec()) {
        QMessageBox::warning(this, "完成任务", "设置失败：\n" + query.lastError().text(), QMessageBox::Cancel);
        return false;
    }
    QMessageBox::information(this, "完成任务", "设置成功", QMessageBox::Ok);
    refresh_data();
    return true;
}

// ==================== UI事件处理 ====================

void HandleMessage::on_SystemMessage_clicked(const QModelIndex &index) {
    if(!standardModel1 || index.row() < 0)
        return;
    QModelIndex data_index = standardModel1->index(index.row(), 1);
    id_value1 = data_index.data().toString();
    data_index = standardModel1->index(index.row(), 2);
    spare = data_index.data().toString();
    curr_user = "系统"; // 系统消息默认用户
}

void HandleMessage::on_UserMessage_clicked(const QModelIndex &index) {
    if(!standardModel2 || index.row() < 0)
        return;
    QModelIndex data_index = standardModel2->index(index.row(), 1);
    id_value2 = data_index.data().toString();
    data_index = standardModel2->index(index.row(), 3);
    curr_user = data_index.data().toString();
}

void HandleMessage::on_FinishedButton1_clicked() {
    updateTaskStatus(id_value1, true);
}

void HandleMessage::on_FinishedButton2_clicked() {
    updateTaskStatus(id_value2, false);
}

void HandleMessage::on_HandleButton1_clicked() {
    handleTask(id_value1, spare);
}

void HandleMessage::on_HandleButton2_clicked() {
    handleTask(id_value2, spare);
}

void HandleMessage::on_EmailButton_clicked() {
    emailWin = new EmailWindow(curr_user, this);
    emailWin->setWindowTitle("发送邮件");
    m_windowMap.insert(tr("发送邮件"), emailWin);
    emailWin->show();
}

void HandleMessage::enable_window() {
    if(ui && ui->centralwidget) {
        ui->centralwidget->setEnabled(true);
    }
}

// ==================== 任务处理相关函数 ====================

void HandleMessage::handleTask(const QString &moldId, const QString &sparePart) {
    if(moldId.isEmpty()) {
        QMessageBox::warning(this, "处理任务", "请选择信息", QMessageBox::Cancel);
        return;
    }
    if(moldId == "版本更新") {
        QDesktopServices::openUrl(QUrl("file://192.168.101.250/模具管理系统/", QUrl::TolerantMode));
        return;
    }
    showTaskDialog(curr_auth, moldId, sparePart);
}

void HandleMessage::showTaskDialog(bool hasAuth, const QString &moldId, const QString &sparePart) {
    QString databaseName = getDatabaseName();
    if(isMoldDatabase()) {
        handleMoldDatabaseTask(hasAuth, moldId);
    } else if(isWarehouseDatabase()) {
        handleWarehouseDatabaseTask(hasAuth, moldId, sparePart);
    }
}

void HandleMessage::handleMoldDatabaseTask(bool hasAuth, const QString &moldId) {
    QMessageBox choice_box;
    choice_box.setWindowTitle("处理任务");
    choice_box.setText("请选择您的处理方式：");
    QPushButton *button1 = nullptr;
    QPushButton *button2 = nullptr;
    QPushButton *button3 = nullptr;
    if(hasAuth) {
        button1 = choice_box.addButton("添加模具备件", QMessageBox::ActionRole);
        button2 = choice_box.addButton("关单保养", QMessageBox::ActionRole);
        button3 = choice_box.addButton("工单信息管理", QMessageBox::ActionRole);
    } else {
        button2 = choice_box.addButton("关单保养", QMessageBox::ActionRole);
        button3 = choice_box.addButton("工单信息管理", QMessageBox::ActionRole);
    }
    choice_box.addButton("取消", QMessageBox::RejectRole);
    choice_box.exec();
    QString databaseName = getDatabaseName();
    QAbstractButton *clickedButton = choice_box.clickedButton();
    if(clickedButton == button1) {
        if(databaseName == "chonya") {
            openChonyaAdd();
        } else if(databaseName == "sumo") {
            openSumoAdd();
        }
    } else if(clickedButton == button2) {
        if(databaseName == "chonya") {
            openChonyaKeep(moldId);
        } else if(databaseName == "sumo") {
            openSumoKeep(moldId);
        }
    } else if(clickedButton == button3) {
        openHandleWorks(moldId);
    }
}

void HandleMessage::handleWarehouseDatabaseTask(bool hasAuth, const QString &moldId, const QString &sparePart) {
    if(hasAuth) {
        QMessageBox choice_box;
        choice_box.setWindowTitle("处理任务");
        choice_box.setText("请选择您的处理方式：");
        QPushButton *button1 = choice_box.addButton("添加模具备件", QMessageBox::ActionRole);
        QPushButton *button2 = choice_box.addButton("模具备件入库", QMessageBox::ActionRole);
        choice_box.addButton("取消", QMessageBox::RejectRole);
        choice_box.exec();
        if(choice_box.clickedButton() == button1) {
            openWarehouseAdd();
        } else if(choice_box.clickedButton() == button2) {
            openWarehouseEnter(moldId, sparePart);
        }
    } else {
        openWarehouseEnter(moldId, sparePart);
    }
}

void HandleMessage::openChonyaAdd() {
    if(chonyaAdd) {
        chonyaAdd->deleteLater();
    }
    chonyaAdd = new ChonyaAdd(this);
    connect(chonyaAdd, SIGNAL(mysignal()), this, SLOT(refresh_data()));
    chonyaAdd->setWindowTitle("添加模具备件");
    chonyaAdd->show();
}

void HandleMessage::openChonyaKeep(const QString &moldId) {
    if(chonyaKeep) {
        chonyaKeep->deleteLater();
    }
    chonyaKeep = new ChonyaKeep(moldId, 2, this);
    chonyaKeep->setWindowTitle("关单保养");
    chonyaKeep->show();
}

void HandleMessage::openSumoAdd() {
    if(sumoAdd) {
        sumoAdd->deleteLater();
    }
    sumoAdd = new SumoAdd(this);
    connect(sumoAdd, SIGNAL(mysignal()), this, SLOT(refresh_data()));
    sumoAdd->setWindowTitle("添加模具备件");
    sumoAdd->show();
}

void HandleMessage::openSumoKeep(const QString &moldId) {
    if(sumoKeep) {
        sumoKeep->deleteLater();
    }
    sumoKeep = new SumoKeep(moldId, 2, this);
    sumoKeep->setWindowTitle("关单保养");
    sumoKeep->show();
}

void HandleMessage::openWarehouseAdd() {
    if(warehouseAdd) {
        warehouseAdd->deleteLater();
    }
    warehouseAdd = new WarehouseAdd(this);
    connect(warehouseAdd, SIGNAL(mysignal()), this, SLOT(refresh_data()));
    warehouseAdd->setWindowTitle("添加模具备件");
    warehouseAdd->show();
}

void HandleMessage::openWarehouseEnter(const QString &moldId, const QString &sparePart) {
    if(warehouseEnter) {
        warehouseEnter->deleteLater();
    }
    warehouseEnter = new WarehouseEnter("chonya_message", moldId, sparePart, "", this);
    connect(warehouseEnter, SIGNAL(mysignal()), this, SLOT(refresh_data()));
    warehouseEnter->setWindowTitle("模具备件入库");
    warehouseEnter->show();
}

void HandleMessage::openHandleWorks(const QString &moldId) {
    if(handleWorks) {
        handleWorks->deleteLater();
    }
    ui->centralwidget->setEnabled(false);
    QString databaseName = getDatabaseName();
    handleWorks = new HandleWorks(databaseName, moldId, curr_name, this);
    connect(handleWorks, SIGNAL(enablesignal()), this, SLOT(enable_window()));
    handleWorks->setWindowTitle("工单信息管理");
    handleWorks->show();
}

// ==================== 导出功能 ====================

void HandleMessage::exportSystemMessages(const QString &templatePath, const QString &title, const QString &fileName) {
    QXlsx::Document xlsx1(templatePath);
    // QXlsx::Document 构造函数会自动加载文件，如果文件不存在或无效，后续操作会失败
    // 可以通过检查 dimension() 来判断文件是否有效
    if(xlsx1.dimension().rowCount() == 0 && xlsx1.dimension().columnCount() == 0) {
        QMessageBox::critical(this, "导出信息列表",
            QString("%1模板加载失败，请检查模板文件是否存在").arg(title));
        return;
    }
    QString sql;
    if(isMoldDatabase()) {
        sql = "SELECT 日期,模具编号,模具性质,信息 FROM information_message "
              "WHERE 发送用户 = '系统' AND (接收用户 = :user_name OR 接收用户 = '所有人') AND 完成情况 = '1'";
    } else {
        sql = "SELECT 日期,模具编号,备件号,信息 FROM information_message "
              "WHERE 发送用户 = '系统' AND (接收用户 = :user_name OR 接收用户 = '所有人') AND 完成情况 = '1'";
    }
    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":user_name", curr_name);
    if(!query.exec()) {
        QMessageBox::warning(this, "导出信息列表",
            QString("%1导出失败：\n%2").arg(title).arg(query.lastError().text()), QMessageBox::Cancel);
        return;
    }
    int row = EXCEL_START_ROW;
    while(query.next()) {
        for(int i = 0; i < COLUMN_COUNT_MOLD; ++i) {
            xlsx1.write(row, i + 1, query.value(i).toString(), Song12C);
        }
        row++;
    }
    QSettings config("userconfig.ini", QSettings::IniFormat);
    QString defaultPath = config.value("DOCUMENTCONFIG/DocumentPath").toString() + fileName;
    QString saveFileName = QFileDialog::getSaveFileName(this, QString("导出%1").arg(title), defaultPath,
        "Excel Files (*.xlsx)");
    if(saveFileName.isEmpty()) {
        return;
    }
    QString file_temp = saveFileName;
    file_temp = file_temp.left(file_temp.lastIndexOf('/')) + "/";
    config.setValue("DOCUMENTCONFIG/DocumentPath", file_temp);
    if(!saveFileName.endsWith(".xlsx")) {
        saveFileName.append(".xlsx");
    }
    if(!xlsx1.saveAs(saveFileName)) {
        QMessageBox::critical(this, "导出信息列表", QString("%1创建失败").arg(title));
    }
}

void HandleMessage::on_CheckButton_clicked() {
    QString databaseName = getDatabaseName();
    if(isMoldDatabase()) {
        exportSystemMessages(":/ducument/information_mold.xlsx", "模具保养预警信息表", "模具保养预警信息表");
    } else if(isWarehouseDatabase()) {
        exportSystemMessages(":/ducument/information_warehouse.xlsx", "模具备件预警信息表",
            "模具备件预警信息表");
    }
}
