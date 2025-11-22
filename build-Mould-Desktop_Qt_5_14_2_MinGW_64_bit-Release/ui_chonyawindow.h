/********************************************************************************
** Form generated from reading UI file 'chonyawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHONYAWINDOW_H
#define UI_CHONYAWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChonyaWindow
{
public:
    QWidget *centralwidget;
    QLabel *LogoLabel;
    QPushButton *AddButton;
    QPushButton *EnterButton;
    QPushButton *KeepButton;
    QPushButton *WorkButton;
    QPushButton *BomButton;
    QWidget *widget_1;
    QGridLayout *gridLayout;
    QTableView *ModleList;
    QLabel *label;
    QWidget *widget_2;
    QPushButton *RefreshButton;
    QTableWidget *RuleView;
    QLabel *Label5;
    QPushButton *EditButton;
    QTextEdit *KeepStatus;
    QLabel *Label4;
    QPushButton *FindButton;
    QLineEdit *DateNum;
    QLabel *Label7;
    QLabel *Label9;
    QLabel *Label8;
    QLineEdit *ControlStand;
    QLineEdit *MoldID;
    QLabel *Label2;
    QLineEdit *ProductStand;
    QLineEdit *MachineNum;
    QTextEdit *ProductID;
    QPushButton *DeleteButton;
    QLabel *Label6;
    QLabel *Label1;
    QLabel *Label3;
    QLineEdit *DirRepair;
    QPushButton *MessageLabel;
    QPushButton *AIButton;
    QCommandLinkButton *commandLinkButton;
    QPushButton *ReturnButton;
    QPushButton *CheckButton;
    QMenuBar *menubar;

    void setupUi(QMainWindow *ChonyaWindow)
    {
        if (ChonyaWindow->objectName().isEmpty())
            ChonyaWindow->setObjectName(QString::fromUtf8("ChonyaWindow"));
        ChonyaWindow->resize(1170, 850);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChonyaWindow->sizePolicy().hasHeightForWidth());
        ChonyaWindow->setSizePolicy(sizePolicy);
        ChonyaWindow->setMinimumSize(QSize(1170, 850));
        ChonyaWindow->setMaximumSize(QSize(1170, 850));
        QFont font;
        font.setFamily(QString::fromUtf8("3ds"));
        font.setPointSize(16);
        ChonyaWindow->setFont(font);
        ChonyaWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(ChonyaWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        centralwidget->setMinimumSize(QSize(800, 600));
        LogoLabel = new QLabel(centralwidget);
        LogoLabel->setObjectName(QString::fromUtf8("LogoLabel"));
        LogoLabel->setGeometry(QRect(1030, 810, 200, 53));
        LogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/static2(1).png")));
        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setEnabled(false);
        AddButton->setGeometry(QRect(110, 20, 181, 61));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(AddButton->sizePolicy().hasHeightForWidth());
        AddButton->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        AddButton->setFont(font1);
        AddButton->setCursor(QCursor(Qt::PointingHandCursor));
        AddButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:white;\n"
"	background-color: rgb(85, 170, 255);\n"
"	border-radius: 20px;  border: 2px groove lavender;\n"
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddButton->setIcon(icon);
        AddButton->setIconSize(QSize(24, 24));
        EnterButton = new QPushButton(centralwidget);
        EnterButton->setObjectName(QString::fromUtf8("EnterButton"));
        EnterButton->setEnabled(false);
        EnterButton->setGeometry(QRect(310, 20, 181, 61));
        sizePolicy1.setHeightForWidth(EnterButton->sizePolicy().hasHeightForWidth());
        EnterButton->setSizePolicy(sizePolicy1);
        EnterButton->setFont(font1);
        EnterButton->setCursor(QCursor(Qt::PointingHandCursor));
        EnterButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:white;\n"
"	background-color: rgb(85, 170, 255);\n"
"	border-radius: 20px;  border: 2px groove lavender;\n"
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/enter.png"), QSize(), QIcon::Normal, QIcon::Off);
        EnterButton->setIcon(icon1);
        EnterButton->setIconSize(QSize(24, 24));
        KeepButton = new QPushButton(centralwidget);
        KeepButton->setObjectName(QString::fromUtf8("KeepButton"));
        KeepButton->setGeometry(QRect(510, 20, 181, 61));
        sizePolicy1.setHeightForWidth(KeepButton->sizePolicy().hasHeightForWidth());
        KeepButton->setSizePolicy(sizePolicy1);
        KeepButton->setFont(font1);
        KeepButton->setCursor(QCursor(Qt::PointingHandCursor));
        KeepButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:white;\n"
"	background-color: rgb(85, 170, 255);\n"
"	border-radius: 20px;  border: 2px groove lavender;\n"
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/maintenance.png"), QSize(), QIcon::Normal, QIcon::Off);
        KeepButton->setIcon(icon2);
        KeepButton->setIconSize(QSize(24, 24));
        WorkButton = new QPushButton(centralwidget);
        WorkButton->setObjectName(QString::fromUtf8("WorkButton"));
        WorkButton->setGeometry(QRect(710, 20, 181, 61));
        sizePolicy1.setHeightForWidth(WorkButton->sizePolicy().hasHeightForWidth());
        WorkButton->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        WorkButton->setFont(font2);
        WorkButton->setCursor(QCursor(Qt::PointingHandCursor));
        WorkButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:white;\n"
"	background-color: rgb(85, 170, 255);\n"
"	border-radius: 20px;  border: 2px groove lavender;\n"
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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/work.png"), QSize(), QIcon::Normal, QIcon::Off);
        WorkButton->setIcon(icon3);
        WorkButton->setIconSize(QSize(24, 24));
        BomButton = new QPushButton(centralwidget);
        BomButton->setObjectName(QString::fromUtf8("BomButton"));
        BomButton->setGeometry(QRect(910, 20, 131, 61));
        BomButton->setFont(font1);
        BomButton->setCursor(QCursor(Qt::PointingHandCursor));
        BomButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:white;\n"
"	background-color: rgb(85, 170, 255);\n"
"	border-radius: 20px;  border: 2px groove lavender;\n"
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
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/data.png"), QSize(), QIcon::Normal, QIcon::Off);
        BomButton->setIcon(icon4);
        BomButton->setIconSize(QSize(24, 24));
        widget_1 = new QWidget(centralwidget);
        widget_1->setObjectName(QString::fromUtf8("widget_1"));
        widget_1->setGeometry(QRect(20, 90, 550, 750));
        widget_1->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	border-style: outset;\n"
"}"));
        gridLayout = new QGridLayout(widget_1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ModleList = new QTableView(widget_1);
        ModleList->setObjectName(QString::fromUtf8("ModleList"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(20);
        font3.setBold(false);
        font3.setWeight(50);
        ModleList->setFont(font3);
        ModleList->setStyleSheet(QString::fromUtf8("QTableView{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}\n"
"/* \350\256\276\347\275\256\350\241\250\345\244\264 */\n"
"QHeaderView::section {\n"
"    font-size: 20px;\n"
"}\n"
"/* \350\256\276\347\275\256\351\246\226\345\210\227\345\215\225\345\205\203\346\240\274\345\255\227\344\275\223 */\n"
"QTableView::item:first-column {\n"
"    font-size: 20px;\n"
"}\n"
""));
        ModleList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ModleList->setSelectionMode(QAbstractItemView::SingleSelection);
        ModleList->setSelectionBehavior(QAbstractItemView::SelectRows);
        ModleList->setSortingEnabled(true);
        ModleList->setWordWrap(false);
        ModleList->horizontalHeader()->setVisible(false);
        ModleList->horizontalHeader()->setCascadingSectionResizes(false);
        ModleList->horizontalHeader()->setHighlightSections(true);
        ModleList->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        ModleList->horizontalHeader()->setStretchLastSection(false);
        ModleList->verticalHeader()->setVisible(false);
        ModleList->verticalHeader()->setCascadingSectionResizes(false);
        ModleList->verticalHeader()->setHighlightSections(true);
        ModleList->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        ModleList->verticalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(ModleList, 0, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 15, 64, 64));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/chonya_logo.png")));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(580, 100, 560, 730));
        widget_2->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius: 25px;\n"
