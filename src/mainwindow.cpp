#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sys/statfs.h"
#include "sys/stat.h"
using namespace std;

MainWindow::MainWindow ( QWidget *parent ) :
    QMainWindow ( parent ),
    ui ( new Ui::MainWindow )
{
    reference_timestamp = GetGlobalTimeStampInSec();
    this->setFocusPolicy(Qt::StrongFocus);
    accumulate_ins = count_ins = 0;
    accumulate_vcu = count_vcu = 0;
    accumulate_ibeo = count_ibeo = 0;
    accumulate_melane = count_melane = 0;
    accumulate_meobjects = count_meobjects = 0;
    accumulate_can2proxy = count_can2proxy = 0;
    accumulate_adp_behavior = count_adp_behavior = 0;
    accumulate_tsr = count_tsr = 0;
    accumulate_velodyne = count_velodyne = 0;
    module_status[30] = 0;

    indicatorlamp_red = new QPixmap();
    indicatorlamp_blue = new QPixmap();
    indicatorlamp_green = new QPixmap();
    indicatorlamp_yellow = new QPixmap();
    indicatorlamp_trigger = new QPixmap();

    qRegisterMetaType<Q_VEHICLE_POSE> ( "Q_VEHICLE_POSE" );
    qRegisterMetaType<Q_VCU_VEHICLE_INFO>("Q_VCU_VEHICLE_INFO");
    qRegisterMetaType<Q_EXECUTE_TRAJECTORY>("Q_EXECUTE_TRAJECTORY");
    qRegisterMetaType<Q_MOBILEYE_LINES>("Q_MOBILEYE_LINES");
    qRegisterMetaType<Q_TRACKED_OBSTACLES>("Q_TRACKED_OBSTACLES");
    qRegisterMetaType<Q_IPC2DEV_VELOCITY>("Q_IPC2DEV_VELOCITY");
    //qRegisterMetaType<Q_IBEO_OBJECTS>("Q_IBEO_OBJECTS");
    qRegisterMetaType<Q_EXECUTE_BEHAVIOR_PLAN>("Q_EXECUTE_BEHAVIOR_PLAN");
    qRegisterMetaType<Q_PERCEPTION_TSR>("Q_PERCEPTION_TSR");
    qRegisterMetaType<Q_VELODYNE_POINTS>("Q_VELODYNE_POINTS");
    qRegisterMetaType<Q_PERCEPTIONED_OBJECTS>("Q_PERCEPTIONED_OBJECTS");

    m_gnPlotIndex[0] = 0;
    m_gnPlotIndex[1] = 0;
    m_gnPlotIndex[2] = 0;
    m_gnPlotIndex[3] = 0;
    m_gnPlotIndex[4] = 0;
    m_gnPlotIndex[5] = 0;

    ui->setupUi(this);
    connect ( ui->widgetTop, SIGNAL ( ShowStatusMsg ( QString ) ), this, SLOT ( OnShowStatusMsg ( QString ) ) );
    //this->setWindowTitle ( QString ( "Chart " ) +QString ( GetCurrentDateString().data() ) );
    this->setWindowTitle ( QString ( "IDS-INCA" ));

    ui->tableWidget->setHorizontalHeaderItem ( 0, new QTableWidgetItem ( "Data" ) );
    ui->tableWidget->setColumnWidth ( 0, 120 );

    ui->tableWidget->setHorizontalHeaderItem ( 1, new QTableWidgetItem ( "Value" ) );
    ui->tableWidget->setColumnWidth ( 1, 100 );

    ui->tableWidget->setHorizontalHeaderItem ( 2, new QTableWidgetItem ( "Value" ) );
    ui->tableWidget->setColumnWidth ( 2, 10 );

    ui->tableWidget->setRowCount ( DFI_END );
    for ( int j=0; j<DFI_END; j++ )
    {
        ui->tableWidget->setItem ( j, 0, new QTableWidgetItem ( QString ( "" ) ) ); //set new item as null string;
        ui->tableWidget->item ( j, 0 )->setTextAlignment ( Qt::AlignCenter ); //set item alignment;

        ui->tableWidget->setItem ( j, 1, new QTableWidgetItem ( QString ( "" ) ) );
        ui->tableWidget->item ( j, 1 )->setTextAlignment ( Qt::AlignCenter );
    }

    ui->widgetTop->SetLineStyle ( 0, Qt::darkRed, Qt::DotLine, QCPScatterStyle::ssDisc );
    ui->widgetTop->SetLineStyle ( 1, Qt::darkGreen, Qt::DotLine, QCPScatterStyle::ssDisc );
    ui->widgetTop->SetLineStyle ( 2, Qt::darkYellow, Qt::DotLine, QCPScatterStyle::ssDisc );
    ui->widgetTop->SetLineStyle ( 3, Qt::darkBlue, Qt::DotLine, QCPScatterStyle::ssDisc );

    ui->widgetBottom->SetLineStyle ( 0, Qt::darkCyan, Qt::SolidLine, QCPScatterStyle::ssDisc );
    ui->widgetBottom->SetLineStyle ( 1, Qt::black, Qt::DotLine, QCPScatterStyle::ssDisc );
    ui->widgetBottom->SetLineStyle ( 2, Qt::darkYellow, Qt::DotLine, QCPScatterStyle::ssDisc );
    ui->widgetBottom->SetLineStyle ( 3, Qt::darkBlue, Qt::DotLine, QCPScatterStyle::ssDisc );

    OnScreenShotTextTimeOut();

    m_pUpdateTimer = new QTimer ( this );
    connect ( m_pUpdateTimer, SIGNAL ( timeout() ), this, SLOT ( OnTimeOut() ) ); //, Qt::QueuedConnection);
    m_pUpdateTimer->start ( 50 );

    m_pScreenShotTextTimer = new QTimer ( this );
    connect ( m_pScreenShotTextTimer, SIGNAL ( timeout() ), this, SLOT ( OnScreenShotTextTimeOut() ) ); //, Qt::QueuedConnection);
    m_pScreenShotTextTimer->start ( 500 );

    m_pRefreshTimer = new QTimer ( this );
    connect ( m_pRefreshTimer, SIGNAL ( timeout() ), this, SLOT ( OnRefreshTimeOut() ) );
    m_pRefreshTimer->start ( 100 );

    //vehicle pose;
    connect ( m_lcmSubscriber.m_pLcmHandler, SIGNAL (NewVehiclePose ( Q_VEHICLE_POSE ) ), this, SLOT (OnNewVehiclePose ( Q_VEHICLE_POSE ) ) );

    //execute trajectory;
    connect ( m_lcmSubscriber.m_pLcmHandler, SIGNAL(NewExecuteTrajectory(Q_EXECUTE_TRAJECTORY)), this, SLOT(OnNewExecuteTrajectory(Q_EXECUTE_TRAJECTORY)));

    //vcu vehicle info;
    connect ( m_lcmSubscriber.m_pLcmHandler, SIGNAL(NewVcuVehicleInfo(Q_VCU_VEHICLE_INFO)), this, SLOT(OnNewVcuVehicleInfo(Q_VCU_VEHICLE_INFO)));

    //mobileye lanes:
    connect( m_lcmSubscriber.m_pLcmHandler, SIGNAL(NewMobileyeLaneLines(Q_MOBILEYE_LINES)), this, SLOT(OnNewMobileyeLines(Q_MOBILEYE_LINES)));

    //perception obstacles:
    //front:
    connect( m_lcmSubscriber.m_pLcmHandler, SIGNAL(NewTrackedObstacles(Q_TRACKED_OBSTACLES)), this, SLOT(OnNewTrackedObstacles(Q_TRACKED_OBSTACLES)));

    //real send to vcu:
    //velocity
    connect( m_lcmSubscriber.m_pLcmHandler, SIGNAL(NewIpc2devVelocity(Q_IPC2DEV_VELOCITY)), this, SLOT(OnNewIpc2devVelocity(Q_IPC2DEV_VELOCITY)));

    //perception objects:
    connect( m_lcmSubscriber.m_pLcmHandler, SIGNAL(NewPerceptionedObjs(Q_PERCEPTIONED_OBJECTS)), this, SLOT(OnNewPerceptionObjs(Q_PERCEPTIONED_OBJECTS)));

    //adp behavior:
    connect( m_lcmSubscriber.m_pLcmHandler, SIGNAL(NewExecuteBehaviorPlan(Q_EXECUTE_BEHAVIOR_PLAN)), this, SLOT(OnNewExecuteBehaviorPlan(Q_EXECUTE_BEHAVIOR_PLAN)));

    //tsr:
    connect( m_lcmSubscriber.m_pLcmHandler, SIGNAL(NewPerceptionTsr(Q_PERCEPTION_TSR)), this, SLOT(OnNewPerceptionTsr(Q_PERCEPTION_TSR)));

    //velodyne:
    connect( m_lcmSubscriber.m_pLcmHandler, SIGNAL(NewVelodynePoints(Q_VELODYNE_POINTS)), this, SLOT(OnNewVelodynePoints(Q_VELODYNE_POINTS)));

    //

    m_gstDataFields[DFI_LATITUDE].strFieldName = QString ( "Lat. deg" );

    m_gstDataFields[DFI_LONGITUDE].strFieldName = QString ( "Longi. deg" );

    m_gstDataFields[DFI_ALTITUDE].strFieldName = QString ( "Alti. m" );

    m_gstDataFields[DFI_ACCELERATION_X].strFieldName = QString ( "AccX m/s^2" );

    m_gstDataFields[DFI_ACCELERATION_Y].strFieldName = "AccY m/s^2";

    m_gstDataFields[DFI_ACCELERATION_Z].strFieldName = "AccZ m/s^2";

    m_gstDataFields[DFI_ANGULAR_RATEX].strFieldName = "AngRateX deg/s";

    m_gstDataFields[DFI_ANGULAR_RATEY].strFieldName = "AngRateY deg/s";

    m_gstDataFields[DFI_ANGULAR_RATEZ].strFieldName = "AngRateZ deg/s";

    m_gstDataFields[DFI_HEADING].strFieldName = "Heading deg";

    m_gstDataFields[DFI_PITCH].strFieldName = "Pitch deg";

    m_gstDataFields[DFI_ROLL].strFieldName = "Roll deg";

    m_gstDataFields[DFI_VELOCITY_NORTH].strFieldName = "VelNorth m/s";

    m_gstDataFields[DFI_VELOCITY_WEST].strFieldName = "VelWest m/s";

    m_gstDataFields[DFI_VELOCITY_UP].strFieldName = "VelUp m/s";

    m_gstDataFields[DFI_SPEED].strFieldName = "Speed kph";

    m_gstDataFields[DFI_DESIRED_SPEED].strFieldName = "DesSpeed kph";

    m_gstDataFields[DFI_STEER_ANGLE].strFieldName = "Steer deg";

    m_gstDataFields[DFI_FRONT_LEFT_WHEEL_SPEED].strFieldName = "FLSpeed m/s";

    m_gstDataFields[DFI_FRONT_RIGHT_WHEEL_SPEED].strFieldName = "FRSpeed m/s";

    m_gstDataFields[DFI_REAR_LEFT_WHEEL_SPEED].strFieldName = "RLSpeed m/s";

    m_gstDataFields[DFI_REAR_RIGHT_WHEEL_SPEED].strFieldName = "RRSpeed m/s";

    m_gstDataFields[DFI_LEFT_LINE_DIST].strFieldName = "LineDist_L m";

    m_gstDataFields[DFI_RIGHT_LINE_DIST].strFieldName = "LineDist_R m";

    m_gstDataFields[DFI_FRONT_OBSTACLE_DIST].strFieldName = "FrnObjDist m";

    m_gstDataFields[DFI_IPC2VCU_VELOCITY].strFieldName = "VelCmd kph";

    m_gstDataFields[DFI_PERCEPTIONED_OBJ].strFieldName = "FrontObj m";

    m_gstDataFields[DFI_ADP_STATUS].strFieldName = "ADP_behavior";

    m_gstDataFields[DFI_TSR].strFieldName = "TSR";

    for ( int i=0; i<DFI_END; i++ )
    {
        ui->tableWidget->item ( i, 0 )->setText ( m_gstDataFields[i].strFieldName );

        ui->comboBox_chart1_x->addItem ( m_gstDataFields[i].strFieldName );
        ui->comboBox_chart1_y->addItem ( m_gstDataFields[i].strFieldName );
        ui->comboBox_chart2_x->addItem ( m_gstDataFields[i].strFieldName );
        ui->comboBox_chart2_y->addItem ( m_gstDataFields[i].strFieldName );
    }

    sys_window_open = false;
    log_window_open = false;
    cali_window_open = false;

    sys_win = new SystemWindow(this);
    connect(sys_win,SIGNAL(sendData(bool)),this,SLOT(receiveData(bool)));
    connect(sys_win,SIGNAL(showMainWindow()),this,SLOT(OnshowMainWindow()));

    log_win = new LoggerWindow(this);
    connect(log_win,SIGNAL(sendData(bool)),this,SLOT(on_recv_log_win_status(bool)));

    cali_win = new CalibrationWindow(this);
    connect(cali_win,SIGNAL(sendData(bool)),this,SLOT(on_recv_cali_win_status(bool)));

}

