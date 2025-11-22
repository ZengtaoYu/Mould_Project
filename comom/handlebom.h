#ifndef HANDLEBOM_H
#define HANDLEBOM_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QTableView>
#include <QModelIndex>
#include <QString>
#include <QList>

class QScroller;
class QToolTip;
class QMessageBox;

namespace Ui {
class HandleBom;
}

// 表配置结构体
struct TableConfig {
    QString tableName;           // 数据库表名
    QString searchColumn;       // 搜索字段名
    QString searchPlaceholder;  // 搜索提示文本
    bool autoIncrementId;       // 是否自动递增ID
};

class HandleBom : public QMainWindow {
    Q_OBJECT

public:
    explicit HandleBom(QWidget *parent = nullptr);
    ~HandleBom();

private slots:
    // 现状BOM相关槽函数
    void on_AddButton_clicked();
    void on_PushButton_clicked();
    void on_FindButton_clicked();
    void on_ReturnButton_clicked();
    void on_DeleteButton_clicked();
    void on_LineEdit_returnPressed();
    void on_LineEdit_textChanged(const QString &arg1);

    // 理论BOM相关槽函数
    void on_AddButton_1_clicked();
    void on_PushButton_1_clicked();
    void on_FindButton_1_clicked();
    void on_ReturnButton_1_clicked();
    void on_DeleteButton_1_clicked();
    void on_LineEdit_1_returnPressed();
    void on_LineEdit_1_textChanged(const QString &arg1);

    // 废料价格相关槽函数
    void on_AddButton_2_clicked();
    void on_PushButton_2_clicked();
    void on_FindButton_2_clicked();
    void on_ReturnButton_2_clicked();
    void on_DeleteButton_2_clicked();
    void on_LineEdit_2_returnPressed();
    void on_LineEdit_2_textChanged(const QString &arg1);

    // 纸箱、吸塑盒单价相关槽函数
    void on_AddButton_3_clicked();
    void on_PushButton_3_clicked();
    void on_FindButton_3_clicked();
    void on_ReturnButton_3_clicked();
    void on_DeleteButton_3_clicked();
    void on_LineEdit_3_returnPressed();
    void on_LineEdit_3_textChanged(const QString &arg1);

    // 工时相关槽函数
    void on_AddButton_4_clicked();
    void on_PushButton_4_clicked();
    void on_FindButton_4_clicked();
    void on_ReturnButton_4_clicked();
    void on_DeleteButton_4_clicked();
    void on_LineEdit_4_returnPressed();
    void on_LineEdit_4_textChanged(const QString &arg1);

    // 机台成本相关槽函数
    void on_AddButton_5_clicked();
    void on_PushButton_5_clicked();
    void on_FindButton_5_clicked();
    void on_ReturnButton_5_clicked();
    void on_DeleteButton_5_clicked();
    void on_LineEdit_5_returnPressed();
    void on_LineEdit_5_textChanged(const QString &arg1);

    // 鼠标悬停提示
    void doMouseTrackTip(QModelIndex index);

    // 标签页切换（延迟加载）
    void on_tabWidget_currentChanged(int index);

private:
    Ui::HandleBom *ui;

    // 使用容器管理模型
    QList<QSqlTableModel *> m_models;
    QList<QTableView *> m_tableViews;

    // 表配置信息
    static const QList<TableConfig> s_tableConfigs;

    // 初始化函数
    void initializeModels();
    void setupTableView(int index, QTableView *tableView, QSqlTableModel *model);
    void setupScroller(QTableView *tableView);
    void loadTableData(int modelIndex);  // 延迟加载数据

    // 公共操作函数
    void submitChanges(int modelIndex);
    void revertChanges(int modelIndex);
    void addRecord(int modelIndex, bool autoIncrementId = true);
    void deleteRecord(int modelIndex, QTableView *tableView);
    void searchRecord(int modelIndex, const QString &searchText, const QString &columnName);
    void resetTableFilter(int modelIndex);

    // 辅助函数
    bool isValidModelIndex(int index) const;
    QString buildSearchFilter(const QString &columnName, const QString &searchText) const;
    void showErrorMessage(const QString &title, const QString &message);

    // 性能优化相关
    bool m_dataLoaded[6];  // 标记每个表是否已加载数据
};

#endif // HANDLEBOM_H
