#include "qplot.h"

QPlot::QPlot(QWidget* parent):
    m_fCurrentTime(0.0),
    m_bPauseReplot(false),
    m_bMultiAxis(true)
{
    this->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    this->xAxis->setDateTimeFormat("ss:zzz");
    this->xAxis->setAutoTickStep(true);

    this->yAxis2->setTickLabelType(QCPAxis::ltNumber);
    this->yAxis2->setVisible(true);
    this->yAxis2->setTickLabels(true);

    this->yAxis->setNumberPrecision(10);
    this->yAxis2->setNumberPrecision(10);

    this->setNoAntialiasingOnDrag(true);

    this->addGraph(this->xAxis, this->yAxis);//line1;
    this->addGraph(this->xAxis, this->yAxis2);//line2;
    this->addGraph(this->xAxis, this->yAxis2);//line3;
    this->addGraph(this->xAxis, this->yAxis);//line4;

    //set legend;
    this->legend->setVisible(true);//set legend visible;
    this->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);//set legend position;
    UpdateLegendLineName(0, "NULL");
    UpdateLegendLineName(1, "NULL");
    UpdateLegendLineName(2, "NULL");
    UpdateLegendLineName(3, "NULL");


    this->axisRect()->setupFullAxesBox();
    this->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes);

    m_pReplotTimer = new QTimer(this);
    connect(m_pReplotTimer, SIGNAL(timeout()), this, SLOT(OnReplotTimeOut()), Qt::QueuedConnection);
    m_pReplotTimer->start(100);//update the plot every 100ms;

    connect(this, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(OnMouseWheel(QWheelEvent*)));
    connect(this, SIGNAL(axisClick(QCPAxis*,QCPAxis::SelectablePart,QMouseEvent*)), this, SLOT(OnAxisClicked(QCPAxis*,QCPAxis::SelectablePart,QMouseEvent*)));
}

void QPlot::SetLineStyle(int lineIndex, QColor color, Qt::PenStyle penStyle,  QCPScatterStyle::ScatterShape scatterShape)
{
    QPen pen;
    pen.setWidth(0.5);
    pen.setColor(color);//set line color
    pen.setStyle(penStyle);//set line style;
    this->graph(lineIndex)->setPen(pen);

    graph(lineIndex)->setLineStyle(QCPGraph::lsNone);
    graph(lineIndex)->setScatterStyle(QCPScatterStyle(scatterShape, 4));//set scatter style;
}

