#include "sparewindow.h"
#include "ui_sparewindow.h"

#include <QSettings>
#include <QSqlQuery>
#include <QSqlError>
#include <QCompleter>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QLineEdit>
#include <QScroller>
#include <QListView>
#include <QFile>
#include <QIODevice>
#include <QStandardItem>

// 静态成员定义
const QStringList SpareWindow::m_workTypeList = {"所有备件", "模具共用件", "前模零件号", "后模零件号", "滑块零件号", "顶针零件号"};

const QColor SpareWindow::ColorDelegate::UNSELECTABLE_BACKGROUND_COLOR("#ffe0e0"); // 浅红色背景
const QColor SpareWindow::ColorDelegate::SELECTABLE_BACKGROUND_COLOR("#e0ffe0");   // 浅绿色背景

SpareWindow::SpareWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SpareWindow)
    , m_model_1(nullptr)
    , m_model_2(nullptr) {
    ui->setupUi(this);
    ui->SureButton->hide();
    ColorDelegate *delegate = new ColorDelegate();
    ui->PIDView_1->setItemDelegate(delegate);
    ui->PIDView_2->setItemDelegate(delegate);
    QListView *listView1 = qobject_cast<QListView *>(ui->MoldCombo->view());
    QScroller *Scroller1 = QScroller::scroller(listView1);
    Scroller1->grabGesture(listView1->viewport(), QScroller::LeftMouseButtonGesture);
    listView1->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QListView *listView2 = qobject_cast<QListView *>(ui->ProductCombo_1->view());
    QScroller *Scroller2 = QScroller::scroller(listView2);
    Scroller2->grabGesture(listView2->viewport(), QScroller::LeftMouseButtonGesture);
    listView2->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QListView *listView2_2 = qobject_cast<QListView *>(ui->ProductCombo_2->view());
    QScroller *Scroller2_2 = QScroller::scroller(listView2_2);
    Scroller2_2->grabGesture(listView2_2->viewport(), QScroller::LeftMouseButtonGesture);
    listView2_2->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QListView *listView3 = qobject_cast<QListView *>(ui->WorkCombo->view());
    QScroller *Scroller3 = QScroller::scroller(listView3);
    Scroller3->grabGesture(listView3->viewport(), QScroller::LeftMouseButtonGesture);
    listView3->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QScroller *pScroller = QScroller::scroller(ui->PIDView_1);
    pScroller->grabGesture(ui->PIDView_1->viewport(), QScroller::LeftMouseButtonGesture);
    ui->PIDView_1->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QScroller *pScroller_2 = QScroller::scroller(ui->PIDView_2);
    pScroller_2->grabGesture(ui->PIDView_2->viewport(), QScroller::LeftMouseButtonGesture);
    ui->PIDView_2->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QSqlQuery query;
    QString sql;
    QStyledItemDelegate *d = new QStyledItemDelegate;
    QString style = "QAbstractItemView{font: 18pt \"微软雅黑\";background-color:rgb(255,255,255);color:rgb(0,0,0);}"
                    "QAbstractItemView::item:hover{background-color:rgb(0, 120, 212)}";
    QStringList mold_list;
    ui->MoldCombo->blockSignals(true);
    sql = "select 模具编号 from mold_message order by 模具编号 asc;";
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "界面初始化", "模具数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        while(query.next()) {
            mold_list.append(query.value(0).toString());
        }
    }
    ui->MoldCombo->addItems(mold_list);
    ui->MoldCombo->blockSignals(false);
    QCompleter *MoldCompleter = new QCompleter(mold_list, this);
    MoldCompleter->setMaxVisibleItems(10);
    MoldCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    MoldCompleter->setCompletionMode(QCompleter::PopupCompletion);
    MoldCompleter->setFilterMode(Qt::MatchContains);
    ui->MoldCombo->setCompleter(MoldCompleter);
    MoldCompleter->popup()->setItemDelegate(d);
    MoldCompleter->popup()->setStyleSheet(style);
    QSettings config("userconfig.ini", QSettings::IniFormat);
    ui->MoldCombo->setCurrentText(config.value("SELECTIONCONFIG/Mold").toString());
    QStringList product_list;
    ui->ProductCombo_1->blockSignals(true);
    ui->ProductCombo_2->blockSignals(true);
    product_list.append("全部料号");
    query.prepare("select distinct 产品料号 from chengxing_work where 模具编号 = :mold_id");
    query.bindValue(":mold_id", ui->MoldCombo->currentText());
    if(!query.exec()) {
        QMessageBox::warning(this, "界面初始化", "模具具体料号查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        while(query.next()) {
            product_list.append(query.value(0).toString());
        }
    }
    ui->ProductCombo_1->addItems(product_list);
    ui->ProductCombo_1->blockSignals(false);
    QCompleter *ProductCompleter = new QCompleter(product_list, this);
    ProductCompleter->setMaxVisibleItems(10);
    ProductCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    ProductCompleter->setCompletionMode(QCompleter::PopupCompletion);
    ProductCompleter->setFilterMode(Qt::MatchContains);
    ui->ProductCombo_1->setCompleter(ProductCompleter);
    ProductCompleter->popup()->setItemDelegate(d);
    ProductCompleter->popup()->setStyleSheet(style);
    ui->ProductCombo_2->addItems(product_list);
    ui->ProductCombo_2->blockSignals(false);
    QCompleter *ProductCompleter_2 = new QCompleter(product_list, this);
    ProductCompleter_2->setMaxVisibleItems(10);
    ProductCompleter_2->setCaseSensitivity(Qt::CaseInsensitive);
    ProductCompleter_2->setCompletionMode(QCompleter::PopupCompletion);
    ProductCompleter_2->setFilterMode(Qt::MatchContains);
    ui->ProductCombo_1->setCompleter(ProductCompleter_2);
    ProductCompleter->popup()->setItemDelegate(d);
    ProductCompleter->popup()->setStyleSheet(style);
    query.prepare("select 模具穴数 from chengxing_work where 模具编号 = :mold_id");
    query.bindValue(":mold_id", ui->MoldCombo->currentText());
    if(!query.exec()) {
        QMessageBox::warning(this, "查询模具穴数", "模具穴数查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        if(query.next()) {
            ui->NumLabel1->setText(query.value(0).toString());
        }
    }
    RefreshData();
}

