#ifndef CHONYAWINDOW_H
#define CHONYAWINDOW_H

// Qt标准库
#include <QMainWindow>
#include <QWidget>
#include <QVariant>
#include <QTimer>
#include <QStandardItemModel>
#include <QSystemTrayIcon>
#include <QPointer>
#include <QMap>
#include <QString>

// 第三方库
#include "xlsxdocument.h"

// 前向声明
class QCloseEvent;
class QModelIndex;

namespace Ui {
class ChonyaWindow;
}

// 业务类前向声明
class AiWindow;
class HandleBom;
class ChonyaAdd;
class ChonyaEdit;
class ChonyaKeep;
class ChonyaEnter;
class DatabaseWindow;
class HandleMessage;
class HandleWorks;

class ChonyaWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit ChonyaWindow(QVariant authority, QVariant name, QWidget *mainWin = nullptr, QWidget *parent = nullptr);
    ~ChonyaWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    // 数据刷新相关
    void refresh_data();
    void refresh_information();
    void on_RefreshButton_clicked();

    // UI交互相关
    void enable_windiow();
    void on_MoldID_textChanged(const QString &arg1);
    void on_MoldID_returnPressed();
    void on_ModleList_clicked(const QModelIndex &index);
    void on_ModleList_doubleClicked(const QModelIndex &index);
    void onTrayIconActivated(QSystemTrayIcon::ActivationReason reason);

    // 按钮点击事件
    void on_AddButton_clicked();
    void on_EditButton_clicked();
    void on_DeleteButton_clicked();
    void on_FindButton_clicked();
    void on_EnterButton_clicked();
    void on_KeepButton_clicked();
    void on_WorkButton_clicked();
    void on_CheckButton_clicked();
    void on_ReturnButton_clicked();
    void on_AIButton_clicked();
    void on_BomButton_clicked();
    void on_MessageLabel_clicked();
    void on_commandLinkButton_clicked();

    // 其他功能
    bool isProcessRunning(const QString &processName);
    void closeApplication();
    void showWorkMessage();

private:
    // UI相关
    Ui::ChonyaWindow *ui;
    QWidget *mainWindow;

    // 业务窗口指针
    AiWindow *aiWindow;
    HandleBom *handleBom;
    ChonyaAdd *chonyaAdd;
    ChonyaEdit *chonyaEdit;
    ChonyaKeep *chonyaKeep;
    ChonyaEnter *chonyaEnter;
    DatabaseWindow *databaseWin;
    HandleMessage *handleMessage;
    QPointer<HandleWorks> handleWorks;

    // Qt对象
    QTimer *timer;
    QSystemTrayIcon *trayIcon;
    QStandardItemModel *standardModel;
    QMap<QString, QWidget *> m_windowMap;

    // Excel格式
    QXlsx::Format Song12C;

    // 用户权限和身份
    QVariant authvalue_;
    QVariant namevalue_;
    bool curr_auth;
    QString curr_name;

    // 状态变量
    QString id_value;
    int message;
    int message_temp;
    int refresh_time;
    bool change_flag;

    // 私有辅助函数
    void sortModelByMaintenanceStatus();
};

#endif // CHONYAWINDOW_H
