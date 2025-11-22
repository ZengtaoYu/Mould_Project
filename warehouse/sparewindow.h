#ifndef SPAREWINDOW_H
#define SPAREWINDOW_H

#include <QMainWindow>
#include <QAbstractItemView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QBrush>
#include <QColor>
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QApplication>
#include <QStyle>

// 前向声明
class QSettings;
class QSqlQuery;
class QCompleter;
class QMessageBox;
class QFileDialog;
class QTextStream;
class QLineEdit;
class QScroller;

namespace Ui {
class SpareWindow;
}

class SpareWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit SpareWindow(QWidget *parent = nullptr);
    ~SpareWindow();

signals:
    void mysignal();

private slots:
    void RefreshData();
    void on_OutButton_clicked();
    void on_ReturnButton_clicked();
    void on_MoldCombo_currentIndexChanged(const QString &arg1);
    void on_WorkCombo_currentIndexChanged(const QString &arg1);
    void on_ProductCombo_1_currentIndexChanged(const QString &arg1);
    void on_ProductCombo_2_currentIndexChanged(const QString &arg1);
    void on_PIDView_1_clicked(const QModelIndex &index);
    void on_PIDView_2_clicked(const QModelIndex &index);

private:
    // 内部委托类
    class ColorDelegate : public QStyledItemDelegate {
    public:
        void paint(QPainter *painter, const QStyleOptionViewItem &option,
            const QModelIndex &index) const override {
            // 获取数据标记
            bool isUnselectable = index.data(Qt::UserRole).toBool();
            // 准备绘制选项
            QStyleOptionViewItem opt = option;
            initStyleOption(&opt, index);
            // 绘制自定义背景
            if(isUnselectable) {
                opt.backgroundBrush = QBrush(UNSELECTABLE_BACKGROUND_COLOR);
            } else {
                opt.backgroundBrush = QBrush(SELECTABLE_BACKGROUND_COLOR);
            }
            // 应用样式绘制
            QApplication::style()->drawControl(QStyle::CE_ItemViewItem, &opt, painter);
        }

    private:
        static const QColor UNSELECTABLE_BACKGROUND_COLOR; // 浅红色背景
        static const QColor SELECTABLE_BACKGROUND_COLOR;   // 浅绿色背景
    };

    Ui::SpareWindow *ui;

    // 成员变量
    static const QStringList m_workTypeList;
    QStandardItemModel *m_model_1;
    QStandardItemModel *m_model_2;
};

#endif // SPAREWINDOW_H
