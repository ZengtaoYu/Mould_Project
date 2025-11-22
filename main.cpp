#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QSharedMemory>
#include <QTranslator>
#include <QtNetwork/QLocalSocket>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QString appName = "Mould.exe";
    QSharedMemory sharedMemory(appName);

    // 检查是否已有实例在运行
    if(!sharedMemory.create(1)) {
        // 程序已在运行，尝试连接到第一个实例并通知它显示窗口
        QLocalSocket socket;
        socket.connectToServer("MouldManagerSingleInstance");

        if(socket.waitForConnected(1000)) {
            // 发送一个消息通知第一个实例显示窗口
            socket.write("show");
            socket.waitForBytesWritten(1000);
            socket.disconnectFromServer();
        } else {
            // 如果连接失败，仍然提示用户
            QMessageBox::information(nullptr, "模具管理系统",
                "程序已在运行，正在尝试显示主窗口...",
                QMessageBox::Ok);
        }

        return 0;
    }

    QTranslator qtTranslator;
    qtTranslator.load(":/qm/qt_zh_CN.qm");
    app.installTranslator(&qtTranslator);
    QTranslator qtBaseTranslator;
    qtBaseTranslator.load(":/qm/qtbase_zh_CN.qm");
    app.installTranslator(&qtBaseTranslator);
    MainWindow w;
    w.setWindowTitle("模具管理系统");
    w.show();
    return app.exec();
}
