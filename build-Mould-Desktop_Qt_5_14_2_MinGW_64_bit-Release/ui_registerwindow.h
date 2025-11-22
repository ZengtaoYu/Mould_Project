/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QWidget *centralwidget;
    QLabel *NewPasswd;
    QPushButton *RightButton;
    QLineEdit *SetPasswdEdit;
    QLineEdit *SetPasswdEdit_2;
    QLabel *RetryPasswd;
    QLineEdit *SetUserEdit;
    QLabel *NewUser;
    QPushButton *ReturnButton0;
    QLabel *AdiminLabel;
    QLineEdit *AdminPasswd;
    QLabel *BackGround;
    QLabel *LoadingLabel;
    QCheckBox *AdminBox;
    QLabel *NewName;
    QLineEdit *SetNameEdit;
    QLineEdit *SetEmailEdit;
    QLabel *NewEmail;
    QCheckBox *PlusBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName(QString::fromUtf8("RegisterWindow"));
        RegisterWindow->resize(610, 410);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RegisterWindow->sizePolicy().hasHeightForWidth());
        RegisterWindow->setSizePolicy(sizePolicy);
        RegisterWindow->setMinimumSize(QSize(610, 410));
        RegisterWindow->setMaximumSize(QSize(610, 410));
        centralwidget = new QWidget(RegisterWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        NewPasswd = new QLabel(centralwidget);
        NewPasswd->setObjectName(QString::fromUtf8("NewPasswd"));
        NewPasswd->setGeometry(QRect(190, 225, 101, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(16);
        NewPasswd->setFont(font);
        RightButton = new QPushButton(centralwidget);
        RightButton->setObjectName(QString::fromUtf8("RightButton"));
        RightButton->setGeometry(QRect(220, 320, 81, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        RightButton->setFont(font1);
        RightButton->setCursor(QCursor(Qt::PointingHandCursor));
        RightButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:white;\n"
"	background-color: rgb(85, 170, 255);\n"
"	border-radius: 10px;  border: 2px groove lavender;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{  /*\351\274\240\346\240\207\346\202\254\346\265\256\346\227\266*/\n"
"	background: rgb(49,106,234);\n"
"}\n"
"QPushButton:pressed{  /*\351\274\240\346\240\207\346\214\211\344\270\213\346\227\266*/\n"
"	background:rgb(96,96,96);\n"
"	color: rgb(200, 200, 200);\n"
"}\n"
"QPushButton:!enabled {   /*\346\214\211\351\222\256\347\246\201\347\224\250\346\227\266*/\n"
"	background: rgb(100, 100, 100);\n"
"	color: rgb(200, 200, 200);\n"
"}"));
        SetPasswdEdit = new QLineEdit(centralwidget);
        SetPasswdEdit->setObjectName(QString::fromUtf8("SetPasswdEdit"));
        SetPasswdEdit->setGeometry(QRect(290, 225, 161, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        SetPasswdEdit->setFont(font2);
        SetPasswdEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        SetPasswdEdit->setMaxLength(20);
        SetPasswdEdit->setEchoMode(QLineEdit::Password);
        SetPasswdEdit_2 = new QLineEdit(centralwidget);
        SetPasswdEdit_2->setObjectName(QString::fromUtf8("SetPasswdEdit_2"));
        SetPasswdEdit_2->setGeometry(QRect(290, 275, 161, 31));
        SetPasswdEdit_2->setFont(font2);
        SetPasswdEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        SetPasswdEdit_2->setMaxLength(20);
        SetPasswdEdit_2->setEchoMode(QLineEdit::Password);
        RetryPasswd = new QLabel(centralwidget);
        RetryPasswd->setObjectName(QString::fromUtf8("RetryPasswd"));
        RetryPasswd->setGeometry(QRect(150, 275, 141, 31));
        RetryPasswd->setFont(font);
        SetUserEdit = new QLineEdit(centralwidget);
        SetUserEdit->setObjectName(QString::fromUtf8("SetUserEdit"));
        SetUserEdit->setGeometry(QRect(290, 75, 161, 31));
        SetUserEdit->setFont(font2);
        SetUserEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        SetUserEdit->setMaxLength(20);
        NewUser = new QLabel(centralwidget);
        NewUser->setObjectName(QString::fromUtf8("NewUser"));
        NewUser->setGeometry(QRect(170, 75, 121, 31));
        NewUser->setFont(font);
        ReturnButton0 = new QPushButton(centralwidget);
        ReturnButton0->setObjectName(QString::fromUtf8("ReturnButton0"));
        ReturnButton0->setGeometry(QRect(340, 320, 81, 41));
        ReturnButton0->setFont(font1);
        ReturnButton0->setCursor(QCursor(Qt::PointingHandCursor));
        ReturnButton0->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:white;\n"
"	background-color: rgb(85, 170, 255);\n"
"	border-radius: 10px;  border: 2px groove lavender;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{  /*\351\274\240\346\240\207\346\202\254\346\265\256\346\227\266*/\n"
"	background: rgb(49,106,234);\n"
"}\n"
"QPushButton:pressed{  /*\351\274\240\346\240\207\346\214\211\344\270\213\346\227\266*/\n"
"	background:rgb(96,96,96);\n"
"	color: rgb(200, 200, 200);\n"
"}\n"
"QPushButton:!enabled {   /*\346\214\211\351\222\256\347\246\201\347\224\250\346\227\266*/\n"
"	background: rgb(100, 100, 100);\n"
"	color: rgb(200, 200, 200);\n"
"}"));
        AdiminLabel = new QLabel(centralwidget);
        AdiminLabel->setObjectName(QString::fromUtf8("AdiminLabel"));
        AdiminLabel->setGeometry(QRect(170, 25, 121, 31));
        AdiminLabel->setFont(font);
        AdminPasswd = new QLineEdit(centralwidget);
        AdminPasswd->setObjectName(QString::fromUtf8("AdminPasswd"));
        AdminPasswd->setGeometry(QRect(290, 25, 161, 31));
        AdminPasswd->setFont(font2);
        AdminPasswd->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        AdminPasswd->setEchoMode(QLineEdit::Password);
        BackGround = new QLabel(centralwidget);
        BackGround->setObjectName(QString::fromUtf8("BackGround"));
        BackGround->setGeometry(QRect(0, 0, 611, 411));
        BackGround->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-radius: 10px;\n"
"color: rgb(255, 255, 255);"));
        LoadingLabel = new QLabel(centralwidget);
        LoadingLabel->setObjectName(QString::fromUtf8("LoadingLabel"));
        LoadingLabel->setGeometry(QRect(0, 70, 170, 170));
        LoadingLabel->setLayoutDirection(Qt::LeftToRight);
        AdminBox = new QCheckBox(centralwidget);
        AdminBox->setObjectName(QString::fromUtf8("AdminBox"));
        AdminBox->setGeometry(QRect(460, 240, 121, 21));
        AdminBox->setFont(font2);
        AdminBox->setCursor(QCursor(Qt::PointingHandCursor));
        NewName = new QLabel(centralwidget);
        NewName->setObjectName(QString::fromUtf8("NewName"));
        NewName->setGeometry(QRect(190, 125, 101, 31));
        NewName->setFont(font);
        SetNameEdit = new QLineEdit(centralwidget);
        SetNameEdit->setObjectName(QString::fromUtf8("SetNameEdit"));
        SetNameEdit->setGeometry(QRect(290, 125, 161, 31));
        SetNameEdit->setFont(font2);
        SetNameEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        SetNameEdit->setMaxLength(5);
        SetEmailEdit = new QLineEdit(centralwidget);
        SetEmailEdit->setObjectName(QString::fromUtf8("SetEmailEdit"));
        SetEmailEdit->setGeometry(QRect(290, 175, 161, 31));
        SetEmailEdit->setFont(font2);
        SetEmailEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        SetEmailEdit->setMaxLength(30);
        NewEmail = new QLabel(centralwidget);
        NewEmail->setObjectName(QString::fromUtf8("NewEmail"));
        NewEmail->setGeometry(QRect(190, 175, 101, 31));
        NewEmail->setFont(font);
        PlusBox = new QCheckBox(centralwidget);
        PlusBox->setObjectName(QString::fromUtf8("PlusBox"));
        PlusBox->setGeometry(QRect(460, 290, 141, 21));
        PlusBox->setFont(font2);
        PlusBox->setCursor(QCursor(Qt::PointingHandCursor));
        RegisterWindow->setCentralWidget(centralwidget);
        BackGround->raise();
        AdiminLabel->raise();
        AdminPasswd->raise();
        NewPasswd->raise();
        NewUser->raise();
        RetryPasswd->raise();
        ReturnButton0->raise();
        RightButton->raise();
        SetPasswdEdit->raise();
        SetPasswdEdit_2->raise();
        SetUserEdit->raise();
        LoadingLabel->raise();
        AdminBox->raise();
        NewName->raise();
        SetNameEdit->raise();
        SetEmailEdit->raise();
        NewEmail->raise();
        PlusBox->raise();
        menubar = new QMenuBar(RegisterWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 610, 23));
        RegisterWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RegisterWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RegisterWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(AdminPasswd, SetUserEdit);
        QWidget::setTabOrder(SetUserEdit, SetNameEdit);
        QWidget::setTabOrder(SetNameEdit, SetEmailEdit);
        QWidget::setTabOrder(SetEmailEdit, SetPasswdEdit);
        QWidget::setTabOrder(SetPasswdEdit, SetPasswdEdit_2);
        QWidget::setTabOrder(SetPasswdEdit_2, AdminBox);
        QWidget::setTabOrder(AdminBox, PlusBox);
        QWidget::setTabOrder(PlusBox, RightButton);
        QWidget::setTabOrder(RightButton, ReturnButton0);

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "MainWindow", nullptr));
        NewPasswd->setText(QCoreApplication::translate("RegisterWindow", "\347\224\250\346\210\267\345\257\206\347\240\201:", nullptr));
        RightButton->setText(QCoreApplication::translate("RegisterWindow", "\347\241\256\345\256\232", nullptr));
        SetPasswdEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "\351\231\220\345\210\26620\344\270\252\345\255\227\347\254\246", nullptr));
        SetPasswdEdit_2->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "\351\231\220\345\210\26620\344\270\252\345\255\227\347\254\246", nullptr));
        RetryPasswd->setText(QCoreApplication::translate("RegisterWindow", "\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201:", nullptr));
        SetUserEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "\351\231\220\345\210\26620\344\270\252\345\255\227\347\254\246", nullptr));
        NewUser->setText(QCoreApplication::translate("RegisterWindow", "\346\226\260\347\232\204\347\224\250\346\210\267\345\220\215:", nullptr));
        ReturnButton0->setText(QCoreApplication::translate("RegisterWindow", "\350\277\224\345\233\236", nullptr));
        AdiminLabel->setText(QCoreApplication::translate("RegisterWindow", "\347\256\241\347\220\206\345\221\230\345\257\206\351\222\245:", nullptr));
        AdminPasswd->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "\350\276\223\345\205\245\347\256\241\347\220\206\345\221\230\345\257\206\351\222\245", nullptr));
        BackGround->setText(QString());
        LoadingLabel->setText(QString());
        AdminBox->setText(QCoreApplication::translate("RegisterWindow", "\350\256\276\347\275\256\344\270\272\347\256\241\347\220\206\345\221\230", nullptr));
        NewName->setText(QCoreApplication::translate("RegisterWindow", "\347\224\250\346\210\267\345\247\223\345\220\215:", nullptr));
        SetNameEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "\351\231\220\345\210\2665\344\270\252\345\255\227\347\254\246", nullptr));
        SetEmailEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "\351\231\220\345\210\26630\344\270\252\345\255\227\347\254\246", nullptr));
        NewEmail->setText(QCoreApplication::translate("RegisterWindow", "\347\224\250\346\210\267\351\202\256\347\256\261:", nullptr));
        PlusBox->setText(QCoreApplication::translate("RegisterWindow", "\350\256\276\347\275\256\344\270\272\351\253\230\347\272\247\350\264\246\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
