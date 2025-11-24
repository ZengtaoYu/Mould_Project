#ifndef SUMOWINDOW_H
#define SUMOWINDOW_H

// Qt 核心模块
#include <QMainWindow>
#include <QCloseEvent>
#include <QMap>
#include <QModelIndex>
#include <QPointer>
#include <QSystemTrayIcon>
#include <QVariant>
#include <QWidget>

// Qt 前向声明
class QStandardItemModel;
class QTimer;

// 项目前向声明
class AiWindow;
class DatabaseWindow;
class HandleBom;
class HandleMessage;
class HandleWorks;
class SumoAdd;
class SumoEdit;
class SumoEnter;
class SumoKeep;

// XLSX 库（需要完整类型）
#include "xlsxchart.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxdocument.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

namespace Ui {
class SumoWindow;
}

class SumoWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit SumoWindow(QVariant authority, QVariant name, QWidget *mainWin = nullptr, QWidget *parent = nullptr);
    ~SumoWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    // 数据刷新相关
    void refresh_data();
    void refresh_information();
    void on_RefreshButton_clicked();

    // UI 交互相关
    void enable_window();
    bool isProcessRunning(const QString &processName);
    void closeApplication();
    void showWorkMessage();
    void onTrayIconActivated(QSystemTrayIcon::ActivationReason reason);

    // 按钮点击事件
    void on_AIButton_clicked();
    void on_AddButton_clicked();
    void on_BomButton_clicked();
    void on_CheckButton_clicked();
    void on_DeleteButton_clicked();
    void on_EditButton_clicked();
    void on_EnterButton_clicked();
    void on_FindButton_clicked();
    void on_KeepButton_clicked();
    void on_MessageLabel_clicked();
    void on_ReturnButton_clicked();
    void on_WorkButton_clicked();
    void on_commandLinkButton_clicked();

    // 输入控件事件
    void on_MoldID_returnPressed();
    void on_MoldID_textChanged(const QString &arg1);
    void on_ModleList_clicked(const QModelIndex &index);
    void on_ModleList_doubleClicked(const QModelIndex &index);

private:
    // 私有辅助函数
    void sortModelByMaintenanceStatus();

    // UI 相关成员
    Ui::SumoWindow *ui;
    QWidget *mainWindow;
    QMap<QString, QWidget *> m_windowMap;

    // 子窗口成员
    SumoAdd *sumoAdd;
    SumoEdit *sumoEdit;
    SumoEnter *sumoEnter;
    SumoKeep *sumoKeep;
    AiWindow *aiWindow;
    HandleBom *handleBom;
    DatabaseWindow *databaseWin;
    HandleMessage *handleMessage;
    QPointer<HandleWorks> handleWorks;

    // Qt 对象成员
    QTimer *timer;
    QSystemTrayIcon *trayIcon;
    QStandardItemModel *standardModel;

    // 用户权限和身份数据
    QVariant authvalue_;
    QVariant namevalue_;
    QString curr_name;
    bool curr_auth;

    // 模具数据
    QString id_value;
    QXlsx::Format Song12C;

    // 消息和刷新状态
    int message;
    int message_temp;
    int refresh_time;
    bool change_flag;
};

#endif // SUMOWINDOW_H
