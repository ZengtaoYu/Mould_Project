#ifndef SUMOENTER_H
#define SUMOENTER_H

#include <QMainWindow>
#include <QTimer>
#include <QVariant>
#include <QtCharts>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlError>
#include <QCompleter>
#include "comom/handledata.h"
#include "xlsxchart.h"
#include "xlsxworkbook.h"
#include "xlsxdocument.h"
#include "xlsxcellrange.h"
#include "xlsxrichstring.h"
#include "xlsxchartsheet.h"

namespace Ui {
class SumoEnter;
}

class SumoEnter : public QMainWindow {
    Q_OBJECT

public:
    explicit SumoEnter(QVariant id_value, QWidget *parent = nullptr);
    ~SumoEnter();

signals:
    void mysignal();

protected:
    void closeEvent(QCloseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    // 初始化相关
    void refresh_data();
    void init_MachineView();
    int init_information(const QString &set_name);

    // UI事件处理
    void on_NewButton_clicked();
    void on_GetButton_clicked();
    void on_PlotButton_clicked();
    void on_EnterButton_clicked();
    void on_CheckButton_clicked();
    void on_ReturnButton_clicked();
    void on_ProductNum_returnPressed();
    void on_MachineNum_2_returnPressed();
    void on_MachineView_clicked(const QModelIndex &index);
    void on_MoldCombo_currentTextChanged(const QString &arg1);

private:
    // 常量定义
    static constexpr int MOLD_LIFETIME_LIMIT = 2000000;
    static constexpr int WARNING_THRESHOLD = 80;
    static constexpr int CRITICAL_THRESHOLD = 90;
    static constexpr double CONVERSION_FACTOR = 1000.0;
    static constexpr int CHART_DATA_LIMIT = 10;
    static constexpr int CHART_WIDTH = 800;
    static constexpr int CHART_HEIGHT = 600;
    static const QString ADMIN_SECRET;
    static const QString SYSTEM_USER;
    static const QString REGULAR_MAINTENANCE;
    static const QString SPECIAL_MAINTENANCE;
    static const QString MAJOR_MAINTENANCE;
    static const QString OVERALL_MOLD;
    static const QString REPAIR_TYPE;
    static const QString ALL_USERS;

    // 辅助函数
    void enterProductData();
    void updateKeepStatusLabels(float keep_num1, float keep_num2, float keep_num3, int total,
        float set_keep_num1, float set_keep_num2, float set_keep_num3);
    bool verifyAdminSecret();
    QString buildTableName(const QString &mold_id);
    void cleanupWindows();

    // UI组件
    Ui::SumoEnter *ui;
    HandleData *handleData;

    // 数据成员
    QVariant idvalue_;
    QString curr_id;
    QStringList data;
    QLineSeries *series;
    QChartView *chartView;
    QXlsx::Format Song12C;
    QStandardItemModel *model;
    QMap<QString, QWidget *> m_windowMap;

    int out_num;
    int set_product_num1;
    int set_product_num2;
    bool mold_static1;
    bool mold_static2;
    bool mold_static3;
    bool mold_static4;
    QString table;
    QString date_str;
    QString machine_num;
};

#endif // SUMOENTER_H