void QPlot::OnMouseWheel(QWheelEvent *event)
{
    if(m_bMultiAxis)
    {
        if(this->xAxis->selectedParts().testFlag(QCPAxis::spAxis) || this->xAxis->selectedParts().testFlag(QCPAxis::spTickLabels))
        {
            this->axisRect()->setRangeZoomAxes(this->xAxis, this->yAxis);
            this->axisRect()->setRangeZoom(this->xAxis->orientation());
        }
        else if(this->yAxis->selectedParts().testFlag(QCPAxis::spAxis) || this->yAxis->selectedParts().testFlag(QCPAxis::spTickLabels))
        {
            this->axisRect()->setRangeZoomAxes(this->xAxis, this->yAxis);
            this->axisRect()->setRangeZoom(this->yAxis->orientation());


        }
        else if(this->yAxis2->selectedParts().testFlag(QCPAxis::spAxis) || this->yAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
        {
            this->axisRect()->setRangeZoomAxes(this->xAxis, this->yAxis2);
            this->axisRect()->setRangeZoom(this->yAxis2->orientation());
        }
        else
        {
            this->axisRect()->setRangeZoom(Qt::Horizontal|Qt::Vertical);
            this->axisRect()->setRangeDragAxes(this->xAxis, this->yAxis);
        }
    }
    else{
        if(this->xAxis->selectedParts().testFlag(QCPAxis::spAxis) || this->xAxis->selectedParts().testFlag(QCPAxis::spTickLabels))
        {
            this->axisRect()->setRangeZoom(this->xAxis->orientation());
        }
        else if(this->yAxis->selectedParts().testFlag(QCPAxis::spAxis) || this->yAxis->selectedParts().testFlag(QCPAxis::spTickLabels) || this->yAxis2->selectedParts().testFlag(QCPAxis::spAxis) || this->yAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
        {
            this->axisRect()->setRangeZoomAxes(this->xAxis, this->yAxis);
            this->axisRect()->setRangeZoom(Qt::Vertical);
        }
        else{
            this->axisRect()->setRangeZoom(Qt::Horizontal|Qt::Vertical);
        }
    }

}

void QPlot::AppendData2Line1(double timestamp, double value, bool replot)
{
    this->graph(0)->addData(timestamp, value);
    this->graph(0)->removeDataBefore(timestamp-60);
    m_fCurrentTime = timestamp;
}

void QPlot::AppendData2Line2(double timestamp, double value, bool replot)
{
    this->graph(1)->addData(timestamp, value);
    this->graph(1)->removeDataBefore(timestamp-60);
    m_fCurrentTime = timestamp;
}

void QPlot::AppendData2Line3(double timestamp, double value, bool replot)
{
    this->graph(2)->addData(timestamp, value);
    this->graph(2)->removeDataBefore(timestamp-60);
    m_fCurrentTime = timestamp;
}


void QPlot::AppendData2Line4(double timestamp, double value, bool replot)
{
    this->graph(3)->addData(timestamp, value);
    this->graph(3)->removeDataBefore(timestamp-60);
    m_fCurrentTime = timestamp;
}

void QPlot::OnReplotTimeOut()
{    
    static double fLastDelta = 0.0;
//    static double fLastDelta2 = 0.0;
//    static double fLastDelta3 = 0.0;
//    static double fLastDelta4 = 0.0;
//    double fDelta = 0.0;
//    double fDelta2 = 0.0;
//    double fDelta3 = 0.0;
//    double fDelta4 = 0.0;
    if(!m_bPauseReplot)
    {
        this->graph(0)->rescaleValueAxis(false);
        this->graph(1)->rescaleValueAxis(false);
        this->graph(2)->rescaleValueAxis(false);
        this->graph(3)->rescaleValueAxis(false);
        this->xAxis->setRange(m_fCurrentTime+0.25, 10.0, Qt::AlignRight);
        if(m_bMultiAxis)
        {
            this->yAxis->setRange(-30,160);
            this->yAxis2->setRange(-6.5,6.5);
//            fDelta = (this->yAxis->range().upper-this->yAxis->range().lower-2*fLastDelta*50.0)/50.0;
//            if(graph(0)->data()->size()>1||graph(3)->data()->size()>1)
//            {
//                this->yAxis->setRange(this->yAxis->range().lower, this->yAxis->range().upper);
//                fLastDelta = fDelta;
//            }
//            else if(graph(0)->data()->size()==1||graph(3)->data()->size()==1)
//            {

//            }

//            fDelta2 = (yAxis2->range().upper-yAxis2->range().lower-2*fLastDelta2*50.0)/50.0;
//            if(graph(1)->data()->size()>1)
//            {
//                this->yAxis2->setRange(yAxis2->range().lower, yAxis2->range().upper);
//                fLastDelta2 = fDelta2;
//            }
//            else if(graph(1)->data()->size()==1)
//            {

//            }

//            fDelta3 = (yAxis2->range().upper-yAxis2->range().lower-2*fLastDelta3*50.0)/50.0;
//            if(graph(2)->data()->size()>1)
//            {
//                this->yAxis2->setRange(yAxis2->range().lower, yAxis2->range().upper);
//                fLastDelta3 = fDelta3;
//            }
//            else if(graph(2)->data()->size()==1)
//            {

//            }

//            fDelta4 = (yAxis2->range().upper-yAxis2->range().lower-2*fLastDelta4*50.0)/50.0;
//            if(graph(3)->data()->size()>1)
//            {
//                this->yAxis2->setRange(yAxis2->range().lower, yAxis2->range().upper);
//                fLastDelta4 = fDelta4;
//            }
//            else if(graph(3)->data()->size()==1)
//            {

//            }
        }
        else
        {
            double fUpper = Maximum(yAxis->range().upper, yAxis2->range().upper)+1;
            double fLower = Minimum(yAxis->range().lower, yAxis2->range().lower)-1;
            double fDelta = (fUpper-fLower-2*fLastDelta)/50.0;
            if(graph(0)->data()->size()>0 || graph(1)->data()->size()>0|| graph(3)->data()->size()>0|| graph(4)->data()->size()>0)
            {
                this->yAxis->setRange(fLower, fUpper);
                this->yAxis2->setRange(fLower, fUpper);

                //                this->yAxis->setRange(fLower-fDelta, fUpper+fDelta);
                //                this->yAxis2->setRange(fLower-fDelta, fUpper+fDelta);
                fLastDelta = fDelta;
            }
        }

        this->yAxis2->setTickLabelType(QCPAxis::ltNumber);
        this->yAxis2->setVisible(true);
        this->yAxis2->setTickLabels(true);
        this->replot();
    }
}

void QPlot::UpdateLegendLineName(int lineIndex, QString name)
{
    this->graph(lineIndex)->setName(name);
}

double QPlot::Maximum(double first, double second)
{
    return (first>second) ? first:second;
}

double QPlot::Minimum(double first, double second)
{
    return (first<second) ? first:second;
}

void QPlot::UpdateMultiSingleAxis(bool multiAxis)
{
    m_bMultiAxis = multiAxis;
    if(m_bMultiAxis)
    {
        disconnect(this->yAxis, SIGNAL(rangeChanged(QCPRange)), this->yAxis2, SLOT(setRange(QCPRange)));
    }
    else
    {
        connect(this->yAxis, SIGNAL(rangeChanged(QCPRange)), this->yAxis2, SLOT(setRange(QCPRange)));
    }
}

void QPlot::OnAxisClicked(QCPAxis *axis, QCPAxis::SelectablePart part, QMouseEvent *event)
{
    if(m_bMultiAxis)
    {
        if(axis == this->xAxis)
        {
            this->axisRect()->setRangeDragAxes(this->xAxis, this->yAxis);
            this->axisRect()->setRangeDrag(this->xAxis->orientation());
        }
        else if(this->yAxis == axis)
        {
            this->axisRect()->setRangeDragAxes(this->xAxis, this->yAxis);
            //this->axisRect()->setRangeDrag(this->yAxis->orientation());
            this->axisRect()->setRangeDrag(Qt::Horizontal | Qt::Vertical);
        }
        else if(this->yAxis2 == axis)
        {
            this->axisRect()->setRangeDragAxes(this->xAxis, this->yAxis2);
            this->axisRect()->setRangeDrag(Qt::Horizontal | Qt::Vertical);
            //this->axisRect()->setRangeDrag(this->yAxis2->orientation());
        }
        else
        {
            this->axisRect()->setRangeDrag(Qt::Horizontal | Qt::Vertical);
        }
    }
    else
    {
        if(axis == this->xAxis)
        {
            this->axisRect()->setRangeDrag(this->xAxis->orientation());
        }
        else if(this->yAxis == axis)
        {
            this->axisRect()->setRangeDragAxes(this->xAxis, this->yAxis);
            this->axisRect()->setRangeDrag(Qt::Horizontal | Qt::Vertical);
        }
        else
        {
            this->axisRect()->setRangeDrag(Qt::Horizontal | Qt::Vertical);
        }
    }

}
