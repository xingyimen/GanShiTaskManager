#ifndef SCHEDULE_H
#define SCHEDULE_H

#include<string>
#include "mytime.h"
#include "daodata.h"

//日程界面部分
class Schedule
{
private:
    std::string name;			//日程名称
    std::string description;		//具体描述
	MyTime start_time;		//日程的开始时间
	MyTime end_time;			//日程的结束时间
	Schedule* next;			//指向下一个日程
	Schedule* prev;			//指向上一个日程
public:
    Schedule(std::string name, std::string description, MyTime start_time, MyTime end_time, int flag);	//构造函数
	~Schedule();	//析构函数
	/*将信息传给QT层*/
    std::string return_name();					//返回日程名称
    std::string return_description();			//返回描述
	MyTime return_time();						//返回起始时间和结束时间

    /*删除日程节点*/
	bool delete_schedule(Schedule* head);	//删除日程

    /*Dao层接口*/
   ScheduleDao toDaoItem();
   Schedule(ScheduleDao& item);
};


#endif
