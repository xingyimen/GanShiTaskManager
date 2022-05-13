#include "graphicsview.h"
#include <QWheelEvent>
#include <QDebug>
GraphicsView::GraphicsView(QWidget *parent)
    : QGraphicsView{parent}
{
    setDragMode(GraphicsView::ScrollHandDrag);
    resize(480,730);
    setStyleSheet("border:0px;background-color : rgb(244, 244, 244)");
    setResizeAnchor(GraphicsView::AnchorUnderMouse);  //确定锚点为鼠标
    m_scalnum=1;
}


void GraphicsView::wheelEvent(QWheelEvent *event)
{
    if(event->delta()>0&&m_scalnum<=1.2)
    {
            m_scalnum *= 1.1;
            this->scale(1.1, 1.1);
    }
    else if(event->delta()<0&&m_scalnum>0.5)
    {
            m_scalnum /= 1.1;
            this->scale(1/1.1, 1/1.1);
    }
}

