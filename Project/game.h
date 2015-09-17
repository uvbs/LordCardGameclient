#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <QDebug>
#include <QFrame>
#include <QPixmap>
#include <QLabel>
#include <QTimer>
#include <QDesktopWidget>//让程序居中显示
#include <QPushButton>
#include <QTextCodec>
#include <QPalette>
#include <QTcpSocket>
#include "hand.h"
#include "chatroom.h"
#include "cardpic.h"
#include "winboard.h"
#include<QSound>
#include<phonon>
#include<QUrl>

namespace Ui {
class game;
}

class game : public QDialog
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = 0);
    ~game();
    void fapai();
    void InitControl();
    void InitcardpicMap();
    void Initother();
    void Cutcardpic(const QPixmap& cardsPic,int x, int y, Card card);
    void m_UpDateCard();
    void l_UpDateCard();
    void r_UpDateCard();
    void Hidelastcards();
    void l_Hidelastcards();
    void r_Hidelastcards();
protected:
    void closeEvent(QCloseEvent* w);
public slots:
    void readplayer(QString,int);
    void getsign();
    void on_m_startButton_clicked();
    void On_m_ContinueBtnClicked();
    void On_m_UserNoCall();
    void On_m_UserCall();
    void On_m_UserRublord();
    void On_m_UserNoRub();
    void On_m_UserPass();
    void On_m_UserPlayHand();
    void On_left_UserPlayHand(int);
    void On_right_UserPlayHand(int);
    void OnCardSelected(Qt::MouseButton mousebutton);
signals:
    void userclose();
    void userinfo();
    void boardinfo();
    void refreshscore();
private:
    Ui::game* ui;
    chatroom* c;
    winboard* wbd;
    QTcpSocket* m_tcpsocket;
    quint16 m_blocksize;

    Cards m_Cards;
    Cards l_Cards;//fake cards
    Cards r_Cards;
    Cards three_Cards;
    Cards lastcards;
    Cards leftlastcards;
    Cards rightlastcards;
    Cards lose1cards;
    Cards lose2cards;
    Hand maxhand;

    bool m_exitgame;
    int m_canjiao;
    int whowin;//通过与服务器发送姓名的比对来确定客户端标号为几的玩家赢了
    QString name[3];
    QString score[3];
    QString m_name;
    QString m_pname[3];
    int lordside;
    QString mywinname;

    QPushButton* m_startButton;
    QPushButton* m_continueButton;
    QPushButton* m_playHandButton;
    QPushButton* m_passButton;
    QPushButton* m_calllordButton;
    QPushButton* m_nocallButton;
    QPushButton* m_rublordButton;
    QPushButton* m_norubButton;

    QLabel* m_p1label;
    QLabel* m_p2label;
    QLabel* m_p3label;
    QLabel* m_leftlabel;
    QLabel* m_midlabel;
    QLabel* m_rightlabel;
    QLabel* m_leftpiclabel;
    QLabel* m_midpiclabel;
    QLabel* m_rightpiclabel;

    QLabel* board;

    QRect cardsRect;//原始牌框
    QRect playHandRect;//出牌框
    QRect leftRect;
    QRect left_playHandRect;
    QRect rightRect;
    QRect right_playHandRect;

    QMap<Card, cardpic*> m_cardPicMap;	// 每张卡片对应一个图片
    QMap<Card, cardpic*> l_cardPicMap;
    QMap<Card, cardpic*> r_cardPicMap;
    QMap<Card,cardpic*> three_cardPicMap;
    QSet<cardpic*>m_selectedCards;

    QPixmap m_cardBackPic; // 牌背面的图像
    QPixmap m_lordPic;
    QPixmap m_farmerPic;
    QSize m_cardSize;//QSize定义了一个二维对象的大小，一个大小由一个宽和一个高确定

//背景音乐的加入
    Phonon::MediaObject*music;
    Phonon::MediaObject*pass;//初始化
    Phonon::MediaObject*qiang;
    Phonon::MediaObject*jiao;
    Phonon::MediaObject*bujiao;
    Phonon::MediaObject*buqiang;
    Phonon::MediaObject*dan1;
    Phonon::MediaObject*dan2;
    Phonon::MediaObject*dan3;
    Phonon::MediaObject*dan4;
    Phonon::MediaObject*dan5;
    Phonon::MediaObject*dan6;
    Phonon::MediaObject*dan7;
    Phonon::MediaObject*dan8;
    Phonon::MediaObject*dan9;
    Phonon::MediaObject*dan10;
    Phonon::MediaObject*dan11;
    Phonon::MediaObject*dan12;
    Phonon::MediaObject*dan13;
    Phonon::MediaObject*dan14;//小王
    Phonon::MediaObject*dan15;//大王
    Phonon::MediaObject*dui1;
    Phonon::MediaObject*dui2;
    Phonon::MediaObject*dui3;
    Phonon::MediaObject*dui4;
    Phonon::MediaObject*dui5;
    Phonon::MediaObject*dui6;
    Phonon::MediaObject*dui7;
    Phonon::MediaObject*dui8;
    Phonon::MediaObject*dui9;
    Phonon::MediaObject*dui10;
    Phonon::MediaObject*dui11;
    Phonon::MediaObject*dui12;
    Phonon::MediaObject*dui13;
    Phonon::MediaObject*shunzi;
    Phonon::MediaObject*liandui;
    Phonon::MediaObject*feiji;
    Phonon::MediaObject*zhadan;
    Phonon::MediaObject*wangzha;
    Phonon::MediaObject*sange;
    Phonon::MediaObject*sandaiyi;
    Phonon::MediaObject*sandaier;
    Phonon::MediaObject*sidaier;
    Phonon::MediaObject*win;
    Phonon::MediaObject*lose;
    Phonon::MediaObject*ffapai;


};
#endif // GAME_H
