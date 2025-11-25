#include "warehousewindow.h"
#include "ui_warehousewindow.h"

// ==================== Qt标准库 ====================
#include <QAbstractItemView>
#include <QApplication>
#include <QBrush>
#include <QCompleter>
#include <QDesktopServices>
#include <QFileDialog>
#include <QFont>
#include <QHeaderView>
#include <QIcon>
#include <QListView>
#include <QMenu>
#include <QProcess>
#include <QPointer>
#include <QPushButton>
#include <QScroller>
#include <QStyledItemDelegate>
#include <QUrl>

// ==================== Qt第三方库 ====================
#include "xlsxdocument.h"

// ==================== 业务类头文件 ====================
#include "comom/aiwindow.h"
#include "comom/databasewindow.h"
#include "comom/handledata.h"
#include "comom/handlemessage.h"
#include "comom/handleworks.h"
#include "warehouse/productwindow.h"
#include "warehouse/sparewindow.h"
#include "warehouse/warehouseadd.h"
#include "warehouse/warehousechange.h"
#include "warehouse/warehousedele.h"
#include "warehouse/warehouseedit.h"
#include "warehouse/warehouseenter.h"
#include "warehouse/warehouseout.h"
#include "warehouse/work/widget.h"

// ==================== 构造函数和析构函数 ====================

WarehouseWindow::WarehouseWindow(QVariant authority, QVariant name, QWidget *mainWin, QWidget *parent)
    : ui(new Ui::WarehouseWindow), mainWindow(mainWin), authvalue_(authority), namevalue_(name) {
    Q_UNUSED(parent);
    ui->setupUi(this);
    QScroller *pScroller1 = QScroller::scroller(ui->CyView);
    pScroller1->grabGesture(ui->CyView->viewport(), QScroller::LeftMouseButtonGesture);
    ui->CyView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QScroller *pScroller2 = QScroller::scroller(ui->CxView);
    pScroller2->grabGesture(ui->CxView->viewport(), QScroller::LeftMouseButtonGesture);
    ui->CxView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QScroller *pScroller3 = QScroller::scroller(ui->ModleList1);
    pScroller3->grabGesture(ui->ModleList1->viewport(), QScroller::LeftMouseButtonGesture);
    ui->ModleList1->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QScroller *pScroller4 = QScroller::scroller(ui->ModleList2);
    pScroller4->grabGesture(ui->ModleList2->viewport(), QScroller::LeftMouseButtonGesture);
    ui->ModleList2->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QListView *m_listView = qobject_cast<QListView *>(ui->ContainerCombo->view());
    QScroller *m_Scroller = QScroller::scroller(m_listView);
    m_Scroller->grabGesture(m_listView->viewport(), QScroller::LeftMouseButtonGesture);
    m_listView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    curr_auth = authority.toBool();
    if(curr_auth) {
        ui->AddButton->setEnabled(true);
        ui->DeleteButton->setEnabled(true);
        ui->DeleteButtonc->setEnabled(true);
        ui->EditButton->setEnabled(true);
        ui->ManageButton->setEnabled(true);
        ui->ChangeButtonc->setEnabled(true);
        ui->PriceEdit->setEchoMode(QLineEdit::EchoMode::Normal);
    }
    curr_name = name.toString();
    Song12C.setFontSize(12);
    Song12C.setFontName("宋体");
    Song12C.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    Song12C.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    trayIcon = new QSystemTrayIcon(this);
    QIcon trayIconIcon(":/images/app.ico");
    trayIcon->setIcon(trayIconIcon);
    QMenu *menu = new QMenu();
    QAction *workAction = menu->addAction("打开工单管理系统");
    QAction *showAction = menu->addAction("打开程序");
    QAction *closeAction = menu->addAction("关闭程序");
    trayIcon->setContextMenu(menu);
    connect(closeAction, &QAction::triggered, this, &WarehouseWindow::closeApplication);
    connect(showAction, &QAction::triggered, this, &WarehouseWindow::show);
    connect(workAction, &QAction::triggered, this, &WarehouseWindow::showWorkMessage);
    connect(trayIcon, &QSystemTrayIcon::activated, this, &WarehouseWindow::onTrayIconActivated);
    trayIcon->setToolTip("广东盟恩电子模具管理系统");
    trayIcon->show();
    trayIcon->showMessage("您好", "欢迎使用广东盟恩电子模具管理系统", QSystemTrayIcon::Information, 5);
    QMovie *movie1 = new QMovie(":/images/warehouse_load.gif");
    QMovie *movie2 = new QMovie(":/images/warehouse_load.gif");
    ui->LoadingLabel->setMovie(movie1);
    ui->LoadingLabelc->setMovie(movie2);
    movie1->start();
    movie2->start();
    QString sql;
    QSqlQuery query;
    QStyledItemDelegate *d = new QStyledItemDelegate;
    QString style = "QAbstractItemView{font: 18pt \"微软雅黑\";background-color:rgb(255,255,255);color:rgb(0,0,0);}"
                    "QAbstractItemView::item:hover{background-color:rgb(0, 120, 212)}";
    QStringList container_list;
    sql = QString("select 货柜名称 from container_message;");
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "界面初始化", "货柜名称查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        while(query.next()) {
            container_list.append(query.value(0).toString());
        }
    }
    ui->ContainerCombo->addItems(container_list);
    QCompleter *ContainerCompleter = new QCompleter(container_list, this);
    ContainerCompleter->setMaxVisibleItems(10);
    ContainerCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    ContainerCompleter->setCompletionMode(QCompleter::PopupCompletion);
    ContainerCompleter->setFilterMode(Qt::MatchContains);
    ui->ContainerCombo->setCompleter(ContainerCompleter);
    ContainerCompleter->popup()->setItemDelegate(d);
    ContainerCompleter->popup()->setStyleSheet(style);
    ui->ContainerCombo->setCurrentText("");
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &WarehouseWindow::refresh_information);
    timer->start(1000);
    ui->CyView->header()->setDefaultAlignment(Qt::AlignHCenter);
    ui->CyView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->CyView->setItemsExpandable(true);
    ui->CxView->header()->setDefaultAlignment(Qt::AlignHCenter);
    ui->CxView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->CxView->setItemsExpandable(true);
    ui->CyView->header()->setSectionResizeMode(QHeaderView::Interactive);
    ui->CxView->header()->setSectionResizeMode(QHeaderView::Interactive);
    QSettings config("userconfig.ini", QSettings::IniFormat);
    QString countSql;
    // 初始化分批加载相关变量
    loadTimer1 = nullptr;
    loadTimer2 = nullptr;
    batchSize = 200;  // 每批加载200条记录
    progressDialog = nullptr;
    totalRecordsToLoad = 0;
    loadedRecordsCount = 0;
    ui->MoldEdit->setText(config.value("SELECTIONCONFIG/Mold").toString());
    refresh_datac();
    refresh_data();
}

WarehouseWindow::~WarehouseWindow() {
    // 停止所有定时器
    if(timer) {
        timer->stop();
    }
    if(loadTimer1) {
        loadTimer1->stop();
    }
    if(loadTimer2) {
        loadTimer2->stop();
    }
    // 关闭进度对话框
    if(progressDialog) {
        progressDialog->close();
        progressDialog->deleteLater();
        progressDialog = nullptr;
    }
    // 清理系统托盘图标
    if(trayIcon) {
        trayIcon->hide();
        trayIcon->deleteLater();
        trayIcon = nullptr;
    }
    // 清理UI
    delete ui;
}

// ==================== 事件处理 ====================

void WarehouseWindow::closeEvent(QCloseEvent *event) {
    QStringList windowNames = {
        tr("添加模具备件"), tr("模具备件出库"), tr("模具备件入库"), tr("模具&货柜管理"),
        tr("模具数据修改"), tr("备件数据修改"), tr("AI问答"),       tr("工站备件数据导出"),
        tr("工站备件查找"), tr("工单管理"),     tr("工单信息管理"), tr("数据库管理"),
    };
    foreach(const QString &windowName, windowNames) {
        if(QWidget *target = m_windowMap.value(windowName)) {
            if(!target->isHidden()) {
                target->close();
                target->deleteLater();
                m_windowMap.remove(windowName);
            }
        }
    }
    setVisible(false);
    event->ignore();
}

void WarehouseWindow::on_ReturnButton_clicked() {
    timer->stop();
    if(trayIcon) {
        trayIcon->hide();
    }
    mainWindow->show();
    this->close();
}

void WarehouseWindow::on_ReturnButtonc_clicked() {
    timer->stop();
    if(trayIcon) {
        trayIcon->hide();
    }
    mainWindow->show();
    this->close();
}

bool WarehouseWindow::isProcessRunning(const QString &processName) {
    QProcess process;
    process.start("tasklist");
    process.waitForFinished();
    QString output = process.readAllStandardOutput();
    return output.contains(processName, Qt::CaseInsensitive);
}

void WarehouseWindow::closeApplication() {
    if(trayIcon) {
        trayIcon->hide();
    }
    if(isProcessRunning("email.exe")) {
        QProcess::execute("taskkill", QStringList() << "/F" << "/IM" << "email.exe");
    }
    QApplication::quit();
}

void WarehouseWindow::showWorkMessage() {
    WarehouseWindow::show();
    handleMessage = new HandleMessage(curr_auth, curr_name, this);
    handleMessage->setWindowTitle("工单信息管理");
    m_windowMap.insert(tr("工单信息管理"), handleMessage);
    handleMessage->show();
}

