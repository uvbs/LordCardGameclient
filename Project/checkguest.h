#ifndef CHECKGUEST_H
#define CHECKGUEST_H

#include <QObject>
#include <QTcpSocket>
#include <QtNetwork>

class checkguest : public QObject
{
    Q_OBJECT
public:
    explicit checkguest(QObject *parent = 0);
    checkguest(bool,QString,QString,QObject *parent=0);
    int getwhether();

signals:

public slots:
    void slotReadMessage();
    void slotConnected();

private:
    bool signorlog;//判断注册用户还是登录用户
    QString m_name;
    QString m_passwd;
    QTcpSocket* m_tcpSocket;//套接字对象指针
    int decide;
};

#endif // CHECKGUEST_H
