/****************************************************************************
** Meta object code from reading C++ file 'handlemessage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../comom/handlemessage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'handlemessage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HandleMessage_t {
    QByteArrayData data[14];
    char stringdata0[258];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HandleMessage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HandleMessage_t qt_meta_stringdata_HandleMessage = {
    {
QT_MOC_LITERAL(0, 0, 13), // "HandleMessage"
QT_MOC_LITERAL(1, 14, 12), // "refresh_data"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 22), // "on_CheckButton_clicked"
QT_MOC_LITERAL(4, 51, 22), // "on_EmailButton_clicked"
QT_MOC_LITERAL(5, 74, 24), // "on_HandleButton1_clicked"
QT_MOC_LITERAL(6, 99, 24), // "on_HandleButton2_clicked"
QT_MOC_LITERAL(7, 124, 26), // "on_FinishedButton1_clicked"
QT_MOC_LITERAL(8, 151, 26), // "on_FinishedButton2_clicked"
QT_MOC_LITERAL(9, 178, 22), // "on_UserMessage_clicked"
QT_MOC_LITERAL(10, 201, 11), // "QModelIndex"
QT_MOC_LITERAL(11, 213, 5), // "index"
QT_MOC_LITERAL(12, 219, 24), // "on_SystemMessage_clicked"
QT_MOC_LITERAL(13, 244, 13) // "enable_window"

    },
    "HandleMessage\0refresh_data\0\0"
    "on_CheckButton_clicked\0on_EmailButton_clicked\0"
    "on_HandleButton1_clicked\0"
    "on_HandleButton2_clicked\0"
    "on_FinishedButton1_clicked\0"
    "on_FinishedButton2_clicked\0"
    "on_UserMessage_clicked\0QModelIndex\0"
    "index\0on_SystemMessage_clicked\0"
    "enable_window"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HandleMessage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    1,   71,    2, 0x08 /* Private */,
      12,    1,   74,    2, 0x08 /* Private */,
      13,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,

       0        // eod
};

void HandleMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HandleMessage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refresh_data(); break;
        case 1: _t->on_CheckButton_clicked(); break;
        case 2: _t->on_EmailButton_clicked(); break;
        case 3: _t->on_HandleButton1_clicked(); break;
        case 4: _t->on_HandleButton2_clicked(); break;
        case 5: _t->on_FinishedButton1_clicked(); break;
        case 6: _t->on_FinishedButton2_clicked(); break;
        case 7: _t->on_UserMessage_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_SystemMessage_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->enable_window(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HandleMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_HandleMessage.data,
    qt_meta_data_HandleMessage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HandleMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HandleMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HandleMessage.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int HandleMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
