#include "mysql.h"
QSqlDatabase* mysql::db;
mysql::mysql()
{

}

void mysql::initdatabase()
{
    db=&QSqlDatabase::addDatabase("QSQLITE");
    db->setDatabaseName("sql.sqlite");
    if(!db->open())
    {
        qDebug()<<"open sql fail!";
        QMessageBox::warning(NULL,QObject::tr("提示"),QObject::tr("无法打开数据库"),QMessageBox::Ok);
    }
}
