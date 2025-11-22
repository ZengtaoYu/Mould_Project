/********************************************************************************
** Form generated from reading UI file 'databasewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEWINDOW_H
#define UI_DATABASEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabaseWindow
{
public:
    QPlainTextEdit *te_output;
    QPushButton *pb_connect;
    QPushButton *pb_showAllDb;
    QLabel *label;
    QPlainTextEdit *te_input;
    QLabel *label_2;
    QPushButton *pb_showCurDb;
    QPushButton *pb_openDb;
    QPushButton *pb_showTable;
    QComboBox *cb_db;
    QComboBox *cb_table;
    QLabel *lb_curDb;
    QPushButton *pb_setTable;
    QLabel *label_3;
    QLabel *lb_curTable;
    QTableView *tableView;
    QLabel *label_4;
    QLineEdit *le_idStart;
    QLineEdit *le_idEnd;
    QLabel *label_5;
    QPushButton *pb_inquire;
    QPushButton *pb_display;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pb_showTableData;
    QPushButton *pb_commit;
    QPushButton *pb_repeal;
    QPushButton *pb_record;
    QPushButton *pb_remove;

    void setupUi(QWidget *DatabaseWindow)
    {
        if (DatabaseWindow->objectName().isEmpty())
            DatabaseWindow->setObjectName(QString::fromUtf8("DatabaseWindow"));
        DatabaseWindow->resize(750, 615);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DatabaseWindow->sizePolicy().hasHeightForWidth());
        DatabaseWindow->setSizePolicy(sizePolicy);
        DatabaseWindow->setMinimumSize(QSize(750, 615));
        DatabaseWindow->setMaximumSize(QSize(750, 615));
        te_output = new QPlainTextEdit(DatabaseWindow);
        te_output->setObjectName(QString::fromUtf8("te_output"));
        te_output->setGeometry(QRect(110, 110, 191, 191));
        te_output->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        pb_connect = new QPushButton(DatabaseWindow);
        pb_connect->setObjectName(QString::fromUtf8("pb_connect"));
        pb_connect->setGeometry(QRect(600, 20, 141, 31));
        pb_connect->setCursor(QCursor(Qt::PointingHandCursor));
        pb_showAllDb = new QPushButton(DatabaseWindow);
        pb_showAllDb->setObjectName(QString::fromUtf8("pb_showAllDb"));
        pb_showAllDb->setGeometry(QRect(319, 110, 141, 31));
        pb_showAllDb->setCursor(QCursor(Qt::PointingHandCursor));
        label = new QLabel(DatabaseWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 25, 91, 31));
        label->setAlignment(Qt::AlignCenter);
        te_input = new QPlainTextEdit(DatabaseWindow);
        te_input->setObjectName(QString::fromUtf8("te_input"));
        te_input->setGeometry(QRect(110, 15, 481, 71));
        te_input->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        label_2 = new QLabel(DatabaseWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 120, 91, 31));
        label_2->setAlignment(Qt::AlignCenter);
        pb_showCurDb = new QPushButton(DatabaseWindow);
        pb_showCurDb->setObjectName(QString::fromUtf8("pb_showCurDb"));
        pb_showCurDb->setGeometry(QRect(320, 160, 141, 31));
        pb_showCurDb->setCursor(QCursor(Qt::PointingHandCursor));
        pb_openDb = new QPushButton(DatabaseWindow);
        pb_openDb->setObjectName(QString::fromUtf8("pb_openDb"));
        pb_openDb->setGeometry(QRect(600, 110, 141, 31));
        pb_openDb->setCursor(QCursor(Qt::PointingHandCursor));
        pb_showTable = new QPushButton(DatabaseWindow);
        pb_showTable->setObjectName(QString::fromUtf8("pb_showTable"));
        pb_showTable->setGeometry(QRect(320, 210, 141, 31));
        pb_showTable->setCursor(QCursor(Qt::PointingHandCursor));
        cb_db = new QComboBox(DatabaseWindow);
        cb_db->setObjectName(QString::fromUtf8("cb_db"));
        cb_db->setGeometry(QRect(470, 110, 121, 31));
        cb_db->setCursor(QCursor(Qt::ArrowCursor));
        cb_table = new QComboBox(DatabaseWindow);
        cb_table->setObjectName(QString::fromUtf8("cb_table"));
        cb_table->setGeometry(QRect(470, 210, 121, 31));
        cb_table->setCursor(QCursor(Qt::ArrowCursor));
        lb_curDb = new QLabel(DatabaseWindow);
        lb_curDb->setObjectName(QString::fromUtf8("lb_curDb"));
        lb_curDb->setGeometry(QRect(470, 160, 121, 31));
        lb_curDb->setCursor(QCursor(Qt::IBeamCursor));
        lb_curDb->setFrameShape(QFrame::Box);
        lb_curDb->setAlignment(Qt::AlignCenter);
        pb_setTable = new QPushButton(DatabaseWindow);
        pb_setTable->setObjectName(QString::fromUtf8("pb_setTable"));
        pb_setTable->setGeometry(QRect(600, 210, 141, 31));
        pb_setTable->setCursor(QCursor(Qt::PointingHandCursor));
        label_3 = new QLabel(DatabaseWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(330, 270, 131, 31));
        label_3->setAlignment(Qt::AlignCenter);
        lb_curTable = new QLabel(DatabaseWindow);
        lb_curTable->setObjectName(QString::fromUtf8("lb_curTable"));
        lb_curTable->setGeometry(QRect(470, 270, 121, 31));
        lb_curTable->setCursor(QCursor(Qt::IBeamCursor));
        lb_curTable->setFrameShape(QFrame::Box);
        lb_curTable->setAlignment(Qt::AlignCenter);
        tableView = new QTableView(DatabaseWindow);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 310, 581, 251));
        tableView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        label_4 = new QLabel(DatabaseWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 570, 81, 31));
        label_4->setAlignment(Qt::AlignCenter);
        le_idStart = new QLineEdit(DatabaseWindow);
        le_idStart->setObjectName(QString::fromUtf8("le_idStart"));
        le_idStart->setGeometry(QRect(100, 570, 71, 31));
        le_idStart->setAlignment(Qt::AlignCenter);
        le_idEnd = new QLineEdit(DatabaseWindow);
        le_idEnd->setObjectName(QString::fromUtf8("le_idEnd"));
        le_idEnd->setGeometry(QRect(210, 570, 71, 31));
        le_idEnd->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(DatabaseWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(180, 570, 21, 31));
        label_5->setAlignment(Qt::AlignCenter);
        pb_inquire = new QPushButton(DatabaseWindow);
        pb_inquire->setObjectName(QString::fromUtf8("pb_inquire"));
        pb_inquire->setGeometry(QRect(290, 570, 91, 31));
        pb_inquire->setCursor(QCursor(Qt::PointingHandCursor));
        pb_display = new QPushButton(DatabaseWindow);
        pb_display->setObjectName(QString::fromUtf8("pb_display"));
        pb_display->setGeometry(QRect(400, 570, 101, 31));
        pb_display->setCursor(QCursor(Qt::PointingHandCursor));
        layoutWidget = new QWidget(DatabaseWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(601, 321, 139, 241));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pb_showTableData = new QPushButton(layoutWidget);
        pb_showTableData->setObjectName(QString::fromUtf8("pb_showTableData"));
        pb_showTableData->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(pb_showTableData);

        pb_commit = new QPushButton(layoutWidget);
        pb_commit->setObjectName(QString::fromUtf8("pb_commit"));
        pb_commit->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(pb_commit);

        pb_repeal = new QPushButton(layoutWidget);
        pb_repeal->setObjectName(QString::fromUtf8("pb_repeal"));
        pb_repeal->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(pb_repeal);

        pb_record = new QPushButton(layoutWidget);
        pb_record->setObjectName(QString::fromUtf8("pb_record"));
        pb_record->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(pb_record);

        pb_remove = new QPushButton(layoutWidget);
        pb_remove->setObjectName(QString::fromUtf8("pb_remove"));
        pb_remove->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(pb_remove);

        QWidget::setTabOrder(te_input, pb_connect);
        QWidget::setTabOrder(pb_connect, te_output);
        QWidget::setTabOrder(te_output, pb_showAllDb);
        QWidget::setTabOrder(pb_showAllDb, cb_db);
        QWidget::setTabOrder(cb_db, pb_openDb);
        QWidget::setTabOrder(pb_openDb, pb_showCurDb);
        QWidget::setTabOrder(pb_showCurDb, pb_showTable);
        QWidget::setTabOrder(pb_showTable, cb_table);
        QWidget::setTabOrder(cb_table, pb_setTable);
        QWidget::setTabOrder(pb_setTable, tableView);
        QWidget::setTabOrder(tableView, pb_showTableData);
        QWidget::setTabOrder(pb_showTableData, pb_commit);
        QWidget::setTabOrder(pb_commit, pb_repeal);
        QWidget::setTabOrder(pb_repeal, pb_record);
        QWidget::setTabOrder(pb_record, pb_remove);
        QWidget::setTabOrder(pb_remove, le_idStart);
        QWidget::setTabOrder(le_idStart, le_idEnd);
        QWidget::setTabOrder(le_idEnd, pb_inquire);
        QWidget::setTabOrder(pb_inquire, pb_display);

        retranslateUi(DatabaseWindow);

        QMetaObject::connectSlotsByName(DatabaseWindow);
    } // setupUi

    void retranslateUi(QWidget *DatabaseWindow)
    {
        DatabaseWindow->setWindowTitle(QCoreApplication::translate("DatabaseWindow", "MySQL", nullptr));
        pb_connect->setText(QCoreApplication::translate("DatabaseWindow", "\346\211\247\350\241\214", nullptr));
        pb_showAllDb->setText(QCoreApplication::translate("DatabaseWindow", "\346\230\276\347\244\272\346\211\200\346\234\211\346\225\260\346\215\256\345\272\223", nullptr));
        label->setText(QCoreApplication::translate("DatabaseWindow", "\344\275\277\347\224\250\345\221\275\344\273\244", nullptr));
        label_2->setText(QCoreApplication::translate("DatabaseWindow", "\346\230\276\347\244\272\347\273\223\346\236\234", nullptr));
        pb_showCurDb->setText(QCoreApplication::translate("DatabaseWindow", "\346\230\276\347\244\272\345\275\223\345\211\215\346\225\260\346\215\256\345\272\223", nullptr));
        pb_openDb->setText(QCoreApplication::translate("DatabaseWindow", "\345\210\207\346\215\242\346\225\260\346\215\256\345\272\223", nullptr));
        pb_showTable->setText(QCoreApplication::translate("DatabaseWindow", "\346\230\276\347\244\272\346\225\260\346\215\256\350\241\250", nullptr));
        lb_curDb->setText(QString());
        pb_setTable->setText(QCoreApplication::translate("DatabaseWindow", "\351\200\211\346\213\251\346\225\260\346\215\256\350\241\250", nullptr));
        label_3->setText(QCoreApplication::translate("DatabaseWindow", "\345\275\223\345\211\215\346\225\260\346\215\256\350\241\250", nullptr));
        lb_curTable->setText(QString());
        label_4->setText(QCoreApplication::translate("DatabaseWindow", "\345\272\217\345\217\267\350\214\203\345\233\264", nullptr));
        label_5->setText(QCoreApplication::translate("DatabaseWindow", "-", nullptr));
        pb_inquire->setText(QCoreApplication::translate("DatabaseWindow", "\346\237\245\350\257\242", nullptr));
        pb_display->setText(QCoreApplication::translate("DatabaseWindow", "\346\230\276\347\244\272\345\205\250\350\241\250", nullptr));
        pb_showTableData->setText(QCoreApplication::translate("DatabaseWindow", "\346\230\276\347\244\272\346\225\260\346\215\256\350\241\250\345\206\205\345\256\271", nullptr));
        pb_commit->setText(QCoreApplication::translate("DatabaseWindow", "\346\217\220\344\272\244\344\277\256\346\224\271", nullptr));
        pb_repeal->setText(QCoreApplication::translate("DatabaseWindow", "\346\222\244\351\224\200\344\277\256\346\224\271", nullptr));
        pb_record->setText(QCoreApplication::translate("DatabaseWindow", "\346\267\273\345\212\240\350\256\260\345\275\225", nullptr));
        pb_remove->setText(QCoreApplication::translate("DatabaseWindow", "\345\210\240\351\231\244\351\200\211\344\270\255\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DatabaseWindow: public Ui_DatabaseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEWINDOW_H
