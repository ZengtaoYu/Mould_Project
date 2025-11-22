#include "warehouseadd.h"
#include "ui_warehouseadd.h"

// Qt核心库
#include <QSettings>
#include <QDateTime>
#include <QDebug>

// Qt GUI
#include <QMessageBox>
#include <QFileDialog>
#include <QCompleter>
#include <QListView>
#include <QScroller>
#include <QAbstractItemView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include <QSqlQuery>
#include <QSqlError>
#include <QBrush>
#include <QFont>
#include <QPushButton>
#include <QCloseEvent>
#include <QModelIndex>
#include <QModelIndexList>
#include <QItemSelectionModel>

// 第三方库
#include "xlsxdocument.h"

// 项目内头文件
#include "warehouse/warehousedele.h"

WarehouseAdd::WarehouseAdd(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WarehouseAdd)
    , m_model(nullptr)
    , m_warehouseDele(nullptr) {
    ui->setupUi(this);
    QListView *listView1 = qobject_cast<QListView *>(ui->MoldCombo->view());
    QScroller *Scroller1 = QScroller::scroller(listView1);
    Scroller1->grabGesture(listView1->viewport(), QScroller::LeftMouseButtonGesture);
    listView1->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QListView *listView2 = qobject_cast<QListView *>(ui->PartCombo_1->view());
    QScroller *Scroller2 = QScroller::scroller(listView2);
    Scroller2->grabGesture(listView2->viewport(), QScroller::LeftMouseButtonGesture);
    listView2->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QListView *listView3 = qobject_cast<QListView *>(ui->PartCombo_2->view());
    QScroller *Scroller3 = QScroller::scroller(listView3);
    Scroller3->grabGesture(listView3->viewport(), QScroller::LeftMouseButtonGesture);
    listView3->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QListView *listView4 = qobject_cast<QListView *>(ui->CabinetCombo->view());
    QScroller *Scroller4 = QScroller::scroller(listView4);
    Scroller4->grabGesture(listView4->viewport(), QScroller::LeftMouseButtonGesture);
    listView4->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QScroller *pScroller = QScroller::scroller(ui->NameView);
    pScroller->grabGesture(ui->NameView->viewport(), QScroller::LeftMouseButtonGesture);
    ui->NameView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QSettings config("userconfig.ini", QSettings::IniFormat);
    m_currentPart = config.value("SELECTIONCONFIG/Select1").toString();
    if(m_currentPart.isEmpty()) {
        m_currentPart = "冲压";
    }
    ui->PartCombo_1->setCurrentText(m_currentPart);
    ui->PartCombo_2->setCurrentText(m_currentPart);
    ui->FMoldEdit->setText(config.value("SELECTIONCONFIG/Mold").toString());
    ui->NameView->header()->setDefaultAlignment(Qt::AlignHCenter);
    ui->NameView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->NameView->setItemsExpandable(true);
    RefreshData();
}

WarehouseAdd::~WarehouseAdd() {
    delete ui;
}

void WarehouseAdd::closeEvent(QCloseEvent *event) {
    Q_UNUSED(event);
    if(QWidget *target = m_windowMap.value(tr("模具&货柜管理"))) {
        if(!target->isHidden()) {
            target->close();
            target->deleteLater();
            m_windowMap.remove(tr("模具&货柜管理"));
        }
    }
}

void WarehouseAdd::RefreshData() {
    QString sql;
    QSqlQuery query;
    QSettings config("userconfig.ini", QSettings::IniFormat);
    ui->FSpareEdit->clear();
    sql = QString("select count(*) from mold_message where 隶属部门 = '%1';").arg(m_currentPart);
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "刷新数据", "模具数量查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        if(query.next()) {
            ui->MoldNum->setText(query.value(0).toString());
        }
    }
    QStyledItemDelegate *d = new QStyledItemDelegate;
    QString style = "QAbstractItemView{font: 18pt \"微软雅黑\";background-color:rgb(255,255,255);color:rgb(0,0,0);}"
                    "QAbstractItemView::item:hover{background-color:rgb(0, 120, 212)}";
    m_moldList.clear();
    ui->MoldCombo->clear();
    sql = QString("select 模具编号 from mold_message where 隶属部门 = '%1';").arg(m_currentPart);
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "刷新数据", "模具编号查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        while(query.next()) {
            m_moldList.append(query.value(0).toString());
        }
    }
    ui->MoldCombo->addItems(m_moldList);
    QCompleter *MoldCompleter = new QCompleter(m_moldList, this);
    MoldCompleter->setMaxVisibleItems(10);
    MoldCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    MoldCompleter->setCompletionMode(QCompleter::PopupCompletion);
    MoldCompleter->setFilterMode(Qt::MatchContains);
    ui->MoldCombo->setCompleter(MoldCompleter);
    MoldCompleter->popup()->setItemDelegate(d);
    MoldCompleter->popup()->setStyleSheet(style);
    ui->MoldCombo->setCurrentText(config.value("SELECTIONCONFIG/Select2").toString());
    m_cabinetList.clear();
    ui->CabinetCombo->clear();
    sql = "select 货柜名称 from cabinet_message order by 货柜名称 asc;";
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "刷新数据", "货柜数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        while(query.next()) {
            m_cabinetList.append(query.value(0).toString());
        }
    }
    ui->CabinetCombo->addItems(m_cabinetList);
    QCompleter *CabinetCompleter = new QCompleter(m_cabinetList, this);
    CabinetCompleter->setMaxVisibleItems(10);
    CabinetCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    CabinetCompleter->setCompletionMode(QCompleter::PopupCompletion);
    CabinetCompleter->setFilterMode(Qt::MatchContains);
    ui->CabinetCombo->setCompleter(CabinetCompleter);
    CabinetCompleter->popup()->setItemDelegate(d);
    CabinetCompleter->popup()->setStyleSheet(style);
    ui->CabinetCombo->setCurrentText(config.value("SELECTIONCONFIG/Select3").toString());
    QMap<QString, int> moldCountMap;
    QString countSql;
    if(m_currentPart == "冲压") {
        countSql = "select 模具编号, count(*) from chonya_message where 模具编号 like :mold_id group by 模具编号";
    } else if(m_currentPart == "成型") {
        countSql =
            "select 模具编号, count(*) from chengxing_message where 模具编号 like :mold_id group by 模具编号";
    }
    query.prepare(countSql);
    query.bindValue(":mold_id", "%" + ui->FMoldEdit->text() + "%");
    if(!query.exec()) {
        QMessageBox::warning(this, "刷新", "备件数据查询失败：\n" + query.lastError().text(), QMessageBox::Cancel);
        return;
    } else {
        while(query.next()) {
            QString moldId = query.value(0).toString();
            int count = query.value(1).toInt();
            moldCountMap[moldId] = count;
        }
    }
    m_model = new QStandardItemModel(this);
    ui->NameView->setModel(m_model);
    m_model->setHorizontalHeaderLabels({"备件号", "安全库存"});
    if(m_currentPart == "冲压") {
        sql = QString("select 模具编号,备件号,安全库存,总库存量 from chonya_message where 模具编号 like '%%1%'").arg(
            ui->FMoldEdit->text());
    } else if(m_currentPart == "成型") {
        sql = QString("select 模具编号,备件号,安全库存,总库存量 from chengxing_message where 模具编号 like '%%1%'").arg(
            ui->FMoldEdit->text());
    }
    QMap<QString, QStandardItem *> topItems;
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "刷新数据", "备件数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        while(query.next()) {
            QString moldId = query.value(0).toString();
            int count = moldCountMap.value(moldId, 0);
            QString table = QString(moldId + "(%1类)").arg(count);
            QStandardItem *topItem = topItems.value(table, nullptr);
            if(!topItem) {
                topItem = new QStandardItem(table);
                topItems[table] = topItem;
                m_model->appendRow(topItem);
            }
            QStandardItem *item1 = new QStandardItem(query.value(1).toString());
            item1->setTextAlignment(Qt::AlignCenter);
            QStandardItem *item2;
            if(query.value(2).toInt()) {
                item2 = new QStandardItem(query.value(2).toString());
            } else {
                item2 = new QStandardItem("未设置");
            }
            item2->setTextAlignment(Qt::AlignCenter);
            topItem->appendRow({item1, item2});
            if(query.value(2).toInt() > query.value(3).toInt() && query.value(2).toInt()) {
                item1->setBackground(QBrush(Qt::red));
                item2->setBackground(QBrush(Qt::red));
            }
        }
    }
    ui->NameView->header()->resizeSection(0, 200);
    ui->NameView->header()->stretchLastSection();
    ui->NameView->header()->setMinimumSectionSize(50);
    QFont font = ui->NameView->header()->font();
    font.setPointSize(12);
    ui->NameView->header()->setFont(font);
    ui->NameView->expandAll();
    m_currentSpare = "";
    ui->CabinetEdit->clear();
    ui->FSpareEdit->clear();
    ui->Label1->setStyleSheet("color:red;");
    m_currentMold = config.value("SELECTIONCONFIG/Mold").toString();
    m_currentSpare = config.value("SELECTIONCONFIG/Spare").toString();
    if(!m_currentMold.isEmpty() && !m_currentSpare.isEmpty()) {
        QStandardItemModel *model = qobject_cast<QStandardItemModel *>(ui->NameView->model());
        if(!model) {
            return;
        }
        QModelIndexList matches = m_model->match(m_model->index(0, 0), Qt::DisplayRole, m_currentSpare, -1,
            Qt::MatchExactly | Qt::MatchRecursive);
        if(!matches.isEmpty()) {
            QModelIndex targetIndex;
            targetIndex = matches.first();
            ui->NameView->setCurrentIndex(targetIndex);
            ui->NameView->selectionModel()->select(targetIndex, QItemSelectionModel::Select | QItemSelectionModel::Rows);
            ui->NameView->scrollTo(targetIndex, QAbstractItemView::PositionAtCenter);
            ui->Label1->setStyleSheet("color:black;");
            ui->FSpareEdit->setText(m_currentSpare);
            if(m_currentPart == "冲压") {
                query.prepare("select * from chonya_message where 模具编号 = :mold and 备件号 = :spare and 存放柜号 = :cabinet");
            } else if(m_currentPart == "成型") {
                query.prepare("select * from chengxing_message where 模具编号 = :mold and 备件号 = :spare and 存放柜号 = :cabinet");
            }
            query.bindValue(":mold", m_currentMold);
            query.bindValue(":spare", m_currentSpare);
            query.bindValue(":cabinet", config.value("SELECTIONCONFIG/Cabinet").toString());
            if(!query.exec()) {
                QMessageBox::warning(this, "刷新数据", "备件数据查询失败：\n" + query.lastError().text(),
                    QMessageBox::Cancel);
                return;
            } else {
                if(query.next()) {
                    ui->SpareNum->setText(query.value("总库存量").toString());
                    ui->CabinetEdit->setText(query.value("存放柜号").toString());
                }
            }
        }
    }
}

