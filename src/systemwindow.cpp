#include "systemwindow.h"
#include "ui_systemwindow.h"
#include "QtNetwork/QNetworkInterface"
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

SystemWindow::SystemWindow ( QWidget *parent ) :
    QMainWindow ( parent ),
    sys_ui ( new Ui::SystemWindow )
{
    sys_ui->setupUi ( this );
    this->setFixedSize(820,600);
    this->setWindowTitle ( QString ( "System_Status" ));

    last_recv_bytes_eth0 = 0;
    last_recv_bytes_eth1 = 0;
    last_send_bytes_eth0 = 0;
    last_send_bytes_eth1 = 0;

    sys_ui->tableWidget_List_Dev_Stats->setHorizontalHeaderItem ( 0, new QTableWidgetItem ( "dev" ) );
    sys_ui->tableWidget_List_Dev_Stats->setHorizontalHeaderItem ( 1, new QTableWidgetItem ( "Recv_Bytes" ) );
    sys_ui->tableWidget_List_Dev_Stats->setHorizontalHeaderItem ( 2, new QTableWidgetItem ( "Recv_Pkgs" ) );
    sys_ui->tableWidget_List_Dev_Stats->setHorizontalHeaderItem ( 3, new QTableWidgetItem ( "Send_Bytes" ) );
    sys_ui->tableWidget_List_Dev_Stats->setHorizontalHeaderItem ( 4, new QTableWidgetItem ( "Send_Pkgs" ) );
    sys_ui->tableWidget_List_Dev_Stats->setHorizontalHeaderItem ( 5, new QTableWidgetItem ( "Down_Speed" ) );
    sys_ui->tableWidget_List_Dev_Stats->setHorizontalHeaderItem ( 6, new QTableWidgetItem ( "Up_Speed" ) );

    sys_ui->tableWidget_List_Dev_Stats->setColumnWidth(0,50);
    sys_ui->tableWidget_List_Dev_Stats->setColumnWidth(1,100);
    sys_ui->tableWidget_List_Dev_Stats->setColumnWidth(2,100);
    sys_ui->tableWidget_List_Dev_Stats->setColumnWidth(3,100);
    sys_ui->tableWidget_List_Dev_Stats->setColumnWidth(4,100);
    sys_ui->tableWidget_List_Dev_Stats->setColumnWidth(5,100);
    sys_ui->tableWidget_List_Dev_Stats->setColumnWidth(6,100);

    indicatorlamp_red = new QPixmap();
    indicatorlamp_blue = new QPixmap();
    indicatorlamp_green = new QPixmap();
    indicatorlamp_yellow = new QPixmap();

    count_of_EW = 0;
    sys_ui->tableWidget_Error_Warnings->setHorizontalHeaderItem (0, new QTableWidgetItem ("No."));
    sys_ui->tableWidget_Error_Warnings->setColumnWidth(0,50);
    sys_ui->tableWidget_Error_Warnings->setHorizontalHeaderItem (1, new QTableWidgetItem ("Message Content."));
    sys_ui->tableWidget_Error_Warnings->setColumnWidth(1,300);
    sys_ui->tableWidget_Error_Warnings->setHorizontalHeaderItem (2, new QTableWidgetItem ("Severity."));
    sys_ui->tableWidget_Error_Warnings->setColumnWidth(2,100);
    sys_ui->tableWidget_Error_Warnings->setHorizontalHeaderItem (3, new QTableWidgetItem ("Module Name."));
    sys_ui->tableWidget_Error_Warnings->setColumnWidth(3,200);
    sys_ui->tableWidget_Error_Warnings->setHorizontalHeaderItem (4, new QTableWidgetItem ("Message Size."));
    sys_ui->tableWidget_Error_Warnings->setColumnWidth(4,100);

    m_pUpdateMonitor = new QTimer ( this );
    connect ( m_pUpdateMonitor, SIGNAL ( timeout() ), this, SLOT ( OnMonitorUpdate() ) ); //, Qt::QueuedConnection);
    m_pUpdateMonitor->start ( 1000 );

    //MainWindow *ptr = (MainWindow*)parentWidget();
    //connect(ptr,SIGNAL(Send_Module_Status(int*)),this,SLOT(on_Receive_Module_Status(int *)));
    //ptr->ui->DebugOutput->append("Initialized System Window!");

    OnCheckProcess();
    m_pCheckProcess = new QTimer ( this );
    connect ( m_pCheckProcess, SIGNAL ( timeout() ), this, SLOT ( OnCheckProcess() ) ); //, Qt::QueuedConnection);
    m_pCheckProcess->start ( 10000 );

}

