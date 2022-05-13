#ifndef SCHEITEM_H
#define SCHEITEM_H
#include "schedule.h"
#include <QWidget>
#include <QTime>
#include <QPoint>
#include <QMouseEvent>
#include "mask.h"
#include <QLabel>
#include <QPushButton>

namespace Ui {
class ScheItem;
}

class MainWindow;

class ScheItem : public QWidget,public Schedule
{
    Q_OBJECT

public:
    explicit ScheItem(QString title, QString description,QTime starttime,QTime endtime,QWidget *parent = nullptr);
    explicit ScheItem(ScheduleDao* item,QWidget *parent = nullptr);
    ~ScheItem();
    void Reflesh(QPoint point);
    void Check();
protected:
    virtual void mousePressEvent(QMouseEvent *event);
private:
    Ui::ScheItem *ui; 
};

#endif // SCHEITEM_H
