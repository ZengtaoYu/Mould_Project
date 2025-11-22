/********************************************************************************
** Form generated from reading UI file 'warehousedele.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAREHOUSEDELE_H
#define UI_WAREHOUSEDELE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WarehouseDele
{
public:
    QWidget *centralwidget;
    QListView *PIDView;
    QPushButton *pushButton_1;
    QLabel *Label1;
    QLabel *NumLabel;
    QLineEdit *CabinetEdit;
    QLabel *Label2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *ShowLabel;
    QLabel *BackGround;
    QLabel *LogoLabel;
    QPushButton *ChangeButton;
    QPushButton *ChangeButtonc;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WarehouseDele)
    {
        if (WarehouseDele->objectName().isEmpty())
            WarehouseDele->setObjectName(QString::fromUtf8("WarehouseDele"));
        WarehouseDele->resize(485, 385);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WarehouseDele->sizePolicy().hasHeightForWidth());
        WarehouseDele->setSizePolicy(sizePolicy);
        WarehouseDele->setMinimumSize(QSize(485, 385));
        WarehouseDele->setMaximumSize(QSize(485, 385));
        centralwidget = new QWidget(WarehouseDele);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        PIDView = new QListView(centralwidget);
        PIDView->setObjectName(QString::fromUtf8("PIDView"));
        PIDView->setGeometry(QRect(20, 100, 181, 241));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(18);
        PIDView->setFont(font);
        PIDView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        PIDView->setMouseTracking(false);
        PIDView->setStyleSheet(QString::fromUtf8("QListView{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        PIDView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(230, 170, 201, 41));
        pushButton_1->setFont(font);
        pushButton_1->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        Label1 = new QLabel(centralwidget);
        Label1->setObjectName(QString::fromUtf8("Label1"));
        Label1->setGeometry(QRect(230, 130, 161, 31));
        Label1->setFont(font);
        NumLabel = new QLabel(centralwidget);
        NumLabel->setObjectName(QString::fromUtf8("NumLabel"));
        NumLabel->setGeometry(QRect(390, 130, 71, 31));
        NumLabel->setFont(font);
        CabinetEdit = new QLineEdit(centralwidget);
        CabinetEdit->setObjectName(QString::fromUtf8("CabinetEdit"));
        CabinetEdit->setGeometry(QRect(340, 230, 121, 41));
        CabinetEdit->setFont(font);
        CabinetEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        CabinetEdit->setAlignment(Qt::AlignCenter);
        CabinetEdit->setReadOnly(false);
        Label2 = new QLabel(centralwidget);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(230, 235, 111, 31));
        Label2->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 290, 111, 41));
        pushButton_2->setFont(font);
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(220, 290, 111, 41));
        pushButton_3->setFont(font);
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        pushButton_3->setCheckable(false);
        ShowLabel = new QLabel(centralwidget);
        ShowLabel->setObjectName(QString::fromUtf8("ShowLabel"));
        ShowLabel->setGeometry(QRect(30, 65, 161, 31));
        ShowLabel->setFont(font);
        BackGround = new QLabel(centralwidget);
        BackGround->setObjectName(QString::fromUtf8("BackGround"));
        BackGround->setGeometry(QRect(5, 5, 476, 356));
        BackGround->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 15px;\n"
"border-style: outset;"));
        LogoLabel = new QLabel(centralwidget);
        LogoLabel->setObjectName(QString::fromUtf8("LogoLabel"));
        LogoLabel->setGeometry(QRect(270, 10, 200, 53));
        LogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/logo200x53.jpg")));
        ChangeButton = new QPushButton(centralwidget);
        ChangeButton->setObjectName(QString::fromUtf8("ChangeButton"));
        ChangeButton->setGeometry(QRect(230, 90, 101, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        ChangeButton->setFont(font1);
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
        ChangeButtonc = new QPushButton(centralwidget);
        ChangeButtonc->setObjectName(QString::fromUtf8("ChangeButtonc"));
        ChangeButtonc->setGeometry(QRect(340, 90, 101, 31));
        ChangeButtonc->setFont(font1);
        ChangeButtonc->setCursor(QCursor(Qt::PointingHandCursor));
        ChangeButtonc->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        ChangeButtonc->setCheckable(true);
        ChangeButtonc->setChecked(false);
        WarehouseDele->setCentralWidget(centralwidget);
        BackGround->raise();
        PIDView->raise();
        pushButton_1->raise();
        Label1->raise();
        NumLabel->raise();
        CabinetEdit->raise();
        Label2->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        ShowLabel->raise();
        LogoLabel->raise();
        ChangeButton->raise();
        ChangeButtonc->raise();
        menubar = new QMenuBar(WarehouseDele);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 485, 23));
        WarehouseDele->setMenuBar(menubar);
        statusbar = new QStatusBar(WarehouseDele);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        WarehouseDele->setStatusBar(statusbar);
        QWidget::setTabOrder(PIDView, ChangeButton);
        QWidget::setTabOrder(ChangeButton, ChangeButtonc);
        QWidget::setTabOrder(ChangeButtonc, pushButton_1);
        QWidget::setTabOrder(pushButton_1, CabinetEdit);
        QWidget::setTabOrder(CabinetEdit, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_2);

        retranslateUi(WarehouseDele);

        QMetaObject::connectSlotsByName(WarehouseDele);
    } // setupUi

    void retranslateUi(QMainWindow *WarehouseDele)
    {
        WarehouseDele->setWindowTitle(QCoreApplication::translate("WarehouseDele", "MainWindow", nullptr));
        pushButton_1->setText(QCoreApplication::translate("WarehouseDele", "\345\210\240\351\231\244\350\257\245\346\250\241\345\205\267/\350\264\247\346\237\234", nullptr));
        Label1->setText(QCoreApplication::translate("WarehouseDele", "\346\211\200\351\200\211\345\244\207\344\273\266\346\225\260\351\207\217:", nullptr));
        NumLabel->setText(QString());
        CabinetEdit->setPlaceholderText(QCoreApplication::translate("WarehouseDele", "\350\276\223\345\205\245\346\237\234\345\217\267", nullptr));
        Label2->setText(QCoreApplication::translate("WarehouseDele", "\350\276\223\345\205\245\346\237\234\345\217\267:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("WarehouseDele", "\346\226\260\345\242\236\346\237\234\345\217\267", nullptr));
        pushButton_3->setText(QCoreApplication::translate("WarehouseDele", "\345\210\207\346\215\242\351\200\211\351\241\271", nullptr));
        ShowLabel->setText(QCoreApplication::translate("WarehouseDele", "\345\206\262\345\216\213\346\250\241\345\205\267\347\261\273\345\210\253\342\254\213", nullptr));
        BackGround->setText(QString());
        LogoLabel->setText(QString());
        ChangeButton->setText(QCoreApplication::translate("WarehouseDele", "\345\210\207\346\215\242\344\270\272\346\210\220\345\236\213\345\244\207\344\273\266", nullptr));
        ChangeButtonc->setText(QCoreApplication::translate("WarehouseDele", "\345\210\207\346\215\242\344\270\272\346\250\241\345\205\267\350\264\247\346\237\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WarehouseDele: public Ui_WarehouseDele {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAREHOUSEDELE_H
