#include "chonyaenter.h"
#include "ui_chonyaenter.h"

#include <QComboBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QCompleter>

#include "xlsxdocument.h"

ChonyaEnter::ChonyaEnter(QVariant id_value, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChonyaEnter)
    , idvalue_(id_value)
    , out_num(0)
    , control_stand(0)
    , mold_static1(false)
    , mold_static2(false)
    , mold_static3(false)
    , mold_static4(false) {
    ui->setupUi(this);
    curr_id = id_value.toString();
    table = curr_id;
    table.replace("-", "_");
    QDate date = QDate::currentDate().addDays(-1);
    date_str = date.toString("yyyy.MM.dd");
    ui->ProductTime->setText(date_str);
    ui->ProductTime->setCursorPosition(0);
    QListView *listView1 = qobject_cast<QListView *>(ui->MoldCombo->view());
    QScroller *Scroller1 = QScroller::scroller(listView1);
    Scroller1->grabGesture(listView1->viewport(), QScroller::LeftMouseButtonGesture);
    listView1->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QListView *listView2 = qobject_cast<QListView *>(ui->Operater->view());
    QScroller *Scroller2 = QScroller::scroller(listView2);
    Scroller2->grabGesture(listView2->viewport(), QScroller::LeftMouseButtonGesture);
    listView2->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QListView *listView3 = qobject_cast<QListView *>(ui->DirRepair->view());
    QScroller *Scroller3 = QScroller::scroller(listView3);
    Scroller3->grabGesture(listView3->viewport(), QScroller::LeftMouseButtonGesture);
    listView3->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QListView *listView4 = qobject_cast<QListView *>(ui->Operater_2->view());
    QScroller *Scroller4 = QScroller::scroller(listView4);
    Scroller4->grabGesture(listView4->viewport(), QScroller::LeftMouseButtonGesture);
    listView4->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QListView *listView5 = qobject_cast<QListView *>(ui->DirRepair_2->view());
    QScroller *Scroller5 = QScroller::scroller(listView5);
    Scroller5->grabGesture(listView5->viewport(), QScroller::LeftMouseButtonGesture);
    listView5->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QScroller *pScroller = QScroller::scroller(ui->MachineView);
    pScroller->grabGesture(ui->MachineView->viewport(), QScroller::LeftMouseButtonGesture);
    ui->MachineView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QSqlQuery query;
    QString sql =
        QString("create table if not exists D%1(序号 int primary key auto_increment,日期 char(20),机台号 char(5),当日产量 float,累计冲次数 double,下料零件累计 double,关键易损件累计 double,成型零件累计 double,操作员 char(10),模修 char(10),备注 char(200))auto_increment=1;").arg(
        table);
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "界面初始化", "模具产量信息表创建失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    sql = QString("select name from user_message");
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "界面初始化", "用户姓名查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        while(query.next()) {
            if(query.value(0).toString() == "NULL" || query.value(0).toString() == "俞増涛") {
                continue;
            }
            data.append(query.value(0).toString());
        }
    }
    ui->Operater->addItems(data);
    ui->DirRepair->addItems(data);
    ui->Operater_2->addItems(data);
    ui->DirRepair_2->addItems(data);
    QStyledItemDelegate *d = new QStyledItemDelegate;
    QString style = "QAbstractItemView{font: 18pt \"微软雅黑\";background-color:rgb(255,255,255);color:rgb(0,0,0);}"
                    "QAbstractItemView::item:hover{background-color:rgb(0, 120, 212)}";
    // 创建并配置自动完成器（使用容器管理）
    QList<QComboBox *> comboBoxes = {ui->Operater, ui->DirRepair, ui->Operater_2, ui->DirRepair_2};
    for(QComboBox *combo : comboBoxes) {
        QCompleter *completer = new QCompleter(data, this);
        completer->setMaxVisibleItems(10);
        completer->setCaseSensitivity(Qt::CaseInsensitive);
        completer->setCompletionMode(QCompleter::PopupCompletion);
        completer->setFilterMode(Qt::MatchContains);
        combo->setCompleter(completer);
        completer->popup()->setItemDelegate(d);
        completer->popup()->setStyleSheet(style);
        nameCompleters.append(completer);
    }
    QStringList mold_list;
    ui->MoldCombo->blockSignals(true);
    sql = "select 模具编号 from type_message;";
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "界面初始化", "模具编号查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        while(query.next()) {
            mold_list.append(query.value(0).toString());
        }
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

ChonyaEnter::~ChonyaEnter() {
    delete ui;
}

void ChonyaEnter::closeEvent(QCloseEvent *event) {
    Q_UNUSED(event);
    if(QWidget *target = m_windowMap.value(tr("模具产量曲线图"))) {
        if(!target->isHidden()) {
            target->close();
            target->deleteLater();
            m_windowMap.remove(tr("模具产量曲线图"));
        }
    }
    if(QWidget *target = m_windowMap.value(tr("模具产量表"))) {
        if(!target->isHidden()) {
            target->close();
            target->deleteLater();
            m_windowMap.remove(tr("模具产量表"));
        }
    }
}

