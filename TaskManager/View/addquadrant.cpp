#include "addquadrant.h"
#include "ui_addquadrant.h"
#include <QMouseEvent>
#include <QDebug>
#include "quadrantitem.h"
AddQuadrant::AddQuadrant(int click_x,int click_y,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddQuadrant)
{
    ui->setupUi(this);
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("输入专注事项");
    ui->textEdit->setPlaceholderText("具体描述");

}

AddQuadrant::~AddQuadrant()
{
    delete ui;
}

void AddQuadrant::mousePressEvent(QMouseEvent *event){

    QRect rec=ui->widget->geometry();
    if(event->x()<rec.x()||event->x()>(rec.x()+rec.width())||event->y()<rec.y()||event->y()>(rec.y()+rec.height())){
        this->close();
        this->~AddQuadrant();
    }

}

void AddQuadrant::NewQuadrantItem(int emergency,int importance){
    /*来自Service层的接口*/

}
