/********************************************************************************
** Form generated from reading UI file 'chonyaedit.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHONYAEDIT_H
#define UI_CHONYAEDIT_H

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

class Ui_ChonyaEdit
{
public:
    QWidget *centralwidget;
    QPushButton *EditButton;
    QLabel *Label2;
    QLabel *Label7;
    QLineEdit *LifeNum;
    QLabel *Label5;
    QLabel *Label3;
    QLineEdit *OutNum_2;
    QLabel *Label8;
    QLabel *Label4;
    QLabel *LoadingLabel;
    QLineEdit *ProductStand;
    QLineEdit *MoldID;
    QLineEdit *OutNum_1;
    QComboBox *ControlStand;
    QLabel *Label6;
    QLabel *Label1;
    QTextEdit *ProductName;
    QTextEdit *ProductID;
    QLabel *Back1;
    QLabel *Label9;
    QLineEdit *MachineNum;
    QComboBox *MachineComb;
    QPushButton *AddButton;
    QLabel *Back2;
    QPushButton *DeleButton;
    QLabel *Label10;
    QLabel *LogoLabel;
    QPushButton *NameButton;
    QLabel *Label10_2;
    QComboBox *NameComb;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChonyaEdit)
    {
        if (ChonyaEdit->objectName().isEmpty())
            ChonyaEdit->setObjectName(QString::fromUtf8("ChonyaEdit"));
        ChonyaEdit->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChonyaEdit->sizePolicy().hasHeightForWidth());
        ChonyaEdit->setSizePolicy(sizePolicy);
        ChonyaEdit->setMinimumSize(QSize(800, 600));
        ChonyaEdit->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(ChonyaEdit);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        EditButton = new QPushButton(centralwidget);
        EditButton->setObjectName(QString::fromUtf8("EditButton"));
        EditButton->setEnabled(true);
        EditButton->setGeometry(QRect(570, 300, 131, 61));
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
        Label2 = new QLabel(centralwidget);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(100, 190, 121, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(20);
        Label2->setFont(font1);
        Label7 = new QLabel(centralwidget);
        Label7->setObjectName(QString::fromUtf8("Label7"));
        Label7->setGeometry(QRect(280, 380, 56, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(24);
        font2.setBold(false);
        font2.setWeight(50);
        Label7->setFont(font2);
        Label7->setAlignment(Qt::AlignCenter);
        LifeNum = new QLineEdit(centralwidget);
        LifeNum->setObjectName(QString::fromUtf8("LifeNum"));
        LifeNum->setGeometry(QRect(620, 380, 71, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(16);
        LifeNum->setFont(font3);
        LifeNum->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        LifeNum->setAlignment(Qt::AlignCenter);
        LifeNum->setReadOnly(false);
        Label5 = new QLabel(centralwidget);
        Label5->setObjectName(QString::fromUtf8("Label5"));
        Label5->setGeometry(QRect(100, 35, 121, 31));
        Label5->setFont(font1);
        Label3 = new QLabel(centralwidget);
        Label3->setObjectName(QString::fromUtf8("Label3"));
        Label3->setGeometry(QRect(100, 265, 121, 31));
        Label3->setFont(font1);
        OutNum_2 = new QLineEdit(centralwidget);
        OutNum_2->setObjectName(QString::fromUtf8("OutNum_2"));
        OutNum_2->setGeometry(QRect(335, 380, 51, 41));
        OutNum_2->setFont(font3);
        OutNum_2->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        OutNum_2->setAlignment(Qt::AlignCenter);
        OutNum_2->setReadOnly(false);
        Label8 = new QLabel(centralwidget);
        Label8->setObjectName(QString::fromUtf8("Label8"));
        Label8->setGeometry(QRect(410, 385, 201, 31));
        Label8->setFont(font1);
        Label4 = new QLabel(centralwidget);
        Label4->setObjectName(QString::fromUtf8("Label4"));
        Label4->setGeometry(QRect(100, 325, 121, 31));
        Label4->setFont(font1);
        LoadingLabel = new QLabel(centralwidget);
        LoadingLabel->setObjectName(QString::fromUtf8("LoadingLabel"));
        LoadingLabel->setGeometry(QRect(560, 90, 200, 200));
        LoadingLabel->setLayoutDirection(Qt::LeftToRight);
        ProductStand = new QLineEdit(centralwidget);
        ProductStand->setObjectName(QString::fromUtf8("ProductStand"));
        ProductStand->setGeometry(QRect(230, 260, 281, 41));
        ProductStand->setFont(font3);
        ProductStand->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductStand->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        ProductStand->setReadOnly(false);
        MoldID = new QLineEdit(centralwidget);
        MoldID->setObjectName(QString::fromUtf8("MoldID"));
        MoldID->setGeometry(QRect(230, 30, 261, 41));
        MoldID->setFont(font3);
        MoldID->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MoldID->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        MoldID->setReadOnly(true);
        OutNum_1 = new QLineEdit(centralwidget);
        OutNum_1->setObjectName(QString::fromUtf8("OutNum_1"));
        OutNum_1->setGeometry(QRect(230, 380, 51, 41));
        OutNum_1->setFont(font3);
        OutNum_1->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        OutNum_1->setAlignment(Qt::AlignCenter);
        OutNum_1->setReadOnly(false);
        ControlStand = new QComboBox(centralwidget);
        ControlStand->addItem(QString());
        ControlStand->addItem(QString());
        ControlStand->addItem(QString());
        ControlStand->addItem(QString());
        ControlStand->addItem(QString());
        ControlStand->addItem(QString());
        ControlStand->setObjectName(QString::fromUtf8("ControlStand"));
        ControlStand->setGeometry(QRect(230, 320, 306, 41));
        ControlStand->setFont(font3);
        ControlStand->setCursor(QCursor(Qt::ArrowCursor));
        ControlStand->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        Label6 = new QLabel(centralwidget);
        Label6->setObjectName(QString::fromUtf8("Label6"));
        Label6->setGeometry(QRect(100, 385, 121, 31));
        Label6->setFont(font1);
        Label1 = new QLabel(centralwidget);
        Label1->setObjectName(QString::fromUtf8("Label1"));
        Label1->setGeometry(QRect(100, 110, 121, 31));
        sizePolicy1.setHeightForWidth(Label1->sizePolicy().hasHeightForWidth());
        Label1->setSizePolicy(sizePolicy1);
        Label1->setFont(font1);
        Label1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Label1->setWordWrap(false);
        ProductName = new QTextEdit(centralwidget);
        ProductName->setObjectName(QString::fromUtf8("ProductName"));
        ProductName->setGeometry(QRect(230, 95, 261, 61));
        ProductName->setFont(font3);
        ProductName->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        ProductName->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductName->setReadOnly(false);
        ProductID = new QTextEdit(centralwidget);
        ProductID->setObjectName(QString::fromUtf8("ProductID"));
        ProductID->setGeometry(QRect(230, 180, 261, 61));
        ProductID->setFont(font3);
        ProductID->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        ProductID->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductID->setReadOnly(false);
        Back1 = new QLabel(centralwidget);
        Back1->setObjectName(QString::fromUtf8("Back1"));
        Back1->setGeometry(QRect(0, 0, 801, 446));
        Back1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"border-style: outset;"));
        Label9 = new QLabel(centralwidget);
        Label9->setObjectName(QString::fromUtf8("Label9"));
        Label9->setGeometry(QRect(290, 465, 121, 31));
        Label9->setFont(font1);
        MachineNum = new QLineEdit(centralwidget);
        MachineNum->setObjectName(QString::fromUtf8("MachineNum"));
        MachineNum->setGeometry(QRect(420, 460, 101, 41));
        MachineNum->setFont(font3);
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
        MachineComb->setGeometry(QRect(160, 460, 101, 41));
        MachineComb->setFont(font3);
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
        AddButton->setGeometry(QRect(399, 515, 121, 51));
        sizePolicy1.setHeightForWidth(AddButton->sizePolicy().hasHeightForWidth());
        AddButton->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        AddButton->setFont(font4);
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
        Back2->setGeometry(QRect(0, 445, 801, 131));
        Back2->setStyleSheet(QString::fromUtf8("background-color: rgb(160, 175, 200);\n"
"border-radius: 10px;\n"
"border-style: outset;"));
        DeleButton = new QPushButton(centralwidget);
        DeleButton->setObjectName(QString::fromUtf8("DeleButton"));
        DeleButton->setEnabled(true);
        DeleButton->setGeometry(QRect(139, 515, 121, 51));
        sizePolicy1.setHeightForWidth(DeleButton->sizePolicy().hasHeightForWidth());
        DeleButton->setSizePolicy(sizePolicy1);
        DeleButton->setFont(font4);
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
        Label10 = new QLabel(centralwidget);
        Label10->setObjectName(QString::fromUtf8("Label10"));
        Label10->setGeometry(QRect(30, 465, 121, 31));
        Label10->setFont(font1);
        LogoLabel = new QLabel(centralwidget);
        LogoLabel->setObjectName(QString::fromUtf8("LogoLabel"));
        LogoLabel->setGeometry(QRect(590, 10, 200, 53));
        LogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/logo200x53.jpg")));
        NameButton = new QPushButton(centralwidget);
        NameButton->setObjectName(QString::fromUtf8("NameButton"));
        NameButton->setEnabled(true);
        NameButton->setGeometry(QRect(659, 515, 121, 51));
        sizePolicy1.setHeightForWidth(NameButton->sizePolicy().hasHeightForWidth());
        NameButton->setSizePolicy(sizePolicy1);
        NameButton->setFont(font4);
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
        NameButton->setIcon(icon2);
        NameButton->setIconSize(QSize(20, 20));
        Label10_2 = new QLabel(centralwidget);
        Label10_2->setObjectName(QString::fromUtf8("Label10_2"));
        Label10_2->setGeometry(QRect(550, 465, 121, 31));
        Label10_2->setFont(font1);
        NameComb = new QComboBox(centralwidget);
        NameComb->setObjectName(QString::fromUtf8("NameComb"));
        NameComb->setGeometry(QRect(680, 460, 101, 41));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(18);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        NameComb->setFont(font5);
        NameComb->setCursor(QCursor(Qt::ArrowCursor));
        NameComb->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        NameComb->setEditable(true);
        ChonyaEdit->setCentralWidget(centralwidget);
        Back2->raise();
        Back1->raise();
        EditButton->raise();
        Label2->raise();
        Label7->raise();
        LifeNum->raise();
        Label5->raise();
        Label3->raise();
        OutNum_2->raise();
        Label8->raise();
        Label4->raise();
        LoadingLabel->raise();
        ProductStand->raise();
        MoldID->raise();
        OutNum_1->raise();
        ControlStand->raise();
        Label6->raise();
        Label1->raise();
        ProductName->raise();
        ProductID->raise();
        Label9->raise();
        MachineNum->raise();
        MachineComb->raise();
        AddButton->raise();
        DeleButton->raise();
        Label10->raise();
        LogoLabel->raise();
        NameButton->raise();
        Label10_2->raise();
        NameComb->raise();
        menubar = new QMenuBar(ChonyaEdit);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        ChonyaEdit->setMenuBar(menubar);
        statusbar = new QStatusBar(ChonyaEdit);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ChonyaEdit->setStatusBar(statusbar);
        QWidget::setTabOrder(MoldID, ProductName);
        QWidget::setTabOrder(ProductName, ProductID);
        QWidget::setTabOrder(ProductID, ProductStand);
        QWidget::setTabOrder(ProductStand, ControlStand);
        QWidget::setTabOrder(ControlStand, OutNum_1);
        QWidget::setTabOrder(OutNum_1, OutNum_2);
        QWidget::setTabOrder(OutNum_2, LifeNum);
        QWidget::setTabOrder(LifeNum, EditButton);
        QWidget::setTabOrder(EditButton, MachineComb);
        QWidget::setTabOrder(MachineComb, MachineNum);
        QWidget::setTabOrder(MachineNum, NameComb);
        QWidget::setTabOrder(NameComb, DeleButton);
        QWidget::setTabOrder(DeleButton, AddButton);
        QWidget::setTabOrder(AddButton, NameButton);

        retranslateUi(ChonyaEdit);

        QMetaObject::connectSlotsByName(ChonyaEdit);
    } // setupUi

    void retranslateUi(QMainWindow *ChonyaEdit)
    {
        ChonyaEdit->setWindowTitle(QCoreApplication::translate("ChonyaEdit", "MainWindow", nullptr));
        EditButton->setText(QCoreApplication::translate("ChonyaEdit", "\344\277\256\346\224\271\345\217\202\346\225\260", nullptr));
        Label2->setText(QCoreApplication::translate("ChonyaEdit", "\344\272\247\345\223\201\346\226\231\345\217\267:", nullptr));
        Label7->setText(QCoreApplication::translate("ChonyaEdit", "*", nullptr));
        Label5->setText(QCoreApplication::translate("ChonyaEdit", "\346\250\241\345\205\267\347\274\226\345\217\267:", nullptr));
        Label3->setText(QCoreApplication::translate("ChonyaEdit", "\346\235\220\346\226\231\350\247\204\346\240\274:", nullptr));
        Label8->setText(QCoreApplication::translate("ChonyaEdit", "\346\250\241\345\205\267\345\257\277\345\221\275\345\206\262\346\254\241\346\225\260:", nullptr));
        Label4->setText(QCoreApplication::translate("ChonyaEdit", "\347\256\241\345\210\266\346\240\207\345\207\206:", nullptr));
        LoadingLabel->setText(QString());
        ProductStand->setPlaceholderText(QCoreApplication::translate("ChonyaEdit", "\350\257\267\350\276\223\345\205\245\346\235\220\346\226\231\350\247\204\346\240\274", nullptr));
        MoldID->setPlaceholderText(QCoreApplication::translate("ChonyaEdit", "\350\257\267\350\276\223\345\205\245\346\250\241\345\205\267\347\274\226\345\217\267", nullptr));
        ControlStand->setItemText(0, QCoreApplication::translate("ChonyaEdit", "NULL", nullptr));
        ControlStand->setItemText(1, QCoreApplication::translate("ChonyaEdit", "\351\223\234\346\235\220\346\235\220\346\226\231\345\216\232\345\272\246\350\247\204\346\240\274\357\274\2340.3mm", nullptr));
        ControlStand->setItemText(2, QCoreApplication::translate("ChonyaEdit", "\351\223\234\346\235\220\346\235\220\346\226\231\345\216\232\345\272\246\350\247\204\346\240\274\342\211\2470.3\344\270\224\357\271\2440.5mm", nullptr));
        ControlStand->setItemText(3, QCoreApplication::translate("ChonyaEdit", "\351\223\234\346\235\220\346\235\220\346\226\231\345\216\232\345\272\246\350\247\204\346\240\274\342\211\2470.5mm", nullptr));
        ControlStand->setItemText(4, QCoreApplication::translate("ChonyaEdit", "\344\270\215\351\224\210\351\222\242\346\235\220\346\226\231\345\216\232\345\272\246\350\247\204\346\240\274\357\274\2340.5mm", nullptr));
        ControlStand->setItemText(5, QCoreApplication::translate("ChonyaEdit", "\344\270\215\351\224\210\351\222\242\346\235\220\346\226\231\345\216\232\345\272\246\350\247\204\346\240\274\342\211\2470.5mm", nullptr));

        Label6->setText(QCoreApplication::translate("ChonyaEdit", "\344\272\247\345\223\201\345\207\272\346\225\260:", nullptr));
        Label1->setText(QCoreApplication::translate("ChonyaEdit", "\344\272\247\345\223\201\345\220\215\347\247\260:", nullptr));
        ProductName->setPlaceholderText(QCoreApplication::translate("ChonyaEdit", "\350\257\267\350\276\223\345\205\245\344\272\247\345\223\201\345\220\215\347\247\260", nullptr));
        ProductID->setPlaceholderText(QCoreApplication::translate("ChonyaEdit", "\350\257\267\350\276\223\345\205\245\344\272\247\345\223\201\346\226\231\345\217\267", nullptr));
        Back1->setText(QString());
        Label9->setText(QCoreApplication::translate("ChonyaEdit", "\345\242\236\345\212\240\346\234\272\345\217\260:", nullptr));
        MachineNum->setText(QCoreApplication::translate("ChonyaEdit", "1#", nullptr));
        MachineNum->setPlaceholderText(QCoreApplication::translate("ChonyaEdit", "#6", nullptr));
        AddButton->setText(QCoreApplication::translate("ChonyaEdit", "\346\267\273\345\212\240\346\234\272\345\217\260", nullptr));
        Back2->setText(QString());
        DeleButton->setText(QCoreApplication::translate("ChonyaEdit", "\345\210\240\351\231\244\346\234\272\345\217\260", nullptr));
        Label10->setText(QCoreApplication::translate("ChonyaEdit", "\345\210\240\351\231\244\346\234\272\345\217\260:", nullptr));
        LogoLabel->setText(QString());
        NameButton->setText(QCoreApplication::translate("ChonyaEdit", "\345\210\240\351\231\244\345\221\230\345\267\245", nullptr));
        Label10_2->setText(QCoreApplication::translate("ChonyaEdit", "\345\210\240\351\231\244\345\221\230\345\267\245:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChonyaEdit: public Ui_ChonyaEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHONYAEDIT_H
