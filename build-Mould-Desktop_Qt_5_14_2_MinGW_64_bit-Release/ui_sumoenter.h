/********************************************************************************
** Form generated from reading UI file 'sumoenter.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUMOENTER_H
#define UI_SUMOENTER_H

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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SumoEnter
{
public:
    QWidget *centralwidget;
    QLabel *Label12;
    QPushButton *PlotButton;
    QComboBox *DirRepair;
    QListView *MachineView;
    QLabel *Label13;
    QLineEdit *ProductTime;
    QLineEdit *ProductNum;
    QLabel *Label9;
    QPushButton *EnterButton;
    QLabel *LogoLabel;
    QLabel *BackGround;
    QLabel *Label3;
    QLabel *Label10;
    QPushButton *ReturnButton;
    QPushButton *GetButton;
    QLabel *Label2;
    QLineEdit *MachineNum_2;
    QComboBox *MoldCombo;
    QTextEdit *ProductID;
    QLabel *Label1;
    QLabel *Label11;
    QSpinBox *OutNum;
    QLabel *OutLabel;
    QTabWidget *tabWidget;
    QWidget *Tab1;
    QLabel *Label7_1;
    QLabel *PercentLabel4_1;
    QLabel *PercentLabel2_1;
    QLabel *Label6_1;
    QLabel *MachineNum;
    QLabel *PercentLabel1_1;
    QLabel *Label8_1;
    QLabel *PercentLabel3_1;
    QLabel *Label5_1;
    QLabel *Label4_1;
    QPushButton *NewButton;
    QWidget *Tab2;
    QLabel *PercentLabel2_2;
    QLabel *Label6_2;
    QLabel *Label5_2;
    QLabel *PercentLabel3_2;
    QPushButton *CheckButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SumoEnter)
    {
        if (SumoEnter->objectName().isEmpty())
            SumoEnter->setObjectName(QString::fromUtf8("SumoEnter"));
        SumoEnter->resize(760, 620);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SumoEnter->sizePolicy().hasHeightForWidth());
        SumoEnter->setSizePolicy(sizePolicy);
        SumoEnter->setMinimumSize(QSize(760, 620));
        SumoEnter->setMaximumSize(QSize(760, 620));
        centralwidget = new QWidget(SumoEnter);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Label12 = new QLabel(centralwidget);
        Label12->setObjectName(QString::fromUtf8("Label12"));
        Label12->setGeometry(QRect(380, 490, 131, 41));
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
        DirRepair->setGeometry(QRect(510, 490, 101, 41));
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
        MachineView = new QListView(centralwidget);
        MachineView->setObjectName(QString::fromUtf8("MachineView"));
        MachineView->setGeometry(QRect(70, 340, 211, 181));
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
        Label13 = new QLabel(centralwidget);
        Label13->setObjectName(QString::fromUtf8("Label13"));
        Label13->setGeometry(QRect(70, 540, 61, 41));
        Label13->setFont(font);
        ProductTime = new QLineEdit(centralwidget);
        ProductTime->setObjectName(QString::fromUtf8("ProductTime"));
        ProductTime->setGeometry(QRect(130, 540, 151, 41));
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
        ProductNum->setGeometry(QRect(480, 370, 71, 41));
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
        Label9->setGeometry(QRect(369, 370, 111, 41));
        Label9->setFont(font);
        EnterButton = new QPushButton(centralwidget);
        EnterButton->setObjectName(QString::fromUtf8("EnterButton"));
        EnterButton->setGeometry(QRect(575, 540, 141, 46));
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
        BackGround->setGeometry(QRect(0, 0, 761, 621));
        BackGround->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Label3 = new QLabel(centralwidget);
        Label3->setObjectName(QString::fromUtf8("Label3"));
        Label3->setGeometry(QRect(70, 300, 101, 41));
        Label3->setFont(font);
        Label10 = new QLabel(centralwidget);
        Label10->setObjectName(QString::fromUtf8("Label10"));
        Label10->setGeometry(QRect(560, 370, 21, 41));
        Label10->setFont(font);
        ReturnButton = new QPushButton(centralwidget);
        ReturnButton->setObjectName(QString::fromUtf8("ReturnButton"));
        ReturnButton->setGeometry(QRect(350, 540, 191, 46));
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
        GetButton->setGeometry(QRect(700, 65, 51, 51));
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
        Label2 = new QLabel(centralwidget);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(70, 255, 111, 31));
        Label2->setFont(font1);
        MachineNum_2 = new QLineEdit(centralwidget);
        MachineNum_2->setObjectName(QString::fromUtf8("MachineNum_2"));
        MachineNum_2->setGeometry(QRect(180, 250, 101, 41));
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
        MoldCombo->setGeometry(QRect(320, 70, 351, 41));
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
        ProductID = new QTextEdit(centralwidget);
        ProductID->setObjectName(QString::fromUtf8("ProductID"));
        ProductID->setGeometry(QRect(70, 120, 211, 111));
        ProductID->setFont(font);
        ProductID->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        ProductID->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductID->setReadOnly(false);
        Label1 = new QLabel(centralwidget);
        Label1->setObjectName(QString::fromUtf8("Label1"));
        Label1->setGeometry(QRect(70, 85, 111, 31));
        Label1->setFont(font);
        Label11 = new QLabel(centralwidget);
        Label11->setObjectName(QString::fromUtf8("Label11"));
        Label11->setGeometry(QRect(420, 430, 61, 41));
        Label11->setFont(font);
        OutNum = new QSpinBox(centralwidget);
        OutNum->setObjectName(QString::fromUtf8("OutNum"));
        OutNum->setGeometry(QRect(480, 430, 61, 41));
        OutNum->setStyleSheet(QString::fromUtf8("background-color: rgb(204, 221, 255);\n"
"border: none;\n"
"border-radius: 2px;\n"
"color: rgb(0,0,0);\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        OutNum->setAlignment(Qt::AlignCenter);
        OutNum->setMaximum(999);
        OutNum->setValue(1);
        OutLabel = new QLabel(centralwidget);
        OutLabel->setObjectName(QString::fromUtf8("OutLabel"));
        OutLabel->setGeometry(QRect(550, 430, 41, 41));
        OutLabel->setFont(font);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(310, 120, 430, 241));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        tabWidget->setFont(font4);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Tab1 = new QWidget();
        Tab1->setObjectName(QString::fromUtf8("Tab1"));
        Label7_1 = new QLabel(Tab1);
        Label7_1->setObjectName(QString::fromUtf8("Label7_1"));
        Label7_1->setGeometry(QRect(10, 125, 181, 41));
        Label7_1->setFont(font);
        PercentLabel4_1 = new QLabel(Tab1);
        PercentLabel4_1->setObjectName(QString::fromUtf8("PercentLabel4_1"));
        PercentLabel4_1->setGeometry(QRect(215, 170, 141, 31));
        PercentLabel4_1->setFont(font);
        PercentLabel2_1 = new QLabel(Tab1);
        PercentLabel2_1->setObjectName(QString::fromUtf8("PercentLabel2_1"));
        PercentLabel2_1->setGeometry(QRect(289, 90, 121, 31));
        PercentLabel2_1->setFont(font);
        Label6_1 = new QLabel(Tab1);
        Label6_1->setObjectName(QString::fromUtf8("Label6_1"));
        Label6_1->setGeometry(QRect(10, 85, 276, 41));
        Label6_1->setFont(font);
        MachineNum = new QLabel(Tab1);
        MachineNum->setObjectName(QString::fromUtf8("MachineNum"));
        MachineNum->setGeometry(QRect(120, 10, 61, 31));
        MachineNum->setFont(font);
        PercentLabel1_1 = new QLabel(Tab1);
        PercentLabel1_1->setObjectName(QString::fromUtf8("PercentLabel1_1"));
        PercentLabel1_1->setGeometry(QRect(215, 50, 141, 31));
        PercentLabel1_1->setFont(font);
        Label8_1 = new QLabel(Tab1);
        Label8_1->setObjectName(QString::fromUtf8("Label8_1"));
        Label8_1->setGeometry(QRect(10, 165, 201, 41));
        Label8_1->setFont(font);
        PercentLabel3_1 = new QLabel(Tab1);
        PercentLabel3_1->setObjectName(QString::fromUtf8("PercentLabel3_1"));
        PercentLabel3_1->setGeometry(QRect(190, 130, 141, 31));
        PercentLabel3_1->setFont(font);
        Label5_1 = new QLabel(Tab1);
        Label5_1->setObjectName(QString::fromUtf8("Label5_1"));
        Label5_1->setGeometry(QRect(10, 45, 201, 41));
        Label5_1->setFont(font);
        Label4_1 = new QLabel(Tab1);
        Label4_1->setObjectName(QString::fromUtf8("Label4_1"));
        Label4_1->setGeometry(QRect(10, 10, 111, 31));
        Label4_1->setFont(font);
        NewButton = new QPushButton(Tab1);
        NewButton->setObjectName(QString::fromUtf8("NewButton"));
        NewButton->setGeometry(QRect(360, 165, 66, 46));
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
        PercentLabel2_2->setGeometry(QRect(265, 70, 101, 31));
        PercentLabel2_2->setFont(font);
        Label6_2 = new QLabel(Tab2);
        Label6_2->setObjectName(QString::fromUtf8("Label6_2"));
        Label6_2->setGeometry(QRect(80, 105, 181, 41));
        Label6_2->setFont(font);
        Label5_2 = new QLabel(Tab2);
        Label5_2->setObjectName(QString::fromUtf8("Label5_2"));
        Label5_2->setGeometry(QRect(55, 65, 201, 41));
        Label5_2->setFont(font);
        PercentLabel3_2 = new QLabel(Tab2);
        PercentLabel3_2->setObjectName(QString::fromUtf8("PercentLabel3_2"));
        PercentLabel3_2->setGeometry(QRect(270, 110, 101, 31));
        PercentLabel3_2->setFont(font);
        tabWidget->addTab(Tab2, QString());
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
        SumoEnter->setCentralWidget(centralwidget);
        BackGround->raise();
        Label12->raise();
        PlotButton->raise();
        DirRepair->raise();
        MachineView->raise();
        Label13->raise();
        ProductTime->raise();
        ProductNum->raise();
        Label9->raise();
        EnterButton->raise();
        LogoLabel->raise();
        Label3->raise();
        Label10->raise();
        ReturnButton->raise();
        GetButton->raise();
        Label2->raise();
        MachineNum_2->raise();
        MoldCombo->raise();
        ProductID->raise();
        Label1->raise();
        Label11->raise();
        OutNum->raise();
        OutLabel->raise();
        tabWidget->raise();
        CheckButton->raise();
        menubar = new QMenuBar(SumoEnter);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 760, 23));
        SumoEnter->setMenuBar(menubar);
        statusbar = new QStatusBar(SumoEnter);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SumoEnter->setStatusBar(statusbar);
        QWidget::setTabOrder(MoldCombo, MachineView);
        QWidget::setTabOrder(MachineView, ProductTime);
        QWidget::setTabOrder(ProductTime, ProductNum);
        QWidget::setTabOrder(ProductNum, OutNum);
        QWidget::setTabOrder(OutNum, DirRepair);
        QWidget::setTabOrder(DirRepair, ReturnButton);
        QWidget::setTabOrder(ReturnButton, EnterButton);
        QWidget::setTabOrder(EnterButton, ProductID);
        QWidget::setTabOrder(ProductID, MachineNum_2);
        QWidget::setTabOrder(MachineNum_2, tabWidget);
        QWidget::setTabOrder(tabWidget, NewButton);
        QWidget::setTabOrder(NewButton, GetButton);
        QWidget::setTabOrder(GetButton, CheckButton);
        QWidget::setTabOrder(CheckButton, PlotButton);

        retranslateUi(SumoEnter);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SumoEnter);
    } // setupUi

    void retranslateUi(QMainWindow *SumoEnter)
    {
        SumoEnter->setWindowTitle(QCoreApplication::translate("SumoEnter", "MainWindow", nullptr));
        Label12->setText(QCoreApplication::translate("SumoEnter", "\344\277\256\346\250\241\346\212\200\346\234\257\345\221\230:", nullptr));
        PlotButton->setText(QCoreApplication::translate("SumoEnter", "\344\272\247\351\207\217\346\233\262\347\272\277\345\233\276", nullptr));
        Label13->setText(QCoreApplication::translate("SumoEnter", "\346\227\245\346\234\237:", nullptr));
        ProductTime->setPlaceholderText(QCoreApplication::translate("SumoEnter", "YYYY.MM.dd", nullptr));
        ProductNum->setText(QCoreApplication::translate("SumoEnter", "0", nullptr));
        ProductNum->setPlaceholderText(QString());
        Label9->setText(QCoreApplication::translate("SumoEnter", "\345\275\223\346\227\245\344\272\247\351\207\217:", nullptr));
        EnterButton->setText(QCoreApplication::translate("SumoEnter", "\344\272\247\351\207\217\345\275\225\345\205\245", nullptr));
        LogoLabel->setText(QString());
        BackGround->setText(QString());
        Label3->setText(QCoreApplication::translate("SumoEnter", "\351\200\211\346\213\251\346\234\272\345\217\260", nullptr));
        Label10->setText(QCoreApplication::translate("SumoEnter", "K", nullptr));
        ReturnButton->setText(QCoreApplication::translate("SumoEnter", "\346\222\244\351\224\200\346\234\200\345\220\216\344\270\200\346\235\241", nullptr));
        GetButton->setText(QString());
        Label2->setText(QCoreApplication::translate("SumoEnter", "\345\242\236\345\212\240\346\234\272\345\217\260:", nullptr));
        MachineNum_2->setText(QCoreApplication::translate("SumoEnter", "1#", nullptr));
        MachineNum_2->setPlaceholderText(QCoreApplication::translate("SumoEnter", "#6", nullptr));
        ProductID->setPlaceholderText(QString());
        Label1->setText(QCoreApplication::translate("SumoEnter", "\344\272\247\345\223\201\346\226\231\345\217\267:", nullptr));
        Label11->setText(QCoreApplication::translate("SumoEnter", "\347\251\264\346\225\260:", nullptr));
        OutLabel->setText(QCoreApplication::translate("SumoEnter", "/n", nullptr));
        Label7_1->setText(QCoreApplication::translate("SumoEnter", "\350\267\235\347\246\273\345\244\247\344\277\235\345\205\273\350\277\233\345\272\246:", nullptr));
        PercentLabel4_1->setText(QString());
        PercentLabel2_1->setText(QString());
        Label6_1->setText(QCoreApplication::translate("SumoEnter", "\350\267\235\347\246\273\347\211\271\345\256\232\346\230\223\346\215\237\344\273\266\344\277\235\345\205\273\350\277\233\345\272\246:", nullptr));
        MachineNum->setText(QString());
        PercentLabel1_1->setText(QString());
        Label8_1->setText(QCoreApplication::translate("SumoEnter", "\346\250\241\345\205\267\345\257\277\345\221\275\346\215\237\350\200\227\347\250\213\345\272\246:", nullptr));
        PercentLabel3_1->setText(QString());
        Label5_1->setText(QCoreApplication::translate("SumoEnter", "\350\267\235\347\246\273\345\256\232\346\234\237\344\277\235\345\205\273\350\277\233\345\272\246:", nullptr));
        Label4_1->setText(QCoreApplication::translate("SumoEnter", "\345\275\223\345\211\215\346\234\272\345\217\260:", nullptr));
        NewButton->setText(QCoreApplication::translate("SumoEnter", "\347\277\273\346\226\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Tab1), QCoreApplication::translate("SumoEnter", "\344\277\235\345\205\273\350\277\233\345\272\246", nullptr));
        PercentLabel2_2->setText(QString());
        Label6_2->setText(QCoreApplication::translate("SumoEnter", "\346\234\254\346\234\210\345\244\247\344\277\235\345\205\273\346\254\241\346\225\260:", nullptr));
        Label5_2->setText(QCoreApplication::translate("SumoEnter", "\346\234\254\346\234\210\345\256\232\346\234\237\344\277\235\345\205\273\346\254\241\346\225\260:", nullptr));
        PercentLabel3_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Tab2), QCoreApplication::translate("SumoEnter", "\346\234\254\346\234\210\346\254\241\346\225\260", nullptr));
        CheckButton->setText(QCoreApplication::translate("SumoEnter", "\345\257\274\345\207\272\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SumoEnter: public Ui_SumoEnter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUMOENTER_H