void ChonyaEnter::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Escape) {
        this->close();
    }
}

void ChonyaEnter::refresh_data() {
    QString sql;
    QSqlQuery query;
    double feed = 0;
    double vulnerable = 0;
    double molding = 0;
    double total = 0;
    QString dir_date;
    QString select_month = date_str.left(7);
    query.prepare("update information_message set 完成情况 = '0' where 模具编号 = :mold_id and 发送用户 = '系统'");
    query.bindValue(":mold_id", curr_id);
    if(!query.exec()) {
        QMessageBox::warning(this, "刷新信息", "保养数据信息刷新失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
    }
    sql = QString("select count(distinct 日期) from D%1 where 备注 like '%关单保养' and 日期 like '%2%';").arg(
        table).arg(select_month);
    if(query.exec(sql)) {
        if(query.next()) {
            ui->PercentLabel1_2->setText(query.value(0).toString());
        }
    }
    QString percent1, percent2, percent3;
    sql = QString("select count(*) from D%1 where 备注 = '下料零件定期保养' and 日期 like '%2%';").arg(
        table).arg(select_month);
    if(query.exec(sql)) {
        if(query.next()) {
            percent1 = query.value(0).toString();
        }
    }
    sql = QString("select count(*) from D%1 where 备注 = '关键易损件定期保养' and 日期 like '%2%';").arg(
        table).arg(select_month);
    if(query.exec(sql)) {
        if(query.next()) {
            percent2 = query.value(0).toString();
        }
    }
    sql = QString("select count(*) from D%1 where 备注 = '成型零件定期保养' and 日期 like '%2%';").arg(
        table).arg(select_month);
    if(query.exec(sql)) {
        if(query.next()) {
            percent3 = query.value(0).toString();
        }
    }
    ui->PercentLabel2_2->setText(QString("下料零件：%1").arg(percent1));
    ui->PercentLabel2_3->setText(QString("关键易损件：%2 成型零件：%3").arg(percent2).arg(percent3));
    sql = QString("select count(*) from D%1 where 备注 = '大保养' and 日期 like '%2%';").arg(table).arg(
        select_month);
    if(query.exec(sql)) {
        if(query.next()) {
            ui->PercentLabel3_2->setText(query.value(0).toString());
        }
    }
    ui->PercentLabel1_1->setStyleSheet("color:balck;");
    ui->PercentLabel2_1->setStyleSheet("color:balck;");
    ui->PercentLabel3_1->setStyleSheet("color:balck;");
    ui->PercentLabel4_1->setStyleSheet("color:balck;");
    model = new QStandardItemModel(this);
    query.prepare("select 管制标准,机台,出数1,出数2,产品料号 from type_message where 模具编号 = :mold_id");
    query.bindValue(":mold_id", curr_id);
    if(!query.exec()) {
        QMessageBox::warning(this, "刷新数据", "模具数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        if(query.value(0).toString() == "铜材材料厚度规格＜0.3mm") {
            control_stand = 1;
        } else if(query.value(0).toString() == "铜材材料厚度规格≧0.3且﹤0.5mm") {
            control_stand = 2;
        } else if(query.value(0).toString() == "铜材材料厚度规格≧0.5mm") {
            control_stand = 3;
        } else if(query.value(0).toString() == "不锈钢材料厚度规格＜0.5mm") {
            control_stand = 4;
        } else if(query.value(0).toString() == "不锈钢材料厚度规格≧0.5mm") {
            control_stand = 5;
        } else {
            control_stand = 0;
        }
        QString machineField = query.value(1).toString();
        QStringList machineList = machineField.split("#");
        for(const QString &machine : machineList) {
            if(!machine.isEmpty()) {
                QList<QStandardItem *> items;
                items.append(new QStandardItem(machine + "#"));
                model->appendRow(items);
            }
        }
        out_num = query.value(2).toInt() * query.value(3).toInt();
        ui->OutNum->setText(query.value(2).toString() + '*' + query.value(3).toString());
        ui->ProductID->setText(query.value("产品料号").toString());
    } else {
        return;
    }
    ui->MachineView->setModel(model);
    sql = QString("(select * from D%1 order by 序号 desc limit 2)order by 序号").arg(table);
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "刷新数据", "产量数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        if(query.next()) {
            ui->Operater->setCurrentText(query.value("操作员").toString());
            ui->DirRepair->setCurrentText(query.value("模修").toString());
            machine_num = query.value("机台号").toString();
            ui->MachineNum->setText(machine_num);
            feed = query.value("下料零件累计").toDouble();
            vulnerable = query.value("关键易损件累计").toDouble();
            molding = query.value("成型零件累计").toDouble();
            total = query.value("累计冲次数").toDouble();
            dir_date = query.value("日期").toString();
            if(query.next()) {
                ui->Operater_2->setCurrentText(query.value("操作员").toString());
                ui->DirRepair_2->setCurrentText(query.value("模修").toString());
                machine_num = query.value("机台号").toString();
                ui->MachineNum->setText(machine_num);
                feed = query.value("下料零件累计").toDouble();
                vulnerable = query.value("关键易损件累计").toDouble();
                molding = query.value("成型零件累计").toDouble();
                total = query.value("累计冲次数").toDouble();
                dir_date = query.value("日期").toString();
            }
        } else {
            feed = 0;
            vulnerable = 0;
            molding = 0;
            total = 0;
        }
    }
    init_MachineView();
    switch(control_stand) {
    case 0: {
        ui->PercentLabel1_1->setText("未设置标准");
        ui->PercentLabel2_1->setText("未设置标准");
        ui->PercentLabel3_1->setText("未设置标准");
    }
    break;
    case 1: {
        ui->PercentLabel1_1->setText(QString("%1%").arg(feed / 5));
        ui->PercentLabel2_1->setText(QString("%1%").arg(vulnerable / 2.5));
        ui->PercentLabel3_1->setText(QString("%1%").arg(molding / 10));
    }
    break;
    case 2: {
        ui->PercentLabel1_1->setText(QString("%1%").arg(feed / 4));
        ui->PercentLabel2_1->setText(QString("%1%").arg(vulnerable / 2));
        ui->PercentLabel3_1->setText(QString("%1%").arg(molding / 8));
    }
    break;
    case 3: {
        ui->PercentLabel1_1->setText(QString("%1%").arg(feed / 2));
        ui->PercentLabel2_1->setText(QString("%1%").arg(vulnerable / 1));
        ui->PercentLabel3_1->setText(QString("%1%").arg(molding / 4));
    }
    break;
    case 4: {
        ui->PercentLabel1_1->setText(QString("%1%").arg(feed / 0.5));
        ui->PercentLabel2_1->setText(QString("%1%").arg(vulnerable / 0.3));
        ui->PercentLabel3_1->setText(QString("%1%").arg(molding / 1));
    }
    break;
    case 5: {
        ui->PercentLabel1_1->setText(QString("%1%").arg(feed / 0.3));
        ui->PercentLabel2_1->setText(QString("%1%").arg(vulnerable / 0.2));
        ui->PercentLabel3_1->setText(QString("%1%").arg(molding / 0.5));
    }
    break;
    }
    if(control_stand) {
        ui->PercentLabel4_1->setText(QString("%1%").arg(total / 200));
        QString keep_status = "";
        if(ui->PercentLabel1_1->text().remove('%').toDouble() > 80) {
            ui->PercentLabel1_1->setStyleSheet("color:orange;");
        }
        if(ui->PercentLabel1_1->text().remove('%').toDouble() > 90) {
            ui->PercentLabel1_1->setStyleSheet("color:red;");
            keep_status += "下料零件需要保养；";
            mold_static1 = 1;
        } else {
            mold_static1 = 0;
        }
        if(ui->PercentLabel2_1->text().remove('%').toDouble() > 80) {
            ui->PercentLabel2_1->setStyleSheet("color:orange;");
        }
        if(ui->PercentLabel2_1->text().remove('%').toDouble() > 90) {
            ui->PercentLabel2_1->setStyleSheet("color:red;");
            keep_status += "关键易损件零件需要保养；";
            mold_static2 = 1;
        } else {
            mold_static2 = 0;
        }
        if(ui->PercentLabel3_1->text().remove('%').toDouble() > 80) {
            ui->PercentLabel3_1->setStyleSheet("color:orange;");
        }
        if(ui->PercentLabel3_1->text().remove('%').toDouble() > 90) {
            ui->PercentLabel3_1->setStyleSheet("color:red;");
            keep_status += "成型零件需要保养；";
            mold_static3 = 1;
        } else {
            mold_static3 = 0;
        }
        if(ui->PercentLabel4_1->text().remove('%').toDouble() > 80) {
            ui->PercentLabel4_1->setStyleSheet("color:orange;");
        }
        if(ui->PercentLabel4_1->text().remove('%').toDouble() > 90) {
            ui->PercentLabel4_1->setStyleSheet("color:red;");
            keep_status += "当前已达模具寿命冲200KK次数，需做报废处理；";
            mold_static4 = 1;
        } else {
            mold_static4 = 0;
        }
        if(init_information("所有人")) {
            if(keep_status.isEmpty()) {
                keep_status += "当前无需保养";
            }
            query.prepare("update type_message set 保养情况 = :keep_status, 模修 = :dir_repair, 维修机台 = :dir_machine, 维修日期 = :dir_date, 下料零件累计 = :feed, 关键易损件累计 = :vulnerable, 成型零件累计 = :molding where 模具编号 = :mold_id");
            query.bindValue(":keep_status", keep_status);
            if(ui->DirRepair->currentText().isEmpty()) {
                query.bindValue(":dir_repair", ui->DirRepair_2->currentText());
            } else if(ui->DirRepair_2->currentText().isEmpty()) {
                query.bindValue(":dir_repair", ui->DirRepair->currentText());
            } else {
                query.bindValue(":dir_repair", ui->DirRepair->currentText() + "、" + ui->DirRepair_2->currentText());
            }
            query.bindValue(":dir_machine", ui->MachineNum->text());
            query.bindValue(":dir_date", dir_date);
            query.bindValue(":feed", feed);
            query.bindValue(":vulnerable", vulnerable);
            query.bindValue(":molding", molding);
            query.bindValue(":mold_id", curr_id);
            if(!query.exec()) {
                QMessageBox::warning(this, "刷新数据", "模具数据更新失败：\n" + query.lastError().text(),
                    QMessageBox::Cancel);
                return;
            }
            QTimer::singleShot(0, this, &ChonyaEnter::mysignal);
            QString currTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            if(mold_static1) {
                query.prepare("update information_message set 日期 = :curr_time,信息 = :keep_status,完成情况 = '1' where 模具编号 = :mold_id and 发送用户 = '系统' and 模具性质 = '下料零件'");
                query.bindValue(":curr_time", currTime);
                query.bindValue(":keep_status", "下料零件需要保养；");
                query.bindValue(":mold_id", curr_id);
                if(!query.exec()) {
                    QMessageBox::warning(this, "刷新数据", "模具信息列表更新失败：\n" + query.lastError().text(),
                        QMessageBox::Cancel);
                    return;
                } else {
                    mold_static1 = 0;
                }
            }
            if(mold_static2) {
                query.prepare("update information_message set 日期 = :curr_time,信息 = :keep_status,完成情况 = '1' where 模具编号 = :mold_id and 发送用户 = '系统' and 模具性质 = '关键易损件'");
                query.bindValue(":curr_time", currTime);
                query.bindValue(":keep_status", "关键易损件需要保养；");
                query.bindValue(":mold_id", curr_id);
                if(!query.exec()) {
                    QMessageBox::warning(this, "刷新数据", "模具信息列表更新失败：\n" + query.lastError().text(),
                        QMessageBox::Cancel);
                    return;
                } else {
                    mold_static2 = 0;
                }
            }
            if(mold_static3) {
                query.prepare("update information_message set 日期 = :curr_time,信息 = :keep_status,完成情况 = '1' where 模具编号 = :mold_id and 发送用户 = '系统' and 模具性质 = '成型零件'");
                query.bindValue(":curr_time", currTime);
                query.bindValue(":keep_status", "成型零件需要保养；");
                query.bindValue(":mold_id", curr_id);
                if(!query.exec()) {
                    QMessageBox::warning(this, "刷新数据", "模具信息列表更新失败：\n" + query.lastError().text(),
                        QMessageBox::Cancel);
                    return;
                } else {
                    mold_static3 = 0;
                }
            }
            if(mold_static4) {
                query.prepare("update information_message set 日期 = :curr_time,信息 = :keep_status,完成情况 = '1' where 模具编号 = :mold_id and 发送用户 = '系统' and 模具性质 = '整体模具'");
                query.bindValue(":curr_time", currTime);
                query.bindValue(":keep_status", "当前已达模具寿命冲200KK次数，需做报废处理；");
                query.bindValue(":mold_id", curr_id);
                if(!query.exec()) {
                    QMessageBox::warning(this, "刷新数据", "模具信息列表更新失败：\n" + query.lastError().text(),
                        QMessageBox::Cancel);
                    return;
                } else {
                    mold_static4 = 0;
                }
            }
        }
    }
}

