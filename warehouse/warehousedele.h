#ifndef WAREHOUSEDELE_H
#define WAREHOUSEDELE_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSettings>
#include <QScroller>
#include <QMessageBox>
#include <QStandardItemModel>

namespace Ui {
class WarehouseDele;
}

class WarehouseDele : public QMainWindow {
    Q_OBJECT

public:
    explicit WarehouseDele(QWidget *parent = nullptr);
    ~WarehouseDele();

signals:
    void mysignal();

private slots:
    // UI事件处理槽函数
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_CabinetEdit_returnPressed();
    void on_ChangeButton_toggled(bool checked);
    void on_ChangeButtonc_clicked(bool checked);
    void on_PIDView_clicked(const QModelIndex &index);

private:
    // 辅助函数
    void Find_ID(const QString &sql, const QString &columnName);
    void refreshMoldList();
    void refreshCabinetList();
    void refreshContainerList();

    // 删除相关函数
    bool deleteMold();
    bool deleteSparePartCabinet();
    bool deleteMoldCabinet();

    // 添加相关函数
    void addCabinet();
    bool insertCabinet(const QString &tableName, const QString &cabinetName);
    void updateUIAfterAddCabinet(const QString &cabinetType);

    // 工具函数
    QString getSparePartTableName() const;
    QString getMoldTableName() const;
    QString getSparePartCabinetColumn() const;
    QString getMoldCabinetColumn() const;

private:
    Ui::WarehouseDele *ui;

    // 状态变量
    bool state;              // 当前状态：false=模具模式，true=货柜模式
    QString part;            // 当前部门："冲压" 或 "成型"
    QString save;            // 当前货柜类型："备件货柜" 或 "模具货柜"
    QString search;          // 当前搜索字段名
    QString id_value;        // 当前选中的ID值
    QString nameCount;       // 备件数量

    // 字符串常量
    static const QString PART_STAMPING;      // "冲压"
    static const QString PART_FORMING;      // "成型"
    static const QString CABINET_SPARE;     // "备件货柜"
    static const QString CABINET_MOLD;      // "模具货柜"
    static const QString COLUMN_MOLD_ID;    // "模具编号"
    static const QString COLUMN_CABINET_NAME; // "货柜名称"
};

#endif // WAREHOUSEDELE_H
