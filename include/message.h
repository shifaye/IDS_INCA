#ifndef MESSAGE_H
#define MESSAGE_H
#include "global.hpp"
struct MESSAGE
{
    std::string strChannelName;
    long int nMsgTimeStamp;//micro second;
    long int nRecvTimeStamp;//micro second;
    long int nMsgSize;//in bytes;
};
Q_DECLARE_METATYPE(MESSAGE)

struct RECORD_STATUS
{
    float fBandWidth;
    float fBytesWritten;
    float fBytesToWrite;
};
Q_DECLARE_METATYPE(RECORD_STATUS)
#endif // MESSAGE_H

