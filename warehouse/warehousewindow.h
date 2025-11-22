#ifndef WAREHOUSEWINDOW_H
#define WAREHOUSEWINDOW_H

// ==================== Qt标准库 ====================
#include <QMainWindow>
#include <QCloseEvent>
#include <QDateTime>
#include <QDebug>
#include <QInputDialog>
#include <QItemSelectionModel>
#include <QLineEdit>
#include <QMap>
#include <QMessageBox>
#include <QMovie>
#include <QPointer>
#include <QProgressDialog>
#include <QSettings>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QStandardItemModel>
#include <QString>
#include <QSystemTrayIcon>
#include <QTableView>
#include <QTimer>
#include <QTreeView>
#include <QVariant>
#include <QWidget>

// ==================== Qt第三方库 ====================
#include "xlsxformat.h"

// ==================== 前向声明 ====================
class QModelIndex;
class QStandardItem;
class QStandardItemModel;
class QSystemTrayIcon;

namespace Ui {
class WarehouseWindow;
}

// 业务类前向声明
class AiWindow;
class DatabaseWindow;
class HandleData;
class HandleMessage;
class HandleWorks;
class MainWidget;
class ProductWindow;
class SpareWindow;
class WarehouseAdd;
class WarehouseChange;
class WarehouseDele;
class WarehouseEdit;
class WarehouseEnter;
class WarehouseOut;

/**
 * @brief 仓库管理主窗口类
 *
 * 负责模具和备件的管理，包括：
 * - 模具和备件的查询、添加、修改、删除
 * - 库存管理（入库、出库）
 * - 数据导出和报表生成
 * - 工单管理
 * - 消息通知
 */
class WarehouseWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit WarehouseWindow(QVariant authority, QVariant name, QWidget *mainWin = nullptr, QWidget *parent = nullptr);
    ~WarehouseWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    // ==================== 数据刷新相关 ====================
    void refresh_data();
    void refresh_datac();
    void refresh_information();
    void Product_Refresh();
    void finishDataLoading();  // 完成数据加载后的处理
    void startProgressiveLoad(const QString &moldFilter = "", const QString &spareFilter = "",
        int tabIndex = -1);  // 启动分批加载
    void loadBatchCyView();  // 分批加载 CyView
    void loadBatchCxView();  // 分批加载 CxView

    // ==================== 备件管理相关（冲压/成型标签页） ====================
    void on_AddButton_clicked();
    void on_OutButton_clicked();
    void on_EnterButton_clicked();
    void on_EditButton_clicked();
    void on_DeleteButton_clicked();
    void on_FindButton_clicked();
    void on_RefreshButton_clicked();
    void on_CheckButton_clicked();
    void on_ManageButton_clicked();
    void on_ProductButton_clicked();
    void on_WorkButton_clicked();
    void on_AIButton_clicked();
    void on_MessageLabel_clicked();
    void on_ReturnButton_clicked();
    void on_commandLinkButton_clicked();
    void on_BomButton_clicked();

    // 编辑框事件（备件管理）
    void on_MoldEdit_returnPressed();
    void on_SpareEdit_returnPressed();
    void on_MoldEdit_textChanged(const QString &arg1);

    // 视图点击事件（备件管理）
    void on_CyView_clicked(const QModelIndex &index);
    void on_CxView_clicked(const QModelIndex &index);

    // ==================== 模具管理相关（模具列表标签页） ====================
    void on_OutButtonc_clicked();
    void on_EnterButtonc_clicked();
    void on_DeleteButtonc_clicked();
    void on_FindButtonc_clicked();
    void on_RefreshButtonc_clicked();
    void on_ChangeButtonc_clicked();
    void on_WorkButtonc_clicked();
    void on_AIButtonc_clicked();
    void on_MessageLabelc_clicked();
    void on_ReturnButtonc_clicked();
    void on_commandLinkButtonc_clicked();

    // 编辑框事件（模具管理）
    void on_MoldEditc_returnPressed();
    void on_MaterialEditc_returnPressed();
    void on_MoldEditc_textChanged(const QString &arg1);

    // 视图点击事件（模具管理）
    void on_ModleList1_clicked(const QModelIndex &index);
    void on_ModleList2_clicked(const QModelIndex &index);

    // ==================== 其他功能 ====================
    void on_tabWidget_currentChanged(int index);
    void onTrayIconActivated(QSystemTrayIcon::ActivationReason reason);
    void showWorkMessage();
    void enable_windiow();

private:
    // ==================== UI相关 ====================
    Ui::WarehouseWindow *ui;
    QWidget *mainWindow;
    QMap<QString, QWidget *> m_windowMap;

    // ==================== 业务窗口指针 ====================
    AiWindow *aiWindow;
    DatabaseWindow *databaseWin;
    HandleData *handleData;
    HandleMessage *handleMessage;
    QPointer<HandleWorks> handleWorks;
    MainWidget *workWin;
    ProductWindow *productWin;
    SpareWindow *spareWin;
    WarehouseAdd *warehouseAdd;
    WarehouseChange *warehouseChange;
    WarehouseDele *warehouseDele;
    WarehouseEdit *warehouseEdit;
    WarehouseEnter *warehouseEnter;
    WarehouseOut *warehouseOut;

    // ==================== 数据模型 ====================
    QStandardItemModel *standardModel1;  // 冲压模具列表模型
    QStandardItemModel *standardModel2;  // 成型模具列表模型
    QStandardItemModel *model1;  // CyView 树形模型
    QStandardItemModel *model2;  // CxView 树形模型

    // ==================== 定时器和系统托盘 ====================
    QTimer *timer;  // 信息刷新定时器
    QTimer *loadTimer1;  // CyView 分批加载定时器
    QTimer *loadTimer2;  // CxView 分批加载定时器
    QSystemTrayIcon *trayIcon;  // 系统托盘图标
    QProgressDialog *progressDialog;  // 数据加载进度对话框

    // ==================== 用户权限和配置 ====================
    QVariant authvalue_;  // 权限值
    bool curr_auth;  // 当前权限状态
    QVariant namevalue_;  // 用户名值
    QString curr_name;  // 当前用户名
    QXlsx::Format Song12C;  // Excel格式设置

    // ==================== 当前选择的数据 ====================
    QString mold_id;  // 当前选中的模具编号
    QString spare_id;  // 当前选中的备件号
    QString cabinet;  // 当前选中的存放柜号

    // ==================== 消息通知相关 ====================
    bool change_flag;  // 消息变化标志
    int message;  // 当前消息数量
    int message_temp;  // 临时消息数量（用于比较）
    int refresh_time;  // 刷新计时器

    // ==================== 分批加载相关 ====================
    QList<QSqlRecord> pendingRecords1;  // CyView 待加载数据
    QList<QSqlRecord> pendingRecords2;  // CxView 待加载数据
    QMap<QString, int> moldCountMap1;   // 模具计数映射（CyView）
    QMap<QString, int> moldCountMap2;   // 模具计数映射（CxView）
    QMap<QString, QStandardItem *> topItems1;  // 顶层节点映射（CyView）
    QMap<QString, QStandardItem *> topItems2;  // 顶层节点映射（CxView）
    int batchSize;  // 每批加载数量
    int totalRecordsToLoad;  // 总记录数
    int loadedRecordsCount;  // 已加载记录数
};

#endif // WAREHOUSEWINDOW_H
