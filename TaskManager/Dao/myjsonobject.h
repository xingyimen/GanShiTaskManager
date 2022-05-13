#ifndef MYJSONOBJECT_H
#define MYJSONOBJECT_H

#include <QObject>
#include "daodata.h"

class MyJsonObject
{

public:
    MyJsonObject();
    //写入需要用的方法
    void writeJson(ScheduleDao& item);   //写日程
    void writeJson(WorkflowDao& item);   //写工作流
     void writeJson(QuadrantDao& item);   //写四象限
     void writeJson(DatagramDao& item);   //写数据报表
    void readScheJson(QStringList &Th,QStringList &De,QStringList &St,QStringList &En,QStringList &I);  //取日程







};

#endif // MYJSONOBJECT_H

//QString theme,QString describe,QString start_time,QString end_time,QString id
//QStringList Theme,QStringList Describe,QStringList Start_Time,QStringList End_Time,QStringList Id,QStringList &Th,QStringList &De,QStringList &St,QStringList &En,QStringList &I



