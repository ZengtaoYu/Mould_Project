#include "handlebom.h"
#include "ui_handlebom.h"
#include <QScroller>
#include <QToolTip>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>
#include <QHeaderView>
#include <QCursor>

// 表配置定义
const QList<TableConfig> HandleBom::s_tableConfigs = {
    {"bom_current_bom", "厂内模号", "模号不能为空！", true},      // 0: 现状BOM
    {"bom_theory_bom", "厂内模号", "模号不能为空！", true},       // 1: 理论BOM
    {"bom_waste_price", "名称", "名称不能为空！", false},         // 2: 废料价格
    {"bom_box_price", "存货名称", "名称不能为空！", false},       // 3: 纸箱、吸塑盒单价
    {"bom_work_price", "产品料号", "料号不能为空！", false},      // 4: 工时
    {"machine_cost", "厂内模号", "模号不能为空！", true}          // 5: 机台成本
};

HandleBom::HandleBom(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HandleBom) {
    ui->setupUi(this);
    // 初始化数据加载标记
    for(int i = 0; i < 6; ++i) {
        m_dataLoaded[i] = false;
    }
    // 初始化模型和视图
    initializeModels();
    // 连接标签页切换信号，实现延迟加载
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &HandleBom::on_tabWidget_currentChanged);
    // 加载第一个标签页的数据（如果当前显示第一个标签页）
    if(ui->tabWidget->currentIndex() == 0) {
        loadTableData(0);
    }
}

HandleBom::~HandleBom() {
    // 清理模型
    for(QSqlTableModel *model : m_models) {
        delete model;
    }
    delete ui;
}

// ==================== 初始化函数 ====================

void HandleBom::initializeModels() {
    // 创建模型并添加到容器
    m_models.append(new QSqlTableModel(this));
    m_models.append(new QSqlTableModel(this));
    m_models.append(new QSqlTableModel(this));
    m_models.append(new QSqlTableModel(this));
    m_models.append(new QSqlTableModel(this));
    m_models.append(new QSqlTableModel(this));
    // 创建视图列表
    m_tableViews.append(ui->tableView);
    m_tableViews.append(ui->tableView_1);
    m_tableViews.append(ui->tableView_2);
    m_tableViews.append(ui->tableView_3);
    m_tableViews.append(ui->tableView_4);
    m_tableViews.append(ui->tableView_5);
    // 初始化每个模型和视图
    for(int i = 0; i < m_models.size() && i < s_tableConfigs.size(); ++i) {
        QSqlTableModel *model = m_models[i];
        QTableView *tableView = m_tableViews[i];
        const TableConfig &config = s_tableConfigs[i];
        // 设置表名和编辑策略
        model->setTable(config.tableName);
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        // 方案1：延迟加载 - 不立即加载数据，等待用户切换到对应标签页时再加载
        // 设置视图
        setupTableView(i, tableView, model);
        setupScroller(tableView);
    }
}

void HandleBom::setupTableView(int index, QTableView *tableView, QSqlTableModel *model) {
    Q_UNUSED(index);
    // 设置模型
    tableView->setModel(model);
    // 优化表头设置：移除 ResizeToContents，使用 Interactive 模式提升性能
    // 注意：Stretch 和 ResizeToContents 不能同时使用，ResizeToContents 在大数据量时非常慢
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    // 设置默认列宽，避免初始渲染时计算所有列宽
    tableView->horizontalHeader()->setDefaultSectionSize(120);
    // 启用鼠标跟踪
    tableView->setMouseTracking(true);
    // 连接鼠标悬停信号
    connect(tableView, &QTableView::entered, this, &HandleBom::doMouseTrackTip);
    // 优化滚动性能
    tableView->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
}

void HandleBom::setupScroller(QTableView *tableView) {
    QScroller *scroller = QScroller::scroller(tableView);
    if(scroller) {
        scroller->grabGesture(tableView->viewport(), QScroller::LeftMouseButtonGesture);
        tableView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    }
}

