#ifndef USER_SQL_H
#define USER_SQL_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

class User_sql
{

public:
    User_sql();

    //连接数据库
    void connect_mysql(QSqlDatabase &database);
    //注册
    void sign(QString name,QString passwd,QSqlDatabase database);
    //登录 返回用户id
    int login(QString name,QString passwd,QSqlDatabase database);
    //插入DJSONS 整个数据的备份 到
    void write_DatagramDao(int user_id,QSqlDatabase database);

    void write_ScheduleDao(int user_id,QSqlDatabase database);

    void write_QuadrantDao(int user_id,QSqlDatabase database);

    void write_WorkflowDao(int user_id,QSqlDatabase database);

    //从数据库读取数据
    void read_DatagramDao(int user_id,QSqlDatabase database,QStringList &ID,QStringList &NAME,QStringList &DATE,QStringList &ST,QStringList &FI);

    void read_ScheduleDao(int user_id,QSqlDatabase database,QStringList &ID,QStringList &THEME,QStringList &DESC,QStringList &ST,QStringList &EN);

    void read_QuadrantDao(int user_id,QSqlDatabase database,QStringList &ID,QStringList &ROL,QStringList &COL,QStringList &NAME,QStringList &DESC,QStringList &EN);

    void read_WorkflowDa(int user_id,QSqlDatabase database,QStringList &ID,QStringList &ROOT,QStringList &BOOK,QStringList &NODE,QStringList &FL,QStringList &SI,QStringList &CH);


};

#endif // USER_SQL_H
