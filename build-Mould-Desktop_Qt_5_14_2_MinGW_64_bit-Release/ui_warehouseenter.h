/********************************************************************************
** Form generated from reading UI file 'warehouseenter.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAREHOUSEENTER_H
#define UI_WAREHOUSEENTER_H

#include <QtCore/QVariant>
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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WarehouseEnter
{
public:
    QWidget *centralwidget;
    QComboBox *MoldCombo;
    QListView *SpareView;
    QLabel *Label1;
    QLabel *Label6;
    QLineEdit *EnterTime;
    QLabel *Label5;
    QPushButton *EnterButton;
    QLabel *TotalNum;
    QPushButton *ReturnButton;
    QLabel *BackGround;
    QLabel *LogoLabel;
    QLabel *SaveNum;
    QLabel *Label2;
    QLineEdit *SpareEdit;
    QLabel *Label4;
    QLabel *Label7;
    QSpinBox *EnterNum;
    QLabel *Label3;
    QPushButton *ExportButton;
    QPushButton *ChangeButton;
    QComboBox *CabinetCombo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WarehouseEnter)
    {
        if (WarehouseEnter->objectName().isEmpty())
            WarehouseEnter->setObjectName(QString::fromUtf8("WarehouseEnter"));
        WarehouseEnter->resize(580, 410);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WarehouseEnter->sizePolicy().hasHeightForWidth());
        WarehouseEnter->setSizePolicy(sizePolicy);
        WarehouseEnter->setMinimumSize(QSize(580, 410));
        WarehouseEnter->setMaximumSize(QSize(580, 410));
        centralwidget = new QWidget(WarehouseEnter);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MoldCombo = new QComboBox(centralwidget);
        MoldCombo->setObjectName(QString::fromUtf8("MoldCombo"));
        MoldCombo->setGeometry(QRect(40, 50, 171, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(18);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        MoldCombo->setFont(font);
        MoldCombo->setCursor(QCursor(Qt::ArrowCursor));
        MoldCombo->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        MoldCombo->setEditable(true);
        SpareView = new QListView(centralwidget);
        SpareView->setObjectName(QString::fromUtf8("SpareView"));
        SpareView->setGeometry(QRect(25, 140, 161, 221));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        SpareView->setFont(font1);
        SpareView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        SpareView->setMouseTracking(false);
        SpareView->setStyleSheet(QString::fromUtf8("QListView{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        SpareView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Label1 = new QLabel(centralwidget);
        Label1->setObjectName(QString::fromUtf8("Label1"));
        Label1->setGeometry(QRect(200, 90, 111, 31));
        Label1->setFont(font1);
        Label6 = new QLabel(centralwidget);
        Label6->setObjectName(QString::fromUtf8("Label6"));
        Label6->setGeometry(QRect(200, 260, 111, 41));
        Label6->setFont(font1);
        EnterTime = new QLineEdit(centralwidget);
        EnterTime->setObjectName(QString::fromUtf8("EnterTime"));
        EnterTime->setGeometry(QRect(310, 260, 251, 41));
        EnterTime->setFont(font1);
        EnterTime->setCursor(QCursor(Qt::IBeamCursor));
        EnterTime->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        EnterTime->setAlignment(Qt::AlignCenter);
        EnterTime->setReadOnly(false);
        Label5 = new QLabel(centralwidget);
        Label5->setObjectName(QString::fromUtf8("Label5"));
        Label5->setGeometry(QRect(200, 200, 111, 41));
        Label5->setFont(font1);
        EnterButton = new QPushButton(centralwidget);
        EnterButton->setObjectName(QString::fromUtf8("EnterButton"));
        EnterButton->setGeometry(QRect(360, 320, 91, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setWeight(50);
        EnterButton->setFont(font2);
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
"}"));
        TotalNum = new QLabel(centralwidget);
        TotalNum->setObjectName(QString::fromUtf8("TotalNum"));
        TotalNum->setGeometry(QRect(310, 90, 51, 31));
        TotalNum->setFont(font1);
        ReturnButton = new QPushButton(centralwidget);
        ReturnButton->setObjectName(QString::fromUtf8("ReturnButton"));
        ReturnButton->setGeometry(QRect(470, 320, 91, 41));
        ReturnButton->setFont(font2);
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
        BackGround = new QLabel(centralwidget);
        BackGround->setObjectName(QString::fromUtf8("BackGround"));
        BackGround->setGeometry(QRect(5, 5, 571, 381));
        BackGround->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);\n"
"border-radius: 15px;\n"
"border-style: outset;"));
        LogoLabel = new QLabel(centralwidget);
        LogoLabel->setObjectName(QString::fromUtf8("LogoLabel"));
        LogoLabel->setGeometry(QRect(370, 10, 200, 53));
        LogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/logo200x53.jpg")));
        SaveNum = new QLabel(centralwidget);
        SaveNum->setObjectName(QString::fromUtf8("SaveNum"));
        SaveNum->setGeometry(QRect(490, 90, 51, 31));
        SaveNum->setFont(font1);
        Label2 = new QLabel(centralwidget);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(380, 90, 111, 31));
        Label2->setFont(font1);
        SpareEdit = new QLineEdit(centralwidget);
        SpareEdit->setObjectName(QString::fromUtf8("SpareEdit"));
        SpareEdit->setGeometry(QRect(310, 140, 121, 41));
        SpareEdit->setFont(font1);
        SpareEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        SpareEdit->setAlignment(Qt::AlignCenter);
        SpareEdit->setReadOnly(false);
        Label4 = new QLabel(centralwidget);
        Label4->setObjectName(QString::fromUtf8("Label4"));
        Label4->setGeometry(QRect(225, 140, 81, 41));
        Label4->setFont(font1);
        Label7 = new QLabel(centralwidget);
        Label7->setObjectName(QString::fromUtf8("Label7"));
        Label7->setGeometry(QRect(210, 320, 61, 41));
        Label7->setFont(font1);
        EnterNum = new QSpinBox(centralwidget);
        EnterNum->setObjectName(QString::fromUtf8("EnterNum"));
        EnterNum->setGeometry(QRect(270, 320, 61, 41));
        EnterNum->setCursor(QCursor(Qt::ArrowCursor));
        EnterNum->setStyleSheet(QString::fromUtf8("background-color: rgb(204, 221, 255);\n"
"border: none;\n"
"border-radius: 2px;\n"
"color: rgb(0,0,0);\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        EnterNum->setMaximum(999);
        EnterNum->setValue(1);
        Label3 = new QLabel(centralwidget);
        Label3->setObjectName(QString::fromUtf8("Label3"));
        Label3->setGeometry(QRect(25, 110, 171, 25));
        Label3->setFont(font1);
        ExportButton = new QPushButton(centralwidget);
        ExportButton->setObjectName(QString::fromUtf8("ExportButton"));
        ExportButton->setGeometry(QRect(450, 150, 91, 91));
        ExportButton->setFont(font2);
        ExportButton->setCursor(QCursor(Qt::PointingHandCursor));
        ExportButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        ChangeButton = new QPushButton(centralwidget);
        ChangeButton->setObjectName(QString::fromUtf8("ChangeButton"));
        ChangeButton->setGeometry(QRect(240, 50, 101, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setWeight(75);
        ChangeButton->setFont(font3);
        ChangeButton->setCursor(QCursor(Qt::PointingHandCursor));
        ChangeButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"	color: rgb(200, 200, 200);\n"
"}\n"
"QPushButton:!enabled {   /*\346\214\211\351\222\256\347\246\201\347\224\250\346\227\266*/\n"
"	background: rgb(100, 100, 100);\n"
"	color: rgb(200, 200, 200);\n"
"}\n"
""));
        ChangeButton->setCheckable(true);
        ChangeButton->setChecked(false);
        CabinetCombo = new QComboBox(centralwidget);
        CabinetCombo->setObjectName(QString::fromUtf8("CabinetCombo"));
        CabinetCombo->setGeometry(QRect(310, 200, 131, 41));
        CabinetCombo->setFont(font);
        CabinetCombo->setCursor(QCursor(Qt::ArrowCursor));
        CabinetCombo->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        CabinetCombo->setEditable(true);
        WarehouseEnter->setCentralWidget(centralwidget);
        BackGround->raise();
        MoldCombo->raise();
        SpareView->raise();
        Label1->raise();
        Label6->raise();
        EnterTime->raise();
        Label5->raise();
        EnterButton->raise();
        TotalNum->raise();
        ReturnButton->raise();
        LogoLabel->raise();
        SaveNum->raise();
        Label2->raise();
        SpareEdit->raise();
        Label4->raise();
        Label7->raise();
        EnterNum->raise();
        Label3->raise();
        ExportButton->raise();
        ChangeButton->raise();
        CabinetCombo->raise();
        menubar = new QMenuBar(WarehouseEnter);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 580, 23));
        WarehouseEnter->setMenuBar(menubar);
        statusbar = new QStatusBar(WarehouseEnter);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        WarehouseEnter->setStatusBar(statusbar);
        QWidget::setTabOrder(ChangeButton, MoldCombo);
        QWidget::setTabOrder(MoldCombo, SpareView);
        QWidget::setTabOrder(SpareView, SpareEdit);
        QWidget::setTabOrder(SpareEdit, CabinetCombo);
        QWidget::setTabOrder(CabinetCombo, EnterTime);
        QWidget::setTabOrder(EnterTime, EnterNum);
        QWidget::setTabOrder(EnterNum, EnterButton);
        QWidget::setTabOrder(EnterButton, ReturnButton);
        QWidget::setTabOrder(ReturnButton, ExportButton);

        retranslateUi(WarehouseEnter);

        QMetaObject::connectSlotsByName(WarehouseEnter);
    } // setupUi

    void retranslateUi(QMainWindow *WarehouseEnter)
    {
        WarehouseEnter->setWindowTitle(QCoreApplication::translate("WarehouseEnter", "MainWindow", nullptr));
        Label1->setText(QCoreApplication::translate("WarehouseEnter", "\346\200\273\345\272\223\345\255\230\351\207\217:", nullptr));
        Label6->setText(QCoreApplication::translate("WarehouseEnter", "\345\205\245\345\272\223\346\227\266\351\227\264:", nullptr));
        EnterTime->setPlaceholderText(QCoreApplication::translate("WarehouseEnter", "yyyy-MM-dd hh:mm:ss", nullptr));
        Label5->setText(QCoreApplication::translate("WarehouseEnter", "\345\255\230\346\224\276\346\237\234\345\217\267:", nullptr));
        EnterButton->setText(QCoreApplication::translate("WarehouseEnter", "\345\205\245\345\272\223", nullptr));
        TotalNum->setText(QString());
        ReturnButton->setText(QCoreApplication::translate("WarehouseEnter", "\350\277\224\345\233\236", nullptr));
        BackGround->setText(QString());
        LogoLabel->setText(QString());
        SaveNum->setText(QString());
        Label2->setText(QCoreApplication::translate("WarehouseEnter", "\345\256\211\345\205\250\345\272\223\345\255\230:", nullptr));
        Label4->setText(QCoreApplication::translate("WarehouseEnter", "\345\244\207\344\273\266\345\217\267:", nullptr));
        Label7->setText(QCoreApplication::translate("WarehouseEnter", "\346\225\260\351\207\217:", nullptr));
        Label3->setText(QCoreApplication::translate("WarehouseEnter", "\351\200\211\346\213\251\345\206\262\345\216\213\345\244\207\344\273\266\342\254\213", nullptr));
        ExportButton->setText(QCoreApplication::translate("WarehouseEnter", "\350\256\260\345\275\225", nullptr));
        ChangeButton->setText(QCoreApplication::translate("WarehouseEnter", "\345\210\207\346\215\242\344\270\272\346\210\220\345\236\213\345\244\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WarehouseEnter: public Ui_WarehouseEnter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAREHOUSEENTER_H