"	border-style: outset;\n"
"}\n"
"QMenu{\n"
"	background-color:palette(window);\n"
"	color:rgb(0, 0, 0);\n"
"}\n"
"QMenu::item{\n"
"  color:rgba(51,51,51,1);\n"
"}\n"
"QMenu::item:hover{\n"
"  background-color:#409CE1;\n"
"}\n"
"QMenu::item:selected{\n"
"  background-color:#409CE1;\n"
"}"));
        RefreshButton = new QPushButton(widget_2);
        RefreshButton->setObjectName(QString::fromUtf8("RefreshButton"));
        RefreshButton->setGeometry(QRect(450, 90, 46, 46));
        RefreshButton->setCursor(QCursor(Qt::PointingHandCursor));
        RefreshButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        RefreshButton->setIcon(icon5);
        RefreshButton->setIconSize(QSize(26, 26));
        RuleView = new QTableWidget(widget_2);
        RuleView->setObjectName(QString::fromUtf8("RuleView"));
        RuleView->setGeometry(QRect(170, 390, 322, 96));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(14);
        RuleView->setFont(font4);
        RuleView->setStyleSheet(QString::fromUtf8("QTableWidget {  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border-radius: 2px;\n"
"	border-style: outset;\n"
"	color: rgb(0,0,0);\n"
"	border: 1px solid rgb(200, 200, 200);\n"
"}"));
        RuleView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        RuleView->setSelectionMode(QAbstractItemView::NoSelection);
        RuleView->verticalHeader()->setVisible(false);
        Label5 = new QLabel(widget_2);
        Label5->setObjectName(QString::fromUtf8("Label5"));
        Label5->setGeometry(QRect(40, 185, 121, 31));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(20);
        Label5->setFont(font5);
        EditButton = new QPushButton(widget_2);
        EditButton->setObjectName(QString::fromUtf8("EditButton"));
        EditButton->setEnabled(false);
        EditButton->setGeometry(QRect(40, 625, 151, 51));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(EditButton->sizePolicy().hasHeightForWidth());
        EditButton->setSizePolicy(sizePolicy2);
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font6.setPointSize(16);
        font6.setBold(true);
        font6.setWeight(75);
        EditButton->setFont(font6);
        EditButton->setCursor(QCursor(Qt::PointingHandCursor));
        EditButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:white;\n"
