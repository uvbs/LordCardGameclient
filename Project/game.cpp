#include"game.h"
#include "ui_game.h"
#include <QPoint>

game::game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::game)
{
    //构造函数
    ui->setupUi(this);
    //居中显示
    this->move((QApplication::desktop()->width() - this->width())/2,
               (QApplication::desktop()->height() - this->height())/2);
    //背景窗口大小
    this->resize( QSize( 1100, 675 ));

    QPixmap background = QPixmap(":/imagefile/res/background3.png").scaled(this->size());

    music=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/bbbackmusic.mp3"));
    music->play();
    //音乐的播放
    qDebug()<<Phonon::BackendCapabilities::availableMimeTypes();

    //音乐的加载与初始化
    pass=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/buyao1.mp3"));
    pass->setParent(this);
    qiang=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/qiangdizhu0.mp3"));
    //qDebug()<<Phonon::BackendCapabilities::availableMimeTypes();
    //pass->setParent(this);
    jiao=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/jiaonizhu.mp3"));
    bujiao=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/bujiao.mp3"));
    buqiang=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/buqiang.mp3"));

    dan1=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/1.mp3"));
    dan2=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/2.mp3"));
    dan3=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/3.mp3"));
    dan4=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/4.mp3"));
    dan5=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/5.mp3"));
    dan6=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/6.mp3"));
    dan7=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/7.mp3"));
    dan8=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/8.mp3"));
    dan9=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/9.mp3"));
    dan10=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/10.mp3"));
    dan11=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/11.mp3"));
    dan12=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/12.mp3"));
    dan13=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/13.mp3"));
    dan14=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/14.mp3"));
    dan15=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/15.mp3"));

    dui1=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/dui1.mp3"));
    dui2=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/dui2.mp3"));
    dui3=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/dui3.mp3"));
    dui4=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/dui4.mp3"));
    dui5=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/dui5.mp3"));
    dui6=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/dui6.mp3"));
    dui7=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/dui7.mp3"));
    dui8=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/dui8.mp3"));
    dui9=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/dui9.mp3"));
    dui10=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/dui10.mp3"));
    dui11=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/dui11.mp3"));
    dui12=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/dui12.mp3"));
    dui13=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/dui13.mp3"));

    shunzi=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/shunzi.mp3"));
    liandui=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/liandui.mp3"));
    zhadan=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/zhadan.mp3"));
    sange=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/sange.mp3"));
    sandaiyi=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/sandaiyi.mp3"));
    sandaier=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/sandaiyidui.mp3"));
    feiji=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/feiji.mp3"));
    wangzha=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/wangzha.mp3"));
    sidaier=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/match/sidaier.mp3"));

    win=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/music/Win.mp3"));
    lose=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/music/Lose.mp3"));
    ffapai=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(":/sound/special/fapai.wav"));

    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(background));
    this->setPalette(palette);
    m_leftlabel = new QLabel(this);
    m_midlabel = new QLabel(this);
    m_rightlabel = new QLabel(this);

    m_leftlabel->resize(200,60);
    m_midlabel->resize(200,60);
    m_rightlabel->resize(200,60);

    m_leftlabel->setText("");
    m_midlabel->setText("");
    m_rightlabel->setText("");

    m_leftlabel->setFont(QFont(tr("新宋体"),9,QFont::Bold));
    m_midlabel->setFont(QFont(tr("新宋体"),9,QFont::Bold));
    m_rightlabel->setFont(QFont(tr("新宋体"),9,QFont::Bold));

    m_leftlabel->move(160,85);
    m_midlabel->move(695,630);
    m_rightlabel->move(680,85);

    m_leftlabel->show();
    m_midlabel->show();
    m_rightlabel->show();

    m_p1label = new QLabel(this);
    m_p2label = new QLabel(this);
    m_p3label = new QLabel(this);

    m_p1label->resize(220,60);
    m_p2label->resize(220,60);
    m_p3label->resize(220,60);

    m_p1label->setText("");
    m_p2label->setText("");
    m_p3label->setText("");

    m_p1label->setFont(QFont(tr("新宋体"),14,QFont::Bold));
    m_p2label->setFont(QFont(tr("新宋体"),14,QFont::Bold));
    m_p3label->setFont(QFont(tr("新宋体"),14,QFont::Bold));
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::yellow);
    m_p1label->setPalette(pe);
    m_p2label->setPalette(pe);
    m_p3label->setPalette(pe);

    m_p1label->move(150,300);
    m_p2label->move(350,500);
    m_p3label->move(720,300);


    m_p2label->setAlignment(Qt::AlignCenter);

    m_p1label->show();
    m_p2label->show();
    m_p3label->show();

    m_leftpiclabel = new QLabel(this);
    m_midpiclabel = new QLabel(this);
    m_rightpiclabel = new QLabel(this);

    m_leftpiclabel->resize(120,90);
    m_midpiclabel->resize(120,90);
    m_rightpiclabel->resize(120,90);

    m_leftpiclabel->move(140,10);
    m_midpiclabel->move(670,550);
    m_rightpiclabel->move(660,10);

    m_cardSize = QSize(80, 124);//每张牌的大小
    cardsRect = QRect(173, rect().bottom() - 120, width(), 100);
    playHandRect = QRect(100, rect().bottom() - 250, width()-300, 100);
    leftRect = QRect(50,200,80,height());
    left_playHandRect =QRect(150,200,80,height());
    rightRect = QRect(770,200,80,height());
    right_playHandRect =QRect(670,200,80,height());
    m_exitgame=true;
    m_canjiao=0;
    InitControl();
    InitcardpicMap();
    Initother();

}

void game::readplayer(QString n,int nu)
{
    m_name=n;
    c=new chatroom(n,nu,this);
    connect(this,SIGNAL(userinfo()),c,SLOT(slotinfoReceived()));
    c->move(900,0);
    c->show();
    m_tcpsocket=new QTcpSocket(this);
    connect(m_tcpsocket,SIGNAL(readyRead()),this,SLOT(getsign()));
    m_blocksize=0;
    m_tcpsocket->connectToHost(QHostAddress("223.3.78.22"),nu+31331);
    //告诉服务端玩家名称
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out<<(quint16)0;
    QString str="name";
    out<<str<<n;
    out.device()->seek(0);
    out<<(quint16)(block.size()-sizeof(quint16));
    m_tcpsocket->write(block);

}

game::~game()
{
    delete ui;
}

