#ifndef CHATROOM_H
#define CHATROOM_H

#include <QFrame>
#include <QTcpSocket>
#include <QHostAddress>
#include <QScrollBar>

namespace Ui {
class chatroom;
}

class game;
class chatroom : public QFrame
{
    Q_OBJECT
    friend class game;
public:
    explicit chatroom(QWidget *parent = 0);
    chatroom(QString,int,QWidget *parent=0);
    ~chatroom();


public slots:
    void slotConnected();
    void slotDataReceived();
    void slotSend();
    void slotinfoReceived();//接收game发过来的账号和积分
    void slotrefreshinfo();

private:
    void Enter();
    void Leave();
    Ui::chatroom *ui;
    QString userName;
    QTcpSocket *tcpSocket;//接口
    int port;//端口
    QString name[3];
    QString score[3];
};

#endif // CHATROOM_H
