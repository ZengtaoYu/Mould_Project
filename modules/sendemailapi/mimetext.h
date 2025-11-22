#ifndef MIMETEXT_H
#define MIMETEXT_H

#include "mimepart.h"

class MimeText : public MimePart
{
public:
    MimeText(const QString &text = "");
    ~MimeText();

    const QString &getText() const;
    void setText(const QString &text);

protected:
    QString text;
    void prepare();
};

#endif // MIMETEXT_H
