#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H

#include <QGraphicsObject>
class GraphicsItem: public QGraphicsObject
{
    //Q_OBJECT
public:
    enum{RoundedRect,Rect};
    enum{Yellow,Blue,Gray};
public:
    GraphicsItem(QGraphicsItem *parent = nullptr);
    //和Service接口
    //GraphicsItem(WorkTree& item,QGraphicsItem *parent = nullptr);/*WorkTree& item*/
    //测试
    GraphicsItem(int t_type,int t_flag,QString t_title);
    ~GraphicsItem();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
private:
    int type;  //节点类型（根/孩子）
    int flag;    //状态（在读/未读/已读）
    QString title;  //打印的文字
    int length;  //记录文字长度，用来调整节点大小
};

#endif // GRAPHICSITEM_H
