#ifndef QUADRANT_H
#define QUADRANT_H

#include<iostream>
#include<string>
#include "mytime.h"
#include "daodata.h"
class Quadrant
{
private:
	int rol;				//任务在象限的横坐标
	int col;				//任务在象限的纵坐标
    std::string name;			//任务名称
    std::string description;		//具体描述
	MyTime now;				//时间
	MyTime end_time;			//截止时间
public:
	Quadrant(int rol, int col, MyTime now);		//构造函数（默认任务名称：未命名，具体描述：略）
    Quadrant(int rol, int col, std::string name, std::string description, MyTime now);		//构造函数
	~Quadrant();	//析构函数
    //Quadrant operator=(const Json& item);   //从Json中导入数据
	/*将信息传给QT层*/
    std::string return_name();		//返回日程名称
    std::string return_description();//返回具体描述
	/*更新时间*/
    bool update(MyTime new_time);	//更新时间

    /*Dao层接口*/
   QuadrantDao toDaoItem();
   Quadrant(QuadrantDao& item);



};

#endif
