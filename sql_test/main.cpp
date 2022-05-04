#include <QCoreApplication>
#include <QtDebug>
#include"user_sql.h"
#include<QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include "myjsonobject.h"

int main(int argc,char *argv[])
{
    QCoreApplication a(argc,argv);

    User_sql b;
    QSqlDatabase database;
    b.connect_mysql(database);
    int user_id=b.login("三","10420",database);

    QStringList c,d,e,f,g;
    b.read_DatagramDao(user_id,database,c,d,e,f,g);
    qDebug()<<c[0];
    return a.exec();
}
