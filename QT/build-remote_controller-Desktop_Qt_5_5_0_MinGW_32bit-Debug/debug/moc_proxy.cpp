/****************************************************************************
** Meta object code from reading C++ file 'proxy.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../remote_controller/proxy.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'proxy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_proxy_t {
    QByteArrayData data[8];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_proxy_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_proxy_t qt_meta_stringdata_proxy = {
    {
QT_MOC_LITERAL(0, 0, 5), // "proxy"
QT_MOC_LITERAL(1, 6, 10), // "updateStep"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 4), // "step"
QT_MOC_LITERAL(4, 23, 12), // "stateChanged"
QT_MOC_LITERAL(5, 36, 16), // "QTimeLine::State"
QT_MOC_LITERAL(6, 53, 6), // "zoomIn"
QT_MOC_LITERAL(7, 60, 7) // "zoomOut"

    },
    "proxy\0updateStep\0\0step\0stateChanged\0"
    "QTimeLine::State\0zoomIn\0zoomOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_proxy[] = {

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
       1,    1,   34,    2, 0x08 /* Private */,
       4,    1,   37,    2, 0x08 /* Private */,
       6,    0,   40,    2, 0x08 /* Private */,
       7,    0,   41,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QReal,    3,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void proxy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        proxy *_t = static_cast<proxy *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateStep((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 1: _t->stateChanged((*reinterpret_cast< QTimeLine::State(*)>(_a[1]))); break;
        case 2: _t->zoomIn(); break;
        case 3: _t->zoomOut(); break;
        default: ;
        }
    }
}

const QMetaObject proxy::staticMetaObject = {
    { &QGraphicsProxyWidget::staticMetaObject, qt_meta_stringdata_proxy.data,
      qt_meta_data_proxy,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *proxy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *proxy::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_proxy.stringdata0))
        return static_cast<void*>(const_cast< proxy*>(this));
    return QGraphicsProxyWidget::qt_metacast(_clname);
}

int proxy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsProxyWidget::qt_metacall(_c, _id, _a);
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
