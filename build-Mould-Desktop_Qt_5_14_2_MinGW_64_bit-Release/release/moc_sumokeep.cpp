/****************************************************************************
** Meta object code from reading C++ file 'sumokeep.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../sumo/sumokeep.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sumokeep.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SumoKeep_t {
    QByteArrayData data[11];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SumoKeep_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SumoKeep_t qt_meta_stringdata_SumoKeep = {
    {
QT_MOC_LITERAL(0, 0, 8), // "SumoKeep"
QT_MOC_LITERAL(1, 9, 8), // "mysignal"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 20), // "on_GetButton_clicked"
QT_MOC_LITERAL(4, 40, 23), // "on_ReturnButton_clicked"
QT_MOC_LITERAL(5, 64, 24), // "on_HistoryButton_clicked"
QT_MOC_LITERAL(6, 89, 25), // "on_FinishedButton_clicked"
QT_MOC_LITERAL(7, 115, 24), // "on_AddCheck_stateChanged"
QT_MOC_LITERAL(8, 140, 4), // "arg1"
QT_MOC_LITERAL(9, 145, 27), // "on_ChangeCheck_stateChanged"
QT_MOC_LITERAL(10, 173, 12) // "refresh_data"

    },
    "SumoKeep\0mysignal\0\0on_GetButton_clicked\0"
    "on_ReturnButton_clicked\0"
    "on_HistoryButton_clicked\0"
    "on_FinishedButton_clicked\0"
    "on_AddCheck_stateChanged\0arg1\0"
    "on_ChangeCheck_stateChanged\0refresh_data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SumoKeep[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    1,   59,    2, 0x08 /* Private */,
       9,    1,   62,    2, 0x08 /* Private */,
      10,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,

       0        // eod
};

void SumoKeep::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SumoKeep *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mysignal(); break;
        case 1: _t->on_GetButton_clicked(); break;
        case 2: _t->on_ReturnButton_clicked(); break;
        case 3: _t->on_HistoryButton_clicked(); break;
        case 4: _t->on_FinishedButton_clicked(); break;
        case 5: _t->on_AddCheck_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_ChangeCheck_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->refresh_data(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SumoKeep::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SumoKeep::mysignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SumoKeep::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_SumoKeep.data,
    qt_meta_data_SumoKeep,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SumoKeep::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SumoKeep::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SumoKeep.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SumoKeep::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void SumoKeep::mysignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
