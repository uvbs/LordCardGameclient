#ifndef CARDPIC_H
#define CARDPIC_H

#include <QFrame>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPixmap>
#include <QPainter>
#include "player.h"
#include "cards.h"

class cardpic : public QFrame
{
    Q_OBJECT

public:
    explicit cardpic(QWidget *parent = 0);
    ~cardpic();
    void SetPic(const QPixmap& pic,const QPixmap& back);
    QPixmap GetPic();
    void SetCard(Card card);
    Card GetCard();
    void SetFrontSide(bool frontside);
    bool IsFrontSide();
    void SetSelected(bool selected);
    bool IsSelected();
signals:
    void NotifySelected(Qt::MouseButton);
protected:
    virtual void paintEvent(QPaintEvent*);
    virtual void mousePressEvent(QMouseEvent* event);
protected:
    QPixmap m_pic;
    QPixmap m_back;
    Card m_card;
    bool m_frontSide;
    bool m_selected;
};

#endif // CARDPIC_H