SpareWindow::~SpareWindow() {
    delete ui;
}

void SpareWindow::RefreshData() {
    ui->NumLabel2->setText("");
    ui->NumLabel3->setText("");
    QSettings config("userconfig.ini", QSettings::IniFormat);
    m_model_1 = new QStandardItemModel(this);
    m_model_2 = new QStandardItemModel(this);
    QSqlQuery query;
    QSqlQuery query_2;
    QString part = "chengxing_work";
    if(ui->WorkCombo->currentIndex() == 0) {
        if(ui->ProductCombo_1->currentText() == "全部料号") {
            query.prepare(QString("select 模具共用件 from %1 where 模具编号 = :mold_id;").arg(part));
            query.bindValue(":mold_id", ui->MoldCombo->currentText());
            if(!query.exec()) {
                return;
            } else {
                while(query.next()) {
                    if(!query.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query.value(0).toString());
                        m_model_1->appendRow(modelitem);
                    }
                }
                ui->PIDView_1->setModel(m_model_1);
                if(!m_model_1->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_1->appendRow(modelitem);
                }
            }
            query.prepare(QString("select 前模零件号 from %1 where 模具编号 = :mold_id;").arg(part));
            query.bindValue(":mold_id", ui->MoldCombo->currentText());
            if(!query.exec()) {
                return;
            } else {
                while(query.next()) {
                    if(!query.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query.value(0).toString());
                        m_model_1->appendRow(modelitem);
                    }
                }
                ui->PIDView_1->setModel(m_model_1);
                if(!m_model_1->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_1->appendRow(modelitem);
                }
            }
            query.prepare(QString("select 后模零件号 from %1 where 模具编号 = :mold_id;").arg(part));
            query.bindValue(":mold_id", ui->MoldCombo->currentText());
            if(!query.exec()) {
                return;
            } else {
                while(query.next()) {
                    if(!query.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query.value(0).toString());
                        m_model_1->appendRow(modelitem);
                    }
                }
                ui->PIDView_1->setModel(m_model_1);
                if(!m_model_1->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_1->appendRow(modelitem);
                }
            }
            query.prepare(QString("select 滑块零件号 from %1 where 模具编号 = :mold_id;").arg(part));
            query.bindValue(":mold_id", ui->MoldCombo->currentText());
            if(!query.exec()) {
                return;
            } else {
                while(query.next()) {
                    if(!query.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query.value(0).toString());
                        m_model_1->appendRow(modelitem);
                    }
                }
                ui->PIDView_1->setModel(m_model_1);
                if(!m_model_1->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_1->appendRow(modelitem);
                }
            }
            query.prepare(QString("select 顶针零件号 from %1 where 模具编号 = :mold_id;").arg(part));
            query.bindValue(":mold_id", ui->MoldCombo->currentText());
            if(!query.exec()) {
                return;
            } else {
                while(query.next()) {
                    if(!query.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query.value(0).toString());
                        m_model_1->appendRow(modelitem);
                    }
                }
                ui->PIDView_1->setModel(m_model_1);
                if(!m_model_1->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_1->appendRow(modelitem);
                }
            }
        } else {
            int work_num = 1;
            query.prepare(
                QString("select 模具共用件 from %1 where 模具编号 = :mold_id and 产品料号 = :product_id;").arg(part));
            query.bindValue(":mold_id", ui->MoldCombo->currentText());
            query.bindValue(":product_id", ui->ProductCombo_1->currentText());
            if(!query.exec()) {
                return;
            } else {
                if(ui->ProductCombo_1->currentText() != "全部料号" && ui->WorkCombo->currentIndex() == 0) {
                    QStandardItem *workitem = new QStandardItem(m_workTypeList[work_num++]);
                    workitem->setData(true, Qt::UserRole);
                    workitem->setFlags(workitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_1->appendRow(workitem);
                }
                while(query.next()) {
                    if(!query.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query.value(0).toString());
                        m_model_1->appendRow(modelitem);
                    }
                }
                ui->PIDView_1->setModel(m_model_1);
                if(!m_model_1->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_1->appendRow(modelitem);
                }
            }
            query.prepare(
                QString("select 前模零件号 from %1 where 模具编号 = :mold_id and 产品料号 = :product_id;").arg(part));
            query.bindValue(":mold_id", ui->MoldCombo->currentText());
            query.bindValue(":product_id", ui->ProductCombo_1->currentText());
            if(!query.exec()) {
                return;
            } else {
                if(ui->ProductCombo_1->currentText() != "全部料号" && ui->WorkCombo->currentIndex() == 0) {
                    QStandardItem *workitem = new QStandardItem(m_workTypeList[work_num++]);
                    workitem->setData(true, Qt::UserRole);
                    workitem->setFlags(workitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_1->appendRow(workitem);
                }
                while(query.next()) {
                    if(!query.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query.value(0).toString());
                        m_model_1->appendRow(modelitem);
                    }
                }
                ui->PIDView_1->setModel(m_model_1);
                if(!m_model_1->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_1->appendRow(modelitem);
                }
            }
            query.prepare(
                QString("select 后模零件号 from %1 where 模具编号 = :mold_id and 产品料号 = :product_id;").arg(part));
            query.bindValue(":mold_id", ui->MoldCombo->currentText());
            query.bindValue(":product_id", ui->ProductCombo_1->currentText());
            if(!query.exec()) {
                return;
            } else {
                if(ui->ProductCombo_1->currentText() != "全部料号" && ui->WorkCombo->currentIndex() == 0) {
                    QStandardItem *workitem = new QStandardItem(m_workTypeList[work_num++]);
                    workitem->setData(true, Qt::UserRole);
                    workitem->setFlags(workitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_1->appendRow(workitem);
                }
                while(query.next()) {
                    if(!query.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query.value(0).toString());
                        m_model_1->appendRow(modelitem);
                    }
                }
                ui->PIDView_1->setModel(m_model_1);
                if(!m_model_1->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_1->appendRow(modelitem);
                }
            }
            query.prepare(
                QString("select 滑块零件号 from %1 where 模具编号 = :mold_id and 产品料号 = :product_id;").arg(part));
            query.bindValue(":mold_id", ui->MoldCombo->currentText());
            query.bindValue(":product_id", ui->ProductCombo_1->currentText());
            if(!query.exec()) {
                return;
            } else {
                if(ui->ProductCombo_1->currentText() != "全部料号" && ui->WorkCombo->currentIndex() == 0) {
                    QStandardItem *workitem = new QStandardItem(m_workTypeList[work_num++]);
                    workitem->setData(true, Qt::UserRole);
                    workitem->setFlags(workitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_1->appendRow(workitem);
                }
                while(query.next()) {
                    if(!query.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query.value(0).toString());
                        m_model_1->appendRow(modelitem);
                    }
                }
                ui->PIDView_1->setModel(m_model_1);
                if(!m_model_1->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_1->appendRow(modelitem);
                }
            }
            query.prepare(
                QString("select 顶针零件号 from %1 where 模具编号 = :mold_id and 产品料号 = :product_id;").arg(part));
            query.bindValue(":mold_id", ui->MoldCombo->currentText());
            query.bindValue(":product_id", ui->ProductCombo_1->currentText());
            if(!query.exec()) {
                return;
            } else {
                if(ui->ProductCombo_1->currentText() != "全部料号" && ui->WorkCombo->currentIndex() == 0) {
                    QStandardItem *workitem = new QStandardItem(m_workTypeList[work_num++]);
                    workitem->setData(true, Qt::UserRole);
                    workitem->setFlags(workitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_1->appendRow(workitem);
                }
                while(query.next()) {
                    if(!query.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query.value(0).toString());
                        m_model_1->appendRow(modelitem);
                    }
                }
                ui->PIDView_1->setModel(m_model_1);
                if(!m_model_1->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_1->appendRow(modelitem);
                }
            }
        }
        if(ui->ProductCombo_2->currentText() == "全部料号") {
            query_2.prepare(QString("select 模具共用件 from %1 where 模具编号 = :mold_id;").arg(part));
            query_2.bindValue(":mold_id", ui->MoldCombo->currentText());
            if(!query_2.exec()) {
                return;
            } else {
                while(query_2.next()) {
                    if(!query_2.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query_2.value(0).toString());
                        m_model_2->appendRow(modelitem);
                    }
                }
                ui->PIDView_2->setModel(m_model_2);
                if(!m_model_2->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_2->appendRow(modelitem);
                }
            }
            query_2.prepare(QString("select 前模零件号 from %1 where 模具编号 = :mold_id;").arg(part));
            query_2.bindValue(":mold_id", ui->MoldCombo->currentText());
            if(!query_2.exec()) {
                return;
            } else {
                while(query_2.next()) {
                    if(!query_2.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query_2.value(0).toString());
                        m_model_2->appendRow(modelitem);
                    }
                }
                ui->PIDView_2->setModel(m_model_2);
                if(!m_model_2->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_2->appendRow(modelitem);
                }
            }
            query_2.prepare(QString("select 后模零件号 from %1 where 模具编号 = :mold_id;").arg(part));
            query_2.bindValue(":mold_id", ui->MoldCombo->currentText());
            if(!query_2.exec()) {
                return;
            } else {
                while(query_2.next()) {
                    if(!query_2.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query_2.value(0).toString());
                        m_model_2->appendRow(modelitem);
                    }
                }
                ui->PIDView_2->setModel(m_model_2);
                if(!m_model_2->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_2->appendRow(modelitem);
                }
            }
            query_2.prepare(QString("select 滑块零件号 from %1 where 模具编号 = :mold_id;").arg(part));
            query_2.bindValue(":mold_id", ui->MoldCombo->currentText());
            if(!query_2.exec()) {
                return;
            } else {
                while(query_2.next()) {
                    if(!query_2.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query_2.value(0).toString());
                        m_model_2->appendRow(modelitem);
                    }
                }
                ui->PIDView_2->setModel(m_model_2);
                if(!m_model_2->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_2->appendRow(modelitem);
                }
            }
            query_2.prepare(QString("select 顶针零件号 from %1 where 模具编号 = :mold_id;").arg(part));
            query_2.bindValue(":mold_id", ui->MoldCombo->currentText());
            if(!query_2.exec()) {
                return;
            } else {
                while(query_2.next()) {
                    if(!query_2.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query_2.value(0).toString());
                        m_model_2->appendRow(modelitem);
                    }
                }
                ui->PIDView_2->setModel(m_model_2);
                if(!m_model_2->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_2->appendRow(modelitem);
                }
            }
        } else {
            int work_num = 1;
            query_2.prepare(
                QString("select 模具共用件 from %1 where 模具编号 = :mold_id and 产品料号 = :product_id;").arg(part));
            query_2.bindValue(":mold_id", ui->MoldCombo->currentText());
            query_2.bindValue(":product_id", ui->ProductCombo_2->currentText());
            if(!query_2.exec()) {
                return;
            } else {
                if(ui->ProductCombo_2->currentText() != "全部料号" && ui->WorkCombo->currentIndex() == 0) {
                    QStandardItem *workitem = new QStandardItem(m_workTypeList[work_num++]);
                    workitem->setData(true, Qt::UserRole);
                    workitem->setFlags(workitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_2->appendRow(workitem);
                }
                while(query_2.next()) {
                    if(!query_2.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query_2.value(0).toString());
                        m_model_2->appendRow(modelitem);
                    }
                }
                ui->PIDView_2->setModel(m_model_2);
                if(!m_model_2->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_2->appendRow(modelitem);
                }
            }
            query_2.prepare(
                QString("select 前模零件号 from %1 where 模具编号 = :mold_id and 产品料号 = :product_id;").arg(part));
            query_2.bindValue(":mold_id", ui->MoldCombo->currentText());
            query_2.bindValue(":product_id", ui->ProductCombo_2->currentText());
            if(!query_2.exec()) {
                return;
            } else {
                if(ui->ProductCombo_2->currentText() != "全部料号" && ui->WorkCombo->currentIndex() == 0) {
                    QStandardItem *workitem = new QStandardItem(m_workTypeList[work_num++]);
                    workitem->setData(true, Qt::UserRole);
                    workitem->setFlags(workitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_2->appendRow(workitem);
                }
                while(query_2.next()) {
                    if(!query_2.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query_2.value(0).toString());
                        m_model_2->appendRow(modelitem);
                    }
                }
                ui->PIDView_2->setModel(m_model_2);
                if(!m_model_2->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_2->appendRow(modelitem);
                }
            }
            query_2.prepare(
                QString("select 后模零件号 from %1 where 模具编号 = :mold_id and 产品料号 = :product_id;").arg(part));
            query_2.bindValue(":mold_id", ui->MoldCombo->currentText());
            query_2.bindValue(":product_id", ui->ProductCombo_2->currentText());
            if(!query_2.exec()) {
                return;
            } else {
                if(ui->ProductCombo_2->currentText() != "全部料号" && ui->WorkCombo->currentIndex() == 0) {
                    QStandardItem *workitem = new QStandardItem(m_workTypeList[work_num++]);
                    workitem->setData(true, Qt::UserRole);
                    workitem->setFlags(workitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_2->appendRow(workitem);
                }
                while(query_2.next()) {
                    if(!query_2.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query_2.value(0).toString());
                        m_model_2->appendRow(modelitem);
                    }
                }
                ui->PIDView_2->setModel(m_model_2);
                if(!m_model_2->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_2->appendRow(modelitem);
                }
            }
            query_2.prepare(
                QString("select 滑块零件号 from %1 where 模具编号 = :mold_id and 产品料号 = :product_id;").arg(part));
            query_2.bindValue(":mold_id", ui->MoldCombo->currentText());
            query_2.bindValue(":product_id", ui->ProductCombo_2->currentText());
            if(!query_2.exec()) {
                return;
            } else {
                if(ui->ProductCombo_2->currentText() != "全部料号" && ui->WorkCombo->currentIndex() == 0) {
                    QStandardItem *workitem = new QStandardItem(m_workTypeList[work_num++]);
                    workitem->setData(true, Qt::UserRole);
                    workitem->setFlags(workitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_2->appendRow(workitem);
                }
                while(query_2.next()) {
                    if(!query_2.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query_2.value(0).toString());
                        m_model_2->appendRow(modelitem);
                    }
                }
                ui->PIDView_2->setModel(m_model_2);
                if(!m_model_2->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_2->appendRow(modelitem);
                }
            }
            query_2.prepare(
                QString("select 顶针零件号 from %1 where 模具编号 = :mold_id and 产品料号 = :product_id;").arg(part));
            query_2.bindValue(":mold_id", ui->MoldCombo->currentText());
            query_2.bindValue(":product_id", ui->ProductCombo_2->currentText());
            if(!query_2.exec()) {
                return;
            } else {
                if(ui->ProductCombo_2->currentText() != "全部料号" && ui->WorkCombo->currentIndex() == 0) {
                    QStandardItem *workitem = new QStandardItem(m_workTypeList[work_num++]);
                    workitem->setData(true, Qt::UserRole);
                    workitem->setFlags(workitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_2->appendRow(workitem);
                }
                while(query_2.next()) {
                    if(!query_2.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query_2.value(0).toString());
                        m_model_2->appendRow(modelitem);
                    }
                }
                ui->PIDView_2->setModel(m_model_2);
                if(!m_model_2->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_2->appendRow(modelitem);
                }
            }
        }
    } else {
        if(ui->ProductCombo_1->currentText() == "全部料号") {
            query.prepare(QString("select %1 from %2 where 模具编号 = :mold_id;").arg(ui->WorkCombo->currentText()).arg(part));
            query.bindValue(":mold_id", ui->MoldCombo->currentText());
            if(!query.exec()) {
                return;
            } else {
                while(query.next()) {
                    if(!query.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query.value(0).toString());
                        m_model_1->appendRow(modelitem);
                    }
                }
                ui->PIDView_1->setModel(m_model_1);
                if(!m_model_1->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_1->appendRow(modelitem);
                }
            }
        } else {
            query.prepare(QString("select %1 from %2 where 模具编号 = :mold_id and 产品料号 = :product_id;").arg(
                ui->WorkCombo->currentText()).arg(part));
            query.bindValue(":mold_id", ui->MoldCombo->currentText());
            query.bindValue(":product_id", ui->ProductCombo_1->currentText());
            if(!query.exec()) {
                return;
            } else {
                while(query.next()) {
                    if(!query.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query.value(0).toString());
                        m_model_1->appendRow(modelitem);
                    }
                }
                ui->PIDView_1->setModel(m_model_1);
                if(!m_model_1->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_1->appendRow(modelitem);
                }
            }
        }
        if(ui->ProductCombo_2->currentText() == "全部料号") {
            query_2.prepare(QString("select %1 from %2 where 模具编号 = :mold_id;").arg(ui->WorkCombo->currentText()).arg(
                part));
            query_2.bindValue(":mold_id", ui->MoldCombo->currentText());
            if(!query_2.exec()) {
                return;
            } else {
                while(query_2.next()) {
                    if(!query_2.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query_2.value(0).toString());
                        m_model_2->appendRow(modelitem);
                    }
                }
                ui->PIDView_2->setModel(m_model_2);
                if(!m_model_2->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_2->appendRow(modelitem);
                }
            }
        } else {
            query_2.prepare(QString("select %1 from %2 where 模具编号 = :mold_id and 产品料号 = :product_id;").arg(
                ui->WorkCombo->currentText()).arg(part));
            query_2.bindValue(":mold_id", ui->MoldCombo->currentText());
            query_2.bindValue(":product_id", ui->ProductCombo_2->currentText());
            if(!query_2.exec()) {
                return;
            } else {
                while(query_2.next()) {
                    if(!query_2.value(0).toString().isEmpty()) {
                        QStandardItem *modelitem = new QStandardItem(query_2.value(0).toString());
                        m_model_2->appendRow(modelitem);
                    }
                }
                ui->PIDView_2->setModel(m_model_2);
                if(!m_model_2->rowCount()) {
                    QStandardItem *modelitem = new QStandardItem("     该工站暂未\n     录入数据");
                    modelitem->setData(true, Qt::UserRole);
                    modelitem->setFlags(modelitem->flags() & ~Qt::ItemIsSelectable);
                    m_model_2->appendRow(modelitem);
                }
            }
        }
    }
}

