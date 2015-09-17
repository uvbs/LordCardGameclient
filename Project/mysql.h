#ifndef MYSQL_H
#define MYSQL_H
#include <QMessageBox>
#include <QString>
#include <QObject>
#include <QSqlDatabase>
#include <QtSql>
class mysql
{
public:
    mysql();
    static QSqlDatabase* db;
    static void initdatabase();
};

#endif // MYSQL_H
