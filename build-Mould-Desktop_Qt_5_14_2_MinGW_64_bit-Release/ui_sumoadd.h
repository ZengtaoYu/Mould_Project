/********************************************************************************
** Form generated from reading UI file 'sumoadd.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUMOADD_H
#define UI_SUMOADD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
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

class Ui_SumoAdd
{
public:
    QWidget *centralwidget;
    QLabel *Label8;
    QLabel *Label3;
    QLabel *Label2;
    QLineEdit *MoldID;
    QLabel *Label1;
    QPushButton *AddButton;
    QLabel *LogoLabel;
    QLabel *BackGround;
    QTextEdit *ProductName;
    QLineEdit *LifeNum;
    QLabel *Label12;
    QLineEdit *MachineNum;
    QLabel *Label7;
    QLabel *Label11;
    QLineEdit *KeepNum1;
    QLabel *Label9;
    QLineEdit *KeepNum2;
    QLineEdit *KeepNum3;
    QLabel *Label10;
    QLineEdit *OutNum;
    QLineEdit *ProductNum1;
    QLabel *Label4;
    QLineEdit *ProductNum2;
    QLabel *Label5;
    QLabel *Label6;
    QLineEdit *ProductNum;
    QLineEdit *ProductID;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SumoAdd)
    {
        if (SumoAdd->objectName().isEmpty())
            SumoAdd->setObjectName(QString::fromUtf8("SumoAdd"));
        SumoAdd->resize(630, 470);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SumoAdd->sizePolicy().hasHeightForWidth());
        SumoAdd->setSizePolicy(sizePolicy);
        SumoAdd->setMinimumSize(QSize(630, 470));
        SumoAdd->setMaximumSize(QSize(630, 470));
        centralwidget = new QWidget(SumoAdd);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Label8 = new QLabel(centralwidget);
        Label8->setObjectName(QString::fromUtf8("Label8"));
        Label8->setGeometry(QRect(20, 255, 201, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(20);
        Label8->setFont(font);
        Label3 = new QLabel(centralwidget);
        Label3->setObjectName(QString::fromUtf8("Label3"));
        Label3->setGeometry(QRect(20, 145, 121, 31));
        Label3->setFont(font);
        Label2 = new QLabel(centralwidget);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(20, 90, 121, 31));
        Label2->setFont(font);
        MoldID = new QLineEdit(centralwidget);
        MoldID->setObjectName(QString::fromUtf8("MoldID"));
        MoldID->setGeometry(QRect(150, 140, 181, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(16);
        MoldID->setFont(font1);
        MoldID->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MoldID->setReadOnly(false);
        Label1 = new QLabel(centralwidget);
        Label1->setObjectName(QString::fromUtf8("Label1"));
        Label1->setGeometry(QRect(20, 35, 121, 31));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Label1->sizePolicy().hasHeightForWidth());
        Label1->setSizePolicy(sizePolicy1);
        Label1->setFont(font);
        Label1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Label1->setWordWrap(false);
        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setEnabled(true);
        AddButton->setGeometry(QRect(350, 365, 131, 61));
        sizePolicy1.setHeightForWidth(AddButton->sizePolicy().hasHeightForWidth());
        AddButton->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        AddButton->setFont(font2);
        AddButton->setCursor(QCursor(Qt::PointingHandCursor));
        AddButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:white;\n"
"	background-color: rgb(170, 170, 255);\n"
"	border-radius: 15px;  border: 2px groove lavender;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{  /*\351\274\240\346\240\207\346\202\254\346\265\256\346\227\266*/\n"
"	background: rgb(170, 85, 255);\n"
"}\n"
"QPushButton:pressed{  /*\351\274\240\346\240\207\346\214\211\344\270\213\346\227\266*/\n"
"	background:rgb(96,96,96);\n"
"color: rgb(200, 200, 200);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddButton->setIcon(icon);
        AddButton->setIconSize(QSize(20, 20));
        LogoLabel = new QLabel(centralwidget);
        LogoLabel->setObjectName(QString::fromUtf8("LogoLabel"));
        LogoLabel->setGeometry(QRect(510, 410, 110, 30));
        LogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/logo110x30.jpg")));
        BackGround = new QLabel(centralwidget);
        BackGround->setObjectName(QString::fromUtf8("BackGround"));
        BackGround->setGeometry(QRect(0, 0, 631, 471));
        BackGround->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        ProductName = new QTextEdit(centralwidget);
        ProductName->setObjectName(QString::fromUtf8("ProductName"));
        ProductName->setGeometry(QRect(150, 30, 261, 41));
        ProductName->setFont(font1);
        ProductName->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        ProductName->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductName->setReadOnly(false);
        LifeNum = new QLineEdit(centralwidget);
        LifeNum->setObjectName(QString::fromUtf8("LifeNum"));
        LifeNum->setGeometry(QRect(200, 370, 81, 41));
        LifeNum->setFont(font1);
        LifeNum->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        LifeNum->setAlignment(Qt::AlignCenter);
        LifeNum->setReadOnly(false);
        Label12 = new QLabel(centralwidget);
        Label12->setObjectName(QString::fromUtf8("Label12"));
        Label12->setGeometry(QRect(20, 375, 171, 31));
        Label12->setFont(font);
        MachineNum = new QLineEdit(centralwidget);
        MachineNum->setObjectName(QString::fromUtf8("MachineNum"));
        MachineNum->setGeometry(QRect(520, 195, 51, 41));
        MachineNum->setFont(font1);
        MachineNum->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MachineNum->setAlignment(Qt::AlignCenter);
        MachineNum->setReadOnly(false);
        Label7 = new QLabel(centralwidget);
        Label7->setObjectName(QString::fromUtf8("Label7"));
        Label7->setGeometry(QRect(395, 200, 121, 31));
        Label7->setFont(font);
        Label11 = new QLabel(centralwidget);
        Label11->setObjectName(QString::fromUtf8("Label11"));
        Label11->setGeometry(QRect(430, 315, 71, 31));
        Label11->setFont(font);
        KeepNum1 = new QLineEdit(centralwidget);
        KeepNum1->setObjectName(QString::fromUtf8("KeepNum1"));
        KeepNum1->setGeometry(QRect(225, 250, 81, 41));
        KeepNum1->setFont(font1);
        KeepNum1->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        KeepNum1->setAlignment(Qt::AlignCenter);
        KeepNum1->setReadOnly(false);
        Label9 = new QLabel(centralwidget);
        Label9->setObjectName(QString::fromUtf8("Label9"));
        Label9->setGeometry(QRect(340, 255, 171, 31));
        Label9->setFont(font);
        KeepNum2 = new QLineEdit(centralwidget);
        KeepNum2->setObjectName(QString::fromUtf8("KeepNum2"));
        KeepNum2->setGeometry(QRect(520, 250, 91, 41));
        KeepNum2->setFont(font1);
        KeepNum2->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        KeepNum2->setAlignment(Qt::AlignCenter);
        KeepNum2->setReadOnly(false);
        KeepNum3 = new QLineEdit(centralwidget);
        KeepNum3->setObjectName(QString::fromUtf8("KeepNum3"));
        KeepNum3->setGeometry(QRect(310, 310, 91, 41));
        KeepNum3->setFont(font1);
        KeepNum3->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        KeepNum3->setAlignment(Qt::AlignCenter);
        KeepNum3->setReadOnly(false);
        Label10 = new QLabel(centralwidget);
        Label10->setObjectName(QString::fromUtf8("Label10"));
        Label10->setGeometry(QRect(20, 315, 291, 31));
        Label10->setFont(font);
        OutNum = new QLineEdit(centralwidget);
        OutNum->setObjectName(QString::fromUtf8("OutNum"));
        OutNum->setGeometry(QRect(500, 310, 51, 41));
        OutNum->setFont(font1);
        OutNum->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        OutNum->setAlignment(Qt::AlignCenter);
        OutNum->setReadOnly(false);
        ProductNum1 = new QLineEdit(centralwidget);
        ProductNum1->setObjectName(QString::fromUtf8("ProductNum1"));
        ProductNum1->setGeometry(QRect(480, 60, 81, 41));
        ProductNum1->setFont(font1);
        ProductNum1->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductNum1->setAlignment(Qt::AlignCenter);
        ProductNum1->setReadOnly(false);
        Label4 = new QLabel(centralwidget);
        Label4->setObjectName(QString::fromUtf8("Label4"));
        Label4->setGeometry(QRect(450, 30, 161, 31));
        Label4->setFont(font);
        ProductNum2 = new QLineEdit(centralwidget);
        ProductNum2->setObjectName(QString::fromUtf8("ProductNum2"));
        ProductNum2->setGeometry(QRect(480, 140, 81, 41));
        ProductNum2->setFont(font1);
        ProductNum2->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductNum2->setAlignment(Qt::AlignCenter);
        ProductNum2->setReadOnly(false);
        Label5 = new QLabel(centralwidget);
        Label5->setObjectName(QString::fromUtf8("Label5"));
        Label5->setGeometry(QRect(450, 110, 161, 31));
        Label5->setFont(font);
        Label6 = new QLabel(centralwidget);
        Label6->setObjectName(QString::fromUtf8("Label6"));
        Label6->setGeometry(QRect(20, 200, 121, 31));
        Label6->setFont(font);
        ProductNum = new QLineEdit(centralwidget);
        ProductNum->setObjectName(QString::fromUtf8("ProductNum"));
        ProductNum->setGeometry(QRect(150, 195, 181, 41));
        ProductNum->setFont(font1);
        ProductNum->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductNum->setAlignment(Qt::AlignCenter);
        ProductNum->setReadOnly(false);
        ProductID = new QLineEdit(centralwidget);
        ProductID->setObjectName(QString::fromUtf8("ProductID"));
        ProductID->setGeometry(QRect(150, 85, 261, 41));
        ProductID->setFont(font1);
        ProductID->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductID->setReadOnly(false);
        SumoAdd->setCentralWidget(centralwidget);
        BackGround->raise();
        Label8->raise();
        Label3->raise();
        Label2->raise();
        MoldID->raise();
        Label1->raise();
        AddButton->raise();
        LogoLabel->raise();
        ProductName->raise();
        LifeNum->raise();
        Label12->raise();
        MachineNum->raise();
        Label7->raise();
        Label11->raise();
        KeepNum1->raise();
        Label9->raise();
        KeepNum2->raise();
        KeepNum3->raise();
        Label10->raise();
        OutNum->raise();
        ProductNum1->raise();
        Label4->raise();
        ProductNum2->raise();
        Label5->raise();
        Label6->raise();
        ProductNum->raise();
        ProductID->raise();
        menubar = new QMenuBar(SumoAdd);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 630, 23));
        SumoAdd->setMenuBar(menubar);
        statusbar = new QStatusBar(SumoAdd);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SumoAdd->setStatusBar(statusbar);
        QWidget::setTabOrder(ProductName, ProductID);
        QWidget::setTabOrder(ProductID, MoldID);
        QWidget::setTabOrder(MoldID, ProductNum);
        QWidget::setTabOrder(ProductNum, ProductNum1);
        QWidget::setTabOrder(ProductNum1, ProductNum2);
        QWidget::setTabOrder(ProductNum2, MachineNum);
        QWidget::setTabOrder(MachineNum, KeepNum1);
        QWidget::setTabOrder(KeepNum1, KeepNum2);
        QWidget::setTabOrder(KeepNum2, KeepNum3);
        QWidget::setTabOrder(KeepNum3, OutNum);
        QWidget::setTabOrder(OutNum, LifeNum);
        QWidget::setTabOrder(LifeNum, AddButton);

        retranslateUi(SumoAdd);

        QMetaObject::connectSlotsByName(SumoAdd);
    } // setupUi

    void retranslateUi(QMainWindow *SumoAdd)
    {
        SumoAdd->setWindowTitle(QCoreApplication::translate("SumoAdd", "MainWindow", nullptr));
        Label8->setText(QCoreApplication::translate("SumoAdd", "\345\256\232\346\234\237\344\277\235\345\205\273\346\250\241\346\254\241\346\225\260:", nullptr));
        Label3->setText(QCoreApplication::translate("SumoAdd", "\346\250\241\345\205\267\347\274\226\345\217\267:", nullptr));
        Label2->setText(QCoreApplication::translate("SumoAdd", "\344\272\247\345\223\201\346\226\231\345\217\267:", nullptr));
        MoldID->setPlaceholderText(QCoreApplication::translate("SumoAdd", "\350\257\267\350\276\223\345\205\245\346\250\241\345\205\267\347\274\226\345\217\267", nullptr));
        Label1->setText(QCoreApplication::translate("SumoAdd", "\344\272\247\345\223\201\345\220\215\347\247\260:", nullptr));
        AddButton->setText(QCoreApplication::translate("SumoAdd", "\345\242\236\345\212\240\346\250\241\345\205\267", nullptr));
        LogoLabel->setText(QString());
        BackGround->setText(QString());
        ProductName->setPlaceholderText(QCoreApplication::translate("SumoAdd", "\350\257\267\350\276\223\345\205\245\344\272\247\345\223\201\345\220\215\347\247\260", nullptr));
        LifeNum->setText(QCoreApplication::translate("SumoAdd", "200", nullptr));
        Label12->setText(QCoreApplication::translate("SumoAdd", "\346\250\241\345\205\267\350\256\276\350\256\241\345\257\277\345\221\275:", nullptr));
        MachineNum->setPlaceholderText(QCoreApplication::translate("SumoAdd", "1#", nullptr));
        Label7->setText(QCoreApplication::translate("SumoAdd", "\345\242\236\345\212\240\346\234\272\345\217\260:", nullptr));
        Label11->setText(QCoreApplication::translate("SumoAdd", "\347\251\264\346\225\260:", nullptr));
        KeepNum1->setText(QCoreApplication::translate("SumoAdd", "50000", nullptr));
        Label9->setText(QCoreApplication::translate("SumoAdd", "\345\244\247\344\277\235\345\205\273\346\250\241\346\254\241\346\225\260:", nullptr));
        KeepNum2->setText(QCoreApplication::translate("SumoAdd", "500000", nullptr));
        KeepNum3->setText(QCoreApplication::translate("SumoAdd", "500000", nullptr));
        Label10->setText(QCoreApplication::translate("SumoAdd", "\347\211\271\345\256\232\346\230\223\346\215\237\344\273\266\347\256\241\345\210\266\346\250\241\346\254\241\346\225\260:", nullptr));
        OutNum->setText(QString());
        ProductNum1->setText(QString());
        Label4->setText(QCoreApplication::translate("SumoAdd", "\345\211\251\344\275\231\350\256\242\345\215\225\346\225\2601:", nullptr));
        ProductNum2->setText(QString());
        Label5->setText(QCoreApplication::translate("SumoAdd", "\345\211\251\344\275\231\350\256\242\345\215\225\346\225\2602:", nullptr));
        Label6->setText(QCoreApplication::translate("SumoAdd", "\346\240\207\345\207\206\344\272\247\351\207\217:", nullptr));
        ProductNum->setText(QString());
        ProductNum->setPlaceholderText(QCoreApplication::translate("SumoAdd", "\346\240\207\345\207\206\344\272\247\351\207\217(k/24H)", nullptr));
        ProductID->setPlaceholderText(QCoreApplication::translate("SumoAdd", "\350\257\267\350\276\223\345\205\245\344\272\247\345\223\201\346\226\231\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SumoAdd: public Ui_SumoAdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUMOADD_H
