/********************************************************************************
** Form generated from reading UI file 'warehousewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAREHOUSEWINDOW_H
#define UI_WAREHOUSEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WarehouseWindow
{
public:
    QWidget *centralwidget;
    QLabel *LogoLabel2;
    QPushButton *AddButton;
    QPushButton *OutButton;
    QPushButton *ManageButton;
    QPushButton *EnterButton;
    QTabWidget *tabWidget;
    QWidget *Tab1;
    QHBoxLayout *horizontalLayout_3;
    QTableView *ModleList1;
    QWidget *Tab2;
    QHBoxLayout *horizontalLayout_4;
    QTableView *ModleList2;
    QWidget *Tab3;
    QHBoxLayout *horizontalLayout;
    QTreeView *CyView;
    QWidget *Tab4;
    QHBoxLayout *horizontalLayout_2;
    QTreeView *CxView;
    QWidget *widget1;
    QLabel *Label1_2;
    QLineEdit *MoldEdit;
    QLabel *Label1_1;
    QLineEdit *SpareEdit;
    QPushButton *RefreshButton;
    QLabel *Label2;
    QLineEdit *PriceEdit;
    QLabel *Label3;
    QLineEdit *FirstEdit;
    QPushButton *WorkButton;
    QLineEdit *StataEdit;
    QLineEdit *ProductEdit;
    QLabel *Label5;
    QPushButton *EditButton;
    QLineEdit *MaterialEdit;
    QLabel *LoadingLabel;
    QLabel *Label6;
    QLabel *Label4;
    QLineEdit *OtherEdit;
    QLabel *Label7;
    QPushButton *DeleteButton;
    QPushButton *FindButton;
    QPushButton *AIButton;
    QPushButton *MessageLabel;
    QLabel *LogoLabel1;
    QCommandLinkButton *commandLinkButton;
    QPushButton *ProductButton;
    QPushButton *ReturnButton;
    QPushButton *CheckButton;
    QWidget *widget2;
    QLabel *Label1c;
    QLineEdit *MoldEditc;
    QPushButton *WorkButtonc;
    QLineEdit *ModelEditc;
    QLabel *Label3c;
    QLabel *LoadingLabelc;
    QPushButton *DeleteButtonc;
    QPushButton *FindButtonc;
    QPushButton *AIButtonc;
    QLabel *LogoLabelc;
    QCommandLinkButton *commandLinkButtonc;
    QPushButton *ReturnButtonc;
    QPushButton *OutButtonc;
    QLineEdit *MaterialEditc;
    QLabel *Label2c;
    QComboBox *ContainerCombo;
    QLabel *Label4c;
    QPushButton *EnterButtonc;
    QPushButton *ChangeButtonc;
    QPushButton *RefreshButtonc;
    QPushButton *MessageLabelc;
    QPushButton *BomButton;
    QMenuBar *menubar;

    void setupUi(QMainWindow *WarehouseWindow)
    {
        if (WarehouseWindow->objectName().isEmpty())
            WarehouseWindow->setObjectName(QString::fromUtf8("WarehouseWindow"));
        WarehouseWindow->resize(1235, 815);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WarehouseWindow->sizePolicy().hasHeightForWidth());
        WarehouseWindow->setSizePolicy(sizePolicy);
        WarehouseWindow->setMinimumSize(QSize(1235, 815));
        WarehouseWindow->setMaximumSize(QSize(1235, 815));
        QFont font;
        font.setFamily(QString::fromUtf8("3ds"));
        font.setPointSize(16);
        WarehouseWindow->setFont(font);
        WarehouseWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(WarehouseWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(800, 600));
        LogoLabel2 = new QLabel(centralwidget);
        LogoLabel2->setObjectName(QString::fromUtf8("LogoLabel2"));
        LogoLabel2->setGeometry(QRect(20, 20, 64, 64));
        LogoLabel2->setPixmap(QPixmap(QString::fromUtf8(":/images/warehouse_logo.png")));
        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setEnabled(false);
        AddButton->setGeometry(QRect(100, 20, 211, 61));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(AddButton->sizePolicy().hasHeightForWidth());
        AddButton->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        AddButton->setFont(font1);
        AddButton->setCursor(QCursor(Qt::PointingHandCursor));
        AddButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddButton->setIcon(icon);
        AddButton->setIconSize(QSize(20, 20));
        OutButton = new QPushButton(centralwidget);
        OutButton->setObjectName(QString::fromUtf8("OutButton"));
        OutButton->setGeometry(QRect(320, 20, 181, 61));
        sizePolicy1.setHeightForWidth(OutButton->sizePolicy().hasHeightForWidth());
        OutButton->setSizePolicy(sizePolicy1);
        OutButton->setFont(font1);
        OutButton->setCursor(QCursor(Qt::PointingHandCursor));
        OutButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/out.png"), QSize(), QIcon::Normal, QIcon::Off);
        OutButton->setIcon(icon1);
        OutButton->setIconSize(QSize(20, 20));
        ManageButton = new QPushButton(centralwidget);
        ManageButton->setObjectName(QString::fromUtf8("ManageButton"));
        ManageButton->setEnabled(false);
        ManageButton->setGeometry(QRect(700, 20, 261, 61));
        sizePolicy1.setHeightForWidth(ManageButton->sizePolicy().hasHeightForWidth());
        ManageButton->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        ManageButton->setFont(font2);
        ManageButton->setCursor(QCursor(Qt::PointingHandCursor));
        ManageButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/enter.png"), QSize(), QIcon::Normal, QIcon::Off);
        ManageButton->setIcon(icon2);
        ManageButton->setIconSize(QSize(20, 20));
        EnterButton = new QPushButton(centralwidget);
        EnterButton->setObjectName(QString::fromUtf8("EnterButton"));
        EnterButton->setGeometry(QRect(510, 20, 181, 61));
        sizePolicy1.setHeightForWidth(EnterButton->sizePolicy().hasHeightForWidth());
        EnterButton->setSizePolicy(sizePolicy1);
        EnterButton->setFont(font1);
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
"}\n"
"QPushButton:!enabled {   /*\346\214\211\351\222\256\347\246\201\347\224\250\346\227\266*/\n"
"	background: rgb(100, 100, 100);\n"
"	color: rgb(200, 200, 200);\n"
"}\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/entry.png"), QSize(), QIcon::Normal, QIcon::Off);
        EnterButton->setIcon(icon3);
        EnterButton->setIconSize(QSize(25, 25));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 100, 655, 690));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        tabWidget->setFont(font3);
        Tab1 = new QWidget();
        Tab1->setObjectName(QString::fromUtf8("Tab1"));
        horizontalLayout_3 = new QHBoxLayout(Tab1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        ModleList1 = new QTableView(Tab1);
        ModleList1->setObjectName(QString::fromUtf8("ModleList1"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(18);
        font4.setBold(false);
        font4.setWeight(50);
        ModleList1->setFont(font4);
        ModleList1->setStyleSheet(QString::fromUtf8("QTableView{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}\n"
"/* \350\256\276\347\275\256\350\241\250\345\244\264 */\n"
"QHeaderView::section {\n"
"    font-size: 18px;\n"
"}\n"
"/* \350\256\276\347\275\256\351\246\226\345\210\227\345\215\225\345\205\203\346\240\274\345\255\227\344\275\223 */\n"
"QTableView::item:first-column {\n"
"    font-size: 18px;\n"
"}\n"
""));
        ModleList1->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ModleList1->setSelectionMode(QAbstractItemView::SingleSelection);
        ModleList1->setSelectionBehavior(QAbstractItemView::SelectRows);
        ModleList1->setSortingEnabled(true);
        ModleList1->setWordWrap(false);
        ModleList1->horizontalHeader()->setVisible(false);
        ModleList1->horizontalHeader()->setCascadingSectionResizes(false);
        ModleList1->horizontalHeader()->setHighlightSections(true);
        ModleList1->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        ModleList1->horizontalHeader()->setStretchLastSection(false);
        ModleList1->verticalHeader()->setVisible(false);
        ModleList1->verticalHeader()->setCascadingSectionResizes(false);
        ModleList1->verticalHeader()->setHighlightSections(true);
        ModleList1->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        ModleList1->verticalHeader()->setStretchLastSection(false);

        horizontalLayout_3->addWidget(ModleList1);

        tabWidget->addTab(Tab1, QString());
        Tab2 = new QWidget();
        Tab2->setObjectName(QString::fromUtf8("Tab2"));
        horizontalLayout_4 = new QHBoxLayout(Tab2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        ModleList2 = new QTableView(Tab2);
        ModleList2->setObjectName(QString::fromUtf8("ModleList2"));
        ModleList2->setFont(font4);
        ModleList2->setStyleSheet(QString::fromUtf8("QTableView{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}\n"
"/* \350\256\276\347\275\256\350\241\250\345\244\264 */\n"
"QHeaderView::section {\n"
"    font-size: 18px;\n"
"}\n"
"/* \350\256\276\347\275\256\351\246\226\345\210\227\345\215\225\345\205\203\346\240\274\345\255\227\344\275\223 */\n"
"QTableView::item:first-column {\n"
"    font-size: 18px;\n"
"}\n"
""));
        ModleList2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ModleList2->setSelectionMode(QAbstractItemView::SingleSelection);
        ModleList2->setSelectionBehavior(QAbstractItemView::SelectRows);
        ModleList2->setSortingEnabled(true);
        ModleList2->setWordWrap(false);
        ModleList2->horizontalHeader()->setVisible(false);
        ModleList2->horizontalHeader()->setCascadingSectionResizes(false);
        ModleList2->horizontalHeader()->setHighlightSections(true);
        ModleList2->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        ModleList2->horizontalHeader()->setStretchLastSection(false);
        ModleList2->verticalHeader()->setVisible(false);
        ModleList2->verticalHeader()->setCascadingSectionResizes(false);
        ModleList2->verticalHeader()->setHighlightSections(true);
        ModleList2->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        ModleList2->verticalHeader()->setStretchLastSection(false);

        horizontalLayout_4->addWidget(ModleList2);

        tabWidget->addTab(Tab2, QString());
        Tab3 = new QWidget();
        Tab3->setObjectName(QString::fromUtf8("Tab3"));
        horizontalLayout = new QHBoxLayout(Tab3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        CyView = new QTreeView(Tab3);
        CyView->setObjectName(QString::fromUtf8("CyView"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(CyView->sizePolicy().hasHeightForWidth());
        CyView->setSizePolicy(sizePolicy2);
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(18);
        CyView->setFont(font5);
        CyView->setStyleSheet(QString::fromUtf8("QTreeView{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        CyView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        CyView->setSortingEnabled(true);
        CyView->header()->setDefaultSectionSize(50);
        CyView->header()->setProperty("showSortIndicator", QVariant(true));

        horizontalLayout->addWidget(CyView);

        tabWidget->addTab(Tab3, QString());
        Tab4 = new QWidget();
        Tab4->setObjectName(QString::fromUtf8("Tab4"));
        horizontalLayout_2 = new QHBoxLayout(Tab4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        CxView = new QTreeView(Tab4);
        CxView->setObjectName(QString::fromUtf8("CxView"));
        sizePolicy2.setHeightForWidth(CxView->sizePolicy().hasHeightForWidth());
        CxView->setSizePolicy(sizePolicy2);
        CxView->setFont(font5);
        CxView->setStyleSheet(QString::fromUtf8("QTreeView{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        CxView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        CxView->setSortingEnabled(true);
        CxView->header()->setDefaultSectionSize(50);

        horizontalLayout_2->addWidget(CxView);

        tabWidget->addTab(Tab4, QString());
        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(695, 100, 520, 690));
        widget1->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius: 25px;\n"
"	border-style: outset;\n"
"}\n"
"QMenu{\n"
"	background-color:palette(window);\n"
"	color:rgb(0, 0, 0);\n"
"}\n"
"QMenu::item{\n"
"  color:rgba(51,51,51,1);\n"
"}\n"
"QMenu::item:hover{\n"
"  background-color:#409CE1;\n"
"}\n"
"QMenu::item:selected{\n"
"  background-color:#409CE1;\n"
"}"));
        Label1_2 = new QLabel(widget1);
        Label1_2->setObjectName(QString::fromUtf8("Label1_2"));
        Label1_2->setGeometry(QRect(30, 75, 121, 31));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font6.setPointSize(20);
        Label1_2->setFont(font6);
        MoldEdit = new QLineEdit(widget1);
        MoldEdit->setObjectName(QString::fromUtf8("MoldEdit"));
        MoldEdit->setGeometry(QRect(160, 70, 211, 41));
        MoldEdit->setFont(font5);
        MoldEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MoldEdit->setAlignment(Qt::AlignCenter);
        MoldEdit->setReadOnly(false);
        Label1_1 = new QLabel(widget1);
        Label1_1->setObjectName(QString::fromUtf8("Label1_1"));
        Label1_1->setGeometry(QRect(30, 135, 121, 31));
        Label1_1->setFont(font6);
        SpareEdit = new QLineEdit(widget1);
        SpareEdit->setObjectName(QString::fromUtf8("SpareEdit"));
        SpareEdit->setGeometry(QRect(160, 130, 101, 41));
        SpareEdit->setFont(font5);
        SpareEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        SpareEdit->setAlignment(Qt::AlignCenter);
        SpareEdit->setReadOnly(false);
        RefreshButton = new QPushButton(widget1);
        RefreshButton->setObjectName(QString::fromUtf8("RefreshButton"));
        RefreshButton->setGeometry(QRect(10, 10, 46, 46));
        RefreshButton->setCursor(QCursor(Qt::PointingHandCursor));
        RefreshButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        RefreshButton->setIcon(icon4);
        RefreshButton->setIconSize(QSize(26, 26));
        Label2 = new QLabel(widget1);
        Label2->setObjectName(QString::fromUtf8("Label2"));
        Label2->setGeometry(QRect(30, 195, 121, 31));
        Label2->setFont(font6);
        PriceEdit = new QLineEdit(widget1);
        PriceEdit->setObjectName(QString::fromUtf8("PriceEdit"));
        PriceEdit->setGeometry(QRect(160, 190, 101, 41));
        PriceEdit->setFont(font5);
        PriceEdit->setCursor(QCursor(Qt::ArrowCursor));
        PriceEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        PriceEdit->setEchoMode(QLineEdit::Password);
        PriceEdit->setAlignment(Qt::AlignCenter);
        PriceEdit->setReadOnly(true);
        Label3 = new QLabel(widget1);
        Label3->setObjectName(QString::fromUtf8("Label3"));
        Label3->setGeometry(QRect(30, 255, 121, 31));
        Label3->setFont(font6);
        FirstEdit = new QLineEdit(widget1);
        FirstEdit->setObjectName(QString::fromUtf8("FirstEdit"));
        FirstEdit->setGeometry(QRect(160, 250, 101, 41));
        FirstEdit->setFont(font5);
        FirstEdit->setCursor(QCursor(Qt::ArrowCursor));
        FirstEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        FirstEdit->setAlignment(Qt::AlignCenter);
        FirstEdit->setReadOnly(true);
        WorkButton = new QPushButton(widget1);
        WorkButton->setObjectName(QString::fromUtf8("WorkButton"));
        WorkButton->setGeometry(QRect(60, 10, 151, 46));
        WorkButton->setFont(font4);
        WorkButton->setCursor(QCursor(Qt::PointingHandCursor));
        WorkButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/work.png"), QSize(), QIcon::Normal, QIcon::Off);
        WorkButton->setIcon(icon5);
        WorkButton->setIconSize(QSize(24, 24));
        StataEdit = new QLineEdit(widget1);
        StataEdit->setObjectName(QString::fromUtf8("StataEdit"));
        StataEdit->setGeometry(QRect(160, 370, 251, 41));
        StataEdit->setFont(font5);
        StataEdit->setCursor(QCursor(Qt::ArrowCursor));
        StataEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        StataEdit->setAlignment(Qt::AlignCenter);
        StataEdit->setReadOnly(true);
        ProductEdit = new QLineEdit(widget1);
        ProductEdit->setObjectName(QString::fromUtf8("ProductEdit"));
        ProductEdit->setGeometry(QRect(160, 430, 331, 41));
        ProductEdit->setFont(font5);
        ProductEdit->setCursor(QCursor(Qt::ArrowCursor));
        ProductEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ProductEdit->setAlignment(Qt::AlignCenter);
        ProductEdit->setReadOnly(true);
        Label5 = new QLabel(widget1);
        Label5->setObjectName(QString::fromUtf8("Label5"));
        Label5->setGeometry(QRect(30, 435, 121, 31));
        Label5->setFont(font6);
        EditButton = new QPushButton(widget1);
        EditButton->setObjectName(QString::fromUtf8("EditButton"));
        EditButton->setEnabled(false);
        EditButton->setGeometry(QRect(70, 560, 101, 51));
        sizePolicy2.setHeightForWidth(EditButton->sizePolicy().hasHeightForWidth());
        EditButton->setSizePolicy(sizePolicy2);
        QFont font7;
        font7.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font7.setPointSize(16);
        font7.setBold(true);
        font7.setWeight(75);
        EditButton->setFont(font7);
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
"}\n"
"QPushButton:!enabled {   /*\346\214\211\351\222\256\347\246\201\347\224\250\346\227\266*/\n"
"	background: rgb(100, 100, 100);\n"
"	color: rgb(200, 200, 200);\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/change.png"), QSize(), QIcon::Normal, QIcon::Off);
        EditButton->setIcon(icon6);
        MaterialEdit = new QLineEdit(widget1);
        MaterialEdit->setObjectName(QString::fromUtf8("MaterialEdit"));
        MaterialEdit->setGeometry(QRect(160, 490, 331, 41));
        MaterialEdit->setFont(font5);
        MaterialEdit->setCursor(QCursor(Qt::ArrowCursor));
        MaterialEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MaterialEdit->setAlignment(Qt::AlignCenter);
        MaterialEdit->setReadOnly(true);
        LoadingLabel = new QLabel(widget1);
        LoadingLabel->setObjectName(QString::fromUtf8("LoadingLabel"));
        LoadingLabel->setGeometry(QRect(280, 150, 200, 113));
        Label6 = new QLabel(widget1);
        Label6->setObjectName(QString::fromUtf8("Label6"));
        Label6->setGeometry(QRect(30, 495, 121, 31));
        Label6->setFont(font6);
        Label4 = new QLabel(widget1);
        Label4->setObjectName(QString::fromUtf8("Label4"));
        Label4->setGeometry(QRect(30, 315, 121, 31));
        Label4->setFont(font6);
        OtherEdit = new QLineEdit(widget1);
        OtherEdit->setObjectName(QString::fromUtf8("OtherEdit"));
        OtherEdit->setGeometry(QRect(160, 310, 251, 41));
        OtherEdit->setFont(font5);
        OtherEdit->setCursor(QCursor(Qt::ArrowCursor));
        OtherEdit->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        OtherEdit->setAlignment(Qt::AlignCenter);
        OtherEdit->setReadOnly(true);
        Label7 = new QLabel(widget1);
        Label7->setObjectName(QString::fromUtf8("Label7"));
        Label7->setGeometry(QRect(30, 375, 121, 31));
        Label7->setFont(font6);
        DeleteButton = new QPushButton(widget1);
        DeleteButton->setObjectName(QString::fromUtf8("DeleteButton"));
        DeleteButton->setEnabled(false);
        DeleteButton->setGeometry(QRect(220, 560, 101, 51));
        sizePolicy2.setHeightForWidth(DeleteButton->sizePolicy().hasHeightForWidth());
        DeleteButton->setSizePolicy(sizePolicy2);
        DeleteButton->setFont(font7);
        DeleteButton->setCursor(QCursor(Qt::PointingHandCursor));
        DeleteButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"}"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        DeleteButton->setIcon(icon7);
        FindButton = new QPushButton(widget1);
        FindButton->setObjectName(QString::fromUtf8("FindButton"));
        FindButton->setEnabled(true);
        FindButton->setGeometry(QRect(390, 70, 91, 41));
        sizePolicy2.setHeightForWidth(FindButton->sizePolicy().hasHeightForWidth());
        FindButton->setSizePolicy(sizePolicy2);
        FindButton->setFont(font7);
        FindButton->setCursor(QCursor(Qt::PointingHandCursor));
        FindButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"color: rgb(200, 200, 200);\n"
"}\n"
"QPushButton:!enabled {   /*\346\214\211\351\222\256\347\246\201\347\224\250\346\227\266*/\n"
"	background: rgb(100, 100, 100);\n"
"	color: rgb(200, 200, 200);\n"
"}\n"
""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        FindButton->setIcon(icon8);
        FindButton->setIconSize(QSize(20, 20));
        AIButton = new QPushButton(widget1);
        AIButton->setObjectName(QString::fromUtf8("AIButton"));
        AIButton->setGeometry(QRect(450, 10, 61, 46));
        AIButton->setFont(font4);
        AIButton->setCursor(QCursor(Qt::PointingHandCursor));
        AIButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/ai.png"), QSize(), QIcon::Normal, QIcon::Off);
        AIButton->setIcon(icon9);
        AIButton->setIconSize(QSize(36, 36));
        MessageLabel = new QPushButton(widget1);
        MessageLabel->setObjectName(QString::fromUtf8("MessageLabel"));
        MessageLabel->setGeometry(QRect(70, 630, 191, 41));
        sizePolicy2.setHeightForWidth(MessageLabel->sizePolicy().hasHeightForWidth());
        MessageLabel->setSizePolicy(sizePolicy2);
        QFont font8;
        font8.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font8.setPointSize(16);
        font8.setBold(false);
        font8.setWeight(50);
        MessageLabel->setFont(font8);
        MessageLabel->setCursor(QCursor(Qt::PointingHandCursor));
        MessageLabel->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:black;\n"
"	background-color: rgb(255,255,255);\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{  /*\351\274\240\346\240\207\346\202\254\346\265\256\346\227\266*/\n"
"	background: rgb(49,106,234);\n"
"}\n"
"QPushButton:pressed{  /*\351\274\240\346\240\207\346\214\211\344\270\213\346\227\266*/\n"
"	background-color: rgb(255,255,255);\n"
"	color: rgb(200, 200, 200);\n"
"}"));
        LogoLabel1 = new QLabel(widget1);
        LogoLabel1->setObjectName(QString::fromUtf8("LogoLabel1"));
        LogoLabel1->setGeometry(QRect(315, 625, 200, 53));
        LogoLabel1->setPixmap(QPixmap(QString::fromUtf8(":/images/logo200x53.jpg")));
        commandLinkButton = new QCommandLinkButton(widget1);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(350, 15, 101, 41));
        commandLinkButton->setCursor(QCursor(Qt::PointingHandCursor));
        ProductButton = new QPushButton(widget1);
        ProductButton->setObjectName(QString::fromUtf8("ProductButton"));
        ProductButton->setGeometry(QRect(420, 310, 81, 91));
        ProductButton->setFont(font4);
        ProductButton->setCursor(QCursor(Qt::PointingHandCursor));
        ProductButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"}\n"
"QPushButton:!enabled {   /*\346\214\211\351\222\256\347\246\201\347\224\250\346\227\266*/\n"
"	background: rgb(100, 100, 100);\n"
"	color: rgb(200, 200, 200);\n"
"}"));
        ProductButton->setIconSize(QSize(24, 24));
        ReturnButton = new QPushButton(widget1);
        ReturnButton->setObjectName(QString::fromUtf8("ReturnButton"));
        ReturnButton->setGeometry(QRect(370, 560, 101, 51));
        ReturnButton->setFont(font4);
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
"}\n"
"QPushButton:!enabled {   /*\346\214\211\351\222\256\347\246\201\347\224\250\346\227\266*/\n"
"	background: rgb(100, 100, 100);\n"
"	color: rgb(200, 200, 200);\n"
"}"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/return.png"), QSize(), QIcon::Normal, QIcon::Off);
        ReturnButton->setIcon(icon10);
        ReturnButton->setIconSize(QSize(20, 20));
        CheckButton = new QPushButton(centralwidget);
        CheckButton->setObjectName(QString::fromUtf8("CheckButton"));
        CheckButton->setEnabled(true);
        CheckButton->setGeometry(QRect(970, 20, 101, 61));
        sizePolicy1.setHeightForWidth(CheckButton->sizePolicy().hasHeightForWidth());
        CheckButton->setSizePolicy(sizePolicy1);
        CheckButton->setFont(font1);
        CheckButton->setCursor(QCursor(Qt::PointingHandCursor));
        CheckButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"}"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        CheckButton->setIcon(icon11);
        CheckButton->setIconSize(QSize(20, 20));
        widget2 = new QWidget(centralwidget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setEnabled(true);
        widget2->setGeometry(QRect(695, 100, 520, 690));
        widget2->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius: 25px;\n"
"	border-style: outset;\n"
"}\n"
"QMenu{\n"
"	background-color:palette(window);\n"
"	color:rgb(0, 0, 0);\n"
"}\n"
"QMenu::item{\n"
"  color:rgba(51,51,51,1);\n"
"}\n"
"QMenu::item:hover{\n"
"  background-color:#409CE1;\n"
"}\n"
"QMenu::item:selected{\n"
"  background-color:#409CE1;\n"
"}"));
        Label1c = new QLabel(widget2);
        Label1c->setObjectName(QString::fromUtf8("Label1c"));
        Label1c->setGeometry(QRect(30, 85, 121, 31));
        Label1c->setFont(font6);
        MoldEditc = new QLineEdit(widget2);
        MoldEditc->setObjectName(QString::fromUtf8("MoldEditc"));
        MoldEditc->setGeometry(QRect(160, 80, 211, 41));
        MoldEditc->setFont(font5);
        MoldEditc->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MoldEditc->setAlignment(Qt::AlignCenter);
        MoldEditc->setReadOnly(false);
        WorkButtonc = new QPushButton(widget2);
        WorkButtonc->setObjectName(QString::fromUtf8("WorkButtonc"));
        WorkButtonc->setGeometry(QRect(60, 10, 151, 46));
        WorkButtonc->setFont(font4);
        WorkButtonc->setCursor(QCursor(Qt::PointingHandCursor));
        WorkButtonc->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        WorkButtonc->setIcon(icon5);
        WorkButtonc->setIconSize(QSize(24, 24));
        ModelEditc = new QLineEdit(widget2);
        ModelEditc->setObjectName(QString::fromUtf8("ModelEditc"));
        ModelEditc->setGeometry(QRect(160, 200, 331, 41));
        ModelEditc->setFont(font5);
        ModelEditc->setCursor(QCursor(Qt::ArrowCursor));
        ModelEditc->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        ModelEditc->setAlignment(Qt::AlignCenter);
        ModelEditc->setReadOnly(true);
        Label3c = new QLabel(widget2);
        Label3c->setObjectName(QString::fromUtf8("Label3c"));
        Label3c->setGeometry(QRect(30, 205, 121, 31));
        Label3c->setFont(font6);
        LoadingLabelc = new QLabel(widget2);
        LoadingLabelc->setObjectName(QString::fromUtf8("LoadingLabelc"));
        LoadingLabelc->setGeometry(QRect(40, 360, 200, 113));
        DeleteButtonc = new QPushButton(widget2);
        DeleteButtonc->setObjectName(QString::fromUtf8("DeleteButtonc"));
        DeleteButtonc->setEnabled(false);
        DeleteButtonc->setGeometry(QRect(390, 430, 101, 51));
        sizePolicy2.setHeightForWidth(DeleteButtonc->sizePolicy().hasHeightForWidth());
        DeleteButtonc->setSizePolicy(sizePolicy2);
        DeleteButtonc->setFont(font7);
        DeleteButtonc->setCursor(QCursor(Qt::PointingHandCursor));
        DeleteButtonc->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"}"));
        DeleteButtonc->setIcon(icon7);
        FindButtonc = new QPushButton(widget2);
        FindButtonc->setObjectName(QString::fromUtf8("FindButtonc"));
        FindButtonc->setEnabled(true);
        FindButtonc->setGeometry(QRect(390, 80, 91, 41));
        sizePolicy2.setHeightForWidth(FindButtonc->sizePolicy().hasHeightForWidth());
        FindButtonc->setSizePolicy(sizePolicy2);
        FindButtonc->setFont(font7);
        FindButtonc->setCursor(QCursor(Qt::PointingHandCursor));
        FindButtonc->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"color: rgb(200, 200, 200);\n"