// ==================== 公共操作函数 ====================

void HandleBom::submitChanges(int modelIndex) {
    if(!isValidModelIndex(modelIndex)) {
        showErrorMessage("错误", "无效的模型索引");
        return;
    }
    QSqlTableModel *model = m_models[modelIndex];
    if(!model) {
        showErrorMessage("错误", "模型指针为空");
        return;
    }
    model->database().transaction();
    if(model->submitAll()) {
        model->database().commit();
    } else {
        model->database().rollback();
        QString errorMsg = QString("数据库错误: %1").arg(model->lastError().text());
        showErrorMessage("提交修改", errorMsg);
    }
}

void HandleBom::revertChanges(int modelIndex) {
    if(!isValidModelIndex(modelIndex)) {
        return;
    }
    QSqlTableModel *model = m_models[modelIndex];
    if(model) {
        model->revertAll();
    }
}

void HandleBom::addRecord(int modelIndex, bool autoIncrementId) {
    if(!isValidModelIndex(modelIndex)) {
        showErrorMessage("错误", "无效的模型索引");
        return;
    }
    QSqlTableModel *model = m_models[modelIndex];
    if(!model) {
        showErrorMessage("错误", "模型指针为空");
        return;
    }
    int rowNum = model->rowCount();
    model->insertRow(rowNum);
    // 如果需要自动递增ID
    if(autoIncrementId && rowNum > 0) {
        QModelIndex prevIndex = model->index(rowNum - 1, 0);
        if(prevIndex.isValid()) {
            QVariant prevValue = prevIndex.data();
            bool ok = false;
            int prevId = prevValue.toInt(&ok);
            if(ok) {
                model->setData(model->index(rowNum, 0), prevId + 1);
            }
        }
    }
}

void HandleBom::deleteRecord(int modelIndex, QTableView *tableView) {
    if(!isValidModelIndex(modelIndex)) {
        showErrorMessage("错误", "无效的模型索引");
        return;
    }
    QSqlTableModel *model = m_models[modelIndex];
    if(!model || !tableView) {
        showErrorMessage("错误", "模型或视图指针为空");
        return;
    }
    // 检查是否有选中的行
    QModelIndex currentIndex = tableView->currentIndex();
    if(!currentIndex.isValid()) {
        showErrorMessage("删除", "请先选择要删除的行");
        return;
    }
    int curRow = currentIndex.row();
    if(curRow < 0 || curRow >= model->rowCount()) {
        showErrorMessage("删除", "无效的行索引");
        return;
    }
    // 先询问用户确认
    int ret = QMessageBox::warning(this, "删除当前行", "你确定删除当前行吗？",
            QMessageBox::Yes | QMessageBox::No,
            QMessageBox::No);
    if(ret == QMessageBox::Yes) {
        model->removeRow(curRow);
        if(!model->submitAll()) {
            model->revertAll();
            showErrorMessage("删除", QString("删除失败: %1").arg(model->lastError().text()));
        }
    }
}

void HandleBom::searchRecord(int modelIndex, const QString &searchText, const QString &columnName) {
    if(!isValidModelIndex(modelIndex)) {
        showErrorMessage("错误", "无效的模型索引");
        return;
    }
    QSqlTableModel *model = m_models[modelIndex];
    if(!model) {
        showErrorMessage("错误", "模型指针为空");
        return;
    }
    if(searchText.isEmpty()) {
        const TableConfig &config = s_tableConfigs[modelIndex];
        showErrorMessage("查找", config.searchPlaceholder);
        return;
    }
    QString filter = buildSearchFilter(columnName, searchText);
    model->setFilter(filter);
    model->select();
}

