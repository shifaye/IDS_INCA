#include "cmessagetable.h"

CMessageTable::CMessageTable(QObject *parent) : QObject(parent),
    m_nRowWidgetsNum(0)
{

}

int CMessageTable::GetRowWidgetsNum()
{
    return m_nRowWidgetsNum;
}

void CMessageTable::OnMessageReceived(MESSAGE msg)
{
    int index = GetChannelIndexByName(QString::fromStdString(msg.strChannelName));
    m_qListRowWidgets[index]->UpdateMsg(msg);
}

int CMessageTable::GetChannelIndexByName(QString str)
{

    //if the message is already in the table, return index;
    for(int i = 0; i<m_qListRowWidgets.size(); i++)
    {
        if(QString::compare(str, m_qListRowWidgets[i]->m_qStrChannelName) == 0)
        {
            return (i);
        }
    }

    //if the message has never exist in the table, create new row;
    m_qListRowWidgets.append(new CMessageRow(str));
    m_nRowWidgetsNum++;
    return (m_nRowWidgetsNum-1);
}
