/********************************************************************************
** Form generated from reading UI file 'handleworks.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDLEWORKS_H
#define UI_HANDLEWORKS_H

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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HandleWorks
{
public:
    QWidget *centralwidget;
    QPushButton *PushButton;
    QTextEdit *MessageEdit;
    QComboBox *PartCombo;
    QLabel *Label1;
    QListView *ProceList;
    QLabel *Label2;
    QLabel *Label5;
    QLabel *Label4;
    QLabel *LogoLabel;
    QLabel *BackGround;
    QLineEdit *MoldEdit;
    QComboBox *NatureCombo;
    QLabel *Label3;
    QPushButton *EmailButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HandleWorks)
    {
        if (HandleWorks->objectName().isEmpty())
            HandleWorks->setObjectName(QString::fromUtf8("HandleWorks"));
        HandleWorks->setEnabled(true);
        HandleWorks->resize(680, 540);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HandleWorks->sizePolicy().hasHeightForWidth());
        HandleWorks->setSizePolicy(sizePolicy);
        HandleWorks->setMinimumSize(QSize(680, 540));
        HandleWorks->setMaximumSize(QSize(680, 540));
        centralwidget = new QWidget(HandleWorks);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        PushButton = new QPushButton(centralwidget);
        PushButton->setObjectName(QString::fromUtf8("PushButton"));
        PushButton->setGeometry(QRect(510, 465, 121, 41));
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
        MessageEdit->setGeometry(QRect(280, 180, 351, 271));
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
        PartCombo = new QComboBox(centralwidget);
        PartCombo->addItem(QString());
        PartCombo->addItem(QString());
        PartCombo->addItem(QString());
        PartCombo->setObjectName(QString::fromUtf8("PartCombo"));
        PartCombo->setGeometry(QRect(50, 100, 151, 41));
        PartCombo->setFont(font1);
        PartCombo->setCursor(QCursor(Qt::ArrowCursor));
        PartCombo->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        PartCombo->setEditable(false);
        Label1 = new QLabel(centralwidget);
        Label1->setObjectName(QString::fromUtf8("Label1"));
        Label1->setGeometry(QRect(50, 70, 121, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font2.setPointSize(20);
        Label1->setFont(font2);
        ProceList = new QListView(centralwidget);
        ProceList->setObjectName(QString::fromUtf8("ProceList"));
        ProceList->setGeometry(QRect(50, 260, 201, 191));
        ProceList->setFont(font1);
        ProceList->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        ProceList->setStyleSheet(QString::fromUtf8("QListView{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProceList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Label2 = new QLabel(centralwidget);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(280, 70, 181, 31));
        Label2->setFont(font2);
        Label5 = new QLabel(centralwidget);
        Label5->setObjectName(QString::fromUtf8("Label5"));
        Label5->setGeometry(QRect(50, 230, 151, 31));
        Label5->setFont(font2);
        Label4 = new QLabel(centralwidget);
        Label4->setObjectName(QString::fromUtf8("Label4"));
        Label4->setGeometry(QRect(280, 150, 121, 31));
        Label4->setFont(font2);
        LogoLabel = new QLabel(centralwidget);
        LogoLabel->setObjectName(QString::fromUtf8("LogoLabel"));
        LogoLabel->setGeometry(QRect(470, 10, 200, 53));
        LogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/logo200x53.jpg")));
        BackGround = new QLabel(centralwidget);
        BackGround->setObjectName(QString::fromUtf8("BackGround"));
        BackGround->setGeometry(QRect(5, 5, 671, 516));
        BackGround->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"border-radius: 15px;\n"
"color: rgb(0,0,0);"));
        MoldEdit = new QLineEdit(centralwidget);
        MoldEdit->setObjectName(QString::fromUtf8("MoldEdit"));
        MoldEdit->setGeometry(QRect(280, 100, 271, 41));
        MoldEdit->setFont(font1);
        MoldEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        NatureCombo = new QComboBox(centralwidget);
        NatureCombo->setObjectName(QString::fromUtf8("NatureCombo"));
        NatureCombo->setGeometry(QRect(50, 180, 151, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(18);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        NatureCombo->setFont(font3);
        NatureCombo->setCursor(QCursor(Qt::ArrowCursor));
        NatureCombo->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        NatureCombo->setEditable(true);
        Label3 = new QLabel(centralwidget);
        Label3->setObjectName(QString::fromUtf8("Label3"));
        Label3->setGeometry(QRect(50, 150, 121, 31));
        Label3->setFont(font2);
        EmailButton = new QPushButton(centralwidget);
        EmailButton->setObjectName(QString::fromUtf8("EmailButton"));
        EmailButton->setGeometry(QRect(10, 10, 111, 41));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(16);
        font4.setBold(true);
        font4.setWeight(75);
        EmailButton->setFont(font4);
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
        HandleWorks->setCentralWidget(centralwidget);
        BackGround->raise();
        PushButton->raise();
        MessageEdit->raise();
        PartCombo->raise();
        Label1->raise();
        ProceList->raise();
        Label2->raise();
        Label5->raise();
        Label4->raise();
        LogoLabel->raise();
        MoldEdit->raise();
        NatureCombo->raise();
        Label3->raise();
        EmailButton->raise();
        menubar = new QMenuBar(HandleWorks);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 680, 23));
        HandleWorks->setMenuBar(menubar);
        statusbar = new QStatusBar(HandleWorks);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HandleWorks->setStatusBar(statusbar);
        QWidget::setTabOrder(PartCombo, MoldEdit);
        QWidget::setTabOrder(MoldEdit, NatureCombo);
        QWidget::setTabOrder(NatureCombo, ProceList);
        QWidget::setTabOrder(ProceList, MessageEdit);
        QWidget::setTabOrder(MessageEdit, PushButton);
        QWidget::setTabOrder(PushButton, EmailButton);

        retranslateUi(HandleWorks);

        QMetaObject::connectSlotsByName(HandleWorks);
    } // setupUi

    void retranslateUi(QMainWindow *HandleWorks)
    {
        HandleWorks->setWindowTitle(QCoreApplication::translate("HandleWorks", "MainWindow", nullptr));
        PushButton->setText(QCoreApplication::translate("HandleWorks", "\346\217\220\344\272\244\345\267\245\345\215\225", nullptr));
        MessageEdit->setPlaceholderText(QCoreApplication::translate("HandleWorks", "\350\257\267\345\241\253\345\206\231\345\267\245\345\215\225\344\277\241\346\201\257", nullptr));
        PartCombo->setItemText(0, QCoreApplication::translate("HandleWorks", "\345\206\262\345\216\213\351\203\250\351\227\250", nullptr));
        PartCombo->setItemText(1, QCoreApplication::translate("HandleWorks", "\345\241\221\346\250\241\351\203\250\351\227\250", nullptr));
        PartCombo->setItemText(2, QCoreApplication::translate("HandleWorks", "\344\273\223\345\272\223\351\203\250\351\227\250", nullptr));

        Label1->setText(QCoreApplication::translate("HandleWorks", "\351\200\211\346\213\251\351\203\250\351\227\250:", nullptr));
        Label2->setText(QCoreApplication::translate("HandleWorks", "\350\276\223\345\205\245\346\250\241\345\205\267\347\274\226\345\217\267:", nullptr));
        Label5->setText(QCoreApplication::translate("HandleWorks", "\351\200\211\346\213\251\345\244\204\347\220\206\344\272\272:", nullptr));
        Label4->setText(QCoreApplication::translate("HandleWorks", "\345\241\253\345\206\231\344\277\241\346\201\257:", nullptr));
        LogoLabel->setText(QString());
        BackGround->setText(QString());
        MoldEdit->setPlaceholderText(QCoreApplication::translate("HandleWorks", "\350\257\267\350\276\223\345\205\245\346\250\241\345\205\267\347\274\226\345\217\267", nullptr));
        Label3->setText(QCoreApplication::translate("HandleWorks", "\346\250\241\345\205\267\346\200\247\350\264\250:", nullptr));
        EmailButton->setText(QCoreApplication::translate("HandleWorks", "\345\217\221\351\200\201\351\202\256\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HandleWorks: public Ui_HandleWorks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDLEWORKS_H
