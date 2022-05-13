#ifndef WORKCHILD_H
#define WORKCHILD_H
#include <QPushButton>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <QGraphicsLinearLayout>
#include "daodata.h"
#include "linklist.h"

class WorkChild : public QPushButton
{
    Q_OBJECT
public:
    enum {Root, Child};
    enum {Index,Book};
    enum {Unfinished, Reading, Finish};
public:
    WorkChild(QString name,QWidget *parent = nullptr);
    WorkChild(QString name,int qttype,WorkChild* parent_node,QWidget *parent = nullptr);
    ~WorkChild();
    void initNode(WorkChild* parent_node = nullptr);
    void RefleshFlag();
    void AddChild();
    void CheckChoose();
    void QuestFlag();
    void RefleshPos(WorkChild* parentnode);
    void first_RefleshPos();
    void secend_RefleshPos(double& floor);
    void third_Refleshline();






    QGraphicsWidget* return_showitem(){return showitem;}
    QGraphicsScene* return_scene(){return scenep;}
    int return_root_node_type(){return root_node_type;}

    /*原WorkTree方法*/
    /*提供给Qt工作流界面显示的接口*/
    QString return_progress();//返回目前在读的书名——提供给描述
    QString return_progress_check(QString& heroNode);
    QString return_name();//返回根节点名称——提供给标题
    /*树的删除*/
    bool delete_node(WorkChild*& root, int key);  //删除子节点
    void delete_tree();  //删除整棵树
    /*Dao层接口*/
    void toDaoItem();
    WorkChild(WorkflowDao* item,WorkChild* par=nullptr);

    void ChangeFlag(WorkChild* item,int flag);
    void changereading(WorkChild* item, bool& readingflag);
    void changefinish(WorkChild* item, bool& finishflag);
    void getdeepth();
    void addLine(WorkChild* parent_node);
    void RefleshLinePos(WorkChild* parent_node);
    void RefleshLineColor();
private:
    /*原worktree节点*/
    int id;					//节点id
    int root_node_type;		//接受是根接点还是孩子节点(0Root,1Child)
    QString name;		//节点名称
    int node_type;			//节点类型（0索引Index、1书book）
    int flag;				//节点状态（0未读Unfinished、1在读Reading、2已读Finish）
    WorkChild* sibling;		//指向兄弟
    WorkChild* child;		//指向孩子
    /*原workchild节点*/
    QPointF point;  //打印的坐标点
    int length;  //记录文字长度，用来调整节点大小
    int child_num;
    QGraphicsWidget* showitem;   //指向当前显示item
    bool selectflag;
    QGraphicsScene* scenep;   //指向打印场景
    int deepth;  //记录深度

    QGraphicsPathItem* line;




signals:

};

#endif // WORKCHILD_H
