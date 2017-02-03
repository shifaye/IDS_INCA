#ifndef CPLAYERTHREAD_H
#define CPLAYERTHREAD_H

#include <QObject>
#include <QMessageBox>
#include <QList>
#include <QTimer>
#include <QReadWriteLock>
#include <lcm/lcm-cpp.hpp>
#include "channelinfo.h"
#include <glib.h>


class CPlayerThread : public QObject
{
    Q_OBJECT
public:
    explicit CPlayerThread(QObject *parent = 0);

    bool m_bTerminateThreads;
    QReadWriteLock m_lockTerminateThreads;

    float m_fReplaySpeed;
    QReadWriteLock m_lockReplaySpeed;

    QList<CHANNEL_INFO> m_listChannels;
    struct ST_LOG_FILE
    {
        bool bSeekToTimeStampUpdated;
        long int nSeekToTimeStamp;
        QReadWriteLock lockSeekToStamp;

        int nBaseQueueSize;//updated when new file is loaded;
        int nMaxQueueSize;//maxQueueSize = baseQueueSize/replaySpeed;
        QReadWriteLock lockQueueSize;

        bool bLoop;//set to true if loop is needed;
        QReadWriteLock lockLoop;

        lcm::LogFile* pLcmLogFile;

        long int nStartTimeStamp;
        long int nStopTimeStamp;

        long int nMsgNumber;//how many message in the file;

        ST_LOG_FILE()
        {
            bSeekToTimeStampUpdated = false;
            nSeekToTimeStamp = 0;

            nBaseQueueSize = 10;
            nMaxQueueSize = 10;

            nStartTimeStamp = 0;
            nStopTimeStamp = 0;
            bLoop = false;

            nMsgNumber = 0;
            pLcmLogFile = NULL;
        }
    };
    ST_LOG_FILE m_stLogFile;

    REPLAY_MODE m_eReplayMode;
    QReadWriteLock m_lockReplayMode;

    GAsyncQueue* m_stAsyncQueue;

    bool m_bQueueCleared;
    QReadWriteLock m_lockQueueCleared;

    long int m_nLastEventTimeStamp;
    long int m_nCurrentEventTimeStamp;

    lcm::LogEvent* m_pCurrentLogEvent;

    QTimer* m_pUIUpdateTimer;

    lcm::LCM* m_pLCM;
    inline bool GetTerminateThreadsStatus();
    void SetTerminateThreadsStatus(bool status);

    void ReadLogFileThread();
    void PublishEventsThread();

    inline long int GetSeekToTimeStamp();
    void SetSeekToTimeStamp(long int stamp);

    void SetReplayMode(REPLAY_MODE mode);
    inline REPLAY_MODE GetReplayMode();

    inline float GetReplaySpeed();
    void SetReplaySpeed(float speed);

    inline int GetMaxQueueSize();
    void SetMaxQueueSize(int size);

    inline bool GetLoop();
    void SetLoop(bool loop);

    inline bool GetQueueCleared();
    inline void SetQueueCleared(bool reset);

    void SeekToTimeStamp(long int stamp);
    void ClearQueue();
    void PreciseDelay(int microseconds, bool reset = false);

    bool GetLogEvent();
    void PublishCurrentEvent();
    bool CheckFile(QString strFileName);
    void LoadFile(QString strFileName);
    int GetChannelIndex(QString strChannelName);
public slots:
    void OnUpdateUI();
    void OnUpdateChannelBroadCast(int index, bool broadcast);
signals:
    void ShowStatusMessage(QString str);
    void UpdateCurrentTimeStamp(long int timestamp);
    void UpdateTableRow(int index, CHANNEL_INFO channel);
};

#endif // CPLAYERTHREAD_H
