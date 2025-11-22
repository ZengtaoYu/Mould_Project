#ifndef MIMEHTML_H
#define MIMEHTML_H

#include "mimetext.h"

class MimeHtml : public MimeText
{
    Q_OBJECT

public:
    MimeHtml(const QString &html = "");
    ~MimeHtml();

    const QString &getHtml() const;
    void setHtml(const QString &html);

protected:
    virtual void prepare();
};

#endif // MIMEHTML_H
