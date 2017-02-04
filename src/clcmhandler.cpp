#include "clcmhandler.h"

CLCMHandler::CLCMHandler()
{

}

CLCMHandler::~CLCMHandler()
{

}

void CLCMHandler::CallbackNULL()
{
    std::cerr<<"call back null success!"<<std::endl;
}
/**@brief mobileye lanes callback function;
 *
 * mobileye lanes callback fuction:;
 *@param recvBuf [IN]: the received raw data (not decoded);
 *@param channelName [IN]: the channel name;
 *@param msg [IN]: the decoded data frame;
 *@return void;
 *@note
 **/
void CLCMHandler::CallbackRawIns ( const lcm::ReceiveBuffer* recvBuf, const std::string& channelName, const RAW_INS* msg )
{
    m_qVehiclePose.fAccX = msg->fAccX;
    m_qVehiclePose.fAccY = msg->fAccY;
    m_qVehiclePose.fAccZ = msg->fAccZ;

    m_qVehiclePose.fAngRateX = msg->fGyroX*RADIAN_TO_DEGREE;
    m_qVehiclePose.fAngRateY = msg->fGyroY*RADIAN_TO_DEGREE;
    m_qVehiclePose.fAngRateZ = msg->fGyroZ*RADIAN_TO_DEGREE;

    m_qVehiclePose.fLatitude = msg->fLatitude;
    m_qVehiclePose.fLongitude = msg->fLongitude;
    m_qVehiclePose.fAltitude = msg->fAltitude;

    m_qVehiclePose.fVelUp = msg->fVelUp;
    m_qVehiclePose.fVelWest = msg->fVelWest;
    m_qVehiclePose.fVelNorth = msg->fVelNorth;

    m_qVehiclePose.fHeading = msg->fHeading*RADIAN_TO_DEGREE;
    m_qVehiclePose.fPitch = msg->fPitch*RADIAN_TO_DEGREE;
    m_qVehiclePose.fRoll = msg->fRoll*RADIAN_TO_DEGREE;

    m_qVehiclePose.fSpeed = 3.6f*sqrt ( msg->fVelNorth*msg->fVelNorth + msg->fVelWest*msg->fVelWest + msg->fVelUp*msg->fVelUp );
    emit NewVehiclePose(m_qVehiclePose);
}

void CLCMHandler::CallbackExecuteTrajectory ( const lcm::ReceiveBuffer* recvBuf, const std::string& channelName, const EXECUTE_TRAJECTORY* msg )
{
  //fprintf(stderr, "new track at %.6lf\n", GetGlobalTimeStampInSec());
  m_qExecuteTrajectory.fDesiredSpeed = msg->fDesiredSpeed*3.6f;

  emit NewExecuteTrajectory(m_qExecuteTrajectory);
}

void CLCMHandler::CallbackVcuVehicleInfo ( const lcm::ReceiveBuffer* recvBuf, const std::string& channelName, const VCU_VEHILCE_INFO* msg )
{
  m_qVcuVehicleInfo.fFrontLeftWheelSpeed = msg->fFrontLeftWheelSpeed;
  m_qVcuVehicleInfo.fFrontRightWheelSpeed = msg->fFrontRightWheelSpeed;
  m_qVcuVehicleInfo.fRearLeftWheelSpeed = msg->fRearLeftWheelSpeed;
  m_qVcuVehicleInfo.fRearRightWheelSpeed = msg->fRearRightWheelSpeed;
  m_qVcuVehicleInfo.fSteeringAngle = msg->fSteeringAngle*RADIAN_TO_DEGREE;
  emit NewVcuVehicleInfo(m_qVcuVehicleInfo);
}


void CLCMHandler::CallbackMobileyeLanes(const lcm::ReceiveBuffer *recvBuf, const std::string &channelName, const MOBILEYE_LANES *msg)
{
    m_qMobileyeLines.fLeftLineDist = fabs(msg->stLeftLine.a);
    m_qMobileyeLines.fRightLineDist = fabs(msg->stRightLine.a);
    emit NewMobileyeLaneLines(m_qMobileyeLines);
}

