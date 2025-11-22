#ifndef SUMOADD_H
#define SUMOADD_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class SumoAdd;
}

class SumoAdd : public QMainWindow {
    Q_OBJECT

public:
    explicit SumoAdd(QWidget *parent = nullptr);
    ~SumoAdd();

signals:
    void mysignal();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_AddButton_clicked();
    void on_OutNum_returnPressed();
    void on_MoldID_returnPressed();
    void on_ProductID_returnPressed();

private:
    // 常量定义
    static constexpr const char *KEEP_STATUS_DEFAULT = "当前无需保养";
    static constexpr int DEFAULT_KEEP_NUM1 = 50000;
    static constexpr int DEFAULT_KEEP_NUM2 = 500000;
    static constexpr int DEFAULT_KEEP_NUM3 = 500000;
    static constexpr int DEFAULT_LIFE_NUM = 200;
    static constexpr int PRODUCT_NUM1_MULTIPLIER = 50;
    static constexpr int PRODUCT_NUM2_MULTIPLIER = 500;

    // 输入验证
    bool validateInput();
    bool validateNumericField(const QString &value, const QString &fieldName);

    // 数据库操作
    bool checkMoldIdExists(const QString &moldId);
    bool insertMoldData();
    bool createMoldTable(const QString &moldId);

    // BOM数据加载
    void loadBomDataByMoldId();
    void loadBomDataByProductId();
    void fillBomDataToUI(const QSqlQuery &query);

    // UI操作
    void clearAndResetUI();

    Ui::SumoAdd *ui;
};

#endif // SUMOADD_H
