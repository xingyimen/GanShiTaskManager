#ifndef DATALIST_H
#define DATALIST_H
#include "mytime.h"

#include<iostream>
#include<string>
#include<map>
#include "daodata.h"

//map<string, DataList> datalist_nums; //存储所有的数据任务

class DataList
{
public:
    int id;
    std::string name;	//完成的科目名称
    MyDate date;        //日期
    MyTime start_time;	//开始时间
    MyTime finish_time;	//结束时间
public:
    DataList();
    DataList(std::string name,MyDate date ,MyTime start_time, MyTime finish_time);	//构造函数
    ~DataList();

    /*Qt接口*/
    std::string getname(){return name;}
    MyDate getdate(){return date;}
    MyTime getstarttime(){return start_time;}
    MyTime getendtime(){return finish_time;}
     /*Dao层接口*/
    DatagramDao toDaoItem();
    DataList(DatagramDao& item);
};


#endif // DATALIST_H


