#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QSharedMemory>
#include <QTranslator>
#include <QtNetwork/QLocalSocket>
#include <QFileInfo>
#include <QFile>
#include <QDir>
#include <QProcess>
#include <QDateTime>

// 检查并更新程序版本
bool checkAndUpdateVersion() {
    QString currentExePath = QCoreApplication::applicationFilePath();
    QString networkExePath = "\\\\192.168.101.250\\共享公共资料夹\\模具管理系统\\替换文件\\Mould.exe";
    QFileInfo currentFileInfo(currentExePath);
    QFileInfo networkFileInfo(networkExePath);
    // 检查网络路径文件是否存在
    if(!networkFileInfo.exists()) {
        qDebug() << "网络更新文件不存在:" << networkExePath;
        return false;
    }
    // 获取创建时间（或最后修改时间）
    QDateTime currentFileTime = currentFileInfo.lastModified();
    QDateTime networkFileTime = networkFileInfo.lastModified();
    // 比较文件时间
    QSettings config("userconfig.ini", QSettings::IniFormat);
    if(networkFileTime > currentFileTime && config.value("USERCONFIG/System").toString() != "dev") {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(nullptr, "发现新版本",
                QString("发现新版本程序，是否更新?\n\n当前版本: %1\n最新版本: %2")
                .arg(currentFileTime.toString("yyyy-MM-dd hh:mm:ss"))
                .arg(networkFileTime.toString("yyyy-MM-dd hh:mm:ss")),
                QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes) {
            // 创建批处理文件进行更新
            QString batPath = QDir::tempPath() + "/update_mould.bat";
            QFile batFile(batPath);
            if(batFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&batFile);
                QString currentExeDir = QFileInfo(currentExePath).absolutePath();
                out << "@echo off\r\n";
                out << "echo 正在等待程序关闭...\r\n";
                out << "timeout /t 2 /nobreak >nul\r\n";
                out << "echo 正在更新程序...\r\n";
                out << "copy /y \"" << networkExePath << "\" \"" << currentExePath << "\"\r\n";
                out << "if errorlevel 1 (\r\n";
                out << "    echo 更新失败！\r\n";
                out << "    pause\r\n";
                out << "    exit\r\n";
                out << ")\r\n";
                out << "echo 更新成功！正在重启程序...\r\n";
                out << "timeout /t 1 /nobreak >nul\r\n";
                out << "cd /d \"" << currentExeDir << "\"\r\n";
                out << "start \"\" \"" << currentExePath << "\"\r\n";
                out << "del \"%~f0\"\r\n";  // 删除批处理文件自身
                batFile.close();
                // 启动批处理文件并退出当前程序
                QProcess::startDetached("cmd.exe", QStringList() << "/c" << batPath);
                return true;  // 返回true表示需要退出程序进行更新
            } else {
                QMessageBox::warning(nullptr, "更新失败", "无法创建更新脚本！");
            }
        }
    }
    return false;  // 返回false表示不需要更新或用户取消更新
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    // 先检查版本更新
    if(checkAndUpdateVersion()) {
        // 需要更新，退出当前程序
        return 0;
    }
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
