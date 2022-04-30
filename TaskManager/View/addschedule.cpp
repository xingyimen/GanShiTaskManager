#include "addschedule.h"
#include "ui_addschedule.h"
#include <QDebug>
#include <QMouseEvent>
AddSchedule::AddSchedule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddSchedule)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("添加日程");
    ui->textEdit->setPlaceholderText("具体描述");
}

AddSchedule::~AddSchedule()
{
    delete ui;
}

void AddSchedule::OpenPomodoro(){


}

void AddSchedule::mousePressEvent(QMouseEvent *event){

    QRect rec=ui->widget->geometry();
    if(event->x()<rec.x()||event->x()>(rec.x()+rec.width())||event->y()<rec.y()||event->y()>(rec.y()+rec.height())){
        this->close();
        this->~AddSchedule();
    }

}
