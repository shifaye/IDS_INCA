#include "loggerwindow.h"
#include "ui_loggerwindow.h"
#include "QtNetwork/QNetworkInterface"
#include "loggerwindow.h"

using namespace std;

LoggerWindow::LoggerWindow ( QWidget *parent ) :
    QMainWindow ( parent ),
    log_ui ( new Ui::LoggerWindow )
{
    m_pTriggerThread = new CTriggerThread;

    log_ui->setupUi ( this );
//    this->setFixedSize(820,600);
    this->setFocusPolicy(Qt::StrongFocus);
    this->setWindowTitle ( QString ( "Logger Window" ));

    //register struct to qt to enable the struct be transmitted by signals and slots;
    qRegisterMetaType<MESSAGE>("MESSAGE");
    qRegisterMetaType<RECORD_STATUS>("RECORD_STATUS");

    InitializeUi();//initialize ui, especially the table widgets;

    InitializeLCM();//initialize lcm;

    InitializeSignalsAndSlots();//initialize signals and slots;

    m_qTimerUpdateTable.start(200);//start the timer to update the table;
}

LoggerWindow::~LoggerWindow()
{
    delete log_ui;
}

void LoggerWindow::init()
{

}

void LoggerWindow::closeEvent(QCloseEvent *event)
{
    //emit sendData();
}


/**@brief initialize the ui;
 *
 * initialize the ui, set up the talbe widgets, including the column size and the header column;
 *@return void;
 *@note
 */
void LoggerWindow::InitializeUi()
{
    indicatorlamp_startrecord = new QPixmap();
    indicatorlamp_stoprecord = new QPixmap();

    indicatorlamp_startrecord->load(INDICATORLAMP_START_PATH);
    indicatorlamp_stoprecord->load(INDICATORLAMP_STOP_PATH);


    log_ui->pushButtonStartRecord->setIcon(*indicatorlamp_startrecord);
    log_ui->pushButtonStartRecord->setIconSize(QSize(log_ui->pushButtonStartRecord->width(),
                                               log_ui->pushButtonStartRecord->height()));

    log_ui->pushButtonStopRecord->setIcon(*indicatorlamp_stoprecord);
    log_ui->pushButtonStopRecord->setIconSize(QSize(log_ui->pushButtonStopRecord->width(),
                                                    log_ui->pushButtonStopRecord->height()));

    log_ui->tableWidgetLCM->setHorizontalHeaderItem(0, new QTableWidgetItem(""));//set the header column;
    log_ui->tableWidgetLCM->setColumnWidth(0, 25);//set the column width;

    log_ui->tableWidgetLCM->setHorizontalHeaderItem(1, new QTableWidgetItem("ChannelName"));
    log_ui->tableWidgetLCM->setColumnWidth(1, 240);

    log_ui->tableWidgetLCM->setHorizontalHeaderItem(2, new QTableWidgetItem("MsgCount"));
    log_ui->tableWidgetLCM->setColumnWidth(2, 120);

    log_ui->tableWidgetLCM->setHorizontalHeaderItem(3, new QTableWidgetItem("MsgSize(kB)"));
    log_ui->tableWidgetLCM->setColumnWidth(3, 120);

    log_ui->tableWidgetLCM->setHorizontalHeaderItem(4, new QTableWidgetItem("Fquency(Hz)"));
    log_ui->tableWidgetLCM->setColumnWidth(4, 120);

    log_ui->tableWidgetLCM->setHorizontalHeaderItem(5, new QTableWidgetItem("Period(s)"));
    log_ui->tableWidgetLCM->setColumnWidth(5, 120);

    log_ui->tableWidgetLCM->setHorizontalHeaderItem(6, new QTableWidgetItem("Stamp(s)"));
    log_ui->tableWidgetLCM->setColumnWidth(6, 180);

    log_ui->tableWidgetLCM->setHorizontalHeaderItem(7, new QTableWidgetItem("Delay(ms)"));
    log_ui->tableWidgetLCM->setColumnWidth(7, 120);
}


/**@brief initialize lcm;
 *
 * initialize lcm, including: create CMessageThread object, check the lcm environment, subscribe to all channels, start the receive and write thread;
 *@return void;
 *@note 1. if the lmc could not be initialize, a messagebox will be shown and the program will exit;
 * 2. the threads are created by boost create_thread and bind functions;
 * 3. the CMessageThread object must be a pointer, to enable copy of the pointer;
 */
