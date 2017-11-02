/****************************************************************************
** Meta object code from reading C++ file 'graphwnd.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Intuitive/graphwnd.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphwnd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_graphWnd_t {
    QByteArrayData data[9];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_graphWnd_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_graphWnd_t qt_meta_stringdata_graphWnd = {
    {
QT_MOC_LITERAL(0, 0, 8), // "graphWnd"
QT_MOC_LITERAL(1, 9, 13), // "on_graph_data"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 6), // "float*"
QT_MOC_LITERAL(4, 31, 10), // "closeEvent"
QT_MOC_LITERAL(5, 42, 12), // "QCloseEvent*"
QT_MOC_LITERAL(6, 55, 5), // "event"
QT_MOC_LITERAL(7, 61, 18), // "on_comboBox_change"
QT_MOC_LITERAL(8, 80, 18) // "on_pB_draw_clicked"

    },
    "graphWnd\0on_graph_data\0\0float*\0"
    "closeEvent\0QCloseEvent*\0event\0"
    "on_comboBox_change\0on_pB_draw_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_graphWnd[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x0a /* Public */,
       4,    1,   39,    2, 0x0a /* Public */,
       7,    1,   42,    2, 0x08 /* Private */,
       8,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void graphWnd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        graphWnd *_t = static_cast<graphWnd *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_graph_data((*reinterpret_cast< float*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 2: _t->on_comboBox_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pB_draw_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject graphWnd::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_graphWnd.data,
      qt_meta_data_graphWnd,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *graphWnd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *graphWnd::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_graphWnd.stringdata0))
        return static_cast<void*>(const_cast< graphWnd*>(this));
    return QWidget::qt_metacast(_clname);
}

int graphWnd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