"	background-color: rgb(85, 170, 255);\n"
"	border-radius: 20px;  border: 2px groove lavender;\n"
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
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/change.png"), QSize(), QIcon::Normal, QIcon::Off);
        EditButton->setIcon(icon6);
        EditButton->setIconSize(QSize(20, 20));
        KeepStatus = new QTextEdit(widget_2);
        KeepStatus->setObjectName(QString::fromUtf8("KeepStatus"));
        KeepStatus->setGeometry(QRect(170, 240, 321, 71));
        QFont font7;
        font7.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font7.setPointSize(18);
        KeepStatus->setFont(font7);
        KeepStatus->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        KeepStatus->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        KeepStatus->setReadOnly(true);
        Label4 = new QLabel(widget_2);
        Label4->setObjectName(QString::fromUtf8("Label4"));
        Label4->setGeometry(QRect(45, 570, 121, 31));
        Label4->setFont(font5);
        FindButton = new QPushButton(widget_2);
        FindButton->setObjectName(QString::fromUtf8("FindButton"));
        FindButton->setEnabled(true);
        FindButton->setGeometry(QRect(450, 30, 91, 41));
        sizePolicy2.setHeightForWidth(FindButton->sizePolicy().hasHeightForWidth());
        FindButton->setSizePolicy(sizePolicy2);
        FindButton->setFont(font6);
        FindButton->setCursor(QCursor(Qt::PointingHandCursor));
        FindButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"}\n"
