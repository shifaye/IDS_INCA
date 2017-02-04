#include "croutethread.h"
#include "iomanip"
using namespace std;

CRouteThread::CRouteThread()
{
    m_RouteFile = "route.txt";
    m_RouteHeader = "route_head.txt";
    m_RouteEnd = "route_end.txt";
    outfile.open(m_RouteFile);
    CopyRouteHead(m_RouteHeader,m_RouteFile);
}

CRouteThread::~CRouteThread()
{

}

int CRouteThread::CopyRouteHead(char *SourceFile,char *NewFile)
{
    ifstream in;
    ofstream out;
    in.open(SourceFile,ios::binary);
    if(in.fail()){
       cout<<"Error 1: Fail to open the source file."<<endl;
       in.close();
       out.close();
       return 0;
    }
    out.open(NewFile,ios::binary);
    if(out.fail()){
       cout<<"Error 2: Fail to create the new file."<<endl;
       out.close();
       in.close();
       return 0;
    }else
    {
        out<<in.rdbuf();
        out.close();
        in.close();
        return 1;
    }
}

//int InsertRoute(char *SourceFile,char *NewFile)
//{

//}

int CRouteThread::AppendRouteEnd()
{
    ifstream in;
    ofstream out;
    in.open(m_RouteEnd,ios::binary);
    if(in.fail()){
       cout<<"Error 1: Fail to open the source file."<<endl;
       in.close();
       out.close();
       return 0;
    }
    out.open(m_RouteFile,ios::app);
    if(out.fail()){
       cout<<"Error 2: Fail to create the new file."<<endl;
       out.close();
       in.close();
       return 0;
    }else
    {
        out<<in.rdbuf();
        out.close();
        in.close();
        return 1;
    }
}

void CRouteThread::OnRouteUpdated(ROUTE_GPS route_gps)
{
    //record gps points in file one by one;
    ofstream out;
    out.open(m_RouteFile,ios::app);
    out.setf(ios::fixed, ios::floatfield);
    out.precision(8);
    if(out.fail()){
       cout<<"Error 2: Fail to create the new file."<<endl;
       out.close();
    }else
    {
        out<<route_gps.fLongitude<<","
           <<route_gps.fLatitude<<","
           <<route_gps.fAltitude<<"\n";
        out.close();
    }

}
