/****************************************************************************
** Meta object code from reading C++ file 'previewwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AutoDrawer/previewwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'previewwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PreviewWindow_t {
    const uint offsetsAndSize[36];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PreviewWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PreviewWindow_t qt_meta_stringdata_PreviewWindow = {
    {
QT_MOC_LITERAL(0, 13), // "PreviewWindow"
QT_MOC_LITERAL(14, 24), // "on_pushButton_2_released"
QT_MOC_LITERAL(39, 0), // ""
QT_MOC_LITERAL(40, 9), // "closeDraw"
QT_MOC_LITERAL(50, 1), // "a"
QT_MOC_LITERAL(52, 4), // "Draw"
QT_MOC_LITERAL(57, 9), // "setCursor"
QT_MOC_LITERAL(67, 1), // "x"
QT_MOC_LITERAL(69, 1), // "y"
QT_MOC_LITERAL(71, 11), // "clickCursor"
QT_MOC_LITERAL(83, 16), // "on_Draw_released"
QT_MOC_LITERAL(100, 7), // "lockPos"
QT_MOC_LITERAL(108, 6), // "pyCode"
QT_MOC_LITERAL(115, 11), // "std::string"
QT_MOC_LITERAL(127, 3), // "str"
QT_MOC_LITERAL(131, 12), // "reloadThemes"
QT_MOC_LITERAL(144, 10), // "holdCursor"
QT_MOC_LITERAL(155, 13) // "releaseCursor"

    },
    "PreviewWindow\0on_pushButton_2_released\0"
    "\0closeDraw\0a\0Draw\0setCursor\0x\0y\0"
    "clickCursor\0on_Draw_released\0lockPos\0"
    "pyCode\0std::string\0str\0reloadThemes\0"
    "holdCursor\0releaseCursor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PreviewWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    1 /* Private */,
       3,    1,   81,    2, 0x08,    2 /* Private */,
       5,    0,   84,    2, 0x08,    4 /* Private */,
       6,    2,   85,    2, 0x08,    5 /* Private */,
       9,    0,   90,    2, 0x08,    8 /* Private */,
      10,    0,   91,    2, 0x08,    9 /* Private */,
      11,    0,   92,    2, 0x08,   10 /* Private */,
      12,    1,   93,    2, 0x08,   11 /* Private */,
      15,    0,   96,    2, 0x08,   13 /* Private */,
      16,    0,   97,    2, 0x08,   14 /* Private */,
      17,    0,   98,    2, 0x08,   15 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PreviewWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PreviewWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_2_released(); break;
        case 1: _t->closeDraw((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->Draw(); break;
        case 3: _t->setCursor((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 4: _t->clickCursor(); break;
        case 5: _t->on_Draw_released(); break;
        case 6: _t->lockPos(); break;
        case 7: { bool _r = _t->pyCode((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->reloadThemes(); break;
        case 9: _t->holdCursor(); break;
        case 10: _t->releaseCursor(); break;
        default: ;
        }
    }
}

const QMetaObject PreviewWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_PreviewWindow.offsetsAndSize,
    qt_meta_data_PreviewWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PreviewWindow_t
, QtPrivate::TypeAndForceComplete<PreviewWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *PreviewWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PreviewWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PreviewWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int PreviewWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
