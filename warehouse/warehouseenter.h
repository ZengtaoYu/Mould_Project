#ifndef WAREHOUSEENTER_H
#define WAREHOUSEENTER_H

#include <QMainWindow>
#include <QVariant>
#include <QString>
#include <QStringList>
#include <QStandardItemModel>
#include "xlsxformat.h"

// Forward declarations
class QComboBox;
class QListView;
class QAbstractItemView;
class QStyledItemDelegate;

namespace Ui {
class WarehouseEnter;
}

class WarehouseEnter : public QMainWindow {
    Q_OBJECT

public:
    explicit WarehouseEnter(QVariant part_value, QVariant mold_value, QVariant spare_value, QVariant cabinet_value,
        QWidget *parent = nullptr);
    ~WarehouseEnter();

signals:
    void mysignal();

private slots:
    void on_EnterButton_clicked();
    void on_ExportButton_clicked();
    void on_ReturnButton_clicked();
    void on_ChangeButton_toggled(bool checked);
    void on_SpareView_clicked(const QModelIndex &index);
    void on_MoldCombo_currentIndexChanged(const QString &arg1);
    bool eventFilter(QObject *obj, QEvent *event);

private:
    // 初始化相关方法
    void initializeUI();
    void initializeScrollers();
    void initializeCompleters();
    void initializeFormat();
    void initializeData();
    void loadInitialData();

    // 辅助方法
    QStringList fetchData(const QString &query);
    void Find_ID(const QString &value);
    void setupCompleter(QComboBox *comboBox, const QStringList &data);
    void setupScroller(QAbstractItemView *view);
    bool validateTableName(const QString &tableName);
    QString buildSafeQuery(const QString &baseQuery, const QString &tableName);
    void handleEnterSuccess(int newTotalNum);
    void updateLabelText();
    void updateLabelStyle();
    void selectSpareInView();
    QString getDepartmentName() const;

    // 成员变量
    Ui::WarehouseEnter *ui;
    QStandardItemModel *model;
    QStyledItemDelegate *itemDelegate;
    QXlsx::Format Song12CB;

    QVariant partvalue_;
    QString part;
    QVariant moldvalue_;
    QString mold;
    QVariant sparevalue_;
    QString spare;
    QVariant cabinetvalue_;
};

#endif // WAREHOUSEENTER_H