void MainWindow::receiveData(bool status)
{
    sys_window_open = false;
    if(ui->pushButton_loadsys->isChecked())
        ui->pushButton_loadsys->toggle();
}

void MainWindow::on_recv_log_win_status(bool status)
{
    log_window_open = false;
    if(ui->pushButton_data_logger->isChecked())
        ui->pushButton_data_logger->toggle();
}

void MainWindow::on_recv_cali_win_status(bool status)
{
    cali_window_open = false;
    if(ui->pushButton_calibration->isChecked())
        ui->pushButton_calibration->toggle();
}

MainWindow::~MainWindow()
{
    delete ui;

    delete indicatorlamp_red;
    delete indicatorlamp_blue;
    delete indicatorlamp_green;
    delete indicatorlamp_yellow;
    delete indicatorlamp_trigger;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    sys_win->close();//close relevant child windows;
    log_win->close();
    cali_win->close();
}

void MainWindow::init()
{
    model_melane = new QStandardItemModel();
    model_vcu    = new QStandardItemModel();
    model_vehiclepose = new QStandardItemModel();

    /*tab 2 settings*/
    QScrollArea *s = new QScrollArea(ui->tab_2);
    s->setGeometry(10,10,1320,760);
    s->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    QWidget *w = new QWidget(s);
    w->setLayout(ui->gridLayout_5);
    w->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    s->setWidget(w);
    //w->setGeometry(0, 0, 1000, 700);
    ui->tableView_can2proxy->hide();
    ui->tableView_can_Message->hide();
    ui->tableView_esr->hide();
    ui->tableView_ethernet->hide();
    ui->tableView_ibeo->hide();
    ui->tableView_idc->hide();
    ui->tableView_inertial->hide();
    ui->tableView_melane->hide();
    ui->tableView_meobs->hide();
    ui->tableView_tsr->hide();
    ui->tableView_vcu->hide();
    ui->tableView_rsds->hide();
    ui->tableView_velodyne->hide();

    ui->visible_tablewidget->setChecked(true);
    ui->visible_Debug_window->setChecked(true);

    ui->pushButton_meobj->setChecked(false);
    ui->pushButton_lane->setChecked(false);
    ui->pushButton_canprocy->setChecked(false);
    ui->pushButton_esr->setChecked(false);
    ui->pushButton_ibeo->setChecked(false);
    ui->pushButton_idc->setChecked(false);
    ui->pushButton_ins->setChecked(false);
    ui->pushButton_velodyne->setChecked(false);
    ui->pushButton_vcu->setChecked(false);
    ui->pushButton_tsr->setChecked(false);
    ui->pushButton_rsds->setChecked(false);

    ui->pushButton_detail_ethernet->setChecked(false);
    ui->pushButton_detail_can->setChecked(false);

    indicatorlamp_red->load(INDICATORLAMP_RED_PATH);
    indicatorlamp_blue->load(INDICATORLAMP_PURPLE_PATH);
    indicatorlamp_green->load(INDICATORLAMP_GREEN_PATH);
    indicatorlamp_yellow->load(INDICATORLAMP_YELLOW_PATH);
    indicatorlamp_trigger->load(INDICATORLAMP_TRIGGER_PATH);

    ui->pushButton_Log_Trigger->setIcon(*indicatorlamp_trigger);
    ui->pushButton_Log_Trigger->setIconSize(QSize(ui->pushButton_Log_Trigger->width()+10,
                                                  ui->pushButton_Log_Trigger->height()+10));

    ui->pushButton_lane->setIcon(*indicatorlamp_red);
    ui->pushButton_lane->setIconSize(QSize(ui->pushButton_lane->width()-10,
                                           ui->pushButton_lane->height()-10));
    ui->pushButton_vcu->setIcon(*indicatorlamp_red);
    ui->pushButton_vcu->setIconSize(QSize(ui->pushButton_vcu->width()-10,
                                          ui->pushButton_vcu->height()-10));
    ui->pushButton_canprocy->setIcon(*indicatorlamp_red);
    ui->pushButton_canprocy->setIconSize(QSize(ui->pushButton_canprocy->width()-10,
                                               ui->pushButton_canprocy->height()-10));
    ui->pushButton_ibeo ->setIcon(*indicatorlamp_red);
    ui->pushButton_ibeo->setIconSize(QSize(ui->pushButton_ibeo->width()-10,
                                           ui->pushButton_ibeo->height()-10));
    ui->pushButton_idc->setIcon(*indicatorlamp_red);
    ui->pushButton_idc->setIconSize(QSize(ui->pushButton_idc->width()-10,
                                          ui->pushButton_idc->height()-10));
    ui->pushButton_ins->setIcon(*indicatorlamp_red);
    ui->pushButton_ins->setIconSize(QSize(ui->pushButton_ins->width()-10,
                                          ui->pushButton_ins->height()-10));
    ui->pushButton_meobj->setIcon(*indicatorlamp_red);
    ui->pushButton_meobj->setIconSize(QSize(ui->pushButton_meobj->width()-10,
                                            ui->pushButton_meobj->height()-10));
    ui->pushButton_tsr->setIcon(*indicatorlamp_red);
    ui->pushButton_tsr->setIconSize(QSize(ui->pushButton_tsr->width()-10,
                                          ui->pushButton_tsr->height()-10));
    ui->pushButton_esr->setIcon(*indicatorlamp_red);
    ui->pushButton_esr->setIconSize(QSize(ui->pushButton_esr->width()-10,
                                          ui->pushButton_esr->height()-10));
    ui->pushButton_velodyne->setIcon(*indicatorlamp_red);
    ui->pushButton_velodyne->setIconSize(QSize(ui->pushButton_velodyne->width()-10,
                                               ui->pushButton_velodyne->height()-10));
    ui->pushButton_esr->setIcon(*indicatorlamp_red);
    ui->pushButton_esr->setIconSize(QSize(ui->pushButton_esr->width()-10,
                                          ui->pushButton_esr->height()-10));
    ui->pushButton_rsds->setIcon(*indicatorlamp_red);
    ui->pushButton_rsds->setIconSize(QSize(ui->pushButton_rsds->width()-10,
                                           ui->pushButton_rsds->height()-10));
}

