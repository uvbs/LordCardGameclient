#include "roomchoser.h"
#include "ui_roomchoser.h"
#include <QCloseEvent>


Roomchoser::Roomchoser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Roomchoser)
{
    ui->setupUi(this);
    inorout=1;
    roommate=0;
    whichbutton=false;
    this->setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint);
    this->move((QApplication::desktop()->width() - this->width())/2,
               (QApplication::desktop()->height() - this->height())/2);
    ui->checkwho->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;background-color:orange");
    ui->joinButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;background-color:red");
    m_tcpSocket=new QTcpSocket(this);
    m_tcpSocket->connectToHost(QHostAddress("223.3.78.22"),31361);
    connect(m_tcpSocket,SIGNAL(connected()),this,SLOT(acceptConnection()));
}

Roomchoser::~Roomchoser()
{
    delete ui;
}

void Roomchoser::acceptConnection()
{
    //滞留2秒
    QTime t;
    t.start();
    while(t.elapsed()<50)
    {
        QApplication::processEvents();
    }
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out<<name<<0<<whichbutton<<inorout;
    m_tcpSocket->write(block);
    connect(m_tcpSocket,SIGNAL(readyRead()),this,SLOT(slotReadMessage()));
}

void Roomchoser::slotsend()
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    int i=ui->roomchoser->currentIndex()+1;
    out<<name<<i<<whichbutton<<inorout;
    m_tcpSocket->write(block);
}

void Roomchoser::slotReadMessage()
{
    QString i;
    QDataStream in(m_tcpSocket);
    in>>roommate;
    for(int i=0;i<3;i++)
    {
        in>>name1[i]>>score[i];
    }
    in>>i;
    if(roommate==4)
    {
        //隐藏房间选择界面并进入游戏
        game* w=new game;
        w->setAttribute(Qt::WA_DeleteOnClose);
        connect(w,SIGNAL(userclose()),this,SLOT(letUserExit()));
        player p(name,ui->roomchoser->currentIndex());
        QObject::connect(&p,SIGNAL(nameSignal(QString,int)),w,SLOT(readplayer(QString,int)));
        p.sendchat();
        w->show();
        //隐藏房间选择界面并进入游戏
    }
}

void Roomchoser::closeEvent(QCloseEvent* r)
{
    this->m_tcpSocket->disconnectFromHost();
    r->accept();
}

void Roomchoser::on_checkwho_clicked()
{
    whichbutton=false;
    this->slotsend();
    ui->listWidget->clear();
    ui->scoreWidget->clear();
    QTime t;
    t.start();
    while(t.elapsed()<100)
    {
        QApplication::processEvents();
    }
    for(int i=0;i<roommate;i++)
    {
        ui->listWidget->addItem(name1[i].left(name1[i].length()));
        ui->scoreWidget->addItem(score[i].left(score[i].length()));
    }
}

void Roomchoser::readName(QString name)
{
    setName(name);
}

void Roomchoser::on_joinButton_clicked()
{
    whichbutton=true;
    this->slotsend();
    if(inorout==1)
    {
        //滞留0.5秒
        QTime t;
        t.start();
        while(t.elapsed()<100)
        {
            QApplication::processEvents();
        }
        if(roommate!=3)
        {
            inorout=0;
            //            QMessageBox::information
            //                    (this,tr("恭喜！"),tr("成功加入房间！"),QMessageBox::Ok);
            if(roommate==0||roommate==1)
            {
                QMessageBox::information
                        (this,tr("天天斗地主"),tr("人数不够，耐心等一下哦！"),QMessageBox::Ok);
            }
            else if(roommate==2)
            {
                //隐藏房间选择界面并进入游戏
                game* w=new game;
                w->setAttribute(Qt::WA_DeleteOnClose);
                connect(w,SIGNAL(userclose()),this,SLOT(letUserExit()));
                player p(name,ui->roomchoser->currentIndex());
                QObject::connect(&p,SIGNAL(nameSignal(QString,int)),w,SLOT(readplayer(QString,int)));
                p.sendchat();
                w->show();
                //隐藏房间选择界面并进入游戏
            }
            ui->joinButton->setText(tr("离开房间"));
            ui->roomchoser->setEnabled(false);
        }
        else{
            QMessageBox::warning(this,
                                 tr("真不巧！"),
                                 tr("房间满员了，换个房间试试！"),
                                 QMessageBox::Ok);
        }
    }
    else
    {
        inorout=1;
        ui->joinButton->setText(tr("进入房间"));
        ui->roomchoser->setEnabled(true);
    }
}

void Roomchoser::letUserExit()
{
    inorout=1;
    ui->joinButton->setText(tr("进入房间"));
    ui->roomchoser->setEnabled(true);
}
