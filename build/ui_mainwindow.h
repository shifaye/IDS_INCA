/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <cqglviewer.h>
#include "qplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_Ctrl_O;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *visible_tablewidget;
    QHBoxLayout *horizontalLayout_6;
    QGridLayout *gridLayout_4;
    QFrame *line_2;
    QPushButton *pushButton_resetall;
    QPushButton *pushButton_analyzeroute;
    QLabel *label_13;
    QPushButton *pushButton_loadgpsins;
    QLabel *label_10;
    QPushButton *pushButton_analyzelanekeep;
    QPushButton *pushButton_analyzeovertaking;
    QPushButton *pushButton_analyzeautochange;
    QPushButton *pushButton_loadlane;
    QPushButton *pushButton_analyzeACC;
    QPushButton *pushButton_loadcam;
    QPushButton *pushButton_loadvcu;
    QPushButton *pushButton_analyzeacceleration;
    QPushButton *pushButton_analyzeAEB;
    QPushButton *pushButton_loadtsr;
    QPushButton *pushButton_idc_statics;
    QPushButton *pushButton_loadsys;
    QPushButton *pushButton_loadcan;
    QPushButton *pushButton_loadobject;
    QFrame *line;
    CQGLViewer *openGLwidget;
    QLabel *label_14;
    QVBoxLayout *verticalLayout_4;
    QPlot *widgetTop;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_chart1_x;
    QComboBox *comboBox_chart1_y;
    QCheckBox *chart1_MultiAxis;
    QPushButton *pushButton_screenshot1;
    QPushButton *pushButton_pause1;
    QPushButton *pushButton_resetchart1;
    QPlot *widgetBottom;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBox_chart2_x;
    QComboBox *comboBox_chart2_y;
    QRadioButton *chart2_MultiAxis;
    QPushButton *pushButton_screenshot2;
    QPushButton *pushButton_pause2;
    QPushButton *pushButton_reset2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QGridLayout *gridLayout_6;
    QLabel *label;
    QPushButton *visible_Debug_window;
    QLabel *label_17;
    QTextBrowser *textBrowser_history;
    QTextEdit *DebugOutput;
    QSpacerItem *horizontalSpacer_3;
    QWidget *tab_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_12;
    QTableView *tableView_ethernet;
    QFrame *line_5;
    QTableView *tableView_can_Message;
    QSpacerItem *verticalSpacer_3;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_ins;
    QPushButton *pushButton_lane;
    QPushButton *pushButton_ibeo;
    QTableView *tableView_vcu;
    QPushButton *pushButton_tsr;
    QPushButton *pushButton_rsds;
    QPushButton *pushButton_meobj;
    QPushButton *pushButton_canprocy;
    QTableView *tableView_melane;
    QTableView *tableView_velodyne;
    QPushButton *pushButton_esr;
    QPushButton *pushButton_idc;
    QPushButton *pushButton_vcu;
    QPushButton *pushButton_velodyne;
    QTableView *tableView_inertial;
    QTableView *tableView_tsr;
    QTableView *tableView_meobs;
    QTableView *tableView_esr;
    QTableView *tableView_ibeo;
    QTableView *tableView_rsds;
    QTableView *tableView_idc;
    QTableView *tableView_can2proxy;
    QLabel *label_3;
    QLabel *label_2;
    QFrame *line_6;
    QFrame *line_3;
    QLabel *label_4;
    QPushButton *pushButton_detail_ethernet;
    QFrame *line_4;
    QPushButton *pushButton_detail_can;
    QWidget *tab_3;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_data_logger;
    QPushButton *pushButton_datalibrary;
    QPushButton *pushButton_datastatics;
    QPushButton *pushButton_clear_data;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_26;
    QPushButton *pushButton_Log_Trigger;
    QSpacerItem *verticalSpacer;
    QLabel *label_23;
    QLineEdit *lineEdit_log_size;
    QLabel *label_24;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_22;
    QLineEdit *lineEdit_space_left;
    QLabel *label_25;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_20;
    QSpacerItem *verticalSpacer_5;
    QWidget *tab_4;
    QLabel *label_27;
    QPushButton *pushButton_calibration;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuPreference;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1009, 1760);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(4000, 4000));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setIconSize(QSize(23, 23));
        actionOpen_Ctrl_O = new QAction(MainWindow);
        actionOpen_Ctrl_O->setObjectName(QStringLiteral("actionOpen_Ctrl_O"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayoutWidget = new QWidget(tab);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 1322, 758));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(3);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_7->addWidget(label_9);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(200, 0));

        horizontalLayout_7->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_15 = new QLabel(verticalLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_8->addWidget(label_15);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        visible_tablewidget = new QPushButton(verticalLayoutWidget);
        visible_tablewidget->setObjectName(QStringLiteral("visible_tablewidget"));
        visible_tablewidget->setMaximumSize(QSize(25, 25));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/icons/to_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        visible_tablewidget->setIcon(icon);
        visible_tablewidget->setIconSize(QSize(23, 24));
        visible_tablewidget->setCheckable(true);

        horizontalLayout_8->addWidget(visible_tablewidget);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        line_2 = new QFrame(verticalLayoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_2, 15, 0, 1, 4);

        pushButton_resetall = new QPushButton(verticalLayoutWidget);
        pushButton_resetall->setObjectName(QStringLiteral("pushButton_resetall"));

        gridLayout_4->addWidget(pushButton_resetall, 0, 3, 1, 1);

        pushButton_analyzeroute = new QPushButton(verticalLayoutWidget);
        pushButton_analyzeroute->setObjectName(QStringLiteral("pushButton_analyzeroute"));
        pushButton_analyzeroute->setCheckable(true);

        gridLayout_4->addWidget(pushButton_analyzeroute, 14, 3, 1, 1);

        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMaximumSize(QSize(16777215, 50));

        gridLayout_4->addWidget(label_13, 0, 0, 1, 3);

        pushButton_loadgpsins = new QPushButton(verticalLayoutWidget);
        pushButton_loadgpsins->setObjectName(QStringLiteral("pushButton_loadgpsins"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_loadgpsins->sizePolicy().hasHeightForWidth());
        pushButton_loadgpsins->setSizePolicy(sizePolicy1);
        pushButton_loadgpsins->setMaximumSize(QSize(120, 50));
        pushButton_loadgpsins->setCheckable(true);

        gridLayout_4->addWidget(pushButton_loadgpsins, 11, 0, 1, 1);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMaximumSize(QSize(16777215, 50));

        gridLayout_4->addWidget(label_10, 9, 0, 1, 3);

        pushButton_analyzelanekeep = new QPushButton(verticalLayoutWidget);
        pushButton_analyzelanekeep->setObjectName(QStringLiteral("pushButton_analyzelanekeep"));
        pushButton_analyzelanekeep->setMinimumSize(QSize(120, 27));
        pushButton_analyzelanekeep->setMaximumSize(QSize(120, 27));
        pushButton_analyzelanekeep->setCheckable(true);

        gridLayout_4->addWidget(pushButton_analyzelanekeep, 3, 0, 1, 1);

        pushButton_analyzeovertaking = new QPushButton(verticalLayoutWidget);
        pushButton_analyzeovertaking->setObjectName(QStringLiteral("pushButton_analyzeovertaking"));
        pushButton_analyzeovertaking->setMinimumSize(QSize(120, 27));
        pushButton_analyzeovertaking->setMaximumSize(QSize(120, 27));
        pushButton_analyzeovertaking->setCheckable(true);

        gridLayout_4->addWidget(pushButton_analyzeovertaking, 4, 0, 1, 1);

        pushButton_analyzeautochange = new QPushButton(verticalLayoutWidget);
        pushButton_analyzeautochange->setObjectName(QStringLiteral("pushButton_analyzeautochange"));
        pushButton_analyzeautochange->setMinimumSize(QSize(120, 27));
        pushButton_analyzeautochange->setMaximumSize(QSize(120, 27));
        pushButton_analyzeautochange->setCheckable(true);

        gridLayout_4->addWidget(pushButton_analyzeautochange, 4, 2, 1, 1);

        pushButton_loadlane = new QPushButton(verticalLayoutWidget);
        pushButton_loadlane->setObjectName(QStringLiteral("pushButton_loadlane"));
        sizePolicy1.setHeightForWidth(pushButton_loadlane->sizePolicy().hasHeightForWidth());
        pushButton_loadlane->setSizePolicy(sizePolicy1);
        pushButton_loadlane->setMaximumSize(QSize(120, 50));
        pushButton_loadlane->setCheckable(true);

        gridLayout_4->addWidget(pushButton_loadlane, 11, 2, 1, 1);

        pushButton_analyzeACC = new QPushButton(verticalLayoutWidget);
        pushButton_analyzeACC->setObjectName(QStringLiteral("pushButton_analyzeACC"));
        pushButton_analyzeACC->setMinimumSize(QSize(120, 27));
        pushButton_analyzeACC->setMaximumSize(QSize(120, 27));
        pushButton_analyzeACC->setCheckable(true);

        gridLayout_4->addWidget(pushButton_analyzeACC, 3, 2, 1, 1);

        pushButton_loadcam = new QPushButton(verticalLayoutWidget);
        pushButton_loadcam->setObjectName(QStringLiteral("pushButton_loadcam"));
        sizePolicy1.setHeightForWidth(pushButton_loadcam->sizePolicy().hasHeightForWidth());
        pushButton_loadcam->setSizePolicy(sizePolicy1);
        pushButton_loadcam->setMaximumSize(QSize(120, 50));
        pushButton_loadcam->setCheckable(true);

        gridLayout_4->addWidget(pushButton_loadcam, 14, 2, 1, 1);

        pushButton_loadvcu = new QPushButton(verticalLayoutWidget);
        pushButton_loadvcu->setObjectName(QStringLiteral("pushButton_loadvcu"));
        sizePolicy1.setHeightForWidth(pushButton_loadvcu->sizePolicy().hasHeightForWidth());
        pushButton_loadvcu->setSizePolicy(sizePolicy1);
        pushButton_loadvcu->setMaximumSize(QSize(120, 50));
        pushButton_loadvcu->setCheckable(true);

        gridLayout_4->addWidget(pushButton_loadvcu, 11, 1, 1, 1);

        pushButton_analyzeacceleration = new QPushButton(verticalLayoutWidget);
        pushButton_analyzeacceleration->setObjectName(QStringLiteral("pushButton_analyzeacceleration"));
        pushButton_analyzeacceleration->setMinimumSize(QSize(120, 27));
        pushButton_analyzeacceleration->setMaximumSize(QSize(120, 27));
        pushButton_analyzeacceleration->setCheckable(true);

        gridLayout_4->addWidget(pushButton_analyzeacceleration, 4, 1, 1, 1);

        pushButton_analyzeAEB = new QPushButton(verticalLayoutWidget);
        pushButton_analyzeAEB->setObjectName(QStringLiteral("pushButton_analyzeAEB"));
        pushButton_analyzeAEB->setMinimumSize(QSize(120, 27));
        pushButton_analyzeAEB->setMaximumSize(QSize(120, 27));
        pushButton_analyzeAEB->setCheckable(true);

        gridLayout_4->addWidget(pushButton_analyzeAEB, 3, 1, 1, 1);

        pushButton_loadtsr = new QPushButton(verticalLayoutWidget);
        pushButton_loadtsr->setObjectName(QStringLiteral("pushButton_loadtsr"));
        sizePolicy1.setHeightForWidth(pushButton_loadtsr->sizePolicy().hasHeightForWidth());
        pushButton_loadtsr->setSizePolicy(sizePolicy1);
        pushButton_loadtsr->setMaximumSize(QSize(120, 50));
        pushButton_loadtsr->setCheckable(true);

        gridLayout_4->addWidget(pushButton_loadtsr, 11, 3, 1, 1);

        pushButton_idc_statics = new QPushButton(verticalLayoutWidget);
        pushButton_idc_statics->setObjectName(QStringLiteral("pushButton_idc_statics"));
        sizePolicy1.setHeightForWidth(pushButton_idc_statics->sizePolicy().hasHeightForWidth());
        pushButton_idc_statics->setSizePolicy(sizePolicy1);
        pushButton_idc_statics->setMinimumSize(QSize(120, 27));
        pushButton_idc_statics->setMaximumSize(QSize(120, 27));
        pushButton_idc_statics->setCheckable(true);

        gridLayout_4->addWidget(pushButton_idc_statics, 4, 3, 1, 1);

        pushButton_loadsys = new QPushButton(verticalLayoutWidget);
        pushButton_loadsys->setObjectName(QStringLiteral("pushButton_loadsys"));
        sizePolicy1.setHeightForWidth(pushButton_loadsys->sizePolicy().hasHeightForWidth());
        pushButton_loadsys->setSizePolicy(sizePolicy1);
        pushButton_loadsys->setMaximumSize(QSize(120, 50));
        pushButton_loadsys->setCheckable(true);

        gridLayout_4->addWidget(pushButton_loadsys, 14, 1, 1, 1);

        pushButton_loadcan = new QPushButton(verticalLayoutWidget);
        pushButton_loadcan->setObjectName(QStringLiteral("pushButton_loadcan"));
        sizePolicy1.setHeightForWidth(pushButton_loadcan->sizePolicy().hasHeightForWidth());
        pushButton_loadcan->setSizePolicy(sizePolicy1);
        pushButton_loadcan->setMaximumSize(QSize(120, 50));
        pushButton_loadcan->setCheckable(true);

        gridLayout_4->addWidget(pushButton_loadcan, 14, 0, 1, 1);

        pushButton_loadobject = new QPushButton(verticalLayoutWidget);
        pushButton_loadobject->setObjectName(QStringLiteral("pushButton_loadobject"));
        sizePolicy1.setHeightForWidth(pushButton_loadobject->sizePolicy().hasHeightForWidth());
        pushButton_loadobject->setSizePolicy(sizePolicy1);
        pushButton_loadobject->setMaximumSize(QSize(120, 50));
        pushButton_loadobject->setCheckable(true);

        gridLayout_4->addWidget(pushButton_loadobject, 12, 0, 1, 1);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line, 8, 0, 1, 4);

        openGLwidget = new CQGLViewer(verticalLayoutWidget);
        openGLwidget->setObjectName(QStringLiteral("openGLwidget"));
        openGLwidget->setMinimumSize(QSize(480, 300));
        openGLwidget->setMaximumSize(QSize(480, 500));

        gridLayout_4->addWidget(openGLwidget, 17, 0, 1, 4);

        label_14 = new QLabel(verticalLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_14->setFont(font);

        gridLayout_4->addWidget(label_14, 16, 0, 1, 4);


        horizontalLayout_6->addLayout(gridLayout_4);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        widgetTop = new QPlot(verticalLayoutWidget);
        widgetTop->setObjectName(QStringLiteral("widgetTop"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widgetTop->sizePolicy().hasHeightForWidth());
        widgetTop->setSizePolicy(sizePolicy2);
        widgetTop->setMinimumSize(QSize(0, 0));
        widgetTop->setMaximumSize(QSize(16777215, 260));

        verticalLayout_4->addWidget(widgetTop);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        comboBox_chart1_x = new QComboBox(verticalLayoutWidget);
        comboBox_chart1_x->setObjectName(QStringLiteral("comboBox_chart1_x"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBox_chart1_x->sizePolicy().hasHeightForWidth());
        comboBox_chart1_x->setSizePolicy(sizePolicy3);
        comboBox_chart1_x->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_2->addWidget(comboBox_chart1_x);

        comboBox_chart1_y = new QComboBox(verticalLayoutWidget);
        comboBox_chart1_y->setObjectName(QStringLiteral("comboBox_chart1_y"));
        sizePolicy3.setHeightForWidth(comboBox_chart1_y->sizePolicy().hasHeightForWidth());
        comboBox_chart1_y->setSizePolicy(sizePolicy3);
        comboBox_chart1_y->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_2->addWidget(comboBox_chart1_y);

        chart1_MultiAxis = new QCheckBox(verticalLayoutWidget);
        chart1_MultiAxis->setObjectName(QStringLiteral("chart1_MultiAxis"));
        chart1_MultiAxis->setChecked(true);

        horizontalLayout_2->addWidget(chart1_MultiAxis);

        pushButton_screenshot1 = new QPushButton(verticalLayoutWidget);
        pushButton_screenshot1->setObjectName(QStringLiteral("pushButton_screenshot1"));
        sizePolicy1.setHeightForWidth(pushButton_screenshot1->sizePolicy().hasHeightForWidth());
        pushButton_screenshot1->setSizePolicy(sizePolicy1);
        pushButton_screenshot1->setMinimumSize(QSize(0, 30));
        pushButton_screenshot1->setMaximumSize(QSize(100, 30));
        pushButton_screenshot1->setCheckable(false);

        horizontalLayout_2->addWidget(pushButton_screenshot1);

        pushButton_pause1 = new QPushButton(verticalLayoutWidget);
        pushButton_pause1->setObjectName(QStringLiteral("pushButton_pause1"));
        sizePolicy1.setHeightForWidth(pushButton_pause1->sizePolicy().hasHeightForWidth());
        pushButton_pause1->setSizePolicy(sizePolicy1);
        pushButton_pause1->setMinimumSize(QSize(0, 30));
        pushButton_pause1->setMaximumSize(QSize(100, 30));
        pushButton_pause1->setCheckable(true);

        horizontalLayout_2->addWidget(pushButton_pause1);

        pushButton_resetchart1 = new QPushButton(verticalLayoutWidget);
        pushButton_resetchart1->setObjectName(QStringLiteral("pushButton_resetchart1"));
        sizePolicy1.setHeightForWidth(pushButton_resetchart1->sizePolicy().hasHeightForWidth());
        pushButton_resetchart1->setSizePolicy(sizePolicy1);
        pushButton_resetchart1->setMinimumSize(QSize(0, 30));
        pushButton_resetchart1->setMaximumSize(QSize(100, 30));
        pushButton_resetchart1->setCheckable(false);

        horizontalLayout_2->addWidget(pushButton_resetchart1);


        verticalLayout_4->addLayout(horizontalLayout_2);

        widgetBottom = new QPlot(verticalLayoutWidget);
        widgetBottom->setObjectName(QStringLiteral("widgetBottom"));
        widgetBottom->setMinimumSize(QSize(0, 0));
        widgetBottom->setMaximumSize(QSize(16777215, 260));

        verticalLayout_4->addWidget(widgetBottom);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        comboBox_chart2_x = new QComboBox(verticalLayoutWidget);
        comboBox_chart2_x->setObjectName(QStringLiteral("comboBox_chart2_x"));
        comboBox_chart2_x->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_3->addWidget(comboBox_chart2_x);

        comboBox_chart2_y = new QComboBox(verticalLayoutWidget);
        comboBox_chart2_y->setObjectName(QStringLiteral("comboBox_chart2_y"));
        comboBox_chart2_y->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_3->addWidget(comboBox_chart2_y);

        chart2_MultiAxis = new QRadioButton(verticalLayoutWidget);
        chart2_MultiAxis->setObjectName(QStringLiteral("chart2_MultiAxis"));

        horizontalLayout_3->addWidget(chart2_MultiAxis);

        pushButton_screenshot2 = new QPushButton(verticalLayoutWidget);
        pushButton_screenshot2->setObjectName(QStringLiteral("pushButton_screenshot2"));
        sizePolicy1.setHeightForWidth(pushButton_screenshot2->sizePolicy().hasHeightForWidth());
        pushButton_screenshot2->setSizePolicy(sizePolicy1);
        pushButton_screenshot2->setMaximumSize(QSize(100, 30));

        horizontalLayout_3->addWidget(pushButton_screenshot2);

        pushButton_pause2 = new QPushButton(verticalLayoutWidget);
        pushButton_pause2->setObjectName(QStringLiteral("pushButton_pause2"));
        sizePolicy1.setHeightForWidth(pushButton_pause2->sizePolicy().hasHeightForWidth());
        pushButton_pause2->setSizePolicy(sizePolicy1);
        pushButton_pause2->setMaximumSize(QSize(100, 30));
        pushButton_pause2->setCheckable(true);

        horizontalLayout_3->addWidget(pushButton_pause2);

        pushButton_reset2 = new QPushButton(verticalLayoutWidget);
        pushButton_reset2->setObjectName(QStringLiteral("pushButton_reset2"));
        sizePolicy1.setHeightForWidth(pushButton_reset2->sizePolicy().hasHeightForWidth());
        pushButton_reset2->setSizePolicy(sizePolicy1);
        pushButton_reset2->setMaximumSize(QSize(100, 30));

        horizontalLayout_3->addWidget(pushButton_reset2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);

        verticalLayout_4->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_4);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_6->addItem(verticalSpacer_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableWidget = new QTableWidget(verticalLayoutWidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        if (tableWidget->rowCount() < 29)
            tableWidget->setRowCount(29);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMinimumSize(QSize(220, 200));
        tableWidget->setMaximumSize(QSize(250, 16777215));
        tableWidget->setBaseSize(QSize(22, 22));
        tableWidget->setRowCount(29);
        tableWidget->setColumnCount(3);
        tableWidget->horizontalHeader()->setDefaultSectionSize(90);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(25);

        verticalLayout_2->addWidget(tableWidget);


        horizontalLayout_6->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout_6);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_6->addWidget(label, 0, 1, 1, 1);

        visible_Debug_window = new QPushButton(verticalLayoutWidget);
        visible_Debug_window->setObjectName(QStringLiteral("visible_Debug_window"));
        visible_Debug_window->setMaximumSize(QSize(25, 25));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/icons/to_down.png"), QSize(), QIcon::Normal, QIcon::Off);
        visible_Debug_window->setIcon(icon1);
        visible_Debug_window->setIconSize(QSize(24, 24));
        visible_Debug_window->setCheckable(true);

        gridLayout_6->addWidget(visible_Debug_window, 0, 2, 1, 1);

        label_17 = new QLabel(verticalLayoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_6->addWidget(label_17, 0, 0, 1, 1);

        textBrowser_history = new QTextBrowser(verticalLayoutWidget);
        textBrowser_history->setObjectName(QStringLiteral("textBrowser_history"));
        textBrowser_history->setMinimumSize(QSize(600, 0));
        textBrowser_history->setMaximumSize(QSize(600, 60));

        gridLayout_6->addWidget(textBrowser_history, 2, 1, 1, 2);

        DebugOutput = new QTextEdit(verticalLayoutWidget);
        DebugOutput->setObjectName(QStringLiteral("DebugOutput"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(DebugOutput->sizePolicy().hasHeightForWidth());
        DebugOutput->setSizePolicy(sizePolicy4);
        DebugOutput->setMaximumSize(QSize(712, 60));

        gridLayout_6->addWidget(DebugOutput, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_3, 3, 0, 1, 3);


        verticalLayout->addLayout(gridLayout_6);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayoutWidget_2 = new QWidget(tab_2);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(40, 10, 1261, 1660));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        tableView_ethernet = new QTableView(gridLayoutWidget_2);
        tableView_ethernet->setObjectName(QStringLiteral("tableView_ethernet"));
        tableView_ethernet->setMinimumSize(QSize(1250, 100));
        tableView_ethernet->setMaximumSize(QSize(2000, 100));

        horizontalLayout_12->addWidget(tableView_ethernet);


        gridLayout_5->addLayout(horizontalLayout_12, 7, 0, 1, 2);

        line_5 = new QFrame(gridLayoutWidget_2);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_5, 8, 0, 1, 2);

        tableView_can_Message = new QTableView(gridLayoutWidget_2);
        tableView_can_Message->setObjectName(QStringLiteral("tableView_can_Message"));
        sizePolicy.setHeightForWidth(tableView_can_Message->sizePolicy().hasHeightForWidth());
        tableView_can_Message->setSizePolicy(sizePolicy);
        tableView_can_Message->setMinimumSize(QSize(1250, 200));
        tableView_can_Message->setMaximumSize(QSize(2000, 200));

        gridLayout_5->addWidget(tableView_can_Message, 12, 0, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_3, 13, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton_ins = new QPushButton(gridLayoutWidget_2);
        pushButton_ins->setObjectName(QStringLiteral("pushButton_ins"));
        sizePolicy1.setHeightForWidth(pushButton_ins->sizePolicy().hasHeightForWidth());
        pushButton_ins->setSizePolicy(sizePolicy1);
        pushButton_ins->setMaximumSize(QSize(120, 27));
        pushButton_ins->setCheckable(true);

        gridLayout_3->addWidget(pushButton_ins, 8, 0, 1, 1);

        pushButton_lane = new QPushButton(gridLayoutWidget_2);
        pushButton_lane->setObjectName(QStringLiteral("pushButton_lane"));
        sizePolicy1.setHeightForWidth(pushButton_lane->sizePolicy().hasHeightForWidth());
        pushButton_lane->setSizePolicy(sizePolicy1);
        pushButton_lane->setMaximumSize(QSize(120, 27));
        pushButton_lane->setCheckable(true);

        gridLayout_3->addWidget(pushButton_lane, 0, 0, 1, 1);

        pushButton_ibeo = new QPushButton(gridLayoutWidget_2);
        pushButton_ibeo->setObjectName(QStringLiteral("pushButton_ibeo"));
        sizePolicy1.setHeightForWidth(pushButton_ibeo->sizePolicy().hasHeightForWidth());
        pushButton_ibeo->setSizePolicy(sizePolicy1);
        pushButton_ibeo->setMaximumSize(QSize(120, 27));
        pushButton_ibeo->setCheckable(true);

        gridLayout_3->addWidget(pushButton_ibeo, 12, 0, 1, 1);

        tableView_vcu = new QTableView(gridLayoutWidget_2);
        tableView_vcu->setObjectName(QStringLiteral("tableView_vcu"));
        tableView_vcu->setMaximumSize(QSize(16777215, 180));

        gridLayout_3->addWidget(tableView_vcu, 7, 0, 1, 2);

        pushButton_tsr = new QPushButton(gridLayoutWidget_2);
        pushButton_tsr->setObjectName(QStringLiteral("pushButton_tsr"));
        sizePolicy1.setHeightForWidth(pushButton_tsr->sizePolicy().hasHeightForWidth());
        pushButton_tsr->setSizePolicy(sizePolicy1);
        pushButton_tsr->setMaximumSize(QSize(120, 27));
        pushButton_tsr->setCheckable(true);

        gridLayout_3->addWidget(pushButton_tsr, 16, 0, 1, 1);

        pushButton_rsds = new QPushButton(gridLayoutWidget_2);
        pushButton_rsds->setObjectName(QStringLiteral("pushButton_rsds"));
        sizePolicy1.setHeightForWidth(pushButton_rsds->sizePolicy().hasHeightForWidth());
        pushButton_rsds->setSizePolicy(sizePolicy1);
        pushButton_rsds->setMaximumSize(QSize(120, 27));
        pushButton_rsds->setCheckable(true);

        gridLayout_3->addWidget(pushButton_rsds, 20, 0, 1, 1);

        pushButton_meobj = new QPushButton(gridLayoutWidget_2);
        pushButton_meobj->setObjectName(QStringLiteral("pushButton_meobj"));
        sizePolicy1.setHeightForWidth(pushButton_meobj->sizePolicy().hasHeightForWidth());
        pushButton_meobj->setSizePolicy(sizePolicy1);
        pushButton_meobj->setMaximumSize(QSize(120, 27));
        pushButton_meobj->setCheckable(true);

        gridLayout_3->addWidget(pushButton_meobj, 2, 0, 1, 1);

        pushButton_canprocy = new QPushButton(gridLayoutWidget_2);
        pushButton_canprocy->setObjectName(QStringLiteral("pushButton_canprocy"));
        sizePolicy1.setHeightForWidth(pushButton_canprocy->sizePolicy().hasHeightForWidth());
        pushButton_canprocy->setSizePolicy(sizePolicy1);
        pushButton_canprocy->setMaximumSize(QSize(120, 27));
        pushButton_canprocy->setCheckable(true);

        gridLayout_3->addWidget(pushButton_canprocy, 4, 0, 1, 1);

        tableView_melane = new QTableView(gridLayoutWidget_2);
        tableView_melane->setObjectName(QStringLiteral("tableView_melane"));
        sizePolicy.setHeightForWidth(tableView_melane->sizePolicy().hasHeightForWidth());
        tableView_melane->setSizePolicy(sizePolicy);
        tableView_melane->setMinimumSize(QSize(0, 0));
        tableView_melane->setMaximumSize(QSize(16777215, 200));

        gridLayout_3->addWidget(tableView_melane, 1, 0, 1, 2);

        tableView_velodyne = new QTableView(gridLayoutWidget_2);
        tableView_velodyne->setObjectName(QStringLiteral("tableView_velodyne"));
        tableView_velodyne->setMaximumSize(QSize(16777215, 120));

        gridLayout_3->addWidget(tableView_velodyne, 15, 0, 1, 2);

        pushButton_esr = new QPushButton(gridLayoutWidget_2);
        pushButton_esr->setObjectName(QStringLiteral("pushButton_esr"));
        pushButton_esr->setMaximumSize(QSize(120, 27));
        pushButton_esr->setCheckable(true);

        gridLayout_3->addWidget(pushButton_esr, 18, 0, 1, 1);

        pushButton_idc = new QPushButton(gridLayoutWidget_2);
        pushButton_idc->setObjectName(QStringLiteral("pushButton_idc"));
        sizePolicy1.setHeightForWidth(pushButton_idc->sizePolicy().hasHeightForWidth());
        pushButton_idc->setSizePolicy(sizePolicy1);
        pushButton_idc->setMaximumSize(QSize(120, 27));
        pushButton_idc->setCheckable(true);

        gridLayout_3->addWidget(pushButton_idc, 10, 0, 1, 1);

        pushButton_vcu = new QPushButton(gridLayoutWidget_2);
        pushButton_vcu->setObjectName(QStringLiteral("pushButton_vcu"));
        sizePolicy1.setHeightForWidth(pushButton_vcu->sizePolicy().hasHeightForWidth());
        pushButton_vcu->setSizePolicy(sizePolicy1);
        pushButton_vcu->setMinimumSize(QSize(120, 27));
        pushButton_vcu->setMaximumSize(QSize(120, 27));
        pushButton_vcu->setCheckable(true);

        gridLayout_3->addWidget(pushButton_vcu, 6, 0, 1, 1);

        pushButton_velodyne = new QPushButton(gridLayoutWidget_2);
        pushButton_velodyne->setObjectName(QStringLiteral("pushButton_velodyne"));
        sizePolicy1.setHeightForWidth(pushButton_velodyne->sizePolicy().hasHeightForWidth());
        pushButton_velodyne->setSizePolicy(sizePolicy1);
        pushButton_velodyne->setMaximumSize(QSize(120, 27));
        pushButton_velodyne->setCheckable(true);

        gridLayout_3->addWidget(pushButton_velodyne, 14, 0, 1, 1);

        tableView_inertial = new QTableView(gridLayoutWidget_2);
        tableView_inertial->setObjectName(QStringLiteral("tableView_inertial"));
        tableView_inertial->setMaximumSize(QSize(16777215, 400));

        gridLayout_3->addWidget(tableView_inertial, 9, 0, 1, 2);

        tableView_tsr = new QTableView(gridLayoutWidget_2);
        tableView_tsr->setObjectName(QStringLiteral("tableView_tsr"));
        tableView_tsr->setMaximumSize(QSize(16777215, 120));

        gridLayout_3->addWidget(tableView_tsr, 17, 0, 1, 2);

        tableView_meobs = new QTableView(gridLayoutWidget_2);
        tableView_meobs->setObjectName(QStringLiteral("tableView_meobs"));
        sizePolicy.setHeightForWidth(tableView_meobs->sizePolicy().hasHeightForWidth());
        tableView_meobs->setSizePolicy(sizePolicy);
        tableView_meobs->setMinimumSize(QSize(0, 20));
        tableView_meobs->setMaximumSize(QSize(16777215, 120));

        gridLayout_3->addWidget(tableView_meobs, 3, 0, 1, 2);

        tableView_esr = new QTableView(gridLayoutWidget_2);
        tableView_esr->setObjectName(QStringLiteral("tableView_esr"));
        tableView_esr->setMaximumSize(QSize(16777215, 120));

        gridLayout_3->addWidget(tableView_esr, 19, 0, 1, 2);

        tableView_ibeo = new QTableView(gridLayoutWidget_2);
        tableView_ibeo->setObjectName(QStringLiteral("tableView_ibeo"));
        tableView_ibeo->setMaximumSize(QSize(16777215, 120));

        gridLayout_3->addWidget(tableView_ibeo, 13, 0, 1, 2);

        tableView_rsds = new QTableView(gridLayoutWidget_2);
        tableView_rsds->setObjectName(QStringLiteral("tableView_rsds"));
        tableView_rsds->setMaximumSize(QSize(16777215, 120));

        gridLayout_3->addWidget(tableView_rsds, 21, 0, 1, 2);

        tableView_idc = new QTableView(gridLayoutWidget_2);
        tableView_idc->setObjectName(QStringLiteral("tableView_idc"));
        tableView_idc->setMaximumSize(QSize(16777215, 120));

        gridLayout_3->addWidget(tableView_idc, 11, 0, 1, 2);

        tableView_can2proxy = new QTableView(gridLayoutWidget_2);
        tableView_can2proxy->setObjectName(QStringLiteral("tableView_can2proxy"));
        sizePolicy.setHeightForWidth(tableView_can2proxy->sizePolicy().hasHeightForWidth());
        tableView_can2proxy->setSizePolicy(sizePolicy);
        tableView_can2proxy->setMinimumSize(QSize(0, 20));
        tableView_can2proxy->setMaximumSize(QSize(16777215, 120));

        gridLayout_3->addWidget(tableView_can2proxy, 5, 0, 1, 2);


        gridLayout_5->addLayout(gridLayout_3, 2, 0, 1, 2);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_5->addWidget(label_3, 10, 0, 1, 2);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_5->addWidget(label_2, 1, 0, 1, 2);

        line_6 = new QFrame(gridLayoutWidget_2);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_6, 9, 0, 1, 2);

        line_3 = new QFrame(gridLayoutWidget_2);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_3, 3, 0, 1, 2);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_5->addWidget(label_4, 5, 0, 1, 2);

        pushButton_detail_ethernet = new QPushButton(gridLayoutWidget_2);
        pushButton_detail_ethernet->setObjectName(QStringLiteral("pushButton_detail_ethernet"));
        pushButton_detail_ethernet->setMaximumSize(QSize(100, 30));
        pushButton_detail_ethernet->setCheckable(true);

        gridLayout_5->addWidget(pushButton_detail_ethernet, 6, 0, 1, 1);

        line_4 = new QFrame(gridLayoutWidget_2);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_4, 4, 0, 1, 2);

        pushButton_detail_can = new QPushButton(gridLayoutWidget_2);
        pushButton_detail_can->setObjectName(QStringLiteral("pushButton_detail_can"));
        pushButton_detail_can->setMaximumSize(QSize(100, 30));
        pushButton_detail_can->setCheckable(true);

        gridLayout_5->addWidget(pushButton_detail_can, 11, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayoutWidget = new QWidget(tab_3);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 20, 951, 741));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_data_logger = new QPushButton(gridLayoutWidget);
        pushButton_data_logger->setObjectName(QStringLiteral("pushButton_data_logger"));
        pushButton_data_logger->setMaximumSize(QSize(100, 30));

        horizontalLayout->addWidget(pushButton_data_logger);

        pushButton_datalibrary = new QPushButton(gridLayoutWidget);
        pushButton_datalibrary->setObjectName(QStringLiteral("pushButton_datalibrary"));
        pushButton_datalibrary->setMinimumSize(QSize(100, 0));
        pushButton_datalibrary->setMaximumSize(QSize(100, 30));

        horizontalLayout->addWidget(pushButton_datalibrary);

        pushButton_datastatics = new QPushButton(gridLayoutWidget);
        pushButton_datastatics->setObjectName(QStringLiteral("pushButton_datastatics"));
        pushButton_datastatics->setMaximumSize(QSize(100, 30));

        horizontalLayout->addWidget(pushButton_datastatics);

        pushButton_clear_data = new QPushButton(gridLayoutWidget);
        pushButton_clear_data->setObjectName(QStringLiteral("pushButton_clear_data"));
        pushButton_clear_data->setMaximumSize(QSize(100, 30));

        horizontalLayout->addWidget(pushButton_clear_data);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_26 = new QLabel(gridLayoutWidget);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setMaximumSize(QSize(70, 50));

        horizontalLayout_4->addWidget(label_26);

        pushButton_Log_Trigger = new QPushButton(gridLayoutWidget);
        pushButton_Log_Trigger->setObjectName(QStringLiteral("pushButton_Log_Trigger"));
        pushButton_Log_Trigger->setMaximumSize(QSize(30, 30));

        horizontalLayout_4->addWidget(pushButton_Log_Trigger);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        horizontalLayout_4->addItem(verticalSpacer);

        label_23 = new QLabel(gridLayoutWidget);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setMaximumSize(QSize(80, 50));

        horizontalLayout_4->addWidget(label_23);

        lineEdit_log_size = new QLineEdit(gridLayoutWidget);
        lineEdit_log_size->setObjectName(QStringLiteral("lineEdit_log_size"));
        lineEdit_log_size->setEnabled(false);
        lineEdit_log_size->setMaximumSize(QSize(50, 30));
        lineEdit_log_size->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lineEdit_log_size);

        label_24 = new QLabel(gridLayoutWidget);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setMaximumSize(QSize(20, 50));

        horizontalLayout_4->addWidget(label_24);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        horizontalLayout_4->addItem(verticalSpacer_2);

        label_22 = new QLabel(gridLayoutWidget);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setMaximumSize(QSize(80, 50));

        horizontalLayout_4->addWidget(label_22);

        lineEdit_space_left = new QLineEdit(gridLayoutWidget);
        lineEdit_space_left->setObjectName(QStringLiteral("lineEdit_space_left"));
        lineEdit_space_left->setEnabled(false);
        lineEdit_space_left->setMaximumSize(QSize(50, 30));
        lineEdit_space_left->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lineEdit_space_left);

        label_25 = new QLabel(gridLayoutWidget);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setMaximumSize(QSize(20, 50));

        horizontalLayout_4->addWidget(label_25);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        gridLayout_2->addLayout(horizontalLayout_4, 2, 0, 1, 1);

        label_20 = new QLabel(gridLayoutWidget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setMaximumSize(QSize(300, 30));
        label_20->setFont(font);

        gridLayout_2->addWidget(label_20, 0, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 3, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label_27 = new QLabel(tab_4);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(700, 350, 158, 175));
        label_27->setFont(font);
        pushButton_calibration = new QPushButton(tab_4);
        pushButton_calibration->setObjectName(QStringLiteral("pushButton_calibration"));
        pushButton_calibration->setGeometry(QRect(710, 550, 158, 30));
        pushButton_calibration->setMaximumSize(QSize(180, 30));
        pushButton_calibration->setCheckable(true);
        tabWidget->addTab(tab_4, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1009, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuPreference = new QMenu(menuBar);
        menuPreference->setObjectName(QStringLiteral("menuPreference"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuPreference->menuAction());
        menuFile->addAction(actionOpen_Ctrl_O);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Sys_chart", 0));
        actionOpen_Ctrl_O->setText(QApplication::translate("MainWindow", "Open(Ctrl+O)", 0));
        label_9->setText(QApplication::translate("MainWindow", "Scenario List:", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "lane keeping", 0)
         << QApplication::translate("MainWindow", "lane changing", 0)
        );
        label_15->setText(QApplication::translate("MainWindow", "Access Test Log: ", 0));
        visible_tablewidget->setText(QString());
        pushButton_resetall->setText(QApplication::translate("MainWindow", "RESET", 0));
        pushButton_analyzeroute->setText(QApplication::translate("MainWindow", "Load_route", 0));
        label_13->setText(QApplication::translate("MainWindow", "Behavior Analysis:", 0));
        pushButton_loadgpsins->setText(QApplication::translate("MainWindow", "Load_ins", 0));
        label_10->setText(QApplication::translate("MainWindow", "Load Data:", 0));
        pushButton_analyzelanekeep->setText(QApplication::translate("MainWindow", "Lane_Keep", 0));
        pushButton_analyzeovertaking->setText(QApplication::translate("MainWindow", "Overtaking", 0));
        pushButton_analyzeautochange->setText(QApplication::translate("MainWindow", "Auto_Change", 0));
        pushButton_loadlane->setText(QApplication::translate("MainWindow", "Load_lane", 0));
        pushButton_analyzeACC->setText(QApplication::translate("MainWindow", "ACC", 0));
        pushButton_loadcam->setText(QApplication::translate("MainWindow", "Load_cam", 0));
        pushButton_loadvcu->setText(QApplication::translate("MainWindow", "Load_vcu", 0));
        pushButton_analyzeacceleration->setText(QApplication::translate("MainWindow", "Accelerate", 0));
        pushButton_analyzeAEB->setText(QApplication::translate("MainWindow", "AEB", 0));
        pushButton_loadtsr->setText(QApplication::translate("MainWindow", "Load_tsr", 0));
        pushButton_idc_statics->setText(QApplication::translate("MainWindow", "Idc_statics", 0));
        pushButton_loadsys->setText(QApplication::translate("MainWindow", "Load_sys", 0));
        pushButton_loadcan->setText(QApplication::translate("MainWindow", "Load_can", 0));
        pushButton_loadobject->setText(QApplication::translate("MainWindow", "Load_object", 0));
        label_14->setText(QApplication::translate("MainWindow", "Visual Panel:", 0));
        comboBox_chart1_x->clear();
        comboBox_chart1_x->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NULL", 0)
        );
        comboBox_chart1_y->clear();
        comboBox_chart1_y->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NULL", 0)
        );
        chart1_MultiAxis->setText(QApplication::translate("MainWindow", "MultiAxis", 0));
        pushButton_screenshot1->setText(QApplication::translate("MainWindow", "ScreenShot", 0));
        pushButton_pause1->setText(QApplication::translate("MainWindow", "Pause", 0));
        pushButton_resetchart1->setText(QApplication::translate("MainWindow", "Reset", 0));
        comboBox_chart2_x->clear();
        comboBox_chart2_x->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NULL", 0)
        );
        comboBox_chart2_y->clear();
        comboBox_chart2_y->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NULL", 0)
        );
        chart2_MultiAxis->setText(QApplication::translate("MainWindow", "MultiAxis", 0));
        pushButton_screenshot2->setText(QApplication::translate("MainWindow", "ScreenShot", 0));
        pushButton_pause2->setText(QApplication::translate("MainWindow", "Pause", 0));
        pushButton_reset2->setText(QApplication::translate("MainWindow", "Reset", 0));
        label->setText(QApplication::translate("MainWindow", "History Window:", 0));
        visible_Debug_window->setText(QString());
        label_17->setText(QApplication::translate("MainWindow", "Debug Window:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Analysis", 0));
        pushButton_ins->setText(QApplication::translate("MainWindow", "           inertial", 0));
        pushButton_lane->setText(QApplication::translate("MainWindow", "          me lane", 0));
        pushButton_ibeo->setText(QApplication::translate("MainWindow", "                ibeo", 0));
        pushButton_tsr->setText(QApplication::translate("MainWindow", " traffic lights", 0));
        pushButton_rsds->setText(QApplication::translate("MainWindow", "                 rsds", 0));
        pushButton_meobj->setText(QApplication::translate("MainWindow", "          me objs", 0));
        pushButton_canprocy->setText(QApplication::translate("MainWindow", "      can proxy", 0));
        pushButton_esr->setText(QApplication::translate("MainWindow", "      delphi esr", 0));
        pushButton_idc->setText(QApplication::translate("MainWindow", "                   idc", 0));
        pushButton_vcu->setText(QApplication::translate("MainWindow", "                VCU", 0));
        pushButton_velodyne->setText(QApplication::translate("MainWindow", "       velodyne", 0));
        label_3->setText(QApplication::translate("MainWindow", "CAN Messages Status:**********************************************************************************************************************************************************", 0));
        label_2->setText(QApplication::translate("MainWindow", "LCM Messages Status:**********************************************************************************************************************************************************", 0));
        label_4->setText(QApplication::translate("MainWindow", "Ethernet Messages Status:******************************************************************************************************************************************************", 0));
        pushButton_detail_ethernet->setText(QApplication::translate("MainWindow", "show details", 0));
        pushButton_detail_can->setText(QApplication::translate("MainWindow", "show details", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "System Status", 0));
        pushButton_data_logger->setText(QApplication::translate("MainWindow", "Data Logger", 0));
        pushButton_datalibrary->setText(QApplication::translate("MainWindow", "Data Library", 0));
        pushButton_datastatics->setText(QApplication::translate("MainWindow", "Data Statics", 0));
        pushButton_clear_data->setText(QApplication::translate("MainWindow", "Clear Data", 0));
        label_26->setText(QApplication::translate("MainWindow", "Trigger:", 0));
        pushButton_Log_Trigger->setText(QString());
        label_23->setText(QApplication::translate("MainWindow", "Log Size", 0));
        label_24->setText(QApplication::translate("MainWindow", "GB", 0));
        label_22->setText(QApplication::translate("MainWindow", "Space Left", 0));
        label_25->setText(QApplication::translate("MainWindow", "GB", 0));
        label_20->setText(QApplication::translate("MainWindow", "Data Panel:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Data Statics", 0));
        label_27->setText(QApplication::translate("MainWindow", "Calibration Panel:", 0));
        pushButton_calibration->setText(QApplication::translate("MainWindow", "Calibration Interface", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Calibration", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuPreference->setTitle(QApplication::translate("MainWindow", "Preference", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
