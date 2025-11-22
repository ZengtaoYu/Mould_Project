/****************************************************************************
** Meta object code from reading C++ file 'sparewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../warehouse/sparewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sparewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SpareWindow_t {
    QByteArrayData data[15];
    char stringdata0[286];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SpareWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SpareWindow_t qt_meta_stringdata_SpareWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "SpareWindow"
QT_MOC_LITERAL(1, 12, 8), // "mysignal"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11), // "RefreshData"
QT_MOC_LITERAL(4, 34, 20), // "on_OutButton_clicked"
QT_MOC_LITERAL(5, 55, 23), // "on_ReturnButton_clicked"
QT_MOC_LITERAL(6, 79, 32), // "on_MoldCombo_currentIndexChanged"
QT_MOC_LITERAL(7, 112, 4), // "arg1"
QT_MOC_LITERAL(8, 117, 32), // "on_WorkCombo_currentIndexChanged"
QT_MOC_LITERAL(9, 150, 37), // "on_ProductCombo_1_currentInde..."
QT_MOC_LITERAL(10, 188, 37), // "on_ProductCombo_2_currentInde..."
QT_MOC_LITERAL(11, 226, 20), // "on_PIDView_1_clicked"
QT_MOC_LITERAL(12, 247, 11), // "QModelIndex"
QT_MOC_LITERAL(13, 259, 5), // "index"
QT_MOC_LITERAL(14, 265, 20) // "on_PIDView_2_clicked"

    },
    "SpareWindow\0mysignal\0\0RefreshData\0"
    "on_OutButton_clicked\0on_ReturnButton_clicked\0"
    "on_MoldCombo_currentIndexChanged\0arg1\0"
    "on_WorkCombo_currentIndexChanged\0"
    "on_ProductCombo_1_currentIndexChanged\0"
    "on_ProductCombo_2_currentIndexChanged\0"
    "on_PIDView_1_clicked\0QModelIndex\0index\0"
    "on_PIDView_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpareWindow[] = {

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
       6,    1,   68,    2, 0x08 /* Private */,
       8,    1,   71,    2, 0x08 /* Private */,
       9,    1,   74,    2, 0x08 /* Private */,
      10,    1,   77,    2, 0x08 /* Private */,
      11,    1,   80,    2, 0x08 /* Private */,
      14,    1,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void SpareWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SpareWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mysignal(); break;
        case 1: _t->RefreshData(); break;
        case 2: _t->on_OutButton_clicked(); break;
        case 3: _t->on_ReturnButton_clicked(); break;
        case 4: _t->on_MoldCombo_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_WorkCombo_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_ProductCombo_1_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_ProductCombo_2_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_PIDView_1_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->on_PIDView_2_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SpareWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpareWindow::mysignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SpareWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_SpareWindow.data,
    qt_meta_data_SpareWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SpareWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpareWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SpareWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SpareWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void SpareWindow::mysignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
