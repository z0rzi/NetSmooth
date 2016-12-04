/****************************************************************************
** Meta object code from reading C++ file 'vuehubcontroleur.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "controleurs/vuehubcontroleur.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vuehubcontroleur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VueHubControleur[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_VueHubControleur[] = {
    "VueHubControleur\0\0allumer()\0"
};

void VueHubControleur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VueHubControleur *_t = static_cast<VueHubControleur *>(_o);
        switch (_id) {
        case 0: _t->allumer(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData VueHubControleur::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VueHubControleur::staticMetaObject = {
    { &VueEntiteeControleur::staticMetaObject, qt_meta_stringdata_VueHubControleur,
      qt_meta_data_VueHubControleur, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VueHubControleur::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VueHubControleur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VueHubControleur::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VueHubControleur))
        return static_cast<void*>(const_cast< VueHubControleur*>(this));
    return VueEntiteeControleur::qt_metacast(_clname);
}

int VueHubControleur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = VueEntiteeControleur::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