void ChonyaEnter::init_MachineView() {
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
        if(machine_num.isEmpty()) {
            indexToSelect = model->index(0, 0);
            machine_num = indexToSelect.data().toString();
        }
    }
}

bool ChonyaEnter::init_information(const QString &set_name) {
    QSqlQuery query;
    QString currTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString sql =
        QString("select count(*) from information_message where 模具编号 = '%1' and 发送用户 = '系统' and 接收用户 = '%2';").arg(
        curr_id).arg(set_name);
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "初始化信息列表",
            "模具信息列表数量查询失败：\n" + query.lastError().text(), QMessageBox::Cancel);
        return false;
    } else {
        if(query.next()) {
            if(!query.value(0).toInt()) {
                sql = "insert into information_message (日期,模具编号,模具性质,发送用户,接收用户,完成情况) values (:date, :mold_id, :mold_nature, :tuser, :ruser, :finished)";
                query.prepare(sql);
                query.bindValue(":date", currTime);
                query.bindValue(":mold_id", curr_id);
                query.bindValue(":mold_nature", "下料零件");
                query.bindValue(":tuser", "系统");
                query.bindValue(":ruser", set_name);
                query.bindValue(":finished", "0");
                if(!query.exec()) {
                    QMessageBox::warning(this, "初始化信息列表",
                        "模具下料零件保养信息插入失败：\n" + query.lastError().text(), QMessageBox::Cancel);
                    return false;
                }
                query.bindValue(":mold_nature", "关键易损件");
                if(!query.exec()) {
                    QMessageBox::warning(this, "初始化信息列表",
                        "模具关键易损件保养信息插入失败：\n" + query.lastError().text(), QMessageBox::Cancel);
                    return false;
                }
                query.bindValue(":mold_nature", "成型零件");
                if(!query.exec()) {
                    QMessageBox::warning(this, "初始化信息列表",
                        "模具成型零件保养信息插入失败：\n" + query.lastError().text(), QMessageBox::Cancel);
                    return false;
                }
                query.bindValue(":mold_nature", "整体模具");
                if(!query.exec()) {
                    QMessageBox::warning(this, "初始化信息列表",
                        "模具寿命保养信息插入失败：\n" + query.lastError().text(), QMessageBox::Cancel);
                    return false;
                }
            }
        }
    }
    return true;
}

