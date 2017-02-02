#ifndef SYSTEMWINDOW_H
#define SYSTEMWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPen>

#include "qplot.h"
#include "clcmhandler.h"
#include "clcmsubscriber.h"
#include <fstream>
#include <iostream>
#include "dirent.h"

using namespace std;

#define INDICATORLAMP_RED_PATH "../data/image/button_red.png"
#define INDICATORLAMP_PURPLE_PATH "../data/image/button_purple.png"
#define INDICATORLAMP_GREEN_PATH "../data/image/button_green.png"
#define INDICATORLAMP_YELLOW_PATH "../data/image/button_yellow.png"

namespace Ui {
class SystemWindow;
class MainWindow;
}

class SystemWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SystemWindow(QWidget *parent = 0);
    ~SystemWindow();
    void Refresh_Error_N_Warnings();
    void Refresh_Network_Statics();
    void init();
    Ui::SystemWindow* sys_ui;
    int count_of_EW;
    void closeEvent(QCloseEvent *event);
    struct net_device_stats *stats;
    int last_recv_bytes_eth0;
    int last_recv_bytes_eth1;
    int last_send_bytes_eth0;
    int last_send_bytes_eth1;
    void Check_Module_Status();
    void keyPressEvent(QKeyEvent *event);

signals:
    void sendData(bool status);
    void showMainWindow();
    void showLoggerWindow();
    void showCalibrationWindow();
public slots:

private slots:
    void on_pushButton_IP_Capture_clicked();
    void OnMonitorUpdate();
    void OnCheckProcess();

private:
    QTimer* m_pUpdateMonitor;
    QTimer* m_pCheckProcess;
    QPixmap *indicatorlamp_red;
    QPixmap *indicatorlamp_blue;
    QPixmap *indicatorlamp_green;
    QPixmap *indicatorlamp_yellow;

};
#endif // SYSTEMWINDOW_H
