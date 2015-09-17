#include "cardpic.h"

cardpic::cardpic(QWidget *parent):
    QFrame(parent)
{
    m_selected=false;
    m_frontSide=true;
}

cardpic::~cardpic()
{

}

void cardpic::SetPic(const QPixmap& pic, const QPixmap& back)
{
    m_pic=pic;
    m_back=back;
    resize(pic.size());
    update();
}

QPixmap cardpic::GetPic()
{
    return m_pic;
}

void cardpic::SetCard(Card card)
{
    m_card=card;
}

Card cardpic::GetCard()
{
    return m_card;
}

void cardpic::SetFrontSide(bool frontside)
{
    if(m_frontSide!=frontside)
    {
        m_frontSide=frontside;
        update();
    }
}

void cardpic::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    if(m_frontSide)
    {
        painter.drawPixmap(rect(),m_pic);
    }
    else
    {
        painter.drawPixmap(rect(),m_back);
    }
}

void cardpic::mousePressEvent(QMouseEvent *event)
{
    emit NotifySelected(event->button());
    QFrame::mousePressEvent(event);
}

bool cardpic::IsFrontSide()
{
    return m_frontSide;
}

void cardpic::SetSelected(bool selected)
{
    m_selected=selected;
}

bool cardpic::IsSelected()
{
    return m_selected;
}