void MainWindow::OnShowStatusMsg ( QString msg )
{
    this->ui->statusBar->clearMessage();
    this->ui->statusBar->showMessage ( msg );
}

void MainWindow::OnTimeOut()
{
    double key = QDateTime::currentDateTime().toMSecsSinceEpoch() /1000.0; //double key = GetGlobalTimeStamp()%100000000/1000000.0;
    double value0 = qSin ( key ) *100 + rand() %10; //rand()%10*0.0000001;//+rand()%5; //randr()%10;//qSin(key); //qSin(key*1.6+qCos(key*1.7)*2)*10 + qSin(key*1.2+0.56)*20 + 26;
    double value1 = qCos ( key ) *100 + rand() %20+20.0;
}

void MainWindow::OnRefreshTimeOut()
{
    if(count_ins - accumulate_ins != 0){
        ui->pushButton_ins->setIcon(*indicatorlamp_red);
    }
    else
        ui->pushButton_ins->setIcon(*indicatorlamp_green);
    count_ins++;

    if(count_vcu - accumulate_vcu != 0){
        ui->pushButton_vcu->setIcon(*indicatorlamp_red);
    }
    else
        ui->pushButton_vcu->setIcon(*indicatorlamp_green);
    count_vcu++;

    if(count_ibeo - accumulate_ibeo != 0){
        ui->pushButton_ibeo->setIcon(*indicatorlamp_red);
    }
    else
        ui->pushButton_ibeo->setIcon(*indicatorlamp_green);
    count_ibeo++;

    if(count_melane - accumulate_melane != 0){
        ui->pushButton_lane->setIcon(*indicatorlamp_red);
    }
    else
        ui->pushButton_lane->setIcon(*indicatorlamp_green);
    count_melane++;

    if(count_meobjects - accumulate_meobjects != 0){
        ui->pushButton_meobj->setIcon(*indicatorlamp_red);
    }
    else
        ui->pushButton_meobj->setIcon(*indicatorlamp_green);
    count_meobjects++;

    if(count_can2proxy - accumulate_can2proxy != 0){
        ui->pushButton_canprocy->setIcon(*indicatorlamp_red);
    }
    else
        ui->pushButton_canprocy->setIcon(*indicatorlamp_green);
    count_can2proxy++;

    if(count_adp_behavior - accumulate_adp_behavior != 0){
        ui->pushButton_idc->setIcon(*indicatorlamp_red);
    }
    else
        ui->pushButton_idc->setIcon(*indicatorlamp_green);
    count_adp_behavior++;

    if(count_tsr - accumulate_tsr != 0){
        ui->pushButton_tsr->setIcon(*indicatorlamp_red);
    }
    else
        ui->pushButton_tsr->setIcon(*indicatorlamp_green);
    count_tsr++;

    if(count_velodyne - accumulate_velodyne != 0){
        ui->pushButton_velodyne->setIcon(*indicatorlamp_red);
    }
    else
        ui->pushButton_velodyne->setIcon(*indicatorlamp_green);
    count_velodyne++;
}

void MainWindow::OnScreenShotTextTimeOut()
{
    on_pushButton_datastatics_clicked();
    emit Send_Module_Status(module_status);
}

void MainWindow::OnNewVcuVehicleInfo ( Q_VCU_VEHICLE_INFO vcuVehicleInfo )
{
    double timestamp = GetGlobalTimeStampInSec();
    accumulate_vcu +=1;
    count_vcu = accumulate_vcu;

    ui->tableWidget->item ( DFI_STEER_ANGLE, 1 )->setText ( QString::asprintf ( "%.3f", vcuVehicleInfo.fSteeringAngle ) );
    AppendPlotData ( DFI_STEER_ANGLE, timestamp, vcuVehicleInfo.fSteeringAngle );

    ui->tableWidget->item ( DFI_FRONT_LEFT_WHEEL_SPEED, 1 )->setText ( QString::asprintf ( "%.3f", vcuVehicleInfo.fFrontLeftWheelSpeed ) );
    AppendPlotData ( DFI_FRONT_LEFT_WHEEL_SPEED, timestamp, vcuVehicleInfo.fFrontLeftWheelSpeed );

    ui->tableWidget->item ( DFI_FRONT_RIGHT_WHEEL_SPEED, 1 )->setText ( QString::asprintf ( "%.3f", vcuVehicleInfo.fFrontRightWheelSpeed ) );
    AppendPlotData ( DFI_FRONT_RIGHT_WHEEL_SPEED, timestamp, vcuVehicleInfo.fFrontRightWheelSpeed );

    ui->tableWidget->item ( DFI_REAR_LEFT_WHEEL_SPEED, 1 )->setText ( QString::asprintf ( "%.3f", vcuVehicleInfo.fRearLeftWheelSpeed ) );
    AppendPlotData ( DFI_REAR_LEFT_WHEEL_SPEED, timestamp, vcuVehicleInfo.fRearLeftWheelSpeed );

    ui->tableWidget->item ( DFI_REAR_RIGHT_WHEEL_SPEED, 1 )->setText ( QString::asprintf ( "%.3f", vcuVehicleInfo.fRearRightWheelSpeed ) );
    AppendPlotData ( DFI_REAR_RIGHT_WHEEL_SPEED, timestamp, vcuVehicleInfo.fRearRightWheelSpeed );

    //detailed messages decoding...
    model_vcu->setColumnCount(4);
    model_vcu->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("Timestamp"));
    model_vcu->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("Message Name"));
    model_vcu->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("Value"));
    model_vcu->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("..."));
    ui->tableView_vcu->setModel(model_vcu);
    ui->tableView_vcu->setColumnWidth(0,200);
    ui->tableView_vcu->setColumnWidth(1,200);
    ui->tableView_vcu->setColumnWidth(2,200);
    ui->tableView_vcu->setColumnWidth(3,ui->tableView_vcu->width()-620);
    for(int i = 0; i < 5; i++){
        model_vcu->setItem(i,0,new QStandardItem(QString::number(timestamp,10,2)));
        model_vcu->item(i,0)->setForeground(QBrush(QColor(255, 0, 0)));
        model_vcu->item(i,0)->setTextAlignment(Qt::AlignCenter);
    }
    model_vcu->setItem(0,1,new QStandardItem(QString("fFrontLeftWheelSpeed")));
    model_vcu->setItem(0,2,new QStandardItem(QString::number(vcuVehicleInfo.fFrontLeftWheelSpeed,10,2)));
    model_vcu->setItem(1,1,new QStandardItem(QString("fFrontRightWheelSpeed")));
    model_vcu->setItem(1,2,new QStandardItem(QString::number(vcuVehicleInfo.fFrontRightWheelSpeed,10,2)));
    model_vcu->setItem(2,1,new QStandardItem(QString("fRearLeftWheelSpeed")));
    model_vcu->setItem(2,2,new QStandardItem(QString::number(vcuVehicleInfo.fRearLeftWheelSpeed,10,2)));
    model_vcu->setItem(3,1,new QStandardItem(QString("fRearRightWheelSpeed")));
    model_vcu->setItem(3,2,new QStandardItem(QString::number(vcuVehicleInfo.fRearRightWheelSpeed,10,2)));
    model_vcu->setItem(4,1,new QStandardItem(QString("fSteeringAngle")));
    model_vcu->setItem(4,2,new QStandardItem(QString::number(vcuVehicleInfo.fSteeringAngle,10,2)));

    module_status[0] = 1;


    return;
}

