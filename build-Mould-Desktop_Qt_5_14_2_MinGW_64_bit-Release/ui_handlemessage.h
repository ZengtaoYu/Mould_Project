/********************************************************************************
** Form generated from reading UI file 'handlemessage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDLEMESSAGE_H
#define UI_HANDLEMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HandleMessage
{
public:
    QWidget *centralwidget;
    QTableView *SystemMessage;
    QLabel *Label1;
    QPushButton *HandleButton1;
    QPushButton *FinishedButton1;
    QFrame *line;
    QPushButton *FinishedButton2;
    QLabel *Label2;
    QPushButton *HandleButton2;
    QTableView *UserMessage;
    QLabel *BackGround;
    QPushButton *EmailButton;
    QPushButton *CheckButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HandleMessage)
    {
        if (HandleMessage->objectName().isEmpty())
            HandleMessage->setObjectName(QString::fromUtf8("HandleMessage"));
        HandleMessage->resize(605, 535);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HandleMessage->sizePolicy().hasHeightForWidth());
        HandleMessage->setSizePolicy(sizePolicy);
        HandleMessage->setMinimumSize(QSize(605, 535));
        HandleMessage->setMaximumSize(QSize(605, 535));
        centralwidget = new QWidget(HandleMessage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SystemMessage = new QTableView(centralwidget);
        SystemMessage->setObjectName(QString::fromUtf8("SystemMessage"));
        SystemMessage->setGeometry(QRect(20, 50, 571, 211));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        SystemMessage->setFont(font);
        SystemMessage->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        SystemMessage->setStyleSheet(QString::fromUtf8("border-radius: 2px;\n"
"font-size: 12pt;"));
        SystemMessage->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Label1 = new QLabel(centralwidget);
        Label1->setObjectName(QString::fromUtf8("Label1"));
        Label1->setGeometry(QRect(20, 15, 101, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        Label1->setFont(font1);
        HandleButton1 = new QPushButton(centralwidget);
        HandleButton1->setObjectName(QString::fromUtf8("HandleButton1"));
        HandleButton1->setGeometry(QRect(340, 10, 71, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setWeight(75);
        HandleButton1->setFont(font2);
        HandleButton1->setCursor(QCursor(Qt::PointingHandCursor));
        HandleButton1->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"color: rgb(200, 200, 200);\n"
"}"));
        FinishedButton1 = new QPushButton(centralwidget);
        FinishedButton1->setObjectName(QString::fromUtf8("FinishedButton1"));
        FinishedButton1->setGeometry(QRect(500, 10, 91, 41));
        FinishedButton1->setFont(font2);
        FinishedButton1->setCursor(QCursor(Qt::PointingHandCursor));
        FinishedButton1->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"color: rgb(200, 200, 200);\n"
"}"));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 265, 581, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        FinishedButton2 = new QPushButton(centralwidget);
        FinishedButton2->setObjectName(QString::fromUtf8("FinishedButton2"));
        FinishedButton2->setGeometry(QRect(500, 290, 91, 41));
        FinishedButton2->setFont(font2);
        FinishedButton2->setCursor(QCursor(Qt::PointingHandCursor));
        FinishedButton2->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"color: rgb(200, 200, 200);\n"
"}"));
        Label2 = new QLabel(centralwidget);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(20, 295, 101, 31));
        Label2->setFont(font1);
        HandleButton2 = new QPushButton(centralwidget);
        HandleButton2->setObjectName(QString::fromUtf8("HandleButton2"));
        HandleButton2->setGeometry(QRect(300, 290, 71, 41));
        HandleButton2->setFont(font2);
        HandleButton2->setCursor(QCursor(Qt::PointingHandCursor));
        HandleButton2->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"color: rgb(200, 200, 200);\n"
"}"));
        UserMessage = new QTableView(centralwidget);
        UserMessage->setObjectName(QString::fromUtf8("UserMessage"));
        UserMessage->setGeometry(QRect(20, 330, 571, 171));
        UserMessage->setFont(font);
        UserMessage->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        UserMessage->setStyleSheet(QString::fromUtf8("border-radius: 2px;\n"
"font-size: 12pt;"));
        UserMessage->setEditTriggers(QAbstractItemView::NoEditTriggers);
        BackGround = new QLabel(centralwidget);
        BackGround->setObjectName(QString::fromUtf8("BackGround"));
        BackGround->setGeometry(QRect(5, 5, 596, 511));
        BackGround->setStyleSheet(QString::fromUtf8("background-color: rgb(204, 221, 255);\n"
"border: none;\n"
"border-radius: 10px;\n"
"font-size: 20pt;"));
        EmailButton = new QPushButton(centralwidget);
        EmailButton->setObjectName(QString::fromUtf8("EmailButton"));
        EmailButton->setGeometry(QRect(380, 290, 111, 41));
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
        CheckButton = new QPushButton(centralwidget);
        CheckButton->setObjectName(QString::fromUtf8("CheckButton"));
        CheckButton->setEnabled(true);
        CheckButton->setGeometry(QRect(420, 10, 71, 41));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CheckButton->sizePolicy().hasHeightForWidth());
        CheckButton->setSizePolicy(sizePolicy1);
        CheckButton->setFont(font2);
        CheckButton->setCursor(QCursor(Qt::PointingHandCursor));
        CheckButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"color: rgb(200, 200, 200);\n"
"}"));
        CheckButton->setIconSize(QSize(20, 20));
        HandleMessage->setCentralWidget(centralwidget);
        BackGround->raise();
        SystemMessage->raise();
        Label1->raise();
        line->raise();
        Label2->raise();
        UserMessage->raise();
        EmailButton->raise();
        FinishedButton2->raise();
        HandleButton2->raise();
        FinishedButton1->raise();
        HandleButton1->raise();
        CheckButton->raise();
        menubar = new QMenuBar(HandleMessage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 605, 23));
        HandleMessage->setMenuBar(menubar);
        statusbar = new QStatusBar(HandleMessage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HandleMessage->setStatusBar(statusbar);
        QWidget::setTabOrder(SystemMessage, HandleButton1);
        QWidget::setTabOrder(HandleButton1, CheckButton);
        QWidget::setTabOrder(CheckButton, FinishedButton1);
        QWidget::setTabOrder(FinishedButton1, UserMessage);
        QWidget::setTabOrder(UserMessage, HandleButton2);
        QWidget::setTabOrder(HandleButton2, EmailButton);
        QWidget::setTabOrder(EmailButton, FinishedButton2);

        retranslateUi(HandleMessage);

        QMetaObject::connectSlotsByName(HandleMessage);
    } // setupUi

    void retranslateUi(QMainWindow *HandleMessage)
    {
        HandleMessage->setWindowTitle(QCoreApplication::translate("HandleMessage", "MainWindow", nullptr));
        Label1->setText(QCoreApplication::translate("HandleMessage", "\347\263\273\347\273\237\346\266\210\346\201\257", nullptr));
        HandleButton1->setText(QCoreApplication::translate("HandleMessage", "\345\244\204\347\220\206", nullptr));
        FinishedButton1->setText(QCoreApplication::translate("HandleMessage", "\345\267\262\345\256\214\346\210\220", nullptr));
        FinishedButton2->setText(QCoreApplication::translate("HandleMessage", "\345\267\262\345\256\214\346\210\220", nullptr));
        Label2->setText(QCoreApplication::translate("HandleMessage", "\347\224\250\346\210\267\346\266\210\346\201\257", nullptr));
        HandleButton2->setText(QCoreApplication::translate("HandleMessage", "\345\244\204\347\220\206", nullptr));
        BackGround->setText(QString());
        EmailButton->setText(QCoreApplication::translate("HandleMessage", "\345\217\221\351\200\201\351\202\256\344\273\266", nullptr));
        CheckButton->setText(QCoreApplication::translate("HandleMessage", "\345\257\274\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HandleMessage: public Ui_HandleMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDLEMESSAGE_H
