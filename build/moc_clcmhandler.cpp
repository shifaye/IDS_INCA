/****************************************************************************
** Meta object code from reading C++ file 'clcmhandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/clcmhandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clcmhandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CLCMHandler_t {
    QByteArrayData data[22];
    char stringdata0[398];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CLCMHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CLCMHandler_t qt_meta_stringdata_CLCMHandler = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CLCMHandler"
QT_MOC_LITERAL(1, 12, 14), // "NewVehiclePose"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "Q_VEHICLE_POSE"
QT_MOC_LITERAL(4, 43, 20), // "NewExecuteTrajectory"
QT_MOC_LITERAL(5, 64, 20), // "Q_EXECUTE_TRAJECTORY"
QT_MOC_LITERAL(6, 85, 17), // "NewVcuVehicleInfo"
QT_MOC_LITERAL(7, 103, 18), // "Q_VCU_VEHICLE_INFO"
QT_MOC_LITERAL(8, 122, 20), // "NewMobileyeLaneLines"
QT_MOC_LITERAL(9, 143, 16), // "Q_MOBILEYE_LINES"
QT_MOC_LITERAL(10, 160, 19), // "NewTrackedObstacles"
QT_MOC_LITERAL(11, 180, 19), // "Q_TRACKED_OBSTACLES"
QT_MOC_LITERAL(12, 200, 18), // "NewIpc2devVelocity"
QT_MOC_LITERAL(13, 219, 18), // "Q_IPC2DEV_VELOCITY"
QT_MOC_LITERAL(14, 238, 22), // "NewExecuteBehaviorPlan"
QT_MOC_LITERAL(15, 261, 23), // "Q_EXECUTE_BEHAVIOR_PLAN"
QT_MOC_LITERAL(16, 285, 16), // "NewPerceptionTsr"
QT_MOC_LITERAL(17, 302, 16), // "Q_PERCEPTION_TSR"
QT_MOC_LITERAL(18, 319, 17), // "NewVelodynePoints"
QT_MOC_LITERAL(19, 337, 17), // "Q_VELODYNE_POINTS"
QT_MOC_LITERAL(20, 355, 19), // "NewPerceptionedObjs"
QT_MOC_LITERAL(21, 375, 22) // "Q_PERCEPTIONED_OBJECTS"

    },
    "CLCMHandler\0NewVehiclePose\0\0Q_VEHICLE_POSE\0"
    "NewExecuteTrajectory\0Q_EXECUTE_TRAJECTORY\0"
    "NewVcuVehicleInfo\0Q_VCU_VEHICLE_INFO\0"
    "NewMobileyeLaneLines\0Q_MOBILEYE_LINES\0"
    "NewTrackedObstacles\0Q_TRACKED_OBSTACLES\0"
    "NewIpc2devVelocity\0Q_IPC2DEV_VELOCITY\0"
    "NewExecuteBehaviorPlan\0Q_EXECUTE_BEHAVIOR_PLAN\0"
    "NewPerceptionTsr\0Q_PERCEPTION_TSR\0"
    "NewVelodynePoints\0Q_VELODYNE_POINTS\0"
    "NewPerceptionedObjs\0Q_PERCEPTIONED_OBJECTS"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CLCMHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       6,    1,   70,    2, 0x06 /* Public */,
       8,    1,   73,    2, 0x06 /* Public */,
      10,    1,   76,    2, 0x06 /* Public */,
      12,    1,   79,    2, 0x06 /* Public */,
      14,    1,   82,    2, 0x06 /* Public */,
      16,    1,   85,    2, 0x06 /* Public */,
      18,    1,   88,    2, 0x06 /* Public */,
      20,    1,   91,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void, 0x80000000 | 19,    2,
    QMetaType::Void, 0x80000000 | 21,    2,

       0        // eod
};

void CLCMHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CLCMHandler *_t = static_cast<CLCMHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NewVehiclePose((*reinterpret_cast< Q_VEHICLE_POSE(*)>(_a[1]))); break;
        case 1: _t->NewExecuteTrajectory((*reinterpret_cast< Q_EXECUTE_TRAJECTORY(*)>(_a[1]))); break;
        case 2: _t->NewVcuVehicleInfo((*reinterpret_cast< Q_VCU_VEHICLE_INFO(*)>(_a[1]))); break;
        case 3: _t->NewMobileyeLaneLines((*reinterpret_cast< Q_MOBILEYE_LINES(*)>(_a[1]))); break;
        case 4: _t->NewTrackedObstacles((*reinterpret_cast< Q_TRACKED_OBSTACLES(*)>(_a[1]))); break;
        case 5: _t->NewIpc2devVelocity((*reinterpret_cast< Q_IPC2DEV_VELOCITY(*)>(_a[1]))); break;
        case 6: _t->NewExecuteBehaviorPlan((*reinterpret_cast< Q_EXECUTE_BEHAVIOR_PLAN(*)>(_a[1]))); break;
        case 7: _t->NewPerceptionTsr((*reinterpret_cast< Q_PERCEPTION_TSR(*)>(_a[1]))); break;
        case 8: _t->NewVelodynePoints((*reinterpret_cast< Q_VELODYNE_POINTS(*)>(_a[1]))); break;
        case 9: _t->NewPerceptionedObjs((*reinterpret_cast< Q_PERCEPTIONED_OBJECTS(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Q_VEHICLE_POSE >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Q_EXECUTE_TRAJECTORY >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Q_VCU_VEHICLE_INFO >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Q_MOBILEYE_LINES >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Q_TRACKED_OBSTACLES >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Q_IPC2DEV_VELOCITY >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Q_EXECUTE_BEHAVIOR_PLAN >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Q_PERCEPTION_TSR >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Q_VELODYNE_POINTS >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Q_PERCEPTIONED_OBJECTS >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CLCMHandler::*_t)(Q_VEHICLE_POSE );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLCMHandler::NewVehiclePose)) {
                *result = 0;
            }
        }
        {
            typedef void (CLCMHandler::*_t)(Q_EXECUTE_TRAJECTORY );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLCMHandler::NewExecuteTrajectory)) {
                *result = 1;
            }
        }
        {
            typedef void (CLCMHandler::*_t)(Q_VCU_VEHICLE_INFO );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLCMHandler::NewVcuVehicleInfo)) {
                *result = 2;
            }
        }
        {
            typedef void (CLCMHandler::*_t)(Q_MOBILEYE_LINES );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLCMHandler::NewMobileyeLaneLines)) {
                *result = 3;
            }
        }
        {
            typedef void (CLCMHandler::*_t)(Q_TRACKED_OBSTACLES );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLCMHandler::NewTrackedObstacles)) {
                *result = 4;
            }
        }
        {
            typedef void (CLCMHandler::*_t)(Q_IPC2DEV_VELOCITY );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLCMHandler::NewIpc2devVelocity)) {
                *result = 5;
            }
        }
        {
            typedef void (CLCMHandler::*_t)(Q_EXECUTE_BEHAVIOR_PLAN );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLCMHandler::NewExecuteBehaviorPlan)) {
                *result = 6;
            }
        }
        {
            typedef void (CLCMHandler::*_t)(Q_PERCEPTION_TSR );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLCMHandler::NewPerceptionTsr)) {
                *result = 7;
            }
        }
        {
            typedef void (CLCMHandler::*_t)(Q_VELODYNE_POINTS );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLCMHandler::NewVelodynePoints)) {
                *result = 8;
            }
        }
        {
            typedef void (CLCMHandler::*_t)(Q_PERCEPTIONED_OBJECTS );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLCMHandler::NewPerceptionedObjs)) {
                *result = 9;
            }
        }
    }
}

const QMetaObject CLCMHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CLCMHandler.data,
      qt_meta_data_CLCMHandler,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CLCMHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CLCMHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CLCMHandler.stringdata0))
        return static_cast<void*>(const_cast< CLCMHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int CLCMHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void CLCMHandler::NewVehiclePose(Q_VEHICLE_POSE _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CLCMHandler::NewExecuteTrajectory(Q_EXECUTE_TRAJECTORY _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CLCMHandler::NewVcuVehicleInfo(Q_VCU_VEHICLE_INFO _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CLCMHandler::NewMobileyeLaneLines(Q_MOBILEYE_LINES _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CLCMHandler::NewTrackedObstacles(Q_TRACKED_OBSTACLES _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CLCMHandler::NewIpc2devVelocity(Q_IPC2DEV_VELOCITY _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CLCMHandler::NewExecuteBehaviorPlan(Q_EXECUTE_BEHAVIOR_PLAN _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CLCMHandler::NewPerceptionTsr(Q_PERCEPTION_TSR _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void CLCMHandler::NewVelodynePoints(Q_VELODYNE_POINTS _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void CLCMHandler::NewPerceptionedObjs(Q_PERCEPTIONED_OBJECTS _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