void MainWindow::OnNewVehiclePose ( Q_VEHICLE_POSE vehiclePose )
{
    double timestamp = GetGlobalTimeStampInSec();
    accumulate_ins +=1;
    count_ins = accumulate_ins;
    ui->tableWidget->item ( DFI_ACCELERATION_X, 1 )->setText ( QString::asprintf ( "%.3f", vehiclePose.fAccX ) );
    AppendPlotData ( DFI_ACCELERATION_X, timestamp, vehiclePose.fAccX );

    ui->tableWidget->item ( DFI_ACCELERATION_Y, 1 )->setText ( QString::asprintf ( "%.3f", vehiclePose.fAccY ) );
    AppendPlotData ( DFI_ACCELERATION_Y, timestamp, vehiclePose.fAccY );

    ui->tableWidget->item ( DFI_ACCELERATION_Z, 1 )->setText ( QString::asprintf ( "%.3f", vehiclePose.fAccZ ) );
    AppendPlotData ( DFI_ACCELERATION_Z, timestamp, vehiclePose.fAccZ );

    ui->tableWidget->item ( DFI_LATITUDE, 1 )->setText ( QString::asprintf ( "%.8lf", vehiclePose.fLatitude ) );
    AppendPlotData ( DFI_LATITUDE, timestamp, vehiclePose.fLatitude );

    ui->tableWidget->item ( DFI_LONGITUDE, 1 )->setText ( QString::asprintf ( "%.8lf", vehiclePose.fLongitude ) );
    AppendPlotData ( DFI_LONGITUDE, timestamp, vehiclePose.fLongitude );

    ui->tableWidget->item ( DFI_ALTITUDE, 1 )->setText ( QString::asprintf ( "%.3f", vehiclePose.fAltitude ) );
    AppendPlotData ( DFI_ALTITUDE, timestamp, vehiclePose.fAltitude );

    ui->tableWidget->item ( DFI_ANGULAR_RATEX, 1 )->setText ( QString::asprintf ( "%.3f", vehiclePose.fAngRateX ) );
    AppendPlotData ( DFI_ANGULAR_RATEX, timestamp, vehiclePose.fAngRateX );

    ui->tableWidget->item ( DFI_ANGULAR_RATEY, 1 )->setText ( QString::asprintf ( "%.3f", vehiclePose.fAngRateY ) );
    AppendPlotData ( DFI_ANGULAR_RATEY, timestamp, vehiclePose.fAngRateY );

    ui->tableWidget->item ( DFI_ANGULAR_RATEZ, 1 )->setText ( QString::asprintf ( "%.3f", vehiclePose.fAngRateZ ) );
    AppendPlotData ( DFI_ANGULAR_RATEZ, timestamp, vehiclePose.fAngRateZ );

    ui->tableWidget->item ( DFI_HEADING, 1 )->setText ( QString::asprintf ( "%.3f", vehiclePose.fHeading ) );
    AppendPlotData ( DFI_HEADING, timestamp, vehiclePose.fHeading );

    ui->tableWidget->item ( DFI_PITCH, 1 )->setText ( QString::asprintf ( "%.3f", vehiclePose.fPitch ) );
    AppendPlotData ( DFI_PITCH, timestamp, vehiclePose.fPitch );

    ui->tableWidget->item ( DFI_ROLL, 1 )->setText ( QString::asprintf ( "%.3f", vehiclePose.fRoll ) );
    AppendPlotData ( DFI_ROLL, timestamp, vehiclePose.fRoll );

    ui->tableWidget->item ( DFI_VELOCITY_NORTH, 1 )->setText ( QString::asprintf ( "%.3f", vehiclePose.fVelNorth ) );
    AppendPlotData ( DFI_VELOCITY_NORTH, timestamp, vehiclePose.fVelNorth );

    ui->tableWidget->item ( DFI_VELOCITY_WEST, 1 )->setText ( QString::asprintf ( "%.3f", vehiclePose.fVelWest ) );
    AppendPlotData ( DFI_VELOCITY_WEST, timestamp, vehiclePose.fVelWest );

    ui->tableWidget->item ( DFI_VELOCITY_UP, 1 )->setText ( QString::asprintf ( "%.3f", vehiclePose.fVelUp ) );
    AppendPlotData ( DFI_VELOCITY_UP, timestamp, vehiclePose.fVelUp );

    ui->tableWidget->item ( DFI_SPEED, 1 )->setText ( QString::asprintf ( "%.3f", vehiclePose.fSpeed ) );
    AppendPlotData ( DFI_SPEED, timestamp, vehiclePose.fSpeed );
    //detailed messages decoding...
    model_vehiclepose->setColumnCount(4);
    model_vehiclepose->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("Timestamp"));
    model_vehiclepose->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("Message Name"));
    model_vehiclepose->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("Value"));
    model_vehiclepose->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("..."));
    ui->tableView_inertial->setModel(model_vehiclepose);
    ui->tableView_inertial->setColumnWidth(0,200);
    ui->tableView_inertial->setColumnWidth(1,200);
    ui->tableView_inertial->setColumnWidth(2,200);
    ui->tableView_inertial->setColumnWidth(3,ui->tableView_inertial->width()-620);
    for(int i = 0; i < 16; i++){
        model_vehiclepose->setItem(i,0,new QStandardItem(QString::number(timestamp,10,2)));
        model_vehiclepose->item(i,0)->setForeground(QBrush(QColor(255, 0, 0)));
        model_vehiclepose->item(i,0)->setTextAlignment(Qt::AlignCenter);
    }
    model_vehiclepose->setItem(0,1,new QStandardItem(QString("fAccX")));
    model_vehiclepose->setItem(0,2,new QStandardItem(QString::number(vehiclePose.fAccX,10,2)));
    model_vehiclepose->setItem(1,1,new QStandardItem(QString("fAccY")));
    model_vehiclepose->setItem(1,2,new QStandardItem(QString::number(vehiclePose.fAccY,10,2)));
    model_vehiclepose->setItem(2,1,new QStandardItem(QString("fAccZ")));
    model_vehiclepose->setItem(2,2,new QStandardItem(QString::number(vehiclePose.fAccZ,10,2)));
    model_vehiclepose->setItem(3,1,new QStandardItem(QString("fAltitude")));
    model_vehiclepose->setItem(3,2,new QStandardItem(QString::number(vehiclePose.fAltitude,10,2)));
    model_vehiclepose->setItem(4,1,new QStandardItem(QString("fAngRateX")));
    model_vehiclepose->setItem(4,2,new QStandardItem(QString::number(vehiclePose.fAngRateX,10,2)));
    model_vehiclepose->setItem(5,1,new QStandardItem(QString("fAngRateY")));
    model_vehiclepose->setItem(5,2,new QStandardItem(QString::number(vehiclePose.fAngRateY,10,2)));
    model_vehiclepose->setItem(6,1,new QStandardItem(QString("fAngRateZ")));
    model_vehiclepose->setItem(6,2,new QStandardItem(QString::number(vehiclePose.fAngRateZ,10,2)));
    model_vehiclepose->setItem(7,1,new QStandardItem(QString("fHeading")));
    model_vehiclepose->setItem(7,2,new QStandardItem(QString::number(vehiclePose.fHeading,10,2)));
    model_vehiclepose->setItem(8,1,new QStandardItem(QString("fLatitude")));
    model_vehiclepose->setItem(8,2,new QStandardItem(QString::number(vehiclePose.fLatitude,10,2)));
    model_vehiclepose->setItem(9,1,new QStandardItem(QString("fLongitude")));
    model_vehiclepose->setItem(9,2,new QStandardItem(QString::number(vehiclePose.fLongitude,10,2)));
    model_vehiclepose->setItem(10,1,new QStandardItem(QString("fPitch")));
    model_vehiclepose->setItem(10,2,new QStandardItem(QString::number(vehiclePose.fPitch,10,2)));
    model_vehiclepose->setItem(11,1,new QStandardItem(QString("fRoll")));
    model_vehiclepose->setItem(11,2,new QStandardItem(QString::number(vehiclePose.fRoll,10,2)));
    model_vehiclepose->setItem(12,1,new QStandardItem(QString("fSpeed")));
    model_vehiclepose->setItem(12,2,new QStandardItem(QString::number(vehiclePose.fSpeed,10,2)));
    model_vehiclepose->setItem(13,1,new QStandardItem(QString("fVelNorth")));
    model_vehiclepose->setItem(13,2,new QStandardItem(QString::number(vehiclePose.fVelNorth,10,2)));
    model_vehiclepose->setItem(14,1,new QStandardItem(QString("fVelUp")));
    model_vehiclepose->setItem(14,2,new QStandardItem(QString::number(vehiclePose.fVelUp,10,2)));
    model_vehiclepose->setItem(15,1,new QStandardItem(QString("fVelWest")));
    model_vehiclepose->setItem(15,2,new QStandardItem(QString::number(vehiclePose.fVelWest,10,2)));

    module_status[1] = 1;
}

void MainWindow::OnNewExecuteTrajectory ( Q_EXECUTE_TRAJECTORY executeTrajectory )
{
      double timestamp = GetGlobalTimeStampInSec();
      ui->tableWidget->item(DFI_DESIRED_SPEED, 1)->setText(QString::asprintf("%.3f", executeTrajectory.fDesiredSpeed));
      AppendPlotData(DFI_DESIRED_SPEED, timestamp, executeTrajectory.fDesiredSpeed);
}

