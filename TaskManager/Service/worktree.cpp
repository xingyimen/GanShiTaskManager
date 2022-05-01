#include"worktree.h"
WorkTree::WorkTree() {
	//默认构造函数（默认为孩子节点、书、未读、名称未命名）
	root_node_type = WorkTree::Child;
	node_type = WorkTree::Book;
	flag = WorkTree::Unfinished;
	std::string name("未命名");
}

WorkTree::WorkTree(std::string name) {
	//构造函数（传入名称）（节点类型默认根、默认未读、默认索引）
	root_node_type = WorkTree::Root;
	node_type = WorkTree::Index;
	flag = WorkTree::Unfinished;
    //std::string name;
}

WorkTree::WorkTree(std::string name, int qttype) {
	//构造函数（传入节点名称、节点类型（索引/书））（默认孩子、默认未读）
	root_node_type = WorkTree::Child;
	flag = WorkTree::Unfinished;
	node_type = qttype;					//传入的节点类型
    //std::string name;
}

WorkTree::~WorkTree() {

}

/*Dao层接口*/
WorkflowDao WorkTree::toDaoItem()
{
    //所有数据转string
    WorkflowDao daoitem;

}
WorkTree::WorkTree(WorkflowDao& daoitem)
{
    //string转数据

}
/*从数组中*/







/*
WorkTree operator=(const Json& item) {
	//从Json中导入数据
	int i = 0;
	int p = 0;

	while (i < sizeof(item) / sizeof(item[0])) {
		if (item[i].root_node_type == WorkTree::Root) {
			return item[i];
			i++;
			if (item[i].node_type == WorkTree::Index) {
				item[i - 1].child = &item[i];
				p = i;
				i++;
				if (item[i].node_type == WorkTree::Book) {
					item[i - 1].child = &item[i];
					i++;
					if (item[i].node_type == WorkTree::Book) {
						item[i - 1].sibing = &item[i];
						i++;
					}
				}
				else {
					item[i - 1].sibling = &item[i];
					i++;
				}
			}
		}
	}
	

}    
*/
/*提供给Qt工作流界面显示的接口*/
std::string return_progress() {
	//返回目前在读的书名——提供给描述

}
std::string return_root() {
	//返回根节点名称——提供给标题
}

/*树的删除*/
bool delete_node(WorkTree&) {
	//删除子节点,删去左子树，将右子树让上提

}  
bool delete_tree(WorkTree&) {
	//删除整棵树


} 
