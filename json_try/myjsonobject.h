#ifndef MYJSONOBJECT_H
#define MYJSONOBJECT_H

#include <QObject>

class MyJsonObject
{

public:
    MyJsonObject();
    //写入需要用的方法
    void writeJson(QString theme,QString describe,QString start_time,QString end_time,QString id);
    void readJson(QStringList Theme,QStringList Describe,QStringList Start_Time,QStringList End_Time,QStringList Id,QStringList &Th,QStringList &De,QStringList &St,QStringList &En,QStringList &I);

};

#endif // MYJSONOBJECT_H