void game::InitControl()
{

    QPoint p_start(405,450);
    QPoint p_first(340,450);
    QPoint p_second(460,450);
    m_startButton = new QPushButton(this);
    m_startButton->setFixedSize(89, 40);
    m_startButton->setStyleSheet("QPushButton			{ border-image:url(:/imagefile/res/startbutton1.png); }"
                                 "QPushButton:hover		{ border-image:url(:/imagefile/res/startbutton3.png); }"
                                 "QPushButton:pressed  	{ border-image:url(:/imagefile/res/startbutton2.png); }");
    m_startButton->move(p_start);
    m_startButton->show();
    connect(m_startButton, SIGNAL(clicked()), this, SLOT(on_m_startButton_clicked()));


    m_continueButton = new QPushButton(this);
    m_continueButton->setFixedSize(89, 40);
    m_continueButton->setStyleSheet("QPushButton			{ border-image:url(:/imagefile/res/startbutton1.png); }"
                                    "QPushButton:hover		{ border-image:url(:/imagefile/res/startbutton3.png); }"
                                    "QPushButton:pressed  	{ border-image:url(:/imagefile/res/startbutton2.png); }");
    m_continueButton->move(p_start);
    m_continueButton->hide();
    connect(m_continueButton, SIGNAL(clicked()), this, SLOT(On_m_ContinueBtnClicked()));

    m_passButton = new QPushButton(this);
    m_passButton->setFixedSize(89, 40);
    m_passButton->move(p_second);
    m_passButton->setStyleSheet("QPushButton			{ border-image:url(:/imagefile/res/passbutton1.png); }"
                                "QPushButton:hover		{ border-image:url(:/imagefile/res/passbutton3.png); }"
                                "QPushButton:pressed  	{ border-image:url(:/imagefile/res/passbutton2.png); }");
    m_passButton->hide();
    connect(m_passButton, SIGNAL(clicked()), this, SLOT(On_m_UserPass()));


    m_playHandButton = new QPushButton(this);
    m_playHandButton->setStyleSheet("QPushButton			{ border-image:url(:/imagefile/res/playbutton2.png); }"
                                    "QPushButton:hover		{ border-image:url(:/imagefile/res/playbutton3.png); }"
                                    "QPushButton:pressed  	{ border-image:url(:/imagefile/res/playbutton4.png); }");
    m_playHandButton->hide();
    m_playHandButton->setFixedSize(89, 40);
    m_playHandButton->move(p_first);
    connect(m_playHandButton, SIGNAL(clicked()), this, SLOT(On_m_UserPlayHand()));

    //////////////////////////////////////////////////////////////////////////

    m_nocallButton = new QPushButton(this);
    m_nocallButton->setStyleSheet("QPushButton			{ border-image:url(:/imagefile/res/Nocallbutton1.png); }"
                                  "QPushButton:hover		{ border-image:url(:/imagefile/res/Nocallbutton3.png); }"
                                  "QPushButton:pressed  	{ border-image:url(:/imagefile/res/Nocallbutton2.png); }");
    m_nocallButton->hide();
    m_nocallButton->setFixedSize(89, 40);
    m_nocallButton->move(p_second);
    connect(m_nocallButton, SIGNAL(clicked()), this, SLOT(On_m_UserNoCall()));


    m_calllordButton = new QPushButton(this);
    m_calllordButton->hide();
    m_calllordButton->setFixedSize(89, 40);
    m_calllordButton->move(p_first);
    m_calllordButton->setStyleSheet("QPushButton			{ border-image:url(:/imagefile/res/Callbutton1.png); }"
                                    "QPushButton:hover		{ border-image:url(:/imagefile/res/Callbutton3.png); }"
                                    "QPushButton:pressed  	{ border-image:url(:/imagefile/res/Callbutton2.png); }");
    connect(m_calllordButton, SIGNAL(clicked()), this, SLOT(On_m_UserCall()));

    m_rublordButton = new QPushButton(this);
    m_rublordButton->hide();
    m_rublordButton->setFixedSize(89, 40);
    m_rublordButton->move(p_first);
    m_rublordButton->setStyleSheet("QPushButton		     	{ border-image:url(:/imagefile/res/Qiangbutton1.png); }"
                                   "QPushButton:hover		{ border-image:url(:/imagefile/res/Qiangbutton3.png); }"
                                   "QPushButton:pressed  	{ border-image:url(:/imagefile/res/Qiangbutton2.png); }");
    connect(m_rublordButton, SIGNAL(clicked()), this, SLOT(On_m_UserRublord()));

    m_norubButton = new QPushButton(this);
    m_norubButton->hide();
    m_norubButton->setFixedSize(89, 40);
    m_norubButton->move(p_second);
    m_norubButton->setStyleSheet("QPushButton			    { border-image:url(:/imagefile/res/norubbutton1.png); }"
                                 "QPushButton:hover		{ border-image:url(:/imagefile/res/norubbutton3.png); }"
                                 "QPushButton:pressed  	{ border-image:url(:/imagefile/res/norubbutton2.png); }");
    connect(m_norubButton, SIGNAL(clicked()), this, SLOT(On_m_UserNoRub()));
}

void game::Cutcardpic(const QPixmap& cardsPic,int x, int y, Card card)//*************************
{

    QPixmap pic = cardsPic.copy(x, y, m_cardSize.width(), m_cardSize.height());

    cardpic* cardPic = new cardpic(this);
    cardPic->hide();//保险起见
    cardPic->SetPic(pic, m_cardBackPic);
    cardPic->SetCard(card);
    cardPic->resize(70,110);
    m_cardPicMap.insert(card, cardPic);

    cardpic* cardPic1 = new cardpic(this);
    cardPic1->hide();
    cardPic1->SetPic(pic, m_cardBackPic);
    cardPic1->SetCard(card);
    cardPic1->resize(70,110);
    l_cardPicMap.insert(card, cardPic1);

    cardpic* cardPic2 = new cardpic(this);
    cardPic2->hide();
    cardPic2->SetPic(pic, m_cardBackPic);
    cardPic2->SetCard(card);
    cardPic2->resize(70,110);
    r_cardPicMap.insert(card, cardPic2);

    cardpic* cardPic3 = new cardpic(this);
    cardPic3->hide();
    cardPic3->SetPic(pic, m_cardBackPic);
    cardPic3->SetCard(card);
    cardPic3->resize(70,110);
    three_cardPicMap.insert(card, cardPic3);
    connect(cardPic,SIGNAL(NotifySelected(Qt::MouseButton)),this,SLOT(OnCardSelected(Qt::MouseButton)));
}


void game::InitcardpicMap()//*************************
{
    QPixmap cardsPic(":/imagefile/res/Cards.png");
    m_cardBackPic = cardsPic.copy(2 * m_cardSize.width(), 4 * m_cardSize.height(),
                                  m_cardSize.width(), m_cardSize.height());//背面那张牌
    for (int suit = Suit_Begin + 1, i = 0; suit < Suit_End; suit++, i++)
    {
        for (int pt = Card_Begin + 1, j = 0; pt < Card_SJ; pt++, j++)
        {
            Card card;
            card.point = (CardPoint)pt;
            card.suit = (CardSuit)suit;
            Cutcardpic(cardsPic, j * m_cardSize.width(), i * m_cardSize.height(), card);
        }
    }
    Card card;

    card.point = Card_SJ;
    card.suit = Suit_Begin;
    Cutcardpic(cardsPic, 0, 4 * m_cardSize.height(), card);//小王

    card.point = Card_BJ;
    card.suit = Suit_Begin;
    Cutcardpic(cardsPic, m_cardSize.width(), 4 * m_cardSize.height(), card);//大王
}

