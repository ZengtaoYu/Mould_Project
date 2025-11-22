#ifndef WAREHOUSECHANGE_H
#define WAREHOUSECHANGE_H

#include <QMainWindow>
#include <QVariant>
#include <QString>

namespace Ui {
class WarehouseChange;
}

class WarehouseChange : public QMainWindow {
    Q_OBJECT

public:
    explicit WarehouseChange(QVariant id_value, QVariant part, QWidget *parent = nullptr);
    ~WarehouseChange();

signals:
    void mysignal();

private slots:
    void on_EditButton_clicked();

private:
    // 辅助函数
    bool initializeContainerCombo();
    bool loadMoldData();
    bool executeQuery(const QString &sql, const QString &errorTitle);
    bool validateInput() const;

    // 成员变量
    Ui::WarehouseChange *ui;
    QVariant idvalue_;
    QString curr_id;
    QVariant partvalue_;
    QString curr_part;
};

#endif // WAREHOUSECHANGE_H
