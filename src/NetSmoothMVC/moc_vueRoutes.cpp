/****************************************************************************
** Meta object code from reading C++ file 'vueRoutes.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "vues/vueRoutes.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vueRoutes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VueRoutes[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      26,   10,   10,   10, 0x0a,
      38,   10,   10,   10, 0x0a,
      53,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_VueRoutes[] = {
    "VueRoutes\0\0deleteRoute4()\0addRoute4()\0"
    "deleteRoute6()\0addRoute6()\0"
};

void VueRoutes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VueRoutes *_t = static_cast<VueRoutes *>(_o);
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

const QMetaObjectExtraData VueRoutes::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VueRoutes::staticMetaObject = {
    { &QGridLayout::staticMetaObject, qt_meta_stringdata_VueRoutes,
      qt_meta_data_VueRoutes, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VueRoutes::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VueRoutes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VueRoutes::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VueRoutes))
        return static_cast<void*>(const_cast< VueRoutes*>(this));
    return QGridLayout::qt_metacast(_clname);
}

int VueRoutes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGridLayout::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
