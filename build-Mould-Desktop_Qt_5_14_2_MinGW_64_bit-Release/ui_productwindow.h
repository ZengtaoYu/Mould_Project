/********************************************************************************
** Form generated from reading UI file 'productwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTWINDOW_H
#define UI_PRODUCTWINDOW_H

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

class Ui_ProductWindow
{
public:
    QWidget *centralwidget;
    QLabel *BackGround;
    QLabel *LogoLabel;
    QPushButton *SureButton;
    QListView *PIDView_1;
    QComboBox *MoldCombo;
    QLabel *Label2;
    QComboBox *WorkCombo;
    QLabel *Label4;
    QComboBox *ProductCombo_1;
    QLabel *Label3_1;
    QLabel *Label1_1;
    QPushButton *ReturnButton;
    QPushButton *OutButton;
    QComboBox *ProductCombo_2;
    QLabel *Label3_2;
    QListView *PIDView_2;
    QLabel *Label1_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ProductWindow)
    {
        if (ProductWindow->objectName().isEmpty())
            ProductWindow->setObjectName(QString::fromUtf8("ProductWindow"));
        ProductWindow->resize(741, 365);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ProductWindow->sizePolicy().hasHeightForWidth());
        ProductWindow->setSizePolicy(sizePolicy);
        ProductWindow->setMinimumSize(QSize(741, 365));
        ProductWindow->setMaximumSize(QSize(741, 365));
        centralwidget = new QWidget(ProductWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        BackGround = new QLabel(centralwidget);
        BackGround->setObjectName(QString::fromUtf8("BackGround"));
        BackGround->setGeometry(QRect(5, 5, 731, 336));
        BackGround->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 15px;\n"
"border-style: outset;"));
        LogoLabel = new QLabel(centralwidget);
        LogoLabel->setObjectName(QString::fromUtf8("LogoLabel"));
        LogoLabel->setGeometry(QRect(520, 10, 200, 53));
        LogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/logo200x53.jpg")));
        SureButton = new QPushButton(centralwidget);
        SureButton->setObjectName(QString::fromUtf8("SureButton"));
        SureButton->setEnabled(true);
        SureButton->setGeometry(QRect(440, 20, 76, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(18);
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
        MoldCombo = new QComboBox(centralwidget);
        MoldCombo->setObjectName(QString::fromUtf8("MoldCombo"));
        MoldCombo->setGeometry(QRect(560, 70, 161, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
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
        Label2->setGeometry(QRect(460, 75, 101, 31));
        Label2->setFont(font);
        WorkCombo = new QComboBox(centralwidget);
        WorkCombo->setObjectName(QString::fromUtf8("WorkCombo"));
        WorkCombo->setGeometry(QRect(560, 235, 161, 41));
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
        Label4 = new QLabel(centralwidget);
        Label4->setObjectName(QString::fromUtf8("Label4"));
        Label4->setGeometry(QRect(460, 240, 101, 31));
        Label4->setFont(font);
        ProductCombo_1 = new QComboBox(centralwidget);
        ProductCombo_1->setObjectName(QString::fromUtf8("ProductCombo_1"));
        ProductCombo_1->setGeometry(QRect(560, 125, 161, 41));
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
        Label3_1 = new QLabel(centralwidget);
        Label3_1->setObjectName(QString::fromUtf8("Label3_1"));
        Label3_1->setGeometry(QRect(460, 130, 101, 31));
        Label3_1->setFont(font);
        Label1_1 = new QLabel(centralwidget);
        Label1_1->setObjectName(QString::fromUtf8("Label1_1"));
        Label1_1->setGeometry(QRect(40, 30, 151, 31));
        Label1_1->setFont(font);
        ReturnButton = new QPushButton(centralwidget);
        ReturnButton->setObjectName(QString::fromUtf8("ReturnButton"));
        ReturnButton->setGeometry(QRect(610, 290, 76, 41));
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
        OutButton = new QPushButton(centralwidget);
        OutButton->setObjectName(QString::fromUtf8("OutButton"));
        OutButton->setGeometry(QRect(500, 290, 76, 41));
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
        ProductCombo_2 = new QComboBox(centralwidget);
        ProductCombo_2->setObjectName(QString::fromUtf8("ProductCombo_2"));
        ProductCombo_2->setGeometry(QRect(560, 180, 161, 41));
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
        Label3_2 = new QLabel(centralwidget);
        Label3_2->setObjectName(QString::fromUtf8("Label3_2"));
        Label3_2->setGeometry(QRect(460, 185, 101, 31));
        Label3_2->setFont(font);
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
        Label1_2 = new QLabel(centralwidget);
        Label1_2->setObjectName(QString::fromUtf8("Label1_2"));
        Label1_2->setGeometry(QRect(270, 30, 151, 31));
        Label1_2->setFont(font);
        ProductWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ProductWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 741, 23));
        ProductWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ProductWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ProductWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(MoldCombo, ProductCombo_1);
        QWidget::setTabOrder(ProductCombo_1, ProductCombo_2);
        QWidget::setTabOrder(ProductCombo_2, WorkCombo);
        QWidget::setTabOrder(WorkCombo, PIDView_1);
        QWidget::setTabOrder(PIDView_1, PIDView_2);
        QWidget::setTabOrder(PIDView_2, OutButton);
        QWidget::setTabOrder(OutButton, ReturnButton);
        QWidget::setTabOrder(ReturnButton, SureButton);

        retranslateUi(ProductWindow);

        QMetaObject::connectSlotsByName(ProductWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ProductWindow)
    {
        ProductWindow->setWindowTitle(QCoreApplication::translate("ProductWindow", "MainWindow", nullptr));
        BackGround->setText(QString());
        LogoLabel->setText(QString());
        SureButton->setText(QCoreApplication::translate("ProductWindow", "\347\241\256\345\256\232", nullptr));
        Label2->setText(QCoreApplication::translate("ProductWindow", "\351\200\211\346\213\251\346\250\241\345\205\267", nullptr));
        Label4->setText(QCoreApplication::translate("ProductWindow", "\351\200\211\346\213\251\345\267\245\347\253\231", nullptr));
        Label3_1->setText(QCoreApplication::translate("ProductWindow", "\345\275\223\345\211\215\346\226\231\345\217\267", nullptr));
        Label1_1->setText(QCoreApplication::translate("ProductWindow", "\345\275\223\345\211\215\346\226\231\345\217\267\345\244\207\344\273\266", nullptr));
        ReturnButton->setText(QCoreApplication::translate("ProductWindow", "\350\277\224\345\233\236", nullptr));
        OutButton->setText(QCoreApplication::translate("ProductWindow", "\345\257\274\345\207\272", nullptr));
        Label3_2->setText(QCoreApplication::translate("ProductWindow", "\346\233\264\346\215\242\346\226\231\345\217\267", nullptr));
        Label1_2->setText(QCoreApplication::translate("ProductWindow", "\346\233\264\346\215\242\345\244\207\344\273\266\346\226\231\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductWindow: public Ui_ProductWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTWINDOW_H
