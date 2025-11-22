#ifndef HANDLEMESSAGE_H
#define HANDLEMESSAGE_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QSettings>
#include <QDesktopServices>
#include <QUrl>
#include <QScroller>
#include <QAbstractItemView>
#include <QModelIndex>
#include <QVariant>
#include <QMap>
#include <QWidget>
#include <QString>
#include <QTableView>
#include <QList>
#include "xlsxdocument.h"
#include "xlsxformat.h"

// 前向声明
namespace Ui {
class HandleMessage;
}

class ChonyaAdd;
class ChonyaKeep;
class SumoAdd;
class SumoKeep;
class WarehouseAdd;
class WarehouseEnter;
class HandleWorks;
class EmailWindow;

class HandleMessage : public QMainWindow {
    Q_OBJECT

public:
    explicit HandleMessage(QVariant authority, QVariant name, QWidget *parent = nullptr);
    ~HandleMessage();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    // 数据刷新
    void refresh_data();

    // UI事件处理
    void on_CheckButton_clicked();
    void on_EmailButton_clicked();
    void on_HandleButton1_clicked();
    void on_HandleButton2_clicked();
    void on_FinishedButton1_clicked();
    void on_FinishedButton2_clicked();
    void on_UserMessage_clicked(const QModelIndex &index);
    void on_SystemMessage_clicked(const QModelIndex &index);
    void enable_window();

private:
    // 辅助函数
    QString getDatabaseName() const;
    bool isMoldDatabase() const;
    bool isWarehouseDatabase() const;

    // 数据查询相关
    QStandardItemModel *createModelFromQuery(QSqlQuery &query, QTableView *view);
    void setupTableView(QTableView *view, int columnCount, const QList<int> &columnWidths);
    bool updateTaskStatus(const QString &moldId, bool isSystemMessage);
    void exportSystemMessages(const QString &templatePath, const QString &title, const QString &fileName);

    // 处理任务相关
    void handleTask(const QString &moldId, const QString &sparePart);
    void showTaskDialog(bool hasAuth, const QString &moldId, const QString &sparePart);
    void handleMoldDatabaseTask(bool hasAuth, const QString &moldId);
    void handleWarehouseDatabaseTask(bool hasAuth, const QString &moldId, const QString &sparePart);
    void openChonyaAdd();
    void openChonyaKeep(const QString &moldId);
    void openSumoAdd();
    void openSumoKeep(const QString &moldId);
    void openWarehouseAdd();
    void openWarehouseEnter(const QString &moldId, const QString &sparePart);
    void openHandleWorks(const QString &moldId);

    // UI指针成员
    Ui::HandleMessage *ui;

    // 窗口指针成员
    SumoAdd *sumoAdd;
    SumoKeep *sumoKeep;
    ChonyaAdd *chonyaAdd;
    ChonyaKeep *chonyaKeep;
    WarehouseAdd *warehouseAdd;
    WarehouseEnter *warehouseEnter;
    HandleWorks *handleWorks;
    EmailWindow *emailWin;

    // 数据模型指针
    QStandardItemModel *standardModel1;
    QStandardItemModel *standardModel2;

    // 窗口映射
    QMap<QString, QWidget *> m_windowMap;

    // Excel格式
    QXlsx::Format Song12C;

    // 用户信息
    QVariant namevalue_;
    QVariant authvalue_;
    QString curr_name;
    bool curr_auth;
    QString curr_user;

    // 当前选择的数据
    QString spare;
    QString id_value1;
    QString id_value2;

    // 常量定义
    static const int EXCEL_START_ROW = 4;
    static const int COLUMN_COUNT_MOLD = 4;
    static const int COLUMN_COUNT_USER = 5;
};

#endif // HANDLEMESSAGE_H
