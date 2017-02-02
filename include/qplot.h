#ifndef QPLOT_H
#define QPLOT_H

#include <QWidget>
#include <QPen>
#include "global.hpp"
#include "qcustomplot.h"

class QPlot : public QCustomPlot
{
    Q_OBJECT
public:
    QPlot(QWidget* parent = 0);
    void SetLineStyle(int lineIndex, QColor color=Qt::black, Qt::PenStyle penStyle=Qt::SolidLine, QCPScatterStyle::ScatterShape scatterShape = QCPScatterStyle::ssDisc);

    void AppendData2Line1(double timestamp, double value, bool replot=false);
    void AppendData2Line2(double timestamp, double value, bool replot=false);
    void AppendData2Line3(double timestamp, double value, bool replot=false);
    void AppendData2Line4(double timestamp, double value, bool replot=false);

    void UpdateLegendLineName(int lineIndex, QString name);
    void UpdateMultiSingleAxis(bool multiAxis);
private:
    inline double Maximum(double first, double second);
    inline double Minimum(double first, double second);
public:
    QCustomPlot* m_pPlot;
    QTimer* m_pReplotTimer;
    double m_fCurrentTime;
    bool m_bPauseReplot;
    bool m_bMultiAxis;
signals:
    void ShowStatusMsg(QString msg);
public slots:
    void OnMouseWheel(QWheelEvent* event);
    void OnReplotTimeOut();
    void OnAxisClicked(QCPAxis* axis, QCPAxis::SelectablePart part, QMouseEvent *  event);
};

#endif // QPLOT_H