void HandleBom::resetTableFilter(int modelIndex) {
    if(!isValidModelIndex(modelIndex)) {
        return;
    }
    QSqlTableModel *model = m_models[modelIndex];
    if(!model) {
        return;
    }
    const TableConfig &config = s_tableConfigs[modelIndex];
    model->setTable(config.tableName);
    model->select();
}

// ==================== 辅助函数 ====================

bool HandleBom::isValidModelIndex(int index) const {
    return index >= 0 && index < m_models.size() && index < s_tableConfigs.size();
}

QString HandleBom::buildSearchFilter(const QString &columnName, const QString &searchText) const {
    // 使用参数化查询方式构建过滤条件，避免SQL注入
    // QSqlTableModel的setFilter会自动处理特殊字符
    return QString("%1 LIKE '%%2%'").arg(columnName, searchText);
}

void HandleBom::showErrorMessage(const QString &title, const QString &message) {
    QMessageBox::warning(this, title, message);
}

// ==================== 性能优化函数 ====================

void HandleBom::loadTableData(int modelIndex) {
    if(!isValidModelIndex(modelIndex)) {
        return;
    }
    if(m_dataLoaded[modelIndex]) {
        return;  // 已经加载过，避免重复加载
    }
    QSqlTableModel *model = m_models[modelIndex];
    if(!model) {
        return;
    }
    // 执行查询
    if(!model->select()) {
        // 某些表可能只在特定数据库中存在（如冲压或成型），查询失败时不弹出提示框
        // 静默失败，避免干扰用户
        m_dataLoaded[modelIndex] = true;  // 标记为已尝试加载，避免重复尝试
        return;
    }
    m_dataLoaded[modelIndex] = true;
}

// ==================== 鼠标悬停提示 ====================

void HandleBom::doMouseTrackTip(QModelIndex index) {
    if(index.isValid()) {
        QToolTip::showText(QCursor::pos(), index.data().toString());
    }
}

// ==================== 现状BOM相关槽函数 ====================

void HandleBom::on_AddButton_clicked() {
    addRecord(0, s_tableConfigs[0].autoIncrementId);
}

void HandleBom::on_PushButton_clicked() {
    submitChanges(0);
}

void HandleBom::on_ReturnButton_clicked() {
    revertChanges(0);
}

void HandleBom::on_DeleteButton_clicked() {
    deleteRecord(0, ui->tableView);
}

void HandleBom::on_FindButton_clicked() {
    QString searchText = ui->LineEdit->text();
    searchRecord(0, searchText, s_tableConfigs[0].searchColumn);
}

void HandleBom::on_LineEdit_returnPressed() {
    on_FindButton_clicked();
}

void HandleBom::on_LineEdit_textChanged(const QString &arg1) {
    if(arg1.isEmpty()) {
        resetTableFilter(0);
    }
}

// ==================== 理论BOM相关槽函数 ====================

void HandleBom::on_AddButton_1_clicked() {
    addRecord(1, s_tableConfigs[1].autoIncrementId);
}

void HandleBom::on_PushButton_1_clicked() {
    submitChanges(1);
}

void HandleBom::on_ReturnButton_1_clicked() {
    revertChanges(1);
}

void HandleBom::on_DeleteButton_1_clicked() {
    deleteRecord(1, ui->tableView_1);
}

void HandleBom::on_FindButton_1_clicked() {
    QString searchText = ui->LineEdit_1->text();
    searchRecord(1, searchText, s_tableConfigs[1].searchColumn);
}

void HandleBom::on_LineEdit_1_returnPressed() {
    on_FindButton_1_clicked();
}

void HandleBom::on_LineEdit_1_textChanged(const QString &arg1) {
    if(arg1.isEmpty()) {
        resetTableFilter(1);
    }
}

// ==================== 废料价格相关槽函数 ====================

void HandleBom::on_AddButton_2_clicked() {
    addRecord(2, s_tableConfigs[2].autoIncrementId);
}

void HandleBom::on_PushButton_2_clicked() {
    submitChanges(2);
}

