#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPen>

#include "qplot.h"
#include "clcmhandler.h"
#include "clcmsubscriber.h"
#include <fstream>
#include <iostream>
using namespace std;

#include "systemwindow.h"
#include "ui_systemwindow.h"
#include "loggerwindow.h"
#include "ui_loggerwindow.h"
#include "calibrationwindow.h"
#include "ui_calibrationwindow.h"
#include "QStandardItemModel"
#include "cplayerthread.h"

#define INDICATORLAMP_RED_PATH "../data/image/button_red.png"
#define INDICATORLAMP_PURPLE_PATH "../data/image/button_purple.png"
#define INDICATORLAMP_GREEN_PATH "../data/image/button_green.png"
#define INDICATORLAMP_YELLOW_PATH "../data/image/button_yellow.png"
#define INDICATORLAMP_TRIGGER_PATH "../data/image/button_trigger.png"

namespace Ui {
class SystemWindow;
class MainWindow;
}

struct DATA_FIELD
{
    double fFieldValue;
    QString strFieldName;
    QString strFieldUnit;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void init();
    Ui::MainWindow *ui;
    Ui::MainWindow *viewer_ui;
    void keyPressEvent(QKeyEvent  *event);

private:
    QPixmap *indicatorlamp_red;
    QPixmap *indicatorlamp_blue;
    QPixmap *indicatorlamp_green;
    QPixmap *indicatorlamp_yellow;
    QPixmap *indicatorlamp_trigger;


    SystemWindow* sys_win;
    LoggerWindow* log_win;
    CalibrationWindow* cali_win;
    bool main_window_open;
    bool sys_window_open;
    bool log_window_open;
    bool cali_window_open;
    CLCMSubscriber m_lcmSubscriber;
    unsigned short int m_gnPlotIndex[6];
    QTimer* m_pUpdateTimer;
    QTimer* m_pScreenShotTextTimer;
    QTimer* m_pRefreshTimer;
    DATA_FIELD m_gstDataFields[DFI_END];
    fstream outfile,fout;
    double reference_timestamp;
    int accumulate_ins;
    int count_ins;
    int accumulate_vcu;
    int count_vcu;
    int accumulate_ibeo;
    int count_ibeo;
    int accumulate_melane;
    int count_melane;
    int accumulate_meobjects;
    int count_meobjects;
    int accumulate_can2proxy;
    int count_can2proxy;
    int accumulate_adp_behavior;
    int count_adp_behavior;
    int accumulate_tsr;
    int count_tsr;
    int accumulate_velodyne;
    int count_velodyne;

    int module_status[30];

    QStandardItemModel* model_melane;
    QStandardItemModel* model_vcu;
    QStandardItemModel* model_vehiclepose;

    CPlayerThread* m_pPlayerThread;
    thread_group m_threadGroup;
    long int m_nFirstEventTimeStamp;
    long int m_nLastEventTimeStamp;

    void SwitchWidgetsStatus(bool bLoadFile, bool bPlay, bool bPause, bool bStep, bool bSetSpeed, bool bGoto, bool bTimeSlider, bool bLoop);
    void InitializeUI();
    void InitializeSignalsAndSlots();
    void DisplayFileAndChannelInfo();

private:
    inline void AppendPlotData(int dataFieldIndex, double timestamp, double value);
    void Refresh_Load_Buttons_and_Graphs(QPushButton* button_toggled);
    void Refresh_Behavior_Buttons_and_Graphs(QPushButton* button_toggled);
    void getAllFiles( string path, vector<string>& files);
    void closeEvent(QCloseEvent *event);

public slots:
    void OnShowStatusMsg(QString msg);
    void OnTimeOut();
    void OnRefreshTimeOut();
    void OnScreenShotTextTimeOut();

