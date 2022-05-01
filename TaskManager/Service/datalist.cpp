#include "datalist.h"

DataList::DataList()
{

}
DataList::DataList(std::string name,MyDate date ,MyTime start_time, MyTime finish_time)
{

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
