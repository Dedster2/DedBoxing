/****************************************************************************
** Meta object code from reading C++ file 'roundTab.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "roundTab.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roundTab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_roundTab_t {
    QByteArrayData data[14];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_roundTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_roundTab_t qt_meta_stringdata_roundTab = {
    {
QT_MOC_LITERAL(0, 0, 8), // "roundTab"
QT_MOC_LITERAL(1, 9, 9), // "setImages"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 6), // "string"
QT_MOC_LITERAL(4, 27, 2), // "s1"
QT_MOC_LITERAL(5, 30, 2), // "s2"
QT_MOC_LITERAL(6, 33, 8), // "endRound"
QT_MOC_LITERAL(7, 42, 11), // "toggleSound"
QT_MOC_LITERAL(8, 54, 3), // "val"
QT_MOC_LITERAL(9, 58, 10), // "toggleAuto"
QT_MOC_LITERAL(10, 69, 6), // "reveal"
QT_MOC_LITERAL(11, 76, 4), // "test"
QT_MOC_LITERAL(12, 81, 1), // "i"
QT_MOC_LITERAL(13, 83, 7) // "advance"

    },
    "roundTab\0setImages\0\0string\0s1\0s2\0"
    "endRound\0toggleSound\0val\0toggleAuto\0"
    "reveal\0test\0i\0advance"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_roundTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       6,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   55,    2, 0x0a /* Public */,
       9,    0,   58,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,
      11,    1,   60,    2, 0x08 /* Private */,
      13,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,

       0        // eod
};

void roundTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        roundTab *_t = static_cast<roundTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setImages((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2]))); break;
        case 1: _t->endRound(); break;
        case 2: _t->toggleSound((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->toggleAuto(); break;
        case 4: _t->reveal(); break;
        case 5: _t->test((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->advance(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (roundTab::*)(string , string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&roundTab::setImages)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (roundTab::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&roundTab::endRound)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject roundTab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_roundTab.data,
      qt_meta_data_roundTab,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *roundTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *roundTab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_roundTab.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int roundTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void roundTab::setImages(string _t1, string _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void roundTab::endRound()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
