#include "addpomodoro.h"
#include "ui_addpomodoro.h"

#include <QMouseEvent>
AddPomodoro::AddPomodoro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddPomodoro)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("输入专注事项");
    ui->textEdit->setPlaceholderText("具体描述");
}

AddPomodoro::~AddPomodoro()
{
    delete ui;
}



void AddPomodoro::OpenPomodoro(){


}

void AddPomodoro::mousePressEvent(QMouseEvent *event){

    QRect rec=ui->widget->geometry();
    if(event->x()<rec.x()||event->x()>(rec.x()+rec.width())||event->y()<rec.y()||event->y()>(rec.y()+rec.height())){
        this->close();
        this->~AddPomodoro();
    }

}
