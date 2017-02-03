#ifndef CTRIGGERTHREAD_H
#define CTRIGGERTHREAD_H

#include <QtGlobal>
#include <QThread>
#include <lcm/lcm-cpp.hpp>
#include "TRIGGER_INFORMATION.hpp"
#include "global.hpp"

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
    void OnTriggerDetected(QString trigger_name);

};
#endif //ctriggerthread.h