    void OnNewVehiclePose(Q_VEHICLE_POSE vehiclePose);
    void OnNewVcuVehicleInfo(Q_VCU_VEHICLE_INFO vcuVehicleInfo);
    void OnNewExecuteTrajectory(Q_EXECUTE_TRAJECTORY executeTrajectory);
    void OnNewMobileyeLines(Q_MOBILEYE_LINES mobileyeLines);
    void OnNewTrackedObstacles(Q_TRACKED_OBSTACLES tracked_obstacles);
    void OnNewIpc2devVelocity(Q_IPC2DEV_VELOCITY ipc2dev_velocity); 
    //void OnNewIbeoObjects(Q_IBEO_OBJECTS ibeo_objects);
    void OnNewExecuteBehaviorPlan(Q_EXECUTE_BEHAVIOR_PLAN execute_behavior_plan);
    void OnNewPerceptionTsr(Q_PERCEPTION_TSR perception_tsr);
    void OnNewVelodynePoints(Q_VELODYNE_POINTS velodyne_points);
    void OnNewPerceptionObjs(Q_PERCEPTIONED_OBJECTS perception_objects);
    void OnNewTrigger(Q_TRIGGER trigger);
    void OnshowMainWindow();

    void OnPushButtonLoadFileClicked();
    void OnPushButtonPlayClicked();
    void OnPushButtonPauseClicked();
    void OnPushButtonStepClicked();
    void OnPushButtonGoToClicked();
    void OnPushButtonSetSpeedClicked();
    void OnTimeSliderMoved(int value);

    void OnCheckBoxLoopStateChanged(int state);

    void OnShowStatusMessage(QString str);

    void OnUpdateCurrentTimeStamp(long int timestamp);
    void OnUpdateTableRow(int index, CHANNEL_INFO channel);
    void OnTableItemClicked(int x, int y);

signals:
    void Send_Module_Status(int* module_status);
    void UpdateChannelBroadCast(int index, bool broadcast);

private slots:
    void receiveData(bool status);
//    void on_recv_log_win_status();
//    void on_recv_cali_win_status();
    void on_pushButton_loadsys_clicked();
    void on_pushButton_loadgpsins_toggled(bool checked);
    void on_comboBox_chart2_x_currentIndexChanged(int index);
    void on_comboBox_chart1_x_currentIndexChanged(int index);
    void on_comboBox_chart1_y_currentIndexChanged(int index);
    void on_comboBox_chart2_y_currentIndexChanged(int index);
    void on_chart1_MultiAxis_toggled(bool checked);
    void on_pushButton_pause1_toggled(bool checked);
    void on_pushButton_analyzelanekeep_toggled(bool checked);
    void on_pushButton_data_logger_clicked();
    void on_pushButton_clear_data_clicked();
    void on_pushButton_datalibrary_clicked();
    void on_pushButton_datastatics_clicked();
    void on_pushButton_loadvcu_toggled(bool checked);
    void on_pushButton_resetall_clicked();
    void on_pushButton_analyzeACC_toggled(bool checked);
    void on_pushButton_pause2_toggled(bool checked);
    void on_pushButton_analyzeAEB_toggled(bool checked);
    void on_pushButton_analyzeautochange_toggled(bool checked);
    void on_pushButton_analyzeovertaking_toggled(bool checked);
    void on_pushButton_analyzeacceleration_toggled(bool checked);
    void on_pushButton_loadcam_toggled(bool checked);
    void on_pushButton_loadlane_toggled(bool checked);
    void on_pushButton_loadtsr_toggled(bool checked);
    void on_pushButton_calibration_clicked();
    void on_pushButton_lane_toggled(bool checked);
    void on_DebugOutput_textChanged();
    void on_visible_tablewidget_toggled(bool checked);
    void on_visible_Debug_window_toggled(bool checked);
    void on_pushButton_meobj_toggled(bool checked);
    void on_pushButton_canprocy_toggled(bool checked);
    void on_pushButton_vcu_toggled(bool checked);
    void on_pushButton_ins_toggled(bool checked);
    void on_pushButton_idc_toggled(bool checked);
    void on_pushButton_ibeo_toggled(bool checked);
    void on_pushButton_velodyne_toggled(bool checked);
    void on_pushButton_tsr_toggled(bool checked);
    void on_pushButton_esr_toggled(bool checked);
    void on_pushButton_rsds_toggled(bool checked);
    void on_pushButton_detail_ethernet_toggled(bool checked);
    void on_pushButton_detail_can_toggled(bool checked);
};

#endif // MAINWINDOW_H
