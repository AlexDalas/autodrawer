/****************************************************************************
** Meta object code from reading C++ file 'settingswindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AutoDrawer/settingswindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SettingsWindow_t {
    QByteArrayData data[21];
    char stringdata0[391];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingsWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingsWindow_t qt_meta_stringdata_SettingsWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SettingsWindow"
QT_MOC_LITERAL(1, 15, 14), // "on_GH_released"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 14), // "on_LR_released"
QT_MOC_LITERAL(4, 46, 19), // "on_Discord_released"
QT_MOC_LITERAL(5, 66, 20), // "on_CloseBox_released"
QT_MOC_LITERAL(6, 87, 22), // "on_OpenThemes_released"
QT_MOC_LITERAL(7, 110, 12), // "reloadThemes"
QT_MOC_LITERAL(8, 123, 5), // "theme"
QT_MOC_LITERAL(9, 129, 18), // "on_Reload_released"
QT_MOC_LITERAL(10, 148, 33), // "on_ThemeCombo_currentIndexCha..."
QT_MOC_LITERAL(11, 182, 21), // "on_OffsetBox_released"
QT_MOC_LITERAL(12, 204, 18), // "on_LogBox_released"
QT_MOC_LITERAL(13, 223, 10), // "reloadList"
QT_MOC_LITERAL(14, 234, 20), // "on_OpenLogs_released"
QT_MOC_LITERAL(15, 255, 22), // "on_PrinterBox_released"
QT_MOC_LITERAL(16, 278, 19), // "on_Console_released"
QT_MOC_LITERAL(17, 298, 23), // "on_ThemeEditor_released"
QT_MOC_LITERAL(18, 322, 30), // "on_intervalTextBox_textChanged"
QT_MOC_LITERAL(19, 353, 4), // "arg1"
QT_MOC_LITERAL(20, 358, 32) // "on_intervalTextBox_2_textChanged"

    },
    "SettingsWindow\0on_GH_released\0\0"
    "on_LR_released\0on_Discord_released\0"
    "on_CloseBox_released\0on_OpenThemes_released\0"
    "reloadThemes\0theme\0on_Reload_released\0"
    "on_ThemeCombo_currentIndexChanged\0"
    "on_OffsetBox_released\0on_LogBox_released\0"
    "reloadList\0on_OpenLogs_released\0"
    "on_PrinterBox_released\0on_Console_released\0"
    "on_ThemeEditor_released\0"
    "on_intervalTextBox_textChanged\0arg1\0"
    "on_intervalTextBox_2_textChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingsWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    1,  104,    2, 0x08 /* Private */,
       9,    0,  107,    2, 0x08 /* Private */,
      10,    0,  108,    2, 0x08 /* Private */,
      11,    0,  109,    2, 0x08 /* Private */,
      12,    0,  110,    2, 0x08 /* Private */,
      13,    0,  111,    2, 0x08 /* Private */,
      14,    0,  112,    2, 0x08 /* Private */,
      15,    0,  113,    2, 0x08 /* Private */,
      16,    0,  114,    2, 0x08 /* Private */,
      17,    0,  115,    2, 0x08 /* Private */,
      18,    1,  116,    2, 0x08 /* Private */,
      20,    1,  119,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   19,

       0        // eod
};

void SettingsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SettingsWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_GH_released(); break;
        case 1: _t->on_LR_released(); break;
        case 2: _t->on_Discord_released(); break;
        case 3: _t->on_CloseBox_released(); break;
        case 4: _t->on_OpenThemes_released(); break;
        case 5: _t->reloadThemes((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->on_Reload_released(); break;
        case 7: _t->on_ThemeCombo_currentIndexChanged(); break;
        case 8: _t->on_OffsetBox_released(); break;
        case 9: _t->on_LogBox_released(); break;
        case 10: _t->reloadList(); break;
        case 11: _t->on_OpenLogs_released(); break;
        case 12: _t->on_PrinterBox_released(); break;
        case 13: _t->on_Console_released(); break;
        case 14: _t->on_ThemeEditor_released(); break;
        case 15: _t->on_intervalTextBox_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->on_intervalTextBox_2_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SettingsWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_SettingsWindow.data,
    qt_meta_data_SettingsWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SettingsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SettingsWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SettingsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