void LoggerWindow::InitializeLCM()
{
    m_pMessageThread = new CMessageThread;//create object, the object must be pointer;

    //check the lcm environment;
    if(!m_pMessageThread->m_lcm.good())
    {
        QMessageBox msgBox;
        msgBox.setText("Initialize Communiation Failure, Please Check the Network Connection !");
        msgBox.exec();
        exit(-1);
    }

    //subscribe to all channels by ".*";
    m_pMessageThread->m_lcm.subscribe(".*", &CMessageThread::ReceiveMessage, m_pMessageThread);

    //create and start receive and write threads;
    thread_group threadGroup;
    threadGroup.create_thread(bind(&CMessageThread::ReceiveThread, m_pMessageThread));
    threadGroup.create_thread(bind(&CMessageThread::WriteThread, m_pMessageThread));

    //OnShowStatusMessage("Communication initialize succeed!");
}


/**@brief initialize signals and slots;
 *
 * initialize signals and slots;
 *@return void;
 *@note
 */
void LoggerWindow::InitializeSignalsAndSlots()
{
    //log_ui related signals and slots;
    connect(log_ui->pushButtonStartRecord, SIGNAL(clicked(bool)), this, SLOT(OnStartRecord()));
    connect(log_ui->pushButtonStopRecord, SIGNAL(clicked(bool)), this, SLOT(OnStopRecord()));
    connect(log_ui->pushButtonSelectall, SIGNAL(clicked(bool)), this, SLOT(OnSelectAll()));
    connect(log_ui->pushButtonUnselectall, SIGNAL(clicked(bool)), this, SLOT(OnInvertSelect()));
    connect(log_ui->tableWidgetLCM, SIGNAL(cellClicked(int,int)), this, SLOT(OnTableItemClicked(int, int)));

    //timer to update the table widget;
    connect(&m_qTimerUpdateTable, SIGNAL(timeout()), this, SLOT(OnTimerUpdateTable()));
    //connect(&m_qTimerUpdateTable, SIGNAL(timeout()), this, SLOT(OnkeyEventTrigger()));

    //display messages from the CMessageTable, mainly used for debug;
    connect(&m_stMessageTable, SIGNAL(ShowStatusMessage(QString)), this, SLOT(OnShowStatusMessage(QString)));

    //CMessageThread related signals and slots;
    connect(m_pMessageThread, SIGNAL(ShowStatusMessage(QString)), this, SLOT(OnShowStatusMessage(QString)));
    connect(m_pMessageThread, SIGNAL(MessageReceived(MESSAGE)), &m_stMessageTable, SLOT(OnMessageReceived(MESSAGE)));
    connect(m_pMessageThread, SIGNAL(ShowLogFileName(QString)), this, SLOT(OnShowLogFileName(QString)));
    connect(m_pMessageThread, SIGNAL(UpdateRecordStatus(RECORD_STATUS)), this, SLOT(OnUpdateRecordStatus(RECORD_STATUS)));
    connect(m_pMessageThread, SIGNAL(LogFinished()), this, SLOT(OnLogFinished()));
    connect(this, SIGNAL(UpdateRecordList(QString, bool)), m_pMessageThread, SLOT(OnUpdateRecordList(QString, bool)));
    connect(this, SIGNAL(SwitchRecord(bool)), m_pMessageThread, SLOT(OnSwitchRecord(bool)));
    connect(this, SIGNAL(SwitchRecord(bool,QString)), m_pMessageThread, SLOT(OnSwitchRecord(bool,QString)));
}


/**@brief update the table widget at frequency specified by the timer;
 *
 * update the table widget at frequency specified by the timer, including: set the number of the rows, update each item;
 *@return void;
 *@note 1. when new channels has been detected, a new row is added to the table;
 * 2. each item is set (by setItem function) only when new row is added to the table to avoid qt warning;
 * 3. only the message receive stamp could be get, the delay could not be measured;
 */
