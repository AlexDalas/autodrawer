/****************************************************************************
** Meta object code from reading C++ file 'downloadthemes.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "downloadthemes.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'downloadthemes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_downloadthemes_t {
    QByteArrayData data[13];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_downloadthemes_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_downloadthemes_t qt_meta_stringdata_downloadthemes = {
    {
QT_MOC_LITERAL(0, 0, 14), // "downloadthemes"
QT_MOC_LITERAL(1, 15, 18), // "on_Violet_released"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 11), // "downloadSet"
QT_MOC_LITERAL(4, 47, 3), // "url"
QT_MOC_LITERAL(5, 51, 6), // "saveAS"
QT_MOC_LITERAL(6, 58, 16), // "on_Blue_released"
QT_MOC_LITERAL(7, 75, 17), // "on_Black_released"
QT_MOC_LITERAL(8, 93, 24), // "on_OrangeYellow_released"
QT_MOC_LITERAL(9, 118, 15), // "on_Red_released"
QT_MOC_LITERAL(10, 134, 17), // "on_Green_released"
QT_MOC_LITERAL(11, 152, 12), // "reloadThemes"
QT_MOC_LITERAL(12, 165, 16) // "on_Exit_released"

    },
    "downloadthemes\0on_Violet_released\0\0"
    "downloadSet\0url\0saveAS\0on_Blue_released\0"
    "on_Black_released\0on_OrangeYellow_released\0"
    "on_Red_released\0on_Green_released\0"
    "reloadThemes\0on_Exit_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_downloadthemes[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    2,   60,    2, 0x08 /* Private */,
       6,    0,   65,    2, 0x08 /* Private */,
       7,    0,   66,    2, 0x08 /* Private */,
       8,    0,   67,    2, 0x08 /* Private */,
       9,    0,   68,    2, 0x08 /* Private */,
      10,    0,   69,    2, 0x08 /* Private */,
      11,    0,   70,    2, 0x08 /* Private */,
      12,    0,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void downloadthemes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<downloadthemes *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_Violet_released(); break;
        case 1: _t->downloadSet((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->on_Blue_released(); break;
        case 3: _t->on_Black_released(); break;
        case 4: _t->on_OrangeYellow_released(); break;
        case 5: _t->on_Red_released(); break;
        case 6: _t->on_Green_released(); break;
        case 7: _t->reloadThemes(); break;
        case 8: _t->on_Exit_released(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject downloadthemes::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_downloadthemes.data,
    qt_meta_data_downloadthemes,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *downloadthemes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *downloadthemes::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_downloadthemes.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int downloadthemes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