"QPushButton:!enabled {   /*\346\214\211\351\222\256\347\246\201\347\224\250\346\227\266*/\n"
"	background: rgb(100, 100, 100);\n"
"	color: rgb(200, 200, 200);\n"
"}\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        FindButton->setIcon(icon7);
        FindButton->setIconSize(QSize(20, 20));
        DateNum = new QLineEdit(widget_2);
        DateNum->setObjectName(QString::fromUtf8("DateNum"));
        DateNum->setGeometry(QRect(330, 565, 171, 41));
        DateNum->setFont(font7);
        DateNum->setCursor(QCursor(Qt::ArrowCursor));
        DateNum->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        DateNum->setAlignment(Qt::AlignCenter);
        DateNum->setReadOnly(true);
        Label7 = new QLabel(widget_2);
        Label7->setObjectName(QString::fromUtf8("Label7"));
        Label7->setGeometry(QRect(40, 250, 121, 31));
        Label7->setFont(font5);
        Label9 = new QLabel(widget_2);
        Label9->setObjectName(QString::fromUtf8("Label9"));
        Label9->setGeometry(QRect(15, 510, 151, 31));
        Label9->setFont(font5);
        Label8 = new QLabel(widget_2);
        Label8->setObjectName(QString::fromUtf8("Label8"));
        Label8->setGeometry(QRect(260, 570, 61, 31));
        Label8->setFont(font5);
        ControlStand = new QLineEdit(widget_2);
        ControlStand->setObjectName(QString::fromUtf8("ControlStand"));
        ControlStand->setGeometry(QRect(170, 330, 321, 41));
        ControlStand->setFont(font7);
        ControlStand->setCursor(QCursor(Qt::ArrowCursor));
        ControlStand->setLayoutDirection(Qt::LeftToRight);
        ControlStand->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ControlStand->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        ControlStand->setReadOnly(true);
        MoldID = new QLineEdit(widget_2);
        MoldID->setObjectName(QString::fromUtf8("MoldID"));
        MoldID->setGeometry(QRect(170, 30, 261, 41));
        MoldID->setFont(font7);
        MoldID->setCursor(QCursor(Qt::IBeamCursor));
        MoldID->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MoldID->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        MoldID->setReadOnly(false);
        Label2 = new QLabel(widget_2);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(40, 35, 121, 31));
        Label2->setFont(font5);
        ProductStand = new QLineEdit(widget_2);
        ProductStand->setObjectName(QString::fromUtf8("ProductStand"));
        ProductStand->setGeometry(QRect(170, 180, 321, 41));
        ProductStand->setFont(font7);
        ProductStand->setCursor(QCursor(Qt::ArrowCursor));
        ProductStand->setLayoutDirection(Qt::LeftToRight);
        ProductStand->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductStand->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        ProductStand->setReadOnly(true);
        MachineNum = new QLineEdit(widget_2);
        MachineNum->setObjectName(QString::fromUtf8("MachineNum"));
        MachineNum->setGeometry(QRect(170, 565, 71, 41));
        MachineNum->setFont(font7);
        MachineNum->setCursor(QCursor(Qt::ArrowCursor));
        MachineNum->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MachineNum->setAlignment(Qt::AlignCenter);
        MachineNum->setReadOnly(true);
        ProductID = new QTextEdit(widget_2);
        ProductID->setObjectName(QString::fromUtf8("ProductID"));
        ProductID->setGeometry(QRect(170, 90, 261, 71));
        ProductID->setFont(font7);
        ProductID->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        ProductID->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductID->setReadOnly(true);
        DeleteButton = new QPushButton(widget_2);
        DeleteButton->setObjectName(QString::fromUtf8("DeleteButton"));
        DeleteButton->setEnabled(false);
        DeleteButton->setGeometry(QRect(230, 625, 151, 51));
        sizePolicy2.setHeightForWidth(DeleteButton->sizePolicy().hasHeightForWidth());
        DeleteButton->setSizePolicy(sizePolicy2);
        DeleteButton->setFont(font6);
        DeleteButton->setCursor(QCursor(Qt::PointingHandCursor));
        DeleteButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:white;\n"
"	background-color: rgb(85, 170, 255);\n"
"	border-radius: 20px;  border: 2px groove lavender;\n"
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
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        DeleteButton->setIcon(icon8);
        DeleteButton->setIconSize(QSize(20, 20));
        Label6 = new QLabel(widget_2);
        Label6->setObjectName(QString::fromUtf8("Label6"));
        Label6->setGeometry(QRect(40, 335, 121, 31));
        Label6->setFont(font5);
        Label1 = new QLabel(widget_2);
        Label1->setObjectName(QString::fromUtf8("Label1"));
        Label1->setGeometry(QRect(40, 400, 121, 31));
        sizePolicy2.setHeightForWidth(Label1->sizePolicy().hasHeightForWidth());
        Label1->setSizePolicy(sizePolicy2);
        Label1->setFont(font5);
        Label1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Label1->setWordWrap(false);
        Label3 = new QLabel(widget_2);
        Label3->setObjectName(QString::fromUtf8("Label3"));
        Label3->setGeometry(QRect(40, 100, 121, 31));
        Label3->setFont(font5);
        DirRepair = new QLineEdit(widget_2);
        DirRepair->setObjectName(QString::fromUtf8("DirRepair"));
        DirRepair->setGeometry(QRect(170, 505, 321, 41));
        DirRepair->setFont(font7);
        DirRepair->setCursor(QCursor(Qt::ArrowCursor));
        DirRepair->setLayoutDirection(Qt::LeftToRight);
        DirRepair->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        DirRepair->setAlignment(Qt::AlignCenter);
        DirRepair->setReadOnly(true);
        MessageLabel = new QPushButton(widget_2);
        MessageLabel->setObjectName(QString::fromUtf8("MessageLabel"));
        MessageLabel->setGeometry(QRect(80, 690, 191, 41));
        sizePolicy2.setHeightForWidth(MessageLabel->sizePolicy().hasHeightForWidth());
        MessageLabel->setSizePolicy(sizePolicy2);
        QFont font8;
        font8.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font8.setPointSize(16);
        font8.setBold(false);
        font8.setWeight(50);
        MessageLabel->setFont(font8);
        MessageLabel->setCursor(QCursor(Qt::PointingHandCursor));
        MessageLabel->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:black;\n"