void SpareWindow::on_MoldCombo_currentIndexChanged(const QString &arg1) {
    ui->ProductCombo_1->clear();
    ui->ProductCombo_2->clear();
    QSqlQuery query;
    QString sql;
    QStyledItemDelegate *d = new QStyledItemDelegate;
    QString style = "QAbstractItemView{font: 18pt \"微软雅黑\";background-color:rgb(255,255,255);color:rgb(0,0,0);}"
                    "QAbstractItemView::item:hover{background-color:rgb(0, 120, 212)}";
    QStringList product_list;
    ui->ProductCombo_1->blockSignals(true);
    ui->ProductCombo_2->blockSignals(true);
    product_list.append("全部料号");
    query.prepare("select distinct 产品料号 from chengxing_work where 模具编号 = :mold_id");
    query.bindValue(":mold_id", arg1);
    if(!query.exec()) {
        QMessageBox::warning(this, "界面初始化", "模具具体料号查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        while(query.next()) {
            product_list.append(query.value(0).toString());
        }
    }
    ui->ProductCombo_1->addItems(product_list);
    ui->ProductCombo_1->blockSignals(false);
    QCompleter *ProductCompleter = new QCompleter(product_list, this);
    ProductCompleter->setMaxVisibleItems(10);
    ProductCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    ProductCompleter->setCompletionMode(QCompleter::PopupCompletion);
    ProductCompleter->setFilterMode(Qt::MatchContains);
    ui->ProductCombo_1->setCompleter(ProductCompleter);
    ProductCompleter->popup()->setItemDelegate(d);
    ProductCompleter->popup()->setStyleSheet(style);
    ui->ProductCombo_2->addItems(product_list);
    ui->ProductCombo_2->blockSignals(false);
    QCompleter *ProductCompleter_2 = new QCompleter(product_list, this);
    ProductCompleter_2->setMaxVisibleItems(10);
    ProductCompleter_2->setCaseSensitivity(Qt::CaseInsensitive);
    ProductCompleter_2->setCompletionMode(QCompleter::PopupCompletion);
    ProductCompleter_2->setFilterMode(Qt::MatchContains);
    ui->ProductCombo_1->setCompleter(ProductCompleter_2);
    ProductCompleter->popup()->setItemDelegate(d);
    ProductCompleter->popup()->setStyleSheet(style);
    query.prepare("select 模具穴数 from chengxing_work where 模具编号 = :mold_id");
    query.bindValue(":mold_id", ui->MoldCombo->currentText());
    if(!query.exec()) {
        QMessageBox::warning(this, "查询模具穴数", "模具穴数查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        if(query.next()) {
            ui->NumLabel1->setText(query.value(0).toString());
        }
    }
    RefreshData();
    QLineEdit *lineEdit = ui->MoldCombo->lineEdit();
    lineEdit->setSelection(0, 0);
}

