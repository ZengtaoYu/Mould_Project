/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *TitleLabel;
    QLabel *UserLabel;
    QLabel *PasswdLabel;
    QLineEdit *UserEdit;
    QLineEdit *PasswdEdit;
    QPushButton *RegisterButton;
    QPushButton *LoginButton;
    QLabel *BackGround;
    QLabel *LoginLabel;
    QLabel *LogoLabel;
    QLabel *IPLabel2;
    QLabel *IPLabel1;
    QLabel *ShowLabel;
    QCheckBox *checkBox;
    QLabel *label;
    QPushButton *DataBaseButton;
    QPushButton *pushButton;
    QComboBox *PartCombo;
    QLabel *PartLabel;
    QLabel *TimeLabel;
    QPushButton *LinkButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 800);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1000, 800));
        MainWindow->setMaximumSize(QSize(1000, 800));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        TitleLabel = new QLabel(centralwidget);
        TitleLabel->setObjectName(QString::fromUtf8("TitleLabel"));
        TitleLabel->setGeometry(QRect(270, 220, 461, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(28);
        font1.setBold(true);
        font1.setWeight(75);
        TitleLabel->setFont(font1);
        TitleLabel->setStyleSheet(QString::fromUtf8("color: rgb(30, 144, 255);"));
        TitleLabel->setAlignment(Qt::AlignCenter);
        UserLabel = new QLabel(centralwidget);
        UserLabel->setObjectName(QString::fromUtf8("UserLabel"));
        UserLabel->setGeometry(QRect(400, 315, 60, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font2.setPointSize(18);
        UserLabel->setFont(font2);
        UserLabel->setStyleSheet(QString::fromUtf8(""));
        UserLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        PasswdLabel = new QLabel(centralwidget);
        PasswdLabel->setObjectName(QString::fromUtf8("PasswdLabel"));
        PasswdLabel->setGeometry(QRect(400, 368, 60, 25));
        PasswdLabel->setFont(font2);
        PasswdLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        UserEdit = new QLineEdit(centralwidget);
        UserEdit->setObjectName(QString::fromUtf8("UserEdit"));
        UserEdit->setGeometry(QRect(460, 312, 120, 35));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(14);
        UserEdit->setFont(font3);
        UserEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        PasswdEdit = new QLineEdit(centralwidget);
        PasswdEdit->setObjectName(QString::fromUtf8("PasswdEdit"));
        PasswdEdit->setGeometry(QRect(460, 365, 120, 35));
        PasswdEdit->setFont(font3);
        PasswdEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        PasswdEdit->setEchoMode(QLineEdit::Password);
        RegisterButton = new QPushButton(centralwidget);
        RegisterButton->setObjectName(QString::fromUtf8("RegisterButton"));
        RegisterButton->setGeometry(QRect(380, 475, 80, 40));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        RegisterButton->setFont(font4);
        RegisterButton->setCursor(QCursor(Qt::PointingHandCursor));
        RegisterButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(30, 144, 255);\n"
"	border: none;\n"
"	border-radius: 10px;\n"
"	color: rgb(255, 255, 255);\n"
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
"}\n"
""));
        LoginButton = new QPushButton(centralwidget);
        LoginButton->setObjectName(QString::fromUtf8("LoginButton"));
        LoginButton->setGeometry(QRect(520, 475, 80, 40));
        LoginButton->setFont(font4);
        LoginButton->setCursor(QCursor(Qt::PointingHandCursor));
        LoginButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(30, 144, 255);\n"
"	border: none;\n"
"	border-radius: 10px;\n"
"	color: rgb(255, 255, 255);\n"
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
"}\n"
""));
        BackGround = new QLabel(centralwidget);
        BackGround->setObjectName(QString::fromUtf8("BackGround"));
        BackGround->setGeometry(QRect(0, 0, 1000, 800));
        sizePolicy.setHeightForWidth(BackGround->sizePolicy().hasHeightForWidth());
        BackGround->setSizePolicy(sizePolicy);
        BackGround->setMinimumSize(QSize(1000, 800));
        BackGround->setMaximumSize(QSize(1000, 800));
        BackGround->setPixmap(QPixmap(QString::fromUtf8(":/images/start_back.png")));
        LoginLabel = new QLabel(centralwidget);
        LoginLabel->setObjectName(QString::fromUtf8("LoginLabel"));
        LoginLabel->setGeometry(QRect(260, 215, 480, 320));
        LoginLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: white;\n"
