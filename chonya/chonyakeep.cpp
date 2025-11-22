#include "chonyakeep.h"
#include "ui_chonyakeep.h"

#include <QDate>
#include <QListView>
#include <QPushButton>
#include <QScroller>

// ============================================================================
// 构造函数和析构函数
// ============================================================================

ChonyaKeep::ChonyaKeep(QVariant id_value, QVariant stata_value, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChonyaKeep)
    , handleData(nullptr)
    , chonyaEnter(nullptr)
    , curr_stata(stata_value.toInt())
    , stata_flag(0)
    , return_flag(true)
    , stata()
    , stata_des()
    , title_header(MaintenanceConstants::TITLE_HEADER)
    , databaseName()
    , idvalue_(id_value)
    , curr_id(id_value.toString())
    , statavalue_(stata_value)
    , dateTime(QDateTime::currentDateTime()) {
    ui->setupUi(this);
    ui->HandleButton->setVisible(false);
    initializeFormats();
    initializeUI();
    loadUserData();
    initializeCompleters();
    refresh_data();
}

ChonyaKeep::~ChonyaKeep() {
    if(handleData) {
        handleData->deleteLater();
        handleData = nullptr;
    }
    if(chonyaEnter) {
        chonyaEnter->deleteLater();
        chonyaEnter = nullptr;
    }
    delete ui;
}

// ============================================================================
// 初始化相关函数
// ============================================================================

void ChonyaKeep::initializeFormats() {
    Song10CB.setFontSize(10);
    Song10CB.setFontName("宋体");
    Song10CB.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    Song10CB.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    Song10CB.setBorderStyle(QXlsx::Format::BorderThin);
    Song11C.setFontSize(11);
    Song11C.setFontName("宋体");
    Song11C.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    Song12C.setFontSize(12);
    Song12C.setFontName("宋体");
    Song12C.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    Song12CB.setFontSize(12);
    Song12CB.setFontName("宋体");
    Song12CB.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    Song12CB.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    Song12CB.setBorderStyle(QXlsx::Format::BorderThin);
    Song12CBL.setFontSize(12);
    Song12CBL.setFontName("宋体");
    Song12CBL.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    Song12CBL.setBorderStyle(QXlsx::Format::BorderThin);
    Song12CBL.setLeftBorderStyle(QXlsx::Format::BorderDouble);
    Song12CCT.setFontSize(12);
    Song12CCT.setFontName("宋体");
    Song12CCT.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    Song12CCT.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    Song12CCT.setBorderStyle(QXlsx::Format::BorderThin);
    Song12CCT.setTopBorderStyle(QXlsx::Format::BorderDouble);
}

void ChonyaKeep::initializeUI() {
    // 隐藏默认控件
    ui->AddCheck->hide();
    ui->Label13->hide();
    ui->StataDes->hide();
    ui->Label14->hide();
    ui->ChangeID->hide();
    ui->Label15->hide();
    ui->ChangeNum->hide();
    ui->Label18->hide();
    ui->OtherDes->hide();
    // 设置滚动视图
    QListView *listView1 = qobject_cast<QListView *>(ui->Operater->view());
    if(listView1) {
        QScroller *scroller1 = QScroller::scroller(listView1);
        scroller1->grabGesture(listView1->viewport(), QScroller::LeftMouseButtonGesture);
        listView1->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    }
    QListView *listView2 = qobject_cast<QListView *>(ui->DirRepair->view());
    if(listView2) {
        QScroller *scroller2 = QScroller::scroller(listView2);
        scroller2->grabGesture(listView2->viewport(), QScroller::LeftMouseButtonGesture);
        listView2->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    }
    // 设置日期时间
    ui->MoldID->setText(curr_id);
    ui->DateTime->setText(dateTime.toString("yyyy.MM.dd"));
    ui->DownTime->setText(dateTime.toString("hh:mm:ss"));
    // 处理状态配置
    processStateConfiguration();
}

void ChonyaKeep::processStateConfiguration() {
    // 处理状态编辑框显示（合并重复代码）
    ui->StataEdit->setVisible(curr_stata == static_cast<int>(MaintenanceState::OtherOperation));
    // 处理保养类型显示
    bool hideKeepType = (curr_stata == static_cast<int>(MaintenanceState::AbnormalRepair) ||
        curr_stata == static_cast<int>(MaintenanceState::LastPieceDefect) ||
        curr_stata == static_cast<int>(MaintenanceState::MajorMaintenance) ||
        curr_stata == static_cast<int>(MaintenanceState::OtherOperation));
    ui->Label17->setVisible(!hideKeepType);
    ui->KeepType->setVisible(!hideKeepType);
    // 添加关单保养选项
    if(curr_stata != static_cast<int>(MaintenanceState::CloseOrderMaintenance)) {
        ui->StataDes->addItem(MaintenanceConstants::CLOSE_ORDER_MAINTENANCE);
    }
    // 根据状态设置标题和显示AddCheck
    switch(curr_stata) {
    case static_cast<int>(MaintenanceState::AbnormalRepair):
        ui->Label1->setText(title_header + "异常维修");
        ui->AddCheck->show();
        break;
    case static_cast<int>(MaintenanceState::CloseOrderMaintenance):
        ui->Label1->setText(title_header + "关单保养");
        ui->AddCheck->show();
        break;
    case static_cast<int>(MaintenanceState::LastPieceDefect):
        ui->Label1->setText(title_header + "末件不良");
        ui->AddCheck->show();
        break;
    case static_cast<int>(MaintenanceState::RegularMaintenance):
        ui->Label1->setText(title_header + "定期保养");
        break;
    case static_cast<int>(MaintenanceState::MajorMaintenance):
        ui->Label1->setText(title_header + "大保养");
        break;
    case static_cast<int>(MaintenanceState::IdleOver6Months):
        ui->Label1->setText(title_header + "呆滞6个月以上");
        ui->AddCheck->show();
        break;
    case static_cast<int>(MaintenanceState::OtherOperation):
        ui->Label1->setText(title_header + "其它操作");
        ui->AddCheck->show();
        break;
    }
}

