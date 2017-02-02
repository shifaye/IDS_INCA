#ifndef CLCMSUBSCRIBER_H
#define CLCMSUBSCRIBER_H
#include <QThread>

#include <lcm/lcm-cpp.hpp>
#include <lcm_channel.h>
#include <global.hpp>
#include "clcmhandler.h"

class CLCMSubscriber:public QThread
{
public:
    CLCMSubscriber();
    ~CLCMSubscriber();
    void run();
    const bool IsInitialized();
private:
    const bool InitializeLCM();
public:
    CLCMHandler* m_pLcmHandler;
private:
    lcm::LCM* m_pLCM;
    bool m_bInitialized;
};

#endif // CLCMSUBSCRIBER_H
