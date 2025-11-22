#ifndef SMTPCLIENT_H
#define SMTPCLIENT_H

#include <QObject>
#include <QtNetwork/QSslSocket>
#include "mimemessage.h"

class SmtpClient : public QObject
{
    Q_OBJECT

public:
    enum AuthMethod
    {
        AuthPlain,
        AuthLogin
    };

    enum SmtpError
    {
        ConnectionTimeoutError,
        ResponseTimeoutError,
        AuthenticationFailedError,
        ServerError, // 4xx smtp error
        ClientError  // 5xx smtp error
    };

    enum ConnectionType
    {
        TcpConnection,
        SslConnection,
        TlsConnection // STARTTLS
    };

    SmtpClient(const QString &host = "locahost", int port = 25, ConnectionType ct = TcpConnection);
    ~SmtpClient();

    void quit();
    bool login();
    int getPort() const;
    bool connectToHost();
    void setPort(int port);
    QTcpSocket *getSocket();
    void setHost(QString &host);
    int getResponseCode() const;
    int getResponseTimeout() const;
    const QString &getHost() const;
    const QString &getName() const;
    const QString &getUser() const;
    int getConnectionTimeout() const;
    bool sendMail(MimeMessage &email);
    void setResponseTimeout(int msec);
    void setUser(const QString &host);
    void setName(const QString &name);
    const QString &getPassword() const;
    void setConnectionTimeout(int msec);
    void setAuthMethod(AuthMethod method);
    const QString &getResponseText() const;
    ConnectionType getConnectionType() const;
    void setPassword(const QString &password);
    void setConnectionType(ConnectionType ct);
    SmtpClient::AuthMethod getAuthMethod() const;
    bool login(const QString &user, const QString &password, AuthMethod method = AuthLogin);

protected:
    int port;
    int responseCode;
    QString host;
    QString name;
    QString user;
    QString password;
    QString responseText;
    QTcpSocket *socket;
    AuthMethod authMethod;
    ConnectionType connectionType;

    int responseTimeout;
    int connectionTimeout;

    class ResponseTimeoutException
    {
    };
    void waitForResponse();
    void sendMessage(const QString &text);

protected slots:
    void socketReadyRead();
    void socketError(QAbstractSocket::SocketError error);
    void socketStateChanged(QAbstractSocket::SocketState state);

signals:
    void smtpError(SmtpError e);
};

#endif // SMTPCLIENT_H
