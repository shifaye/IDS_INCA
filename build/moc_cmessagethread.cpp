/****************************************************************************
** Meta object code from reading C++ file 'cmessagethread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/cmessagethread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cmessagethread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CMessageThread_t {
    QByteArrayData data[15];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CMessageThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CMessageThread_t qt_meta_stringdata_CMessageThread = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CMessageThread"
QT_MOC_LITERAL(1, 15, 17), // "ShowStatusMessage"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 3), // "str"
QT_MOC_LITERAL(4, 38, 15), // "ShowLogFileName"
QT_MOC_LITERAL(5, 54, 15), // "MessageReceived"
QT_MOC_LITERAL(6, 70, 7), // "MESSAGE"
QT_MOC_LITERAL(7, 78, 18), // "UpdateRecordStatus"
QT_MOC_LITERAL(8, 97, 13), // "RECORD_STATUS"
QT_MOC_LITERAL(9, 111, 11), // "LogFinished"
QT_MOC_LITERAL(10, 123, 18), // "OnUpdateRecordList"
QT_MOC_LITERAL(11, 142, 14), // "strChannelName"
QT_MOC_LITERAL(12, 157, 6), // "record"
QT_MOC_LITERAL(13, 164, 14), // "OnSwitchRecord"
QT_MOC_LITERAL(14, 179, 25) // "OnTimerUpdateRecordStatus"

    },
    "CMessageThread\0ShowStatusMessage\0\0str\0"
    "ShowLogFileName\0MessageReceived\0MESSAGE\0"
    "UpdateRecordStatus\0RECORD_STATUS\0"
    "LogFinished\0OnUpdateRecordList\0"
    "strChannelName\0record\0OnSwitchRecord\0"
    "OnTimerUpdateRecordStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMessageThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       5,    1,   65,    2, 0x06 /* Public */,
       7,    1,   68,    2, 0x06 /* Public */,
       9,    0,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    2,   72,    2, 0x0a /* Public */,
      13,    1,   77,    2, 0x0a /* Public */,
      13,    2,   80,    2, 0x0a /* Public */,
      14,    0,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   11,   12,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    2,    2,
    QMetaType::Void,

       0        // eod
};

void CMessageThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CMessageThread *_t = static_cast<CMessageThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ShowStatusMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->ShowLogFileName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->MessageReceived((*reinterpret_cast< MESSAGE(*)>(_a[1]))); break;
        case 3: _t->UpdateRecordStatus((*reinterpret_cast< RECORD_STATUS(*)>(_a[1]))); break;
        case 4: _t->LogFinished(); break;
        case 5: _t->OnUpdateRecordList((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->OnSwitchRecord((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->OnSwitchRecord((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->OnTimerUpdateRecordStatus(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MESSAGE >(); break;
            }
            break;
        case 3:
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
            typedef void (CMessageThread::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CMessageThread::ShowStatusMessage)) {
                *result = 0;
            }
        }
        {
            typedef void (CMessageThread::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CMessageThread::ShowLogFileName)) {
                *result = 1;
            }
        }
        {
            typedef void (CMessageThread::*_t)(MESSAGE );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CMessageThread::MessageReceived)) {
                *result = 2;
            }
        }
        {
            typedef void (CMessageThread::*_t)(RECORD_STATUS );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CMessageThread::UpdateRecordStatus)) {
                *result = 3;
            }
        }
        {
            typedef void (CMessageThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CMessageThread::LogFinished)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject CMessageThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CMessageThread.data,
      qt_meta_data_CMessageThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CMessageThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMessageThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CMessageThread.stringdata0))
        return static_cast<void*>(const_cast< CMessageThread*>(this));
    return QObject::qt_metacast(_clname);
}

int CMessageThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CMessageThread::ShowStatusMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CMessageThread::ShowLogFileName(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CMessageThread::MessageReceived(MESSAGE _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CMessageThread::UpdateRecordStatus(RECORD_STATUS _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CMessageThread::LogFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
