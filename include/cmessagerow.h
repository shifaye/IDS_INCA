#ifndef CMESSAGEROW_H
#define CMESSAGEROW_H

#include <QObject>
#include <QTableWidgetItem>
#include "message.h"

class CMessageRow : public QObject
{
    Q_OBJECT
public:
    explicit CMessageRow(QString strChannelName, QObject *parent = 0);

    //informatio of each row;
    QString m_qStrChannelName;//channel name;
    long int m_nMsgTimeStamp;//the newest message timestamp, not used right now;
    long int m_nRecvTimeStamp;//the time when the newest message is received;
    long int m_nMsgSize;
    int m_nMsgCounter;
    float m_fFrequency;
    float m_fPeriod;
    long int m_nLastTimeStamp;
    long int m_nCurrentTimeStamp;

    void UpdateMsg(MESSAGE msg);
signals:

public slots:
};

#endif // CMESSAGEROW_H
