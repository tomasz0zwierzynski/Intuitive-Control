/****************************************************************************
** Meta object code from reading C++ file 'simhandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Intuitive/vrep/simhandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simhandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SimHandler_t {
    QByteArrayData data[14];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SimHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SimHandler_t qt_meta_stringdata_SimHandler = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SimHandler"
QT_MOC_LITERAL(1, 11, 16), // "stream_from_vrep"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 6), // "float*"
QT_MOC_LITERAL(4, 36, 17), // "on_setup_finished"
QT_MOC_LITERAL(5, 54, 3), // "dir"
QT_MOC_LITERAL(6, 58, 3), // "sce"
QT_MOC_LITERAL(7, 62, 3), // "ofs"
QT_MOC_LITERAL(8, 66, 21), // "on_velocities_changed"
QT_MOC_LITERAL(9, 88, 7), // "double*"
QT_MOC_LITERAL(10, 96, 22), // "on_motion_event_change"
QT_MOC_LITERAL(11, 119, 17), // "on_gripper_action"
QT_MOC_LITERAL(12, 137, 11), // "on_sim_stop"
QT_MOC_LITERAL(13, 149, 19) // "on_stream_from_vrep"

    },
    "SimHandler\0stream_from_vrep\0\0float*\0"
    "on_setup_finished\0dir\0sce\0ofs\0"
    "on_velocities_changed\0double*\0"
    "on_motion_event_change\0on_gripper_action\0"
    "on_sim_stop\0on_stream_from_vrep"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SimHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    3,   54,    2, 0x0a /* Public */,
       8,    2,   61,    2, 0x0a /* Public */,
      10,    1,   66,    2, 0x0a /* Public */,
      11,    1,   69,    2, 0x0a /* Public */,
      12,    0,   72,    2, 0x0a /* Public */,
      13,    2,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    5,    6,    7,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    2,

       0        // eod
};

void SimHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SimHandler *_t = static_cast<SimHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stream_from_vrep((*reinterpret_cast< float*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->on_setup_finished((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->on_velocities_changed((*reinterpret_cast< double*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->on_motion_event_change((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_gripper_action((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_sim_stop(); break;
        case 6: _t->on_stream_from_vrep((*reinterpret_cast< float*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SimHandler::*_t)(float * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SimHandler::stream_from_vrep)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SimHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SimHandler.data,
      qt_meta_data_SimHandler,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SimHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SimHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SimHandler.stringdata0))
        return static_cast<void*>(const_cast< SimHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int SimHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void SimHandler::stream_from_vrep(float * _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
