#include "sparetableviewmodel.h"
#include "spare.h"

#include <QSettings>
#include <QSqlQuery>
#include <QSqlError>
#include <algorithm>

SpareTableViewModel::SpareTableViewModel(QObject *parent) : QAbstractTableModel(parent) {
    m_nextId = 1;
    m_workNum = 1;
    QSettings config("userconfig.ini", QSettings::IniFormat);
    QString moldId = config.value("SELECTIONCONFIG/Mold").toString();
    QSqlQuery query;
    query.prepare("select 工站 from mold_message where 模具编号 = :mold_id");
    query.bindValue(":mold_id", moldId);
    if(!query.exec()) {
        return;
    }
    if(query.next()) {
        QStringList tempList = query.value(0).toString().split('#', Qt::SkipEmptyParts);
        int n = 1;
        for(const QString &item : tempList) {
            if(!item.isEmpty()) {
                QString num = QString("%1.").arg(n);
                m_workList.append(num + item);
                n++;
            }
        }
        m_workNum = n;
    }
}

SpareTableViewModel::~SpareTableViewModel() {
    qDeleteAll(m_spareMap);
    m_spareMap.clear();
    m_spareList.clear();
}

int SpareTableViewModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_spareList.size();
}

int SpareTableViewModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_workNum;
}

QVariant SpareTableViewModel::data(const QModelIndex &index, int role) const {
    if(!index.isValid() || index.row() >= m_spareList.size()) {
        return QVariant();
    }
    Spare *spare = m_spareList.at(index.row());
    if(!spare) {
        return QVariant();
    }
    switch(role) {
    case Qt::DisplayRole:
        return getDisplayData(index);
    case Qt::UserRole:
        return spare->id();
    default:
        break;
    }
    return QVariant();
}

QVariant SpareTableViewModel::getDisplayData(const QModelIndex &index) const {
    if(index.row() >= m_spareList.size()) {
        return QVariant();
    }
    Spare *spare = m_spareList.at(index.row());
    if(!spare) {
        return QVariant();
    }
    int column = index.column();
    if(column == 0) {
        return spare->name();
    } else if(column > 0 && column < m_workNum) {
        // 工站索引等于列索引（列1对应工站1，列2对应工站2）
        int workStation = column;
        return getSpareLinksForWorkStation(workStation, spare->name(), spare->id());
    }
    return QVariant();
}

QString SpareTableViewModel::getSpareLinksForWorkStation(int workStation, const QString &productId, int spareId) const {
    QSqlQuery query;
    QString part = "chonya_work";
    QSettings config("userconfig.ini", QSettings::IniFormat);
    QString moldId = config.value("SELECTIONCONFIG/Mold").toString();
    query.prepare(
        QString("select 备件号 from %1 where 模具编号 = :mold_id and 工站 = :work_id and 产品料号 = :product_id;").arg(
        part));
    query.bindValue(":mold_id", moldId);
    query.bindValue(":work_id", workStation);
    query.bindValue(":product_id", productId);
    if(!query.exec()) {
        return QString();
    }
    QString spareLinks;
    while(query.next()) {
        QStringList tempList = query.value(0).toString().split('#', Qt::SkipEmptyParts);
        for(const QString &item : tempList) {
            if(!item.isEmpty()) {
                spareLinks += QString("<a href=\"%1?%2\">%1</a>&nbsp;<br>").arg(item).arg(spareId);
            }
        }
    }
    return spareLinks;
}

QVariant SpareTableViewModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if(section == 0) {
            return "产品料号";
        } else if(section > 0 && section <= m_workList.size()) {
            return m_workList[section - 1];
        }
    }
    return QAbstractTableModel::headerData(section, orientation, role);
}

Qt::ItemFlags SpareTableViewModel::flags(const QModelIndex &index) const {
    return QAbstractTableModel::flags(index);
}

void SpareTableViewModel::add(const QString &product_id) {
    Spare *spare = new Spare;
    spare->setId(m_nextId);
    spare->setName(product_id);
    m_spareMap.insert(m_nextId, spare);
    updateModel();
    m_nextId++;
}

Spare *SpareTableViewModel::get(int id) const {
    return m_spareMap.value(id);
}

void SpareTableViewModel::remove(int id) {
    if(m_spareMap.contains(id)) {
        delete m_spareMap.value(id);
        m_spareMap.remove(id);
        updateModel();
    }
}

void SpareTableViewModel::updateModel() {
    m_spareList.clear();
    QList<int> keys = m_spareMap.keys();
    std::sort(keys.begin(), keys.end());
    for(int key : keys) {
        m_spareList.push_back(m_spareMap.value(key));
    }
    emit layoutChanged();
}
