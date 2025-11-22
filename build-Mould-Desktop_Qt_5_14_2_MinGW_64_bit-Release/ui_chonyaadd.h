/********************************************************************************
** Form generated from reading UI file 'chonyaadd.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHONYAADD_H
#define UI_CHONYAADD_H

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

class Ui_ChonyaAdd
{
public:
    QWidget *centralwidget;
    QLabel *Label6;
    QLabel *Label3;
    QLabel *Label5;
    QLabel *Label2;
    QLineEdit *MoldID;
    QLabel *Label1;
    QLineEdit *ProductStand;
    QLabel *Label4;
    QPushButton *AddButton;
    QLineEdit *OutNum_1;
    QLabel *Label7;
    QLineEdit *OutNum_2;
    QLabel *LoadingLabel;
    QLabel *LogoLabel;
    QLabel *BackGround;
    QTextEdit *ProductID;
    QTextEdit *ProductName;
    QComboBox *ControlStand;
    QLineEdit *LifeNum;
    QLabel *Label8;
    QLineEdit *MachineNum;
    QLabel *Label9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChonyaAdd)
    {
        if (ChonyaAdd->objectName().isEmpty())
            ChonyaAdd->setObjectName(QString::fromUtf8("ChonyaAdd"));
        ChonyaAdd->resize(665, 470);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChonyaAdd->sizePolicy().hasHeightForWidth());
        ChonyaAdd->setSizePolicy(sizePolicy);
        ChonyaAdd->setMinimumSize(QSize(665, 470));
        ChonyaAdd->setMaximumSize(QSize(665, 470));
        centralwidget = new QWidget(ChonyaAdd);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Label6 = new QLabel(centralwidget);
        Label6->setObjectName(QString::fromUtf8("Label6"));
        Label6->setGeometry(QRect(305, 320, 121, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(20);
        Label6->setFont(font);
        Label3 = new QLabel(centralwidget);
        Label3->setObjectName(QString::fromUtf8("Label3"));
        Label3->setGeometry(QRect(40, 200, 121, 31));
        Label3->setFont(font);
        Label5 = new QLabel(centralwidget);
        Label5->setObjectName(QString::fromUtf8("Label5"));
        Label5->setGeometry(QRect(40, 320, 121, 31));
        Label5->setFont(font);
        Label2 = new QLabel(centralwidget);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(40, 125, 121, 31));
        Label2->setFont(font);
        MoldID = new QLineEdit(centralwidget);
        MoldID->setObjectName(QString::fromUtf8("MoldID"));
        MoldID->setGeometry(QRect(170, 315, 101, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(16);
        MoldID->setFont(font1);
        MoldID->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MoldID->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        MoldID->setReadOnly(false);
        Label1 = new QLabel(centralwidget);
        Label1->setObjectName(QString::fromUtf8("Label1"));
        Label1->setGeometry(QRect(40, 45, 121, 31));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Label1->sizePolicy().hasHeightForWidth());
        Label1->setSizePolicy(sizePolicy1);
        Label1->setFont(font);
        Label1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Label1->setWordWrap(false);
        ProductStand = new QLineEdit(centralwidget);
        ProductStand->setObjectName(QString::fromUtf8("ProductStand"));
        ProductStand->setGeometry(QRect(170, 195, 281, 41));
        ProductStand->setFont(font1);
        ProductStand->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductStand->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        ProductStand->setReadOnly(false);
        Label4 = new QLabel(centralwidget);
        Label4->setObjectName(QString::fromUtf8("Label4"));
        Label4->setGeometry(QRect(40, 260, 121, 31));
        Label4->setFont(font);
        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setEnabled(true);
        AddButton->setGeometry(QRect(520, 245, 131, 61));
        sizePolicy1.setHeightForWidth(AddButton->sizePolicy().hasHeightForWidth());
        AddButton->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        AddButton->setFont(font2);
        AddButton->setCursor(QCursor(Qt::PointingHandCursor));
        AddButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddButton->setIcon(icon);
        AddButton->setIconSize(QSize(20, 20));
        OutNum_1 = new QLineEdit(centralwidget);
        OutNum_1->setObjectName(QString::fromUtf8("OutNum_1"));
        OutNum_1->setGeometry(QRect(435, 315, 51, 41));
        OutNum_1->setFont(font1);
        OutNum_1->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        OutNum_1->setAlignment(Qt::AlignCenter);
        OutNum_1->setReadOnly(false);
        Label7 = new QLabel(centralwidget);
        Label7->setObjectName(QString::fromUtf8("Label7"));
        Label7->setGeometry(QRect(485, 315, 56, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(24);
        font3.setBold(false);
        font3.setWeight(50);
        Label7->setFont(font3);
        Label7->setAlignment(Qt::AlignCenter);
        OutNum_2 = new QLineEdit(centralwidget);
        OutNum_2->setObjectName(QString::fromUtf8("OutNum_2"));
        OutNum_2->setGeometry(QRect(540, 315, 51, 41));
        OutNum_2->setFont(font1);
        OutNum_2->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        OutNum_2->setAlignment(Qt::AlignCenter);
        OutNum_2->setReadOnly(false);
        LoadingLabel = new QLabel(centralwidget);
        LoadingLabel->setObjectName(QString::fromUtf8("LoadingLabel"));
        LoadingLabel->setGeometry(QRect(460, 30, 200, 200));
        LoadingLabel->setLayoutDirection(Qt::LeftToRight);
        LogoLabel = new QLabel(centralwidget);
        LogoLabel->setObjectName(QString::fromUtf8("LogoLabel"));
        LogoLabel->setGeometry(QRect(540, 410, 110, 30));
        LogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/logo110x30.jpg")));
        BackGround = new QLabel(centralwidget);
        BackGround->setObjectName(QString::fromUtf8("BackGround"));
        BackGround->setGeometry(QRect(0, 0, 666, 471));
        BackGround->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        ProductID = new QTextEdit(centralwidget);
        ProductID->setObjectName(QString::fromUtf8("ProductID"));
        ProductID->setGeometry(QRect(170, 115, 261, 61));
        ProductID->setFont(font1);
        ProductID->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        ProductID->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductID->setReadOnly(false);
        ProductName = new QTextEdit(centralwidget);
        ProductName->setObjectName(QString::fromUtf8("ProductName"));
        ProductName->setGeometry(QRect(170, 30, 261, 61));
        ProductName->setFont(font1);
        ProductName->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        ProductName->setStyleSheet(QString::fromUtf8("QTextEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductName->setReadOnly(false);
        ControlStand = new QComboBox(centralwidget);
        ControlStand->addItem(QString());
        ControlStand->addItem(QString());
        ControlStand->addItem(QString());
        ControlStand->addItem(QString());
        ControlStand->addItem(QString());
        ControlStand->addItem(QString());
        ControlStand->setObjectName(QString::fromUtf8("ControlStand"));
        ControlStand->setGeometry(QRect(170, 255, 331, 41));
        ControlStand->setFont(font1);
        ControlStand->setCursor(QCursor(Qt::ArrowCursor));
        ControlStand->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        LifeNum = new QLineEdit(centralwidget);
        LifeNum->setObjectName(QString::fromUtf8("LifeNum"));
        LifeNum->setGeometry(QRect(240, 370, 66, 41));
        LifeNum->setFont(font1);
        LifeNum->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        LifeNum->setAlignment(Qt::AlignCenter);
        LifeNum->setReadOnly(false);
        Label8 = new QLabel(centralwidget);
        Label8->setObjectName(QString::fromUtf8("Label8"));
        Label8->setGeometry(QRect(30, 375, 201, 31));
        Label8->setFont(font);
        MachineNum = new QLineEdit(centralwidget);
        MachineNum->setObjectName(QString::fromUtf8("MachineNum"));
        MachineNum->setGeometry(QRect(470, 370, 51, 41));
        MachineNum->setFont(font1);
        MachineNum->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(160, 175, 200);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MachineNum->setAlignment(Qt::AlignCenter);
        MachineNum->setReadOnly(false);
        Label9 = new QLabel(centralwidget);
        Label9->setObjectName(QString::fromUtf8("Label9"));
        Label9->setGeometry(QRect(340, 375, 121, 31));
        Label9->setFont(font);
        ChonyaAdd->setCentralWidget(centralwidget);
        BackGround->raise();
        Label6->raise();
        Label3->raise();
        Label5->raise();
        Label2->raise();
        MoldID->raise();
        Label1->raise();
        ProductStand->raise();
        Label4->raise();
        AddButton->raise();
        OutNum_1->raise();
        Label7->raise();
        OutNum_2->raise();
        LoadingLabel->raise();
        LogoLabel->raise();
        ProductID->raise();
        ProductName->raise();
        ControlStand->raise();
        LifeNum->raise();
        Label8->raise();
        MachineNum->raise();
        Label9->raise();
        menubar = new QMenuBar(ChonyaAdd);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 665, 23));
        ChonyaAdd->setMenuBar(menubar);
        statusbar = new QStatusBar(ChonyaAdd);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ChonyaAdd->setStatusBar(statusbar);
        QWidget::setTabOrder(ProductName, ProductID);
        QWidget::setTabOrder(ProductID, ProductStand);
        QWidget::setTabOrder(ProductStand, ControlStand);
        QWidget::setTabOrder(ControlStand, MoldID);
        QWidget::setTabOrder(MoldID, OutNum_1);
        QWidget::setTabOrder(OutNum_1, OutNum_2);
        QWidget::setTabOrder(OutNum_2, LifeNum);
        QWidget::setTabOrder(LifeNum, MachineNum);
        QWidget::setTabOrder(MachineNum, AddButton);

        retranslateUi(ChonyaAdd);

        QMetaObject::connectSlotsByName(ChonyaAdd);
    } // setupUi

    void retranslateUi(QMainWindow *ChonyaAdd)
    {
        ChonyaAdd->setWindowTitle(QCoreApplication::translate("ChonyaAdd", "MainWindow", nullptr));
        Label6->setText(QCoreApplication::translate("ChonyaAdd", "\344\272\247\345\223\201\345\207\272\346\225\260:", nullptr));
        Label3->setText(QCoreApplication::translate("ChonyaAdd", "\346\235\220\346\226\231\350\247\204\346\240\274:", nullptr));
        Label5->setText(QCoreApplication::translate("ChonyaAdd", "\346\250\241\345\205\267\347\274\226\345\217\267:", nullptr));
        Label2->setText(QCoreApplication::translate("ChonyaAdd", "\344\272\247\345\223\201\346\226\231\345\217\267:", nullptr));
        MoldID->setPlaceholderText(QCoreApplication::translate("ChonyaAdd", "\350\276\223\345\205\245\347\274\226\345\217\267", nullptr));
        Label1->setText(QCoreApplication::translate("ChonyaAdd", "\344\272\247\345\223\201\345\220\215\347\247\260:", nullptr));
        ProductStand->setPlaceholderText(QCoreApplication::translate("ChonyaAdd", "\350\257\267\350\276\223\345\205\245\346\235\220\346\226\231\350\247\204\346\240\274", nullptr));
        Label4->setText(QCoreApplication::translate("ChonyaAdd", "\347\256\241\345\210\266\346\240\207\345\207\206:", nullptr));
        AddButton->setText(QCoreApplication::translate("ChonyaAdd", "\345\242\236\345\212\240\346\250\241\345\205\267", nullptr));
        OutNum_1->setText(QCoreApplication::translate("ChonyaAdd", "1", nullptr));
        Label7->setText(QCoreApplication::translate("ChonyaAdd", "*", nullptr));
        OutNum_2->setText(QCoreApplication::translate("ChonyaAdd", "1", nullptr));
        LoadingLabel->setText(QString());
        LogoLabel->setText(QString());
        BackGround->setText(QString());
        ProductID->setPlaceholderText(QCoreApplication::translate("ChonyaAdd", "\350\257\267\350\276\223\345\205\245\344\272\247\345\223\201\346\226\231\345\217\267", nullptr));
        ProductName->setPlaceholderText(QCoreApplication::translate("ChonyaAdd", "\350\257\267\350\276\223\345\205\245\344\272\247\345\223\201\345\220\215\347\247\260", nullptr));
        ControlStand->setItemText(0, QCoreApplication::translate("ChonyaAdd", "NULL", nullptr));
        ControlStand->setItemText(1, QCoreApplication::translate("ChonyaAdd", "\351\223\234\346\235\220\346\235\220\346\226\231\345\216\232\345\272\246\350\247\204\346\240\274\357\274\2340.3mm", nullptr));
        ControlStand->setItemText(2, QCoreApplication::translate("ChonyaAdd", "\351\223\234\346\235\220\346\235\220\346\226\231\345\216\232\345\272\246\350\247\204\346\240\274\342\211\2470.3\344\270\224\357\271\2440.5mm", nullptr));
        ControlStand->setItemText(3, QCoreApplication::translate("ChonyaAdd", "\351\223\234\346\235\220\346\235\220\346\226\231\345\216\232\345\272\246\350\247\204\346\240\274\342\211\2470.5mm", nullptr));
        ControlStand->setItemText(4, QCoreApplication::translate("ChonyaAdd", "\344\270\215\351\224\210\351\222\242\346\235\220\346\226\231\345\216\232\345\272\246\350\247\204\346\240\274\357\274\2340.5mm", nullptr));
        ControlStand->setItemText(5, QCoreApplication::translate("ChonyaAdd", "\344\270\215\351\224\210\351\222\242\346\235\220\346\226\231\345\216\232\345\272\246\350\247\204\346\240\274\342\211\2470.5m", nullptr));

        LifeNum->setText(QCoreApplication::translate("ChonyaAdd", "200", nullptr));
        Label8->setText(QCoreApplication::translate("ChonyaAdd", "\346\250\241\345\205\267\345\257\277\345\221\275\345\206\262\346\254\241\346\225\260:", nullptr));
        MachineNum->setPlaceholderText(QCoreApplication::translate("ChonyaAdd", "1#", nullptr));
        Label9->setText(QCoreApplication::translate("ChonyaAdd", "\345\242\236\345\212\240\346\234\272\345\217\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChonyaAdd: public Ui_ChonyaAdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHONYAADD_H
