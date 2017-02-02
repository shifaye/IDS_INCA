/********************************************************************************
** Form generated from reading UI file 'loggerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGGERWINDOW_H
#define UI_LOGGERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoggerWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidgetLCM;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_4;
    QLabel *label_23;
    QPushButton *pushButton_14;
    QPushButton *pushButton_32;
    QLabel *label_20;
    QPushButton *pushButton_11;
    QLabel *label_22;
    QPushButton *pushButton_26;
    QPushButton *pushButton_8;
    QLabel *label_37;
    QLabel *label_24;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QPushButton *pushButton_16;
    QPushButton *pushButton_5;
    QPushButton *pushButton_23;
    QPushButton *pushButton_28;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_18;
    QPushButton *pushButton_10;
    QPushButton *pushButton_20;
    QLabel *label_17;
    QLabel *label_27;
    QPushButton *pushButton_9;
    QPushButton *pushButton_19;
    QPushButton *pushButton_33;
    QPushButton *pushButton;
    QLabel *label_35;
    QLabel *label_19;
    QLabel *label_28;
    QLabel *label_31;
    QLabel *label_34;
    QPushButton *pushButton_18;
    QLabel *label_26;
    QPushButton *pushButton_24;
    QLabel *label_32;
    QPushButton *pushButton_27;
    QLabel *label_33;
    QLabel *label_30;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_17;
    QLabel *label_36;
    QPushButton *pushButton_25;
    QLabel *label_21;
    QPushButton *pushButton_12;
    QPushButton *pushButton_29;
    QPushButton *pushButton_31;
    QLabel *label_8;
    QLabel *label_29;
    QLabel *label_25;
    QListView *listView_tag_history;
    QLabel *label_39;
    QLabel *label_5;
    QLabel *label_16;
    QPushButton *pushButton_4;
    QLabel *label_38;
    QPushButton *pushButton_6;
    QLabel *label_40;
    QPushButton *pushButton_7;
    QLabel *label_41;
    QPushButton *pushButton_15;
    QLabel *label_42;
    QLabel *label_3;
    QPushButton *pushButtonStartRecord;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_14;
    QRadioButton *radioButton_19;
    QRadioButton *radioButton_18;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_17;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_12;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_11;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEditExtraFileName;
    QLabel *label_10;
    QLineEdit *lineEditBandWidth;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_13;
    QRadioButton *radioButton_15;
    QRadioButton *radioButton_16;
    QRadioButton *radioButton_12;
    QRadioButton *radioButton_13;
    QRadioButton *radioButton_14;
    QSpacerItem *horizontalSpacer_4;
    QFrame *line_2;
    QLineEdit *lineEditDataToWrite;
    QPushButton *pushButton_13;
    QLineEdit *lineEditDataWritten;
    QPushButton *pushButtonStopRecord;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_11;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_9;
    QRadioButton *radioButton_10;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_8;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QFrame *line;
    QLabel *label;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_15;
    QPushButton *pushButtonSelectall;
    QPushButton *pushButtonUnselectall;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LoggerWindow)
    {
        if (LoggerWindow->objectName().isEmpty())
            LoggerWindow->setObjectName(QStringLiteral("LoggerWindow"));
        LoggerWindow->resize(1094, 814);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoggerWindow->sizePolicy().hasHeightForWidth());
        LoggerWindow->setSizePolicy(sizePolicy);
        LoggerWindow->setMinimumSize(QSize(0, 0));
        LoggerWindow->setMaximumSize(QSize(4000, 4000));
        LoggerWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(LoggerWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tableWidgetLCM = new QTableWidget(centralWidget);
        if (tableWidgetLCM->columnCount() < 8)
            tableWidgetLCM->setColumnCount(8);
        tableWidgetLCM->setObjectName(QStringLiteral("tableWidgetLCM"));
        tableWidgetLCM->setMaximumSize(QSize(1100, 200));
        tableWidgetLCM->setColumnCount(8);

        gridLayout_2->addWidget(tableWidgetLCM, 1, 0, 1, 9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_23 = new QLabel(centralWidget);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setMaximumSize(QSize(90, 16777215));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_23->setFont(font);

        gridLayout_4->addWidget(label_23, 3, 5, 1, 1);

        pushButton_14 = new QPushButton(centralWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setMaximumSize(QSize(70, 60));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/icons/motorcycle.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon);
        pushButton_14->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_14, 7, 4, 1, 1);

        pushButton_32 = new QPushButton(centralWidget);
        pushButton_32->setObjectName(QStringLiteral("pushButton_32"));
        pushButton_32->setMaximumSize(QSize(70, 60));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/icons/expressway exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_32->setIcon(icon1);
        pushButton_32->setIconSize(QSize(55, 55));

        gridLayout_4->addWidget(pushButton_32, 5, 10, 1, 1);

        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font);

        gridLayout_4->addWidget(label_20, 3, 11, 1, 1);

        pushButton_11 = new QPushButton(centralWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(70, 60));
        pushButton_11->setMaximumSize(QSize(70, 60));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/icons/pictograms_road_signs_pedestrian_crossing_sign_256px_543140_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon2);
        pushButton_11->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_11, 6, 4, 1, 1);

        label_22 = new QLabel(centralWidget);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setFont(font);

        gridLayout_4->addWidget(label_22, 7, 3, 1, 1);

        pushButton_26 = new QPushButton(centralWidget);
        pushButton_26->setObjectName(QStringLiteral("pushButton_26"));
        pushButton_26->setMaximumSize(QSize(70, 60));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/icons/stopsign.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_26->setIcon(icon3);
        pushButton_26->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_26, 4, 4, 1, 1);

        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(70, 60));
        pushButton_8->setMaximumSize(QSize(70, 60));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/icons/pictograms_road_signs_traffic_lights_ahead_sign_256px_543119_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon4);
        pushButton_8->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_8, 4, 2, 1, 1);

        label_37 = new QLabel(centralWidget);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setFont(font);

        gridLayout_4->addWidget(label_37, 3, 9, 1, 1);

        label_24 = new QLabel(centralWidget);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setFont(font);

        gridLayout_4->addWidget(label_24, 4, 11, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        gridLayout_4->addLayout(horizontalLayout, 9, 0, 1, 9);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(90, 16777215));
        label_6->setFont(font);

        gridLayout_4->addWidget(label_6, 3, 1, 1, 1);

        pushButton_16 = new QPushButton(centralWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setMaximumSize(QSize(70, 60));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix1/icons/pictograms_road_signs_bicycles_roadsign_256px_543162_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_16->setIcon(icon5);
        pushButton_16->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_16, 5, 4, 1, 1);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(70, 60));
        pushButton_5->setMaximumSize(QSize(70, 60));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/prefix1/icons/pictograms_road_signs_dangerous_bend_to_right._128px_543158_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon6);
        pushButton_5->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_5, 3, 0, 1, 1);

        pushButton_23 = new QPushButton(centralWidget);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        pushButton_23->setMaximumSize(QSize(70, 60));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/new/prefix1/icons/U-turn.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_23->setIcon(icon7);
        pushButton_23->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_23, 3, 8, 1, 1);

        pushButton_28 = new QPushButton(centralWidget);
        pushButton_28->setObjectName(QStringLiteral("pushButton_28"));
        pushButton_28->setMaximumSize(QSize(70, 60));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/new/prefix1/icons/speed limit.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_28->setIcon(icon8);
        pushButton_28->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_28, 5, 2, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        gridLayout_4->addWidget(label_7, 4, 1, 1, 1);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        gridLayout_4->addWidget(label_9, 6, 1, 1, 1);

        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMaximumSize(QSize(90, 16777215));
        label_18->setFont(font);

        gridLayout_4->addWidget(label_18, 3, 3, 1, 1);

        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setMaximumSize(QSize(70, 60));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/new/prefix1/icons/Truck.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon9);
        pushButton_10->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_10, 3, 4, 1, 1);

        pushButton_20 = new QPushButton(centralWidget);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setMaximumSize(QSize(70, 60));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/new/prefix1/icons/Left_turn.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_20->setIcon(icon10);
        pushButton_20->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_20, 6, 6, 1, 1);

        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font);

        gridLayout_4->addWidget(label_17, 7, 1, 1, 1);

        label_27 = new QLabel(centralWidget);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setFont(font);

        gridLayout_4->addWidget(label_27, 7, 5, 1, 1);

        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(70, 60));
        pushButton_9->setMaximumSize(QSize(70, 60));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/new/prefix1/icons/pictograms_road_signs_roadlayout_sign_9_256px_543130_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon11);
        pushButton_9->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_9, 6, 0, 1, 1);

        pushButton_19 = new QPushButton(centralWidget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setMaximumSize(QSize(70, 60));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/new/prefix1/icons/Overtaking.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_19->setIcon(icon12);
        pushButton_19->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_19, 5, 6, 1, 1);

        pushButton_33 = new QPushButton(centralWidget);
        pushButton_33->setObjectName(QStringLiteral("pushButton_33"));
        pushButton_33->setMaximumSize(QSize(70, 60));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/new/prefix1/icons/tollgate.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_33->setIcon(icon13);
        pushButton_33->setIconSize(QSize(55, 55));

        gridLayout_4->addWidget(pushButton_33, 6, 10, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(70, 60));
        pushButton->setMaximumSize(QSize(70, 60));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/new/prefix1/icons/pictograms_road_signs_arrowup_arrowdown_directional_sign_256px_543163_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon14);
        pushButton->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton, 3, 2, 1, 1);

        label_35 = new QLabel(centralWidget);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setFont(font);

        gridLayout_4->addWidget(label_35, 6, 7, 1, 1);

        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font);

        gridLayout_4->addWidget(label_19, 4, 3, 1, 1);

        label_28 = new QLabel(centralWidget);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setFont(font);

        gridLayout_4->addWidget(label_28, 5, 11, 1, 1);

        label_31 = new QLabel(centralWidget);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setFont(font);

        gridLayout_4->addWidget(label_31, 5, 3, 1, 1);

        label_34 = new QLabel(centralWidget);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setFont(font);

        gridLayout_4->addWidget(label_34, 5, 7, 1, 1);

        pushButton_18 = new QPushButton(centralWidget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setMaximumSize(QSize(70, 60));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/new/prefix1/icons/Lane Change.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_18->setIcon(icon15);
        pushButton_18->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_18, 4, 6, 1, 1);

        label_26 = new QLabel(centralWidget);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setFont(font);

        gridLayout_4->addWidget(label_26, 6, 5, 1, 1);

        pushButton_24 = new QPushButton(centralWidget);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));
        pushButton_24->setMaximumSize(QSize(70, 60));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/new/prefix1/icons/Right_turn.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_24->setIcon(icon16);
        pushButton_24->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_24, 7, 6, 1, 1);

        label_32 = new QLabel(centralWidget);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setMaximumSize(QSize(90, 16777215));
        label_32->setFont(font);

        gridLayout_4->addWidget(label_32, 3, 7, 1, 1);

        pushButton_27 = new QPushButton(centralWidget);
        pushButton_27->setObjectName(QStringLiteral("pushButton_27"));
        pushButton_27->setMaximumSize(QSize(70, 60));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/new/prefix1/icons/human Interfere.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_27->setIcon(icon17);
        pushButton_27->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_27, 7, 2, 1, 1);

        label_33 = new QLabel(centralWidget);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setFont(font);

        gridLayout_4->addWidget(label_33, 4, 7, 1, 1);

        label_30 = new QLabel(centralWidget);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setFont(font);

        gridLayout_4->addWidget(label_30, 4, 5, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(70, 60));
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/new/prefix1/icons/Ttype.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon18);
        pushButton_2->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_2, 7, 0, 1, 1);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(70, 60));
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/new/prefix1/icons/ACC.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon19);
        pushButton_3->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_3, 3, 6, 1, 1);

        pushButton_17 = new QPushButton(centralWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setMaximumSize(QSize(70, 60));
        QIcon icon20;
        icon20.addFile(QStringLiteral(":/new/prefix1/icons/pictograms_road_signs_10_downward_gradient_roadsign_256px_543172_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_17->setIcon(icon20);
        pushButton_17->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_17, 4, 0, 1, 1);

        label_36 = new QLabel(centralWidget);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setFont(font);

        gridLayout_4->addWidget(label_36, 7, 7, 1, 1);

        pushButton_25 = new QPushButton(centralWidget);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));
        pushButton_25->setMaximumSize(QSize(70, 60));
        QIcon icon21;
        icon21.addFile(QStringLiteral(":/new/prefix1/icons/construction.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_25->setIcon(icon21);
        pushButton_25->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_25, 6, 2, 1, 1);

        label_21 = new QLabel(centralWidget);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font);

        gridLayout_4->addWidget(label_21, 6, 3, 1, 1);

        pushButton_12 = new QPushButton(centralWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(70, 60));
        pushButton_12->setMaximumSize(QSize(70, 60));
        QIcon icon22;
        icon22.addFile(QStringLiteral(":/new/prefix1/icons/cross.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon22);
        pushButton_12->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_12, 5, 0, 1, 1);

        pushButton_29 = new QPushButton(centralWidget);
        pushButton_29->setObjectName(QStringLiteral("pushButton_29"));
        pushButton_29->setMaximumSize(QSize(70, 60));
        QIcon icon23;
        icon23.addFile(QStringLiteral(":/new/prefix1/icons/Expressway Entrance.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_29->setIcon(icon23);
        pushButton_29->setIconSize(QSize(55, 55));

        gridLayout_4->addWidget(pushButton_29, 3, 10, 1, 1);

        pushButton_31 = new QPushButton(centralWidget);
        pushButton_31->setObjectName(QStringLiteral("pushButton_31"));
        pushButton_31->setMaximumSize(QSize(70, 60));
        QIcon icon24;
        icon24.addFile(QStringLiteral(":/new/prefix1/icons/exit_highway.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_31->setIcon(icon24);
        pushButton_31->setIconSize(QSize(55, 55));

        gridLayout_4->addWidget(pushButton_31, 4, 10, 1, 1);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        gridLayout_4->addWidget(label_8, 5, 1, 1, 1);

        label_29 = new QLabel(centralWidget);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setFont(font);

        gridLayout_4->addWidget(label_29, 6, 11, 1, 1);

        label_25 = new QLabel(centralWidget);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setFont(font);

        gridLayout_4->addWidget(label_25, 5, 5, 1, 1);

        listView_tag_history = new QListView(centralWidget);
        listView_tag_history->setObjectName(QStringLiteral("listView_tag_history"));
        listView_tag_history->setEnabled(false);
        sizePolicy.setHeightForWidth(listView_tag_history->sizePolicy().hasHeightForWidth());
        listView_tag_history->setSizePolicy(sizePolicy);
        listView_tag_history->setMinimumSize(QSize(0, 0));
        listView_tag_history->setMaximumSize(QSize(16777215, 50));

        gridLayout_4->addWidget(listView_tag_history, 8, 0, 1, 13);

        label_39 = new QLabel(centralWidget);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setFont(font);

        gridLayout_4->addWidget(label_39, 0, 0, 1, 3);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout_4->addWidget(label_5, 0, 6, 1, 2);

        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_4->addWidget(label_16, 0, 10, 1, 2);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMaximumSize(QSize(70, 60));
        QIcon icon25;
        icon25.addFile(QStringLiteral(":/new/prefix1/icons/parking.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon25);
        pushButton_4->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_4, 4, 8, 1, 1);

        label_38 = new QLabel(centralWidget);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setFont(font);

        gridLayout_4->addWidget(label_38, 4, 9, 1, 1);

        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMaximumSize(QSize(70, 60));
        QIcon icon26;
        icon26.addFile(QStringLiteral(":/new/prefix1/icons/following.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon26);
        pushButton_6->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_6, 5, 8, 1, 1);

        label_40 = new QLabel(centralWidget);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setFont(font);

        gridLayout_4->addWidget(label_40, 5, 9, 1, 1);

        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setMaximumSize(QSize(70, 60));
        pushButton_7->setFont(font);
        QIcon icon27;
        icon27.addFile(QStringLiteral(":/new/prefix1/icons/AEB.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon27);
        pushButton_7->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_7, 6, 8, 1, 1);

        label_41 = new QLabel(centralWidget);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setFont(font);

        gridLayout_4->addWidget(label_41, 6, 9, 1, 1);

        pushButton_15 = new QPushButton(centralWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setMaximumSize(QSize(70, 60));
        QIcon icon28;
        icon28.addFile(QStringLiteral(":/new/prefix1/icons/intersection.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_15->setIcon(icon28);
        pushButton_15->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_15, 7, 8, 1, 1);

        label_42 = new QLabel(centralWidget);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setFont(font);

        gridLayout_4->addWidget(label_42, 7, 9, 1, 1);


        gridLayout_3->addLayout(gridLayout_4, 0, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_3);


        gridLayout_2->addLayout(horizontalLayout_3, 12, 0, 1, 9);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(80, 30));

        gridLayout_2->addWidget(label_3, 3, 7, 1, 1);

        pushButtonStartRecord = new QPushButton(centralWidget);
        pushButtonStartRecord->setObjectName(QStringLiteral("pushButtonStartRecord"));
        pushButtonStartRecord->setMaximumSize(QSize(30, 30));

        gridLayout_2->addWidget(pushButtonStartRecord, 3, 1, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_8->addWidget(label_14);

        radioButton_19 = new QRadioButton(centralWidget);
        radioButton_19->setObjectName(QStringLiteral("radioButton_19"));

        horizontalLayout_8->addWidget(radioButton_19);

        radioButton_18 = new QRadioButton(centralWidget);
        radioButton_18->setObjectName(QStringLiteral("radioButton_18"));

        horizontalLayout_8->addWidget(radioButton_18);

        radioButton_4 = new QRadioButton(centralWidget);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setMaximumSize(QSize(160, 16777215));

        horizontalLayout_8->addWidget(radioButton_4);

        radioButton_17 = new QRadioButton(centralWidget);
        radioButton_17->setObjectName(QStringLiteral("radioButton_17"));

        horizontalLayout_8->addWidget(radioButton_17);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);


        gridLayout_2->addLayout(horizontalLayout_8, 9, 0, 1, 9);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_6->addWidget(label_12);

        radioButton_3 = new QRadioButton(centralWidget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_6->addWidget(radioButton_3);

        radioButton_11 = new QRadioButton(centralWidget);
        radioButton_11->setObjectName(QStringLiteral("radioButton_11"));

        horizontalLayout_6->addWidget(radioButton_11);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        gridLayout_2->addLayout(horizontalLayout_6, 7, 0, 1, 9);

        lineEditExtraFileName = new QLineEdit(centralWidget);
        lineEditExtraFileName->setObjectName(QStringLiteral("lineEditExtraFileName"));
        lineEditExtraFileName->setMaximumSize(QSize(400, 30));

        gridLayout_2->addWidget(lineEditExtraFileName, 3, 0, 1, 1);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        gridLayout_2->addWidget(label_10, 5, 0, 1, 1);

        lineEditBandWidth = new QLineEdit(centralWidget);
        lineEditBandWidth->setObjectName(QStringLiteral("lineEditBandWidth"));
        lineEditBandWidth->setEnabled(false);
        lineEditBandWidth->setMaximumSize(QSize(100, 30));

        gridLayout_2->addWidget(lineEditBandWidth, 3, 4, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_7->addWidget(label_13);

        radioButton_15 = new QRadioButton(centralWidget);
        radioButton_15->setObjectName(QStringLiteral("radioButton_15"));

        horizontalLayout_7->addWidget(radioButton_15);

        radioButton_16 = new QRadioButton(centralWidget);
        radioButton_16->setObjectName(QStringLiteral("radioButton_16"));

        horizontalLayout_7->addWidget(radioButton_16);

        radioButton_12 = new QRadioButton(centralWidget);
        radioButton_12->setObjectName(QStringLiteral("radioButton_12"));

        horizontalLayout_7->addWidget(radioButton_12);

        radioButton_13 = new QRadioButton(centralWidget);
        radioButton_13->setObjectName(QStringLiteral("radioButton_13"));

        horizontalLayout_7->addWidget(radioButton_13);

        radioButton_14 = new QRadioButton(centralWidget);
        radioButton_14->setObjectName(QStringLiteral("radioButton_14"));

        horizontalLayout_7->addWidget(radioButton_14);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);


        gridLayout_2->addLayout(horizontalLayout_7, 8, 0, 1, 9);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 4, 0, 1, 9);

        lineEditDataToWrite = new QLineEdit(centralWidget);
        lineEditDataToWrite->setObjectName(QStringLiteral("lineEditDataToWrite"));
        lineEditDataToWrite->setEnabled(false);
        lineEditDataToWrite->setMaximumSize(QSize(100, 30));

        gridLayout_2->addWidget(lineEditDataToWrite, 3, 6, 1, 1);

        pushButton_13 = new QPushButton(centralWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));

        gridLayout_2->addWidget(pushButton_13, 5, 1, 1, 3);

        lineEditDataWritten = new QLineEdit(centralWidget);
        lineEditDataWritten->setObjectName(QStringLiteral("lineEditDataWritten"));
        lineEditDataWritten->setEnabled(false);
        lineEditDataWritten->setMaximumSize(QSize(100, 30));

        gridLayout_2->addWidget(lineEditDataWritten, 3, 8, 1, 1);

        pushButtonStopRecord = new QPushButton(centralWidget);
        pushButtonStopRecord->setObjectName(QStringLiteral("pushButtonStopRecord"));
        pushButtonStopRecord->setMaximumSize(QSize(30, 30));

        gridLayout_2->addWidget(pushButtonStopRecord, 3, 2, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_4->addWidget(label_11);

        radioButton_7 = new QRadioButton(centralWidget);
        radioButton_7->setObjectName(QStringLiteral("radioButton_7"));

        horizontalLayout_4->addWidget(radioButton_7);

        radioButton_2 = new QRadioButton(centralWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_4->addWidget(radioButton_2);

        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_4->addWidget(radioButton);

        radioButton_9 = new QRadioButton(centralWidget);
        radioButton_9->setObjectName(QStringLiteral("radioButton_9"));

        horizontalLayout_4->addWidget(radioButton_9);

        radioButton_10 = new QRadioButton(centralWidget);
        radioButton_10->setObjectName(QStringLiteral("radioButton_10"));

        horizontalLayout_4->addWidget(radioButton_10);

        radioButton_5 = new QRadioButton(centralWidget);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));

        horizontalLayout_4->addWidget(radioButton_5);

        radioButton_6 = new QRadioButton(centralWidget);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));

        horizontalLayout_4->addWidget(radioButton_6);

        radioButton_8 = new QRadioButton(centralWidget);
        radioButton_8->setObjectName(QStringLiteral("radioButton_8"));

        horizontalLayout_4->addWidget(radioButton_8);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout_4, 6, 0, 1, 9);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(80, 30));

        gridLayout_2->addWidget(label_2, 3, 5, 1, 1);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 10, 0, 1, 9);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(80, 30));

        gridLayout_2->addWidget(label, 3, 3, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font);

        horizontalLayout_5->addWidget(label_15);

        pushButtonSelectall = new QPushButton(centralWidget);
        pushButtonSelectall->setObjectName(QStringLiteral("pushButtonSelectall"));
        pushButtonSelectall->setMaximumSize(QSize(100, 30));

        horizontalLayout_5->addWidget(pushButtonSelectall);

        pushButtonUnselectall = new QPushButton(centralWidget);
        pushButtonUnselectall->setObjectName(QStringLiteral("pushButtonUnselectall"));
        pushButtonUnselectall->setMaximumSize(QSize(100, 30));

        horizontalLayout_5->addWidget(pushButtonUnselectall);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(16777215, 30));
        label_4->setFont(font);

        gridLayout_2->addWidget(label_4, 11, 0, 1, 9);


        horizontalLayout_2->addLayout(gridLayout_2);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        LoggerWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(LoggerWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LoggerWindow->setStatusBar(statusBar);

        retranslateUi(LoggerWindow);

        QMetaObject::connectSlotsByName(LoggerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoggerWindow)
    {
        LoggerWindow->setWindowTitle(QApplication::translate("LoggerWindow", "Logger_Window", 0));
        label_23->setText(QApplication::translate("LoggerWindow", "Truck\n"
"CTRL+Z", 0));
        pushButton_14->setText(QString());
        pushButton_32->setText(QString());
        label_20->setText(QApplication::translate("LoggerWindow", "Express Entry\n"
"SHIFT+A", 0));
        pushButton_11->setText(QString());
        label_22->setText(QApplication::translate("LoggerWindow", "Interfere\n"
"CTRL+F", 0));
        pushButton_26->setText(QString());
        pushButton_8->setText(QString());
        label_37->setText(QApplication::translate("LoggerWindow", "U-Turn\n"
"SHIFT+Y", 0));
        label_24->setText(QApplication::translate("LoggerWindow", "Highway Exit\n"
"SHIFT+S", 0));
        label_6->setText(QApplication::translate("LoggerWindow", "Curve\n"
"CTRL+Q ", 0));
        pushButton_16->setText(QString());
        pushButton_5->setText(QString());
        pushButton_23->setText(QString());
        pushButton_28->setText(QString());
        label_7->setText(QApplication::translate("LoggerWindow", "Ramp\n"
"CTRL+W", 0));
        label_9->setText(QApplication::translate("LoggerWindow", "Merge\n"
"CTRL+R ", 0));
        label_18->setText(QApplication::translate("LoggerWindow", "Dual\n"
"CTRL+Y", 0));
        pushButton_10->setText(QString());
        pushButton_20->setText(QString());
        label_17->setText(QApplication::translate("LoggerWindow", "T-type Road\n"
"CTRL+T ", 0));
        label_27->setText(QApplication::translate("LoggerWindow", "MotorCycle\n"
"CTRL+B", 0));
        pushButton_9->setText(QString());
        pushButton_19->setText(QString());
        pushButton_33->setText(QString());
        pushButton->setText(QString());
        label_35->setText(QApplication::translate("LoggerWindow", "Left Turn\n"
"SHIFT+R", 0));
        label_19->setText(QApplication::translate("LoggerWindow", "TSR\n"
"CTRL+A", 0));
        label_28->setText(QApplication::translate("LoggerWindow", "Express Exit\n"
"SHIFT+D", 0));
        label_31->setText(QApplication::translate("LoggerWindow", "Speed Sign\n"
"CTRL+S", 0));
        label_34->setText(QApplication::translate("LoggerWindow", "Overtaking\n"
"SHIFT+E ", 0));
        pushButton_18->setText(QString());
        label_26->setText(QApplication::translate("LoggerWindow", "Pedestrian\n"
"CTRL+V", 0));
        pushButton_24->setText(QString());
        label_32->setText(QApplication::translate("LoggerWindow", "Lane Keep\n"
"SHIFT+Q", 0));
        pushButton_27->setText(QString());
        label_33->setText(QApplication::translate("LoggerWindow", "LaneChange\n"
"SHIFT+W", 0));
        label_30->setText(QApplication::translate("LoggerWindow", "Stop Sign\n"
"CTRL+X", 0));
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_17->setText(QString());
        label_36->setText(QApplication::translate("LoggerWindow", "Right Turn\n"
"SHIFT+T ", 0));
        pushButton_25->setText(QString());
        label_21->setText(QApplication::translate("LoggerWindow", "Construct\n"
"CTRL+D", 0));
        pushButton_12->setText(QString());
        pushButton_29->setText(QString());
        pushButton_31->setText(QString());
        label_8->setText(QApplication::translate("LoggerWindow", "Cross\n"
"CTRL+E", 0));
        label_29->setText(QApplication::translate("LoggerWindow", "Toll Gate\n"
"SHIFT+F", 0));
        label_25->setText(QApplication::translate("LoggerWindow", "Bycicle\n"
"CTRL+C", 0));
        label_39->setText(QApplication::translate("LoggerWindow", "Road Situation:", 0));
        label_5->setText(QApplication::translate("LoggerWindow", "Feature:", 0));
        label_16->setText(QApplication::translate("LoggerWindow", "TextLabel", 0));
        pushButton_4->setText(QString());
        label_38->setText(QApplication::translate("LoggerWindow", "Park\n"
"SHIFT+U", 0));
        pushButton_6->setText(QString());
        label_40->setText(QApplication::translate("LoggerWindow", "Following\n"
"SHIFT+I", 0));
        pushButton_7->setText(QString());
        label_41->setText(QApplication::translate("LoggerWindow", "Following\n"
"SHIFT+O", 0));
        pushButton_15->setText(QString());
        label_42->setText(QApplication::translate("LoggerWindow", "Intersection\n"
"SHIFT+P", 0));
        label_3->setText(QApplication::translate("LoggerWindow", "TextLabel", 0));
        pushButtonStartRecord->setText(QString());
        label_14->setText(QApplication::translate("LoggerWindow", "Driver Information:", 0));
        radioButton_19->setText(QApplication::translate("LoggerWindow", "No Driver", 0));
        radioButton_18->setText(QApplication::translate("LoggerWindow", "None", 0));
        radioButton_4->setText(QApplication::translate("LoggerWindow", "Professional Driver", 0));
        radioButton_17->setText(QApplication::translate("LoggerWindow", "Unprofessional Driver", 0));
        label_12->setText(QApplication::translate("LoggerWindow", "Vehicle Information:", 0));
        radioButton_3->setText(QApplication::translate("LoggerWindow", "speed range", 0));
        radioButton_11->setText(QApplication::translate("LoggerWindow", "Automation Level", 0));
        label_10->setText(QApplication::translate("LoggerWindow", "Configurate Basic Scenario", 0));
        label_13->setText(QApplication::translate("LoggerWindow", "Weather Information:", 0));
        radioButton_15->setText(QApplication::translate("LoggerWindow", "Normal", 0));
        radioButton_16->setText(QApplication::translate("LoggerWindow", "Sunny", 0));
        radioButton_12->setText(QApplication::translate("LoggerWindow", "Heavy Rain", 0));
        radioButton_13->setText(QApplication::translate("LoggerWindow", "Frog", 0));
        radioButton_14->setText(QApplication::translate("LoggerWindow", "Heavy Snow", 0));
        pushButton_13->setText(QApplication::translate("LoggerWindow", "Set Scenario", 0));
        pushButtonStopRecord->setText(QString());
        label_11->setText(QApplication::translate("LoggerWindow", "Environment Information:", 0));
        radioButton_7->setText(QApplication::translate("LoggerWindow", "Urban", 0));
        radioButton_2->setText(QApplication::translate("LoggerWindow", "Motorway", 0));
        radioButton->setText(QApplication::translate("LoggerWindow", "Highway", 0));
        radioButton_9->setText(QApplication::translate("LoggerWindow", "Parking(Open)", 0));
        radioButton_10->setText(QApplication::translate("LoggerWindow", "Parking(Garage)", 0));
        radioButton_5->setText(QApplication::translate("LoggerWindow", "Interstate", 0));
        radioButton_6->setText(QApplication::translate("LoggerWindow", "Resident", 0));
        radioButton_8->setText(QApplication::translate("LoggerWindow", "CountryRoad", 0));
        label_2->setText(QApplication::translate("LoggerWindow", "TextLabel", 0));
        label->setText(QApplication::translate("LoggerWindow", "TextLabel", 0));
        label_15->setText(QApplication::translate("LoggerWindow", "Logger Window:", 0));
        pushButtonSelectall->setText(QApplication::translate("LoggerWindow", "Select All", 0));
        pushButtonUnselectall->setText(QApplication::translate("LoggerWindow", "Unselect All", 0));
        label_4->setText(QApplication::translate("LoggerWindow", "Trigger By Tags:", 0));
    } // retranslateUi

};

namespace Ui {
    class LoggerWindow: public Ui_LoggerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGGERWINDOW_H
