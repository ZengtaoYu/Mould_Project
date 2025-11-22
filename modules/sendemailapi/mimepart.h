#ifndef MIMEPART_H
#define MIMEPART_H

#include <QObject>
#include "mimecontentformatter.h"

class MimePart : public QObject
{
    Q_OBJECT

public:
    enum Encoding
    {
        _7Bit,
        _8Bit,
        Base64,
        QuotedPrintable
    };

    MimePart();
    ~MimePart();

    virtual void prepare();
    virtual QString toString();
    Encoding getEncoding() const;
    void setEncoding(Encoding enc);
    const QString &getHeader() const;
    const QString &getCharset() const;
    const QString &getContentId() const;
    const QByteArray &getContent() const;
    void setHeader(const QString &header);
    void setContentId(const QString &cId);
    const QString &getContentName() const;
    const QString &getContentType() const;
    void addHeaderLine(const QString &line);
    void setCharset(const QString &charset);
    void setContentName(const QString &cName);
    void setContentType(const QString &cType);
    void setContent(const QByteArray &content);
    MimeContentFormatter &getContentFormatter();

protected:
    QString header;
    QByteArray content;

    QString cId;
    QString cName;
    QString cType;
    QString cCharset;
    QString cBoundary;
    Encoding cEncoding;

    bool prepared;
    QString mimeString;

    MimeContentFormatter formatter;
};

#endif // MIMEPART_H
