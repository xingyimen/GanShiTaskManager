#include "grapharea.h"
#include <QScrollBar>
#include <QPushButton>
#include <QDebug>
#include <QMouseEvent>
#include <QLabel>
#include <QToolButton>


int X0=0;
int Y0=0;

GraphArea::GraphArea(QWidget *parent)
    : QScrollArea{parent}
{
    setFixedSize(480,740);
    setStyleSheet("background-color:qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(255, 255, 255, 255), stop:0.373979 rgba(255, 255, 255, 255), stop:0.373991 rgba(33, 30, 255, 255), stop:0.624018 rgba(33, 30, 255, 255), stop:0.624043 rgba(255, 0, 0, 255), stop:1 rgba(255, 0, 0, 255))"); //测试
    //打印标签
    QLabel* label=new QLabel(this);
    label->setFixedSize(480,50);
    label->setText("工作流");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("background-color: rgb(42, 180, 255);color:white;font:25px;font-family: 幼圆;font-weight:bold;");
    //打印返回按钮
    QPushButton* returnbtn= new QPushButton(label);
    returnbtn->setFixedSize(50,50);
    returnbtn->move(20,0);
    returnbtn->setStyleSheet("border-image: url(:/menu/res/return.png)");
    connect(returnbtn,&QPushButton::clicked,[=](){
        this->close();
        this->~GraphArea();
    });
    QWidget* graph=new QWidget(this);
    graph->setMinimumSize(2000,2000);
    //右下滑块
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setWidget(graph);
    setWidgetResizable(true);  //好像是设置可缩放的
    //setMouseTracking(true);


    QPushButton *btn1=new QPushButton(graph);
    QPushButton *btn2=new QPushButton(graph);
    btn1->resize(200,200);
    btn2->resize(200,200);
    btn1->move(500,200);
    btn2->move(1400,1400);
    btn1->setText("aaa");
    btn2->setText("bbb");

    hbra=horizontalScrollBar() ;
    vbra=verticalScrollBar() ;

}


void GraphArea::mousePressEvent(QMouseEvent *event){//鼠标点击事件
    X0=event->x();
    Y0=event->y();
}
void GraphArea::mouseMoveEvent(QMouseEvent *event){//鼠标移动事件(没开鼠标追踪默认是点击后才触发)
   int dX=event->x()-X0;
   int dY=event->y()-Y0;
   hbra->setValue((hbra->value())-dX);
   vbra->setValue((vbra->value())-dY);
   X0=event->x();
   Y0=event->y();
}
GraphArea::~GraphArea(){
    qDebug()<<"没了";
}
