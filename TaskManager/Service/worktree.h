#ifndef WORKTREE_H
#define WORKTREE_H

#include <string>
#include "daodata.h"

class WorkTree {  //任务树内的节点（点击查看后）
public:
	enum {Root, Child};
	enum {Index,Book};
	enum {Finish, Unfinished, Reading};
private:
    int id;					//节点id
	int root_node_type;		//接受是根接点还是孩子节点(0Root,1Child)
	std::string book;		//节点名称 
	int node_type;			//节点类型（0索引Index、1书book）
	int flag;				//节点状态（0未读Unfinished、1在读Reading、2已读Finish）
	WorkTree* sibling;		//指向兄弟
	WorkTree* child;		//指向孩子
public:
	/*构造析构复制(树的插入)*/
	WorkTree(); //默认构造函数（默认为孩子节点、书、未读、名称未命名）
	WorkTree(std::string name);   //构造函数（传入名称）（节点类型默认根、默认未读、默认索引）
	WorkTree(std::string name,int qttype);   //构造函数（传入节点名称、节点类型（索引/书））（默认孩子、默认未读）
	~WorkTree();

	/*提供给Qt工作流界面显示的接口*/
	std::string return_progress();//返回目前在读的书名——提供给描述
	std::string return_root();//返回根节点名称——提供给标题
	/*树的删除*/
	bool delete_node(WorkTree&);  //删除子节点
	bool delete_tree(WorkTree&);  //删除整棵树
    /*Dao层接口*/
   WorkflowDao toDaoItem();
   WorkTree(WorkflowDao& item);



};
#endif // !WORKFLOW

