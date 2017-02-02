/****************************************************************************
** Meta object code from reading C++ file 'systemwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/systemwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'systemwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SystemWindow_t {
    QByteArrayData data[10];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SystemWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SystemWindow_t qt_meta_stringdata_SystemWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SystemWindow"
QT_MOC_LITERAL(1, 13, 8), // "sendData"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 6), // "status"
QT_MOC_LITERAL(4, 30, 14), // "showMainWindow"
QT_MOC_LITERAL(5, 45, 16), // "showLoggerWindow"
QT_MOC_LITERAL(6, 62, 21), // "showCalibrationWindow"
QT_MOC_LITERAL(7, 84, 32), // "on_pushButton_IP_Capture_clicked"
QT_MOC_LITERAL(8, 117, 15), // "OnMonitorUpdate"
QT_MOC_LITERAL(9, 133, 14) // "OnCheckProcess"

    },
    "SystemWindow\0sendData\0\0status\0"
    "showMainWindow\0showLoggerWindow\0"
    "showCalibrationWindow\0"
    "on_pushButton_IP_Capture_clicked\0"
    "OnMonitorUpdate\0OnCheckProcess"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SystemWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    0,   52,    2, 0x06 /* Public */,
       5,    0,   53,    2, 0x06 /* Public */,
       6,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SystemWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SystemWindow *_t = static_cast<SystemWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendData((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->showMainWindow(); break;
        case 2: _t->showLoggerWindow(); break;
        case 3: _t->showCalibrationWindow(); break;
        case 4: _t->on_pushButton_IP_Capture_clicked(); break;
        case 5: _t->OnMonitorUpdate(); break;
        case 6: _t->OnCheckProcess(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SystemWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SystemWindow::sendData)) {
                *result = 0;
            }
        }
        {
            typedef void (SystemWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SystemWindow::showMainWindow)) {
                *result = 1;
            }
        }
        {
            typedef void (SystemWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SystemWindow::showLoggerWindow)) {
                *result = 2;
            }
        }
        {
            typedef void (SystemWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SystemWindow::showCalibrationWindow)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject SystemWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SystemWindow.data,
      qt_meta_data_SystemWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SystemWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SystemWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SystemWindow.stringdata0))
        return static_cast<void*>(const_cast< SystemWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SystemWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void SystemWindow::sendData(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SystemWindow::showMainWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void SystemWindow::showLoggerWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void SystemWindow::showCalibrationWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
