/****************************************************************************
** Meta object code from reading C++ file 'vueRoutesControleur.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../NetSmoothMVC/controleurs/vueRoutesControleur.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vueRoutesControleur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VueRoutesControleur_t {
    QByteArrayData data[6];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VueRoutesControleur_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VueRoutesControleur_t qt_meta_stringdata_VueRoutesControleur = {
    {
QT_MOC_LITERAL(0, 0, 19), // "VueRoutesControleur"
QT_MOC_LITERAL(1, 20, 12), // "deleteRoute4"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 9), // "addRoute4"
QT_MOC_LITERAL(4, 44, 12), // "deleteRoute6"
QT_MOC_LITERAL(5, 57, 9) // "addRoute6"

    },
    "VueRoutesControleur\0deleteRoute4\0\0"
    "addRoute4\0deleteRoute6\0addRoute6"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VueRoutesControleur[] = {

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
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VueRoutesControleur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VueRoutesControleur *_t = static_cast<VueRoutesControleur *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deleteRoute4(); break;
        case 1: _t->addRoute4(); break;
        case 2: _t->deleteRoute6(); break;
        case 3: _t->addRoute6(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject VueRoutesControleur::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_VueRoutesControleur.data,
      qt_meta_data_VueRoutesControleur,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VueRoutesControleur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VueRoutesControleur::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VueRoutesControleur.stringdata0))
        return static_cast<void*>(const_cast< VueRoutesControleur*>(this));
    return QObject::qt_metacast(_clname);
}

int VueRoutesControleur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
