#ifndef HAND_H
#define HAND_H

#include "cards.h"
#include <QVector>
class Hand//非常精妙的类，抓住出牌的三个实质：类型，关键牌点数，关键牌数量,描述了手牌
{
public:
    Hand();
    Hand(HandType type,CardPoint base,int extra);
    Hand(const Cards& cards);
    bool operator==(const Hand& hand);
    void FromCards(const Cards& cards);
    void JudgeHand();
    bool canBeat(const Hand& other);
    HandType GetType();
    CardPoint GetBasePoint();
    int GetExtra();
protected:
    HandType m_handType;
    CardPoint m_basePoint;
    int m_extra;
    //分类，将手牌中1,2,3,4张牌的点数加入容器
    QVector<CardPoint> m_oneCard;
    QVector<CardPoint> m_twoCard;
    QVector<CardPoint> m_threeCard;
    QVector<CardPoint> m_fourCard;
};

#endif // HAND_H
