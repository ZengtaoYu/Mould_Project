/********************************************************************************
** Form generated from reading UI file 'handledata.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDLEDATA_H
#define UI_HANDLEDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HandleData
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *PushButton;
    QPushButton *ReturnButton;
    QPushButton *AddButton;
    QPushButton *DeleteButton;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *LineEdit;
    QHBoxLayout *horizontalLayout_7;
    QComboBox *comboBox;
    QPushButton *FindButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HandleData)
    {
        if (HandleData->objectName().isEmpty())
            HandleData->setObjectName(QString::fromUtf8("HandleData"));
        HandleData->resize(800, 600);
        centralwidget = new QWidget(HandleData);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QFont font;
        font.setPointSize(10);
        tableView->setFont(font);
        tableView->setStyleSheet(QString::fromUtf8(""));
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        PushButton = new QPushButton(centralwidget);
        PushButton->setObjectName(QString::fromUtf8("PushButton"));
        QFont font1;
        font1.setPointSize(14);
        PushButton->setFont(font1);
        PushButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(PushButton);

        ReturnButton = new QPushButton(centralwidget);
        ReturnButton->setObjectName(QString::fromUtf8("ReturnButton"));
        ReturnButton->setFont(font1);
        ReturnButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(ReturnButton);

        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setFont(font1);
        AddButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(AddButton);

        DeleteButton = new QPushButton(centralwidget);
        DeleteButton->setObjectName(QString::fromUtf8("DeleteButton"));
        DeleteButton->setFont(font1);
        DeleteButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(DeleteButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        LineEdit = new QLineEdit(centralwidget);
        LineEdit->setObjectName(QString::fromUtf8("LineEdit"));
        QFont font2;
        font2.setPointSize(12);
        LineEdit->setFont(font2);

        horizontalLayout_6->addWidget(LineEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_7->addWidget(comboBox);

        FindButton = new QPushButton(centralwidget);
        FindButton->setObjectName(QString::fromUtf8("FindButton"));
        FindButton->setFont(font1);
        FindButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_7->addWidget(FindButton);


        verticalLayout->addLayout(horizontalLayout_7);

        HandleData->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HandleData);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        HandleData->setMenuBar(menubar);
        statusbar = new QStatusBar(HandleData);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HandleData->setStatusBar(statusbar);

        retranslateUi(HandleData);

        QMetaObject::connectSlotsByName(HandleData);
    } // setupUi

    void retranslateUi(QMainWindow *HandleData)
    {
        HandleData->setWindowTitle(QCoreApplication::translate("HandleData", "MainWindow", nullptr));
        PushButton->setText(QCoreApplication::translate("HandleData", "\346\217\220\344\272\244\344\277\256\346\224\271", nullptr));
        ReturnButton->setText(QCoreApplication::translate("HandleData", "\346\222\244\351\224\200\344\277\256\346\224\271", nullptr));
        AddButton->setText(QCoreApplication::translate("HandleData", "\346\267\273\345\212\240\350\256\260\345\275\225", nullptr));
        DeleteButton->setText(QCoreApplication::translate("HandleData", "\345\210\240\351\231\244\351\200\211\344\270\255\350\241\214", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("HandleData", "\345\205\250\351\203\250", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("HandleData", "01\346\234\210", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("HandleData", "02\346\234\210", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("HandleData", "03\346\234\210", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("HandleData", "04\346\234\210", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("HandleData", "05\346\234\210", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("HandleData", "06\346\234\210", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("HandleData", "07\346\234\210", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("HandleData", "08\346\234\210", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("HandleData", "09\346\234\210", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("HandleData", "10\346\234\210", nullptr));
        comboBox->setItemText(11, QCoreApplication::translate("HandleData", "11\346\234\210", nullptr));
        comboBox->setItemText(12, QCoreApplication::translate("HandleData", "12\346\234\210", nullptr));

        FindButton->setText(QCoreApplication::translate("HandleData", "\346\237\245\346\211\276\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HandleData: public Ui_HandleData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDLEDATA_H