"	background-color: rgb(255,255,255);\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{  /*\351\274\240\346\240\207\346\202\254\346\265\256\346\227\266*/\n"
"	background: rgb(49,106,234);\n"
"}\n"
"QPushButton:pressed{  /*\351\274\240\346\240\207\346\214\211\344\270\213\346\227\266*/\n"
"	background-color: rgb(255,255,255);\n"
"	color: rgb(200, 200, 200);\n"
"}"));
        AIButton = new QPushButton(widget_2);
        AIButton->setObjectName(QString::fromUtf8("AIButton"));
        AIButton->setGeometry(QRect(490, 680, 61, 46));
        QFont font9;
        font9.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font9.setPointSize(18);
        font9.setBold(false);
        font9.setWeight(50);
        AIButton->setFont(font9);
        AIButton->setCursor(QCursor(Qt::PointingHandCursor));
        AIButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:white;\n"
"	background-color: rgb(85, 170, 255);\n"
"	border-radius: 20px;  border: 2px groove lavender;\n"
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
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/ai.png"), QSize(), QIcon::Normal, QIcon::Off);
        AIButton->setIcon(icon9);
        AIButton->setIconSize(QSize(36, 36));
        commandLinkButton = new QCommandLinkButton(widget_2);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(390, 690, 101, 41));
        commandLinkButton->setCursor(QCursor(Qt::PointingHandCursor));
        ReturnButton = new QPushButton(widget_2);
        ReturnButton->setObjectName(QString::fromUtf8("ReturnButton"));
        ReturnButton->setGeometry(QRect(430, 625, 101, 51));
        ReturnButton->setFont(font9);
        ReturnButton->setCursor(QCursor(Qt::PointingHandCursor));
        ReturnButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:white;\n"
"	background-color: rgb(85, 170, 255);\n"
"	border-radius: 20px;  border: 2px groove lavender;\n"
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
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/return.png"), QSize(), QIcon::Normal, QIcon::Off);
        ReturnButton->setIcon(icon10);
        ReturnButton->setIconSize(QSize(20, 20));
        CheckButton = new QPushButton(centralwidget);
        CheckButton->setObjectName(QString::fromUtf8("CheckButton"));
        CheckButton->setEnabled(true);
        CheckButton->setGeometry(QRect(1060, 20, 101, 61));
        sizePolicy1.setHeightForWidth(CheckButton->sizePolicy().hasHeightForWidth());
        CheckButton->setSizePolicy(sizePolicy1);
        CheckButton->setFont(font1);
        CheckButton->setCursor(QCursor(Qt::PointingHandCursor));
        CheckButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:white;\n"