void MainWindow::OnNewMobileyeLines(Q_MOBILEYE_LINES mobileyeLines)
{
    double timestamp = GetGlobalTimeStampInSec();
    accumulate_melane +=1;
    count_melane = accumulate_melane;
    ui->tableWidget->item(DFI_LEFT_LINE_DIST, 1)->setText(QString::asprintf("%.3f", mobileyeLines.fLeftLineDist));
    ui->tableWidget->item(DFI_RIGHT_LINE_DIST, 1)->setText(QString::asprintf("%.3f", mobileyeLines.fRightLineDist));
    AppendPlotData(DFI_LEFT_LINE_DIST, timestamp, mobileyeLines.fLeftLineDist);
    AppendPlotData(DFI_RIGHT_LINE_DIST, timestamp, mobileyeLines.fRightLineDist);
    //detailed messages decoding...

    model_melane->setColumnCount(4);
    model_melane->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("Timestamp"));
    model_melane->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("Message Name"));
    model_melane->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("Value"));
    model_melane->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("..."));
    ui->tableView_melane->setModel(model_melane);
    ui->tableView_melane->setColumnWidth(0,200);
    ui->tableView_melane->setColumnWidth(1,200);
    ui->tableView_melane->setColumnWidth(2,200);
    ui->tableView_melane->setColumnWidth(3,ui->tableView_melane->width()-620);
    for(int i = 0; i < 4; i++){
        model_melane->setItem(i,0,new QStandardItem(QString::number(timestamp,10,2)));
        model_melane->item(i,0)->setForeground(QBrush(QColor(255, 0, 0)));
        model_melane->item(i,0)->setTextAlignment(Qt::AlignCenter);
    }
    model_melane->setItem(0,1,new QStandardItem(QString("stLeftLine")));
        model_melane->setItem(0,2,new QStandardItem(QString::number(mobileyeLines.fLeftLineDist,10,2)));
    model_melane->setItem(1,1,new QStandardItem(QString("stRightLine")));
        model_melane->setItem(1,2,new QStandardItem(QString::number(mobileyeLines.fRightLineDist,10,2)));
    model_melane->setItem(2,1,new QStandardItem(QString("stNextLeftLine")));
        model_melane->setItem(2,2,new QStandardItem(QString::number(0,10,2)));
    model_melane->setItem(3,1,new QStandardItem(QString("stNextRightLine")));
        model_melane->setItem(3,2,new QStandardItem(QString::number(0,10,2)));
}

void MainWindow::OnNewTrackedObstacles(Q_TRACKED_OBSTACLES tracked_obstacles)
{
    double timestamp = GetGlobalTimeStampInSec();
    accumulate_meobjects +=1;
    count_meobjects = accumulate_meobjects;

    ui->tableWidget->item(DFI_FRONT_OBSTACLE_DIST, 1)->setText(QString::asprintf("%.3f", tracked_obstacles.gstTrackedObjectes[0].stAbsBoxCenter.x));
    AppendPlotData(DFI_FRONT_OBSTACLE_DIST, timestamp, tracked_obstacles.gstTrackedObjectes[0].stAbsBoxCenter.x);

}

void MainWindow::OnNewIpc2devVelocity(Q_IPC2DEV_VELOCITY ipc2dev_velocity)
{
    double timestamp = GetGlobalTimeStampInSec();
    accumulate_can2proxy +=1;
    count_can2proxy = accumulate_can2proxy;
    ipc2dev_velocity.gbData[4];
        fprintf(stderr,"%d,%d,%d,%d,%d,%d,%d,%d\n",ipc2dev_velocity.gbData[4][0],ipc2dev_velocity.gbData[4][1],
                ipc2dev_velocity.gbData[4][2],ipc2dev_velocity.gbData[4][3],
                ipc2dev_velocity.gbData[4][4],ipc2dev_velocity.gbData[4][5],
                ipc2dev_velocity.gbData[4][6],ipc2dev_velocity.gbData[4][7]);
        ui->tableWidget->item(DFI_IPC2VCU_VELOCITY, 1)->setText(QString::asprintf("%.3f",ipc2dev_velocity ));
        //AppendPlotData(DFI_IPC2VCU_VELOCITY, timestamp,ipc2dev_velocity. );
}

void MainWindow::OnNewPerceptionObjs(Q_PERCEPTIONED_OBJECTS perception_objects)
{
    double timestamp = GetGlobalTimeStampInSec();
    accumulate_ibeo +=1;
    count_ibeo = accumulate_ibeo;

    ui->tableWidget->item(DFI_PERCEPTIONED_OBJ, 1)->setText(QString::asprintf("%.3f", perception_objects.gstMiddleLaneObstacles[0].fDistance));
    AppendPlotData(DFI_PERCEPTIONED_OBJ, timestamp, perception_objects.gstMiddleLaneObstacles[0].fDistance);
}

void MainWindow::OnNewExecuteBehaviorPlan(Q_EXECUTE_BEHAVIOR_PLAN execute_behavior_plan)
{
    double timestamp = GetGlobalTimeStampInSec();
    accumulate_adp_behavior +=1;
    count_adp_behavior = accumulate_adp_behavior;
    //printf("current behavior is: %d \n",execute_behavior_plan.n_current_behavior);
    ui->tableWidget->item(DFI_ADP_STATUS, 1)->setText(QString::asprintf("%d",execute_behavior_plan.n_current_behavior ));
    AppendPlotData(DFI_ADP_STATUS, timestamp, 20*execute_behavior_plan.n_current_behavior);
}

void MainWindow::OnNewPerceptionTsr(Q_PERCEPTION_TSR perception_tsr)
{
    accumulate_tsr +=1;
    count_tsr = accumulate_tsr;
}

void MainWindow::OnNewVelodynePoints(Q_VELODYNE_POINTS velodyne_points)
{
    accumulate_velodyne +=1;
    count_velodyne = accumulate_velodyne;
}

void MainWindow::AppendPlotData ( int dataFieldIndex, double timestamp, double value )
{
    dataFieldIndex += 1;
    if (dataFieldIndex == m_gnPlotIndex[0]){
        ui->widgetTop->AppendData2Line1 ( timestamp, value );
    }
    if ( dataFieldIndex==m_gnPlotIndex[1] ){
        ui->widgetTop->AppendData2Line2 ( timestamp, value );
    }
    if ( dataFieldIndex==m_gnPlotIndex[2] ){
        ui->widgetTop->AppendData2Line3 ( timestamp, value );
    }
    if ( dataFieldIndex==m_gnPlotIndex[3] ){
        ui->widgetTop->AppendData2Line4 ( timestamp, value );
    }
    if ( dataFieldIndex==m_gnPlotIndex[4] ){
        ui->widgetBottom->AppendData2Line1 ( timestamp, value );
    }
    if ( dataFieldIndex==m_gnPlotIndex[5] ){
        ui->widgetBottom->AppendData2Line2 ( timestamp, value );
    }    
    if ( dataFieldIndex==m_gnPlotIndex[6] ){
        ui->widgetBottom->AppendData2Line3 ( timestamp, value );
    }
    if ( dataFieldIndex==m_gnPlotIndex[7] ){
        ui->widgetBottom->AppendData2Line4 ( timestamp, value );
    }
}

void MainWindow::on_pushButton_loadsys_clicked()
{
    //analyze the system status from a seperated interface:

    if(sys_window_open == false)
    {
        sys_win->show();
        sys_window_open = true;
    }
    else
    {
        //pop out a window:
        QMessageBox *dlg = new QMessageBox;
        dlg->setText("WARNING: Already Running An System Monitor!");
        dlg->show();
    }

    //software modules:according to run.sh file
    ifstream in;
    in.open("../../../atd-d2d-integration/applications/bin/run.sh");
    if(!in)
    {
        ui->DebugOutput->setTextColor(QColor("red"));
        ui->DebugOutput->setText("ERROR[Sys_Chart]:Failed to Read run.sh");
        ui->DebugOutput->setTextColor(QColor("black"));
        return;
    }
    else
    {
        ui->DebugOutput->setText("run.sh File has been Detected! Checking For Modules ...");
    }

    while(!in.eof())
    {
        string line;
        getline(in,line,'\n');
        if(line[0] == '#'){
            //            cerr<<"note line, skipped!"<<endl;
        }
        else if(line[0] == '.')
        {
            char *str = (char *)malloc((line.length()+1)*sizeof(char));
            line.copy(str,line.length(),0);
            const char* s_delim = " ";
            char *delim = new char[strlen(s_delim)+1];
            strcpy(delim,s_delim);
            char *app_name;
            app_name = strtok(str, delim);
            //ui->DebugOutput->setText(app_name);
        }
        else{
            //            cerr<<"blank lines or basic lines, skipped!"<<endl;
        }
    }
    //software module frequecy:according to normal

    //cpu load

    //computer storage

    //
}

void MainWindow::on_comboBox_chart1_x_currentIndexChanged(int index)
{
    ui->widgetTop->graph ( 0 )->clearData();
    if ( index!=0 ){
        ui->widgetTop->UpdateLegendLineName ( 0, m_gstDataFields[index-1].strFieldName );
    }else{
        ui->widgetTop->UpdateLegendLineName ( 0, "NULL" );
    }
    m_gnPlotIndex[0] = index;
}