void ChonyaEnter::on_GetButton_clicked() {
    handleData = new HandleData(curr_id, "mold", this);
    connect(handleData, SIGNAL(mysignal()), this, SLOT(refresh_data()));
    handleData->setWindowTitle("模具产量表");
    m_windowMap.insert(tr("模具产量表"), handleData);
    handleData->show();
}

void ChonyaEnter::on_NewButton_clicked() {
    QString question =
        "您确定要翻新该模具？翻新后，所有数据将还原到最初值（包括模具累计冲次数）";
    int reply = QMessageBox::question(this, "模具翻新", question, QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
retry:
        bool ok;
        QString secret = QInputDialog::getText(this, "模具翻新", "请输入管理密钥:", QLineEdit::Password, "", &ok);
        if(ok && !secret.isEmpty()) {
            if(secret == "mengen888") {
                QSqlQuery query;
                QString sql =
                    QString("insert into D%1 (日期,机台号,当日产量,累计冲次数,下料零件累计,关键易损件累计,成型零件累计,操作员,模修,备注) values (:date, :machine_num, :product_num, :total_num, :feed_num, :vulnerable_num, :molding_num, :operator, :repair, :des)").arg(
                    table);
                query.prepare(sql);
                query.bindValue(":date", ui->ProductTime->text());
                query.bindValue(":machine_num", machine_num);
                query.bindValue(":product_num", 0);
                query.bindValue(":total_num", 0);
                query.bindValue(":feed_num", 0);
                query.bindValue(":vulnerable_num", 0);
                query.bindValue(":molding_num", 0);
                query.bindValue(":operator", "");
                query.bindValue(":repair", "");
                query.bindValue(":des", "模具翻新");
                if(!query.exec()) {
                    QMessageBox::warning(this, "模具翻新", "产量数据插入失败：\n" + query.lastError().text(),
                        QMessageBox::Cancel);
                    return;
                } else {
                    QMessageBox::information(this, "模具翻新", "模具翻新成功", QMessageBox::Ok);
                    refresh_data();
                }
            } else {
                QMessageBox::warning(this, "模具翻新", "密钥错误，请重新输入！");
                goto retry;
            }
        } else if(ok && secret.isEmpty()) {
            QMessageBox::warning(this, "模具翻新", "密钥为空，请输入管理密钥！");
            return;
        }
    }
}

