/********************************************************************************
** Form generated from reading UI file 'warehouseadd.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAREHOUSEADD_H
#define UI_WAREHOUSEADD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WarehouseAdd
{
public:
    QWidget *centralwidget;
    QWidget *widget2;
    QLabel *Label9;
    QLineEdit *MaterialEdit;
    QLabel *Label13;
    QComboBox *PartCombo_2;
    QLabel *Label8;
    QLineEdit *MoldEdit;
    QLineEdit *ProductEdit;
    QLabel *Label11;
    QPushButton *AddButton1;
    QLineEdit *CustomEdit;
    QLabel *Label10;
    QPushButton *ToAddButton;
    QLabel *Back2;
    QLabel *MoldNum;
    QLabel *Label14;
    QLabel *LogoLabel;
    QLabel *Label12;
    QLineEdit *MouldEdit;
    QWidget *widget3;
    QComboBox *MoldCombo;
    QLabel *Label18;
    QComboBox *CabinetCombo;
    QSpinBox *SaveEdit;
    QLineEdit *SpareEdit;
    QLabel *Label16;
    QLabel *Label15;
    QLabel *Label17;
    QPushButton *AddButton2;
    QLineEdit *OtherEdit;
    QLabel *Label19;
    QLabel *Back3;
    QPushButton *ExcleButton;
    QLineEdit *PriceEdit;
    QLabel *Label20;
    QWidget *widget1;
    QLineEdit *FMoldEdit;
    QLineEdit *CabinetEdit;
    QLineEdit *NumEdit;
    QPushButton *AddButton3;
    QLabel *Label5;
    QPushButton *ReturnButton;
    QLabel *Label6;
    QLabel *Label2;
    QLabel *Label1;
    QTreeView *NameView;
    QPushButton *FindButton;
    QLabel *Label4;
    QLineEdit *FSpareEdit;
    QLabel *SpareNum;
    QLabel *Label3;
    QLabel *Back1;
    QComboBox *PartCombo_1;
    QLabel *Label7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WarehouseAdd)
    {
        if (WarehouseAdd->objectName().isEmpty())
            WarehouseAdd->setObjectName(QString::fromUtf8("WarehouseAdd"));
        WarehouseAdd->resize(1410, 540);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WarehouseAdd->sizePolicy().hasHeightForWidth());
        WarehouseAdd->setSizePolicy(sizePolicy);
        WarehouseAdd->setMinimumSize(QSize(1410, 540));
        WarehouseAdd->setMaximumSize(QSize(1410, 540));
        centralwidget = new QWidget(WarehouseAdd);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget2 = new QWidget(centralwidget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(10, 10, 710, 310));
        widget2->setStyleSheet(QString::fromUtf8(""));
        Label9 = new QLabel(widget2);
        Label9->setObjectName(QString::fromUtf8("Label9"));
        Label9->setGeometry(QRect(30, 80, 161, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(18);
        Label9->setFont(font);
        MaterialEdit = new QLineEdit(widget2);
        MaterialEdit->setObjectName(QString::fromUtf8("MaterialEdit"));
        MaterialEdit->setGeometry(QRect(190, 135, 151, 41));
        MaterialEdit->setFont(font);
        MaterialEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MaterialEdit->setReadOnly(false);
        Label13 = new QLabel(widget2);
        Label13->setObjectName(QString::fromUtf8("Label13"));
        Label13->setGeometry(QRect(30, 205, 161, 31));
        Label13->setFont(font);
        PartCombo_2 = new QComboBox(widget2);
        PartCombo_2->addItem(QString());
        PartCombo_2->addItem(QString());
        PartCombo_2->setObjectName(QString::fromUtf8("PartCombo_2"));
        PartCombo_2->setGeometry(QRect(480, 20, 81, 41));
        PartCombo_2->setFont(font);
        PartCombo_2->setCursor(QCursor(Qt::ArrowCursor));
        PartCombo_2->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        Label8 = new QLabel(widget2);
        Label8->setObjectName(QString::fromUtf8("Label8"));
        Label8->setGeometry(QRect(370, 25, 111, 31));
        Label8->setFont(font);
        MoldEdit = new QLineEdit(widget2);
        MoldEdit->setObjectName(QString::fromUtf8("MoldEdit"));
        MoldEdit->setGeometry(QRect(190, 75, 151, 41));
        MoldEdit->setFont(font);
        MoldEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MoldEdit->setReadOnly(false);
        ProductEdit = new QLineEdit(widget2);
        ProductEdit->setObjectName(QString::fromUtf8("ProductEdit"));
        ProductEdit->setGeometry(QRect(190, 200, 471, 41));
        ProductEdit->setFont(font);
        ProductEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductEdit->setReadOnly(false);
        Label11 = new QLabel(widget2);
        Label11->setObjectName(QString::fromUtf8("Label11"));
        Label11->setGeometry(QRect(30, 140, 161, 31));
        Label11->setFont(font);
        AddButton1 = new QPushButton(widget2);
        AddButton1->setObjectName(QString::fromUtf8("AddButton1"));
        AddButton1->setGeometry(QRect(540, 250, 141, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(16);
        AddButton1->setFont(font1);
        AddButton1->setCursor(QCursor(Qt::PointingHandCursor));
        AddButton1->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddButton1->setIcon(icon);
        AddButton1->setIconSize(QSize(20, 20));
        CustomEdit = new QLineEdit(widget2);
        CustomEdit->setObjectName(QString::fromUtf8("CustomEdit"));
        CustomEdit->setGeometry(QRect(530, 75, 151, 41));
        CustomEdit->setFont(font);
        CustomEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        CustomEdit->setReadOnly(false);
        Label10 = new QLabel(widget2);
        Label10->setObjectName(QString::fromUtf8("Label10"));
        Label10->setGeometry(QRect(370, 80, 161, 31));
        Label10->setFont(font);
        ToAddButton = new QPushButton(widget2);
        ToAddButton->setObjectName(QString::fromUtf8("ToAddButton"));
        ToAddButton->setGeometry(QRect(370, 250, 141, 51));
        ToAddButton->setFont(font1);
        ToAddButton->setCursor(QCursor(Qt::PointingHandCursor));
        ToAddButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"}"));
        ToAddButton->setIcon(icon);
        ToAddButton->setIconSize(QSize(20, 20));
        Back2 = new QLabel(widget2);
        Back2->setObjectName(QString::fromUtf8("Back2"));
        Back2->setGeometry(QRect(0, 0, 711, 311));
        Back2->setStyleSheet(QString::fromUtf8("background-color: rgb(160, 175, 200);\n"
"border-radius: 20px;\n"
"border-style: outset;"));
        MoldNum = new QLabel(widget2);
        MoldNum->setObjectName(QString::fromUtf8("MoldNum"));
        MoldNum->setGeometry(QRect(240, 260, 81, 31));
        MoldNum->setFont(font);
        Label14 = new QLabel(widget2);
        Label14->setObjectName(QString::fromUtf8("Label14"));
        Label14->setGeometry(QRect(30, 260, 211, 31));
        Label14->setFont(font);
        LogoLabel = new QLabel(widget2);
        LogoLabel->setObjectName(QString::fromUtf8("LogoLabel"));
        LogoLabel->setGeometry(QRect(10, 10, 200, 53));
        LogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/logo_mat200x53.png")));
        Label12 = new QLabel(widget2);
        Label12->setObjectName(QString::fromUtf8("Label12"));
        Label12->setGeometry(QRect(370, 140, 161, 31));
        Label12->setFont(font);
        MouldEdit = new QLineEdit(widget2);
        MouldEdit->setObjectName(QString::fromUtf8("MouldEdit"));
        MouldEdit->setGeometry(QRect(530, 135, 151, 41));
        MouldEdit->setFont(font);
        MouldEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MouldEdit->setReadOnly(false);
        Back2->raise();
        Label9->raise();
        MaterialEdit->raise();
        Label13->raise();
        PartCombo_2->raise();
        Label8->raise();
        MoldEdit->raise();
        ProductEdit->raise();
        Label11->raise();
        AddButton1->raise();
        CustomEdit->raise();
        Label10->raise();
        ToAddButton->raise();
        MoldNum->raise();
        Label14->raise();
        LogoLabel->raise();
        Label12->raise();
        MouldEdit->raise();
        widget3 = new QWidget(centralwidget);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(10, 320, 710, 200));
        widget3->setStyleSheet(QString::fromUtf8(""));
        MoldCombo = new QComboBox(widget3);
        MoldCombo->setObjectName(QString::fromUtf8("MoldCombo"));
        MoldCombo->setGeometry(QRect(140, 20, 171, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        MoldCombo->setFont(font2);
        MoldCombo->setCursor(QCursor(Qt::ArrowCursor));
        MoldCombo->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(230,230,250);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        MoldCombo->setEditable(true);
        Label18 = new QLabel(widget3);
        Label18->setObjectName(QString::fromUtf8("Label18"));
        Label18->setGeometry(QRect(350, 85, 111, 31));
        Label18->setFont(font);
        CabinetCombo = new QComboBox(widget3);
        CabinetCombo->setObjectName(QString::fromUtf8("CabinetCombo"));
        CabinetCombo->setGeometry(QRect(460, 80, 131, 41));
        CabinetCombo->setFont(font2);
        CabinetCombo->setCursor(QCursor(Qt::ArrowCursor));
        CabinetCombo->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(230,230,250);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        CabinetCombo->setEditable(true);
        SaveEdit = new QSpinBox(widget3);
        SaveEdit->setObjectName(QString::fromUtf8("SaveEdit"));
        SaveEdit->setGeometry(QRect(490, 20, 61, 41));
        SaveEdit->setCursor(QCursor(Qt::ArrowCursor));
        SaveEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(230,230,250);\n"
"border: none;\n"
"border-radius: 2px;\n"
"color: rgb(0,0,0);\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        SaveEdit->setMaximum(999);
        SaveEdit->setStepType(QAbstractSpinBox::DefaultStepType);
        SpareEdit = new QLineEdit(widget3);
        SpareEdit->setObjectName(QString::fromUtf8("SpareEdit"));
        SpareEdit->setGeometry(QRect(165, 80, 151, 41));
        SpareEdit->setFont(font);
        SpareEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(230,230,250);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        SpareEdit->setReadOnly(false);
        Label16 = new QLabel(widget3);
        Label16->setObjectName(QString::fromUtf8("Label16"));
        Label16->setGeometry(QRect(330, 25, 161, 31));
        Label16->setFont(font);
        Label15 = new QLabel(widget3);
        Label15->setObjectName(QString::fromUtf8("Label15"));
        Label15->setGeometry(QRect(30, 25, 111, 31));
        Label15->setFont(font);
        Label17 = new QLabel(widget3);
        Label17->setObjectName(QString::fromUtf8("Label17"));
        Label17->setGeometry(QRect(30, 85, 131, 31));
        Label17->setFont(font);
        AddButton2 = new QPushButton(widget3);
        AddButton2->setObjectName(QString::fromUtf8("AddButton2"));
        AddButton2->setGeometry(QRect(545, 140, 141, 51));
        AddButton2->setFont(font1);
        AddButton2->setCursor(QCursor(Qt::PointingHandCursor));
        AddButton2->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        AddButton2->setIcon(icon);
        AddButton2->setIconSize(QSize(20, 20));
        OtherEdit = new QLineEdit(widget3);
        OtherEdit->setObjectName(QString::fromUtf8("OtherEdit"));
        OtherEdit->setGeometry(QRect(95, 140, 161, 41));
        OtherEdit->setFont(font);
        OtherEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(230,230,250);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        OtherEdit->setReadOnly(false);
        Label19 = new QLabel(widget3);
        Label19->setObjectName(QString::fromUtf8("Label19"));
        Label19->setGeometry(QRect(30, 145, 61, 31));
        Label19->setFont(font);
        Back3 = new QLabel(widget3);
        Back3->setObjectName(QString::fromUtf8("Back3"));
        Back3->setGeometry(QRect(0, 0, 711, 201));
        Back3->setStyleSheet(QString::fromUtf8("background-color: rgb(176,196,222);\n"
"border-radius: 20px;\n"
"border-style: outset;"));
        ExcleButton = new QPushButton(widget3);
        ExcleButton->setObjectName(QString::fromUtf8("ExcleButton"));
        ExcleButton->setGeometry(QRect(560, 15, 141, 51));
        ExcleButton->setFont(font1);
        ExcleButton->setCursor(QCursor(Qt::PointingHandCursor));
        ExcleButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/enter.png"), QSize(), QIcon::Normal, QIcon::Off);
        ExcleButton->setIcon(icon1);
        ExcleButton->setIconSize(QSize(20, 20));
        PriceEdit = new QLineEdit(widget3);
        PriceEdit->setObjectName(QString::fromUtf8("PriceEdit"));
        PriceEdit->setGeometry(QRect(360, 140, 161, 41));
        PriceEdit->setFont(font);
        PriceEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(230,230,250);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        PriceEdit->setAlignment(Qt::AlignCenter);
        PriceEdit->setReadOnly(false);
        Label20 = new QLabel(widget3);
        Label20->setObjectName(QString::fromUtf8("Label20"));
        Label20->setGeometry(QRect(295, 145, 61, 31));
        Label20->setFont(font);
        Back3->raise();
        MoldCombo->raise();
        Label18->raise();
        CabinetCombo->raise();
        SaveEdit->raise();
        SpareEdit->raise();
        Label16->raise();
        Label15->raise();
        Label17->raise();
        AddButton2->raise();
        OtherEdit->raise();
        Label19->raise();
        ExcleButton->raise();
        PriceEdit->raise();
        Label20->raise();
        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(720, 10, 680, 510));
        widget1->setStyleSheet(QString::fromUtf8(""));
        FMoldEdit = new QLineEdit(widget1);
        FMoldEdit->setObjectName(QString::fromUtf8("FMoldEdit"));
        FMoldEdit->setGeometry(QRect(500, 105, 151, 41));
        FMoldEdit->setFont(font);
        FMoldEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        FMoldEdit->setReadOnly(false);
        CabinetEdit = new QLineEdit(widget1);
        CabinetEdit->setObjectName(QString::fromUtf8("CabinetEdit"));
        CabinetEdit->setGeometry(QRect(500, 370, 151, 41));
        CabinetEdit->setFont(font);
        CabinetEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        CabinetEdit->setAlignment(Qt::AlignCenter);
        CabinetEdit->setReadOnly(true);
        NumEdit = new QLineEdit(widget1);
        NumEdit->setObjectName(QString::fromUtf8("NumEdit"));
        NumEdit->setGeometry(QRect(500, 310, 61, 41));
        NumEdit->setFont(font);
        NumEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        NumEdit->setAlignment(Qt::AlignCenter);
        NumEdit->setReadOnly(false);
        AddButton3 = new QPushButton(widget1);
        AddButton3->setObjectName(QString::fromUtf8("AddButton3"));
        AddButton3->setGeometry(QRect(380, 430, 131, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(18);
        font3.setBold(false);
        font3.setWeight(50);
        AddButton3->setFont(font3);
        AddButton3->setCursor(QCursor(Qt::PointingHandCursor));
        AddButton3->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"}"));
        Label5 = new QLabel(widget1);
        Label5->setObjectName(QString::fromUtf8("Label5"));
        Label5->setGeometry(QRect(390, 315, 111, 31));
        Label5->setFont(font);
        ReturnButton = new QPushButton(widget1);
        ReturnButton->setObjectName(QString::fromUtf8("ReturnButton"));
        ReturnButton->setGeometry(QRect(530, 430, 131, 51));
        ReturnButton->setFont(font3);
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
"	color: rgb(200, 200, 200);\n"
"}"));
        Label6 = new QLabel(widget1);
        Label6->setObjectName(QString::fromUtf8("Label6"));
        Label6->setGeometry(QRect(390, 375, 111, 31));
        Label6->setFont(font);
        Label2 = new QLabel(widget1);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(400, 40, 211, 31));
        Label2->setFont(font);
        Label1 = new QLabel(widget1);
        Label1->setObjectName(QString::fromUtf8("Label1"));
        Label1->setGeometry(QRect(24, 70, 151, 31));
        Label1->setFont(font1);
        NameView = new QTreeView(widget1);
        NameView->setObjectName(QString::fromUtf8("NameView"));
        NameView->setGeometry(QRect(20, 100, 351, 381));
        NameView->setFont(font1);
        NameView->setStyleSheet(QString::fromUtf8("QTreeView{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        NameView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        NameView->setSortingEnabled(true);
        FindButton = new QPushButton(widget1);
        FindButton->setObjectName(QString::fromUtf8("FindButton"));
        FindButton->setGeometry(QRect(520, 220, 131, 51));
        FindButton->setFont(font);
        FindButton->setCursor(QCursor(Qt::PointingHandCursor));
        FindButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        FindButton->setIcon(icon2);
        FindButton->setIconSize(QSize(22, 22));
        Label4 = new QLabel(widget1);
        Label4->setObjectName(QString::fromUtf8("Label4"));
        Label4->setGeometry(QRect(415, 165, 91, 31));
        Label4->setFont(font);
        FSpareEdit = new QLineEdit(widget1);
        FSpareEdit->setObjectName(QString::fromUtf8("FSpareEdit"));
        FSpareEdit->setGeometry(QRect(500, 160, 151, 41));
        FSpareEdit->setFont(font);
        FSpareEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        FSpareEdit->setReadOnly(false);
        SpareNum = new QLabel(widget1);
        SpareNum->setObjectName(QString::fromUtf8("SpareNum"));
        SpareNum->setGeometry(QRect(610, 40, 41, 31));
        SpareNum->setFont(font);
        Label3 = new QLabel(widget1);
        Label3->setObjectName(QString::fromUtf8("Label3"));
        Label3->setGeometry(QRect(390, 110, 111, 31));
        Label3->setFont(font);
        Back1 = new QLabel(widget1);
        Back1->setObjectName(QString::fromUtf8("Back1"));
        Back1->setGeometry(QRect(0, 0, 681, 511));
        Back1->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);\n"
"	border-radius: 15px;\n"
"	border-style: outset;"));
        PartCombo_1 = new QComboBox(widget1);
        PartCombo_1->addItem(QString());
        PartCombo_1->addItem(QString());
        PartCombo_1->setObjectName(QString::fromUtf8("PartCombo_1"));
        PartCombo_1->setGeometry(QRect(290, 35, 81, 41));
        PartCombo_1->setFont(font);
        PartCombo_1->setCursor(QCursor(Qt::ArrowCursor));
        PartCombo_1->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        Label7 = new QLabel(widget1);
        Label7->setObjectName(QString::fromUtf8("Label7"));
        Label7->setGeometry(QRect(180, 40, 111, 31));
        Label7->setFont(font);
        Back1->raise();
        FMoldEdit->raise();
        CabinetEdit->raise();
        NumEdit->raise();
        AddButton3->raise();
        Label5->raise();
        ReturnButton->raise();
        Label6->raise();
        Label2->raise();
        Label1->raise();
        NameView->raise();
        FindButton->raise();
        Label4->raise();
        FSpareEdit->raise();
        SpareNum->raise();
        Label3->raise();
        PartCombo_1->raise();
        Label7->raise();
        WarehouseAdd->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WarehouseAdd);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1410, 23));
        WarehouseAdd->setMenuBar(menubar);
        statusbar = new QStatusBar(WarehouseAdd);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        WarehouseAdd->setStatusBar(statusbar);
        QWidget::setTabOrder(PartCombo_2, MoldEdit);
        QWidget::setTabOrder(MoldEdit, CustomEdit);
        QWidget::setTabOrder(CustomEdit, MaterialEdit);
        QWidget::setTabOrder(MaterialEdit, MouldEdit);
        QWidget::setTabOrder(MouldEdit, ProductEdit);
        QWidget::setTabOrder(ProductEdit, ToAddButton);
        QWidget::setTabOrder(ToAddButton, AddButton1);
        QWidget::setTabOrder(AddButton1, MoldCombo);
        QWidget::setTabOrder(MoldCombo, SaveEdit);
        QWidget::setTabOrder(SaveEdit, SpareEdit);
        QWidget::setTabOrder(SpareEdit, CabinetCombo);
        QWidget::setTabOrder(CabinetCombo, OtherEdit);
        QWidget::setTabOrder(OtherEdit, PriceEdit);
        QWidget::setTabOrder(PriceEdit, ExcleButton);
        QWidget::setTabOrder(ExcleButton, AddButton2);
        QWidget::setTabOrder(AddButton2, NameView);
        QWidget::setTabOrder(NameView, PartCombo_1);
        QWidget::setTabOrder(PartCombo_1, FMoldEdit);
        QWidget::setTabOrder(FMoldEdit, FSpareEdit);
        QWidget::setTabOrder(FSpareEdit, FindButton);
        QWidget::setTabOrder(FindButton, NumEdit);
        QWidget::setTabOrder(NumEdit, CabinetEdit);
        QWidget::setTabOrder(CabinetEdit, AddButton3);
        QWidget::setTabOrder(AddButton3, ReturnButton);

        retranslateUi(WarehouseAdd);

        QMetaObject::connectSlotsByName(WarehouseAdd);
    } // setupUi

    void retranslateUi(QMainWindow *WarehouseAdd)
    {
        WarehouseAdd->setWindowTitle(QCoreApplication::translate("WarehouseAdd", "MainWindow", nullptr));
        Label9->setText(QCoreApplication::translate("WarehouseAdd", "\350\276\223\345\205\245\346\250\241\345\205\267\347\274\226\345\217\267:", nullptr));
        MaterialEdit->setPlaceholderText(QCoreApplication::translate("WarehouseAdd", "\350\276\223\345\205\245\344\272\247\345\223\201\346\226\231\345\217\267", nullptr));
        Label13->setText(QCoreApplication::translate("WarehouseAdd", "\350\276\223\345\205\245\344\272\247\345\223\201\345\220\215\347\247\260:", nullptr));
        PartCombo_2->setItemText(0, QCoreApplication::translate("WarehouseAdd", "\345\206\262\345\216\213", nullptr));
        PartCombo_2->setItemText(1, QCoreApplication::translate("WarehouseAdd", "\346\210\220\345\236\213", nullptr));

        Label8->setText(QCoreApplication::translate("WarehouseAdd", "\351\200\211\346\213\251\351\203\250\351\227\250:", nullptr));
        MoldEdit->setPlaceholderText(QCoreApplication::translate("WarehouseAdd", "\350\276\223\345\205\245\346\250\241\345\205\267\347\274\226\345\217\267", nullptr));
        ProductEdit->setPlaceholderText(QCoreApplication::translate("WarehouseAdd", "\350\276\223\345\205\245\344\272\247\345\223\201\345\220\215\347\247\260", nullptr));
        Label11->setText(QCoreApplication::translate("WarehouseAdd", "\350\276\223\345\205\245\344\272\247\345\223\201\346\226\231\345\217\267:", nullptr));
        AddButton1->setText(QCoreApplication::translate("WarehouseAdd", "\346\267\273\345\212\240\346\250\241\345\205\267", nullptr));
        CustomEdit->setPlaceholderText(QCoreApplication::translate("WarehouseAdd", "\350\276\223\345\205\245\345\256\242\346\210\267\346\250\241\345\217\267", nullptr));
        Label10->setText(QCoreApplication::translate("WarehouseAdd", "\350\276\223\345\205\245\345\256\242\346\210\267\346\250\241\345\217\267:", nullptr));
        ToAddButton->setText(QCoreApplication::translate("WarehouseAdd", "\346\267\273\345\212\240\350\264\247\346\237\234", nullptr));
        Back2->setText(QString());
        MoldNum->setText(QString());
        Label14->setText(QCoreApplication::translate("WarehouseAdd", "\345\275\223\345\211\215\346\250\241\345\205\267\347\261\273\345\236\213\346\225\260\351\207\217:", nullptr));
        LogoLabel->setText(QString());
        Label12->setText(QCoreApplication::translate("WarehouseAdd", "\350\276\223\345\205\245\346\250\241\345\205\267\345\260\272\345\257\270:", nullptr));
        MouldEdit->setPlaceholderText(QCoreApplication::translate("WarehouseAdd", "\350\276\223\345\205\245\346\250\241\345\205\267\345\260\272\345\257\270", nullptr));
        Label18->setText(QCoreApplication::translate("WarehouseAdd", "\351\200\211\346\213\251\346\237\234\345\217\267:", nullptr));
        SpareEdit->setPlaceholderText(QCoreApplication::translate("WarehouseAdd", "\350\276\223\345\205\245\345\244\207\344\273\266\345\217\267", nullptr));
        Label16->setText(QCoreApplication::translate("WarehouseAdd", "\350\256\276\347\275\256\345\256\211\345\205\250\345\272\223\345\255\230:", nullptr));
        Label15->setText(QCoreApplication::translate("WarehouseAdd", "\351\200\211\346\213\251\346\250\241\345\205\267:", nullptr));
        Label17->setText(QCoreApplication::translate("WarehouseAdd", "\350\276\223\345\205\245\345\244\207\344\273\266\345\217\267:", nullptr));
        AddButton2->setText(QCoreApplication::translate("WarehouseAdd", "\345\242\236\345\212\240\345\244\207\344\273\266", nullptr));
        OtherEdit->setPlaceholderText(QCoreApplication::translate("WarehouseAdd", "\350\276\223\345\205\245\345\244\207\346\263\250\344\277\241\346\201\257", nullptr));
        Label19->setText(QCoreApplication::translate("WarehouseAdd", "\345\244\207\346\263\250:", nullptr));
        Back3->setText(QString());
        ExcleButton->setText(QCoreApplication::translate("WarehouseAdd", "\350\241\250\346\240\274\345\257\274\345\205\245", nullptr));
        PriceEdit->setPlaceholderText(QCoreApplication::translate("WarehouseAdd", "\350\276\223\345\205\245\345\244\207\344\273\266\344\273\267\346\240\274", nullptr));
        Label20->setText(QCoreApplication::translate("WarehouseAdd", "\344\273\267\346\240\274:", nullptr));
        FMoldEdit->setPlaceholderText(QCoreApplication::translate("WarehouseAdd", "\350\276\223\345\205\245\346\250\241\345\205\267\347\274\226\345\217\267", nullptr));
        CabinetEdit->setPlaceholderText(QCoreApplication::translate("WarehouseAdd", "\346\211\200\351\200\211\350\264\247\346\237\234\345\217\267", nullptr));
        NumEdit->setText(QCoreApplication::translate("WarehouseAdd", "1", nullptr));
        NumEdit->setPlaceholderText(QCoreApplication::translate("WarehouseAdd", "1", nullptr));
        AddButton3->setText(QCoreApplication::translate("WarehouseAdd", "\346\267\273\345\212\240", nullptr));
        Label5->setText(QCoreApplication::translate("WarehouseAdd", "\350\276\223\345\205\245\346\225\260\351\207\217:", nullptr));
        ReturnButton->setText(QCoreApplication::translate("WarehouseAdd", "\350\277\224\345\233\236", nullptr));
        Label6->setText(QCoreApplication::translate("WarehouseAdd", "\346\267\273\345\212\240\350\264\247\346\237\234:", nullptr));
        Label2->setText(QCoreApplication::translate("WarehouseAdd", "\345\275\223\345\211\215\345\244\207\344\273\266\346\200\273\345\272\223\345\255\230\351\207\217:", nullptr));
        Label1->setText(QCoreApplication::translate("WarehouseAdd", "\350\257\267\345\205\210\351\200\211\346\213\251\345\244\207\344\273\266\342\254\213", nullptr));
        FindButton->setText(QCoreApplication::translate("WarehouseAdd", "\346\237\245\346\211\276", nullptr));
        Label4->setText(QCoreApplication::translate("WarehouseAdd", "\345\244\207\344\273\266\345\217\267:", nullptr));
        FSpareEdit->setPlaceholderText(QCoreApplication::translate("WarehouseAdd", "\350\276\223\345\205\245\345\244\207\344\273\266\345\217\267", nullptr));
        SpareNum->setText(QString());
        Label3->setText(QCoreApplication::translate("WarehouseAdd", "\346\250\241\345\205\267\347\274\226\345\217\267:", nullptr));
        Back1->setText(QString());
        PartCombo_1->setItemText(0, QCoreApplication::translate("WarehouseAdd", "\345\206\262\345\216\213", nullptr));
        PartCombo_1->setItemText(1, QCoreApplication::translate("WarehouseAdd", "\346\210\220\345\236\213", nullptr));

        Label7->setText(QCoreApplication::translate("WarehouseAdd", "\351\200\211\346\213\251\351\203\250\351\227\250:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WarehouseAdd: public Ui_WarehouseAdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAREHOUSEADD_H
