#ifndef DATALIST_H
#define DATALIST_H
#include "mytime.h"

#include<iostream>
#include "daodata.h"
class DataList
{
private:
    int id;
    std::string name;		//完成的科目名称
    MyDate date;      //日期
    MyTime start_time;	//开始时间
    MyTime finish_time;	//结束时间
public:
    DataList();
    DataList(std::string name,MyDate date ,MyTime start_time, MyTime finish_time);	//构造函数
    std::pair<std::string, std::string> return_name();		//返回{root,name}
    std::pair<MyTime, MyTime> return_time();			//返回{start_time,finish_time}
    ~DataList();

     /*Dao层接口*/
    DatagramDao toDaoItem();
    DataList(DatagramDao& item);


};

#endif // DATALIST_H
