/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Controller_t {
    QByteArrayData data[16];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Controller"
QT_MOC_LITERAL(1, 11, 11), // "modifyLense"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "type"
QT_MOC_LITERAL(4, 29, 8), // "position"
QT_MOC_LITERAL(5, 38, 8), // "vergency"
QT_MOC_LITERAL(6, 47, 15), // "deflectionXAxis"
QT_MOC_LITERAL(7, 63, 15), // "deflectionZAxis"
QT_MOC_LITERAL(8, 79, 6), // "create"
QT_MOC_LITERAL(9, 86, 10), // "checkLense"
QT_MOC_LITERAL(10, 97, 9), // "LenseType"
QT_MOC_LITERAL(11, 107, 16), // "getLensePosition"
QT_MOC_LITERAL(12, 124, 9), // "lenseType"
QT_MOC_LITERAL(13, 134, 16), // "getLenseVergency"
QT_MOC_LITERAL(14, 151, 23), // "getLenseXAxisDeflection"
QT_MOC_LITERAL(15, 175, 23) // "getLenseZAxisDeflection"

    },
    "Controller\0modifyLense\0\0type\0position\0"
    "vergency\0deflectionXAxis\0deflectionZAxis\0"
    "create\0checkLense\0LenseType\0"
    "getLensePosition\0lenseType\0getLenseVergency\0"
    "getLenseXAxisDeflection\0getLenseZAxisDeflection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       1,   75, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    6,   44,    2, 0x02 /* Public */,
       9,    2,   57,    2, 0x02 /* Public */,
      11,    1,   62,    2, 0x02 /* Public */,
      13,    1,   65,    2, 0x02 /* Public */,
      14,    1,   68,    2, 0x02 /* Public */,
      15,    1,   71,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool,    3,    4,    5,    6,    7,    8,
    QMetaType::Bool, QMetaType::Int, 0x80000000 | 10,    2,    2,
    QMetaType::Int, QMetaType::Int,   12,
    QMetaType::Double, QMetaType::Int,   12,
    QMetaType::Double, QMetaType::Int,   12,
    QMetaType::Double, QMetaType::Int,   12,

 // constructors: parameters
    0x80000000 | 2,

 // constructors: name, argc, parameters, tag, flags
       0,    0,   74,    2, 0x0e /* Public */,

       0        // eod
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { Controller *_r = new Controller();
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    } else if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->modifyLense((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->checkLense((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< LenseType(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->getLensePosition((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { double _r = _t->getLenseVergency((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 4: { double _r = _t->getLenseXAxisDeflection((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 5: { double _r = _t->getLenseZAxisDeflection((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Controller::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Controller.data,
    qt_meta_data_Controller,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
