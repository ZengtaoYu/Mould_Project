#ifndef HANDLEWORKS_H
#define HANDLEWORKS_H

#include <QMainWindow>
#include <QVariant>
#include <QString>
#include <QMap>
#include <QWidget>

class QCloseEvent;
class QModelIndex;
class QStandardItemModel;
class QSqlDatabase;
class QSqlQuery;

namespace Ui {
class HandleWorks;
}

class EmailWindow;

class HandleWorks : public QMainWindow {
    Q_OBJECT

public:
    explicit HandleWorks(QVariant db_value, QVariant id_value, QVariant name, QWidget *parent = nullptr);
    ~HandleWorks();

signals:
    void enablesignal();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_PartCombo_currentIndexChanged(const QString &arg1);
    void on_ProceList_clicked(const QModelIndex &index);
    void on_PushButton_clicked();
    void on_EmailButton_clicked();

private:
    void refresh_data();
    bool openDatabase(const QString &dbName);
    void initializeDepartmentSettings(const QString &dbValue);
    void cleanupEmailWindow();

private:
    Ui::HandleWorks *ui;
    EmailWindow *emailWin;

    QVariant dbvalue_;
    QVariant idvalue_;
    QVariant namevalue_;
    QString curr_name;
    QString proces;
    QString databaseName;
    QMap<QString, QWidget *> m_windowMap;
};

#endif // HANDLEWORKS_H
