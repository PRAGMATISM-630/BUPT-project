/****************************************************************************
** Meta object code from reading C++ file 'gui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../traveling_system/gui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GUI_t {
    QByteArrayData data[18];
    char stringdata0[381];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUI_t qt_meta_stringdata_GUI = {
    {
QT_MOC_LITERAL(0, 0, 3), // "GUI"
QT_MOC_LITERAL(1, 4, 19), // "on_get_path_clicked"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 25), // "on_get_user_state_clicked"
QT_MOC_LITERAL(4, 51, 27), // "on_start_simulation_clicked"
QT_MOC_LITERAL(5, 79, 26), // "on_stop_simulation_clicked"
QT_MOC_LITERAL(6, 106, 23), // "on_get_strategy_clicked"
QT_MOC_LITERAL(7, 130, 25), // "on_get_strategy_2_clicked"
QT_MOC_LITERAL(8, 156, 23), // "on_get_origin_activated"
QT_MOC_LITERAL(9, 180, 5), // "index"
QT_MOC_LITERAL(10, 186, 28), // "on_get_destination_activated"
QT_MOC_LITERAL(11, 215, 20), // "on_get_day_activated"
QT_MOC_LITERAL(12, 236, 21), // "on_get_hour_activated"
QT_MOC_LITERAL(13, 258, 23), // "on_get_choice_activated"
QT_MOC_LITERAL(14, 282, 31), // "on_get_max_time_editingFinished"
QT_MOC_LITERAL(15, 314, 11), // "update_info"
QT_MOC_LITERAL(16, 326, 24), // "on_add_traveller_clicked"
QT_MOC_LITERAL(17, 351, 29) // "on_choose_traveller_activated"

    },
    "GUI\0on_get_path_clicked\0\0"
    "on_get_user_state_clicked\0"
    "on_start_simulation_clicked\0"
    "on_stop_simulation_clicked\0"
    "on_get_strategy_clicked\0"
    "on_get_strategy_2_clicked\0"
    "on_get_origin_activated\0index\0"
    "on_get_destination_activated\0"
    "on_get_day_activated\0on_get_hour_activated\0"
    "on_get_choice_activated\0"
    "on_get_max_time_editingFinished\0"
    "update_info\0on_add_traveller_clicked\0"
    "on_choose_traveller_activated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    1,   95,    2, 0x08 /* Private */,
      10,    1,   98,    2, 0x08 /* Private */,
      11,    1,  101,    2, 0x08 /* Private */,
      12,    1,  104,    2, 0x08 /* Private */,
      13,    1,  107,    2, 0x08 /* Private */,
      14,    0,  110,    2, 0x08 /* Private */,
      15,    0,  111,    2, 0x08 /* Private */,
      16,    0,  112,    2, 0x08 /* Private */,
      17,    1,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void GUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GUI *_t = static_cast<GUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_get_path_clicked(); break;
        case 1: _t->on_get_user_state_clicked(); break;
        case 2: _t->on_start_simulation_clicked(); break;
        case 3: _t->on_stop_simulation_clicked(); break;
        case 4: _t->on_get_strategy_clicked(); break;
        case 5: _t->on_get_strategy_2_clicked(); break;
        case 6: _t->on_get_origin_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_get_destination_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_get_day_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_get_hour_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_get_choice_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_get_max_time_editingFinished(); break;
        case 12: _t->update_info(); break;
        case 13: _t->on_add_traveller_clicked(); break;
        case 14: _t->on_choose_traveller_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject GUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GUI.data,
      qt_meta_data_GUI,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GUI.stringdata0))
        return static_cast<void*>(const_cast< GUI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int GUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
