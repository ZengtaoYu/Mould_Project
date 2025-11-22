#ifndef WAREHOUSEMOLD_H
#define WAREHOUSEMOLD_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlError>
#include <QScroller>
#include <QMessageBox>
#include <QStandardItemModel>

namespace Ui {
class WarehouseMold;
}

class WarehouseMold : public QMainWindow {
    Q_OBJECT

public:
    explicit WarehouseMold(QVariant part_value, QVariant mold_value, QWidget *parent = nullptr);
    ~WarehouseMold();

signals:
    void mysignal();

private slots:
    void on_EditButton_clicked();
    void on_FindButton_clicked();
    void on_ReturnButton_clicked();
    void on_FMoldEdit_returnPressed();
    void on_ChangeButton_toggled(bool checked);
    void on_MoldView_clicked(const QModelIndex &index);

private:
    // 辅助函数
    void initializeUI();
    void setupScroller();
    void loadMoldList();
    void selectInitialMold(const QString &mold_value);
    void loadMoldDetails(const QString &mold_id);
    void updateMoldView(const QString &part_name);
    void searchMold(const QString &search_text);
    QString getPartName() const;
    int getSpareCount(const QString &mold_id);

    // 成员变量
    Ui::WarehouseMold *ui;
    QString part;
    QVariant moldvalue_;
    QString mold;

    // 常量
    static const QString PART_CHENGXING;
    static const QString PART_CHONYA;
    static const QString PART_NAME_CHENGXING;
    static const QString PART_NAME_CHONYA;
};

#endif // WAREHOUSEMOLD_H
