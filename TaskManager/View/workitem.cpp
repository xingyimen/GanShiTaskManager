#include "workitem.h"
#include "ui_workitem.h"
#include <QGraphicsView>
#include "graphicsscene.h"
#include <QLabel>
#include "graphicsview.h"
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

    GraphicsView* tree_graph=new GraphicsView(this->parentWidget());
    //打印标签
    QLabel* label=new QLabel(tree_graph);
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
        tree_graph->close();
        tree_graph->~GraphicsView();
    });
    //加载Scene场景
    GraphicsScene* scene=new GraphicsScene();
    tree_graph->setScene(scene);
    tree_graph->show();









}



