/****************************************************************************
** Meta object code from reading C++ file 'previewwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AutoDrawer/previewwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'previewwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PreviewWindow_t {
    QByteArrayData data[25];
    char stringdata0[219];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PreviewWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PreviewWindow_t qt_meta_stringdata_PreviewWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "PreviewWindow"
QT_MOC_LITERAL(1, 14, 24), // "on_pushButton_2_released"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 9), // "closeDraw"
QT_MOC_LITERAL(4, 50, 1), // "a"
QT_MOC_LITERAL(5, 52, 4), // "Draw"
QT_MOC_LITERAL(6, 57, 16), // "on_Draw_released"
QT_MOC_LITERAL(7, 74, 7), // "lockPos"
QT_MOC_LITERAL(8, 82, 12), // "reloadThemes"
QT_MOC_LITERAL(9, 95, 11), // "ResetPixels"
QT_MOC_LITERAL(10, 107, 3), // "NOP"
QT_MOC_LITERAL(11, 111, 6), // "ourint"
QT_MOC_LITERAL(12, 118, 5), // "setPA"
QT_MOC_LITERAL(13, 124, 1), // "x"
QT_MOC_LITERAL(14, 126, 1), // "y"
QT_MOC_LITERAL(15, 128, 5), // "value"
QT_MOC_LITERAL(16, 134, 5), // "getPA"
QT_MOC_LITERAL(17, 140, 8), // "DrawArea"
QT_MOC_LITERAL(18, 149, 19), // "std::vector<QPoint>"
QT_MOC_LITERAL(19, 169, 5), // "stack"
QT_MOC_LITERAL(20, 175, 4), // "xImg"
QT_MOC_LITERAL(21, 180, 4), // "yImg"
QT_MOC_LITERAL(22, 185, 4), // "Push"
QT_MOC_LITERAL(23, 190, 3), // "Pop"
QT_MOC_LITERAL(24, 194, 24) // "std::tuple<bool,int,int>"

    },
    "PreviewWindow\0on_pushButton_2_released\0"
    "\0closeDraw\0a\0Draw\0on_Draw_released\0"
    "lockPos\0reloadThemes\0ResetPixels\0NOP\0"
    "ourint\0setPA\0x\0y\0value\0getPA\0DrawArea\0"
    "std::vector<QPoint>\0stack\0xImg\0yImg\0"
    "Push\0Pop\0std::tuple<bool,int,int>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PreviewWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    1,   80,    2, 0x08 /* Private */,
       5,    0,   83,    2, 0x08 /* Private */,
       6,    0,   84,    2, 0x08 /* Private */,
       7,    0,   85,    2, 0x08 /* Private */,
       8,    0,   86,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    1,   88,    2, 0x08 /* Private */,
      12,    3,   91,    2, 0x08 /* Private */,
      16,    2,   98,    2, 0x08 /* Private */,
      17,    5,  103,    2, 0x08 /* Private */,
      22,    3,  114,    2, 0x08 /* Private */,
      23,    3,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   13,   14,   15,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,   13,   14,
    QMetaType::Bool, 0x80000000 | 18, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   19,   20,   21,   13,   14,
    0x80000000 | 18, 0x80000000 | 18, QMetaType::Int, QMetaType::Int,   19,   20,   21,
    0x80000000 | 24, 0x80000000 | 18, QMetaType::Int, QMetaType::Int,   19,   20,   21,

       0        // eod
};

void PreviewWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PreviewWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_2_released(); break;
        case 1: _t->closeDraw((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->Draw(); break;
        case 3: _t->on_Draw_released(); break;
        case 4: _t->lockPos(); break;
        case 5: _t->reloadThemes(); break;
        case 6: _t->ResetPixels(); break;
        case 7: _t->NOP((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setPA((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 9: { int _r = _t->getPA((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->DrawArea((*reinterpret_cast< std::vector<QPoint>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { std::vector<QPoint> _r = _t->Push((*reinterpret_cast< std::vector<QPoint>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< std::vector<QPoint>*>(_a[0]) = std::move(_r); }  break;
        case 12: { std::tuple<bool,int,int> _r = _t->Pop((*reinterpret_cast< std::vector<QPoint>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< std::tuple<bool,int,int>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PreviewWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_PreviewWindow.data,
    qt_meta_data_PreviewWindow,
    qt_static_metacall,
    nullptr,
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
