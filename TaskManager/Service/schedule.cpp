#include "schedule.h"

//日程类
/*
构造函数：
【参数】
string name：日程名称
string description：日程的具体描述
Time start_time：日程的开始时间
Time end_time：日程的结束时间
*/
#include <QDebug>

extern Linklist<ScheduleDao>* ScheDaoList;  //全局变量，装载日程的链表
int IDSchedule=1;  //ID
Schedule::Schedule(std::string q_name, std::string q_description, MyTime q_start_time, MyTime q_end_time)
{
    id=IDSchedule++;
    name=(q_name=="")? "未命名":q_name;
    description=(q_description=="")? "略":q_description;
    start_time=q_start_time;
    end_time=q_end_time;
}

Schedule::Schedule(WorkChild* item, MyTime q_start_time, MyTime q_end_time){
/*从工作流导入数据*/
    id=IDSchedule++;
    name=item->return_name().toStdString();
    description=item->return_progress().toStdString();
    start_time=q_start_time;
    end_time=q_end_time;
}

Schedule::Schedule(Quadrant* item, MyTime q_start_time, MyTime q_end_time){
/*从四象限导入数据*/
    id=IDSchedule++;
    name=item->return_name();
    description=item->return_description();
    start_time=q_start_time;
    end_time=q_end_time;
}

Schedule::~Schedule(){

}
/*Dao层接口*/
void Schedule::toDaoItem()
{
    ScheduleDao* daoitem=new (ScheduleDao);
    daoitem->id=std::to_string(id);
    daoitem->theme=name;
    daoitem->start_time=start_time.toString();
    daoitem->end_time=end_time.toString();
    daoitem->describe=description;
    /*所有数据转string*/
    ScheDaoList->InsertDataAtHead(daoitem);
}

Schedule::Schedule(ScheduleDao* daoitem)
{
    /*string转数据*/
    id=IDSchedule++;
    name = daoitem->theme;
    start_time.getData(daoitem->start_time);
    end_time.getData(daoitem->end_time);
    description=daoitem->describe;
}

