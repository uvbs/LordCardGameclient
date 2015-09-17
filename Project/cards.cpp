#include "cards.h"

Cards::Cards()
{
}

Cards::~Cards()
{

}

void Cards::Add(const Card& card)
{
    m_cards.insert(card);
}

void Cards::Add(const Cards& cards)
{
    m_cards.unite(cards.m_cards);//unite���������п��������һ������
}

void Cards::Add(const QVector<Cards>& cardsArray)
{
    for(int i=0;i<cardsArray.size();i++)
    {
        Add(cardsArray[i]);
    }
}

void Cards::Remove(const Card& card)
{
    m_cards.remove(card);
}

void Cards::Remove(const Cards& cards)
{
    m_cards.subtract(cards.m_cards);//subtract���������п�����ȥ��һ������
}

void Cards::Remove(const QVector<Cards>& cardsArray)
{
    for(int i=0;i<cardsArray.size();i++)
    {
        Remove(cardsArray[i]);
    }
}

Cards& Cards::operator<<(const Cards& cards)
{
    Add(cards);
    return *this;
}

Cards& Cards::operator<<(const Card& card)
{
    Add(card);
    return *this;
}
Cards& Cards::operator<<(const QVector<Cards>& cardsArray)
{
    Add(cardsArray);
    return *this;
}

CardList Cards::ToCardList(SortType sorttype)const
{
    CardList cardlist;
    for(QSet<Card>::ConstIterator it=m_cards.begin();it!=m_cards.end();it++)
    {
        cardlist<<*it;
    }
    if(sorttype==Asc)
    {
        qSort(cardlist.begin(),cardlist.end(),qLess<Card>());
    }
    if(sorttype==Desc)
    {
        qSort(cardlist.begin(),cardlist.end(),qGreater<Card>());
    }
    return cardlist;
}

Card Cards::TakeRandomCard()
{
    QTime time;
    time=QTime::currentTime();
    qsrand(time.msec()+1000*time.second());
    int index=qrand()%m_cards.size();
    QSet<Card>::iterator it=m_cards.begin()+index;
    Card randomcard=*it;
    m_cards.erase(it);//����ָ����������ͷŽڵ�
    return randomcard;
}

int Cards::Count()
{
    return m_cards.size();
}

void Cards::Clear()
{
    m_cards.clear();
}

bool Cards::IsEmpty() const
{
    return m_cards.isEmpty();
}
