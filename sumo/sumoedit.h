#ifndef SUMOEDIT_H
#define SUMOEDIT_H

#include <QMainWindow>
#include <QMap>
#include <QString>
#include <QVariant>

class QCloseEvent;
class QWidget;
class QListView;
class QScroller;

namespace Ui {
class SumoEdit;
}

class NewWorker;

class SumoEdit : public QMainWindow {
    Q_OBJECT

public:
    explicit SumoEdit(QVariant id_value, QWidget *parent = nullptr);
    ~SumoEdit();

signals:
    void mysignal();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_AddButton_clicked();
    void on_EditButton_clicked();
    void on_DeleButton_clicked();
    void on_NameButton_clicked();
    void on_MachineNum_returnPressed();

private:
    // 初始化相关
    void initializeUI();
    bool loadMoldData();
    void loadMachineList(const QString &machineField);

    // 机台管理相关
    bool addMachine(const QString &machineNum);
    bool removeMachine();
    QString buildMachineString(const QString &excludeMachine = QString()) const;
    QString sanitizeMachineNumber(const QString &input) const;
    bool isMachineExists(const QString &machine) const;

    // 数据验证相关
    bool validateMoldId() const;
    bool validateEditInputs() const;
    bool validateNumericInput(const QString &value, const QString &fieldName) const;

    // 数据库操作相关
    bool updateMoldData();
    bool updateMachineData(const QString &machineString);

    // 成员变量
    Ui::SumoEdit *ui;
    NewWorker *newWorker;

    QString curr_id;
    QMap<QString, QWidget *> m_windowMap;
};

#endif // SUMOEDIT_H
