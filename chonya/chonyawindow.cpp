#include "chonyawindow.h"
#include "ui_chonyawindow.h"

// Qt标准库
#include <QCloseEvent>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QStandardItem>
#include <QTableWidgetItem>
#include <QColor>
#include <QFont>
#include <QSettings>
#include <QFileDialog>
#include <QInputDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QDate>
#include <QScroller>
#include <QAbstractItemView>
#include <QItemSelectionModel>
#include <QMenu>
#include <QAction>
#include <QApplication>
#include <QIcon>
#include <QList>

// 第三方库
#include "xlsxchart.h"
#include "xlsxworkbook.h"
#include "xlsxdocument.h"
#include "xlsxcellrange.h"
#include "xlsxrichstring.h"
#include "xlsxchartsheet.h"

// 项目头文件
#include "chonya/chonyaadd.h"
#include "chonya/chonyaedit.h"
#include "chonya/chonyakeep.h"
#include "chonya/chonyaenter.h"
#include "comom/aiwindow.h"
#include "comom/handlebom.h"
#include "comom/handleworks.h"
#include "comom/handlemessage.h"
#include "comom/databasewindow.h"

ChonyaWindow::ChonyaWindow(QVariant authority, QVariant name, QWidget *mainWin, QWidget *parent)
    : ui(new Ui::ChonyaWindow)
    , mainWindow(mainWin)
    , aiWindow(nullptr)
    , handleBom(nullptr)
    , chonyaAdd(nullptr)
    , chonyaEdit(nullptr)
    , chonyaKeep(nullptr)
    , chonyaEnter(nullptr)
    , databaseWin(nullptr)
    , handleMessage(nullptr)
    , handleWorks(nullptr)
    , timer(nullptr)
    , trayIcon(nullptr)
    , standardModel(nullptr)
    , authvalue_(authority)
    , namevalue_(name)
    , curr_auth(false)
    , curr_name()
    , id_value()
    , message(0)
    , message_temp(0)
    , refresh_time(0)
    , change_flag(false) {
    Q_UNUSED(parent);
    ui->setupUi(this);
    // 初始化Excel格式
    Song12C.setFontSize(12);
    Song12C.setFontName("宋体");
    Song12C.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    Song12C.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    // 设置列表滚动
    QScroller *pScroller = QScroller::scroller(ui->ModleList);
    pScroller->grabGesture(ui->ModleList->viewport(), QScroller::LeftMouseButtonGesture);
    ui->ModleList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    // 初始化规则视图
    QStringList m_Header;
    ui->RuleView->setColumnCount(3);
    ui->RuleView->setRowCount(2);
    m_Header << QString("下料零件") << QString("关键易损件") << QString("成型零件");
    ui->RuleView->setHorizontalHeaderLabels(m_Header);
    ui->RuleView->horizontalHeader()->setVisible(true);
    ui->RuleView->horizontalHeader()->setFont(QFont("微软雅黑", 14));
    ui->RuleView->setColumnWidth(0, 100);
    ui->RuleView->setColumnWidth(1, 120);
    ui->RuleView->setColumnWidth(2, 100);
    // 初始化系统托盘
    trayIcon = new QSystemTrayIcon(this);
    QIcon trayIconIcon(":/images/app.ico");
    trayIcon->setIcon(trayIconIcon);
    QMenu *menu = new QMenu();
    QAction *workAction = menu->addAction("打开工单管理系统");
    QAction *showAction = menu->addAction("打开程序");
    QAction *closeAction = menu->addAction("关闭程序");
    trayIcon->setContextMenu(menu);
    connect(closeAction, &QAction::triggered, this, &QApplication::quit);
    connect(showAction, &QAction::triggered, this, &ChonyaWindow::show);
    connect(workAction, &QAction::triggered, this, &ChonyaWindow::showWorkMessage);
    connect(trayIcon, &QSystemTrayIcon::activated, this, &ChonyaWindow::onTrayIconActivated);
    trayIcon->setToolTip("广东盟恩电子模具管理系统");
    trayIcon->show();
    trayIcon->showMessage("您好", "欢迎使用广东盟恩电子模具管理系统", QSystemTrayIcon::Information, 5);
    // 初始化用户权限和身份
    curr_auth = authority.toBool();
    curr_name = name.toString();
    if(curr_auth) {
        ui->AddButton->setEnabled(true);
        ui->EnterButton->setEnabled(true);
        ui->EditButton->setEnabled(true);
        ui->DeleteButton->setEnabled(true);
    }
    // 初始化定时器
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ChonyaWindow::refresh_information);
    timer->start(1000);
    // 刷新数据
    refresh_data();
}

ChonyaWindow::~ChonyaWindow() {
    delete ui;
}

