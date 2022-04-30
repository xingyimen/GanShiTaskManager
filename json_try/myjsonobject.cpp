#include "myjsonobject.h"
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

MyJsonObject::MyJsonObject()
{

}
void MyJsonObject::writeJson(QString theme,QString describe,QString start_time,QString end_time,QString id)
{
    //创建存储json文件的文件夹
    QString a=QCoreApplication::applicationDirPath();//获取程序所在位置的目录
    QString dir_str=a+"/JSONS";
    //检查目录是否存在，若不存在则新建
    QDir dir;
    if(!dir.exists(dir_str))
    {
        bool res=dir.mkpath(dir_str);
        if(!res) qDebug()<<"JSONS file can't be created";
    }


    QJsonObject obj;
    obj.insert("主题",theme);//这里是QJsonValue类型，发生了隐式的字符串转换
    obj.insert("描述",describe);
    obj.insert("开始时间",start_time);
    obj.insert("结束时间",end_time);
    obj.insert("id",id);

    QJsonDocument doc(obj);
    QByteArray json=doc.toJson();//得到json字符串

    QString json_name="a"+id+".json";
    QFile file(a+"/JSONS/"+json_name);//保存到指定路径
    file.open(QFile::WriteOnly);//bool 函数 true文件打开成功 false 打开失败
    file.write(json);
    file.close();
}

void MyJsonObject::readJson(QStringList Theme,QStringList Describe,QStringList Start_Time,QStringList End_Time,QStringList Id,QStringList &Th,QStringList &De,QStringList &St,QStringList &En,QStringList &I)
{
    QString a=QCoreApplication::applicationDirPath();//获取当前路径
    QString path=a+"/JSONS";


    //获取所有文件名
    QDir dir(path);
    dir.setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);
    QStringList fileEntryList=dir.entryList();
    for(int i=0;i<fileEntryList.size();++i)
    {
        QString json_name=fileEntryList[i];
        QString a=QCoreApplication::applicationDirPath();//获取当前路径
        QFile file(a+"/JSONS/"+json_name);//保存到指定路径
        file.open(QFile::ReadOnly);//bool 函数 true文件打开成功 false 打开失败
        QByteArray all=file.readAll();
        file.close();

        QJsonDocument doc=QJsonDocument::fromJson(all);
        if(doc.isObject())
        {
            QJsonObject obj=doc.object();
            QStringList keys=obj.keys();

            QString t_value=obj.value("主题").toString();
            Theme.append(t_value);

            QString d_value=obj.value("描述").toString();
            Describe.append(d_value);

            QString s_value=obj.value("开始时间").toString();
            Start_Time.append(s_value);

            QString e_value=obj.value("结束时间").toString();
            End_Time.append(e_value);

            QString i_value=obj.value("id").toString();
            Id.append(i_value);


        }
    }
    //这里改了下，在函数里增加了五个指针参数传出数据
    Th=Theme;
    De=Describe;
    St=Start_Time;
    En=End_Time;
    I=Id;
}
