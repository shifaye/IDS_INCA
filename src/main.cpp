#include "mainwindow.h"
#include <QApplication>
#include "clcmsubscriber.h"
CLCMSubscriber* g_pLcmSubscriber;
int main(int argc, char *argv[])
{
    g_pLcmSubscriber = new CLCMSubscriber;

    QApplication a(argc, argv);
    MainWindow w;
    w.init();
    w.setWindowIcon(QIcon("monitor.ico"));
    w.showMaximized();
    //w.show();

    if ( !g_pLcmSubscriber->IsInitialized() ){
        return ( EXIT_FAILURE );
    }

    boost::thread_group threadGroup;
    threadGroup.create_thread( boost::bind ( &CLCMSubscriber::run, g_pLcmSubscriber ));
    //threadGroup.join_all();

    a.exec();
    return ( EXIT_SUCCESS );
}
