#ifndef WAREHOUSEADD_H
#define WAREHOUSEADD_H

#include <QMainWindow>
#include <QMap>
#include <QString>
#include <QStringList>
#include <QWidget>

// 前向声明
class QStandardItemModel;
class QCloseEvent;
class QModelIndex;

namespace Ui {
class WarehouseAdd;
}

class WarehouseDele;

class WarehouseAdd : public QMainWindow {
    Q_OBJECT

public:
    explicit WarehouseAdd(QWidget *parent = nullptr);
    ~WarehouseAdd();

signals:
    void mysignal();

private slots:
    // 数据刷新
    void RefreshData();

    // 按钮点击事件
    void on_AddButton1_clicked();
    void on_AddButton2_clicked();
    void on_AddButton3_clicked();
    void on_FindButton_clicked();
    void on_ToAddButton_clicked();
    void on_ExcleButton_clicked();
    void on_ReturnButton_clicked();

    // 编辑框回车事件
    void on_NumEdit_returnPressed();
    void on_FMoldEdit_returnPressed();
    void on_SpareEdit_returnPressed();
    void on_FSpareEdit_returnPressed();
    void on_MaterialEdit_returnPressed();

    // 其他事件
    void closeEvent(QCloseEvent *event);
    void on_NameView_clicked(const QModelIndex &index);
    void on_FMoldEdit_textChanged(const QString &arg1);
    void on_PartCombo_1_currentIndexChanged(const QString &arg1);
    void on_PartCombo_2_currentIndexChanged(const QString &arg1);

private:
    Ui::WarehouseAdd *ui;
    QStandardItemModel *m_model;
    WarehouseDele *m_warehouseDele;
    QMap<QString, QWidget *> m_windowMap;

    // 当前选择的数据
    QString m_currentPart;
    QString m_currentMold;
    QString m_currentSpare;

    // 列表数据
    QStringList m_moldList;
    QStringList m_containerList;
    QStringList m_cabinetList;
};

#endif // WAREHOUSEADD_H
