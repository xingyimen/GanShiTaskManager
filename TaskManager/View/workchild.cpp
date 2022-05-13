#include "workchild.h"
#include <QWidget>
#include <QLineEdit>
#include <QGraphicsProxyWidget>
#include "mask.h"
#include <QVBoxLayout>
#include <QRadioButton>
#include <QButtonGroup>


extern int IDWorkTree=1;
extern Linklist<WorkflowDao>* WorkDaoList;  //全局变量，装载日程的链表
extern Linklist<WorkChild>* worklist; /*全局变量WorkTree的链表*/
extern QWidget* mainwid_p;
extern WorkChild* CheckingItem;  //当前正在查看的树

//根节点
WorkChild::WorkChild(QString name,QWidget *parent)
    : QPushButton{parent}
{
    //worktree内容
    id=IDWorkTree++;
    root_node_type = WorkChild::Root;
    node_type = WorkChild::Index;
    flag = WorkChild::Unfinished;
    this->name=(name=="")? "未命名":name;
    sibling=nullptr;
    child=nullptr;
    //构造函数（传入名称）（节点类型默认根、默认未读、默认索引）
    this->setText(this->name);
    length=this->return_name().length();//获取长度
    this->setFixedSize(length*20+80,80);
    this->RefleshFlag();
    scenep = new QGraphicsScene();
    child_num=0;
    deepth=0;
    line=nullptr;
    connect(this,&QPushButton::clicked,[=](){
        this->CheckChoose();
    });


}

//孩子节点
WorkChild::WorkChild(QString name,int qttype,WorkChild* parent_node,QWidget *parent)
    : QPushButton{parent}
{
    //worktree内容
    id=IDWorkTree++;
    root_node_type = WorkChild::Child;
    flag = WorkChild::Unfinished;
    node_type = qttype;					//传入的节点类型
    this->child = nullptr;
    this->name=(name=="")? "未命名":name;
    WorkChild* p = parent_node;
    if (parent_node->child) {
        this->sibling = parent_node->child;
        parent_node->child = this;
    }
    else {
        this->sibling = nullptr;
        parent_node->child = this;
    }
     //构造函数（传入节点名称、节点类型（索引/书））（默认孩子、默认未读）
    this->setText(this->name);
    length=this->name.length();//获取长度
    this->setFixedSize(length*20+80,80);
    this->RefleshFlag();
    scenep = parent_node->return_scene();
    deepth=0;
    child_num=0;
    parent_node->child_num++;
    connect(this,&QPushButton::clicked,[=](){
        this->CheckChoose();
    });
    line=nullptr;

}

/*所有需要等对象创建好后的数据初始化步骤*/
void WorkChild::initNode(WorkChild* parent_node){
    /*基于该Widget对象创建一个视图内Item对象*/
    showitem=scenep->addWidget(this);
    /*初始化其X轴位置*/
    if(parent_node!=nullptr){
        //孩子节点
        point=parent_node->showitem->scenePos();  //记录他场景中的坐标
        point.setX(point.x()+260+parent_node->showitem->rect().width()); //新坐标点X等于父节点原点+一半父长
        showitem->setPos(point);  
    }
    else{
        //根节点
        point=this->showitem->scenePos();  //记录他场景中的坐标
    }
}

WorkChild::~WorkChild(){
     qDebug()<<"析构WorkChild"<<this->name;
}
/************原WorkTree*************/
/*提供给Qt工作流界面显示的接口*/
//一定是根节点调用
QString WorkChild::return_progress() {
    QString heroNode="null";
    return return_progress_check(heroNode);
}
QString WorkChild::return_progress_check(QString& heroNode) {
    //返回目前在读的书名——提供给描述
    if (this->flag == WorkChild::Reading && this->node_type == WorkChild::Book) {
        return this->name;
    }
    //向左边找
    if (this->child != NULL) {
        heroNode = this->child->return_progress();
    }
    if (heroNode!="null") {
        //说明找到了
        return heroNode;
    }
    //向右边找
    if (this->sibling != NULL) {
        heroNode = this->sibling->return_progress();
        //this是其父节点
    }
    //不管找没找到  都要返回了
    return heroNode;
}

void WorkChild::ChangeFlag(WorkChild* root, int flag) {
    switch (flag) {
    case WorkChild::Reading:
    {
        bool changeflag = false;
        root->changereading(this, changeflag);
        break;
    }
    case WorkChild::Finish:
    {
        bool finishflag = false;
        root->changefinish(this, finishflag);
        break;
    }
    }
}

