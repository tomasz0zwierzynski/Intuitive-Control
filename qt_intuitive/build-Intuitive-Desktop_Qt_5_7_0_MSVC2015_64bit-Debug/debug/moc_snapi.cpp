/****************************************************************************
** Meta object code from reading C++ file 'snapi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Intuitive/3Dmouse/snapi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'snapi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SNapi_t {
    QByteArrayData data[9];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SNapi_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SNapi_t qt_meta_stringdata_SNapi = {
    {
QT_MOC_LITERAL(0, 0, 5), // "SNapi"
QT_MOC_LITERAL(1, 6, 8), // "finished"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 5), // "error"
QT_MOC_LITERAL(4, 22, 3), // "err"
QT_MOC_LITERAL(5, 26, 4), // "info"
QT_MOC_LITERAL(6, 31, 12), // "data_arrived"
QT_MOC_LITERAL(7, 44, 7), // "process"
QT_MOC_LITERAL(8, 52, 19) // "RequestThreadToStop"

    },
    "SNapi\0finished\0\0error\0err\0info\0"
    "data_arrived\0process\0RequestThreadToStop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SNapi[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,
       5,    1,   48,    2, 0x06 /* Public */,
       6,    1,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SNapi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SNapi *_t = static_cast<SNapi *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->info((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->data_arrived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->process(); break;
        case 5: _t->RequestThreadToStop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SNapi::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SNapi::finished)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SNapi::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SNapi::error)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SNapi::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SNapi::info)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (SNapi::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SNapi::data_arrived)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject SNapi::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SNapi.data,
      qt_meta_data_SNapi,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SNapi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SNapi::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SNapi.stringdata0))
        return static_cast<void*>(const_cast< SNapi*>(this));
    return QObject::qt_metacast(_clname);
}

int SNapi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SNapi::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void SNapi::error(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SNapi::info(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SNapi::data_arrived(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
