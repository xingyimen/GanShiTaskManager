#include "graphicsitem.h"
#include <QGraphicsWidget>
#include <QWidget>
#include <QPainter>


GraphicsItem::GraphicsItem(QGraphicsItem *parent)
    :QGraphicsObject(parent)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    type=GraphicsItem::Rect;  //节点类型（根/孩子）
    flag=GraphicsItem::Yellow;    //状态（在读/未读/已读）
    title="哈哈哈哈哈哈哈哈";  //打印的文字
    length=title.length();//获取长度
}
//测试
GraphicsItem::GraphicsItem(int t_type,int t_flag,QString t_title)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    type=t_type;
    flag=t_flag;
    title=t_title;
    length=title.length();//获取长度
}

GraphicsItem::~GraphicsItem(){


}

QRectF GraphicsItem::boundingRect() const
{
    if(length<=6)  return QRectF(-80,-30,160,60);
    else return QRectF(-80-(length-6)*10,-30,160+(length-6)*20,60);  //多一个字长20
}

void GraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);
    QPen pen;
    QBrush brush;
    pen.setWidth(3);
    //设置颜色
    if(flag==GraphicsItem::Gray) {
        pen.setColor(Qt::gray);
        brush=Qt::gray;
    }
    else if(flag==GraphicsItem::Yellow){
        pen.setColor(QColor(255,192,0));
        brush=Qt::white;
    }
    else if(flag==GraphicsItem::Blue){
        pen.setColor(QColor(113,192,245));
        brush=Qt::white;
    }
    painter->setBrush(brush);
    painter->setPen(pen);


    //设置形状
    if(type==GraphicsItem::RoundedRect){
        painter->drawRoundedRect(boundingRect(),5,5);
    }
    else {
        painter->drawRect(boundingRect());
    }
    //设置文字
    pen.setColor(Qt::black);
    QFont ft;
    ft.setFamily("Segoe UI");
    ft.setWeight(QFont::Medium);
    ft.setPointSize(15);
    painter->setFont(ft);
    painter->setPen(pen);
    painter->drawText(boundingRect(),Qt::AlignCenter,title);
}
