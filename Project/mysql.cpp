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
        QMessageBox::warning(NULL,QObject::tr("��ʾ"),QObject::tr("�޷������ݿ�"),QMessageBox::Ok);
    }
}
