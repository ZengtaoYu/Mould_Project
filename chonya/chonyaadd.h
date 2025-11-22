#ifndef CHONYAADD_H
#define CHONYAADD_H

#include <QMainWindow>
#include <QMessageBox>
#include <QMovie>
#include <QRegExp>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

namespace Ui {
class ChonyaAdd;
}

class ChonyaAdd : public QMainWindow {
    Q_OBJECT

public:
    explicit ChonyaAdd(QWidget *parent = nullptr);
    ~ChonyaAdd();

signals:
    void mysignal();

private slots:
    void on_AddButton_clicked();
    void on_MoldID_returnPressed();
    void on_MachineNum_returnPressed();

private:
    // 数据验证函数
    bool validateInput();
    bool validateNumericValue(const QString &value, const QString &fieldName);

    // 数据库操作函数
    bool checkMoldIdExists(const QString &moldId);
    bool insertMoldData();
    bool createMoldTable(const QString &moldId);
    bool addMoldWithTransaction();

    // UI操作函数
    void clearForm();
    void loadBomData(const QString &moldId);

private:
    Ui::ChonyaAdd *ui;
    QMovie *m_movie;
};

#endif // CHONYAADD_H
