#include "handledata.h"
#include "ui_handledata.h"

#include <QDebug>
#include <QToolTip>
#include <QSqlQuery>
#include <QSqlError>
#include <QSettings>
#include <QScroller>
#include <QMessageBox>
#include <QAbstractItemView>
#include <QHeaderView>
#include <QTableView>
#include <QCursor>

using namespace HandleDataConstants;

// ==================== CustomSqlModel 实现 ====================

CustomSqlModel::CustomSqlModel(QObject *parent, QSqlDatabase db)
    : QSqlTableModel(parent, db) {
}

QVariant CustomSqlModel::data(const QModelIndex &index, int role) const {
    if(role != Qt::DisplayRole) {
        return QSqlTableModel::data(index, role);
    }
    QSqlDatabase db = database();
    QString databaseName = db.databaseName();
    QString tableName = QSqlTableModel::tableName();
    // 处理 chonya 数据库中特定列的显示格式
    if(databaseName == DATABASE_CHONYA && tableName != TABLE_KEEP_MESSAGE) {
        int column = index.column();
        // 第 4、5、6、7 列添加重量单位后缀
        if(column == COLUMN_INDEX_4 || column == COLUMN_INDEX_5 ||
            column == COLUMN_INDEX_6 || column == COLUMN_INDEX_7) {
            QString originalValue = QSqlTableModel::data(index, role).toString();
            return originalValue + SUFFIX_WEIGHT;
        }
        // 第 3 列添加数量单位后缀
        else if(column == COLUMN_INDEX_3) {
            QString originalValue = QSqlTableModel::data(index, role).toString();
            return originalValue + SUFFIX_COUNT;
        }
    }
    return QSqlTableModel::data(index, role);
}

// ==================== HandleData 构造函数和析构函数 ====================

HandleData::HandleData(QVariant id_value, QVariant select_value, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HandleData)
    , idvalue_(id_value)
    , selectvalue_(select_value)
    , m_dataLoaded(false) {
    ui->setupUi(this);
    // 初始化表格名
    table = id_value.toString();
    table.replace("-", "_");
    // 设置滚动视图
    QScroller *pScroller = QScroller::scroller(ui->tableView);
    pScroller->grabGesture(ui->tableView->viewport(), QScroller::LeftMouseButtonGesture);
    ui->tableView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    // 根据选择类型初始化
    select_str = select_value.toString();
    if(select_str == SELECT_TYPE_MOLD) {
        myModel.setTable(QString("D%1").arg(table));
        ui->FindButton->setText("按机台号查找");
    } else if(select_str == SELECT_TYPE_KEEP) {
        myModel.setTable(TABLE_KEEP_MESSAGE);
        ui->LineEdit->setText(id_value.toString());
        ui->FindButton->setText("按模具编号查找");
        QString escapedValue = escapeSqlString(id_value.toString());
        QString whereStr = QObject::tr("模具编号 like '%%1%'").arg(escapedValue);
        myModel.setFilter(whereStr);
    } else if(select_str == SELECT_TYPE_MESSAGE) {
        ui->LineEdit->hide();
        ui->comboBox->hide();
        ui->FindButton->hide();
        ui->PushButton->hide();
        ui->ReturnButton->hide();
        ui->AddButton->hide();
        ui->DeleteButton->hide();
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        myModel.setTable(TABLE_CHENGXING_WORK);
        ui->LineEdit->setText(id_value.toString());
        ui->FindButton->setText("按模具编号查找");
        QString escapedValue = escapeSqlString(id_value.toString());
        QString whereStr = QObject::tr("模具编号 like '%%1%'").arg(escapedValue);
        myModel.setFilter(whereStr);
    }
    // 配置模型和视图（延迟加载数据）
    myModel.setEditStrategy(QSqlTableModel::OnManualSubmit);
    setupTableView();
    connect(ui->tableView, &QTableView::entered, this, &HandleData::doMouseTrackTip);
}

HandleData::~HandleData() {
    delete ui;
}

// ==================== 事件处理 ====================

void HandleData::closeEvent(QCloseEvent *event) {
    emit mysignal();
    event->accept();
}

void HandleData::showEvent(QShowEvent *event) {
    QMainWindow::showEvent(event);
    // 窗口显示时加载数据（延迟加载）
    if(!m_dataLoaded) {
        loadTableData();
    }
}

