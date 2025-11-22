/********************************************************************************
** Form generated from reading UI file 'chonyaenter.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHONYAENTER_H
#define UI_CHONYAENTER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChonyaEnter
{
public:
    QWidget *centralwidget;
    QLabel *Label12;
    QPushButton *PlotButton;
    QComboBox *DirRepair;
    QComboBox *Operater;
    QLabel *Label11;
    QListView *MachineView;
    QLabel *Label18;
    QLineEdit *ProductTime;
    QLineEdit *ProductNum;
    QLabel *Label9;
    QPushButton *EnterButton;
    QLabel *LogoLabel;
    QLabel *BackGround;
    QLabel *Label2;
    QLabel *Label10;
    QPushButton *ReturnButton;
    QPushButton *GetButton;
    QLabel *Label1_1;
    QLineEdit *MachineNum_2;
    QComboBox *MoldCombo;
    QLabel *Label8;
    QComboBox *DirRepair_2;
    QLineEdit *ProductNum_2;
    QLabel *Label15;
    QLabel *Label16;
    QComboBox *Operater_2;
    QLabel *Label17;
    QLabel *Label14;
    QLabel *Label13;
    QTextEdit *ProductID;
    QLabel *Label0_1;
    QTabWidget *tabWidget;
    QWidget *Tab1;
    QLabel *PercentLabel1_1;
    QLabel *PercentLabel3_1;
    QLabel *Label3_1;
    QLabel *Label4_1;
    QLabel *MachineNum;
    QLabel *Label6_1;
    QLabel *PercentLabel2_1;
    QLabel *PercentLabel4_1;
    QLabel *Label5_1;
    QLabel *Label7_1;
    QPushButton *NewButton;
    QWidget *Tab2;
    QLabel *PercentLabel2_2;
    QLabel *Label6_2;
    QLabel *PercentLabel3_2;
    QLabel *Label5_2;
    QLabel *PercentLabel1_2;
    QLabel *Label4_2;
    QLabel *PercentLabel2_3;
    QLineEdit *UserEdit;
    QLabel *Label1_2;
    QLabel *Label0_2;
    QLineEdit *OutNum;
    QPushButton *CheckButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChonyaEnter)
    {
        if (ChonyaEnter->objectName().isEmpty())
            ChonyaEnter->setObjectName(QString::fromUtf8("ChonyaEnter"));
        ChonyaEnter->resize(760, 640);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChonyaEnter->sizePolicy().hasHeightForWidth());
        ChonyaEnter->setSizePolicy(sizePolicy);
        ChonyaEnter->setMinimumSize(QSize(760, 640));
        ChonyaEnter->setMaximumSize(QSize(760, 640));
        centralwidget = new QWidget(ChonyaEnter);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Label12 = new QLabel(centralwidget);
        Label12->setObjectName(QString::fromUtf8("Label12"));
        Label12->setGeometry(QRect(549, 400, 61, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(18);
        Label12->setFont(font);
        PlotButton = new QPushButton(centralwidget);
        PlotButton->setObjectName(QString::fromUtf8("PlotButton"));
        PlotButton->setGeometry(QRect(575, 5, 181, 46));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setWeight(50);
        PlotButton->setFont(font1);
        PlotButton->setCursor(QCursor(Qt::PointingHandCursor));
        PlotButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/plot.png"), QSize(), QIcon::Normal, QIcon::Off);
        PlotButton->setIcon(icon);
        PlotButton->setIconSize(QSize(30, 30));
        DirRepair = new QComboBox(centralwidget);
        DirRepair->setObjectName(QString::fromUtf8("DirRepair"));
        DirRepair->setGeometry(QRect(610, 400, 101, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        DirRepair->setFont(font2);
        DirRepair->setCursor(QCursor(Qt::ArrowCursor));
        DirRepair->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        DirRepair->setEditable(true);
        Operater = new QComboBox(centralwidget);
        Operater->setObjectName(QString::fromUtf8("Operater"));
        Operater->setGeometry(QRect(425, 400, 111, 41));
        Operater->setFont(font2);
        Operater->setCursor(QCursor(Qt::ArrowCursor));
        Operater->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        Operater->setEditable(true);
        Label11 = new QLabel(centralwidget);
        Label11->setObjectName(QString::fromUtf8("Label11"));
        Label11->setGeometry(QRect(340, 400, 91, 41));
        Label11->setFont(font);
        MachineView = new QListView(centralwidget);
        MachineView->setObjectName(QString::fromUtf8("MachineView"));
        MachineView->setGeometry(QRect(70, 360, 211, 181));
        MachineView->setFont(font);
        MachineView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        MachineView->setMouseTracking(false);
        MachineView->setStyleSheet(QString::fromUtf8("QListView{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MachineView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Label18 = new QLabel(centralwidget);
        Label18->setObjectName(QString::fromUtf8("Label18"));
        Label18->setGeometry(QRect(70, 560, 61, 41));
        Label18->setFont(font);
        ProductTime = new QLineEdit(centralwidget);
        ProductTime->setObjectName(QString::fromUtf8("ProductTime"));
        ProductTime->setGeometry(QRect(130, 560, 151, 41));
        ProductTime->setFont(font);
        ProductTime->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductTime->setAlignment(Qt::AlignCenter);
        ProductTime->setReadOnly(false);
        ProductNum = new QLineEdit(centralwidget);
        ProductNum->setObjectName(QString::fromUtf8("ProductNum"));
        ProductNum->setGeometry(QRect(480, 350, 71, 41));
        ProductNum->setFont(font);
        ProductNum->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductNum->setAlignment(Qt::AlignCenter);
        ProductNum->setReadOnly(false);
        Label9 = new QLabel(centralwidget);
        Label9->setObjectName(QString::fromUtf8("Label9"));
        Label9->setGeometry(QRect(420, 350, 61, 41));
        Label9->setFont(font);
        EnterButton = new QPushButton(centralwidget);
        EnterButton->setObjectName(QString::fromUtf8("EnterButton"));
        EnterButton->setGeometry(QRect(575, 560, 141, 46));
        EnterButton->setFont(font1);
        EnterButton->setCursor(QCursor(Qt::PointingHandCursor));
        EnterButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/enter.png"), QSize(), QIcon::Normal, QIcon::Off);
        EnterButton->setIcon(icon1);
        EnterButton->setIconSize(QSize(20, 20));
        LogoLabel = new QLabel(centralwidget);
        LogoLabel->setObjectName(QString::fromUtf8("LogoLabel"));
        LogoLabel->setGeometry(QRect(10, 10, 200, 53));
        LogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/logo200x53.jpg")));
        BackGround = new QLabel(centralwidget);
        BackGround->setObjectName(QString::fromUtf8("BackGround"));
        BackGround->setGeometry(QRect(0, 0, 761, 641));
        BackGround->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Label2 = new QLabel(centralwidget);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(70, 320, 101, 41));
        Label2->setFont(font);
        Label10 = new QLabel(centralwidget);
        Label10->setObjectName(QString::fromUtf8("Label10"));
        Label10->setGeometry(QRect(555, 350, 61, 41));
        Label10->setFont(font);
        ReturnButton = new QPushButton(centralwidget);
        ReturnButton->setObjectName(QString::fromUtf8("ReturnButton"));
        ReturnButton->setGeometry(QRect(350, 560, 191, 46));
        ReturnButton->setFont(font1);
        ReturnButton->setCursor(QCursor(Qt::PointingHandCursor));
        ReturnButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/return.png"), QSize(), QIcon::Normal, QIcon::Off);
        ReturnButton->setIcon(icon2);
        ReturnButton->setIconSize(QSize(25, 25));
        GetButton = new QPushButton(centralwidget);
        GetButton->setObjectName(QString::fromUtf8("GetButton"));
        GetButton->setGeometry(QRect(690, 55, 51, 51));
        GetButton->setFont(font1);
        GetButton->setCursor(QCursor(Qt::PointingHandCursor));
        GetButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/data.png"), QSize(), QIcon::Normal, QIcon::Off);
        GetButton->setIcon(icon3);
        GetButton->setIconSize(QSize(30, 30));
        Label1_1 = new QLabel(centralwidget);
        Label1_1->setObjectName(QString::fromUtf8("Label1_1"));
        Label1_1->setGeometry(QRect(70, 235, 111, 31));
        Label1_1->setFont(font1);
        MachineNum_2 = new QLineEdit(centralwidget);
        MachineNum_2->setObjectName(QString::fromUtf8("MachineNum_2"));
        MachineNum_2->setGeometry(QRect(180, 230, 101, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(16);
        MachineNum_2->setFont(font3);
        MachineNum_2->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MachineNum_2->setAlignment(Qt::AlignCenter);
        MachineNum_2->setReadOnly(false);
        MoldCombo = new QComboBox(centralwidget);
        MoldCombo->setObjectName(QString::fromUtf8("MoldCombo"));
        MoldCombo->setGeometry(QRect(320, 60, 351, 41));
        MoldCombo->setFont(font2);
        MoldCombo->setCursor(QCursor(Qt::ArrowCursor));
        MoldCombo->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        MoldCombo->setEditable(true);
        Label8 = new QLabel(centralwidget);
        Label8->setObjectName(QString::fromUtf8("Label8"));
        Label8->setGeometry(QRect(350, 350, 61, 41));
        Label8->setFont(font);
        Label8->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);"));
        DirRepair_2 = new QComboBox(centralwidget);
        DirRepair_2->setObjectName(QString::fromUtf8("DirRepair_2"));
        DirRepair_2->setGeometry(QRect(610, 510, 101, 41));
        DirRepair_2->setFont(font2);
        DirRepair_2->setCursor(QCursor(Qt::ArrowCursor));
        DirRepair_2->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        DirRepair_2->setEditable(true);
        ProductNum_2 = new QLineEdit(centralwidget);
        ProductNum_2->setObjectName(QString::fromUtf8("ProductNum_2"));
        ProductNum_2->setGeometry(QRect(480, 460, 71, 41));
        ProductNum_2->setFont(font);
        ProductNum_2->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductNum_2->setAlignment(Qt::AlignCenter);
        ProductNum_2->setReadOnly(false);
        Label15 = new QLabel(centralwidget);
        Label15->setObjectName(QString::fromUtf8("Label15"));
        Label15->setGeometry(QRect(555, 460, 61, 41));
        Label15->setFont(font);
        Label16 = new QLabel(centralwidget);
        Label16->setObjectName(QString::fromUtf8("Label16"));
        Label16->setGeometry(QRect(340, 510, 91, 41));
        Label16->setFont(font);
        Operater_2 = new QComboBox(centralwidget);
        Operater_2->setObjectName(QString::fromUtf8("Operater_2"));
        Operater_2->setGeometry(QRect(425, 510, 111, 41));
        Operater_2->setFont(font2);
        Operater_2->setCursor(QCursor(Qt::ArrowCursor));
        Operater_2->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        Operater_2->setEditable(true);
        Label17 = new QLabel(centralwidget);
        Label17->setObjectName(QString::fromUtf8("Label17"));
        Label17->setGeometry(QRect(549, 510, 61, 41));
        Label17->setFont(font);
        Label14 = new QLabel(centralwidget);
        Label14->setObjectName(QString::fromUtf8("Label14"));
        Label14->setGeometry(QRect(420, 460, 61, 41));
        Label14->setFont(font);
        Label13 = new QLabel(centralwidget);
        Label13->setObjectName(QString::fromUtf8("Label13"));
        Label13->setGeometry(QRect(350, 460, 61, 41));
        Label13->setFont(font);
        Label13->setStyleSheet(QString::fromUtf8("color: rgb(170, 170, 255);"));
        ProductID = new QTextEdit(centralwidget);
        ProductID->setObjectName(QString::fromUtf8("ProductID"));
        ProductID->setGeometry(QRect(70, 100, 211, 71));
        ProductID->setFont(font);
        ProductID->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        ProductID->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductID->setReadOnly(true);
        Label0_1 = new QLabel(centralwidget);
        Label0_1->setObjectName(QString::fromUtf8("Label0_1"));
        Label0_1->setGeometry(QRect(70, 65, 111, 31));
        Label0_1->setFont(font);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(299, 110, 441, 231));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        tabWidget->setFont(font4);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Tab1 = new QWidget();
        Tab1->setObjectName(QString::fromUtf8("Tab1"));
        PercentLabel1_1 = new QLabel(Tab1);
        PercentLabel1_1->setObjectName(QString::fromUtf8("PercentLabel1_1"));
        PercentLabel1_1->setGeometry(QRect(220, 45, 141, 31));
        PercentLabel1_1->setFont(font);
        PercentLabel3_1 = new QLabel(Tab1);
        PercentLabel3_1->setObjectName(QString::fromUtf8("PercentLabel3_1"));
        PercentLabel3_1->setGeometry(QRect(220, 125, 141, 31));
        PercentLabel3_1->setFont(font);
        Label3_1 = new QLabel(Tab1);
        Label3_1->setObjectName(QString::fromUtf8("Label3_1"));
        Label3_1->setGeometry(QRect(10, 5, 111, 31));
        Label3_1->setFont(font);
        Label4_1 = new QLabel(Tab1);
        Label4_1->setObjectName(QString::fromUtf8("Label4_1"));
        Label4_1->setGeometry(QRect(10, 40, 201, 41));
        Label4_1->setFont(font);
        MachineNum = new QLabel(Tab1);
        MachineNum->setObjectName(QString::fromUtf8("MachineNum"));
        MachineNum->setGeometry(QRect(120, 5, 61, 31));
        MachineNum->setFont(font);
        Label6_1 = new QLabel(Tab1);
        Label6_1->setObjectName(QString::fromUtf8("Label6_1"));
        Label6_1->setGeometry(QRect(10, 120, 201, 41));
        Label6_1->setFont(font);
        PercentLabel2_1 = new QLabel(Tab1);
        PercentLabel2_1->setObjectName(QString::fromUtf8("PercentLabel2_1"));
        PercentLabel2_1->setGeometry(QRect(270, 85, 141, 31));
        PercentLabel2_1->setFont(font);
        PercentLabel4_1 = new QLabel(Tab1);
        PercentLabel4_1->setObjectName(QString::fromUtf8("PercentLabel4_1"));
        PercentLabel4_1->setGeometry(QRect(220, 165, 141, 31));
        PercentLabel4_1->setFont(font);
        Label5_1 = new QLabel(Tab1);
        Label5_1->setObjectName(QString::fromUtf8("Label5_1"));
        Label5_1->setGeometry(QRect(10, 80, 251, 41));
        Label5_1->setFont(font);
        Label7_1 = new QLabel(Tab1);
        Label7_1->setObjectName(QString::fromUtf8("Label7_1"));
        Label7_1->setGeometry(QRect(10, 160, 201, 41));
        Label7_1->setFont(font);
        NewButton = new QPushButton(Tab1);
        NewButton->setObjectName(QString::fromUtf8("NewButton"));
        NewButton->setGeometry(QRect(370, 155, 66, 46));
        NewButton->setFont(font1);
        NewButton->setCursor(QCursor(Qt::PointingHandCursor));
        NewButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        NewButton->setIconSize(QSize(20, 20));
        tabWidget->addTab(Tab1, QString());
        Tab2 = new QWidget();
        Tab2->setObjectName(QString::fromUtf8("Tab2"));
        PercentLabel2_2 = new QLabel(Tab2);
        PercentLabel2_2->setObjectName(QString::fromUtf8("PercentLabel2_2"));
        PercentLabel2_2->setGeometry(QRect(220, 55, 201, 31));
        PercentLabel2_2->setFont(font);
        Label6_2 = new QLabel(Tab2);
        Label6_2->setObjectName(QString::fromUtf8("Label6_2"));
        Label6_2->setGeometry(QRect(10, 145, 181, 41));
        Label6_2->setFont(font);
        PercentLabel3_2 = new QLabel(Tab2);
        PercentLabel3_2->setObjectName(QString::fromUtf8("PercentLabel3_2"));
        PercentLabel3_2->setGeometry(QRect(200, 150, 101, 31));
        PercentLabel3_2->setFont(font);
        Label5_2 = new QLabel(Tab2);
        Label5_2->setObjectName(QString::fromUtf8("Label5_2"));
        Label5_2->setGeometry(QRect(10, 50, 201, 41));
        Label5_2->setFont(font);
        PercentLabel1_2 = new QLabel(Tab2);
        PercentLabel1_2->setObjectName(QString::fromUtf8("PercentLabel1_2"));
        PercentLabel1_2->setGeometry(QRect(220, 10, 101, 31));
        PercentLabel1_2->setFont(font);
        Label4_2 = new QLabel(Tab2);
        Label4_2->setObjectName(QString::fromUtf8("Label4_2"));
        Label4_2->setGeometry(QRect(10, 5, 201, 41));
        Label4_2->setFont(font);
        PercentLabel2_3 = new QLabel(Tab2);
        PercentLabel2_3->setObjectName(QString::fromUtf8("PercentLabel2_3"));
        PercentLabel2_3->setGeometry(QRect(55, 100, 361, 31));
        PercentLabel2_3->setFont(font);
        tabWidget->addTab(Tab2, QString());
        UserEdit = new QLineEdit(centralwidget);
        UserEdit->setObjectName(QString::fromUtf8("UserEdit"));
        UserEdit->setGeometry(QRect(180, 280, 101, 41));
        UserEdit->setFont(font3);
        UserEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        UserEdit->setAlignment(Qt::AlignCenter);
        UserEdit->setReadOnly(false);
        Label1_2 = new QLabel(centralwidget);
        Label1_2->setObjectName(QString::fromUtf8("Label1_2"));
        Label1_2->setGeometry(QRect(70, 285, 111, 31));
        Label1_2->setFont(font1);
        Label0_2 = new QLabel(centralwidget);
        Label0_2->setObjectName(QString::fromUtf8("Label0_2"));
        Label0_2->setGeometry(QRect(70, 185, 111, 31));
        Label0_2->setFont(font);
        OutNum = new QLineEdit(centralwidget);
        OutNum->setObjectName(QString::fromUtf8("OutNum"));
        OutNum->setGeometry(QRect(180, 180, 101, 41));
        OutNum->setFont(font3);
        OutNum->setCursor(QCursor(Qt::ArrowCursor));
        OutNum->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        OutNum->setAlignment(Qt::AlignCenter);
        OutNum->setReadOnly(true);
        CheckButton = new QPushButton(centralwidget);
        CheckButton->setObjectName(QString::fromUtf8("CheckButton"));
        CheckButton->setGeometry(QRect(450, 5, 111, 46));
        CheckButton->setFont(font1);
        CheckButton->setCursor(QCursor(Qt::PointingHandCursor));
        CheckButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        CheckButton->setIconSize(QSize(30, 30));
        ChonyaEnter->setCentralWidget(centralwidget);
        BackGround->raise();
        Label12->raise();
        PlotButton->raise();
        DirRepair->raise();
        Operater->raise();
        Label11->raise();
        MachineView->raise();
        Label18->raise();
        ProductTime->raise();
        ProductNum->raise();
        Label9->raise();
        EnterButton->raise();
        LogoLabel->raise();
        Label2->raise();
        Label10->raise();
        ReturnButton->raise();
        GetButton->raise();
        Label1_1->raise();
        MachineNum_2->raise();
        MoldCombo->raise();
        Label8->raise();
        DirRepair_2->raise();
        ProductNum_2->raise();
        Label15->raise();
        Label16->raise();
        Operater_2->raise();
        Label17->raise();
        Label14->raise();
        Label13->raise();
        ProductID->raise();
        Label0_1->raise();
        tabWidget->raise();
        UserEdit->raise();
        Label1_2->raise();
        Label0_2->raise();
        OutNum->raise();
        CheckButton->raise();
        menubar = new QMenuBar(ChonyaEnter);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 760, 23));
        ChonyaEnter->setMenuBar(menubar);
        statusbar = new QStatusBar(ChonyaEnter);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ChonyaEnter->setStatusBar(statusbar);
        QWidget::setTabOrder(MoldCombo, MachineView);
        QWidget::setTabOrder(MachineView, ProductTime);
        QWidget::setTabOrder(ProductTime, ProductNum);
        QWidget::setTabOrder(ProductNum, Operater);
        QWidget::setTabOrder(Operater, DirRepair);
        QWidget::setTabOrder(DirRepair, ProductNum_2);
        QWidget::setTabOrder(ProductNum_2, Operater_2);
        QWidget::setTabOrder(Operater_2, DirRepair_2);
        QWidget::setTabOrder(DirRepair_2, ReturnButton);
        QWidget::setTabOrder(ReturnButton, EnterButton);
        QWidget::setTabOrder(EnterButton, MachineNum_2);
        QWidget::setTabOrder(MachineNum_2, UserEdit);
        QWidget::setTabOrder(UserEdit, ProductID);
        QWidget::setTabOrder(ProductID, OutNum);
        QWidget::setTabOrder(OutNum, tabWidget);
        QWidget::setTabOrder(tabWidget, NewButton);
        QWidget::setTabOrder(NewButton, GetButton);
        QWidget::setTabOrder(GetButton, CheckButton);
        QWidget::setTabOrder(CheckButton, PlotButton);

        retranslateUi(ChonyaEnter);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ChonyaEnter);
    } // setupUi

    void retranslateUi(QMainWindow *ChonyaEnter)
    {
        ChonyaEnter->setWindowTitle(QCoreApplication::translate("ChonyaEnter", "MainWindow", nullptr));
        Label12->setText(QCoreApplication::translate("ChonyaEnter", "\346\250\241\344\277\256:", nullptr));
        PlotButton->setText(QCoreApplication::translate("ChonyaEnter", "\344\272\247\351\207\217\346\233\262\347\272\277\345\233\276", nullptr));
        Label11->setText(QCoreApplication::translate("ChonyaEnter", "\346\223\215\344\275\234\345\221\230:", nullptr));
        Label18->setText(QCoreApplication::translate("ChonyaEnter", "\346\227\245\346\234\237:", nullptr));
        ProductTime->setPlaceholderText(QCoreApplication::translate("ChonyaEnter", "YYYY.MM.dd", nullptr));
        ProductNum->setText(QCoreApplication::translate("ChonyaEnter", "0", nullptr));
        ProductNum->setPlaceholderText(QString());
        Label9->setText(QCoreApplication::translate("ChonyaEnter", "\344\272\247\351\207\217:", nullptr));
        EnterButton->setText(QCoreApplication::translate("ChonyaEnter", "\344\272\247\351\207\217\345\275\225\345\205\245", nullptr));
        LogoLabel->setText(QString());
        BackGround->setText(QString());
        Label2->setText(QCoreApplication::translate("ChonyaEnter", "\351\200\211\346\213\251\346\234\272\345\217\260", nullptr));
        Label10->setText(QCoreApplication::translate("ChonyaEnter", "kpcs", nullptr));
        ReturnButton->setText(QCoreApplication::translate("ChonyaEnter", "\346\222\244\351\224\200\346\234\200\345\220\216\344\270\200\346\235\241", nullptr));
        GetButton->setText(QString());
        Label1_1->setText(QCoreApplication::translate("ChonyaEnter", "\345\242\236\345\212\240\346\234\272\345\217\260:", nullptr));
        MachineNum_2->setText(QCoreApplication::translate("ChonyaEnter", "1#", nullptr));
        MachineNum_2->setPlaceholderText(QCoreApplication::translate("ChonyaEnter", "#6", nullptr));
        Label8->setText(QCoreApplication::translate("ChonyaEnter", "\347\231\275\347\217\255", nullptr));
        ProductNum_2->setText(QCoreApplication::translate("ChonyaEnter", "0", nullptr));
        ProductNum_2->setPlaceholderText(QString());
        Label15->setText(QCoreApplication::translate("ChonyaEnter", "kpcs", nullptr));
        Label16->setText(QCoreApplication::translate("ChonyaEnter", "\346\223\215\344\275\234\345\221\230:", nullptr));
        Label17->setText(QCoreApplication::translate("ChonyaEnter", "\346\250\241\344\277\256:", nullptr));
        Label14->setText(QCoreApplication::translate("ChonyaEnter", "\344\272\247\351\207\217:", nullptr));
        Label13->setText(QCoreApplication::translate("ChonyaEnter", "\346\231\232\347\217\255", nullptr));
        ProductID->setPlaceholderText(QString());
        Label0_1->setText(QCoreApplication::translate("ChonyaEnter", "\344\272\247\345\223\201\346\226\231\345\217\267:", nullptr));
        PercentLabel1_1->setText(QString());
        PercentLabel3_1->setText(QString());
        Label3_1->setText(QCoreApplication::translate("ChonyaEnter", "\345\275\223\345\211\215\346\234\272\345\217\260:", nullptr));
        Label4_1->setText(QCoreApplication::translate("ChonyaEnter", "\344\270\213\346\226\231\351\233\266\344\273\266\346\215\237\350\200\227\347\250\213\345\272\246:", nullptr));
        MachineNum->setText(QString());
        Label6_1->setText(QCoreApplication::translate("ChonyaEnter", "\346\210\220\345\236\213\351\233\266\344\273\266\346\215\237\350\200\227\347\250\213\345\272\246:", nullptr));
        PercentLabel2_1->setText(QString());
        PercentLabel4_1->setText(QString());
        Label5_1->setText(QCoreApplication::translate("ChonyaEnter", "\345\205\263\351\224\256\346\230\223\346\215\237\344\273\266\344\273\266\346\215\237\350\200\227\347\250\213\345\272\246:", nullptr));
        Label7_1->setText(QCoreApplication::translate("ChonyaEnter", "\346\250\241\345\205\267\345\257\277\345\221\275\346\215\237\350\200\227\347\250\213\345\272\246:", nullptr));
        NewButton->setText(QCoreApplication::translate("ChonyaEnter", "\347\277\273\346\226\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Tab1), QCoreApplication::translate("ChonyaEnter", "\344\277\235\345\205\273\350\277\233\345\272\246", nullptr));
        PercentLabel2_2->setText(QString());
        Label6_2->setText(QCoreApplication::translate("ChonyaEnter", "\346\234\254\346\234\210\345\244\247\344\277\235\345\205\273\346\254\241\346\225\260:", nullptr));
        PercentLabel3_2->setText(QString());
        Label5_2->setText(QCoreApplication::translate("ChonyaEnter", "\346\234\254\346\234\210\345\256\232\346\234\237\344\277\235\345\205\273\346\254\241\346\225\260:", nullptr));
        PercentLabel1_2->setText(QString());
        Label4_2->setText(QCoreApplication::translate("ChonyaEnter", "\346\234\254\346\234\210\345\205\263\345\215\225\344\277\235\345\205\273\346\254\241\346\225\260:", nullptr));
        PercentLabel2_3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Tab2), QCoreApplication::translate("ChonyaEnter", "\346\234\254\346\234\210\346\254\241\346\225\260", nullptr));
        UserEdit->setText(QString());
        UserEdit->setPlaceholderText(QString());
        Label1_2->setText(QCoreApplication::translate("ChonyaEnter", "\345\242\236\345\212\240\345\221\230\345\267\245:", nullptr));
        Label0_2->setText(QCoreApplication::translate("ChonyaEnter", "\344\272\247\345\223\201\345\207\272\346\225\260:", nullptr));
        OutNum->setText(QString());
        OutNum->setPlaceholderText(QString());
        CheckButton->setText(QCoreApplication::translate("ChonyaEnter", "\345\257\274\345\207\272\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChonyaEnter: public Ui_ChonyaEnter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHONYAENTER_H
