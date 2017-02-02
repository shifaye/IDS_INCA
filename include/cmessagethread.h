#ifndef CMESSAGETHREAD_H
#define CMESSAGETHREAD_H

#include <QObject>
#include <QString>
#include <QList>

#include "global.hpp"
#include "message.h"
#include "glib.h"
#include <QTimer>

class CMessageThread : public QObject
{
    Q_OBJECT
public:
    explicit CMessageThread(QObject *parent = 0);
    ~CMessageThread();

    void ReceiveMessage(const lcm::ReceiveBuffer *rbuf, const std::string &channel);
    void ReceiveThread();
    void WriteThread();

    lcm::LCM m_lcm;
    MESSAGE m_stMsg;
    lcm::LogFile* m_pLCMLogFile;
    bool m_bQueueData;//if true, queue data; else, stop queue data;
    bool m_bLogData;//if true, file is ok, write data to file;
    QList<QString> m_qListRecordChannelName;

    GAsyncQueue* m_stGAsyncQueue;
    inline bool IsRecorded(QString strChannelName);
    mutex m_mtuRecordStatus;
    QTimer m_qTimer;

    long int m_nQueueDataSize;
    long int m_nDataWritten;
    long int m_nLastDataWritten;

signals:
    void ShowStatusMessage(QString str);
    void ShowLogFileName(QString str);
    void MessageReceived(MESSAGE);//emit new signal when new message is received;
    void UpdateRecordStatus(RECORD_STATUS);
    void LogFinished();
public slots:
    void OnUpdateRecordList(QString strChannelName, bool record);
    void OnSwitchRecord(bool);
    void OnSwitchRecord(bool, QString);
    void OnTimerUpdateRecordStatus();
};

#endif // CMESSAGETHREAD_H
