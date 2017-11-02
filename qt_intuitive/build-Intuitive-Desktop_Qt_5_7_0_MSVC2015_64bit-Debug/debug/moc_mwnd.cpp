/****************************************************************************
** Meta object code from reading C++ file 'mwnd.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Intuitive/mwnd.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mwnd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_mWnd_t {
    QByteArrayData data[14];
    char stringdata0[312];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mWnd_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mWnd_t qt_meta_stringdata_mWnd = {
    {
QT_MOC_LITERAL(0, 0, 4), // "mWnd"
QT_MOC_LITERAL(1, 5, 18), // "switchFramePressed"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 14), // "lockAxePressed"
QT_MOC_LITERAL(4, 40, 15), // "startSimulation"
QT_MOC_LITERAL(5, 56, 14), // "stopSimulation"
QT_MOC_LITERAL(6, 71, 18), // "restartApplication"
QT_MOC_LITERAL(7, 90, 34), // "on_actionStop_simulation_trig..."
QT_MOC_LITERAL(8, 125, 38), // "on_actionRestart_Application_..."
QT_MOC_LITERAL(9, 164, 36), // "on_actionClose_Application_tr..."
QT_MOC_LITERAL(10, 201, 17), // "on_setup_finished"
QT_MOC_LITERAL(11, 219, 27), // "on_actionSettings_triggered"
QT_MOC_LITERAL(12, 247, 33), // "on_actionRun_simulation_trigg..."
QT_MOC_LITERAL(13, 281, 30) // "on_actionShow_graphs_triggered"

    },
    "mWnd\0switchFramePressed\0\0lockAxePressed\0"
    "startSimulation\0stopSimulation\0"
    "restartApplication\0"
    "on_actionStop_simulation_triggered\0"
    "on_actionRestart_Application_triggered\0"
    "on_actionClose_Application_triggered\0"
    "on_setup_finished\0on_actionSettings_triggered\0"
    "on_actionRun_simulation_triggered\0"
    "on_actionShow_graphs_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mWnd[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       3,    1,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   80,    2, 0x0a /* Public */,
       5,    0,   81,    2, 0x0a /* Public */,
       6,    0,   82,    2, 0x0a /* Public */,
       7,    0,   83,    2, 0x08 /* Private */,
       8,    0,   84,    2, 0x08 /* Private */,
       9,    0,   85,    2, 0x08 /* Private */,
      10,    0,   86,    2, 0x08 /* Private */,
      11,    0,   87,    2, 0x08 /* Private */,
      12,    0,   88,    2, 0x08 /* Private */,
      13,    0,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mWnd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mWnd *_t = static_cast<mWnd *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->switchFramePressed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->lockAxePressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->startSimulation(); break;
        case 3: _t->stopSimulation(); break;
        case 4: _t->restartApplication(); break;
        case 5: _t->on_actionStop_simulation_triggered(); break;
        case 6: _t->on_actionRestart_Application_triggered(); break;
        case 7: _t->on_actionClose_Application_triggered(); break;
        case 8: _t->on_setup_finished(); break;
        case 9: _t->on_actionSettings_triggered(); break;
        case 10: _t->on_actionRun_simulation_triggered(); break;
        case 11: _t->on_actionShow_graphs_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (mWnd::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&mWnd::switchFramePressed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (mWnd::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&mWnd::lockAxePressed)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject mWnd::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_mWnd.data,
      qt_meta_data_mWnd,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *mWnd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mWnd::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_mWnd.stringdata0))
        return static_cast<void*>(const_cast< mWnd*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int mWnd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void mWnd::switchFramePressed(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void mWnd::lockAxePressed(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
