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
#include<QMessageBox>
#include "myjsonobject.h"


Linklist<ScheduleDao>* ScheDaoList=new Linklist<ScheduleDao>();  //全局变量，装载日程的链表
Linklist<WorkflowDao>* WorkDaoList=new Linklist<WorkflowDao>();  //全局变量，装载日程的链表
Linklist<QuadrantDao>* QuadDaoList=new Linklist<QuadrantDao>();  //全局变量，装载日程的链表

User_sql::User_sql()
{

}

bool User_sql::connect_mysql(QSqlDatabase &database)
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
         return false;
     }
     else
     {
          qDebug()<<"连接成功"<<"connect to mysql OK";
          database=db;
          return true;
     }

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

void User_sql::write_ScheduleDao(int user_id,ScheduleDao item,QSqlDatabase database)
{
    QString userid=QString::number(user_id);
    QSqlQuery query(database);
    QString sql_s="INSERT INTO `tomato`.`scheduledao`(`user_id`,`id`,`theme`,`describe`,`start_time`,`end_time`) VALUES('"+userid+"','"+QString(item.id.c_str())+"','"+QString(item.theme.c_str())+"','"+QString(item.describe.c_str())+"','"+QString(item.start_time.c_str())+"','"+QString(item.end_time.c_str())+"');";
    qDebug()<<sql_s;
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
void User_sql::write_QuadrantDao(int user_id,QuadrantDao item,QSqlDatabase database)
{
    QString userid=QString::number(user_id);
    QSqlQuery query(database);
    QString sql_s="insert into QuadrantDao(user_id,id,rol,col,name,description,end_time,end_date) values('"+userid+"','"+QString(item.id.c_str())+"','"+QString(item.rol.c_str())+"','"+QString(item.col.c_str())+"','"+QString(item.name.c_str())+"','"+QString(item.description.c_str())+"','"+QString(item.end_time.c_str())+"','"+QString(item.end_date.c_str())+"');";
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

void User_sql::write_WorkflowDao(int user_id,WorkflowDao item,QSqlDatabase database)
{
    QString userid=QString::number(user_id);
    QSqlQuery query(database);
    QString sql_s="insert into WorkflowDao(user_id,id,root_node_type,book,node_type,flag,sibling,child) values("+userid+","+item.id+","+item.root_node_type+",'"+item.book+"',"+item.node_type+","+item.flag+",'"+item.sibling+"','"+item.child+"');";
    if(!query.exec(sql_s))
    {
        qDebug()<<"插入错误";
        return;
    }
    else
    {
        qDebug()<<"插入成功";
    }
//    QString a=QCoreApplication::applicationDirPath();//获取当前路径
//    QString path=a+"/WJSONS";


//    //获取所有文件名
//    QDir dir(path);
//    dir.setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);
//    QStringList fileEntryList=dir.entryList();
//    for(int i=0;i<fileEntryList.size();++i)
//    {
//        QString json_name=fileEntryList[i];
//        QString a=QCoreApplication::applicationDirPath();//获取当前路径
//        QFile file(a+"/WJSONS/"+json_name);//保存到指定路径
//        file.open(QFile::ReadOnly);//bool 函数 true文件打开成功 false 打开失败
//        QByteArray all=file.readAll();
//        file.close();

//        QJsonDocument doc=QJsonDocument::fromJson(all);
//        if(doc.isObject())
//        {
//            QJsonObject obj=doc.object();
//            QStringList keys=obj.keys();
////这边括号里名字要和json方法里存储名字一一对应
//            QString root_node_type=obj.value("接受是根节点还是孩子结点").toString();

//            QString book=obj.value("节点名称").toString();

//            QString node_type=obj.value("节点类型").toString();

//            QString flag=obj.value("节点状态").toString();

//            QString sibling=obj.value("指向兄弟").toString();

//            QString child=obj.value("指向孩子").toString();

//            QString id=obj.value("节点id").toString();


//        }
//    }
}

void User_sql::read_ScheduleDao(int user_id,QSqlDatabase database)
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
       QString theme=query.value("theme").toString();
       QString describe=query.value("describe").toString();
       QString start_time=query.value("start_time").toString();
       QString end_time=query.value("end_time").toString();
       //插入链表
       ScheduleDao* item = new(ScheduleDao);
       item->id=id.toStdString();
       item->theme = theme.toStdString();
       item->describe = describe.toStdString();
       item->start_time=start_time.toStdString();
       item->end_time=end_time.toStdString();
       ScheDaoList->InsertDataAtRear(item);
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

void User_sql::read_QuadrantDao(int user_id,QSqlDatabase database)
{
    QString userid=QString::number(user_id);
    QSqlQuery query(database);
    QString sql_s="select * from tomato.quadrantdao where user_id="+userid+";";
    qDebug()<<user_id;
    if(query.exec(sql_s))
    {
        qDebug()<<"查询成功";
    }
    while(query.next()){
       QString id=query.value("id").toString();
       QString rol=query.value("rol").toString();
       QString col=query.value("col").toString();
       QString name=query.value("name").toString();
       QString description=query.value("description").toString();
       QString end_time=query.value("end_time").toString();
       QString end_date=query.value("end_date").toString();
       //插入链表
       QuadrantDao* item = new(QuadrantDao);
       item->id=id.toStdString();
       item->rol=rol.toStdString();
       item->col=col.toStdString();
       item->name=name.toStdString();
       item->description=description.toStdString();
       item->end_time=end_time.toStdString();
       item->end_date=end_date.toStdString();
       QuadDaoList->InsertDataAtHead(item);
    }
}


void User_sql::read_WorkflowDao(int user_id,QSqlDatabase database,QStringList &ID,QStringList &ROOT,QStringList &BOOK,QStringList &NODE,QStringList &FL,QStringList &SI,QStringList &CH)
{
    QString userid=QString::number(user_id);
    QSqlQuery query(database);
    QString sql_s="select * from tomato.workflowdao where user_id="+userid+";";

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

void User_sql::clean_QuadrantDao(int user_id,QSqlDatabase database)
{
    QString userid=QString::number(user_id);
    QSqlQuery query(database);
    QString sql_d=("delete from QuadrantDao where user_id='")+userid+"';";
    if(query.exec(sql_d))
    {
        qDebug()<<"QuadrantDao删除成功";
    }
}
void User_sql::clean_ScheduleDao(int user_id,QSqlDatabase database)
{
    QString userid=QString::number(user_id);
    QSqlQuery query(database);
    QString sql_d=("delete from ScheduleDao where user_id='")+userid+"';";
    if(query.exec(sql_d))
    {
        qDebug()<<"ScheduleDao删除成功";
    }
}
void User_sql::clean_WorkflowDao(int user_id,QSqlDatabase database)
{
    QString userid=QString::number(user_id);
    QSqlQuery query(database);
    QString sql_d=("delete from WorkflowDao where user_id='")+userid+"';";
    if(query.exec(sql_d))
    {
        qDebug()<<"WorkflowDao删除成功";
    }
}
