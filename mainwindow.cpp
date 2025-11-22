#include "mainwindow.h"
#include "ui_mainwindow.h"

// ============================================================================
// Constructor & Destructor
// ============================================================================

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_sumoWin(nullptr)
    , m_adminWin(nullptr)
    , m_chonyaWin(nullptr)
    , m_registerWin(nullptr)
    , m_databaseWin(nullptr)
    , m_warehouseWin(nullptr)
    , m_timer(nullptr)
    , m_localServer(nullptr)
    , m_activeWindow(nullptr)
    , m_dbIP("192.168.101.214")
    , m_dbPort(3306)
    , m_partText("chonya")
    , m_partName("冲压模具寿命管制")
    , m_userName("")
    , m_authority(false)
    , m_isRemember(false)
    , m_appVersion("v4.11.21")
    , m_adminClickCount(0) {
    ui->setupUi(this);
    // 初始化配置文件
    QFile file("userconfig.ini");
    QSettings config("userconfig.ini", QSettings::IniFormat);
    if(!file.exists()) {
        config.beginGroup("DBCONFIG");
        config.setValue("DBIP", "192.168.101.214");
        config.setValue("DBPort", "3306");
        config.setValue("DBPart", "冲压模具寿命管制");
        config.endGroup();
        config.beginGroup("USERCONFIG");
        config.setValue("UserName", "");
        config.setValue("PassWord", "");
        config.setValue("IsRemberPas", false);
        config.endGroup();
        config.beginGroup("DOCUMENTCONFIG");
        config.setValue("DocumentPath", QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/");
        config.endGroup();
        config.beginGroup("SELECTIONCONFIG");
        config.setValue("Select1", "");
        config.setValue("Select2", "");
        config.setValue("Select3", "");
        config.setValue("Mold", "");
        config.setValue("Spare", "");
        config.setValue("Cabinet", "");
        config.endGroup();
    }
    config.sync();
    // 加载配置
    m_dbIP = config.value("DBCONFIG/DBIP").toString();
    m_dbPort = config.value("DBCONFIG/DBPort").toString().toInt();
    m_partName = config.value("DBCONFIG/DBPart").toString();
    ui->IPLabel2->setText(m_dbIP + "     " + m_partName);
    QSignalBlocker blocker(ui->PartCombo);
    ui->PartCombo->setCurrentText(m_partName);
    switch(ui->PartCombo->currentIndex()) {
    case 0:
        m_partText = "chonya";
        break;
    case 1 :
        m_partText = "sumo";
        break;
    case 2 :
        m_partText = "warehouse";
        break;
    }
    // 加载用户配置
    bool isRemember = config.value("USERCONFIG/IsRemberPas").toBool();
    ui->checkBox->setChecked(isRemember);
    m_isRemember = isRemember;
    QString userName = config.value("USERCONFIG/UserName").toString();
    QString passWord = config.value("USERCONFIG/PassWord").toString();
    ui->UserEdit->setText(userName);
    if(!userName.isEmpty() && !passWord.isEmpty() && ui->checkBox->checkState()) {
        ui->PasswdEdit->setText(passWord);
    }
    // 初始化定时器
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &MainWindow::refresh_time);
    m_timer->start(1000); // 1秒刷新一次
    // 初始化动画
    QMovie *movie = new QMovie(":/images/gear_show.gif");
    ui->ShowLabel->setMovie(movie);
    movie->start();
    // 初始化数据库连接
    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setHostName(m_dbIP);
    m_db.setPort(m_dbPort);
    m_db.setConnectOptions("MYSQL_OPT_RECONNECT=1");
    m_db.setUserName(m_partText);
    m_db.setPassword(m_partText);
    m_db.setDatabaseName(m_partText);
    // 连接数据库
connect:
    bool ok;
    int port = 0;
    QString ip_text;
    if(!m_db.open()) {
        QMessageBox::warning(this, "连接数据库",
            m_db.lastError().text() + "\n请检查数据库连接，程序将无法正常使用！");
        while(ip_text.isEmpty()) {
            ip_text = QInputDialog::getText(this, "连接数据库", "请输入您数据库的IP:", QLineEdit::Normal, m_dbIP, &ok);
            if(ok && !ip_text.isEmpty()) {
                m_db.setHostName(ip_text);
                m_dbIP = ip_text;
            } else if(ok && ip_text.isEmpty()) {
                QMessageBox::warning(this, "连接数据库", "连接失败！！！\n请输入数据库地址！！！");
            }
            if(!ok) {
                ui->IPLabel2->setText("");
                return;
            }
            config.setValue("DBCONFIG/DBIP", ip_text);
        }
        while(!port) {
            QString portStr = QString::number(m_dbPort);
            port = QInputDialog::getText(this, "连接数据库", "请输入数据库端口:", QLineEdit::Normal, portStr,
                    &ok).toInt();
            if(ok && port) {
                m_db.setPort(port);
                m_dbPort = port;
            } else if(ok && !port) {
                QMessageBox::warning(this, "连接数据库", "连接失败！！！\n请输入连接端口！！！");
            }
            if(!ok) {
                ui->IPLabel2->setText("");
                return;
            }
            config.setValue("DBCONFIG/DBPort", port);
        }
        goto connect;
    }

    // 初始化本地服务器，用于接收新实例的消息
    m_localServer = new QLocalServer(this);
    connect(m_localServer, &QLocalServer::newConnection, this, &MainWindow::handleNewConnection);
    m_localServer->listen("MouldManagerSingleInstance");
}