void WarehouseAdd::on_PartCombo_1_currentIndexChanged(const QString &arg1) {
    m_currentPart = arg1;
    ui->FMoldEdit->clear();
    ui->PartCombo_2->setCurrentText(ui->PartCombo_1->currentText());
    QSettings config("userconfig.ini", QSettings::IniFormat);
    config.setValue("SELECTIONCONFIG/Select1", m_currentPart);
    config.sync();
    RefreshData();
}

void WarehouseAdd::on_PartCombo_2_currentIndexChanged(const QString &arg1) {
    m_currentPart = arg1;
    ui->FMoldEdit->clear();
    ui->PartCombo_1->setCurrentText(ui->PartCombo_2->currentText());
    QSettings config("userconfig.ini", QSettings::IniFormat);
    config.setValue("SELECTIONCONFIG/Select1", m_currentPart);
    config.sync();
    RefreshData();
}

void WarehouseAdd::on_AddButton1_clicked() {
    QMessageBox choice_box;
    choice_box.setWindowTitle("添加模具");
    choice_box.setText("请选择您要添加的位置：");
    QPushButton *button1 = choice_box.addButton("仅添加至备件表", QMessageBox::ActionRole);
    QPushButton *button2 = choice_box.addButton("仅添加至模具表", QMessageBox::ActionRole);
    QPushButton *button3 = choice_box.addButton("两者同时添加", QMessageBox::ActionRole);
    choice_box.addButton("取消", QMessageBox::RejectRole);
    choice_box.exec();
    QSqlQuery query;
    if(choice_box.clickedButton() == button1) {
        if(!(ui->MoldEdit->text().isEmpty())) {
            query.prepare("insert into mold_message (模具编号,客户模号,产品名称,产品料号,隶属部门) select :mold_id,:custom_id,:product_name,:product_material,:part where not exists (select 1 from mold_message where 模具编号 = :mold_id and 隶属部门 = :part)");
            query.bindValue(":mold_id", ui->MoldEdit->text());
            query.bindValue(":custom_id", ui->CustomEdit->text());
            query.bindValue(":product_name", ui->ProductEdit->text());
            query.bindValue(":product_material", ui->MaterialEdit->text());
            query.bindValue(":part", m_currentPart);
            if(!query.exec()) {
                QMessageBox::warning(this, "添加模具", "模具数据插入失败：\n" + query.lastError().text(),
                    QMessageBox::Cancel);
                return;
            } else {
                if(query.numRowsAffected()) {
                    QMessageBox::information(this, "添加模具", "模具添加成功", QMessageBox::Ok);
                    QSettings config("userconfig.ini", QSettings::IniFormat);
                    config.setValue("SELECTIONCONFIG/Select1", ui->PartCombo_1->currentText());
                    config.setValue("SELECTIONCONFIG/Select2", ui->MoldEdit->text());
                    config.sync();
                    RefreshData();
                } else {
                    QMessageBox::warning(this, "添加模具", "该模具已存在", QMessageBox::Cancel);
                }
            }
        } else {
            QMessageBox::warning(this, "添加模具", "请输入模具名称", QMessageBox::Cancel);
            return;
        }
    } else if(choice_box.clickedButton() == button2) {
        if(!(ui->MoldEdit->text().isEmpty())) {
            if(m_currentPart == "冲压") {
                query.prepare("insert into chonya_mold (模具编号,产品料号,模具尺寸) select :mold_id,:product_material,:mould where not exists (select 1 from chonya_mold where 模具编号 = :mold_id)");
                query.bindValue(":mold_id", ui->MoldEdit->text());
                query.bindValue(":product_material", ui->MaterialEdit->text());
                query.bindValue(":mould", ui->MouldEdit->text());
                if(!query.exec()) {
                    QMessageBox::warning(this, "添加模具", "模具数据插入失败：\n" + query.lastError().text(),
                        QMessageBox::Cancel);
                    return;
                } else {
                    QMessageBox::information(this, "添加模具", "模具添加成功", QMessageBox::Ok);
                    RefreshData();
                }
            } else {
                query.prepare("insert into chengxing_mold (模具编号,产品料号,模具尺寸) select :mold_id,:product_material,:mould where not exists (select 1 from chonya_mold where 模具编号 = :chengxing_id)");
                query.bindValue(":mold_id", ui->MoldEdit->text());
                query.bindValue(":product_material", ui->MaterialEdit->text());
                query.bindValue(":mould", ui->MouldEdit->text());
                if(!query.exec()) {
                    QMessageBox::warning(this, "添加模具", "模具数据插入失败：\n" + query.lastError().text(),
                        QMessageBox::Cancel);
                    return;
                } else {
                    QMessageBox::information(this, "添加模具", "模具添加成功", QMessageBox::Ok);
                    QSettings config("userconfig.ini", QSettings::IniFormat);
                    config.setValue("SELECTIONCONFIG/Select1", ui->PartCombo_1->currentText());
                    config.setValue("SELECTIONCONFIG/Select2", ui->MoldEdit->text());
                    config.sync();
                    RefreshData();
                }
            }
        } else {
            QMessageBox::warning(this, "添加模具", "请输入模具名称", QMessageBox::Cancel);
            return;
        }
    } else if(choice_box.clickedButton() == button3) {
        if(!(ui->MoldEdit->text().isEmpty())) {
            query.prepare("insert into mold_message (模具编号,客户模号,产品名称,产品料号,隶属部门) select :mold_id,:custom_id,:product_name,:product_material,:part where not exists (select 1 from mold_message where 模具编号 = :mold_id and 隶属部门 = :part)");
            query.bindValue(":mold_id", ui->MoldEdit->text());
            query.bindValue(":custom_id", ui->CustomEdit->text());
            query.bindValue(":product_name", ui->ProductEdit->text());
            query.bindValue(":product_material", ui->MaterialEdit->text());
            query.bindValue(":part", m_currentPart);
            if(!query.exec()) {
                QMessageBox::warning(this, "添加模具", "模具数据插入失败：\n" + query.lastError().text(),
                    QMessageBox::Cancel);
                return;
            } else {
                if(query.numRowsAffected()) {
                    if(m_currentPart == "冲压") {
                        query.prepare("insert into chonya_mold (模具编号,产品料号,模具尺寸) select :mold_id,:product_material,:mould where not exists (select 1 from chonya_mold where 模具编号 = :mold_id)");
                        query.bindValue(":mold_id", ui->MoldEdit->text());
                        query.bindValue(":product_material", ui->MaterialEdit->text());
                        query.bindValue(":mould", ui->MouldEdit->text());
                        if(!query.exec()) {
                            QMessageBox::warning(this, "添加模具", "模具数据插入失败：\n" + query.lastError().text(),
                                QMessageBox::Cancel);
                            return;
                        } else {
                            QMessageBox::information(this, "添加模具", "模具添加成功", QMessageBox::Ok);
                            QSettings config("userconfig.ini", QSettings::IniFormat);
                            config.setValue("SELECTIONCONFIG/Select1", ui->PartCombo_1->currentText());
                            config.setValue("SELECTIONCONFIG/Select2", ui->MoldEdit->text());
                            config.sync();
                            RefreshData();
                        }
                    } else {
                        query.prepare("insert into chengxing_mold (模具编号,产品料号,模具尺寸) select :mold_id,:product_material,:mould where not exists (select 1 from chonya_mold where 模具编号 = :chengxing_id)");
                        query.bindValue(":mold_id", ui->MoldEdit->text());
                        query.bindValue(":product_material", ui->MaterialEdit->text());
                        query.bindValue(":mould", ui->MouldEdit->text());
                        if(!query.exec()) {
                            QMessageBox::warning(this, "添加模具", "模具数据插入失败：\n" + query.lastError().text(),
                                QMessageBox::Cancel);
                            return;
                        } else {
                            QMessageBox::information(this, "添加模具", "模具添加成功", QMessageBox::Ok);
                            QSettings config("userconfig.ini", QSettings::IniFormat);
                            config.setValue("SELECTIONCONFIG/Select1", ui->PartCombo_1->currentText());
                            config.setValue("SELECTIONCONFIG/Select2", ui->MoldEdit->text());
                            config.sync();
                            RefreshData();
                        }
                    }
                } else {
                    QMessageBox::warning(this, "添加模具", "该模具已存在", QMessageBox::Cancel);
                }
            }
        } else {
            QMessageBox::warning(this, "添加模具", "请输入模具名称", QMessageBox::Cancel);
            return;
        }
    }
}