"}\n"
"QPushButton:!enabled {   /*\346\214\211\351\222\256\347\246\201\347\224\250\346\227\266*/\n"
"	background: rgb(100, 100, 100);\n"
"	color: rgb(200, 200, 200);\n"
"}\n"
""));
        FindButtonc->setIcon(icon8);
        FindButtonc->setIconSize(QSize(20, 20));
        AIButtonc = new QPushButton(widget2);
        AIButtonc->setObjectName(QString::fromUtf8("AIButtonc"));
        AIButtonc->setGeometry(QRect(450, 10, 61, 46));
        AIButtonc->setFont(font4);
        AIButtonc->setCursor(QCursor(Qt::PointingHandCursor));
        AIButtonc->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        AIButtonc->setIcon(icon9);
        AIButtonc->setIconSize(QSize(36, 36));
        LogoLabelc = new QLabel(widget2);
        LogoLabelc->setObjectName(QString::fromUtf8("LogoLabelc"));
        LogoLabelc->setGeometry(QRect(315, 625, 200, 53));
        LogoLabelc->setPixmap(QPixmap(QString::fromUtf8(":/images/logo200x53.jpg")));
        commandLinkButtonc = new QCommandLinkButton(widget2);
        commandLinkButtonc->setObjectName(QString::fromUtf8("commandLinkButtonc"));
        commandLinkButtonc->setGeometry(QRect(350, 15, 101, 41));
        commandLinkButtonc->setCursor(QCursor(Qt::PointingHandCursor));
        ReturnButtonc = new QPushButton(widget2);
        ReturnButtonc->setObjectName(QString::fromUtf8("ReturnButtonc"));
        ReturnButtonc->setGeometry(QRect(370, 560, 101, 51));
        ReturnButtonc->setFont(font4);
        ReturnButtonc->setCursor(QCursor(Qt::PointingHandCursor));
        ReturnButtonc->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"}"));
        ReturnButtonc->setIcon(icon10);
        ReturnButtonc->setIconSize(QSize(20, 20));
        OutButtonc = new QPushButton(widget2);
        OutButtonc->setObjectName(QString::fromUtf8("OutButtonc"));
        OutButtonc->setGeometry(QRect(270, 340, 101, 51));
        OutButtonc->setFont(font4);
        OutButtonc->setCursor(QCursor(Qt::PointingHandCursor));
        OutButtonc->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"}"));
        OutButtonc->setIcon(icon1);
        OutButtonc->setIconSize(QSize(20, 20));
        MaterialEditc = new QLineEdit(widget2);
        MaterialEditc->setObjectName(QString::fromUtf8("MaterialEditc"));
        MaterialEditc->setGeometry(QRect(160, 140, 331, 41));
        MaterialEditc->setFont(font5);
        MaterialEditc->setStyleSheet(QString::fromUtf8("QLineEdit{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"}"));
        MaterialEditc->setAlignment(Qt::AlignCenter);
        MaterialEditc->setReadOnly(false);
        Label2c = new QLabel(widget2);
        Label2c->setObjectName(QString::fromUtf8("Label2c"));
        Label2c->setGeometry(QRect(30, 145, 121, 31));
        Label2c->setFont(font6);
        ContainerCombo = new QComboBox(widget2);
        ContainerCombo->setObjectName(QString::fromUtf8("ContainerCombo"));
        ContainerCombo->setGeometry(QRect(160, 260, 131, 41));
        QFont font9;
        font9.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font9.setPointSize(18);
        font9.setBold(false);
        font9.setItalic(false);
        font9.setWeight(50);
        ContainerCombo->setFont(font9);
        ContainerCombo->setCursor(QCursor(Qt::ArrowCursor));
        ContainerCombo->setStyleSheet(QString::fromUtf8("QComboBox{  /*\345\270\270\346\200\201*/\n"
"	background-color: rgb(204, 221, 255);\n"
"	border: none;\n"
"	border-radius: 2px;\n"
"	color: rgb(0,0,0);\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        ContainerCombo->setEditable(true);
        Label4c = new QLabel(widget2);
        Label4c->setObjectName(QString::fromUtf8("Label4c"));
        Label4c->setGeometry(QRect(30, 265, 121, 31));
        Label4c->setFont(font6);
        EnterButtonc = new QPushButton(widget2);
        EnterButtonc->setObjectName(QString::fromUtf8("EnterButtonc"));
        EnterButtonc->setGeometry(QRect(390, 340, 101, 51));
        EnterButtonc->setFont(font4);
        EnterButtonc->setCursor(QCursor(Qt::PointingHandCursor));
        EnterButtonc->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"}"));
        EnterButtonc->setIcon(icon3);
        EnterButtonc->setIconSize(QSize(20, 20));
        ChangeButtonc = new QPushButton(widget2);
        ChangeButtonc->setObjectName(QString::fromUtf8("ChangeButtonc"));
        ChangeButtonc->setEnabled(false);
        ChangeButtonc->setGeometry(QRect(270, 430, 101, 51));
        sizePolicy2.setHeightForWidth(ChangeButtonc->sizePolicy().hasHeightForWidth());
        ChangeButtonc->setSizePolicy(sizePolicy2);
        ChangeButtonc->setFont(font7);
        ChangeButtonc->setCursor(QCursor(Qt::PointingHandCursor));
        ChangeButtonc->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
"}"));
        ChangeButtonc->setIcon(icon6);
        RefreshButtonc = new QPushButton(widget2);
        RefreshButtonc->setObjectName(QString::fromUtf8("RefreshButtonc"));
        RefreshButtonc->setGeometry(QRect(10, 10, 46, 46));
        RefreshButtonc->setCursor(QCursor(Qt::PointingHandCursor));
        RefreshButtonc->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        RefreshButtonc->setIcon(icon4);
        RefreshButtonc->setIconSize(QSize(26, 26));
        MessageLabelc = new QPushButton(widget2);
        MessageLabelc->setObjectName(QString::fromUtf8("MessageLabelc"));
        MessageLabelc->setGeometry(QRect(70, 630, 191, 41));
        sizePolicy2.setHeightForWidth(MessageLabelc->sizePolicy().hasHeightForWidth());
        MessageLabelc->setSizePolicy(sizePolicy2);
        MessageLabelc->setFont(font8);
        MessageLabelc->setCursor(QCursor(Qt::PointingHandCursor));
        MessageLabelc->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
