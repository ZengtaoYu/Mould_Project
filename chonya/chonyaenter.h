#ifndef CHONYAENTER_H
#define CHONYAENTER_H

#include <QMainWindow>
#include <QtCharts>

#include "xlsxrichstring.h"

#include "comom/handledata.h"

namespace Ui {
class ChonyaEnter;
}

class ChonyaEnter : public QMainWindow {
    Q_OBJECT

public:
    explicit ChonyaEnter(QVariant id_value, QWidget *parent = nullptr);
    ~ChonyaEnter();

signals:
    void mysignal();

protected:
    void closeEvent(QCloseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    // 初始化相关
    void refresh_data();
    void init_MachineView();
    bool init_information(const QString &set_name);

    // UI事件处理 - 按钮点击
    void on_GetButton_clicked();
    void on_NewButton_clicked();
    void on_PlotButton_clicked();
    void on_CheckButton_clicked();
    void on_EnterButton_clicked();
    void on_ReturnButton_clicked();

    // UI事件处理 - 输入框回车
    void on_UserEdit_returnPressed();
    void on_ProductNum_2_returnPressed();
    void on_MachineNum_2_returnPressed();

    // UI事件处理 - 其他
    void on_MachineView_clicked(const QModelIndex &index);
    void on_MoldCombo_currentTextChanged(const QString &arg1);

private:
    // UI相关
    Ui::ChonyaEnter *ui;
    HandleData *handleData;

    // 数据模型和视图
    QStandardItemModel *model;
    QLineSeries *series;
    QChartView *chartView;
    QXlsx::Format Song12C;
    QMap<QString, QWidget *> m_windowMap;

    // 自动完成器（使用容器管理）
    QList<QCompleter *> nameCompleters;

    // 只读成员变量
    const QVariant idvalue_;

    // 字符串数据
    QString curr_id;
    QStringList data;
    QString table;
    QString date_str;
    QString machine_num;

    // 数值成员变量
    int out_num;
    int control_stand;
    bool mold_static1;
    bool mold_static2;
    bool mold_static3;
    bool mold_static4;
};

#endif // CHONYAENTER_H
