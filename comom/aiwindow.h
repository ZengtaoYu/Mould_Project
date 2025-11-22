#ifndef AIWINDOW_H
#define AIWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QMovie>
#include <QUrl>
#include <QStringList>

namespace Ui {
class AiWindow;
}

class AiWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit AiWindow(QWidget *parent = nullptr);
    ~AiWindow();

private slots:
    void on_AnswerButton_clicked();
    void on_DeepButton_toggled(bool checked);
    void onNetworkReplyFinished();

private:
    void initializeAddBox();
    QString getTableData(const QString &tableName);

    Ui::AiWindow *ui;
    QMovie *movie;
    QNetworkAccessManager manager;
    QString ai_base;
};

#endif // AIWINDOW_H