void SpareWindow::on_ProductCombo_1_currentIndexChanged(const QString &arg1) {
    RefreshData();
    QLineEdit *lineEdit = ui->ProductCombo_1->lineEdit();
    lineEdit->setSelection(0, 0);
    Q_UNUSED(arg1);
}

void SpareWindow::on_ProductCombo_2_currentIndexChanged(const QString &arg1) {
    RefreshData();
    QLineEdit *lineEdit = ui->ProductCombo_1->lineEdit();
    lineEdit->setSelection(0, 0);
    Q_UNUSED(arg1);
}

void SpareWindow::on_WorkCombo_currentIndexChanged(const QString &arg1) {
    RefreshData();
    Q_UNUSED(arg1);
    QLineEdit *lineEdit = ui->WorkCombo->lineEdit();
    lineEdit->setSelection(0, 0);
}

void SpareWindow::on_ReturnButton_clicked() {
    this->close();
}

void SpareWindow::on_OutButton_clicked() {
    QAbstractItemModel *model = ui->PIDView_1->model();
    if(!model) {
        return;
    }
    QString fileName, file_temp;
    QSettings config("userconfig.ini", QSettings::IniFormat);
    fileName = QFileDialog::getSaveFileName(this, "导出冲压模具备件盘点记录表",
            config.value("DOCUMENTCONFIG/DocumentPath").toString() + ui->MoldCombo->currentText() + "备件更换单",
            "文本文件 (*.txt)");
    file_temp = fileName;
    file_temp = file_temp.left(file_temp.lastIndexOf('/')) + "/";
    config.setValue("DOCUMENTCONFIG/DocumentPath", file_temp);
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }
    QTextStream out(&file);
    out << ui->MoldCombo->currentText() << "#" << ui->ProductCombo_1->currentText() << ":\n";
    int t = 0;
    for(int row = 0; row < model->rowCount(); ++row) {
        QModelIndex index = model->index(row, 0);
        QString text = model->data(index, Qt::DisplayRole).toString();
        QString spare_name;
        int pos = text.indexOf('(');
        if(pos != -1) {
            spare_name = text.left(pos).trimmed();
        } else {
            spare_name = text;
        }
        if(spare_name == "模具共用件" || spare_name.contains("零件号")) {
            if(spare_name != "模具共用件") {
                out << "\n";
            }
            t = 0;
            out << spare_name << "\t\n";
        } else {
            t++;
            out << spare_name << "\t";
            if(t % 10 == 0) {
                out << "\n";
            }
        }
    }
    out << "\n";
    out << "\n";
    out << ui->MoldCombo->currentText() << "#" << ui->ProductCombo_2->currentText() << ":\n";
    for(int row = 0; row < m_model_2->rowCount(); ++row) {
        QModelIndex index = m_model_2->index(row, 0);
        QString text = m_model_2->data(index, Qt::DisplayRole).toString();
        QString spare_name;
        int pos = text.indexOf('(');
        if(pos != -1) {
            spare_name = text.left(pos).trimmed();
        } else {
            spare_name = text;
        }
        if(spare_name == "模具共用件" || spare_name.contains("零件号")) {
            if(spare_name != "模具共用件") {
                out << "\n";
            }
            t = 0;
            out << spare_name << "\t\n";
        } else {
            t++;
            out << spare_name << "\t";
            if(t % 10 == 0) {
                out << "\n";
            }
        }
    }
    out << "\n";
    file.close();
}

