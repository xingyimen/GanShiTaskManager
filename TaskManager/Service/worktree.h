#ifndef WORKTREE_H
#define WORKTREE_H

#include <string>
#include "daodata.h"

class WorkTree {  //�������ڵĽڵ㣨����鿴��
public:
	enum {Root, Child};
	enum {Index,Book};
	enum {Finish, Unfinished, Reading};
private:
    int id;					//�ڵ�id
	int root_node_type;		//�����Ǹ��ӵ㻹�Ǻ��ӽڵ�(0Root,1Child)
	std::string book;		//�ڵ����� 
	int node_type;			//�ڵ����ͣ�0����Index��1��book��
	int flag;				//�ڵ�״̬��0δ��Unfinished��1�ڶ�Reading��2�Ѷ�Finish��
	WorkTree* sibling;		//ָ���ֵ�
	WorkTree* child;		//ָ����
public:
	/*������������(���Ĳ���)*/
	WorkTree(); //Ĭ�Ϲ��캯����Ĭ��Ϊ���ӽڵ㡢�顢δ��������δ������
	WorkTree(std::string name);   //���캯�����������ƣ����ڵ�����Ĭ�ϸ���Ĭ��δ����Ĭ��������
	WorkTree(std::string name,int qttype);   //���캯��������ڵ����ơ��ڵ����ͣ�����/�飩����Ĭ�Ϻ��ӡ�Ĭ��δ����
	~WorkTree();

	/*�ṩ��Qt������������ʾ�Ľӿ�*/
	std::string return_progress();//����Ŀǰ�ڶ������������ṩ������
	std::string return_root();//���ظ��ڵ����ơ����ṩ������
	/*����ɾ��*/
	bool delete_node(WorkTree&);  //ɾ���ӽڵ�
	bool delete_tree(WorkTree&);  //ɾ��������
    /*Dao��ӿ�*/
   WorkflowDao toDaoItem();
   WorkTree(WorkflowDao& item);



};
#endif // !WORKFLOW

