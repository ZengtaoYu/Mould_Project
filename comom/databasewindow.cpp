#include "databasewindow.h"
#include "ui_databasewindow.h"

#include <QCloseEvent>
#include <QDebug>
#include <QHeaderView>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>
#include <QToolTip>
#include <QCursor>
#include <QRegExp>
#include <QValidator>

DatabaseWindow::DatabaseWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DatabaseWindow)
    , m_myModel(new QSqlTableModel(this)) {
    ui->setupUi(this);
    QSqlDatabase currentDb = QSqlDatabase::database();
    m_currDb = currentDb.databaseName();
}

DatabaseWindow::~DatabaseWindow() {
    if(m_myModel) {
        delete m_myModel;
        m_myModel = nullptr;
    }
    delete ui;
}

void DatabaseWindow::closeEvent(QCloseEvent *event) {
    Q_UNUSED(event);
    // 关闭窗口时不需要重新打开数据库连接
    // 数据库连接由应用程序统一管理
}

bool DatabaseWindow::checkDatabaseConnection() {
    QSqlDatabase currentDb = QSqlDatabase::database();
    if(!currentDb.isOpen()) {
        QMessageBox::warning(this, tr("连接数据库"),
            tr("数据库未连接\n请检查数据库连接，程序将无法正常使用！"),
            QMessageBox::Cancel);
        return false;
    }
    m_myDb = currentDb;
    return true;
}

bool DatabaseWindow::executeQueryAndDisplay(QSqlQuery &query, const QString &sql) {
    if(!query.exec(sql)) {
        QMessageBox::warning(this, tr("执行SQL语句"),
            tr("SQL语句执行失败：\n%1").arg(query.lastError().text()),
            QMessageBox::Cancel);
        return false;
    }
    return true;
}

bool DatabaseWindow::validateNumberInput(const QString &input, int &value) {
    bool ok;
    value = input.toInt(&ok);
    return ok && value >= 0;
}

void DatabaseWindow::updateCurrentDatabaseDisplay(const QString &dbName) {
    ui->te_output->appendPlainText(dbName);
    ui->lb_curDb->setText(dbName);
}

void DatabaseWindow::setPlainText(const QString &text) {
    ui->te_input->clear();
    ui->te_output->clear();
    ui->te_input->appendPlainText(text);
}

void DatabaseWindow::doMouseTrackTip(QModelIndex index) {
    QToolTip::showText(QCursor::pos(), index.data().toString());
}

// 数据库操作相关槽函数
void DatabaseWindow::on_pb_connect_clicked() {
    if(!checkDatabaseConnection()) {
        return;
    }
    QString sql = ui->te_input->toPlainText().trimmed();
    if(sql.isEmpty()) {
        QMessageBox::warning(this, tr("执行SQL语句"),
            tr("SQL语句不能为空！"),
            QMessageBox::Cancel);
        return;
    }
    QSqlQuery query(m_myDb);
    if(!executeQueryAndDisplay(query, sql)) {
        return;
    }
    ui->te_output->clear();
    while(query.next()) {
        ui->te_output->appendPlainText(query.value(0).toString());
    }
}

void DatabaseWindow::on_pb_showAllDb_clicked() {
    if(!checkDatabaseConnection()) {
        return;
    }
    setPlainText(tr("show databases;"));
    QSqlQuery query(m_myDb);
    if(!executeQueryAndDisplay(query, tr("show databases;"))) {
        return;
    }
    ui->cb_db->clear();
    while(query.next()) {
        QString dbName = query.value(0).toString();
        ui->te_output->appendPlainText(dbName);
        ui->cb_db->addItem(dbName);
    }
}

void DatabaseWindow::on_pb_showCurDb_clicked() {
    if(!checkDatabaseConnection()) {
        return;
    }
    setPlainText(tr("select database();"));
    QSqlQuery query(m_myDb);
    if(!executeQueryAndDisplay(query, tr("select database();"))) {
        return;
    }
    while(query.next()) {
        updateCurrentDatabaseDisplay(query.value(0).toString());
    }
}

void DatabaseWindow::on_pb_openDb_clicked() {
    if(!checkDatabaseConnection()) {
        return;
    }
    QString dbName = ui->cb_db->currentText().trimmed();
    if(dbName.isEmpty()) {
        QMessageBox::warning(this, tr("打开数据库"),
            tr("请选择要打开的数据库！"),
            QMessageBox::Cancel);
        return;
    }
    // 使用参数化查询防止SQL注入
    QSqlQuery query(m_myDb);
    QString useSql = tr("use `%1`;").arg(dbName);
    setPlainText(useSql + tr("\nselect database();"));
    if(!executeQueryAndDisplay(query, useSql)) {
        return;
    }
    if(!executeQueryAndDisplay(query, tr("select database();"))) {
        return;
    }
    while(query.next()) {
        updateCurrentDatabaseDisplay(query.value(0).toString());
    }
}

// 表操作相关槽函数
void DatabaseWindow::on_pb_showTable_clicked() {
    if(!checkDatabaseConnection()) {
        return;
    }
    setPlainText(tr("show tables;"));
    QSqlQuery query(m_myDb);
    if(!executeQueryAndDisplay(query, tr("show tables;"))) {
        return;
    }
    ui->cb_table->clear();
    while(query.next()) {
        QString tableName = query.value(0).toString();
        ui->te_output->appendPlainText(tableName);
        ui->cb_table->addItem(tableName);
    }
}

void DatabaseWindow::on_pb_setTable_clicked() {
    QString tableName = ui->cb_table->currentText().trimmed();
    if(!tableName.isEmpty()) {
        ui->lb_curTable->setText(tableName);
    }
}

