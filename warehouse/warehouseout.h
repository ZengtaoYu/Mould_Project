#ifndef WAREHOUSEOUT_H
#define WAREHOUSEOUT_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QVariant>
#include <QString>
#include "xlsxformat.h"

class QCompleter;
class QStyledItemDelegate;
class QSqlQuery;

namespace Ui {
class WarehouseOut;
}

class WarehouseOut : public QMainWindow {
    Q_OBJECT

public:
    explicit WarehouseOut(QVariant part_value, QVariant mold_value, QVariant spare_value, QVariant cabinet_value,
        QWidget *parent = nullptr);
    ~WarehouseOut();

signals:
    void mysignal();

private slots:
    void on_OutButton_clicked();
    void on_ExportButton_clicked();
    void on_ReturnButton_clicked();
    void on_ChangeButton_toggled(bool checked);
    void on_SpareView_clicked(const QModelIndex &index);
    void on_MoldCombo_currentIndexChanged(const QString &arg1);
    bool eventFilter(QObject *obj, QEvent *event);

private:
    // 辅助方法
    QStringList fetchData(const QString &query) const;
    void Find_ID(const QString &value);
    void setupCompleter(const QStringList &data);
    void updateSpareInfo(const QString &moldId, const QString &spareId, const QString &cabinet);
    bool validateOutInput();
    bool querySpareData(int &totalNum, int &enterNum, int &outNum);
    bool updateSpareInventory(int totalNum, int enterNum, int outNum);
    bool insertOutRecord(int outNum);
    void insertLowStockWarning(int remainingNum);
    void showOutSuccess(int remainingNum);

    // 成员变量
    Ui::WarehouseOut *ui;
    QStandardItemModel *model;
    QXlsx::Format Song12CB;
    QStyledItemDelegate *itemDelegate;

    QString part;
    QString mold;
    QString spare;
};

#endif // WAREHOUSEOUT_H
