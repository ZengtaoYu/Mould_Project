/********************************************************************************
** Form generated from reading UI file 'emailwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMAILWINDOW_H
#define UI_EMAILWINDOW_H

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

class Ui_EmailWindow
{
public:
    QWidget *centralwidget;
    QLabel *Label1;
    QLabel *Label2;
    QLineEdit *ToEdit;
    QLineEdit *TitleEdit;
    QTextEdit *TextEdit;
    QLabel *Label3;
    QPushButton *SendButton;
    QPushButton *AddButton;
    QLabel *BackGround;
    QLabel *Label4;
    QPushButton *AddFile;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EmailWindow)
    {
        if (EmailWindow->objectName().isEmpty())
            EmailWindow->setObjectName(QString::fromUtf8("EmailWindow"));
        EmailWindow->resize(600, 430);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EmailWindow->sizePolicy().hasHeightForWidth());
        EmailWindow->setSizePolicy(sizePolicy);
        EmailWindow->setMinimumSize(QSize(600, 430));
        EmailWindow->setMaximumSize(QSize(600, 430));
        centralwidget = new QWidget(EmailWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Label1 = new QLabel(centralwidget);
        Label1->setObjectName(QString::fromUtf8("Label1"));
        Label1->setGeometry(QRect(20, 10, 71, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        Label1->setFont(font);
        Label2 = new QLabel(centralwidget);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(40, 50, 51, 31));
        Label2->setFont(font);
        ToEdit = new QLineEdit(centralwidget);
        ToEdit->setObjectName(QString::fromUtf8("ToEdit"));
        ToEdit->setGeometry(QRect(90, 10, 401, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        ToEdit->setFont(font1);
        ToEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        TitleEdit = new QLineEdit(centralwidget);
        TitleEdit->setObjectName(QString::fromUtf8("TitleEdit"));
        TitleEdit->setGeometry(QRect(90, 50, 401, 31));
        TitleEdit->setFont(font1);
        TitleEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        TextEdit = new QTextEdit(centralwidget);
        TextEdit->setObjectName(QString::fromUtf8("TextEdit"));
        TextEdit->setGeometry(QRect(60, 90, 530, 270));
        TextEdit->setFont(font1);
        TextEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        TextEdit->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        Label3 = new QLabel(centralwidget);
        Label3->setObjectName(QString::fromUtf8("Label3"));
        Label3->setGeometry(QRect(10, 190, 51, 31));
        Label3->setFont(font);
        SendButton = new QPushButton(centralwidget);
        SendButton->setObjectName(QString::fromUtf8("SendButton"));
        SendButton->setGeometry(QRect(505, 10, 81, 31));
        SendButton->setFont(font1);
        SendButton->setCursor(QCursor(Qt::PointingHandCursor));
        SendButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"}\n"
""));
        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setGeometry(QRect(505, 50, 81, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        AddButton->setFont(font2);
        AddButton->setCursor(QCursor(Qt::PointingHandCursor));
        AddButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"}\n"
""));
        BackGround = new QLabel(centralwidget);
        BackGround->setObjectName(QString::fromUtf8("BackGround"));
        BackGround->setGeometry(QRect(5, 5, 591, 406));
        BackGround->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);\n"
"border-radius: 15px;\n"
"border-style: outset;"));
        Label4 = new QLabel(centralwidget);
        Label4->setObjectName(QString::fromUtf8("Label4"));
        Label4->setGeometry(QRect(60, 370, 91, 31));
        Label4->setFont(font);
        AddFile = new QPushButton(centralwidget);
        AddFile->setObjectName(QString::fromUtf8("AddFile"));
        AddFile->setGeometry(QRect(150, 370, 221, 31));
        AddFile->setFont(font1);
        AddFile->setCursor(QCursor(Qt::PointingHandCursor));
        AddFile->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:white;\n"
"	background-color: rgb(204, 221, 255);\n"
"	border-radius: 10px;  border: 2px groove lavender;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{  /*\351\274\240\346\240\207\346\202\254\346\265\256\346\227\266*/\n"
"	background: rgb(170, 170, 225);\n"
"}\n"
"QPushButton:pressed{  /*\351\274\240\346\240\207\346\214\211\344\270\213\346\227\266*/\n"
"	background:rgb(96,96,96);\n"
"	color: rgb(200, 200, 200);\n"
"}\n"
""));
        EmailWindow->setCentralWidget(centralwidget);
        BackGround->raise();
        Label1->raise();
        Label2->raise();
        ToEdit->raise();
        TitleEdit->raise();
        TextEdit->raise();
        Label3->raise();
        SendButton->raise();
        AddButton->raise();
        Label4->raise();
        AddFile->raise();
        menubar = new QMenuBar(EmailWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 23));
        EmailWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(EmailWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        EmailWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(ToEdit, TitleEdit);
        QWidget::setTabOrder(TitleEdit, TextEdit);
        QWidget::setTabOrder(TextEdit, AddButton);
        QWidget::setTabOrder(AddButton, AddFile);
        QWidget::setTabOrder(AddFile, SendButton);

        retranslateUi(EmailWindow);

        QMetaObject::connectSlotsByName(EmailWindow);
    } // setupUi

    void retranslateUi(QMainWindow *EmailWindow)
    {
        EmailWindow->setWindowTitle(QCoreApplication::translate("EmailWindow", "MainWindow", nullptr));
        Label1->setText(QCoreApplication::translate("EmailWindow", "\346\224\266\344\273\266\344\272\272:", nullptr));
        Label2->setText(QCoreApplication::translate("EmailWindow", "\344\270\273\351\242\230:", nullptr));
        ToEdit->setText(QString());
        ToEdit->setPlaceholderText(QCoreApplication::translate("EmailWindow", "example@qq.com", nullptr));
        TitleEdit->setText(QString());
        TitleEdit->setPlaceholderText(QCoreApplication::translate("EmailWindow", "\350\257\267\350\276\223\345\205\245\344\270\273\351\242\230", nullptr));
        TextEdit->setHtml(QCoreApplication::translate("EmailWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        TextEdit->setPlaceholderText(QCoreApplication::translate("EmailWindow", "\350\257\267\350\276\223\345\205\245\346\255\243\346\226\207", nullptr));
        Label3->setText(QCoreApplication::translate("EmailWindow", "\346\255\243\346\226\207:", nullptr));
        SendButton->setText(QCoreApplication::translate("EmailWindow", "\345\217\221\351\200\201", nullptr));
        AddButton->setText(QCoreApplication::translate("EmailWindow", "\346\267\273\345\212\240\351\231\204\344\273\266", nullptr));
        BackGround->setText(QString());
        Label4->setText(QCoreApplication::translate("EmailWindow", "\346\267\273\345\212\240\351\231\204\344\273\266:", nullptr));
        AddFile->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EmailWindow: public Ui_EmailWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMAILWINDOW_H
