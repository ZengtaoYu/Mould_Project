/********************************************************************************
** Form generated from reading UI file 'sumoedit.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUMOEDIT_H
#define UI_SUMOEDIT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SumoEdit
{
public:
    QWidget *centralwidget;
    QPushButton *EditButton;
    QLabel *Back1;
    QLabel *Label13;
    QLineEdit *MachineNum;
    QComboBox *MachineComb;
    QPushButton *AddButton;
    QLabel *Back2;
    QPushButton *DeleButton;
    QLabel *Label12;
    QLabel *LogoLabel;
    QTextEdit *ProductName;
    QLabel *Label11;
    QLineEdit *LifeNum;
    QLabel *Label10;
    QLineEdit *ProductNum;
    QLabel *Label5;
    QLineEdit *MoldID;
    QLabel *Label1;
    QLabel *Label7;
    QLabel *Label6;
    QLabel *Label4;
    QLabel *Label8;
    QLineEdit *ProductNum2;
    QLabel *Label2;
    QLabel *Label9;
    QTextEdit *ProductID;
    QLineEdit *KeepNum1;
    QLineEdit *KeepNum2;
    QLabel *Label3;
    QLineEdit *KeepNum3;
    QLineEdit *OutNum;
    QLineEdit *ProductNum1;
    QPushButton *NameButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SumoEdit)
    {
        if (SumoEdit->objectName().isEmpty())
            SumoEdit->setObjectName(QString::fromUtf8("SumoEdit"));
        SumoEdit->resize(690, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SumoEdit->sizePolicy().hasHeightForWidth());
        SumoEdit->setSizePolicy(sizePolicy);
        SumoEdit->setMinimumSize(QSize(690, 600));
        SumoEdit->setMaximumSize(QSize(690, 600));
        centralwidget = new QWidget(SumoEdit);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        EditButton = new QPushButton(centralwidget);
        EditButton->setObjectName(QString::fromUtf8("EditButton"));
        EditButton->setEnabled(true);
        EditButton->setGeometry(QRect(500, 370, 131, 61));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(EditButton->sizePolicy().hasHeightForWidth());
        EditButton->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        EditButton->setFont(font);
        EditButton->setCursor(QCursor(Qt::PointingHandCursor));
        EditButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:white;\n"
"	background-color: rgb(170, 170, 255);\n"
"	border-radius: 20px;  border: 2px groove lavender;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{  /*\351\274\240\346\240\207\346\202\254\346\265\256\346\227\266*/\n"
"	background: rgb(170, 85, 255);\n"
"}\n"
"QPushButton:pressed{  /*\351\274\240\346\240\207\346\214\211\344\270\213\346\227\266*/\n"
"	background:rgb(96,96,96);\n"
"color: rgb(200, 200, 200);\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/change.png"), QSize(), QIcon::Normal, QIcon::Off);
        EditButton->setIcon(icon);
        EditButton->setIconSize(QSize(20, 20));
        Back1 = new QLabel(centralwidget);
        Back1->setObjectName(QString::fromUtf8("Back1"));
        Back1->setGeometry(QRect(0, 0, 691, 446));
        Back1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"border-style: outset;"));
        Label13 = new QLabel(centralwidget);
        Label13->setObjectName(QString::fromUtf8("Label13"));
        Label13->setGeometry(QRect(301, 465, 121, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(20);
        Label13->setFont(font1);
        MachineNum = new QLineEdit(centralwidget);
        MachineNum->setObjectName(QString::fromUtf8("MachineNum"));
        MachineNum->setGeometry(QRect(431, 460, 101, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(16);
        MachineNum->setFont(font2);
        MachineNum->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MachineNum->setAlignment(Qt::AlignCenter);
        MachineNum->setReadOnly(false);
        MachineComb = new QComboBox(centralwidget);
        MachineComb->setObjectName(QString::fromUtf8("MachineComb"));
        MachineComb->setGeometry(QRect(161, 460, 101, 41));
        MachineComb->setFont(font2);
        MachineComb->setCursor(QCursor(Qt::ArrowCursor));
        MachineComb->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setEnabled(true);
        AddButton->setGeometry(QRect(410, 515, 121, 51));
        sizePolicy1.setHeightForWidth(AddButton->sizePolicy().hasHeightForWidth());
        AddButton->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        AddButton->setFont(font3);
        AddButton->setCursor(QCursor(Qt::PointingHandCursor));
        AddButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"}\n"
"QPushButton:!enabled {   /*\346\214\211\351\222\256\347\246\201\347\224\250\346\227\266*/\n"
"	background: rgb(100, 100, 100);\n"
"	color: rgb(200, 200, 200);\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddButton->setIcon(icon1);
        AddButton->setIconSize(QSize(20, 20));
        Back2 = new QLabel(centralwidget);
        Back2->setObjectName(QString::fromUtf8("Back2"));
        Back2->setGeometry(QRect(0, 445, 691, 131));
        Back2->setStyleSheet(QString::fromUtf8("background-color: rgb(160, 175, 200);\n"
"border-radius: 10px;\n"
"border-style: outset;"));
        DeleButton = new QPushButton(centralwidget);
        DeleButton->setObjectName(QString::fromUtf8("DeleButton"));
        DeleButton->setEnabled(true);
        DeleButton->setGeometry(QRect(140, 515, 121, 51));
        sizePolicy1.setHeightForWidth(DeleButton->sizePolicy().hasHeightForWidth());
        DeleButton->setSizePolicy(sizePolicy1);
        DeleButton->setFont(font3);
        DeleButton->setCursor(QCursor(Qt::PointingHandCursor));
        DeleButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"}\n"
"QPushButton:!enabled {   /*\346\214\211\351\222\256\347\246\201\347\224\250\346\227\266*/\n"
"	background: rgb(100, 100, 100);\n"
"	color: rgb(200, 200, 200);\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        DeleButton->setIcon(icon2);
        DeleButton->setIconSize(QSize(20, 20));
        Label12 = new QLabel(centralwidget);
        Label12->setObjectName(QString::fromUtf8("Label12"));
        Label12->setGeometry(QRect(31, 465, 121, 31));
        Label12->setFont(font1);
        LogoLabel = new QLabel(centralwidget);
        LogoLabel->setObjectName(QString::fromUtf8("LogoLabel"));
        LogoLabel->setGeometry(QRect(470, 10, 200, 53));
        LogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/logo200x53.jpg")));
        ProductName = new QTextEdit(centralwidget);
        ProductName->setObjectName(QString::fromUtf8("ProductName"));
        ProductName->setGeometry(QRect(170, 40, 261, 41));
        ProductName->setFont(font2);
        ProductName->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        ProductName->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductName->setReadOnly(false);
        Label11 = new QLabel(centralwidget);
        Label11->setObjectName(QString::fromUtf8("Label11"));
        Label11->setGeometry(QRect(150, 385, 171, 31));
        Label11->setFont(font1);
        LifeNum = new QLineEdit(centralwidget);
        LifeNum->setObjectName(QString::fromUtf8("LifeNum"));
        LifeNum->setGeometry(QRect(330, 380, 81, 41));
        LifeNum->setFont(font2);
        LifeNum->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        LifeNum->setAlignment(Qt::AlignCenter);
        LifeNum->setReadOnly(false);
        Label10 = new QLabel(centralwidget);
        Label10->setObjectName(QString::fromUtf8("Label10"));
        Label10->setGeometry(QRect(450, 325, 71, 31));
        Label10->setFont(font1);
        ProductNum = new QLineEdit(centralwidget);
        ProductNum->setObjectName(QString::fromUtf8("ProductNum"));
        ProductNum->setGeometry(QRect(170, 205, 181, 41));
        ProductNum->setFont(font2);
        ProductNum->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductNum->setAlignment(Qt::AlignCenter);
        ProductNum->setReadOnly(false);
        Label5 = new QLabel(centralwidget);
        Label5->setObjectName(QString::fromUtf8("Label5"));
        Label5->setGeometry(QRect(40, 205, 121, 31));
        Label5->setFont(font1);
        MoldID = new QLineEdit(centralwidget);
        MoldID->setObjectName(QString::fromUtf8("MoldID"));
        MoldID->setGeometry(QRect(170, 150, 181, 41));
        MoldID->setFont(font2);
        MoldID->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MoldID->setAlignment(Qt::AlignCenter);
        MoldID->setReadOnly(true);
        Label1 = new QLabel(centralwidget);
        Label1->setObjectName(QString::fromUtf8("Label1"));
        Label1->setGeometry(QRect(40, 45, 121, 31));
        sizePolicy1.setHeightForWidth(Label1->sizePolicy().hasHeightForWidth());
        Label1->setSizePolicy(sizePolicy1);
        Label1->setFont(font1);
        Label1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Label1->setWordWrap(false);
        Label7 = new QLabel(centralwidget);
        Label7->setObjectName(QString::fromUtf8("Label7"));
        Label7->setGeometry(QRect(40, 265, 201, 31));
        Label7->setFont(font1);
        Label6 = new QLabel(centralwidget);
        Label6->setObjectName(QString::fromUtf8("Label6"));
        Label6->setGeometry(QRect(370, 215, 161, 31));
        Label6->setFont(font1);
        Label4 = new QLabel(centralwidget);
        Label4->setObjectName(QString::fromUtf8("Label4"));
        Label4->setGeometry(QRect(370, 165, 161, 31));
        Label4->setFont(font1);
        Label8 = new QLabel(centralwidget);
        Label8->setObjectName(QString::fromUtf8("Label8"));
        Label8->setGeometry(QRect(360, 265, 171, 31));
        Label8->setFont(font1);
        ProductNum2 = new QLineEdit(centralwidget);
        ProductNum2->setObjectName(QString::fromUtf8("ProductNum2"));
        ProductNum2->setGeometry(QRect(540, 210, 81, 41));
        ProductNum2->setFont(font2);
        ProductNum2->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductNum2->setAlignment(Qt::AlignCenter);
        ProductNum2->setReadOnly(false);
        Label2 = new QLabel(centralwidget);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(40, 100, 121, 31));
        Label2->setFont(font1);
        Label9 = new QLabel(centralwidget);
        Label9->setObjectName(QString::fromUtf8("Label9"));
        Label9->setGeometry(QRect(40, 325, 291, 31));
        Label9->setFont(font1);
        ProductID = new QTextEdit(centralwidget);
        ProductID->setObjectName(QString::fromUtf8("ProductID"));
        ProductID->setGeometry(QRect(170, 95, 261, 41));
        ProductID->setFont(font2);
        ProductID->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        ProductID->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductID->setReadOnly(false);
        KeepNum1 = new QLineEdit(centralwidget);
        KeepNum1->setObjectName(QString::fromUtf8("KeepNum1"));
        KeepNum1->setGeometry(QRect(240, 260, 81, 41));
        KeepNum1->setFont(font2);
        KeepNum1->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        KeepNum1->setAlignment(Qt::AlignCenter);
        KeepNum1->setReadOnly(false);
        KeepNum2 = new QLineEdit(centralwidget);
        KeepNum2->setObjectName(QString::fromUtf8("KeepNum2"));
        KeepNum2->setGeometry(QRect(540, 260, 91, 41));
        KeepNum2->setFont(font2);
        KeepNum2->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        KeepNum2->setAlignment(Qt::AlignCenter);
        KeepNum2->setReadOnly(false);
        Label3 = new QLabel(centralwidget);
        Label3->setObjectName(QString::fromUtf8("Label3"));
        Label3->setGeometry(QRect(40, 155, 121, 31));
        Label3->setFont(font1);
        KeepNum3 = new QLineEdit(centralwidget);
        KeepNum3->setObjectName(QString::fromUtf8("KeepNum3"));
        KeepNum3->setGeometry(QRect(330, 320, 91, 41));
        KeepNum3->setFont(font2);
        KeepNum3->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        KeepNum3->setAlignment(Qt::AlignCenter);
        KeepNum3->setReadOnly(false);
        OutNum = new QLineEdit(centralwidget);
        OutNum->setObjectName(QString::fromUtf8("OutNum"));
        OutNum->setGeometry(QRect(520, 320, 51, 41));
        OutNum->setFont(font2);
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
        ProductNum1->setGeometry(QRect(540, 160, 81, 41));
        ProductNum1->setFont(font2);
        ProductNum1->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductNum1->setAlignment(Qt::AlignCenter);
        ProductNum1->setReadOnly(false);
        NameButton = new QPushButton(centralwidget);
        NameButton->setObjectName(QString::fromUtf8("NameButton"));
        NameButton->setEnabled(true);
        NameButton->setGeometry(QRect(580, 475, 71, 71));
        sizePolicy1.setHeightForWidth(NameButton->sizePolicy().hasHeightForWidth());
        NameButton->setSizePolicy(sizePolicy1);
        NameButton->setFont(font3);
        NameButton->setCursor(QCursor(Qt::PointingHandCursor));
        NameButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"}\n"
"QPushButton:!enabled {   /*\346\214\211\351\222\256\347\246\201\347\224\250\346\227\266*/\n"
"	background: rgb(100, 100, 100);\n"
"	color: rgb(200, 200, 200);\n"
"}\n"
""));
        NameButton->setIconSize(QSize(20, 20));
        SumoEdit->setCentralWidget(centralwidget);
        Back1->raise();
        Back2->raise();
        EditButton->raise();
        Label13->raise();
        MachineNum->raise();
        MachineComb->raise();
        AddButton->raise();
        DeleButton->raise();
        Label12->raise();
        LogoLabel->raise();
        ProductName->raise();
        Label11->raise();
        LifeNum->raise();
        Label10->raise();
        ProductNum->raise();
        Label5->raise();
        MoldID->raise();
        Label1->raise();
        Label7->raise();
        Label6->raise();
        Label4->raise();
        Label8->raise();
        ProductNum2->raise();
        Label2->raise();
        Label9->raise();
        ProductID->raise();
        KeepNum1->raise();
        KeepNum2->raise();
        Label3->raise();
        KeepNum3->raise();
        OutNum->raise();
        ProductNum1->raise();
        NameButton->raise();
        menubar = new QMenuBar(SumoEdit);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 690, 23));
        SumoEdit->setMenuBar(menubar);
        statusbar = new QStatusBar(SumoEdit);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SumoEdit->setStatusBar(statusbar);
        QWidget::setTabOrder(ProductName, ProductID);
        QWidget::setTabOrder(ProductID, MoldID);
        QWidget::setTabOrder(MoldID, ProductNum);
        QWidget::setTabOrder(ProductNum, ProductNum1);
        QWidget::setTabOrder(ProductNum1, ProductNum2);
        QWidget::setTabOrder(ProductNum2, KeepNum1);
        QWidget::setTabOrder(KeepNum1, KeepNum2);
        QWidget::setTabOrder(KeepNum2, KeepNum3);
        QWidget::setTabOrder(KeepNum3, OutNum);
        QWidget::setTabOrder(OutNum, LifeNum);
        QWidget::setTabOrder(LifeNum, EditButton);
        QWidget::setTabOrder(EditButton, MachineComb);
        QWidget::setTabOrder(MachineComb, MachineNum);
        QWidget::setTabOrder(MachineNum, DeleButton);
        QWidget::setTabOrder(DeleButton, AddButton);
        QWidget::setTabOrder(AddButton, NameButton);

        retranslateUi(SumoEdit);

        QMetaObject::connectSlotsByName(SumoEdit);
    } // setupUi

    void retranslateUi(QMainWindow *SumoEdit)
    {
        SumoEdit->setWindowTitle(QCoreApplication::translate("SumoEdit", "MainWindow", nullptr));
        EditButton->setText(QCoreApplication::translate("SumoEdit", "\344\277\256\346\224\271\345\217\202\346\225\260", nullptr));
        Back1->setText(QString());
        Label13->setText(QCoreApplication::translate("SumoEdit", "\345\242\236\345\212\240\346\234\272\345\217\260:", nullptr));
        MachineNum->setText(QCoreApplication::translate("SumoEdit", "1#", nullptr));
        MachineNum->setPlaceholderText(QCoreApplication::translate("SumoEdit", "#6", nullptr));
        AddButton->setText(QCoreApplication::translate("SumoEdit", "\346\267\273\345\212\240\346\234\272\345\217\260", nullptr));
        Back2->setText(QString());
        DeleButton->setText(QCoreApplication::translate("SumoEdit", "\345\210\240\351\231\244\346\234\272\345\217\260", nullptr));
        Label12->setText(QCoreApplication::translate("SumoEdit", "\345\210\240\351\231\244\346\234\272\345\217\260:", nullptr));
        LogoLabel->setText(QString());
        ProductName->setPlaceholderText(QCoreApplication::translate("SumoEdit", "\350\257\267\350\276\223\345\205\245\344\272\247\345\223\201\345\220\215\347\247\260", nullptr));
        Label11->setText(QCoreApplication::translate("SumoEdit", "\346\250\241\345\205\267\350\256\276\350\256\241\345\257\277\345\221\275:", nullptr));
        LifeNum->setText(QString());
        Label10->setText(QCoreApplication::translate("SumoEdit", "\347\251\264\346\225\260:", nullptr));
        ProductNum->setPlaceholderText(QCoreApplication::translate("SumoEdit", "\346\240\207\345\207\206\344\272\247\351\207\217(k/24H)", nullptr));
        Label5->setText(QCoreApplication::translate("SumoEdit", "\346\240\207\345\207\206\344\272\247\351\207\217:", nullptr));
        MoldID->setPlaceholderText(QCoreApplication::translate("SumoEdit", "\350\257\267\350\276\223\345\205\245\346\250\241\345\205\267\347\274\226\345\217\267", nullptr));
        Label1->setText(QCoreApplication::translate("SumoEdit", "\344\272\247\345\223\201\345\220\215\347\247\260:", nullptr));
        Label7->setText(QCoreApplication::translate("SumoEdit", "\345\256\232\346\234\237\344\277\235\345\205\273\346\250\241\346\254\241\346\225\260:", nullptr));
        Label6->setText(QCoreApplication::translate("SumoEdit", "\345\211\251\344\275\231\350\256\242\345\215\225\346\225\2602:", nullptr));
        Label4->setText(QCoreApplication::translate("SumoEdit", "\345\211\251\344\275\231\350\256\242\345\215\225\346\225\2601:", nullptr));
        Label8->setText(QCoreApplication::translate("SumoEdit", "\345\244\247\344\277\235\345\205\273\346\250\241\346\254\241\346\225\260:", nullptr));
        ProductNum2->setText(QString());
        Label2->setText(QCoreApplication::translate("SumoEdit", "\344\272\247\345\223\201\346\226\231\345\217\267:", nullptr));
        Label9->setText(QCoreApplication::translate("SumoEdit", "\347\211\271\345\256\232\346\230\223\346\215\237\344\273\266\347\256\241\345\210\266\346\250\241\346\254\241\346\225\260:", nullptr));
        ProductID->setPlaceholderText(QCoreApplication::translate("SumoEdit", "\350\257\267\350\276\223\345\205\245\344\272\247\345\223\201\346\226\231\345\217\267", nullptr));
        KeepNum1->setText(QString());
        KeepNum2->setText(QString());
        Label3->setText(QCoreApplication::translate("SumoEdit", "\346\250\241\345\205\267\347\274\226\345\217\267:", nullptr));
        KeepNum3->setText(QString());
        OutNum->setText(QString());
        ProductNum1->setText(QString());
        NameButton->setText(QCoreApplication::translate("SumoEdit", "\346\267\273\345\212\240\n"
"\345\221\230\345\267\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SumoEdit: public Ui_SumoEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUMOEDIT_H
