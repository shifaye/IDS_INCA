#include "ctriggerthread.h"

CTriggerThread::CTriggerThread()
{
    if(!InitializeLCM())
    {
        exit(-1);
    }
    //connect publish slot...
}

bool CTriggerThread::InitializeLCM()
{
    m_pLCM = new lcm::LCM("udpm://239.255.76.67:7667?ttl=0");
    if(!m_pLCM->good())
    {
        PrintErrorInfo("cannot initialize communication, please check the ethernet connection", __FILE__, __FUNCTION__, __LINE__);
        return (false);
    }

    m_trigger_info.stHeader.nTimeStamp = GetGlobalTimeStampInMicroSec();
    m_trigger_info.nTriggerContent = 0;
    return (true);
}

CTriggerThread::~CTriggerThread()
{

}

void CTriggerThread::PublishLCMMsg()
{
    m_pLCM->publish("TRIGGER_INFORMATION", &m_trigger_info);
}

void CTriggerThread::OnTriggerDetected(TRIGGER_INFO trigger)
{
//    m_trigger_info.type   @to do: add type to hpp file for trigger;
    m_trigger_info.stHeader.nTimeStamp = trigger.header.nTimeStamp;
    if(trigger.trigger_name == "no trigger")
        m_trigger_info.nTriggerContent = 0;
    else if(trigger.trigger_name == "curve_road")
        m_trigger_info.nTriggerContent = 1;
    else if(trigger.trigger_name == "ramp")
        m_trigger_info.nTriggerContent = 2;
    else if(trigger.trigger_name == "cross")
        m_trigger_info.nTriggerContent = 3;
    else if(trigger.trigger_name == "merge")
        m_trigger_info.nTriggerContent = 4;

    //automatically detect a behavior...
    else if(trigger.trigger_name == "lane_keeping")
        m_trigger_info.nTriggerContent = 101;
    else if(trigger.trigger_name == "lane changing left" )
        m_trigger_info.nTriggerContent = 102;
    else if(trigger.trigger_name == "lane changing right" )
        m_trigger_info.nTriggerContent = 103;
    else if(trigger.trigger_name == "overtaking left" )
        m_trigger_info.nTriggerContent = 104;
    else if(trigger.trigger_name == "overtaking right" )
        m_trigger_info.nTriggerContent = 105;
    else if(trigger.trigger_name == "half overtaking left" )
        m_trigger_info.nTriggerContent = 106;
    else if(trigger.trigger_name == "half overtaking right" )
        m_trigger_info.nTriggerContent = 107;
    else if(trigger.trigger_name == "changing left global" )
        m_trigger_info.nTriggerContent = 108;
    else if(trigger.trigger_name == "changing right global" )
        m_trigger_info.nTriggerContent = 109;
    else if(trigger.trigger_name == "half changing left global" )
        m_trigger_info.nTriggerContent = 110;
    else if(trigger.trigger_name == "half changing right global" )
        m_trigger_info.nTriggerContent = 111;
    else if(trigger.trigger_name == "stop in distance" )
        m_trigger_info.nTriggerContent = 112;
    else{}

    PublishLCMMsg();
}
