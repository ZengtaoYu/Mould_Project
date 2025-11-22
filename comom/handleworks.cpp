#include "handleworks.h"
#include "ui_handleworks.h"

#include <QScroller>
#include <QAbstractItemView>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QList>
#include <QStandardItem>
#include "comom/emailwindow.h"

// ============================================================================
// 构造函数和析构函数
// ============================================================================

HandleWorks::HandleWorks(QVariant db_value, QVariant id_value, QVariant name, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HandleWorks)
    , emailWin(nullptr)
    , dbvalue_(db_value)
    , idvalue_(id_value)
    , namevalue_(name)
    , curr_name(name.toString())
    , proces()
    , databaseName(db_value.toString()) {
    ui->setupUi(this);
    // 初始化列表滚动设置
    QScroller *pScroller = QScroller::scroller(ui->ProceList);
    pScroller->grabGesture(ui->ProceList->viewport(), QScroller::LeftMouseButtonGesture);
    ui->ProceList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    // 设置模具编号
    ui->MoldEdit->setText(id_value.toString());
    ui->MoldEdit->setSelection(0, 0);
    // 初始化部门设置
    initializeDepartmentSettings(db_value.toString());
    // 打开数据库并刷新数据
    if(openDatabase(databaseName)) {
        refresh_data();
    }
}

HandleWorks::~HandleWorks() {
    cleanupEmailWindow();
    delete ui;
}

// ============================================================================
// 重写事件处理函数
// ============================================================================

void HandleWorks::closeEvent(QCloseEvent *event) {
    Q_UNUSED(event);
    cleanupEmailWindow();
    if(openDatabase(databaseName)) {
        emit enablesignal();
    }
}

// ============================================================================
// 私有槽函数
// ============================================================================

void HandleWorks::on_PartCombo_currentIndexChanged(const QString &arg1) {
    QString dbName;
    if(arg1 == "冲压部门") {
        dbName = "chonya";
    } else if(arg1 == "塑模部门") {
        dbName = "sumo";
    } else if(arg1 == "仓库部门") {
        dbName = "warehouse";
    } else {
        return;
    }
    if(openDatabase(dbName)) {
        databaseName = dbName;
        refresh_data();
    }
}

void HandleWorks::on_ProceList_clicked(const QModelIndex &index) {
    if(index.isValid()) {
        proces = index.data().toString();
    }
}