"	background-color: rgb(85, 170, 255);\n"
"	border-radius: 20px;  border: 2px groove lavender;\n"
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
"}"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        CheckButton->setIcon(icon11);
        CheckButton->setIconSize(QSize(20, 20));
        ChonyaWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChonyaWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1170, 23));
        ChonyaWindow->setMenuBar(menubar);
        QWidget::setTabOrder(ModleList, MoldID);
        QWidget::setTabOrder(MoldID, FindButton);
        QWidget::setTabOrder(FindButton, ProductID);
        QWidget::setTabOrder(ProductID, ProductStand);
        QWidget::setTabOrder(ProductStand, KeepStatus);
        QWidget::setTabOrder(KeepStatus, ControlStand);
        QWidget::setTabOrder(ControlStand, RuleView);
        QWidget::setTabOrder(RuleView, DirRepair);
        QWidget::setTabOrder(DirRepair, MachineNum);
        QWidget::setTabOrder(MachineNum, DateNum);
        QWidget::setTabOrder(DateNum, RefreshButton);
        QWidget::setTabOrder(RefreshButton, EditButton);
        QWidget::setTabOrder(EditButton, DeleteButton);
        QWidget::setTabOrder(DeleteButton, ReturnButton);
        QWidget::setTabOrder(ReturnButton, MessageLabel);
        QWidget::setTabOrder(MessageLabel, commandLinkButton);
        QWidget::setTabOrder(commandLinkButton, AIButton);
        QWidget::setTabOrder(AIButton, AddButton);
        QWidget::setTabOrder(AddButton, EnterButton);
        QWidget::setTabOrder(EnterButton, KeepButton);
        QWidget::setTabOrder(KeepButton, WorkButton);
        QWidget::setTabOrder(WorkButton, BomButton);
        QWidget::setTabOrder(BomButton, CheckButton);

        retranslateUi(ChonyaWindow);

        QMetaObject::connectSlotsByName(ChonyaWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChonyaWindow)
    {
        ChonyaWindow->setWindowTitle(QCoreApplication::translate("ChonyaWindow", "MainWindow", nullptr));
        LogoLabel->setText(QString());
        AddButton->setText(QCoreApplication::translate("ChonyaWindow", "\346\226\260\345\242\236\346\250\241\345\205\267", nullptr));
        EnterButton->setText(QCoreApplication::translate("ChonyaWindow", "\344\272\247\351\207\217\345\275\225\345\205\245", nullptr));
        KeepButton->setText(QCoreApplication::translate("ChonyaWindow", "\347\273\264\346\212\244\347\256\241\347\220\206", nullptr));
        WorkButton->setText(QCoreApplication::translate("ChonyaWindow", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
        BomButton->setText(QCoreApplication::translate("ChonyaWindow", "BOM", nullptr));
        label->setText(QString());
        RefreshButton->setText(QString());
        Label5->setText(QCoreApplication::translate("ChonyaWindow", "\346\235\220\346\226\231\350\247\204\346\240\274:", nullptr));
        EditButton->setText(QCoreApplication::translate("ChonyaWindow", "\345\217\202\346\225\260\344\277\256\346\224\271", nullptr));
        Label4->setText(QCoreApplication::translate("ChonyaWindow", "\345\275\223\345\211\215\346\234\272\345\217\260:", nullptr));
        FindButton->setText(QCoreApplication::translate("ChonyaWindow", "\346\237\245\346\211\276", nullptr));
        Label7->setText(QCoreApplication::translate("ChonyaWindow", "\344\277\235\345\205\273\347\212\266\345\206\265:", nullptr));
        Label9->setText(QCoreApplication::translate("ChonyaWindow", "\344\277\256\346\250\241\346\212\200\346\234\257\345\221\230:", nullptr));
        Label8->setText(QCoreApplication::translate("ChonyaWindow", "\346\227\245\346\234\237:", nullptr));
        Label2->setText(QCoreApplication::translate("ChonyaWindow", "\346\250\241\345\205\267\347\274\226\345\217\267:", nullptr));
        DeleteButton->setText(QCoreApplication::translate("ChonyaWindow", "\345\210\240\351\231\244\346\250\241\345\205\267", nullptr));
        Label6->setText(QCoreApplication::translate("ChonyaWindow", "\347\256\241\345\210\266\346\240\207\345\207\206:", nullptr));
        Label1->setText(QCoreApplication::translate("ChonyaWindow", "\347\256\241\345\210\266\347\264\257\350\256\241:", nullptr));
        Label3->setText(QCoreApplication::translate("ChonyaWindow", "\344\272\247\345\223\201\346\226\231\345\217\267:", nullptr));
        MessageLabel->setText(QCoreApplication::translate("ChonyaWindow", "\345\275\223\345\211\215\346\266\210\346\201\257\346\235\241\346\225\260\357\274\2100\357\274\211", nullptr));
        AIButton->setText(QString());
        commandLinkButton->setText(QCoreApplication::translate("ChonyaWindow", "Database", nullptr));
        ReturnButton->setText(QCoreApplication::translate("ChonyaWindow", "\350\277\224\345\233\236", nullptr));
        CheckButton->setText(QCoreApplication::translate("ChonyaWindow", "\347\233\230\347\202\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChonyaWindow: public Ui_ChonyaWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHONYAWINDOW_H
