/****************************************************************************
** Meta object code from reading C++ file 'RoundTabs.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "RoundTabs.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RoundTabs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RoundTabs_t {
    QByteArrayData data[11];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RoundTabs_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RoundTabs_t qt_meta_stringdata_RoundTabs = {
    {
QT_MOC_LITERAL(0, 0, 9), // "RoundTabs"
QT_MOC_LITERAL(1, 10, 9), // "setImages"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 6), // "string"
QT_MOC_LITERAL(4, 28, 2), // "s1"
QT_MOC_LITERAL(5, 31, 2), // "s2"
QT_MOC_LITERAL(6, 34, 12), // "createRounds"
QT_MOC_LITERAL(7, 47, 6), // "Match*"
QT_MOC_LITERAL(8, 54, 1), // "m"
QT_MOC_LITERAL(9, 56, 8), // "spoilers"
QT_MOC_LITERAL(10, 65, 8) // "showNext"

    },
    "RoundTabs\0setImages\0\0string\0s1\0s2\0"
    "createRounds\0Match*\0m\0spoilers\0showNext"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RoundTabs[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   34,    2, 0x0a /* Public */,
      10,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7, QMetaType::Bool,    8,    9,
    QMetaType::Void,

       0        // eod
};

void RoundTabs::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RoundTabs *_t = static_cast<RoundTabs *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setImages((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2]))); break;
        case 1: _t->createRounds((*reinterpret_cast< Match*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->showNext(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RoundTabs::*)(string , string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RoundTabs::setImages)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RoundTabs::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_RoundTabs.data,
      qt_meta_data_RoundTabs,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RoundTabs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RoundTabs::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RoundTabs.stringdata0))
        return static_cast<void*>(this);
    return QTabWidget::qt_metacast(_clname);
}

int RoundTabs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void RoundTabs::setImages(string _t1, string _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