"	color:black;\n"
"	background-color: rgb(255,255,255);\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{  /*\351\274\240\346\240\207\346\202\254\346\265\256\346\227\266*/\n"
"	background: rgb(49,106,234);\n"
"}\n"
"QPushButton:pressed{  /*\351\274\240\346\240\207\346\214\211\344\270\213\346\227\266*/\n"
"	background-color: rgb(255,255,255);\n"
"	color: rgb(200, 200, 200);\n"
"}"));
        BomButton = new QPushButton(centralwidget);
        BomButton->setObjectName(QString::fromUtf8("BomButton"));
        BomButton->setGeometry(QRect(1080, 20, 131, 61));
        BomButton->setFont(font1);
        BomButton->setCursor(QCursor(Qt::PointingHandCursor));
        BomButton->setStyleSheet(QString::fromUtf8("QPushButton{  /*\345\270\270\346\200\201*/\n"
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
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/data.png"), QSize(), QIcon::Normal, QIcon::Off);
        BomButton->setIcon(icon12);
        BomButton->setIconSize(QSize(24, 24));
        WarehouseWindow->setCentralWidget(centralwidget);
        AddButton->raise();
        OutButton->raise();
        ManageButton->raise();
        EnterButton->raise();
        LogoLabel2->raise();
        tabWidget->raise();
        widget1->raise();
        CheckButton->raise();
        widget2->raise();
        BomButton->raise();
        menubar = new QMenuBar(WarehouseWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1235, 23));
        WarehouseWindow->setMenuBar(menubar);
        QWidget::setTabOrder(tabWidget, ModleList1);
        QWidget::setTabOrder(ModleList1, MoldEditc);
        QWidget::setTabOrder(MoldEditc, FindButtonc);
        QWidget::setTabOrder(FindButtonc, MaterialEditc);
        QWidget::setTabOrder(MaterialEditc, ModelEditc);
        QWidget::setTabOrder(ModelEditc, ContainerCombo);
        QWidget::setTabOrder(ContainerCombo, OutButtonc);
        QWidget::setTabOrder(OutButtonc, EnterButtonc);
        QWidget::setTabOrder(EnterButtonc, ChangeButtonc);
        QWidget::setTabOrder(ChangeButtonc, DeleteButtonc);
        QWidget::setTabOrder(DeleteButtonc, MoldEdit);
        QWidget::setTabOrder(MoldEdit, FindButton);
        QWidget::setTabOrder(FindButton, SpareEdit);
        QWidget::setTabOrder(SpareEdit, PriceEdit);
        QWidget::setTabOrder(PriceEdit, FirstEdit);
        QWidget::setTabOrder(FirstEdit, OtherEdit);
        QWidget::setTabOrder(OtherEdit, ProductButton);
        QWidget::setTabOrder(ProductButton, StataEdit);
        QWidget::setTabOrder(StataEdit, ProductEdit);
        QWidget::setTabOrder(ProductEdit, MaterialEdit);
        QWidget::setTabOrder(MaterialEdit, EditButton);
        QWidget::setTabOrder(EditButton, DeleteButton);
        QWidget::setTabOrder(DeleteButton, AddButton);
        QWidget::setTabOrder(AddButton, OutButton);
        QWidget::setTabOrder(OutButton, EnterButton);
        QWidget::setTabOrder(EnterButton, ManageButton);
        QWidget::setTabOrder(ManageButton, CheckButton);
        QWidget::setTabOrder(CheckButton, BomButton);
        QWidget::setTabOrder(BomButton, RefreshButton);
        QWidget::setTabOrder(RefreshButton, WorkButton);
        QWidget::setTabOrder(WorkButton, commandLinkButtonc);
        QWidget::setTabOrder(commandLinkButtonc, AIButtonc);
        QWidget::setTabOrder(AIButtonc, ReturnButton);
        QWidget::setTabOrder(ReturnButton, MessageLabel);
        QWidget::setTabOrder(MessageLabel, ReturnButtonc);
        QWidget::setTabOrder(ReturnButtonc, WorkButtonc);
        QWidget::setTabOrder(WorkButtonc, ModleList2);
        QWidget::setTabOrder(ModleList2, CyView);
        QWidget::setTabOrder(CyView, commandLinkButton);
        QWidget::setTabOrder(commandLinkButton, AIButton);
        QWidget::setTabOrder(AIButton, RefreshButtonc);
        QWidget::setTabOrder(RefreshButtonc, MessageLabelc);
        QWidget::setTabOrder(MessageLabelc, CxView);

        retranslateUi(WarehouseWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WarehouseWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WarehouseWindow)
    {
        WarehouseWindow->setWindowTitle(QCoreApplication::translate("WarehouseWindow", "MainWindow", nullptr));
        LogoLabel2->setText(QString());
        AddButton->setText(QCoreApplication::translate("WarehouseWindow", " \346\226\260\345\242\236\346\250\241\345\205\267/\345\244\207\344\273\266", nullptr));
        OutButton->setText(QCoreApplication::translate("WarehouseWindow", " \345\207\272\345\272\223\347\256\241\347\220\206", nullptr));
        ManageButton->setText(QCoreApplication::translate("WarehouseWindow", " \346\250\241\345\205\267\347\247\215\347\261\273/\350\264\247\346\237\234\347\256\241\347\220\206", nullptr));
        EnterButton->setText(QCoreApplication::translate("WarehouseWindow", " \345\205\245\345\272\223\347\256\241\347\220\206", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Tab1), QCoreApplication::translate("WarehouseWindow", "\345\206\262\345\216\213\346\250\241\346\262\273\345\205\267", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Tab2), QCoreApplication::translate("WarehouseWindow", "\346\210\220\345\236\213\346\250\241\346\262\273\345\205\267", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Tab3), QCoreApplication::translate("WarehouseWindow", "\345\206\262\345\216\213\345\244\207\344\273\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Tab4), QCoreApplication::translate("WarehouseWindow", "\346\210\220\345\236\213\345\244\207\344\273\266", nullptr));
        Label1_2->setText(QCoreApplication::translate("WarehouseWindow", "\346\250\241\345\205\267\347\274\226\345\217\267:", nullptr));
        MoldEdit->setPlaceholderText(QString());
        Label1_1->setText(QCoreApplication::translate("WarehouseWindow", "\345\244\207\344\273\266\347\274\226\345\217\267:", nullptr));
        RefreshButton->setText(QString());
        Label2->setText(QCoreApplication::translate("WarehouseWindow", "\345\244\207\344\273\266\344\273\267\346\240\274:", nullptr));
        Label3->setText(QCoreApplication::translate("WarehouseWindow", "\346\234\237\345\210\235\345\272\223\345\255\230:", nullptr));
        WorkButton->setText(QCoreApplication::translate("WarehouseWindow", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
        Label5->setText(QCoreApplication::translate("WarehouseWindow", "\344\272\247\345\223\201\345\220\215\347\247\260:", nullptr));
        EditButton->setText(QCoreApplication::translate("WarehouseWindow", "\344\277\256\346\224\271", nullptr));
        LoadingLabel->setText(QString());
        Label6->setText(QCoreApplication::translate("WarehouseWindow", "\344\272\247\345\223\201\346\226\231\345\217\267:", nullptr));
        Label4->setText(QCoreApplication::translate("WarehouseWindow", "\345\244\207\346\263\250\344\277\241\346\201\257:", nullptr));
        Label7->setText(QCoreApplication::translate("WarehouseWindow", "\345\275\223\345\211\215\347\212\266\346\200\201:", nullptr));
        DeleteButton->setText(QCoreApplication::translate("WarehouseWindow", "\345\210\240\351\231\244", nullptr));
        FindButton->setText(QCoreApplication::translate("WarehouseWindow", "\346\237\245\346\211\276", nullptr));
        AIButton->setText(QString());
        MessageLabel->setText(QCoreApplication::translate("WarehouseWindow", "\345\275\223\345\211\215\346\266\210\346\201\257\346\235\241\346\225\260\357\274\2100\357\274\211", nullptr));
        LogoLabel1->setText(QString());
        commandLinkButton->setText(QCoreApplication::translate("WarehouseWindow", "Database", nullptr));
        ProductButton->setText(QCoreApplication::translate("WarehouseWindow", "\345\267\245\347\253\231\n"
"\346\237\245\346\211\276", nullptr));
        ReturnButton->setText(QCoreApplication::translate("WarehouseWindow", "\350\277\224\345\233\236", nullptr));
        CheckButton->setText(QCoreApplication::translate("WarehouseWindow", "\347\233\230\347\202\271", nullptr));
        Label1c->setText(QCoreApplication::translate("WarehouseWindow", "\346\250\241\345\205\267\347\274\226\345\217\267:", nullptr));
        MoldEditc->setPlaceholderText(QString());
        WorkButtonc->setText(QCoreApplication::translate("WarehouseWindow", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
        Label3c->setText(QCoreApplication::translate("WarehouseWindow", "\346\250\241\345\205\267\345\260\272\345\257\270:", nullptr));
        LoadingLabelc->setText(QString());
        DeleteButtonc->setText(QCoreApplication::translate("WarehouseWindow", "\345\210\240\351\231\244", nullptr));
        FindButtonc->setText(QCoreApplication::translate("WarehouseWindow", "\346\237\245\346\211\276", nullptr));
        AIButtonc->setText(QString());
        LogoLabelc->setText(QString());
        commandLinkButtonc->setText(QCoreApplication::translate("WarehouseWindow", "Database", nullptr));
        ReturnButtonc->setText(QCoreApplication::translate("WarehouseWindow", "\350\277\224\345\233\236", nullptr));
        OutButtonc->setText(QCoreApplication::translate("WarehouseWindow", "\345\207\272\345\272\223", nullptr));
        Label2c->setText(QCoreApplication::translate("WarehouseWindow", "\344\272\247\345\223\201\346\226\231\345\217\267:", nullptr));
        Label4c->setText(QCoreApplication::translate("WarehouseWindow", "\351\200\211\346\213\251\345\272\223\344\275\215:", nullptr));
        EnterButtonc->setText(QCoreApplication::translate("WarehouseWindow", "\345\205\245\345\272\223", nullptr));
        ChangeButtonc->setText(QCoreApplication::translate("WarehouseWindow", "\344\277\256\346\224\271", nullptr));
        RefreshButtonc->setText(QString());
        MessageLabelc->setText(QCoreApplication::translate("WarehouseWindow", "\345\275\223\345\211\215\346\266\210\346\201\257\346\235\241\346\225\260\357\274\2100\357\274\211", nullptr));
        BomButton->setText(QCoreApplication::translate("WarehouseWindow", "BOM", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WarehouseWindow: public Ui_WarehouseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAREHOUSEWINDOW_H
