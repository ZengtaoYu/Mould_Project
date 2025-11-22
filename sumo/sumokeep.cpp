#include "sumokeep.h"
#include "ui_sumokeep.h"

#include <QDebug>
#include <QThread>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSettings>
#include <QCompleter>
#include <QMessageBox>
#include <QFileDialog>
#include <QStandardPaths>
#include <QStyledItemDelegate>
#include <QListView>
#include <QScroller>
#include <QAbstractItemView>
#include <QPushButton>
#include <QDate>
#include <QCloseEvent>
#include "xlsxchart.h"
#include "xlsxworkbook.h"
#include "xlsxdocument.h"
#include "xlsxcellrange.h"
#include "xlsxrichstring.h"
#include "xlsxchartsheet.h"
#include "sumo/sumoenter.h"
#include "comom/handledata.h"

// ==================== 构造函数和析构函数 ====================

SumoKeep::SumoKeep(QVariant id_value, QVariant stata_value, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::SumoKeep),
      sumoEnter(nullptr),
      handleData(nullptr),
      idvalue_(id_value),
      statavalue_(stata_value),
      curr_id(id_value.toString()),
      curr_stata(stata_value.toInt()),
      return_flag(true),
      dateTime(QDateTime::currentDateTime()),
      stata_flag(0),
      set_product_num1(0),
      set_product_num2(0),
      title_header("成型模具"),
      databaseName(QSqlDatabase::database().databaseName()) {
    ui->setupUi(this);
    initializeFormats();
    initializeUI();
    initializeUserData();
    configureUIByState();
    refresh_data();
}

SumoKeep::~SumoKeep() {
    cleanupWindows();
    delete ui;
}

// ==================== 初始化辅助函数 ====================

void SumoKeep::initializeFormats() {
    Song12C.setFontSize(12);
    Song12C.setFontName("宋体");
    Song12C.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    Song12CB.setFontSize(12);
    Song12CB.setFontName("宋体");
    Song12CB.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    Song12CB.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    Song12CB.setBorderStyle(QXlsx::Format::BorderThin);
}

void SumoKeep::initializeUI() {
    ui->LifeNum->setVisible(false);
    ui->DateTime->setText(dateTime.toString("yyyy.MM.dd"));
    ui->MoldID->setText(curr_id);
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
    // 初始化状态描述下拉框
    if(curr_stata != 2) {
        ui->StataDes->addItem("关单保养");
    }
    ui->StataDes->addItem("定期保养");
    ui->StataDes->addItem("特定易损件");
    ui->StataDes->addItem("大保养");
    ui->StataDes->addItem("呆滞6个月以上");
    // 隐藏初始不需要的控件
    ui->AddCheck->hide();
    ui->Label14->hide();
    ui->StataDes->hide();
    ui->Label15->hide();
    ui->ChangeID->hide();
    ui->Label16->hide();
    ui->ChangeNum->hide();
}

void SumoKeep::initializeUserData() {
    QSqlQuery query;
    QStringList data1, data2;
    // 查询调机员
    QString sql = "select name from user_message where type = '调机员';";
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "界面初始化", "用户调机员姓名查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    while(query.next()) {
        QString name = query.value(0).toString();
        if(name != "NULL" && name != "俞増涛") {
            data1.append(name);
        }
    }
    // 查询维修员
    sql = "select name from user_message where type = '维修员';";
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "界面初始化", "用户维修员姓名查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    while(query.next()) {
        QString name = query.value(0).toString();
        if(name != "NULL" && name != "俞増涛") {
            data2.append(name);
        }
    }
    ui->Operater->addItems(data1);
    ui->DirRepair->addItems(data2);
    setupCompleters(data1, data2);
}

