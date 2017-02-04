#ifndef CROUTETHREAD_H
#define CROUTETHREAD_H

#include <QtGlobal>
#include <QThread>
#include <fstream>
#include <iostream>
using namespace std;

struct ROUTE_GPS
{
    double fLatitude;//in deg;
    double fLongitude;//in deg;
    float fAltitude;//in deg;
};

class CRouteThread : public QThread
{
    Q_OBJECT
public:
    CRouteThread();
    ~CRouteThread();
    ofstream outfile;
    char* m_RouteFile;
    char* m_RouteHeader;
    char* m_RouteEnd;
    int CopyRouteHead(char *SourceFile,char *NewFile);
    int AppendRouteEnd();
signals:

public slots:
    void OnRouteUpdated(ROUTE_GPS route_gps);

};
#endif //croutethread.h
