#include "user_sql.h"
#include<QString>
#include<string>
#include<QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonValue>
#include<QtDebug>
#include<QFile>
#include<QString>
#include<QCoreApplication>
#include<QDir>
#include<QFileDialog>

#include "myjsonobject.h"

User_sql::User_sql()
{

}

void User_sql::connect_mysql(QSqlDatabase &database)
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("124.223.188.73");      //连接数据库主机名，这里需要注意（若填的为”127.0.0.1“，出现不能连接，则改为localhost)
    db.setPort(3306);                 //连接数据库端口号，与设置一致
     db.setDatabaseName("tomato");      //连接数据库名，与设置一致
     db.setUserName("root");          //数据库用户名，与设置一致
     db.setPassword("Yintama2002");    //数据库密码，与设置一致
     qDebug()<<"开始连接";
     db.open();
     if(!db.open())
     {
         qDebug()<<"不能连接"<<"connect to mysql error"<<db.lastError().text();
         return ;
     }
     else
     {
          qDebug()<<"连接成功"<<"connect to mysql OK";
     }
     database=db;
//     QSqlQuery query(db);
//     //这是自己的表的名字，下面操作是打印出test表name一列的所有数据
//     query.exec("select * from student");
//     while(query.next()){
//         qDebug()<<query.value("uname").toString();
//     }
}

void User_sql::sign(QString name,QString passwd,QSqlDatabase database)
{
    QSqlQuery query(database);
    QString sql_s="insert into users(id,username,password) values(NULL,'"+name+"','"+passwd+"');";
    if(!query.exec(sql_s))
    {
        qDebug()<<"插入错误"<<"用户名已存在";
        return;
    }
    else
    {
        qDebug()<<"插入成功";
    }
}

int User_sql::login(QString name,QString passwd,QSqlDatabase database)
{
    QSqlQuery query(database);
    QString sql_s="SELECT id FROM tomato.users where username='"+name+"' and password='"+passwd+"';";
    if(!query.exec(sql_s))
    {
        qDebug()<<"登录失败,请重新输入用户名和密码"<<database.lastError();
        return 0;
    }
    else
    {
        query.next();
        int id=query.value("id").toInt();
        qDebug()<<"登录成功"<<"用户id为"<<id;
        return id;
    }
}

void User_sql::write_ScheduleDao(int user_id,QSqlDatabase database)
{
    QString userid=QString::number(user_id);
    QSqlQuery query(database);
    QString a=QCoreApplication::applicationDirPath();//获取当前路径
    QString path=a+"/SJSONS";


    //获取所有文件名
    QDir dir(path);
    dir.setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);
    QStringList fileEntryList=dir.entryList();
    for(int i=0;i<fileEntryList.size();++i)
    {
        QString json_name=fileEntryList[i];
        QString a=QCoreApplication::applicationDirPath();//获取当前路径
        QFile file(a+"/SJSONS/"+json_name);//保存到指定路径
        file.open(QFile::ReadOnly);//bool 函数 true文件打开成功 false 打开失败
        QByteArray all=file.readAll();
        file.close();

        QJsonDocument doc=QJsonDocument::fromJson(all);
        if(doc.isObject())
        {
            QJsonObject obj=doc.object();
            QStringList keys=obj.keys();
//这边括号里名字要和json方法里存储名字一一对应
            QString theme=obj.value("名称").toString();

            QString describe=obj.value("描述").toString();

            QString start_time=obj.value("开始时间").toString();

            QString end_time=obj.value("结束日期").toString();

            QString id=obj.value("节点id").toString();

            QString sql_s="insert into ScheduleDao(user_id,id,theme,describe,start_time,end_time) values("+userid+","+id+",'"+theme+"','"+describe+"','"+start_time+"','"+end_time+"');";
            if(!query.exec(sql_s))
            {
                qDebug()<<"插入错误";
                return;
            }
            else
            {
                qDebug()<<"插入成功";
            }
        }
    }
}