void SpareWindow::on_PIDView_1_clicked(const QModelIndex &index) {
    ui->NumLabel2->setText("");
    ui->NumLabel3->setText("");
    QSqlQuery query;
    query.prepare("select 模具共用件数量,模具共用件合计数量 from chengxing_work where 模具编号 = :mold_id and 模具共用件 = :spare_id");
    query.bindValue(":mold_id", ui->MoldCombo->currentText());
    query.bindValue(":spare_id", index.data().toString());
    if(!query.exec()) {
        QMessageBox::warning(this, "查询模具数据", "模具备件数量查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        if(query.next()) {
            ui->Label8->setText("       数量:");
            ui->NumLabel2->setText(query.value(0).toString());
            ui->NumLabel3->setText(query.value(1).toString());
        }
    }
    query.prepare("select 前模零件号单穴数量,前模零件号合计数量 from chengxing_work where 模具编号 = :mold_id and 前模零件号 = :spare_id");
    query.bindValue(":mold_id", ui->MoldCombo->currentText());
    query.bindValue(":spare_id", index.data().toString());
    if(!query.exec()) {
        QMessageBox::warning(this, "查询模具数据", "模具备件数量查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        if(query.next()) {
            ui->Label8->setText("单穴数量:");
            ui->NumLabel2->setText(query.value(0).toString());
            ui->NumLabel3->setText(query.value(1).toString());
        }
    }
    query.prepare("select 后模零件号单穴数量,后模零件号合计数量 from chengxing_work where 模具编号 = :mold_id and 后模零件号 = :spare_id");
    query.bindValue(":mold_id", ui->MoldCombo->currentText());
    query.bindValue(":spare_id", index.data().toString());
    if(!query.exec()) {
        QMessageBox::warning(this, "查询模具数据", "模具备件数量查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        if(query.next()) {
            ui->Label8->setText("单穴数量:");
            ui->NumLabel2->setText(query.value(0).toString());
            ui->NumLabel3->setText(query.value(1).toString());
        }
    }
    query.prepare("select 滑块零件号单穴数量,滑块零件号合计数量 from chengxing_work where 模具编号 = :mold_id and 滑块零件号 = :spare_id");
    query.bindValue(":mold_id", ui->MoldCombo->currentText());
    query.bindValue(":spare_id", index.data().toString());
    if(!query.exec()) {
        QMessageBox::warning(this, "查询模具数据", "模具备件数量查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        if(query.next()) {
            ui->Label8->setText("单穴数量:");
            ui->NumLabel2->setText(query.value(0).toString());
            ui->NumLabel3->setText(query.value(1).toString());
        }
    }
    query.prepare("select 顶针零件号单穴数量,顶针零件号合计数量 from chengxing_work where 模具编号 = :mold_id and 顶针零件号 = :spare_id");
    query.bindValue(":mold_id", ui->MoldCombo->currentText());
    query.bindValue(":spare_id", index.data().toString());
    if(!query.exec()) {
        QMessageBox::warning(this, "查询模具数据", "模具备件数量查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        if(query.next()) {
            ui->Label8->setText("单穴数量:");
            ui->NumLabel2->setText(query.value(0).toString());
            ui->NumLabel3->setText(query.value(1).toString());
        }
    }
}

