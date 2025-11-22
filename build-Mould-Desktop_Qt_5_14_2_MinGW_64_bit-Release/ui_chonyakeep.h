/********************************************************************************
** Form generated from reading UI file 'chonyakeep.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHONYAKEEP_H
#define UI_CHONYAKEEP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChonyaKeep
{
public:
    QWidget *centralwidget;
    QPushButton *HandleButton;
    QComboBox *DirRepair;
    QLabel *Label12;
    QLabel *Label11;
    QComboBox *Operater;
    QLabel *Label1;
    QLabel *Label3;
    QLineEdit *DateTime;
    QLabel *Label4;
    QLabel *Label2;
    QTextEdit *ProductID;
    QLineEdit *LifeNum;
    QLineEdit *MoldID;
    QLabel *Label7;
    QLineEdit *DownTime;
    QLabel *Label5;
    QComboBox *StataDes;
    QLabel *Label13;
    QTextEdit *ProblemDes;
    QLabel *Label10;
    QLabel *BackGround;
    QLabel *Label9;
    QLineEdit *MachineNum;
    QLabel *Label8;
    QLabel *Logo;
    QTextEdit *ProductName;
    QLabel *Label6;
    QComboBox *KeepType;
    QLabel *Label17;
    QTextEdit *KeepDes;
    QLabel *Label16;
    QFrame *line;
    QPushButton *FinishedButton;
    QLabel *label;
    QLineEdit *StataEdit;
    QCheckBox *OtherCheck;
    QCheckBox *ChangeCheck;
    QLabel *Label18;
    QTextEdit *OtherDes;
    QLabel *Label14;
    QLineEdit *ChangeID;
    QLabel *Label15;
    QLineEdit *ChangeNum;
    QPushButton *HistoryButton;
    QCheckBox *AddCheck;
    QPushButton *ReturnButton;
    QPushButton *GetButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChonyaKeep)
    {
        if (ChonyaKeep->objectName().isEmpty())
            ChonyaKeep->setObjectName(QString::fromUtf8("ChonyaKeep"));
        ChonyaKeep->resize(720, 865);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChonyaKeep->sizePolicy().hasHeightForWidth());
        ChonyaKeep->setSizePolicy(sizePolicy);
        ChonyaKeep->setMinimumSize(QSize(720, 865));
        ChonyaKeep->setMaximumSize(QSize(720, 865));
        centralwidget = new QWidget(ChonyaKeep);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        HandleButton = new QPushButton(centralwidget);
        HandleButton->setObjectName(QString::fromUtf8("HandleButton"));
        HandleButton->setEnabled(true);
        HandleButton->setGeometry(QRect(520, 490, 121, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        HandleButton->setFont(font);
        HandleButton->setCursor(QCursor(Qt::PointingHandCursor));
        HandleButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        DirRepair = new QComboBox(centralwidget);
        DirRepair->setObjectName(QString::fromUtf8("DirRepair"));
        DirRepair->setGeometry(QRect(600, 420, 101, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        DirRepair->setFont(font1);
        DirRepair->setCursor(QCursor(Qt::ArrowCursor));
        DirRepair->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        DirRepair->setEditable(true);
        Label12 = new QLabel(centralwidget);
        Label12->setObjectName(QString::fromUtf8("Label12"));
        Label12->setGeometry(QRect(540, 425, 61, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(18);
        Label12->setFont(font2);
        Label11 = new QLabel(centralwidget);
        Label11->setObjectName(QString::fromUtf8("Label11"));
        Label11->setGeometry(QRect(515, 375, 81, 31));
        Label11->setFont(font2);
        Operater = new QComboBox(centralwidget);
        Operater->setObjectName(QString::fromUtf8("Operater"));
        Operater->setGeometry(QRect(600, 370, 101, 41));
        Operater->setFont(font1);
        Operater->setCursor(QCursor(Qt::ArrowCursor));
        Operater->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        Operater->setEditable(true);
        Label1 = new QLabel(centralwidget);
        Label1->setObjectName(QString::fromUtf8("Label1"));
        Label1->setGeometry(QRect(290, 30, 231, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(20);
        Label1->setFont(font3);
        Label3 = new QLabel(centralwidget);
        Label3->setObjectName(QString::fromUtf8("Label3"));
        Label3->setGeometry(QRect(465, 95, 61, 31));
        Label3->setFont(font2);
        DateTime = new QLineEdit(centralwidget);
        DateTime->setObjectName(QString::fromUtf8("DateTime"));
        DateTime->setGeometry(QRect(530, 90, 151, 41));
        DateTime->setFont(font2);
        DateTime->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        DateTime->setAlignment(Qt::AlignCenter);
        DateTime->setReadOnly(false);
        Label4 = new QLabel(centralwidget);
        Label4->setObjectName(QString::fromUtf8("Label4"));
        Label4->setGeometry(QRect(30, 160, 111, 31));
        Label4->setFont(font2);
        Label2 = new QLabel(centralwidget);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(80, 95, 61, 31));
        Label2->setFont(font2);
        ProductID = new QTextEdit(centralwidget);
        ProductID->setObjectName(QString::fromUtf8("ProductID"));
        ProductID->setGeometry(QRect(140, 150, 261, 61));
        ProductID->setFont(font2);
        ProductID->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        ProductID->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductID->setReadOnly(false);
        LifeNum = new QLineEdit(centralwidget);
        LifeNum->setObjectName(QString::fromUtf8("LifeNum"));
        LifeNum->setGeometry(QRect(550, 205, 91, 41));
        LifeNum->setFont(font2);
        LifeNum->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        LifeNum->setAlignment(Qt::AlignCenter);
        LifeNum->setReadOnly(false);
        MoldID = new QLineEdit(centralwidget);
        MoldID->setObjectName(QString::fromUtf8("MoldID"));
        MoldID->setGeometry(QRect(140, 90, 261, 41));
        MoldID->setFont(font2);
        MoldID->setCursor(QCursor(Qt::ArrowCursor));
        MoldID->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MoldID->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        MoldID->setReadOnly(true);
        Label7 = new QLabel(centralwidget);
        Label7->setObjectName(QString::fromUtf8("Label7"));
        Label7->setGeometry(QRect(420, 210, 131, 31));
        Label7->setFont(font2);
        DownTime = new QLineEdit(centralwidget);
        DownTime->setObjectName(QString::fromUtf8("DownTime"));
        DownTime->setGeometry(QRect(530, 150, 121, 41));
        DownTime->setFont(font2);
        DownTime->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        DownTime->setAlignment(Qt::AlignCenter);
        DownTime->setReadOnly(false);
        Label5 = new QLabel(centralwidget);
        Label5->setObjectName(QString::fromUtf8("Label5"));
        Label5->setGeometry(QRect(420, 155, 111, 31));
        Label5->setFont(font2);
        StataDes = new QComboBox(centralwidget);
        StataDes->addItem(QString());
        StataDes->addItem(QString());
        StataDes->addItem(QString());
        StataDes->setObjectName(QString::fromUtf8("StataDes"));
        StataDes->setGeometry(QRect(140, 500, 161, 41));
        StataDes->setFont(font2);
        StataDes->setCursor(QCursor(Qt::ArrowCursor));
        StataDes->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        Label13 = new QLabel(centralwidget);
        Label13->setObjectName(QString::fromUtf8("Label13"));
        Label13->setGeometry(QRect(30, 505, 111, 31));
        Label13->setFont(font2);
        ProblemDes = new QTextEdit(centralwidget);
        ProblemDes->setObjectName(QString::fromUtf8("ProblemDes"));
        ProblemDes->setGeometry(QRect(140, 310, 361, 171));
        ProblemDes->setFont(font2);
        ProblemDes->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        ProblemDes->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProblemDes->setReadOnly(false);
        Label10 = new QLabel(centralwidget);
        Label10->setObjectName(QString::fromUtf8("Label10"));
        Label10->setGeometry(QRect(30, 320, 111, 31));
        Label10->setFont(font2);
        BackGround = new QLabel(centralwidget);
        BackGround->setObjectName(QString::fromUtf8("BackGround"));
        BackGround->setGeometry(QRect(5, 5, 711, 551));
        BackGround->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);\n"
"border-radius: 15px;\n"
"border-style: outset;"));
        Label9 = new QLabel(centralwidget);
        Label9->setObjectName(QString::fromUtf8("Label9"));
        Label9->setGeometry(QRect(445, 265, 81, 31));
        Label9->setFont(font2);
        MachineNum = new QLineEdit(centralwidget);
        MachineNum->setObjectName(QString::fromUtf8("MachineNum"));
        MachineNum->setGeometry(QRect(530, 260, 66, 41));
        MachineNum->setFont(font2);
        MachineNum->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MachineNum->setAlignment(Qt::AlignCenter);
        MachineNum->setReadOnly(false);
        Label8 = new QLabel(centralwidget);
        Label8->setObjectName(QString::fromUtf8("Label8"));
        Label8->setGeometry(QRect(645, 210, 51, 31));
        Label8->setFont(font2);
        Logo = new QLabel(centralwidget);
        Logo->setObjectName(QString::fromUtf8("Logo"));
        Logo->setGeometry(QRect(10, 10, 200, 53));
        Logo->setPixmap(QPixmap(QString::fromUtf8(":/images/logo200x53.jpg")));
        ProductName = new QTextEdit(centralwidget);
        ProductName->setObjectName(QString::fromUtf8("ProductName"));
        ProductName->setGeometry(QRect(140, 230, 261, 61));
        ProductName->setFont(font2);
        ProductName->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        ProductName->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductName->setReadOnly(false);
        Label6 = new QLabel(centralwidget);
        Label6->setObjectName(QString::fromUtf8("Label6"));
        Label6->setGeometry(QRect(30, 240, 111, 31));
        Label6->setFont(font2);
        KeepType = new QComboBox(centralwidget);
        KeepType->addItem(QString());
        KeepType->addItem(QString());
        KeepType->addItem(QString());
        KeepType->setObjectName(QString::fromUtf8("KeepType"));
        KeepType->setGeometry(QRect(500, 705, 161, 41));
        KeepType->setFont(font2);
        KeepType->setCursor(QCursor(Qt::ArrowCursor));
        KeepType->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        Label17 = new QLabel(centralwidget);
        Label17->setObjectName(QString::fromUtf8("Label17"));
        Label17->setGeometry(QRect(500, 670, 111, 31));
        Label17->setFont(font2);
        KeepDes = new QTextEdit(centralwidget);
        KeepDes->setObjectName(QString::fromUtf8("KeepDes"));
        KeepDes->setGeometry(QRect(50, 655, 431, 171));
        KeepDes->setFont(font2);
        KeepDes->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        KeepDes->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        KeepDes->setReadOnly(false);
        Label16 = new QLabel(centralwidget);
        Label16->setObjectName(QString::fromUtf8("Label16"));
        Label16->setGeometry(QRect(50, 620, 110, 31));
        Label16->setFont(font2);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 545, 701, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        FinishedButton = new QPushButton(centralwidget);
        FinishedButton->setObjectName(QString::fromUtf8("FinishedButton"));
        FinishedButton->setGeometry(QRect(500, 780, 121, 51));
        FinishedButton->setFont(font);
        FinishedButton->setCursor(QCursor(Qt::PointingHandCursor));
        FinishedButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(5, 555, 711, 291));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(160, 175, 200);\n"
"border-radius: 15px;\n"
"border-style: outset;"));
        StataEdit = new QLineEdit(centralwidget);
        StataEdit->setObjectName(QString::fromUtf8("StataEdit"));
        StataEdit->setGeometry(QRect(320, 500, 181, 41));
        StataEdit->setFont(font2);
        StataEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        StataEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        StataEdit->setReadOnly(false);
        OtherCheck = new QCheckBox(centralwidget);
        OtherCheck->setObjectName(QString::fromUtf8("OtherCheck"));
        OtherCheck->setGeometry(QRect(500, 755, 121, 16));
        QFont font4;
        font4.setPointSize(12);
        OtherCheck->setFont(font4);
        OtherCheck->setCursor(QCursor(Qt::PointingHandCursor));
        ChangeCheck = new QCheckBox(centralwidget);
        ChangeCheck->setObjectName(QString::fromUtf8("ChangeCheck"));
        ChangeCheck->setGeometry(QRect(500, 640, 151, 16));
        ChangeCheck->setFont(font4);
        ChangeCheck->setCursor(QCursor(Qt::PointingHandCursor));
        Label18 = new QLabel(centralwidget);
        Label18->setObjectName(QString::fromUtf8("Label18"));
        Label18->setGeometry(QRect(50, 725, 111, 31));
        Label18->setFont(font2);
        OtherDes = new QTextEdit(centralwidget);
        OtherDes->setObjectName(QString::fromUtf8("OtherDes"));
        OtherDes->setGeometry(QRect(50, 760, 431, 71));
        OtherDes->setFont(font2);
        OtherDes->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        OtherDes->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        OtherDes->setReadOnly(false);
        Label14 = new QLabel(centralwidget);
        Label14->setObjectName(QString::fromUtf8("Label14"));
        Label14->setGeometry(QRect(110, 575, 111, 31));
        Label14->setFont(font2);
        ChangeID = new QLineEdit(centralwidget);
        ChangeID->setObjectName(QString::fromUtf8("ChangeID"));
        ChangeID->setGeometry(QRect(220, 570, 211, 41));
        ChangeID->setFont(font2);
        ChangeID->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ChangeID->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        ChangeID->setReadOnly(false);
        Label15 = new QLabel(centralwidget);
        Label15->setObjectName(QString::fromUtf8("Label15"));
        Label15->setGeometry(QRect(440, 575, 111, 31));
        Label15->setFont(font2);
        ChangeNum = new QLineEdit(centralwidget);
        ChangeNum->setObjectName(QString::fromUtf8("ChangeNum"));
        ChangeNum->setGeometry(QRect(550, 570, 111, 41));
        ChangeNum->setFont(font2);
        ChangeNum->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ChangeNum->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        ChangeNum->setReadOnly(false);
        HistoryButton = new QPushButton(centralwidget);
        HistoryButton->setObjectName(QString::fromUtf8("HistoryButton"));
        HistoryButton->setGeometry(QRect(550, 10, 161, 51));
        HistoryButton->setFont(font);
        HistoryButton->setCursor(QCursor(Qt::PointingHandCursor));
        HistoryButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/history.png"), QSize(), QIcon::Normal, QIcon::Off);
        HistoryButton->setIcon(icon);
        HistoryButton->setIconSize(QSize(26, 26));
        AddCheck = new QCheckBox(centralwidget);
        AddCheck->setObjectName(QString::fromUtf8("AddCheck"));
        AddCheck->setGeometry(QRect(530, 330, 151, 16));
        AddCheck->setFont(font4);
        AddCheck->setCursor(QCursor(Qt::PointingHandCursor));
        ReturnButton = new QPushButton(centralwidget);
        ReturnButton->setObjectName(QString::fromUtf8("ReturnButton"));
        ReturnButton->setGeometry(QRect(630, 780, 71, 51));
        ReturnButton->setFont(font);
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
"color: rgb(200, 200, 200);\n"
"}"));
        GetButton = new QPushButton(centralwidget);
        GetButton->setObjectName(QString::fromUtf8("GetButton"));
        GetButton->setGeometry(QRect(650, 495, 51, 46));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(18);
        font5.setBold(false);
        font5.setWeight(50);
        GetButton->setFont(font5);
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/data.png"), QSize(), QIcon::Normal, QIcon::Off);
        GetButton->setIcon(icon1);
        GetButton->setIconSize(QSize(30, 30));
        ChonyaKeep->setCentralWidget(centralwidget);
        label->raise();
        BackGround->raise();
        HandleButton->raise();
        DirRepair->raise();
        Label12->raise();
        Label11->raise();
        Operater->raise();
        Label1->raise();
        Label3->raise();
        DateTime->raise();
        Label4->raise();
        Label2->raise();
        ProductID->raise();
        LifeNum->raise();
        MoldID->raise();
        Label7->raise();
        DownTime->raise();
        Label5->raise();
        StataDes->raise();
        Label13->raise();
        ProblemDes->raise();
        Label10->raise();
        Label9->raise();
        MachineNum->raise();
        Label8->raise();
        Logo->raise();
        ProductName->raise();
        Label6->raise();
        KeepType->raise();
        Label17->raise();
        KeepDes->raise();
        Label16->raise();
        line->raise();
        FinishedButton->raise();
        StataEdit->raise();
        OtherCheck->raise();
        ChangeCheck->raise();
        Label18->raise();
        OtherDes->raise();
        Label14->raise();
        ChangeID->raise();
        Label15->raise();
        ChangeNum->raise();
        HistoryButton->raise();
        AddCheck->raise();
        ReturnButton->raise();
        GetButton->raise();
        menubar = new QMenuBar(ChonyaKeep);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 720, 23));
        ChonyaKeep->setMenuBar(menubar);
        statusbar = new QStatusBar(ChonyaKeep);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ChonyaKeep->setStatusBar(statusbar);
        QWidget::setTabOrder(MoldID, DateTime);
        QWidget::setTabOrder(DateTime, ProductID);
        QWidget::setTabOrder(ProductID, DownTime);
        QWidget::setTabOrder(DownTime, ProductName);
        QWidget::setTabOrder(ProductName, LifeNum);
        QWidget::setTabOrder(LifeNum, MachineNum);
        QWidget::setTabOrder(MachineNum, ProblemDes);
        QWidget::setTabOrder(ProblemDes, AddCheck);
        QWidget::setTabOrder(AddCheck, Operater);
        QWidget::setTabOrder(Operater, DirRepair);
        QWidget::setTabOrder(DirRepair, StataDes);
        QWidget::setTabOrder(StataDes, StataEdit);
        QWidget::setTabOrder(StataEdit, ChangeID);
        QWidget::setTabOrder(ChangeID, ChangeNum);
        QWidget::setTabOrder(ChangeNum, KeepDes);
        QWidget::setTabOrder(KeepDes, OtherDes);
        QWidget::setTabOrder(OtherDes, ChangeCheck);
        QWidget::setTabOrder(ChangeCheck, KeepType);
        QWidget::setTabOrder(KeepType, OtherCheck);
        QWidget::setTabOrder(OtherCheck, FinishedButton);
        QWidget::setTabOrder(FinishedButton, ReturnButton);
        QWidget::setTabOrder(ReturnButton, HandleButton);
        QWidget::setTabOrder(HandleButton, GetButton);
        QWidget::setTabOrder(GetButton, HistoryButton);

        retranslateUi(ChonyaKeep);

        QMetaObject::connectSlotsByName(ChonyaKeep);
    } // setupUi

    void retranslateUi(QMainWindow *ChonyaKeep)
    {
        ChonyaKeep->setWindowTitle(QCoreApplication::translate("ChonyaKeep", "MainWindow", nullptr));
        HandleButton->setText(QCoreApplication::translate("ChonyaKeep", "\347\224\237\346\210\220\350\241\250\345\215\225", nullptr));
        Label12->setText(QCoreApplication::translate("ChonyaKeep", "\346\250\241\344\277\256:", nullptr));
        Label11->setText(QCoreApplication::translate("ChonyaKeep", "\346\223\215\344\275\234\345\221\230:", nullptr));
        Label1->setText(QCoreApplication::translate("ChonyaKeep", "\346\250\241\345\205\267\347\273\264\344\277\256&\344\277\235\345\205\273", nullptr));
        Label3->setText(QCoreApplication::translate("ChonyaKeep", "\346\227\245\346\234\237:", nullptr));
        DateTime->setPlaceholderText(QCoreApplication::translate("ChonyaKeep", "yyyy.MM.dd", nullptr));
        Label4->setText(QCoreApplication::translate("ChonyaKeep", "\344\272\247\345\223\201\346\226\231\345\217\267:", nullptr));
        Label2->setText(QCoreApplication::translate("ChonyaKeep", "\346\250\241\345\217\267:", nullptr));
        ProductID->setPlaceholderText(QCoreApplication::translate("ChonyaKeep", "\350\257\267\350\276\223\345\205\245\344\272\247\345\223\201\346\226\231\345\217\267", nullptr));
        LifeNum->setPlaceholderText(QCoreApplication::translate("ChonyaKeep", "666", nullptr));
        MoldID->setPlaceholderText(QCoreApplication::translate("ChonyaKeep", "\350\257\267\350\276\223\345\205\245\346\250\241\345\217\267", nullptr));
        Label7->setText(QCoreApplication::translate("ChonyaKeep", "\347\264\257\350\256\241\345\206\262\346\254\241\346\225\260:", nullptr));
        DownTime->setPlaceholderText(QCoreApplication::translate("ChonyaKeep", "hh:mm:ss", nullptr));
        Label5->setText(QCoreApplication::translate("ChonyaKeep", "\344\270\213\346\250\241\346\227\266\351\227\264:", nullptr));
        StataDes->setItemText(0, QCoreApplication::translate("ChonyaKeep", "\345\256\232\346\234\237\344\277\235\345\205\273", nullptr));
        StataDes->setItemText(1, QCoreApplication::translate("ChonyaKeep", "\345\244\247\344\277\235\345\205\273", nullptr));
        StataDes->setItemText(2, QCoreApplication::translate("ChonyaKeep", "\345\221\206\346\273\2366\344\270\252\346\234\210\344\273\245\344\270\212", nullptr));

        Label13->setText(QCoreApplication::translate("ChonyaKeep", "\344\277\235\345\205\273\346\226\271\345\274\217:", nullptr));
        ProblemDes->setPlaceholderText(QCoreApplication::translate("ChonyaKeep", "\350\257\267\350\276\223\345\205\245\346\250\241\345\205\267\345\255\230\345\234\250\351\227\256\351\242\230", nullptr));
        Label10->setText(QCoreApplication::translate("ChonyaKeep", "\351\227\256\351\242\230\346\217\217\350\277\260:", nullptr));
        BackGround->setText(QString());
        Label9->setText(QCoreApplication::translate("ChonyaKeep", "\346\234\272\345\217\260\345\217\267:", nullptr));
        MachineNum->setPlaceholderText(QCoreApplication::translate("ChonyaKeep", "#6", nullptr));
        Label8->setText(QCoreApplication::translate("ChonyaKeep", "\344\270\207\346\254\241", nullptr));
        Logo->setText(QString());
        ProductName->setPlaceholderText(QCoreApplication::translate("ChonyaKeep", "\350\257\267\350\276\223\345\205\245\344\272\247\345\223\201\345\220\215\347\247\260", nullptr));
        Label6->setText(QCoreApplication::translate("ChonyaKeep", "\344\272\247\345\223\201\345\220\215\347\247\260:", nullptr));
        KeepType->setItemText(0, QCoreApplication::translate("ChonyaKeep", "\344\270\213\346\226\231\351\233\266\344\273\266", nullptr));
        KeepType->setItemText(1, QCoreApplication::translate("ChonyaKeep", "\345\205\263\351\224\256\346\230\223\346\215\237\344\273\266", nullptr));
        KeepType->setItemText(2, QCoreApplication::translate("ChonyaKeep", "\346\210\220\345\236\213\351\233\266\344\273\266", nullptr));

        Label17->setText(QCoreApplication::translate("ChonyaKeep", "\344\277\235\345\205\273\351\233\266\344\273\266:", nullptr));
        KeepDes->setPlaceholderText(QCoreApplication::translate("ChonyaKeep", "\350\257\267\350\276\223\345\205\245\346\250\241\345\205\267\345\244\204\347\220\206\345\257\271\347\255\226", nullptr));
        Label16->setText(QCoreApplication::translate("ChonyaKeep", "\345\244\204\347\220\206\345\257\271\347\255\226:", nullptr));
        FinishedButton->setText(QCoreApplication::translate("ChonyaKeep", "\346\267\273\345\212\240\346\225\260\346\215\256", nullptr));
        label->setText(QString());
        StataEdit->setPlaceholderText(QCoreApplication::translate("ChonyaKeep", "\350\257\267\350\276\223\345\205\245\345\205\266\345\256\203\347\212\266\346\200\201", nullptr));
        OtherCheck->setText(QCoreApplication::translate("ChonyaKeep", "\346\230\257\345\220\246\351\234\200\350\246\201\345\244\207\346\263\250", nullptr));
        ChangeCheck->setText(QCoreApplication::translate("ChonyaKeep", "\346\230\257\345\220\246\351\234\200\350\246\201\346\233\264\346\215\242\345\244\207\344\273\266", nullptr));
        Label18->setText(QCoreApplication::translate("ChonyaKeep", "\345\244\207\346\263\250\345\206\205\345\256\271:", nullptr));
        OtherDes->setPlaceholderText(QCoreApplication::translate("ChonyaKeep", "\350\257\267\350\276\223\345\205\245\345\244\207\346\263\250\345\206\205\345\256\271", nullptr));
        Label14->setText(QCoreApplication::translate("ChonyaKeep", "\346\233\264\346\215\242\345\244\207\344\273\266:", nullptr));
        ChangeID->setPlaceholderText(QCoreApplication::translate("ChonyaKeep", "\350\257\267\350\276\223\345\205\245\345\244\207\344\273\266\345\217\267", nullptr));
        Label15->setText(QCoreApplication::translate("ChonyaKeep", "\350\276\223\345\205\245\346\225\260\351\207\217:", nullptr));
        ChangeNum->setPlaceholderText(QString());
        HistoryButton->setText(QCoreApplication::translate("ChonyaKeep", "\345\257\274\345\207\272\345\216\206\345\217\262", nullptr));
        AddCheck->setText(QCoreApplication::translate("ChonyaKeep", "\346\230\257\345\220\246\351\234\200\350\246\201\351\231\204\345\212\240\344\277\235\345\205\273", nullptr));
        ReturnButton->setText(QCoreApplication::translate("ChonyaKeep", "\346\222\244\345\233\236", nullptr));
        GetButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChonyaKeep: public Ui_ChonyaKeep {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHONYAKEEP_H
