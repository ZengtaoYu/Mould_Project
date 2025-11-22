#include "emailwindow.h"
#include "ui_emailwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <QSettings>
#include <QSqlError>
#include <QSqlQuery>

#include "emailaddress.h"
#include "mimeattachment.h"
#include "mimehtml.h"
#include "mimemessage.h"
#include "smtpclient.h"

// 构造函数
EmailWindow::EmailWindow(QVariant user, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EmailWindow)
    , uservalue_(user)
    , smtp(new SmtpClient("smtp.163.com", 25, SmtpClient::TcpConnection))
    , message(nullptr) {
    ui->setupUi(this);
    ui->AddFile->hide();
    // 查询用户邮箱和电话信息
    QSqlQuery query;
    query.prepare("select email,phone from user_message where name = :user");
    query.bindValue(":user", user.toString());
    if(!query.exec()) {
        QMessageBox::warning(this, "界面初始化", "用户数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
    } else {
        if(query.next()) {
            ui->ToEdit->setText(query.value(0).toString());
        }
    }
}

// 析构函数
EmailWindow::~EmailWindow() {
    delete ui;
    if(smtp) {
        delete smtp;
    }
    if(message) {
        delete message;
    }
}

// 添加附件按钮
void EmailWindow::on_AddButton_clicked() {
    QFileDialog fileDialog(this);
    fileDialog.setWindowTitle(tr("打开附加文件"));
    fileDialog.setFileMode(QFileDialog::ExistingFiles);
    fileDialog.setViewMode(QFileDialog::Detail);
    QSettings config("userconfig.ini", QSettings::IniFormat);
    fileDialog.setDirectory(config.value("DOCUMENTCONFIG/DocumentPath").toString());
    if(fileDialog.exec()) {
        filelist = fileDialog.selectedFiles();
        if(filelist.isEmpty()) {
            return;
        }
        QString filename = filelist.last();
        QFileInfo fileInfo(filename);
        // 保存目录路径而不是文件路径
        config.setValue("DOCUMENTCONFIG/DocumentPath", fileInfo.absolutePath());
        config.sync();
        QString filetext = fileInfo.fileName();
        if(filetext.length() * 15 > 220) {
            ui->AddFile->resize(220, 30);
            ui->AddFile->setText(filetext);
        } else {
            ui->AddFile->resize(filetext.length() * 15, 30);
            ui->AddFile->setText(filetext);
        }
        ui->AddFile->show();
    }
}

// 移除附件按钮
void EmailWindow::on_AddFile_clicked() {
    filelist.clear();
    ui->AddFile->hide();
}

// 发送邮件按钮
void EmailWindow::on_SendButton_clicked() {
    if(ui->ToEdit->text().isEmpty()) {
        QMessageBox::warning(this, "发送邮件", "邮件发送失败：\n未填写接收邮箱", QMessageBox::Cancel);
        return;
    }
    // 如果 smtp 对象不存在，重新创建
    if(!smtp) {
        smtp = new SmtpClient("smtp.163.com", 25, SmtpClient::TcpConnection);
    }
    smtp->setUser("mengenmould@163.com");
    smtp->setPassword("WSbYNzFza24KmsMp");
    // 使用成员变量 message
    if(message) {
        delete message;
    }
    message = new MimeMessage();
    message->setSender(new EmailAddress("mengenmould@163.com"));
    QStringList receiver = ui->ToEdit->text().split(";");
    for(int i = 0; i < receiver.count(); i++) {
        message->addRecipient(new EmailAddress(receiver.at(i)));
    }
    message->setSubject(ui->TitleEdit->text());
    MimeHtml text;
    text.setHtml(ui->TextEdit->toHtml());
    message->addPart(&text);
    // 添加附件
    for(int i = 0; i < filelist.count(); i++) {
        QString name = filelist.at(i);
        QFile *file = new QFile(name);
        if(file->exists()) {
            message->addPart(new MimeAttachment(file));
        } else {
            delete file;  // 文件不存在时删除，避免内存泄漏
        }
    }
    ui->TextEdit->setPlainText("等待发送中......");
    if(!smtp->connectToHost()) {
        QMessageBox::warning(this, "发送邮件", "邮件发送失败：\n请检查网络连接", QMessageBox::Cancel);
        ui->TextEdit->clear();
        return;
    }
    if(!smtp->login()) {
        QMessageBox::warning(this, "发送邮件", "邮件发送失败：\nSMTP服务登录错误", QMessageBox::Cancel);
        ui->TextEdit->clear();
        return;
    }
    if(!smtp->sendMail(*message)) {
        QMessageBox::warning(this, "发送邮件", "邮件发送失败：\n超出文件内容限制", QMessageBox::Cancel);
        ui->TextEdit->clear();
        return;
    }
    QMessageBox::information(this, "发送邮件", "邮件发送成功", QMessageBox::Ok);
    ui->TextEdit->clear();
    smtp->quit();
    delete smtp;
    smtp = nullptr;
}
