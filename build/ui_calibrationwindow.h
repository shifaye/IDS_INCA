/********************************************************************************
** Form generated from reading UI file 'calibrationwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATIONWINDOW_H
#define UI_CALIBRATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalibrationWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CalibrationWindow)
    {
        if (CalibrationWindow->objectName().isEmpty())
            CalibrationWindow->setObjectName(QStringLiteral("CalibrationWindow"));
        CalibrationWindow->resize(990, 815);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CalibrationWindow->sizePolicy().hasHeightForWidth());
        CalibrationWindow->setSizePolicy(sizePolicy);
        CalibrationWindow->setMinimumSize(QSize(0, 0));
        CalibrationWindow->setMaximumSize(QSize(4000, 4000));
        CalibrationWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(CalibrationWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        CalibrationWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CalibrationWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CalibrationWindow->setStatusBar(statusBar);

        retranslateUi(CalibrationWindow);

        QMetaObject::connectSlotsByName(CalibrationWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CalibrationWindow)
    {
        CalibrationWindow->setWindowTitle(QApplication::translate("CalibrationWindow", "Logger_Window", 0));
    } // retranslateUi

};

namespace Ui {
    class CalibrationWindow: public Ui_CalibrationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATIONWINDOW_H
