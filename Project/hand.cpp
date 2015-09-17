#include "hand.h"

Hand::Hand()
{
    m_handType=Hand_Unknown;
    m_basePoint=Card_Begin;
    m_extra=0;
}

Hand::Hand(HandType type, CardPoint base, int extra)
{
    m_handType=type;
    m_basePoint=base;
    m_extra=extra;
}

Hand::Hand(const Cards &cards)
{
    FromCards(cards);
    JudgeHand();
}

void Hand::FromCards(const Cards& cards)
{
    CardList cardlist=cards.ToCardList();
    int* CardRecord=new int[Card_End];
    memset(CardRecord,0,sizeof(int)*Card_End);
    for(CardList::const_iterator it=cardlist.begin();it!=cardlist.end();it++)
    {
        CardRecord[(int)it->point]++;
    }
    m_oneCard.clear();
    m_twoCard.clear();
    m_threeCard.clear();
    m_fourCard.clear();
    for(int i=Card_3;i<Card_End;i++)
    {
        if(CardRecord[i]==1)
            m_oneCard.push_back((CardPoint)i);
        if(CardRecord[i]==2)
            m_twoCard.push_back((CardPoint)i);
        if(CardRecord[i]==3)
            m_threeCard.push_back((CardPoint)i);
        if(CardRecord[i]==4)
            m_fourCard.push_back((CardPoint)i);
    }
    delete[] CardRecord;
}