void ChonyaKeep::loadUserData() {
    QSqlQuery query;
    QStringList data;
    QString sql = "SELECT name FROM user_message;";
    if(!query.exec(sql)) {
        showWarning("界面初始化", "用户名称查询失败：\n" + query.lastError().text());
        return;
    }
    while(query.next()) {
        QString name = query.value(0).toString();
        if(name == "NULL" || name == "俞増涛") {
            continue;
        }
        data.append(name);
    }
    ui->Operater->addItems(data);
    ui->DirRepair->addItems(data);
}

void ChonyaKeep::initializeCompleters() {
    QStringList data;
    for(int i = 0; i < ui->Operater->count(); ++i) {
        data.append(ui->Operater->itemText(i));
    }
    QStyledItemDelegate *delegate = new QStyledItemDelegate(this);
    QString style = "QAbstractItemView{font: 18pt \"微软雅黑\";background-color:rgb(255,255,255);color:rgb(0,0,0);}"
                    "QAbstractItemView::item:hover{background-color:rgb(0, 120, 212)}";
    QCompleter *completer1 = new QCompleter(data, this);
    completer1->setMaxVisibleItems(10);
    completer1->setCaseSensitivity(Qt::CaseInsensitive);
    completer1->setCompletionMode(QCompleter::PopupCompletion);
    completer1->setFilterMode(Qt::MatchContains);
    ui->Operater->setCompleter(completer1);
    completer1->popup()->setItemDelegate(delegate);
    completer1->popup()->setStyleSheet(style);
    QCompleter *completer2 = new QCompleter(data, this);
    completer2->setMaxVisibleItems(10);
    completer2->setCaseSensitivity(Qt::CaseInsensitive);
    completer2->setCompletionMode(QCompleter::PopupCompletion);
    completer2->setFilterMode(Qt::MatchContains);
    ui->DirRepair->setCompleter(completer2);
    completer2->popup()->setItemDelegate(delegate);
    completer2->popup()->setStyleSheet(style);
}

// ============================================================================
// 工具函数
// ============================================================================

bool ChonyaKeep::showError(const QString &title, const QString &message) {
    QMessageBox::critical(this, title, message);
    return false;
}

bool ChonyaKeep::showSuccess(const QString &title, const QString &message) {
    QMessageBox::information(this, title, message);
    return true;
}

bool ChonyaKeep::showWarning(const QString &title, const QString &message) {
    QMessageBox::warning(this, title, message, QMessageBox::Cancel);
    return false;
}

