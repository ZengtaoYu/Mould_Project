#ifndef PRODUCTWINDOW_H
#define PRODUCTWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

class QAbstractItemModel;
class QComboBox;
class QSqlQuery;
class QTextStream;

namespace Ui {
class ProductWindow;
}

class ProductWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit ProductWindow(QWidget *parent = nullptr);
    ~ProductWindow();

signals:
    void mysignal();

private slots:
    // 数据刷新
    void RefreshData();

    // 按钮槽函数
    void on_OutButton_clicked();
    void on_SureButton_clicked();
    void on_ReturnButton_clicked();

    // 下拉框槽函数
    void on_MoldCombo_currentIndexChanged(const QString &arg1);
    void on_WorkCombo_currentIndexChanged(const QString &arg1);
    void on_ProductCombo_1_currentIndexChanged(const QString &arg1);
    void on_ProductCombo_2_currentIndexChanged(const QString &arg1);

private:
    // UI初始化相关
    void initializeUI();
    void setupScrollers();
    void setupCompleters();

    // 数据加载相关
    void loadMoldList();
    void loadProductList(const QString &moldId);
    void loadWorkList(const QString &moldId);

    // 工具函数
    QString extractSpareId(const QString &spareName) const;
    void setupCompleterForComboBox(QComboBox *combo, const QStringList &items);
    void setupScrollerForWidget(QWidget *widget);
    void clearLineEditSelection(QComboBox *combo);

    // 数据刷新辅助函数
    void refreshModelData(QStandardItemModel *model, QSqlQuery &query,
        const QString &productComboText, bool isFirstModel);
    void prepareQuery(QSqlQuery &query, const QString &productComboText, bool isFirstModel);
    void exportModelToStream(QTextStream &out, QAbstractItemModel *model);

    Ui::ProductWindow *ui;

    QStringList work;
    QStandardItemModel *model_1;
    QStandardItemModel *model_2;

    // 常量定义
    static const QString ALL_PRODUCTS;
    static const QString ALL_SPARES;
    static const QString TABLE_WORK;
    static const QString TABLE_MESSAGE;
    static const QString STYLE_SHEET;
    static const int MAX_VISIBLE_ITEMS;
    static const int SPARES_PER_LINE;
};

#endif // PRODUCTWINDOW_H
