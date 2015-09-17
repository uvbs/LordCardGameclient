#ifndef HAND_H
#define HAND_H

#include "cards.h"
#include <QVector>
class Hand//�ǳ�������࣬ץס���Ƶ�����ʵ�ʣ����ͣ��ؼ��Ƶ������ؼ�������,����������
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
    //���࣬��������1,2,3,4���Ƶĵ�����������
    QVector<CardPoint> m_oneCard;
    QVector<CardPoint> m_twoCard;
    QVector<CardPoint> m_threeCard;
    QVector<CardPoint> m_fourCard;
};

#endif // HAND_H
