#include "checkguest.h"

checkguest::checkguest(QObject *parent) :
    QObject(parent)
{
}

checkguest::checkguest(bool s,QString n, QString p, QObject *parent)
    :QObject(parent)
{
    signorlog=s;
    m_name=n;
    m_passwd=p;
    m_tcpSocket=new QTcpSocket(this);
    m_tcpSocket->connectToHost(QHostAddress("223.3.78.22"),31300);
    connect(this->m_tcpSocket,SIGNAL(connected()),this,SLOT(slotConnected()));
}


void checkguest::slotConnected()
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out<<signorlog<<m_name<<m_passwd;
    m_tcpSocket->write(block);
    connect(m_tcpSocket,SIGNAL(readyRead()),this,SLOT(slotReadMessage()));
}

void checkguest::slotReadMessage()
{
    QDataStream in(m_tcpSocket);
    in>>decide;
}

int checkguest::getwhether()
{
    return decide;
}