void SystemWindow::closeEvent(QCloseEvent *event)
{
    emit sendData(true);
}

void SystemWindow::OnCheckProcess()
{
    sys_ui->pushButton_app_logger->setText("logger_off");
    sys_ui->pushButton_app_logger->setIcon(*indicatorlamp_red);
    sys_ui->pushButton_app_adp->setText("adp_off");
    sys_ui->pushButton_app_adp->setIcon(*indicatorlamp_red);
    sys_ui->pushButton_app_ins->setText("app_ins_off");
    sys_ui->pushButton_app_ins->setIcon(*indicatorlamp_red);
    sys_ui->pushButton_app_player->setText("player_off");
    sys_ui->pushButton_app_player->setIcon(*indicatorlamp_red);
    sys_ui->pushButton_app_vcu->setText("can2proxy_off");
    sys_ui->pushButton_app_vcu->setIcon(*indicatorlamp_red);
    sys_ui->pushButton_app_chart->setText("chart_off");
    sys_ui->pushButton_app_chart->setIcon(*indicatorlamp_red);
    sys_ui->pushButton_app_drivermap->setText("drivermap_off");
    sys_ui->pushButton_app_drivermap->setIcon(*indicatorlamp_red);
    sys_ui->pushButton_app_idc2vcu->setText("idc2vcu_off");
    sys_ui->pushButton_app_idc2vcu->setIcon(*indicatorlamp_red);
    sys_ui->pushButton_app_logitech->setText("logitech_off");
    sys_ui->pushButton_app_logitech->setIcon(*indicatorlamp_red);
    sys_ui->pushButton_app_me_process->setText("me_process_off");
    sys_ui->pushButton_app_me_process->setIcon(*indicatorlamp_red);
    sys_ui->pushButton_app_mobileye->setText("mobileye_off");
    sys_ui->pushButton_app_mobileye->setIcon(*indicatorlamp_red);
    sys_ui->pushButton_app_transformer->setText("transformer_off");
    sys_ui->pushButton_app_transformer->setIcon(*indicatorlamp_red);
    sys_ui->pushButton_app_vcb->setText("vcb_off");
    sys_ui->pushButton_app_vcb->setIcon(*indicatorlamp_red);
    sys_ui->pushButton_app_lanefusion->setText("lane_fusion_off");
    sys_ui->pushButton_app_lanefusion->setIcon(*indicatorlamp_red);
    sys_ui->pushButton_app_ibeo->setText("ibeo_off");
    sys_ui->pushButton_app_ibeo->setIcon(*indicatorlamp_red);
    sys_ui->pushButton_app_ibeoprocess->setText("ibeo_process_off");
    sys_ui->pushButton_app_ibeoprocess->setIcon(*indicatorlamp_red);
    sys_ui->pushButton_app_velodyne->setText("velodyne_off");
    sys_ui->pushButton_app_velodyne->setIcon(*indicatorlamp_red);
    sys_ui->pushButton_app_velodyneprocess->setText("HDL_process_off");
    sys_ui->pushButton_app_velodyneprocess->setIcon(*indicatorlamp_red);
    sys_ui->pushButton_app_viewer->setText("viewer_off");
    sys_ui->pushButton_app_viewer->setIcon(*indicatorlamp_red);

    indicatorlamp_green->load(INDICATORLAMP_GREEN_PATH);
    indicatorlamp_red->load(INDICATORLAMP_RED_PATH);

    DIR *dir;
    struct dirent *ptr;
    FILE *fp;
    char filepath[50];
    char cur_task_name[50];
    char buf[1024];
    dir = opendir("/proc");
    if (NULL != dir)
    {
        int repeat_process_checker_adp = 0;
        while ((ptr = readdir(dir)) != NULL)
        {
            if ((strcmp(ptr->d_name, ".") == 0) || (strcmp(ptr->d_name, "..") == 0)){
                continue;
            }else if (DT_DIR != ptr->d_type){
                continue;
            }

            sprintf(filepath, "/proc/%s/status", ptr->d_name);
            fp = fopen(filepath, "r");
            if (NULL != fp){
                if( fgets(buf, 1024-1, fp)== NULL){
                    fclose(fp);
                    continue;
                }
                sscanf(buf, "%*s %s", cur_task_name);

                if (!strcmp("app_player", cur_task_name)){
                    sys_ui->pushButton_app_player->setIcon(*indicatorlamp_green);
                    sys_ui->pushButton_app_player->setText("player_running");
                }
                if (!strcmp("app_can2_proxy", cur_task_name)){
                    sys_ui->pushButton_app_vcu->setText("can2proxy_running");
                    sys_ui->pushButton_app_vcu->setIcon(*indicatorlamp_green);
                }

                if (!strcmp("app_sys_chart", cur_task_name)){
                    sys_ui->pushButton_app_chart->setIcon(*indicatorlamp_green);
                    sys_ui->pushButton_app_chart->setText("chart_running");
                }

                if (!strcmp("app_logger", cur_task_name)){
                    sys_ui->pushButton_app_logger->setText("logger_running");
                    sys_ui->pushButton_app_logger->setIcon(*indicatorlamp_green);
                }

                if (!strcmp("app_adp", cur_task_name)){
                    sys_ui->pushButton_app_adp->setText("adp_running");
                    sys_ui->pushButton_app_adp->setIcon(*indicatorlamp_green);
                    repeat_process_checker_adp++;
                }

                if (!strcmp("app_inertial", cur_task_name) || !strcmp("app_spatial_fog", cur_task_name)){
                    sys_ui->pushButton_app_ins->setText("ins_running");
                    sys_ui->pushButton_app_ins->setIcon(*indicatorlamp_green);
                }

                if (!strcmp("app_driver_map", cur_task_name)){
                    sys_ui->pushButton_app_drivermap->setText("driver_map_running");
                    sys_ui->pushButton_app_drivermap->setIcon(*indicatorlamp_green);
                }

                if (!strcmp("app_ibeo", cur_task_name)){
                    sys_ui->pushButton_app_ibeo->setText("ibeo_running");
                    sys_ui->pushButton_app_ibeo->setIcon(*indicatorlamp_green);
                }

                if (!strcmp("app_ibeo_process", cur_task_name)){
                    sys_ui->pushButton_app_ibeoprocess->setText("ibeoprocess_running");
                    sys_ui->pushButton_app_ibeoprocess->setIcon(*indicatorlamp_green);
                }

                if (!strcmp("app_velodyne64", cur_task_name)){
                    sys_ui->pushButton_app_velodyne->setText("velodyne_running");
                    sys_ui->pushButton_app_velodyne->setIcon(*indicatorlamp_green);
                }

                if (!strcmp("app_velodyne_process", cur_task_name)){
                    sys_ui->pushButton_app_velodyneprocess->setText("HDL64process_running");
                    sys_ui->pushButton_app_velodyneprocess->setIcon(*indicatorlamp_green);
                }

                if (!strcmp("app_transformer", cur_task_name)){
                    sys_ui->pushButton_app_transformer->setText("transformer_running");
                    sys_ui->pushButton_app_transformer->setIcon(*indicatorlamp_green);
                }

                if (!strcmp("app_mobileye", cur_task_name)){
                    sys_ui->pushButton_app_mobileye->setText("mobileye_running");
                    sys_ui->pushButton_app_mobileye->setIcon(*indicatorlamp_green);
                }

                if (!strcmp("app_mobileye_process", cur_task_name)){
                    sys_ui->pushButton_app_me_process->setText("meprocess_running");
                    sys_ui->pushButton_app_me_process->setIcon(*indicatorlamp_green);
                }

                if (!strcmp("app_viewer", cur_task_name)){
                    sys_ui->pushButton_app_viewer->setText("viewer_running");
                    sys_ui->pushButton_app_viewer->setIcon(*indicatorlamp_green);
                }

                if (!strcmp("app_lane_fusion", cur_task_name)){
                    sys_ui->pushButton_app_lanefusion->setText("lane_fusion_running");
                    sys_ui->pushButton_app_lanefusion->setIcon(*indicatorlamp_green);
                }

                if (!strcmp("app_idc2vcu", cur_task_name)){
                    sys_ui->pushButton_app_idc2vcu->setText("idc2vcu_running");
                    sys_ui->pushButton_app_idc2vcu->setIcon(*indicatorlamp_green);
                }

                if (!strcmp("app_logitech", cur_task_name)){
                    sys_ui->pushButton_app_logitech->setText("logitech_running");
                    sys_ui->pushButton_app_logitech->setIcon(*indicatorlamp_green);
                }

                if (!strcmp("app_vcb", cur_task_name)){
                    sys_ui->pushButton_app_vcb->setText("vcb_running");
                    sys_ui->pushButton_app_vcb->setIcon(*indicatorlamp_green);
                }
                fclose(fp);
            }
            }
        if(repeat_process_checker_adp > 1){
            QMessageBox *dlg = new QMessageBox;
            dlg->setText("[ERROR]: One or More <APP_ADP> is running, please check system monitor!");
            dlg->show();
            repeat_process_checker_adp = 0;
        }
        closedir(dir);
    }
}

