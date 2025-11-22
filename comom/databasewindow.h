#ifndef DATABASEWINDOW_H
#define DATABASEWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QModelIndex>
#include <QSqlDatabase>
#include <QSqlTableModel>

class QSqlQuery;

namespace Ui {
class DatabaseWindow;
}

class DatabaseWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit DatabaseWindow(QWidget *parent = nullptr);
    ~DatabaseWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    // 数据库操作相关
    void on_pb_connect_clicked();
    void on_pb_showAllDb_clicked();
    void on_pb_showCurDb_clicked();
    void on_pb_openDb_clicked();

    // 表操作相关
    void on_pb_showTable_clicked();
    void on_pb_setTable_clicked();
    void on_pb_showTableData_clicked();
    void on_pb_display_clicked();

    // 数据操作相关
    void on_pb_record_clicked();
    void on_pb_remove_clicked();
    void on_pb_commit_clicked();
    void on_pb_repeal_clicked();
    void on_pb_inquire_clicked();

    // UI辅助函数
    void doMouseTrackTip(QModelIndex index);

private:
    // 辅助函数
    void setPlainText(const QString &text);
    bool checkDatabaseConnection();
    bool executeQueryAndDisplay(QSqlQuery &query, const QString &sql);
    bool validateNumberInput(const QString &input, int &value);
    void updateCurrentDatabaseDisplay(const QString &dbName);

    Ui::DatabaseWindow *ui;

    QSqlDatabase m_myDb;
    QSqlTableModel *m_myModel;
    QString m_currDb;
};

#endif // DATABASEWINDOW_H
