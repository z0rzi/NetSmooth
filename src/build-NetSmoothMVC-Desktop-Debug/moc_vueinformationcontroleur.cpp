/****************************************************************************
** Meta object code from reading C++ file 'vueinformationcontroleur.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../NetSmoothMVC/controleurs/vueinformationcontroleur.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vueinformationcontroleur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VueInformationControleur_t {
    QByteArrayData data[5];
    char stringdata0[61];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VueInformationControleur_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VueInformationControleur_t qt_meta_stringdata_VueInformationControleur = {
    {
QT_MOC_LITERAL(0, 0, 24), // "VueInformationControleur"
QT_MOC_LITERAL(1, 25, 11), // "ajoutLigne4"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 11), // "ajoutLigne6"
QT_MOC_LITERAL(4, 50, 10) // "refreshVue"

    },
    "VueInformationControleur\0ajoutLigne4\0"
    "\0ajoutLigne6\0refreshVue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VueInformationControleur[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       4,    0,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VueInformationControleur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VueInformationControleur *_t = static_cast<VueInformationControleur *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ajoutLigne4(); break;
        case 1: _t->ajoutLigne6(); break;
        case 2: _t->refreshVue(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject VueInformationControleur::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_VueInformationControleur.data,
      qt_meta_data_VueInformationControleur,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VueInformationControleur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VueInformationControleur::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VueInformationControleur.stringdata0))
        return static_cast<void*>(const_cast< VueInformationControleur*>(this));
    return QObject::qt_metacast(_clname);
}

int VueInformationControleur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE