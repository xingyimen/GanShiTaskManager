#ifndef SCHEDULE_H
#define SCHEDULE_H

#include<string>
#include "mytime.h"
#include "daodata.h"
#include"worktree.h"
#include"quadrant.h"



//日程界面部分
class Schedule
{
private:
    std::string name;			//日程名称
    std::string description;		//具体描述
    MyTime start_time;		//日程的开始时间
    MyTime end_time;			//日程的结束时间
public:
    Schedule(std::string name, std::string description, MyTime start_time, MyTime end_time);	//构造函数
    Schedule(WorkTree& item, MyTime start_time, MyTime end_time); //从工作流导入数据
    Schedule(Quadrant& item, MyTime start_time, MyTime end_time); //从四象限导入数据
    ~Schedule();	//析构函数
    /*Qt接口*/
    std::string getname(){return name;}
    std::string getdescription(){return description;}
    MyTime getstarttime(){return start_time;}
    MyTime getendtime(){return end_time;}
    /*Dao层接口*/
   ScheduleDao toDaoItem();
   Schedule(ScheduleDao& item);
};

#endif
