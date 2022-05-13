#ifndef WORKITEM_H
#define WORKITEM_H
#include<QDebug>
#include <QWidget>
#include "workchild.h"
#include "graphicsview.h"
namespace Ui {
class WorkItem;
}

class WorkItem : public QWidget
{
    Q_OBJECT

public:
    explicit WorkItem(WorkChild* root,QWidget *parent = nullptr);
    ~WorkItem();
    void CheckQuestTree();    //点击查看
    void Reflesh(QPoint point);   //刷新WorkItem打印位置
    void Check();                 //查看WorkItem信息
    void ShowScene();             //显示场景
    WorkChild* return_child(){return rootp;}


private:
    Ui::WorkItem *ui;
    WorkChild* rootp;        //指向同数据的根节点
    QGraphicsScene* scenep;   //指向打印场景
protected:
    virtual void mousePressEvent(QMouseEvent *event);

};

#endif // WORKITEM_H
