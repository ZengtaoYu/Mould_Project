#include "adminwindow.h"
#include "ui_adminwindow.h"

// ============================================================================
// 静态常量定义
// ============================================================================
const QStringList AdminWindow::DATABASE_NAMES = {"chonya", "sumo", "warehouse"};
const QString AdminWindow::SYSTEM_USER = "系统";
const QString AdminWindow::EMAIL_WINDOW_TITLE = "发送邮件";

// ============================================================================
// 构造函数和析构函数
// ============================================================================
AdminWindow::AdminWindow(QVariant db_value, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdminWindow)
    , emailWin_(nullptr)
    , dbvalue_(db_value)
    , databaseName_(db_value.toString())
    , get_email_()
    , send_flag_(false) {
    ui->setupUi(this);
}

AdminWindow::~AdminWindow() {
    // 清理邮件窗口
    if(emailWin_) {
        emailWin_->deleteLater();
    }
    delete ui;
}

// ============================================================================
// 事件处理函数
// ============================================================================
void AdminWindow::closeEvent(QCloseEvent *event) {
    Q_UNUSED(event);
    // 关闭并清理邮件窗口
    QString windowTitle = tr("发送邮件");
    if(QWidget *target = m_windowMap.value(windowTitle)) {
        if(!target->isHidden()) {
            target->close();
            target->deleteLater();
            m_windowMap.remove(windowTitle);
        }
    }
    // 恢复数据库连接
    if(openDatabase(databaseName_)) {
        emit enablesignal();
    }
}

// ============================================================================
// 私有槽函数
// ============================================================================
void AdminWindow::on_PushButton_clicked() {
    // 重置状态
    send_flag_ = false;
    get_email_.clear();
    // 依次向各个数据库发送消息
    for(const QString &dbName : DATABASE_NAMES) {
        if(send_flag_) {
            break;
        }
        send_message(dbName);
    }
    // 显示结果
    if(!send_flag_) {
        QMessageBox::information(this, "发送信息", "信息发送成功", QMessageBox::Ok);
    } else {
        QMessageBox::warning(this, "发送信息", "部分信息发送失败，请检查日志", QMessageBox::Ok);
        send_flag_ = false;
    }
}

void AdminWindow::on_EmailButton_clicked() {
    // 检查是否已存在邮件窗口
    if(emailWin_ && !emailWin_->isHidden()) {
        emailWin_->raise();
        emailWin_->activateWindow();
        return;
    }
    // 清理旧的邮件窗口
    if(emailWin_) {
        emailWin_->deleteLater();
    }
    // 创建新的邮件窗口
    emailWin_ = new EmailWindow(get_email_, this);
    emailWin_->setWindowTitle(EMAIL_WINDOW_TITLE);
    m_windowMap.insert(tr("发送邮件"), emailWin_);
    emailWin_->show();
}

// ============================================================================
// 私有辅助函数 - 数据库操作
// ============================================================================
bool AdminWindow::openDatabase(const QString &dbName) {
    // 输入验证
    if(dbName.isEmpty()) {
        QMessageBox::warning(this, "连接数据库", "数据库名称不能为空！");
        return false;
    }
    // 打开数据库连接
    QSqlDatabase currentDb = QSqlDatabase::database();
    currentDb.setDatabaseName(dbName);
    if(!currentDb.open()) {
        QMessageBox::warning(this, "连接数据库",
            QString("数据库连接失败：%1\n请检查数据库连接，程序将无法正常使用！")
            .arg(currentDb.lastError().text()));
        return false;
    }
    return true;
}

void AdminWindow::send_message(const QString &dbName) {
    // 输入验证
    if(dbName.isEmpty()) {
        QMessageBox::warning(this, "发送信息", "数据库名称不能为空！");
        send_flag_ = true;
        return;
    }
    // 验证数据库名称是否在允许列表中（防止SQL注入）
    if(!DATABASE_NAMES.contains(dbName)) {
        QMessageBox::warning(this, "发送信息", QString("非法的数据库名称：%1").arg(dbName));
        send_flag_ = true;
        return;
    }
    // 打开数据库
    if(!openDatabase(dbName)) {
        send_flag_ = true;
        return;
    }
    // 查询用户信息
    QSqlQuery query;
    const QString sql = "SELECT name, email FROM user_message;";
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "发送信息",
            QString("用户数据查询失败：\n%1").arg(query.lastError().text()),
            QMessageBox::Cancel);
        send_flag_ = true;
        return;
    }
    // 获取标题和消息内容
    QString title = ui->TitleEdit->text();
    QString message = ui->MessageEdit->toPlainText();
    QString currTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    // 遍历用户并发送消息
    while(query.next()) {
        QString userName = query.value(0).toString();
        QString userEmail = query.value(1).toString();
        // 累积邮件地址（跨数据库累积，不清空）
        if(!userEmail.isEmpty()) {
            if(!get_email_.isEmpty()) {
                get_email_ += ';';
            }
            get_email_ += userEmail;
        }
        // 插入消息记录
        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO information_message (日期, 模具编号, 信息, 发送用户, 接收用户, 完成情况) "
                            "VALUES (:date, :mold, :message, :tuser, :ruser, :finished)");
        insertQuery.bindValue(":date", currTime);
        insertQuery.bindValue(":mold", title);
        insertQuery.bindValue(":message", message);
        insertQuery.bindValue(":tuser", SYSTEM_USER);
        insertQuery.bindValue(":ruser", userName);
        insertQuery.bindValue(":finished", "1");
        if(!insertQuery.exec()) {
            QMessageBox::warning(this, QString("发送信息到%1").arg(dbName),
                QString("信息发送失败：\n%1").arg(insertQuery.lastError().text()),
                QMessageBox::Cancel);
            send_flag_ = true;
        }
    }
}
