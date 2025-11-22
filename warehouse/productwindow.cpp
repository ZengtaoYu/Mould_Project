#include "productwindow.h"
#include "ui_productwindow.h"

#include <QApplication>
#include <QComboBox>
#include <QCompleter>
#include <QFile>
#include <QFileDialog>
#include <QLineEdit>
#include <QListView>
#include <QMessageBox>
#include <QPainter>
#include <QScroller>
#include <QSettings>
#include <QSet>
#include <QSqlError>
#include <QSqlQuery>
#include <QStandardItem>
#include <QStyledItemDelegate>
#include <QTextStream>
#include <QAbstractItemView>
#include <QAbstractScrollArea>

// 常量定义
const QString ProductWindow::ALL_PRODUCTS = "全部料号";
const QString ProductWindow::ALL_SPARES = "全部备件";
const QString ProductWindow::TABLE_WORK = "chonya_work";
const QString ProductWindow::TABLE_MESSAGE = "chonya_message";
const QString ProductWindow::STYLE_SHEET =
    "QAbstractItemView{font: 18pt \"微软雅黑\";background-color:rgb(255,255,255);color:rgb(0,0,0);}"
    "QAbstractItemView::item:hover{background-color:rgb(0, 120, 212)}";
const int ProductWindow::MAX_VISIBLE_ITEMS = 10;
const int ProductWindow::SPARES_PER_LINE = 11;

// ColorDelegate类定义
class ColorDelegate : public QStyledItemDelegate {
public:
    explicit ColorDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
        const QModelIndex &index) const override {
        // 获取数据标记
        bool isUnselectable = index.data(Qt::UserRole).toBool();
        // 准备绘制选项
        QStyleOptionViewItem opt = option;
        initStyleOption(&opt, index);
        // 绘制自定义背景
        if(isUnselectable) {
            opt.backgroundBrush = QBrush(QColor("#ffe0e0")); // 浅红色背景
        } else {
            opt.backgroundBrush = QBrush(QColor("#e0ffe0")); // 浅绿色背景
        }
        // 应用样式绘制
        QApplication::style()->drawControl(QStyle::CE_ItemViewItem, &opt, painter);
    }
};

// ==================== 构造函数和析构函数 ====================

ProductWindow::ProductWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ProductWindow)
    , model_1(nullptr)
    , model_2(nullptr) {
    ui->setupUi(this);
    initializeUI();
}

ProductWindow::~ProductWindow() {
    delete ui;
}

// ==================== UI初始化相关 ====================

void ProductWindow::initializeUI() {
    ui->SureButton->hide();
    // 设置ColorDelegate（使用this作为父对象，自动管理内存）
    ColorDelegate *delegate = new ColorDelegate(this);
    ui->PIDView_1->setItemDelegate(delegate);
    ui->PIDView_2->setItemDelegate(delegate);
    // 设置滚动器
    setupScrollers();
    // 加载数据
    loadMoldList();
    // 加载产品和工站列表
    QString currentMold = ui->MoldCombo->currentText();
    if(!currentMold.isEmpty()) {
        loadProductList(currentMold);
        loadWorkList(currentMold);
    }
    // 设置自动完成
    setupCompleters();
    // 刷新数据
    RefreshData();
}

void ProductWindow::setupScrollers() {
    // 为下拉框设置滚动器
    setupScrollerForWidget(ui->MoldCombo->view());
    setupScrollerForWidget(ui->ProductCombo_1->view());
    setupScrollerForWidget(ui->ProductCombo_2->view());
    setupScrollerForWidget(ui->WorkCombo->view());
    // 为列表视图设置滚动器
    setupScrollerForWidget(ui->PIDView_1);
    setupScrollerForWidget(ui->PIDView_2);
}

void ProductWindow::setupScrollerForWidget(QWidget *widget) {
    if(!widget)
        return;
    // 对于QAbstractScrollArea及其子类，使用viewport
    QAbstractScrollArea *scrollArea = qobject_cast<QAbstractScrollArea *>(widget);
    if(scrollArea) {
        QScroller *scroller = QScroller::scroller(scrollArea);
        if(scroller) {
            scroller->grabGesture(scrollArea->viewport(), QScroller::LeftMouseButtonGesture);
        }
        QAbstractItemView *itemView = qobject_cast<QAbstractItemView *>(scrollArea);
        if(itemView) {
            itemView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        }
    } else {
        // 对于其他类型的widget，直接使用widget本身
        QScroller *scroller = QScroller::scroller(widget);
        if(scroller) {
            scroller->grabGesture(widget, QScroller::LeftMouseButtonGesture);
        }
    }
}

