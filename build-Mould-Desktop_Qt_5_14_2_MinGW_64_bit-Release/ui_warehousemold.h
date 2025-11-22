/********************************************************************************
** Form generated from reading UI file 'warehousemold.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAREHOUSEMOLD_H
#define UI_WAREHOUSEMOLD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WarehouseMold
{
public:
    QWidget *centralwidget;
    QListView *MoldView;
    QLabel *Label2;
    QLabel *Label6;
    QLineEdit *MaterialEdit;
    QLineEdit *ProductEdit;
    QLabel *Label5;
    QPushButton *EditButton;
    QLabel *SpareNum;
    QPushButton *ReturnButton;
    QLabel *BackGround;
    QLabel *LogoLabel;
    QLabel *Label1;
    QLabel *Label3;
    QComboBox *PartCombo;
    QLineEdit *MoldEdit;
    QLabel *Label4_1;
    QPushButton *ChangeButton;
    QLineEdit *CustomEdit;
    QLabel *Label4_2;
    QLineEdit *FMoldEdit;
    QPushButton *FindButton;
    QLineEdit *DetailMaterial;
    QLabel *Label7;
    QLineEdit *DetailWork;
    QLabel *Label8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WarehouseMold)
    {
        if (WarehouseMold->objectName().isEmpty())
            WarehouseMold->setObjectName(QString::fromUtf8("WarehouseMold"));
        WarehouseMold->resize(580, 580);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WarehouseMold->sizePolicy().hasHeightForWidth());
        WarehouseMold->setSizePolicy(sizePolicy);
        WarehouseMold->setMinimumSize(QSize(580, 580));
        WarehouseMold->setMaximumSize(QSize(580, 580));
        centralwidget = new QWidget(WarehouseMold);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MoldView = new QListView(centralwidget);
        MoldView->setObjectName(QString::fromUtf8("MoldView"));
        MoldView->setGeometry(QRect(25, 139, 161, 241));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(18);
        MoldView->setFont(font);
        MoldView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        MoldView->setMouseTracking(false);
        MoldView->setStyleSheet(QString::fromUtf8("QListView{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MoldView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Label2 = new QLabel(centralwidget);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(200, 110, 111, 31));
        Label2->setFont(font);
        Label6 = new QLabel(centralwidget);
        Label6->setObjectName(QString::fromUtf8("Label6"));
        Label6->setGeometry(QRect(200, 340, 111, 41));
        Label6->setFont(font);
        MaterialEdit = new QLineEdit(centralwidget);
        MaterialEdit->setObjectName(QString::fromUtf8("MaterialEdit"));
        MaterialEdit->setGeometry(QRect(310, 340, 251, 41));
        MaterialEdit->setFont(font);
        MaterialEdit->setCursor(QCursor(Qt::IBeamCursor));
        MaterialEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MaterialEdit->setReadOnly(false);
        ProductEdit = new QLineEdit(centralwidget);
        ProductEdit->setObjectName(QString::fromUtf8("ProductEdit"));
        ProductEdit->setGeometry(QRect(310, 280, 251, 41));
        ProductEdit->setFont(font);
        ProductEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductEdit->setReadOnly(false);
        Label5 = new QLabel(centralwidget);
        Label5->setObjectName(QString::fromUtf8("Label5"));
        Label5->setGeometry(QRect(200, 280, 111, 41));
        Label5->setFont(font);
        EditButton = new QPushButton(centralwidget);
        EditButton->setObjectName(QString::fromUtf8("EditButton"));
        EditButton->setGeometry(QRect(360, 510, 91, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setWeight(50);
        EditButton->setFont(font1);
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
"	color: rgb(200, 200, 200);\n"
"}"));
        SpareNum = new QLabel(centralwidget);
        SpareNum->setObjectName(QString::fromUtf8("SpareNum"));
        SpareNum->setGeometry(QRect(310, 110, 51, 31));
        SpareNum->setFont(font);
        ReturnButton = new QPushButton(centralwidget);
        ReturnButton->setObjectName(QString::fromUtf8("ReturnButton"));
        ReturnButton->setGeometry(QRect(470, 510, 91, 41));
        ReturnButton->setFont(font1);
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
        BackGround->setGeometry(QRect(5, 5, 571, 556));
        BackGround->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);\n"
"border-radius: 15px;\n"
"border-style: outset;"));
        LogoLabel = new QLabel(centralwidget);
        LogoLabel->setObjectName(QString::fromUtf8("LogoLabel"));
        LogoLabel->setGeometry(QRect(370, 10, 200, 53));
        LogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/logo200x53.jpg")));
        Label1 = new QLabel(centralwidget);
        Label1->setObjectName(QString::fromUtf8("Label1"));
        Label1->setGeometry(QRect(20, 105, 171, 31));
        Label1->setFont(font);
        Label3 = new QLabel(centralwidget);
        Label3->setObjectName(QString::fromUtf8("Label3"));
        Label3->setGeometry(QRect(370, 105, 111, 41));
        Label3->setFont(font);
        PartCombo = new QComboBox(centralwidget);
        PartCombo->setObjectName(QString::fromUtf8("PartCombo"));
        PartCombo->setGeometry(QRect(480, 105, 81, 41));
        PartCombo->setFont(font);
        PartCombo->setCursor(QCursor(Qt::ArrowCursor));
        PartCombo->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MoldEdit = new QLineEdit(centralwidget);
        MoldEdit->setObjectName(QString::fromUtf8("MoldEdit"));
        MoldEdit->setGeometry(QRect(310, 160, 251, 41));
        MoldEdit->setFont(font);
        MoldEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MoldEdit->setReadOnly(false);
        Label4_1 = new QLabel(centralwidget);
        Label4_1->setObjectName(QString::fromUtf8("Label4_1"));
        Label4_1->setGeometry(QRect(200, 160, 111, 41));
        Label4_1->setFont(font);
        ChangeButton = new QPushButton(centralwidget);
        ChangeButton->setObjectName(QString::fromUtf8("ChangeButton"));
        ChangeButton->setGeometry(QRect(90, 20, 101, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        ChangeButton->setFont(font2);
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
        CustomEdit = new QLineEdit(centralwidget);
        CustomEdit->setObjectName(QString::fromUtf8("CustomEdit"));
        CustomEdit->setGeometry(QRect(310, 220, 251, 41));
        CustomEdit->setFont(font);
        CustomEdit->setCursor(QCursor(Qt::IBeamCursor));
        CustomEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        CustomEdit->setReadOnly(false);
        Label4_2 = new QLabel(centralwidget);
        Label4_2->setObjectName(QString::fromUtf8("Label4_2"));
        Label4_2->setGeometry(QRect(200, 220, 111, 41));
        Label4_2->setFont(font);
        FMoldEdit = new QLineEdit(centralwidget);
        FMoldEdit->setObjectName(QString::fromUtf8("FMoldEdit"));
        FMoldEdit->setGeometry(QRect(20, 60, 171, 41));
        FMoldEdit->setFont(font);
        FMoldEdit->setCursor(QCursor(Qt::IBeamCursor));
        FMoldEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        FMoldEdit->setReadOnly(false);
        FindButton = new QPushButton(centralwidget);
        FindButton->setObjectName(QString::fromUtf8("FindButton"));
        FindButton->setGeometry(QRect(200, 60, 91, 41));
        FindButton->setFont(font1);
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
        DetailMaterial = new QLineEdit(centralwidget);
        DetailMaterial->setObjectName(QString::fromUtf8("DetailMaterial"));
        DetailMaterial->setGeometry(QRect(140, 400, 421, 41));
        DetailMaterial->setFont(font);
        DetailMaterial->setCursor(QCursor(Qt::IBeamCursor));
        DetailMaterial->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        DetailMaterial->setReadOnly(false);
        Label7 = new QLabel(centralwidget);
        Label7->setObjectName(QString::fromUtf8("Label7"));
        Label7->setGeometry(QRect(30, 400, 111, 41));
        Label7->setFont(font);
        DetailWork = new QLineEdit(centralwidget);
        DetailWork->setObjectName(QString::fromUtf8("DetailWork"));
        DetailWork->setGeometry(QRect(140, 455, 421, 41));
        DetailWork->setFont(font);
        DetailWork->setCursor(QCursor(Qt::IBeamCursor));
        DetailWork->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        DetailWork->setReadOnly(false);
        Label8 = new QLabel(centralwidget);
        Label8->setObjectName(QString::fromUtf8("Label8"));
        Label8->setGeometry(QRect(30, 455, 111, 41));
        Label8->setFont(font);
        WarehouseMold->setCentralWidget(centralwidget);
        BackGround->raise();
        MoldView->raise();
        Label2->raise();
        Label6->raise();
        MaterialEdit->raise();
        ProductEdit->raise();
        Label5->raise();
        EditButton->raise();
        SpareNum->raise();
        ReturnButton->raise();
        LogoLabel->raise();
        Label1->raise();
        Label3->raise();
        PartCombo->raise();
        MoldEdit->raise();
        Label4_1->raise();
        ChangeButton->raise();
        CustomEdit->raise();
        Label4_2->raise();
        FMoldEdit->raise();
        FindButton->raise();
        DetailMaterial->raise();
        Label7->raise();
        DetailWork->raise();
        Label8->raise();
        menubar = new QMenuBar(WarehouseMold);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 580, 23));
        WarehouseMold->setMenuBar(menubar);
        statusbar = new QStatusBar(WarehouseMold);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        WarehouseMold->setStatusBar(statusbar);
        QWidget::setTabOrder(ChangeButton, FMoldEdit);
        QWidget::setTabOrder(FMoldEdit, FindButton);
        QWidget::setTabOrder(FindButton, MoldView);
        QWidget::setTabOrder(MoldView, PartCombo);
        QWidget::setTabOrder(PartCombo, MoldEdit);
        QWidget::setTabOrder(MoldEdit, CustomEdit);
        QWidget::setTabOrder(CustomEdit, ProductEdit);
        QWidget::setTabOrder(ProductEdit, MaterialEdit);
        QWidget::setTabOrder(MaterialEdit, DetailMaterial);
        QWidget::setTabOrder(DetailMaterial, DetailWork);
        QWidget::setTabOrder(DetailWork, EditButton);
        QWidget::setTabOrder(EditButton, ReturnButton);

        retranslateUi(WarehouseMold);

        QMetaObject::connectSlotsByName(WarehouseMold);
    } // setupUi

    void retranslateUi(QMainWindow *WarehouseMold)
    {
        WarehouseMold->setWindowTitle(QCoreApplication::translate("WarehouseMold", "MainWindow", nullptr));
        Label2->setText(QCoreApplication::translate("WarehouseMold", "\345\244\207\344\273\266\346\225\260\351\207\217:", nullptr));
        Label6->setText(QCoreApplication::translate("WarehouseMold", "\344\272\247\345\223\201\346\226\231\345\217\267:", nullptr));
        MaterialEdit->setPlaceholderText(QCoreApplication::translate("WarehouseMold", "\350\257\267\350\276\223\345\205\245\344\272\247\345\223\201\346\226\231\345\217\267", nullptr));
        ProductEdit->setPlaceholderText(QCoreApplication::translate("WarehouseMold", "\350\257\267\350\276\223\345\205\245\344\272\247\345\223\201\345\220\215\347\247\260", nullptr));
        Label5->setText(QCoreApplication::translate("WarehouseMold", "\344\272\247\345\223\201\345\220\215\347\247\260:", nullptr));
        EditButton->setText(QCoreApplication::translate("WarehouseMold", "\344\277\256\346\224\271", nullptr));
        SpareNum->setText(QString());
        ReturnButton->setText(QCoreApplication::translate("WarehouseMold", "\350\277\224\345\233\236", nullptr));
        BackGround->setText(QString());
        LogoLabel->setText(QString());
        Label1->setText(QCoreApplication::translate("WarehouseMold", "\351\200\211\346\213\251\345\206\262\345\216\213\346\250\241\345\205\267\342\254\213", nullptr));
        Label3->setText(QCoreApplication::translate("WarehouseMold", "\351\232\266\345\261\236\351\203\250\351\227\250:", nullptr));
        MoldEdit->setPlaceholderText(QCoreApplication::translate("WarehouseMold", "\350\257\267\350\276\223\345\205\245\346\250\241\345\205\267\347\274\226\345\217\267", nullptr));
        Label4_1->setText(QCoreApplication::translate("WarehouseMold", "\346\250\241\345\205\267\347\274\226\345\217\267:", nullptr));
        ChangeButton->setText(QCoreApplication::translate("WarehouseMold", "\345\210\207\346\215\242\344\270\272\346\210\220\345\236\213\345\244\207\344\273\266", nullptr));
        CustomEdit->setPlaceholderText(QCoreApplication::translate("WarehouseMold", "\350\257\267\350\276\223\345\205\245\345\256\242\346\210\267\346\250\241\345\217\267", nullptr));
        Label4_2->setText(QCoreApplication::translate("WarehouseMold", "\345\256\242\346\210\267\346\250\241\345\217\267:", nullptr));
        FMoldEdit->setPlaceholderText(QCoreApplication::translate("WarehouseMold", "\350\276\223\345\205\245\346\250\241\345\205\267\347\274\226\345\217\267", nullptr));
        FindButton->setText(QCoreApplication::translate("WarehouseMold", "\346\237\245\346\211\276", nullptr));
        DetailMaterial->setPlaceholderText(QCoreApplication::translate("WarehouseMold", "\350\257\267\350\276\223\345\205\245\345\205\267\344\275\223\346\226\231\345\217\267\357\274\214\346\257\217\344\270\252\346\226\231\345\217\267\345\211\215\351\235\242\345\212\240#", nullptr));
        Label7->setText(QCoreApplication::translate("WarehouseMold", "\345\205\267\344\275\223\346\226\231\345\217\267:", nullptr));
        DetailWork->setText(QString());
        DetailWork->setPlaceholderText(QCoreApplication::translate("WarehouseMold", "\350\257\267\350\276\223\345\205\245\350\257\245\346\250\241\345\205\267\345\267\245\347\253\231\357\274\214\346\257\217\344\270\252\345\267\245\347\253\231\345\211\215\351\235\242\345\212\240#", nullptr));
        Label8->setText(QCoreApplication::translate("WarehouseMold", "\346\250\241\345\205\267\345\267\245\347\253\231:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WarehouseMold: public Ui_WarehouseMold {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAREHOUSEMOLD_H