void Hand::JudgeHand()
{
    m_handType=Hand_Unknown;
    m_basePoint=Card_Begin;
    m_extra=0;
    if(m_oneCard.isEmpty()&&m_twoCard.isEmpty()&&m_threeCard.isEmpty()&&m_fourCard.isEmpty())
    {
        m_handType=Hand_Pass;
    }
    else if(m_oneCard.size()==1&&m_twoCard.isEmpty()&&m_threeCard.isEmpty()&&m_fourCard.isEmpty())
    {
        m_handType=Hand_Single;
        m_basePoint=m_oneCard[0];
    }
    else if(m_oneCard.isEmpty()&&m_twoCard.size()==1&&m_threeCard.isEmpty()&&m_fourCard.isEmpty())
    {
        m_handType=Hand_Pair;
        m_basePoint=m_twoCard[0];
    }
    else if(m_oneCard.size()>=5&&m_twoCard.isEmpty()&&m_threeCard.isEmpty()&&m_fourCard.isEmpty())
    {
        qSort(m_oneCard.begin(),m_oneCard.end());//好像可以删除
        if(m_oneCard.last()<Card_2&&(m_oneCard.last()-m_oneCard.first()==m_oneCard.size()-1))
        {
            m_handType=Hand_Seq_Single;
            m_basePoint=m_oneCard[0];
            m_extra=m_oneCard.size();
        }
    }
    else if(m_oneCard.isEmpty()&&m_twoCard.size()>=3&&m_threeCard.isEmpty()&&m_fourCard.isEmpty())
    {
        qSort(m_twoCard.begin(),m_twoCard.end());
        if(m_twoCard.last()<Card_2&&(m_twoCard.last()-m_twoCard.first()==m_twoCard.size()-1))
        {
            m_handType=Hand_Seq_Pair;
            m_basePoint=m_twoCard[0];
            m_extra=m_twoCard.size();
        }
    }
    else if(m_oneCard.isEmpty()&&m_twoCard.isEmpty()&&m_threeCard.size()>=1&&m_fourCard.isEmpty())
    {
        qSort(m_threeCard.begin(),m_threeCard.end());
        if(m_threeCard.size()==1||(m_threeCard.last()<Card_2&&(m_threeCard.last()-m_threeCard.first()==m_threeCard.size()-1)))
        {
            m_handType=Hand_Seq_Triple;
            m_basePoint=m_threeCard[0];
            m_extra=m_threeCard.size();
        }
    }
    else if(m_oneCard.size()>=1&&m_twoCard.isEmpty()&&m_threeCard.size()==m_oneCard.size()&&m_fourCard.isEmpty())
    {
        qSort(m_oneCard.begin(),m_oneCard.end());
        qSort(m_threeCard.begin(),m_threeCard.end());
        if((m_oneCard.size()==1)||(m_oneCard.size()>1&&m_threeCard.last()<Card_2
                                   &&(m_threeCard.last()-m_threeCard.first()==m_threeCard.size()-1)&&(m_oneCard[m_oneCard.size()-2]!=Card_SJ||
                                                                                                      m_oneCard[m_oneCard.size()-1]!=Card_BJ)))//双王不能同时出现
        {
            m_handType=Hand_Plane_n_Single;
            m_basePoint=m_threeCard[0];
            m_extra=m_threeCard.size();
        }
    }
    else if(m_oneCard.isEmpty()&&m_twoCard.size()>=1&&m_threeCard.size()==m_twoCard.size()&&m_fourCard.isEmpty())
    {
        qSort(m_twoCard.begin(),m_twoCard.end());
        qSort(m_threeCard.begin(),m_threeCard.end());
        if((m_threeCard.size()==1)||(m_threeCard.last()<Card_2 &&(m_threeCard.last()-m_threeCard.first()==m_threeCard.size()-1)))
        {
            m_handType=Hand_Plane_n_Pair;
            m_basePoint=m_threeCard[0];
            m_extra=m_threeCard.size();
        }
    }
    else if(m_oneCard.isEmpty()&&m_twoCard.isEmpty()&&m_threeCard.isEmpty()&&m_fourCard.size()==1)
    {
        m_handType=Hand_Bomb;
        m_basePoint=m_fourCard[0];
    }
    else if(m_oneCard.isEmpty()&&m_twoCard.size()==2&&m_threeCard.isEmpty()&&m_fourCard.size()==1)
    {
        m_handType=Hand_Bomb_Pair;
        m_basePoint=m_fourCard[0];
    }
    else if(m_oneCard.size()==2&&m_twoCard.isEmpty()&&m_threeCard.isEmpty()&&m_fourCard.size()==1)
    {
        qSort(m_oneCard.begin(),m_oneCard.end());
        if(m_oneCard[0]!=Card_SJ||m_oneCard[1]!=Card_BJ)
        {
            m_handType=Hand_Bomb_Two_Single;
            m_basePoint=m_fourCard[0];
        }
    }
    else if(m_oneCard.size()==2&&m_twoCard.isEmpty()&&m_threeCard.isEmpty()&&m_fourCard.isEmpty())
    {
        qSort(m_oneCard.begin(),m_oneCard.end());
        if(m_oneCard[0]==Card_SJ&&m_oneCard[1]==Card_BJ)
        {
            m_handType=Hand_Bomb_Jokers;
        }
    }
}

bool Hand::operator ==(const Hand& other)
{
    return (m_handType==other.m_handType&&m_basePoint==other.m_basePoint&&m_extra==other.m_extra);
}

HandType Hand::GetType()
{
    return m_handType;
}

CardPoint Hand::GetBasePoint()
{
    return m_basePoint;
}

int Hand::GetExtra()
{
    return m_extra;
}

bool Hand::canBeat(const Hand& other)
{
    if(m_handType==Hand_Unknown)
        return false;//我出牌不合法
    if(other.m_handType==Hand_Unknown)
        return true;//别人出牌不合法或者还未出牌
    if(m_handType==Hand_Bomb_Jokers)
        return true;//我是王炸我做主
    if(other.m_handType==Hand_Pass)
        return true;
    if (other.m_handType >= Hand_Single &&
            other.m_handType <= Hand_Plane_n_Pair&&
            m_handType == Hand_Bomb)
    {
        return true;
    }//炸弹
    if(m_handType==other.m_handType)
    {
        if(m_basePoint>other.m_basePoint&&m_extra==other.m_extra)
            return true;
        else
            return false;
    }
    return false;
}