void WarehouseWindow::onTrayIconActivated(QSystemTrayIcon::ActivationReason reason) {
    if(reason == QSystemTrayIcon::DoubleClick) {
        WarehouseWindow::showNormal();
        WarehouseWindow::activateWindow();
        if(message) {
            handleMessage = new HandleMessage(curr_auth, curr_name, this);
            handleMessage->setWindowTitle("工单信息管理");
            m_windowMap.insert(tr("工单信息管理"), handleMessage);
            handleMessage->show();
        }
    } else if(reason == QSystemTrayIcon::Trigger) { // 鼠标左键单击
        WarehouseWindow::showNormal();
        WarehouseWindow::activateWindow();
    }
}

// ==================== 数据刷新相关 ====================

void WarehouseWindow::refresh_information() {
    if(handleWorks) {
        return;
    }
    refresh_time++;
    if(refresh_time % 2 && change_flag) {
        QIcon trayIconIcon(":/images/app.ico");
        trayIcon->setIcon(trayIconIcon);
    } else {
        QIcon trayIconIcon(":/images/information.png");
        trayIcon->setIcon(trayIconIcon);
    }
    if(refresh_time >= 1800) {
        refresh_data();
        refresh_datac();
        refresh_time = 0;
    }
    QSqlQuery query;
    query.prepare("select count(*) from information_message where (接收用户 = :name or 接收用户 = '所有人') and 完成情况 = '1'");
    query.bindValue(":name", curr_name);
    if(!query.exec()) {
        QMessageBox::warning(this, "刷新信息", "信息列表数量查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        refresh_time = 0;
        message = 0;
        message_temp = 0;
        change_flag = false;
        timer->stop();
    } else {
        if(query.next()) {
            if(message_temp == 0) {
                message_temp = query.value(0).toInt();
            }
            message = query.value(0).toInt();
            if(message > message_temp) {
                QString sql =
                    "select 模具编号,备件号,信息 from information_message where (接收用户 = :name or 接收用户 = '所有人') and 完成情况 = '1' order by 序号 desc limit 1";
                query.prepare(sql);
                query.bindValue(":name", curr_name);
                if(!query.exec()) {
                    QMessageBox::warning(this, "刷新信息", "信息列表数据查询失败：\n" + query.lastError().text(),
                        QMessageBox::Cancel);
                    change_flag = false;
                } else {
                    if(query.next()) {
                        QString show_message =
                            query.value(0).toString() + ":\n" + query.value(1).toString() + query.value(2).toString();
                        trayIcon->showMessage("模具信息", show_message, QSystemTrayIcon::Information, 5);
                    }
                }
            }
        }
    }
    message_temp = message;
    if(message) {
        change_flag = true;
        ui->MessageLabel->setText(QString("当前消息条数（%1）").arg(message));
        ui->MessageLabelc->setText(QString("当前消息条数（%1）").arg(message));
        trayIcon->setToolTip(QString("当前消息条数（%1）").arg(message));
        ui->MessageLabel->setStyleSheet(
            "QPushButton{background-color: rgb(255, 255, 255);color: rgb(255, 0, 0);border-style: "
            "outset;}QPushButton:hover{background: rgb(100,100,100);}QPushButton:pressed{background-color: rgb(255, "
            "255, 255);border-style: outset;}");
        ui->MessageLabelc->setStyleSheet(
            "QPushButton{background-color: rgb(255, 255, 255);color: rgb(255, 0, 0);border-style: "
            "outset;}QPushButton:hover{background: rgb(100,100,100);}QPushButton:pressed{background-color: rgb(255, "
            "255, 255);border-style: outset;}");
    } else {
        change_flag = false;
        QIcon trayIconIcon(":/images/app.ico");
        trayIcon->setIcon(trayIconIcon);
        ui->MessageLabel->setText(QString("当前消息条数（%1）").arg(0));
        ui->MessageLabelc->setText(QString("当前消息条数（%1）").arg(0));
        trayIcon->setToolTip("广东盟恩电子模具管理系统");
        ui->MessageLabel->setStyleSheet(
            "QPushButton{background-color: rgb(255, 255, 255);border-style: outset;}QPushButton:hover{background: "
            "rgb(100,100,100);}QPushButton:pressed{background-color: rgb(255, 255, 255);border-style: outset;}");
        ui->MessageLabelc->setStyleSheet(
            "QPushButton{background-color: rgb(255, 255, 255);border-style: outset;}QPushButton:hover{background: "
            "rgb(100,100,100);}QPushButton:pressed{background-color: rgb(255, 255, 255);border-style: outset;}");
    }
}

void WarehouseWindow::refresh_data() {
    QSettings config("userconfig.ini", QSettings::IniFormat);
    if(config.value("SELECTIONCONFIG/Select1").toString() == "冲压") {
        ui->tabWidget->setCurrentIndex(2);
    } else {
        ui->tabWidget->setCurrentIndex(3);
    }
    ui->widget1->setVisible(true);
    ui->widget2->setVisible(false);
    // 根据当前标签页决定过滤条件和要加载的视图
    QString moldFilter = ui->MoldEdit->text();
    int currentTab = ui->tabWidget->currentIndex();
    // 使用通用分批加载函数，传入当前标签页索引
    startProgressiveLoad(moldFilter, "", currentTab);
    // 清空编辑框（这些可以立即执行）
    spare_id = "";
    cabinet = "";
    ui->SpareEdit->clear();
    ui->PriceEdit->clear();
    ui->FirstEdit->clear();
    ui->OtherEdit->clear();
    ui->MaterialEdit->clear();
    ui->ProductEdit->clear();
    ui->StataEdit->clear();
    ui->MoldEditc->clear();
    ui->MaterialEditc->clear();
    ui->ModelEditc->clear();
    ui->ContainerCombo->setCurrentText("");
    // 注意：expandAll() 和配置恢复逻辑将在分批加载完成后执行
}

void WarehouseWindow::refresh_datac() {
    QSqlQuery query;
    QSqlQueryModel *model;
    model = new QSqlQueryModel(ui->ModleList1);
    QString sql = "select 模具编号,存放货柜,当前状态 from chonya_mold;";
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "刷新数据", "模具数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    model->setQuery(query);
    standardModel1 = new QStandardItemModel(model->rowCount(), model->columnCount(), this);
    for(int row = 0; row < model->rowCount(); ++row) {
        for(int column = 0; column < model->columnCount(); ++column) {
            QModelIndex index = model->index(row, column);
            QVariant value = model->data(index);
            standardModel1->setItem(row, column, new QStandardItem(value.toString()));
        }
    }
    for(int column = 0; column < model->columnCount(); ++column) {
        QString columnName = model->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
        standardModel1->setHeaderData(column, Qt::Horizontal, columnName);
    }
    ui->ModleList1->setModel(standardModel1);
    ui->ModleList1->setColumnWidth(0, 200);
    ui->ModleList1->setColumnWidth(1, 120);
    ui->ModleList1->horizontalHeader()->setVisible(true);
    ui->ModleList1->verticalHeader()->setVisible(true);
    ui->ModleList1->horizontalHeader()->setStretchLastSection(true);
    ui->ModleList1->resizeRowsToContents();
    model = new QSqlQueryModel(ui->ModleList2);
    sql = "select 模具编号,存放货柜,当前状态 from chengxing_mold;";
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "刷新数据", "模具数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    model->setQuery(query);
    standardModel2 = new QStandardItemModel(model->rowCount(), model->columnCount(), this);
    for(int row = 0; row < model->rowCount(); ++row) {
        for(int column = 0; column < model->columnCount(); ++column) {
            QModelIndex index = model->index(row, column);
            QVariant value = model->data(index);
            standardModel2->setItem(row, column, new QStandardItem(value.toString()));
        }
    }
    for(int column = 0; column < model->columnCount(); ++column) {
        QString columnName = model->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
        standardModel2->setHeaderData(column, Qt::Horizontal, columnName);
    }
    ui->ModleList2->setModel(standardModel2);
    ui->ModleList2->setColumnWidth(0, 200);
    ui->ModleList2->setColumnWidth(1, 120);
    ui->ModleList2->horizontalHeader()->setVisible(true);
    ui->ModleList2->verticalHeader()->setVisible(true);
    ui->ModleList2->horizontalHeader()->setStretchLastSection(true);
    ui->ModleList2->resizeRowsToContents();
    mold_id = "";
    ui->MoldEditc->clear();
    ui->MaterialEditc->clear();
    ui->ModelEditc->clear();
    ui->ContainerCombo->setCurrentText("");
}

void WarehouseWindow::loadBatchCyView() {
    if(pendingRecords1.isEmpty()) {
        // CyView 加载完成
        loadTimer1->stop();
        // 设置视图属性
        ui->CyView->expandAll();
        ui->CyView->header()->resizeSection(0, 220);
        ui->CyView->header()->resizeSection(1, 115);
        ui->CyView->header()->resizeSection(2, 115);
        ui->CyView->header()->resizeSection(3, 115);
        QFont font1 = ui->CyView->header()->font();
        font1.setPointSize(18);
        ui->CyView->header()->setFont(font1);
        // 检查是否两个视图都加载完成
        if(pendingRecords2.isEmpty()) {
            finishDataLoading();
        }
        loadedRecordsCount++;
        return;
    }
    // 加载一批数据
    int count = qMin(batchSize, pendingRecords1.size());
    for(int i = 0; i < count; ++i) {
        QSqlRecord record = pendingRecords1.takeFirst();
        QString mold = record.value(0).toString();
        int moldCount = moldCountMap1.value(mold, 0);
        QString table = QString(mold + "(%1类)").arg(moldCount);
        QStandardItem *topItem = topItems1.value(table, nullptr);
        if(!topItem) {
            topItem = new QStandardItem(table);
            topItems1[table] = topItem;
            model1->appendRow(topItem);
        }
        QStandardItem *item1 = new QStandardItem(record.value(1).toString());
        item1->setTextAlignment(Qt::AlignCenter);
        QStandardItem *item2;
        if(record.value(2).toString() == "0") {
            item2 = new QStandardItem("未设置");
        } else {
            item2 = new QStandardItem(record.value(2).toString());
        }
        item2->setTextAlignment(Qt::AlignCenter);
        QStandardItem *item3 = new QStandardItem(record.value(3).toString());
        item3->setTextAlignment(Qt::AlignCenter);
        QStandardItem *item4 = new QStandardItem(record.value(4).toString());
        item4->setTextAlignment(Qt::AlignCenter);
        topItem->appendRow({item1, item2, item3, item4});
        // 检查是否需要标红（安全库存不足）
        if(record.value(2).toInt() > record.value(3).toInt() && record.value(2).toInt()) {
            item1->setBackground(QBrush(Qt::red));
            item2->setBackground(QBrush(Qt::red));
            item3->setBackground(QBrush(Qt::red));
            item4->setBackground(QBrush(Qt::red));
        }
        loadedRecordsCount++;
    }
    // 更新进度
    if(progressDialog) {
        progressDialog->setValue(loadedRecordsCount);
    }
}

void WarehouseWindow::loadBatchCxView() {
    if(pendingRecords2.isEmpty()) {
        // CxView 加载完成
        loadTimer2->stop();
        // 设置视图属性
        ui->CxView->expandAll();
        ui->CxView->header()->resizeSection(0, 220);
        ui->CxView->header()->resizeSection(1, 115);
        ui->CxView->header()->resizeSection(2, 115);
        ui->CxView->header()->resizeSection(3, 115);
        QFont font2 = ui->CxView->header()->font();
        font2.setPointSize(18);
        ui->CxView->header()->setFont(font2);
        // 检查是否两个视图都加载完成
        if(pendingRecords1.isEmpty()) {
            finishDataLoading();
        }
        loadedRecordsCount++;
        return;
    }
    // 加载一批数据
    int count = qMin(batchSize, pendingRecords2.size());
    for(int i = 0; i < count; ++i) {
        QSqlRecord record = pendingRecords2.takeFirst();
        QString mold = record.value(0).toString();
        int moldCount = moldCountMap2.value(mold, 0);
        QString table = QString(mold + "(%1类)").arg(moldCount);
        QStandardItem *topItem = topItems2.value(table, nullptr);
        if(!topItem) {
            topItem = new QStandardItem(table);
            topItems2[table] = topItem;
            model2->appendRow(topItem);
        }
        QStandardItem *item1 = new QStandardItem(record.value(1).toString());
        item1->setTextAlignment(Qt::AlignCenter);
        QStandardItem *item2;
        if(record.value(2).toString() == "0") {
            item2 = new QStandardItem("未设置");
        } else {
            item2 = new QStandardItem(record.value(2).toString());
        }
        item2->setTextAlignment(Qt::AlignCenter);
        QStandardItem *item3 = new QStandardItem(record.value(3).toString());
        item3->setTextAlignment(Qt::AlignCenter);
        QStandardItem *item4 = new QStandardItem(record.value(4).toString());
        item4->setTextAlignment(Qt::AlignCenter);
        topItem->appendRow({item1, item2, item3, item4});
        // 检查是否需要标红（安全库存不足）
        if(record.value(2).toInt() > record.value(3).toInt() && record.value(2).toInt()) {
            item1->setBackground(QBrush(Qt::red));
            item2->setBackground(QBrush(Qt::red));
            item3->setBackground(QBrush(Qt::red));
            item4->setBackground(QBrush(Qt::red));
        }
        loadedRecordsCount++;
    }
    // 更新进度
    if(progressDialog) {
        progressDialog->setValue(loadedRecordsCount);
    }
}

void WarehouseWindow::startProgressiveLoad(const QString &moldFilter, const QString &spareFilter, int tabIndex) {
    // 停止之前的加载（如果正在进行）
    if(loadTimer1) {
        loadTimer1->stop();
    }
    if(loadTimer2) {
        loadTimer2->stop();
    }
    // 关闭之前的进度对话框
    if(progressDialog) {
        progressDialog->close();
        progressDialog->deleteLater();
        progressDialog = nullptr;
    }
    // 清空待加载列表和映射
    pendingRecords1.clear();
    pendingRecords2.clear();
    moldCountMap1.clear();
    moldCountMap2.clear();
    topItems1.clear();
    topItems2.clear();
    // 如果 tabIndex 为 -1，使用当前标签页
    if(tabIndex == -1) {
        tabIndex = ui->tabWidget->currentIndex();
    }
    // 决定哪个视图使用过滤条件，哪个视图加载全部数据
    // tabIndex = 2: CyView 使用过滤条件，CxView 加载全部
    // tabIndex = 3: CxView 使用过滤条件，CyView 加载全部
    // tabIndex = -1: 两个视图都使用过滤条件
    bool useFilterForCyView = (tabIndex == 2 || tabIndex == -1);  // tabIndex 2 或 -1 时 CyView 使用过滤条件
    bool useFilterForCxView = (tabIndex == 3 || tabIndex == -1);  // tabIndex 3 或 -1 时 CxView 使用过滤条件
    QString sql;
    QSqlQuery query;
    QString countSql;
    // ========== 第一步：查询模具计数映射（两个视图都需要）==========
    countSql = "select 模具编号, count(*) from chonya_message group by 模具编号";
    query.prepare(countSql);
    if(!query.exec()) {
        QMessageBox::warning(this, "刷新数据", "备件数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        while(query.next()) {
            QString moldId = query.value(0).toString();
            int count = query.value(1).toInt();
            moldCountMap1[moldId] = count;
        }
    }
    countSql = "select 模具编号, count(*) from chengxing_message group by 模具编号";
    query.prepare(countSql);
    if(!query.exec()) {
        QMessageBox::warning(this, "刷新数据", "备件数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        while(query.next()) {
            QString moldId = query.value(0).toString();
            int count = query.value(1).toInt();
            moldCountMap2[moldId] = count;
        }
    }
    // ========== 第二步：查询所有数据到待加载列表 ==========
    // 查询 CyView 数据（根据 useFilterForCyView 决定是否使用过滤条件）
    if(useFilterForCyView && !moldFilter.isEmpty() && !spareFilter.isEmpty()) {
        sql = QString("select 模具编号,备件号,安全库存,总库存量,存放柜号 from chonya_message where 模具编号 like '%%1%' and 备件号 like '%%2%'").arg(
            moldFilter).arg(spareFilter);
    } else if(useFilterForCyView && !moldFilter.isEmpty()) {
        sql = QString("select 模具编号,备件号,安全库存,总库存量,存放柜号 from chonya_message where 模具编号 like '%%1%'").arg(
            moldFilter);
    } else {
        // 不使用过滤条件，加载全部数据
        sql = "select 模具编号,备件号,安全库存,总库存量,存放柜号 from chonya_message";
    }
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "刷新数据", "备件数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        while(query.next()) {
            pendingRecords1.append(query.record());
        }
    }
    // 查询 CxView 数据（根据 useFilterForCxView 决定是否使用过滤条件）
    if(useFilterForCxView && !moldFilter.isEmpty() && !spareFilter.isEmpty()) {
        sql = QString("select 模具编号,备件号,安全库存,总库存量,存放柜号 from chengxing_message where 模具编号 like '%%1%' and 备件号 like '%%2%'").arg(
            moldFilter).arg(spareFilter);
    } else if(useFilterForCxView && !moldFilter.isEmpty()) {
        sql = QString("select 模具编号,备件号,安全库存,总库存量,存放柜号 from chengxing_message where 模具编号 like '%%1%'").arg(
            moldFilter);
    } else {
        // 不使用过滤条件，加载全部数据
        sql = "select 模具编号,备件号,安全库存,总库存量,存放柜号 from chengxing_message";
    }
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "刷新数据", "备件数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        while(query.next()) {
            pendingRecords2.append(query.record());
        }
    }
    // ========== 第三步：初始化模型（两个视图都需要初始化）==========
    model1 = new QStandardItemModel(this);
    ui->CyView->setModel(model1);
    model1->setHorizontalHeaderLabels({"备件号", "安全库存", "总库存量", "存放柜号"});
    // 在加载前设置列宽
    ui->CyView->header()->resizeSection(0, 220);
    ui->CyView->header()->resizeSection(1, 115);
    ui->CyView->header()->resizeSection(2, 115);
    ui->CyView->header()->resizeSection(3, 115);
    model2 = new QStandardItemModel(this);
    ui->CxView->setModel(model2);
    model2->setHorizontalHeaderLabels({"备件号", "安全库存", "总库存量", "存放柜号"});
    // 在加载前设置列宽
    ui->CxView->header()->resizeSection(0, 220);
    ui->CxView->header()->resizeSection(1, 115);
    ui->CxView->header()->resizeSection(2, 115);
    ui->CxView->header()->resizeSection(3, 115);
    // ========== 第四步：创建进度对话框 ==========
    totalRecordsToLoad = pendingRecords1.size() + pendingRecords2.size() + 2;
    loadedRecordsCount = 0;
    if(totalRecordsToLoad > 1000) { // 只有数据量较大时才显示进度条
        progressDialog = new QProgressDialog("正在加载数据...", "取消", 0, totalRecordsToLoad, this);
        progressDialog->setWindowModality(Qt::WindowModal);
        progressDialog->setMinimumDuration(0);
        progressDialog->setValue(0);
        connect(progressDialog, &QProgressDialog::canceled, this, [this]() {
            if(loadTimer1) loadTimer1->stop();
            if(loadTimer2) loadTimer2->stop();
        });
    }
    // ========== 第五步：创建并启动定时器 ==========
    if(!loadTimer1) {
        loadTimer1 = new QTimer(this);
        connect(loadTimer1, &QTimer::timeout, this, &WarehouseWindow::loadBatchCyView);
    }
    if(!loadTimer2) {
        loadTimer2 = new QTimer(this);
        connect(loadTimer2, &QTimer::timeout, this, &WarehouseWindow::loadBatchCxView);
    }
    // 启动定时器，每10毫秒加载一批（两个视图都启动，只要有数据就加载）
    if(!pendingRecords1.isEmpty()) {
        loadTimer1->start(10);
    }
    if(!pendingRecords2.isEmpty()) {
        loadTimer2->start(10);
    }
}

