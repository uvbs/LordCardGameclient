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
    begin.judgeauto();//����Ƿ����û��Զ���¼

    return a.exec();
}