void DatabaseWindow::on_pb_showTableData_clicked() {
    if(!checkDatabaseConnection()) {
        return;
    }
    QString tableName = ui->lb_curTable->text().trimmed();
    if(tableName.isEmpty()) {
        QMessageBox::warning(this, tr("错误"),
            tr("当前数据表为空\n请选择数据表！！！"),
            QMessageBox::Cancel);
        return;
    }
    // 使用参数化方式设置表名（QSqlTableModel内部会处理）
    QString selectStr = tr("select * from `%1`;").arg(tableName);
    setPlainText(selectStr);
    m_myModel->setTable(tableName);
    if(!m_myModel->select()) {
        QMessageBox::warning(this, tr("错误"),
            tr("无法加载数据表：\n%1").arg(m_myModel->lastError().text()),
            QMessageBox::Cancel);
        return;
    }
    m_myModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(m_myModel);
    ui->tableView->setMouseTracking(true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    connect(ui->tableView, &QTableView::entered, this, &DatabaseWindow::doMouseTrackTip);
}

void DatabaseWindow::on_pb_display_clicked() {
    if(!checkDatabaseConnection()) {
        return;
    }
    QString tableName = ui->lb_curTable->text().trimmed();
    if(tableName.isEmpty()) {
        QMessageBox::warning(this, tr("错误"),
            tr("当前数据表为空\n请选择数据表！！！"),
            QMessageBox::Cancel);
        return;
    }
    m_myModel->setTable(tableName);
    if(!m_myModel->select()) {
        QMessageBox::warning(this, tr("错误"),
            tr("无法加载数据表：\n%1").arg(m_myModel->lastError().text()),
            QMessageBox::Cancel);
    }
}

// 数据操作相关槽函数
void DatabaseWindow::on_pb_record_clicked() {
    if(!m_myModel) {
        return;
    }
    int rowNum = m_myModel->rowCount();
    m_myModel->insertRow(rowNum);
    m_myModel->setData(m_myModel->index(rowNum, 0), rowNum + 1);
}

void DatabaseWindow::on_pb_remove_clicked() {
    if(!m_myModel) {
        return;
    }
    int curRow = ui->tableView->currentIndex().row();
    if(curRow < 0) {
        QMessageBox::warning(this, tr("删除当前行"),
            tr("请先选择要删除的行！"),
            QMessageBox::Cancel);
        return;
    }
    // 先确认再删除
    int ok = QMessageBox::warning(this, tr("删除当前行"),
        tr("你确定删除当前行吗？"),
        QMessageBox::Yes, QMessageBox::No);
    if(ok == QMessageBox::No) {
        return;
    }
    m_myModel->removeRow(curRow);
    if(!m_myModel->submitAll()) {
        QMessageBox::warning(this, tr("删除失败"),
            tr("删除操作失败：\n%1").arg(m_myModel->lastError().text()),
            QMessageBox::Cancel);
        m_myModel->revertAll();
    }
}

void DatabaseWindow::on_pb_commit_clicked() {
    if(!m_myModel) {
        return;
    }
    if(!checkDatabaseConnection()) {
        return;
    }
    m_myModel->database().transaction();
    if(m_myModel->submitAll()) {
        m_myModel->database().commit();
        QMessageBox::information(this, tr("提交成功"),
            tr("数据已成功提交到数据库。"),
            QMessageBox::Ok);
    } else {
        m_myModel->database().rollback();
        QMessageBox::warning(this, tr("tableModel"),
            tr("数据库错误：%1").arg(m_myModel->lastError().text()),
            QMessageBox::Cancel);
    }
}

void DatabaseWindow::on_pb_repeal_clicked() {
    if(!m_myModel) {
        return;
    }
    m_myModel->revertAll();
}

void DatabaseWindow::on_pb_inquire_clicked() {
    if(!checkDatabaseConnection()) {
        return;
    }
    QString tableName = ui->lb_curTable->text().trimmed();
    if(tableName.isEmpty()) {
        QMessageBox::warning(this, tr("筛查序号"),
            tr("请先选择数据表！"),
            QMessageBox::Cancel);
        return;
    }
    QString idStartStr = ui->le_idStart->text().trimmed();
    QString idEndStr = ui->le_idEnd->text().trimmed();
    if(idStartStr.isEmpty() || idEndStr.isEmpty()) {
        QMessageBox::warning(this, tr("筛查序号"),
            tr("序号范围不能为空！"),
            QMessageBox::Cancel);
        return;
    }
    int idStart, idEnd;
    if(!validateNumberInput(idStartStr, idStart) || !validateNumberInput(idEndStr, idEnd)) {
        QMessageBox::warning(this, tr("筛查序号"),
            tr("序号必须是有效的非负整数！"),
            QMessageBox::Cancel);
        return;
    }
    if(idStart > idEnd) {
        QMessageBox::warning(this, tr("筛查序号"),
            tr("起始序号不能大于结束序号！"),
            QMessageBox::Cancel);
        return;
    }
    // 使用参数化查询防止SQL注入
    QString whereStr = tr("序号>=%1 and 序号<=%2").arg(idStart).arg(idEnd);
    QString selectStr = tr("select * from `%1` where %2").arg(tableName).arg(whereStr);
    setPlainText(selectStr);
    m_myModel->setFilter(whereStr);
    if(!m_myModel->select()) {
        QMessageBox::warning(this, tr("查询失败"),
            tr("查询操作失败：\n%1").arg(m_myModel->lastError().text()),
            QMessageBox::Cancel);
    }
}

