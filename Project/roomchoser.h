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
        this->setWindowTitle(tr("��ӭ��")+name+tr("��"));
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
    int inorout;//0�����ȥ��1�������
    bool whichbutton;//false����鿴���䣬true������뷿��
    QTcpSocket* m_tcpSocket;//�׽��ֶ���ָ��
    QString name;
    QString name1[3];//�����õ��������Ϣ
    QString score[3];//����������Ϣ
};

#endif // ROOMCHOSER_H