void WorkChild::changereading(WorkChild* item, bool& readingflag) {
    //返回目前在读的书名——提供给描述
    if (this==item) {
        this->flag = WorkChild::Reading;
        readingflag = true;
        this->RefleshFlag();
        this->RefleshLineColor();
        return;
    }
    //向左边找
    if (this->child != NULL) {
        this->child->changereading(item, readingflag);
        if (readingflag == true) {
            if (this->flag == WorkChild::Unfinished && this->node_type == WorkChild::Index)
                this->flag = WorkChild::Reading;
            this->RefleshFlag();
            this->RefleshLineColor();
            //说明找到了
            return;
        }
    }
    //向右边找
    if (this->sibling != NULL) {
        this->sibling->changereading(item, readingflag);
        if (readingflag == true) {
            //说明找到了
            this->RefleshFlag();
            this->RefleshLineColor();
            return;
        }
        //this是其父节点
    }
};

void WorkChild::changefinish(WorkChild* item, bool& finishflag) {
    //返回目前在读的书名——提供给描述
    if (this == item) {
        this->flag = WorkChild::Finish;
        finishflag = true;
        this->RefleshFlag();
        this->RefleshLineColor();
        return;
    }
    //向左边找
    if (this->child != NULL) {
        this->child->changefinish(item ,finishflag);
        if (finishflag == true) {
            if (this->flag == WorkChild::Reading && this->node_type == WorkChild::Index) {
                WorkChild* p = this->child;
                bool finishflag2 = true;
                while (p) {
                    if (p->flag != WorkChild::Finish) finishflag2 = false;
                    p = p->sibling;
                }
                if (finishflag2)  {
                    this->flag = WorkChild::Finish;
                    this->RefleshFlag();
                    this->RefleshLineColor();
                }
            }
            //说明找到了
            return;
        }
    }
    //向右边找
    if (this->sibling != NULL) {
        this->sibling->changefinish(item, finishflag);
        if (finishflag == true) {
            //说明找到了
            return;
        }
        //this是其父节点
    }
};

//一定是根节点调用
QString WorkChild::return_name() {
    return name;
}
void WorkChild::delete_tree() {
    //删除整棵树
    if (this->sibling)  this->sibling->delete_tree();
    if (this->child)  this->child->delete_tree();
    this->~WorkChild();
}
/************原WorkTree*************/

void WorkChild::RefleshFlag(){
    /*设置样式表*/
    if(this->flag==WorkChild::Unfinished) {
        setStyleSheet("QPushButton{border: 5px solid rgb(199,199,199);background-color:rgb(199,199,199);color:black;font:25px;font-family: Segoe UI;}");
    }
    else if(this->flag==WorkChild::Reading){
        setStyleSheet("QPushButton{border: 5px solid rgb(255,199,0);background-color:white;color:black;font:25px;font-family: Segoe UI;}");
    }
    else if(this->flag==WorkChild::Finish){
        setStyleSheet("QPushButton{border: 5px solid rgb(0,199,255);background-color:white;color:black;font:25px;font-family: Segoe UI;}");
    }
}


void WorkChild::getdeepth() {
    this->deepth = 0;
    if (this->child != nullptr) {
        this->child->getdeepth();
    }
    if (this->sibling != nullptr) {
        this->sibling->getdeepth();
    }
    WorkChild* p = this->child;
    int d = 0;
    if (!this->child) this->deepth = 1;
    else {
        while (p) {
            d += p->deepth;
            p = p->sibling;
        }
        this->deepth = d;
        }
}
void WorkChild::RefleshPos(WorkChild* parentnode){
    this->first_RefleshPos();
    if(parentnode->child_num>1){
        double MaxHieght=(this->deepth-1)*(80+60);
        double floor = (-1)*MaxHieght/2;
        this->secend_RefleshPos(floor);
    }
    this->third_Refleshline();

}
void WorkChild::first_RefleshPos(){
    this->getdeepth();
}

void WorkChild::secend_RefleshPos(double& floor){
    if(this->child!=nullptr)  this->child->secend_RefleshPos(floor);
    {
        if(this->deepth==1){
            this->showitem->setPos(this->point.x(),floor);
            floor+=140;
        }
        else{
            double dy = this->child->showitem->pos().y()+((this->deepth)-1)*140/2;
            this->showitem->setPos(this->point.x(),dy);
        }

    }
    if(this->sibling!=nullptr)  this->sibling->secend_RefleshPos(floor);
}
void WorkChild::third_Refleshline()
{
    if(this->child){
        this->child->third_Refleshline();
        WorkChild* p =this->child;
        while(p){
            p->RefleshLinePos(this);
            p->RefleshLineColor();
            p=p->sibling;
        }
    }
    if(this->sibling){
        this->sibling->third_Refleshline();
    }
}

