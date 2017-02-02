#include "calibrationwindow.h"
#include "ui_calibrationwindow.h"
#include "QtNetwork/QNetworkInterface"
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

CalibrationWindow::CalibrationWindow ( QWidget *parent ) :
    QMainWindow ( parent ),
    cali_ui ( new Ui::CalibrationWindow )
{
    cali_ui->setupUi ( this );
    this->setFixedSize(820,600);
    this->setWindowTitle ( QString ( "Calibration Window" ));
}

CalibrationWindow::~CalibrationWindow()
{
    delete cali_ui;
}

void CalibrationWindow::init()
{

}

void CalibrationWindow::closeEvent(QCloseEvent *event)
{
    emit sendData(true);
}