void CLCMHandler::CallbackTrackedObstacles(const lcm::ReceiveBuffer *recvBuf, const std::string &channelName, const TRACKED_OBJECTS *msg)
{
//   m_qPerceptionOctObstacles.gstOctObstacles[0].fDistance = msg->gstOctObstacles[0].fDistance;

   emit NewTrackedObstacles(m_qTrackedObstacles);
}

void CLCMHandler::CallbackSendToVCUMessage(const lcm::ReceiveBuffer *recvBuf, const std::string &channelName, const CAN2_IPC2DEV *msg)
{
    m_qIpc2devVelocity.stHeader.nCounter = 0;
    m_qIpc2devVelocity.stHeader.nTimeStamp = 0;
    m_qIpc2devVelocity.bLen = 6;

//    memcpy ( m_qIpc2devVelocity.gbData[0], 0x00, 8);

//    memcpy ( m_qIpc2devVelocity.gbData[1], 0x00, 8);

//    memcpy ( m_qIpc2devVelocity.gbData[2], 0x00, 8);

//    memcpy ( m_qIpc2devVelocity.gbData[3], 0x00, 8);

    m_qIpc2devVelocity.gnMsgId[4] = static_cast<uint16_t> ( 0x12 );
    m_qIpc2devVelocity.gbMsgLen[4] = static_cast<uint8_t> ( 8 );
    memcpy ( m_qIpc2devVelocity.gbData[4], msg->gbData[4], 8);

//    memcpy ( m_qIpc2devVelocity.gbData[5], 0x00, 8);

   emit NewIpc2devVelocity(m_qIpc2devVelocity);
}

void CLCMHandler::CallbackIbeoObjects(const lcm::ReceiveBuffer *recvBuf, const std::string &chanenelName, const IBEO_OBJECTS *msg)
{
//   m_qIbeoObjects.gnObjectID[0] = msg->gnObjectID[0];
//    //m_qIbeoObjects.
//   emit NewIbeoObjects(m_qIbeoObjects);
}

void CLCMHandler::CallbackExecuteBehaviorPlan(const lcm::ReceiveBuffer *recvBuf, const std::string &chanenelName, const EXECUTE_BEHAVIOR_PLAN *msg)
{
   m_qExecuteBehaviorPlan.header.nTimeStamp = msg->header.nTimeStamp;
   m_qExecuteBehaviorPlan.n_current_behavior = msg->n_current_behavior;
   emit NewExecuteBehaviorPlan(m_qExecuteBehaviorPlan);
}

void CLCMHandler::CallbackPerceptionTsr(const lcm::ReceiveBuffer *recvBuf, const std::string &chanenelName, const PERCEPTION_TSR *msg)
{
   emit NewPerceptionTsr(m_qPerceptionTsr);
}

void CLCMHandler::CallbackVelodyne(const lcm::ReceiveBuffer *recvBuf, const std::string &chanenelName, const VELODYNE64_FRAME *msg)
{
   emit NewVelodynePoints(m_qVelodynePoints);
}

/**
 * @brief CLCMHandler::CallbackLogitechImage
 * @param recvBuf
 * @param channelName
 * @param msg
 */
void CLCMHandler::CallbackLogitechImage(const lcm::ReceiveBuffer *recvBuf, const std::string &channelName,const LOGITECH_IMAGE* msg)
{
    m_stCameraDrawer.DecodeLogitechImageMsg(msg);
}

void CLCMHandler::CallbackPerceptionObstacles(const lcm::ReceiveBuffer *recvBuf, const std::string &channelName, const PERCEPTION_OBSTACLES *msg)
{
    m_qPerceptionObjs.gstMiddleLaneObstacles[0].fDistance = msg->gstMiddleLaneObstacles[0].fDistance;
    emit NewPerceptionedObjs(m_qPerceptionObjs);
}

void CLCMHandler::CallbackTrigger(const lcm::ReceiveBuffer *recvBuf, const std::string &channelName, const TRIGGER_INFORMATION *msg)
{
    m_qTrigger.m_trigger_type = msg->nTriggerContent;
    m_qTrigger.header.nTimeStamp = msg->stHeader.nTimeStamp;
    emit NewTrigger(m_qTrigger);
    std::cerr<<"a trigger is detected!"<<std::endl;
}
