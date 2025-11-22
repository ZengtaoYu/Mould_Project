#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

// Qt 核心模块
#include <QMainWindow>
#include <QCloseEvent>
#include <QDateTime>
#include <QMap>
#include <QVariant>
#include <QWidget>

// Qt GUI 模块
#include <QMessageBox>

// Qt SQL 模块
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

// Qt 其他模块
#include <QStandardItemModel>

// 项目文件
#include "comom/emailwindow.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit AdminWindow(QVariant db_value, QWidget *parent = nullptr);
    ~AdminWindow();

signals:
    void enablesignal();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_PushButton_clicked();
    void on_EmailButton_clicked();

private:
    // 数据库操作
    bool openDatabase(const QString &dbName);
    void send_message(const QString &dbName);

    // UI 组件
    Ui::AdminWindow *ui;
    EmailWindow *emailWin_;

    // 数据成员
    QVariant dbvalue_;
    QMap<QString, QWidget *> m_windowMap;
    QString databaseName_;
    QString get_email_;
    bool send_flag_;

    // 常量
    static const QStringList DATABASE_NAMES;
    static const QString SYSTEM_USER;
    static const QString EMAIL_WINDOW_TITLE;
};

#endif // ADMINWINDOW_H
