/********************************************************************************
** Form generated from reading UI file 'systemwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMWINDOW_H
#define UI_SYSTEMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab_modules;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QFrame *line;
    QLabel *label;
    QPushButton *pushButton_app_drivermap;
    QPushButton *pushButton_app_me_process;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_app_ibeo;
    QLabel *label_4;
    QFrame *line_2;
    QLabel *label_5;
    QPushButton *pushButton_app_adp;
    QLabel *label_3;
    QLabel *label_7;
    QPushButton *pushButton_app_chart;
    QPushButton *pushButton_app_velodyne;
    QLabel *label_2;
    QPushButton *pushButton_app_mobileye;
    QTableWidget *tableWidget_Error_Warnings;
    QPushButton *pushButton_app_player;
    QFrame *line_4;
    QPushButton *pushButton_app_velodyneprocess;
    QPushButton *pushButton_app_ibeoprocess;
    QPushButton *pushButton_app_lanefusion;
    QPushButton *pushButton_app_ins;
    QFrame *line_3;
    QPushButton *pushButton_app_vcu;
    QLabel *label_6;
    QPushButton *pushButton_app_transformer;
    QPushButton *pushButton_app_viewer;
    QPushButton *pushButton_app_logitech;
    QPushButton *pushButton_app_logger;
    QPushButton *pushButton_app_vcb;
    QFrame *line_5;
    QLabel *label_8;
    QPushButton *pushButton_app_idc2vcu;
    QWidget *tab_communication;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_CAN_Capture;
    QPushButton *pushButton_IP_Capture;
    QListWidget *listWidget_CAN;
    QListWidget *listWidget_IP;
    QTableWidget *tableWidget_List_Dev_Stats;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SystemWindow)
    {
        if (SystemWindow->objectName().isEmpty())
            SystemWindow->setObjectName(QStringLiteral("SystemWindow"));
        SystemWindow->resize(939, 644);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SystemWindow->sizePolicy().hasHeightForWidth());
        SystemWindow->setSizePolicy(sizePolicy);
        SystemWindow->setMinimumSize(QSize(0, 0));
        SystemWindow->setMaximumSize(QSize(4000, 4000));
        SystemWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(SystemWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_modules = new QWidget();
        tab_modules->setObjectName(QStringLiteral("tab_modules"));
        gridLayout_6 = new QGridLayout(tab_modules);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        line = new QFrame(tab_modules);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line, 9, 0, 1, 9);

        label = new QLabel(tab_modules);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 30));

        gridLayout_5->addWidget(label, 0, 0, 1, 9);

        pushButton_app_drivermap = new QPushButton(tab_modules);
        pushButton_app_drivermap->setObjectName(QStringLiteral("pushButton_app_drivermap"));
        pushButton_app_drivermap->setMaximumSize(QSize(180, 30));

        gridLayout_5->addWidget(pushButton_app_drivermap, 8, 0, 1, 1);

        pushButton_app_me_process = new QPushButton(tab_modules);
        pushButton_app_me_process->setObjectName(QStringLiteral("pushButton_app_me_process"));
        pushButton_app_me_process->setMaximumSize(QSize(250, 30));

        gridLayout_5->addWidget(pushButton_app_me_process, 5, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_app_ibeo = new QPushButton(tab_modules);
        pushButton_app_ibeo->setObjectName(QStringLiteral("pushButton_app_ibeo"));
        pushButton_app_ibeo->setMaximumSize(QSize(180, 30));

        verticalLayout->addWidget(pushButton_app_ibeo);


        gridLayout_5->addLayout(verticalLayout, 3, 0, 1, 1);

        label_4 = new QLabel(tab_modules);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_5->addWidget(label_4, 1, 2, 1, 1);

        line_2 = new QFrame(tab_modules);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_2, 1, 1, 8, 1);

        label_5 = new QLabel(tab_modules);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_5->addWidget(label_5, 1, 4, 1, 1);

        pushButton_app_adp = new QPushButton(tab_modules);
        pushButton_app_adp->setObjectName(QStringLiteral("pushButton_app_adp"));
        pushButton_app_adp->setMaximumSize(QSize(130, 50));

        gridLayout_5->addWidget(pushButton_app_adp, 4, 6, 1, 1);

        label_3 = new QLabel(tab_modules);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_5->addWidget(label_3, 1, 0, 1, 1);

        label_7 = new QLabel(tab_modules);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_5->addWidget(label_7, 1, 8, 1, 1);

        pushButton_app_chart = new QPushButton(tab_modules);
        pushButton_app_chart->setObjectName(QStringLiteral("pushButton_app_chart"));
        pushButton_app_chart->setMaximumSize(QSize(130, 30));

        gridLayout_5->addWidget(pushButton_app_chart, 5, 8, 1, 1);

        pushButton_app_velodyne = new QPushButton(tab_modules);
        pushButton_app_velodyne->setObjectName(QStringLiteral("pushButton_app_velodyne"));
        pushButton_app_velodyne->setMaximumSize(QSize(180, 30));

        gridLayout_5->addWidget(pushButton_app_velodyne, 2, 0, 1, 1);

        label_2 = new QLabel(tab_modules);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(16777215, 30));

        gridLayout_5->addWidget(label_2, 12, 0, 1, 9);

        pushButton_app_mobileye = new QPushButton(tab_modules);
        pushButton_app_mobileye->setObjectName(QStringLiteral("pushButton_app_mobileye"));
        pushButton_app_mobileye->setMaximumSize(QSize(180, 30));

        gridLayout_5->addWidget(pushButton_app_mobileye, 5, 0, 1, 1);

        tableWidget_Error_Warnings = new QTableWidget(tab_modules);
        if (tableWidget_Error_Warnings->columnCount() < 5)
            tableWidget_Error_Warnings->setColumnCount(5);
        if (tableWidget_Error_Warnings->rowCount() < 11)
            tableWidget_Error_Warnings->setRowCount(11);
        tableWidget_Error_Warnings->setObjectName(QStringLiteral("tableWidget_Error_Warnings"));
        tableWidget_Error_Warnings->setMaximumSize(QSize(16777215, 200));
        tableWidget_Error_Warnings->setRowCount(11);
        tableWidget_Error_Warnings->setColumnCount(5);
        tableWidget_Error_Warnings->horizontalHeader()->setMinimumSectionSize(60);
        tableWidget_Error_Warnings->verticalHeader()->setVisible(false);

        gridLayout_5->addWidget(tableWidget_Error_Warnings, 13, 0, 1, 9);

        pushButton_app_player = new QPushButton(tab_modules);
        pushButton_app_player->setObjectName(QStringLiteral("pushButton_app_player"));
        pushButton_app_player->setMaximumSize(QSize(130, 30));

        gridLayout_5->addWidget(pushButton_app_player, 7, 8, 1, 1);

        line_4 = new QFrame(tab_modules);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_4, 1, 3, 8, 1);

        pushButton_app_velodyneprocess = new QPushButton(tab_modules);
        pushButton_app_velodyneprocess->setObjectName(QStringLiteral("pushButton_app_velodyneprocess"));
        pushButton_app_velodyneprocess->setMaximumSize(QSize(250, 30));

        gridLayout_5->addWidget(pushButton_app_velodyneprocess, 2, 2, 1, 1);

        pushButton_app_ibeoprocess = new QPushButton(tab_modules);
        pushButton_app_ibeoprocess->setObjectName(QStringLiteral("pushButton_app_ibeoprocess"));
        pushButton_app_ibeoprocess->setMaximumSize(QSize(250, 30));

        gridLayout_5->addWidget(pushButton_app_ibeoprocess, 3, 2, 1, 1);

        pushButton_app_lanefusion = new QPushButton(tab_modules);
        pushButton_app_lanefusion->setObjectName(QStringLiteral("pushButton_app_lanefusion"));
        pushButton_app_lanefusion->setMaximumSize(QSize(170, 30));

        gridLayout_5->addWidget(pushButton_app_lanefusion, 5, 4, 1, 1);

        pushButton_app_ins = new QPushButton(tab_modules);
        pushButton_app_ins->setObjectName(QStringLiteral("pushButton_app_ins"));
        pushButton_app_ins->setMaximumSize(QSize(180, 30));
        pushButton_app_ins->setCheckable(true);

        gridLayout_5->addWidget(pushButton_app_ins, 4, 0, 1, 1);

        line_3 = new QFrame(tab_modules);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_3, 1, 5, 8, 1);

        pushButton_app_vcu = new QPushButton(tab_modules);
        pushButton_app_vcu->setObjectName(QStringLiteral("pushButton_app_vcu"));
        pushButton_app_vcu->setMaximumSize(QSize(170, 30));

        gridLayout_5->addWidget(pushButton_app_vcu, 10, 4, 1, 1);

        label_6 = new QLabel(tab_modules);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_5->addWidget(label_6, 1, 6, 1, 1);

        pushButton_app_transformer = new QPushButton(tab_modules);
        pushButton_app_transformer->setObjectName(QStringLiteral("pushButton_app_transformer"));
        pushButton_app_transformer->setMaximumSize(QSize(170, 30));

        gridLayout_5->addWidget(pushButton_app_transformer, 6, 4, 1, 1);

        pushButton_app_viewer = new QPushButton(tab_modules);
        pushButton_app_viewer->setObjectName(QStringLiteral("pushButton_app_viewer"));
        pushButton_app_viewer->setMaximumSize(QSize(130, 30));

        gridLayout_5->addWidget(pushButton_app_viewer, 6, 8, 1, 1);

        pushButton_app_logitech = new QPushButton(tab_modules);
        pushButton_app_logitech->setObjectName(QStringLiteral("pushButton_app_logitech"));
        pushButton_app_logitech->setMaximumSize(QSize(180, 30));

        gridLayout_5->addWidget(pushButton_app_logitech, 6, 0, 1, 1);

        pushButton_app_logger = new QPushButton(tab_modules);
        pushButton_app_logger->setObjectName(QStringLiteral("pushButton_app_logger"));
        pushButton_app_logger->setMaximumSize(QSize(130, 30));

        gridLayout_5->addWidget(pushButton_app_logger, 8, 8, 1, 1);

        pushButton_app_vcb = new QPushButton(tab_modules);
        pushButton_app_vcb->setObjectName(QStringLiteral("pushButton_app_vcb"));
        pushButton_app_vcb->setMaximumSize(QSize(180, 30));

        gridLayout_5->addWidget(pushButton_app_vcb, 7, 0, 1, 1);

        line_5 = new QFrame(tab_modules);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_5, 1, 7, 8, 1);

        label_8 = new QLabel(tab_modules);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_5->addWidget(label_8, 10, 0, 1, 1);

        pushButton_app_idc2vcu = new QPushButton(tab_modules);
        pushButton_app_idc2vcu->setObjectName(QStringLiteral("pushButton_app_idc2vcu"));
        pushButton_app_idc2vcu->setMaximumSize(QSize(170, 30));

        gridLayout_5->addWidget(pushButton_app_idc2vcu, 10, 6, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 1);

        tabWidget->addTab(tab_modules, QString());
        tab_communication = new QWidget();
        tab_communication->setObjectName(QStringLiteral("tab_communication"));
        gridLayout_4 = new QGridLayout(tab_communication);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton_CAN_Capture = new QPushButton(tab_communication);
        pushButton_CAN_Capture->setObjectName(QStringLiteral("pushButton_CAN_Capture"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_CAN_Capture->sizePolicy().hasHeightForWidth());
        pushButton_CAN_Capture->setSizePolicy(sizePolicy1);
        pushButton_CAN_Capture->setMaximumSize(QSize(150, 30));

        gridLayout_3->addWidget(pushButton_CAN_Capture, 2, 0, 1, 1);

        pushButton_IP_Capture = new QPushButton(tab_communication);
        pushButton_IP_Capture->setObjectName(QStringLiteral("pushButton_IP_Capture"));
        sizePolicy1.setHeightForWidth(pushButton_IP_Capture->sizePolicy().hasHeightForWidth());
        pushButton_IP_Capture->setSizePolicy(sizePolicy1);
        pushButton_IP_Capture->setMaximumSize(QSize(150, 30));

        gridLayout_3->addWidget(pushButton_IP_Capture, 0, 0, 1, 1);

        listWidget_CAN = new QListWidget(tab_communication);
        listWidget_CAN->setObjectName(QStringLiteral("listWidget_CAN"));
        listWidget_CAN->setMaximumSize(QSize(16777215, 200));
        listWidget_CAN->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        gridLayout_3->addWidget(listWidget_CAN, 2, 1, 1, 1);

        listWidget_IP = new QListWidget(tab_communication);
        listWidget_IP->setObjectName(QStringLiteral("listWidget_IP"));
        listWidget_IP->setMaximumSize(QSize(16777215, 100));

        gridLayout_3->addWidget(listWidget_IP, 0, 1, 1, 1);

        tableWidget_List_Dev_Stats = new QTableWidget(tab_communication);
        if (tableWidget_List_Dev_Stats->columnCount() < 7)
            tableWidget_List_Dev_Stats->setColumnCount(7);
        if (tableWidget_List_Dev_Stats->rowCount() < 3)
            tableWidget_List_Dev_Stats->setRowCount(3);
        tableWidget_List_Dev_Stats->setObjectName(QStringLiteral("tableWidget_List_Dev_Stats"));
        tableWidget_List_Dev_Stats->setMaximumSize(QSize(16777215, 120));
        tableWidget_List_Dev_Stats->setRowCount(3);
        tableWidget_List_Dev_Stats->setColumnCount(7);
        tableWidget_List_Dev_Stats->verticalHeader()->setVisible(false);

        gridLayout_3->addWidget(tableWidget_List_Dev_Stats, 1, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        tabWidget->addTab(tab_communication, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        SystemWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SystemWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SystemWindow->setStatusBar(statusBar);

        retranslateUi(SystemWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SystemWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SystemWindow)
    {
        SystemWindow->setWindowTitle(QApplication::translate("SystemWindow", "Sys_chart", 0));
        label->setText(QApplication::translate("SystemWindow", "Display All Modules Running Status", 0));
        pushButton_app_drivermap->setText(QApplication::translate("SystemWindow", "app_driver_map", 0));
        pushButton_app_me_process->setText(QApplication::translate("SystemWindow", "app_mobileye_process", 0));
        pushButton_app_ibeo->setText(QApplication::translate("SystemWindow", "app_ibeo", 0));
        label_4->setText(QApplication::translate("SystemWindow", "Data Process", 0));
        label_5->setText(QApplication::translate("SystemWindow", "Transform & Fusion", 0));
        pushButton_app_adp->setText(QApplication::translate("SystemWindow", "app_adp", 0));
        label_3->setText(QApplication::translate("SystemWindow", "Raw Data", 0));
        label_7->setText(QApplication::translate("SystemWindow", "System Tools", 0));
        pushButton_app_chart->setText(QApplication::translate("SystemWindow", "app_chart", 0));
        pushButton_app_velodyne->setText(QApplication::translate("SystemWindow", "app_velodyne", 0));
        label_2->setText(QApplication::translate("SystemWindow", "Display Detailed Running Errors Or Warnings:", 0));
        pushButton_app_mobileye->setText(QApplication::translate("SystemWindow", "app_mobileye", 0));
        pushButton_app_player->setText(QApplication::translate("SystemWindow", "app_player", 0));
        pushButton_app_velodyneprocess->setText(QApplication::translate("SystemWindow", "app_velodyne_process", 0));
        pushButton_app_ibeoprocess->setText(QApplication::translate("SystemWindow", "app_Ibeo_process", 0));
        pushButton_app_lanefusion->setText(QApplication::translate("SystemWindow", "app_lane_fusion", 0));
        pushButton_app_ins->setText(QApplication::translate("SystemWindow", "app_ins", 0));
        pushButton_app_vcu->setText(QApplication::translate("SystemWindow", "app_can2proxy", 0));
        label_6->setText(QApplication::translate("SystemWindow", "Decesion & Planning", 0));
        pushButton_app_transformer->setText(QApplication::translate("SystemWindow", "app_transformer", 0));
        pushButton_app_viewer->setText(QApplication::translate("SystemWindow", "app_viewer", 0));
        pushButton_app_logitech->setText(QApplication::translate("SystemWindow", "app_logitech", 0));
        pushButton_app_logger->setText(QApplication::translate("SystemWindow", "app_logger", 0));
        pushButton_app_vcb->setText(QApplication::translate("SystemWindow", "app_vcb", 0));
        label_8->setText(QApplication::translate("SystemWindow", "VCU Related", 0));
        pushButton_app_idc2vcu->setText(QApplication::translate("SystemWindow", "app_idc2vcu", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_modules), QApplication::translate("SystemWindow", "Modules", 0));
        pushButton_CAN_Capture->setText(QApplication::translate("SystemWindow", "CAN Capture", 0));
        pushButton_IP_Capture->setText(QApplication::translate("SystemWindow", "IP Capture", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_communication), QApplication::translate("SystemWindow", "Communication", 0));
    } // retranslateUi

};

namespace Ui {
    class SystemWindow: public Ui_SystemWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMWINDOW_H