void LoggerWindow::OnTimerUpdateTable()
{
    //if new channel is detected, add row to the table;
    if(m_stMessageTable.GetRowWidgetsNum() > log_ui->tableWidgetLCM->rowCount())
    {
        int j = log_ui->tableWidgetLCM->rowCount();
        log_ui->tableWidgetLCM->setRowCount(m_stMessageTable.GetRowWidgetsNum());
        for(; j<m_stMessageTable.GetRowWidgetsNum(); j++)
        {
            log_ui->tableWidgetLCM->setItem(j, 0, new QTableWidgetItem(QString("")));//set new item as null string;
            log_ui->tableWidgetLCM->item(j, 0)->setTextAlignment(Qt::AlignCenter);//set item alignment;
            log_ui->tableWidgetLCM->item(j, 0)->setCheckState(Qt::Unchecked);//set check status;

            log_ui->tableWidgetLCM->setItem(j, 1, new QTableWidgetItem(QString("")));
            log_ui->tableWidgetLCM->item(j, 1)->setTextAlignment(Qt::AlignCenter);

            log_ui->tableWidgetLCM->setItem(j, 2, new QTableWidgetItem(QString("")));
            log_ui->tableWidgetLCM->item(j, 2)->setTextAlignment(Qt::AlignCenter);

            log_ui->tableWidgetLCM->setItem(j, 3, new QTableWidgetItem(QString("")));
            log_ui->tableWidgetLCM->item(j, 3)->setTextAlignment(Qt::AlignCenter);

            log_ui->tableWidgetLCM->setItem(j, 4, new QTableWidgetItem(QString("")));
            log_ui->tableWidgetLCM->item(j, 4)->setTextAlignment(Qt::AlignCenter);

            log_ui->tableWidgetLCM->setItem(j, 5, new QTableWidgetItem(QString("")));
            log_ui->tableWidgetLCM->item(j, 5)->setTextAlignment(Qt::AlignCenter);

            log_ui->tableWidgetLCM->setItem(j, 6, new QTableWidgetItem(QString("")));
            log_ui->tableWidgetLCM->item(j, 6)->setTextAlignment(Qt::AlignCenter);

            log_ui->tableWidgetLCM->setItem(j, 7, new QTableWidgetItem(QString("")));
            log_ui->tableWidgetLCM->item(j, 7)->setTextAlignment(Qt::AlignCenter);
        }
    }

    //update each row at specified frequency;
    for(int i=0; i<m_stMessageTable.GetRowWidgetsNum(); i++)
    {
        log_ui->tableWidgetLCM->item(i, 1)->setText(m_stMessageTable.m_qListRowWidgets[i]->m_qStrChannelName);
        log_ui->tableWidgetLCM->item(i, 2)->setText(QString::asprintf("%d", m_stMessageTable.m_qListRowWidgets[i]->m_nMsgCounter));
        log_ui->tableWidgetLCM->item(i, 3)->setText(QString::asprintf("%.3lf", m_stMessageTable.m_qListRowWidgets[i]->m_nMsgSize/1000.0));
        log_ui->tableWidgetLCM->item(i, 4)->setText(QString::asprintf("%.3lf", m_stMessageTable.m_qListRowWidgets[i]->m_fFrequency));
        log_ui->tableWidgetLCM->item(i, 5)->setText(QString::asprintf("%.6lf",m_stMessageTable.m_qListRowWidgets[i]->m_fPeriod));
        log_ui->tableWidgetLCM->item(i, 6)->setText(QString::asprintf("%.6lf", m_stMessageTable.m_qListRowWidgets[i]->m_nRecvTimeStamp/1000000.0));
    }
}


/**@brief slot function to show message on the status bar;
 *
 * slot function to clear the status bar and show new message on the status bar;
 *@param msg [IN]: the message to be showed;
 *@return void;
 *@note 1. previous message on the status bar will be firstly cleared;
 */
void LoggerWindow::OnShowStatusMessage(QString msg)
{
    log_ui->statusBar->clearMessage();
    log_ui->statusBar->showMessage(msg);
}


/**@brief slot function to update the record status of each channel;
 *
 * when the item of the table widget is clicked, this function is invoked to update the  record status of each channel;
 *@param x [IN]: the row index of the clicked item;
 *@param y [IN]: the column of the clicked item;
 *@return void;
 *@note 1. the row and column index starts from 0;
 * 2. the function will also be invoked to update the record list when only click in the first column but not click the checkbox;
 */
void LoggerWindow::OnTableItemClicked(int x, int y)
{
    //only respond to the log checkbox in the first column;
    if(0 != y)
    {
        return;
    }

    Qt::CheckState checkState = log_ui->tableWidgetLCM->item(x, y)->checkState();//get check state of the channels;
    if(Qt::Checked == checkState)
    {
        emit UpdateRecordList(m_stMessageTable.m_qListRowWidgets[x]->m_qStrChannelName, true);//emit signal to CMessageThread to add the channel to record list;
        return;
    }
    else
    {
        emit UpdateRecordList(m_stMessageTable.m_qListRowWidgets[x]->m_qStrChannelName, false);//emit signal to CMessageThread to remove the channel from the record list;
        return;
    }
}


/**@brief slot function to start log file when the start button is clicked;
 *
 * if the start button is clicked, this function will be invoked to: disable the start button, enable the stop button and emit signal to CMessageThread to start record;
 *@return void;
 *@note 1. the start button is disable and the stop button is enabled;
 */
void LoggerWindow::OnStartRecord()
{
    log_ui->pushButtonStartRecord->setEnabled(false);
    log_ui->pushButtonStopRecord->setEnabled(true);

    //read the text in the
    QString qstrText = this->log_ui->lineEditExtraFileName->text();
    this->log_ui->lineEditExtraFileName->clear();
    this->log_ui->lineEditExtraFileName->setEnabled(false);
    if(qstrText.length()>0)
    {
        qstrText.replace(QString(" "), QString("_"));
        qstrText.prepend('_');
    }

    emit SwitchRecord(true, qstrText);//emit signal to CMessageThread to start log file;
}


