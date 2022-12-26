/****************************************************************************
** Meta object code from reading C++ file 'consolewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AutoDrawer/consolewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'consolewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConsoleWindow_t {
    QByteArrayData data[11];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConsoleWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConsoleWindow_t qt_meta_stringdata_ConsoleWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ConsoleWindow"
QT_MOC_LITERAL(1, 14, 18), // "on_Exit_3_released"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 18), // "on_Exit_2_released"
QT_MOC_LITERAL(4, 53, 16), // "on_Exit_released"
QT_MOC_LITERAL(5, 70, 18), // "on_Exit_4_released"
QT_MOC_LITERAL(6, 89, 13), // "reloadConsole"
QT_MOC_LITERAL(7, 103, 11), // "std::string"
QT_MOC_LITERAL(8, 115, 2), // "ln"
QT_MOC_LITERAL(9, 118, 18), // "on_Exit_5_released"
QT_MOC_LITERAL(10, 137, 12) // "reloadThemes"

    },
    "ConsoleWindow\0on_Exit_3_released\0\0"
    "on_Exit_2_released\0on_Exit_released\0"
    "on_Exit_4_released\0reloadConsole\0"
    "std::string\0ln\0on_Exit_5_released\0"
    "reloadThemes"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConsoleWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,
       9,    0,   56,    2, 0x08 /* Private */,
      10,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ConsoleWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConsoleWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Exit_3_released(); break;
        case 1: _t->on_Exit_2_released(); break;
        case 2: _t->on_Exit_released(); break;
        case 3: _t->on_Exit_4_released(); break;
        case 4: _t->reloadConsole((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 5: _t->on_Exit_5_released(); break;
        case 6: _t->reloadThemes(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ConsoleWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ConsoleWindow.data,
    qt_meta_data_ConsoleWindow,
    qt_static_metacall,
    nullptr,
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