MainWindow::~MainWindow() {
    delete ui;
}

// ============================================================================
// Protected Methods
// ============================================================================

void MainWindow::closeEvent(QCloseEvent *event) {
    Q_UNUSED(event);
    QCoreApplication::exit();
}

// ============================================================================
// Private Slots - Timer
// ============================================================================

void MainWindow::refresh_time() {
    QDateTime dateTime = QDateTime::currentDateTime();
    ui->TimeLabel->setText(dateTime.toString("yyyy-MM-dd hh:mm:ss"));
}

// ============================================================================
// Private Slots - UI Event Handlers
// ============================================================================

void MainWindow::on_LoginButton_clicked() {
    performLogin();
}

void MainWindow::on_UserEdit_returnPressed() {
    performLogin();
}

void MainWindow::on_PasswdEdit_returnPressed() {
    performLogin();
}

void MainWindow::on_RegisterButton_clicked() {
    m_registerWin = new RegisterWindow(this);
    m_registerWin->setWindowTitle("注册");
    m_registerWin->show();
}

void MainWindow::on_DataBaseButton_clicked() {
retry:
    bool ok;
    QString secret = QInputDialog::getText(this, "数据库管理", "请输入管理密钥:", QLineEdit::Password, "", &ok);
    if(ok && !secret.isEmpty()) {
        if(secret == "mengen888") {
            m_databaseWin = new DatabaseWindow(this);
            m_databaseWin->setWindowTitle("数据库管理");
            m_databaseWin->show();
        } else {
            QMessageBox::warning(this, "数据库管理", "密钥错误，请重新输入！");
            goto retry;
        }
    } else if(ok && secret.isEmpty()) {
        QMessageBox::warning(this, "数据库管理", "密钥为空，请输入管理密钥！");
        goto retry;
    }
}

void MainWindow::on_LinkButton_clicked() {
    QSettings config("userconfig.ini", QSettings::IniFormat);
connect:
    bool ok;
    int port = 0;
    QString ip_text;
    while(ip_text.isEmpty()) {
        ip_text = QInputDialog::getText(this, "连接数据库", "请输入您数据库的IP:", QLineEdit::Normal, m_dbIP, &ok);
        if(ok && !ip_text.isEmpty()) {
            m_db.setHostName(ip_text);
            m_dbIP = ip_text;
        } else if(ok && ip_text.isEmpty()) {
            QMessageBox::warning(this, "连接数据库", "连接失败！！！\n请输入数据库地址！！！");
        }
        if(!ok) {
            return;
        }
        config.setValue("DBCONFIG/DBIP", ip_text);
    }
    while(!port) {
        QString portStr = QString::number(m_dbPort);
        port = QInputDialog::getText(this, "连接数据库", "请输入数据库端口:", QLineEdit::Normal, portStr,
                &ok).toInt();
        if(ok && port) {
            m_db.setPort(port);
            m_dbPort = port;
        } else if(ok && !port) {
            QMessageBox::warning(this, "连接数据库", "连接失败！！！\n请输入连接端口！！！");
        }
        if(!ok) {
            return;
        }
        config.setValue("DBCONFIG/DBPort", port);
    }
    if(!m_db.open()) {
        QMessageBox::warning(this, "连接数据库",
            m_db.lastError().text() + "\n请检查数据库连接，程序将无法正常使用！");
        goto connect;
    }
    config.sync();
    ui->IPLabel2->setText(m_dbIP + "     " + m_partName);
}

void MainWindow::on_pushButton_clicked() {
    m_adminClickCount++;
    if(m_adminClickCount >= 3) {
        m_adminClickCount = 0;
retry:
        bool ok;
        QString secret = QInputDialog::getText(this, "管理员消息", "请输入管理密钥:", QLineEdit::Password, "", &ok);
        if(ok && !secret.isEmpty()) {
            if(secret == "mengen888") {
                m_adminClickCount = 0;
                QSqlDatabase currentDb = QSqlDatabase::database();
                QString curr_db = currentDb.databaseName();
                m_adminWin = new AdminWindow(curr_db, this);
                m_adminWin->setWindowTitle("管理员消息");
                m_adminWin->show();
            } else {
                QMessageBox::warning(this, "管理员消息", "密钥错误，请重新输入！");
                goto retry;
            }
        } else if(ok && secret.isEmpty()) {
            QMessageBox::warning(this, "管理员消息", "密钥为空，请输入管理密钥！");
            goto retry;
        }
    }
}

