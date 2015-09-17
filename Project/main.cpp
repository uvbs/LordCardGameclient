#include <QtGui/QApplication>
#include <QTextCodec>
#include <QString>
#include <QApplication>
#include "entry.h"
#include "login.h"
#include "player.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle("windows");
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    mysql::initdatabase();
    login begin; 
    begin.show();
    begin.judgeauto();//检测是否有用户自动登录

    return a.exec();
}
