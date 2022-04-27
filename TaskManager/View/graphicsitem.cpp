#include "graphicsitem.h"
#include <QGraphicsView>
GraphicsItem::GraphicsItem()
{
    setFlag(QGraphicsItem::ItemIsMovable);
    QPen pen;   // 定义一个画笔，设置画笔颜色和宽度
    pen.setColor(QColor(0, 160, 230));
    pen.setWidth(10);
    setRect(0, 0, 80, 80);
    setPen(pen);
    setBrush(QBrush(QColor(255, 0, 255)));
//    QFont ft;
//    ft.setPointSize(18);
//    ft.setFamily("黑体");
//    text.setFont(ft);
//    text.setText("C++");



}
