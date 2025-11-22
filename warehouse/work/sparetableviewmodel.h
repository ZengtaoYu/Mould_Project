#ifndef SPARETABLEVIEWMODEL_H
#define SPARETABLEVIEWMODEL_H

#include <QAbstractTableModel>
#include <QMap>
#include <QList>
#include <QStringList>

class Spare;

class SpareTableViewModel : public QAbstractTableModel {
    Q_OBJECT

public:
    explicit SpareTableViewModel(QObject *parent = nullptr);
    ~SpareTableViewModel();

    // 数据访问
    Spare *get(int id) const;
    void remove(int id);
    void add(const QString &product_id);

    // QAbstractTableModel接口
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

private:
    QVariant getDisplayData(const QModelIndex &index) const;
    QString getSpareLinksForWorkStation(int workStation, const QString &productId, int spareId) const;

    void updateModel();

    int m_workNum;
    int m_nextId;
    QStringList m_workList;
    QList<Spare *> m_spareList;
    QMap<int, Spare *> m_spareMap;
};

#endif // SPARETABLEVIEWMODEL_H
