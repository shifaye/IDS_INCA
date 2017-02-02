#include "cmessagerow.h"

CMessageRow::CMessageRow(QString strChannelName, QObject *parent)
    : QObject(parent),
      m_qStrChannelName(strChannelName),
      m_nMsgCounter(0),
      m_nLastTimeStamp(GetGlobalTimeStampInMicroSec()),
      m_nCurrentTimeStamp(GetGlobalTimeStampInMicroSec()),
      m_fFrequency(0.0),
      m_fPeriod(0.0)
{    
}


void CMessageRow::UpdateMsg(MESSAGE msg)
{
    m_nMsgTimeStamp = msg.nMsgTimeStamp;
    m_nRecvTimeStamp = msg.nRecvTimeStamp;
    m_nMsgSize = msg.nMsgSize;
    m_nMsgCounter++;
    if(m_nMsgCounter%10 == 0)
    {
        m_nCurrentTimeStamp = GetGlobalTimeStampInMicroSec();
        m_fPeriod = (m_nCurrentTimeStamp-m_nLastTimeStamp)/10000000.0;
        m_fFrequency = 10000000.0/(m_nCurrentTimeStamp-m_nLastTimeStamp);
        m_nLastTimeStamp = m_nCurrentTimeStamp;
    }
}
