#ifndef WORKITEM_H
#define WORKITEM_H

#include <QWidget>

namespace Ui {
class WorkItem;
}

class WorkItem : public QWidget
{
    Q_OBJECT

public:
    explicit WorkItem(QWidget *parent = nullptr);
    void CheckQuestTree();
    ~WorkItem();

private:
    Ui::WorkItem *ui;
    QString title;
    QString description;
};

#endif // WORKITEM_H