void HandleBom::on_ReturnButton_2_clicked() {
    revertChanges(2);
}

void HandleBom::on_DeleteButton_2_clicked() {
    deleteRecord(2, ui->tableView_2);
}

void HandleBom::on_FindButton_2_clicked() {
    QString searchText = ui->LineEdit_2->text();
    searchRecord(2, searchText, s_tableConfigs[2].searchColumn);
}

void HandleBom::on_LineEdit_2_returnPressed() {
    on_FindButton_2_clicked();
}

void HandleBom::on_LineEdit_2_textChanged(const QString &arg1) {
    if(arg1.isEmpty()) {
        resetTableFilter(2);
    }
}

// ==================== 纸箱、吸塑盒单价相关槽函数 ====================

void HandleBom::on_AddButton_3_clicked() {
    addRecord(3, s_tableConfigs[3].autoIncrementId);
}

void HandleBom::on_PushButton_3_clicked() {
    submitChanges(3);
}

void HandleBom::on_ReturnButton_3_clicked() {
    revertChanges(3);
}

void HandleBom::on_DeleteButton_3_clicked() {
    deleteRecord(3, ui->tableView_3);
}

void HandleBom::on_FindButton_3_clicked() {
    QString searchText = ui->LineEdit_3->text();
    searchRecord(3, searchText, s_tableConfigs[3].searchColumn);
}

void HandleBom::on_LineEdit_3_returnPressed() {
    on_FindButton_3_clicked();
}

void HandleBom::on_LineEdit_3_textChanged(const QString &arg1) {
    if(arg1.isEmpty()) {
        resetTableFilter(3);
    }
}

// ==================== 工时相关槽函数 ====================

void HandleBom::on_AddButton_4_clicked() {
    addRecord(4, s_tableConfigs[4].autoIncrementId);
}

void HandleBom::on_PushButton_4_clicked() {
    submitChanges(4);
}

void HandleBom::on_ReturnButton_4_clicked() {
    revertChanges(4);
}

void HandleBom::on_DeleteButton_4_clicked() {
    deleteRecord(4, ui->tableView_4);
}

void HandleBom::on_FindButton_4_clicked() {
    QString searchText = ui->LineEdit_4->text();
    searchRecord(4, searchText, s_tableConfigs[4].searchColumn);
}

void HandleBom::on_LineEdit_4_returnPressed() {
    on_FindButton_4_clicked();
}

void HandleBom::on_LineEdit_4_textChanged(const QString &arg1) {
    if(arg1.isEmpty()) {
        resetTableFilter(4);
    }
}

// ==================== 机台成本相关槽函数 ====================

void HandleBom::on_AddButton_5_clicked() {
    addRecord(5, s_tableConfigs[5].autoIncrementId);
}

void HandleBom::on_PushButton_5_clicked() {
    submitChanges(5);
}

void HandleBom::on_ReturnButton_5_clicked() {
    revertChanges(5);
}

void HandleBom::on_DeleteButton_5_clicked() {
    deleteRecord(5, ui->tableView_5);
}

void HandleBom::on_FindButton_5_clicked() {
    QString searchText = ui->LineEdit_5->text();
    searchRecord(5, searchText, s_tableConfigs[5].searchColumn);
}

void HandleBom::on_LineEdit_5_returnPressed() {
    on_FindButton_5_clicked();
}

void HandleBom::on_LineEdit_5_textChanged(const QString &arg1) {
    if(arg1.isEmpty()) {
        resetTableFilter(5);
    }
}

// ==================== 标签页切换延迟加载 ====================

void HandleBom::on_tabWidget_currentChanged(int index) {
    // 当切换到某个标签页时，才加载对应的数据
    // 这样可以避免一次性加载所有6个表的数据
    if(index >= 0 && index < 6 && !m_dataLoaded[index]) {
        loadTableData(index);
    }
}
