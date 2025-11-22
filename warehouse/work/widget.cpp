#include "widget.h"
#include "spare.h"
#include "linkabletableview.h"
#include "sparetableviewmodel.h"
#include "linkableitemdelegate.h"

#include <QMessageBox>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QSettings>
#include <QSqlQuery>
#include <QSqlError>
#include <QScroller>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent) {
    // 初始化视图
    m_linkableTableView = new LinkableTableView(this);
    m_linkableTableView->setMouseTracking(false);
    m_linkableTableView->setSelectionMode(QTableView::NoSelection);
    m_linkableTableView->horizontalHeader()->setStretchLastSection(true);
    // 设置滚动
    QScroller *pScroller = QScroller::scroller(m_linkableTableView);
    pScroller->grabGesture(m_linkableTableView->viewport(), QScroller::LeftMouseButtonGesture);
    m_linkableTableView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    // 设置布局
    QVBoxLayout *vLayout = new QVBoxLayout(this);
    vLayout->addWidget(m_linkableTableView);
    // 初始化模型和委托
    m_spareTableViewModel = new SpareTableViewModel(this);
    m_linkableTableView->setModel(m_spareTableViewModel);
    m_linkableItemDelegate = new LinkableItemDelegate(this);
    m_linkableTableView->setItemDelegate(m_linkableItemDelegate);
    // 连接信号和槽
    connect(m_linkableTableView, &LinkableTableView::linkActivated, this, &MainWidget::doLinkActivated);
    // 加载数据
    QSettings config("userconfig.ini", QSettings::IniFormat);
    m_moldId = config.value("SELECTIONCONFIG/Mold").toString();
    QSqlQuery query;
    query.prepare("select 具体料号 from mold_message where 模具编号 = :mold_id");
    query.bindValue(":mold_id", m_moldId);
    if(!query.exec()) {
        QMessageBox::warning(this, "界面初始化", "模具具体料号查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        QStringList tempList = query.value(0).toString().split('#', Qt::SkipEmptyParts);
        int row = 0;
        for(const QString &item : tempList) {
            if(!item.isEmpty()) {
                m_spareTableViewModel->add(item);
                m_linkableTableView->setRowHeight(row, 130);
                row++;
            }
        }
    }
}

MainWidget::~MainWidget() {}

QString MainWidget::extractSpareIdFromLink(const QString &link) const {
    QString spareName = link.left(link.indexOf("?"));
    int pos = spareName.indexOf('(');
    if(pos != -1) {
        return spareName.left(pos).trimmed();
    }
    pos = spareName.indexOf("（");
    if(pos != -1) {
        return spareName.left(pos).trimmed();
    }
    return spareName;
}

void MainWidget::doLinkActivated(QString link) {
    int id = link.mid(link.indexOf("?") + 1).toInt();
    Spare *spare = m_spareTableViewModel->get(id);
    if(!spare) {
        return;
    }
    QSettings config("userconfig.ini", QSettings::IniFormat);
    QSqlQuery query;
    QString spareId = extractSpareIdFromLink(link);
    if(spareId == "共用" || spareId == "此站不用") {
        return;
    }
    QString part = "chonya_message";
    query.prepare(QString("select 备件号 from %1 where 模具编号 = :mold_id and 备件号 = :spare_id;").arg(part));
    query.bindValue(":mold_id", m_moldId);
    query.bindValue(":spare_id", spareId);
    if(!query.exec()) {
        QMessageBox::warning(this, "备件选择", "查询失败：\n" + query.lastError().text(), QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        config.setValue("SELECTIONCONFIG/Mold", m_moldId);
        config.setValue("SELECTIONCONFIG/Spare", spareId);
        config.setValue("SELECTIONCONFIG/Cabinet", "");
        config.sync();
        emit mysignal();
    } else {
        QMessageBox::warning(this, "备件选择", "仓库没有该备件的记录\n", QMessageBox::Cancel);
    }
}
