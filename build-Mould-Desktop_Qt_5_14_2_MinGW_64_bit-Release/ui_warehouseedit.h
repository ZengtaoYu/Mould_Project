/********************************************************************************
** Form generated from reading UI file 'warehouseedit.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAREHOUSEEDIT_H
#define UI_WAREHOUSEEDIT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WarehouseEdit
{
public:
    QWidget *centralwidget;
    QLabel *Label5;
    QLabel *Label10;
    QLabel *Label4;
    QLabel *Label3;
    QLabel *Label8;
    QLabel *Label12;
    QComboBox *CabinetCombo;
    QLineEdit *SpareEdit;
    QPushButton *EditButton;
    QPushButton *ReturnButton;
    QLineEdit *OutTime;
    QLineEdit *EnterTime;
    QComboBox *IDCombo;
    QLabel *LogoLabel;
    QLabel *BackGround;
    QSpinBox *SaveNum;
    QLabel *Label6;
    QSpinBox *FirstNum;
    QLabel *Label7;
    QSpinBox *TotalNum;
    QLabel *Label9;
    QSpinBox *EnterNum;
    QSpinBox *OutNum;
    QLabel *Label11;
    QPushButton *MoldButton;
    QLabel *Label1;
    QComboBox *MoldCombo;
    QLabel *PartLabel;
    QLineEdit *OtherEdit;
    QLabel *Label2;
    QSpinBox *PriceNum;
    QLabel *Label13;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WarehouseEdit)
    {
        if (WarehouseEdit->objectName().isEmpty())
            WarehouseEdit->setObjectName(QString::fromUtf8("WarehouseEdit"));
        WarehouseEdit->resize(610, 465);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WarehouseEdit->sizePolicy().hasHeightForWidth());
        WarehouseEdit->setSizePolicy(sizePolicy);
        WarehouseEdit->setMinimumSize(QSize(610, 465));
        WarehouseEdit->setMaximumSize(QSize(610, 465));
        centralwidget = new QWidget(WarehouseEdit);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Label5 = new QLabel(centralwidget);
        Label5->setObjectName(QString::fromUtf8("Label5"));
        Label5->setGeometry(QRect(30, 200, 111, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(18);
        Label5->setFont(font);
        Label10 = new QLabel(centralwidget);
        Label10->setObjectName(QString::fromUtf8("Label10"));
        Label10->setGeometry(QRect(30, 320, 111, 41));
        Label10->setFont(font);
        Label4 = new QLabel(centralwidget);
        Label4->setObjectName(QString::fromUtf8("Label4"));
        Label4->setGeometry(QRect(195, 140, 81, 41));
        Label4->setFont(font);
        Label3 = new QLabel(centralwidget);
        Label3->setObjectName(QString::fromUtf8("Label3"));
        Label3->setGeometry(QRect(35, 140, 61, 41));
        Label3->setFont(font);
        Label8 = new QLabel(centralwidget);
        Label8->setObjectName(QString::fromUtf8("Label8"));
        Label8->setGeometry(QRect(30, 260, 111, 41));
        Label8->setFont(font);
        Label12 = new QLabel(centralwidget);
        Label12->setObjectName(QString::fromUtf8("Label12"));
        Label12->setGeometry(QRect(30, 380, 111, 41));
        Label12->setFont(font);
        CabinetCombo = new QComboBox(centralwidget);
        CabinetCombo->setObjectName(QString::fromUtf8("CabinetCombo"));
        CabinetCombo->setGeometry(QRect(140, 380, 141, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        CabinetCombo->setFont(font1);
        CabinetCombo->setCursor(QCursor(Qt::ArrowCursor));
        CabinetCombo->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        CabinetCombo->setEditable(true);
        SpareEdit = new QLineEdit(centralwidget);
        SpareEdit->setObjectName(QString::fromUtf8("SpareEdit"));
        SpareEdit->setGeometry(QRect(280, 140, 131, 41));
        SpareEdit->setFont(font);
        SpareEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        SpareEdit->setAlignment(Qt::AlignCenter);
        EditButton = new QPushButton(centralwidget);
        EditButton->setObjectName(QString::fromUtf8("EditButton"));
        EditButton->setGeometry(QRect(310, 380, 121, 41));
        EditButton->setFont(font);
        EditButton->setCursor(QCursor(Qt::PointingHandCursor));
        EditButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:white;\n"
"	background-color: rgb(85, 170, 255);\n"
"	border-radius: 15px;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{  /*\351\274\240\346\240\207\346\202\254\346\265\256\346\227\266*/\n"
"	background: rgb(49,106,234);\n"
"}\n"
"QPushButton:pressed{  /*\351\274\240\346\240\207\346\214\211\344\270\213\346\227\266*/\n"
"	background:rgb(96,96,96);\n"
"	color: rgb(200, 200, 200);\n"
"}"));
        ReturnButton = new QPushButton(centralwidget);
        ReturnButton->setObjectName(QString::fromUtf8("ReturnButton"));
        ReturnButton->setGeometry(QRect(470, 380, 71, 41));
        ReturnButton->setFont(font);
        ReturnButton->setCursor(QCursor(Qt::PointingHandCursor));
        ReturnButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:white;\n"