void WarehouseAdd::on_MaterialEdit_returnPressed() {
    QSqlQuery query;
    if(!(ui->MoldEdit->text().isEmpty())) {
        query.prepare("insert into mold_message (模具编号,客户模号,产品名称,产品料号,隶属部门) select :mold_id,:custom_id,:product_name,:product_material,:part where not exists (select 1 from mold_message where 模具编号 = :mold_id and 隶属部门 = :part)");
        query.bindValue(":mold_id", ui->MoldEdit->text());
        query.bindValue(":custom_id", ui->CustomEdit->text());
        query.bindValue(":product_name", ui->ProductEdit->text());
        query.bindValue(":product_material", ui->MaterialEdit->text());
        query.bindValue(":part", m_currentPart);
        if(!query.exec()) {
            QMessageBox::warning(this, "添加模具", "模具数据插入失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        } else {
            if(query.numRowsAffected()) {
                if(m_currentPart == "冲压") {
                    query.prepare("insert into chonya_mold (模具编号,产品料号,模具尺寸) select :mold_id,:product_material,:mould where not exists (select 1 from chonya_mold where 模具编号 = :mold_id)");
                    query.bindValue(":mold_id", ui->MoldEdit->text());
                    query.bindValue(":product_material", ui->MaterialEdit->text());
                    query.bindValue(":mould", ui->MouldEdit->text());
                    if(!query.exec()) {
                        QMessageBox::warning(this, "添加模具", "模具数据插入失败：\n" + query.lastError().text(),
                            QMessageBox::Cancel);
                        return;
                    } else {
                        QMessageBox::information(this, "添加模具", "模具添加成功", QMessageBox::Ok);
                        QSettings config("userconfig.ini", QSettings::IniFormat);
                        config.setValue("SELECTIONCONFIG/Select1", ui->PartCombo_1->currentText());
                        config.setValue("SELECTIONCONFIG/Select2", ui->MoldEdit->text());
                        config.sync();
                        RefreshData();
                    }
                } else {
                    query.prepare("insert into chengxing_mold (模具编号,产品料号,模具尺寸) select :mold_id,:product_material,:mould where not exists (select 1 from chonya_mold where 模具编号 = :chengxing_id)");
                    query.bindValue(":mold_id", ui->MoldEdit->text());
                    query.bindValue(":product_material", ui->MaterialEdit->text());
                    query.bindValue(":mould", ui->MouldEdit->text());
                    if(!query.exec()) {
                        QMessageBox::warning(this, "添加模具", "模具数据插入失败：\n" + query.lastError().text(),
                            QMessageBox::Cancel);
                        return;
                    } else {
                        QMessageBox::information(this, "添加模具", "模具添加成功", QMessageBox::Ok);
                        QSettings config("userconfig.ini", QSettings::IniFormat);
                        config.setValue("SELECTIONCONFIG/Select1", ui->PartCombo_1->currentText());
                        config.setValue("SELECTIONCONFIG/Select2", ui->MoldEdit->text());
                        config.sync();
                        RefreshData();
                    }
                }
            } else {
                QMessageBox::warning(this, "添加模具", "该模具已存在", QMessageBox::Cancel);
                return;
            }
        }
    } else {
        QMessageBox::warning(this, "添加模具", "请输入模具名称", QMessageBox::Cancel);
        return;
    }
}

void WarehouseAdd::on_AddButton2_clicked() {
    QString pid;
    QString sql;
    QSqlQuery query;
    if(ui->SpareEdit->text().isEmpty()) {
        QMessageBox::warning(this, "添加备件", "请输入备件号", QMessageBox::Cancel);
        return;
    } else {
        sql = QString("select PID from mold_message where 模具编号 = '%1'").arg(ui->MoldCombo->currentText());
        if(!query.exec(sql)) {
            QMessageBox::warning(this, "添加备件", "模具PID查询失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        } else {
            if(query.next()) {
                pid = query.value(0).toString();
            }
        }
        if(m_currentPart == "冲压") {
            sql = "insert into chonya_message (PID,模具编号,备件号,状态,安全库存,期初库存,总库存量,备件价格,累计入库,累计出库,存放柜号,备注) select :pid,:mold_id,:spare_id,'入库：0    出库：0',:save_num,'0','0',:price_num,'0','0',:cabinet,:other where not exists (select 1 from chonya_message where 模具编号 = :mold_id and 备件号 = :spare_id and 存放柜号 = :cabinet)";
        } else if(m_currentPart == "成型") {
            sql = "insert into chengxing_message (PID,模具编号,备件号,状态,安全库存,期初库存,总库存量,备件价格,累计入库,累计出库,存放柜号,备注) select :pid,:mold_id,:spare_id,'入库：0    出库：0',:save_num,'0','0',:price_num,'0','0',:cabinet,:other where not exists (select 1 from chengxing_message where 模具编号 = :mold_id and 备件号 = :spare_id and 存放柜号 = :cabinet)";
        }
        query.prepare(sql);
        query.bindValue(":pid", pid);
        query.bindValue(":mold_id", ui->MoldCombo->currentText());
        query.bindValue(":spare_id", ui->SpareEdit->text());
        if(ui->SaveEdit->text().toInt()) {
            query.bindValue(":save_num", ui->SaveEdit->text());
        } else {
            query.bindValue(":save_num", "0");
        }
        query.bindValue(":price_num", ui->PriceEdit->text());
        query.bindValue(":cabinet", ui->CabinetCombo->currentText());
        query.bindValue(":other", ui->OtherEdit->text());
        if(!query.exec()) {
            QMessageBox::warning(this, "添加备件", "备件数据插入失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        } else {
            if(query.numRowsAffected()) {
                if(ui->SaveEdit->text().toInt()) {
                    query.prepare("insert into information_message (日期,模具编号,备件号,发送用户,接收用户,完成情况,信息) select :date, :mold_id, :spare_id, :tuser, :ruser, :finished, :information where not exists (select 1 from information_message where 模具编号 = :mold_id and 备件号 = :spare_id and 接收用户 = :ruser)");
                    QDateTime dateTime = QDateTime::currentDateTime();
                    query.bindValue(":date", dateTime.toString("yyyy-MM-dd hh:mm:ss"));
                    query.bindValue(":mold_id", ui->MoldCombo->currentText());
                    query.bindValue(":spare_id", ui->SpareEdit->text());
                    query.bindValue(":tuser", "系统");
                    query.bindValue(":ruser", "所有人");
                    query.bindValue(":finished", "1");
                    if(m_currentPart == "冲压") {
                        query.bindValue(":information", "备件不足" + ui->SaveEdit->text() + "个，需要补货（冲压）。");
                    } else {
                        query.bindValue(":information", "备件不足" + ui->SaveEdit->text() + "个，需要补货（成型）。");
                    }
                    if(!query.exec()) {
                        QMessageBox::warning(this, "添加备件", "补货信息列表数据插入失败：\n" + query.lastError().text(),
                            QMessageBox::Cancel);
                        return;
                    }
                    QMessageBox::information(this, "添加备件", "备件添加成功", QMessageBox::Ok);
                    ui->FMoldEdit->setText(ui->MoldCombo->currentText());
                    QSettings config("userconfig.ini", QSettings::IniFormat);
                    config.setValue("SELECTIONCONFIG/Select1", ui->PartCombo_1->currentText());
                    config.setValue("SELECTIONCONFIG/Select2", ui->MoldCombo->currentText());
                    config.setValue("SELECTIONCONFIG/Select3", ui->CabinetCombo->currentText());
                    config.setValue("SELECTIONCONFIG/Mold", ui->MoldCombo->currentText());
                    config.setValue("SELECTIONCONFIG/Spare", ui->SpareEdit->text());
                    config.sync();
                    RefreshData();
                    emit mysignal();
                } else {
                    QMessageBox::information(this, "添加备件", "备件添加成功", QMessageBox::Ok);
                    ui->FMoldEdit->setText(ui->MoldCombo->currentText());
                    QSettings config("userconfig.ini", QSettings::IniFormat);
                    config.setValue("SELECTIONCONFIG/Select1", ui->PartCombo_1->currentText());
                    config.setValue("SELECTIONCONFIG/Select2", ui->MoldCombo->currentText());
                    config.setValue("SELECTIONCONFIG/Select3", ui->CabinetCombo->currentText());
                    config.setValue("SELECTIONCONFIG/Mold", ui->MoldCombo->currentText());
                    config.setValue("SELECTIONCONFIG/Spare", ui->SpareEdit->text());
                    RefreshData();
                    emit mysignal();
                }
            } else {
                QMessageBox::warning(this, "添加备件", "该备件已存在", QMessageBox::Cancel);
                return;
            }
        }
    }
}

void WarehouseAdd::on_SpareEdit_returnPressed() {
    QString pid;
    QString sql;
    QSqlQuery query;
    if(ui->SpareEdit->text().isEmpty()) {
        QMessageBox::warning(this, "添加备件", "请输入备件号", QMessageBox::Cancel);
        return;
    } else {
        sql = QString("select PID from mold_message where 模具编号 = '%1'").arg(ui->MoldCombo->currentText());
        if(!query.exec(sql)) {
            QMessageBox::warning(this, "添加备件", "模具PID查询失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        } else {
            if(query.next()) {
                pid = query.value(0).toString();
            }
        }
        if(m_currentPart == "冲压") {
            sql = "insert into chonya_message (PID,模具编号,备件号,状态,安全库存,期初库存,总库存量,备件价格,累计入库,累计出库,存放柜号,备注) select :pid,:mold_id,:spare_id,'入库：0    出库：0',:save_num,'0','0',:price_num,'0','0',:cabinet,:other where not exists (select 1 from chonya_message where 模具编号 = :mold_id and 备件号 = :spare_id and 存放柜号 = :cabinet)";
        } else if(m_currentPart == "成型") {
            sql = "insert into chengxing_message (PID,模具编号,备件号,状态,安全库存,期初库存,总库存量,备件价格,累计入库,累计出库,存放柜号,备注) select :pid,:mold_id,:spare_id,'入库：0    出库：0',:save_num,'0','0',:price_num,'0','0',:cabinet,:other where not exists (select 1 from chengxing_message where 模具编号 = :mold_id and 备件号 = :spare_id and 存放柜号 = :cabinet)";
        }
        query.prepare(sql);
        query.bindValue(":pid", pid);
        query.bindValue(":mold_id", ui->MoldCombo->currentText());
        query.bindValue(":spare_id", ui->SpareEdit->text());
        if(ui->SaveEdit->text().toInt()) {
            query.bindValue(":save_num", ui->SaveEdit->text());
        } else {
            query.bindValue(":save_num", "0");
        }
        query.bindValue(":price_num", ui->PriceEdit->text());
        query.bindValue(":cabinet", ui->CabinetCombo->currentText());
        query.bindValue(":other", ui->OtherEdit->text());
        if(!query.exec()) {
            QMessageBox::warning(this, "添加备件", "备件数据插入失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        } else {
            if(query.numRowsAffected()) {
                if(ui->SaveEdit->text().toInt()) {
                    query.prepare("insert into information_message (日期,模具编号,备件号,发送用户,接收用户,完成情况,信息) select :date, :mold_id, :spare_id, :tuser, :ruser, :finished, :information where not exists (select 1 from information_message where 模具编号 = :mold_id and 备件号 = :spare_id and 接收用户 = :ruser)");
                    QDateTime dateTime = QDateTime::currentDateTime();
                    query.bindValue(":date", dateTime.toString("yyyy-MM-dd hh:mm:ss"));
                    query.bindValue(":mold_id", ui->MoldCombo->currentText());
                    query.bindValue(":spare_id", ui->SpareEdit->text());
                    query.bindValue(":tuser", "系统");
                    query.bindValue(":ruser", "所有人");
                    query.bindValue(":finished", "1");
                    if(m_currentPart == "冲压") {
                        query.bindValue(":information", "备件不足" + ui->SaveEdit->text() + "个，需要补货（冲压）。");
                    } else {
                        query.bindValue(":information", "备件不足" + ui->SaveEdit->text() + "个，需要补货（成型）。");
                    }
                    if(!query.exec()) {
                        QMessageBox::warning(this, "添加备件", "补货信息列表数据插入失败：\n" + query.lastError().text(),
                            QMessageBox::Cancel);
                        return;
                    }
                    QMessageBox::information(this, "添加备件", "备件添加成功", QMessageBox::Ok);
                    ui->FMoldEdit->setText(ui->MoldCombo->currentText());
                    QSettings config("userconfig.ini", QSettings::IniFormat);
                    config.setValue("SELECTIONCONFIG/Select1", ui->PartCombo_1->currentText());
                    config.setValue("SELECTIONCONFIG/Select2", ui->MoldCombo->currentText());
                    config.setValue("SELECTIONCONFIG/Select3", ui->CabinetCombo->currentText());
                    config.setValue("SELECTIONCONFIG/Mold", ui->MoldCombo->currentText());
                    config.setValue("SELECTIONCONFIG/Spare", ui->SpareEdit->text());
                    config.sync();
                    RefreshData();
                    emit mysignal();
                } else {
                    QMessageBox::information(this, "添加备件", "备件添加成功", QMessageBox::Ok);
                    ui->FMoldEdit->setText(ui->MoldCombo->currentText());
                    QSettings config("userconfig.ini", QSettings::IniFormat);
                    config.setValue("SELECTIONCONFIG/Select1", ui->PartCombo_1->currentText());
                    config.setValue("SELECTIONCONFIG/Select2", ui->MoldCombo->currentText());
                    config.setValue("SELECTIONCONFIG/Select3", ui->CabinetCombo->currentText());
                    config.setValue("SELECTIONCONFIG/Mold", ui->MoldCombo->currentText());
                    config.setValue("SELECTIONCONFIG/Spare", ui->SpareEdit->text());
                    RefreshData();
                    emit mysignal();
                }
            } else {
                QMessageBox::warning(this, "添加备件", "该备件已存在", QMessageBox::Cancel);
                return;
            }
        }
    }
}

void WarehouseAdd::on_NameView_clicked(const QModelIndex &index) {
    ui->Label1->setStyleSheet("color:black;");
    QModelIndex firstColIndex = index.sibling(index.row(), 0);
    if(!m_model->data(firstColIndex, Qt::DisplayRole).toString().contains("类")) {
        m_currentSpare = m_model->data(firstColIndex, Qt::DisplayRole).toString();
        QModelIndex parentIndex = index.parent();
        QString parent_data = parentIndex.data().toString();
        int pos = parent_data.indexOf("(");
        m_currentMold = parent_data.left(pos);
        int sameCount = 0;
        int position = 0;
        int totalChildren = m_model->rowCount(parentIndex);
        for(int row = 0; row < totalChildren; ++row) {
            QModelIndex childIndex = m_model->index(row, 0, parentIndex);
            QString childText = childIndex.data().toString();
            if(childText == m_currentSpare) {
                sameCount++;
                if(childIndex.row() == index.row()) {
                    position = sameCount - 1;
                }
            }
        }
        ui->FMoldEdit->setText(m_currentMold);
        ui->FSpareEdit->setText(m_currentSpare);
        QSqlQuery query;
        if(m_currentPart == "冲压") {
            query.prepare(
                QString("select * from chonya_message where 模具编号 = :mold and 备件号 = :spare order by id asc limit 1 offset %1").arg(
                position));
        } else if(m_currentPart == "成型") {
            query.prepare(
                QString("select * from chengxing_message where 模具编号 = :mold and 备件号 = :spare order by id asc limit 1 offset %1").arg(
                position));
        }
        query.bindValue(":mold", m_currentMold);
        query.bindValue(":spare", m_currentSpare);
        if(!query.exec()) {
            QMessageBox::warning(this, "查询备件数据", "备件数据查询失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        } else {
            if(query.next()) {
                QString MoldCount = query.value("总库存量").toString();
                ui->SpareNum->setText(MoldCount);
                ui->CabinetEdit->setText(query.value("存放柜号").toString());
                QSettings config("userconfig.ini", QSettings::IniFormat);
                config.setValue("SELECTIONCONFIG/Select1", ui->PartCombo_1->currentText());
                config.setValue("SELECTIONCONFIG/Select2", m_currentMold);
                config.setValue("SELECTIONCONFIG/Select3", ui->CabinetCombo->currentText());
                config.setValue("SELECTIONCONFIG/Mold", m_currentMold);
                config.setValue("SELECTIONCONFIG/Spare", m_currentSpare);
                config.sync();
            }
        }
    } else {
        QString mold_data = m_model->data(firstColIndex, Qt::DisplayRole).toString();
        int pos = mold_data.indexOf("(");
        m_currentMold = mold_data.left(pos);
        ui->FMoldEdit->setText(m_currentMold);
        m_currentSpare = "";
        ui->SpareNum->setText("");
        ui->FSpareEdit->setText(m_currentSpare);
    }
}

void WarehouseAdd::on_FindButton_clicked() {
    QString sql;
    QSqlQuery query;
    QMap<QString, int> moldCountMap;
    QString countSql;
    if(m_currentPart == "冲压") {
        countSql =
            "SELECT 模具编号, COUNT(*) FROM chonya_message WHERE 模具编号 LIKE :mold_id AND 备件号 LIKE :spare_id GROUP BY 模具编号";
    } else if(m_currentPart == "成型") {
        countSql =
            "SELECT 模具编号, COUNT(*) FROM chengxing_message WHERE 模具编号 LIKE :mold_id AND 备件号 LIKE :spare_id GROUP BY 模具编号";
    }
    query.prepare(countSql);
    query.bindValue(":mold_id", "%" + ui->FMoldEdit->text() + "%");
    query.bindValue(":spare_id", "%" + ui->FSpareEdit->text() + "%");
    if(!query.exec()) {
        QMessageBox::warning(this, "查找备件", "备件数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        while(query.next()) {
            QString moldId = query.value(0).toString();
            int count = query.value(1).toInt();
            moldCountMap[moldId] = count;
        }
    }
    m_model = new QStandardItemModel(this);
    ui->NameView->setModel(m_model);
    m_model->setHorizontalHeaderLabels({"备件号", "安全库存"});
    if(m_currentPart == "冲压") {
        sql = QString("select 模具编号,备件号,安全库存,总库存量 from chonya_message where 模具编号 like '%%1%' and 备件号 like '%%2%'").arg(
            ui->FMoldEdit->text()).arg(ui->FSpareEdit->text());
    } else if(m_currentPart == "成型") {
        sql = QString("select 模具编号,备件号,安全库存,总库存量 from chengxing_message where 模具编号 like '%%1%' and 备件号 like '%%2%'").arg(
            ui->FMoldEdit->text()).arg(ui->FSpareEdit->text());
    }
    QMap<QString, QStandardItem *> topItems;
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "查找备件", "备件数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        while(query.next()) {
            QString moldId = query.value(0).toString();
            int count = moldCountMap.value(moldId, 0);
            QString table = QString(moldId + "(%1类)").arg(count);
            QStandardItem *topItem = topItems.value(table, nullptr);
            if(!topItem) {
                topItem = new QStandardItem(table);
                topItems[table] = topItem;
                m_model->appendRow(topItem);
            }
            QStandardItem *item1 = new QStandardItem(query.value(1).toString());
            item1->setTextAlignment(Qt::AlignCenter);
            QStandardItem *item2;
            if(query.value(2).toInt()) {
                item2 = new QStandardItem(query.value(2).toString());
            } else {
                item2 = new QStandardItem("未设置");
            }
            item2->setTextAlignment(Qt::AlignCenter);
            topItem->appendRow({item1, item2});
            if(query.value(2).toInt() > query.value(3).toInt() && query.value(2).toInt()) {
                item1->setBackground(QBrush(Qt::red));
                item2->setBackground(QBrush(Qt::red));
            }
        }
    }
    ui->NameView->header()->resizeSection(0, 200);
    ui->NameView->header()->stretchLastSection();
    ui->NameView->header()->setMinimumSectionSize(50);
    QFont font = ui->NameView->header()->font();
    font.setPointSize(12);
    ui->NameView->header()->setFont(font);
    ui->NameView->expandAll();
    ui->CabinetEdit->clear();
    ui->Label1->setStyleSheet("color:red;");
}

void WarehouseAdd::on_FMoldEdit_returnPressed() {
    QString sql;
    QSqlQuery query;
    QMap<QString, int> moldCountMap;
    QString countSql;
    if(m_currentPart == "冲压") {
        countSql = "SELECT 模具编号, COUNT(*) FROM chonya_message WHERE 模具编号 LIKE :mold_id GROUP BY 模具编号";
    } else if(m_currentPart == "成型") {
        countSql =
            "SELECT 模具编号, COUNT(*) FROM chengxing_message WHERE 模具编号 LIKE :mold_id GROUP BY 模具编号";
    }
    query.prepare(countSql);
    query.bindValue(":mold_id", "%" + ui->FMoldEdit->text() + "%");
    if(!query.exec()) {
        QMessageBox::warning(this, "查找模具", "模具数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        while(query.next()) {
            QString moldId = query.value(0).toString();
            int count = query.value(1).toInt();
            moldCountMap[moldId] = count;
        }
    }
    m_model = new QStandardItemModel(this);
    ui->NameView->setModel(m_model);
    m_model->setHorizontalHeaderLabels({"备件号", "安全库存"});
    if(m_currentPart == "冲压") {
        sql = QString("select 模具编号,备件号,安全库存,总库存量 from chonya_message where 模具编号 like '%%1%'").arg(
            ui->FMoldEdit->text());
    } else if(m_currentPart == "成型") {
        sql = QString("select 模具编号,备件号,安全库存,总库存量 from chengxing_message where 模具编号 like '%%1%'").arg(
            ui->FMoldEdit->text());
    }
    QMap<QString, QStandardItem *> topItems;
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "查找模具", "模具数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        while(query.next()) {
            QString moldId = query.value(0).toString();
            int count = moldCountMap.value(moldId, 0);
            QString table = QString(moldId + "(%1类)").arg(count);
            QStandardItem *topItem = topItems.value(table, nullptr);
            if(!topItem) {
                topItem = new QStandardItem(table);
                topItems[table] = topItem;
                m_model->appendRow(topItem);
            }
            QStandardItem *item1 = new QStandardItem(query.value(1).toString());
            item1->setTextAlignment(Qt::AlignCenter);
            QStandardItem *item2;
            if(query.value(2).toInt()) {
                item2 = new QStandardItem(query.value(2).toString());
            } else {
                item2 = new QStandardItem("未设置");
            }
            item2->setTextAlignment(Qt::AlignCenter);
            topItem->appendRow({item1, item2});
            if(query.value(2).toInt() > query.value(3).toInt() && query.value(2).toInt()) {
                item1->setBackground(QBrush(Qt::red));
                item2->setBackground(QBrush(Qt::red));
            }
        }
    }
    ui->NameView->header()->resizeSection(0, 200);
    ui->NameView->header()->stretchLastSection();
    ui->NameView->header()->setMinimumSectionSize(50);
    QFont font = ui->NameView->header()->font();
    font.setPointSize(12);
    ui->NameView->header()->setFont(font);
    ui->NameView->expandAll();
    m_currentSpare = "";
    ui->CabinetEdit->clear();
    ui->FSpareEdit->clear();
    ui->Label1->setStyleSheet("color:red;");
}

void WarehouseAdd::on_FMoldEdit_textChanged(const QString &arg1) {
    if(arg1.isEmpty()) {
        QString sql;
        QSqlQuery query;
        QMap<QString, int> moldCountMap;
        QString countSql;
        if(m_currentPart == "冲压") {
            countSql = "SELECT 模具编号, COUNT(*) FROM chonya_message WHERE 模具编号 LIKE :mold_id GROUP BY 模具编号";
        } else if(m_currentPart == "成型") {
            countSql =
                "SELECT 模具编号, COUNT(*) FROM chengxing_message WHERE 模具编号 LIKE :mold_id GROUP BY 模具编号";
        }
        query.prepare(countSql);
        query.bindValue(":mold_id", "%" + ui->FMoldEdit->text() + "%");
        if(!query.exec()) {
            QMessageBox::warning(this, "查找模具", "模具数据查询失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        } else {
            while(query.next()) {
                QString moldId = query.value(0).toString();
                int count = query.value(1).toInt();
                moldCountMap[moldId] = count;
            }
        }
        m_model = new QStandardItemModel(this);
        ui->NameView->setModel(m_model);
        m_model->setHorizontalHeaderLabels({"备件号", "安全库存"});
        if(m_currentPart == "冲压") {
            sql = QString("select 模具编号,备件号,安全库存,总库存量 from chonya_message where 模具编号 like '%%1%'").arg(
                ui->FMoldEdit->text());
        } else if(m_currentPart == "成型") {
            sql = QString("select 模具编号,备件号,安全库存,总库存量 from chengxing_message where 模具编号 like '%%1%'").arg(
                ui->FMoldEdit->text());
        }
        QMap<QString, QStandardItem *> topItems;
        if(!query.exec(sql)) {
            QMessageBox::warning(this, "查找模具", "模具数据查询失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        } else {
            while(query.next()) {
                QString moldId = query.value(0).toString();
                int count = moldCountMap.value(moldId, 0);
                QString table = QString(moldId + "(%1类)").arg(count);
                QStandardItem *topItem = topItems.value(table, nullptr);
                if(!topItem) {
                    topItem = new QStandardItem(table);
                    topItems[table] = topItem;
                    m_model->appendRow(topItem);
                }
                QStandardItem *item1 = new QStandardItem(query.value(1).toString());
                item1->setTextAlignment(Qt::AlignCenter);
                QStandardItem *item2;
                if(query.value(2).toInt()) {
                    item2 = new QStandardItem(query.value(2).toString());
                } else {
                    item2 = new QStandardItem("未设置");
                }
                item2->setTextAlignment(Qt::AlignCenter);
                topItem->appendRow({item1, item2});
                if(query.value(2).toInt() > query.value(3).toInt() && query.value(2).toInt()) {
                    item1->setBackground(QBrush(Qt::red));
                    item2->setBackground(QBrush(Qt::red));
                }
            }
        }
        ui->NameView->header()->resizeSection(0, 200);
        ui->NameView->header()->stretchLastSection();
        ui->NameView->header()->setMinimumSectionSize(50);
        QFont font = ui->NameView->header()->font();
        font.setPointSize(12);
        ui->NameView->header()->setFont(font);
        ui->NameView->expandAll();
        m_currentSpare = "";
        ui->CabinetEdit->clear();
        ui->FSpareEdit->clear();
        ui->Label1->setStyleSheet("color:red;");
    }
    ui->FSpareEdit->clear();
}

void WarehouseAdd::on_FSpareEdit_returnPressed() {
    QString sql;
    QSqlQuery query;
    QMap<QString, int> moldCountMap;
    QString countSql;
    if(m_currentPart == "冲压") {
        countSql =
            "SELECT 模具编号, COUNT(*) FROM chonya_message WHERE 模具编号 LIKE :mold_id AND 备件号 LIKE :spare_id GROUP BY 模具编号";
    } else if(m_currentPart == "成型") {
        countSql =
            "SELECT 模具编号, COUNT(*) FROM chengxing_message WHERE 模具编号 LIKE :mold_id AND 备件号 LIKE :spare_id GROUP BY 模具编号";
    }
    query.prepare(countSql);
    query.bindValue(":mold_id", "%" + ui->FMoldEdit->text() + "%");
    query.bindValue(":spare_id", "%" + ui->FSpareEdit->text() + "%");
    if(!query.exec()) {
        QMessageBox::warning(this, "查找备件", "备件数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        while(query.next()) {
            QString moldId = query.value(0).toString();
            int count = query.value(1).toInt();
            moldCountMap[moldId] = count;
        }
    }
    m_model = new QStandardItemModel(this);
    ui->NameView->setModel(m_model);
    m_model->setHorizontalHeaderLabels({"备件号", "安全库存"});
    if(m_currentPart == "冲压") {
        sql = QString("select 模具编号,备件号,安全库存,总库存量 from chonya_message where 模具编号 like '%%1%' and 备件号 like '%%2%'").arg(
            ui->FMoldEdit->text()).arg(ui->FSpareEdit->text());
    } else if(m_currentPart == "成型") {
        sql = QString("select 模具编号,备件号,安全库存,总库存量 from chengxing_message where 模具编号 like '%%1%' and 备件号 like '%%2%'").arg(
            ui->FMoldEdit->text()).arg(ui->FSpareEdit->text());
    }
    QMap<QString, QStandardItem *> topItems;
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "查找备件", "备件数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        while(query.next()) {
            QString moldId = query.value(0).toString();
            int count = moldCountMap.value(moldId, 0);
            QString table = QString(moldId + "(%1类)").arg(count);
            QStandardItem *topItem = topItems.value(table, nullptr);
            if(!topItem) {
                topItem = new QStandardItem(table);
                topItems[table] = topItem;
                m_model->appendRow(topItem);
            }
            QStandardItem *item1 = new QStandardItem(query.value(1).toString());
            item1->setTextAlignment(Qt::AlignCenter);
            QStandardItem *item2;
            if(query.value(2).toInt()) {
                item2 = new QStandardItem(query.value(2).toString());
            } else {
                item2 = new QStandardItem("未设置");
            }
            item2->setTextAlignment(Qt::AlignCenter);
            topItem->appendRow({item1, item2});
            if(query.value(2).toInt() > query.value(3).toInt() && query.value(2).toInt()) {
                item1->setBackground(QBrush(Qt::red));
                item2->setBackground(QBrush(Qt::red));
            }
        }
    }
    ui->NameView->header()->resizeSection(0, 200);
    ui->NameView->header()->stretchLastSection();
    ui->NameView->header()->setMinimumSectionSize(50);
    QFont font = ui->NameView->header()->font();
    font.setPointSize(12);
    ui->NameView->header()->setFont(font);
    ui->NameView->expandAll();
    ui->CabinetEdit->clear();
    ui->Label1->setStyleSheet("color:red;");
}

void WarehouseAdd::on_AddButton3_clicked() {
    if(m_currentSpare.isEmpty()) {
        QMessageBox::warning(this, "添加备件", "请选择备件", QMessageBox::Cancel);
        return;
    }
    if(!ui->NumEdit->text().toInt()) {
        QMessageBox::warning(this, "添加备件", "请输入添加数量", QMessageBox::Cancel);
        return;
    }
    QString sql;
    QSqlQuery query;
    int save_num = 0, first_num = 0, total_num = 0;
    QString cabinet_get = ui->CabinetEdit->text();
    if(m_currentPart == "冲压") {
        sql = QString("select 安全库存,期初库存,总库存量 from chonya_message where 模具编号 = '%1' and 备件号 = '%2' and 存放柜号 = '%3';").arg(
            m_currentMold).arg(m_currentSpare).arg(cabinet_get);
    } else if(m_currentPart == "成型") {
        sql = QString("select 安全库存,期初库存,总库存量 from chengxing_message where 模具编号 = '%1' and 备件号 = '%2' and 存放柜号 = '%3';").arg(
            m_currentMold).arg(m_currentSpare).arg(cabinet_get);
    }
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "添加备件", "备件数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        if(query.next()) {
            save_num = query.value(0).toInt();
            first_num = query.value(1).toInt();
            total_num = query.value(2).toInt();
        }
    }
    if(m_currentPart == "冲压") {
        sql = "update chonya_message set 期初库存 = :first_num,总库存量 = :total_num where 模具编号 = :mold_id and 备件号 = :spare_id and 存放柜号 = :cabinet;";
    } else if(m_currentPart == "成型") {
        sql = "update chengxing_message set 期初库存 = :first_num,总库存量 = :total_num where 模具编号 = :mold_id and 备件号 = :spare_id and 存放柜号 = :cabinet;";
    }
    query.prepare(sql);
    query.bindValue(":first_num", first_num + ui->NumEdit->text().toInt());
    query.bindValue(":total_num", total_num + ui->NumEdit->text().toInt());
    query.bindValue(":cabinet", cabinet_get);
    query.bindValue(":mold_id", m_currentMold);
    query.bindValue(":spare_id", m_currentSpare);
    if(!query.exec()) {
        QMessageBox::warning(this, "添加备件", "备件数据更新失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        if(save_num <= total_num + ui->NumEdit->text().toInt()) {
            sql = "delete from information_message where 模具编号 = :mold_id and 备件号 = :spare_id";
            query.prepare(sql);
            query.bindValue(":mold_id", m_currentMold);
            query.bindValue(":spare_id", m_currentSpare);
            if(!query.exec()) {
                QMessageBox::warning(this, "添加备件", "补货信息列表数据删除失败：\n" + query.lastError().text(),
                    QMessageBox::Cancel);
                return;
            } else {
                QMessageBox::information(this, "添加备件", "备件添加成功", QMessageBox::Ok);
                ui->SpareNum->setText(QString("%1").arg(total_num + ui->NumEdit->text().toInt()));
                QSettings config("userconfig.ini", QSettings::IniFormat);
                config.setValue("SELECTIONCONFIG/Select1", ui->PartCombo_1->currentText());
                config.setValue("SELECTIONCONFIG/Select2", m_currentMold);
                config.setValue("SELECTIONCONFIG/Select3", ui->CabinetCombo->currentText());
                config.setValue("SELECTIONCONFIG/Mold", m_currentMold);
                config.setValue("SELECTIONCONFIG/Spare", m_currentSpare);
                config.sync();
                RefreshData();
                emit mysignal();
            }
        } else {
            QMessageBox::information(this, "添加备件", "备件添加成功", QMessageBox::Ok);
            ui->SpareNum->setText(QString("%1").arg(total_num + ui->NumEdit->text().toInt()));
            QSettings config("userconfig.ini", QSettings::IniFormat);
            config.setValue("SELECTIONCONFIG/Select1", ui->PartCombo_1->currentText());
            config.setValue("SELECTIONCONFIG/Select2", m_currentMold);
            config.setValue("SELECTIONCONFIG/Select3", ui->CabinetCombo->currentText());
            config.setValue("SELECTIONCONFIG/Mold", m_currentMold);
            config.setValue("SELECTIONCONFIG/Spare", m_currentSpare);
            config.sync();
            RefreshData();
            emit mysignal();
        }
    }
}

