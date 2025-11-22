/********************************************************************************
** Form generated from reading UI file 'aiwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIWINDOW_H
#define UI_AIWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AiWindow
{
public:
    QWidget *centralwidget;
    QPushButton *AnswerButton;
    QTextEdit *ReturnEdit;
    QTextEdit *ProblemEdit;
    QComboBox *AddBox;
    QLabel *Label1;
    QLabel *LoadLabel;
    QLabel *BackGround;
    QLabel *Label2;
    QLabel *Label3;
    QPushButton *DeepButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AiWindow)
    {
        if (AiWindow->objectName().isEmpty())
            AiWindow->setObjectName(QString::fromUtf8("AiWindow"));
        AiWindow->resize(500, 410);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AiWindow->sizePolicy().hasHeightForWidth());
        AiWindow->setSizePolicy(sizePolicy);
        AiWindow->setMinimumSize(QSize(500, 410));
        AiWindow->setMaximumSize(QSize(500, 410));
        centralwidget = new QWidget(AiWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        AnswerButton = new QPushButton(centralwidget);
        AnswerButton->setObjectName(QString::fromUtf8("AnswerButton"));
        AnswerButton->setGeometry(QRect(370, 300, 111, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        AnswerButton->setFont(font);
        AnswerButton->setCursor(QCursor(Qt::PointingHandCursor));
        AnswerButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        ReturnEdit = new QTextEdit(centralwidget);
        ReturnEdit->setObjectName(QString::fromUtf8("ReturnEdit"));
        ReturnEdit->setGeometry(QRect(20, 30, 331, 141));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        ReturnEdit->setFont(font1);
        ReturnEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        ReturnEdit->setReadOnly(true);
        ProblemEdit = new QTextEdit(centralwidget);
        ProblemEdit->setObjectName(QString::fromUtf8("ProblemEdit"));
        ProblemEdit->setGeometry(QRect(20, 210, 331, 141));
        ProblemEdit->setFont(font1);
        ProblemEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        AddBox = new QComboBox(centralwidget);
        AddBox->setObjectName(QString::fromUtf8("AddBox"));
        AddBox->setGeometry(QRect(375, 240, 101, 41));
        AddBox->setFont(font1);
        AddBox->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        Label1 = new QLabel(centralwidget);
        Label1->setObjectName(QString::fromUtf8("Label1"));
        Label1->setGeometry(QRect(20, 180, 121, 31));
        Label1->setFont(font1);
        LoadLabel = new QLabel(centralwidget);
        LoadLabel->setObjectName(QString::fromUtf8("LoadLabel"));
        LoadLabel->setGeometry(QRect(380, 70, 80, 80));
        BackGround = new QLabel(centralwidget);
        BackGround->setObjectName(QString::fromUtf8("BackGround"));
        BackGround->setGeometry(QRect(5, 5, 491, 386));
        BackGround->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);\n"
"border-radius: 15px;\n"
"border-style: outset;"));
        Label2 = new QLabel(centralwidget);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(375, 210, 101, 31));
        Label2->setFont(font1);
        Label3 = new QLabel(centralwidget);
        Label3->setObjectName(QString::fromUtf8("Label3"));
        Label3->setGeometry(QRect(330, 355, 161, 31));
        Label3->setFont(font1);
        Label3->setStyleSheet(QString::fromUtf8("color: rgb(160, 160, 160);"));
        DeepButton = new QPushButton(centralwidget);
        DeepButton->setObjectName(QString::fromUtf8("DeepButton"));
        DeepButton->setGeometry(QRect(290, 175, 61, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        DeepButton->setFont(font2);
        DeepButton->setCursor(QCursor(Qt::PointingHandCursor));
        DeepButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:white;\n"
"	background-color: rgb(85, 170, 255);\n"
"	border-radius: 10px;  border: 2px groove lavender;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{  /*\351\274\240\346\240\207\346\202\254\346\265\256\346\227\266*/\n"
"	background: rgb(49,106,234);\n"
"}\n"
"QPushButton:checked{  /*\351\274\240\346\240\207\346\214\211\344\270\213\346\227\266*/\n"
"	background:rgb(96,96,96);\n"
"	color: rgb(200, 200, 200);\n"
"}\n"
"QPushButton:!enabled {   /*\346\214\211\351\222\256\347\246\201\347\224\250\346\227\266*/\n"
"	background: rgb(100, 100, 100);\n"
"	color: rgb(200, 200, 200);\n"
"}\n"
""));
        DeepButton->setCheckable(true);
        DeepButton->setChecked(false);
        AiWindow->setCentralWidget(centralwidget);
        BackGround->raise();
        AnswerButton->raise();
        ReturnEdit->raise();
        ProblemEdit->raise();
        AddBox->raise();
        Label1->raise();
        LoadLabel->raise();
        Label2->raise();
        Label3->raise();
        DeepButton->raise();
        menubar = new QMenuBar(AiWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 500, 23));
        AiWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AiWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AiWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(ReturnEdit, ProblemEdit);
        QWidget::setTabOrder(ProblemEdit, AddBox);
        QWidget::setTabOrder(AddBox, AnswerButton);
        QWidget::setTabOrder(AnswerButton, DeepButton);

        retranslateUi(AiWindow);

        QMetaObject::connectSlotsByName(AiWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AiWindow)
    {
        AiWindow->setWindowTitle(QCoreApplication::translate("AiWindow", "MainWindow", nullptr));
        AnswerButton->setText(QCoreApplication::translate("AiWindow", "\346\217\220\344\272\244\351\227\256\351\242\230", nullptr));
        ReturnEdit->setPlaceholderText(QCoreApplication::translate("AiWindow", "\346\235\245\350\207\252DeepSeek\347\232\204\345\233\236\347\255\224", nullptr));
        ProblemEdit->setPlaceholderText(QCoreApplication::translate("AiWindow", "\350\257\267\345\234\250\346\255\244\345\244\204\350\276\223\345\205\245\346\202\250\347\232\204\351\227\256\351\242\230\357\274\210\345\246\202\357\274\232\345\275\223\345\211\215\350\241\250\345\223\252\344\272\233\346\250\241\345\205\267\351\234\200\350\246\201\344\277\235\345\205\273\357\274\237\357\274\211", nullptr));
        Label1->setText(QCoreApplication::translate("AiWindow", "\350\257\267\350\276\223\345\205\245\346\202\250\347\232\204\351\227\256\351\242\230:", nullptr));
        LoadLabel->setText(QString());
        BackGround->setText(QString());
        Label2->setText(QCoreApplication::translate("AiWindow", "\351\231\204\345\212\240\350\241\250\346\240\274\345\206\205\345\256\271", nullptr));
        Label3->setText(QCoreApplication::translate("AiWindow", "\345\237\272\344\272\216DeepSeek\345\244\247\346\250\241\345\236\213", nullptr));
        DeepButton->setText(QCoreApplication::translate("AiWindow", "\346\267\261\345\272\246\346\200\235\350\200\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AiWindow: public Ui_AiWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIWINDOW_H
