#ifndef CARDS_H
#define CARDS_H

#include <QMap>
#include <QList>
#include <QVector>
#include <QSet>
#include <QTime>

class Hand;
enum CardPoint
{
    Card_Begin,
    Card_3,
    Card_4,
    Card_5,
    Card_6,
    Card_7,
    Card_8,
    Card_9,
    Card_10,
    Card_J,
    Card_Q,
    Card_K,
    Card_A,
    Card_2,
    Card_SJ,
    Card_BJ,
    Card_End
};
const int PointCount=15;

enum CardSuit
{
    Suit_Begin,
    Diamond,//����
    Club,//÷��
    Heart,//����
    Spade,//����
    Suit_End
};

enum HandType
{
    Hand_Unknown,//��֪����ʲô����
    Hand_Pass,//��
    Hand_Single,//����
    Hand_Pair,//˫��
    Hand_Seq_Single,//��˳
    Hand_Seq_Pair,//˫˳
    Hand_Seq_Triple,//��˳
    Hand_Plane_n_Single,//�ɻ���n��(��������һ��
    Hand_Plane_n_Pair,//�ɻ���n�ԣ�������������
    Hand_Bomb,//ը��
    Hand_Bomb_Pair,//ը��������
    Hand_Bomb_Two_Single,//ը��������
    Hand_Bomb_Jokers//��ը
};

class Card//�����ͻ�ɫȷ���Ƶ�ö����
{
public:
    Card(CardPoint point1=Card_Begin,CardSuit suit1=Suit_Begin)
    {
        point=point1;
        suit=suit1;
    }
    Card(uint i,uint j)
    {
        if(i==0)
            point=Card_Begin;
        if(i==1)
            point=Card_3;
        if(i==2)
            point=Card_4;
        if(i==3)
            point=Card_5;
        if(i==4)
            point=Card_6;
        if(i==5)
            point=Card_7;
        if(i==6)
            point=Card_8;
        if(i==7)
            point=Card_9;
        if(i==8)
            point=Card_10;
        if(i==9)
            point=Card_J;
        if(i==10)
            point=Card_Q;
        if(i==11)
            point=Card_K;
        if(i==12)
            point=Card_A;
        if(i==13)
            point=Card_2;
        if(i==14)
            point=Card_SJ;
        if(i==15)
            point=Card_BJ;
        if(i==16)
            point=Card_End;
        if(j==0)
            suit=Suit_Begin;
        if(j==1)
            suit=Diamond;
        if(j==2)
            suit=Club;
        if(j==3)
            suit=Heart;
        if(j==4)
            suit=Spade;
        if(j==5)
            suit=Suit_End;
    }

    CardPoint point;
    CardSuit suit;
};

inline bool operator==(const Card& left,const Card& right)
{
    return (left.point==right.point&&left.suit==right.suit);
}

inline bool operator<(const Card& left,const Card& right)
{
    if(left.point==right.point)
    {
        return left.suit<right.suit;
    }
    else
    {
        return left.point<right.point;
    }
}

inline uint qHash(const Card& card)//��������ûһ����һһ��Ӧ����
{
    return card.point*100+card.suit;
}

typedef QVector<Card> CardList;//����һ����CardList,�䱾���ǿ�Ƭ������

class Cards//����
{
public:
    Cards();
    ~Cards();
    enum SortType
    {
        Nosort,
        Asc,
        Desc
    };
    void Add(const Card& card);
    void Add(const Cards& cards);
    void Add(const QVector<Cards>& cardsArray);//����Ӧ���Ǵ��濨Ƭ�飨Cards)������,���ǿ�Ƭ����

    void Remove(const Card& card);
    void Remove(const Cards& cards);
    void Remove(const QVector<Cards>& cardsArray);

    Cards& operator<<(const Cards& cards);
    Cards& operator<<(const Card& card);
    Cards& operator<<(const QVector<Cards>& cardsArray);

    CardList ToCardList(SortType=Asc)const;//��������뿨Ƭ������,�γ�������
    int Count();

    Card TakeRandomCard();

    bool IsEmpty() const;
    void Clear();
protected:
    QSet<Card> m_cards;//����Ŀ���
};

#endif // CARDS_H