"border-radius: 10px;  border: 2px groove lavender;\n"
"border-style: outset;\n"
""));
        LogoLabel = new QLabel(centralwidget);
        LogoLabel->setObjectName(QString::fromUtf8("LogoLabel"));
        LogoLabel->setGeometry(QRect(740, 710, 241, 61));
        LogoLabel->setStyleSheet(QString::fromUtf8(""));
        LogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/logo240x64.png")));
        IPLabel2 = new QLabel(centralwidget);
        IPLabel2->setObjectName(QString::fromUtf8("IPLabel2"));
        IPLabel2->setGeometry(QRect(120, 730, 380, 30));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font5.setPointSize(14);
        IPLabel2->setFont(font5);
        IPLabel2->setStyleSheet(QString::fromUtf8("color: rgb(190, 190, 190);"));
        IPLabel1 = new QLabel(centralwidget);
        IPLabel1->setObjectName(QString::fromUtf8("IPLabel1"));
        IPLabel1->setGeometry(QRect(10, 730, 111, 30));
        IPLabel1->setFont(font3);
        IPLabel1->setStyleSheet(QString::fromUtf8("color: rgb(190, 190, 190);"));
        ShowLabel = new QLabel(centralwidget);
        ShowLabel->setObjectName(QString::fromUtf8("ShowLabel"));
        ShowLabel->setGeometry(QRect(20, 20, 200, 200));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(590, 370, 85, 25));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font6.setPointSize(12);
        checkBox->setFont(font6);
        checkBox->setCursor(QCursor(Qt::PointingHandCursor));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(320, 330, 64, 64));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/user.png")));
        DataBaseButton = new QPushButton(centralwidget);
        DataBaseButton->setObjectName(QString::fromUtf8("DataBaseButton"));
        DataBaseButton->setGeometry(QRect(870, 10, 121, 41));
        DataBaseButton->setFont(font4);
        DataBaseButton->setCursor(QCursor(Qt::PointingHandCursor));
        DataBaseButton->setStyleSheet(QString::fromUtf8("background-color: rgb(204, 221, 255);\n"
"border: none;\n"
"border-radius: 10px;\n"
"color: rgb(255,255,255);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(950, 690, 21, 23));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(190, 190, 190);\n"
"border: none;"));
        PartCombo = new QComboBox(centralwidget);
        PartCombo->addItem(QString());
        PartCombo->addItem(QString());
        PartCombo->addItem(QString());
        PartCombo->setObjectName(QString::fromUtf8("PartCombo"));
        PartCombo->setGeometry(QRect(460, 415, 200, 35));
        PartCombo->setFont(font3);
        PartCombo->setCursor(QCursor(Qt::ArrowCursor));
        PartCombo->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        PartCombo->setEditable(false);
        PartLabel = new QLabel(centralwidget);
        PartLabel->setObjectName(QString::fromUtf8("PartLabel"));
        PartLabel->setGeometry(QRect(400, 420, 60, 25));
        PartLabel->setFont(font2);
        PartLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        TimeLabel = new QLabel(centralwidget);
        TimeLabel->setObjectName(QString::fromUtf8("TimeLabel"));
        TimeLabel->setGeometry(QRect(320, 170, 361, 41));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font7.setPointSize(26);
        TimeLabel->setFont(font7);
        TimeLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        LinkButton = new QPushButton(centralwidget);
        LinkButton->setObjectName(QString::fromUtf8("LinkButton"));
        LinkButton->setGeometry(QRect(760, 10, 91, 40));
        LinkButton->setFont(font4);
        LinkButton->setCursor(QCursor(Qt::PointingHandCursor));
        LinkButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(30, 144, 255);\n"
"	border: none;\n"
"	border-radius: 10px;\n"
"	color: rgb(255, 255, 255);\n"
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
"}\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        BackGround->raise();
        LoginLabel->raise();
        UserLabel->raise();
        UserEdit->raise();
        TitleLabel->raise();
        RegisterButton->raise();
        PasswdLabel->raise();
        PasswdEdit->raise();
        LoginButton->raise();
        IPLabel2->raise();
        IPLabel1->raise();
        LogoLabel->raise();
        ShowLabel->raise();
        checkBox->raise();
        label->raise();
        DataBaseButton->raise();
        pushButton->raise();
        PartCombo->raise();
        PartLabel->raise();
        TimeLabel->raise();
        LinkButton->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(UserEdit, PasswdEdit);
        QWidget::setTabOrder(PasswdEdit, checkBox);
        QWidget::setTabOrder(checkBox, PartCombo);
        QWidget::setTabOrder(PartCombo, RegisterButton);
        QWidget::setTabOrder(RegisterButton, LoginButton);
        QWidget::setTabOrder(LoginButton, DataBaseButton);
        QWidget::setTabOrder(DataBaseButton, pushButton);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        TitleLabel->setText(QCoreApplication::translate("MainWindow", "\346\254\242\350\277\216\344\275\277\347\224\250\346\250\241\345\205\267\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        UserLabel->setText(QCoreApplication::translate("MainWindow", "\350\264\246\345\217\267:", nullptr));
        PasswdLabel->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201:", nullptr));
        UserEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        PasswdEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        RegisterButton->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\206\214", nullptr));
        LoginButton->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        BackGround->setText(QString());
        LoginLabel->setText(QString());
        LogoLabel->setText(QString());
        IPLabel2->setText(QString());
        IPLabel1->setText(QCoreApplication::translate("MainWindow", "\346\202\250\345\267\262\350\277\236\346\216\245\350\207\263\357\274\232", nullptr));
        ShowLabel->setText(QString());
        checkBox->setText(QCoreApplication::translate("MainWindow", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        label->setText(QString());
        DataBaseButton->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\347\256\241\347\220\206", nullptr));
        pushButton->setText(QString());
        PartCombo->setItemText(0, QCoreApplication::translate("MainWindow", "\345\206\262\345\216\213\346\250\241\345\205\267\345\257\277\345\221\275\347\256\241\345\210\266", nullptr));
        PartCombo->setItemText(1, QCoreApplication::translate("MainWindow", "\346\210\220\345\236\213\346\250\241\345\205\267\345\257\277\345\221\275\347\256\241\345\210\266", nullptr));
        PartCombo->setItemText(2, QCoreApplication::translate("MainWindow", "\346\250\241\345\205\267&\345\244\207\344\273\266\344\273\223\345\202\250\347\256\241\347\220\206", nullptr));

        PartLabel->setText(QCoreApplication::translate("MainWindow", "\345\212\237\350\203\275:", nullptr));
        TimeLabel->setText(QCoreApplication::translate("MainWindow", "2025-08-05 00:00:00", nullptr));
        LinkButton->setText(QCoreApplication::translate("MainWindow", "\351\207\215\346\226\260\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