void SumoKeep::setupCompleters(const QStringList &data1, const QStringList &data2) {
    QStyledItemDelegate *delegate = new QStyledItemDelegate(this);
    QString style = "QAbstractItemView{font: 18pt \"微软雅黑\";background-color:rgb(255,255,255);color:rgb(0,0,0);}"
                    "QAbstractItemView::item:hover{background-color:rgb(0, 120, 212)}";
    // 设置调机员自动完成
    QCompleter *completer1 = new QCompleter(data1, this);
    completer1->setMaxVisibleItems(10);
    completer1->setCaseSensitivity(Qt::CaseInsensitive);
    completer1->setCompletionMode(QCompleter::PopupCompletion);
    completer1->setFilterMode(Qt::MatchContains);
    ui->Operater->setCompleter(completer1);
    completer1->popup()->setItemDelegate(delegate);
    completer1->popup()->setStyleSheet(style);
    // 设置维修员自动完成
    QCompleter *completer2 = new QCompleter(data2, this);
    completer2->setMaxVisibleItems(10);
    completer2->setCaseSensitivity(Qt::CaseInsensitive);
    completer2->setCompletionMode(QCompleter::PopupCompletion);
    completer2->setFilterMode(Qt::MatchContains);
    ui->DirRepair->setCompleter(completer2);
    completer2->popup()->setItemDelegate(delegate);
    completer2->popup()->setStyleSheet(style);
}

void SumoKeep::configureUIByState() {
    // 配置状态编辑框显示
    ui->StataEdit->setVisible(curr_stata == 7);
    // 根据状态设置标题和显示AddCheck
    switch(curr_stata) {
    case 1:
        ui->Label1->setText(title_header + "异常维修");
        ui->AddCheck->show();
        break;
    case 2:
        ui->Label1->setText(title_header + "关单保养");
        ui->AddCheck->show();
        break;
    case 3:
        ui->Label1->setText(title_header + "转单换线");
        ui->AddCheck->show();
        break;
    case 4:
        ui->Label1->setText(title_header + "定期保养");
        break;
    case 5:
        ui->Label1->setText(title_header + "大保养");
        break;
    case 6:
        ui->Label1->setText(title_header + "呆滞6个月以上");
        ui->AddCheck->show();
        break;
    case 7:
        ui->Label1->setText(title_header + "其它操作");
        ui->AddCheck->show();
        break;
    }
}

// ==================== 数据刷新 ====================

void SumoKeep::refresh_data() {
    QSqlQuery query;
    // 合并查询：同时获取模具信息和产量数据
    QString tableName = buildTableName(curr_id);
    // 查询模具基本信息
    QString sql =
        "select 产品名称,产品料号,穴数,保养情况,剩余订单数1,剩余订单数2 from type_message where 模具编号 = :mold_id";
    query.prepare(sql);
    query.bindValue(":mold_id", curr_id);
    if(!query.exec()) {
        QMessageBox::warning(this, "刷新数据", "模具数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        ui->ProductName->setText(query.value(0).toString());
        ui->OutLabel->setText("/" + query.value(2).toString());
        ui->ProblemDes->setText(query.value(3).toString());
        set_product_num1 = query.value(4).toInt();
        set_product_num2 = query.value(5).toInt();
    }
    // 查询产量数据
    sql = QString("select * from D%1 order by 序号 desc limit 1;").arg(tableName);
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "刷新数据", "产量数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        ui->MachineNum->setText(query.value("机台号").toString());
        ui->LifeNum->setText(query.value("累计模数").toString());
        ui->OutNum->setValue(query.value("穴数").toString().split('/').first().toInt());
        ui->DirRepair->setCurrentText(query.value("模修").toString());
    } else {
        ui->OutNum->setValue(ui->OutLabel->text().split('/').first().toInt());
    }
    ui->MoldID->setSelection(0, 0);
    ui->LifeNum->setSelection(0, 0);
}

// ==================== 保养完成相关函数 ====================

