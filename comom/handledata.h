#ifndef HANDLEDATA_H
#define HANDLEDATA_H

#include <QMainWindow>
#include <QVariant>
#include <QCloseEvent>
#include <QShowEvent>
#include <QSqlTableModel>

namespace Ui {
class HandleData;
}

// 常量定义
namespace HandleDataConstants {
// 数据库和表名常量
constexpr const char *DATABASE_CHONYA = "chonya";
constexpr const char *TABLE_KEEP_MESSAGE = "keep_message";
constexpr const char *TABLE_CHENGXING_WORK = "chengxing_work";
constexpr const char *TABLE_CHENGXING_MESSAGE = "chengxing_message";

// 选择类型常量
constexpr const char *SELECT_TYPE_MOLD = "mold";
constexpr const char *SELECT_TYPE_KEEP = "keep";
constexpr const char *SELECT_TYPE_MESSAGE = "message";

// 显示后缀常量
constexpr const char *SUFFIX_WEIGHT = "w";
constexpr const char *SUFFIX_COUNT = "kpcs";

// 列索引常量
constexpr int COLUMN_INDEX_3 = 3;
constexpr int COLUMN_INDEX_4 = 4;
constexpr int COLUMN_INDEX_5 = 5;
constexpr int COLUMN_INDEX_6 = 6;
constexpr int COLUMN_INDEX_7 = 7;

// 日期相关常量
constexpr const char *DATE_ALL = "全部";
constexpr const char *DATE_MONTH_SEPARATOR = "月";
constexpr const char *DATE_DOT = ".";
}

class CustomSqlModel : public QSqlTableModel {
    Q_OBJECT
public:
    explicit CustomSqlModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

class HandleData : public QMainWindow {
    Q_OBJECT

public:
    explicit HandleData(QVariant id_value, QVariant select_value, QWidget *parent = nullptr);
    ~HandleData();

signals:
    void mysignal();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    // 数据操作槽函数
    void on_AddButton_clicked();
    void on_DeleteButton_clicked();
    void on_PushButton_clicked();
    void on_ReturnButton_clicked();

    // 查找相关槽函数
    void on_FindButton_clicked();
    void on_LineEdit_returnPressed();
    void on_LineEdit_textChanged(const QString &arg1);

    // 视图交互槽函数
    void on_tableView_clicked(const QModelIndex &index);
    void doMouseTrackTip(QModelIndex index);

protected:
    void showEvent(QShowEvent *event) override;

private:
    // 辅助函数
    QString extractDateFromComboBox() const;
    void performSearch(const QString &searchField, const QString &searchValue);
    QString escapeSqlString(const QString &str) const;
    bool validateRowIndex(int row) const;
    int getNextIdValue() const;
    void loadTableData();  // 延迟加载数据
    void setupTableView();  // 设置表格视图

    // 成员变量
    Ui::HandleData *ui;
    QVariant idvalue_;
    QVariant selectvalue_;
    QString select_str;
    CustomSqlModel myModel;
    QString table;
    bool m_dataLoaded;  // 标记数据是否已加载
};

#endif // HANDLEDATA_H