void WarehouseWindow::finishDataLoading() {
    // 关闭进度对话框
    if(progressDialog) {
        progressDialog->close();
        progressDialog->deleteLater();
        progressDialog = nullptr;
    }
    // 恢复配置选择（如果有）
    QSettings config("userconfig.ini", QSettings::IniFormat);
    if(!config.value("SELECTIONCONFIG/Mold").toString().isEmpty() &&
        !config.value("SELECTIONCONFIG/Spare").toString().isEmpty()) {
        QStandardItemModel *model;
        if(config.value("SELECTIONCONFIG/Select1").toString() == "冲压") {
            model = qobject_cast<QStandardItemModel *>(ui->CyView->model());
        } else {
            model = qobject_cast<QStandardItemModel *>(ui->CxView->model());
        }
        if(model) {
            QModelIndexList spare_matches = model->match(model->index(0, 0), Qt::DisplayRole,
                config.value("SELECTIONCONFIG/Spare").toString(), -1, Qt::MatchExactly | Qt::MatchRecursive);
            foreach(const QModelIndex &spareIndex, spare_matches) {
                QModelIndex moldIndex = model->index(spareIndex.row(), 3, spareIndex.parent());
                if((moldIndex.data(Qt::DisplayRole).toString() == config.value("SELECTIONCONFIG/Cabinet").toString()) ||
                    config.value("SELECTIONCONFIG/Cabinet").toString().isEmpty()) {
                    mold_id = config.value("SELECTIONCONFIG/Mold").toString();
                    spare_id = config.value("SELECTIONCONFIG/Spare").toString();
                    cabinet = config.value("SELECTIONCONFIG/Cabinet").toString();
                    if(ui->tabWidget->currentIndex() == 3) {
                        ui->CxView->setCurrentIndex(moldIndex);
                        ui->CxView->selectionModel()->select(moldIndex, QItemSelectionModel::Select | QItemSelectionModel::Rows);
                        ui->CxView->scrollTo(moldIndex, QAbstractItemView::PositionAtCenter);
                    } else if(ui->tabWidget->currentIndex() == 2) {
                        ui->CyView->setCurrentIndex(moldIndex);
                        ui->CyView->selectionModel()->select(moldIndex, QItemSelectionModel::Select | QItemSelectionModel::Rows);
                        ui->CyView->scrollTo(moldIndex, QAbstractItemView::PositionAtCenter);
                    }
                    QSqlQuery query;
                    if(ui->tabWidget->currentIndex() == 2) {
                        query.prepare("select * from chonya_message where 模具编号 = :mold and 备件号 = :spare");
                    } else if(ui->tabWidget->currentIndex() == 3) {
                        query.prepare("select * from chengxing_message where 模具编号 = :mold and 备件号 = :spare");
                    }
                    query.bindValue(":mold", mold_id);
                    query.bindValue(":spare", spare_id);
                    if(query.exec() && query.next()) {
                        cabinet = query.value("存放柜号").toString();
                        ui->MoldEdit->setText(mold_id);
                        ui->SpareEdit->setText(spare_id);
                        if(query.value("备件价格").toInt()) {
                            ui->PriceEdit->setText(query.value("备件价格").toString());
                        } else {
                            ui->PriceEdit->setText("未设置");
                        }
                        ui->FirstEdit->setText(query.value("期初库存").toString());
                        ui->OtherEdit->setText(query.value("备注").toString());
                        ui->StataEdit->setText(query.value("状态").toString());
                        query.prepare("select * from mold_message where 模具编号 = :id and 隶属部门 = :part");
                        query.bindValue(":id", mold_id);
                        query.bindValue(":part", config.value("SELECTIONCONFIG/Select1").toString());
                        if(query.exec() && query.next()) {
                            if(query.next()) {
                                ui->ProductEdit->setText(query.value("产品名称").toString());
                                ui->MaterialEdit->setText(query.value("产品料号").toString());
                            }
                        }
                    }
                    ui->SpareEdit->setSelection(0, 0);
                    ui->OtherEdit->setSelection(0, 0);
                    ui->ProductEdit->setSelection(0, 0);
                    ui->MaterialEdit->setSelection(0, 0);
                    break;  // 只处理第一个匹配项
                }
            }
        }
    }
}

