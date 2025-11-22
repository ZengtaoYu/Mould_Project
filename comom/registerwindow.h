#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QMainWindow>

class QMovie;

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

private slots:
    void on_RightButton_clicked();
    void on_ReturnButton0_clicked();
    void on_AdminBox_stateChanged(int arg1);
    void on_PlusBox_stateChanged(int arg1);
    void on_SetPasswdEdit_2_returnPressed();

private:
    // 辅助函数
    bool validateAdminPassword();
    bool validateUserInput(QString &errorMessage);
    bool checkUserExists(const QString &userName, const QString &name, QString &errorMessage);
    bool registerNewUser();
    bool registerUserToDatabase(const QString &databaseName, const QString &userName,
        const QString &name, const QString &passwd,
        const QString &email, int authority);

    // 成员变量
    Ui::RegisterWindow *ui;
    QMovie *m_movie;
    int m_authoritySet;
    int m_plusSet;
};

#endif // REGISTERWINDOW_H