void SystemWindow::Refresh_Error_N_Warnings()
{
    QDir dir("../../atd-d2d-integration/applications/log");
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dir.setSorting(QDir::Size | QDir::Reversed);
    QFileInfoList list = dir.entryInfoList();
    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list.at(i);
        if(fileInfo.size())
        {
            sys_ui->tableWidget_Error_Warnings->insertRow(0);
            QString counter_of_ew = "#" + QString("%1").arg(count_of_EW);
            sys_ui->tableWidget_Error_Warnings->setItem(0,0,new QTableWidgetItem(counter_of_ew));
            sys_ui->tableWidget_Error_Warnings->setItem(0,1,new QTableWidgetItem(fileInfo.fileName()));
            QTableWidgetItem *item = new QTableWidgetItem("Error!");
            item->setTextColor(QColor("red"));
            sys_ui->tableWidget_Error_Warnings->setItem(0,2,item);

            QString module_name;
            string line = fileInfo.fileName().toStdString();
            char *str = (char *)malloc((line.length()+1)*sizeof(char));
            line.copy(str,line.length(),0);
            const char* s_delim = "_";
            char *delim = new char[strlen(s_delim)+1];
            strcpy(delim,s_delim);
            char *app_name;
            strtok(str,delim);
            int cc = 0;
            while(app_name = strtok(NULL, delim))
            {
                if(cc >= 5)
                {
                    if(app_name[0]=='e' && app_name[1]=='r' && app_name[2]=='r')
                        break;
                    else
                     module_name+= QString(QLatin1String(app_name));
                }
                cc++;
            }
            QTableWidgetItem *item_module = new QTableWidgetItem(module_name);
            item_module->setTextColor(QColor("red"));
            sys_ui->tableWidget_Error_Warnings->setItem(0,3,item_module);

            QString size_of_file ;
            if(fileInfo.size()>1024)
                size_of_file = QString("%1").arg((fileInfo.size()/1024)) + " kb";
            else
                size_of_file = QString("%1").arg((fileInfo.size())) + " byte";
            sys_ui->tableWidget_Error_Warnings->setItem(0,4, new QTableWidgetItem(size_of_file));
            count_of_EW++;
        }
    }

}

