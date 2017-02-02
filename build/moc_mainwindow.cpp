/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[88];
    char stringdata0[2105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 18), // "Send_Module_Status"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "int*"
QT_MOC_LITERAL(4, 36, 13), // "module_status"
QT_MOC_LITERAL(5, 50, 15), // "OnShowStatusMsg"
QT_MOC_LITERAL(6, 66, 3), // "msg"
QT_MOC_LITERAL(7, 70, 9), // "OnTimeOut"
QT_MOC_LITERAL(8, 80, 16), // "OnRefreshTimeOut"
QT_MOC_LITERAL(9, 97, 23), // "OnScreenShotTextTimeOut"
QT_MOC_LITERAL(10, 121, 16), // "OnNewVehiclePose"
QT_MOC_LITERAL(11, 138, 14), // "Q_VEHICLE_POSE"
QT_MOC_LITERAL(12, 153, 11), // "vehiclePose"
QT_MOC_LITERAL(13, 165, 19), // "OnNewVcuVehicleInfo"
QT_MOC_LITERAL(14, 185, 18), // "Q_VCU_VEHICLE_INFO"
QT_MOC_LITERAL(15, 204, 14), // "vcuVehicleInfo"
QT_MOC_LITERAL(16, 219, 22), // "OnNewExecuteTrajectory"
QT_MOC_LITERAL(17, 242, 20), // "Q_EXECUTE_TRAJECTORY"
QT_MOC_LITERAL(18, 263, 17), // "executeTrajectory"
QT_MOC_LITERAL(19, 281, 18), // "OnNewMobileyeLines"
QT_MOC_LITERAL(20, 300, 16), // "Q_MOBILEYE_LINES"
QT_MOC_LITERAL(21, 317, 13), // "mobileyeLines"
QT_MOC_LITERAL(22, 331, 21), // "OnNewTrackedObstacles"
QT_MOC_LITERAL(23, 353, 19), // "Q_TRACKED_OBSTACLES"
QT_MOC_LITERAL(24, 373, 17), // "tracked_obstacles"
QT_MOC_LITERAL(25, 391, 20), // "OnNewIpc2devVelocity"
QT_MOC_LITERAL(26, 412, 18), // "Q_IPC2DEV_VELOCITY"
QT_MOC_LITERAL(27, 431, 16), // "ipc2dev_velocity"
QT_MOC_LITERAL(28, 448, 24), // "OnNewExecuteBehaviorPlan"
QT_MOC_LITERAL(29, 473, 23), // "Q_EXECUTE_BEHAVIOR_PLAN"
QT_MOC_LITERAL(30, 497, 21), // "execute_behavior_plan"
QT_MOC_LITERAL(31, 519, 18), // "OnNewPerceptionTsr"
QT_MOC_LITERAL(32, 538, 16), // "Q_PERCEPTION_TSR"
QT_MOC_LITERAL(33, 555, 14), // "perception_tsr"
QT_MOC_LITERAL(34, 570, 19), // "OnNewVelodynePoints"
QT_MOC_LITERAL(35, 590, 17), // "Q_VELODYNE_POINTS"
QT_MOC_LITERAL(36, 608, 15), // "velodyne_points"
QT_MOC_LITERAL(37, 624, 19), // "OnNewPerceptionObjs"
QT_MOC_LITERAL(38, 644, 22), // "Q_PERCEPTIONED_OBJECTS"
QT_MOC_LITERAL(39, 667, 18), // "perception_objects"
QT_MOC_LITERAL(40, 686, 16), // "OnshowMainWindow"
QT_MOC_LITERAL(41, 703, 11), // "receiveData"
QT_MOC_LITERAL(42, 715, 6), // "status"
QT_MOC_LITERAL(43, 722, 22), // "on_recv_log_win_status"
QT_MOC_LITERAL(44, 745, 23), // "on_recv_cali_win_status"
QT_MOC_LITERAL(45, 769, 29), // "on_pushButton_loadsys_clicked"
QT_MOC_LITERAL(46, 799, 32), // "on_pushButton_loadgpsins_toggled"
QT_MOC_LITERAL(47, 832, 7), // "checked"
QT_MOC_LITERAL(48, 840, 40), // "on_comboBox_chart2_x_currentI..."
QT_MOC_LITERAL(49, 881, 5), // "index"
QT_MOC_LITERAL(50, 887, 40), // "on_comboBox_chart1_x_currentI..."
QT_MOC_LITERAL(51, 928, 40), // "on_comboBox_chart1_y_currentI..."
QT_MOC_LITERAL(52, 969, 40), // "on_comboBox_chart2_y_currentI..."
QT_MOC_LITERAL(53, 1010, 27), // "on_chart1_MultiAxis_toggled"
QT_MOC_LITERAL(54, 1038, 28), // "on_pushButton_pause1_toggled"
QT_MOC_LITERAL(55, 1067, 37), // "on_pushButton_analyzelanekeep..."
QT_MOC_LITERAL(56, 1105, 33), // "on_pushButton_data_logger_cli..."
QT_MOC_LITERAL(57, 1139, 32), // "on_pushButton_clear_data_clicked"
QT_MOC_LITERAL(58, 1172, 33), // "on_pushButton_datalibrary_cli..."
QT_MOC_LITERAL(59, 1206, 33), // "on_pushButton_datastatics_cli..."
QT_MOC_LITERAL(60, 1240, 29), // "on_pushButton_loadvcu_toggled"
QT_MOC_LITERAL(61, 1270, 30), // "on_pushButton_resetall_clicked"
QT_MOC_LITERAL(62, 1301, 32), // "on_pushButton_analyzeACC_toggled"
QT_MOC_LITERAL(63, 1334, 28), // "on_pushButton_pause2_toggled"
QT_MOC_LITERAL(64, 1363, 32), // "on_pushButton_analyzeAEB_toggled"
QT_MOC_LITERAL(65, 1396, 39), // "on_pushButton_analyzeautochan..."
QT_MOC_LITERAL(66, 1436, 39), // "on_pushButton_analyzeovertaki..."
QT_MOC_LITERAL(67, 1476, 41), // "on_pushButton_analyzeaccelera..."
QT_MOC_LITERAL(68, 1518, 29), // "on_pushButton_loadcam_toggled"
QT_MOC_LITERAL(69, 1548, 30), // "on_pushButton_loadlane_toggled"
QT_MOC_LITERAL(70, 1579, 29), // "on_pushButton_loadtsr_toggled"
QT_MOC_LITERAL(71, 1609, 33), // "on_pushButton_calibration_cli..."
QT_MOC_LITERAL(72, 1643, 26), // "on_pushButton_lane_toggled"
QT_MOC_LITERAL(73, 1670, 26), // "on_DebugOutput_textChanged"
QT_MOC_LITERAL(74, 1697, 30), // "on_visible_tablewidget_toggled"
QT_MOC_LITERAL(75, 1728, 31), // "on_visible_Debug_window_toggled"
QT_MOC_LITERAL(76, 1760, 27), // "on_pushButton_meobj_toggled"
QT_MOC_LITERAL(77, 1788, 30), // "on_pushButton_canprocy_toggled"
QT_MOC_LITERAL(78, 1819, 25), // "on_pushButton_vcu_toggled"
QT_MOC_LITERAL(79, 1845, 25), // "on_pushButton_ins_toggled"
QT_MOC_LITERAL(80, 1871, 25), // "on_pushButton_idc_toggled"
QT_MOC_LITERAL(81, 1897, 26), // "on_pushButton_ibeo_toggled"
QT_MOC_LITERAL(82, 1924, 30), // "on_pushButton_velodyne_toggled"
QT_MOC_LITERAL(83, 1955, 25), // "on_pushButton_tsr_toggled"
QT_MOC_LITERAL(84, 1981, 25), // "on_pushButton_esr_toggled"
QT_MOC_LITERAL(85, 2007, 26), // "on_pushButton_rsds_toggled"
QT_MOC_LITERAL(86, 2034, 37), // "on_pushButton_detail_ethernet..."
QT_MOC_LITERAL(87, 2072, 32) // "on_pushButton_detail_can_toggled"

    },
    "MainWindow\0Send_Module_Status\0\0int*\0"
    "module_status\0OnShowStatusMsg\0msg\0"
    "OnTimeOut\0OnRefreshTimeOut\0"
    "OnScreenShotTextTimeOut\0OnNewVehiclePose\0"
    "Q_VEHICLE_POSE\0vehiclePose\0"
    "OnNewVcuVehicleInfo\0Q_VCU_VEHICLE_INFO\0"
    "vcuVehicleInfo\0OnNewExecuteTrajectory\0"
    "Q_EXECUTE_TRAJECTORY\0executeTrajectory\0"
    "OnNewMobileyeLines\0Q_MOBILEYE_LINES\0"
    "mobileyeLines\0OnNewTrackedObstacles\0"
    "Q_TRACKED_OBSTACLES\0tracked_obstacles\0"
    "OnNewIpc2devVelocity\0Q_IPC2DEV_VELOCITY\0"
    "ipc2dev_velocity\0OnNewExecuteBehaviorPlan\0"
    "Q_EXECUTE_BEHAVIOR_PLAN\0execute_behavior_plan\0"
    "OnNewPerceptionTsr\0Q_PERCEPTION_TSR\0"
    "perception_tsr\0OnNewVelodynePoints\0"
    "Q_VELODYNE_POINTS\0velodyne_points\0"
    "OnNewPerceptionObjs\0Q_PERCEPTIONED_OBJECTS\0"
    "perception_objects\0OnshowMainWindow\0"
    "receiveData\0status\0on_recv_log_win_status\0"
    "on_recv_cali_win_status\0"
    "on_pushButton_loadsys_clicked\0"
    "on_pushButton_loadgpsins_toggled\0"
    "checked\0on_comboBox_chart2_x_currentIndexChanged\0"
    "index\0on_comboBox_chart1_x_currentIndexChanged\0"
    "on_comboBox_chart1_y_currentIndexChanged\0"
    "on_comboBox_chart2_y_currentIndexChanged\0"
    "on_chart1_MultiAxis_toggled\0"
    "on_pushButton_pause1_toggled\0"
    "on_pushButton_analyzelanekeep_toggled\0"
    "on_pushButton_data_logger_clicked\0"
    "on_pushButton_clear_data_clicked\0"
    "on_pushButton_datalibrary_clicked\0"
    "on_pushButton_datastatics_clicked\0"
    "on_pushButton_loadvcu_toggled\0"
    "on_pushButton_resetall_clicked\0"
    "on_pushButton_analyzeACC_toggled\0"
    "on_pushButton_pause2_toggled\0"
    "on_pushButton_analyzeAEB_toggled\0"
    "on_pushButton_analyzeautochange_toggled\0"
    "on_pushButton_analyzeovertaking_toggled\0"
    "on_pushButton_analyzeacceleration_toggled\0"
    "on_pushButton_loadcam_toggled\0"
    "on_pushButton_loadlane_toggled\0"
    "on_pushButton_loadtsr_toggled\0"
    "on_pushButton_calibration_clicked\0"
    "on_pushButton_lane_toggled\0"
    "on_DebugOutput_textChanged\0"
    "on_visible_tablewidget_toggled\0"
    "on_visible_Debug_window_toggled\0"
    "on_pushButton_meobj_toggled\0"
    "on_pushButton_canprocy_toggled\0"
    "on_pushButton_vcu_toggled\0"
    "on_pushButton_ins_toggled\0"
    "on_pushButton_idc_toggled\0"
    "on_pushButton_ibeo_toggled\0"
    "on_pushButton_velodyne_toggled\0"
    "on_pushButton_tsr_toggled\0"
    "on_pushButton_esr_toggled\0"
    "on_pushButton_rsds_toggled\0"
    "on_pushButton_detail_ethernet_toggled\0"
    "on_pushButton_detail_can_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      60,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  314,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,  317,    2, 0x0a /* Public */,
       7,    0,  320,    2, 0x0a /* Public */,
       8,    0,  321,    2, 0x0a /* Public */,
       9,    0,  322,    2, 0x0a /* Public */,
      10,    1,  323,    2, 0x0a /* Public */,
      13,    1,  326,    2, 0x0a /* Public */,
      16,    1,  329,    2, 0x0a /* Public */,
      19,    1,  332,    2, 0x0a /* Public */,
      22,    1,  335,    2, 0x0a /* Public */,
      25,    1,  338,    2, 0x0a /* Public */,
      28,    1,  341,    2, 0x0a /* Public */,
      31,    1,  344,    2, 0x0a /* Public */,
      34,    1,  347,    2, 0x0a /* Public */,
      37,    1,  350,    2, 0x0a /* Public */,
      40,    0,  353,    2, 0x0a /* Public */,
      41,    1,  354,    2, 0x08 /* Private */,
      43,    1,  357,    2, 0x08 /* Private */,
      44,    1,  360,    2, 0x08 /* Private */,
      45,    0,  363,    2, 0x08 /* Private */,
      46,    1,  364,    2, 0x08 /* Private */,
      48,    1,  367,    2, 0x08 /* Private */,
      50,    1,  370,    2, 0x08 /* Private */,
      51,    1,  373,    2, 0x08 /* Private */,
      52,    1,  376,    2, 0x08 /* Private */,
      53,    1,  379,    2, 0x08 /* Private */,
      54,    1,  382,    2, 0x08 /* Private */,
      55,    1,  385,    2, 0x08 /* Private */,
      56,    0,  388,    2, 0x08 /* Private */,
      57,    0,  389,    2, 0x08 /* Private */,
      58,    0,  390,    2, 0x08 /* Private */,
      59,    0,  391,    2, 0x08 /* Private */,
      60,    1,  392,    2, 0x08 /* Private */,
      61,    0,  395,    2, 0x08 /* Private */,
      62,    1,  396,    2, 0x08 /* Private */,
      63,    1,  399,    2, 0x08 /* Private */,
      64,    1,  402,    2, 0x08 /* Private */,
      65,    1,  405,    2, 0x08 /* Private */,
      66,    1,  408,    2, 0x08 /* Private */,
      67,    1,  411,    2, 0x08 /* Private */,
      68,    1,  414,    2, 0x08 /* Private */,
      69,    1,  417,    2, 0x08 /* Private */,
      70,    1,  420,    2, 0x08 /* Private */,
      71,    0,  423,    2, 0x08 /* Private */,
      72,    1,  424,    2, 0x08 /* Private */,
      73,    0,  427,    2, 0x08 /* Private */,
      74,    1,  428,    2, 0x08 /* Private */,
      75,    1,  431,    2, 0x08 /* Private */,
      76,    1,  434,    2, 0x08 /* Private */,
      77,    1,  437,    2, 0x08 /* Private */,
      78,    1,  440,    2, 0x08 /* Private */,
      79,    1,  443,    2, 0x08 /* Private */,
      80,    1,  446,    2, 0x08 /* Private */,
      81,    1,  449,    2, 0x08 /* Private */,
      82,    1,  452,    2, 0x08 /* Private */,
      83,    1,  455,    2, 0x08 /* Private */,
      84,    1,  458,    2, 0x08 /* Private */,
      85,    1,  461,    2, 0x08 /* Private */,
      86,    1,  464,    2, 0x08 /* Private */,
      87,    1,  467,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void, 0x80000000 | 29,   30,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void, 0x80000000 | 35,   36,
    QMetaType::Void, 0x80000000 | 38,   39,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   42,
    QMetaType::Void, QMetaType::Bool,   42,
    QMetaType::Void, QMetaType::Bool,   42,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Int,   49,
    QMetaType::Void, QMetaType::Int,   49,
    QMetaType::Void, QMetaType::Int,   49,
    QMetaType::Void, QMetaType::Int,   49,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   47,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Send_Module_Status((*reinterpret_cast< int*(*)>(_a[1]))); break;
        case 1: _t->OnShowStatusMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->OnTimeOut(); break;
        case 3: _t->OnRefreshTimeOut(); break;
        case 4: _t->OnScreenShotTextTimeOut(); break;
        case 5: _t->OnNewVehiclePose((*reinterpret_cast< Q_VEHICLE_POSE(*)>(_a[1]))); break;
        case 6: _t->OnNewVcuVehicleInfo((*reinterpret_cast< Q_VCU_VEHICLE_INFO(*)>(_a[1]))); break;
        case 7: _t->OnNewExecuteTrajectory((*reinterpret_cast< Q_EXECUTE_TRAJECTORY(*)>(_a[1]))); break;
        case 8: _t->OnNewMobileyeLines((*reinterpret_cast< Q_MOBILEYE_LINES(*)>(_a[1]))); break;
        case 9: _t->OnNewTrackedObstacles((*reinterpret_cast< Q_TRACKED_OBSTACLES(*)>(_a[1]))); break;
        case 10: _t->OnNewIpc2devVelocity((*reinterpret_cast< Q_IPC2DEV_VELOCITY(*)>(_a[1]))); break;
        case 11: _t->OnNewExecuteBehaviorPlan((*reinterpret_cast< Q_EXECUTE_BEHAVIOR_PLAN(*)>(_a[1]))); break;
        case 12: _t->OnNewPerceptionTsr((*reinterpret_cast< Q_PERCEPTION_TSR(*)>(_a[1]))); break;
        case 13: _t->OnNewVelodynePoints((*reinterpret_cast< Q_VELODYNE_POINTS(*)>(_a[1]))); break;
        case 14: _t->OnNewPerceptionObjs((*reinterpret_cast< Q_PERCEPTIONED_OBJECTS(*)>(_a[1]))); break;
        case 15: _t->OnshowMainWindow(); break;
        case 16: _t->receiveData((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->on_recv_log_win_status((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->on_recv_cali_win_status((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->on_pushButton_loadsys_clicked(); break;
        case 20: _t->on_pushButton_loadgpsins_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->on_comboBox_chart2_x_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->on_comboBox_chart1_x_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->on_comboBox_chart1_y_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->on_comboBox_chart2_y_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->on_chart1_MultiAxis_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->on_pushButton_pause1_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->on_pushButton_analyzelanekeep_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->on_pushButton_data_logger_clicked(); break;
        case 29: _t->on_pushButton_clear_data_clicked(); break;
        case 30: _t->on_pushButton_datalibrary_clicked(); break;
        case 31: _t->on_pushButton_datastatics_clicked(); break;
        case 32: _t->on_pushButton_loadvcu_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->on_pushButton_resetall_clicked(); break;
        case 34: _t->on_pushButton_analyzeACC_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 35: _t->on_pushButton_pause2_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 36: _t->on_pushButton_analyzeAEB_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 37: _t->on_pushButton_analyzeautochange_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 38: _t->on_pushButton_analyzeovertaking_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 39: _t->on_pushButton_analyzeacceleration_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 40: _t->on_pushButton_loadcam_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 41: _t->on_pushButton_loadlane_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 42: _t->on_pushButton_loadtsr_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 43: _t->on_pushButton_calibration_clicked(); break;
        case 44: _t->on_pushButton_lane_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 45: _t->on_DebugOutput_textChanged(); break;
        case 46: _t->on_visible_tablewidget_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 47: _t->on_visible_Debug_window_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 48: _t->on_pushButton_meobj_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 49: _t->on_pushButton_canprocy_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 50: _t->on_pushButton_vcu_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 51: _t->on_pushButton_ins_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 52: _t->on_pushButton_idc_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 53: _t->on_pushButton_ibeo_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 54: _t->on_pushButton_velodyne_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 55: _t->on_pushButton_tsr_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 56: _t->on_pushButton_esr_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 57: _t->on_pushButton_rsds_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 58: _t->on_pushButton_detail_ethernet_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 59: _t->on_pushButton_detail_can_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Q_VEHICLE_POSE >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Q_VCU_VEHICLE_INFO >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Q_EXECUTE_TRAJECTORY >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Q_MOBILEYE_LINES >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Q_TRACKED_OBSTACLES >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Q_IPC2DEV_VELOCITY >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Q_EXECUTE_BEHAVIOR_PLAN >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Q_PERCEPTION_TSR >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Q_VELODYNE_POINTS >(); break;
            }
            break;
        case 14:
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
            typedef void (MainWindow::*_t)(int * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::Send_Module_Status)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 60)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 60;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 60)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 60;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::Send_Module_Status(int * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
