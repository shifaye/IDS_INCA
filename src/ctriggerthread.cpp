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

void CTriggerThread::OnTriggerDetected(QString trigger_name)
{
    if(trigger_name == "no trigger")
        m_trigger_info.nTriggerContent = 0;
    else if(trigger_name == "curve_road")
        m_trigger_info.nTriggerContent = 1;
    else if(trigger_name == "ramp")
        m_trigger_info.nTriggerContent = 2;
    else if(trigger_name == "cross")
        m_trigger_info.nTriggerContent = 3;
    else if(trigger_name == "merge")
        m_trigger_info.nTriggerContent = 4;
    else
        m_trigger_info.nTriggerContent = 0;

    PublishLCMMsg();
}
