#ifndef LOGGERWINDOW_H
#define LOGGERWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPen>

#include "qplot.h"
#include "clcmhandler.h"
#include "clcmsubscriber.h"
#include <fstream>
#include <iostream>
#include "dirent.h"
#include "cmessagetable.h"
#include "cmessagethread.h"
#include "message.h"

#include <QKeyEvent>

using namespace std;

#define INDICATORLAMP_START_PATH "../data/image/button_start.png"
#define INDICATORLAMP_STOP_PATH "../data/image/button_stop.png"

namespace Ui {
class LoggerWindow;
class SystemWindow;
class MainWindow;
}

class LoggerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoggerWindow(QWidget *parent = 0);
    ~LoggerWindow();

private:
    void closeEvent(QCloseEvent *event);
    void init();
    Ui::LoggerWindow* log_ui;

    QPixmap *indicatorlamp_startrecord;
    QPixmap *indicatorlamp_stoprecord;

    CMessageTable m_stMessageTable;
    CMessageThread* m_pMessageThread;
    QTimer m_qTimerUpdateTable;//timer to update table;
    void InitializeUi();
    void InitializeSignalsAndSlots();
    void InitializeLCM();
    void keyPressEvent(QKeyEvent  *event);
    void UpdateListView();

signals:
    void sendData(bool status);
    void UpdateRecordList(QString str,bool record);
    void SwitchRecord(bool);
    void SwitchRecord(bool, QString);

public slots:
    void OnTimerUpdateTable();

    void OnStartRecord();
    void OnStopRecord();
    void OnLogFinished();
    void OnSelectAll();
    void OnInvertSelect();

    void OnShowStatusMessage(QString msg);
    void OnTableItemClicked(int x, int y);

    void OnShowLogFileName(QString strFileName);
    void OnUpdateRecordStatus(RECORD_STATUS recordStatus);

};
#endif // LOGGERWINDOW_H