void ChonyaEnter::on_PlotButton_clicked() {
    QLineSeries *series = new QLineSeries;
    QSqlQuery query;
    QString sql =
        QString("(select 日期,当日产量 from D%1 where 机台号 = '%2' order by 序号 desc limit 10)order by 日期 desc;").arg(
        table).arg(ui->MachineNum->text());
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "创建产量曲线图", "产量数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        while(query.next()) {
            QString dateStr = query.value(0).toString();
            QDateTime date = QDateTime::fromString(dateStr, "yyyy.MM.dd");
            int production = query.value(1).toInt();
            series->append(date.toMSecsSinceEpoch(), production);
        }
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
    chartView->resize(800, 600);
    chartView->show();
}

void ChonyaEnter::on_CheckButton_clicked() {
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
        QXlsx::Document xlsx1(":/ducument/chonya_message.xlsx");
        QString sql =
            QString("select 产品名称,产品料号,模具编号,材料规格,管制标准,出数1,出数2 from type_message where 模具编号 = '%1';").arg(
            ui->MoldCombo->currentText());
        if(query.exec(sql)) {
            if(query.next()) {
                xlsx1.write(3, 2, query.value(0).toString(), Song12C);
                xlsx1.write(3, 6, query.value(1).toString(), Song12C);
                xlsx1.write(4, 2, query.value(2).toString(), Song12C);
                xlsx1.write(4, 6, query.value(3).toString(), Song12C);
                xlsx1.write(3, 9, query.value(5).toString(), Song12C);
                xlsx1.write(3, 11, query.value(6).toString(), Song12C);
                if(query.value(4).toString() == "铜材材料厚度规格＜0.3mm") {
                    xlsx1.write(6, 5, "500", Song12C);
                    xlsx1.write(6, 6, "250", Song12C);
                    xlsx1.write(6, 7, "1000", Song12C);
                } else if(query.value(4).toString() == "铜材材料厚度规格≧0.3且﹤0.5mm") {
                    xlsx1.write(6, 5, "400", Song12C);
                    xlsx1.write(6, 6, "200", Song12C);
                    xlsx1.write(6, 7, "800", Song12C);
                } else if(query.value(4).toString() == "铜材材料厚度规格≧0.5mm") {
                    xlsx1.write(6, 5, "200", Song12C);
                    xlsx1.write(6, 6, "100", Song12C);
                    xlsx1.write(6, 7, "400", Song12C);
                } else if(query.value(4).toString() == "不锈钢材料厚度规格＜0.5mm") {
                    xlsx1.write(6, 5, "50", Song12C);
                    xlsx1.write(6, 6, "30", Song12C);
                    xlsx1.write(6, 7, "100", Song12C);
                } else if(query.value(4).toString() == "不锈钢材料厚度规格≧0.5mm") {
                    xlsx1.write(6, 5, "30", Song12C);
                    xlsx1.write(6, 6, "20", Song12C);
                    xlsx1.write(6, 7, "50", Song12C);
                }
                if(selected == "全部数据") {
                    sql = QString("select * from D%1 order by 序号 ").arg(table);
                } else {
                    sql = QString("select * from D%1 where 日期 like '%%2%' order by 序号 ").arg(table).arg(date_str.left(5));
                }
                if(!query.exec(sql)) {
                    QMessageBox::warning(this, "导出产量统计及模具保养期限管制信息",
                        "产量数据查询失败：\n" + query.lastError().text(), QMessageBox::Cancel);
                    return;
                }
                while(query.next()) {
                    for(int i = 1; i < 11; i++) {
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
                    "冲压产量统计及模具保养期限管制信息表创建失败：");
            }
        } else {
            QMessageBox::warning(this, "导出产量统计及模具保养期限管制信息",
                "模具数据查询失败：\n" + query.lastError().text(), QMessageBox::Cancel);
        }
    }
}

