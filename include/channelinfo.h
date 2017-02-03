#ifndef CHANNELINFO_H
#define CHANNELINFO_H
#include "global.hpp"
#include <QString>

struct CHANNEL_INFO
{
    QString strChannelName;

    long int nFirstTimeStamp;
    long int nLastTimeStamp;
    long int nCurrentTimeStamp;
    long int nPreviousTimeStamp;
    long int nDeltaTimeStamp;

    float fAvgFrequency;
    float fFrequency;

    float fAvgPeriod;
    float fPeriod;

    int nAvgMsgSize;
    long int nMsgSize;
    int nCurrentMsgSize;

    long int nMsgCount;
    long int nMsgNumber;

    bool bFirstMsg;
    bool bBroadCast;

    CHANNEL_INFO()//default constructor;
    {
        bFirstMsg = true;
        bBroadCast = true;

        nFirstTimeStamp = 0;
        nLastTimeStamp = 0;
        nCurrentTimeStamp = 0;
        nPreviousTimeStamp = 0;
        nDeltaTimeStamp = 0;

        fAvgFrequency = 0.0;
        fFrequency = 0.0;

        fAvgPeriod = 0.0;
        fPeriod = 0.0;

        nAvgMsgSize = 0.0;
        nMsgSize = 0.0;
        nCurrentMsgSize = 0.0;

        nMsgNumber = 0;
        nMsgCount = 0;
    }
};
Q_DECLARE_METATYPE(CHANNEL_INFO)

enum REPLAY_MODE{PLAY, STEP, PAUSE, FINISHED, TERMINATED};
#endif // CHANNELINFO_H