void WarehouseWindow::on_FindButton_clicked() {
    // 使用分批加载函数，传入模具和备件过滤条件，以及当前标签页索引
    int currentTab = ui->tabWidget->currentIndex();
    startProgressiveLoad(ui->MoldEdit->text(), ui->SpareEdit->text(), currentTab);
    // 清空编辑框
    mold_id = "";
    spare_id = "";
    cabinet = "";
    ui->PriceEdit->clear();
    ui->FirstEdit->clear();
    ui->OtherEdit->clear();
    ui->MaterialEdit->clear();
    ui->ProductEdit->clear();
    ui->StataEdit->clear();
}

void WarehouseWindow::on_SpareEdit_returnPressed() {
    // 使用分批加载函数，传入模具和备件过滤条件，以及当前标签页索引
    int currentTab = ui->tabWidget->currentIndex();
    startProgressiveLoad(ui->MoldEdit->text(), ui->SpareEdit->text(), currentTab);
    // 清空编辑框
    mold_id = "";
    spare_id = "";
    cabinet = "";
    ui->PriceEdit->clear();
    ui->FirstEdit->clear();
    ui->OtherEdit->clear();
    ui->MaterialEdit->clear();
    ui->ProductEdit->clear();
    ui->StataEdit->clear();
}

void WarehouseWindow::on_MoldEdit_returnPressed() {
    // 使用分批加载函数，只传入模具过滤条件，以及当前标签页索引
    int currentTab = ui->tabWidget->currentIndex();
    startProgressiveLoad(ui->MoldEdit->text(), "", currentTab);
    // 清空编辑框
    mold_id = "";
    spare_id = "";
    cabinet = "";
    ui->SpareEdit->clear();
    ui->PriceEdit->clear();
    ui->FirstEdit->clear();
    ui->OtherEdit->clear();
    ui->MaterialEdit->clear();
    ui->ProductEdit->clear();
    ui->StataEdit->clear();
}

void WarehouseWindow::on_MoldEdit_textChanged(const QString &arg1) {
    ui->SpareEdit->clear();
    if(arg1.isEmpty()) {
        // 当文本为空时，加载所有数据（使用分批加载），根据当前标签页决定加载哪个视图
        int currentTab = ui->tabWidget->currentIndex();
        startProgressiveLoad("", "", currentTab);
        // 清空编辑框
        mold_id = "";
        spare_id = "";
        cabinet = "";
        ui->PriceEdit->clear();
        ui->FirstEdit->clear();
        ui->OtherEdit->clear();
        ui->MaterialEdit->clear();
        ui->ProductEdit->clear();
        ui->StataEdit->clear();
    }
}

