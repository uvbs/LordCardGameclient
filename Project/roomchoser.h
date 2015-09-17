#ifndef ROOMCHOSER_H
#define ROOMCHOSER_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include "game.h"
#include "player.h"
#include <QTcpSocket>
#include <QtNetwork>
#include <QTextCodec>

namespace Ui {
class Roomchoser;
}

class Roomchoser : public QDialog
{
    Q_OBJECT

public:
    explicit Roomchoser(QWidget *parent = 0);
    ~Roomchoser();
    void setName(QString n)
    {
        name=n;
        this->setWindowTitle(tr("欢迎，")+name+tr("！"));
    }
    void slotsend();
protected:
    void closeEvent(QCloseEvent *);
private slots:
    void on_checkwho_clicked();
    void on_joinButton_clicked();
public slots:
    void readName(QString name);
    void slotReadMessage();
    void acceptConnection();
    void letUserExit();
private:
    Ui::Roomchoser *ui;
    int roommate;
    int inorout;//0代表出去，1代表进入
    bool whichbutton;//false代表查看房间，true代表进入房间
    QTcpSocket* m_tcpSocket;//套接字对象指针
    QString name;
    QString name1[3];//存贮得到的玩家信息
    QString score[3];//存贮积分信息
};

#endif // ROOMCHOSER_H
