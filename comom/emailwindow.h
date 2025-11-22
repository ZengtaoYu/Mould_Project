#ifndef EMAILWINDOW_H
#define EMAILWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QVariant>

// 前向声明
class Sms;
class SmtpClient;
class MimeMessage;

namespace Ui {
class EmailWindow;
}

class EmailWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit EmailWindow(QVariant user, QWidget *parent = nullptr);
    ~EmailWindow();

private slots:
    void on_AddButton_clicked();
    void on_AddFile_clicked();
    void on_SendButton_clicked();

private:
    Ui::EmailWindow *ui;

    QVariant uservalue_;
    SmtpClient *smtp;
    MimeMessage *message;
    QStringList filelist;
};

#endif // EMAILWINDOW_H
