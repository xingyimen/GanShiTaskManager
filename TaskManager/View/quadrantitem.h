#ifndef QUADRANTITEM_H
#define QUADRANTITEM_H

#include <QWidget>
#include"quadrant.h"
#include <QDateTime>
namespace Ui {
class QuadrantItem;
}

class QuadrantItem : public QWidget,public Quadrant
{
    Q_OBJECT

public:
    explicit QuadrantItem(int x, int y,QDateTime dt, QString name, QString description,QWidget *parent = nullptr);
    ~QuadrantItem();
    void Reflesh();
    void Check();

private:
    Ui::QuadrantItem *ui;

};

#endif // QUADRANTITEM_H
