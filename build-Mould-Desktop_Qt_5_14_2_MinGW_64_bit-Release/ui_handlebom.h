/********************************************************************************
** Form generated from reading UI file 'handlebom.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDLEBOM_H
#define UI_HANDLEBOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HandleBom
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_1;
    QPushButton *PushButton;
    QPushButton *ReturnButton;
    QPushButton *AddButton;
    QPushButton *DeleteButton;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *LineEdit;
    QPushButton *FindButton;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QTableView *tableView_1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *PushButton_1;
    QPushButton *ReturnButton_1;
    QPushButton *AddButton_1;
    QPushButton *DeleteButton_1;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *LineEdit_1;
    QPushButton *FindButton_1;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *PushButton_2;
    QPushButton *ReturnButton_2;
    QPushButton *AddButton_2;
    QPushButton *DeleteButton_2;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *LineEdit_2;
    QPushButton *FindButton_2;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_4;
    QTableView *tableView_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *PushButton_3;
    QPushButton *ReturnButton_3;
    QPushButton *AddButton_3;
    QPushButton *DeleteButton_3;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *LineEdit_3;
    QPushButton *FindButton_3;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_5;
    QTableView *tableView_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *PushButton_4;
    QPushButton *ReturnButton_4;
    QPushButton *AddButton_4;
    QPushButton *DeleteButton_4;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *LineEdit_4;
    QPushButton *FindButton_4;
    QWidget *tab_6;
    QGridLayout *gridLayout;
    QTableView *tableView_5;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *PushButton_5;
    QPushButton *ReturnButton_5;
    QPushButton *AddButton_5;
    QPushButton *DeleteButton_5;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *LineEdit_5;
    QPushButton *FindButton_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HandleBom)
    {
        if (HandleBom->objectName().isEmpty())
            HandleBom->setObjectName(QString::fromUtf8("HandleBom"));
        HandleBom->resize(800, 600);
        QFont font;
        font.setPointSize(12);
        HandleBom->setFont(font);
        centralwidget = new QWidget(HandleBom);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setCursor(QCursor(Qt::ArrowCursor));
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        verticalLayout = new QVBoxLayout(tab_1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(tab_1);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QFont font1;
        font1.setPointSize(10);
        tableView->setFont(font1);
        tableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableView);

        horizontalLayout_1 = new QHBoxLayout();
        horizontalLayout_1->setObjectName(QString::fromUtf8("horizontalLayout_1"));
        PushButton = new QPushButton(tab_1);
        PushButton->setObjectName(QString::fromUtf8("PushButton"));
        QFont font2;
        font2.setPointSize(14);
        PushButton->setFont(font2);
        PushButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_1->addWidget(PushButton);

        ReturnButton = new QPushButton(tab_1);
        ReturnButton->setObjectName(QString::fromUtf8("ReturnButton"));
        ReturnButton->setFont(font2);
        ReturnButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_1->addWidget(ReturnButton);

        AddButton = new QPushButton(tab_1);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setFont(font2);
        AddButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_1->addWidget(AddButton);

        DeleteButton = new QPushButton(tab_1);
        DeleteButton->setObjectName(QString::fromUtf8("DeleteButton"));
        DeleteButton->setFont(font2);
        DeleteButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_1->addWidget(DeleteButton);


        verticalLayout->addLayout(horizontalLayout_1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        LineEdit = new QLineEdit(tab_1);
        LineEdit->setObjectName(QString::fromUtf8("LineEdit"));

        horizontalLayout_6->addWidget(LineEdit);

        FindButton = new QPushButton(tab_1);
        FindButton->setObjectName(QString::fromUtf8("FindButton"));
        FindButton->setFont(font2);
        FindButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_6->addWidget(FindButton);


        verticalLayout->addLayout(horizontalLayout_6);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tableView_1 = new QTableView(tab_2);
        tableView_1->setObjectName(QString::fromUtf8("tableView_1"));
        tableView_1->setFont(font1);
        tableView_1->verticalHeader()->setVisible(false);

        verticalLayout_3->addWidget(tableView_1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        PushButton_1 = new QPushButton(tab_2);
        PushButton_1->setObjectName(QString::fromUtf8("PushButton_1"));
        PushButton_1->setFont(font2);
        PushButton_1->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(PushButton_1);

        ReturnButton_1 = new QPushButton(tab_2);
        ReturnButton_1->setObjectName(QString::fromUtf8("ReturnButton_1"));
        ReturnButton_1->setFont(font2);
        ReturnButton_1->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(ReturnButton_1);

        AddButton_1 = new QPushButton(tab_2);
        AddButton_1->setObjectName(QString::fromUtf8("AddButton_1"));
        AddButton_1->setFont(font2);
        AddButton_1->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(AddButton_1);

        DeleteButton_1 = new QPushButton(tab_2);
        DeleteButton_1->setObjectName(QString::fromUtf8("DeleteButton_1"));
        DeleteButton_1->setFont(font2);
        DeleteButton_1->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(DeleteButton_1);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        LineEdit_1 = new QLineEdit(tab_2);
        LineEdit_1->setObjectName(QString::fromUtf8("LineEdit_1"));

        horizontalLayout_7->addWidget(LineEdit_1);

        FindButton_1 = new QPushButton(tab_2);
        FindButton_1->setObjectName(QString::fromUtf8("FindButton_1"));
        FindButton_1->setFont(font2);
        FindButton_1->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_7->addWidget(FindButton_1);


        verticalLayout_3->addLayout(horizontalLayout_7);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_2 = new QVBoxLayout(tab_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableView_2 = new QTableView(tab_3);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setFont(font1);
        tableView_2->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(tableView_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        PushButton_2 = new QPushButton(tab_3);
        PushButton_2->setObjectName(QString::fromUtf8("PushButton_2"));
        PushButton_2->setFont(font2);
        PushButton_2->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_3->addWidget(PushButton_2);

        ReturnButton_2 = new QPushButton(tab_3);
        ReturnButton_2->setObjectName(QString::fromUtf8("ReturnButton_2"));
        ReturnButton_2->setFont(font2);
        ReturnButton_2->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_3->addWidget(ReturnButton_2);

        AddButton_2 = new QPushButton(tab_3);
        AddButton_2->setObjectName(QString::fromUtf8("AddButton_2"));
        AddButton_2->setFont(font2);
        AddButton_2->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_3->addWidget(AddButton_2);

        DeleteButton_2 = new QPushButton(tab_3);
        DeleteButton_2->setObjectName(QString::fromUtf8("DeleteButton_2"));
        DeleteButton_2->setFont(font2);
        DeleteButton_2->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_3->addWidget(DeleteButton_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        LineEdit_2 = new QLineEdit(tab_3);
        LineEdit_2->setObjectName(QString::fromUtf8("LineEdit_2"));

        horizontalLayout_8->addWidget(LineEdit_2);

        FindButton_2 = new QPushButton(tab_3);
        FindButton_2->setObjectName(QString::fromUtf8("FindButton_2"));
        FindButton_2->setFont(font2);
        FindButton_2->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_8->addWidget(FindButton_2);


        verticalLayout_2->addLayout(horizontalLayout_8);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_4 = new QVBoxLayout(tab_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        tableView_3 = new QTableView(tab_4);
        tableView_3->setObjectName(QString::fromUtf8("tableView_3"));
        tableView_3->setFont(font1);
        tableView_3->verticalHeader()->setVisible(false);

        verticalLayout_4->addWidget(tableView_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        PushButton_3 = new QPushButton(tab_4);
        PushButton_3->setObjectName(QString::fromUtf8("PushButton_3"));
        PushButton_3->setFont(font2);
        PushButton_3->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_4->addWidget(PushButton_3);

        ReturnButton_3 = new QPushButton(tab_4);
        ReturnButton_3->setObjectName(QString::fromUtf8("ReturnButton_3"));
        ReturnButton_3->setFont(font2);
        ReturnButton_3->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_4->addWidget(ReturnButton_3);

        AddButton_3 = new QPushButton(tab_4);
        AddButton_3->setObjectName(QString::fromUtf8("AddButton_3"));
        AddButton_3->setFont(font2);
        AddButton_3->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_4->addWidget(AddButton_3);

        DeleteButton_3 = new QPushButton(tab_4);
        DeleteButton_3->setObjectName(QString::fromUtf8("DeleteButton_3"));
        DeleteButton_3->setFont(font2);
        DeleteButton_3->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_4->addWidget(DeleteButton_3);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        LineEdit_3 = new QLineEdit(tab_4);
        LineEdit_3->setObjectName(QString::fromUtf8("LineEdit_3"));

        horizontalLayout_9->addWidget(LineEdit_3);

        FindButton_3 = new QPushButton(tab_4);
        FindButton_3->setObjectName(QString::fromUtf8("FindButton_3"));
        FindButton_3->setFont(font2);
        FindButton_3->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_9->addWidget(FindButton_3);


        verticalLayout_4->addLayout(horizontalLayout_9);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        verticalLayout_5 = new QVBoxLayout(tab_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        tableView_4 = new QTableView(tab_5);
        tableView_4->setObjectName(QString::fromUtf8("tableView_4"));
        tableView_4->setFont(font1);
        tableView_4->verticalHeader()->setVisible(false);

        verticalLayout_5->addWidget(tableView_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        PushButton_4 = new QPushButton(tab_5);
        PushButton_4->setObjectName(QString::fromUtf8("PushButton_4"));
        PushButton_4->setFont(font2);
        PushButton_4->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_5->addWidget(PushButton_4);

        ReturnButton_4 = new QPushButton(tab_5);
        ReturnButton_4->setObjectName(QString::fromUtf8("ReturnButton_4"));
        ReturnButton_4->setFont(font2);
        ReturnButton_4->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_5->addWidget(ReturnButton_4);

        AddButton_4 = new QPushButton(tab_5);
        AddButton_4->setObjectName(QString::fromUtf8("AddButton_4"));
        AddButton_4->setFont(font2);
        AddButton_4->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_5->addWidget(AddButton_4);

        DeleteButton_4 = new QPushButton(tab_5);
        DeleteButton_4->setObjectName(QString::fromUtf8("DeleteButton_4"));
        DeleteButton_4->setFont(font2);
        DeleteButton_4->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_5->addWidget(DeleteButton_4);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        LineEdit_4 = new QLineEdit(tab_5);
        LineEdit_4->setObjectName(QString::fromUtf8("LineEdit_4"));

        horizontalLayout_10->addWidget(LineEdit_4);

        FindButton_4 = new QPushButton(tab_5);
        FindButton_4->setObjectName(QString::fromUtf8("FindButton_4"));
        FindButton_4->setFont(font2);
        FindButton_4->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_10->addWidget(FindButton_4);


        verticalLayout_5->addLayout(horizontalLayout_10);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        gridLayout = new QGridLayout(tab_6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView_5 = new QTableView(tab_6);
        tableView_5->setObjectName(QString::fromUtf8("tableView_5"));
        tableView_5->setFont(font1);
        tableView_5->verticalHeader()->setVisible(false);

        gridLayout->addWidget(tableView_5, 0, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        PushButton_5 = new QPushButton(tab_6);
        PushButton_5->setObjectName(QString::fromUtf8("PushButton_5"));
        PushButton_5->setFont(font2);
        PushButton_5->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_12->addWidget(PushButton_5);

        ReturnButton_5 = new QPushButton(tab_6);
        ReturnButton_5->setObjectName(QString::fromUtf8("ReturnButton_5"));
        ReturnButton_5->setFont(font2);
        ReturnButton_5->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_12->addWidget(ReturnButton_5);

        AddButton_5 = new QPushButton(tab_6);
        AddButton_5->setObjectName(QString::fromUtf8("AddButton_5"));
        AddButton_5->setFont(font2);
        AddButton_5->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_12->addWidget(AddButton_5);

        DeleteButton_5 = new QPushButton(tab_6);
        DeleteButton_5->setObjectName(QString::fromUtf8("DeleteButton_5"));
        DeleteButton_5->setFont(font2);
        DeleteButton_5->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_12->addWidget(DeleteButton_5);


        gridLayout->addLayout(horizontalLayout_12, 1, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        LineEdit_5 = new QLineEdit(tab_6);
        LineEdit_5->setObjectName(QString::fromUtf8("LineEdit_5"));

        horizontalLayout_11->addWidget(LineEdit_5);

        FindButton_5 = new QPushButton(tab_6);
        FindButton_5->setObjectName(QString::fromUtf8("FindButton_5"));
        FindButton_5->setFont(font2);
        FindButton_5->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_11->addWidget(FindButton_5);


        gridLayout->addLayout(horizontalLayout_11, 2, 0, 1, 1);

        tabWidget->addTab(tab_6, QString());

        horizontalLayout->addWidget(tabWidget);

        HandleBom->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HandleBom);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        HandleBom->setMenuBar(menubar);
        statusbar = new QStatusBar(HandleBom);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HandleBom->setStatusBar(statusbar);
        QWidget::setTabOrder(tabWidget, tableView);
        QWidget::setTabOrder(tableView, PushButton);
        QWidget::setTabOrder(PushButton, ReturnButton);
        QWidget::setTabOrder(ReturnButton, AddButton);
        QWidget::setTabOrder(AddButton, DeleteButton);
        QWidget::setTabOrder(DeleteButton, LineEdit);
        QWidget::setTabOrder(LineEdit, FindButton);
        QWidget::setTabOrder(FindButton, tableView_1);
        QWidget::setTabOrder(tableView_1, PushButton_1);
        QWidget::setTabOrder(PushButton_1, ReturnButton_1);
        QWidget::setTabOrder(ReturnButton_1, AddButton_1);
        QWidget::setTabOrder(AddButton_1, DeleteButton_1);
        QWidget::setTabOrder(DeleteButton_1, LineEdit_1);
        QWidget::setTabOrder(LineEdit_1, FindButton_1);
        QWidget::setTabOrder(FindButton_1, tableView_2);
        QWidget::setTabOrder(tableView_2, PushButton_2);
        QWidget::setTabOrder(PushButton_2, ReturnButton_2);
        QWidget::setTabOrder(ReturnButton_2, AddButton_2);
        QWidget::setTabOrder(AddButton_2, DeleteButton_2);
        QWidget::setTabOrder(DeleteButton_2, LineEdit_2);
        QWidget::setTabOrder(LineEdit_2, FindButton_2);
        QWidget::setTabOrder(FindButton_2, tableView_3);
        QWidget::setTabOrder(tableView_3, PushButton_3);
        QWidget::setTabOrder(PushButton_3, ReturnButton_3);
        QWidget::setTabOrder(ReturnButton_3, AddButton_3);
        QWidget::setTabOrder(AddButton_3, DeleteButton_3);
        QWidget::setTabOrder(DeleteButton_3, LineEdit_3);
        QWidget::setTabOrder(LineEdit_3, FindButton_3);
        QWidget::setTabOrder(FindButton_3, tableView_4);
        QWidget::setTabOrder(tableView_4, PushButton_4);
        QWidget::setTabOrder(PushButton_4, ReturnButton_4);
        QWidget::setTabOrder(ReturnButton_4, AddButton_4);
        QWidget::setTabOrder(AddButton_4, DeleteButton_4);
        QWidget::setTabOrder(DeleteButton_4, LineEdit_4);
        QWidget::setTabOrder(LineEdit_4, FindButton_4);

        retranslateUi(HandleBom);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(HandleBom);
    } // setupUi

    void retranslateUi(QMainWindow *HandleBom)
    {
        HandleBom->setWindowTitle(QCoreApplication::translate("HandleBom", "MainWindow", nullptr));
        PushButton->setText(QCoreApplication::translate("HandleBom", "\346\217\220\344\272\244\344\277\256\346\224\271", nullptr));
        ReturnButton->setText(QCoreApplication::translate("HandleBom", "\346\222\244\351\224\200\344\277\256\346\224\271", nullptr));
        AddButton->setText(QCoreApplication::translate("HandleBom", "\346\267\273\345\212\240\350\256\260\345\275\225", nullptr));
        DeleteButton->setText(QCoreApplication::translate("HandleBom", "\345\210\240\351\231\244\351\200\211\344\270\255\350\241\214", nullptr));
        FindButton->setText(QCoreApplication::translate("HandleBom", "\346\237\245\346\211\276\345\216\202\345\206\205\346\250\241\345\217\267", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QCoreApplication::translate("HandleBom", "\347\216\260\347\212\266BOM", nullptr));
        PushButton_1->setText(QCoreApplication::translate("HandleBom", "\346\217\220\344\272\244\344\277\256\346\224\271", nullptr));
        ReturnButton_1->setText(QCoreApplication::translate("HandleBom", "\346\222\244\351\224\200\344\277\256\346\224\271", nullptr));
        AddButton_1->setText(QCoreApplication::translate("HandleBom", "\346\267\273\345\212\240\350\256\260\345\275\225", nullptr));
        DeleteButton_1->setText(QCoreApplication::translate("HandleBom", "\345\210\240\351\231\244\351\200\211\344\270\255\350\241\214", nullptr));
        FindButton_1->setText(QCoreApplication::translate("HandleBom", "\346\237\245\346\211\276\345\216\202\345\206\205\346\250\241\345\217\267", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("HandleBom", "\347\220\206\350\256\272BOM", nullptr));
        PushButton_2->setText(QCoreApplication::translate("HandleBom", "\346\217\220\344\272\244\344\277\256\346\224\271", nullptr));
        ReturnButton_2->setText(QCoreApplication::translate("HandleBom", "\346\222\244\351\224\200\344\277\256\346\224\271", nullptr));
        AddButton_2->setText(QCoreApplication::translate("HandleBom", "\346\267\273\345\212\240\350\256\260\345\275\225", nullptr));
        DeleteButton_2->setText(QCoreApplication::translate("HandleBom", "\345\210\240\351\231\244\351\200\211\344\270\255\350\241\214", nullptr));
        FindButton_2->setText(QCoreApplication::translate("HandleBom", "\346\237\245\346\211\276\345\255\230\350\264\247\345\220\215\347\247\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("HandleBom", "\345\272\237\346\226\231\344\273\267\346\240\274", nullptr));
        PushButton_3->setText(QCoreApplication::translate("HandleBom", "\346\217\220\344\272\244\344\277\256\346\224\271", nullptr));
        ReturnButton_3->setText(QCoreApplication::translate("HandleBom", "\346\222\244\351\224\200\344\277\256\346\224\271", nullptr));
        AddButton_3->setText(QCoreApplication::translate("HandleBom", "\346\267\273\345\212\240\350\256\260\345\275\225", nullptr));
        DeleteButton_3->setText(QCoreApplication::translate("HandleBom", "\345\210\240\351\231\244\351\200\211\344\270\255\350\241\214", nullptr));
        FindButton_3->setText(QCoreApplication::translate("HandleBom", "\346\237\245\346\211\276\345\216\202\345\206\205\346\250\241\345\217\267", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("HandleBom", "\347\272\270\347\256\261\343\200\201\345\220\270\345\241\221\347\233\222\345\215\225\344\273\267", nullptr));
        PushButton_4->setText(QCoreApplication::translate("HandleBom", "\346\217\220\344\272\244\344\277\256\346\224\271", nullptr));
        ReturnButton_4->setText(QCoreApplication::translate("HandleBom", "\346\222\244\351\224\200\344\277\256\346\224\271", nullptr));
        AddButton_4->setText(QCoreApplication::translate("HandleBom", "\346\267\273\345\212\240\350\256\260\345\275\225", nullptr));
        DeleteButton_4->setText(QCoreApplication::translate("HandleBom", "\345\210\240\351\231\244\351\200\211\344\270\255\350\241\214", nullptr));
        FindButton_4->setText(QCoreApplication::translate("HandleBom", "\346\237\245\346\211\276\344\272\247\345\223\201\346\226\231\345\217\267", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("HandleBom", "\345\267\245\346\227\266", nullptr));
        PushButton_5->setText(QCoreApplication::translate("HandleBom", "\346\217\220\344\272\244\344\277\256\346\224\271", nullptr));
        ReturnButton_5->setText(QCoreApplication::translate("HandleBom", "\346\222\244\351\224\200\344\277\256\346\224\271", nullptr));
        AddButton_5->setText(QCoreApplication::translate("HandleBom", "\346\267\273\345\212\240\350\256\260\345\275\225", nullptr));
        DeleteButton_5->setText(QCoreApplication::translate("HandleBom", "\345\210\240\351\231\244\351\200\211\344\270\255\350\241\214", nullptr));
        FindButton_5->setText(QCoreApplication::translate("HandleBom", "\346\237\245\346\211\276\344\272\247\345\223\201\346\226\231\345\217\267", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("HandleBom", "\346\234\272\345\217\260\346\210\220\346\234\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HandleBom: public Ui_HandleBom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDLEBOM_H
