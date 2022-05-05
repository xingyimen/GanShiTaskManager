#include"worktree.h"
#include<QDebug>
#include "myjsonobject.h"

extern int IDWorkTree=1; //从Json读出断点记录
extern Linklist<WorkflowDao>* WorkDaoList;  //全局变量，装载日程的链表
extern Linklist<WorkTree>* worklist; /*全局变量WorkTree的链表*/

WorkTree::WorkTree() {
    //默认构造函数（默认为孩子节点、书、未读、名称未命名）
    id=IDWorkTree++;
    root_node_type = WorkTree::Child;
    node_type = WorkTree::Book;
    flag = WorkTree::Unfinished;
    book="未命名";
}
/*根节点*/
WorkTree::WorkTree(std::string name) {
    qDebug()<<"WorkTree create";
    //构造函数（传入名称）（节点类型默认根、默认未读、默认索引）
    id=IDWorkTree++;
    root_node_type = WorkTree::Root;
    node_type = WorkTree::Index;
    flag = WorkTree::Unfinished;
    book=name;
    sibling=nullptr;
    child=nullptr;
}

WorkTree::WorkTree(WorkTree& parent,std::string name, int qttype) {
    //构造函数（传入节点名称、节点类型（索引/书））（默认孩子、默认未读）
    id=IDWorkTree++;
    root_node_type = WorkTree::Child;
    flag = WorkTree::Unfinished;
    node_type = qttype;					//传入的节点类型
    this->child=nullptr;
    book = name;
    WorkTree* p =&parent;
    if(parent.child){
        this->sibling=parent.child;
        parent.child=this;
    }
    else {
        this->sibling=nullptr;
        parent.child=this;
    }
}


WorkTree::~WorkTree() {
   qDebug()<<"析构WorkTree";
}

/*Dao层接口*/
WorkflowDao WorkTree::toDaoItem()
{
    //所有数据转string,
        //转出？
        WorkflowDao daoitem;
        //字符串=整形
        daoitem.id = std::to_string(id);
        daoitem.root_node_type = std::to_string(root_node_type);
        daoitem.book = book;
        daoitem.node_type = std::to_string(node_type);
        daoitem.flag = std::to_string(flag);
        daoitem.child = std::to_string(this->child->id);
        daoitem.sibling = std::to_string(this->sibling->id);
}
WorkTree::WorkTree(WorkflowDao& daoitem)
{
    //string转数据
        //转入？
        id = atoi(daoitem.id.c_str());
        root_node_type = atoi(daoitem.root_node_type.c_str());
        book = daoitem.book;
        node_type = atoi(daoitem.node_type.c_str());
        flag = atoi(daoitem.flag.c_str());
        child=nullptr;
        sibling=nullptr;
}
void SaveWorkflow(){
    /*存储所有Workflow数据*/
    /*
    1、worklist是一个单链表，里面存储了所有的根节点
    2、（1）需要存储以根节点为首的整个树的所有节点（2）需要存储所有根节点
    3、存储代码如下
    MyJsonObject json;     //创建一个Dao层对象
    WorkflowDao a=(遍历到的节点).toDaoItem;   //把WorkTree转化为WorkflowDao
    json.writeJson(a)   //把WorkflowDao写入Json
    */

}
void GetWorkflow(){
    /*从WorkDaoListt全局变量链表中读出数据*/
    /*
    1、WorkDaoList存储了所有的从Json文件中读取出来的WorkflowDao节点（可能包含多颗树）
    2、（1）遍历WorkDaoList链表取出所有节点并连接成树（2）把所有根节点连接到worklist
    3、调用WorkDaoList->CleanList()清空链表
    */





}
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
//一定是根节点调用
std::string WorkTree::return_progress() {
    //返回目前在读的书名——提供给描述
    if (this->child!=nullptr) {
        if (this->flag == WorkTree::Reading) {
            return this->book;
        }
        else {
            this->child->return_progress();
            this->sibling->return_progress();
        }
    }
    else {
        return "null";
    }

}

//一定是根节点调用
std::string WorkTree::return_root() {
   return book;
}

/*树的删除*/
bool WorkTree::delete_node(WorkTree*& root, int key) {

    //删除子节点,删去左子树，将右子树让上提
    while (root) {
            if (root->id > key) {
                return delete_node(root->sibling, key);
            }
            else if (root->id < key)
            {
                return delete_node(root->child, key);
            }//找到待删除节点
            else {
                WorkTree* parent = NULL;
                //叶子结点
                if (root->child == NULL && root->sibling == NULL) {
                    delete root;
                }
                //只有孩子
                else if (root->sibling == NULL && root->child != NULL) {
                    delete root;
                }
                //只有兄弟
                else if (root->child == NULL) {
                    if (parent->sibling == root) {
                        parent->sibling = root->sibling;
                    }
                    else if (parent->child == root) {
                        parent->child = root->sibling;
                    }
                }
                //孩子兄弟都存在
                else {
                    if (parent->sibling == root) {
                        parent->sibling = root->sibling;
                    }
                    else if (parent->child == root) {
                        parent->child = root->sibling;
                    }
                }
                return true;
            }
        }
        return false;

}


void WorkTree::delete_tree() {
    //删除整棵树
    if(this->sibling)  this->sibling->delete_tree();
    if(this->child)  this->child->delete_tree();
    this->~WorkTree();
}


