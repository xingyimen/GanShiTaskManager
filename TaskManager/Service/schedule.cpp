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
Schedule::Schedule(std::string q_name, std::string q_description, MyTime q_start_time, MyTime q_end_time)
{
    name=q_name;



}

Schedule::Schedule(WorkTree& item, MyTime start_time, MyTime end_time){
/*从工作流导入数据*/


}

Schedule::Schedule(Quadrant& item, MyTime start_time, MyTime end_time){
/*从四象限导入数据*/


}

Schedule::~Schedule(){

}
/*Dao层接口*/
ScheduleDao Schedule::toDaoItem()
{
    ScheduleDao daoitem;
    /*所有数据转string*/
    return daoitem;
}

Schedule::Schedule(ScheduleDao& daoitem)
{
    /*string转数据*/

}

