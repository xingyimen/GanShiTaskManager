#include "schedule.h"

//日程类
/*
构造函数：
【参数】
string name：日程名称
string description：日程的具体描述
Time start_time：日程的开始时间
Time end_time：日程的结束时间
int flag：用于判断用户是否从工作流中获取日程名称，如果从工作流中获取flag=1，如果直接输入名称flag=2
*/
Schedule::Schedule(std::string name, std::string description, MyTime start_time, MyTime end_time, int flag)
{

}

/*
析构函数
*/
Schedule::~Schedule(){

}

/*
从Json中导入数据
*/
//Schedule::Schedule operator=(const Json& item)
//{

//}

/*
返回日程的名称
*/
std::string Schedule::return_name()
{

}

/*
返回日程的具体描述
*/
std::string Schedule::return_description()
{

}

/*
返回日程的开始和结束时间
*/
MyTime Schedule::return_time()
{

}

/*
删除日程：
【参数】
Schedule* head：所有日程的头指针即头指针指向的下一个是第一个日程
【步骤】
1、将该日程的上一个日程和下一个日程进行连接
2、释放该日程的内存
3、返回是否删除成功，成功返回true，失败返回false
*/
bool delete_schedule(Schedule* head)
{

}




/*Dao层接口*/
ScheduleDao Schedule::toDaoItem()
{
    //所有数据转string
    ScheduleDao daoitem;

}

Schedule::Schedule(ScheduleDao& daoitem)
{
    //string转数据

}