void game::Initother()
{
    QPixmap cardsPic(":/imagefile/res/lord.png");
    m_lordPic=cardsPic.scaled(108,81);
    QPixmap cardsPic1(":/imagefile/res/nongming.png");
    m_farmerPic=cardsPic1.scaled(108,81);
}

void game::fapai()
{
    ffapai->stop();
    m_canjiao=0;
    m_leftlabel->setText(m_pname[0]);
    m_midlabel->setText(m_pname[1]);
    m_rightlabel->setText(m_pname[2]);
    QEventLoop eventloop;
    CardList Cardlist =m_Cards.ToCardList(Cards::Desc);//给17张牌排序
    CardList l_Cardlist = l_Cards.ToCardList(Cards::Desc);
    CardList r_Cardlist = r_Cards.ToCardList(Cards::Desc);
    int m = Cardlist.size();
    int l = cardsRect.left();
    int t = leftRect.top();
    const int cardSpacing = 25;		// 牌间隔
    ffapai->play();
    CardList::ConstIterator it = Cardlist.constBegin();
    CardList::ConstIterator l_it = l_Cardlist.constBegin();
    CardList::ConstIterator r_it = r_Cardlist.constBegin();
    for (;it != Cardlist.constEnd()+1; it++,l_it++,r_it++)
    {

        CardList::ConstIterator it2 = Cardlist.constBegin();
        CardList::ConstIterator it3 = l_Cardlist.constBegin();
        CardList::ConstIterator it4 = r_Cardlist.constBegin();
        for (int i = 0; it2 != it; it2++,i++)
        {

            cardpic* cardPic = m_cardPicMap[*it2];
            cardPic->show();
            cardPic->raise();

            int leftBase = l + (cardsRect.width() - (m - 1) * cardSpacing - cardPic->width()) / 2;
            int top = cardsRect.top() + (cardsRect.height() - cardPic->height()) / 2;

            cardPic->move(leftBase + i * cardSpacing, top);

        }
        for (int i = 0; it3 != l_it; it3++,i++)
        {
            cardpic* l_cardPic = l_cardPicMap[*it3];
            l_cardPic->show();
            l_cardPic->raise();

            l_cardPic->SetFrontSide(0);
            int topBase = t + (leftRect.height() - (m - 1) * cardSpacing - l_cardPic->height()) / 2;
            int left = leftRect.left();

            l_cardPic->move(left, topBase + i * cardSpacing);
        }
        for (int i = 0; it4 != r_it; it4++,i++)
        {
            cardpic* r_cardPic = r_cardPicMap[*it4];
            r_cardPic->show();
            r_cardPic->raise();

            r_cardPic->SetFrontSide(0);
            int topBase = t + (rightRect.height() - (m - 1) * cardSpacing - r_cardPic->height()) / 2;
            int left = rightRect.left();

            r_cardPic->move(left, topBase + i * cardSpacing);
        }
        QTimer::singleShot(200, &eventloop, SLOT(quit()));
        eventloop.exec();
        l=l-30;
        t=t-25;
        m--;

    }
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out<<(quint16)0;
    QString str="fapaiover";
    out<<str;
    out.device()->seek(0);
    out<<(quint16)(block.size()-sizeof(quint16));
    m_tcpsocket->write(block);
}

void game::m_UpDateCard()
{
    const int cardSpacing = 25;		// 牌间隔
    if(!lastcards.IsEmpty())
    {
        CardList Cardlist1 =lastcards.ToCardList(Cards::Desc);
        int n = Cardlist1.size();

        CardList::ConstIterator it1 = Cardlist1.constBegin();
        for (int i = 0; it1 != Cardlist1.constEnd(); it1++,i++)
        {
            cardpic* cardPic = m_cardPicMap[*it1];
            m_Cards.Remove(*it1);
            cardPic->show();
            cardPic->raise();

            int leftBase = playHandRect.left()-(n*cardSpacing)/4 + (playHandRect.width() - (n - 1) * cardSpacing - cardPic->width()) / 2;
            int top = playHandRect.top() + (playHandRect.height() - cardPic->height()) / 2;
            cardPic->move(leftBase + i * cardSpacing, top);
        }
    }
    CardList Cardlist =m_Cards.ToCardList(Cards::Desc);//排序

    int m = Cardlist.size();
    int l = cardsRect.left()-17*30;

    CardList::ConstIterator it = Cardlist.constBegin();
    for (int i = 0;it != Cardlist.constEnd(); it++,i++)
    {
        cardpic* cardPic = m_cardPicMap[*it];
        cardPic->show();
        cardPic->raise();
        int leftBase = l+(17-m)*30 + (cardsRect.width() - (16-m) * cardSpacing - cardPic->width()) /2;
        int top = cardsRect.top() + (cardsRect.height() - cardPic->height()) / 2;
        cardPic->move(leftBase + i * cardSpacing, top);

    }
}
void game::l_UpDateCard()
{
    CardList Cardlist =l_Cards.ToCardList(Cards::Desc);//排序

    int m = Cardlist.size();
    int t = leftRect.top()-17*25;
    const int cardSpacing = 25;		// 牌间隔

    CardList::ConstIterator it = Cardlist.constBegin();
    for (int i = 0;it != Cardlist.constEnd(); it++,i++)
    {
        cardpic* cardPic = l_cardPicMap[*it];
        cardPic->show();
        cardPic->raise();
        cardPic->SetFrontSide(0);
        int topBase = t+(17-m)*25 + (leftRect.height() - (16-m) * cardSpacing - cardPic->height()) / 2;
        int left = leftRect.left();

        cardPic->move(left, topBase + i * cardSpacing);
    }
    if(!leftlastcards.IsEmpty())
    {
        CardList Cardlist1 =leftlastcards.ToCardList(Cards::Desc);//排序
        int m1 = Cardlist1.size();
        int t1 = left_playHandRect.top()-17*25;

        CardList::ConstIterator it1 = Cardlist1.constBegin();
        for (int i = 0;it1 != Cardlist1.constEnd(); it1++,i++)
        {
            cardpic* cardPic = l_cardPicMap[*it1];
            cardPic->SetFrontSide(1);
            cardPic->show();
            cardPic->raise();
            int topBase = t1+(17-m1)*25 + (left_playHandRect.height() - (16-m1) * cardSpacing - cardPic->height()) / 2;
            int left = left_playHandRect.left();
            cardPic->move(left, topBase + i * cardSpacing);
        }
    }
}
void game::r_UpDateCard()
{
    CardList Cardlist =r_Cards.ToCardList(Cards::Desc);//排序
    int m = Cardlist.size();
    int t = rightRect.top()-17*25;
    const int cardSpacing = 25;		// 牌间隔

    CardList::ConstIterator it = Cardlist.constBegin();
    for (int i = 0;it != Cardlist.constEnd(); it++,i++)
    {
        cardpic* cardPic = r_cardPicMap[*it];
        cardPic->SetFrontSide(0);
        cardPic->show();
        cardPic->raise();
        int topBase = t+(17-m)*25 + (rightRect.height() - (16-m) * cardSpacing - cardPic->height()) / 2;
        int left = rightRect.left();
        cardPic->move(left, topBase + i * cardSpacing);
    }

    if(!rightlastcards.IsEmpty())
    {
        CardList Cardlist1 =rightlastcards.ToCardList(Cards::Desc);//排序
        int m1 = Cardlist1.size();
        int t1 = right_playHandRect.top()-17*25;

        CardList::ConstIterator it1 = Cardlist1.constBegin();
        for (int i = 0;it1 != Cardlist1.constEnd(); it1++,i++)
        {
            cardpic* cardPic = r_cardPicMap[*it1];
            cardPic->SetFrontSide(1);
            cardPic->show();
            cardPic->raise();
            int topBase = t1+(17-m1)*25 + (right_playHandRect.height() - (16-m1) * cardSpacing - cardPic->height()) / 2;
            int left = right_playHandRect.left();
            cardPic->move(left, topBase + i * cardSpacing);
        }
    }
}
void game::on_m_startButton_clicked()
{
    m_startButton->hide();
    m_p2label->setText(tr("正在等待其他玩家开始"));
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out<<(quint16)0;
    QString str="ready";
    out<<str;
    out.device()->seek(0);
    out<<(quint16)(block.size()-sizeof(quint16));
    m_tcpsocket->write(block);
}

