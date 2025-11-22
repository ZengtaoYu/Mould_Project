/********************************************************************************
** Form generated from reading UI file 'sparewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPAREWINDOW_H
#define UI_SPAREWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpareWindow
{
public:
    QWidget *centralwidget;
    QLabel *BackGround;
    QLabel *Label3;
    QComboBox *ProductCombo_1;
    QPushButton *SureButton;
    QLabel *Label5;
    QLabel *LogoLabel;
    QComboBox *MoldCombo;
    QLabel *Label2;
    QComboBox *WorkCombo;
    QPushButton *ReturnButton;
    QComboBox *ProductCombo_2;
    QListView *PIDView_2;
    QLabel *Label4;
    QLabel *Label1;
    QListView *PIDView_1;
    QLabel *Label6;
    QPushButton *OutButton;
    QLabel *Label8;
    QLabel *NumLabel2;
    QLabel *NumLabel3;
    QLabel *Label9;
    QLabel *NumLabel1;
    QLabel *Label7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SpareWindow)
    {
        if (SpareWindow->objectName().isEmpty())
            SpareWindow->setObjectName(QString::fromUtf8("SpareWindow"));
        SpareWindow->resize(741, 475);
        SpareWindow->setMinimumSize(QSize(741, 475));
        SpareWindow->setMaximumSize(QSize(741, 475));
        centralwidget = new QWidget(SpareWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        BackGround = new QLabel(centralwidget);
        BackGround->setObjectName(QString::fromUtf8("BackGround"));
        BackGround->setGeometry(QRect(5, 5, 731, 421));
        BackGround->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 15px;\n"
"border-style: outset;"));
        Label3 = new QLabel(centralwidget);
        Label3->setObjectName(QString::fromUtf8("Label3"));
        Label3->setGeometry(QRect(460, 105, 101, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(18);
        Label3->setFont(font);
        ProductCombo_1 = new QComboBox(centralwidget);
        ProductCombo_1->setObjectName(QString::fromUtf8("ProductCombo_1"));
        ProductCombo_1->setGeometry(QRect(560, 155, 161, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        ProductCombo_1->setFont(font1);
        ProductCombo_1->setCursor(QCursor(Qt::ArrowCursor));
        ProductCombo_1->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        ProductCombo_1->setEditable(true);
        SureButton = new QPushButton(centralwidget);
        SureButton->setObjectName(QString::fromUtf8("SureButton"));
        SureButton->setEnabled(true);
        SureButton->setGeometry(QRect(440, 20, 76, 41));
        SureButton->setFont(font);
        SureButton->setCursor(QCursor(Qt::PointingHandCursor));
        SureButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        Label5 = new QLabel(centralwidget);
        Label5->setObjectName(QString::fromUtf8("Label5"));
        Label5->setGeometry(QRect(460, 215, 101, 31));
        Label5->setFont(font);
        LogoLabel = new QLabel(centralwidget);
        LogoLabel->setObjectName(QString::fromUtf8("LogoLabel"));
        LogoLabel->setGeometry(QRect(520, 10, 200, 53));
        LogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/logo200x53.jpg")));
        MoldCombo = new QComboBox(centralwidget);
        MoldCombo->setObjectName(QString::fromUtf8("MoldCombo"));
        MoldCombo->setGeometry(QRect(560, 100, 161, 41));
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
        Label2 = new QLabel(centralwidget);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(270, 30, 151, 31));
        Label2->setFont(font);
        WorkCombo = new QComboBox(centralwidget);
        WorkCombo->addItem(QString());
        WorkCombo->addItem(QString());
        WorkCombo->addItem(QString());
        WorkCombo->addItem(QString());
        WorkCombo->addItem(QString());
        WorkCombo->addItem(QString());
        WorkCombo->setObjectName(QString::fromUtf8("WorkCombo"));
        WorkCombo->setGeometry(QRect(560, 265, 161, 41));
        WorkCombo->setFont(font1);
        WorkCombo->setCursor(QCursor(Qt::ArrowCursor));
        WorkCombo->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        WorkCombo->setEditable(true);
        ReturnButton = new QPushButton(centralwidget);
        ReturnButton->setObjectName(QString::fromUtf8("ReturnButton"));
        ReturnButton->setGeometry(QRect(610, 350, 76, 41));
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
"	color: rgb(200, 200, 200);\n"
"}"));
        ProductCombo_2 = new QComboBox(centralwidget);
        ProductCombo_2->setObjectName(QString::fromUtf8("ProductCombo_2"));
        ProductCombo_2->setGeometry(QRect(560, 210, 161, 41));
        ProductCombo_2->setFont(font1);
        ProductCombo_2->setCursor(QCursor(Qt::ArrowCursor));
        ProductCombo_2->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        ProductCombo_2->setEditable(true);
        PIDView_2 = new QListView(centralwidget);
        PIDView_2->setObjectName(QString::fromUtf8("PIDView_2"));
        PIDView_2->setGeometry(QRect(240, 70, 211, 251));
        PIDView_2->setFont(font);
        PIDView_2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        PIDView_2->setMouseTracking(false);
        PIDView_2->setStyleSheet(QString::fromUtf8("QListView{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        PIDView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Label4 = new QLabel(centralwidget);
        Label4->setObjectName(QString::fromUtf8("Label4"));
        Label4->setGeometry(QRect(460, 160, 101, 31));
        Label4->setFont(font);
        Label1 = new QLabel(centralwidget);
        Label1->setObjectName(QString::fromUtf8("Label1"));
        Label1->setGeometry(QRect(40, 30, 151, 31));
        Label1->setFont(font);
        PIDView_1 = new QListView(centralwidget);
        PIDView_1->setObjectName(QString::fromUtf8("PIDView_1"));
        PIDView_1->setGeometry(QRect(20, 70, 211, 251));
        PIDView_1->setFont(font);
        PIDView_1->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        PIDView_1->setMouseTracking(false);
        PIDView_1->setStyleSheet(QString::fromUtf8("QListView{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        PIDView_1->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Label6 = new QLabel(centralwidget);
        Label6->setObjectName(QString::fromUtf8("Label6"));
        Label6->setGeometry(QRect(460, 270, 101, 31));
        Label6->setFont(font);
        OutButton = new QPushButton(centralwidget);
        OutButton->setObjectName(QString::fromUtf8("OutButton"));
        OutButton->setGeometry(QRect(500, 350, 76, 41));
        OutButton->setFont(font);
        OutButton->setCursor(QCursor(Qt::PointingHandCursor));
        OutButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        Label8 = new QLabel(centralwidget);
        Label8->setObjectName(QString::fromUtf8("Label8"));
        Label8->setGeometry(QRect(250, 335, 111, 31));
        Label8->setFont(font);
        Label8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        NumLabel2 = new QLabel(centralwidget);
        NumLabel2->setObjectName(QString::fromUtf8("NumLabel2"));
        NumLabel2->setGeometry(QRect(360, 335, 71, 31));
        NumLabel2->setFont(font);
        NumLabel3 = new QLabel(centralwidget);
        NumLabel3->setObjectName(QString::fromUtf8("NumLabel3"));
        NumLabel3->setGeometry(QRect(360, 380, 71, 31));
        NumLabel3->setFont(font);
        Label9 = new QLabel(centralwidget);
        Label9->setObjectName(QString::fromUtf8("Label9"));
        Label9->setGeometry(QRect(250, 380, 111, 31));
        Label9->setFont(font);
        NumLabel1 = new QLabel(centralwidget);
        NumLabel1->setObjectName(QString::fromUtf8("NumLabel1"));
        NumLabel1->setGeometry(QRect(140, 335, 71, 31));
        NumLabel1->setFont(font);
        Label7 = new QLabel(centralwidget);
        Label7->setObjectName(QString::fromUtf8("Label7"));
        Label7->setGeometry(QRect(30, 335, 111, 31));
        Label7->setFont(font);
        SpareWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SpareWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 741, 23));
        SpareWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SpareWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SpareWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(MoldCombo, ProductCombo_1);
        QWidget::setTabOrder(ProductCombo_1, ProductCombo_2);
        QWidget::setTabOrder(ProductCombo_2, WorkCombo);
        QWidget::setTabOrder(WorkCombo, PIDView_1);
        QWidget::setTabOrder(PIDView_1, PIDView_2);
        QWidget::setTabOrder(PIDView_2, OutButton);
        QWidget::setTabOrder(OutButton, ReturnButton);
        QWidget::setTabOrder(ReturnButton, SureButton);

        retranslateUi(SpareWindow);

        QMetaObject::connectSlotsByName(SpareWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SpareWindow)
    {
        SpareWindow->setWindowTitle(QCoreApplication::translate("SpareWindow", "MainWindow", nullptr));
        BackGround->setText(QString());
        Label3->setText(QCoreApplication::translate("SpareWindow", "\351\200\211\346\213\251\346\250\241\345\205\267", nullptr));
        SureButton->setText(QCoreApplication::translate("SpareWindow", "\347\241\256\345\256\232", nullptr));
        Label5->setText(QCoreApplication::translate("SpareWindow", "\346\233\264\346\215\242\346\226\231\345\217\267", nullptr));
        LogoLabel->setText(QString());
        Label2->setText(QCoreApplication::translate("SpareWindow", "\346\233\264\346\215\242\345\244\207\344\273\266\346\226\231\345\217\267", nullptr));
        WorkCombo->setItemText(0, QCoreApplication::translate("SpareWindow", "\346\211\200\346\234\211\345\244\207\344\273\266", nullptr));
        WorkCombo->setItemText(1, QCoreApplication::translate("SpareWindow", "\346\250\241\345\205\267\345\205\261\347\224\250\344\273\266", nullptr));
        WorkCombo->setItemText(2, QCoreApplication::translate("SpareWindow", "\345\211\215\346\250\241\351\233\266\344\273\266\345\217\267", nullptr));
        WorkCombo->setItemText(3, QCoreApplication::translate("SpareWindow", "\345\220\216\346\250\241\351\233\266\344\273\266\345\217\267", nullptr));
        WorkCombo->setItemText(4, QCoreApplication::translate("SpareWindow", "\346\273\221\345\235\227\351\233\266\344\273\266\345\217\267", nullptr));
        WorkCombo->setItemText(5, QCoreApplication::translate("SpareWindow", "\351\241\266\351\222\210\351\233\266\344\273\266\345\217\267", nullptr));

        ReturnButton->setText(QCoreApplication::translate("SpareWindow", "\350\277\224\345\233\236", nullptr));
        Label4->setText(QCoreApplication::translate("SpareWindow", "\345\275\223\345\211\215\346\226\231\345\217\267", nullptr));
        Label1->setText(QCoreApplication::translate("SpareWindow", "\345\275\223\345\211\215\346\226\231\345\217\267\345\244\207\344\273\266", nullptr));
        Label6->setText(QCoreApplication::translate("SpareWindow", "\351\200\211\346\213\251\347\261\273\345\236\213", nullptr));
        OutButton->setText(QCoreApplication::translate("SpareWindow", "\345\257\274\345\207\272", nullptr));
        Label8->setText(QCoreApplication::translate("SpareWindow", "\345\215\225\347\251\264\346\225\260\351\207\217:", nullptr));
        NumLabel2->setText(QString());
        NumLabel3->setText(QString());
        Label9->setText(QCoreApplication::translate("SpareWindow", "\345\220\210\350\256\241\346\225\260\351\207\217:", nullptr));
        NumLabel1->setText(QString());
        Label7->setText(QCoreApplication::translate("SpareWindow", "\346\250\241\345\205\267\347\251\264\346\225\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpareWindow: public Ui_SpareWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPAREWINDOW_H
