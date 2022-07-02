/****************************************************************************
** Meta object code from reading C++ file 'consolewindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AutoDrawer/consolewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'consolewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConsoleWindow_t {
    const uint offsetsAndSize[20];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ConsoleWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ConsoleWindow_t qt_meta_stringdata_ConsoleWindow = {
    {
QT_MOC_LITERAL(0, 13), // "ConsoleWindow"
QT_MOC_LITERAL(14, 18), // "on_Exit_3_released"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 18), // "on_Exit_2_released"
QT_MOC_LITERAL(53, 16), // "on_Exit_released"
QT_MOC_LITERAL(70, 18), // "on_Exit_4_released"
QT_MOC_LITERAL(89, 13), // "reloadConsole"
QT_MOC_LITERAL(103, 11), // "std::string"
QT_MOC_LITERAL(115, 2), // "ln"
QT_MOC_LITERAL(118, 18) // "on_Exit_5_released"

    },
    "ConsoleWindow\0on_Exit_3_released\0\0"
    "on_Exit_2_released\0on_Exit_released\0"
    "on_Exit_4_released\0reloadConsole\0"
    "std::string\0ln\0on_Exit_5_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConsoleWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    1,   54,    2, 0x08,    5 /* Private */,
       9,    0,   57,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,

       0        // eod
};

void ConsoleWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConsoleWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_Exit_3_released(); break;
        case 1: _t->on_Exit_2_released(); break;
        case 2: _t->on_Exit_released(); break;
        case 3: _t->on_Exit_4_released(); break;
        case 4: _t->reloadConsole((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 5: _t->on_Exit_5_released(); break;
        default: ;
        }
    }
}

const QMetaObject ConsoleWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ConsoleWindow.offsetsAndSize,
    qt_meta_data_ConsoleWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ConsoleWindow_t
, QtPrivate::TypeAndForceComplete<ConsoleWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ConsoleWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConsoleWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConsoleWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ConsoleWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