/**@brief slot function to stop log file when the stop button is clicked;
 *
 * if the stop button is clicked, this function will be invoked to disable the stop button, and emit signal to CMessageThread to stop recording file;
 *@return void;
 *@note 1. the start will not be enabled until the CMessageThread has finished writting of all queued messages;
 */
void LoggerWindow::OnStopRecord()
{
    log_ui->pushButtonStopRecord->setEnabled(false);
    this->log_ui->lineEditExtraFileName->setEnabled(true);
    emit SwitchRecord(false);//emit signal to CMessageThread to stop log file;
}


/**@brief slot function to enable the start button;
 *
 * only when current log file is finished, the start button will be enabled;
 *@return void;
 *@note 1. the sigial is emitted by the CMessageThread only when all the queued message are written to the log file and the log file is closed;
 */
void LoggerWindow::OnLogFinished()
{
    log_ui->pushButtonStartRecord->setEnabled(true);
}


/**@brief slot function to display current log file name on the line edit;
 *
 * each time new log file is created, this function will be invoked to display messages on the log_ui;
 *@param strFileName [IN]: current record file name;
 *@return void;
 *@note 1. each time start button is clicked, a new file is created to log the data;
 */
void LoggerWindow::OnShowLogFileName(QString strFileName)
{
    //this->log_ui->lineEditFileName->setText(strFileName);
    this->OnShowStatusMessage(strFileName);
}

/**@brief slot function to update the record status;
 *
 * the record status (including bandwidth, bytestowrite, byteswritten) will be updated every 1 second;
 *@param recordStatus [IN]: current record status;
 *@return void;
 *@note 1. the signal is emitted by the CMessageThread;
 */
void LoggerWindow::OnUpdateRecordStatus(RECORD_STATUS recordStatus)
{
    log_ui->lineEditBandWidth->setText(QString::asprintf("%.3f", recordStatus.fBandWidth));
    log_ui->lineEditDataToWrite->setText(QString::asprintf("%.3f", recordStatus.fBytesToWrite));
    log_ui->lineEditDataWritten->setText(QString::asprintf("%.3f", recordStatus.fBytesWritten));
}

void LoggerWindow::OnSelectAll()
{
    int _rowCount = log_ui->tableWidgetLCM->rowCount();
    for(int i=0;i<_rowCount;i++)
    {
        log_ui->tableWidgetLCM->item(i,0)->setCheckState(Qt::Checked);
        emit UpdateRecordList(m_stMessageTable.m_qListRowWidgets[i]->m_qStrChannelName, true);
    }
}

void LoggerWindow::OnInvertSelect()
{
    int _rowCount = log_ui->tableWidgetLCM->rowCount();
    for(int i=0;i<_rowCount;i++)
    {
        if(log_ui->tableWidgetLCM->item(i,0)->checkState())
        {
            log_ui->tableWidgetLCM->item(i,0)->setCheckState(Qt::Unchecked);
            emit UpdateRecordList(m_stMessageTable.m_qListRowWidgets[i]->m_qStrChannelName, false);
        }
        else
        {
            log_ui->tableWidgetLCM->item(i,0)->setCheckState(Qt::Checked);
            emit UpdateRecordList(m_stMessageTable.m_qListRowWidgets[i]->m_qStrChannelName, true);
        }
    }
}

/*record trigger manually*/
void LoggerWindow::keyPressEvent(QKeyEvent *event)
{
    TRIGGER_INFO manual_trigger;
    manual_trigger.type = MANUAL;
    manual_trigger.header.nTimeStamp = GetGlobalTimeStampInSec();
    if(event->key() == Qt::Key_Q && event->modifiers() == Qt::ControlModifier){
        if(event->isAutoRepeat()) return;
        manual_trigger.trigger_name = "curve_road";
    }
    else if(event->key() == Qt::Key_W){
        if(event->isAutoRepeat()) return;
        manual_trigger.trigger_name = "ramp";
    }
    else if(event->key() == Qt::Key_E){
        if(event->isAutoRepeat()) return;
        manual_trigger.trigger_name = "cross";
    }
    else if(event->key() == Qt::Key_R){
        if(event->isAutoRepeat()) return;
        manual_trigger.trigger_name = "merge";
    }else{
        manual_trigger.trigger_name = "NULL";
    }
    m_pTriggerThread->OnTriggerDetected(manual_trigger);
    /*  this part captures all key events,
        if a trigger is detected,
        publish a message in channel "TRIGGER_INFORMATION" */

}

void LoggerWindow::UpdateListView()
{

}
