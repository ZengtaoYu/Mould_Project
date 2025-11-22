#ifndef MIMEMESSAGE_H
#define MIMEMESSAGE_H

#include <QList>
#include "mimepart.h"
#include "mimemultipart.h"
#include "emailaddress.h"

class MimeMessage : public QObject
{
public:
    enum RecipientType
    {
        To, // primary
        Cc, // carbon copy
        Bcc // blind carbon copy
    };

    MimeMessage(bool createAutoMimeConent = true);
    ~MimeMessage();

    MimePart &getContent();
    virtual QString toString();
    void addPart(MimePart *part);
    void addTo(EmailAddress *rcpt);
    void addCc(EmailAddress *rcpt);
    void setSender(EmailAddress *e);
    void addBcc(EmailAddress *rcpt);
    void setContent(MimePart *content);
    const QString &getSubject() const;
    const EmailAddress &getSender() const;
    void setSubject(const QString &subject);
    const QList<MimePart *> &getParts() const;
    void setHeaderEncoding(MimePart::Encoding);
    void addRecipient(EmailAddress *rcpt, RecipientType type = To);
    const QList<EmailAddress *> &getRecipients(RecipientType type = To) const;

protected:
    QString subject;
    MimePart *content;
    EmailAddress *sender;
    MimePart::Encoding hEncoding;
    QList<EmailAddress *> recipientsTo, recipientsCc, recipientsBcc;
};

#endif // MIMEMESSAGE_H
