#include "cmessagethread.h"


CMessageThread::CMessageThread(QObject *parent) : QObject(parent),
    m_bQueueData(false),//set queue data to false to disable queue data;
    m_bLogData(false),//set log data to false to disable log data to files;
    m_nDataWritten(0),
    m_nQueueDataSize(0),
    m_nLastDataWritten(0)
{
    m_stGAsyncQueue = g_async_queue_new();//create asynchronized queue by glib;

    connect(&m_qTimer, SIGNAL(timeout()), this, SLOT(OnTimerUpdateRecordStatus()));//set timer slot to update record status;

    m_qTimer.start(1000);//set timer to 1 second, each 1 second, the record status will be updated;s
}

CMessageThread::~CMessageThread()
{
    g_async_queue_unref(m_stGAsyncQueue);//
}

void CMessageThread::ReceiveThread()
{
    while(m_lcm.handle() == 0)
    {
    }
}

void CMessageThread::WriteThread()
{
    while(1)
    {
        if(m_bLogData)
        {
            void* msg = g_async_queue_pop(m_stGAsyncQueue);
            lcm::LogEvent* logEvent = (lcm::LogEvent*) msg;
            m_pLCMLogFile->writeEvent(logEvent);
            m_mtuRecordStatus.lock();
            m_nDataWritten += logEvent->datalen;
            m_mtuRecordStatus.unlock();
            delete logEvent->data;
            delete logEvent;
        }
        else
        {
            usleep(10000);
        }
    }
}

void CMessageThread::ReceiveMessage(const lcm::ReceiveBuffer* recvBuffer, const std::string &channel)
{
    MESSAGE msg;
    msg.strChannelName = channel;
    msg.nMsgSize = recvBuffer->data_size;
    msg.nRecvTimeStamp = GetGlobalTimeStampInMicroSec();
    emit MessageReceived(msg);

    if(m_bQueueData)
    {
        if(IsRecorded(QString::fromStdString(channel)))
        {
            //construct the log event;
            lcm::LogEvent* logEvent = new lcm::LogEvent;
            logEvent->channel = channel;
            logEvent->timestamp = GetGlobalTimeStampInMicroSec();
            logEvent->datalen = recvBuffer->data_size;
            logEvent->data = new char[logEvent->datalen];

            memcpy(logEvent->data, recvBuffer->data, logEvent->datalen);

            //push to the queue;
            g_async_queue_push(m_stGAsyncQueue, logEvent);

            m_mtuRecordStatus.lock();
            m_nQueueDataSize += logEvent->datalen;
            m_mtuRecordStatus.unlock();
        }
    }
}


bool CMessageThread::IsRecorded(QString strChannelName)
{
    for(int i=0; i<m_qListRecordChannelName.size(); i++)
    {
        if(QString::compare(strChannelName, m_qListRecordChannelName[i])==0)
        {
            return true;
        }
    }
    return false;
}

void CMessageThread::OnUpdateRecordList(QString strChannelName, bool record)
{
    int i = 0;
    if(true == record)
    {
        for(i=0; i<m_qListRecordChannelName.size(); i++)
        {
            if(QString::compare(strChannelName, m_qListRecordChannelName[i])==0)
            {
                return;
            }
        }
        m_qListRecordChannelName.append(strChannelName);
    }

    if(false == record)
    {
        m_qListRecordChannelName.removeAll(strChannelName);
    }

}

void CMessageThread::OnSwitchRecord(bool record, QString extraFileName)
{
    if(record)
    {
        std::string strFileName = GetCurrentDateTimeString()+extraFileName.toStdString()+ std::string(".log");
        //open a new file to record;
        m_pLCMLogFile = new lcm::LogFile(strFileName, "w");
        m_mtuRecordStatus.lock();
        m_nQueueDataSize = 0;
        m_nDataWritten = 0;
        m_nLastDataWritten = 0;
        m_mtuRecordStatus.unlock();
        m_bLogData = true;
        m_bQueueData = true;
        emit ShowLogFileName(QString::fromStdString(strFileName));
    }
}

void CMessageThread::OnSwitchRecord(bool record)
{

    if(!record)
    {
        m_bQueueData = false;//stop queue data;

        //sleep until the queue is empty;
        while(g_async_queue_length(m_stGAsyncQueue)>0)
        {
            usleep(10000);
        }

        m_bLogData = false;//stop write data to file;

        //close the file;
        delete m_pLCMLogFile;

        emit LogFinished();
    }
}

void CMessageThread::OnTimerUpdateRecordStatus()
{
    RECORD_STATUS recordStatus;
    m_mtuRecordStatus.lock();
    recordStatus.fBytesWritten = m_nDataWritten/1000000.0;
    recordStatus.fBytesToWrite = (m_nQueueDataSize-m_nDataWritten)/1000000.0;
    recordStatus.fBandWidth = (m_nDataWritten-m_nLastDataWritten)/1000000.0;
    m_nLastDataWritten = m_nDataWritten;
    m_mtuRecordStatus.unlock();
    emit UpdateRecordStatus(recordStatus);
}
