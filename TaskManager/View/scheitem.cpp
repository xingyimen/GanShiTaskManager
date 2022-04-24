#include "scheitem.h"
#include "ui_scheitem.h"

ScheItem::ScheItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScheItem)
{
    ui->setupUi(this);
    this->resize(300,80);
    ui->widget->setStyleSheet("QWidget#widget{background-color:white;border:1px solid gray;border-radius:30px;}");
    //设置只读
    ui->title->setReadOnly(true);
    ui->description->setReadOnly(true);
    ui->starttime->setReadOnly(true);
    ui->endtime->setReadOnly(true);
    //设置文字样式
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

    /*测试*/
    title="C++学习";
    description="看Effective C++第四章内容";
    starttime.setHMS(8,0,0);
    endtime.setHMS(9,30,0);

    /*测试*/


    //初始化数据
    ui->starttime->setTime(starttime);
    ui->endtime->setTime(endtime);
    ui->title->setText(title);
    ui->description->setText(description);








}

ScheItem::~ScheItem()
{
    delete ui;
}
