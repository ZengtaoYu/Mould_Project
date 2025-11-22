#include "spare.h"

Spare::Spare() : m_id(0), m_name() {
}

int Spare::id() const {
    return m_id;
}

void Spare::setId(int id) {
    m_id = id;
}

QString Spare::name() const {
    return m_name;
}

void Spare::setName(const QString &name) {
    m_name = name;
}