void User_sql::write_QuadrantDao(int user_id,QSqlDatabase database)
{
    QString userid=QString::number(user_id);
    QSqlQuery query(database);
    QString a=QCoreApplication::applicationDirPath();//获取当前路径
    QString path=a+"/QJSONS";


    //获取所有文件名
    QDir dir(path);
    dir.setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);
    QStringList fileEntryList=dir.entryList();
    for(int i=0;i<fileEntryList.size();++i)
    {
        QString json_name=fileEntryList[i];
        QString a=QCoreApplication::applicationDirPath();//获取当前路径
        QFile file(a+"/QJSONS/"+json_name);//保存到指定路径
        file.open(QFile::ReadOnly);//bool 函数 true文件打开成功 false 打开失败
        QByteArray all=file.readAll();
        file.close();

        QJsonDocument doc=QJsonDocument::fromJson(all);
        if(doc.isObject())
        {
            QJsonObject obj=doc.object();
            QStringList keys=obj.keys();
//这边括号里名字要和json方法里存储名字一一对应
            QString rol=obj.value("任务在象限的横坐标").toString();

            QString col=obj.value("任务在象限的纵坐标").toString();

            QString name=obj.value("任务名称").toString();

            QString description=obj.value("具体描述").toString();

            QString end_time=obj.value("截止时间").toString();

            QString id=obj.value("id").toString();

            QString sql_s="insert into QuadrantDao(user_id,id,rol,col,name,description,end_time) values("+userid+","+id+",'"+rol+"','"+col+"','"+name+"','"+description+"','"+end_time+"');";
            if(!query.exec(sql_s))
            {
                qDebug()<<"插入错误";
                return;
            }
            else
            {
                qDebug()<<"插入成功";
            }
        }
    }
}


void User_sql::write_DatagramDao(int user_id,QSqlDatabase database)
{
    QString userid=QString::number(user_id);
    QSqlQuery query(database);
    QString a=QCoreApplication::applicationDirPath();//获取当前路径
    QString path=a+"/DJSONS";


    //获取所有文件名
    QDir dir(path);
    dir.setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);
    QStringList fileEntryList=dir.entryList();
    for(int i=0;i<fileEntryList.size();++i)
    {
        QString json_name=fileEntryList[i];
        QString a=QCoreApplication::applicationDirPath();//获取当前路径  ？？
        QFile file(a+"/DJSONS/"+json_name);//保存到指定路径
        file.open(QFile::ReadOnly);//bool 函数 true文件打开成功 false 打开失败
        QByteArray all=file.readAll();
        file.close();

        QJsonDocument doc=QJsonDocument::fromJson(all);
        if(doc.isObject())
        {
            QJsonObject obj=doc.object();
            QStringList keys=obj.keys();

            QString name=obj.value("完成的科目名称").toString();

            QString date=obj.value("日期").toString();

            QString start_time=obj.value("开始时间").toString();

            QString finish_time=obj.value("结束时间").toString();

            QString id=obj.value("id").toString();

            QString sql_s="insert into DatagramDao(user_id,id,name,date,start_time,finish_time) values("+userid+","+id+",'"+name+"','"+date+"','"+start_time+"','"+finish_time+"');";
            if(!query.exec(sql_s))
            {
                qDebug()<<"插入错误";
                return;
            }
            else
            {
                qDebug()<<"插入成功";
            }
        }
    }
}

void User_sql::write_WorkflowDao(int user_id,QSqlDatabase database)
{
    QString userid=QString::number(user_id);
    QSqlQuery query(database);
    QString a=QCoreApplication::applicationDirPath();//获取当前路径
    QString path=a+"/WJSONS";


    //获取所有文件名
    QDir dir(path);
    dir.setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);
    QStringList fileEntryList=dir.entryList();
    for(int i=0;i<fileEntryList.size();++i)
    {
        QString json_name=fileEntryList[i];
        QString a=QCoreApplication::applicationDirPath();//获取当前路径
        QFile file(a+"/WJSONS/"+json_name);//保存到指定路径
        file.open(QFile::ReadOnly);//bool 函数 true文件打开成功 false 打开失败
        QByteArray all=file.readAll();
        file.close();

        QJsonDocument doc=QJsonDocument::fromJson(all);
        if(doc.isObject())
        {
            QJsonObject obj=doc.object();
            QStringList keys=obj.keys();
//这边括号里名字要和json方法里存储名字一一对应
            QString root_node_type=obj.value("接受是根节点还是孩子结点").toString();

            QString book=obj.value("节点名称").toString();

            QString node_type=obj.value("节点类型").toString();

            QString flag=obj.value("节点状态").toString();

            QString sibling=obj.value("指向兄弟").toString();

            QString child=obj.value("指向孩子").toString();

            QString id=obj.value("节点id").toString();

            QString sql_s="insert into WorkflowDao(user_id,id,root_node_type,book,node_type,flag,sibling,child) values("+userid+","+id+","+root_node_type+",'"+book+"',"+node_type+","+flag+",'"+sibling+"','"+child+"');";
            if(!query.exec(sql_s))
            {
                qDebug()<<"插入错误";
                return;
            }
            else
            {
                qDebug()<<"插入成功";
            }
        }
    }
}