void MainWindow::on_comboBox_chart1_y_currentIndexChanged(int index)
{
    ui->widgetTop->graph ( 0 )->clearData();
    if ( index!=0 ){
        ui->widgetTop->UpdateLegendLineName ( 1, m_gstDataFields[index-1].strFieldName );
    }else{
        ui->widgetTop->UpdateLegendLineName ( 1, "NULL" );
    }
    m_gnPlotIndex[3] = index;
}

void MainWindow::on_comboBox_chart2_x_currentIndexChanged(int index)
{
    ui->widgetBottom->graph ( 0 )->clearData();
    if ( index!=0 ){
        ui->widgetBottom->UpdateLegendLineName ( 0, m_gstDataFields[index-1].strFieldName );
    }else{
        ui->widgetBottom->UpdateLegendLineName ( 0, "NULL" );
    }
    m_gnPlotIndex[4] = index;
}

void MainWindow::on_comboBox_chart2_y_currentIndexChanged(int index)
{
    ui->widgetBottom->graph ( 0 )->clearData();
    if ( index!=0 ){
        ui->widgetBottom->UpdateLegendLineName ( 1, m_gstDataFields[index-1].strFieldName );
    }else{
        ui->widgetBottom->UpdateLegendLineName ( 1, "NULL" );
    }
    m_gnPlotIndex[5] = index;
}

void MainWindow::on_chart1_MultiAxis_toggled(bool checked)
{
    ui->widgetTop->UpdateMultiSingleAxis ( checked );
}

void MainWindow::on_pushButton_pause1_toggled(bool checked)
{
    ui->widgetTop->m_bPauseReplot = checked;
}

void MainWindow::Refresh_Behavior_Buttons_and_Graphs(QPushButton* button_toggled)
{
    if(ui->pushButton_analyzelanekeep != button_toggled){
        on_pushButton_analyzelanekeep_toggled(false);
        ui->pushButton_analyzelanekeep->setChecked(false);
    }
    if(ui->pushButton_analyzeACC != button_toggled){
        on_pushButton_analyzeACC_toggled(false);
        ui->pushButton_analyzeACC->setChecked(false);
    }
    if(ui->pushButton_analyzeAEB != button_toggled){
        on_pushButton_analyzeAEB_toggled(false);
        ui->pushButton_analyzeAEB->setChecked(false);
    }
    if(ui->pushButton_analyzeautochange != button_toggled){
        on_pushButton_analyzeautochange_toggled(false);
        ui->pushButton_analyzeautochange->setChecked(false);
    }
    if(ui->pushButton_analyzeovertaking != button_toggled){
        on_pushButton_analyzeovertaking_toggled(false);
        ui->pushButton_analyzeovertaking->setChecked(false);
    }
    if(ui->pushButton_analyzeacceleration != button_toggled){
        on_pushButton_analyzeacceleration_toggled(false);
        ui->pushButton_analyzeacceleration->setChecked(false);
    }

    if(button_toggled->isChecked())
        button_toggled->toggle();
}

void MainWindow::Refresh_Load_Buttons_and_Graphs(QPushButton* button_toggled)
{
    if(ui->pushButton_loadgpsins != button_toggled){
        on_pushButton_loadgpsins_toggled(false);
        ui->pushButton_loadgpsins->setChecked(false);
    }
    if(ui->pushButton_loadvcu != button_toggled){
        on_pushButton_loadvcu_toggled(false);
        ui->pushButton_loadvcu->setChecked(false);
    }
    if(ui->pushButton_loadlane != button_toggled){
        on_pushButton_loadlane_toggled(false);
        ui->pushButton_loadlane->setChecked(false);
    }
    if(ui->pushButton_loadtsr != button_toggled){
        on_pushButton_loadtsr_toggled(false);
        ui->pushButton_loadtsr->setChecked(false);
    }
    if(button_toggled->isChecked())
        button_toggled->toggle();
}

void MainWindow::on_pushButton_analyzelanekeep_toggled(bool checked)//analysis lane keeping behavior
{
    if(checked){
        Refresh_Behavior_Buttons_and_Graphs(ui->pushButton_analyzelanekeep);
        ui->DebugOutput->setText("Analyzing Lane Keeping!");
        ui->pushButton_analyzelanekeep->setText(QString("Analyzing"));
        //vehicle status:
        ui->widgetTop->UpdateLegendLineName ( 0, m_gstDataFields[21-1].strFieldName );//20:speed
        m_gnPlotIndex[0] = 21;
        //lane keeping Status:
    }else{
        ui->pushButton_analyzelanekeep->setText(QString("Lane_Keep"));
        for(int index = 0; index < 4; index++)
        {
            ui->widgetTop->UpdateLegendLineName ( index, "NULL" );
            ui->widgetTop->graph ( index )->clearData();
            m_gnPlotIndex[index] = 0;
        }
    }
}

void MainWindow::on_pushButton_calibration_clicked()
{
    if(cali_window_open == false)
    {
        cali_win->show();
        cali_window_open = true;
    }
    else
    {
        //pop out a window:
        QMessageBox *dlg = new QMessageBox;
        dlg->setText("WARNING: Already Running An Calibration Monitor!");
        dlg->show();
    }
}

void MainWindow::on_pushButton_data_logger_clicked()
{
    if(log_window_open == false)
    {
        log_win->show();
        log_window_open = true;
    }
    else
    {
        //pop out a window:
        QMessageBox *dlg = new QMessageBox;
        dlg->setText("WARNING: Already Running An Logger Window!");
        dlg->show();
    }
}

void MainWindow::on_pushButton_clear_data_clicked()
{
    //pop out a window:
    QMessageBox *dlg = new QMessageBox(this);
    dlg->setText("WARNING: Are U Sure To Clear All Data Immediately!");
    QAbstractButton *abort_button = dlg->addButton(tr("Abort"), QMessageBox::ActionRole);
    QAbstractButton *continue_button = dlg->addButton(tr("Continue"), QMessageBox::ActionRole);
    dlg->show();
}

void MainWindow::on_pushButton_datalibrary_clicked()//Browse the data library and edit
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Data Library!"), ".", tr("DataLog Files (*.log)"));
    if(fileName.isNull()){
        return;
    }
    ui->DebugOutput->setText(fileName);
}

void MainWindow::on_pushButton_datastatics_clicked()
{
    FILE *fp;
    char cur_task_name[50];//大小随意，能装下要识别的命令行文本即可
    char buf[1024];
    fp = fopen("/proc/meminfo", "r");//打开文件
    if (NULL != fp){
        if( fgets(buf, 1024-1, fp)== NULL ){
            fclose(fp);
        }
        sscanf(buf, "%*s %s\n", cur_task_name);
        if( fgets(buf, 1024-1, fp)== NULL ){
            fclose(fp);
        }
        sscanf(buf, "%*s %s\n", cur_task_name);
        string space_left;
        float free_mem_size = atoi(cur_task_name);
        sprintf(buf,"%.2f",free_mem_size/1000/1000);
        space_left = buf;
        ui->lineEdit_space_left->setText(QString::fromStdString(space_left));
        fclose(fp);
    }

    DIR *dir;
    struct dirent *ptr;
    char filepath[50];
    dir = opendir("../../../atd-d2d-integration/applications/bin"); //打开路径
    int i_log_size = 0;
    if (NULL != dir)
    {
        while ((ptr = readdir(dir)) != NULL) //循环读取路径下的每一个文件/文件夹
        {
            if(!(NULL == strstr(ptr->d_name,".log")))
            {
                struct stat statbuf;
                sprintf(filepath,"%s",ptr->d_name);
                string base_path = filepath ;
                base_path = "/home/vov/iGS/4.0.2/atd-d2d-integration/applications/bin/"+ base_path;
                stat(base_path.c_str(),&statbuf);
                int size=statbuf.st_size;
                i_log_size += size;

                continue;
            }
            else if (DT_DIR != ptr->d_type){
                continue;
            }

        }
        sprintf(buf,"%.3f",float(i_log_size)/1000/1000/1000);
        ui->lineEdit_log_size->setText(QString::fromStdString(buf));

        closedir(dir);//关闭路径
    }else{
        cerr<<"error to open dir!"<<endl;
    }

//         struct statfs diskInfo;
//            statfs("~/", &diskInfo);
//            unsigned long long blocksize = diskInfo.f_bsize; //每个block里包含的字节数
//            unsigned long long totalsize = blocksize * diskInfo.f_blocks; //总的字节数，f_blocks为block的数目
//            printf("Total_size = %llu B = %llu KB = %llu MB = %llu GB\n",
//                totalsize, totalsize>>10, totalsize>>20, totalsize>>30);

//            unsigned long long freeDisk = diskInfo.f_bfree * blocksize; //剩余空间的大小
//            unsigned long long availableDisk = diskInfo.f_bavail * blocksize; //可用空间大小
//            printf("Disk_free = %llu MB = %llu GB\nDisk_available = %llu MB = %llu GB\n",
//                freeDisk>>20, freeDisk>>30, availableDisk>>20, availableDisk>>30);
}