void game::On_m_ContinueBtnClicked()
{
    m_continueButton->hide();
    m_continueButton->move(405,450);
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out<<(quint16)0;
    QString str="ready1";
    out<<str;
    out.device()->seek(0);
    out<<(quint16)(block.size()-sizeof(quint16));
    m_tcpsocket->write(block);
}
void game::On_m_UserCall()
{
    m_calllordButton->hide();
    m_nocallButton->hide();
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out<<(quint16)0;
    QString str="jiao";
    int n=1;
    out<<str<<n;
    out.device()->seek(0);
    out<<(quint16)(block.size()-sizeof(quint16));
    m_tcpsocket->write(block);
}
void game::On_m_UserNoCall()
{
    m_nocallButton->hide();
    m_calllordButton->hide();
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out<<(quint16)0;
    QString str="jiao";
    int n=0;
    out<<str<<n;
    out.device()->seek(0);
    out<<(quint16)(block.size()-sizeof(quint16));
    m_tcpsocket->write(block);
}
void game::On_m_UserRublord()
{
    m_rublordButton->hide();
    m_norubButton->hide();
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out<<(quint16)0;
    if(m_canjiao==1)
    {
        QString str="qiang1";
        int n=1;
        out<<str<<n;
    }
    else
    {
        QString str="qiang";
        int n=1;
        out<<str<<n;
    }
    out.device()->seek(0);
    out<<(quint16)(block.size()-sizeof(quint16));
    m_tcpsocket->write(block);
}
void game::On_m_UserNoRub()
{
    m_rublordButton->hide();
    m_norubButton->hide();
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out<<(quint16)0;
    if(m_canjiao==1)
    {
        QString str="qiang1";
        int n=0;
        out<<str<<n;
    }
    else
    {
        QString str="qiang";
        int n=0;
        out<<str<<n;
    }
    out.device()->seek(0);
    out<<(quint16)(block.size()-sizeof(quint16));
    m_tcpsocket->write(block);
}

void game::On_m_UserPass()
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out<<(quint16)0;
    m_passButton->hide();
    m_playHandButton->hide();
    QString str="chupai";
    int n=0;
    out<<str<<n;
    out.device()->seek(0);
    out<<(quint16)(block.size()-sizeof(quint16));
    m_tcpsocket->write(block);
}

void game::On_m_UserPlayHand()
{
    if (m_selectedCards.isEmpty()) return;
    Cards playCards;
    QSet<cardpic*>::const_iterator it = m_selectedCards.constBegin();
    for (; it != m_selectedCards.constEnd(); it++)
    {
        playCards.Add((*it)->GetCard());
    }
    if(Hand(playCards).canBeat(maxhand)||(m_p1label->text()==QString(tr("不出"))&&m_p3label->text()==QString(tr("不出"))&&Hand(playCards).GetType()!=Hand_Unknown))
    {
        m_playHandButton->hide();
        m_passButton->hide();
        QByteArray block;
        QDataStream out(&block,QIODevice::WriteOnly);
        out<<(quint16)0;

        QString str="chupai";
        int n=m_selectedCards.size();
        int k;
        out<<str<<n;
        QSet<cardpic*>::const_iterator it = m_selectedCards.constBegin();
        for (; it != m_selectedCards.constEnd(); it++)
        {
            out<<qHash((*it)->GetCard());
        }
        if(Hand(playCards).GetType()==Hand_Bomb||Hand(playCards).GetType()==Hand_Bomb_Jokers)
        {
            k=1;
        }
        else
        {
            k=0;
        }
        out<<k;
        m_selectedCards.clear();
        out.device()->seek(0);
        out<<(quint16)(block.size()-sizeof(quint16));
        m_tcpsocket->write(block);
    }
}

void game::On_left_UserPlayHand(int x)
{
    CardList Cardlist =l_Cards.ToCardList(Cards::Desc);
    CardList::ConstIterator it = Cardlist.constBegin();
    for (int i = 0; it != Cardlist.constEnd() && i<x; it++,i++)
    {
        cardpic* cardPic = l_cardPicMap[*it];
        l_Cards.Remove(*it);
        cardPic->move(-1000, 0);
    }
    l_UpDateCard();
}

void game::On_right_UserPlayHand(int x)
{
    CardList Cardlist =r_Cards.ToCardList(Cards::Desc);
    CardList::ConstIterator it = Cardlist.constBegin();
    for (int i = 0; it != Cardlist.constEnd() && i<x; it++,i++)
    {
        cardpic* cardPic = r_cardPicMap[*it];
        r_Cards.Remove(*it);
        cardPic->move(-1000, 0);
    }
    r_UpDateCard();
}

void game::Hidelastcards()
{
    m_p2label->setText("");
    if (lastcards.IsEmpty())	// 上一次打的空牌，即pass
    {
    }
    else
    {
        CardList lastCardList = lastcards.ToCardList();
        CardList::ConstIterator itLast = lastCardList.constBegin();
        for (; itLast != lastCardList.constEnd(); itLast++)
        {
            m_cardPicMap[*itLast]->hide();
        }
    }
}

void game::l_Hidelastcards()
{
    m_p1label->setText("");
    if (leftlastcards.IsEmpty())	// 上一次打的空牌，即pass
    {
    }
    else
    {
        CardList lastCardList = leftlastcards.ToCardList();
        CardList::ConstIterator itLast = lastCardList.constBegin();
        for (; itLast != lastCardList.constEnd(); itLast++)
        {
            l_cardPicMap[*itLast]->hide();
        }
    }
}

