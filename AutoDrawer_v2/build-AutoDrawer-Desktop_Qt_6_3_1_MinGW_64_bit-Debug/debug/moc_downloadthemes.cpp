/****************************************************************************
** Meta object code from reading C++ file 'downloadthemes.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AutoDrawer/downloadthemes.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'downloadthemes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_downloadthemes_t {
    const uint offsetsAndSize[26];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_downloadthemes_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_downloadthemes_t qt_meta_stringdata_downloadthemes = {
    {
QT_MOC_LITERAL(0, 14), // "downloadthemes"
QT_MOC_LITERAL(15, 18), // "on_Violet_released"
QT_MOC_LITERAL(34, 0), // ""
QT_MOC_LITERAL(35, 11), // "downloadSet"
QT_MOC_LITERAL(47, 3), // "url"
QT_MOC_LITERAL(51, 6), // "saveAS"
QT_MOC_LITERAL(58, 16), // "on_Blue_released"
QT_MOC_LITERAL(75, 17), // "on_Black_released"
QT_MOC_LITERAL(93, 24), // "on_OrangeYellow_released"
QT_MOC_LITERAL(118, 15), // "on_Red_released"
QT_MOC_LITERAL(134, 17), // "on_Green_released"
QT_MOC_LITERAL(152, 12), // "reloadThemes"
QT_MOC_LITERAL(165, 16) // "on_Exit_released"

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
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    2,   69,    2, 0x08,    2 /* Private */,
       6,    0,   74,    2, 0x08,    5 /* Private */,
       7,    0,   75,    2, 0x08,    6 /* Private */,
       8,    0,   76,    2, 0x08,    7 /* Private */,
       9,    0,   77,    2, 0x08,    8 /* Private */,
      10,    0,   78,    2, 0x08,    9 /* Private */,
      11,    0,   79,    2, 0x08,   10 /* Private */,
      12,    0,   80,    2, 0x08,   11 /* Private */,

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
        case 1: _t->downloadSet((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
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

const QMetaObject downloadthemes::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_downloadthemes.offsetsAndSize,
    qt_meta_data_downloadthemes,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_downloadthemes_t
, QtPrivate::TypeAndForceComplete<downloadthemes, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
