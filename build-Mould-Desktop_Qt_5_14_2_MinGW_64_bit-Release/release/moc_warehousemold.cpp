/****************************************************************************
** Meta object code from reading C++ file 'warehousemold.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../warehouse/warehousemold.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'warehousemold.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WarehouseMold_t {
    QByteArrayData data[12];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WarehouseMold_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WarehouseMold_t qt_meta_stringdata_WarehouseMold = {
    {
QT_MOC_LITERAL(0, 0, 13), // "WarehouseMold"
QT_MOC_LITERAL(1, 14, 8), // "mysignal"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 21), // "on_EditButton_clicked"
QT_MOC_LITERAL(4, 46, 21), // "on_FindButton_clicked"
QT_MOC_LITERAL(5, 68, 23), // "on_ReturnButton_clicked"
QT_MOC_LITERAL(6, 92, 26), // "on_FMoldEdit_returnPressed"
QT_MOC_LITERAL(7, 119, 23), // "on_ChangeButton_toggled"
QT_MOC_LITERAL(8, 143, 7), // "checked"
QT_MOC_LITERAL(9, 151, 19), // "on_MoldView_clicked"
QT_MOC_LITERAL(10, 171, 11), // "QModelIndex"
QT_MOC_LITERAL(11, 183, 5) // "index"

    },
    "WarehouseMold\0mysignal\0\0on_EditButton_clicked\0"
    "on_FindButton_clicked\0on_ReturnButton_clicked\0"
    "on_FMoldEdit_returnPressed\0"
    "on_ChangeButton_toggled\0checked\0"
    "on_MoldView_clicked\0QModelIndex\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WarehouseMold[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    1,   54,    2, 0x08 /* Private */,
       9,    1,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void WarehouseMold::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WarehouseMold *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mysignal(); break;
        case 1: _t->on_EditButton_clicked(); break;
        case 2: _t->on_FindButton_clicked(); break;
        case 3: _t->on_ReturnButton_clicked(); break;
        case 4: _t->on_FMoldEdit_returnPressed(); break;
        case 5: _t->on_ChangeButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_MoldView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WarehouseMold::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WarehouseMold::mysignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WarehouseMold::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_WarehouseMold.data,
    qt_meta_data_WarehouseMold,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WarehouseMold::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WarehouseMold::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WarehouseMold.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int WarehouseMold::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void WarehouseMold::mysignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
