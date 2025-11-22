/****************************************************************************
** Meta object code from reading C++ file 'handledata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../comom/handledata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'handledata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CustomSqlModel_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustomSqlModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustomSqlModel_t qt_meta_stringdata_CustomSqlModel = {
    {
QT_MOC_LITERAL(0, 0, 14) // "CustomSqlModel"

    },
    "CustomSqlModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustomSqlModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void CustomSqlModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CustomSqlModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QSqlTableModel::staticMetaObject>(),
    qt_meta_stringdata_CustomSqlModel.data,
    qt_meta_data_CustomSqlModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CustomSqlModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomSqlModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CustomSqlModel.stringdata0))
        return static_cast<void*>(this);
    return QSqlTableModel::qt_metacast(_clname);
}

int CustomSqlModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSqlTableModel::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_HandleData_t {
    QByteArrayData data[15];
    char stringdata0[244];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HandleData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HandleData_t qt_meta_stringdata_HandleData = {
    {
QT_MOC_LITERAL(0, 0, 10), // "HandleData"
QT_MOC_LITERAL(1, 11, 8), // "mysignal"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 20), // "on_AddButton_clicked"
QT_MOC_LITERAL(4, 42, 23), // "on_DeleteButton_clicked"
QT_MOC_LITERAL(5, 66, 21), // "on_PushButton_clicked"
QT_MOC_LITERAL(6, 88, 23), // "on_ReturnButton_clicked"
QT_MOC_LITERAL(7, 112, 21), // "on_FindButton_clicked"
QT_MOC_LITERAL(8, 134, 25), // "on_LineEdit_returnPressed"
QT_MOC_LITERAL(9, 160, 23), // "on_LineEdit_textChanged"
QT_MOC_LITERAL(10, 184, 4), // "arg1"
QT_MOC_LITERAL(11, 189, 20), // "on_tableView_clicked"
QT_MOC_LITERAL(12, 210, 11), // "QModelIndex"
QT_MOC_LITERAL(13, 222, 5), // "index"
QT_MOC_LITERAL(14, 228, 15) // "doMouseTrackTip"

    },
    "HandleData\0mysignal\0\0on_AddButton_clicked\0"
    "on_DeleteButton_clicked\0on_PushButton_clicked\0"
    "on_ReturnButton_clicked\0on_FindButton_clicked\0"
    "on_LineEdit_returnPressed\0"
    "on_LineEdit_textChanged\0arg1\0"
    "on_tableView_clicked\0QModelIndex\0index\0"
    "doMouseTrackTip"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HandleData[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    1,   71,    2, 0x08 /* Private */,
      11,    1,   74,    2, 0x08 /* Private */,
      14,    1,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void HandleData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HandleData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mysignal(); break;
        case 1: _t->on_AddButton_clicked(); break;
        case 2: _t->on_DeleteButton_clicked(); break;
        case 3: _t->on_PushButton_clicked(); break;
        case 4: _t->on_ReturnButton_clicked(); break;
        case 5: _t->on_FindButton_clicked(); break;
        case 6: _t->on_LineEdit_returnPressed(); break;
        case 7: _t->on_LineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_tableView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->doMouseTrackTip((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HandleData::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HandleData::mysignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HandleData::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_HandleData.data,
    qt_meta_data_HandleData,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HandleData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HandleData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HandleData.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int HandleData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void HandleData::mysignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