void WarehouseAdd::on_NumEdit_returnPressed() {
    if(m_currentSpare.isEmpty()) {
        QMessageBox::warning(this, "添加备件", "请选择备件", QMessageBox::Cancel);
        return;
    }
    if(!ui->NumEdit->text().toInt()) {
        QMessageBox::warning(this, "添加备件", "请输入添加数量", QMessageBox::Cancel);
        return;
    }
    QString sql;
    QSqlQuery query;
    int save_num = 0, first_num = 0, total_num = 0;
    QString cabinet_get = ui->CabinetEdit->text();
    if(m_currentPart == "冲压") {
        sql = QString("select 安全库存,期初库存,总库存量 from chonya_message where 模具编号 = '%1' and 备件号 = '%2' and 存放柜号 = '%3';").arg(
            m_currentMold).arg(m_currentSpare).arg(cabinet_get);
    } else if(m_currentPart == "成型") {
        sql = QString("select 安全库存,期初库存,总库存量 from chengxing_message where 模具编号 = '%1' and 备件号 = '%2' and 存放柜号 = '%3';").arg(
            m_currentMold).arg(m_currentSpare).arg(cabinet_get);
    }
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "添加备件", "备件数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        if(query.next()) {
            save_num = query.value(0).toInt();
            first_num = query.value(1).toInt();
            total_num = query.value(2).toInt();
        }
    }
    if(m_currentPart == "冲压") {
        sql = "update chonya_message set 期初库存 = :first_num,总库存量 = :total_num where 模具编号 = :mold_id and 备件号 = :spare_id and 存放柜号 = :cabinet;";
    } else if(m_currentPart == "成型") {
        sql = "update chengxing_message set 期初库存 = :first_num,总库存量 = :total_num where 模具编号 = :mold_id and 备件号 = :spare_id and 存放柜号 = :cabinet;";
    }
    query.prepare(sql);
    query.bindValue(":first_num", first_num + ui->NumEdit->text().toInt());
    query.bindValue(":total_num", total_num + ui->NumEdit->text().toInt());
    query.bindValue(":cabinet", cabinet_get);
    query.bindValue(":mold_id", m_currentMold);
    query.bindValue(":spare_id", m_currentSpare);
    if(!query.exec()) {
        QMessageBox::warning(this, "添加备件", "备件数据更新失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        if(save_num <= total_num + ui->NumEdit->text().toInt()) {
            sql = "delete from information_message where 模具编号 = :mold_id and 备件号 = :spare_id";
            query.prepare(sql);
            query.bindValue(":mold_id", m_currentMold);
            query.bindValue(":spare_id", m_currentSpare);
            if(!query.exec()) {
                QMessageBox::warning(this, "添加备件", "补货信息列表数据删除失败：\n" + query.lastError().text(),
                    QMessageBox::Cancel);
                return;
            } else {
                QMessageBox::information(this, "添加备件", "备件添加成功", QMessageBox::Ok);
                ui->SpareNum->setText(QString("%1").arg(total_num + ui->NumEdit->text().toInt()));
                QSettings config("userconfig.ini", QSettings::IniFormat);
                config.setValue("SELECTIONCONFIG/Select1", ui->PartCombo_1->currentText());
                config.setValue("SELECTIONCONFIG/Select2", m_currentMold);
                config.setValue("SELECTIONCONFIG/Select3", ui->CabinetCombo->currentText());
                config.setValue("SELECTIONCONFIG/Mold", m_currentMold);
                config.setValue("SELECTIONCONFIG/Spare", m_currentSpare);
                config.sync();
                RefreshData();
                emit mysignal();
            }
        } else {
            QMessageBox::information(this, "添加备件", "备件添加成功", QMessageBox::Ok);
            ui->SpareNum->setText(QString("%1").arg(total_num + ui->NumEdit->text().toInt()));
            QSettings config("userconfig.ini", QSettings::IniFormat);
            config.setValue("SELECTIONCONFIG/Select1", ui->PartCombo_1->currentText());
            config.setValue("SELECTIONCONFIG/Select2", m_currentMold);
            config.setValue("SELECTIONCONFIG/Select3", ui->CabinetCombo->currentText());
            config.setValue("SELECTIONCONFIG/Mold", m_currentMold);
            config.setValue("SELECTIONCONFIG/Spare", m_currentSpare);
            config.sync();
            RefreshData();
            emit mysignal();
        }
    }
}

