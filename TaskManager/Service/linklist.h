#ifndef LINKLIST_H
#define LINKLIST_H
#include<QDebug>
/*链表的节点*/
template<class DataType>
struct Node
{
    DataType* data;  //指向数据节点的指针
    Node<DataType> *next;  //指向下一个链表节点
};
/*链表*/
template<class DataType>
class Linklist
{
public:
    Linklist();
    ~Linklist();
    bool isEmpty();   //链表判空
    bool InsertDataAtHead(DataType* pdata);
    bool InsertDataAtRear(DataType* pdata);
    bool DeleteElement(Node<DataType>* deletenode);              //删除节点
    bool DeleteData(DataType* deletenode);              //删除节点
    bool CleanList();  //清空链表
public:
    Node<DataType> *head;
};


/*构造函数：初始化链表（带头节点）*/
template<class DataType>
Linklist<DataType>::Linklist()
{
    head = new Node<DataType>;
    head->data=nullptr;//头结点不存放数据
    head->next=nullptr;
}
/*析构函数：删除所有节点*/
template<class DataType>
Linklist<DataType>::~Linklist()
{
    Node<DataType>* p = head;
    Node<DataType>* deletep=p->next;
    while(p->next){
        p->data->~DataType(); //删数据
        p->next=deletep->next;
        delete(deletep);  //删链表节点
        deletep=p->next;
    }
}
/*增：头插法*/
template<class DataType>
bool Linklist<DataType>::InsertDataAtHead(DataType* pdata)
{
    //创建链表节点并插入数据
    Node<DataType>* newnode = new Node<DataType>;
    if(newnode==nullptr) return false;
    newnode->data=pdata;
    newnode->next=head->next;
    head->next= newnode;
    return true;
}
/*增：尾插法*/
template<class DataType>
bool Linklist<DataType>::InsertDataAtRear(DataType* pdata)
{
    //寻找链尾
    Node<DataType>* p=head;
    while(p->next!=nullptr)  p=p->next;
    //创建链表节点并插入数据
    Node<DataType>* newnode = new Node<DataType>;
    if(newnode==nullptr) return false;
    newnode->data=pdata;
    newnode->next=p->next;
    p->next= newnode;
    return true;
}
/*删：按指针寻找*/
template<class DataType>
bool Linklist<DataType>::DeleteElement(Node<DataType>* deletenode)
{
    //寻找父节点
    Node<DataType>* p=head;
    while(p->next){
        if(p->next==deletenode){
            p->next=p->next->next;
            deletenode->data->~DataType();  //删数据节点
            delete(deletenode);  //删链表节点
            return true;
        }
        else {
            p=p->next;
        }
    }
    return false;
}
/*删：按数据寻找*/
template<class DataType>
bool Linklist<DataType>::DeleteData(DataType* deletenode)
{
    //寻找父节点
    Node<DataType>* p=head;
    Node<DataType>* deletep=nullptr;
    while(p->next){
        if(p->next->data==deletenode){
            deletep=p->next;
            p->next=p->next->next;
            deletenode->~DataType();  //删数据节点
            delete(deletep);  //删链表节点
            return true;
        }
        else {
            p=p->next;
        }
    }
    return false;
}
/*删：清空链表*/
template<class DataType>
bool Linklist<DataType>::CleanList()
{
    //仅用于Dao层清空
    Node<DataType>* p = head;
    Node<DataType>* deletep=p->next;
    while(p->next){
        delete(deletep->data); //删数据
        p->next=deletep->next;
        delete(deletep);  //删链表节点
        deletep=p->next;
    }
}





#endif // LINKLIST_H
