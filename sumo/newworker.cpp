#include "newworker.h"
#include "ui_newworker.h"

// ============================================================================
// 构造函数和析构函数
// ============================================================================

NewWorker::NewWorker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NewWorker)
    , user_model(nullptr) {
    ui->setupUi(this);
    // 初始化用户模型
    user_model = new QStandardItemModel(this);
    ui->UserView->setModel(user_model);
    // 初始化界面
    ui->ShowLabel->show();
    ui->ShowLabel->setText("管理员⬋");
    // 验证并刷新用户列表
    if(validateWorkerType(ui->TypeComb->currentText())) {
        refreshUserList();
    }
}

NewWorker::~NewWorker() {
    delete ui;
}

// ============================================================================
// 私有辅助函数
// ============================================================================

void NewWorker::refreshUserList() {
    if(!user_model) {
        user_model = new QStandardItemModel(this);
    } else {
        user_model->clear();
    }
    QString workerType = ui->TypeComb->currentText();
    if(!validateWorkerType(workerType)) {
        QMessageBox::warning(this, "刷新数据", "员工类型无效", QMessageBox::Cancel);
        return;
    }
    QSqlQuery query;
    query.prepare("SELECT name FROM user_message WHERE type = :worker_type");
    query.bindValue(":worker_type", workerType);
    if(!query.exec()) {
        QMessageBox::warning(this, "刷新数据", "用户姓名查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    while(query.next()) {
        QStandardItem *item = new QStandardItem(query.value("name").toString());
        user_model->appendRow(item);
    }
}

bool NewWorker::validateWorkerType(const QString &type) const {
    return !type.isEmpty() && !type.contains('\'') && !type.contains(';');
}

bool NewWorker::checkWorkerExists(const QString &workerName, const QString &workerType) {
    if(!validateWorkerType(workerType)) {
        return false;
    }
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM user_message WHERE name = :worker_name AND type = :worker_type");
    query.bindValue(":worker_name", workerName);
    query.bindValue(":worker_type", workerType);
    if(!query.exec()) {
        QMessageBox::warning(this, "添加员工", "员工姓名查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return false;
    }
    if(query.next()) {
        return query.value(0).toInt() > 0;
    }
    return false;
}

bool NewWorker::getNextWorkerId(QString &userId, QString &password) {
    QSqlQuery query;
    query.prepare("SELECT id FROM user_message ORDER BY id DESC LIMIT 1");
    if(!query.exec()) {
        QMessageBox::warning(this, "添加员工", "员工ID查询失败：\n" + query.lastError().text(), QMessageBox::Cancel);
        return false;
    }
    int nextId = 1;
    if(query.next()) {
        nextId = query.value(0).toInt() + 1;
    }
    userId = QString("user%1").arg(nextId);
    password = QString("user%1").arg(nextId);
    return true;
}

void NewWorker::addNewWorker() {
    QString workerName = ui->NameEdit->text().trimmed();
    if(workerName.isEmpty()) {
        QMessageBox::warning(this, "添加员工", "员工姓名不能为空", QMessageBox::Cancel);
        return;
    }
    QString workerType = ui->TypeComb->currentText();
    if(!validateWorkerType(workerType)) {
        QMessageBox::warning(this, "添加员工", "员工类型无效", QMessageBox::Cancel);
        return;
    }
    // 检查员工是否已存在
    if(checkWorkerExists(workerName, workerType)) {
        QMessageBox::warning(this, "添加员工", "该员工已存在", QMessageBox::Cancel);
        return;
    }
    // 获取下一个员工ID
    QString userId, password;
    if(!getNextWorkerId(userId, password)) {
        return;
    }
    // 插入新员工
    QSqlQuery query;
    query.prepare("INSERT INTO user_message (user, name, type, passwd, authority) "
                  "VALUES (:set_user, :set_name, :set_type, :set_passwd, :set_authority)");
    query.bindValue(":set_user", userId);
    query.bindValue(":set_name", workerName);
    query.bindValue(":set_type", workerType);
    query.bindValue(":set_passwd", password);
    query.bindValue(":set_authority", "0");
    if(!query.exec()) {
        QMessageBox::warning(this, "添加员工", "员工数据插入失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    QMessageBox::information(this, "增加员工",
        QString("员工添加成功\n账号：%1\n密码：%2").arg(userId).arg(password),
        QMessageBox::Ok);
    ui->NameEdit->clear();
    refreshUserList();
}

// ============================================================================
// UI槽函数
// ============================================================================

void NewWorker::on_UserView_clicked(const QModelIndex &index) {
    selected_worker_name = index.data().toString();
}

void NewWorker::on_pushButton_1_clicked() {
    if(selected_worker_name.isEmpty()) {
        QMessageBox::warning(this, "删除员工", "请选择员工", QMessageBox::Cancel);
        return;
    }
    QString question = QString("您确定要删除 %1 吗？").arg(selected_worker_name);
    int reply = QMessageBox::question(this, "删除员工", question, QMessageBox::Yes | QMessageBox::No);
    if(reply != QMessageBox::Yes) {
        return;
    }
    QSqlQuery query;
    bool success = true;
    QString errorMessage;
    // 删除员工信息列表
    query.prepare("DELETE FROM information_message WHERE 接收用户 = :user_name");
    query.bindValue(":user_name", selected_worker_name);
    if(!query.exec()) {
        success = false;
        errorMessage = "员工信息列表删除失败：\n" + query.lastError().text();
    }
    // 删除员工数据
    if(success) {
        query.prepare("DELETE FROM user_message WHERE name = :user_name");
        query.bindValue(":user_name", selected_worker_name);
        if(!query.exec()) {
            success = false;
            errorMessage = "员工数据删除失败：\n" + query.lastError().text();
        }
    }
    if(success) {
        QMessageBox::information(this, "删除员工", "员工删除成功", QMessageBox::Ok);
        selected_worker_name.clear();
        refreshUserList();
    } else {
        QMessageBox::warning(this, "删除员工", errorMessage, QMessageBox::Cancel);
    }
}

void NewWorker::on_pushButton_2_clicked() {
    addNewWorker();
}

void NewWorker::on_NameEdit_returnPressed() {
    addNewWorker();
}

void NewWorker::on_TypeComb_currentTextChanged(const QString &arg1) {
    Q_UNUSED(arg1);
    QString workerType = ui->TypeComb->currentText();
    if(!validateWorkerType(workerType)) {
        QMessageBox::warning(this, "刷新数据", "员工类型无效", QMessageBox::Cancel);
        return;
    }
    ui->ShowLabel->setText(workerType + "⬋");
    refreshUserList();
}