// ==================== 私有辅助函数 ====================

void HandleData::setupTableView() {
    // 设置模型
    ui->tableView->setModel(&myModel);
    // 优化表头设置：移除 ResizeToContents，使用 Interactive 模式提升性能
    // 注意：Stretch 和 ResizeToContents 不能同时使用，ResizeToContents 在大数据量时非常慢
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    // 设置默认列宽，避免初始渲染时计算所有列宽
    ui->tableView->horizontalHeader()->setDefaultSectionSize(120);
    // 启用鼠标跟踪
    ui->tableView->setMouseTracking(true);
    // 优化滚动性能
    ui->tableView->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
}

void HandleData::loadTableData() {
    if(m_dataLoaded) {
        return;  // 已经加载过，避免重复加载
    }
    
    // 执行查询
    if(!myModel.select()) {
        // 某些表可能只在特定数据库中存在，查询失败时不弹出提示框
        // 静默失败，避免干扰用户
        m_dataLoaded = true;  // 标记为已尝试加载，避免重复尝试
        return;
    }
    
    m_dataLoaded = true;
    // 数据加载完成后滚动到底部
    ui->tableView->scrollToBottom();
}

QString HandleData::extractDateFromComboBox() const {
    QString comboText = ui->comboBox->currentText();
    if(comboText == DATE_ALL) {
        return "";
    }
    int monthIndex = comboText.indexOf(DATE_MONTH_SEPARATOR);
    if(monthIndex > 0) {
        return comboText.left(monthIndex) + DATE_DOT;
    }
    return "";
}

QString HandleData::escapeSqlString(const QString &str) const {
    // 转义 SQL LIKE 查询中的特殊字符，防止 SQL 注入
    QString escaped = str;
    escaped.replace("'", "''");  // 转义单引号
    escaped.replace("%", "\\%"); // 转义百分号
    escaped.replace("_", "\\_"); // 转义下划线
    return escaped;
}

void HandleData::performSearch(const QString &searchField, const QString &searchValue) {
    if(searchField.isEmpty() || searchValue.isEmpty()) {
        return;
    }
    // 确保数据已加载
    if(!m_dataLoaded) {
        loadTableData();
    }
    QString date = extractDateFromComboBox();
    QString escapedValue = escapeSqlString(searchValue);
    QString escapedDate = escapeSqlString(date);
    QString whereStr;
    if(date.isEmpty()) {
        whereStr = QString("%1 like '%%2%'").arg(searchField, escapedValue);
    } else {
        whereStr = QString("%1 like '%%2%' and 日期 like '%%3%'")
            .arg(searchField, escapedValue, escapedDate);
    }
    myModel.setFilter(whereStr);
    myModel.select();
}

bool HandleData::validateRowIndex(int row) const {
    return row >= 0 && row < myModel.rowCount();
}

int HandleData::getNextIdValue() const {
    int rowCount = myModel.rowCount();
    if(rowCount == 0) {
        return 1;
    }
    // 获取最后一行第一列的值
    QModelIndex lastIndex = myModel.index(rowCount - 1, 0);
    QVariant lastValue = myModel.data(lastIndex);
    bool ok;
    int lastId = lastValue.toInt(&ok);
    if(ok && lastId > 0) {
        return lastId + 1;
    }
    return rowCount + 1;
}

// ==================== 数据操作槽函数 ====================

void HandleData::on_AddButton_clicked() {
    // 确保数据已加载
    if(!m_dataLoaded) {
        loadTableData();
    }
    int rowNum = myModel.rowCount();
    if(!myModel.insertRow(rowNum)) {
        QMessageBox::warning(this, "添加行", "无法添加新行", QMessageBox::Ok);
        return;
    }
    int nextId = getNextIdValue();
    QModelIndex newIndex = myModel.index(rowNum, 0);
    if(!myModel.setData(newIndex, nextId)) {
        QMessageBox::warning(this, "添加行", "无法设置新行的ID值", QMessageBox::Ok);
        myModel.removeRow(rowNum);
    }
}

