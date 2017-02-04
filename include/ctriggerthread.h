#ifndef CTRIGGERTHREAD_H
#define CTRIGGERTHREAD_H

#include <QtGlobal>
#include <QThread>
#include <lcm/lcm-cpp.hpp>
#include "TRIGGER_INFORMATION.hpp"
#include "global.hpp"
enum TRIGGER_TYPE
{
    MANUAL,
    AUTOMATIC
};

struct TRIGGER_INFO
{
    TRIGGER_TYPE type;
    HEADER header;
    QString trigger_name;
};

class CTriggerThread : public QThread
{
    Q_OBJECT
public:
    CTriggerThread();
    ~CTriggerThread();
    void PublishLCMMsg();
    bool InitializeLCM();
public:
    TRIGGER_INFORMATION m_trigger_info;
    lcm::LCM* m_pLCM;

signals:

public slots:
    void OnTriggerDetected(TRIGGER_INFO trigger);

};
#endif //ctriggerthread.h