void game::r_Hidelastcards()
{
    m_p3label->setText("");
    if (rightlastcards.IsEmpty())	// 上一次打的空牌，即pass
    {
    }
    else
    {
        CardList lastCardList = rightlastcards.ToCardList();
        CardList::ConstIterator itLast = lastCardList.constBegin();
        for (; itLast != lastCardList.constEnd(); itLast++)
        {
            r_cardPicMap[*itLast]->hide();
        }
    }
}

void game::OnCardSelected(Qt::MouseButton mousebutton)
{
    cardpic* cardPic = (cardpic*)sender();
    int a=cardPic->x();
    int top=cardPic->y();
    if (mousebutton == Qt::LeftButton)
    {
        cardPic->SetSelected(!cardPic->IsSelected());

        QSet<cardpic*>::Iterator it = m_selectedCards.find(cardPic);
        if (it == m_selectedCards.end())		// 选中牌
        {
            if (cardPic->IsSelected()) top -= 10;
            cardPic->move(a, top);
            m_selectedCards.insert(cardPic);
        }
        else	// 取消选中牌
        {
            if (!cardPic->IsSelected()) top += 10;
            cardPic->move(a, top);
            m_selectedCards.erase(it);
        }
    }
}

void game::getsign()
{
    QDataStream in(m_tcpsocket);
    in.setVersion(QDataStream::Qt_4_0);
    if(m_blocksize==0)
    {
        if(m_tcpsocket->bytesAvailable()<(int)sizeof(quint16))
        {
            return;
        }
        in>>m_blocksize;
    }
    if(m_tcpsocket->bytesAvailable()<m_blocksize)
    {
        return;
    }
    m_blocksize=0;
    QString m_judge;
    in>>m_judge;
    if(m_judge=="exit")
    {
        m_exitgame=false;
        this->close();
    }
    if(m_judge=="fapai")
    {
        m_Cards.Clear();
        l_Cards.Clear();
        r_Cards.Clear();
        uint temp[17];
        for(int i=0;i<17;i++)
            in>>temp[i];
        for(int i=0;i<17;i++)
        {
            m_Cards.Add(Card(temp[i]/100,temp[i]%100));
            l_Cards.Add(Card(temp[i]/100,temp[i]%100));
            r_Cards.Add(Card(temp[i]/100,temp[i]%100));
        }
        m_p2label->setText(tr(""));
        fapai();
    }

    if(m_judge=="fapai1")
    {
        music->play();
        m_p2label->setText(tr(""));
        m_leftpiclabel->hide();
        m_midpiclabel->hide();
        m_rightpiclabel->hide();
        CardList Threelist=three_Cards.ToCardList(Cards::Desc);
        for (CardList::ConstIterator it=Threelist.constBegin();it != Threelist.constEnd()+1; it++)
        {
            CardList::ConstIterator it1 = Threelist.constBegin();
            for (int i = 0; it1 != it; it1++,i++)
            {
                cardpic* cardPic = three_cardPicMap[*it1];
                cardPic->hide();
            }
        }
        three_Cards.Clear();
        if(mywinname==m_pname[0])
        {
            l_Hidelastcards();
            leftlastcards.Clear();
            CardList lose1list=m_Cards.ToCardList(Cards::Desc);
            for (CardList::ConstIterator it=lose1list.constBegin();it != lose1list.constEnd()+1; it++)
            {
                CardList::ConstIterator it1 = lose1list.constBegin();
                for (int i = 0; it1 != it; it1++,i++)
                {
                    cardpic* cardPic = m_cardPicMap[*it1];
                    cardPic->hide();
                }
            }
            CardList lose2list=lose2cards.ToCardList(Cards::Desc);
            for (CardList::ConstIterator it=lose2list.constBegin();it != lose2list.constEnd()+1; it++)
            {
                CardList::ConstIterator it1 = lose2list.constBegin();
                for (int i = 0; it1 != it; it1++,i++)
                {
                    cardpic* cardPic = r_cardPicMap[*it1];
                    cardPic->hide();
                }
            }
        }
        if(mywinname==m_pname[1])
        {
            Hidelastcards();
            lastcards.Clear();
            CardList lose1list=lose1cards.ToCardList(Cards::Desc);
            for (CardList::ConstIterator it=lose1list.constBegin();it != lose1list.constEnd()+1; it++)
            {
                CardList::ConstIterator it1 = lose1list.constBegin();
                for (int i = 0; it1 != it; it1++,i++)
                {
                    cardpic* cardPic = r_cardPicMap[*it1];
                    cardPic->hide();
                }
            }
            CardList lose2list=lose2cards.ToCardList(Cards::Desc);
            for (CardList::ConstIterator it=lose2list.constBegin();it != lose2list.constEnd()+1; it++)
            {
                CardList::ConstIterator it1 = lose2list.constBegin();
                for (int i = 0; it1 != it; it1++,i++)
                {
                    cardpic* cardPic = l_cardPicMap[*it1];
                    cardPic->hide();
                }
            }
        }
        if(mywinname==m_pname[2])
        {
            r_Hidelastcards();
            rightlastcards.Clear();
            CardList lose1list=lose1cards.ToCardList(Cards::Desc);
            for (CardList::ConstIterator it=lose1list.constBegin();it != lose1list.constEnd()+1; it++)
            {
                CardList::ConstIterator it1 = lose1list.constBegin();
                for (int i = 0; it1 != it; it1++,i++)
                {
                    cardpic* cardPic = l_cardPicMap[*it1];
                    cardPic->hide();
                }
            }
            CardList lose2list=m_Cards.ToCardList(Cards::Desc);
            for (CardList::ConstIterator it=lose2list.constBegin();it != lose2list.constEnd()+1; it++)
            {
                CardList::ConstIterator it1 = lose2list.constBegin();
                for (int i = 0; it1 != it; it1++,i++)
                {
                    cardpic* cardPic = m_cardPicMap[*it1];
                    cardPic->hide();
                }
            }
        }
        lose1cards.Clear();
        lose2cards.Clear();
        m_Cards.Clear();
        r_Cards.Clear();
        l_Cards.Clear();
        maxhand=Hand();
        wbd->close();
        m_cardPicMap.clear();
        l_cardPicMap.clear();
        r_cardPicMap.clear();
        InitcardpicMap();
        uint temp[17];
        for(int i=0;i<17;i++)
            in>>temp[i];
        for(int i=0;i<17;i++)
        {
            m_Cards.Add(Card(temp[i]/100,temp[i]%100));
            l_Cards.Add(Card(temp[i]/100,temp[i]%100));
            r_Cards.Add(Card(temp[i]/100,temp[i]%100));
        }
        fapai();
    }

    if(m_judge=="allname")
    {
        for(int i=0;i<3;i++)
        {
            in>>name[i]>>score[i];
            c->name[i]=name[i];
            c->score[i]=score[i];
        }
        for(int j=0;j<3;j++)
        {
            if(name[j]==m_name)
            {
                m_pname[0]=name[(j+2)%3];
                m_pname[1]=name[j];
                m_pname[2]=name[(j+1)%3];
            }
        }
        emit userinfo();
    }
    if(m_judge=="jiao")
    {
        m_canjiao=1;
        m_calllordButton->show();
        m_nocallButton->show();
    }
    if(m_judge=="whetherjiao")
    {
        QString str;
        int decide;
        in>>str>>decide;
        if(decide)
        {
            jiao->stop();
            if(str==m_pname[0])
                m_p1label->setText(tr("叫"));
            if(str==m_pname[1])
                m_p2label->setText(tr("叫"));
            if(str==m_pname[2])
                m_p3label->setText(tr("叫"));
            jiao->play();
        }
        else
        {
            bujiao->stop();
            if(str==m_pname[0])
                m_p1label->setText(tr("不叫"));
            if(str==m_pname[1])
                m_p2label->setText(tr("不叫"));
            if(str==m_pname[2])
                m_p3label->setText(tr("不叫"));
            bujiao->play();
        }
    }
    if(m_judge=="qiang")
    {
        m_rublordButton->show();
        m_norubButton->show();
    }
    if(m_judge=="whetherqiang")
    {
        QString str;
        int decide;
        in>>str>>decide;
        if(decide)
        {
            qiang->stop();
            if(str==m_pname[0])
                m_p1label->setText(tr("抢"));
            if(str==m_pname[1])
                m_p2label->setText(tr("抢"));
            if(str==m_pname[2])
                m_p3label->setText(tr("抢"));
            qiang->play();
        }
        else
        {
            buqiang->stop();
            if(str==m_pname[0])
                m_p1label->setText(tr("不抢"));
            if(str==m_pname[1])
                m_p2label->setText(tr("不抢"));
            if(str==m_pname[2])
                m_p3label->setText(tr("不抢"));
            buqiang->play();
        }
    }
    if(m_judge=="qiang1")
    {
        m_p2label->setText("");
        m_rublordButton->show();
        m_norubButton->show();
    }
    if(m_judge=="chongxinfapai")
    {
        m_p1label->setText("");
        m_p2label->setText("");
        m_p3label->setText("");
        CardList Cardlist =m_Cards.ToCardList(Cards::Desc);
        CardList l_Cardlist = l_Cards.ToCardList(Cards::Desc);
        CardList r_Cardlist = r_Cards.ToCardList(Cards::Desc);
        CardList::ConstIterator it = Cardlist.constBegin();
        CardList::ConstIterator l_it = l_Cardlist.constBegin();
        CardList::ConstIterator r_it = r_Cardlist.constBegin();
        for (;it != Cardlist.constEnd()+1; it++,l_it++,r_it++)
        {
            CardList::ConstIterator it2 = Cardlist.constBegin();
            CardList::ConstIterator it3 = l_Cardlist.constBegin();
            CardList::ConstIterator it4 = r_Cardlist.constBegin();
            for (int i = 0; it2 != it; it2++,i++)
            {
                cardpic* cardPic = m_cardPicMap[*it2];
                cardPic->hide();
            }
            for (int i = 0; it3 != l_it; it3++,i++)
            {
                cardpic* cardPic = l_cardPicMap[*it3];
                cardPic->hide();
            }
            for (int i = 0; it4 != r_it; it4++,i++)
            {
                cardpic* cardPic = r_cardPicMap[*it4];
                cardPic->hide();
            }
        }
        m_Cards.Clear();
        l_Cards.Clear();
        r_Cards.Clear();
        uint temp[17];
        for(int i=0;i<17;i++)
            in>>temp[i];
        for(int i=0;i<17;i++)
        {
            m_Cards.Add(Card(temp[i]/100,temp[i]%100));
            l_Cards.Add(Card(temp[i]/100,temp[i]%100));
            r_Cards.Add(Card(temp[i]/100,temp[i]%100));
        }
        fapai();
    }
    if(m_judge=="dipai")
    {
        m_p1label->setText("");
        m_p2label->setText("");
        m_p3label->setText("");
        three_Cards.Clear();
        QString str;
        in>>str;
        uint  temp[3];
        for(int i=0;i<3;i++)
            in>>temp[i];
        for(int i=0;i<3;i++)
        {
            if(name[i]==str)
                lordside=i;
        }
        if(str==m_pname[0])
        {
            m_leftpiclabel->setPixmap(m_lordPic);
            m_midpiclabel->setPixmap(m_farmerPic);
            m_rightpiclabel->setPixmap(m_farmerPic);
            for(int i=0;i<3;i++)
            {
                l_Cards.Add(Card(temp[i]/100,temp[i]%100));
                three_Cards.Add(Card(temp[i]/100,temp[i]%100));
            }
            l_UpDateCard();
        }
        if(str==m_pname[1])
        {
            m_leftpiclabel->setPixmap(m_farmerPic);
            m_midpiclabel->setPixmap(m_lordPic);
            m_rightpiclabel->setPixmap(m_farmerPic);
            for(int i=0;i<3;i++)
            {
                m_Cards.Add(Card(temp[i]/100,temp[i]%100));
                three_Cards. Add(Card(temp[i]/100,temp[i]%100));
            }
            m_UpDateCard();
        }
        if(str==m_pname[2])
        {
            m_leftpiclabel->setPixmap(m_farmerPic);
            m_midpiclabel->setPixmap(m_farmerPic);
            m_rightpiclabel->setPixmap(m_lordPic);
            for(int i=0;i<3;i++)
            {
                r_Cards.Add(Card(temp[i]/100,temp[i]%100));
                three_Cards. Add(Card(temp[i]/100,temp[i]%100));
            }
            r_UpDateCard();
        }
        m_leftpiclabel->show();
        m_midpiclabel->show();
        m_rightpiclabel->show();
        CardList Threelist=three_Cards.ToCardList(Cards::Desc);
        CardList::ConstIterator it=Threelist.constBegin();
        for (;it != Threelist.constEnd()+1; it++)
        {
            CardList::ConstIterator it1 = Threelist.constBegin();
            for (int i = 0; it1 != it; it1++,i++)
            {
                cardpic* cardPic = three_cardPicMap[*it1];
                cardPic->show();
                cardPic->raise();
                cardPic->resize(75,112);
                cardPic->move(300+90*i,30);
            }
        }
    }
    if(m_judge=="chupai")
    {
        m_playHandButton->show();
    }
    if(m_judge=="chudepai")
    {
        int n;
        QString str;
        in>>n;
        in>>str;
        if(n==0)
        {
            pass->stop();
            if(m_pname[0]==str)
            {
                l_Hidelastcards();
                m_p1label->setText(tr("不出"));
                m_playHandButton->show();
                if(m_p3label->text()!=QString(tr("不出")))
                    m_passButton->show();
                leftlastcards.Clear();
                Hidelastcards();
                lastcards.Clear();
            }
            if(m_pname[1]==str)
            {
                m_p2label->setText(tr("不出"));
                lastcards.Clear();
            }
            if(m_pname[2]==str)
            {
                r_Hidelastcards();
                m_p3label->setText(tr("不出"));
                rightlastcards.Clear();
            }
            pass->play();
        }
        else
        {
            int m;
            Cards cards;
            for(int i=0;i<n;i++)
            {
                in>>m;
                cards.Add(Card(m/100,m%100));
            }
            Hand temp=Hand(cards);
            CardList temp_cardlist=cards.ToCardList();
            CardList::const_iterator it=temp_cardlist.constBegin();
            if(temp.GetType()==Hand_Single)//单牌
            {
                if(it->point==Card_3)
                {
                    //dan3->stop();//解决重复播放的问题
                    dan3->play();
                }
                if(it->point==Card_4)
                {
                    dan4->stop();
                    dan4->play();
                }
                if(it->point==Card_5)
                {
                    dan5->stop();
                    dan5->play();
                }
                if(it->point==Card_6)
                {
                    dan6->stop();
                    dan6->play();
                }
                if(it->point==Card_7)
                {
                    dan7->stop();
                    dan7->play();
                }
                if(it->point==Card_8)
                {
                    dan8->stop();
                    dan8->play();
                }
                if(it->point==Card_9)
                {
                    dan9->stop();
                    dan9->play();
                }
                if(it->point==Card_10)
                {
                    dan10->stop();
                    dan10->play();
                }
                if(it->point==Card_J)
                {
                    dan11->stop();
                    dan11->play();
                }
                if(it->point==Card_Q)
                {
                    dan12->stop();
                    dan12->play();
                }
                if(it->point==Card_K)
                {
                    dan13->stop();
                    dan13->play();
                }
                if(it->point==Card_A)
                {
                    dan1->stop();
                    dan1->play();
                }
                if(it->point==Card_2)
                {
                    dan2->stop();
                    dan2->play();
                }
                if(it->point==Card_SJ)
                {
                    dan14->stop();
                    dan14->play();
                }
                if(it->point==Card_BJ)
                {
                    dan15->stop();
                    dan15->play();
                }
            }
            if(temp.GetType()==Hand_Pair)//对
            {
                if(it->point==Card_3)
                {
                    dui3->stop();
                    dui3->play();
                }
                if(it->point==Card_4)
                {
                    dui4->stop();
                    dui4->play();
                }
                if(it->point==Card_5)
                {
                    dui5->stop();
                    dui5->play();
                }
                if(it->point==Card_6)
                {
                    dui6->stop();
                    dui6->play();
                }
                if(it->point==Card_7)
                {
                    dui7->stop();
                    dui7->play();
                }
                if(it->point==Card_8)
                {
                    dui8->stop();
                    dui8->play();
                }
                if(it->point==Card_9)
                {
                    dui9->stop();
                    dui9->play();
                }
                if(it->point==Card_10)
                {
                    dui10->stop();
                    dui10->play();
                }
                if(it->point==Card_J)
                {
                    dui11->stop();
                    dui11->play();
                }
                if(it->point==Card_Q)
                {
                    dui12->stop();
                    dui12->play();
                }
                if(it->point==Card_K)
                {
                    dui13->stop();
                    dui13->play();
                }
                if(it->point==Card_A)
                {
                    dui1->stop();
                    dui1->play();
                }
                if(it->point==Card_2)
                {
                    dui2->stop();
                    dui2->play();
                }
            }
            if(temp.GetType()==Hand_Seq_Single)//顺子
            {
                shunzi->stop();
                shunzi->play();
            }
            if(temp.GetType()==Hand_Seq_Pair)//连对
            {
                liandui->stop();
                liandui->play();
            }
            if(temp.GetType()==Hand_Seq_Triple&&n==3)//3个X
            {
                QEventLoop eventloop;
                if(it->point==Card_3)
                {
                    sange->stop();
                    dan3->stop();

                    sange->play();
                    QTimer::singleShot(400, &eventloop, SLOT(quit()));
                    eventloop.exec();
                    dan3->play();
                }
                if(it->point==Card_4)
                {
                    sange->stop();
                    dan4->stop();

                    sange->play();
                    QTimer::singleShot(400, &eventloop, SLOT(quit()));
                    eventloop.exec();
                    dan4->play();
                }
                if(it->point==Card_5)
                {
                    sange->stop();
                    dan5->stop();

                    sange->play();
                    QTimer::singleShot(400, &eventloop, SLOT(quit()));
                    eventloop.exec();
                    dan5->play();
                }
                if(it->point==Card_6)
                {
                    sange->stop();
                    dan6->stop();

                    sange->play();
                    QTimer::singleShot(400, &eventloop, SLOT(quit()));
                    eventloop.exec();
                    dan6->play();
                }
                if(it->point==Card_7)
                {
                    sange->stop();
                    dan7->stop();

                    sange->play();
                    QTimer::singleShot(400, &eventloop, SLOT(quit()));
                    eventloop.exec();
                    dan7->play();
                }
                if(it->point==Card_8)
                {
                    sange->stop();
                    dan8->stop();

                    sange->play();
                    QTimer::singleShot(400, &eventloop, SLOT(quit()));
                    eventloop.exec();
                    dan8->play();
                }
                if(it->point==Card_9)
                {
                    sange->stop();
                    dan9->stop();

                    sange->play();
                    QTimer::singleShot(400, &eventloop, SLOT(quit()));
                    eventloop.exec();
                    dan9->play();
                }
                if(it->point==Card_10)
                {
                    sange->stop();
                    dan10->stop();

                    sange->play();
                    QTimer::singleShot(400, &eventloop, SLOT(quit()));
                    eventloop.exec();
                    dan10->play();
                }
                if(it->point==Card_J)
                {
                    sange->stop();
                    dan11->stop();

                    sange->play();
                    QTimer::singleShot(400, &eventloop, SLOT(quit()));
                    eventloop.exec();
                    dan11->play();
                }
                if(it->point==Card_Q)
                {
                    sange->stop();
                    dan12->stop();

                    sange->play();
                    QTimer::singleShot(400, &eventloop, SLOT(quit()));
                    eventloop.exec();
                    dan12->play();
                }
                if(it->point==Card_K)
                {
                    sange->stop();
                    dan13->stop();

                    sange->play();
                    QTimer::singleShot(400, &eventloop, SLOT(quit()));
                    eventloop.exec();
                    dan13->play();
                }
                if(it->point==Card_A)
                {
                    sange->stop();
                    dan1->stop();

                    sange->play();
                    QTimer::singleShot(400, &eventloop, SLOT(quit()));
                    eventloop.exec();
                    dan1->play();
                }
                if(it->point==Card_2)
                {
                    sange->stop();
                    dan2->stop();

                    sange->play();
                    QTimer::singleShot(400, &eventloop, SLOT(quit()));
                    eventloop.exec();
                    dan2->play();
                }

            }
            if(temp.GetType()==Hand_Plane_n_Single&&n==4)//三带一
            {
                sandaiyi->stop();
                sandaiyi->play();
            }

            if(temp.GetType()==Hand_Plane_n_Pair&&n==5)//三带二
            {
                sandaier->stop();
                sandaier->play();
            }

            if(((temp.GetType()==Hand_Seq_Triple)||(temp.GetType()==Hand_Plane_n_Single)||(temp.GetType()==Hand_Plane_n_Pair))&&n>=6)//飞机
            {
               feiji->stop();
               feiji->play();
            }
            if(temp.GetType()==Hand_Bomb)//炸弹
            {
                zhadan->stop();
                zhadan->play();
            }
            if(temp.GetType()==Hand_Bomb_Pair||temp.GetType()==Hand_Bomb_Two_Single)//四带二
            {
                sidaier->stop();
                sidaier->play();
            }
            if(temp.GetType()==Hand_Bomb_Jokers)//王炸
            {
                wangzha->stop();
                wangzha->play();
            }
            if(m_pname[0]==str)
            {
                l_Hidelastcards();
                leftlastcards=cards;
                m_playHandButton->show();
                m_passButton->show();
                On_left_UserPlayHand(cards.Count());
                Hidelastcards();
                lastcards.Clear();
            }
            if(m_pname[1]==str)
            {
                lastcards=cards;
                m_UpDateCard();
            }
            if(m_pname[2]==str)
            {
                r_Hidelastcards();
                rightlastcards=cards;
                On_right_UserPlayHand(cards.Count());
            }
            maxhand=temp;
        }
    }
    if(m_judge=="win")
    {
        wbd= new winboard(this);
        wbd->move(270,170);
        wbd->show();
        connect(this,SIGNAL(boardinfo()),wbd,SLOT(slotbdinfoReceived()));
        connect(this,SIGNAL(refreshscore()),c,SLOT(slotrefreshinfo()));
        mywinname="";
        QString winname;
        in>>winname;
        mywinname=winname;
        for(int k=0;k<3;k++)
        {
            wbd->b_name[k]=c->name[k];
        }

        if(winname==name[lordside])
        {
            for(int i=0;i<3;i++)
            {
                if(lordside==i)
                    wbd->temp_winornot[i]=1;
                else
                    wbd->temp_winornot[i]=0;
            }
        }
        else
        {
            for(int i=0;i<3;i++)
            {
                if(lordside!=i)
                    wbd->temp_winornot[i]=1;
                else
                    wbd->temp_winornot[i]=0;
            }
        }
        for(int i=0;i<3;i++)
        {
            in>>score[i];
            c->score[i]=score[i];
        }
        for(int j=0;j<3;j++)
        {
            in>>wbd->b_cgscore[j];
        }
        emit refreshscore();
        emit boardinfo();
        if(winname==m_pname[0])
        {
            m_playHandButton->hide();
            m_passButton->hide();
        }
        m_continueButton->show();
        lose1cards.Clear();
        lose2cards.Clear();
        int n1,n2,temp;
        in>>n1;
        for(int i=0;i<n1;i++)
        {
            in>>temp;
            lose1cards.Add(Card(temp/100,temp%100));
        }
        in>>n2;
        for(int i=0;i<n2;i++)
        {
            in>>temp;
            lose2cards.Add(Card(temp/100,temp%100));
        }
        if(winname==m_pname[0])
        {
            r_Hidelastcards();
            rightlastcards.Clear();
            On_right_UserPlayHand(r_Cards.Count());
            Hidelastcards();
            lastcards.Clear();

            CardList Cardlist =lose2cards.ToCardList(Cards::Desc);//排序
            int m = Cardlist.size();
            int t = rightRect.top()-17*25;
            const int cardSpacing = 25;		// 牌间隔
            CardList::ConstIterator it = Cardlist.constBegin();
            for (int i = 0;it != Cardlist.constEnd(); it++,i++)
            {
                cardpic* cardPic = r_cardPicMap[*it];
                cardPic->SetFrontSide(1);
                cardPic->show();
                cardPic->raise();
                int topBase = t+(17-m)*25 + (rightRect.height() - (16-m) * cardSpacing - cardPic->height()) / 2;
                int left = rightRect.left();
                cardPic->move(left, topBase + i * cardSpacing);
            }
        }
        if(winname==m_pname[1])
        {
            m_continueButton->move(405,600);
            r_Hidelastcards();
            rightlastcards.Clear();
            On_right_UserPlayHand(r_Cards.Count());
            l_Hidelastcards();
            leftlastcards.Clear();
            On_left_UserPlayHand(l_Cards.Count());

            CardList Cardlist =lose1cards.ToCardList(Cards::Desc);//排序
            int m = Cardlist.size();
            int t = rightRect.top()-17*25;
            const int cardSpacing = 25;		// 牌间隔
            CardList::ConstIterator it = Cardlist.constBegin();
            for (int i = 0;it != Cardlist.constEnd(); it++,i++)
            {
                cardpic* cardPic = r_cardPicMap[*it];
                cardPic->SetFrontSide(1);
                cardPic->show();
                cardPic->raise();
                int topBase = t+(17-m)*25 + (rightRect.height() - (16-m) * cardSpacing - cardPic->height()) / 2;
                int left = rightRect.left();
                cardPic->move(left, topBase + i * cardSpacing);
            }

            CardList Cardlist1 =lose2cards.ToCardList(Cards::Desc);//排序
            int n = Cardlist1.size();
            int k = leftRect.top()-17*25;
            CardList::ConstIterator it1 = Cardlist1.constBegin();
            for (int i = 0;it1 != Cardlist1.constEnd(); it1++,i++)
            {
                cardpic* cardPic = l_cardPicMap[*it1];
                cardPic->SetFrontSide(1);
                cardPic->show();
                cardPic->raise();
                int topBase = k+(17-n)*25 + (leftRect.height() - (16-n) * cardSpacing - cardPic->height()) / 2;
                int left = leftRect.left();
                cardPic->move(left, topBase + i * cardSpacing);
            }
        }
        if(winname==m_pname[2])
        {
            l_Hidelastcards();
            leftlastcards.Clear();
            On_left_UserPlayHand(l_Cards.Count());
            Hidelastcards();
            lastcards.Clear();

            CardList Cardlist =lose1cards.ToCardList(Cards::Desc);//排序
            int m = Cardlist.size();
            int t = leftRect.top()-17*25;
            const int cardSpacing = 25;		// 牌间隔
            CardList::ConstIterator it = Cardlist.constBegin();
            for (int i = 0;it != Cardlist.constEnd(); it++,i++)
            {
                cardpic* cardPic = l_cardPicMap[*it];
                cardPic->SetFrontSide(1);
                cardPic->show();
                cardPic->raise();
                int topBase = t+(17-m)*25 + (leftRect.height() - (16-m) * cardSpacing - cardPic->height()) / 2;
                int left = leftRect.left();
                cardPic->move(left, topBase + i * cardSpacing);
            }
        }
        int imnum;
        for(int i =0;i<3;i++)
        {
            if(m_name==wbd->b_name[i])
                imnum=i;
        }
        music->stop();
        if(wbd->temp_winornot[imnum]==1)
        {
            win->stop();
            win->play();
        }
        else
        {
            lose->stop();
            lose->play();
        }
    }
    getsign();
}

void game::closeEvent(QCloseEvent* w)
{
    music->stop();
    if(m_exitgame)
    {
        emit  userclose();
    }
}
