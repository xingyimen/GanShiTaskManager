#ifndef MYTIME_H
#define MYTIME_H

#include<string>

class MyTime
{
private:
    int hour;	//小时
    int mintue;	//分钟
    int second;	//秒
public:
    MyTime();
    MyTime(int hout, int minute,int second=0);				//构造函数(类型默认为时间)
    ~MyTime();	//析构函数
    std::string toString();  //转化为字符串
    void getData(std::string& str);   //字符串转化为数字
};

class MyDate
{
private:
    int year;	//年
    int month;	//月
    int day;	//日
public:
    MyDate();
    MyDate(int year, int month, int day);		//构造函数(类型为日期，hour和minute默认为0)
    ~MyDate();	//析构函数
    std::string toString();   //转化为字符串
    void getData(std::string& str);   //字符串转化为数字
};


#endif // MYTIME_H
