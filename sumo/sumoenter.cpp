#include "sumoenter.h"
#include "ui_sumoenter.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>
#include <QSettings>
#include <QStandardItemModel>
#include <QListView>
#include <QScroller>
#include <QStyledItemDelegate>
#include <QItemSelectionModel>
#include <QDate>

// 常量定义
const QString SumoEnter::ADMIN_SECRET = "mengen888";
const QString SumoEnter::SYSTEM_USER = "系统";
const QString SumoEnter::REGULAR_MAINTENANCE = "定期保养";
const QString SumoEnter::SPECIAL_MAINTENANCE = "特定易损件";
const QString SumoEnter::MAJOR_MAINTENANCE = "大保养";
const QString SumoEnter::OVERALL_MOLD = "整体模具";
const QString SumoEnter::REPAIR_TYPE = "维修员";
const QString SumoEnter::ALL_USERS = "所有人";

// ==================== 构造函数和析构函数 ====================

SumoEnter::SumoEnter(QVariant id_value, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SumoEnter), handleData(nullptr),
      idvalue_(id_value), series(nullptr), chartView(nullptr), model(nullptr) {
    ui->setupUi(this);
    curr_id = id_value.toString();
    table = buildTableName(curr_id);
    QDate date = QDate::currentDate().addDays(-1);
    date_str = date.toString("yyyy.MM.dd");
    ui->ProductTime->setText(date_str);
    ui->ProductTime->setCursorPosition(0);
    // 设置滚动视图
    QListView *listView1 = qobject_cast<QListView *>(ui->MoldCombo->view());
    QScroller *Scroller1 = QScroller::scroller(listView1);
    Scroller1->grabGesture(listView1->viewport(), QScroller::LeftMouseButtonGesture);
    listView1->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QListView *listView2 = qobject_cast<QListView *>(ui->DirRepair->view());
    QScroller *Scroller2 = QScroller::scroller(listView2);
    Scroller2->grabGesture(listView2->viewport(), QScroller::LeftMouseButtonGesture);
    listView2->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QScroller *pScroller = QScroller::scroller(ui->MachineView);
    pScroller->grabGesture(ui->MachineView->viewport(), QScroller::LeftMouseButtonGesture);
    ui->MachineView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    // 设置Excel格式
    Song12C.setFontSize(12);
    Song12C.setFontName("宋体");
    Song12C.setBorderStyle(QXlsx::Format::BorderThin);
    Song12C.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    Song12C.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    // 创建数据表
    QSqlQuery query;
    QString tableName = "D" + table;
    QString sql =
        QString("create table if not exists %1(序号 int primary key auto_increment,日期 char(20),机台号 char(5),当日产量 float,穴数 char(10),当日模次 int,累计模数 int,定期保养模累计数 int,剩余订单数1 int,大保养模累计数 int,剩余订单数2 int,特定易损件管制模累计数 int,模修 char(10),备注 char(200))auto_increment=1;").arg(
        tableName);
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "界面初始化", "模具产量信息表创建失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    // 查询维修员列表
    query.prepare("select name from user_message where type = :repair_type");
    query.bindValue(":repair_type", REPAIR_TYPE);
    if(!query.exec()) {
        QMessageBox::warning(this, "界面初始化", "用户维修员姓名查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    while(query.next()) {
        QString name = query.value(0).toString();
        if(name != "NULL" && name != "俞増涛") {
            data.append(name);
        }
    }
    ui->DirRepair->addItems(data);
    QStyledItemDelegate *d = new QStyledItemDelegate(this);
    QString style = "QAbstractItemView{font: 18pt \"微软雅黑\";background-color:rgb(255,255,255);color:rgb(0,0,0);}"
                    "QAbstractItemView::item:hover{background-color:rgb(0, 120, 212)}";
    QCompleter *NameCompleter1 = new QCompleter(data, this);
    NameCompleter1->setMaxVisibleItems(10);
    NameCompleter1->setCaseSensitivity(Qt::CaseInsensitive);
    NameCompleter1->setCompletionMode(QCompleter::PopupCompletion);
    NameCompleter1->setFilterMode(Qt::MatchContains);
    ui->DirRepair->setCompleter(NameCompleter1);
    NameCompleter1->popup()->setItemDelegate(d);
    NameCompleter1->popup()->setStyleSheet(style);
    // 查询模具列表
    QStringList mold_list;
    ui->MoldCombo->blockSignals(true);
    query.prepare("select 模具编号 from type_message");
    if(!query.exec()) {
        QMessageBox::warning(this, "界面初始化", "模具编号查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    while(query.next()) {
        mold_list.append(query.value(0).toString());
    }
    ui->MoldCombo->addItems(mold_list);
    QCompleter *MoldCompleter = new QCompleter(mold_list, this);
    MoldCompleter->setMaxVisibleItems(10);
    MoldCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    MoldCompleter->setCompletionMode(QCompleter::PopupCompletion);
    MoldCompleter->setFilterMode(Qt::MatchContains);
    ui->MoldCombo->setCompleter(MoldCompleter);
    MoldCompleter->popup()->setItemDelegate(d);
    MoldCompleter->popup()->setStyleSheet(style);
    ui->MoldCombo->setCurrentText(id_value.toString());
    ui->MoldCombo->blockSignals(false);
    refresh_data();
}

SumoEnter::~SumoEnter() {
    if(handleData) {
        handleData->deleteLater();
    }
    if(model) {
        delete model;
    }
    delete ui;
}

// ==================== 事件处理 ====================

void SumoEnter::closeEvent(QCloseEvent *event) {
    Q_UNUSED(event);
    cleanupWindows();
}

void SumoEnter::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Escape) {
        this->close();
    }
}