void SystemWindow::Refresh_Network_Statics()
{
    sys_ui->tableWidget_List_Dev_Stats->setItem(0,0,new QTableWidgetItem( QString("eth0")));
    sys_ui->tableWidget_List_Dev_Stats->setItem(1,0,new QTableWidgetItem( QString("eth1")));
    char* recv_bytes_eth0;
    char* recv_pkgs_eth0;
    char* send_bytes_eth0;
    char* send_pkgs_eth0;

    char* recv_bytes_eth1;
    char* recv_pkgs_eth1;
    char* send_bytes_eth1;
    char* send_pkgs_eth1;

    ifstream in;
    string file = "/proc/net/dev";
    in.open(file.c_str());
    if (in.fail())
        cout << "Failed - " << strerror(errno) << endl;
    else{
        while(!in.eof()){
            string line;
            getline(in,line,'\n');
            char *str = (char *)malloc((line.length()+1)*sizeof(char));
            line.copy(str,line.length(),0);
            const char* s_delim = " ";
            char *delim = new char[strlen(s_delim)+1];
            strcpy(delim,s_delim);
            char *eth_channel_name;
            eth_channel_name = strtok(str, delim);
            int cnt_of_decoding = 0;

            if(eth_channel_name[0] == 'e' && eth_channel_name[3] == '0'){
                while(eth_channel_name = strtok(NULL,delim)){
                    if(cnt_of_decoding == 0)
                        recv_bytes_eth0 = eth_channel_name;
                    else if(cnt_of_decoding == 1)
                        recv_pkgs_eth0 = eth_channel_name;
                    else if(cnt_of_decoding == 7)
                        send_bytes_eth0 = eth_channel_name;
                    else if(cnt_of_decoding == 8)
                        send_pkgs_eth0 = eth_channel_name;
                    else{}
                    cnt_of_decoding++;
                }
            }
            else if(eth_channel_name[0] == 'e' && eth_channel_name[3] == '1'){
                while(eth_channel_name = strtok(NULL,delim)){
                    if(cnt_of_decoding == 0)
                        recv_bytes_eth1 = eth_channel_name;
                    else if(cnt_of_decoding == 1)
                        recv_pkgs_eth1 = eth_channel_name;
                    else if(cnt_of_decoding == 7)
                        send_bytes_eth1 = eth_channel_name;
                    else if(cnt_of_decoding == 8)
                        send_pkgs_eth1 = eth_channel_name;
                    else{}
                    cnt_of_decoding++;
                }
            }
            else{}
        }
    }
    sys_ui->tableWidget_List_Dev_Stats->setItem(0,1,new QTableWidgetItem( QString(QLatin1String(recv_bytes_eth0))));
    sys_ui->tableWidget_List_Dev_Stats->setItem(0,2,new QTableWidgetItem( QString(QLatin1String(recv_pkgs_eth0))));
    sys_ui->tableWidget_List_Dev_Stats->setItem(0,3,new QTableWidgetItem( QString(QLatin1String(send_bytes_eth0))));
    sys_ui->tableWidget_List_Dev_Stats->setItem(0,4,new QTableWidgetItem( QString(QLatin1String(send_pkgs_eth0))));

    sys_ui->tableWidget_List_Dev_Stats->setItem(1,1,new QTableWidgetItem( QString(QLatin1String(recv_bytes_eth1))));
    sys_ui->tableWidget_List_Dev_Stats->setItem(1,2,new QTableWidgetItem( QString(QLatin1String(recv_pkgs_eth1))));
    sys_ui->tableWidget_List_Dev_Stats->setItem(1,3,new QTableWidgetItem( QString(QLatin1String(send_bytes_eth1))));
    sys_ui->tableWidget_List_Dev_Stats->setItem(1,4,new QTableWidgetItem( QString(QLatin1String(send_pkgs_eth1))));

    int now_eth1_recv_bytes = atoi(recv_bytes_eth1);
    int recv_speed_eth1 = (now_eth1_recv_bytes-last_recv_bytes_eth1);
    if(recv_speed_eth1 > 1024 && recv_speed_eth1 <=1024*1024)
        sys_ui->tableWidget_List_Dev_Stats->setItem(1,5,new QTableWidgetItem( QString(QString::number(recv_speed_eth1/1024,10,1)+QString("kb/s"))));
    else if(recv_speed_eth1 > 1024*1024 )
        sys_ui->tableWidget_List_Dev_Stats->setItem(1,5,new QTableWidgetItem( QString(QString::number(recv_speed_eth1/1024/1024,10,1)+QString("Mb/s"))));
    else{
        sys_ui->tableWidget_List_Dev_Stats->setItem(1,5,new QTableWidgetItem( QString(QString::number(recv_speed_eth1,10,1)+QString("bytes/s"))));
    }
    last_recv_bytes_eth1 = now_eth1_recv_bytes;

    int now_eth0_recv_bytes = atoi(recv_bytes_eth0);
    int recv_speed_eth0 = (now_eth0_recv_bytes-last_recv_bytes_eth0);
    if(recv_speed_eth0 > 1024 && recv_speed_eth0 <=1024*1024)
        sys_ui->tableWidget_List_Dev_Stats->setItem(0,5,new QTableWidgetItem( QString(QString::number(recv_speed_eth0/1024,10,1)+QString("kb/s"))));
    else if(recv_speed_eth0 > 1024*1024 )
        sys_ui->tableWidget_List_Dev_Stats->setItem(0,5,new QTableWidgetItem( QString(QString::number(recv_speed_eth0/1024/1024,10,1)+QString("Mb/s"))));
    else{
        sys_ui->tableWidget_List_Dev_Stats->setItem(0,5,new QTableWidgetItem( QString(QString::number(recv_speed_eth0,10,1)+QString("bytes/s"))));
    }
    last_recv_bytes_eth0 = now_eth0_recv_bytes;

    int now_eth1_send_bytes = atoi(send_bytes_eth1);
    int send_speed_eth1 = (now_eth1_send_bytes-last_send_bytes_eth1)/1024;
    sys_ui->tableWidget_List_Dev_Stats->setItem(1,6,new QTableWidgetItem( QString(QString::number(send_speed_eth1,10,1)+QString("kb/s"))));
    last_send_bytes_eth1 = now_eth1_send_bytes;

    int now_eth0_send_bytes = atoi(send_bytes_eth0);
    int send_speed_eth0 = (now_eth0_send_bytes-last_send_bytes_eth0)/1024;
    sys_ui->tableWidget_List_Dev_Stats->setItem(0,6,new QTableWidgetItem( QString(QString::number(send_speed_eth0,10,1)+QString("kb/s"))));
    last_send_bytes_eth0 = now_eth0_send_bytes;
    in.close();
}

