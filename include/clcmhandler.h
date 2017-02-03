#ifndef CLCMHANDLER_H
#define CLCMHANDLER_H

#include <QObject>
#include <qabstractitemmodel.h>

#include <global.hpp>
#include <lcm/lcm-cpp.hpp>
#include <lcm_channel.h>

#include <MOBILEYE_LANES.hpp>
//#include <MWR_FRONT_RAW_OBJECTS.hpp>
#include <VELODYNE64_FRAME.hpp>
#include <MOBILEYE_HPP.hpp>
#include <RAW_INS.hpp>
#include <VCU_VEHILCE_INFO.hpp>
#include <EXECUTE_TRAJECTORY.hpp>
#include <MOBILEYE_LANES.hpp>
#include <PERCEPTION_OBSTACLES.hpp>
#include <PERCEPTION_OCT_OBSTACLES.hpp>
#include <CAN2_IPC2DEV.hpp>
#include <IBEO_OBJECTS.hpp>
#include <IBEO_POINTS.hpp>
#include <EXECUTE_BEHAVIOR_PLAN.hpp>        //logged adp behavior
#include <PERCEPTION_TSR.hpp>               //logged tsr
#include <TRACKED_OBJECTS.hpp>              //logged tracked objects
#include <VELODYNE_POINTS.hpp>              //logged velodyne points
#include <VELODYNE_720POINTS.hpp>
#include <TRIGGER_INFORMATION.hpp>
#include <LOGITECH_IMAGE.hpp>               //logged logitech image
#include "cdrawcamera.h"

#include "qtmsg.h"

class CLCMHandler:public QObject
{
    Q_OBJECT
public:
    CLCMHandler();
    ~CLCMHandler();
    void CallbackNULL();
    void CallbackRawIns ( const lcm::ReceiveBuffer* recvBuf, const std::string& channelName, const RAW_INS* msg );
    void CallbackVcuVehicleInfo ( const lcm::ReceiveBuffer* recvBuf, const std::string& channelName, const VCU_VEHILCE_INFO* msg );
    void CallbackExecuteTrajectory ( const lcm::ReceiveBuffer* recvBuf, const std::string& channelName, const EXECUTE_TRAJECTORY* msg );
    void CallbackMobileyeLanes(const lcm::ReceiveBuffer* recvBuf, const std::string& channelName, const MOBILEYE_LANES* msg);
    void CallbackTrackedObstacles(const lcm::ReceiveBuffer* recvBuf, const std::string& chanenelName, const TRACKED_OBJECTS * msg);
    void CallbackSendToVCUMessage(const lcm::ReceiveBuffer* recvBuf, const std::string& chanenelName, const CAN2_IPC2DEV* msg);
    void CallbackIbeoObjects(const lcm::ReceiveBuffer* recvBuf, const std::string& chanenelName, const IBEO_OBJECTS* msg);
    void CallbackExecuteBehaviorPlan(const lcm::ReceiveBuffer* recvBuf, const std::string& chanenelName, const EXECUTE_BEHAVIOR_PLAN* msg);
    void CallbackPerceptionTsr(const lcm::ReceiveBuffer* recvBuf, const std::string& chanenelName, const PERCEPTION_TSR* msg);
    void CallbackVelodyne(const lcm::ReceiveBuffer* recvBuf, const std::string& chanenelName, const VELODYNE64_FRAME* msg);
    void CallbackLogitechImage(const lcm::ReceiveBuffer *recvBuf, const std::string &channelName, const LOGITECH_IMAGE* msg);
    void CallbackPerceptionObstacles(const lcm::ReceiveBuffer *recvBuf, const std::string &channelName, const PERCEPTION_OBSTACLES* msg);
    void CallbackTrigger(const lcm::ReceiveBuffer *recvBuf, const std::string &channelName, const TRIGGER_INFORMATION* msg);
    CDrawCamera m_stCameraDrawer;

    Q_VEHICLE_POSE m_qVehiclePose;
    Q_VCU_VEHICLE_INFO m_qVcuVehicleInfo;
    Q_EXECUTE_TRAJECTORY m_qExecuteTrajectory;
    Q_MOBILEYE_LINES m_qMobileyeLines;
    Q_TRACKED_OBSTACLES m_qTrackedObstacles;
    Q_IPC2DEV_VELOCITY m_qIpc2devVelocity;
    //Q_IBEO_OBJECTS m_qIbeoObjects;
    Q_EXECUTE_BEHAVIOR_PLAN m_qExecuteBehaviorPlan;
    Q_PERCEPTION_TSR m_qPerceptionTsr;
    Q_VELODYNE_POINTS m_qVelodynePoints;
    Q_PERCEPTIONED_OBJECTS m_qPerceptionObjs;
    Q_TRIGGER m_qTrigger;

signals:
    void NewVehiclePose ( Q_VEHICLE_POSE );
    void NewExecuteTrajectory ( Q_EXECUTE_TRAJECTORY );
    void NewVcuVehicleInfo ( Q_VCU_VEHICLE_INFO );
    void NewMobileyeLaneLines(Q_MOBILEYE_LINES);
    void NewTrackedObstacles(Q_TRACKED_OBSTACLES);
    void NewIpc2devVelocity(Q_IPC2DEV_VELOCITY);
    //void NewIbeoObjects(Q_IBEO_OBJECTS);
    void NewExecuteBehaviorPlan(Q_EXECUTE_BEHAVIOR_PLAN);
    void NewPerceptionTsr(Q_PERCEPTION_TSR);
    void NewVelodynePoints(Q_VELODYNE_POINTS);
    void NewPerceptionedObjs(Q_PERCEPTIONED_OBJECTS);
    void NewTrigger(Q_TRIGGER);
};

#endif // CLCMHANDLER_H