void WarehouseAdd::on_ReturnButton_clicked() {
    this->close();
}

void WarehouseAdd::on_ToAddButton_clicked() {
    m_warehouseDele = new WarehouseDele(this);
    connect(m_warehouseDele, SIGNAL(mysignal()), this, SLOT(RefreshData()));
    m_warehouseDele->setWindowTitle("模具&货柜管理");
    m_windowMap.insert(tr("模具&货柜管理"), m_warehouseDele);
    m_warehouseDele->show();
}

void WarehouseAdd::on_ExcleButton_clicked() {
    QSettings config("userconfig.ini", QSettings::IniFormat);
    QString DocumentPath =
        QFileDialog::getOpenFileName(this, "选择导入文件", config.value("DOCUMENTCONFIG/DocumentPath").toString());
    QXlsx::Document xlsx(DocumentPath);
    QString file_temp = DocumentPath;
    file_temp = file_temp.left(file_temp.lastIndexOf('/')) + "/";
    config.setValue("DOCUMENTCONFIG/DocumentPath", file_temp);
    config.sync();
    int row = xlsx.dimension().rowCount() + 1;
    for(int n = 2; n < row; n++) {
        QString pid;
        QString sql;
        QSqlQuery query;
        sql = QString("select PID from mold_message where 模具编号 = '%1'").arg(ui->MoldCombo->currentText());
        if(!query.exec(sql)) {
            QMessageBox::warning(this, "添加备件", "查询模具PID失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        } else {
            if(query.next()) {
                pid = query.value(0).toString();
            }
        }
        if(m_currentPart == "冲压")
            sql =
                "insert into chonya_message (PID,模具编号,备件号,状态,安全库存,期初库存,总库存量,备件价格,累计入库,累计出库,存放柜号,备注) select :pid,:mold_id,:spare_id,:stata,:save_num,:first_num,:total_num,:price_num,:enter_num,:out_num,:cabinet,:other where not exists (select 1 from chonya_message where 模具编号 = :mold_id and 备件号 = :spare_id and 存放柜号 = :cabinet)";
        else if(m_currentPart == "成型")
            sql =
                "insert into chengxing_message (PID,模具编号,备件号,状态,安全库存,期初库存,总库存量,备件价格,累计入库,累计出库,存放柜号,备注) select :pid,:mold_id,:spare_id,:stata,:save_num,:first_num,:total_num,:price_num,:enter_num,:out_num,:cabinet,:other where not exists (select 1 from chonya_message where 模具编号 = :mold_id and 备件号 = :spare_id and 存放柜号 = :cabinet)";
        query.prepare(sql);
        query.bindValue(":pid", pid);
        query.bindValue(":mold_id", ui->MoldCombo->currentText());
        query.bindValue(":spare_id", xlsx.read(n, 1).toString());
        query.bindValue(":stata", QString("入库：%1    出库：%2").arg(xlsx.read(n, 5).toInt()).arg(xlsx.read(n,
            6).toInt()));
        query.bindValue(":save_num", xlsx.read(n, 2).toString());
        query.bindValue(":first_num", xlsx.read(n, 3).toString());
        query.bindValue(":total_num", xlsx.read(n, 4).toString());
        query.bindValue(":price_num", xlsx.read(n, 5).toString());
        query.bindValue(":enter_num", xlsx.read(n, 6).toString());
        query.bindValue(":out_num", xlsx.read(n, 7).toString());
        query.bindValue(":cabinet", xlsx.read(n, 8).toString());
        query.bindValue(":other", xlsx.read(n, 9).toString());
        if(!query.exec()) {
            QMessageBox::warning(this, "添加备件", xlsx.read(n, 1).toString() + "添加失败：\n" + query.lastError().text(),
                QMessageBox::Cancel);
            return;
        } else {
            if(query.numRowsAffected()) {
                if(xlsx.read(n, 2).toInt()) {
                    query.prepare("insert into information_message (日期,模具编号,备件号,发送用户,接收用户,完成情况,信息) select :date, :mold_id, :spare_id, :tuser, :ruser, :finished, :information where not exists (select 1 from information_message where 模具编号 = :mold_id and 备件号 = :spare_id and 接收用户 = :ruser)");
                    QDateTime dateTime = QDateTime::currentDateTime();
                    query.bindValue(":date", dateTime.toString("yyyy-MM-dd hh:mm:ss"));
                    query.bindValue(":mold_id", ui->MoldCombo->currentText());
                    query.bindValue(":spare_id", xlsx.read(n, 1).toString());
                    query.bindValue(":tuser", "系统");
                    query.bindValue(":ruser", "所有人");
                    query.bindValue(":finished", "1");
                    if(m_currentPart == "冲压") {
                        query.bindValue(":information", "备件不足" + xlsx.read(n, 2).toString() + "个，需要补货（冲压）。");
                    } else {
                        query.bindValue(":information", "备件不足" + xlsx.read(n, 2).toString() + "个，需要补货（成型）。");
                    }
                    if(!query.exec()) {
                        QMessageBox::warning(this, "添加备件", "补货信息列表数据插入失败：\n" + query.lastError().text(),
                            QMessageBox::Cancel);
                        return;
                    }
                    RefreshData();
                    emit mysignal();
                } else {
                    RefreshData();
                    emit mysignal();
                }
            } else {
                QMessageBox::warning(this, "添加新备件", "该备件已存在", QMessageBox::Cancel);
                return;
            }
        }
    }
    QMessageBox::information(this, "添加新备件", "添加成功", QMessageBox::Ok);
}
