/********************************************************************************
** Form generated from reading UI file 'sumokeep.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUMOKEEP_H
#define UI_SUMOKEEP_H

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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SumoKeep
{
public:
    QWidget *centralwidget;
    QComboBox *DirRepair;
    QLabel *Label13;
    QLabel *Label12;
    QComboBox *Operater;
    QLabel *Label1;
    QLabel *Label3;
    QLineEdit *DateTime;
    QLabel *Label4_1;
    QLabel *Label2;
    QTextEdit *ProductName;
    QLineEdit *MoldID;
    QLabel *Label10;
    QComboBox *StataDes;
    QLabel *Label14;
    QTextEdit *ProblemDes;
    QLabel *Label11;
    QLabel *BackGround;
    QLabel *Label5;
    QLineEdit *MachineNum;
    QLabel *Logo;
    QTextEdit *ThinkDes;
    QLabel *Label17;
    QFrame *line;
    QPushButton *FinishedButton;
    QLabel *label;
    QLineEdit *StataEdit;
    QCheckBox *ChangeCheck;
    QLabel *Label19;
    QTextEdit *ProceDes;
    QLabel *Label15;
    QLineEdit *ChangeID;
    QLabel *Label16;
    QLineEdit *ChangeNum;
    QPushButton *HistoryButton;
    QCheckBox *AddCheck;
    QPushButton *ReturnButton;
    QLineEdit *DownTime;
    QLabel *Label6;
    QLineEdit *DirTime;
    QLabel *Label7;
    QSpinBox *OutNum;
    QLabel *OutLabel;
    QTextEdit *ProductID;
    QLabel *Label4_2;
    QLineEdit *LifeNum;
    QPushButton *GetButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SumoKeep)
    {
        if (SumoKeep->objectName().isEmpty())
            SumoKeep->setObjectName(QString::fromUtf8("SumoKeep"));
        SumoKeep->resize(720, 865);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SumoKeep->sizePolicy().hasHeightForWidth());
        SumoKeep->setSizePolicy(sizePolicy);
        SumoKeep->setMinimumSize(QSize(720, 865));
        SumoKeep->setMaximumSize(QSize(720, 865));
        centralwidget = new QWidget(SumoKeep);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        DirRepair = new QComboBox(centralwidget);
        DirRepair->setObjectName(QString::fromUtf8("DirRepair"));
        DirRepair->setGeometry(QRect(600, 400, 101, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(18);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        DirRepair->setFont(font);
        DirRepair->setCursor(QCursor(Qt::ArrowCursor));
        DirRepair->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        DirRepair->setEditable(true);
        Label13 = new QLabel(centralwidget);
        Label13->setObjectName(QString::fromUtf8("Label13"));
        Label13->setGeometry(QRect(515, 405, 81, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        Label13->setFont(font1);
        Label12 = new QLabel(centralwidget);
        Label12->setObjectName(QString::fromUtf8("Label12"));
        Label12->setGeometry(QRect(515, 355, 81, 31));
        Label12->setFont(font1);
        Operater = new QComboBox(centralwidget);
        Operater->setObjectName(QString::fromUtf8("Operater"));
        Operater->setGeometry(QRect(600, 350, 101, 41));
        Operater->setFont(font);
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
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(20);
        Label1->setFont(font2);
        Label3 = new QLabel(centralwidget);
        Label3->setObjectName(QString::fromUtf8("Label3"));
        Label3->setGeometry(QRect(465, 95, 61, 31));
        Label3->setFont(font1);
        DateTime = new QLineEdit(centralwidget);
        DateTime->setObjectName(QString::fromUtf8("DateTime"));
        DateTime->setGeometry(QRect(530, 90, 151, 41));
        DateTime->setFont(font1);
        DateTime->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        DateTime->setAlignment(Qt::AlignCenter);
        DateTime->setReadOnly(false);
        Label4_1 = new QLabel(centralwidget);
        Label4_1->setObjectName(QString::fromUtf8("Label4_1"));
        Label4_1->setGeometry(QRect(30, 155, 111, 31));
        Label4_1->setFont(font1);
        Label2 = new QLabel(centralwidget);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(80, 95, 61, 31));
        Label2->setFont(font1);
        ProductName = new QTextEdit(centralwidget);
        ProductName->setObjectName(QString::fromUtf8("ProductName"));
        ProductName->setGeometry(QRect(140, 150, 261, 41));
        ProductName->setFont(font1);
        ProductName->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        ProductName->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductName->setReadOnly(false);
        MoldID = new QLineEdit(centralwidget);
        MoldID->setObjectName(QString::fromUtf8("MoldID"));
        MoldID->setGeometry(QRect(140, 90, 261, 41));
        MoldID->setFont(font1);
        MoldID->setCursor(QCursor(Qt::ArrowCursor));
        MoldID->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MoldID->setReadOnly(true);
        Label10 = new QLabel(centralwidget);
        Label10->setObjectName(QString::fromUtf8("Label10"));
        Label10->setGeometry(QRect(420, 215, 111, 31));
        Label10->setFont(font1);
        StataDes = new QComboBox(centralwidget);
        StataDes->setObjectName(QString::fromUtf8("StataDes"));
        StataDes->setGeometry(QRect(140, 460, 161, 41));
        StataDes->setFont(font1);
        StataDes->setCursor(QCursor(Qt::ArrowCursor));
        StataDes->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        Label14 = new QLabel(centralwidget);
        Label14->setObjectName(QString::fromUtf8("Label14"));
        Label14->setGeometry(QRect(30, 465, 111, 31));
        Label14->setFont(font1);
        ProblemDes = new QTextEdit(centralwidget);
        ProblemDes->setObjectName(QString::fromUtf8("ProblemDes"));
        ProblemDes->setGeometry(QRect(140, 350, 361, 91));
        ProblemDes->setFont(font1);
        ProblemDes->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        ProblemDes->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProblemDes->setReadOnly(false);
        Label11 = new QLabel(centralwidget);
        Label11->setObjectName(QString::fromUtf8("Label11"));
        Label11->setGeometry(QRect(30, 355, 111, 31));
        Label11->setFont(font1);
        BackGround = new QLabel(centralwidget);
        BackGround->setObjectName(QString::fromUtf8("BackGround"));
        BackGround->setGeometry(QRect(5, 5, 711, 521));
        BackGround->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);\n"
"border-radius: 15px;\n"
"border-style: outset;"));
        Label5 = new QLabel(centralwidget);
        Label5->setObjectName(QString::fromUtf8("Label5"));
        Label5->setGeometry(QRect(440, 155, 81, 31));
        Label5->setFont(font1);
        MachineNum = new QLineEdit(centralwidget);
        MachineNum->setObjectName(QString::fromUtf8("MachineNum"));
        MachineNum->setGeometry(QRect(530, 150, 66, 41));
        MachineNum->setFont(font1);
        MachineNum->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MachineNum->setAlignment(Qt::AlignCenter);
        MachineNum->setReadOnly(false);
        Logo = new QLabel(centralwidget);
        Logo->setObjectName(QString::fromUtf8("Logo"));
        Logo->setGeometry(QRect(10, 10, 200, 53));
        Logo->setPixmap(QPixmap(QString::fromUtf8(":/images/logo200x53.jpg")));
        ThinkDes = new QTextEdit(centralwidget);
        ThinkDes->setObjectName(QString::fromUtf8("ThinkDes"));
        ThinkDes->setGeometry(QRect(50, 635, 431, 71));
        ThinkDes->setFont(font1);
        ThinkDes->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        ThinkDes->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ThinkDes->setReadOnly(false);
        Label17 = new QLabel(centralwidget);
        Label17->setObjectName(QString::fromUtf8("Label17"));
        Label17->setGeometry(QRect(50, 600, 111, 31));
        Label17->setFont(font1);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 515, 701, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        FinishedButton = new QPushButton(centralwidget);
        FinishedButton->setObjectName(QString::fromUtf8("FinishedButton"));
        FinishedButton->setGeometry(QRect(500, 775, 121, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setWeight(75);
        FinishedButton->setFont(font3);
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
        label->setGeometry(QRect(5, 525, 711, 321));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(160, 175, 200);\n"
"border-radius: 15px;\n"
"border-style: outset;"));
        StataEdit = new QLineEdit(centralwidget);
        StataEdit->setObjectName(QString::fromUtf8("StataEdit"));
        StataEdit->setGeometry(QRect(320, 460, 181, 41));
        StataEdit->setFont(font1);
        StataEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        StataEdit->setReadOnly(false);
        ChangeCheck = new QCheckBox(centralwidget);
        ChangeCheck->setObjectName(QString::fromUtf8("ChangeCheck"));
        ChangeCheck->setGeometry(QRect(520, 640, 151, 16));
        QFont font4;
        font4.setPointSize(12);
        ChangeCheck->setFont(font4);
        ChangeCheck->setCursor(QCursor(Qt::PointingHandCursor));
        Label19 = new QLabel(centralwidget);
        Label19->setObjectName(QString::fromUtf8("Label19"));
        Label19->setGeometry(QRect(50, 715, 111, 31));
        Label19->setFont(font1);
        ProceDes = new QTextEdit(centralwidget);
        ProceDes->setObjectName(QString::fromUtf8("ProceDes"));
        ProceDes->setGeometry(QRect(50, 750, 431, 71));
        ProceDes->setFont(font1);
        ProceDes->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        ProceDes->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProceDes->setReadOnly(false);
        Label15 = new QLabel(centralwidget);
        Label15->setObjectName(QString::fromUtf8("Label15"));
        Label15->setGeometry(QRect(110, 555, 111, 31));
        Label15->setFont(font1);
        ChangeID = new QLineEdit(centralwidget);
        ChangeID->setObjectName(QString::fromUtf8("ChangeID"));
        ChangeID->setGeometry(QRect(220, 550, 211, 41));
        ChangeID->setFont(font1);
        ChangeID->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ChangeID->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        ChangeID->setReadOnly(false);
        Label16 = new QLabel(centralwidget);
        Label16->setObjectName(QString::fromUtf8("Label16"));
        Label16->setGeometry(QRect(440, 555, 111, 31));
        Label16->setFont(font1);
        ChangeNum = new QLineEdit(centralwidget);
        ChangeNum->setObjectName(QString::fromUtf8("ChangeNum"));
        ChangeNum->setGeometry(QRect(550, 550, 111, 41));
        ChangeNum->setFont(font1);
        ChangeNum->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ChangeNum->setAlignment(Qt::AlignCenter);
        ChangeNum->setReadOnly(false);
        HistoryButton = new QPushButton(centralwidget);
        HistoryButton->setObjectName(QString::fromUtf8("HistoryButton"));
        HistoryButton->setGeometry(QRect(550, 10, 161, 51));
        HistoryButton->setFont(font3);
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
        AddCheck->setGeometry(QRect(540, 260, 151, 16));
        AddCheck->setFont(font4);
        AddCheck->setCursor(QCursor(Qt::PointingHandCursor));
        ReturnButton = new QPushButton(centralwidget);
        ReturnButton->setObjectName(QString::fromUtf8("ReturnButton"));
        ReturnButton->setGeometry(QRect(630, 775, 71, 51));
        ReturnButton->setFont(font3);
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
        DownTime = new QLineEdit(centralwidget);
        DownTime->setObjectName(QString::fromUtf8("DownTime"));
        DownTime->setGeometry(QRect(140, 290, 121, 41));
        DownTime->setFont(font1);
        DownTime->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        DownTime->setAlignment(Qt::AlignCenter);
        DownTime->setReadOnly(false);
        Label6 = new QLabel(centralwidget);
        Label6->setObjectName(QString::fromUtf8("Label6"));
        Label6->setGeometry(QRect(30, 295, 111, 31));
        Label6->setFont(font1);
        DirTime = new QLineEdit(centralwidget);
        DirTime->setObjectName(QString::fromUtf8("DirTime"));
        DirTime->setGeometry(QRect(390, 290, 201, 41));
        DirTime->setFont(font1);
        DirTime->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        DirTime->setAlignment(Qt::AlignCenter);
        DirTime->setReadOnly(false);
        Label7 = new QLabel(centralwidget);
        Label7->setObjectName(QString::fromUtf8("Label7"));
        Label7->setGeometry(QRect(280, 295, 111, 31));
        Label7->setFont(font1);
        OutNum = new QSpinBox(centralwidget);
        OutNum->setObjectName(QString::fromUtf8("OutNum"));
        OutNum->setGeometry(QRect(530, 210, 61, 41));
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
        OutLabel->setGeometry(QRect(600, 210, 41, 41));
        OutLabel->setFont(font1);
        ProductID = new QTextEdit(centralwidget);
        ProductID->setObjectName(QString::fromUtf8("ProductID"));
        ProductID->setGeometry(QRect(140, 210, 261, 61));
        ProductID->setFont(font1);
        ProductID->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        ProductID->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductID->setReadOnly(false);
        Label4_2 = new QLabel(centralwidget);
        Label4_2->setObjectName(QString::fromUtf8("Label4_2"));
        Label4_2->setGeometry(QRect(30, 215, 111, 31));
        Label4_2->setFont(font1);
        LifeNum = new QLineEdit(centralwidget);
        LifeNum->setObjectName(QString::fromUtf8("LifeNum"));
        LifeNum->setGeometry(QRect(610, 150, 81, 41));
        LifeNum->setFont(font1);
        LifeNum->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        LifeNum->setAlignment(Qt::AlignCenter);
        LifeNum->setReadOnly(false);
        GetButton = new QPushButton(centralwidget);
        GetButton->setObjectName(QString::fromUtf8("GetButton"));
        GetButton->setGeometry(QRect(650, 460, 51, 46));
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
        SumoKeep->setCentralWidget(centralwidget);
        label->raise();
        BackGround->raise();
        DirRepair->raise();
        Label13->raise();
        Label12->raise();
        Operater->raise();
        Label1->raise();
        Label3->raise();
        DateTime->raise();
        Label4_1->raise();
        Label2->raise();
        ProductName->raise();
        MoldID->raise();
        Label10->raise();
        StataDes->raise();
        Label14->raise();
        ProblemDes->raise();
        Label11->raise();
        Label5->raise();
        MachineNum->raise();
        Logo->raise();
        ThinkDes->raise();
        Label17->raise();
        line->raise();
        FinishedButton->raise();
        StataEdit->raise();
        ChangeCheck->raise();
        Label19->raise();
        ProceDes->raise();
        Label15->raise();
        ChangeID->raise();
        Label16->raise();
        ChangeNum->raise();
        HistoryButton->raise();
        AddCheck->raise();
        ReturnButton->raise();
        DownTime->raise();
        Label6->raise();
        DirTime->raise();
        Label7->raise();
        OutNum->raise();
        OutLabel->raise();
        ProductID->raise();
        Label4_2->raise();
        LifeNum->raise();
        GetButton->raise();
        menubar = new QMenuBar(SumoKeep);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 720, 23));
        SumoKeep->setMenuBar(menubar);
        statusbar = new QStatusBar(SumoKeep);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SumoKeep->setStatusBar(statusbar);
        QWidget::setTabOrder(MoldID, DateTime);
        QWidget::setTabOrder(DateTime, ProductName);
        QWidget::setTabOrder(ProductName, MachineNum);
        QWidget::setTabOrder(MachineNum, LifeNum);
        QWidget::setTabOrder(LifeNum, ProductID);
        QWidget::setTabOrder(ProductID, OutNum);
        QWidget::setTabOrder(OutNum, AddCheck);
        QWidget::setTabOrder(AddCheck, DownTime);
        QWidget::setTabOrder(DownTime, DirTime);
        QWidget::setTabOrder(DirTime, ProblemDes);
        QWidget::setTabOrder(ProblemDes, Operater);
        QWidget::setTabOrder(Operater, DirRepair);
        QWidget::setTabOrder(DirRepair, StataDes);
        QWidget::setTabOrder(StataDes, StataEdit);
        QWidget::setTabOrder(StataEdit, ChangeID);
        QWidget::setTabOrder(ChangeID, ChangeNum);
        QWidget::setTabOrder(ChangeNum, ThinkDes);
        QWidget::setTabOrder(ThinkDes, ChangeCheck);
        QWidget::setTabOrder(ChangeCheck, ProceDes);
        QWidget::setTabOrder(ProceDes, FinishedButton);
        QWidget::setTabOrder(FinishedButton, ReturnButton);
        QWidget::setTabOrder(ReturnButton, GetButton);
        QWidget::setTabOrder(GetButton, HistoryButton);

        retranslateUi(SumoKeep);

        QMetaObject::connectSlotsByName(SumoKeep);
    } // setupUi

    void retranslateUi(QMainWindow *SumoKeep)
    {
        SumoKeep->setWindowTitle(QCoreApplication::translate("SumoKeep", "MainWindow", nullptr));
        Label13->setText(QCoreApplication::translate("SumoKeep", "\347\273\264\344\277\256\345\221\230:", nullptr));
        Label12->setText(QCoreApplication::translate("SumoKeep", "\350\260\203\346\234\272\345\221\230:", nullptr));
        Label1->setText(QCoreApplication::translate("SumoKeep", "\346\250\241\345\205\267\347\273\264\344\277\256&\344\277\235\345\205\273", nullptr));
        Label3->setText(QCoreApplication::translate("SumoKeep", "\346\227\245\346\234\237:", nullptr));
        DateTime->setPlaceholderText(QCoreApplication::translate("SumoKeep", "yyyy.MM.dd", nullptr));
        Label4_1->setText(QCoreApplication::translate("SumoKeep", "\344\272\247\345\223\201\345\220\215\347\247\260:", nullptr));
        Label2->setText(QCoreApplication::translate("SumoKeep", "\346\250\241\345\217\267:", nullptr));
        ProductName->setPlaceholderText(QCoreApplication::translate("SumoKeep", "\350\257\267\350\276\223\345\205\245\344\272\247\345\223\201\345\220\215\347\247\260", nullptr));
        MoldID->setPlaceholderText(QCoreApplication::translate("SumoKeep", "\350\257\267\350\276\223\345\205\245\346\250\241\345\217\267", nullptr));
        Label10->setText(QCoreApplication::translate("SumoKeep", "\346\250\241\345\205\267\347\251\264\346\225\260:", nullptr));
        Label14->setText(QCoreApplication::translate("SumoKeep", "\344\277\235\345\205\273\346\226\271\345\274\217:", nullptr));
        ProblemDes->setPlaceholderText(QCoreApplication::translate("SumoKeep", "\350\257\267\350\276\223\345\205\245\346\250\241\345\205\267\345\255\230\345\234\250\351\227\256\351\242\230", nullptr));
        Label11->setText(QCoreApplication::translate("SumoKeep", "\345\274\202\345\270\270\347\212\266\346\200\201:", nullptr));
        BackGround->setText(QString());
        Label5->setText(QCoreApplication::translate("SumoKeep", "\346\234\272\345\217\260\345\217\267:", nullptr));
        MachineNum->setPlaceholderText(QCoreApplication::translate("SumoKeep", "#6", nullptr));
        Logo->setText(QString());
        ThinkDes->setPlaceholderText(QCoreApplication::translate("SumoKeep", "\350\257\267\350\276\223\345\205\245\346\250\241\345\205\267\345\244\204\347\220\206\345\257\271\347\255\226", nullptr));
        Label17->setText(QCoreApplication::translate("SumoKeep", "\345\216\237\345\233\240\345\210\206\346\236\220:", nullptr));
        FinishedButton->setText(QCoreApplication::translate("SumoKeep", "\346\267\273\345\212\240\346\225\260\346\215\256", nullptr));
        label->setText(QString());
        StataEdit->setPlaceholderText(QCoreApplication::translate("SumoKeep", "\350\257\267\350\276\223\345\205\245\345\205\266\345\256\203\347\212\266\346\200\201", nullptr));
        ChangeCheck->setText(QCoreApplication::translate("SumoKeep", "\346\230\257\345\220\246\351\234\200\350\246\201\346\233\264\346\215\242\345\244\207\344\273\266", nullptr));
        Label19->setText(QCoreApplication::translate("SumoKeep", "\345\244\204\347\220\206\345\257\271\347\255\226:", nullptr));
        ProceDes->setPlaceholderText(QCoreApplication::translate("SumoKeep", "\350\257\267\350\276\223\345\205\245\345\244\207\346\263\250\345\206\205\345\256\271", nullptr));
        Label15->setText(QCoreApplication::translate("SumoKeep", "\346\233\264\346\215\242\345\244\207\344\273\266:", nullptr));
        ChangeID->setPlaceholderText(QCoreApplication::translate("SumoKeep", "\350\257\267\350\276\223\345\205\245\345\244\207\344\273\266\345\217\267", nullptr));
        Label16->setText(QCoreApplication::translate("SumoKeep", "\350\276\223\345\205\245\346\225\260\351\207\217:", nullptr));
        ChangeNum->setPlaceholderText(QString());
        HistoryButton->setText(QCoreApplication::translate("SumoKeep", "\345\257\274\345\207\272\345\216\206\345\217\262", nullptr));
        AddCheck->setText(QCoreApplication::translate("SumoKeep", "\346\230\257\345\220\246\351\234\200\350\246\201\351\231\204\345\212\240\344\277\235\345\205\273", nullptr));
        ReturnButton->setText(QCoreApplication::translate("SumoKeep", "\346\222\244\345\233\236", nullptr));
        DownTime->setText(QString());
        DownTime->setPlaceholderText(QCoreApplication::translate("SumoKeep", "hh:mm:ss", nullptr));
        Label6->setText(QCoreApplication::translate("SumoKeep", "\344\270\213\347\272\277\346\227\266\351\227\264:", nullptr));
        DirTime->setText(QString());
        DirTime->setPlaceholderText(QCoreApplication::translate("SumoKeep", "hh:mm:ss", nullptr));
        Label7->setText(QCoreApplication::translate("SumoKeep", "\347\273\264\344\277\256\346\227\266\351\227\264:", nullptr));
        OutLabel->setText(QCoreApplication::translate("SumoKeep", "/n", nullptr));
        ProductID->setPlaceholderText(QCoreApplication::translate("SumoKeep", "\350\257\267\350\276\223\345\205\245\344\272\247\345\223\201\346\226\231\345\217\267", nullptr));
        Label4_2->setText(QCoreApplication::translate("SumoKeep", "\344\272\247\345\223\201\346\226\231\345\217\267:", nullptr));
        LifeNum->setPlaceholderText(QCoreApplication::translate("SumoKeep", "666", nullptr));
        GetButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SumoKeep: public Ui_SumoKeep {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUMOKEEP_H
