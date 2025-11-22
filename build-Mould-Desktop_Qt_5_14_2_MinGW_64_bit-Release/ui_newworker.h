/********************************************************************************
** Form generated from reading UI file 'newworker.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWWORKER_H
#define UI_NEWWORKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewWorker
{
public:
    QWidget *centralwidget;
    QListView *UserView;
    QPushButton *pushButton_1;
    QLineEdit *NameEdit;
    QLabel *Label2;
    QPushButton *pushButton_2;
    QLabel *ShowLabel;
    QLabel *BackGround;
    QLabel *LogoLabel;
    QComboBox *TypeComb;
    QLabel *Label1;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *NewWorker)
    {
        if (NewWorker->objectName().isEmpty())
            NewWorker->setObjectName(QString::fromUtf8("NewWorker"));
        NewWorker->resize(485, 385);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NewWorker->sizePolicy().hasHeightForWidth());
        NewWorker->setSizePolicy(sizePolicy);
        NewWorker->setMinimumSize(QSize(485, 385));
        NewWorker->setMaximumSize(QSize(485, 385));
        centralwidget = new QWidget(NewWorker);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        UserView = new QListView(centralwidget);
        UserView->setObjectName(QString::fromUtf8("UserView"));
        UserView->setGeometry(QRect(20, 100, 181, 241));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(18);
        UserView->setFont(font);
        UserView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        UserView->setMouseTracking(false);
        UserView->setStyleSheet(QString::fromUtf8("QListView{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        UserView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(230, 160, 151, 41));
        pushButton_1->setFont(font);
        pushButton_1->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:white;\n"
"	background-color: rgb(85, 170, 255);\n"
"	border-radius: 15px;  border: 2px groove lavender;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{  /*\351\274\240\346\240\207\346\202\254\346\265\256\346\227\266*/\n"
"	background: rgb(49,106,234);\n"
"}\n"
"QPushButton:pressed{  /*\351\274\240\346\240\207\346\214\211\344\270\213\346\227\266*/\n"
"	background:rgb(96,96,96);\n"
"	color: rgb(200, 200, 200);\n"
"}"));
        NameEdit = new QLineEdit(centralwidget);
        NameEdit->setObjectName(QString::fromUtf8("NameEdit"));
        NameEdit->setGeometry(QRect(340, 230, 121, 41));
        NameEdit->setFont(font);
        NameEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        NameEdit->setAlignment(Qt::AlignCenter);
        NameEdit->setReadOnly(false);
        Label2 = new QLabel(centralwidget);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(230, 235, 111, 31));
        Label2->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 290, 121, 41));
        pushButton_2->setFont(font);
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:white;\n"
"	background-color: rgb(85, 170, 255);\n"
"	border-radius: 15px;  border: 2px groove lavender;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{  /*\351\274\240\346\240\207\346\202\254\346\265\256\346\227\266*/\n"
"	background: rgb(49,106,234);\n"
"}\n"
"QPushButton:pressed{  /*\351\274\240\346\240\207\346\214\211\344\270\213\346\227\266*/\n"
"	background:rgb(96,96,96);\n"
"	color: rgb(200, 200, 200);\n"
"}"));
        ShowLabel = new QLabel(centralwidget);
        ShowLabel->setObjectName(QString::fromUtf8("ShowLabel"));
        ShowLabel->setGeometry(QRect(30, 60, 101, 31));
        ShowLabel->setFont(font);
        BackGround = new QLabel(centralwidget);
        BackGround->setObjectName(QString::fromUtf8("BackGround"));
        BackGround->setGeometry(QRect(5, 5, 476, 356));
        BackGround->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 15px;\n"
"border-style: outset;"));
        LogoLabel = new QLabel(centralwidget);
        LogoLabel->setObjectName(QString::fromUtf8("LogoLabel"));
        LogoLabel->setGeometry(QRect(270, 10, 200, 53));
        LogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/logo200x53.jpg")));
        TypeComb = new QComboBox(centralwidget);
        TypeComb->addItem(QString());
        TypeComb->addItem(QString());
        TypeComb->addItem(QString());
        TypeComb->setObjectName(QString::fromUtf8("TypeComb"));
        TypeComb->setGeometry(QRect(290, 100, 101, 41));
        TypeComb->setFont(font);
        TypeComb->setCursor(QCursor(Qt::ArrowCursor));
        TypeComb->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        Label1 = new QLabel(centralwidget);
        Label1->setObjectName(QString::fromUtf8("Label1"));
        Label1->setGeometry(QRect(230, 105, 61, 31));
        Label1->setFont(font);
        NewWorker->setCentralWidget(centralwidget);
        BackGround->raise();
        UserView->raise();
        pushButton_1->raise();
        NameEdit->raise();
        Label2->raise();
        pushButton_2->raise();
        ShowLabel->raise();
        LogoLabel->raise();
        TypeComb->raise();
        Label1->raise();
        menubar = new QMenuBar(NewWorker);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 485, 23));
        NewWorker->setMenuBar(menubar);
        statusbar = new QStatusBar(NewWorker);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        NewWorker->setStatusBar(statusbar);
        QWidget::setTabOrder(UserView, TypeComb);
        QWidget::setTabOrder(TypeComb, pushButton_1);
        QWidget::setTabOrder(pushButton_1, NameEdit);
        QWidget::setTabOrder(NameEdit, pushButton_2);

        retranslateUi(NewWorker);

        QMetaObject::connectSlotsByName(NewWorker);
    } // setupUi

    void retranslateUi(QMainWindow *NewWorker)
    {
        NewWorker->setWindowTitle(QCoreApplication::translate("NewWorker", "MainWindow", nullptr));
        pushButton_1->setText(QCoreApplication::translate("NewWorker", "\345\210\240\351\231\244\350\257\245\345\221\230\345\267\245", nullptr));
        NameEdit->setPlaceholderText(QCoreApplication::translate("NewWorker", "\350\276\223\345\205\245\345\247\223\345\220\215", nullptr));
        Label2->setText(QCoreApplication::translate("NewWorker", "\350\276\223\345\205\245\345\247\223\345\220\215:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("NewWorker", "\346\267\273\345\212\240\345\221\230\345\267\245", nullptr));
        ShowLabel->setText(QCoreApplication::translate("NewWorker", "\350\260\203\346\234\272\345\221\230\342\254\213", nullptr));
        BackGround->setText(QString());
        LogoLabel->setText(QString());
        TypeComb->setItemText(0, QCoreApplication::translate("NewWorker", "\347\256\241\347\220\206\345\221\230", nullptr));
        TypeComb->setItemText(1, QCoreApplication::translate("NewWorker", "\350\260\203\346\234\272\345\221\230", nullptr));
        TypeComb->setItemText(2, QCoreApplication::translate("NewWorker", "\347\273\264\344\277\256\345\221\230", nullptr));

        Label1->setText(QCoreApplication::translate("NewWorker", "\347\261\273\345\210\253:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewWorker: public Ui_NewWorker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWWORKER_H
