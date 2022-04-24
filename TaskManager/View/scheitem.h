#ifndef SCHEITEM_H
#define SCHEITEM_H

#include <QWidget>
#include <QTime>
namespace Ui {
class ScheItem;
}

class ScheItem : public QWidget
{
    Q_OBJECT

public:
    explicit ScheItem(QWidget *parent = nullptr);
    friend void setitem(/*自定义类*/);
    ~ScheItem();

private:
    Ui::ScheItem *ui;
    QTime starttime;
    QTime endtime;
    QString title;
    QString description;
};

#endif // SCHEITEM_H
