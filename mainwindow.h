#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Qt Core
#include <QCloseEvent>
#include <QDateTime>
#include <QFile>
#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QTimer>
#include <QProcess>

// Qt Network
#include <QtNetwork/QLocalServer>
#include <QtNetwork/QLocalSocket>

// Qt GUI
#include <QInputDialog>
#include <QLineEdit>
#include <QMovie>
#include <QStandardPaths>

// Qt Core Application
#include <QCoreApplication>

// Project Headers
#include "chonya/chonyawindow.h"
#include "comom/adminwindow.h"
#include "comom/databasewindow.h"
#include "comom/registerwindow.h"
#include "sumo/sumowindow.h"
#include "warehouse/warehousewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showAndActivate(); // 显示并激活窗口

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    // UI Event Handlers
    void on_LoginButton_clicked();
    void on_RegisterButton_clicked();
    void on_DataBaseButton_clicked();
    void on_LinkButton_clicked();
    void on_pushButton_clicked();
    void on_UserEdit_returnPressed();
    void on_PasswdEdit_returnPressed();
    void on_checkBox_stateChanged(int arg1);
    void on_PartCombo_currentIndexChanged(const QString &arg1);

    // Timer
    void refresh_time();

    // LocalServer - 接收新实例消息
    void handleNewConnection();

private:
    // Helper Methods
    void performLogin();

    // UI
    Ui::MainWindow *ui;

    // Window Pointers
    SumoWindow *m_sumoWin;
    AdminWindow *m_adminWin;
    ChonyaWindow *m_chonyaWin;
    RegisterWindow *m_registerWin;
    DatabaseWindow *m_databaseWin;
    WarehouseWindow *m_warehouseWin;

    // Timer
    QTimer *m_timer;

    // LocalServer
    QLocalServer *m_localServer;

    // 当前活动窗口
    QWidget *m_activeWindow;

    // Database
    QSqlDatabase m_db;
    QString m_dbIP;
    int m_dbPort;
    QString m_partText;
    QString m_partName;

    // User Info
    QString m_userName;
    bool m_authority;
    bool m_isRemember;

    // Application
    QString m_appVersion;
    int m_adminClickCount;
};
#endif // MAINWINDOW_H
