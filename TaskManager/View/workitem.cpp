#include "workitem.h"
#include "ui_workitem.h"
#include <QGraphicsView>
#include <QLabel>
#include <QDebug>
#include "graphicsview.h"
#include "mask.h"
#include <QMouseEvent>

extern Linklist<WorkItem>* worklist;
extern QWidget* mainwid_p;
WorkChild* CheckingItem=nullptr;
WorkItem::WorkItem(WorkChild* root,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkItem)
{
    ui->setupUi(this);
    //设置样式
    ui->widget->setStyleSheet("QWidget#widget{background-color:white;border:1px solid rgb(253,202,36);border-radius:25px;}");
    //设置只读
    ui->title->setReadOnly(true);
    ui->description->setReadOnly(true);
    //设置文字样式
    QFont ft;
    ft.setPointSize(16);
    ft.setFamily("Segoe UI;");
    ui->title->setFont(ft);
    ft.setPointSize(16);
    ui->checkbtn->setFont(ft);
    ft.setPointSize(12);
    ui->description->setFont(ft);
    ui->description->setTextColor(QColor(253,202,36));
    /*初始化数据*/
    rootp=root;
    scenep=root->return_scene();
    ui->title->setText(rootp->return_name());
    connect(ui->checkbtn,&QPushButton::clicked,[=](){
        this->CheckQuestTree();
    });
}

WorkItem::~WorkItem()
{
    delete ui;
}
void WorkItem::CheckQuestTree(){
    /***任务树内***/
    CheckingItem=this->rootp;
    /*显示View*/
    GraphicsView* tree_graph=new GraphicsView(mainwid_p);
    tree_graph->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tree_graph->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    /*打印标签*/
    QLabel* label=new QLabel(tree_graph);
    label->setFixedSize(480,50);
    label->setText("工作流");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("background-color: rgb(42, 180, 255);color:white;font:25px;font-family: 幼圆;font-weight:bold;");
    /*打印返回按钮*/
    QPushButton* returnbtn= new QPushButton(label);
    returnbtn->setFixedSize(50,50);
    returnbtn->move(20,0);
    returnbtn->setStyleSheet("border-image: url(:/menu/res/return.png)");
    connect(returnbtn,&QPushButton::clicked,[=](){
        tree_graph->close();
        tree_graph->~GraphicsView();
    });
    /*刷新显示数据*/
    tree_graph->setScene(this->scenep);
    tree_graph->show(); 
    CheckingItem->RefleshPos(this->rootp);
}

void WorkItem::Reflesh(QPoint point){
   move(point);
   ui->description->setText(rootp->return_progress());
   qDebug()<<"reflesh";
   show();
}

void WorkItem::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton) this->Check();
}

void WorkItem::Check(){
    /*遮罩*/
    Mask* mask=new Mask(mainwid_p);
    /*WorkItem窗口*/
    QWidget* deleWork = new QWidget(mask);
    deleWork->setFixedSize(260,130);
    deleWork->move(110,260);
    deleWork->setStyleSheet("QWidget{background-color: white;border: 1px solid gray;border-radius:30px;font-family: Segoe UI;}");
    deleWork->show();
    mask->setRect(deleWork->geometry());
    /*输入标题*/
    QLineEdit* name = new QLineEdit(deleWork);
    name->setFixedSize(100,30);
    name->move(30,30);
    name->setStyleSheet("QLineEdit{font:25px;border:1px solid white;background-color:white;font-family: Segoe UI;}");
    name->setReadOnly(true);
    name->setText(rootp->return_name());
    name->show();
    /*输入描述*/
    QLineEdit* text = new QLineEdit(deleWork);
    text->setFixedSize(140,20);
    text->setReadOnly(true);
    text->move(40,60);
    text->setStyleSheet("QLineEdit{border:1px solid white;background-color:white;font-family: Segoe UI;}");
    text->setText(rootp->return_progress());
    text->show();
    /*删除按钮*/
    QPushButton* deletebtn = new QPushButton(deleWork);
    deletebtn->setFixedSize(100,35);
    deletebtn->move(80,80);
    deletebtn->setText("删除");
    deletebtn->setStyleSheet("QPushButton{border: 1px solid gray;background-color: white;border-radius:15px;font:12px; font-family: Segoe UI;}"
                           "QPushButton:pressed{background-color: gray;}");
    deletebtn->show();
    connect(deletebtn,&QPushButton::clicked,[=](){
        this->rootp->delete_tree();   //删掉所有孩子节点
        worklist->DeleteData(this);   //从链表删除改节点
        QPoint pbase(30,50);   //打印的基点
        int direct=110+30;  //110是WorkItem的高，20是间隔
        Node<WorkItem>* p=worklist->head;
        while(p->next){
            pbase.setY(pbase.y());
            p->next->data->Reflesh(pbase);
            pbase.setY(pbase.y()+direct);
            p=p->next;
        }
        mask->~Mask();
    });
}

