#ifndef CHONYAEDIT_H
#define CHONYAEDIT_H

#include <QMainWindow>
#include <QVariant>
#include <QString>

class QListView;
class QSqlQuery;

namespace Ui {
class ChonyaEdit;
}

class ChonyaEdit : public QMainWindow {
    Q_OBJECT

public:
    explicit ChonyaEdit(QVariant id_value, QWidget *parent = nullptr);
    ~ChonyaEdit();

signals:
    void mysignal();

private slots:
    void on_AddButton_clicked();
    void on_EditButton_clicked();
    void on_DeleButton_clicked();
    void on_NameButton_clicked();
    void on_MachineNum_returnPressed();

private:
    // 辅助函数
    void setupListViewScroller(QListView *listView);
    bool executeQuery(QSqlQuery &query, const QString &errorTitle, const QString &errorMessage);
    void loadMoldData();
    void loadMachineList();
    void loadUserNameList();
    void setupNameCompleter(const QStringList &nameList);
    void addMachine(const QString &machineNum);

    Ui::ChonyaEdit *ui;
    QVariant idvalue_;
    QString curr_id;
};

#endif // CHONYAEDIT_H
