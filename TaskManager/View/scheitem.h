#ifndef SCHEITEM_H
#define SCHEITEM_H
#include "schedule.h"
#include <QWidget>
#include <QTime>
#include <QPoint>
namespace Ui {
class ScheItem;
}

class ScheItem : public QWidget,public Schedule
{
    Q_OBJECT

public:
    explicit ScheItem(QString title, QString description,QTime starttime,QTime endtime,QWidget *parent = nullptr);
    ~ScheItem();
    void Reflesh(QPoint* point);
private:
    Ui::ScheItem *ui; 
};

#endif // SCHEITEM_H