// ==================== 初始化函数 ====================

void SumoEnter::refresh_data() {
    QSqlQuery query;
    float keep_num1 = 0;
    float keep_num2 = 0;
    float keep_num3 = 0;
    float set_keep_num1 = 0;
    float set_keep_num2 = 0;
    float set_keep_num3 = 0;
    int total = 0;
    QString dir_date;
    QString select_month = date_str.left(7);
    // 更新信息状态
    query.prepare("update information_message set 完成情况 = '0' where 模具编号 = :mold_id and 发送用户 = :system_user");
    query.bindValue(":mold_id", curr_id);
    query.bindValue(":system_user", SYSTEM_USER);
    if(!query.exec()) {
        QMessageBox::warning(this, "刷新信息", "保养数据信息刷新失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
    }
    // 查询定期保养数量
    query.prepare("select count(*) from keep_message where 模具编号 = :mold_id and 状态描述 = :maintenance_type and 日期 like :month_pattern");
    query.bindValue(":mold_id", curr_id);
    query.bindValue(":maintenance_type", REGULAR_MAINTENANCE);
    query.bindValue(":month_pattern", select_month + "%");
    if(!query.exec()) {
        QMessageBox::warning(this, "刷新数据", "模具定期保养数量查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        ui->PercentLabel2_2->setText(query.value(0).toString());
    }
    // 查询大保养数量
    query.prepare("select count(*) from keep_message where 模具编号 = :mold_id and 状态描述 = :maintenance_type and 日期 like :month_pattern");
    query.bindValue(":mold_id", curr_id);
    query.bindValue(":maintenance_type", MAJOR_MAINTENANCE);
    query.bindValue(":month_pattern", select_month + "%");
    if(!query.exec()) {
        QMessageBox::warning(this, "刷新数据", "模具大保养数量查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        ui->PercentLabel3_2->setText(query.value(0).toString());
    }
    // 重置标签样式
    ui->PercentLabel1_1->setStyleSheet("color:black;");
    ui->PercentLabel2_1->setStyleSheet("color:black;");
    ui->PercentLabel3_1->setStyleSheet("color:black;");
    ui->PercentLabel4_1->setStyleSheet("color:black;");
    // 重新创建模型
    if(model) {
        delete model;
    }
    model = new QStandardItemModel(this);
    // 查询模具信息
    query.prepare("select 定期保养模次数,特定易损件管制模次数,大保养模次数,机台,穴数,剩余订单数1,剩余订单数2,产品料号 from type_message where 模具编号 = :mold_id");
    query.bindValue(":mold_id", curr_id);
    if(!query.exec()) {
        QMessageBox::warning(this, "刷新数据", "保养数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        set_keep_num1 = query.value(0).toInt();
        set_keep_num2 = query.value(1).toInt();
        set_keep_num3 = query.value(2).toInt();
        QString machineField = query.value(3).toString();
        QStringList machineList = machineField.split("#");
        for(const QString &machine : machineList) {
            if(!machine.isEmpty()) {
                QList<QStandardItem *> items;
                items.append(new QStandardItem(machine + "#"));
                model->appendRow(items);
            }
        }
        ui->OutLabel->setText("/" + query.value(4).toString());
        set_product_num1 = query.value(5).toInt();
        set_product_num2 = query.value(6).toInt();
        ui->ProductID->setText(query.value("产品料号").toString());
    } else {
        return;
    }
    ui->MachineView->setModel(model);
    // 查询最新产量数据
    QString tableName = "D" + table;
    QString sql = QString("select * from %1 order by 序号 desc limit 1").arg(tableName);
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "刷新数据", "产量数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        ui->DirRepair->setCurrentText(query.value("模修").toString());
        machine_num = query.value("机台号").toString();
        ui->MachineNum->setText(machine_num);
        ui->OutNum->setValue(query.value("穴数").toString().split('/').first().toInt());
        keep_num1 = query.value("定期保养模累计数").toDouble();
        keep_num2 = query.value("特定易损件管制模累计数").toDouble();
        keep_num3 = query.value("大保养模累计数").toDouble();
        total = query.value("累计模数").toInt();
        dir_date = query.value("日期").toString();
    } else {
        keep_num1 = 0;
        keep_num2 = 0;
        keep_num3 = 0;
        total = 0;
    }
    init_MachineView();
    // 计算百分比
    double percent1 = (set_keep_num1 > 0) ? (keep_num1 / set_keep_num1 * 100.0) : 0.0;
    double percent2 = (set_keep_num2 > 0) ? (keep_num2 / set_keep_num2 * 100.0) : 0.0;
    double percent3 = (set_keep_num3 > 0) ? (keep_num3 / set_keep_num3 * 100.0) : 0.0;
    double percent4 = (MOLD_LIFETIME_LIMIT > 0) ? (static_cast<double>(total) / MOLD_LIFETIME_LIMIT * 100.0) : 0.0;
    // 更新标签并设置样式
    ui->PercentLabel1_1->setText(QString("%1%").arg(percent1, 0, 'f', 1));
    ui->PercentLabel2_1->setText(QString("%1%").arg(percent2, 0, 'f', 1));
    ui->PercentLabel3_1->setText(QString("%1%").arg(percent3, 0, 'f', 1));
    ui->PercentLabel4_1->setText(QString("%1%").arg(percent4, 0, 'f', 1));
    QString keep_status = "";
    // 判断定期保养状态
    if(percent1 > CRITICAL_THRESHOLD) {
        ui->PercentLabel1_1->setStyleSheet("color:red;");
        keep_status += "需要进行定期保养；";
        mold_static1 = true;
    } else if(percent1 > WARNING_THRESHOLD) {
        ui->PercentLabel1_1->setStyleSheet("color:orange;");
        mold_static1 = false;
    } else {
        mold_static1 = false;
    }
    // 判断特定易损件状态
    if(percent2 > CRITICAL_THRESHOLD) {
        ui->PercentLabel2_1->setStyleSheet("color:red;");
        keep_status += "特定易损件需要保养；";
        mold_static2 = true;
    } else if(percent2 > WARNING_THRESHOLD) {
        ui->PercentLabel2_1->setStyleSheet("color:orange;");
        mold_static2 = false;
    } else {
        mold_static2 = false;
    }
    // 判断大保养状态
    if(percent3 > CRITICAL_THRESHOLD) {
        ui->PercentLabel3_1->setStyleSheet("color:red;");
        keep_status += "需要进行大保养；";
        mold_static3 = true;
    } else if(percent3 > WARNING_THRESHOLD) {
        ui->PercentLabel3_1->setStyleSheet("color:orange;");
        mold_static3 = false;
    } else {
        mold_static3 = false;
    }
    // 判断模具寿命状态
    if(percent4 > CRITICAL_THRESHOLD) {
        ui->PercentLabel4_1->setStyleSheet("color:red;");
        keep_status += "当前已达模具寿命冲200KK次数，需做报废处理；";
        mold_static4 = true;
    } else if(percent4 > WARNING_THRESHOLD) {
        ui->PercentLabel4_1->setStyleSheet("color:orange;");
        mold_static4 = false;
    } else {
        mold_static4 = false;
    }
    if(!init_information(ALL_USERS)) {
        if(keep_status.isEmpty()) {
            keep_status = "当前无需保养";
        }
        query.prepare("update type_message set 保养情况 = :keep_status, 模修 = :dir_repair, 维修机台 = :dir_machine, 维修日期 = :dir_date, 定期保养模累计数 = :keep_num1, 特定易损件管制模累计数 = :keep_num2, 大保养模累计数 = :keep_num3 where 模具编号 = :mold_id");
        query.bindValue(":keep_status", keep_status);
        query.bindValue(":dir_repair", ui->DirRepair->currentText());
        query.bindValue(":dir_machine", ui->MachineNum->text());
        query.bindValue(":dir_date", dir_date);
        query.bindValue(":keep_num1", keep_num1);
        query.bindValue(":keep_num2", keep_num2);
        query.bindValue(":keep_num3", keep_num3);
        query.bindValue(":mold_id", curr_id);
        if(!query.exec()) {
            QMessageBox::warning(this, "刷新数据", "保养数据更新失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        }
        QTimer::singleShot(0, this, &SumoEnter::mysignal);
        QString currTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        if(mold_static1) {
            query.prepare("update information_message set 日期 = :curr_time,信息 = :keep_status,完成情况 = '1' where 模具编号 = :mold_id and 发送用户 = :system_user and 模具性质 = :maintenance_type");
            query.bindValue(":curr_time", currTime);
            query.bindValue(":keep_status", "需要进行定期保养；");
            query.bindValue(":mold_id", curr_id);
            query.bindValue(":system_user", SYSTEM_USER);
            query.bindValue(":maintenance_type", REGULAR_MAINTENANCE);
            if(!query.exec()) {
                QMessageBox::warning(this, "刷新数据", "模具信息列表更新失败：\n" + query.lastError().text(),
                    QMessageBox::Cancel);
                return;
            }
            mold_static1 = false;
        }
        if(mold_static2) {
            query.prepare("update information_message set 日期 = :curr_time,信息 = :keep_status,完成情况 = '1' where 模具编号 = :mold_id and 发送用户 = :system_user and 模具性质 = :maintenance_type");
            query.bindValue(":curr_time", currTime);
            query.bindValue(":keep_status", "特定易损件需要保养；");
            query.bindValue(":mold_id", curr_id);
            query.bindValue(":system_user", SYSTEM_USER);
            query.bindValue(":maintenance_type", SPECIAL_MAINTENANCE);
            if(!query.exec()) {
                QMessageBox::warning(this, "刷新数据", "模具信息列表更新失败：\n" + query.lastError().text(),
                    QMessageBox::Cancel);
                return;
            }
            mold_static2 = false;
        }
        if(mold_static3) {
            query.prepare("update information_message set 日期 = :curr_time,信息 = :keep_status,完成情况 = '1' where 模具编号 = :mold_id and 发送用户 = :system_user and 模具性质 = :maintenance_type");
            query.bindValue(":curr_time", currTime);
            query.bindValue(":keep_status", "需要进行大保养；");
            query.bindValue(":mold_id", curr_id);
            query.bindValue(":system_user", SYSTEM_USER);
            query.bindValue(":maintenance_type", MAJOR_MAINTENANCE);
            if(!query.exec()) {
                QMessageBox::warning(this, "刷新数据", "模具信息列表更新失败：\n" + query.lastError().text(),
                    QMessageBox::Cancel);
                return;
            }
            mold_static3 = false;
        }
        if(mold_static4) {
            query.prepare("update information_message set 日期 = :curr_time,信息 = :keep_status,完成情况 = '1' where 模具编号 = :mold_id and 发送用户 = :system_user and 模具性质 = :maintenance_type");
            query.bindValue(":curr_time", currTime);
            query.bindValue(":keep_status", "当前已达模具寿命冲200KK次数，需做报废处理；");
            query.bindValue(":mold_id", curr_id);
            query.bindValue(":system_user", SYSTEM_USER);
            query.bindValue(":maintenance_type", OVERALL_MOLD);
            if(!query.exec()) {
                QMessageBox::warning(this, "刷新数据", "模具信息列表更新失败：\n" + query.lastError().text(),
                    QMessageBox::Cancel);
                return;
            }
            mold_static4 = false;
        }
    }
}

void SumoEnter::init_MachineView() {
    if(!model) {
        return;
    }
    QString valueToSelect = machine_num;
    QModelIndex indexToSelect;
    for(int row = 0; row < model->rowCount(); ++row) {
        QModelIndex index = model->index(row, 0);
        if(model->data(index).toString() == valueToSelect) {
            indexToSelect = index;
            break;
        }
    }
    if(indexToSelect.isValid()) {
        ui->MachineView->selectionModel()->select(indexToSelect, QItemSelectionModel::Select);
        ui->MachineView->scrollTo(indexToSelect);
    } else {
        if(machine_num.isEmpty() && model->rowCount() > 0) {
            indexToSelect = model->index(0, 0);
            machine_num = indexToSelect.data().toString();
        }
    }
}

int SumoEnter::init_information(const QString &set_name) {
    QSqlQuery query;
    QString currTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    query.prepare("select count(*) from information_message where 模具编号 = :mold_id and 发送用户 = :system_user and 接收用户 = :receive_user");
    query.bindValue(":mold_id", curr_id);
    query.bindValue(":system_user", SYSTEM_USER);
    query.bindValue(":receive_user", set_name);
    if(!query.exec()) {
        QMessageBox::warning(this, "初始化信息列表",
            "模具信息列表数量查询失败：\n" + query.lastError().text(), QMessageBox::Cancel);
        return 1;
    }
    if(query.next()) {
        if(!query.value(0).toInt()) {
            query.prepare("insert into information_message (日期,模具编号,模具性质,发送用户,接收用户,完成情况) values (:date, :mold_id, :mold_nature, :tuser, :ruser, :finished)");
            query.bindValue(":date", currTime);
            query.bindValue(":mold_id", curr_id);
            query.bindValue(":tuser", SYSTEM_USER);
            query.bindValue(":ruser", set_name);
            query.bindValue(":finished", "0");
            query.bindValue(":mold_nature", REGULAR_MAINTENANCE);
            if(!query.exec()) {
                QMessageBox::warning(this, "初始化信息列表", "模具定期保养插入失败：\n" + query.lastError().text(),
                    QMessageBox::Cancel);
                return 1;
            }
            query.bindValue(":mold_nature", SPECIAL_MAINTENANCE);
            if(!query.exec()) {
                QMessageBox::warning(this, "初始化信息列表",
                    "模具特定易损件保养插入失败：\n" + query.lastError().text(), QMessageBox::Cancel);
                return 1;
            }
            query.bindValue(":mold_nature", MAJOR_MAINTENANCE);
            if(!query.exec()) {
                QMessageBox::warning(this, "初始化信息列表", "模具大保养插入失败：\n" + query.lastError().text(),
                    QMessageBox::Cancel);
                return 1;
            }
            query.bindValue(":mold_nature", OVERALL_MOLD);
            if(!query.exec()) {
                QMessageBox::warning(this, "初始化信息列表", "模具翻新插入失败：\n" + query.lastError().text(),
                    QMessageBox::Cancel);
                return 1;
            }
        }
    }
    return 0;
}

// ==================== UI事件处理 ====================

void SumoEnter::on_EnterButton_clicked() {
    if(ui->ProductNum->text().isEmpty()) {
        QMessageBox::warning(this, "录入产量", "请输入产量", QMessageBox::Cancel);
        return;
    }
    enterProductData();
}

void SumoEnter::on_ProductNum_returnPressed() {
    if(ui->ProductNum->text().isEmpty()) {
        QMessageBox::warning(this, "录入产量", "请输入产量", QMessageBox::Cancel);
        return;
    }
    enterProductData();
}

void SumoEnter::on_ReturnButton_clicked() {
    QString question = "您确定要撤回上一条数据吗？";
    int reply = QMessageBox::question(this, "撤回产量数据", question, QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        QSqlQuery query;
        QString tableName = "D" + table;
        QString sql = QString("select 序号 from %1 order by 序号 desc limit 1").arg(tableName);
        if(!query.exec(sql)) {
            QMessageBox::warning(this, "撤回产量数据", "产量序号查询失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        }
        if(query.next()) {
            int seqNum = query.value(0).toInt();
            sql = QString("delete from %1 where 序号 = :seq_num").arg(tableName);
            query.prepare(sql);
            query.bindValue(":seq_num", seqNum);
            if(!query.exec()) {
                QMessageBox::warning(this, "撤回产量数据", "产量数据删除失败：\n" + query.lastError().text(),
                    QMessageBox::Cancel);
                return;
            }
        }
        QMessageBox::information(this, "撤回产量数据", "产量数据撤回成功", QMessageBox::Ok);
        refresh_data();
    }
}

void SumoEnter::on_PlotButton_clicked() {
    QLineSeries *series = new QLineSeries();
    QSqlQuery query;
    QString tableName = "D" + table;
    // 由于表名和列名不能参数化，需要直接构建SQL，但机台号使用参数化查询
    query.prepare(
        QString("(select 日期,当日产量 from %1 where 机台号 = :machine_num order by 序号 desc limit %2)order by 日期 desc")
        .arg(tableName)
        .arg(CHART_DATA_LIMIT));
    query.bindValue(":machine_num", ui->MachineNum->text());
    if(!query.exec()) {
        QMessageBox::warning(this, "创建模具产量曲线图", "产量数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        delete series;
        return;
    }
    while(query.next()) {
        QString dateStr = query.value(0).toString();
        QDateTime date = QDateTime::fromString(dateStr, "yyyy.MM.dd");
        int production = query.value(1).toInt();
        series->append(date.toMSecsSinceEpoch(), production);
    }
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(ui->MachineNum->text() + " 产量变化图");
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setTickCount(1);
    axisX->setFormat("yyyy-MM-dd");
    axisX->setTitleText("日期");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("产量");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    chartView = new QChartView(chart);
    chartView->setWindowTitle("模具产量曲线图");
    m_windowMap.insert(tr("模具产量曲线图"), chartView);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(CHART_WIDTH, CHART_HEIGHT);
    chartView->show();
}

void SumoEnter::on_GetButton_clicked() {
    if(handleData) {
        handleData->deleteLater();
    }
    handleData = new HandleData(curr_id, "mold", this);
    connect(handleData, &HandleData::mysignal, this, &SumoEnter::refresh_data);
    handleData->setWindowTitle("模具产量表");
    m_windowMap.insert(tr("模具产量表"), handleData);
    handleData->show();
}

void SumoEnter::on_MachineNum_2_returnPressed() {
    if(curr_id.isEmpty()) {
        QMessageBox::warning(this, "添加机台", "请选择模具", QMessageBox::Cancel);
        return;
    }
    QString data_machine;
    QString curr_machine = ui->MachineNum_2->text().replace("#", "");
    for(int i = 0; i < ui->MachineView->model()->rowCount(); ++i) {
        QModelIndex index = ui->MachineView->model()->index(i, 0);
        QString existingMachine = ui->MachineView->model()->data(index, Qt::DisplayRole).toString();
        if(existingMachine.remove('#') == curr_machine) {
            QMessageBox::warning(this, "添加机台", "该机台已存在", QMessageBox::Cancel);
            return;
        }
        data_machine += ("#" + existingMachine);
    }
    data_machine += ("#" + curr_machine);
    QSqlQuery query;
    query.prepare("update type_message set 机台 = :data_machine where 模具编号 = :mold_id");
    query.bindValue(":data_machine", data_machine);
    query.bindValue(":mold_id", curr_id);
    if(!query.exec()) {
        QMessageBox::warning(this, "添加机台", "模具机台更新失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    QMessageBox::information(this, "添加机台", "机台添加成功", QMessageBox::Ok);
    refresh_data();
}

void SumoEnter::on_MachineView_clicked(const QModelIndex &index) {
    machine_num = index.data().toString();
    ui->MachineNum->setText(machine_num);
}

void SumoEnter::on_MoldCombo_currentTextChanged(const QString &arg1) {
    curr_id = arg1;
    table = buildTableName(curr_id);
    ui->MachineNum->clear();
    ui->ProductID->clear();
    ui->PercentLabel1_1->clear();
    ui->PercentLabel2_1->clear();
    ui->PercentLabel3_1->clear();
    ui->PercentLabel4_1->clear();
    if(model) {
        delete model;
    }
    model = new QStandardItemModel(this);
    ui->MachineView->setModel(model);
    refresh_data();
}

void SumoEnter::on_NewButton_clicked() {
    QString question =
        "您确定要翻新该模具？翻新后，所有数据将还原到最初值（包括模具累计冲次数）";
    int reply = QMessageBox::question(this, "模具翻新", question, QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        if(!verifyAdminSecret()) {
            return;
        }
        QSqlQuery query;
        QString product_value1, product_value2, out_value;
        query.prepare("select 穴数,剩余订单数1,剩余订单数2 from type_message where 模具编号 = :mold_id");
        query.bindValue(":mold_id", curr_id);
        if(!query.exec()) {
            QMessageBox::warning(this, "模具翻新", "模具数据查询失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        }
        if(query.next()) {
            out_value = query.value(0).toString();
            product_value1 = query.value(1).toString();
            product_value2 = query.value(2).toString();
        }
        QString tableName = "D" + table;
        QString sql =
            QString("insert into %1 (日期,机台号,穴数,当日产量,当日模次,累计模数,定期保养模累计数,特定易损件管制模累计数,大保养模累计数,剩余订单数1,剩余订单数2,模修,备注) values (:date, :machine_num, :out_num, :enter_num, :product_num, :total_num, :keep_num1, :keep_num2, :keep_num3, :product_num1, :product_num2, :repair, :des)")
            .arg(tableName);
        query.prepare(sql);
        query.bindValue(":date", ui->ProductTime->text());
        query.bindValue(":machine_num", machine_num);
        query.bindValue(":out_num", out_value + ui->OutLabel->text());
        query.bindValue(":enter_num", 0);
        query.bindValue(":product_num", 0);
        query.bindValue(":total_num", 0);
        query.bindValue(":keep_num1", 0);
        query.bindValue(":keep_num2", 0);
        query.bindValue(":keep_num3", 0);
        query.bindValue(":product_num1", product_value1);
        query.bindValue(":product_num2", product_value2);
        query.bindValue(":repair", "");
        query.bindValue(":des", "模具翻新");
        if(!query.exec()) {
            QMessageBox::warning(this, "模具翻新", "模具数据插入失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        }
        QMessageBox::information(this, "模具翻新", "模具翻新成功", QMessageBox::Ok);
        refresh_data();
    }
}

void SumoEnter::on_CheckButton_clicked() {
    bool ok;
    QStringList items;
    items << "全部数据" << "本年数据";
    QString selected = QInputDialog::getItem(this, "导出产量统计及模具保养期限管制信息",
            "请选择需要导出的保养数据范围:", items, 0, false, &ok);
    if(ok && !selected.isEmpty()) {
        int row = 7;
        QSqlQuery query;
        QString fileName, file_temp;
        QSettings config("userconfig.ini", QSettings::IniFormat);
        QXlsx::Document xlsx1(":/ducument/sumo_message.xlsx");
        query.prepare("select 产品名称,产品料号,模具编号,标准产量,剩余订单数1,剩余订单数2 from type_message where 模具编号 = :mold_id");
        query.bindValue(":mold_id", ui->MoldCombo->currentText());
        if(!query.exec()) {
            QMessageBox::warning(this, "导出产量统计及模具保养期限管制信息",
                "模具数据查询失败：\n" + query.lastError().text(), QMessageBox::Cancel);
            return;
        }
        if(query.next()) {
            xlsx1.write(3, 2, query.value(0).toString(), Song12C);
            xlsx1.write(3, 8, query.value(1).toString(), Song12C);
            xlsx1.write(4, 2, query.value(2).toString(), Song12C);
            xlsx1.write(4, 6, query.value(3).toString(), Song12C);
            xlsx1.write(6, 8, query.value(4).toString(), Song12C);
            xlsx1.write(6, 10, query.value(5).toString(), Song12C);
            QString tableName = "D" + table;
            QString sql;
            if(selected == "全部数据") {
                sql = QString("select * from %1 order by 序号").arg(tableName);
            } else {
                QString yearPattern = date_str.left(5) + "%";
                sql = QString("select * from %1 where 日期 like '%2' order by 序号").arg(tableName).arg(yearPattern);
            }
            if(!query.exec(sql)) {
                QMessageBox::warning(this, "导出产量统计及模具保养期限管制信息",
                    "成型产量统计及模具保养期限管制信息导出失败：\n" + query.lastError().text(), QMessageBox::Cancel);
                return;
            }
            while(query.next()) {
                for(int i = 1; i < 14; i++) {
                    xlsx1.write(row, i, query.value(i).toString(), Song12C);
                }
                row++;
            }
        }
        fileName = QFileDialog::getSaveFileName(this, "导出产量统计及模具保养期限管制信息",
                config.value("DOCUMENTCONFIG/DocumentPath").toString() + ui->MoldCombo->currentText() +
                "产量统计及模具保养期限管制表", "Excel Files (*.xlsx)");
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
            QMessageBox::critical(this, "导出产量统计及模具保养期限管制信息",
                "成型产量统计及模具保养期限管制表创建失败：");
        }
    }
}

// ==================== 辅助函数 ====================

void SumoEnter::enterProductData() {
    double keep_num1, keep_num2, keep_num3, total, product_num, product_num1, product_num2;
    QSqlQuery query;
    QString tableName = "D" + table;
    QString sql = QString("select * from %1 order by 序号 desc limit 1").arg(tableName);
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "录入产量", "产量数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        total = query.value("累计模数").toDouble();
        keep_num1 = query.value("定期保养模累计数").toDouble();
        keep_num2 = query.value("特定易损件管制模累计数").toDouble();
        keep_num3 = query.value("大保养模累计数").toDouble();
        product_num1 = query.value("剩余订单数1").toDouble();
        product_num2 = query.value("剩余订单数2").toDouble();
    } else {
        total = 0;
        keep_num1 = 0;
        keep_num2 = 0;
        keep_num3 = 0;
        product_num1 = set_product_num1;
        product_num2 = set_product_num2;
    }
    int outNum = ui->OutNum->text().toInt();
    if(outNum == 0) {
        QMessageBox::warning(this, "录入产量", "穴数不能为0", QMessageBox::Cancel);
        return;
    }
    double productInput = ui->ProductNum->text().toDouble();
    product_num = productInput * CONVERSION_FACTOR / outNum;
    int rounded = qRound(productInput);
    product_num1 -= rounded;
    product_num2 -= rounded;
    total = product_num + total;
    keep_num1 = product_num + keep_num1;
    keep_num2 = product_num + keep_num2;
    keep_num3 = product_num + keep_num3;
    sql = QString("insert into %1 (日期,机台号,穴数,当日产量,当日模次,累计模数,定期保养模累计数,特定易损件管制模累计数,大保养模累计数,剩余订单数1,剩余订单数2,模修) values (:date, :machine_num, :out_num, :enter_num, :product_num, :total_num, :keep_num1, :keep_num2, :keep_num3, :product_num1, :product_num2, :repair)")
        .arg(tableName);
    query.prepare(sql);
    query.bindValue(":date", ui->ProductTime->text());
    query.bindValue(":machine_num", machine_num);
    query.bindValue(":out_num", ui->OutNum->text() + ui->OutLabel->text());
    query.bindValue(":enter_num", QString::number(productInput, 'f', 2));
    query.bindValue(":product_num", QString::number(product_num, 'f', 0));
    query.bindValue(":total_num", QString::number(total, 'f', 0));
    query.bindValue(":keep_num1", QString::number(keep_num1, 'f', 0));
    query.bindValue(":keep_num2", QString::number(keep_num2, 'f', 0));
    query.bindValue(":keep_num3", QString::number(keep_num3, 'f', 0));
    query.bindValue(":product_num1", QString::number(product_num1, 'f', 0));
    query.bindValue(":product_num2", QString::number(product_num2, 'f', 0));
    query.bindValue(":repair", ui->DirRepair->currentText());
    if(!query.exec()) {
        QMessageBox::warning(this, "录入产量", "产量数据插入失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    QMessageBox::information(this, "录入产量", "产量录入成功", QMessageBox::Ok);
    refresh_data();
}

void SumoEnter::updateKeepStatusLabels(float keep_num1, float keep_num2, float keep_num3, int total,
    float set_keep_num1, float set_keep_num2, float set_keep_num3) {
    // 防止除零
    if(set_keep_num1 > 0) {
        double percent1 = keep_num1 / set_keep_num1 * 100.0;
        ui->PercentLabel1_1->setText(QString("%1%").arg(percent1, 0, 'f', 1));
    } else {
        ui->PercentLabel1_1->setText("0%");
    }
    if(set_keep_num2 > 0) {
        double percent2 = keep_num2 / set_keep_num2 * 100.0;
        ui->PercentLabel2_1->setText(QString("%1%").arg(percent2, 0, 'f', 1));
    } else {
        ui->PercentLabel2_1->setText("0%");
    }
    if(set_keep_num3 > 0) {
        double percent3 = keep_num3 / set_keep_num3 * 100.0;
        ui->PercentLabel3_1->setText(QString("%1%").arg(percent3, 0, 'f', 1));
    } else {
        ui->PercentLabel3_1->setText("0%");
    }
    if(MOLD_LIFETIME_LIMIT > 0) {
        double percent4 = static_cast<double>(total) / MOLD_LIFETIME_LIMIT * 100.0;
        ui->PercentLabel4_1->setText(QString("%1%").arg(percent4, 0, 'f', 1));
    } else {
        ui->PercentLabel4_1->setText("0%");
    }
}

bool SumoEnter::verifyAdminSecret() {
    while(true) {
        bool ok;
        QString secret = QInputDialog::getText(this, "模具翻新", "请输入管理密钥:", QLineEdit::Password, "", &ok);
        if(!ok) {
            return false;
        }
        if(secret.isEmpty()) {
            QMessageBox::warning(this, "模具翻新", "密钥为空，请输入管理密钥！");
            continue;
        }
        if(secret == ADMIN_SECRET) {
            return true;
        }
        QMessageBox::warning(this, "模具翻新", "密钥错误，请重新输入！");
    }
}

QString SumoEnter::buildTableName(const QString &mold_id) {
    QString tableName = mold_id;
    tableName.replace("-", "_");
    return tableName;
}

void SumoEnter::cleanupWindows() {
    if(QWidget *target = m_windowMap.value(tr("模具产量表"))) {
        if(!target->isHidden()) {
            target->close();
            target->deleteLater();
            m_windowMap.remove(tr("模具产量表"));
        }
    }
    if(QWidget *target = m_windowMap.value(tr("模具产量曲线图"))) {
        if(!target->isHidden()) {
            target->close();
            target->deleteLater();
            m_windowMap.remove(tr("模具产量曲线图"));
        }
    }
}
