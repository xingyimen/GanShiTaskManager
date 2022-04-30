#include "graphicsview.h"
#include <QWheelEvent>
#include <QDebug>
GraphicsView::GraphicsView(QWidget *parent)
    : QGraphicsView{parent}
{
    //设置样式表
    setDragMode(GraphicsView::ScrollHandDrag);
    resize(480,730);
    setStyleSheet("background-color : rgb(244, 244, 244)");
    setResizeAnchor(GraphicsView::AnchorUnderMouse);  //确定锚点为鼠标
    m_scalnum=1;
}


void GraphicsView::wheelEvent(QWheelEvent *event)
{
    if(event->delta()>0&&m_scalnum<=1.5)
    {
            m_scalnum *= 1.1;
            this->scale(1.1, 1.1);
    }
    else if(event->delta()<0&&m_scalnum>0.3)
    {
            m_scalnum /= 1.1;
            this->scale(1/1.1, 1/1.1);
    }
}

