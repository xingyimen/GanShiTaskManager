#include "mytime.h"


//时间类

/*
默认构造函数
*/
MyTime::MyTime()
{

}

/*
构造函数：
如果传入的是三个参数，自动定位到这个构造函数，将三个参数分别赋值给年月日
*/
MyTime::MyTime(int hour, int minute, int second)
{
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

/*
析构函数
*/
MyTime::~MyTime()
{

}

//日期类

/*
默认构造函数
*/
MyDate::MyDate()
{

}

/*
构造函数：
如果传入的是两个参数，自动定位到这个构造函数，将两个参数分别赋值给小时和分钟
*/
MyDate::MyDate(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

/*
析构函数
*/
MyDate::~MyDate()
{

}


/*
数据格式转换
*/
//转化为字符串
std::string MyDate::toString()
{
    std::string date=std::to_string(year);
    std::string m=std::to_string(month);
    if(m.size()==1)
        date+='0'+m;
    else
        date+=m;
    std::string d=std::to_string(day);
    if(d.size()==1)
        date+='0'+d;
    else
        date+=d;
    return date;
}
std::string MyTime::toString()
{
    std::string mt="";
    std::string h=std::to_string(hour);
    std::string m=std::to_string(minute);
    if(h.size()==1)
        mt+='0'+h;
    else
        mt+=h;
    if(m.size()==1)
        mt+='0'+m;
    else
        mt+=m;
    return mt;
}
//字符串转化为数字
void MyDate::getData(std::string& str)
{
    const char* p=str.c_str();
    year=atoi(p)/10000;
    month=atoi(p)%10000/100;
    day=atoi(p)%100;
}
void MyTime::getData(std::string& str)
{
    const char* p=str.c_str();
    hour=atoi(p)/100;
    minute=atoi(p)%100;
}





