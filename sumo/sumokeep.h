#ifndef SUMOKEEP_H
#define SUMOKEEP_H

#include <QMainWindow>
#include <QDateTime>
#include <QMap>
#include <QVariant>
#include <QString>
#include "xlsxdocument.h"

// 前向声明
class QWidget;
class QCloseEvent;

namespace Ui {
class SumoKeep;
}

class SumoEnter;
class HandleData;

class SumoKeep : public QMainWindow {
    Q_OBJECT

public:
    explicit SumoKeep(QVariant id_value, QVariant stata_value, QWidget *parent = nullptr);
    ~SumoKeep();

signals:
    void mysignal();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    // UI事件处理
    void on_GetButton_clicked();
    void on_ReturnButton_clicked();
    void on_HistoryButton_clicked();
    void on_FinishedButton_clicked();
    void on_AddCheck_stateChanged(int arg1);
    void on_ChangeCheck_stateChanged(int arg1);

    // 数据刷新
    void refresh_data();

private:
    // 辅助函数 - 初始化
    void initializeUI();
    void initializeFormats();
    void initializeUserData();
    void setupCompleters(const QStringList &data1, const QStringList &data2);
    void configureUIByState();

    // 辅助函数 - 保养完成相关
    bool validateInput();
    bool insertProductionData();
    bool updateInformationMessage();
    void showSumoEnterWindow();
    QString buildStatusDescription();
    bool insertKeepMessage(const QString &statusDesc);

    // 辅助函数 - 历史记录导出
    void exportHistoryData(int monthOffset);
    bool exportToExcel(const QString &sql, const QString &defaultFileName);

    // 辅助函数 - 撤回相关
    bool deleteProductionData();
    bool deleteKeepMessage();

    // 辅助函数 - 工具函数
    QString buildTableName(const QString &moldId) const;
    void cleanupWindows();

    // UI组件
    Ui::SumoKeep *ui;
    SumoEnter *sumoEnter;
    HandleData *handleData;

    // 数据成员
    const QVariant idvalue_;
    const QVariant statavalue_;
    QString curr_id;
    int curr_stata;
    bool return_flag;
    QDateTime dateTime;
    QXlsx::Format Song12C;
    QXlsx::Format Song12CB;
    QMap<QString, QWidget *> m_windowMap;

    // 状态相关
    int stata_flag;
    int set_product_num1;
    int set_product_num2;
    QString stata;
    QString title_header;
    QString databaseName;
};

#endif // SUMOKEEP_H
