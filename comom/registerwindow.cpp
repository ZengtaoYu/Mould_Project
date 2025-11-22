#include "registerwindow.h"
#include "ui_registerwindow.h"
#include <QMovie>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

RegisterWindow::RegisterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RegisterWindow)
    , m_movie(nullptr)
    , m_authoritySet(0)
    , m_plusSet(0) {
    ui->setupUi(this);
    m_movie = new QMovie(":/images/register_load.gif", nullptr, this);
    ui->LoadingLabel->setMovie(m_movie);
    m_movie->start();
}

RegisterWindow::~RegisterWindow() {
    delete ui;
    // m_movie 由Qt父子关系自动管理，无需手动删除
}

void RegisterWindow::on_RightButton_clicked() {
    registerNewUser();
}

void RegisterWindow::on_ReturnButton0_clicked() {
    this->close();
    if(this->parentWidget()) {
        this->parentWidget()->show();
    }
}

void RegisterWindow::on_AdminBox_stateChanged(int arg1) {
    m_authoritySet = (arg1 != 0) ? 1 : 0;
}

void RegisterWindow::on_PlusBox_stateChanged(int arg1) {
    m_plusSet = (arg1 != 0) ? 1 : 0;
}

void RegisterWindow::on_SetPasswdEdit_2_returnPressed() {
    registerNewUser();
}

bool RegisterWindow::validateAdminPassword() {
    QSqlQuery query;
    query.prepare("SELECT passwd FROM user_message WHERE id = :id");
    query.bindValue(":id", 1);
    if(!query.exec()) {
        QMessageBox::warning(this, tr("注册"),
            tr("管理员密钥查询失败：\n%1").arg(query.lastError().text()),
            QMessageBox::Cancel);
        return false;
    }
    if(!query.next()) {
        QMessageBox::warning(this, tr("注册"),
            tr("管理员密钥丢失，请联系管理员"),
            QMessageBox::Cancel);
        return false;
    }
    QString passwd_key = query.value("passwd").toString();
    if(ui->AdminPasswd->text() != passwd_key) {
        QMessageBox::warning(this, tr("注册"),
            tr("请检查管理员密钥是否正确"),
            QMessageBox::Cancel);
        return false;
    }
    return true;
}

bool RegisterWindow::validateUserInput(QString &errorMessage) {
    if(ui->SetNameEdit->text().isEmpty()) {
        errorMessage = tr("用户姓名为空");
        return false;
    }
    if(ui->SetPasswdEdit_2->text() != ui->SetPasswdEdit->text()) {
        errorMessage = tr("请检查两次密码是否相同");
        return false;
    }
    if(ui->SetUserEdit->text().isEmpty() || ui->SetPasswdEdit->text().isEmpty()) {
        errorMessage = tr("用户名或密码为空");
        return false;
    }
    return true;
}

bool RegisterWindow::checkUserExists(const QString &userName, const QString &name, QString &errorMessage) {
    QSqlQuery query;
    // 检查用户名是否存在
    query.prepare("SELECT COUNT(*) FROM user_message WHERE user = :user");
    query.bindValue(":user", userName);
    if(!query.exec()) {
        errorMessage = tr("用户数据查询失败：\n%1").arg(query.lastError().text());
        return false;
    }
    if(query.next() && query.value(0).toInt() > 0) {
        errorMessage = tr("用户名已存在");
        return true; // 用户存在
    }
    // 检查姓名是否存在
    query.prepare("SELECT COUNT(*) FROM user_message WHERE name = :name");
    query.bindValue(":name", name);
    if(!query.exec()) {
        errorMessage = tr("用户数据查询失败：\n%1").arg(query.lastError().text());
        return false;
    }
    if(query.next() && query.value(0).toInt() > 0) {
        errorMessage = tr("该用户已存在");
        return true; // 用户存在
    }
    return false; // 用户不存在
}

