#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "cards.h"
class player : public QObject
{
    Q_OBJECT
public:
    explicit player(QString name="",int number=-1,QObject *parent=0);
    virtual ~player();
    void CallLord(int bet);
    void PlayHand(const Cards& cards);

    void sendname();
    void sendchat();
    void setname(QString name);
    QString getname();
    void ClearCards();


signals:
    void nameSignal(QString name);
    void nameSignal(QString name,int number);

private:
    QString m_name;
    int roomnumber;//不是真的房间号
};

#endif // PLAYER_H
