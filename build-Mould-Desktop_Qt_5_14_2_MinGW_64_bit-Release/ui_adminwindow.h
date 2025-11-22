/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QWidget *centralwidget;
    QPushButton *PushButton;
    QTextEdit *MessageEdit;
    QLabel *Label1;
    QLabel *Label2;
    QLabel *LogoLabel;
    QLabel *BackGround;
    QLineEdit *TitleEdit;
    QPushButton *EmailButton;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName(QString::fromUtf8("AdminWindow"));
        AdminWindow->setEnabled(true);
        AdminWindow->resize(550, 480);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AdminWindow->sizePolicy().hasHeightForWidth());
        AdminWindow->setSizePolicy(sizePolicy);
        AdminWindow->setMinimumSize(QSize(550, 480));
        AdminWindow->setMaximumSize(QSize(550, 480));
        centralwidget = new QWidget(AdminWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        PushButton = new QPushButton(centralwidget);
        PushButton->setObjectName(QString::fromUtf8("PushButton"));
        PushButton->setGeometry(QRect(400, 400, 121, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(18);
        font.setBold(false);
        font.setWeight(50);
        PushButton->setFont(font);
        PushButton->setCursor(QCursor(Qt::PointingHandCursor));
        PushButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        MessageEdit = new QTextEdit(centralwidget);
        MessageEdit->setObjectName(QString::fromUtf8("MessageEdit"));
        MessageEdit->setGeometry(QRect(30, 170, 351, 271));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        MessageEdit->setFont(font1);
        MessageEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        MessageEdit->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        Label1 = new QLabel(centralwidget);
        Label1->setObjectName(QString::fromUtf8("Label1"));
        Label1->setGeometry(QRect(30, 60, 121, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font2.setPointSize(20);
        Label1->setFont(font2);
        Label2 = new QLabel(centralwidget);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(30, 140, 121, 31));
        Label2->setFont(font2);
        LogoLabel = new QLabel(centralwidget);
        LogoLabel->setObjectName(QString::fromUtf8("LogoLabel"));
        LogoLabel->setGeometry(QRect(340, 10, 200, 53));
        LogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/logo200x53.jpg")));
        BackGround = new QLabel(centralwidget);
        BackGround->setObjectName(QString::fromUtf8("BackGround"));
        BackGround->setGeometry(QRect(5, 5, 541, 461));
        BackGround->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-radius: 15px;\n"
"color: rgb(0,0,0);"));
        TitleEdit = new QLineEdit(centralwidget);
        TitleEdit->setObjectName(QString::fromUtf8("TitleEdit"));
        TitleEdit->setGeometry(QRect(30, 90, 271, 41));
        TitleEdit->setFont(font1);
        TitleEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        TitleEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        EmailButton = new QPushButton(centralwidget);
        EmailButton->setObjectName(QString::fromUtf8("EmailButton"));
        EmailButton->setGeometry(QRect(10, 10, 111, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setWeight(75);
        EmailButton->setFont(font3);
        EmailButton->setCursor(QCursor(Qt::PointingHandCursor));
        EmailButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"color: rgb(200, 200, 200);\n"
"}"));
        AdminWindow->setCentralWidget(centralwidget);
        BackGround->raise();
        PushButton->raise();
        MessageEdit->raise();
        Label1->raise();
        Label2->raise();
        LogoLabel->raise();
        TitleEdit->raise();
        EmailButton->raise();
        statusbar = new QStatusBar(AdminWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AdminWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(AdminWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 550, 23));
        AdminWindow->setMenuBar(menubar);
        QWidget::setTabOrder(TitleEdit, MessageEdit);
        QWidget::setTabOrder(MessageEdit, PushButton);
        QWidget::setTabOrder(PushButton, EmailButton);

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWindow)
    {
        AdminWindow->setWindowTitle(QCoreApplication::translate("AdminWindow", "MainWindow", nullptr));
        PushButton->setText(QCoreApplication::translate("AdminWindow", "\345\217\221\351\200\201", nullptr));
        MessageEdit->setPlaceholderText(QCoreApplication::translate("AdminWindow", "\350\257\267\345\241\253\345\206\231\346\255\243\346\226\207\344\277\241\346\201\257", nullptr));
        Label1->setText(QCoreApplication::translate("AdminWindow", "\350\276\223\345\205\245\344\270\273\351\242\230:", nullptr));
        Label2->setText(QCoreApplication::translate("AdminWindow", "\345\241\253\345\206\231\344\277\241\346\201\257:", nullptr));
        LogoLabel->setText(QString());
        BackGround->setText(QString());
        TitleEdit->setPlaceholderText(QCoreApplication::translate("AdminWindow", "\350\257\267\350\276\223\345\205\245\344\270\273\351\242\230", nullptr));
        EmailButton->setText(QCoreApplication::translate("AdminWindow", "\345\217\221\351\200\201\351\202\256\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
