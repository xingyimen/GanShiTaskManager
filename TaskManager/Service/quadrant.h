#ifndef QUADRANT_H
#define QUADRANT_H
#include"worktree.h"
#include<iostream>
#include<string>
#include "mytime.h"
#include "daodata.h"

class Quadrant
{
private:
    int rol;					//任务在象限的横坐标
    int col;					//任务在象限的纵坐标
    std::string name;			//任务名称
    std::string description;	//具体描述
    MyTime now;					//时间
    MyTime end_time;			//截止时间
    MyDate end_date;			//截止日期
public:
    Quadrant();
    Quadrant(int q_rol, int q_col,MyDate end_date, MyTime end_time, std::string name, std::string description);		//构造函数
    Quadrant(int q_rol, int q_col,MyDate end_date, MyTime end_time, WorkTree& item);  //从工作流中读入数据
    ~Quadrant();	//析构函数
    /*将信息传给QT层*/
    int return_rol(){return rol;}
    int return_col(){return col;}
    std::string return_name();		//返回日程名称
    std::string return_description();//返回具体描述
    MyDate return_enddate(){return end_date;}
    MyTime return_endtime(){return end_time;}



    /*更新时间*/
    bool update();	//更新时间

    /*Dao层接口*/
   QuadrantDao toDaoItem();
   Quadrant(QuadrantDao& item);

};

#endif