void User_sql::read_ScheduleDao(int user_id,QSqlDatabase database,QStringList &ID,QStringList &THEME,QStringList &DESC,QStringList &ST,QStringList &EN)
{
    QString userid=QString::number(user_id);
    QSqlQuery query(database);
    QString sql_s="select * from tomato.scheduledao where user_id="+userid+";";

    if(query.exec(sql_s))
    {
        qDebug()<<"查询成功";
    }
    while(query.next()){
       QString id=query.value("id").toString();
       ID.append(id);
       QString theme=query.value("theme").toString();
       THEME.append(theme);
       QString describe=query.value("describe").toString();
       DESC.append(describe);
       QString start_time=query.value("start_time").toString();
       ST.append(start_time);
       QString end_time=query.value("end_time").toString();
       EN.append(end_time);

       //使用json方法保存到本地
       //       MyJsonObject example1;
       //       example1.writeJson();
    }
}

void User_sql::read_DatagramDao(int user_id,QSqlDatabase database,QStringList &ID,QStringList &NAME,QStringList &DATE,QStringList &ST,QStringList &FI)
{
    QString userid=QString::number(user_id);
    QSqlQuery query(database);
    QString sql_s="select * from tomato.datagramdao where user_id="+userid+";";

    if(query.exec(sql_s))
    {
        qDebug()<<"查询成功";
    }
    while(query.next()){
       QString id=query.value("id").toString();
       ID.append(id);
       QString name=query.value("name").toString();
       NAME.append(name);
       QString date=query.value("date").toString();
       DATE.append(date);
       QString start_time=query.value("start_time").toString();
       ST.append(start_time);
       QString finish_time=query.value("finish_time").toString();
       FI.append(finish_time);

       //使用json方法保存到本地
       //       MyJsonObject example1;
       //       example1.writeJson();
    }
}

void User_sql::read_QuadrantDao(int user_id,QSqlDatabase database,QStringList &ID,QStringList &ROL,QStringList &COL,QStringList &NAME,QStringList &DESC,QStringList &EN)
{
    QString userid=QString::number(user_id);
    QSqlQuery query(database);
    QString sql_s="select * from tomato.quadrantdao where user_id="+userid+";";

    if(query.exec(sql_s))
    {
        qDebug()<<"查询成功";
    }
    while(query.next()){
       QString id=query.value("id").toString();
       ID.append(id);
       QString rol=query.value("rol").toString();
       ROL.append(rol);
       QString col=query.value("col").toString();
       COL.append(col);
       QString name=query.value("name").toString();
       NAME.append(name);
       QString description=query.value("description").toString();
       DESC.append(description);
       QString end_time=query.value("end_time").toString();
       EN.append(end_time);

       //使用json方法保存到本地
       //       MyJsonObject example1;
       //       example1.writeJson();
    }
}


void User_sql::read_WorkflowDa(int user_id,QSqlDatabase database,QStringList &ID,QStringList &ROOT,QStringList &BOOK,QStringList &NODE,QStringList &FL,QStringList &SI,QStringList &CH)
{
    QString userid=QString::number(user_id);
    QSqlQuery query(database);
    QString sql_s="select * from tomato.quadrantdao where user_id="+userid+";";

    if(query.exec(sql_s))
    {
        qDebug()<<"查询成功";
    }
    while(query.next()){
       QString id=query.value("id").toString();
       ID.append(id);
       QString root_node_type=query.value("root_node_type").toString();
       ROOT.append(root_node_type);
       QString book=query.value("book").toString();
       BOOK.append(book);
       QString node_type=query.value("node_type").toString();
       NODE.append(node_type);
       QString flag=query.value("flag").toString();
       FL.append(flag);
       QString sibling=query.value("sibling").toString();
       SI.append(sibling);
       QString child=query.value("child").toString();
       CH.append(child);

       //使用json方法保存到本地
       //       MyJsonObject example1;
       //       example1.writeJson();
    }
}
