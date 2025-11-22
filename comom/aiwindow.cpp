#include "aiwindow.h"
#include "ui_aiwindow.h"

AiWindow::AiWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::AiWindow) {
    ui->setupUi(this);
    ai_base = "deepseek-chat";
    movie = new QMovie(":/images/ai_load.gif");
    ui->LoadLabel->setMovie(movie);
    initializeAddBox();
}

AiWindow::~AiWindow() {
    delete movie;
    delete ui;
}

void AiWindow::initializeAddBox() {
    ui->AddBox->addItem("无");
    ui->AddBox->addItem("用户表");
    QSqlDatabase currentDb = QSqlDatabase::database();
    QString databaseName = currentDb.databaseName();
    if(databaseName == "warehouse") {
        ui->AddBox->addItem("冲压备件表");
        ui->AddBox->addItem("成型备件表");
        ui->AddBox->addItem("货柜表");
    } else {
        ui->AddBox->addItem("BOM表");
        ui->AddBox->addItem("保养表");
        ui->AddBox->addItem("模具损耗表");
    }
}

QString AiWindow::getTableData(const QString &tableName) {
    QString sql = QString("select * from %1;").arg(tableName);
    QSqlQuery query;
    QStringList problemList;
    if(!query.exec(sql)) {
        QMessageBox::warning(this, "AI问答", "附加信息表拉取失败：\n" + query.lastError().text(),
            QMessageBox::Cancel);
        return QString();
    }
    while(query.next()) {
        QStringList rowData;
        for(int i = 1; i < 5; i++) {
            rowData << query.value(i).toString();
        }
        rowData << query.value(8).toString();
        problemList << rowData.join(",");
    }
    return problemList.join("\n");
}

void AiWindow::on_AnswerButton_clicked() {
    QString problemText = ui->ProblemEdit->toPlainText();
    if(problemText.isEmpty()) {
        QMessageBox::warning(this, "AI问答", "请输入您的问题", QMessageBox::Cancel);
        return;
    }
    QString apiKey = "sk-a410dfe2439044439aed52b9644092ee";
    QString apiUrl = "https://api.deepseek.com/chat/completions";
    QNetworkRequest request;
    request.setUrl(QUrl(apiUrl));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", ("Bearer " + apiKey).toUtf8());
    QJsonObject json;
    json["model"] = ai_base;
    json["stream"] = false;
    QJsonArray messages;
    QJsonObject systemMessage;
    systemMessage["role"] = "system";
    systemMessage["content"] = "You are a helpful assistant.";
    messages.append(systemMessage);
    QJsonObject userMessage;
    userMessage["role"] = "user";
    QString content;
    QString tableName;
    QString currentTable = ui->AddBox->currentText();
    if(currentTable == "BOM表") {
        tableName = "current_bom";
    } else if(currentTable == "冲压备件表") {
        tableName = "chonya_message";
    } else if(currentTable == "成型备件表") {
        tableName = "chengxing_message";
    } else if(currentTable == "用户表") {
        tableName = "user_message";
    } else if(currentTable == "保养表") {
        tableName = "keep_message";
    } else if(currentTable == "货柜表") {
        tableName = "cabinet_message";
    } else if(currentTable == "模具损耗表") {
        tableName = "type_message";
    }
    if(!tableName.isEmpty()) {
        QString tableData = getTableData(tableName);
        if(!tableData.isEmpty()) {
            content = tableData + "\n";
        }
    }
    content += problemText;
    userMessage["content"] = content;
    messages.append(userMessage);
    json["messages"] = messages;
    QJsonDocument doc(json);
    QByteArray jsonData = doc.toJson(QJsonDocument::Compact);
    QNetworkReply *reply = manager.post(request, jsonData);
    ui->ReturnEdit->setText("等待回复中......");
    movie->start();
    connect(reply, &QNetworkReply::finished, this, &AiWindow::onNetworkReplyFinished);
}

void AiWindow::on_DeepButton_toggled(bool checked) {
    ai_base = checked ? "deepseek-reasoner" : "deepseek-chat";
}

void AiWindow::onNetworkReplyFinished() {
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    if(!reply) {
        return;
    }
    movie->stop();
    if(reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
        QJsonObject jsonObject = jsonResponse.object();
        QJsonArray choice_array = jsonObject["choices"].toArray();
        if(!choice_array.isEmpty()) {
            QJsonObject firstChoice = choice_array[0].toObject();
            QJsonObject messageObj = firstChoice["message"].toObject();
            QString content = messageObj["content"].toString();
            ui->ReturnEdit->setText(content);
        } else {
            qWarning() << "The 'choices' array is empty.";
            ui->ReturnEdit->setText("回答为空：（可能是DeepSeek服务器出现问题）");
        }
    } else {
        QString errorString = reply->errorString();
        QByteArray response = reply->readAll();
        QString errorMessage = QString("问题提交失败：\n错误代码：%1\n错误信息：%2")
            .arg(reply->error())
            .arg(errorString);
        if(!response.isEmpty()) {
            errorMessage += "\n服务器响应：" + QString::fromUtf8(response);
        }
        QMessageBox::warning(this, "AI问答", errorMessage, QMessageBox::Cancel);
        ui->ReturnEdit->clear();
    }
    reply->deleteLater();
}
