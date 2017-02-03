#include "clcmsubscriber.h"

CLCMSubscriber::CLCMSubscriber() :
    m_bInitialized ( false )
{
    m_pLcmHandler = new CLCMHandler;
    m_bInitialized = InitializeLCM();
    this->start();
}

CLCMSubscriber::~CLCMSubscriber()
{

}

/**@brieft check if the subscriber is initialized or not;
 *
 * check if the subscriber is initialized or not;
 *@return bool: if the lcm is successfully initialized, return true; else, return false;
 *@note
 **/
const bool CLCMSubscriber::IsInitialized()
{
    return m_bInitialized;
}

/**@brief initialize lcm communications;
 *
 * initialize lcm communications, including mobileye_lanes, mwr_objects;
 *@return bool: if all lcm successfully initialized, return true; else, return false;
 *@note change ttl to enable messages from different machines;
 */
const bool CLCMSubscriber::InitializeLCM()
{
    m_pLCM = new lcm::LCM ( "udpm://239.255.76.67:7667?ttl=0" );
    if ( !m_pLCM->good() )
    {
        PrintErrorInfo ( "initialize communication error, please check the ethernet connection", __FILE__, __FUNCTION__, __LINE__ );
        return ( false );
    }

    m_pLCM->subscribe ( CHANNEL_NAME_RAW_INS, &CLCMHandler::CallbackRawIns, m_pLcmHandler );
    m_pLCM->subscribe ( CHANNEL_NAME_EXECUTE_TRAJECTORY, &CLCMHandler::CallbackExecuteTrajectory, m_pLcmHandler );
    m_pLCM->subscribe ( CHANNEL_NAME_VCU_VEHICLE_INFO, &CLCMHandler::CallbackVcuVehicleInfo, m_pLcmHandler );
    m_pLCM->subscribe ( CHANNEL_NAME_MOBILEYE_LANES, &CLCMHandler::CallbackMobileyeLanes, m_pLcmHandler);
    m_pLCM->subscribe ( CHANNEL_NAME_TRACKED_OBJECTS, &CLCMHandler::CallbackTrackedObstacles, m_pLcmHandler);
    m_pLCM->subscribe ( CHANNEL_NAME_CAN2_IPC2VCU_TRAJECTORY, &CLCMHandler::CallbackSendToVCUMessage, m_pLcmHandler);
    m_pLCM->subscribe ( CHANNEL_NAME_IBEO_OBJECTS, &CLCMHandler::CallbackIbeoObjects, m_pLcmHandler);
    m_pLCM->subscribe ( CHANNEL_NAME_EXECUTE_BEHAVIOR_PLAN, &CLCMHandler::CallbackExecuteBehaviorPlan, m_pLcmHandler);
    m_pLCM->subscribe ( CHANNEL_NAME_PERCEPTION_TSR, &CLCMHandler::CallbackPerceptionTsr, m_pLcmHandler);
    m_pLCM->subscribe ( CHANNEL_NAME_VELODYNE64, &CLCMHandler::CallbackVelodyne, m_pLcmHandler);
    m_pLCM->subscribe ( CHANNEL_NAME_PERCEPTION_OBSTACLES,&CLCMHandler::CallbackPerceptionObstacles, m_pLcmHandler);

    m_pLCM->subscribe ("TRIGGER_INFORMATION",&CLCMHandler::CallbackTrigger, m_pLcmHandler);
    m_pLCM->subscribe ("LOGITECH_IMAGE",&CLCMHandler::CallbackLogitechImage, m_pLcmHandler);

    return true;
}


/**@brief  lcm thread function;
 *
 * lcm thread function, only used to call the handle;
 *@return void;
 *@note
 *@todo timeout should be added to diagnose the fault;
 **/
void CLCMSubscriber::run()
{
    while ( 0==m_pLCM->handle() );
}
