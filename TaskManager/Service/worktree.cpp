#include"worktree.h"
WorkTree::WorkTree() {
	//Ĭ�Ϲ��캯����Ĭ��Ϊ���ӽڵ㡢�顢δ��������δ������
	root_node_type = WorkTree::Child;
	node_type = WorkTree::Book;
	flag = WorkTree::Unfinished;
	std::string name("δ����");
}

WorkTree::WorkTree(std::string name) {
	//���캯�����������ƣ����ڵ�����Ĭ�ϸ���Ĭ��δ����Ĭ��������
	root_node_type = WorkTree::Root;
	node_type = WorkTree::Index;
	flag = WorkTree::Unfinished;
    //std::string name;
}

WorkTree::WorkTree(std::string name, int qttype) {
	//���캯��������ڵ����ơ��ڵ����ͣ�����/�飩����Ĭ�Ϻ��ӡ�Ĭ��δ����
	root_node_type = WorkTree::Child;
	flag = WorkTree::Unfinished;
	node_type = qttype;					//����Ľڵ�����
    //std::string name;
}

WorkTree::~WorkTree() {

}

/*Dao��ӿ�*/
WorkflowDao WorkTree::toDaoItem()
{
    //��������תstring
    WorkflowDao daoitem;

}
WorkTree::WorkTree(WorkflowDao& daoitem)
{
    //stringת����

}
/*��������*/







/*
WorkTree operator=(const Json& item) {
	//��Json�е�������
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
/*�ṩ��Qt������������ʾ�Ľӿ�*/
std::string return_progress() {
	//����Ŀǰ�ڶ������������ṩ������

}
std::string return_root() {
	//���ظ��ڵ����ơ����ṩ������
}

/*����ɾ��*/
bool delete_node(WorkTree&) {
	//ɾ���ӽڵ�,ɾȥ����������������������

}  
bool delete_tree(WorkTree&) {
	//ɾ��������


} 
