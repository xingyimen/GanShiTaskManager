#include "workitem.h"
#include "ui_workitem.h"

WorkItem::WorkItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkItem)
{
    ui->setupUi(this);
    this->resize(320,80);
    ui->widget->setStyleSheet("QWidget#widget{background-color:white;border:1px solid rgb(253,202,36);border-radius:25px;}");
    //设置只读
    ui->title->setReadOnly(true);
    ui->description->setReadOnly(true);
    //设置文字样式
    QFont ft;
    ft.setPointSize(18);
    ft.setFamily("Arial");
    ui->title->setFont(ft);
    ft.setPointSize(15);
    ui->pushButton->setFont(ft);
    ft.setPointSize(10);
    ui->description->setFont(ft);
    ui->description->setTextColor(QColor(253,202,36));

    /*测试*/
    ui->title->setText("C++学习");
    ui->description->setText("Effective C++");
}

WorkItem::~WorkItem()
{
    delete ui;
}
