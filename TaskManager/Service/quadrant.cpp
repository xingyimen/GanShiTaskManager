#include"quadrant.h"
#include "linklist.h"
#include<QDebug>
#include<QString>

/*获取系统时间*/
extern MyTime GetTime();
extern MyDate GetDate();


int IDQuadrant=1;  //ID
extern Linklist<QuadrantDao>* QuadDaoList;

int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
//增加天数
void add_day(MyDate& temp, int k)
{
    temp.day += k;  //加上k天
    int leap = (temp.year % 100 && temp.year % 4 == 0) || temp.year % 400 == 0; //判断是否为闰年
    //判断日数是否超过
    if (temp.month == 2 && temp.day > months[2] + leap)
    {
        temp.day -= (months[2] + leap);
        ++temp.month;
    }
    else if (temp.day > months[temp.month])
    {
        temp.day -= months[temp.month] ;
        ++temp.month;
    }
    //判断月份是否超过
    if (temp.month > 12)
    {
        temp.month = 0;
        ++temp.year;
    }
}

//计算当前时间距离截止时间还有多久
int dis_time(MyTime new_time, MyDate new_date, MyTime end_time, MyDate end_date)
{
    int n_minute = new_time.minute, n_hour = new_time.hour;
    int n_year = new_date.year, n_month = new_date.month, n_day = new_date.day;
    int cnt = 0;    //距离截止时间的总分钟
    //判断当前时间是否已经超过截止时间
    if (end_date.year < n_year || (end_date.year == n_year && end_date.month < n_month)
        || (end_date.year == n_year && end_date.month == n_month && end_date.day < n_day))
    {
        return -1;
    }
    //计算距离截止时间还有多少分钟
    int max_minute = 8 * 24 * 60;
    while (cnt <= max_minute)
    {
        ++cnt;
        ++n_minute;
        if (n_minute == 60)
        {
            n_minute = 0;
            ++n_hour;
            if (n_hour == 24)
            {
                n_hour = 0;
                ++n_day;
                add_day(new_date, 1);
                n_year = new_date.year, n_month = new_date.month, n_day = new_date.day;
            }
        }
        //如果已经遍历到截止时间，就返回统计的分钟
        if (n_year == end_date.year && n_month == end_date.month && n_day == end_date.day
            && n_hour == end_time.hour && n_minute == end_time.minute)
            return cnt;
    }
    return -1;
}


/*
构造函数：
要在构造时计算出截止时间，截止时间计算是判断里最右即第8格差多少格，差多少格就将获取的时间加上多少天（最多7天）
【参数】
int rol：任务在象限的横坐标第几格
int col：任务在象限的纵坐标第几格
string description：任务的具体描述
Time now：当前操作时间
*/
Quadrant::Quadrant()
{

}
Quadrant::Quadrant(int q_rol, int q_col,MyDate end_date, MyTime end_time,std::string q_name, std::string q_description)
{
    this->rol = q_rol;
    this->col = q_col;
    this->name=(q_name=="")? "未命名":q_name;
    this->description=(q_description=="")? "略":q_description;
    //int dis = 8 - q_rol;    //距离截止时间还有多少天
    this->now = GetTime();
    this->end_date = end_date;
    //add_day(this->end_date, dis);
    this->end_time=end_time;
    this->id=IDQuadrant++;
}
//从工作流中读入数据
Quadrant::Quadrant(int q_rol, int q_col,MyDate end_date, MyTime end_time,  WorkChild* item)
{

}
/*
析构函数
*/
Quadrant::~Quadrant()
{
    qDebug()<<"删除Quadrant"<<name.c_str();
}

/*
返回日程名称
*/
std::string Quadrant::return_name()
{
    return this->name;
}

/*
返回具体描述
*/
std::string Quadrant::return_description()
{
    return this->description;
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
bool Quadrant::update()
{
    MyTime new_time=GetTime();
    MyDate new_date=GetDate();
    int n_hour = new_time.hour, n_minute = new_time.minute;
    int n_year = new_date.year, n_month = new_date.month, n_day = new_date.day;
    //如果当前时间距离
    int dis = dis_time(new_time, new_date, this->end_time, this->end_date);
    //如果超过截止时间，返回true提示要删除该任务
    if (dis == -1)
        return true;
    //否则，更新坐标
    else
    {
        this->rol = 7 - dis / 1440;
        return false;
    }
}

/*Dao层接口*/
void Quadrant::toDaoItem()
{
    //所有数据转string
    QuadrantDao* daoitem=new(QuadrantDao);
    //字符串=整形
    daoitem->id = std::to_string(id);
    daoitem->name = name;
    daoitem->description = description;
    daoitem->col = std::to_string(col);
    daoitem->rol = std::to_string(rol);
    daoitem->end_time = end_time.toString();
    daoitem->end_date = end_date.toString();
    QuadDaoList->InsertDataAtHead(daoitem);
}

Quadrant::Quadrant(QuadrantDao* daoitem)
{
    //string转数据
    id = IDQuadrant++;
    name = daoitem->name;
    description = daoitem->description;
    col = atoi(daoitem->col.c_str());
    rol = atoi(daoitem->rol.c_str());
    end_time.getData(daoitem->end_time);
    end_date.getData(daoitem->end_date);
}
