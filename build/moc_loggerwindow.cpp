/****************************************************************************
** Meta object code from reading C++ file 'loggerwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/loggerwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loggerwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LoggerWindow_t {
    QByteArrayData data[24];
    char stringdata0[283];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoggerWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoggerWindow_t qt_meta_stringdata_LoggerWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "LoggerWindow"
QT_MOC_LITERAL(1, 13, 8), // "sendData"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 6), // "status"
QT_MOC_LITERAL(4, 30, 16), // "UpdateRecordList"
QT_MOC_LITERAL(5, 47, 3), // "str"
QT_MOC_LITERAL(6, 51, 6), // "record"
QT_MOC_LITERAL(7, 58, 12), // "SwitchRecord"
QT_MOC_LITERAL(8, 71, 18), // "OnTimerUpdateTable"
QT_MOC_LITERAL(9, 90, 13), // "OnStartRecord"
QT_MOC_LITERAL(10, 104, 12), // "OnStopRecord"
QT_MOC_LITERAL(11, 117, 13), // "OnLogFinished"
QT_MOC_LITERAL(12, 131, 11), // "OnSelectAll"
QT_MOC_LITERAL(13, 143, 14), // "OnInvertSelect"
QT_MOC_LITERAL(14, 158, 19), // "OnShowStatusMessage"
QT_MOC_LITERAL(15, 178, 3), // "msg"
QT_MOC_LITERAL(16, 182, 18), // "OnTableItemClicked"
QT_MOC_LITERAL(17, 201, 1), // "x"
QT_MOC_LITERAL(18, 203, 1), // "y"
QT_MOC_LITERAL(19, 205, 17), // "OnShowLogFileName"
QT_MOC_LITERAL(20, 223, 11), // "strFileName"
QT_MOC_LITERAL(21, 235, 20), // "OnUpdateRecordStatus"
QT_MOC_LITERAL(22, 256, 13), // "RECORD_STATUS"
QT_MOC_LITERAL(23, 270, 12) // "recordStatus"

    },
    "LoggerWindow\0sendData\0\0status\0"
    "UpdateRecordList\0str\0record\0SwitchRecord\0"
    "OnTimerUpdateTable\0OnStartRecord\0"
    "OnStopRecord\0OnLogFinished\0OnSelectAll\0"
    "OnInvertSelect\0OnShowStatusMessage\0"
    "msg\0OnTableItemClicked\0x\0y\0OnShowLogFileName\0"
    "strFileName\0OnUpdateRecordStatus\0"
    "RECORD_STATUS\0recordStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoggerWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    2,   87,    2, 0x06 /* Public */,
       7,    1,   92,    2, 0x06 /* Public */,
       7,    2,   95,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,  100,    2, 0x0a /* Public */,
       9,    0,  101,    2, 0x0a /* Public */,
      10,    0,  102,    2, 0x0a /* Public */,
      11,    0,  103,    2, 0x0a /* Public */,
      12,    0,  104,    2, 0x0a /* Public */,
      13,    0,  105,    2, 0x0a /* Public */,
      14,    1,  106,    2, 0x0a /* Public */,
      16,    2,  109,    2, 0x0a /* Public */,
      19,    1,  114,    2, 0x0a /* Public */,
      21,    1,  117,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    5,    6,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   18,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, 0x80000000 | 22,   23,

       0        // eod
};

void LoggerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoggerWindow *_t = static_cast<LoggerWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendData((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->UpdateRecordList((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->SwitchRecord((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->SwitchRecord((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->OnTimerUpdateTable(); break;
        case 5: _t->OnStartRecord(); break;
        case 6: _t->OnStopRecord(); break;
        case 7: _t->OnLogFinished(); break;
        case 8: _t->OnSelectAll(); break;
        case 9: _t->OnInvertSelect(); break;
        case 10: _t->OnShowStatusMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->OnTableItemClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->OnShowLogFileName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->OnUpdateRecordStatus((*reinterpret_cast< RECORD_STATUS(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< RECORD_STATUS >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LoggerWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoggerWindow::sendData)) {
                *result = 0;
            }
        }
        {
            typedef void (LoggerWindow::*_t)(QString , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoggerWindow::UpdateRecordList)) {
                *result = 1;
            }
        }
        {
            typedef void (LoggerWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoggerWindow::SwitchRecord)) {
                *result = 2;
            }
        }
        {
            typedef void (LoggerWindow::*_t)(bool , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoggerWindow::SwitchRecord)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject LoggerWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_LoggerWindow.data,
      qt_meta_data_LoggerWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LoggerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoggerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LoggerWindow.stringdata0))
        return static_cast<void*>(const_cast< LoggerWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int LoggerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void LoggerWindow::sendData(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LoggerWindow::UpdateRecordList(QString _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LoggerWindow::SwitchRecord(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LoggerWindow::SwitchRecord(bool _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