bool ChonyaKeep::showQuestion(const QString &title, const QString &question) {
    return QMessageBox::question(this, title, question, QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes;
}

QString ChonyaKeep::getTableName() const {
    QString table = curr_id;
    table.replace("-", "_");
    return table;
}

QDate ChonyaKeep::getLastMonthDate() const {
    return QDate::currentDate().addMonths(-1);
}

QString ChonyaKeep::getSaveFileName(const QString &title, const QString &defaultName) {
    QSettings config("userconfig.ini", QSettings::IniFormat);
    QString fileName = QFileDialog::getSaveFileName(this, title,
            config.value("DOCUMENTCONFIG/DocumentPath").toString() + defaultName,
            "Excel Files (*.xlsx)");
    if(!fileName.isEmpty()) {
        QString filePath = fileName.left(fileName.lastIndexOf('/') + 1);
        config.setValue("DOCUMENTCONFIG/DocumentPath", filePath);
        config.sync();
        if(!fileName.endsWith(".xlsx")) {
            fileName.append(".xlsx");
        }
    }
    return fileName;
}

bool ChonyaKeep::saveExcelFile(QXlsx::Document &xlsx, const QString &fileName, const QString &errorTitle) {
    if(fileName.isEmpty()) {
        return false;
    }
    if(!xlsx.saveAs(fileName)) {
        showError(errorTitle, errorTitle + "创建失败");
        return false;
    }
    return true;
}

// ============================================================================
// 数据刷新
// ============================================================================

void ChonyaKeep::refresh_data() {
    QSqlQuery query;
    // 查询模具基本信息
    QString sql = "SELECT 产品料号, 产品名称, 保养情况 FROM type_message WHERE 模具编号 = :mold_id";
    query.prepare(sql);
    query.bindValue(":mold_id", curr_id);
    if(!query.exec()) {
        showWarning("刷新数据", "模具数据查询失败：\n" + query.lastError().text());
        return;
    }
    if(query.next()) {
        ui->ProductID->setText(query.value(0).toString());
        ui->ProductName->setText(query.value(1).toString());
        QString maintenanceStatus = query.value("保养情况").toString();
        ui->ProblemDes->setText(maintenanceStatus);
        // 设置保养类型
        if(maintenanceStatus.contains(MaintenanceConstants::FEED_PART)) {
            ui->KeepType->setCurrentText(MaintenanceConstants::FEED_PART);
        } else if(maintenanceStatus.contains(MaintenanceConstants::VULNERABLE_PART)) {
            ui->KeepType->setCurrentText(MaintenanceConstants::VULNERABLE_PART);
        } else if(maintenanceStatus.contains(MaintenanceConstants::MOLDING_PART)) {
            ui->KeepType->setCurrentText(MaintenanceConstants::MOLDING_PART);
        }
    }
    // 查询产量数据（使用参数化查询）
    QString tableName = getTableName();
    sql = QString("SELECT * FROM D%1 ORDER BY 序号 DESC LIMIT 1").arg(tableName);
    if(!query.exec(sql)) {
        showWarning("刷新数据", "产量数据查询失败：\n" + query.lastError().text());
        return;
    }
    if(query.next()) {
        ui->MachineNum->setText(query.value("机台号").toString());
        ui->LifeNum->setText(query.value("累计冲次数").toString());
        ui->Operater->setCurrentText(query.value("操作员").toString());
        ui->DirRepair->setCurrentText(query.value("模修").toString());
    } else {
        ui->LifeNum->setText("0");
    }
    ui->MoldID->setSelection(0, 0);
    ui->LifeNum->setSelection(0, 0);
}

// ============================================================================
// Excel操作相关函数
// ============================================================================

void ChonyaKeep::writeBasicInfoToExcel(QXlsx::Document &xlsx) {
    xlsx.write("A3", "机台号：" + ui->MachineNum->text(), Song12C);
    xlsx.write("B4", ui->DateTime->text(), Song12CCT);
    xlsx.write("D4", ui->DownTime->text(), Song12CCT);
    xlsx.write("F4", ui->MoldID->text(), Song12CCT);
    xlsx.write("I4", ui->ProductID->toPlainText(), Song12CCT);
    xlsx.write("B5", ui->LifeNum->text(), Song12CB);
    xlsx.write("D5", ui->Operater->currentText(), Song12CB);
    xlsx.write("D12", ui->DirRepair->currentText(), Song12CB);
    xlsx.write("A6", stata_des, Song12CBL);
    xlsx.write("B7", ui->ProblemDes->toPlainText(), Song12CB);
}

void ChonyaKeep::writeProductInfoToExcel(QXlsx::Document &xlsx, const QString &cell, const QString &maintenanceType) {
    if(cell == "A3") {
        // xlsx1格式
        xlsx.write("A3", "产品名称：" + ui->ProductName->toPlainText(), Song11C);
        xlsx.write("D3", "产品料号：" + ui->ProductID->toPlainText(), Song11C);
        xlsx.write("G3", "模号：" + ui->ProductID->toPlainText(), Song11C);
    } else if(cell == "F3") {
        // xlsx2格式
        xlsx.write("A3", "产品名称：" + ui->ProductName->toPlainText(), Song11C);
        xlsx.write("F3", "产品料号：" + ui->ProductID->toPlainText(), Song11C);
        xlsx.write("M3", "模号：" + ui->ProductID->toPlainText(), Song11C);
    }
    if(maintenanceType == MaintenanceConstants::REGULAR_MAINTENANCE) {
        xlsx.write("G5", MaintenanceConstants::REGULAR_MAINTENANCE, Song10CB);
    } else if(maintenanceType == MaintenanceConstants::CLOSE_ORDER_MAINTENANCE) {
        xlsx.write("F5", MaintenanceConstants::CLOSE_ORDER_MAINTENANCE, Song10CB);
    } else {
        xlsx.write("F5", "不定期保养", Song10CB);
    }
}

// ============================================================================
// 状态处理相关函数
// ============================================================================

void ChonyaKeep::determineStateAndDescription() {
    bool isAddChecked = ui->AddCheck->isChecked();
    QString stataDesText = ui->StataDes->currentText();
    QString otherText = ui->StataEdit->text();
    switch(curr_stata) {
    case static_cast<int>(MaintenanceState::AbnormalRepair):
        if(isAddChecked) {
            if(stataDesText == MaintenanceConstants::CLOSE_ORDER_MAINTENANCE) {
                stata_flag = static_cast<int>(StateFlag::AbnormalRepairCloseOrder);
                stata = "异常维修&" + MaintenanceConstants::CLOSE_ORDER_MAINTENANCE;
                stata_des =
                    "状态描述： ■①异常维修 ■②关单保养 □③末件不良 □④定期保养 □⑤大保养 □⑥呆滞6个月以上  □⑦";
            } else if(stataDesText == MaintenanceConstants::REGULAR_MAINTENANCE) {
                stata_flag = static_cast<int>(StateFlag::AbnormalRepairRegular);
                stata = "异常维修&" + MaintenanceConstants::REGULAR_MAINTENANCE;
                stata_des =
                    "状态描述： ■①异常维修 □②关单保养 □③末件不良 ■④定期保养 □⑤大保养 □⑥呆滞6个月以上  □⑦";
            } else if(stataDesText == MaintenanceConstants::MAJOR_MAINTENANCE) {
                stata_flag = static_cast<int>(StateFlag::AbnormalRepairMajor);
                stata = "异常维修&" + MaintenanceConstants::MAJOR_MAINTENANCE;
                stata_des =
                    "状态描述： ■①异常维修 □②关单保养 □③末件不良 □④定期保养 ■⑤大保养 □⑥呆滞6个月以上  □⑦";
            } else if(stataDesText == MaintenanceConstants::IDLE_OVER_6_MONTHS) {
                stata_flag = static_cast<int>(StateFlag::AbnormalRepairIdle);
                stata = "异常维修&呆滞6个月以上的保养";
                stata_des =
                    "状态描述： ■①异常维修 □②关单保养 □③末件不良 □④定期保养 □⑤大保养 ■⑥呆滞6个月以上  □⑦";
            }
        } else {
            stata_flag = static_cast<int>(StateFlag::AbnormalRepairOnly);
            stata = "异常维修";
            stata_des =
                "状态描述： ■①异常维修 □②关单保养 □③末件不良 □④定期保养 □⑤大保养 □⑥呆滞6个月以上  □⑦";
        }
        break;
    case static_cast<int>(MaintenanceState::CloseOrderMaintenance):
        if(isAddChecked) {
            if(stataDesText == MaintenanceConstants::REGULAR_MAINTENANCE) {
                stata_flag = static_cast<int>(StateFlag::CloseOrderRegular);
                stata = MaintenanceConstants::CLOSE_ORDER_MAINTENANCE + "&" + MaintenanceConstants::REGULAR_MAINTENANCE;
                stata_des =
                    "状态描述： □①异常维修 ■②关单保养 □③末件不良 ■④定期保养 □⑤大保养 □⑥呆滞6个月以上  □⑦";
            } else if(stataDesText == MaintenanceConstants::MAJOR_MAINTENANCE) {
                stata_flag = static_cast<int>(StateFlag::CloseOrderMajor);
                stata = MaintenanceConstants::CLOSE_ORDER_MAINTENANCE + "&" + MaintenanceConstants::MAJOR_MAINTENANCE;
                stata_des =
                    "状态描述： □①异常维修 ■②关单保养 □③末件不良 □④定期保养 ■⑤大保养 □⑥呆滞6个月以上  □⑦";
            } else if(stataDesText == MaintenanceConstants::IDLE_OVER_6_MONTHS) {
                stata_flag = static_cast<int>(StateFlag::CloseOrderIdle);
                stata = MaintenanceConstants::CLOSE_ORDER_MAINTENANCE + "&呆滞6个月以上的保养";
                stata_des =
                    "状态描述： □①异常维修 ■②关单保养 □③末件不良 □④定期保养 □⑤大保养 ■⑥呆滞6个月以上  □⑦";
            }
        } else {
            stata_flag = static_cast<int>(StateFlag::CloseOrderOnly);
            stata = MaintenanceConstants::CLOSE_ORDER_MAINTENANCE;
            stata_des =
                "状态描述： □①异常维修 ■②关单保养 □③末件不良 □④定期保养 □⑤大保养 □⑥呆滞6个月以上  □⑦";
        }
        break;
    case static_cast<int>(MaintenanceState::LastPieceDefect):
        if(isAddChecked) {
            if(stataDesText == MaintenanceConstants::CLOSE_ORDER_MAINTENANCE) {
                stata_flag = static_cast<int>(StateFlag::LastPieceCloseOrder);
                stata = "末件不良&" + MaintenanceConstants::CLOSE_ORDER_MAINTENANCE;
                stata_des =
                    "状态描述： □①异常维修 ■②关单保养 ■③末件不良 □④定期保养 □⑤大保养 □⑥呆滞6个月以上  □⑦";
            } else if(stataDesText == MaintenanceConstants::REGULAR_MAINTENANCE) {
                stata_flag = static_cast<int>(StateFlag::LastPieceRegular);
                stata = "末件不良&" + MaintenanceConstants::REGULAR_MAINTENANCE;
                stata_des =
                    "状态描述： □①异常维修 □②关单保养 ■③末件不良 ■④定期保养 □⑤大保养 □⑥呆滞6个月以上  □⑦";
            } else if(stataDesText == MaintenanceConstants::MAJOR_MAINTENANCE) {
                stata_flag = static_cast<int>(StateFlag::LastPieceMajor);
                stata = "末件不良&" + MaintenanceConstants::MAJOR_MAINTENANCE;
                stata_des =
                    "状态描述： □①异常维修 □②关单保养 ■③末件不良 □④定期保养 ■⑤大保养 □⑥呆滞6个月以上  □⑦";
            } else if(stataDesText == MaintenanceConstants::IDLE_OVER_6_MONTHS) {
                stata_flag = static_cast<int>(StateFlag::LastPieceIdle);
                stata = "末件不良&呆滞6个月以上的保养";
                stata_des =
                    "状态描述： □①异常维修 □②关单保养 ■③末件不良 □④定期保养 □⑤大保养 ■⑥呆滞6个月以上  □⑦";
            }
        } else {
            stata_flag = static_cast<int>(StateFlag::LastPieceOnly);
            stata = "末件不良";
            stata_des =
                "状态描述： □①异常维修 □②关单保养 ■③末件不良 □④定期保养 □⑤大保养 □⑥呆滞6个月以上  □⑦";
        }
        break;
    case static_cast<int>(MaintenanceState::RegularMaintenance):
        stata_flag = static_cast<int>(StateFlag::RegularOnly);
        stata = MaintenanceConstants::REGULAR_MAINTENANCE;
        stata_des =
            "状态描述： □①异常维修 □②关单保养 □③末件不良 ■④定期保养 □⑤大保养 □⑥呆滞6个月以上  □⑦";
        break;
    case static_cast<int>(MaintenanceState::MajorMaintenance):
        stata_flag = static_cast<int>(StateFlag::MajorOnly);
        stata = MaintenanceConstants::MAJOR_MAINTENANCE;
        stata_des =
            "状态描述： □①异常维修 □②关单保养 □③末件不良 □④定期保养 ■⑤大保养 □⑥呆滞6个月以上  □⑦";
        break;
    case static_cast<int>(MaintenanceState::IdleOver6Months):
        stata_flag = static_cast<int>(StateFlag::IdleOnly);
        stata = "呆滞6个月以上的保养";
        stata_des =
            "状态描述： □①异常维修 □②关单保养 □③末件不良 □④定期保养 □⑤大保养 ■⑥呆滞6个月以上  □⑦";
        break;
    case static_cast<int>(MaintenanceState::OtherOperation):
        if(isAddChecked) {
            if(stataDesText == MaintenanceConstants::CLOSE_ORDER_MAINTENANCE) {
                stata_flag = static_cast<int>(StateFlag::OtherCloseOrder);
                stata = otherText + MaintenanceConstants::CLOSE_ORDER_MAINTENANCE;
                stata_des =
                    "状态描述： □①异常维修 ■②关单保养 □③末件不良 □④定期保养 □⑤大保养 □⑥呆滞6个月以上  ■⑦"
                    + otherText;
            } else if(stataDesText == MaintenanceConstants::REGULAR_MAINTENANCE) {
                stata_flag = static_cast<int>(StateFlag::OtherRegular);
                stata = otherText + MaintenanceConstants::REGULAR_MAINTENANCE;
                stata_des =
                    "状态描述： □①异常维修 □②关单保养 □③末件不良 ■④定期保养 □⑤大保养 □⑥呆滞6个月以上  ■⑦"
                    + otherText;
            } else if(stataDesText == MaintenanceConstants::MAJOR_MAINTENANCE) {
                stata_flag = static_cast<int>(StateFlag::OtherMajor);
                stata = otherText + MaintenanceConstants::MAJOR_MAINTENANCE;
                stata_des =
                    "状态描述： □①异常维修 □②关单保养 □③末件不良 □④定期保养 ■⑤大保养 □⑥呆滞6个月以上  ■⑦"
                    + otherText;
            } else if(stataDesText == MaintenanceConstants::IDLE_OVER_6_MONTHS) {
                stata_flag = static_cast<int>(StateFlag::OtherIdle);
                stata = otherText + "呆滞6个月以上的保养";
                stata_des =
                    "状态描述： □①异常维修 □②关单保养 □③末件不良 □④定期保养 □⑤大保养 ■⑥呆滞6个月以上  ■⑦"
                    + otherText;
            }
        } else {
            stata_flag = static_cast<int>(StateFlag::OtherOnly);
            stata = otherText;
            stata_des =
                "状态描述： □①异常维修 □②关单保养 □③末件不良 □④定期保养 □⑤大保养 □⑥呆滞6个月以上  ■⑦"
                + otherText;
        }
        break;
    }
}

void ChonyaKeep::handleStateForExcel(int stataFlag) {
    QXlsx::Document xlsx1(QString(":/ducument/%1_keep1.xlsx").arg("chonya"));
    QXlsx::Document xlsx2(QString(":/ducument/%1_keep2.xlsx").arg("chonya"));
    bool needXlsx1 = false;
    bool needXlsx2 = false;
    QString maintenanceType;
    switch(stataFlag) {
    case static_cast<int>(StateFlag::AbnormalRepairCloseOrder):
    case static_cast<int>(StateFlag::AbnormalRepairIdle):
    case static_cast<int>(StateFlag::CloseOrderOnly):
    case static_cast<int>(StateFlag::CloseOrderIdle):
    case static_cast<int>(StateFlag::LastPieceCloseOrder):
    case static_cast<int>(StateFlag::LastPieceIdle):
    case static_cast<int>(StateFlag::IdleOnly):
    case static_cast<int>(StateFlag::OtherCloseOrder):
    case static_cast<int>(StateFlag::OtherIdle):
        needXlsx1 = true;
        maintenanceType = "不定期保养";
        writeProductInfoToExcel(xlsx1, "A3", maintenanceType);
        break;
    case static_cast<int>(StateFlag::AbnormalRepairRegular):
    case static_cast<int>(StateFlag::CloseOrderRegular):
    case static_cast<int>(StateFlag::LastPieceRegular):
    case static_cast<int>(StateFlag::RegularOnly):
    case static_cast<int>(StateFlag::OtherRegular):
        needXlsx1 = true;
        maintenanceType = MaintenanceConstants::REGULAR_MAINTENANCE;
        writeProductInfoToExcel(xlsx1, "A3", maintenanceType);
        break;
    case static_cast<int>(StateFlag::AbnormalRepairMajor):
    case static_cast<int>(StateFlag::CloseOrderMajor):
    case static_cast<int>(StateFlag::LastPieceMajor):
    case static_cast<int>(StateFlag::MajorOnly):
    case static_cast<int>(StateFlag::OtherMajor):
        needXlsx2 = true;
        writeProductInfoToExcel(xlsx2, "F3", "");
        break;
    }
    // 保存xlsx1
    if(needXlsx1) {
        QString fileName = getSaveFileName("创建不定期&定期保养记录表",
                "冲压模具不定期&定期保养记录表");
        if(saveExcelFile(xlsx1, fileName, "创建不定期&定期保养记录表")) {
            showSuccess("创建维修&保养记录表", "维修&保养记录表创建成功");
        }
    }
    // 保存xlsx2
    else if(needXlsx2) {
        QString fileName = getSaveFileName("创建大保养记录表", "冲压模具大保养记录表");
        if(saveExcelFile(xlsx2, fileName, "创建大保养记录表")) {
            showSuccess("创建维修&保养记录表", "维修&保养记录表创建成功");
        }
    }
}

// ============================================================================
// 数据库操作相关函数
// ============================================================================

bool ChonyaKeep::queryLatestProductionData(QSqlQuery &query, QString &total,
    QString &feed, QString &vulnerable, QString &molding) {
    QString tableName = getTableName();
    QString sql = QString("SELECT * FROM D%1 ORDER BY 序号 DESC LIMIT 1").arg(tableName);
    if(!query.exec(sql)) {
        showWarning("模具保养", "产量数据查询失败：\n" + query.lastError().text());
        return false;
    }
    if(!query.next()) {
        showWarning("模具保养", "产量数据不存在");
        return false;
    }
    total = query.value("累计冲次数").toString();
    feed = query.value("下料零件累计").toString();
    vulnerable = query.value("关键易损件累计").toString();
    molding = query.value("成型零件累计").toString();
    return true;
}

bool ChonyaKeep::insertProductionData(QSqlQuery &query, const QString &maintenanceType) {
    // 先查询最新数据
    QString total, feed, vulnerable, molding;
    if(!queryLatestProductionData(query, total, feed, vulnerable, molding)) {
        return false;
    }
    // 准备插入SQL
    QString tableName = getTableName();
    QString sql = QString("INSERT INTO D%1 (日期, 机台号, 当日产量, 累计冲次数, "
                          "下料零件累计, 关键易损件累计, 成型零件累计, 操作员, 模修, 备注) "
                          "VALUES (:date, :machine_num, :product_num, :total_num, "
                          ":feed_num, :vulnerable_num, :molding_num, :operator, :repair, :des)").arg(tableName);
    query.prepare(sql);
    query.bindValue(":date", ui->DateTime->text());
    query.bindValue(":machine_num", ui->MachineNum->text());
    query.bindValue(":product_num", "0");
    query.bindValue(":total_num", total);
    query.bindValue(":operator", ui->Operater->currentText());
    query.bindValue(":repair", ui->DirRepair->currentText());
    // 根据保养类型设置不同的值
    if(maintenanceType == MaintenanceConstants::CLOSE_ORDER_MAINTENANCE) {
        QString keepType = ui->KeepType->currentText();
        if(keepType == MaintenanceConstants::FEED_PART) {
            query.bindValue(":feed_num", feed);
            query.bindValue(":vulnerable_num", vulnerable);
            query.bindValue(":molding_num", molding);
            query.bindValue(":des", MaintenanceConstants::FEED_PART + MaintenanceConstants::CLOSE_ORDER_MAINTENANCE);
        } else if(keepType == MaintenanceConstants::VULNERABLE_PART) {
            query.bindValue(":feed_num", feed);
            query.bindValue(":vulnerable_num", vulnerable);
            query.bindValue(":molding_num", molding);
            query.bindValue(":des", MaintenanceConstants::VULNERABLE_PART + MaintenanceConstants::CLOSE_ORDER_MAINTENANCE);
        } else if(keepType == MaintenanceConstants::MOLDING_PART) {
            query.bindValue(":feed_num", feed);
            query.bindValue(":vulnerable_num", vulnerable);
            query.bindValue(":molding_num", molding);
            query.bindValue(":des", MaintenanceConstants::MOLDING_PART + MaintenanceConstants::CLOSE_ORDER_MAINTENANCE);
        }
    } else if(maintenanceType == MaintenanceConstants::REGULAR_MAINTENANCE) {
        QString keepType = ui->KeepType->currentText();
        query.bindValue(":feed_num", feed);
        query.bindValue(":vulnerable_num", vulnerable);
        query.bindValue(":molding_num", molding);
        if(keepType == MaintenanceConstants::FEED_PART) {
            query.bindValue(":feed_num", "0");
            query.bindValue(":des", MaintenanceConstants::FEED_PART + MaintenanceConstants::REGULAR_MAINTENANCE);
        } else if(keepType == MaintenanceConstants::VULNERABLE_PART) {
            query.bindValue(":vulnerable_num", "0");
            query.bindValue(":des", MaintenanceConstants::VULNERABLE_PART + MaintenanceConstants::REGULAR_MAINTENANCE);
        } else if(keepType == MaintenanceConstants::MOLDING_PART) {
            query.bindValue(":molding_num", "0");
            query.bindValue(":des", MaintenanceConstants::MOLDING_PART + MaintenanceConstants::REGULAR_MAINTENANCE);
        }
    } else if(maintenanceType == MaintenanceConstants::MAJOR_MAINTENANCE) {
        query.bindValue(":feed_num", "0");
        query.bindValue(":vulnerable_num", "0");
        query.bindValue(":molding_num", "0");
        query.bindValue(":des", MaintenanceConstants::MAJOR_MAINTENANCE);
    }
    if(!query.exec()) {
        showWarning("模具保养", "产量数据插入失败：\n" + query.lastError().text());
        return false;
    }
    return true;
}

bool ChonyaKeep::updateInformationMessage(QSqlQuery &query, const QString &moldNature) {
    QString sql = "UPDATE information_message SET 日期 = :curr_time, 信息 = :set_information, "
                  "完成情况 = :finish_status WHERE 模具编号 = :mold AND 模具性质 = :mold_nature";
    query.prepare(sql);
    query.bindValue(":curr_time", dateTime.toString("yyyy-MM-dd hh:mm:ss"));
    query.bindValue(":set_information", "");
    query.bindValue(":finish_status", "0");
    query.bindValue(":mold", curr_id);
    query.bindValue(":mold_nature", moldNature);
    if(!query.exec()) {
        showWarning("模具保养", "模具信息列表更新失败：\n" + query.lastError().text());
        return false;
    }
    return true;
}

bool ChonyaKeep::deleteLatestProductionRecord(QSqlQuery &query) {
    QString tableName = getTableName();
    QString sql = QString("DELETE FROM D%1 ORDER BY 序号 DESC LIMIT 1").arg(tableName);
    if(!query.exec(sql)) {
        showWarning("撤回保养数据", "产量数据删除失败：\n" + query.lastError().text());
        return false;
    }
    return true;
}

bool ChonyaKeep::deleteLatestMaintenanceRecord(QSqlQuery &query) {
    QString sql = "DELETE FROM keep_message WHERE 模具编号 = :mold_id ORDER BY 序号 DESC LIMIT 1";
    query.prepare(sql);
    query.bindValue(":mold_id", curr_id);
    if(!query.exec()) {
        showWarning("撤回保养数据", "保养数据删除失败：\n" + query.lastError().text());
        return false;
    }
    return true;
}

// ============================================================================
// 保养处理相关函数
// ============================================================================

void ChonyaKeep::openProductionInputWindow() {
    if(chonyaEnter) {
        chonyaEnter->deleteLater();
    }
    chonyaEnter = new ChonyaEnter(ui->MoldID->text(), this);
    chonyaEnter->setWindowTitle("冲压模具产量输入");
    m_windowMap.insert(tr("冲压模具产量输入"), chonyaEnter);
    chonyaEnter->show();
    QThread::msleep(100);
    chonyaEnter->close();
}

void ChonyaKeep::handleCloseOrderMaintenance() {
    QSqlQuery query;
    if(!insertProductionData(query, MaintenanceConstants::CLOSE_ORDER_MAINTENANCE)) {
        return;
    }
    if(!updateInformationMessage(query, ui->KeepType->currentText())) {
        return;
    }
    openProductionInputWindow();
}

void ChonyaKeep::handleRegularMaintenance() {
    QSqlQuery query;
    if(!insertProductionData(query, MaintenanceConstants::REGULAR_MAINTENANCE)) {
        return;
    }
    if(!updateInformationMessage(query, ui->KeepType->currentText())) {
        return;
    }
    openProductionInputWindow();
}

void ChonyaKeep::handleMajorMaintenance() {
    QSqlQuery query;
    if(!insertProductionData(query, MaintenanceConstants::MAJOR_MAINTENANCE)) {
        return;
    }
    // 更新所有类型的模具信息
    QStringList moldNatures = {MaintenanceConstants::WHOLE_MOLD,
        MaintenanceConstants::FEED_PART,
        MaintenanceConstants::VULNERABLE_PART,
        MaintenanceConstants::MOLDING_PART
    };
    for(const QString &nature : moldNatures) {
        if(!updateInformationMessage(query, nature)) {
            return;
        }
    }
    openProductionInputWindow();
}

// ============================================================================
// 历史记录相关函数
// ============================================================================

void ChonyaKeep::exportHistoryRecords(const QString &monthFilter, const QString &fileNameSuffix) {
    Q_UNUSED(fileNameSuffix);
    QSqlQuery query;
    QXlsx::Document xlsx3(QString(":/ducument/%1_keep3.xlsx").arg("chonya"));
    QString sql;
    if(monthFilter.isEmpty()) {
        sql = "SELECT * FROM keep_message";
    } else {
        sql = "SELECT * FROM keep_message WHERE 日期 LIKE :date_filter AND 模具编号 = :mold_id";
        query.prepare(sql);
        query.bindValue(":date_filter", monthFilter + "%");
        query.bindValue(":mold_id", ui->MoldID->text());
    }
    if(!query.exec(sql)) {
        showWarning("导出维修&保养记录履历", "保养数据查询失败：\n" + query.lastError().text());
        return;
    }
    int row = 3;
    while(query.next()) {
        for(int i = 1; i < 13; ++i) {
            xlsx3.write(row, i, query.value(i - 1).toString(), Song12CB);
        }
        ++row;
    }
    QString defaultName = monthFilter.isEmpty() ?
        "冲压模具维修&保养记录履历表" :
        ui->MoldID->text() + "-" + monthFilter + "维修&保养记录履历表";
    QString fileName = getSaveFileName("导出维修&保养记录履历", defaultName);
    if(saveExcelFile(xlsx3, fileName, "导出维修&保养记录履历")) {
        showSuccess("导出维修&保养记录履历", "维修&保养记录履历表创建成功");
    }
}

void ChonyaKeep::exportAllHistoryRecords() {
    exportHistoryRecords("", "冲压模具维修&保养记录履历表");
}

// ============================================================================
// UI事件处理函数
// ============================================================================

void ChonyaKeep::closeEvent(QCloseEvent *event) {
    Q_UNUSED(event);
    if(QWidget *target = m_windowMap.value(tr("冲压模具产量输入"))) {
        if(!target->isHidden()) {
            target->close();
            target->deleteLater();
            m_windowMap.remove(tr("冲压模具产量输入"));
        }
    }
    if(QWidget *target = m_windowMap.value(tr("模具保养表"))) {
        if(!target->isHidden()) {
            target->close();
            target->deleteLater();
            m_windowMap.remove(tr("模具保养表"));
        }
    }
}

void ChonyaKeep::on_AddCheck_stateChanged(int arg1) {
    bool visible = (arg1 != 0);
    ui->Label13->setVisible(visible);
    ui->StataDes->setVisible(visible);
    ui->Label17->setVisible(visible);
    ui->KeepType->setVisible(visible);
}

void ChonyaKeep::on_ChangeCheck_stateChanged(int arg1) {
    bool visible = (arg1 != 0);
    ui->Label14->setVisible(visible);
    ui->ChangeID->setVisible(visible);
    ui->Label15->setVisible(visible);
    ui->ChangeNum->setVisible(visible);
}

void ChonyaKeep::on_OtherCheck_stateChanged(int arg1) {
    if(arg1) {
        ui->KeepDes->resize(430, 70);
        ui->Label18->show();
        ui->OtherDes->show();
    } else {
        ui->KeepDes->resize(430, 170);
        ui->Label18->hide();
        ui->OtherDes->hide();
    }
}

void ChonyaKeep::on_StataDes_currentIndexChanged(const QString &arg1) {
    bool hideKeepType = (arg1 == MaintenanceConstants::MAJOR_MAINTENANCE);
    ui->Label17->setVisible(!hideKeepType);
    ui->KeepType->setVisible(!hideKeepType);
}

void ChonyaKeep::on_GetButton_clicked() {
    if(handleData) {
        handleData->deleteLater();
    }
    handleData = new HandleData(curr_id, "keep", this);
    handleData->setWindowTitle("模具保养表");
    m_windowMap.insert(tr("模具保养表"), handleData);
    handleData->show();
}

void ChonyaKeep::on_HandleButton_clicked() {
    QXlsx::Document xlsx0(QString(":/ducument/%1_keep0.xlsx").arg("chonya"));
    determineStateAndDescription();
    writeBasicInfoToExcel(xlsx0);
    QString fileName = getSaveFileName("创建维修&保养记录表", "冲压模具维修&保养记录表");
    if(!saveExcelFile(xlsx0, fileName, "创建维修&保养记录表")) {
        return;
    }
    handleStateForExcel(stata_flag);
}

void ChonyaKeep::on_FinishedButton_clicked() {
    if(ui->LifeNum->text().isEmpty()) {
        showWarning("模具保养", "累计冲次数不能为空");
        return;
    }
    // 处理不同类型的保养
    if(curr_stata == static_cast<int>(MaintenanceState::CloseOrderMaintenance) ||
        (ui->KeepType->isVisible() && ui->StataDes->isVisible() &&
        ui->StataDes->currentText() == MaintenanceConstants::CLOSE_ORDER_MAINTENANCE)) {
        handleCloseOrderMaintenance();
    }
    if(curr_stata == static_cast<int>(MaintenanceState::RegularMaintenance) ||
        (ui->KeepType->isVisible() && ui->StataDes->isVisible() &&
        ui->StataDes->currentText() == MaintenanceConstants::REGULAR_MAINTENANCE)) {
        handleRegularMaintenance();
    }
    if(curr_stata == static_cast<int>(MaintenanceState::MajorMaintenance) ||
        (ui->KeepType->isVisible() && ui->StataDes->isVisible() &&
        ui->StataDes->currentText() == MaintenanceConstants::MAJOR_MAINTENANCE)) {
        handleMajorMaintenance();
    }
    // 确定状态描述
    determineStateAndDescription();
    // 插入保养记录
    QSqlQuery query;
    QString sql = "INSERT INTO keep_message (日期, 模具编号, 机台号, 产品料号, 状态描述, "
                  "问题点, 维修对策, 更换备件号, 数量, 累计模次数, 备注) "
                  "VALUES (:date, :mold_id, :machine_num, :product_id, :stata_des, "
                  ":problem_des, :keep_des, :change_id, :number, :total_num, :other_des)";
    query.prepare(sql);
    query.bindValue(":date", ui->DateTime->text());
    query.bindValue(":mold_id", curr_id);
    query.bindValue(":machine_num", ui->MachineNum->text());
    query.bindValue(":product_id", ui->ProductID->toPlainText());
    query.bindValue(":stata_des", stata);
    query.bindValue(":problem_des", ui->ProblemDes->toPlainText());
    query.bindValue(":keep_des", ui->KeepDes->toPlainText());
    query.bindValue(":change_id", ui->ChangeID->text());
    query.bindValue(":number", ui->ChangeNum->text());
    query.bindValue(":total_num", ui->LifeNum->text());
    query.bindValue(":other_des", ui->OtherDes->toPlainText());
    if(!query.exec()) {
        showWarning("模具保养", "保养数据插入失败：\n" + query.lastError().text());
        return;
    }
    showSuccess("模具保养", "模具保养成功");
    return_flag = false;
    refresh_data();
    emit mysignal();
}

void ChonyaKeep::on_HistoryButton_clicked() {
    QMessageBox choiceBox;
    choiceBox.setWindowTitle("选择导出方式");
    choiceBox.setText("请选择您需要的内容：");
    QPushButton *button1 = choiceBox.addButton("仅导出该模具本月保养历史", QMessageBox::ActionRole);
    QPushButton *button2 = choiceBox.addButton("仅导出该模具上月保养历史", QMessageBox::ActionRole);
    QPushButton *button3 = choiceBox.addButton("导出全部保养历史", QMessageBox::ActionRole);
    choiceBox.addButton("取消", QMessageBox::RejectRole);
    choiceBox.exec();
    if(choiceBox.clickedButton() == button1) {
        QDate date = QDate::currentDate();
        QString monthFilter = date.toString("yyyy.MM");
        exportHistoryRecords(monthFilter, ui->MoldID->text() + "-" + monthFilter + "维修&保养记录履历表");
    } else if(choiceBox.clickedButton() == button2) {
        QDate date = getLastMonthDate();
        QString monthFilter = date.toString("yyyy.MM");
        exportHistoryRecords(monthFilter, ui->MoldID->text() + "-" + monthFilter + "维修&保养记录履历表");
    } else if(choiceBox.clickedButton() == button3) {
        exportAllHistoryRecords();
    }
}

void ChonyaKeep::on_ReturnButton_clicked() {
    if(return_flag) {
        showSuccess("撤回保养数据", "当前没有保养数据可以撤回");
        return;
    }
    if(!showQuestion("撤回保养数据", "您确定要撤回上一条数据吗？")) {
        return;
    }
    QSqlQuery query;
    // 删除产量数据（如果需要）
    bool needDeleteProduction = !((curr_stata == static_cast<int>(MaintenanceState::AbnormalRepair) ||
        curr_stata == static_cast<int>(MaintenanceState::LastPieceDefect) ||
        curr_stata == static_cast<int>(MaintenanceState::OtherOperation)) &&
        !ui->KeepType->isVisible());
    if(needDeleteProduction) {
        if(!deleteLatestProductionRecord(query)) {
            return;
        }
        openProductionInputWindow();
    }
    // 删除保养记录
    if(!deleteLatestMaintenanceRecord(query)) {
        return;
    }
    showSuccess("撤回保养数据", "保养数据撤回成功");
    return_flag = true;
    refresh_data();
}
