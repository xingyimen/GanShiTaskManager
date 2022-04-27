#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>

class GraphicsItem: public QGraphicsRectItem
{
//private:
    //QGraphicsRectItem rect;
    //QGraphicsSimpleTextItem text;
public:
    GraphicsItem();/*来自Service的数据：名字+状态*/
};

#endif // GRAPHICSITEM_H
