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
    //connect(ui->begin,SIGNAL(clicked()),this,SLOT(btn_begin()));
    connect(ui->begin,&QPushButton::clicked,[=](){
        btn_begin();

    });
    b_mouseEve = false;

    //workOrrelax = new workOrrelax_sde(this);
}

AddPomodoro::~AddPomodoro()
{
    delete ui;
}

void AddPomodoro::btn_begin()
{
    workOrrelax = new workOrrelax_sde(this);
    b_mouseEve = true;
    connect(workOrrelax,SIGNAL(closedown()),this,SLOT(closepom()));
    int start_work = ui->spinBox_work->value();
    int start_relax = ui->spinBox_relax->value();
    QString theme_text = ui->lineEdit->text();
    QString dtl_text = ui->textEdit->toPlainText();
    workOrrelax->onShowTime(start_work,start_relax,theme_text);
    workOrrelax->show();

    //this->close();


}

void AddPomodoro::closepom()
{
    b_mouseEve = false;
    this->close();
}

void AddPomodoro::OpenPomodoro(){


}

void AddPomodoro::mousePressEvent(QMouseEvent *event){

    if(b_mouseEve)
    {
        return;
    }
    else
    {
        QRect rec=ui->widget->geometry();
        if(event->x()<rec.x()||event->x()>(rec.x()+rec.width())||event->y()<rec.y()||event->y()>(rec.y()+rec.height())){
            this->close();
            this->~AddPomodoro();
        }
    }

}
