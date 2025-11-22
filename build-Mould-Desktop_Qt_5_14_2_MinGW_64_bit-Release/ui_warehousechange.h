/********************************************************************************
** Form generated from reading UI file 'warehousechange.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAREHOUSECHANGE_H
#define UI_WAREHOUSECHANGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WarehouseChange
{
public:
    QWidget *centralwidget;
    QPushButton *EditButton;
    QLabel *Label2;
    QLabel *Label1;
    QLabel *Label3;
    QLabel *Label5;
    QLabel *LoadingLabel;
    QLineEdit *MouldEdit;
    QLineEdit *MoldID;
    QComboBox *ContainerCombo;
    QTextEdit *ProductID;
    QLabel *Back1;
    QLabel *LogoLabel;
    QComboBox *StatusCombo;
    QLabel *Label4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WarehouseChange)
    {
        if (WarehouseChange->objectName().isEmpty())
            WarehouseChange->setObjectName(QString::fromUtf8("WarehouseChange"));
        WarehouseChange->resize(700, 400);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WarehouseChange->sizePolicy().hasHeightForWidth());
        WarehouseChange->setSizePolicy(sizePolicy);
        WarehouseChange->setMinimumSize(QSize(700, 400));
        WarehouseChange->setMaximumSize(QSize(700, 400));
        centralwidget = new QWidget(WarehouseChange);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        EditButton = new QPushButton(centralwidget);
        EditButton->setObjectName(QString::fromUtf8("EditButton"));
        EditButton->setEnabled(true);
        EditButton->setGeometry(QRect(430, 300, 131, 61));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(EditButton->sizePolicy().hasHeightForWidth());
        EditButton->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        EditButton->setFont(font);
        EditButton->setCursor(QCursor(Qt::PointingHandCursor));
        EditButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:white;\n"
"	background-color: rgb(170, 170, 255);\n"
"	border-radius: 20px;  border: 2px groove lavender;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{  /*\351\274\240\346\240\207\346\202\254\346\265\256\346\227\266*/\n"
"	background: rgb(170, 85, 255);\n"
"}\n"
"QPushButton:pressed{  /*\351\274\240\346\240\207\346\214\211\344\270\213\346\227\266*/\n"
"	background:rgb(96,96,96);\n"
"color: rgb(200, 200, 200);\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/change.png"), QSize(), QIcon::Normal, QIcon::Off);
        EditButton->setIcon(icon);
        EditButton->setIconSize(QSize(20, 20));
        Label2 = new QLabel(centralwidget);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(30, 120, 121, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(20);
        Label2->setFont(font1);
        Label1 = new QLabel(centralwidget);
        Label1->setObjectName(QString::fromUtf8("Label1"));
        Label1->setGeometry(QRect(30, 55, 121, 31));
        Label1->setFont(font1);
        Label3 = new QLabel(centralwidget);
        Label3->setObjectName(QString::fromUtf8("Label3"));
        Label3->setGeometry(QRect(30, 195, 121, 31));
        Label3->setFont(font1);
        Label5 = new QLabel(centralwidget);
        Label5->setObjectName(QString::fromUtf8("Label5"));
        Label5->setGeometry(QRect(30, 315, 121, 31));
        Label5->setFont(font1);
        LoadingLabel = new QLabel(centralwidget);
        LoadingLabel->setObjectName(QString::fromUtf8("LoadingLabel"));
        LoadingLabel->setGeometry(QRect(460, 80, 200, 200));
        LoadingLabel->setLayoutDirection(Qt::LeftToRight);
        MouldEdit = new QLineEdit(centralwidget);
        MouldEdit->setObjectName(QString::fromUtf8("MouldEdit"));
        MouldEdit->setGeometry(QRect(160, 190, 261, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(16);
        MouldEdit->setFont(font2);
        MouldEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MouldEdit->setReadOnly(false);
        MoldID = new QLineEdit(centralwidget);
        MoldID->setObjectName(QString::fromUtf8("MoldID"));
        MoldID->setGeometry(QRect(160, 50, 261, 41));
        MoldID->setFont(font2);
        MoldID->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MoldID->setReadOnly(true);
        ContainerCombo = new QComboBox(centralwidget);
        ContainerCombo->setObjectName(QString::fromUtf8("ContainerCombo"));
        ContainerCombo->setGeometry(QRect(160, 310, 181, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(16);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        ContainerCombo->setFont(font3);
        ContainerCombo->setCursor(QCursor(Qt::ArrowCursor));
        ContainerCombo->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        ContainerCombo->setEditable(true);
        ProductID = new QTextEdit(centralwidget);
        ProductID->setObjectName(QString::fromUtf8("ProductID"));
        ProductID->setGeometry(QRect(160, 110, 261, 61));
        ProductID->setFont(font2);
        ProductID->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        ProductID->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductID->setReadOnly(false);
        Back1 = new QLabel(centralwidget);
        Back1->setObjectName(QString::fromUtf8("Back1"));
        Back1->setGeometry(QRect(0, 0, 701, 381));
        Back1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"border-style: outset;"));
        LogoLabel = new QLabel(centralwidget);
        LogoLabel->setObjectName(QString::fromUtf8("LogoLabel"));
        LogoLabel->setGeometry(QRect(480, 10, 200, 53));
        LogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/logo200x53.jpg")));
        StatusCombo = new QComboBox(centralwidget);
        StatusCombo->addItem(QString());
        StatusCombo->addItem(QString());
        StatusCombo->setObjectName(QString::fromUtf8("StatusCombo"));
        StatusCombo->setGeometry(QRect(160, 250, 91, 41));
        StatusCombo->setFont(font3);
        StatusCombo->setCursor(QCursor(Qt::ArrowCursor));
        StatusCombo->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        StatusCombo->setEditable(true);
        Label4 = new QLabel(centralwidget);
        Label4->setObjectName(QString::fromUtf8("Label4"));
        Label4->setGeometry(QRect(30, 255, 121, 31));
        Label4->setFont(font1);
        WarehouseChange->setCentralWidget(centralwidget);
        Back1->raise();
        EditButton->raise();
        Label2->raise();
        Label1->raise();
        Label3->raise();
        Label5->raise();
        LoadingLabel->raise();
        MouldEdit->raise();
        MoldID->raise();
        ContainerCombo->raise();
        ProductID->raise();
        LogoLabel->raise();
        StatusCombo->raise();
        Label4->raise();
        menubar = new QMenuBar(WarehouseChange);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 700, 23));
        WarehouseChange->setMenuBar(menubar);
        statusbar = new QStatusBar(WarehouseChange);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        WarehouseChange->setStatusBar(statusbar);
        QWidget::setTabOrder(MoldID, ProductID);
        QWidget::setTabOrder(ProductID, MouldEdit);
        QWidget::setTabOrder(MouldEdit, StatusCombo);
        QWidget::setTabOrder(StatusCombo, ContainerCombo);
        QWidget::setTabOrder(ContainerCombo, EditButton);

        retranslateUi(WarehouseChange);

        QMetaObject::connectSlotsByName(WarehouseChange);
    } // setupUi

    void retranslateUi(QMainWindow *WarehouseChange)
    {
        WarehouseChange->setWindowTitle(QCoreApplication::translate("WarehouseChange", "MainWindow", nullptr));
        EditButton->setText(QCoreApplication::translate("WarehouseChange", "\344\277\256\346\224\271\345\217\202\346\225\260", nullptr));
        Label2->setText(QCoreApplication::translate("WarehouseChange", "\344\272\247\345\223\201\346\226\231\345\217\267:", nullptr));
        Label1->setText(QCoreApplication::translate("WarehouseChange", "\346\250\241\345\205\267\347\274\226\345\217\267:", nullptr));
        Label3->setText(QCoreApplication::translate("WarehouseChange", "\346\250\241\345\205\267\345\260\272\345\257\270:", nullptr));
        Label5->setText(QCoreApplication::translate("WarehouseChange", "\345\255\230\346\224\276\350\264\247\346\237\234:", nullptr));
        LoadingLabel->setText(QString());
        MouldEdit->setPlaceholderText(QCoreApplication::translate("WarehouseChange", "\350\257\267\350\276\223\345\205\245\346\250\241\345\205\267\345\260\272\345\257\270", nullptr));
        MoldID->setPlaceholderText(QCoreApplication::translate("WarehouseChange", "\350\257\267\350\276\223\345\205\245\346\250\241\345\205\267\347\274\226\345\217\267", nullptr));
        ProductID->setPlaceholderText(QCoreApplication::translate("WarehouseChange", "\350\257\267\350\276\223\345\205\245\344\272\247\345\223\201\346\226\231\345\217\267", nullptr));
        Back1->setText(QString());
        LogoLabel->setText(QString());
        StatusCombo->setItemText(0, QCoreApplication::translate("WarehouseChange", "\345\267\262\345\207\272\345\272\223", nullptr));
        StatusCombo->setItemText(1, QCoreApplication::translate("WarehouseChange", "\345\234\250\345\272\223\344\270\255", nullptr));

        Label4->setText(QCoreApplication::translate("WarehouseChange", "\345\275\223\345\211\215\347\212\266\346\200\201:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WarehouseChange: public Ui_WarehouseChange {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAREHOUSECHANGE_H
