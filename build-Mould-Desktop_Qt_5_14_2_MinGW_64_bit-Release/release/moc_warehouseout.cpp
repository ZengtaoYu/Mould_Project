/****************************************************************************
** Meta object code from reading C++ file 'warehouseout.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../warehouse/warehouseout.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'warehouseout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WarehouseOut_t {
    QByteArrayData data[17];
    char stringdata0[231];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WarehouseOut_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WarehouseOut_t qt_meta_stringdata_WarehouseOut = {
    {
QT_MOC_LITERAL(0, 0, 12), // "WarehouseOut"
QT_MOC_LITERAL(1, 13, 8), // "mysignal"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 20), // "on_OutButton_clicked"
QT_MOC_LITERAL(4, 44, 23), // "on_ExportButton_clicked"
QT_MOC_LITERAL(5, 68, 23), // "on_ReturnButton_clicked"
QT_MOC_LITERAL(6, 92, 23), // "on_ChangeButton_toggled"
QT_MOC_LITERAL(7, 116, 7), // "checked"
QT_MOC_LITERAL(8, 124, 20), // "on_SpareView_clicked"
QT_MOC_LITERAL(9, 145, 11), // "QModelIndex"
QT_MOC_LITERAL(10, 157, 5), // "index"
QT_MOC_LITERAL(11, 163, 32), // "on_MoldCombo_currentIndexChanged"
QT_MOC_LITERAL(12, 196, 4), // "arg1"
QT_MOC_LITERAL(13, 201, 11), // "eventFilter"
QT_MOC_LITERAL(14, 213, 3), // "obj"
QT_MOC_LITERAL(15, 217, 7), // "QEvent*"
QT_MOC_LITERAL(16, 225, 5) // "event"

    },
    "WarehouseOut\0mysignal\0\0on_OutButton_clicked\0"
    "on_ExportButton_clicked\0on_ReturnButton_clicked\0"
    "on_ChangeButton_toggled\0checked\0"
    "on_SpareView_clicked\0QModelIndex\0index\0"
    "on_MoldCombo_currentIndexChanged\0arg1\0"
    "eventFilter\0obj\0QEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WarehouseOut[] = {

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
       6,    1,   58,    2, 0x08 /* Private */,
       8,    1,   61,    2, 0x08 /* Private */,
      11,    1,   64,    2, 0x08 /* Private */,
      13,    2,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 15,   14,   16,

       0        // eod
};

void WarehouseOut::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WarehouseOut *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mysignal(); break;
        case 1: _t->on_OutButton_clicked(); break;
        case 2: _t->on_ExportButton_clicked(); break;
        case 3: _t->on_ReturnButton_clicked(); break;
        case 4: _t->on_ChangeButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_SpareView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_MoldCombo_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WarehouseOut::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WarehouseOut::mysignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WarehouseOut::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_WarehouseOut.data,
    qt_meta_data_WarehouseOut,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WarehouseOut::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WarehouseOut::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WarehouseOut.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int WarehouseOut::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void WarehouseOut::mysignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
