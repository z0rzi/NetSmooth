/****************************************************************************
** Meta object code from reading C++ file 'vueprincipalecontroleur.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../NetSmoothMVC/vueprincipalecontroleur.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vueprincipalecontroleur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VuePrincipaleControleur_t {
    QByteArrayData data[4];
    char stringdata0[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VuePrincipaleControleur_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VuePrincipaleControleur_t qt_meta_stringdata_VuePrincipaleControleur = {
    {
QT_MOC_LITERAL(0, 0, 23), // "VuePrincipaleControleur"
QT_MOC_LITERAL(1, 24, 12), // "paintMachine"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 3) // "pos"

    },
    "VuePrincipaleControleur\0paintMachine\0"
    "\0pos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VuePrincipaleControleur[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    3,

       0        // eod
};

void VuePrincipaleControleur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VuePrincipaleControleur *_t = static_cast<VuePrincipaleControleur *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->paintMachine((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject VuePrincipaleControleur::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_VuePrincipaleControleur.data,
      qt_meta_data_VuePrincipaleControleur,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VuePrincipaleControleur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VuePrincipaleControleur::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VuePrincipaleControleur.stringdata0))
        return static_cast<void*>(const_cast< VuePrincipaleControleur*>(this));
    return QObject::qt_metacast(_clname);
}

int VuePrincipaleControleur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