void HandleWorks::on_PushButton_clicked() {
    // 验证处理用户是否已选择
    if(proces.isEmpty()) {
        QMessageBox::warning(this, "提交工单", "请选择处理用户", QMessageBox::Cancel);
        return;
    }
    // 验证数据库连接
    if(!openDatabase(databaseName)) {
        return;
    }
    // 获取表单数据
    QString mold_id = ui->MoldEdit->text().trimmed();
    QString mold_nature = ui->NatureCombo->currentText();
    QString message = ui->MessageEdit->toPlainText();
    QString currTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    // 验证模具编号
    if(mold_id.isEmpty()) {
        QMessageBox::warning(this, "提交工单", "模具编号不能为空", QMessageBox::Cancel);
        return;
    }
    // 执行数据库插入操作
    QSqlQuery query;
    query.prepare("insert into information_message (日期,模具编号,模具性质,信息,发送用户,接收用户,完成情况) VALUES (:date, :mold_id, :mold_nature, :message, :tuser, :ruser, :finished)");
    query.bindValue(":date", currTime);
    query.bindValue(":mold_id", mold_id);
    query.bindValue(":mold_nature", mold_nature);
    query.bindValue(":message", message);
    query.bindValue(":tuser", curr_name);
    query.bindValue(":ruser", proces);
    query.bindValue(":finished", "1");
    if(!query.exec()) {
        QMessageBox::warning(this, "提交工单", "信息列表数据插入失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
    } else {
        QMessageBox::information(this, "提交工单", "工单提交成功", QMessageBox::Ok);
        // 清空消息编辑框
        ui->MessageEdit->clear();
    }
}

void HandleWorks::on_EmailButton_clicked() {
    if(proces.isEmpty()) {
        QMessageBox::warning(this, "发送邮件", "请先选择处理用户", QMessageBox::Cancel);
        return;
    }
    // 检查是否已存在邮件窗口
    if(emailWin != nullptr && !emailWin->isHidden()) {
        emailWin->raise();
        emailWin->activateWindow();
        return;
    }
    // 清理旧的邮件窗口
    cleanupEmailWindow();
    // 创建新的邮件窗口
    emailWin = new EmailWindow(proces, this);
    emailWin->setWindowTitle("发送邮件");
    m_windowMap.insert(tr("发送邮件"), emailWin);
    emailWin->show();
}

// ============================================================================
// 私有辅助函数
// ============================================================================

void HandleWorks::refresh_data() {
    // 验证数据库连接
    QSqlDatabase currentDb = QSqlDatabase::database();
    if(!currentDb.isOpen()) {
        QMessageBox::warning(this, "刷新数据", "数据库未连接，无法刷新数据", QMessageBox::Cancel);
        return;
    }
    // 清理旧的模型
    QStandardItemModel *oldModel = qobject_cast<QStandardItemModel *>(ui->ProceList->model());
    if(oldModel != nullptr) {
        oldModel->clear();
        oldModel->deleteLater();
    }
    // 创建新模型
    QStandardItemModel *model = new QStandardItemModel(this);
    // 执行查询
    QSqlQuery query;
    QString sql = "SELECT name FROM user_message;";
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "刷新数据", "用户姓名查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        delete model;
        return;
    }
    // 填充模型数据
    while(query.next()) {
        QString get_name = query.value(0).toString();
        if(get_name == curr_name || get_name == "NULL" || get_name.isEmpty()) {
            continue;
        }
        QList<QStandardItem *> items;
        items.append(new QStandardItem(get_name));
        model->appendRow(items);
    }
    // 设置模型
    ui->ProceList->setModel(model);
}

bool HandleWorks::openDatabase(const QString &dbName) {
    if(dbName.isEmpty()) {
        QMessageBox::warning(this, "连接数据库", "数据库名称不能为空", QMessageBox::Cancel);
        return false;
    }
    QSqlDatabase currentDb = QSqlDatabase::database();
    currentDb.setDatabaseName(dbName);
    if(!currentDb.open()) {
        QMessageBox::warning(this, "连接数据库",
            QString("无法连接到数据库 '%1'：\n%2\n请检查数据库连接，程序将无法正常使用！")
            .arg(dbName, currentDb.lastError().text()),
            QMessageBox::Cancel);
        return false;
    }
    return true;
}

void HandleWorks::initializeDepartmentSettings(const QString &dbValue) {
    if(dbValue == "chonya") {
        ui->PartCombo->setCurrentText("冲压部门");
        ui->NatureCombo->addItem("无");
        ui->NatureCombo->addItem("下料零件");
        ui->NatureCombo->addItem("关键易损件");
        ui->NatureCombo->addItem("成型零件");
    } else if(dbValue == "sumo") {
        ui->PartCombo->setCurrentText("塑模部门");
        ui->NatureCombo->addItem("无");
        ui->NatureCombo->addItem("定期保养");
        ui->NatureCombo->addItem("特定易损件");
        ui->NatureCombo->addItem("大保养");
    } else if(dbValue == "warehouse") {
        ui->PartCombo->setCurrentText("仓库部门");
        ui->NatureCombo->addItem("无");
    }
}

void HandleWorks::cleanupEmailWindow() {
    if(emailWin != nullptr) {
        if(!emailWin->isHidden()) {
            emailWin->close();
        }
        emailWin->deleteLater();
        emailWin = nullptr;
        m_windowMap.remove(tr("发送邮件"));
    }
}