void SystemWindow::OnMonitorUpdate()
{
    //1.refresh Errors & Warnings Files
    Refresh_Error_N_Warnings();

    //2.refresh Internet/CAN port statics
    //Refresh_Network_Statics();
}

SystemWindow::~SystemWindow()
{
    delete sys_ui;
}

void SystemWindow::init()
{

}

void SystemWindow::on_pushButton_IP_Capture_clicked()
{
    sys_ui->listWidget_IP->clear();
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    foreach (QNetworkInterface netInterface, list) {
        if(netInterface.name()!="lo")
        {
            QList<QNetworkAddressEntry> entryList = netInterface.addressEntries();
            foreach(QNetworkAddressEntry entry, entryList) {
                if(entry.ip().toString().length()<16)
                {
                    QString Device_Name = QString(" IP Address: " + entry.ip().toString() + "---From Device: "+netInterface.name() );
                    sys_ui->listWidget_IP->addItem(new QListWidgetItem(QIcon(INDICATORLAMP_GREEN_PATH),Device_Name));
                }
            }
        }
    }
}

void SystemWindow::keyPressEvent(QKeyEvent *event)
{
    double reference_timestamp = GetGlobalTimeStampInSec();
    if(event->key() == Qt::Key_H && event->modifiers() == Qt::ControlModifier){
        if(event->isAutoRepeat()) return;
        this->window()->showMinimized();
//        log_win->focusWidget();
    }
    if(event->key() == Qt::Key_1 && event->modifiers() == Qt::ControlModifier){
        if(event->isAutoRepeat()) return;
        emit showMainWindow();
    }
    if(event->key() == Qt::Key_3 && event->modifiers() == Qt::ControlModifier){
        if(event->isAutoRepeat()) return;
        emit showLoggerWindow();
    }
    if(event->key() == Qt::Key_4 && event->modifiers() == Qt::ControlModifier){
        if(event->isAutoRepeat()) return;
        emit showCalibrationWindow();
    }
}