bool RegisterWindow::registerUserToDatabase(const QString &databaseName, const QString &userName,
    const QString &name, const QString &passwd,
    const QString &email, int authority) {
    QSqlDatabase currentDb = QSqlDatabase::database();
    QString originalDbName = currentDb.databaseName();
    // 切换到目标数据库
    currentDb.setDatabaseName(databaseName);
    if(!currentDb.open()) {
        QMessageBox::warning(this, tr("注册"),
            tr("无法连接到数据库 %1：\n%2").arg(databaseName).arg(currentDb.lastError().text()),
            QMessageBox::Cancel);
        // 恢复原始数据库
        currentDb.setDatabaseName(originalDbName);
        currentDb.open();
        return false;
    }
    // 在目标数据库中注册用户
    QSqlQuery query(currentDb);
    query.prepare("INSERT INTO user_message (user, name, passwd, email, authority) "
                  "VALUES (:user, :name, :passwd, :email, :authority)");
    query.bindValue(":user", userName);
    query.bindValue(":name", name);
    query.bindValue(":passwd", passwd);
    query.bindValue(":email", email);
    query.bindValue(":authority", authority);
    bool success = query.exec();
    // 恢复原始数据库
    currentDb.setDatabaseName(originalDbName);
    currentDb.open();
    if(!success) {
        QMessageBox::warning(this, tr("注册"),
            tr("在数据库 %1 中插入用户失败：\n%2").arg(databaseName).arg(query.lastError().text()),
            QMessageBox::Cancel);
        return false;
    }
    return true;
}

bool RegisterWindow::registerNewUser() {
    // 验证管理员密码
    if(!validateAdminPassword()) {
        return false;
    }
    // 验证用户输入
    QString errorMessage;
    if(!validateUserInput(errorMessage)) {
        QMessageBox::warning(this, tr("注册"), errorMessage, QMessageBox::Cancel);
        return false;
    }
    // 获取用户输入
    QString newUser = ui->SetUserEdit->text();
    QString newPasswd = ui->SetPasswdEdit->text();
    QString newName = ui->SetNameEdit->text();
    QString newEmail = ui->SetEmailEdit->text();
    // 检查用户是否已存在
    if(checkUserExists(newUser, newName, errorMessage)) {
        QMessageBox::warning(this, tr("注册"), errorMessage, QMessageBox::Cancel);
        return false;
    }
    // 如果 m_plusSet 为1，则在三个数据库中注册用户
    if(m_plusSet == 1) {
        QStringList databases = {"chonya", "sumo", "warehouse"};
        QStringList failedDatabases;
        for(const QString &dbName : databases) {
            if(!registerUserToDatabase(dbName, newUser, newName, newPasswd, newEmail, m_authoritySet)) {
                failedDatabases.append(dbName);
            }
        }
        if(!failedDatabases.isEmpty()) {
            QMessageBox::warning(this, tr("注册"),
                tr("部分数据库注册失败：\n%1").arg(failedDatabases.join(", ")),
                QMessageBox::Cancel);
            return false;
        }
        QMessageBox::information(this, tr("注册"),
            tr("注册成功！用户已在 chonya、sumo、warehouse 三个数据库中注册"),
            QMessageBox::Ok);
        return true;
    } else {
        // 只在当前数据库中注册用户
        QSqlQuery query;
        query.prepare("INSERT INTO user_message (user, name, passwd, email, authority) "
                      "VALUES (:user, :name, :passwd, :email, :authority)");
        query.bindValue(":user", newUser);
        query.bindValue(":name", newName);
        query.bindValue(":passwd", newPasswd);
        query.bindValue(":email", newEmail);
        query.bindValue(":authority", m_authoritySet);
        if(!query.exec()) {
            QMessageBox::warning(this, tr("注册"),
                tr("用户数据插入失败：\n%1").arg(query.lastError().text()),
                QMessageBox::Cancel);
            return false;
        }
        QMessageBox::information(this, tr("注册"), tr("注册成功"), QMessageBox::Ok);
        return true;
    }
}