void WorkChild::AddChild(){
    /*遮罩*/
    Mask* mask=new Mask(mainwid_p);
    /*添加WorkItem窗口*/
    QWidget* addNode = new QWidget(mask);
    addNode->setFixedSize(270,160);
    addNode->move(110,280);
    addNode->setStyleSheet("QWidget{background-color: white;border: 1px solid gray;border-radius:30px;font-family: Segoe UI;}");
    addNode->show();
    mask->setRect(addNode->geometry());
    /*输入标题*/
    QLineEdit* name = new QLineEdit(addNode);
    name->setFixedSize(130,21);
    name->move(40,50);
    name->setStyleSheet("QLineEdit{border:1px solid white;border-bottom-color:gray;background-color:white;}");
    name->show();
    name->setPlaceholderText("创建子节点");
    QRadioButton* rbtn1 = new QRadioButton("索引",addNode);
    QRadioButton* rbtn2 = new QRadioButton("书",addNode);
    QButtonGroup* group=new QButtonGroup(addNode);
    group->addButton(rbtn1,1);
    group->addButton(rbtn2,2);
    rbtn1->setFixedSize(50,20);
    rbtn1->setStyleSheet("QRadioButton{border:0px solid white;}");
    rbtn1->move(40,80);
    rbtn1->setChecked(true);
    rbtn1->show();
    rbtn2->setFixedSize(50,20);
    rbtn2->setStyleSheet("QRadioButton{border:0px solid white;}");
    rbtn2->move(110,80);
    rbtn2->show();
    /*完成按钮*/
    QPushButton* finishbtn = new QPushButton(addNode);
    finishbtn->setFixedSize(100,35);
    finishbtn->move(100,110);
    finishbtn->setText("完成");
    finishbtn->setStyleSheet("QPushButton{border: 1px solid gray;background-color: white;border-radius:15px;font:12px; font-family: Segoe UI;}"
                             "QPushButton:pressed{background-color: gray;}");
    finishbtn->show();
    /*创建孩子*/
    connect(finishbtn,&QPushButton::clicked,[=](){
        int qtype=(rbtn1->isChecked()==true)?WorkChild::Index:WorkChild::Book;
        WorkChild* child= new WorkChild(name->displayText(),qtype,this);
        child->initNode(this);
        child->addLine(this);
        CheckingItem->RefleshPos(this);
        mask->~Mask();
    });
}

void WorkChild::QuestFlag()
{
    if(this->flag==WorkChild::Unfinished) {
        qDebug()<<"开始任务";
        this->ChangeFlag(CheckingItem,WorkChild::Reading);
    }
    else {
        qDebug()<<"完成任务";
        this->ChangeFlag(CheckingItem,WorkChild::Finish);
    }
}

void WorkChild::CheckChoose()
{
    /*遮罩*/
    Mask* mask=new Mask(mainwid_p);
    /*添加WorkItem窗口*/
    QWidget* Choose = new QWidget(mask);
    Choose->setFixedSize(190,150);
    Choose->move(150,290);
    Choose->setStyleSheet("QWidget{background-color: white;border: 1px solid gray;border-radius:30px;font-family: Segoe UI;}");
    Choose->show();
    mask->setRect(Choose->geometry());
    /*添加按钮*/
    QPushButton* btn1 =new QPushButton(Choose);
    btn1->setFixedSize(110,30);
    btn1->setStyleSheet("QPushButton{border: 1px solid gray;background-color: white;border-radius:15px;font:12px; font-family: Segoe UI;}"
                             "QPushButton:pressed{background-color: gray;}");
    QPushButton* btn2 =new QPushButton(Choose);
    btn2->setFixedSize(110,30);
    btn2->setStyleSheet("QPushButton{border: 1px solid gray;background-color: white;border-radius:15px;font:12px; font-family: Segoe UI;}"
                             "QPushButton:pressed{background-color: gray;}");
    QVBoxLayout* layout = new QVBoxLayout(Choose);
    btn1->setText("添加子节点");
    if(this->node_type==WorkChild::Index){
        layout->addWidget(btn1);
    }
    layout->setAlignment(Qt::AlignCenter);
    layout->setSpacing(20);
    if(this->node_type==WorkChild::Book){
        switch(this->flag)
        {
        case WorkChild::Unfinished:
        {
            btn2->setText("开始任务");
            layout->addWidget(btn2);
            break;
        }
        case WorkChild::Reading:
        {
            btn2->setText("完成任务");
            layout->addWidget(btn2);
            break;
        }
        }
    }
    connect(btn1,&QPushButton::clicked,[=](){
        this->AddChild();
        mask->~Mask();
    });
    connect(btn2,&QPushButton::clicked,[=](){
        this->QuestFlag();
        mask->~Mask();
    });
}

