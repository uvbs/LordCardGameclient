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
    bool signorlog;//�ж�ע���û����ǵ�¼�û�
    QString m_name;
    QString m_passwd;
    QTcpSocket* m_tcpSocket;//�׽��ֶ���ָ��
    int decide;
};

#endif // CHECKGUEST_H