void ChonyaEnter::on_EnterButton_clicked() {
    if(ui->ProductNum->text().isEmpty() || ui->ProductNum_2->text().isEmpty()) {
        QMessageBox::warning(this, "录入产量", "请输入产量", QMessageBox::Cancel);
        return;
    }
    double feed, vulnerable, molding, total;
    QSqlQuery query;
    QString sql = QString("select * from D%1 order by 序号 desc limit 1;").arg(table);
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "录入产量", "产量数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        total = query.value("累计冲次数").toDouble();
        feed = query.value("下料零件累计").toDouble();
        vulnerable = query.value("关键易损件累计").toDouble();
        molding = query.value("成型零件累计").toDouble();
    } else {
        total = 0;
        feed = 0;
        vulnerable = 0;
        molding = 0;
    }
    total = ui->ProductNum->text().toDouble() / 10 / out_num + total;
    feed = ui->ProductNum->text().toDouble() / 10 / out_num + feed;
    vulnerable = ui->ProductNum->text().toDouble() / 10 / out_num + vulnerable;
    molding = ui->ProductNum->text().toDouble() / 10 / out_num + molding;
    sql = QString("insert into D%1 (日期,机台号,当日产量,累计冲次数,下料零件累计,关键易损件累计,成型零件累计,操作员,模修) values (:date, :machine_num, :product_num, :total_num, :feed_num, :vulnerable_num, :molding_num, :operator, :repair)").arg(
        table);
    query.prepare(sql);
    query.bindValue(":date", ui->ProductTime->text());
    query.bindValue(":machine_num", machine_num);
    query.bindValue(":product_num", ui->ProductNum->text());
    QString total_value = QString::number(total, 'f', 2);
    query.bindValue(":total_num", total_value);
    QString feed_value = QString::number(feed, 'f', 2);
    query.bindValue(":feed_num", feed_value);
    QString vulnerable_value = QString::number(vulnerable, 'f', 2);
    query.bindValue(":vulnerable_num", vulnerable_value);
    QString molding_value = QString::number(molding, 'f', 2);
    query.bindValue(":molding_num", molding_value);
    query.bindValue(":operator", ui->Operater->currentText());
    query.bindValue(":repair", ui->DirRepair->currentText());
    if(!query.exec()) {
        QMessageBox::warning(this, "录入产量", "产量数据插入失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        total = ui->ProductNum_2->text().toDouble() / 10 / out_num + total;
        feed = ui->ProductNum_2->text().toDouble() / 10 / out_num + feed;
        vulnerable = ui->ProductNum_2->text().toDouble() / 10 / out_num + vulnerable;
        molding = ui->ProductNum_2->text().toDouble() / 10 / out_num + molding;
        sql = QString("insert into D%1 (日期,机台号,当日产量,累计冲次数,下料零件累计,关键易损件累计,成型零件累计,操作员,模修) values (:date, :machine_num, :product_num, :total_num, :feed_num, :vulnerable_num, :molding_num, :operator, :repair)").arg(
            table);
        query.prepare(sql);
        query.bindValue(":date", ui->ProductTime->text());
        query.bindValue(":machine_num", machine_num);
        query.bindValue(":product_num", ui->ProductNum_2->text());
        QString total_value = QString::number(total, 'f', 2);
        query.bindValue(":total_num", total_value);
        QString feed_value = QString::number(feed, 'f', 2);
        query.bindValue(":feed_num", feed_value);
        QString vulnerable_value = QString::number(vulnerable, 'f', 2);
        query.bindValue(":vulnerable_num", vulnerable_value);
        QString molding_value = QString::number(molding, 'f', 2);
        query.bindValue(":molding_num", molding_value);
        query.bindValue(":operator", ui->Operater_2->currentText());
        query.bindValue(":repair", ui->DirRepair_2->currentText());
        if(!query.exec()) {
            QMessageBox::warning(this, "录入产量", "产量数据插入失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        } else {
            QMessageBox::information(this, "录入产量", "产量录入成功", QMessageBox::Ok);
            refresh_data();
        }
    }
}

void ChonyaEnter::on_ProductNum_2_returnPressed() {
    if(ui->ProductNum->text().isEmpty() || ui->ProductNum_2->text().isEmpty()) {
        QMessageBox::warning(this, "录入产量", "请输入产量", QMessageBox::Cancel);
        return;
    }
    double feed, vulnerable, molding, total;
    QSqlQuery query;
    QString sql = QString("select * from D%1 order by 序号 desc limit 1;").arg(table);
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "录入产量", "产量数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        total = query.value("累计冲次数").toDouble();
        feed = query.value("下料零件累计").toDouble();
        vulnerable = query.value("关键易损件累计").toDouble();
        molding = query.value("成型零件累计").toDouble();
    } else {
        total = 0;
        feed = 0;
        vulnerable = 0;
        molding = 0;
    }
    total = ui->ProductNum->text().toDouble() / 10 / out_num + total;
    feed = ui->ProductNum->text().toDouble() / 10 / out_num + feed;
    vulnerable = ui->ProductNum->text().toDouble() / 10 / out_num + vulnerable;
    molding = ui->ProductNum->text().toDouble() / 10 / out_num + molding;
    sql = QString("insert into D%1 (日期,机台号,当日产量,累计冲次数,下料零件累计,关键易损件累计,成型零件累计,操作员,模修) values (:date, :machine_num, :product_num, :total_num, :feed_num, :vulnerable_num, :molding_num, :operator, :repair)").arg(
        table);
    query.prepare(sql);
    query.bindValue(":date", ui->ProductTime->text());
    query.bindValue(":machine_num", machine_num);
    query.bindValue(":product_num", ui->ProductNum->text());
    QString total_value = QString::number(total, 'f', 2);
    query.bindValue(":total_num", total_value);
    QString feed_value = QString::number(feed, 'f', 2);
    query.bindValue(":feed_num", feed_value);
    QString vulnerable_value = QString::number(vulnerable, 'f', 2);
    query.bindValue(":vulnerable_num", vulnerable_value);
    QString molding_value = QString::number(molding, 'f', 2);
    query.bindValue(":molding_num", molding_value);
    query.bindValue(":operator", ui->Operater->currentText());
    query.bindValue(":repair", ui->DirRepair->currentText());
    if(!query.exec()) {
        QMessageBox::warning(this, "录入产量", "产量数据插入失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        total = ui->ProductNum_2->text().toDouble() / 10 / out_num + total;
        feed = ui->ProductNum_2->text().toDouble() / 10 / out_num + feed;
        vulnerable = ui->ProductNum_2->text().toDouble() / 10 / out_num + vulnerable;
        molding = ui->ProductNum_2->text().toDouble() / 10 / out_num + molding;
        ;
        sql = QString("insert into D%1 (日期,机台号,当日产量,累计冲次数,下料零件累计,关键易损件累计,成型零件累计,操作员,模修) values (:date, :machine_num, :product_num, :total_num, :feed_num, :vulnerable_num, :molding_num, :operator, :repair)").arg(
            table);
        query.prepare(sql);
        query.bindValue(":date", ui->ProductTime->text());
        query.bindValue(":machine_num", machine_num);
        query.bindValue(":product_num", ui->ProductNum_2->text());
        QString total_value = QString::number(total, 'f', 2);
        query.bindValue(":total_num", total_value);
        QString feed_value = QString::number(feed, 'f', 2);
        query.bindValue(":feed_num", feed_value);
        QString vulnerable_value = QString::number(vulnerable, 'f', 2);
        query.bindValue(":vulnerable_num", vulnerable_value);
        QString molding_value = QString::number(molding, 'f', 2);
        query.bindValue(":molding_num", molding_value);
        query.bindValue(":operator", ui->Operater_2->currentText());
        query.bindValue(":repair", ui->DirRepair_2->currentText());
        if(!query.exec()) {
            QMessageBox::warning(this, "录入产量", "产量数据插入失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        } else {
            QMessageBox::information(this, "录入产量", "产量录入成功", QMessageBox::Ok);
            refresh_data();
        }
    }
}

void ChonyaEnter::on_ReturnButton_clicked() {
    QString question = "您确定要撤回上一条数据吗？";
    int reply = QMessageBox::question(this, "撤回产量数据", question, QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        QSqlQuery query;
        QString sql = QString("select 序号 from D%1 order by 序号 desc limit 2;").arg(table);
        if(!query.exec(sql)) {
            QMessageBox::warning(this, "撤回产量数据", "产量序号查询失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        } else {
            while(query.next()) {
                QSqlQuery re_delete;
                sql = QString("delete from D%1 where 序号 = '%2';").arg(table).arg(query.value(0).toString());
                if(!re_delete.exec(sql)) {
                    QMessageBox::warning(this, "撤回产量数据", "产量数据删除失败：\n" + query.lastError().text(),
                        QMessageBox::Cancel);
                    return;
                }
            }
            QMessageBox::information(this, "撤回产量数据", "产量数据撤回成功", QMessageBox::Ok);
            refresh_data();
        }
    }
}

void ChonyaEnter::on_UserEdit_returnPressed() {
    QString set_name = ui->UserEdit->text();
    if(set_name.isEmpty()) {
        QMessageBox::warning(this, "添加员工", "员工名称不能为空", QMessageBox::Cancel);
        return;
    }
    bool stat = false;
    QSqlQuery query;
    QString sql = "select name from user_message;";
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "添加员工", "员工姓名查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        while(query.next()) {
            if(set_name == query.value(0).toString()) {
                QMessageBox::warning(this, "添加员工", "该员工已存在", QMessageBox::Cancel);
                stat = true;
                return;
            }
        }
        if(stat) {
            return;
        }
    }
    QString set_user, set_passwd;
    sql = "select id from user_message order by id desc limit 1;";
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "添加员工", "员工ID查询失败：\n" + query.lastError().text(), QMessageBox::Cancel);
        return;
    } else {
        if(query.next()) {
            set_user = QString("user%1").arg(query.value(0).toInt() + 1);
            set_passwd = QString("user%1").arg(query.value(0).toInt() + 1);
        }
    }
    query.prepare("insert into user_message (user,name,passwd,authority) values (:set_user, :set_name, :set_passwd, :set_authority)");
    query.bindValue(":set_user", set_user);
    query.bindValue(":set_name", set_name);
    query.bindValue(":set_passwd", set_passwd);
    query.bindValue(":set_authority", "0");
    if(!query.exec()) {
        QMessageBox::warning(this, "添加员工", "员工数据插入失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        QMessageBox::information(this, "添加员工", "员工添加成功\n账号：" + set_user + "\n密码：" + set_passwd,
            QMessageBox::Ok);
        ui->Operater->addItem(set_name);
        ui->DirRepair->addItem(set_name);
        ui->Operater_2->addItem(set_name);
        ui->DirRepair_2->addItem(set_name);
        // 更新所有自动完成器的模型
        for(QCompleter *completer : nameCompleters) {
            QStringListModel *model = qobject_cast<QStringListModel *>(completer->model());
            if(model) {
                QStringList strings = model->stringList();
                strings << set_name;
                model->setStringList(strings);
            }
        }
        ui->UserEdit->clear();
    }
}

