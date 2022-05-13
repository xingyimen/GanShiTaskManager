#ifndef DAODATA_H
#define DAODATA_H

#include <string>
#include "linklist.h"
/*****日程数据*****/
typedef struct ScheduleDao{
    std::string id;                 //节点id
    std::string theme;              //名称
    std::string describe;           //描述
    std::string start_time;           //开始时间
    std::string end_time;            //结束日期
}ScheduleDao;
/*****四象限数据*****/
typedef struct QuadrantDao{
    std::string id;                 //id
    std::string rol;				//任务在象限的横坐标
    std::string col;				//任务在象限的纵坐标
    std::string name;		     	//任务名称
    std::string description;		//具体描述
    std::string end_time;			//截止时间
    std::string end_date;           //截止日期
}QuadrantDao;
/*****数据报表数据*****/
typedef struct DatagramDao{
    std::string id;         //id
    std::string name;		//完成的科目名称
    std::string date;      //日期
    std::string start_time;	//开始时间
    std::string finish_time;	//结束时间
}DatagramDao;
/*****任务树数据*****/
typedef struct WorkflowDao{
    QString id;					//节点id
    QString root_node_type;		//接受是根接点还是孩子节点(0Root,1Child)
    QString book;		//节点名称
    QString node_type;			//节点类型（0索引Index、1书book）
    QString flag;				//节点状态（0未读Unfinished、1在读Reading、2已读Finish）
    QString sibling;		//指向兄弟
    QString child;		//指向孩子
}WorkflowDao;
#endif // DAODATA_H







