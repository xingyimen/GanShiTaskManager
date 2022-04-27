#include "workitem.h"
#include "ui_workitem.h"
#include "grapharea.h"


WorkItem::WorkItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkItem)
{
    ui->setupUi(this);
    //设置样式
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
    ui->checkbtn->setFont(ft);
    ft.setPointSize(10);
    ui->description->setFont(ft);
    ui->description->setTextColor(QColor(253,202,36));

    /*测试*/
    title="C++学习";
    description="Effective C++";
    ui->title->setText(title);
    ui->description->setText(description);

    //connect(ui->checkbtn,&QPushButton::clicked,this,&WorkItem::CheckQuestTree);
    connect(ui->checkbtn,&QPushButton::clicked,[=](){
        this->CheckQuestTree();
    });



}

WorkItem::~WorkItem()
{
    delete ui;
}

void WorkItem::CheckQuestTree(){
    QScrollArea* tree_graph=new GraphArea(this->parentWidget());
    tree_graph->show();

}



