/****************************************************************************
** Meta object code from reading C++ file 'OptionsWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "OptionsWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OptionsWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OptionsWidget_t {
    QByteArrayData data[13];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OptionsWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OptionsWidget_t qt_meta_stringdata_OptionsWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "OptionsWidget"
QT_MOC_LITERAL(1, 14, 11), // "sendOptions"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "numRounds"
QT_MOC_LITERAL(4, 37, 9), // "downCount"
QT_MOC_LITERAL(5, 47, 11), // "roundLength"
QT_MOC_LITERAL(6, 59, 8), // "spoilers"
QT_MOC_LITERAL(7, 68, 12), // "sendFileName"
QT_MOC_LITERAL(8, 81, 4), // "name"
QT_MOC_LITERAL(9, 86, 11), // "toggleSound"
QT_MOC_LITERAL(10, 98, 3), // "val"
QT_MOC_LITERAL(11, 102, 12), // "startClicked"
QT_MOC_LITERAL(12, 115, 11) // "saveClicked"

    },
    "OptionsWidget\0sendOptions\0\0numRounds\0"
    "downCount\0roundLength\0spoilers\0"
    "sendFileName\0name\0toggleSound\0val\0"
    "startClicked\0saveClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OptionsWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   39,    2, 0x06 /* Public */,
       7,    1,   48,    2, 0x06 /* Public */,
       9,    1,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   54,    2, 0x08 /* Private */,
      12,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Bool,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OptionsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OptionsWidget *_t = static_cast<OptionsWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendOptions((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 1: _t->sendFileName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->toggleSound((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->startClicked(); break;
        case 4: _t->saveClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OptionsWidget::*)(int , int , int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OptionsWidget::sendOptions)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (OptionsWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OptionsWidget::sendFileName)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (OptionsWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OptionsWidget::toggleSound)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OptionsWidget::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_OptionsWidget.data,
      qt_meta_data_OptionsWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *OptionsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OptionsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OptionsWidget.stringdata0))
        return static_cast<void*>(this);
    return QGroupBox::qt_metacast(_clname);
}

int OptionsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void OptionsWidget::sendOptions(int _t1, int _t2, int _t3, bool _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OptionsWidget::sendFileName(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void OptionsWidget::toggleSound(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
