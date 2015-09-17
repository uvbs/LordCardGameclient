#include "chatroom.h"
#include "ui_chatroom.h"
#include <QDebug>

chatroom::chatroom(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::chatroom)
{
    ui->setupUi(this);
}

chatroom::chatroom(QString n,int nu,QWidget *parent) :
    QFrame(parent),
    ui(new Ui::chatroom)
{
    ui->setupUi(this);
    this->userName=n;
    port=31301+nu;
    this->Enter();
    connect(ui->send,SIGNAL(clicked()),this,SLOT(slotSend()));
    ui->send->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;background-color:yellow");
    ui->content->setStyleSheet(";;;background-color:transparent");
    ui->sendtextEdit->setStyleSheet(";;;background-color:transparent");
    ui->infotable->setStyleSheet(";;;background-color:transparent");
}

chatroom::~chatroom()
{
    this->Leave();
    delete ui;
}

void chatroom::Enter()
{
    this->tcpSocket = new QTcpSocket(this);
    connect(this->tcpSocket,SIGNAL(connected()),this,SLOT(slotConnected()));
    this->tcpSocket->connectToHost("223.3.78.22",this->port);//和服务器连接
}

void chatroom::Leave()
{
    QString msg = this->userName + tr(" : 离开房间")+QString::number(port-31300);
    this->tcpSocket->write(msg.toLocal8Bit(),2*msg.length());
    this->tcpSocket->disconnectFromHost();//断开连接
}

void chatroom::slotConnected()
{
    connect(this->tcpSocket,SIGNAL(readyRead()),this,SLOT(slotDataReceived()));
    QString msg = this->userName + tr(" : 进入房间")+QString::number(port-31300);
    this->tcpSocket->write(msg.toLocal8Bit(),2*msg.length());
}

void chatroom::slotSend()
{
    if(ui->sendtextEdit->toPlainText()=="")
    {
        return;
    }
    QString msg = this->userName+" : "+ui->sendtextEdit->toPlainText();
    this->tcpSocket->write(msg.toLocal8Bit(),2*msg.length());
    ui->sendtextEdit->clear();
}

void chatroom::slotDataReceived()
{
    while(tcpSocket->bytesAvailable()>0)
    {
        QString msg = this->tcpSocket->readAll();
        ui->content->append(msg.left(msg.length()));
        ui->content->verticalScrollBar()->setValue(ui->content->verticalScrollBar()->maximum());
    }
}

void chatroom::slotinfoReceived()
{
    ui->infotable->setRowCount(3);
    ui->infotable->setColumnCount(2);
    ui->infotable->verticalHeader()->setVisible(false);
    ui->infotable->horizontalHeader()->setVisible(false);
    for(int i=0;i<3;i++)
    {
        ui->infotable->setItem(i,0,new QTableWidgetItem(name[i]));
        ui->infotable->setItem(i,1,new QTableWidgetItem(score[i]));
    }
}

void chatroom::slotrefreshinfo()
{
    for(int j=0;j<3;j++)
    {
        ui->infotable->setItem(j,1,new QTableWidgetItem(score[j]));
    }
}
