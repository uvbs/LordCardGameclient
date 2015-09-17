#include "player.h"

player::player(QString name,int number,QObject *parent)
    :QObject(parent),m_name(name),roomnumber(number)
{
}

player::~player()
{

}

void player::sendname()
{
    emit nameSignal(m_name);
}

void player::sendchat()
{
    emit nameSignal(m_name,roomnumber);
}

void player::setname(QString name)
{
    m_name=name;
}

QString player::getname()
{
    return m_name;
}