"	background-color: rgb(85, 170, 255);\n"
"	border-radius: 15px;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{  /*\351\274\240\346\240\207\346\202\254\346\265\256\346\227\266*/\n"
"	background: rgb(49,106,234);\n"
"}\n"
"QPushButton:pressed{  /*\351\274\240\346\240\207\346\214\211\344\270\213\346\227\266*/\n"
"	background:rgb(96,96,96);\n"
"	color: rgb(200, 200, 200);\n"
"}"));
        OutTime = new QLineEdit(centralwidget);
        OutTime->setObjectName(QString::fromUtf8("OutTime"));
        OutTime->setGeometry(QRect(140, 320, 251, 41));
        OutTime->setFont(font);
        OutTime->setCursor(QCursor(Qt::IBeamCursor));
        OutTime->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        OutTime->setAlignment(Qt::AlignCenter);
        EnterTime = new QLineEdit(centralwidget);
        EnterTime->setObjectName(QString::fromUtf8("EnterTime"));
        EnterTime->setGeometry(QRect(140, 260, 251, 41));
        EnterTime->setFont(font);
        EnterTime->setCursor(QCursor(Qt::IBeamCursor));
        EnterTime->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        EnterTime->setAlignment(Qt::AlignCenter);
        IDCombo = new QComboBox(centralwidget);
        IDCombo->setObjectName(QString::fromUtf8("IDCombo"));
        IDCombo->setGeometry(QRect(95, 140, 81, 41));
        IDCombo->setFont(font1);
        IDCombo->setCursor(QCursor(Qt::ArrowCursor));
        IDCombo->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        IDCombo->setEditable(false);
        LogoLabel = new QLabel(centralwidget);
        LogoLabel->setObjectName(QString::fromUtf8("LogoLabel"));
        LogoLabel->setGeometry(QRect(10, 10, 200, 53));
        LogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/logo200x53.jpg")));
        BackGround = new QLabel(centralwidget);
        BackGround->setObjectName(QString::fromUtf8("BackGround"));
        BackGround->setGeometry(QRect(5, 5, 601, 441));
        BackGround->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"border-style: outset;"));
        SaveNum = new QSpinBox(centralwidget);
        SaveNum->setObjectName(QString::fromUtf8("SaveNum"));
        SaveNum->setGeometry(QRect(140, 200, 61, 41));
        SaveNum->setCursor(QCursor(Qt::ArrowCursor));
        SaveNum->setStyleSheet(QString::fromUtf8("background-color: rgb(204, 221, 255);\n"
"border: none;\n"
"border-radius: 2px;\n"
"color: rgb(0,0,0);\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        SaveNum->setAlignment(Qt::AlignCenter);
        SaveNum->setMaximum(999);
        Label6 = new QLabel(centralwidget);
        Label6->setObjectName(QString::fromUtf8("Label6"));
        Label6->setGeometry(QRect(220, 200, 111, 41));
        Label6->setFont(font);
        FirstNum = new QSpinBox(centralwidget);
        FirstNum->setObjectName(QString::fromUtf8("FirstNum"));
        FirstNum->setGeometry(QRect(330, 200, 61, 41));
        FirstNum->setCursor(QCursor(Qt::ArrowCursor));
        FirstNum->setStyleSheet(QString::fromUtf8("background-color: rgb(204, 221, 255);\n"
"border: none;\n"
"border-radius: 2px;\n"
"color: rgb(0,0,0);\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        FirstNum->setAlignment(Qt::AlignCenter);
        Label7 = new QLabel(centralwidget);
        Label7->setObjectName(QString::fromUtf8("Label7"));
        Label7->setGeometry(QRect(425, 140, 101, 41));
        Label7->setFont(font);
        TotalNum = new QSpinBox(centralwidget);
        TotalNum->setObjectName(QString::fromUtf8("TotalNum"));
        TotalNum->setGeometry(QRect(530, 140, 61, 41));
        TotalNum->setCursor(QCursor(Qt::ArrowCursor));
        TotalNum->setStyleSheet(QString::fromUtf8("background-color: rgb(204, 221, 255);\n"
"border: none;\n"
"border-radius: 2px;\n"
"color: rgb(0,0,0);\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        TotalNum->setAlignment(Qt::AlignCenter);
        TotalNum->setMaximum(99);
        Label9 = new QLabel(centralwidget);
        Label9->setObjectName(QString::fromUtf8("Label9"));
        Label9->setGeometry(QRect(420, 200, 111, 41));
        Label9->setFont(font);
        EnterNum = new QSpinBox(centralwidget);
        EnterNum->setObjectName(QString::fromUtf8("EnterNum"));
        EnterNum->setGeometry(QRect(530, 200, 61, 41));
        EnterNum->setCursor(QCursor(Qt::ArrowCursor));
        EnterNum->setStyleSheet(QString::fromUtf8("background-color: rgb(204, 221, 255);\n"
"border: none;\n"
"border-radius: 2px;\n"
"color: rgb(0,0,0);\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        EnterNum->setAlignment(Qt::AlignCenter);
        OutNum = new QSpinBox(centralwidget);
        OutNum->setObjectName(QString::fromUtf8("OutNum"));
        OutNum->setGeometry(QRect(530, 260, 61, 41));
        OutNum->setCursor(QCursor(Qt::ArrowCursor));
        OutNum->setStyleSheet(QString::fromUtf8("background-color: rgb(204, 221, 255);\n"
"border: none;\n"
"border-radius: 2px;\n"
"color: rgb(0,0,0);\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        OutNum->setAlignment(Qt::AlignCenter);
        Label11 = new QLabel(centralwidget);
        Label11->setObjectName(QString::fromUtf8("Label11"));
        Label11->setGeometry(QRect(420, 260, 111, 41));
        Label11->setFont(font);
        MoldButton = new QPushButton(centralwidget);
        MoldButton->setObjectName(QString::fromUtf8("MoldButton"));
        MoldButton->setGeometry(QRect(450, 20, 141, 41));
        MoldButton->setFont(font);
        MoldButton->setCursor(QCursor(Qt::PointingHandCursor));
        MoldButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:white;\n"
"	background-color: rgb(85, 170, 255);\n"
"	border-radius: 15px;\n"
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
        icon.addFile(QString::fromUtf8(":/images/maintenance.png"), QSize(), QIcon::Normal, QIcon::Off);
        MoldButton->setIcon(icon);
        MoldButton->setIconSize(QSize(24, 24));
        Label1 = new QLabel(centralwidget);
        Label1->setObjectName(QString::fromUtf8("Label1"));
        Label1->setGeometry(QRect(30, 80, 111, 41));
        Label1->setFont(font);
        MoldCombo = new QComboBox(centralwidget);
        MoldCombo->setObjectName(QString::fromUtf8("MoldCombo"));
        MoldCombo->setGeometry(QRect(140, 80, 151, 41));
        MoldCombo->setFont(font1);
        MoldCombo->setCursor(QCursor(Qt::ArrowCursor));
        MoldCombo->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        MoldCombo->setEditable(true);
        PartLabel = new QLabel(centralwidget);
        PartLabel->setObjectName(QString::fromUtf8("PartLabel"));
        PartLabel->setGeometry(QRect(240, 60, 51, 21));
        OtherEdit = new QLineEdit(centralwidget);
        OtherEdit->setObjectName(QString::fromUtf8("OtherEdit"));
        OtherEdit->setGeometry(QRect(420, 80, 161, 41));
        OtherEdit->setFont(font);
        OtherEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        Label2 = new QLabel(centralwidget);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(310, 80, 111, 41));
        Label2->setFont(font);
        PriceNum = new QSpinBox(centralwidget);
        PriceNum->setObjectName(QString::fromUtf8("PriceNum"));
        PriceNum->setGeometry(QRect(530, 320, 61, 41));
        PriceNum->setCursor(QCursor(Qt::ArrowCursor));
        PriceNum->setStyleSheet(QString::fromUtf8("background-color: rgb(204, 221, 255);\n"
"border: none;\n"
"border-radius: 2px;\n"
"color: rgb(0,0,0);\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        PriceNum->setAlignment(Qt::AlignCenter);
        Label13 = new QLabel(centralwidget);
        Label13->setObjectName(QString::fromUtf8("Label13"));
        Label13->setGeometry(QRect(420, 320, 111, 41));
        Label13->setFont(font);
        WarehouseEdit->setCentralWidget(centralwidget);
        BackGround->raise();
        Label5->raise();
        Label10->raise();
        Label4->raise();
        Label3->raise();
        Label8->raise();
        Label12->raise();
        CabinetCombo->raise();
        SpareEdit->raise();
        EditButton->raise();
        ReturnButton->raise();
        OutTime->raise();
        EnterTime->raise();
        IDCombo->raise();
        LogoLabel->raise();
        SaveNum->raise();
        Label6->raise();
        FirstNum->raise();
        Label7->raise();
        TotalNum->raise();
        Label9->raise();
        EnterNum->raise();
        OutNum->raise();
        Label11->raise();
        MoldButton->raise();
        Label1->raise();
        MoldCombo->raise();
        PartLabel->raise();
        OtherEdit->raise();
        Label2->raise();
        PriceNum->raise();
        Label13->raise();
        menubar = new QMenuBar(WarehouseEdit);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 610, 23));
        WarehouseEdit->setMenuBar(menubar);
        statusbar = new QStatusBar(WarehouseEdit);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        WarehouseEdit->setStatusBar(statusbar);
        QWidget::setTabOrder(MoldCombo, OtherEdit);
        QWidget::setTabOrder(OtherEdit, IDCombo);
        QWidget::setTabOrder(IDCombo, SpareEdit);
        QWidget::setTabOrder(SpareEdit, TotalNum);
        QWidget::setTabOrder(TotalNum, SaveNum);
        QWidget::setTabOrder(SaveNum, FirstNum);
        QWidget::setTabOrder(FirstNum, EnterNum);
        QWidget::setTabOrder(EnterNum, EnterTime);
        QWidget::setTabOrder(EnterTime, OutNum);
        QWidget::setTabOrder(OutNum, OutTime);
        QWidget::setTabOrder(OutTime, PriceNum);
        QWidget::setTabOrder(PriceNum, CabinetCombo);
        QWidget::setTabOrder(CabinetCombo, EditButton);
        QWidget::setTabOrder(EditButton, ReturnButton);
        QWidget::setTabOrder(ReturnButton, MoldButton);

        retranslateUi(WarehouseEdit);

        QMetaObject::connectSlotsByName(WarehouseEdit);
    } // setupUi

    void retranslateUi(QMainWindow *WarehouseEdit)
    {
        WarehouseEdit->setWindowTitle(QCoreApplication::translate("WarehouseEdit", "MainWindow", nullptr));
        Label5->setText(QCoreApplication::translate("WarehouseEdit", "\345\256\211\345\205\250\345\272\223\345\255\230:", nullptr));
        Label10->setText(QCoreApplication::translate("WarehouseEdit", "\345\207\272\345\272\223\346\227\266\351\227\264:", nullptr));
        Label4->setText(QCoreApplication::translate("WarehouseEdit", "\345\244\207\344\273\266\345\217\267:", nullptr));
        Label3->setText(QCoreApplication::translate("WarehouseEdit", "\345\272\217\345\217\267:", nullptr));
        Label8->setText(QCoreApplication::translate("WarehouseEdit", "\345\205\245\345\272\223\346\227\266\351\227\264:", nullptr));
        Label12->setText(QCoreApplication::translate("WarehouseEdit", "\345\255\230\346\224\276\346\237\234\345\217\267:", nullptr));
        SpareEdit->setPlaceholderText(QCoreApplication::translate("WarehouseEdit", "\350\276\223\345\205\245\345\244\207\344\273\266\345\217\267", nullptr));
        EditButton->setText(QCoreApplication::translate("WarehouseEdit", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
        ReturnButton->setText(QCoreApplication::translate("WarehouseEdit", "\350\277\224\345\233\236", nullptr));
        OutTime->setPlaceholderText(QCoreApplication::translate("WarehouseEdit", "yyyy-MM-dd hh:mm:ss", nullptr));
        EnterTime->setPlaceholderText(QCoreApplication::translate("WarehouseEdit", "yyyy-MM-dd hh:mm:ss", nullptr));
        LogoLabel->setText(QString());
        BackGround->setText(QString());
        Label6->setText(QCoreApplication::translate("WarehouseEdit", "\346\234\237\345\210\235\345\272\223\345\255\230:", nullptr));
        Label7->setText(QCoreApplication::translate("WarehouseEdit", "\346\200\273\345\272\223\345\255\230\351\207\217:", nullptr));
        Label9->setText(QCoreApplication::translate("WarehouseEdit", "\347\264\257\350\256\241\345\205\245\345\272\223:", nullptr));
        Label11->setText(QCoreApplication::translate("WarehouseEdit", "\347\264\257\350\256\241\345\207\272\345\272\223:", nullptr));
        MoldButton->setText(QCoreApplication::translate("WarehouseEdit", "\346\250\241\345\205\267\344\277\256\346\224\271", nullptr));
        Label1->setText(QCoreApplication::translate("WarehouseEdit", "\346\250\241\345\205\267\347\274\226\345\217\267:", nullptr));
        PartLabel->setText(QCoreApplication::translate("WarehouseEdit", "\345\206\262\345\216\213\351\203\250\351\227\250", nullptr));
        OtherEdit->setPlaceholderText(QCoreApplication::translate("WarehouseEdit", "\350\276\223\345\205\245\345\244\207\346\263\250\344\277\241\346\201\257", nullptr));
        Label2->setText(QCoreApplication::translate("WarehouseEdit", "\345\244\207\346\263\250\344\277\241\346\201\257:", nullptr));
        Label13->setText(QCoreApplication::translate("WarehouseEdit", "\345\244\207\344\273\266\344\273\267\346\240\274:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WarehouseEdit: public Ui_WarehouseEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAREHOUSEEDIT_H
