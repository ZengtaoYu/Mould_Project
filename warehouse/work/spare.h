#ifndef SPARE_H
#define SPARE_H

#include <QString>

class Spare {
public:
    Spare();

    int id() const;
    void setId(int id);

    QString name() const;
    void setName(const QString &name);

private:
    int m_id;
    QString m_name;
};

#endif // SPARE_H
