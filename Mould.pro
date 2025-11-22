QT += core gui sql charts xlsx network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets     #条件引入Qt Widgets模块

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.

DEFINES += QT_DEPRECATED_WARNINGS   #启用Qt废弃API警告
#QMAKE_CXXFLAGS +=  -Wno-unused-parameter   #禁用未使用参数的编译器警告
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    comom/aiwindow.cpp \
    comom/handlebom.cpp \
    comom/handledata.cpp \
    comom/adminwindow.cpp \
    comom/emailwindow.cpp \
    comom/handleworks.cpp \
    comom/handlemessage.cpp \
    comom/registerwindow.cpp \
    comom/databasewindow.cpp \
    chonya/chonyaadd.cpp \
    chonya/chonyaedit.cpp \
    chonya/chonyakeep.cpp \
    chonya/chonyaenter.cpp \
    chonya/chonyawindow.cpp \
    sumo/sumoadd.cpp \
    sumo/sumokeep.cpp \
    sumo/sumoedit.cpp \
    sumo/sumoenter.cpp \
    sumo/newworker.cpp \
    sumo/sumowindow.cpp \
    warehouse/sparewindow.cpp \
    warehouse/warehouseout.cpp \
    warehouse/warehouseadd.cpp \
    warehouse/warehousedele.cpp \
    warehouse/warehouseedit.cpp \
    warehouse/warehousemold.cpp \
    warehouse/productwindow.cpp \
    warehouse/warehouseenter.cpp \
    warehouse/warehousewindow.cpp \
    warehouse/warehousechange.cpp \
    warehouse/work/spare.cpp \
    warehouse/work/widget.cpp \
    warehouse/work/linkabletableview.cpp \
    warehouse/work/sparetableviewmodel.cpp \
    warehouse/work/linkableitemdelegate.cpp

HEADERS += \
    mainwindow.h \
    comom/aiwindow.h \
    comom/handlebom.h \
    comom/handledata.h \
    comom/adminwindow.h \
    comom/emailwindow.h \
    comom/handleworks.h \
    comom/handlemessage.h \
    comom/registerwindow.h \
    comom/databasewindow.h \
    chonya/chonyaadd.h \
    chonya/chonyakeep.h \
    chonya/chonyaedit.h \
    chonya/chonyaenter.h \
    chonya/chonyawindow.h \
    sumo/sumoadd.h \
    sumo/sumoedit.h \
    sumo/sumokeep.h \
    sumo/sumoenter.h \
    sumo/newworker.h \
    sumo/sumowindow.h \
    warehouse/work/spare.h \
    warehouse/work/widget.h \
    warehouse/sparewindow.h \
    warehouse/warehouseout.h \
    warehouse/warehouseadd.h \
    warehouse/warehousedele.h \
    warehouse/warehouseedit.h \
    warehouse/warehousemold.h \
    warehouse/productwindow.h \
    warehouse/warehouseenter.h \
    warehouse/warehousewindow.h \
    warehouse/warehousechange.h \
    warehouse/work/linkabletableview.h \
    warehouse/work/sparetableviewmodel.h \
    warehouse/work/linkableitemdelegate.h

FORMS += \
    mainwindow.ui \
    comom/aiwindow.ui \
    comom/handlebom.ui \
    comom/handledata.ui \
    comom/adminwindow.ui \
    comom/emailwindow.ui \
    comom/handleworks.ui \
    comom/handlemessage.ui \
    comom/registerwindow.ui \
    comom/databasewindow.ui \
    chonya/chonyaadd.ui \
    chonya/chonyaedit.ui \
    chonya/chonyakeep.ui \
    chonya/chonyaenter.ui \
    chonya/chonyawindow.ui \
    sumo/sumoadd.ui \
    sumo/sumoedit.ui \
    sumo/sumokeep.ui \
    sumo/sumoenter.ui \
    sumo/newworker.ui \
    sumo/sumowindow.ui \
    warehouse/sparewindow.ui \
    warehouse/warehouseout.ui \
    warehouse/warehouseadd.ui \
    warehouse/warehousedele.ui \
    warehouse/warehouseedit.ui \
    warehouse/warehousemold.ui \
    warehouse/productwindow.ui \
    warehouse/warehouseenter.ui \
    warehouse/warehousewindow.ui \
    warehouse/warehousechange.ui

TRANSLATIONS += Mould_zh_CN.ts

RESOURCES += resources.qrc

RC_FILE += myApp.rc

DISTFILES += format.astylerc

include($$PWD/modules/sendemailapi/sendemailapi.pri)
