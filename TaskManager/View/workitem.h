#ifndef WORKITEM_H
#define WORKITEM_H
#include<QDebug>
#include <QWidget>
#include"worktree.h"
namespace Ui {
class WorkItem;
}

class WorkItem : public QWidget,public WorkTree
{
    Q_OBJECT

public:
    explicit WorkItem(QString title,QWidget *parent = nullptr);
    void CheckQuestTree();
    ~WorkItem();
    void Reflesh(QPoint point);
private:
    Ui::WorkItem *ui;


};

#endif // WORKITEM_H
