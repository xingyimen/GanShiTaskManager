#include"quadrant.h"


/*
构造函数：
默认任务名称：未命名，具体描述：略
要在构造时计算出截止时间，截止时间计算是判断里最右即第8格差多少格，差多少格就将获取的时间加上多少天（最多7天）
【参数】
int rol：任务在象限的横坐标
int col：任务在象限的纵坐标
Time now：当前操作时间
*/


Quadrant::Quadrant(int rol, int col, MyTime now)
{

}

/*
构造函数：
要在构造时计算出截止时间，截止时间计算是判断里最右即第8格差多少格，差多少格就将获取的时间加上多少天（最多7天）
【参数】
int rol：任务在象限的横坐标
int col：任务在象限的纵坐标
string description：任务的具体描述
Time now：当前操作时间
*/
Quadrant::Quadrant(int rol, int col, std::string name, std::string description, MyTime now)
{

}

/*
析构函数
*/
Quadrant::~Quadrant()
{}

/*
从Json中导入数据
*/
//Quadrant::Quadrant operator=(const Json& item)
//{

//}

/*
返回日程名称
*/
std::string return_name()
{

}

/*
返回具体描述
*/
std::string return_description()
{

}

/*
更新时间：
每次进入四象限页面时，更新一次任务的坐标
【参数】
Time new：当前操作的最新时间
【步骤】
1、将任务的截止时间减去传入的最新时间（日期界限判断要考虑时间，不能以24小时为界限，要看传入的时间）
（1）如果相差天数小于1天
提醒用户，任务具体截止时间不足一天
（2）如果相差天数大于1天
不发消息
（3）如果相差天数为负数
说明任务已经到达或超过截止时间，提醒用户任务已经结束，并且返回true，说明该任务要进行删除操作
2、如果任务没有结束，更新col即纵坐标，并且返回false
*/
bool update(MyTime new_time)
{

}

/*Dao层接口*/
QuadrantDao Quadrant::toDaoItem()
{
    //所有数据转string
    QuadrantDao daoitem;

}

Quadrant::Quadrant(QuadrantDao& daoitem)
{
    //string转数据

}