void SumoKeep::on_FinishedButton_clicked() {
    if(!validateInput()) {
        return;
    }
    // 如果需要插入产量数据
    bool needInsertProduction = ((curr_stata == 1 || curr_stata == 2 || curr_stata == 3 || curr_stata == 7)
        && ui->StataDes->isVisible()) || (curr_stata == 4 || curr_stata == 5 || curr_stata == 6);
    if(needInsertProduction) {
        if(!insertProductionData()) {
            return;
        }
        if(!updateInformationMessage()) {
            return;
        }
        showSumoEnterWindow();
    }
    // 构建状态描述
    QString statusDesc = buildStatusDescription();
    // 插入保养记录
    if(!insertKeepMessage(statusDesc)) {
        return;
    }
    QMessageBox::information(this, "完成保养", "模具保养成功", QMessageBox::Ok);
    return_flag = false;
    refresh_data();
    emit mysignal();
}

bool SumoKeep::validateInput() {
    if(ui->OutNum->text().isEmpty()) {
        QMessageBox::warning(this, "模具保养", "模具穴数不能为空", QMessageBox::Cancel);
        return false;
    }
    return true;
}

bool SumoKeep::insertProductionData() {
    QSqlQuery query;
    QString tableName = buildTableName(curr_id);
    QString sql = QString("select * from D%1 order by 序号 desc limit 1;").arg(tableName);
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "模具保养", "产量数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    if(!query.next()) {
        QMessageBox::warning(this, "模具保养", "产量数据不存在\n" + query.lastError().text(), QMessageBox::Cancel);
        return false;
    }
    QString total = query.value("累计模数").toString();
    QString keep_num1 = query.value("定期保养模累计数").toString();
    QString keep_num2 = query.value("特定易损件管制模累计数").toString();
    QString keep_num3 = query.value("大保养模累计数").toString();
    QString product_num1 = query.value("剩余订单数1").toString();
    QString product_num2 = query.value("剩余订单数2").toString();
    sql = QString("insert into D%1 (日期,机台号,穴数,当日产量,当日模次,累计模数,定期保养模累计数,特定易损件管制模累计数,大保养模累计数,剩余订单数1,剩余订单数2,模修,备注) values (:date, :machine_num, :out_num, :enter_num, :product_num, :total_num, :keep_num1, :keep_num2, :keep_num3, :product_num1, :product_num2, :repair, :des)").arg(
        tableName);
    query.prepare(sql);
    query.bindValue(":date", ui->DateTime->text());
    query.bindValue(":machine_num", ui->MachineNum->text());
    query.bindValue(":out_num", ui->OutNum->text() + ui->OutLabel->text());
    query.bindValue(":enter_num", QString::number(0, 'f', 0));
    query.bindValue(":product_num", QString::number(0, 'f', 0));
    query.bindValue(":product_num1", product_num1);
    query.bindValue(":product_num2", product_num2);
    query.bindValue(":total_num", total);
    query.bindValue(":keep_num1", keep_num1);
    query.bindValue(":keep_num2", keep_num2);
    query.bindValue(":keep_num3", keep_num3);
    query.bindValue(":repair", ui->DirRepair->currentText());
    // 根据保养类型设置不同的值
    QString stataDesText = ui->StataDes->currentText();
    if(curr_stata == 5 || stataDesText == "大保养") {
        query.bindValue(":keep_num1", "0");
        query.bindValue(":keep_num2", "0");
        query.bindValue(":keep_num3", "0");
        query.bindValue(":product_num1", set_product_num1);
        query.bindValue(":product_num2", set_product_num2);
        query.bindValue(":des", "大保养");
    } else if(curr_stata == 4 || stataDesText == "定期保养") {
        query.bindValue(":keep_num1", "0");
        query.bindValue(":product_num1", set_product_num1);
        query.bindValue(":des", "定期保养");
    } else if(stataDesText == "特定易损件") {
        query.bindValue(":keep_num1", "0");
        query.bindValue(":keep_num2", "0");
        query.bindValue(":keep_num3", "0");
        query.bindValue(":product_num1", set_product_num1);
        query.bindValue(":product_num2", set_product_num2);
        query.bindValue(":des", "特定易损件保养");
    } else if(curr_stata == 6 || stataDesText == "呆滞6个月以上") {
        query.bindValue(":keep_num1", "0");
        query.bindValue(":keep_num2", "0");
        query.bindValue(":keep_num3", "0");
        query.bindValue(":product_num1", set_product_num1);
        query.bindValue(":product_num2", set_product_num2);
        query.bindValue(":des", "呆滞6个月以上的保养");
    }
    if(!query.exec()) {
        QMessageBox::warning(this, "模具保养", "产量数据插入失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    return true;
}

bool SumoKeep::updateInformationMessage() {
    QSqlQuery query;
    QString sql =
        "update information_message set 日期 = :curr_time,信息 = :set_information,完成情况 = :finish_status where 模具编号 = :mold and 模具性质 = :mold_nature";
    query.prepare(sql);
    query.bindValue(":curr_time", dateTime.toString("yyyy-MM-dd hh:mm:ss"));
    query.bindValue(":set_information", "");
    query.bindValue(":finish_status", "0");
    query.bindValue(":mold", curr_id);
    query.bindValue(":mold_nature", ui->StataDes->currentText());
    if(!query.exec()) {
        QMessageBox::warning(this, "模具保养", "模具信息列表更新失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    return true;
}

void SumoKeep::showSumoEnterWindow() {
    if(!sumoEnter) {
        sumoEnter = new SumoEnter(ui->MoldID->text(), this);
        sumoEnter->setWindowTitle("成型模具产量输入");
        m_windowMap.insert(tr("成型模具产量输入"), sumoEnter);
    }
    sumoEnter->show();
    QThread::msleep(100);
    sumoEnter->hide();
}

QString SumoKeep::buildStatusDescription() {
    QString result;
    bool isAddChecked = ui->AddCheck->isChecked();
    QString stataDesText = ui->StataDes->currentText();
    switch(curr_stata) {
    case 1:
        if(isAddChecked) {
            if(stataDesText == "关单保养")
                result = "异常维修&关单保养";
            else if(stataDesText == "定期保养")
                result = "异常维修&定期保养";
            else if(stataDesText == "大保养")
                result = "异常维修&大保养";
            else if(stataDesText == "呆滞6个月以上")
                result = "异常维修&呆滞6个月以上的保养";
        } else {
            result = "异常维修";
        }
        break;
    case 2:
        if(isAddChecked) {
            if(stataDesText == "定期保养")
                result = "关单保养&定期保养";
            else if(stataDesText == "大保养")
                result = "关单保养&大保养";
            else if(stataDesText == "呆滞6个月以上")
                result = "关单保养&呆滞6个月以上的保养";
        } else {
            result = "关单保养";
        }
        break;
    case 3:
        if(isAddChecked) {
            if(stataDesText == "关单保养")
                result = "转单换线&关单保养";
            else if(stataDesText == "定期保养")
                result = "转单换线&定期保养";
            else if(stataDesText == "大保养")
                result = "转单换线&大保养";
            else if(stataDesText == "呆滞6个月以上")
                result = "转单换线&呆滞6个月以上的保养";
        } else {
            result = "转单换线";
        }
        break;
    case 4:
        result = "定期保养";
        break;
    case 5:
        result = "大保养";
        break;
    case 6:
        result = "呆滞6个月以上的保养";
        break;
    case 7:
        if(isAddChecked) {
            QString editText = ui->StataEdit->text();
            if(stataDesText == "关单保养")
                result = editText + "关单保养";
            else if(stataDesText == "定期保养")
                result = editText + "定期保养";
            else if(stataDesText == "大保养")
                result = editText + "大保养";
            else if(stataDesText == "呆滞6个月以上")
                result = editText + "呆滞6个月以上的保养";
        } else {
            result = ui->StataEdit->text();
        }
        break;
    }
    return result;
}

bool SumoKeep::insertKeepMessage(const QString &statusDesc) {
    QSqlQuery query;
    QString sql =
        "insert into keep_message (日期,模具编号,机台号,模具穴数,产品名称,产品料号,下线时间,维修时间,状态描述,异常状态,原因分析,处理对策,更换备件号,数量,调机员,维修员) values (:date, :mold_id, :machine_num, :out_num, :product_name, :product_id, :down_time, :dir_time, :stata_des, :problem_des, :think_des, :proce_des, :change_id, :number, :operater, :dir_repair)";
    query.prepare(sql);
    query.bindValue(":date", ui->DateTime->text());
    query.bindValue(":mold_id", curr_id);
    query.bindValue(":machine_num", ui->MachineNum->text());
    query.bindValue(":out_num", ui->OutNum->text() + ui->OutLabel->text());
    query.bindValue(":product_name", ui->ProductName->toPlainText());
    query.bindValue(":product_id", ui->ProductID->toPlainText());
    query.bindValue(":down_time", ui->DownTime->text());
    query.bindValue(":dir_time", ui->DirTime->text());
    query.bindValue(":stata_des", statusDesc);
    query.bindValue(":problem_des", ui->ProblemDes->toPlainText());
    query.bindValue(":think_des", ui->ThinkDes->toPlainText());
    query.bindValue(":proce_des", ui->ProceDes->toPlainText());
    query.bindValue(":change_id", ui->ChangeID->text());
    query.bindValue(":number", ui->ChangeNum->text());
    query.bindValue(":operater", ui->Operater->currentText());
    query.bindValue(":dir_repair", ui->DirRepair->currentText());
    if(!query.exec()) {
        QMessageBox::warning(this, "模具保养", "保养数据插入失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    return true;
}

// ==================== 历史记录导出 ====================

void SumoKeep::on_HistoryButton_clicked() {
    QMessageBox choice_box;
    choice_box.setWindowTitle("选择导出方式");
    choice_box.setText("请选择您需要的内容：");
    QPushButton *button1 = choice_box.addButton("仅导出本月保养历史", QMessageBox::ActionRole);
    QPushButton *button2 = choice_box.addButton("仅导出上月保养历史", QMessageBox::ActionRole);
    QPushButton *button3 = choice_box.addButton("导出全部保养历史", QMessageBox::ActionRole);
    choice_box.addButton("取消", QMessageBox::RejectRole);
    choice_box.exec();
    if(choice_box.clickedButton() == button1) {
        exportHistoryData(0);
    } else if(choice_box.clickedButton() == button2) {
        exportHistoryData(-1);
    } else if(choice_box.clickedButton() == button3) {
        exportHistoryData(-999); // 使用特殊值表示全部
    }
}

void SumoKeep::exportHistoryData(int monthOffset) {
    QString sql;
    QString defaultFileName;
    if(monthOffset == -999) {
        // 导出全部
        sql = "select * from keep_message;";
        defaultFileName = "成型模具维修&保养记录履历表";
    } else {
        // 导出指定月份
        QDate date = QDate::currentDate().addMonths(monthOffset);
        QString date_str = date.toString("yyyy.MM.dd");
        QString select_month = date_str.left(7);
        sql = QString("select * from keep_message where 日期 like '%1%';").arg(select_month);
        defaultFileName = select_month + "成型模具维修&保养记录履历表";
    }
    exportToExcel(sql, defaultFileName);
}

bool SumoKeep::exportToExcel(const QString &sql, const QString &defaultFileName) {
    QSqlQuery query;
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "导出维修&保养记录履历",
            "保养数据查询失败：\n" + query.lastError().text(), QMessageBox::Cancel);
        return false;
    }
    QSettings config("userconfig.ini", QSettings::IniFormat);
    QXlsx::Document xlsx3(QString(":/ducument/%1_keep3.xlsx").arg("sumo"));
    int row = 3;
    while(query.next()) {
        for(int i = 1; i < 13; i++) {
            xlsx3.write(row, i, query.value(i - 1).toString(), Song12CB);
        }
        row++;
    }
    QString fileName = QFileDialog::getSaveFileName(this, "导出维修&保养记录履历表",
            config.value("DOCUMENTCONFIG/DocumentPath").toString() + defaultFileName,
            "Excel Files (*.xlsx)");
    if(fileName.isEmpty()) {
        return false;
    }
    // 保存路径配置
    QString file_temp = fileName.left(fileName.lastIndexOf('/')) + "/";
    config.setValue("DOCUMENTCONFIG/DocumentPath", file_temp);
    if(!fileName.endsWith(".xlsx")) {
        fileName.append(".xlsx");
    }
    if(!xlsx3.saveAs(fileName)) {
        QMessageBox::critical(this, "导出维修&保养记录履历", "维修&保养记录履历表创建失败：");
        return false;
    }
    config.sync();
    QMessageBox::information(this, "导出维修&保养记录履历", "维修&保养记录履历表创建成功",
        QMessageBox::Ok);
    return true;
}

// ==================== 撤回相关函数 ====================

void SumoKeep::on_ReturnButton_clicked() {
    if(return_flag) {
        QMessageBox::information(this, "撤回保养数据", "当前没有保养数据可以撤回", QMessageBox::Ok);
        return;
    }
    QString question = "您确定要撤回上一条数据吗？";
    int reply = QMessageBox::question(this, "撤回保养数据", question, QMessageBox::Yes | QMessageBox::No);
    if(reply != QMessageBox::Yes) {
        return;
    }
    // 判断是否需要删除产量数据
    bool needDeleteProduction = ((curr_stata == 1 || curr_stata == 2 || curr_stata == 3 || curr_stata == 7)
        && ui->StataDes->isVisible()) || (curr_stata == 4 || curr_stata == 5 || curr_stata == 6);
    if(needDeleteProduction) {
        if(!deleteProductionData()) {
            return;
        }
    }
    if(!deleteKeepMessage()) {
        return;
    }
    QMessageBox::information(this, "撤回保养数据", "保养数据撤回成功", QMessageBox::Ok);
    return_flag = true;
    refresh_data();
}

bool SumoKeep::deleteProductionData() {
    QSqlQuery query;
    QString tableName = buildTableName(curr_id);
    QString sql = QString("delete from D%1 order by 序号 desc limit 1;").arg(tableName);
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "撤回保养数据", "产量数据删除失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    return true;
}

bool SumoKeep::deleteKeepMessage() {
    QSqlQuery query;
    QString sql = QString("delete from keep_message where 模具编号 = '%1' order by 序号 desc limit 1;").arg(curr_id);
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "撤回保养数据", "保养数据删除失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    return true;
}

// ==================== 其他UI事件处理 ====================

void SumoKeep::on_GetButton_clicked() {
    if(!handleData) {
        handleData = new HandleData(curr_id, "keep", this);
        handleData->setWindowTitle("模具保养表");
        m_windowMap.insert(tr("模具保养表"), handleData);
    }
    handleData->show();
}

void SumoKeep::on_AddCheck_stateChanged(int arg1) {
    bool visible = (arg1 != 0);
    ui->Label14->setVisible(visible);
    ui->StataDes->setVisible(visible);
}

void SumoKeep::on_ChangeCheck_stateChanged(int arg1) {
    bool visible = (arg1 != 0);
    ui->Label15->setVisible(visible);
    ui->ChangeID->setVisible(visible);
    ui->Label16->setVisible(visible);
    ui->ChangeNum->setVisible(visible);
}

// ==================== 工具函数 ====================

QString SumoKeep::buildTableName(const QString &moldId) const {
    QString table = moldId;
    table.replace("-", "_");
    return table;
}

void SumoKeep::cleanupWindows() {
    if(QWidget *target = m_windowMap.value(tr("成型模具产量输入"))) {
        if(!target->isHidden()) {
            target->close();
            target->deleteLater();
        }
        m_windowMap.remove(tr("成型模具产量输入"));
    }
    if(QWidget *target = m_windowMap.value(tr("模具保养表"))) {
        if(!target->isHidden()) {
            target->close();
            target->deleteLater();
        }
        m_windowMap.remove(tr("模具保养表"));
    }
}

// ==================== 事件处理 ====================

void SumoKeep::closeEvent(QCloseEvent *event) {
    Q_UNUSED(event);
    cleanupWindows();
}