void ProductWindow::setupCompleters() {
    // 为所有下拉框设置自动完成
    QStringList moldList;
    QSqlQuery query;
    query.prepare("select 模具编号 from mold_message order by 模具编号 asc;");
    if(query.exec()) {
        while(query.next()) {
            moldList.append(query.value(0).toString());
        }
        setupCompleterForComboBox(ui->MoldCombo, moldList);
    }
    // 产品和工站的自动完成在loadProductList和loadWorkList中设置
}

void ProductWindow::setupCompleterForComboBox(QComboBox *combo, const QStringList &items) {
    if(!combo)
        return;
    QCompleter *completer = new QCompleter(items, this);
    completer->setMaxVisibleItems(MAX_VISIBLE_ITEMS);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setCompletionMode(QCompleter::PopupCompletion);
    completer->setFilterMode(Qt::MatchContains);
    combo->setCompleter(completer);
    QStyledItemDelegate *delegate = new QStyledItemDelegate(this);
    completer->popup()->setItemDelegate(delegate);
    completer->popup()->setStyleSheet(STYLE_SHEET);
}

// ==================== 数据加载相关 ====================

void ProductWindow::loadMoldList() {
    QSqlQuery query;
    query.prepare("select 模具编号 from mold_message order by 模具编号 asc;");
    if(!query.exec()) {
        QMessageBox::warning(this, "界面初始化",
            "模具数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    QStringList moldList;
    while(query.next()) {
        moldList.append(query.value(0).toString());
    }
    ui->MoldCombo->blockSignals(true);
    ui->MoldCombo->addItems(moldList);
    ui->MoldCombo->blockSignals(false);
    // 设置自动完成
    setupCompleterForComboBox(ui->MoldCombo, moldList);
    // 从配置文件加载上次选择的模具
    QSettings config("userconfig.ini", QSettings::IniFormat);
    ui->MoldCombo->setCurrentText(config.value("SELECTIONCONFIG/Mold").toString());
}

void ProductWindow::loadProductList(const QString &moldId) {
    if(moldId.isEmpty())
        return;
    QSqlQuery query;
    query.prepare("select 具体料号 from mold_message where 模具编号 = :mold_id");
    query.bindValue(":mold_id", moldId);
    if(!query.exec()) {
        QMessageBox::warning(this, "界面初始化",
            "模具具体料号查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    QStringList productList;
    productList.append(ALL_PRODUCTS);
    if(query.next()) {
        QStringList tempList = query.value(0).toString().split('#', Qt::SkipEmptyParts);
        for(const QString &item : tempList) {
            if(!item.isEmpty()) {
                productList.append(item);
            }
        }
    }
    // 更新ProductCombo_1
    ui->ProductCombo_1->blockSignals(true);
    ui->ProductCombo_1->clear();
    ui->ProductCombo_1->addItems(productList);
    ui->ProductCombo_1->blockSignals(false);
    setupCompleterForComboBox(ui->ProductCombo_1, productList);
    // 更新ProductCombo_2
    ui->ProductCombo_2->blockSignals(true);
    ui->ProductCombo_2->clear();
    ui->ProductCombo_2->addItems(productList);
    ui->ProductCombo_2->blockSignals(false);
    setupCompleterForComboBox(ui->ProductCombo_2, productList);
}

void ProductWindow::loadWorkList(const QString &moldId) {
    if(moldId.isEmpty())
        return;
    QSqlQuery query;
    query.prepare("select 工站 from mold_message where 模具编号 = :mold_id");
    query.bindValue(":mold_id", moldId);
    if(!query.exec()) {
        QMessageBox::warning(this, "界面初始化",
            "模具工站查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    QStringList workList;
    work.clear();
    if(query.next()) {
        QStringList list = {ALL_SPARES};
        QStringList tempList = list + query.value(0).toString().split('#', Qt::SkipEmptyParts);
        int n = 0;
        for(const QString &item : tempList) {
            if(!item.isEmpty()) {
                QString num = QString("%1.").arg(n);
                QString workItem = num + item;
                workList.append(workItem);
                work.append(workItem);
                n++;
            }
        }
    }
    ui->WorkCombo->blockSignals(true);
    ui->WorkCombo->clear();
    ui->WorkCombo->addItems(workList);
    ui->WorkCombo->blockSignals(false);
    setupCompleterForComboBox(ui->WorkCombo, workList);
}

// ==================== 工具函数 ====================

QString ProductWindow::extractSpareId(const QString &spareName) const {
    int pos = spareName.indexOf('(');
    if(pos != -1) {
        return spareName.left(pos).trimmed();
    }
    return spareName;
}

void ProductWindow::clearLineEditSelection(QComboBox *combo) {
    if(!combo)
        return;
    QLineEdit *lineEdit = combo->lineEdit();
    if(lineEdit) {
        lineEdit->setSelection(0, 0);
    }
}

// ==================== 数据刷新相关 ====================

void ProductWindow::RefreshData() {
    // 创建新模型
    if(model_1) {
        model_1->deleteLater();
    }
    if(model_2) {
        model_2->deleteLater();
    }
    model_1 = new QStandardItemModel(this);
    model_2 = new QStandardItemModel(this);
    // 准备查询
    QSqlQuery query;
    QSqlQuery query_2;
    prepareQuery(query, ui->ProductCombo_1->currentText(), true);
    prepareQuery(query_2, ui->ProductCombo_2->currentText(), false);
    // 执行查询并填充模型
    if(query.exec()) {
        refreshModelData(model_1, query, ui->ProductCombo_1->currentText(), true);
        ui->PIDView_1->setModel(model_1);
    } else {
        QMessageBox::warning(this, "数据刷新",
            "数据查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
    }
    if(query_2.exec()) {
        refreshModelData(model_2, query_2, ui->ProductCombo_2->currentText(), false);
        ui->PIDView_2->setModel(model_2);
    } else {
        QMessageBox::warning(this, "数据刷新",
            "数据查询失败：\n" + query_2.lastError().text(),
            QMessageBox::Cancel);
    }
}

void ProductWindow::prepareQuery(QSqlQuery &query, const QString &productComboText, bool isFirstModel) {
    Q_UNUSED(isFirstModel);
    QString productText = productComboText;
    int workIndex = ui->WorkCombo->currentIndex();
    QString moldId = ui->MoldCombo->currentText();
    if(workIndex == 0) {
        // 全部工站
        if(productText == ALL_PRODUCTS) {
            query.prepare(QString("select 备件号 from %1 where 模具编号 = :mold_id;").arg(TABLE_WORK));
        } else {
            query.prepare(QString("select 备件号 from %1 where 模具编号 = :mold_id and 产品料号 = :product_id;").arg(
                TABLE_WORK));
            query.bindValue(":product_id", productText);
        }
    } else {
        // 指定工站
        if(productText == ALL_PRODUCTS) {
            query.prepare(QString("select 备件号 from %1 where 模具编号 = :mold_id and 工站 = :work_id;").arg(TABLE_WORK));
        } else {
            query.prepare(
                QString("select 备件号 from %1 where 模具编号 = :mold_id and 工站 = :work_id and 产品料号 = :product_id;").arg(
                TABLE_WORK));
            query.bindValue(":product_id", productText);
        }
        query.bindValue(":work_id", workIndex);
    }
    query.bindValue(":mold_id", moldId);
}

void ProductWindow::refreshModelData(QStandardItemModel *model, QSqlQuery &query,
    const QString &productComboText, bool isFirstModel) {
    Q_UNUSED(productComboText);
    if(!model)
        return;
    int workNum = 1;
    QString productText = isFirstModel ? ui->ProductCombo_1->currentText() : ui->ProductCombo_2->currentText();
    int workIndex = ui->WorkCombo->currentIndex();
    while(query.next()) {
        // 如果是非全部料号且全部工站，添加工站标题
        if(productText != ALL_PRODUCTS && workIndex == 0) {
            if(workNum < work.size()) {
                QStandardItem *workItem = new QStandardItem(work[workNum++]);
                workItem->setData(true, Qt::UserRole);
                workItem->setFlags(workItem->flags() & ~Qt::ItemIsSelectable);
                model->appendRow(workItem);
            }
        }
        // 处理备件列表
        QStringList tempList = query.value(0).toString().split('#', Qt::SkipEmptyParts);
        QSet<QString> processedItems;
        for(const QString &item : tempList) {
            if(!item.isEmpty() &&
                !processedItems.contains(item) &&
                !(productText == ALL_PRODUCTS && item == "共用")) {
                processedItems.insert(item);
                QStandardItem *modelItem = new QStandardItem(item);
                model->appendRow(modelItem);
            }
        }
    }
    // 如果没有数据，显示提示
    if(model->rowCount() == 0) {
        QStandardItem *emptyItem = new QStandardItem("     该工站暂未\n     录入数据");
        emptyItem->setData(true, Qt::UserRole);
        emptyItem->setFlags(emptyItem->flags() & ~Qt::ItemIsSelectable);
        model->appendRow(emptyItem);
    }
}

// ==================== 按钮槽函数 ====================

void ProductWindow::on_SureButton_clicked() {
    QModelIndex currentIndex = ui->PIDView_1->currentIndex();
    if(!currentIndex.isValid()) {
        QMessageBox::warning(this, "备件选择", "请先选择一个备件", QMessageBox::Cancel);
        return;
    }
    QString spareName = currentIndex.data().toString();
    QString spareId = extractSpareId(spareName);
    QSqlQuery query;
    query.prepare(QString("select 备件号 from %1 where 模具编号 = :mold_id and 备件号 = :spare_id;").arg(
        TABLE_MESSAGE));
    query.bindValue(":mold_id", ui->MoldCombo->currentText());
    query.bindValue(":spare_id", spareId);
    if(!query.exec()) {
        QMessageBox::warning(this, "备件选择",
            "查询失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return;
    }
    if(query.next()) {
        QSettings config("userconfig.ini", QSettings::IniFormat);
        config.setValue("SELECTIONCONFIG/Mold", ui->MoldCombo->currentText());
        config.setValue("SELECTIONCONFIG/Spare", spareId);
        config.setValue("SELECTIONCONFIG/Cabinet", "");
        config.sync();
        emit mysignal();
    } else {
        QMessageBox::warning(this, "备件选择", "仓库没有该备件的记录\n", QMessageBox::Cancel);
    }
}

void ProductWindow::on_ReturnButton_clicked() {
    this->close();
}

void ProductWindow::on_OutButton_clicked() {
    QAbstractItemModel *model = ui->PIDView_1->model();
    if(!model) {
        QMessageBox::warning(this, "导出数据", "没有可导出的数据", QMessageBox::Cancel);
        return;
    }
    QSettings config("userconfig.ini", QSettings::IniFormat);
    QString defaultPath = config.value("DOCUMENTCONFIG/DocumentPath").toString();
    QString defaultFileName = defaultPath + ui->MoldCombo->currentText() + "备件更换单";
    QString fileName = QFileDialog::getSaveFileName(this, "导出冲压模具备件盘点记录表",
            defaultFileName, "文本文件 (*.txt)");
    if(fileName.isEmpty()) {
        return;
    }
    // 更新配置文件中的路径
    QString filePath = fileName.left(fileName.lastIndexOf('/')) + "/";
    config.setValue("DOCUMENTCONFIG/DocumentPath", filePath);
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "导出数据",
            "无法打开文件进行写入：\n" + file.errorString(),
            QMessageBox::Cancel);
        return;
    }
    QTextStream out(&file);
    // 导出第一个模型
    out << ui->MoldCombo->currentText() << "#" << ui->ProductCombo_1->currentText() << ":\n";
    exportModelToStream(out, model);
    // 导出第二个模型
    out << "\n";
    out << ui->MoldCombo->currentText() << "#" << ui->ProductCombo_2->currentText() << ":\n";
    exportModelToStream(out, model_2);
    file.close();
    QMessageBox::information(this, "导出数据", "数据导出成功", QMessageBox::Ok);
}

void ProductWindow::exportModelToStream(QTextStream &out, QAbstractItemModel *model) {
    if(!model)
        return;
    int t = 0;
    for(int row = 0; row < model->rowCount(); ++row) {
        QModelIndex index = model->index(row, 0);
        QString text = model->data(index, Qt::DisplayRole).toString();
        QString spareName = extractSpareId(text);
        if(spareName.contains(".")) {
            // 工站标题
            if(t != 0) {
                out << "\n";
            }
            t = 1;
            out << spareName << "\t\n";
        } else {
            // 备件号
            t++;
            out << spareName << "\t";
            if(t % SPARES_PER_LINE == 0) {
                out << "\n";
            }
        }
    }
    out << "\n";
}

// ==================== 下拉框槽函数 ====================

void ProductWindow::on_MoldCombo_currentIndexChanged(const QString &arg1) {
    if(arg1.isEmpty())
        return;
    ui->ProductCombo_1->clear();
    ui->ProductCombo_2->clear();
    ui->WorkCombo->clear();
    loadProductList(arg1);
    loadWorkList(arg1);
    RefreshData();
    clearLineEditSelection(ui->MoldCombo);
}

void ProductWindow::on_ProductCombo_1_currentIndexChanged(const QString &) {
    RefreshData();
    clearLineEditSelection(ui->ProductCombo_1);
}

void ProductWindow::on_ProductCombo_2_currentIndexChanged(const QString &) {
    RefreshData();
    clearLineEditSelection(ui->ProductCombo_2);  // 修复：使用正确的combo
}

void ProductWindow::on_WorkCombo_currentIndexChanged(const QString &) {
    RefreshData();
    clearLineEditSelection(ui->WorkCombo);
}
