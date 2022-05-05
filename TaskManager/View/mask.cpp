#include "mask.h"
#include <QMouseEvent>
#include <QDebug>
Mask::Mask(QWidget *parent)
    : QWidget{parent}
{
    move(0,0);
    setFixedSize(480,800);
    QWidget* blackmask=new QWidget(this);
    blackmask->setFixedSize(480,800);
    blackmask->move(0,0);
    blackmask->setStyleSheet("background:rgba(0,0,0,0.5);");
    this->show();
}

void Mask::mousePressEvent(QMouseEvent *event)
{
    if(event->x()<rec.x()||event->x()>rec.x()+rec.width()||event->y()<rec.y()||event->y()>rec.y()+rec.height()){
        this->~Mask();
    }
}

Mask::~Mask()
{
   qDebug()<<"析构mask";
}

void Mask::setRect(QRect rec)
{
    this->rec= rec;
}