void WarehouseWindow::on_CyView_clicked(const QModelIndex &index) {
    QModelIndex firstColumnIndex = index.sibling(index.row(), 0);
    if(!model1->data(firstColumnIndex, Qt::DisplayRole).toString().contains("类")) {
        spare_id = model1->data(firstColumnIndex, Qt::DisplayRole).toString();
        QModelIndex CabinetColumnIndex = index.sibling(index.row(), 3);
        cabinet = model1->data(CabinetColumnIndex, Qt::DisplayRole).toString();
        QModelIndex parentIndex = index.parent();
        QString parent_data = parentIndex.data().toString();
        int sameCount = 0;
        int position = 0;
        int totalChildren = model1->rowCount(parentIndex);
        for(int row = 0; row < totalChildren; ++row) {
            QModelIndex childIndex = model1->index(row, 0, parentIndex);
            QString childText = childIndex.data().toString();
            if(childText == spare_id) {
                sameCount++;
                if(childIndex.row() == index.row()) {
                    position = sameCount - 1;
                }
            }
        }
        int pos = parent_data.indexOf("(");
        mold_id = parent_data.left(pos);
        QSqlQuery query;
        query.prepare(
            QString("select * from chonya_message where 模具编号 = :mold and 备件号 = :spare order by id asc limit 1 offset %1;").arg(
            position));
        query.bindValue(":mold", mold_id);
        query.bindValue(":spare", spare_id);
        if(!query.exec()) {
            QMessageBox::warning(this, "查询备件数据", "备件数据查询失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        } else {
            if(query.next()) {
                ui->MoldEdit->setText(mold_id);
                ui->SpareEdit->setText(spare_id);
                if(query.value("备件价格").toInt()) {
                    ui->PriceEdit->setText(query.value("备件价格").toString());
                } else {
                    ui->PriceEdit->setText("未设置");
                }
                ui->FirstEdit->setText(query.value("期初库存").toString());
                ui->OtherEdit->setText(query.value("备注").toString());
                ui->StataEdit->setText(query.value("状态").toString());
            }
        }
        query.prepare("select * from mold_message where 模具编号 = :id");
        query.bindValue((":id"), mold_id);
        if(!query.exec()) {
            QMessageBox::warning(this, "查询备件数据", "模具数据查询失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        } else {
            if(query.next()) {
                ui->ProductEdit->setText(query.value("产品名称").toString());
                ui->MaterialEdit->setText(query.value("产品料号").toString());
            }
        }
        ui->SpareEdit->setSelection(0, 0);
        ui->OtherEdit->setSelection(0, 0);
        ui->ProductEdit->setSelection(0, 0);
        ui->MaterialEdit->setSelection(0, 0);
        QSettings config("userconfig.ini", QSettings::IniFormat);
        config.setValue("SELECTIONCONFIG/Select1", "冲压");
        config.setValue("SELECTIONCONFIG/Select2", mold_id);
        config.setValue("SELECTIONCONFIG/Select3", cabinet);
        config.setValue("SELECTIONCONFIG/Mold", mold_id);
        config.setValue("SELECTIONCONFIG/Spare", spare_id);
        config.setValue("SELECTIONCONFIG/Cabinet", cabinet);
        config.sync();
    } else {
        QString mold_data = model1->data(firstColumnIndex, Qt::DisplayRole).toString();
        int pos = mold_data.indexOf("(");
        mold_id = mold_data.left(pos);
        spare_id = "";
        ui->MoldEdit->setText(mold_id);
        ui->SpareEdit->clear();
        ui->PriceEdit->clear();
        ui->FirstEdit->clear();
        ui->OtherEdit->clear();
        ui->MaterialEdit->clear();
        ui->ProductEdit->clear();
        ui->StataEdit->clear();
    }
}

void WarehouseWindow::on_CxView_clicked(const QModelIndex &index) {
    QModelIndex firstColumnIndex = index.sibling(index.row(), 0);
    if(!model2->data(firstColumnIndex, Qt::DisplayRole).toString().contains("类")) {
        spare_id = model2->data(firstColumnIndex, Qt::DisplayRole).toString();
        QModelIndex CabinetColumnIndex = index.sibling(index.row(), 3);
        cabinet = model2->data(CabinetColumnIndex, Qt::DisplayRole).toString();
        QModelIndex parentIndex = index.parent();
        QString parent_data = parentIndex.data().toString();
        int sameCount = 0;
        int position = 0;
        int totalChildren = model2->rowCount(parentIndex);
        for(int row = 0; row < totalChildren; ++row) {
            QModelIndex childIndex = model2->index(row, 0, parentIndex);
            QString childText = model2->data(childIndex, Qt::DisplayRole).toString();
            if(childText == spare_id) {
                sameCount++;
                if(childIndex.row() == index.row()) {
                    position = sameCount - 1;
                }
            }
        }
        int pos = parent_data.indexOf("(");
        mold_id = parent_data.left(pos);
        QSqlQuery query;
        query.prepare(
            QString("select * from chengxing_message where 模具编号 = :mold and 备件号 = :spare order by id asc limit 1 offset %1;").arg(
            position));
        query.bindValue(":mold", mold_id);
        query.bindValue(":spare", spare_id);
        if(!query.exec()) {
            QMessageBox::warning(this, "查询备件数据", "备件数据查询失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        } else {
            if(query.next()) {
                ui->MoldEdit->setText(mold_id);
                ui->SpareEdit->setText(spare_id);
                if(query.value("备件价格").toInt()) {
                    ui->PriceEdit->setText(query.value("备件价格").toString());
                } else {
                    ui->PriceEdit->setText("未设置");
                }
                ui->FirstEdit->setText(query.value("期初库存").toString());
                ui->OtherEdit->setText(query.value("备注").toString());
                ui->StataEdit->setText(query.value("状态").toString());
            }
        }
        query.prepare("select * from mold_message where 模具编号 = :id");
        query.bindValue(":id", mold_id);
        if(!query.exec()) {
            QMessageBox::warning(this, "查询备件数据", "模具数据查询失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        } else {
            if(query.next()) {
                ui->ProductEdit->setText(query.value("产品名称").toString());
                ui->MaterialEdit->setText(query.value("产品料号").toString());
            }
        }
        ui->SpareEdit->setSelection(0, 0);
        ui->OtherEdit->setSelection(0, 0);
        ui->ProductEdit->setSelection(0, 0);
        ui->MaterialEdit->setSelection(0, 0);
        QSettings config("userconfig.ini", QSettings::IniFormat);
        config.setValue("SELECTIONCONFIG/Select1", "成型");
        config.setValue("SELECTIONCONFIG/Select2", mold_id);
        config.setValue("SELECTIONCONFIG/Select3", cabinet);
        config.setValue("SELECTIONCONFIG/Mold", mold_id);
        config.setValue("SELECTIONCONFIG/Spare", spare_id);
        config.setValue("SELECTIONCONFIG/Cabinet", cabinet);
        config.sync();
    } else {
        QString mold_data = model2->data(firstColumnIndex, Qt::DisplayRole).toString();
        int pos = mold_data.indexOf("(");
        mold_id = mold_data.left(pos);
        spare_id = "";
        ui->MoldEdit->setText(mold_id);
        ui->SpareEdit->clear();
        ui->PriceEdit->clear();
        ui->FirstEdit->clear();
        ui->OtherEdit->clear();
        ui->MaterialEdit->clear();
        ui->ProductEdit->clear();
        ui->StataEdit->clear();
    }
}

// ==================== 备件管理相关（冲压/成型标签页） ====================

void WarehouseWindow::on_AddButton_clicked() {
    warehouseAdd = new WarehouseAdd(this);
    connect(warehouseAdd, SIGNAL(mysignal()), this, SLOT(refresh_data()));
    warehouseAdd->setWindowTitle("添加模具备件");
    m_windowMap.insert(tr("添加模具备件"), warehouseAdd);
    warehouseAdd->show();
}

void WarehouseWindow::on_OutButton_clicked() {
    if(mold_id.isEmpty() || spare_id.isEmpty()) {
        QMessageBox::warning(this, "模具备件出库", "请选择备件", QMessageBox::Cancel);
        return;
    }
    int currentIndex = ui->tabWidget->currentIndex();
    if(currentIndex == 1 || currentIndex == 3) {
        warehouseOut = new WarehouseOut("chengxing_message", mold_id, spare_id, cabinet, this);
    } else if(currentIndex == 0 || currentIndex == 2) {
        warehouseOut = new WarehouseOut("chonya_message", mold_id, spare_id, cabinet, this);
    }
    connect(warehouseOut, SIGNAL(mysignal()), this, SLOT(refresh_data()));
    warehouseOut->setWindowTitle("模具备件出库");
    m_windowMap.insert(tr("模具备件出库"), warehouseOut);
    warehouseOut->show();
}

void WarehouseWindow::on_EnterButton_clicked() {
    if(mold_id.isEmpty() || spare_id.isEmpty()) {
        QMessageBox::warning(this, "模具备件入库", "请选择备件", QMessageBox::Cancel);
        return;
    }
    int currentIndex = ui->tabWidget->currentIndex();
    if(currentIndex == 1 || currentIndex == 3) {
        warehouseEnter = new WarehouseEnter("chengxing_message", mold_id, spare_id, cabinet, this);
    } else if(currentIndex == 0 || currentIndex == 2) {
        warehouseEnter = new WarehouseEnter("chonya_message", mold_id, spare_id, cabinet, this);
    }
    connect(warehouseEnter, SIGNAL(mysignal()), this, SLOT(refresh_data()));
    warehouseEnter->setWindowTitle("模具备件入库");
    m_windowMap.insert(tr("模具备件入库"), warehouseEnter);
    warehouseEnter->show();
}

void WarehouseWindow::on_ManageButton_clicked() {
    warehouseDele = new WarehouseDele(this);
    connect(warehouseDele, SIGNAL(mysignal()), this, SLOT(refresh_data()));
    warehouseDele->setWindowTitle("模具&货柜管理");
    m_windowMap.insert(tr("模具&货柜管理"), warehouseDele);
    warehouseDele->show();
}

void WarehouseWindow::on_EditButton_clicked() {
    if(spare_id.isEmpty()) {
        QMessageBox::warning(this, "备件数据修改", "请选择备件", QMessageBox::Cancel);
        return;
    }
    int currentIndex = ui->tabWidget->currentIndex();
    if(currentIndex == 1 || currentIndex == 3) {
        warehouseEdit = new WarehouseEdit("chengxing_message", mold_id, spare_id, cabinet, this);
    } else if(currentIndex == 0 || currentIndex == 2) {
        warehouseEdit = new WarehouseEdit("chonya_message", mold_id, spare_id, cabinet, this);
    }
    connect(warehouseEdit, SIGNAL(mysignal()), this, SLOT(refresh_data()));
    warehouseEdit->setWindowTitle("备件数据修改");
    m_windowMap.insert(tr("备件数据修改"), warehouseEdit);
    warehouseEdit->show();
}

void WarehouseWindow::on_DeleteButton_clicked() {
    QString question = "您确定要删除 " + spare_id + " 吗？";
    int reply = QMessageBox::question(this, "删除备件", question, QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        QSqlQuery query;
        QSqlQuery query_to;
        int currentIndex = ui->tabWidget->currentIndex();
        if(currentIndex == 3) {
            query.prepare("delete from chengxing_message where 模具编号 = :mold and 备件号 = :spare and 存放柜号 = :cabinet");
        } else if(currentIndex == 2) {
            query.prepare("delete from chonya_message where 模具编号 = :mold and 备件号 = :spare and 存放柜号 = :cabinet");
        }
        query.bindValue(":mold", mold_id);
        query.bindValue(":spare", spare_id);
        query.bindValue(":cabinet", cabinet);
        if(!query.exec()) {
            QMessageBox::warning(this, "删除备件", "备件数据删除失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        } else {
            query.prepare("delete from information_message where 模具编号 = :mold and 备件号 = :spare");
            query.bindValue(":mold", mold_id);
            query.bindValue(":spare", spare_id);
            if(!query.exec()) {
                QMessageBox::warning(this, "删除备件", "备件信息列表数据删除失败：\n" + query.lastError().text(),
                    QMessageBox::Cancel);
                return;
            } else {
                QMessageBox::information(this, "删除备件", "备件删除成功", QMessageBox::Ok);
                refresh_data();
                mold_id = "";
                spare_id = "";
                cabinet = "";
            }
        }
    }
}

void WarehouseWindow::on_MessageLabel_clicked() {
    handleMessage = new HandleMessage(curr_auth, curr_name, this);
    handleMessage->setWindowTitle("工单信息管理");
    m_windowMap.insert(tr("工单信息管理"), handleMessage);
    handleMessage->show();
}

void WarehouseWindow::on_commandLinkButton_clicked() {
retry:
    bool ok;
    QString secret = QInputDialog::getText(this, "数据库管理", "请输入管理密钥:", QLineEdit::Password, "", &ok);
    if(ok && !secret.isEmpty()) {
        if(secret == "mengen888") {
            databaseWin = new DatabaseWindow(this);
            databaseWin->setWindowTitle("数据库管理");
            databaseWin->show();
        } else {
            QMessageBox::warning(this, "数据库管理", "密钥错误，请重新输入！");
            goto retry;
        }
    } else if(ok && secret.isEmpty()) {
        QMessageBox::warning(this, "数据库管理", "密钥为空，请输入管理密钥！");
        goto retry;
    }
}

void WarehouseWindow::on_AIButton_clicked() {
    aiWindow = new AiWindow(this);
    aiWindow->setWindowTitle("AI问答");
    m_windowMap.insert(tr("AI问答"), aiWindow);
    aiWindow->show();
}

void WarehouseWindow::enable_windiow() {
    ui->centralwidget->setEnabled(true);
}

void WarehouseWindow::on_WorkButton_clicked() {
    if(mold_id.isEmpty()) {
        QMessageBox::warning(this, "工单管理", "请选择模具", QMessageBox::Cancel);
        return;
    } else {
        ui->centralwidget->setEnabled(false);
        QSqlDatabase currentDb = QSqlDatabase::database();
        QString databaseName = currentDb.databaseName();
        if(!spare_id.isEmpty()) {
            handleWorks = new HandleWorks(databaseName, mold_id + '#' + spare_id, curr_name, this);
        } else {
            handleWorks = new HandleWorks(databaseName, mold_id, curr_name, this);
        }
        connect(handleWorks, SIGNAL(enablesignal()), this, SLOT(enable_windiow()));
        handleWorks->setWindowTitle("工单管理");
        m_windowMap.insert(tr("工单管理"), handleWorks);
        handleWorks->show();
    }
}

void WarehouseWindow::on_RefreshButton_clicked() {
    refresh_data();
}

void WarehouseWindow::on_CheckButton_clicked() {
    int row = 4;
    QSqlQuery query;
    QString fileName, file_temp;
    QSettings config("userconfig.ini", QSettings::IniFormat);
    QXlsx::Document xlsx1(":/ducument/check_chonya.xlsx");
    QString sql = "select 模具编号,备件号,总库存量,存放柜号,安全库存 from chonya_message;";
    if(query.exec(sql)) {
        while(query.next()) {
            for(int i = 1; i < 6; i++) {
                xlsx1.write(row, i, query.value(-1 + i).toString(), Song12C);
            }
            row++;
        }
        fileName = QFileDialog::getSaveFileName(this, "导出库存盘点信息",
                config.value("DOCUMENTCONFIG/DocumentPath").toString() + "冲压模具备件盘点记录表", "Excel Files (*.xlsx)");
        file_temp = fileName;
        file_temp = file_temp.left(file_temp.lastIndexOf('/')) + "/";
        config.setValue("DOCUMENTCONFIG/DocumentPath", file_temp);
        if(fileName.isEmpty()) {
            return;
        }
        if(!fileName.endsWith(".xlsx")) {
            fileName.append(".xlsx");
        }
        if(!xlsx1.saveAs(fileName)) {
            QMessageBox::critical(this, "导出库存盘点信息", "冲压模具备件库存盘点记录表创建失败");
        }
    } else {
        QMessageBox::warning(this, "导出库存盘点信息", "模具数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    row = 4;
    QXlsx::Document xlsx2(":/ducument/check_chengxing.xlsx");
    sql = "select 模具编号,备件号,总库存量,存放柜号 from chengxing_message;";
    if(query.exec(sql)) {
        while(query.next()) {
            for(int i = 1; i < 5; i++) {
                xlsx2.write(row, i, query.value(-1 + i).toString(), Song12C);
            }
            row++;
        }
        fileName = QFileDialog::getSaveFileName(this, "导出成型模具备件盘点记录表",
                config.value("DOCUMENTCONFIG/DocumentPath").toString() + "成型模具备件盘点记录表", "Excel Files (*.xlsx)");
        file_temp = fileName;
        file_temp = file_temp.left(file_temp.lastIndexOf('/')) + "/";
        config.setValue("DOCUMENTCONFIG/DocumentPath", file_temp);
        if(fileName.isEmpty()) {
            return;
        }
        if(!fileName.endsWith(".xlsx")) {
            fileName.append(".xlsx");
        }
        if(!xlsx2.saveAs(fileName)) {
            QMessageBox::critical(this, "导出库存盘点信息", "成型模具备件库存盘点记录表创建失败：");
        } else {
            config.sync();
            QMessageBox::information(this, "导出库存盘点信息", "库存盘点信息导出成功", QMessageBox::Ok);
        }
    } else {
        QMessageBox::warning(this, "导出库存盘点信息", "库存盘点信息导出失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
}

void WarehouseWindow::Product_Refresh() {
    QSettings config("userconfig.ini", QSettings::IniFormat);
    ui->MoldEdit->setText(config.value("SELECTIONCONFIG/Mold").toString());
    refresh_data();
}

void WarehouseWindow::on_ProductButton_clicked() {
    QMessageBox choice_box;
    choice_box.setWindowTitle("工站查找");
    choice_box.setText("请选择您需要的内容：");
    QPushButton *button1 = choice_box.addButton("导出料号对应备件列表", QMessageBox::ActionRole);
    QPushButton *button2 = choice_box.addButton("打开备件工站表", QMessageBox::ActionRole);
    choice_box.addButton("取消", QMessageBox::RejectRole);
    choice_box.exec();
    if(choice_box.clickedButton() == button1 && ui->tabWidget->currentIndex() == 2) {
        productWin = new ProductWindow(this);
        productWin->setWindowTitle("工站备件数据导出");
        m_windowMap.insert(tr("工站备件数据导出"), productWin);
        connect(productWin, SIGNAL(mysignal()), this, SLOT(Product_Refresh()));
        productWin->show();
    }
    if(choice_box.clickedButton() == button1 && ui->tabWidget->currentIndex() == 3) {
        spareWin = new SpareWindow(this);
        spareWin->setWindowTitle("工站备件数据导出");
        m_windowMap.insert(tr("工站备件数据导出"), spareWin);
        connect(spareWin, SIGNAL(mysignal()), this, SLOT(Product_Refresh()));
        spareWin->show();
    } else if(choice_box.clickedButton() == button2 && ui->tabWidget->currentIndex() == 2) {
        workWin = new MainWidget();
        workWin->setWindowTitle("工站备件查找");
        m_windowMap.insert(tr("工站备件查找"), workWin);
        connect(workWin, SIGNAL(mysignal()), this, SLOT(Product_Refresh()));
        workWin->resize(1000, 800);
        workWin->show();
    } else if(choice_box.clickedButton() == button2 && ui->tabWidget->currentIndex() == 3) {
        handleData = new HandleData(ui->MoldEdit->text(), "message", this);
        handleData->setWindowTitle("工站备件查找");
        m_windowMap.insert(tr("工站备件查找"), handleData);
        connect(handleData, SIGNAL(mysignal()), this, SLOT(Product_Refresh()));
        handleData->show();
    }
}

// ==================== 其他功能 ====================

void WarehouseWindow::on_tabWidget_currentChanged(int index) {
    // 清除 CyView 和 CxView 的选择
    if(ui->CyView->selectionModel()) {
        ui->CyView->selectionModel()->clearSelection();
    }
    if(ui->CxView->selectionModel()) {
        ui->CxView->selectionModel()->clearSelection();
    }
    ui->SpareEdit->clear();
    ui->PriceEdit->clear();
    ui->FirstEdit->clear();
    ui->OtherEdit->clear();
    ui->MaterialEdit->clear();
    ui->ProductEdit->clear();
    ui->StataEdit->clear();
    ui->MoldEditc->clear();
    ui->MaterialEditc->clear();
    ui->ModelEditc->clear();
    if(index == 0 || index == 1) {
        ui->widget1->setVisible(false);
        ui->widget2->setVisible(true);
    } else {
        ui->widget1->setVisible(true);
        ui->widget2->setVisible(false);
    }
}

void WarehouseWindow::on_ModleList1_clicked(const QModelIndex &index) {
    QModelIndex data_index = standardModel1->index(index.row(), 0);
    mold_id = data_index.data().toString();
    QSqlQuery query;
    query.prepare("select * from chonya_mold where 模具编号 = :mold;");
    query.bindValue(":mold", mold_id);
    if(!query.exec()) {
        QMessageBox::warning(this, "查询模具数据", "模具数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        if(query.next()) {
            ui->MoldEditc->setText(query.value("模具编号").toString());
            ui->MaterialEditc->setText(query.value("产品料号").toString());
            ui->ModelEditc->setText(query.value("模具尺寸").toString());
            ui->ContainerCombo->setCurrentText(query.value("存放货柜").toString());
        }
    }
}

void WarehouseWindow::on_ModleList2_clicked(const QModelIndex &index) {
    QModelIndex data_index = standardModel2->index(index.row(), 0);
    mold_id = data_index.data().toString();
    QSqlQuery query;
    query.prepare("select * from chengxing_mold where 模具编号 = :mold;");
    query.bindValue(":mold", mold_id);
    if(!query.exec()) {
        QMessageBox::warning(this, "查询模具数据", "模具数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        if(query.next()) {
            ui->MoldEditc->setText(query.value("模具编号").toString());
            ui->MaterialEditc->setText(query.value("产品料号").toString());
            ui->ModelEditc->setText(query.value("模具尺寸").toString());
            ui->ContainerCombo->setCurrentText(query.value("存放货柜").toString());
        }
    }
}

void WarehouseWindow::on_commandLinkButtonc_clicked() {
retry:
    bool ok;
    QString secret = QInputDialog::getText(this, "数据库管理", "请输入管理密钥:", QLineEdit::Password, "", &ok);
    if(ok && !secret.isEmpty()) {
        if(secret == "mengen888") {
            databaseWin = new DatabaseWindow(this);
            databaseWin->setWindowTitle("数据库管理");
            m_windowMap.insert(tr("数据库管理"), databaseWin);
            databaseWin->show();
        } else {
            QMessageBox::warning(this, "数据库管理", "密钥错误，请重新输入！");
            goto retry;
        }
    } else if(ok && secret.isEmpty()) {
        QMessageBox::warning(this, "数据库管理", "密钥为空，请输入管理密钥！");
        return;
    }
}

void WarehouseWindow::on_AIButtonc_clicked() {
    aiWindow = new AiWindow(this);
    aiWindow->setWindowTitle("AI问答");
    m_windowMap.insert(tr("AI问答"), aiWindow);
    aiWindow->show();
}

void WarehouseWindow::on_WorkButtonc_clicked() {
    if(mold_id.isEmpty()) {
        QMessageBox::warning(this, "工单管理", "请选择模具", QMessageBox::Cancel);
        return;
    } else {
        ui->centralwidget->setEnabled(false);
        QSqlDatabase currentDb = QSqlDatabase::database();
        QString databaseName = currentDb.databaseName();
        handleWorks = new HandleWorks(databaseName, mold_id, curr_name, this);
        connect(handleWorks, SIGNAL(enablesignal()), this, SLOT(enable_windiow()));
        handleWorks->setWindowTitle("工单管理");
        m_windowMap.insert(tr("工单管理"), handleWorks);
        handleWorks->show();
    }
}

void WarehouseWindow::on_FindButtonc_clicked() {
    QString sql;
    QSqlQuery query;
    QSqlQueryModel *model;
    if(ui->tabWidget->currentIndex() == 0) {
        model = new QSqlQueryModel(ui->ModleList1);
        sql = QString("select 模具编号,存放货柜,当前状态 from chonya_mold where 模具编号 like '%%1%' and 产品料号 like '%%2%';").arg(
            ui->MoldEditc->text()).arg(ui->MaterialEditc->text());
        if(!query.exec(sql)) {
            QMessageBox::warning(this, "查找模具", "模具数据查询失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        }
        model->setQuery(query);
        standardModel1 = new QStandardItemModel(model->rowCount(), model->columnCount(), this);
        for(int row = 0; row < model->rowCount(); ++row) {
            for(int column = 0; column < model->columnCount(); ++column) {
                QModelIndex index = model->index(row, column);
                QVariant value = model->data(index);
                standardModel1->setItem(row, column, new QStandardItem(value.toString()));
            }
        }
        for(int column = 0; column < model->columnCount(); ++column) {
            QString columnName = model->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
            standardModel1->setHeaderData(column, Qt::Horizontal, columnName);
        }
        ui->ModleList1->setModel(standardModel1);
        ui->ModleList1->setColumnWidth(0, 200);
        ui->ModleList1->setColumnWidth(1, 120);
        ui->ModleList1->horizontalHeader()->setVisible(true);
        ui->ModleList1->verticalHeader()->setVisible(true);
        ui->ModleList1->horizontalHeader()->setStretchLastSection(true);
        ui->ModleList1->resizeRowsToContents();
    } else if(ui->tabWidget->currentIndex() == 1) {
        model = new QSqlQueryModel(ui->ModleList2);
        sql = QString("select 模具编号,存放货柜,当前状态 from chonya_mold where 模具编号 = '%1' and 产品料号 = '%2';").arg(
            ui->MoldEditc->text()).arg(ui->MaterialEditc->text());
        if(!query.exec(sql)) {
            QMessageBox::warning(this, "查找模具", "模具数据查询失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        }
        model->setQuery(query);
        standardModel2 = new QStandardItemModel(model->rowCount(), model->columnCount(), this);
        for(int row = 0; row < model->rowCount(); ++row) {
            for(int column = 0; column < model->columnCount(); ++column) {
                QModelIndex index = model->index(row, column);
                QVariant value = model->data(index);
                standardModel2->setItem(row, column, new QStandardItem(value.toString()));
            }
        }
        for(int column = 0; column < model->columnCount(); ++column) {
            QString columnName = model->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
            standardModel2->setHeaderData(column, Qt::Horizontal, columnName);
        }
        ui->ModleList2->setModel(standardModel2);
        ui->ModleList2->setColumnWidth(0, 200);
        ui->ModleList2->setColumnWidth(1, 120);
        ui->ModleList2->horizontalHeader()->setVisible(true);
        ui->ModleList2->verticalHeader()->setVisible(true);
        ui->ModleList2->horizontalHeader()->setStretchLastSection(true);
        ui->ModleList2->resizeRowsToContents();
    }
    mold_id = "";
    ui->ModelEditc->clear();
    ui->ContainerCombo->setCurrentText("");
}

void WarehouseWindow::on_MoldEditc_returnPressed() {
    QString sql;
    QSqlQuery query;
    QSqlQueryModel *model;
    if(ui->tabWidget->currentIndex() == 0) {
        model = new QSqlQueryModel(ui->ModleList1);
        sql = QString("select 模具编号,存放货柜,当前状态 from chonya_mold where 模具编号 like '%%1%';")
            .arg(ui->MoldEditc->text());
        if(!query.exec(sql)) {
            QMessageBox::warning(this, "查找模具", "模具数据查询失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        }
        model->setQuery(query);
        standardModel1 = new QStandardItemModel(model->rowCount(), model->columnCount(), this);
        for(int row = 0; row < model->rowCount(); ++row) {
            for(int column = 0; column < model->columnCount(); ++column) {
                QModelIndex index = model->index(row, column);
                QVariant value = model->data(index);
                standardModel1->setItem(row, column, new QStandardItem(value.toString()));
            }
        }
        for(int column = 0; column < model->columnCount(); ++column) {
            QString columnName = model->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
            standardModel1->setHeaderData(column, Qt::Horizontal, columnName);
        }
        ui->ModleList1->setModel(standardModel1);
        ui->ModleList1->setColumnWidth(0, 200);
        ui->ModleList1->setColumnWidth(1, 120);
        ui->ModleList1->horizontalHeader()->setVisible(true);
        ui->ModleList1->verticalHeader()->setVisible(true);
        ui->ModleList1->horizontalHeader()->setStretchLastSection(true);
        ui->ModleList1->resizeRowsToContents();
    } else if(ui->tabWidget->currentIndex() == 1) {
        model = new QSqlQueryModel(ui->ModleList2);
        sql = QString("select 模具编号,存放货柜,当前状态 from chonya_mold where 模具编号 = '%1';").arg(mold_id);
        if(!query.exec(sql)) {
            QMessageBox::warning(this, "查找模具", "模具数据查询失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        }
        model->setQuery(query);
        standardModel2 = new QStandardItemModel(model->rowCount(), model->columnCount(), this);
        for(int row = 0; row < model->rowCount(); ++row) {
            for(int column = 0; column < model->columnCount(); ++column) {
                QModelIndex index = model->index(row, column);
                QVariant value = model->data(index);
                standardModel2->setItem(row, column, new QStandardItem(value.toString()));
            }
        }
        for(int column = 0; column < model->columnCount(); ++column) {
            QString columnName = model->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
            standardModel2->setHeaderData(column, Qt::Horizontal, columnName);
        }
        ui->ModleList2->setModel(standardModel2);
        ui->ModleList2->setColumnWidth(0, 200);
        ui->ModleList2->setColumnWidth(1, 120);
        ui->ModleList2->horizontalHeader()->setVisible(true);
        ui->ModleList2->verticalHeader()->setVisible(true);
        ui->ModleList2->horizontalHeader()->setStretchLastSection(true);
        ui->ModleList2->resizeRowsToContents();
    }
    mold_id = "";
    ui->MaterialEditc->clear();
    ui->ModelEditc->clear();
    ui->ContainerCombo->setCurrentText("");
}

void WarehouseWindow::on_MaterialEditc_returnPressed() {
    QString sql;
    QSqlQuery query;
    QSqlQueryModel *model;
    if(ui->tabWidget->currentIndex() == 0) {
        model = new QSqlQueryModel(ui->ModleList1);
        sql = QString("select 模具编号,存放货柜,当前状态 from chonya_mold where 模具编号 like '%%1%' and 产品料号 = '%%2%';").arg(
            mold_id).arg(ui->MaterialEditc->text());
        if(!query.exec(sql)) {
            QMessageBox::warning(this, "查找料号", "模具数据查询失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        }
        model->setQuery(query);
        standardModel1 = new QStandardItemModel(model->rowCount(), model->columnCount(), this);
        for(int row = 0; row < model->rowCount(); ++row) {
            for(int column = 0; column < model->columnCount(); ++column) {
                QModelIndex index = model->index(row, column);
                QVariant value = model->data(index);
                standardModel1->setItem(row, column, new QStandardItem(value.toString()));
            }
        }
        for(int column = 0; column < model->columnCount(); ++column) {
            QString columnName = model->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
            standardModel1->setHeaderData(column, Qt::Horizontal, columnName);
        }
        ui->ModleList1->setModel(standardModel1);
        ui->ModleList1->setColumnWidth(0, 200);
        ui->ModleList1->setColumnWidth(1, 120);
        ui->ModleList1->horizontalHeader()->setVisible(true);
        ui->ModleList1->verticalHeader()->setVisible(true);
        ui->ModleList1->horizontalHeader()->setStretchLastSection(true);
        ui->ModleList1->resizeRowsToContents();
    } else if(ui->tabWidget->currentIndex() == 1) {
        model = new QSqlQueryModel(ui->ModleList2);
        sql = QString("select 模具编号,存放货柜,当前状态 from chonya_mold where 模具编号 = '%1' and 产品料号 = '%2';").arg(
            mold_id).arg(ui->MaterialEditc->text());
        if(!query.exec(sql)) {
            QMessageBox::warning(this, "查找料号", "模具数据查询失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        }
        model->setQuery(query);
        standardModel2 = new QStandardItemModel(model->rowCount(), model->columnCount(), this);
        for(int row = 0; row < model->rowCount(); ++row) {
            for(int column = 0; column < model->columnCount(); ++column) {
                QModelIndex index = model->index(row, column);
                QVariant value = model->data(index);
                standardModel2->setItem(row, column, new QStandardItem(value.toString()));
            }
        }
        for(int column = 0; column < model->columnCount(); ++column) {
            QString columnName = model->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
            standardModel2->setHeaderData(column, Qt::Horizontal, columnName);
        }
        ui->ModleList2->setModel(standardModel2);
        ui->ModleList2->setColumnWidth(0, 200);
        ui->ModleList2->setColumnWidth(1, 120);
        ui->ModleList2->horizontalHeader()->setVisible(true);
        ui->ModleList2->verticalHeader()->setVisible(true);
        ui->ModleList2->horizontalHeader()->setStretchLastSection(true);
        ui->ModleList2->resizeRowsToContents();
    }
    mold_id = "";
    ui->MaterialEditc->clear();
    ui->ModelEditc->clear();
    ui->ContainerCombo->setCurrentText("");
}

void WarehouseWindow::on_DeleteButtonc_clicked() {
    if(mold_id.isEmpty()) {
        QMessageBox::warning(this, "删除模具", "请选择模具", QMessageBox::Cancel);
        return;
    }
    QString question = "您确定要删除 " + mold_id + " 吗？";
    int reply = QMessageBox::question(this, "删除模具", question, QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        QSqlQuery query;
        QSqlQuery query_to;
        int currentIndex = ui->tabWidget->currentIndex();
        if(currentIndex == 0) {
            query.prepare("delete from chonya_mold where 模具编号 = :mold and 产品料号 = :material");
        }
        if(currentIndex == 1) {
            query.prepare("delete from chengxing_mold where 模具编号 = :mold and 产品料号 = :material");
        }
        query.bindValue(":mold", mold_id);
        query.bindValue(":material", ui->MaterialEditc->text());
        if(!query.exec()) {
            QMessageBox::warning(this, "删除模具", "模具数据删除失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        } else {
            QMessageBox::information(this, "删除模具", "模具删除成功", QMessageBox::Ok);
            int index = ui->tabWidget->currentIndex();
            refresh_data();
            mold_id = "";
            ui->tabWidget->setCurrentIndex(index);
        }
    }
}

// ==================== 模具管理相关（模具列表标签页） ====================

void WarehouseWindow::on_OutButtonc_clicked() {
    if(mold_id.isEmpty()) {
        QMessageBox::warning(this, "出库模具", "请选择模具", QMessageBox::Cancel);
        return;
    }
    QSqlQuery query;
    QString sql;
    if(ui->tabWidget->currentIndex() == 0) {
        sql = "update chonya_mold set 当前状态 = :status where 模具编号 = :mold_id and 产品料号 = :materal_id;";
    } else if(ui->tabWidget->currentIndex() == 1) {
        sql = "update chengxing_mold set 当前状态 = :status where 模具编号 = :mold_id and 产品料号 = :materal_id;";
    }
    query.prepare(sql);
    query.bindValue(":status", "已出库");
    query.bindValue(":mold_id", ui->MoldEditc->text());
    query.bindValue(":materal_id", ui->MaterialEditc->text());
    if(!query.exec()) {
        QMessageBox::warning(this, "出库模具", "模具数据更新失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        QMessageBox::information(this, "出库模具", "模具出库成功", QMessageBox::Ok);
        refresh_datac();
        mold_id = "";
    }
}

void WarehouseWindow::on_EnterButtonc_clicked() {
    if(mold_id.isEmpty()) {
        QMessageBox::warning(this, "入库模具", "请选择模具", QMessageBox::Cancel);
        return;
    }
    QSqlQuery query;
    QString sql;
    if(ui->tabWidget->currentIndex() == 0) {
        sql = "update chonya_mold set 当前状态 = :status where 模具编号 = :mold_id and 产品料号 = :materal_id;";
    } else if(ui->tabWidget->currentIndex() == 1) {
        sql = "update chengxing_mold set 当前状态 = :status where 模具编号 = :mold_id and 产品料号 = :materal_id;";
    }
    query.prepare(sql);
    query.bindValue(":status", "在库中");
    query.bindValue(":mold_id", ui->MoldEditc->text());
    query.bindValue(":materal_id", ui->MaterialEditc->text());
    if(!query.exec()) {
        QMessageBox::warning(this, "入库模具", "模具数据更新失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        QMessageBox::information(this, "入库模具", "模具入库成功", QMessageBox::Ok);
        refresh_datac();
        mold_id = "";
    }
}

void WarehouseWindow::on_ChangeButtonc_clicked() {
    if(mold_id.isEmpty()) {
        QMessageBox::warning(this, "模具参数修改", "请选择模具", QMessageBox::Cancel);
        return;
    }
    if(ui->tabWidget->currentIndex() == 0) {
        warehouseChange = new WarehouseChange(mold_id, "chonya_mold", this);
    } else if(ui->tabWidget->currentIndex() == 1) {
        warehouseChange = new WarehouseChange(mold_id, "chengxing_mold", this);
    }
    connect(warehouseChange, SIGNAL(mysignal()), this, SLOT(refresh_datac()));
    warehouseChange->setWindowTitle("模具数据修改");
    m_windowMap.insert(tr("模具数据修改"), warehouseChange);
    warehouseChange->show();
}

void WarehouseWindow::on_MoldEditc_textChanged(const QString &arg1) {
    if(arg1.isEmpty()) {
        ui->MaterialEditc->clear();
        refresh_datac();
    }
}

void WarehouseWindow::on_RefreshButtonc_clicked() {
    refresh_datac();
}

void WarehouseWindow::on_MessageLabelc_clicked() {
    handleMessage = new HandleMessage(curr_auth, curr_name, this);
    handleMessage->setWindowTitle("工单信息管理");
    m_windowMap.insert(tr("工单信息管理"), handleMessage);
    handleMessage->show();
}

void WarehouseWindow::on_BomButton_clicked() {
    if(ui->tabWidget->currentIndex() == 1 || ui->tabWidget->currentIndex() == 3) {
        QDesktopServices::openUrl(QUrl("file://192.168.101.250/bom/注塑/", QUrl::TolerantMode));
    } else {
        QDesktopServices::openUrl(QUrl("file://192.168.101.250/bom/冲压/", QUrl::TolerantMode));
    }
}