void ChonyaEnter::on_MachineNum_2_returnPressed() {
    if(curr_id.isEmpty()) {
        QMessageBox::warning(this, "添加机台", "请选择模具", QMessageBox::Cancel);
        return;
    }
    QString data_machine;
    QString curr_machine = ui->MachineNum_2->text().replace("#", "");
    for(int i = 0; i < ui->MachineView->model()->rowCount(); ++i) {
        QModelIndex index = ui->MachineView->model()->index(i, 0);
        QString exisingMachine = ui->MachineView->model()->data(index, Qt::DisplayRole).toString();
        if(ui->MachineView->model()->data(index, Qt::DisplayRole).toString().remove('#') == curr_machine.remove('#')) {
            QMessageBox::warning(this, "添加机台", "该机台已存在", QMessageBox::Cancel);
            return;
        }
        data_machine += ("#" + exisingMachine);
    }
    data_machine += ("#" + curr_machine);
    QSqlQuery query;
    QString sql = "update type_message set 机台 = :data_machine where 模具编号 = :mold_id";
    query.prepare(sql);
    query.bindValue(":data_machine", data_machine);
    query.bindValue(":mold_id", curr_id);
    if(!query.exec()) {
        QMessageBox::warning(this, "添加机台", "模具机台更新失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        QMessageBox::information(this, "添加机台", "机台添加成功", QMessageBox::Ok);
        refresh_data();
    }
}

void ChonyaEnter::on_MachineView_clicked(const QModelIndex &index) {
    machine_num = index.data().toString();
    ui->MachineNum->setText(machine_num);
}

void ChonyaEnter::on_MoldCombo_currentTextChanged(const QString &arg1) {
    curr_id = arg1;
    table = curr_id;
    table.replace("-", "_");
    ui->MachineNum->clear();
    ui->ProductID->clear();
    ui->PercentLabel1_1->clear();
    ui->PercentLabel2_1->clear();
    ui->PercentLabel3_1->clear();
    ui->PercentLabel4_1->clear();
    model = new QStandardItemModel(this);
    ui->MachineView->setModel(model);
    refresh_data();
}
