#include "scheitem.h"
#include "ui_scheitem.h"

ScheItem::ScheItem(QString q_title, QString q_description,QTime q_starttime,QTime q_endtime,QWidget *parent) :
    QWidget(parent),Schedule(q_title.toStdString(), q_description.toStdString(), MyTime(q_starttime.hour(),q_starttime.minute(),q_starttime.second()), MyTime(q_endtime.hour(),q_endtime.minute(),q_endtime.second())),
    ui(new Ui::ScheItem)
{
    ui->setupUi(this);
    /*设置样式表*/
    ui->widget->setStyleSheet("QWidget#widget{background-color:white;border:1px solid gray;border-radius:30px;}");
    /*设置只读*/
    ui->title->setReadOnly(true);
    ui->description->setReadOnly(true);
    ui->starttime->setReadOnly(true);
    ui->endtime->setReadOnly(true);
    /*设置文字样式*/
    QFont ft;
    ft.setPointSize(18);
    ft.setFamily("黑体");
    ui->starttime->setFont(ft);
    ui->endtime->setFont(ft);
    ui->title->setFont(ft);
    ft.setPointSize(10);
    ft.setFamily("Arial");
    ui->description->setFont(ft);
    ui->description->setTextColor(QColor(130,130,130));
    ui->starttime->setDisplayFormat("HH:mm");
    ui->endtime->setDisplayFormat("HH:mm");
    /*初始化数据*/
    ui->title->setText(this->getname().c_str());
    ui->description->setText(this->getdescription().c_str());
    ui->starttime->setTime(QTime(this->getstarttime().hour,this->getstarttime().minute));
    ui->endtime->setTime(QTime(this->getendtime().hour,this->getendtime().minute));
}

ScheItem::~ScheItem()
{
    delete ui;
}

void ScheItem::Reflesh(QPoint* point){
   move(*point);
}
