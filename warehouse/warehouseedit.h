#ifndef WAREHOUSEEDIT_H
#define WAREHOUSEEDIT_H

#include <QMainWindow>
#include <QMap>
#include <QString>
#include <QVariant>
#include <QCompleter>
#include "warehouse/warehousemold.h"

class QComboBox;
class QWidget;
class QCloseEvent;
class QObject;
class QEvent;

namespace Ui {
class WarehouseEdit;
}

class WarehouseEdit : public QMainWindow {
    Q_OBJECT

public:
    explicit WarehouseEdit(QVariant part_value, QVariant mold_value, QVariant id_value, QVariant cabinet_value,
        QWidget *parent = nullptr);
    ~WarehouseEdit();

signals:
    void mysignal();

protected:
    void closeEvent(QCloseEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void on_MoldButton_clicked();
    void on_EditButton_clicked();
    void on_ReturnButton_clicked();
    void on_OutNum_valueChanged(int arg1);
    void on_FirstNum_valueChanged(int arg1);
    void on_EnterNum_valueChanged(int arg1);
    void on_MoldCombo_highlighted(const QString &arg1);
    void on_IDCombo_currentIndexChanged(const QString &arg1);
    void send_signal();

private:
    // 初始化方法
    void initializeComboBoxes();
    void setupComboBoxScroller(QComboBox *combo);
    void loadInitialData();
    void loadIDList();
    void loadMoldList();
    void loadCabinetList();
    void loadWarehouseData();
    void updatePartLabel(const QString &moldId);

    // 辅助方法
    bool executeQueryWithErrorHandling(const QString &title, const QString &errorMessage);
    bool checkSparePartExists() const;
    QString getMoldPID() const;
    bool updateWarehouseData();
    void handleLowStockNotification();
    void removeLowStockNotification();
    void loadSparePartData(const QString &id);
    QCompleter *createCompleter(const QStringList &items, QComboBox *combo) const;

    // 验证方法
    bool validateInput() const;

    // UI成员
    Ui::WarehouseEdit *ui;
    WarehouseMold *warehouseMold;
    QMap<QString, QWidget *> m_windowMap;

    // 常量成员变量
    const QVariant partvalue_;
    const QString curr_part;
    const QVariant moldvalue_;
    const QVariant idvalue_;
    const QVariant cabinetvalue_;

    // 状态成员变量
    int out_num;
    int first_num;
    int enter_num;

    // 常量定义
    static const int MAX_VISIBLE_ITEMS = 10;
    static const QString DATE_TIME_FORMAT;
    static const QString SYSTEM_USER;
    static const QString ALL_USERS;
};

#endif // WAREHOUSEEDIT_H