void MainWindow::on_pushButton_resetall_clicked()
{
    Refresh_Behavior_Buttons_and_Graphs(ui->pushButton_resetall);
    Refresh_Load_Buttons_and_Graphs(ui->pushButton_resetall);
}


void MainWindow::on_pushButton_analyzeAEB_toggled(bool checked)
{
    if(checked){
        Refresh_Behavior_Buttons_and_Graphs(ui->pushButton_analyzeAEB);
        ui->DebugOutput->setText("Analyzing AEB!");
        ui->pushButton_analyzeAEB->setText(QString("Analyzing"));
        //vehicle status:
        ui->widgetTop->UpdateLegendLineName ( 0, m_gstDataFields[21-1].strFieldName );//20:ins speed
        ui->widgetTop->UpdateLegendLineName ( 1, m_gstDataFields[16-1].strFieldName );//15:acceleration x
        ui->widgetTop->UpdateLegendLineName ( 2, m_gstDataFields[22-1].strFieldName );//21:acceleration x
        ui->widgetTop->UpdateLegendLineName ( 3, m_gstDataFields[30-1].strFieldName );//29:decision speed
        m_gnPlotIndex[0] = 21;
        m_gnPlotIndex[1] = 16;
        m_gnPlotIndex[2] = 22;
        m_gnPlotIndex[3] = 30;
        //lane keeping Status:
    }else{
        ui->pushButton_analyzeAEB->setText(QString("AEB"));
        for(int index = 0; index < 4; index++)
        {
            ui->widgetTop->UpdateLegendLineName ( index, "NULL" );
            ui->widgetTop->graph ( index )->clearData();
            m_gnPlotIndex[index] = 0;
        }
    }
}

void MainWindow::on_pushButton_analyzeautochange_toggled(bool checked)
{
    if(checked){
        Refresh_Behavior_Buttons_and_Graphs(ui->pushButton_analyzeautochange);
        ui->DebugOutput->setText("Analyzing Autochange!");
        ui->pushButton_analyzeautochange->setText(QString("Analyzing"));
        //vehicle status:
        ui->widgetTop->UpdateLegendLineName ( 0, m_gstDataFields[21-1].strFieldName );//20:ins speed
        ui->widgetTop->UpdateLegendLineName ( 1, m_gstDataFields[16-1].strFieldName );//15:acceleration x
        ui->widgetTop->UpdateLegendLineName ( 2, m_gstDataFields[22-1].strFieldName );//21:acceleration x
        ui->widgetTop->UpdateLegendLineName ( 3, m_gstDataFields[30-1].strFieldName );//29:decision speed
        m_gnPlotIndex[0] = 21;
        m_gnPlotIndex[1] = 16;
        m_gnPlotIndex[2] = 22;
        m_gnPlotIndex[3] = 30;
        //lane keeping Status:
    }else{
        ui->pushButton_analyzeautochange->setText(QString("Auto_Change"));
        for(int index = 0; index < 4; index++)
        {
            ui->widgetTop->UpdateLegendLineName ( index, "NULL" );
            ui->widgetTop->graph ( index )->clearData();
            m_gnPlotIndex[index] = 0;
        }
    }
}

void MainWindow::on_pushButton_analyzeovertaking_toggled(bool checked)
{
    if(checked){
        Refresh_Behavior_Buttons_and_Graphs(ui->pushButton_analyzeovertaking);
        ui->DebugOutput->setText("Analyzing overtaking!");
        ui->pushButton_analyzeovertaking->setText(QString("Analyzing"));
        //vehicle status:
        ui->widgetTop->UpdateLegendLineName ( 0, m_gstDataFields[21-1].strFieldName );//20:ins speed
        ui->widgetTop->UpdateLegendLineName ( 1, m_gstDataFields[16-1].strFieldName );//15:acceleration x
        ui->widgetTop->UpdateLegendLineName ( 2, m_gstDataFields[22-1].strFieldName );//21:acceleration x
        ui->widgetTop->UpdateLegendLineName ( 3, m_gstDataFields[30-1].strFieldName );//29:decision speed
        m_gnPlotIndex[0] = 21;
        m_gnPlotIndex[1] = 16;
        m_gnPlotIndex[2] = 22;
        m_gnPlotIndex[3] = 30;
        //lane keeping Status:
    }else{
        ui->pushButton_analyzeovertaking->setText(QString("Overtaking"));
        for(int index = 0; index < 4; index++)
        {
            ui->widgetTop->UpdateLegendLineName ( index, "NULL" );
            ui->widgetTop->graph ( index )->clearData();
            m_gnPlotIndex[index] = 0;
        }
    }
}

void MainWindow::on_pushButton_analyzeacceleration_toggled(bool checked)
{
    if(checked){
        Refresh_Behavior_Buttons_and_Graphs(ui->pushButton_analyzeacceleration);
        ui->DebugOutput->setText("Analyzing acceleration!");
        ui->pushButton_analyzeacceleration->setText(QString("Analyzing"));
        //vehicle status:
        ui->widgetTop->UpdateLegendLineName ( 0, m_gstDataFields[21-1].strFieldName );//20:ins speed
        ui->widgetTop->UpdateLegendLineName ( 1, m_gstDataFields[16-1].strFieldName );//15:acceleration x
        ui->widgetTop->UpdateLegendLineName ( 2, m_gstDataFields[22-1].strFieldName );//21:acceleration x
        ui->widgetTop->UpdateLegendLineName ( 3, m_gstDataFields[30-1].strFieldName );//29:decision speed
        m_gnPlotIndex[0] = 21;
        m_gnPlotIndex[1] = 16;
        m_gnPlotIndex[2] = 22;
        m_gnPlotIndex[3] = 30;
        //lane keeping Status:
    }else{
        ui->pushButton_analyzeacceleration->setText(QString("Accelerate"));
        for(int index = 0; index < 4; index++)
        {
            ui->widgetTop->UpdateLegendLineName ( index, "NULL" );
            ui->widgetTop->graph ( index )->clearData();
            m_gnPlotIndex[index] = 0;
        }
    }
}

void MainWindow::on_pushButton_analyzeACC_toggled(bool checked)
{
    if(checked){
        Refresh_Behavior_Buttons_and_Graphs(ui->pushButton_analyzeACC);
        ui->DebugOutput->setText("Analyzing ACC!");
        ui->pushButton_analyzeACC->setText(QString("Analyzing"));
        //vehicle status:
        ui->widgetTop->UpdateLegendLineName ( 0, m_gstDataFields[21-1].strFieldName );//20:ins speed
        ui->widgetTop->UpdateLegendLineName ( 1, m_gstDataFields[16-1].strFieldName );//15:acceleration x
        ui->widgetTop->UpdateLegendLineName ( 2, m_gstDataFields[22-1].strFieldName );//21:acceleration x
        ui->widgetTop->UpdateLegendLineName ( 3, m_gstDataFields[30-1].strFieldName );//29:decision speed
        m_gnPlotIndex[0] = 21;
        m_gnPlotIndex[1] = 16;
        m_gnPlotIndex[2] = 22;
        m_gnPlotIndex[3] = 30;
        //lane keeping Status:
    }else{
        ui->pushButton_analyzeACC->setText(QString("ACC"));
        for(int index = 0; index < 4; index++)
        {
            ui->widgetTop->UpdateLegendLineName ( index, "NULL" );
            ui->widgetTop->graph ( index )->clearData();
            m_gnPlotIndex[index] = 0;
        }
    }
}

void MainWindow::on_pushButton_pause2_toggled(bool checked)
{
    ui->widgetBottom->m_bPauseReplot = checked;
}

void MainWindow::on_pushButton_loadcam_toggled(bool checked)
{
    //load image
}

void MainWindow::on_pushButton_loadgpsins_toggled(bool checked)
{
    if(checked){
        Refresh_Load_Buttons_and_Graphs(ui->pushButton_loadgpsins);
        ui->DebugOutput->setText("Checked! Please Go Ahead!");
        ui->pushButton_loadgpsins->setText(QString("Analyzing.."));
        //collect data for chart...
        ui->widgetBottom->UpdateLegendLineName ( 0, m_gstDataFields[21-1].strFieldName );//20:speed
        m_gnPlotIndex[4] = 21;
        ui->widgetBottom->UpdateLegendLineName ( 1, m_gstDataFields[4-1].strFieldName );//3:acceleration x
        m_gnPlotIndex[5] = 4;
        ui->widgetBottom->UpdateLegendLineName ( 2, m_gstDataFields[5-1].strFieldName );//4:acceleration y
        m_gnPlotIndex[6] = 5;
        ui->widgetBottom->UpdateLegendLineName ( 3, m_gstDataFields[28-1].strFieldName );//27:vel north
        m_gnPlotIndex[7] = 28;
    }else{
        ui->pushButton_loadgpsins->setText(QString("Load_ins"));
        for(int index = 0; index < 4; index++){
            ui->widgetBottom->UpdateLegendLineName ( index, "NULL" );
            ui->widgetBottom->graph (index)->clearData();
//            m_gnPlotIndex[index + 4] = 0;
        }
    }
}

