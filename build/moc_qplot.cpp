/****************************************************************************
** Meta object code from reading C++ file 'qplot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/qplot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qplot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QPlot_t {
    QByteArrayData data[14];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QPlot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QPlot_t qt_meta_stringdata_QPlot = {
    {
QT_MOC_LITERAL(0, 0, 5), // "QPlot"
QT_MOC_LITERAL(1, 6, 13), // "ShowStatusMsg"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 3), // "msg"
QT_MOC_LITERAL(4, 25, 12), // "OnMouseWheel"
QT_MOC_LITERAL(5, 38, 12), // "QWheelEvent*"
QT_MOC_LITERAL(6, 51, 5), // "event"
QT_MOC_LITERAL(7, 57, 15), // "OnReplotTimeOut"
QT_MOC_LITERAL(8, 73, 13), // "OnAxisClicked"
QT_MOC_LITERAL(9, 87, 8), // "QCPAxis*"
QT_MOC_LITERAL(10, 96, 4), // "axis"
QT_MOC_LITERAL(11, 101, 23), // "QCPAxis::SelectablePart"
QT_MOC_LITERAL(12, 125, 4), // "part"
QT_MOC_LITERAL(13, 130, 12) // "QMouseEvent*"

    },
    "QPlot\0ShowStatusMsg\0\0msg\0OnMouseWheel\0"
    "QWheelEvent*\0event\0OnReplotTimeOut\0"
    "OnAxisClicked\0QCPAxis*\0axis\0"
    "QCPAxis::SelectablePart\0part\0QMouseEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QPlot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x0a /* Public */,
       7,    0,   40,    2, 0x0a /* Public */,
       8,    3,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 11, 0x80000000 | 13,   10,   12,    6,

       0        // eod
};

void QPlot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QPlot *_t = static_cast<QPlot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ShowStatusMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->OnMouseWheel((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 2: _t->OnReplotTimeOut(); break;
        case 3: _t->OnAxisClicked((*reinterpret_cast< QCPAxis*(*)>(_a[1])),(*reinterpret_cast< QCPAxis::SelectablePart(*)>(_a[2])),(*reinterpret_cast< QMouseEvent*(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCPAxis* >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCPAxis::SelectablePart >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QPlot::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QPlot::ShowStatusMsg)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QPlot::staticMetaObject = {
    { &QCustomPlot::staticMetaObject, qt_meta_stringdata_QPlot.data,
      qt_meta_data_QPlot,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QPlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPlot::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QPlot.stringdata0))
        return static_cast<void*>(const_cast< QPlot*>(this));
    return QCustomPlot::qt_metacast(_clname);
}

int QPlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCustomPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QPlot::ShowStatusMsg(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
