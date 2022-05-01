#ifndef PROMODOROCLOCK_H
#define PROMODOROCLOCK_H
#include "mytime.h"
#include<iostream>
//#include<bits/stdc++.h>
class PromodoroClock
{
private:
    std::string name;			//日程名称
    std::string description;		//具体描述
    int tomato;				//番茄时间
    int rest;				//休息时间
public:
    PromodoroClock();
    PromodoroClock(std::string name, std::string description, int tomato = 25, int rest = 5);	//构造函数（默认描述：略，一个番茄时间：25min，休息时间：5min）
    std::string return_name();	//返回日程名称
    std::string return_description();	//返回具体描述
    std::pair<int, int> return_time();	//返回{tomato,rest}
};

#endif // PROMODOROCLOCK_H