void MainWindow::on_pushButton_loadvcu_toggled(bool checked)
{
    if(checked){
        Refresh_Load_Buttons_and_Graphs(ui->pushButton_loadvcu);
        ui->pushButton_loadvcu->setText(QString("Analyzing.."));
        //collect data for chart...
        ui->widgetBottom->UpdateLegendLineName ( 0, m_gstDataFields[17-1].strFieldName );//16:Front Right Wheel SPeed
        m_gnPlotIndex[4] = 17;
        ui->widgetBottom->UpdateLegendLineName ( 1, m_gstDataFields[16-1].strFieldName );//15:Front Left Wheel SPeed
        m_gnPlotIndex[5] = 16;
        ui->widgetBottom->UpdateLegendLineName ( 2, m_gstDataFields[17-1].strFieldName );//16:Front Right Wheel SPeed
        m_gnPlotIndex[6] = 17;
        ui->widgetBottom->UpdateLegendLineName ( 3, m_gstDataFields[16-1].strFieldName );//15:Front Left Wheel SPeed
        m_gnPlotIndex[7] = 16;
    }else{
        ui->pushButton_loadvcu->setText(QString("Load_vcu"));
        for(int index = 0; index < 4; index++){
            ui->widgetBottom->UpdateLegendLineName ( index, "NULL" );
            ui->widgetBottom->graph (index)->clearData();
//            m_gnPlotIndex[index + 4] = 0;
        }
    }
}

void MainWindow::on_pushButton_loadlane_toggled(bool checked)
{
    if(checked){
        Refresh_Load_Buttons_and_Graphs(ui->pushButton_loadlane);
        ui->pushButton_loadlane->setText(QString("Analyzing.."));
        //collect data for chart...
        ui->widgetBottom->UpdateLegendLineName ( 0, m_gstDataFields[17-1].strFieldName );//16:Front Right Wheel SPeed
        m_gnPlotIndex[4] = 17;
        ui->widgetBottom->UpdateLegendLineName ( 1, m_gstDataFields[16-1].strFieldName );//15:Front Left Wheel SPeed
        m_gnPlotIndex[5] = 16;
        ui->widgetBottom->UpdateLegendLineName ( 2, m_gstDataFields[17-1].strFieldName );//16:Front Right Wheel SPeed
        m_gnPlotIndex[6] = 17;
        ui->widgetBottom->UpdateLegendLineName ( 3, m_gstDataFields[16-1].strFieldName );//15:Front Left Wheel SPeed
        m_gnPlotIndex[7] = 16;
    }else{
        ui->pushButton_loadlane->setText(QString("Load_lane"));
        for(int index = 0; index < 4; index++){
            ui->widgetBottom->UpdateLegendLineName ( index, "NULL" );
            ui->widgetBottom->graph (index)->clearData();
//            m_gnPlotIndex[index + 4] = 0;
        }
    }
}

void MainWindow::on_pushButton_loadtsr_toggled(bool checked)
{
    if(checked){
        Refresh_Load_Buttons_and_Graphs(ui->pushButton_loadtsr);
        ui->pushButton_loadtsr->setText(QString("Analyzing.."));
        //collect data for chart...
        ui->widgetBottom->UpdateLegendLineName ( 0, m_gstDataFields[17-1].strFieldName );//16:Front Right Wheel SPeed
        m_gnPlotIndex[4] = 17;
        ui->widgetBottom->UpdateLegendLineName ( 1, m_gstDataFields[16-1].strFieldName );//15:Front Left Wheel SPeed
        m_gnPlotIndex[5] = 16;
        ui->widgetBottom->UpdateLegendLineName ( 2, m_gstDataFields[17-1].strFieldName );//16:Front Right Wheel SPeed
        m_gnPlotIndex[6] = 17;
        ui->widgetBottom->UpdateLegendLineName ( 3, m_gstDataFields[16-1].strFieldName );//15:Front Left Wheel SPeed
        m_gnPlotIndex[7] = 16;
    }else{
        ui->pushButton_loadtsr->setText(QString("Load_tsr"));
        for(int index = 0; index < 4; index++){
            ui->widgetBottom->UpdateLegendLineName ( index, "NULL" );
            ui->widgetBottom->graph (index)->clearData();
//            m_gnPlotIndex[index + 4] = 0;
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_T && event->modifiers() == Qt::ControlModifier){
        if(event->isAutoRepeat()) return;
        ui->DebugOutput->setText("Top View");
        QDialog *dlg = new QDialog;
        dlg->setWindowTitle("Top View");

        dlg->setGeometry(QRect(10,10,300,300));
        dlg->setFixedSize(300,300);
        dlg->show();
    }

    if(event->key() == Qt::Key_H && event->modifiers() == Qt::ControlModifier){
        if(event->isAutoRepeat()) return;
        ui->DebugOutput->setText("hello,Ctrl + H");
        this->window()->showMinimized();
//        log_win->focusWidget();
    }
    if(event->key() == Qt::Key_2 && event->modifiers() == Qt::ControlModifier){
        if(event->isAutoRepeat()) return;
        ui->DebugOutput->setText("hello,Ctrl + 2");
        log_win->show();
    }
    if(event->key() == Qt::Key_3 && event->modifiers() == Qt::ControlModifier){
        if(event->isAutoRepeat()) return;
        ui->DebugOutput->setText("hello,Ctrl + 3");
        sys_win->show();
    }
    if(event->key() == Qt::Key_4 && event->modifiers() == Qt::ControlModifier){
        if(event->isAutoRepeat()) return;
        ui->DebugOutput->setText("hello,Ctrl + 4");
        cali_win->show();
    }
}

void MainWindow::OnshowMainWindow()
{
    ui->DebugOutput->setText("hello,Ctrl + 1");
    this->setWindowFlags(this->windowFlags()|Qt::WindowStaysOnTopHint);
    this->showNormal();
}

void MainWindow::on_pushButton_lane_toggled(bool checked)
{
    if(!checked){
        ui->tableView_melane->hide();
    }else{
        ui->tableView_melane->show();
    }
}

void MainWindow::on_DebugOutput_textChanged()
{
    if(ui->textBrowser_history->document()->lineCount()>20){
        ui->textBrowser_history->clear();
    }

    ui->textBrowser_history->setText(ui->DebugOutput->toPlainText()+
                                  "\n"+ui->textBrowser_history->toPlainText());
}

void MainWindow::on_visible_tablewidget_toggled(bool checked)
{
    if(!checked)
        ui->tableWidget->hide();
    else
        ui->tableWidget->show();
}

void MainWindow::on_visible_Debug_window_toggled(bool checked)
{
    if(!checked){
        ui->DebugOutput->hide();
        ui->textBrowser_history->hide();
    }
    else{
        ui->DebugOutput->show();
        ui->textBrowser_history->show();
    }
}

void MainWindow::on_pushButton_meobj_toggled(bool checked)
{
    if(!checked){
        ui->tableView_meobs->hide();
    }else{
        ui->tableView_meobs->show();
    }
}

void MainWindow::on_pushButton_canprocy_toggled(bool checked)
{
    if(!checked){
        ui->tableView_can2proxy->hide();
    }else{
        ui->tableView_can2proxy->show();
    }
}

void MainWindow::on_pushButton_vcu_toggled(bool checked)
{
    if(!checked){
        ui->tableView_vcu->hide();
    }else{
        ui->tableView_vcu->show();
    }
}

void MainWindow::on_pushButton_ins_toggled(bool checked)
{
    if(!checked){
        ui->tableView_inertial->hide();
    }else{
        ui->tableView_inertial->show();
    }
}

void MainWindow::on_pushButton_idc_toggled(bool checked)
{
    if(!checked){
        ui->tableView_idc->hide();
    }else{
        ui->tableView_idc->show();
    }
}

void MainWindow::on_pushButton_ibeo_toggled(bool checked)
{
    if(!checked){
        ui->tableView_ibeo->hide();
    }else{
        ui->tableView_ibeo->show();
    }
}

void MainWindow::on_pushButton_velodyne_toggled(bool checked)
{
    if(!checked){
        ui->tableView_velodyne->hide();
    }else{
        ui->tableView_velodyne->show();
    }
}

void MainWindow::on_pushButton_tsr_toggled(bool checked)
{
    if(!checked){
        ui->tableView_tsr->hide();
    }else{
        ui->tableView_tsr->show();
    }
}

void MainWindow::on_pushButton_esr_toggled(bool checked)
{
    if(!checked){
        ui->tableView_esr->hide();
    }else{
        ui->tableView_esr->show();
    }
}

void MainWindow::on_pushButton_rsds_toggled(bool checked)
{
    if(!checked){
        ui->tableView_rsds->hide();
    }else{
        ui->tableView_rsds->show();
    }
}

void MainWindow::on_pushButton_detail_ethernet_toggled(bool checked)
{
    if(!checked){
        ui->tableView_ethernet->hide();
    }else{
        ui->tableView_ethernet->show();
    }
}

void MainWindow::on_pushButton_detail_can_toggled(bool checked)
{
    if(!checked){
        ui->tableView_can_Message->hide();
    }else{
        ui->tableView_can_Message->show();
    }
}
