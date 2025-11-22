#ifndef NEWWORKER_H
#define NEWWORKER_H

#include <QMainWindow>
#include <QMessageBox>
#include <QModelIndex>
#include <QSqlQuery>
#include <QSqlError>
#include <QStandardItemModel>

namespace Ui {
class NewWorker;
}

class NewWorker : public QMainWindow {
    Q_OBJECT

public:
    explicit NewWorker(QWidget *parent = nullptr);
    ~NewWorker();

private slots:
    // UI槽函数
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_NameEdit_returnPressed();
    void on_UserView_clicked(const QModelIndex &index);
    void on_TypeComb_currentTextChanged(const QString &arg1);

private:
    // 私有辅助函数
    void refreshUserList();
    void addNewWorker();
    bool checkWorkerExists(const QString &workerName, const QString &workerType);
    bool getNextWorkerId(QString &userId, QString &password);
    bool validateWorkerType(const QString &type) const;

    // 成员变量
    Ui::NewWorker *ui;
    QString selected_worker_name;
    QStandardItemModel *user_model;
};

#endif // NEWWORKER_H