void SpareWindow::on_PIDView_2_clicked(const QModelIndex &index) {
    ui->NumLabel2->setText("");
    ui->NumLabel3->setText("");
    QSqlQuery query;
    query.prepare("select 模具共用件数量,模具共用件合计数量 from chengxing_work where 模具编号 = :mold_id and 模具共用件 = :spare_id");
    query.bindValue(":mold_id", ui->MoldCombo->currentText());
    query.bindValue(":spare_id", index.data().toString());
    if(!query.exec()) {
        QMessageBox::warning(this, "查询模具数据", "模具备件数量查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        if(query.next()) {
            ui->Label8->setText("       数量:");
            ui->NumLabel2->setText(query.value(0).toString());
            ui->NumLabel3->setText(query.value(1).toString());
        }
    }
    query.prepare("select 前模零件号单穴数量,前模零件号合计数量 from chengxing_work where 模具编号 = :mold_id and 前模零件号 = :spare_id");
    query.bindValue(":mold_id", ui->MoldCombo->currentText());
    query.bindValue(":spare_id", index.data().toString());
    if(!query.exec()) {
        QMessageBox::warning(this, "查询模具数据", "模具备件数量查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        if(query.next()) {
            ui->Label8->setText("单穴数量:");
            ui->NumLabel2->setText(query.value(0).toString());
            ui->NumLabel3->setText(query.value(1).toString());
        }
    }
    query.prepare("select 后模零件号单穴数量,后模零件号合计数量 from chengxing_work where 模具编号 = :mold_id and 后模零件号 = :spare_id");
    query.bindValue(":mold_id", ui->MoldCombo->currentText());
    query.bindValue(":spare_id", index.data().toString());
    if(!query.exec()) {
        QMessageBox::warning(this, "查询模具数据", "模具备件数量查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        if(query.next()) {
            ui->Label8->setText("单穴数量:");
            ui->NumLabel2->setText(query.value(0).toString());
            ui->NumLabel3->setText(query.value(1).toString());
        }
    }
    query.prepare("select 滑块零件号单穴数量,滑块零件号合计数量 from chengxing_work where 模具编号 = :mold_id and 滑块零件号 = :spare_id");
    query.bindValue(":mold_id", ui->MoldCombo->currentText());
    query.bindValue(":spare_id", index.data().toString());
    if(!query.exec()) {
        QMessageBox::warning(this, "查询模具数据", "模具备件数量查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        if(query.next()) {
            ui->Label8->setText("单穴数量:");
            ui->NumLabel2->setText(query.value(0).toString());
            ui->NumLabel3->setText(query.value(1).toString());
        }
    }
    query.prepare("select 顶针零件号单穴数量,顶针零件号合计数量 from chengxing_work where 模具编号 = :mold_id and 顶针零件号 = :spare_id");
    query.bindValue(":mold_id", ui->MoldCombo->currentText());
    query.bindValue(":spare_id", index.data().toString());
    if(!query.exec()) {
        QMessageBox::warning(this, "查询模具数据", "模具备件数量查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    } else {
        if(query.next()) {
            ui->Label8->setText("单穴数量:");
            ui->NumLabel2->setText(query.value(0).toString());
            ui->NumLabel3->setText(query.value(1).toString());
        }
    }
}