void WorkChild::addLine(WorkChild* parent_node)
{
    //连接直线
    QPointF start = parent_node->showitem->scenePos();
    start.setX(start.x()+parent_node->showitem->rect().width());
    start.setY(start.y()+40);
    QPointF end = this->showitem->scenePos();
    end.setY(end.y()+40);
    QPainterPath path(start);
    path.lineTo(start.x()+130,start.y());
    path.lineTo(start.x()+130,end.y());
    path.lineTo(end);
    QPen pen;
    pen.setWidth(10);
    pen.setColor(QColor(199,199,199));
    pen.setJoinStyle(Qt::MiterJoin);
    this->line=this->scenep->addPath(path,pen);
}
void WorkChild::RefleshLinePos(WorkChild* parent_node)
{
    //连接直线
    QPointF start = parent_node->showitem->scenePos();
    start.setX(start.x()+parent_node->showitem->rect().width());
    start.setY(start.y()+40);
    QPointF end = this->showitem->scenePos();
    end.setY(end.y()+40);
    QPainterPath path(start);
    path.lineTo(start.x()+130,start.y());
    path.lineTo(start.x()+130,end.y());
    path.lineTo(end);
    this->line->setPath(path);
}
void WorkChild::RefleshLineColor()
{
    QPen pen;
    pen.setWidth(10);
    pen.setJoinStyle(Qt::MiterJoin);
    if(this->flag==WorkChild::Unfinished)
    {
        pen.setColor(QColor(199,199,199));
    }
    else if(this->flag==WorkChild::Reading)
    {
        pen.setColor(QColor(255,199,0));
    }
    else if(this->flag==WorkChild::Finish)
    {
        pen.setColor(QColor(0,199,255));
    }
    if(this->line)  {
        this->line->setPen(pen); //改变颜色
        if(this->flag==WorkChild::Unfinished) this->line->setZValue(0);  //确定谁在最上面
        else if(this->flag==WorkChild::Reading)this->line->setZValue(1);
        else this->line->setZValue(-1);
    }
}

 /*Dao层接口*/
void WorkChild::toDaoItem(){
    //一定是根节点调用
    //中序遍历二叉树---树的后根
    if(this->child)  {
        this->child->toDaoItem();
    }
    {
    WorkflowDao* wdao = new WorkflowDao;
    wdao->book = this->name;
    wdao->id.setNum(this->id);
    wdao->flag.setNum(this->flag);
    wdao->node_type.setNum(this->node_type);
    wdao->root_node_type.setNum(this->root_node_type);
    if(this->child) wdao->child.setNum(this->child->id);
    else wdao->child.setNum(0);
    if(this->sibling) wdao->sibling.setNum(this->sibling->id);
    else wdao->sibling.setNum(0);
    WorkDaoList ->InsertDataAtHead(wdao);
    }
    if(this->sibling)  {
        this->sibling->toDaoItem();
    }
}

WorkChild::WorkChild(WorkflowDao* item,WorkChild* par){
    this->id=IDWorkTree++;
    this->name= item->book;
    this->flag = item->flag.toInt();
    this->node_type = item->node_type.toInt();
    this->root_node_type = item->root_node_type.toInt();
    this->child = nullptr;
    this->sibling = nullptr;
    if(par) {
        //为了保证输出稳定，这里使用尾插
        if (par->child) {
            WorkChild*p=par->child;
            while(p->sibling) p=p->sibling;   //找到链尾
            p->sibling = this;
        }
        else {
            this->sibling = nullptr;
            par->child = this;
        }

    }
    //构造函数（传入节点名称、节点类型（索引/书））（默认孩子、默认未读）
   this->setText(this->name);
   length=this->name.length();//获取长度
   this->setFixedSize(length*20+80,80);
   this->RefleshFlag();
   deepth=0;
   child_num=0;
   if(par){
       scenep = par->return_scene();
       par->child_num++;
   }
   else scenep = new QGraphicsScene();;
   connect(this,&QPushButton::clicked,[=](){
       this->CheckChoose();
   });
   line=nullptr;
}
