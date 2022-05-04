#ifndef MYJSONOBJECT_H
#define MYJSONOBJECT_H

#include <QObject>

class MyJsonObject
{

public:
    MyJsonObject();
    //写入需要用的方法
    void writeJson(QString id,QString name,QString date,QString start_time,QString finish_time);
    void readJson(QStringList &Th,QStringList &De,QStringList &St,QStringList &En,QStringList &I);

};

#endif // MYJSONOBJECT_H
