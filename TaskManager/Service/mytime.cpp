#include "mytime.h"

MyTime::MyTime()
{

}
MyDate::MyDate()
{

}

//时间类
/*
构造函数：
如果传入的是三个参数，自动定位到这个构造函数，将三个参数分别赋值给年月日
*/
MyTime::MyTime(int year, int month, int day)
{

}

/*
构造函数：
如果传入的是两个参数，自动定位到这个构造函数，将两个参数分别赋值给小时和分钟
*/
MyDate::MyDate(int hout, int minute,int second)
{

}

/*
析构函数
*/
MyTime::~MyTime()
{

}
MyDate::~MyDate()
{

}
/*
数据格式转换
*/
//转化为字符串
std::string MyDate::toString()
{

}
std::string MyTime::toString()
{

}
//字符串转化为数字
void MyDate::getData(std::string& str)
{

}
void MyTime::getData(std::string& str)
{

}
