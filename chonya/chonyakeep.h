#ifndef CHONYAKEEP_H
#define CHONYAKEEP_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QCompleter>
#include <QDateTime>
#include <QFileDialog>
#include <QMap>
#include <QMessageBox>
#include <QSettings>
#include <QSqlError>
#include <QSqlQuery>
#include <QStandardPaths>
#include <QStyledItemDelegate>
#include <QThread>
#include <QWidget>

#include "xlsxchart.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxdocument.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

#include "chonya/chonyaenter.h"
#include "comom/handledata.h"

namespace Ui {
class ChonyaKeep;
}

// 状态枚举
enum class MaintenanceState {
    AbnormalRepair = 1,      // 异常维修
    CloseOrderMaintenance = 2, // 关单保养
    LastPieceDefect = 3,     // 末件不良
    RegularMaintenance = 4,  // 定期保养
    MajorMaintenance = 5,    // 大保养
    IdleOver6Months = 6,     // 呆滞6个月以上
    OtherOperation = 7       // 其它操作
};

// 状态标志枚举
enum class StateFlag {
    AbnormalRepairOnly = 10,
    AbnormalRepairCloseOrder = 11,
    AbnormalRepairRegular = 12,
    AbnormalRepairMajor = 13,
    AbnormalRepairIdle = 14,
    CloseOrderOnly = 20,
    CloseOrderRegular = 22,
    CloseOrderMajor = 23,
    CloseOrderIdle = 24,
    LastPieceOnly = 30,
    LastPieceCloseOrder = 31,
    LastPieceRegular = 32,
    LastPieceMajor = 33,
    LastPieceIdle = 34,
    RegularOnly = 40,
    MajorOnly = 50,
    IdleOnly = 60,
    OtherOnly = 70,
    OtherCloseOrder = 71,
    OtherRegular = 72,
    OtherMajor = 73,
    OtherIdle = 74
};

// 字符串常量
namespace MaintenanceConstants {
const QString TITLE_HEADER = "冲压模具";
const QString CLOSE_ORDER_MAINTENANCE = "关单保养";
const QString REGULAR_MAINTENANCE = "定期保养";
const QString MAJOR_MAINTENANCE = "大保养";
const QString IDLE_OVER_6_MONTHS = "呆滞6个月以上";
const QString FEED_PART = "下料零件";
const QString VULNERABLE_PART = "关键易损件";
const QString MOLDING_PART = "成型零件";
const QString WHOLE_MOLD = "整体模具";
}

class ChonyaKeep : public QMainWindow {
    Q_OBJECT

public:
    explicit ChonyaKeep(QVariant id_value, QVariant stata_value, QWidget *parent = nullptr);
    ~ChonyaKeep();

signals:
    void mysignal();

private slots:
    // UI事件处理
    void on_AddCheck_stateChanged(int arg1);
    void on_ChangeCheck_stateChanged(int arg1);
    void on_OtherCheck_stateChanged(int arg1);
    void on_StataDes_currentIndexChanged(const QString &arg1);
    void on_GetButton_clicked();
    void on_HandleButton_clicked();
    void on_ReturnButton_clicked();
    void on_HistoryButton_clicked();
    void on_FinishedButton_clicked();
    void closeEvent(QCloseEvent *event);

private:
    // 数据刷新
    void refresh_data();

    // 初始化相关
    void initializeUI();
    void initializeFormats();
    void initializeCompleters();
    void loadUserData();

    // Excel操作相关
    void writeBasicInfoToExcel(QXlsx::Document &xlsx);
    void writeProductInfoToExcel(QXlsx::Document &xlsx, const QString &cell, const QString &maintenanceType);
    QString getSaveFileName(const QString &title, const QString &defaultName);
    bool saveExcelFile(QXlsx::Document &xlsx, const QString &fileName, const QString &errorTitle);

    // 状态处理相关
    void processStateConfiguration();
    void determineStateAndDescription();
    void handleStateForExcel(int stataFlag);

    // 数据库操作相关
    QString getTableName() const;
    bool queryLatestProductionData(QSqlQuery &query, QString &total, QString &feed,
        QString &vulnerable, QString &molding);
    bool insertProductionData(QSqlQuery &query, const QString &maintenanceType);
    bool updateInformationMessage(QSqlQuery &query, const QString &moldNature);
    bool deleteLatestProductionRecord(QSqlQuery &query);
    bool deleteLatestMaintenanceRecord(QSqlQuery &query);

    // 保养处理相关
    void handleCloseOrderMaintenance();
    void handleRegularMaintenance();
    void handleMajorMaintenance();
    void openProductionInputWindow();

    // 历史记录相关
    QDate getLastMonthDate() const;
    void exportHistoryRecords(const QString &monthFilter, const QString &fileNameSuffix);
    void exportAllHistoryRecords();

    // 工具函数
    bool showError(const QString &title, const QString &message);
    bool showSuccess(const QString &title, const QString &message);
    bool showWarning(const QString &title, const QString &message);
    bool showQuestion(const QString &title, const QString &question);

private:
    Ui::ChonyaKeep *ui;
    HandleData *handleData;
    ChonyaEnter *chonyaEnter;

    int curr_stata;
    int stata_flag;
    bool return_flag;
    QString stata;
    QString stata_des;
    QString title_header;
    QString databaseName;
    QVariant idvalue_;
    QString curr_id;
    QVariant statavalue_;
    QDateTime dateTime;

    // Excel格式
    QXlsx::Format Song10CB;
    QXlsx::Format Song11C;
    QXlsx::Format Song12C;
    QXlsx::Format Song12CB;
    QXlsx::Format Song12CBL;
    QXlsx::Format Song12CCT;

    QMap<QString, QWidget *> m_windowMap;
};

#endif // CHONYAKEEP_H