void MainWindow::on_checkBox_stateChanged(int arg1) {
    m_isRemember = (arg1 != 0);
    QSettings config("userconfig.ini", QSettings::IniFormat);
    config.setValue("USERCONFIG/IsRemberPas", m_isRemember);
    config.sync();
}

void MainWindow::on_PartCombo_currentIndexChanged(const QString &arg1) {
    if(arg1 == "冲压模具寿命管制") {
        m_partText = "chonya";
        m_partName = "冲压模具寿命管制";
    } else if(arg1 == "成型模具寿命管制") {
        m_partText = "sumo";
        m_partName = "成型模具寿命管制";
    } else if(arg1 == "模具&备件仓储管理") {
        m_partText = "warehouse";
        m_partName = "模具&备件仓储管理";
    }
    m_db.setUserName(m_partText);
    m_db.setPassword(m_partText);
    m_db.setDatabaseName(m_partText);
    if(!m_db.open()) {
        QMessageBox::warning(this, "连接数据库",
            m_db.lastError().text() + "\n请检查数据库连接，程序将无法正常使用！");
        return;
    }
    ui->IPLabel2->setText(m_dbIP + "     " + m_partName);
    QSettings config("userconfig.ini", QSettings::IniFormat);
    config.setValue("DBCONFIG/DBPart", arg1);
    config.sync();
}

// ============================================================================
// Private Methods
// ============================================================================

void MainWindow::performLogin() {
    QString username = ui->UserEdit->text();
    QString password = ui->PasswdEdit->text();
    // 参数化查询，安全、高效
    QSqlQuery query;
    query.prepare("SELECT name, passwd, authority FROM user_message WHERE user = :user");
    query.bindValue(":user", username);
    if(!query.exec()) {
        QMessageBox::warning(this, "查询用户数据",
            "用户数据查询失败：\n" + query.lastError().text());
        return;
    }
    // 检查是否有结果
    if(!query.next()) {
        QMessageBox::warning(this, "登录", "用户不存在，请检查用户名", QMessageBox::Cancel);
        ui->UserEdit->clear();
        ui->PasswdEdit->clear();
        return;
    }
    QString realPasswd  = query.value("passwd").toString();
    m_userName          = query.value("name").toString();
    m_authority         = query.value("authority").toBool();
    // 密码验证
    if(password != realPasswd) {
        QMessageBox::warning(this, "登录", "密码错误，请重新输入！", QMessageBox::Cancel);
        ui->PasswdEdit->clear();
        return;
    }
    // 登录成功后写配置
    QSettings config("userconfig.ini", QSettings::IniFormat);
    config.setValue("USERCONFIG/UserName", username);
    config.setValue("USERCONFIG/PassWord", password);
    config.sync();
    // 根据模块名创建相应窗口
    QWidget *win = nullptr;
    if(m_partText == "chonya") {
        win = new ChonyaWindow(m_authority, m_userName, this);
        win->setWindowTitle("冲压模具管理系统" + m_appVersion);
    } else if(m_partText == "sumo") {
        win = new SumoWindow(m_authority, m_userName, this);
        win->setWindowTitle("成型模具管理系统" + m_appVersion);
    } else if(m_partText == "warehouse") {
        win = new WarehouseWindow(m_authority, m_userName, this);
        win->setWindowTitle("模具仓库管理系统" + m_appVersion);
    }
    // 显示窗口
    if(win) {
        m_activeWindow = win;  // 保存当前活动窗口
        win->show();
        this->hide();
    }
}

// ============================================================================
// Public Methods
// ============================================================================

void MainWindow::showAndActivate() {
    // 判断应该显示哪个窗口
    QWidget *targetWindow = nullptr;

    if (m_activeWindow && m_activeWindow->isVisible()) {
        // 如果有活动的子窗口（ChonyaWindow/SumoWindow/WarehouseWindow），显示它
        targetWindow = m_activeWindow;
    } else if (m_activeWindow) {
        // 子窗口存在但被隐藏了，显示它
        targetWindow = m_activeWindow;
    } else {
        // 还没有登录，显示主窗口
        targetWindow = this;
    }

    // 显示目标窗口
    targetWindow->show();
    // 如果窗口被最小化，恢复正常状态
    if (targetWindow->isMinimized()) {
        targetWindow->showNormal();
    }
    // 激活窗口并置顶
    targetWindow->raise();
    targetWindow->activateWindow();
}

// ============================================================================
// Private Slots - LocalServer
// ============================================================================

void MainWindow::handleNewConnection() {
    QLocalSocket *socket = m_localServer->nextPendingConnection();
    if (socket) {
        // 读取消息（虽然这里我们不需要具体内容，但为了完整性还是读取一下）
        socket->waitForReadyRead(1000);
        socket->readAll();
        socket->disconnectFromServer();
        delete socket;

        // 显示并激活窗口
        showAndActivate();
    }
}