void ChonyaWindow::closeEvent(QCloseEvent *event) {
    QStringList windowNames = {
        tr("冲压模具增加"), tr("冲压模具产量输入"), tr("异常维修"),      tr("关单保养"), tr("末件不良"),
        tr("定期保养"),     tr("大保养"),           tr("呆滞6个月以上"), tr("其它"),     tr("冲压模具参数修改"),
        tr("AI问答"),       tr("BOM表查询"),        tr("数据库管理"),    tr("工单管理"), tr("工单信息管理"),
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

// ==================== 数据刷新相关 ====================

void ChonyaWindow::refresh_data() {
    QSqlQuery query;
    QSqlQueryModel *model;
    model = new QSqlQueryModel(ui->ModleList);
    QString sql = "select 模具编号,产品料号,保养情况 from type_message;";
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "刷新数据", "模具数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    model->setQuery(query);
    standardModel = new QStandardItemModel(model->rowCount(), model->columnCount(), this);
    for(int row = 0; row < model->rowCount(); ++row) {
        for(int column = 0; column < model->columnCount(); ++column) {
            QModelIndex index = model->index(row, column);
            QVariant value = model->data(index);
            standardModel->setItem(row, column, new QStandardItem(value.toString()));
        }
        if(model->data(model->index(row, 2)) != "当前无需保养") {
            for(int i = 0; i <= 2; i++) {
                standardModel->item(row, i)->setBackground(QColor(Qt::red));
            }
        }
    }
    for(int column = 0; column < model->columnCount(); ++column) {
        QString columnName = model->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
        standardModel->setHeaderData(column, Qt::Horizontal, columnName);
    }
    ui->ModleList->setModel(standardModel);
    ui->ModleList->setColumnWidth(0, 150);
    ui->ModleList->setColumnWidth(1, 200);
    ui->ModleList->horizontalHeader()->setVisible(true);
    ui->ModleList->verticalHeader()->setVisible(true);
    ui->ModleList->horizontalHeader()->setStretchLastSection(true);
    ui->ModleList->resizeRowsToContents();
    sortModelByMaintenanceStatus();
    id_value = "";
    ui->RuleView->clearContents();
    ui->MoldID->clear();
    ui->ProductID->clear();
    ui->MachineNum->clear();
    ui->DateNum->clear();
    ui->ProductStand->clear();
    ui->ControlStand->clear();
    ui->KeepStatus->clear();
    ui->DirRepair->clear();
    QSettings config("userconfig.ini", QSettings::IniFormat);
    if(!config.value("SELECTIONCONFIG/Mold").toString().isEmpty()) {
        QStandardItemModel *model;
        model = qobject_cast<QStandardItemModel *>(ui->ModleList->model());
        if(!model) {
            return;
        }
        QModelIndexList matches = model->match(model->index(0, 0), Qt::DisplayRole,
            config.value("SELECTIONCONFIG/Mold").toString(), -1, Qt::MatchExactly | Qt::MatchRecursive);
        if(!matches.isEmpty()) {
            QModelIndex targetIndex;
            targetIndex = matches.first();
            ui->ModleList->setCurrentIndex(targetIndex);
            ui->ModleList->selectionModel()->select(targetIndex, QItemSelectionModel::Select | QItemSelectionModel::Rows);
            ui->ModleList->scrollTo(targetIndex, QAbstractItemView::PositionAtCenter);
            id_value = config.value("SELECTIONCONFIG/Mold").toString();
            query.prepare("select * from type_message where 模具编号 = :mold_id");
            query.bindValue(":mold_id", id_value);
            if(!query.exec()) {
                QMessageBox::warning(this, "刷新数据", "模具数据查询失败：\n" + query.lastError().text(),
                    QMessageBox::Cancel);
                return;
            } else {
                if(query.next()) {
                    if(query.value("管制标准").toString() == "铜材材料厚度规格＜0.3mm") {
                        ui->RuleView->setItem(0, 0, new QTableWidgetItem("500w"));
                        ui->RuleView->setItem(0, 1, new QTableWidgetItem("250w"));
                        ui->RuleView->setItem(0, 2, new QTableWidgetItem("1000w"));
                    } else if(query.value("管制标准").toString() == "铜材材料厚度规格≧0.3且﹤0.5mm") {
                        ui->RuleView->setItem(0, 0, new QTableWidgetItem("400w"));
                        ui->RuleView->setItem(0, 1, new QTableWidgetItem("200w"));
                        ui->RuleView->setItem(0, 2, new QTableWidgetItem("800w"));
                    } else if(query.value("管制标准").toString() == "铜材材料厚度规格≧0.5mm") {
                        ui->RuleView->setItem(0, 0, new QTableWidgetItem("200w"));
                        ui->RuleView->setItem(0, 1, new QTableWidgetItem("100w"));
                        ui->RuleView->setItem(0, 2, new QTableWidgetItem("400w"));
                    } else if(query.value("管制标准").toString() == "不锈钢材料厚度规格＜0.5mm") {
                        ui->RuleView->setItem(0, 0, new QTableWidgetItem("50w"));
                        ui->RuleView->setItem(0, 1, new QTableWidgetItem("30w"));
                        ui->RuleView->setItem(0, 2, new QTableWidgetItem("100w"));
                    } else if(query.value("管制标准").toString() == "不锈钢材料厚度规格≧0.5mm") {
                        ui->RuleView->setItem(0, 0, new QTableWidgetItem("30w"));
                        ui->RuleView->setItem(0, 1, new QTableWidgetItem("20w"));
                        ui->RuleView->setItem(0, 2, new QTableWidgetItem("50w"));
                    } else {
                        ui->RuleView->setItem(0, 0, new QTableWidgetItem("0"));
                        ui->RuleView->setItem(0, 1, new QTableWidgetItem("0"));
                        ui->RuleView->setItem(0, 2, new QTableWidgetItem("0"));
                    }
                    ui->RuleView->item(0, 0)->setTextAlignment(Qt::AlignCenter);
                    ui->RuleView->item(0, 1)->setTextAlignment(Qt::AlignCenter);
                    ui->RuleView->item(0, 2)->setTextAlignment(Qt::AlignCenter);
                    ui->RuleView->setItem(1, 0, new QTableWidgetItem(query.value("下料零件累计").toString() + "w"));
                    ui->RuleView->setItem(1, 1, new QTableWidgetItem(query.value("关键易损件累计").toString() + "w"));
                    ui->RuleView->setItem(1, 2, new QTableWidgetItem(query.value("成型零件累计").toString() + "w"));
                    ui->RuleView->item(1, 0)->setTextAlignment(Qt::AlignCenter);
                    ui->RuleView->item(1, 1)->setTextAlignment(Qt::AlignCenter);
                    ui->RuleView->item(1, 2)->setTextAlignment(Qt::AlignCenter);
                    if(ui->RuleView->item(0, 0)->text().remove("w").toDouble() * 0.9 < ui->RuleView->item(1,
                        0)->text().remove("w").toDouble()) {
                        ui->RuleView->item(1, 0)->setBackground(QColor("red"));
                    }
                    if(ui->RuleView->item(0, 1)->text().remove("w").toDouble() * 0.9 < ui->RuleView->item(1,
                        1)->text().remove("w").toDouble()) {
                        ui->RuleView->item(1, 1)->setBackground(QColor("red"));
                    }
                    if(ui->RuleView->item(0, 2)->text().remove("w").toDouble() * 0.9 < ui->RuleView->item(1,
                        2)->text().remove("w").toDouble()) {
                        ui->RuleView->item(1, 2)->setBackground(QColor("red"));
                    }
                    ui->MoldID->setText(query.value("模具编号").toString());
                    ui->MoldID->setSelection(0, 0);
                    ui->ProductID->setText(query.value("产品料号").toString());
                    ui->MachineNum->setText(query.value("维修机台").toString());
                    ui->DateNum->setText(query.value("维修日期").toString());
                    ui->ProductStand->setText(query.value("材料规格").toString());
                    ui->ProductStand->setSelection(0, 0);
                    ui->ControlStand->setText(query.value("管制标准").toString());
                    ui->ControlStand->setSelection(0, 0);
                    ui->KeepStatus->setText(query.value("保养情况").toString());
                    ui->DirRepair->setText(query.value("模修").toString());
                }
            }
        }
    }
}

void ChonyaWindow::refresh_information() {
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
        refresh_time = 0;
    }
    QSqlQuery query;
    query.prepare("select count(*) from information_message where (接收用户 = :name or 接收用户 = '所有人') and 完成情况 = '1'");
    query.bindValue(":name", curr_name);
    if(!query.exec()) {
        QMessageBox::warning(this, "刷新信息列表", "信息列表数量查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        refresh_time = 0;
        message = 0;
        message_temp = 0;
        change_flag = false;
        timer->stop();
        return;
    } else {
        if(query.next()) {
            if(message_temp == 0) {
                message_temp = query.value(0).toInt();
            }
            message = query.value(0).toInt();
            if(message > message_temp) {
                QString sql =
                    QString("select 模具编号,信息 from information_message where (接收用户 = '%1' or 接收用户 = '所有人') and 完成情况 = '1' order by 日期 desc limit 1").arg(
                    curr_name);
                if(!query.exec(sql)) {
                    QMessageBox::warning(this, "刷新信息列表", "信息列表数据查询失败：\n" + query.lastError().text(),
                        QMessageBox::Cancel);
                    change_flag = false;
                    return;
                } else {
                    if(query.next()) {
                        QString show_message = query.value(0).toString() + ":\n" + query.value(1).toString();
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
        trayIcon->setToolTip(QString("当前消息条数（%1）").arg(message));
        ui->MessageLabel->setStyleSheet(
            "QPushButton{background-color: rgb(255, 255, 255);color: rgb(255, 0, 0);border-style: "
            "outset;}QPushButton:hover{background: rgb(100,100,100);}QPushButton:pressed{background-color: rgb(255, "
            "255, 255);border-style: outset;}");
    } else {
        change_flag = false;
        QIcon trayIconIcon(":/images/app.ico");
        trayIcon->setIcon(trayIconIcon);
        ui->MessageLabel->setText(QString("当前消息条数（%1）").arg(0));
        trayIcon->setToolTip("广东盟恩电子模具管理系统");
        ui->MessageLabel->setStyleSheet(
            "QPushButton{background-color: rgb(255, 255, 255);border-style: outset;}QPushButton:hover{background: "
            "rgb(100,100,100);}QPushButton:pressed{background-color: rgb(255, 255, 255);border-style: outset;}");
    }
}

void ChonyaWindow::on_RefreshButton_clicked() {
    refresh_data();
}

// ==================== UI交互相关 ====================

void ChonyaWindow::enable_windiow() {
    ui->centralwidget->setEnabled(true);
}

void ChonyaWindow::on_ModleList_clicked(const QModelIndex &index) {
    QModelIndex data_index = standardModel->index(index.row(), 0);
    id_value = data_index.data().toString();
    QSqlQuery query;
    query.prepare("select * from type_message where 模具编号 = :mold_id");
    query.bindValue(":mold_id", id_value);
    if(!query.exec()) {
        QMessageBox::warning(this, "查询模具数据", "模具数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        if(query.next()) {
            if(query.value("管制标准").toString() == "铜材材料厚度规格＜0.3mm") {
                ui->RuleView->setItem(0, 0, new QTableWidgetItem("500w"));
                ui->RuleView->setItem(0, 1, new QTableWidgetItem("250w"));
                ui->RuleView->setItem(0, 2, new QTableWidgetItem("1000w"));
            } else if(query.value("管制标准").toString() == "铜材材料厚度规格≧0.3且﹤0.5mm") {
                ui->RuleView->setItem(0, 0, new QTableWidgetItem("400w"));
                ui->RuleView->setItem(0, 1, new QTableWidgetItem("200w"));
                ui->RuleView->setItem(0, 2, new QTableWidgetItem("800w"));
            } else if(query.value("管制标准").toString() == "铜材材料厚度规格≧0.5mm") {
                ui->RuleView->setItem(0, 0, new QTableWidgetItem("200w"));
                ui->RuleView->setItem(0, 1, new QTableWidgetItem("100w"));
                ui->RuleView->setItem(0, 2, new QTableWidgetItem("400w"));
            } else if(query.value("管制标准").toString() == "不锈钢材料厚度规格＜0.5mm") {
                ui->RuleView->setItem(0, 0, new QTableWidgetItem("50w"));
                ui->RuleView->setItem(0, 1, new QTableWidgetItem("30w"));
                ui->RuleView->setItem(0, 2, new QTableWidgetItem("100w"));
            } else if(query.value("管制标准").toString() == "不锈钢材料厚度规格≧0.5mm") {
                ui->RuleView->setItem(0, 0, new QTableWidgetItem("30w"));
                ui->RuleView->setItem(0, 1, new QTableWidgetItem("20w"));
                ui->RuleView->setItem(0, 2, new QTableWidgetItem("50w"));
            } else {
                ui->RuleView->setItem(0, 0, new QTableWidgetItem("0"));
                ui->RuleView->setItem(0, 1, new QTableWidgetItem("0"));
                ui->RuleView->setItem(0, 2, new QTableWidgetItem("0"));
            }
            ui->RuleView->item(0, 0)->setTextAlignment(Qt::AlignCenter);
            ui->RuleView->item(0, 1)->setTextAlignment(Qt::AlignCenter);
            ui->RuleView->item(0, 2)->setTextAlignment(Qt::AlignCenter);
            ui->RuleView->setItem(1, 0, new QTableWidgetItem(query.value("下料零件累计").toString() + "w"));
            ui->RuleView->setItem(1, 1, new QTableWidgetItem(query.value("关键易损件累计").toString() + "w"));
            ui->RuleView->setItem(1, 2, new QTableWidgetItem(query.value("成型零件累计").toString() + "w"));
            ui->RuleView->item(1, 0)->setTextAlignment(Qt::AlignCenter);
            ui->RuleView->item(1, 1)->setTextAlignment(Qt::AlignCenter);
            ui->RuleView->item(1, 2)->setTextAlignment(Qt::AlignCenter);
            if(ui->RuleView->item(0, 0)->text().remove("w").toDouble() * 0.9 <
                ui->RuleView->item(1, 0)->text().remove("w").toDouble()) {
                ui->RuleView->item(1, 0)->setBackground(QColor("red"));
            }
            if(ui->RuleView->item(0, 1)->text().remove("w").toDouble() * 0.9 <
                ui->RuleView->item(1, 1)->text().remove("w").toDouble()) {
                ui->RuleView->item(1, 1)->setBackground(QColor("red"));
            }
            if(ui->RuleView->item(0, 2)->text().remove("w").toDouble() * 0.9 <
                ui->RuleView->item(1, 2)->text().remove("w").toDouble()) {
                ui->RuleView->item(1, 2)->setBackground(QColor("red"));
            }
            ui->MoldID->setText(query.value("模具编号").toString());
            ui->MoldID->setSelection(0, 0);
            ui->ProductID->setText(query.value("产品料号").toString());
            ui->MachineNum->setText(query.value("维修机台").toString());
            ui->DateNum->setText(query.value("维修日期").toString());
            ui->ProductStand->setText(query.value("材料规格").toString());
            ui->ProductStand->setSelection(0, 0);
            ui->ControlStand->setText(query.value("管制标准").toString());
            ui->ControlStand->setSelection(0, 0);
            ui->KeepStatus->setText(query.value("保养情况").toString());
            ui->DirRepair->setText(query.value("模修").toString());
            QSettings config("userconfig.ini", QSettings::IniFormat);
            config.setValue("SELECTIONCONFIG/Mold", ui->MoldID->text());
            config.sync();
        }
    }
}

void ChonyaWindow::on_MoldID_returnPressed() {
    QSqlQuery query;
    QString mold_id = "%" + ui->MoldID->text() + "%";
    QSqlQueryModel *model = new QSqlQueryModel(ui->ModleList);
    QString sql = "select 模具编号,产品料号,保养情况 from type_message where 模具编号 like :mold_id";
    query.prepare(sql);
    query.bindValue(":mold_id", mold_id);
    if(!query.exec()) {
        QMessageBox::warning(this, "查找模具", "模具数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        model->setQuery(query);
        standardModel = new QStandardItemModel(model->rowCount(), model->columnCount(), this);
        for(int row = 0; row < model->rowCount(); ++row) {
            for(int column = 0; column < model->columnCount(); ++column) {
                QModelIndex index = model->index(row, column);
                QVariant value = model->data(index);
                standardModel->setItem(row, column, new QStandardItem(value.toString()));
            }
            if(model->data(model->index(row, 2)) != "当前无需保养") {
                for(int i = 0; i <= 2; i++) {
                    standardModel->item(row, i)->setBackground(QColor(Qt::red));
                }
            }
        }
        for(int column = 0; column < model->columnCount(); ++column) {
            QString columnName = model->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
            standardModel->setHeaderData(column, Qt::Horizontal, columnName);
        }
        ui->ModleList->setModel(standardModel);
        ui->ModleList->setColumnWidth(0, 150);
        ui->ModleList->setColumnWidth(1, 200);
        ui->ModleList->horizontalHeader()->setVisible(1);
        ui->ModleList->verticalHeader()->setVisible(1);
        ui->ModleList->horizontalHeader()->setStretchLastSection(true);
        ui->ModleList->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->ModleList->resizeRowsToContents();
        sortModelByMaintenanceStatus();
    }
}

void ChonyaWindow::on_MoldID_textChanged(const QString &arg1) {
    if(arg1.isEmpty()) {
        QSqlQuery query;
        QSqlQueryModel *model;
        model = new QSqlQueryModel(ui->ModleList);
        QString sql = "select 模具编号,产品料号,保养情况 from type_message;";
        if(!query.exec(sql)) {
            QMessageBox::warning(this, "查找模具", "模具数据查询失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        }
        model->setQuery(query);
        standardModel = new QStandardItemModel(model->rowCount(), model->columnCount(), this);
        for(int row = 0; row < model->rowCount(); ++row) {
            for(int column = 0; column < model->columnCount(); ++column) {
                QModelIndex index = model->index(row, column);
                QVariant value = model->data(index);
                standardModel->setItem(row, column, new QStandardItem(value.toString()));
            }
            if(model->data(model->index(row, 2)) != "当前无需保养") {
                for(int i = 0; i <= 2; i++) {
                    standardModel->item(row, i)->setBackground(QColor(Qt::red));
                }
            }
        }
        for(int column = 0; column < model->columnCount(); ++column) {
            QString columnName = model->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
            standardModel->setHeaderData(column, Qt::Horizontal, columnName);
        }
        ui->ModleList->setModel(standardModel);
        ui->ModleList->setColumnWidth(0, 150);
        ui->ModleList->setColumnWidth(1, 200);
        ui->ModleList->horizontalHeader()->setVisible(true);
        ui->ModleList->verticalHeader()->setVisible(true);
        ui->ModleList->horizontalHeader()->setStretchLastSection(true);
        ui->ModleList->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->ModleList->resizeRowsToContents();
        sortModelByMaintenanceStatus();
        id_value = "";
        ui->RuleView->clearContents();
        ui->MoldID->clear();
        ui->ProductID->clear();
        ui->MachineNum->clear();
        ui->DateNum->clear();
        ui->ProductStand->clear();
        ui->ControlStand->clear();
        ui->KeepStatus->clear();
        ui->DirRepair->clear();
    }
}

void ChonyaWindow::on_FindButton_clicked() {
    if(ui->MoldID->text().isEmpty()) {
        QMessageBox::warning(this, "查找模具", "请输入模具编号", QMessageBox::Cancel);
        return;
    }
    QSqlQuery query;
    QString mold_id = "%" + ui->MoldID->text() + "%";
    QSqlQueryModel *model = new QSqlQueryModel(ui->ModleList);
    QString sql = "select 模具编号,产品料号,保养情况 from type_message where 模具编号 like :mold_id";
    query.prepare(sql);
    query.bindValue(":mold_id", mold_id);
    if(!query.exec()) {
        QMessageBox::warning(this, "查找模具", "模具数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        model->setQuery(query);
        standardModel = new QStandardItemModel(model->rowCount(), model->columnCount(), this);
        for(int row = 0; row < model->rowCount(); ++row) {
            for(int column = 0; column < model->columnCount(); ++column) {
                QModelIndex index = model->index(row, column);
                QVariant value = model->data(index);
                standardModel->setItem(row, column, new QStandardItem(value.toString()));
            }
            if(model->data(model->index(row, 2)) != "当前无需保养") {
                for(int i = 0; i <= 2; i++) {
                    standardModel->item(row, i)->setBackground(QColor(Qt::red));
                }
            }
        }
        for(int column = 0; column < model->columnCount(); ++column) {
            QString columnName = model->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
            standardModel->setHeaderData(column, Qt::Horizontal, columnName);
        }
        ui->ModleList->setModel(standardModel);
        ui->ModleList->setColumnWidth(0, 150);
        ui->ModleList->setColumnWidth(1, 200);
        ui->ModleList->horizontalHeader()->setVisible(1);
        ui->ModleList->verticalHeader()->setVisible(1);
        ui->ModleList->horizontalHeader()->setStretchLastSection(true);
        ui->ModleList->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->ModleList->resizeRowsToContents();
        sortModelByMaintenanceStatus();
        id_value = "";
    }
}

void ChonyaWindow::on_ModleList_doubleClicked(const QModelIndex &index) {
    Q_UNUSED(index);
    if(id_value.isEmpty()) {
        QMessageBox::warning(this, "录入产量", "请选择模具", QMessageBox::Cancel);
        return;
    }
    chonyaEnter = new ChonyaEnter(id_value);
    connect(chonyaEnter, SIGNAL(mysignal()), this, SLOT(refresh_data()));
    chonyaEnter->setWindowTitle("冲压模具产量输入");
    m_windowMap.insert(tr("冲压模具产量输入"), chonyaEnter);
    chonyaEnter->show();
}

void ChonyaWindow::onTrayIconActivated(QSystemTrayIcon::ActivationReason reason) {
    if(reason == QSystemTrayIcon::DoubleClick) {
        ChonyaWindow::showNormal();
        ChonyaWindow::activateWindow();
        if(message) {
            handleMessage = new HandleMessage(curr_auth, curr_name, this);
            handleMessage->setWindowTitle("工单信息管理");
            m_windowMap.insert(tr("工单信息管理"), handleMessage);
            handleMessage->show();
        }
    } else if(reason == QSystemTrayIcon::Trigger) { // 鼠标左键单击
        ChonyaWindow::showNormal();
        ChonyaWindow::activateWindow();
    }
}

// ==================== 按钮点击事件 ====================

void ChonyaWindow::on_AddButton_clicked() {
    chonyaAdd = new ChonyaAdd(this);
    connect(chonyaAdd, SIGNAL(mysignal()), this, SLOT(refresh_data()));
    chonyaAdd->setWindowTitle("冲压模具增加");
    m_windowMap.insert(tr("冲压模具增加"), chonyaAdd);
    chonyaAdd->show();
}

void ChonyaWindow::on_EditButton_clicked() {
    if(id_value.isEmpty()) {
        QMessageBox::warning(this, "模具参数修改", "请选择模具", QMessageBox::Cancel);
        return;
    }
    chonyaEdit = new ChonyaEdit(id_value, this);
    connect(chonyaEdit, SIGNAL(mysignal()), this, SLOT(refresh_data()));
    chonyaEdit->setWindowTitle("冲压模具参数修改");
    m_windowMap.insert(tr("冲压模具参数修改"), chonyaEdit);
    chonyaEdit->show();
}

void ChonyaWindow::on_DeleteButton_clicked() {
    QSqlQuery query;
    int machine_num = 0;
    QString mold_id = ui->MoldID->text();
    QString sql = "select 机台 from type_message where 模具编号 = :mold_id";
    query.prepare(sql);
    query.bindValue(":mold_id", mold_id);
    if(!query.exec()) {
        QMessageBox::warning(this, "删除模具", "模具机台查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        while(query.next()) {
            QString machineField = query.value(0).toString();
            QStringList machineList = machineField.split("#");
            for(const QString &machine : machineList) {
                if(!machine.isEmpty()) {
                    machine_num++;
                }
            }
        }
    }
    if(!mold_id.isEmpty()) {
        QString question = QString("您确定要删除(%1个机台履历) 吗？").arg(machine_num);
        int reply = QMessageBox::question(this, "删除模具", question, QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes) {
            sql = "delete from type_message where 模具编号 = :mold";
            query.prepare(sql);
            query.bindValue(":mold", mold_id);
            if(!query.exec()) {
                QMessageBox::warning(this, "删除模具", "模具数据删除失败：\n" + query.lastError().text(),
                    QMessageBox::Cancel);
                return;
            }
            sql = "delete from information_message where 模具编号 = :mold";
            query.prepare(sql);
            query.bindValue(":mold", mold_id);
            if(!query.exec()) {
                QMessageBox::warning(this, "删除模具", "模具信息列表删除失败：\n" + query.lastError().text(),
                    QMessageBox::Cancel);
                return;
            } else {
                QString table = id_value;
                table.replace("-", "_");
                sql = QString("drop table D%1;").arg(table);
                if(!query.exec(sql)) {
                    QMessageBox::warning(this, "删除模具", "模具信息列表删除失败：\n" + query.lastError().text(),
                        QMessageBox::Cancel);
                    return;
                } else {
                    QMessageBox::information(this, "删除模具", "模具删除成功", QMessageBox::Ok);
                    refresh_data();
                }
            }
        }
    } else {
        QMessageBox::warning(this, "删除模具", "请选择删除模具", QMessageBox::Cancel);
        return;
    }
}

void ChonyaWindow::on_EnterButton_clicked() {
    if(id_value.isEmpty()) {
        QMessageBox::warning(this, "录入产量", "请选择模具", QMessageBox::Cancel);
        return;
    }
    chonyaEnter = new ChonyaEnter(id_value);
    connect(chonyaEnter, SIGNAL(mysignal()), this, SLOT(refresh_data()));
    chonyaEnter->setWindowTitle("冲压模具产量输入");
    m_windowMap.insert(tr("冲压模具产量输入"), chonyaEnter);
    chonyaEnter->show();
}

void ChonyaWindow::on_KeepButton_clicked() {
    if(id_value.isEmpty()) {
        QMessageBox::warning(this, "保养管理", "请选择模具", QMessageBox::Cancel);
        return;
    }
    QMessageBox way_choice;
    way_choice.setWindowTitle("状态选择选择");
    way_choice.setText("请选择您的保养&维修内容：");
    QPushButton *way_button1 = way_choice.addButton("异常维修", QMessageBox::ActionRole);
    QPushButton *way_button2 = way_choice.addButton("关单保养", QMessageBox::ActionRole);
    QPushButton *way_button3 = way_choice.addButton("末件不良", QMessageBox::ActionRole);
    QPushButton *way_button4 = way_choice.addButton("定期保养", QMessageBox::ActionRole);
    QPushButton *way_button5 = way_choice.addButton("大保养", QMessageBox::ActionRole);
    QPushButton *way_button6 = way_choice.addButton("呆滞6个月以上", QMessageBox::ActionRole);
    QPushButton *way_button7 = way_choice.addButton("其它", QMessageBox::ActionRole);
    way_choice.addButton("取消", QMessageBox::RejectRole);
    way_choice.exec();
    if(way_choice.clickedButton() == way_button1) {
        chonyaKeep = new ChonyaKeep(id_value, 1, this);
        connect(chonyaKeep, SIGNAL(mysignal()), this, SLOT(refresh_data()));
        chonyaKeep->setWindowTitle("异常维修");
        m_windowMap.insert(tr("异常维修"), chonyaKeep);
        chonyaKeep->show();
    }
    if(way_choice.clickedButton() == way_button2) {
        chonyaKeep = new ChonyaKeep(id_value, 2, this);
        connect(chonyaKeep, SIGNAL(mysignal()), this, SLOT(refresh_data()));
        chonyaKeep->setWindowTitle("关单保养");
        m_windowMap.insert(tr("关单保养"), chonyaKeep);
        chonyaKeep->show();
    }
    if(way_choice.clickedButton() == way_button3) {
        chonyaKeep = new ChonyaKeep(id_value, 3, this);
        connect(chonyaKeep, SIGNAL(mysignal()), this, SLOT(refresh_data()));
        chonyaKeep->setWindowTitle("末件不良");
        m_windowMap.insert(tr("末件不良"), chonyaKeep);
        chonyaKeep->show();
    }
    if(way_choice.clickedButton() == way_button4) {
        chonyaKeep = new ChonyaKeep(id_value, 4, this);
        connect(chonyaKeep, SIGNAL(mysignal()), this, SLOT(refresh_data()));
        chonyaKeep->setWindowTitle("定期保养");
        m_windowMap.insert(tr("定期保养"), chonyaKeep);
        chonyaKeep->show();
    }
    if(way_choice.clickedButton() == way_button5) {
        chonyaKeep = new ChonyaKeep(id_value, 5, this);
        connect(chonyaKeep, SIGNAL(mysignal()), this, SLOT(refresh_data()));
        chonyaKeep->setWindowTitle("大保养");
        m_windowMap.insert(tr("大保养"), chonyaKeep);
        chonyaKeep->show();
    }
    if(way_choice.clickedButton() == way_button6) {
        chonyaKeep = new ChonyaKeep(id_value, 6, this);
        connect(chonyaKeep, SIGNAL(mysignal()), this, SLOT(refresh_data()));
        chonyaKeep->setWindowTitle("呆滞6个月以上");
        m_windowMap.insert(tr("呆滞6个月以上"), chonyaKeep);
        chonyaKeep->show();
    }
    if(way_choice.clickedButton() == way_button7) {
        chonyaKeep = new ChonyaKeep(id_value, 7, this);
        connect(chonyaKeep, SIGNAL(mysignal()), this, SLOT(refresh_data()));
        chonyaKeep->setWindowTitle("其它");
        m_windowMap.insert(tr("其它"), chonyaKeep);
        chonyaKeep->show();
    }
}

void ChonyaWindow::on_MessageLabel_clicked() {
    handleMessage = new HandleMessage(curr_auth, curr_name, this);
    handleMessage->setWindowTitle("工单信息管理");
    m_windowMap.insert(tr("工单信息管理"), handleMessage);
    handleMessage->show();
}

void ChonyaWindow::on_WorkButton_clicked() {
    if(ui->MoldID->text().isEmpty()) {
        QMessageBox::warning(this, "工单管理", "请选择模具", QMessageBox::Cancel);
        return;
    }
    ui->centralwidget->setEnabled(false);
    QSqlDatabase currentDb = QSqlDatabase::database();
    QString databaseName = currentDb.databaseName();
    handleWorks = new HandleWorks(databaseName, id_value, curr_name, this);
    connect(handleWorks, SIGNAL(enablesignal()), this, SLOT(enable_windiow()));
    handleWorks->setWindowTitle("工单管理");
    m_windowMap.insert(tr("工单管理"), handleWorks);
    handleWorks->show();
}

void ChonyaWindow::on_BomButton_clicked() {
    QMessageBox choice_box;
    choice_box.setWindowTitle("选择打开方式");
    choice_box.setText("请选择您的打开方式：");
    QPushButton *button1 = choice_box.addButton("打开excle表", QMessageBox::ActionRole);
    QPushButton *button2 = choice_box.addButton("打开数据库", QMessageBox::ActionRole);
    choice_box.addButton("取消", QMessageBox::RejectRole);
    choice_box.exec();
    if(choice_box.clickedButton() == button1) {
        QDesktopServices::openUrl(QUrl("file://192.168.101.250/bom/冲压/", QUrl::TolerantMode));
    } else if(choice_box.clickedButton() == button2) {
        handleBom = new HandleBom(this);
        handleBom->setWindowTitle("BOM表查询");
        m_windowMap.insert(tr("BOM表查询"), handleBom);
        handleBom->show();
    }
}

void ChonyaWindow::on_commandLinkButton_clicked() {
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

void ChonyaWindow::on_AIButton_clicked() {
    aiWindow = new AiWindow(this);
    aiWindow->setWindowTitle("AI问答");
    m_windowMap.insert(tr("AI问答"), aiWindow);
    aiWindow->show();
}

void ChonyaWindow::on_CheckButton_clicked() {
    bool ok;
    QStringList items;
    QDate date_str = QDate::currentDate();
    QString newDateStr = date_str.toString("yyyy.MM.dd");
    QString select_year1 = newDateStr.left(5);
    date_str = QDate::currentDate().addYears(-1);
    newDateStr = date_str.toString("yyyy.MM.dd");
    QString select_year2 = newDateStr.left(5);
    items << select_year2 + "12" << select_year1 + "01" << select_year1 + "02" << select_year1 + "03"
        << select_year1 + "04" << select_year1 + "05" << select_year1 + "06" << select_year1 + "07"
        << select_year1 + "08" << select_year1 + "09" << select_year1 + "10" << select_year1 + "11";
    QString selected = QInputDialog::getItem(this, "导出模具保养盘点信息",
            "请选择需要导出的保养数据月份:", items, 0, false, &ok);
    if(ok && !selected.isEmpty()) {
        int row = 4;
        QDate date_str;
        date_str = QDate::currentDate().addMonths(-1);
        QString newDateStr = date_str.toString("yyyy.MM.dd");
        QString select_month = newDateStr.left(7);
        QSqlQuery query, select;
        QString fileName, file_temp;
        QSettings config("userconfig.ini", QSettings::IniFormat);
        QXlsx::Document xlsx(":/ducument/check_cykeep.xlsx");
        QString sql =
            QString("select distinct 模具编号,产品料号 from keep_message where (状态描述 = '关单保养' or 状态描述 = '定期保养' or 状态描述 = '大保养') and 日期 like '%1%';").arg(
            select_month);
        if(query.exec(sql)) {
            while(query.next()) {
                QString table = query.value("模具编号").toString();
                table.replace("-", "_");
                xlsx.write(row, 1, query.value("模具编号").toString(), Song12C);
                xlsx.write(row, 2, query.value("产品料号").toString(), Song12C);
                sql = QString("select count(distinct 日期) from D%1 where 备注 like '%关单保养' and 日期 like '%2%';").arg(
                    table).arg(select_month);
                if(!select.exec(sql)) {
                    QMessageBox::warning(this, "导出模具保养盘点信息",
                        "关单保养数量查询失败：\n" + select.lastError().text(), QMessageBox::Cancel);
                    return;
                } else {
                    if(select.next()) {
                        xlsx.write(row, 3, select.value(0).toString(), Song12C);
                    }
                }
                QString percent1, percent2, percent3;
                sql = QString("select count(*) from D%1 where 备注 = '下料零件定期保养' and 日期 like '%2%';").arg(
                    table).arg(select_month);
                if(!select.exec(sql)) {
                    QMessageBox::warning(this, "导出模具保养盘点信息",
                        "下料零件定期保养数量查询失败：\n" + select.lastError().text(), QMessageBox::Cancel);
                    return;
                } else {
                    if(select.next()) {
                        percent1 = select.value(0).toString();
                    }
                }
                sql = QString("select count(*) from D%1 where 备注 = '关键易损件定期保养' and 日期 like '%2%';").arg(
                    table).arg(select_month);
                if(!select.exec(sql)) {
                    QMessageBox::warning(this, "导出模具保养盘点信息",
                        "关键易损件定期保养数量查询失败：\n" + select.lastError().text(), QMessageBox::Cancel);
                    return;
                } else {
                    if(select.next()) {
                        percent2 = select.value(0).toString();
                    }
                }
                sql = QString("select count(*) from D%1 where 备注 = '成型零件定期保养' and 日期 like '%2%';").arg(
                    table).arg(select_month);
                if(!select.exec(sql)) {
                    QMessageBox::warning(this, "导出模具保养盘点信息",
                        "成型零件定期保养数量查询失败：\n" + select.lastError().text(), QMessageBox::Cancel);
                    return;
                } else {
                    if(select.next()) {
                        percent3 = select.value(0).toString();
                    }
                }
                xlsx.write(row, 4, percent1, Song12C);
                xlsx.write(row, 5, percent2, Song12C);
                xlsx.write(row, 6, percent3, Song12C);
                sql = QString("select count(*) from D%1 where 备注 = '大保养' and 日期 like '%2%';").arg(table).arg(
                    select_month);
                if(!select.exec(sql)) {
                    QMessageBox::warning(this, "导出模具保养盘点信息",
                        "大保养数量查询失败：\n" + select.lastError().text(), QMessageBox::Cancel);
                    return;
                } else {
                    if(select.next()) {
                        xlsx.write(row, 7, select.value(0).toString(), Song12C);
                    }
                }
                row++;
            }
            fileName = QFileDialog::getSaveFileName(this, "导出模具保养盘点信息",
                    config.value("DOCUMENTCONFIG/DocumentPath").toString() + select_month + "冲压模具保养盘点记录表",
                    "Excel Files (*.xlsx)");
            file_temp = fileName;
            file_temp = file_temp.left(file_temp.lastIndexOf('/')) + "/";
            config.setValue("DOCUMENTCONFIG/DocumentPath", file_temp);
            if(fileName.isEmpty()) {
                return;
            }
            if(!fileName.endsWith(".xlsx")) {
                fileName.append(".xlsx");
            }
            if(!xlsx.saveAs(fileName)) {
                QMessageBox::critical(this, "导出模具保养盘点信息", "冲压模具保养盘点记录表创建失败");
            }
        } else {
            QMessageBox::warning(this, "导出模具保养盘点信息",
                "模具保养盘点信息导出失败：\n" + query.lastError().text(), QMessageBox::Cancel);
        }
    }
}

void ChonyaWindow::on_ReturnButton_clicked() {
    timer->stop();
    delete trayIcon;
    mainWindow->show();
    this->close();
}

// ==================== 其他功能 ====================

void ChonyaWindow::showWorkMessage() {
    ChonyaWindow::show();
    handleMessage = new HandleMessage(curr_auth, curr_name, this);
    handleMessage->setWindowTitle("工单信息管理");
    m_windowMap.insert(tr("工单信息管理"), handleMessage);
    handleMessage->show();
}

// ==================== 私有辅助函数 ====================

void ChonyaWindow::sortModelByMaintenanceStatus() {
    if(!standardModel) {
        return;
    }
    int rowCount = standardModel->rowCount();
    if(rowCount == 0) {
        return;
    }
    // 收集需要保养的行索引和不需要保养的行索引
    QList<int> maintenanceRowIndices;  // 需要保养的行索引
    QList<int> normalRowIndices;       // 不需要保养的行索引
    for(int row = 0; row < rowCount; ++row) {
        // 检查第3列（索引2）是否为"当前无需保养"
        QStandardItem* statusItem = standardModel->item(row, 2);
        if(statusItem && statusItem->text() != "当前无需保养") {
            maintenanceRowIndices.append(row);
        } else {
            normalRowIndices.append(row);
        }
    }
    // 如果所有行都需要保养或都不需要保养，则无需重新排序
    if(maintenanceRowIndices.isEmpty() || normalRowIndices.isEmpty()) {
        return;
    }
    // 创建一个新的模型，先添加需要保养的行，再添加不需要保养的行
    QStandardItemModel* newModel = new QStandardItemModel(0, standardModel->columnCount(), this);
    // 复制表头
    for(int col = 0; col < standardModel->columnCount(); ++col) {
        QString headerText = standardModel->headerData(col, Qt::Horizontal, Qt::DisplayRole).toString();
        newModel->setHeaderData(col, Qt::Horizontal, headerText);
    }
    // 先添加需要保养的行
    for(int rowIndex : maintenanceRowIndices) {
        QList<QStandardItem *> rowItems;
        for(int col = 0; col < standardModel->columnCount(); ++col) {
            QStandardItem* originalItem = standardModel->item(rowIndex, col);
            if(originalItem) {
                QStandardItem* newItem = new QStandardItem(originalItem->text());
                newItem->setBackground(originalItem->background());
                newItem->setTextAlignment(originalItem->textAlignment());
                rowItems.append(newItem);
            } else {
                rowItems.append(new QStandardItem());
            }
        }
        newModel->appendRow(rowItems);
    }
    // 再添加不需要保养的行
    for(int rowIndex : normalRowIndices) {
        QList<QStandardItem *> rowItems;
        for(int col = 0; col < standardModel->columnCount(); ++col) {
            QStandardItem* originalItem = standardModel->item(rowIndex, col);
            if(originalItem) {
                QStandardItem* newItem = new QStandardItem(originalItem->text());
                newItem->setBackground(originalItem->background());
                newItem->setTextAlignment(originalItem->textAlignment());
                rowItems.append(newItem);
            } else {
                rowItems.append(new QStandardItem());
            }
        }
        newModel->appendRow(rowItems);
    }
    // 替换模型
    standardModel->deleteLater();
    standardModel = newModel;
    ui->ModleList->setModel(standardModel);
}
