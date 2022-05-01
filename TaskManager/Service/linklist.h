#ifndef LINKLIST_H
#define LINKLIST_H


template<class NodeType>
class Linklist
{
private:
    NodeType data;
    NodeType* next;
public:
    Linklist();
    bool isEmpty();
    bool AddElement(int id,int index);
    bool DeleteElement(int id);
    bool DeleteAllElement(int id);
};

#endif // LINKLIST_H
