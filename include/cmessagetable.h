#ifndef CMESSAGETABLE_H
#define CMESSAGETABLE_H

#include <QObject>
#include "cmessagerow.h"

class CMessageTable : public QObject
{
    Q_OBJECT
public:
    explicit CMessageTable(QObject *parent = 0);

    QList<CMessageRow*> m_qListRowWidgets;
    int m_nRowWidgetsNum;

    int GetRowWidgetsNum();
    int GetChannelIndexByName(QString str);
signals:
    void ShowStatusMessage(QString);

public slots:
    void OnMessageReceived(MESSAGE msg);
};

#endif // CMESSAGETABLE_H
