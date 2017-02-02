#ifndef CALIBRATIONWINDOW_H
#define CALIBRATIONWINDOW_H

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
class CalibrationWindow;
class LoggerWindow;
class SystemWindow;
class MainWindow;
}

class CalibrationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CalibrationWindow(QWidget *parent = 0);
    ~CalibrationWindow();

    void closeEvent(QCloseEvent *event);
    void init();
    Ui::CalibrationWindow* cali_ui;

signals:
    void sendData(bool status);
public slots:

private slots:

private:

};
#endif // CALIBRATIONWINDOW_H
