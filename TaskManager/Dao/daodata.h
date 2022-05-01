#ifndef DAODATA_H
#define DAODATA_H

#include <string>
/*****数据报表数据*****/
typedef struct DatagramDao{
    std::string id;         //id
    std::string name;		//完成的科目名称
    std::string date;      //日期
    std::string start_time;	//开始时间
    std::string finish_time;	//结束时间
}DatagramDao;
/*****日程数据*****/
typedef struct ScheduleDao{
    std::string id;                 //id
    std::string rol;				//任务在象限的横坐标
    std::string col;				//任务在象限的纵坐标
    std::string name;		     	//任务名称
    std::string description;		//具体描述
    std::string now;				//时间
    std::string end_time;			//截止时间
}ScheduleDao;
/*****任务树数据*****/
typedef struct WorkflowDao{
    std::string id;					//节点id
    std::string root_node_type;		//接受是根接点还是孩子节点(0Root,1Child)
    std::string book;		//节点名称
    std::string node_type;			//节点类型（0索引Index、1书book）
    std::string flag;				//节点状态（0未读Unfinished、1在读Reading、2已读Finish）
    std::string sibling;		//指向兄弟
    std::string child;		//指向孩子
}WorkflowDao;
/*****四象限数据*****/
typedef struct QuadrantDao{
    std::string id;
    std::string theme;
    std::string describe;
    std::string start_time;
    std::string end_time;
}QuadrantDao;
#endif // DAODATA_H
