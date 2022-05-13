#include "datalist.h"

map<string, DataList> datalist_nums; //存储所有的数据任务

std::string date_tostring(MyDate date, MyTime start_time)
{
    std::string x = to_string(date.year);
    if (date.month < 10)
        x += "0";
    x += to_string(date.month);
    if (date.day < 10)
        x += "0";
    x += to_string(date.day);
    if (start_time.hour < 10)
        x += "0";
    x += to_string(start_time.hour);
    if (start_time.minute < 10)
        x += "0";
    x += to_string(start_time.minute);
    return x;
}

DataList::DataList()
{

}
DataList::DataList(std::string name,MyDate date ,MyTime start_time, MyTime finish_time)
{
    this->name = name;
    this->date = date;
    this->start_time = start_time;
    this->finish_time = finish_time;
    std::string temp = date_tostring(date, start_time);
    datalist_nums[temp] = * this;
}
DataList::~DataList()
{

}



/*Dao层接口*/
DatagramDao DataList::toDaoItem()
{
    //所有数据转string
    DatagramDao daoitem;
    daoitem.id=id;
    daoitem.name=name;
    daoitem.date=date.toString();
    daoitem.start_time=start_time.toString();
    daoitem.finish_time=finish_time.toString();
}

DataList::DataList(DatagramDao& daoitem)
{
    //string转数据
    id=atoi(daoitem.id.c_str());  //string转int
    name=daoitem.name;    //string转string
    date.getData(daoitem.date);
    start_time.getData(daoitem.start_time);
    finish_time.getData(daoitem.finish_time);
}