void HandleData::on_DeleteButton_clicked() {
    int curRow = ui->tableView->currentIndex().row();
    if(!validateRowIndex(curRow)) {
        QMessageBox::warning(this, "删除行", "请先选择要删除的行", QMessageBox::Ok);
        return;
    }
    myModel.removeRow(curRow);
    int ok = QMessageBox::warning(this, "删除当前行", "你确定删除当前行吗？",
            QMessageBox::Yes, QMessageBox::No);
    if(ok == QMessageBox::No) {
        myModel.revertAll();
    } else {
        if(!myModel.submitAll()) {
            QMessageBox::warning(this, "删除行",
                QString("删除失败: %1").arg(myModel.lastError().text()),
                QMessageBox::Ok);
            myModel.revertAll();
        }
    }
}

void HandleData::on_PushButton_clicked() {
    myModel.database().transaction();
    if(myModel.submitAll()) {
        myModel.database().commit();
        QMessageBox::information(this, "提交修改", "数据已成功提交", QMessageBox::Ok);
    } else {
        myModel.database().rollback();
        QMessageBox::warning(this, "提交修改",
            QString("数据库错误: %1").arg(myModel.lastError().text()),
            QMessageBox::Ok);
    }
}

void HandleData::on_ReturnButton_clicked() {
    myModel.revertAll();
}

// ==================== 查找相关槽函数 ====================

void HandleData::on_FindButton_clicked() {
    QString searchValue = ui->LineEdit->text().trimmed();
    if(select_str == SELECT_TYPE_MOLD) {
        performSearch("机台号", searchValue);
    } else if(select_str == SELECT_TYPE_KEEP) {
        performSearch("模具编号", searchValue);
    }
}

void HandleData::on_LineEdit_returnPressed() {
    on_FindButton_clicked();
}

void HandleData::on_LineEdit_textChanged(const QString &arg1) {
    if(arg1.isEmpty() && select_str != SELECT_TYPE_MESSAGE) {
        QString date = extractDateFromComboBox();
        QString escapedDate = escapeSqlString(date);
        QString whereStr = QString("日期 like '%%1%'").arg(escapedDate);
        // 恢复原始表格
        if(select_str == SELECT_TYPE_MOLD) {
            myModel.setTable("D" + table);
        } else if(select_str == SELECT_TYPE_KEEP) {
            myModel.setTable(TABLE_KEEP_MESSAGE);
        }
        myModel.setFilter(whereStr);
        myModel.select();
    }
}

// ==================== 视图交互槽函数 ====================

void HandleData::on_tableView_clicked(const QModelIndex &index) {
    if(select_str != SELECT_TYPE_MESSAGE) {
        return;
    }
    // 检查是否点击了特定列（4, 7, 10, 13, 16）
    int column = index.column();
    if(column != 4 && column != 7 && column != 10 && column != 13 && column != 16) {
        return;
    }
    if(!validateRowIndex(index.row())) {
        return;
    }
    QModelIndex dataIndex = myModel.index(index.row(), 1);
    if(!dataIndex.isValid()) {
        return;
    }
    QString moldId = dataIndex.data().toString();
    QString spareId = index.data().toString();
    if(moldId.isEmpty() || spareId.isEmpty()) {
        QMessageBox::warning(this, "备件选择", "数据不完整", QMessageBox::Ok);
        return;
    }
    QSqlQuery query;
    query.prepare("SELECT 备件号 FROM " + QString(TABLE_CHENGXING_MESSAGE) +
        " WHERE 模具编号 = :mold_id AND 备件号 = :spare_id");
    query.bindValue(":mold_id", moldId);
    query.bindValue(":spare_id", spareId);
    if(!query.exec()) {
        QMessageBox::warning(this, "备件选择",
            QString("查询失败: %1").arg(query.lastError().text()),
            QMessageBox::Ok);
        return;
    }
    if(query.next()) {
        QSettings config("userconfig.ini", QSettings::IniFormat);
        config.setValue("SELECTIONCONFIG/Mold", moldId);
        config.setValue("SELECTIONCONFIG/Spare", spareId);
        config.setValue("SELECTIONCONFIG/Cabinet", "");
        config.sync();
        emit mysignal();
    } else {
        QMessageBox::warning(this, "备件选择", "仓库没有该备件的记录", QMessageBox::Ok);
    }
}

void HandleData::doMouseTrackTip(QModelIndex index) {
    if(index.isValid()) {
        QToolTip::showText(QCursor::pos(), index.data().toString());
    }
}
