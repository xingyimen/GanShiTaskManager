#include "datashowdtl.h"
#include "ui_datashowdtl.h"


/*全局变量DataList的链表*/
Linklist<DateTimeRangeWidget>* datalist=new Linklist<DateTimeRangeWidget>();
extern User_sql mysql;
extern QSqlDatabase database;
extern int user_id;


dataShowDtl::dataShowDtl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dataShowDtl)
{
    ui->setupUi(this);

    dataScene =new QGraphicsScene();
    ui->DatagraphicsView->setScene(dataScene);

    this->setFixedSize(480,740); //设置窗体固定大小
    this->move(0,0);
    this->setStyleSheet("background-color : rgb(244, 244, 244);");
    //setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    CalendWnd = new QCalendarWidget(this);
    CalendWnd->setHidden(true);
    CalendWnd->move(150,100);
    connect(ui->toolButton_date,SIGNAL(clicked()),this,SLOT(showTimeslots()));
    //CalendWnd = new QCalendarWidget();
    //时间控件点击事件
    connect(CalendWnd,SIGNAL(activated(QDate)),this,SLOT(setDate()));
    connect(ui->dateEdit,SIGNAL(dateChanged(QDate)),this,SLOT(setUiDate(QDate)));
    //CalendWnd->setHidden(true);
    ui->dateEdit->setDisplayFormat("yyyy-MM-dd");
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
    CalendWnd->setFocusPolicy(Qt::NoFocus);
    QFont font("黑体", 12);
    ui->dateEdit->setFont(font);
//    ui->dateEdit->setStyleSheet("QDateEdit{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, "
//                                            "stop:0 rgba(250, 250, 250, 255), "
//                                            "stop:0.5 rgba(240, 240, 240, 255), "
//                                            "stop:1 rgba(230, 230, 230, 255));"
//                                            "border: 1px solid rgb(200, 200, 200);"
//                                            "border-radius: 4px;"
//                                            "padding-left:10px;}"
//                                            "QDateEdit::drop-down{width:35px;border-image: url(:/menu/res/drop-down-arrow.png);}"
//                                 "QDateEdit::up-button{image: url(:/menu/res/upbutton.png);}"
//                                "QDateEdit::down-button{image: url(:/menu/res/downbutton.png);}"
//                                   );

    //ui->horizontalLayout->SetMaximumSize;

    /*返回按钮*/
    QToolButton* returnbtn= new QToolButton(this);
    returnbtn->setFixedSize(50,50);
    returnbtn->move(20,0);
    returnbtn->setStyleSheet("border-image: url(:/menu/res/return.png)");
    connect(returnbtn,&QToolButton::clicked,[=](){
        this->close();
        this->~dataShowDtl();
    });


    //mysql.connect_mysql(database);



}

dataShowDtl::~dataShowDtl()
{
    delete ui;
    qDebug()<<"删除dataShowDtl";
}


void dataShowDtl::mousePressEvent(QMouseEvent *event)
{
    QRect rec = CalendWnd->geometry();
    if(event->x()<rec.x()||event->x()>(rec.x()+rec.width())||event->y()<rec.y()||event->y()>(rec.y()+rec.height()))
    {
        CalendWnd->setHidden(true);
    }
}

void dataShowDtl::showTimeslots()
{
    CalendWnd->setHidden(false);

}
void dataShowDtl::setDate()
{
    //接收选择时间
    QDate date = CalendWnd->selectedDate();
    //时间格式化
    QString str = date.toString("yyyy-MM-dd");
    //calendar_Edit->setText(str);
    ui->dateEdit->setDate(date);
    //清除
    //clearLayout(ui->verticalLayout_3);
    datalist->CleanList();
    qDebug()<<str;
    //database = userSql->connect_mysql();
    QSqlQuery query(database);
    QString sql_s="select * from tomato.datagramdao where";
    sql_s.append(QString(" date = '%1' and user_id = '%2';").arg(str).arg(user_id));
    //QString sql_s="select * from tomato.datagramdao where date=2022-05-06;";
    qDebug()<<sql_s;
    if(query.exec(sql_s))
    {
        qDebug()<< query.exec(sql_s);
        qDebug()<<"查询成功";
    }
    while(query.next()){
       QString id=query.value("id").toString();

       QString nameQ=query.value("name").toString();
       std::string name = nameQ.toStdString();
       QString datestr=query.value("date").toString();
       QDateTime date = QDateTime::fromString(datestr, "yyyy-MM-dd");
       QString start_timestr=query.value("start_time").toString();
       QTime start_time = QTime::fromString(start_timestr,"hh:mm"); //从字符串转换为QTime
       QString finish_timestr=query.value("finish_time").toString();
       QTime finish_time = QTime::fromString(finish_timestr,"hh:mm"); //从字符串转换为QTime
       addForm(name,date,start_time,finish_time);
       //使用json方法保存到本地
       //       MyJsonObject example1;
       //       example1.writeJson();
    }
    CalendWnd->setHidden(true);


}
void dataShowDtl::setUiDate(QDate selectdate)
{
    //接收选择时间
    QDate date = selectdate;
    //时间格式化
    QString str = date.toString("yyyy-MM-dd");
    //calendar_Edit->setText(str);
    ui->dateEdit->setDate(date);
    //清除
    //clearLayout(ui->verticalLayout_3);
    datalist->CleanList();
    qDebug()<<str;
    //database = userSql->connect_mysql();
    QSqlQuery query(database);
    QString sql_s="select * from tomato.datagramdao where";
    sql_s.append(QString(" date = '%1' and user_id = '%2';").arg(str).arg(user_id));
    qDebug()<<sql_s;
    if(query.exec(sql_s))
    {
        qDebug()<< query.exec(sql_s);
        qDebug()<<"查询成功";
    }
    while(query.next()){
       QString id=query.value("id").toString();

       QString nameQ=query.value("name").toString();
       std::string name = nameQ.toStdString();
       QString datestr=query.value("date").toString();
       QDateTime date = QDateTime::fromString(datestr, "yyyy-MM-dd");
       QString start_timestr=query.value("start_time").toString();
       QTime start_time = QTime::fromString(start_timestr,"hh:mm"); //从字符串转换为QTime
       QString finish_timestr=query.value("finish_time").toString();
       QTime finish_time = QTime::fromString(finish_timestr,"hh:mm"); //从字符串转换为QTime
       addForm(name,date,start_time,finish_time);
    }
    CalendWnd->setHidden(true);
    RefreshDatalist();


}

void dataShowDtl::addForm(std::string name,QDateTime date ,QTime start_time, QTime finish_time)
{

    dateWnd = new DateTimeRangeWidget(name,date,start_time,finish_time);
    dataScene->addWidget(dateWnd);
    //ui->verticalLayout_3->addWidget(dateWnd);
    datalist->InsertDataAtRear(dateWnd);


}

/*数据报表的刷新*/
void dataShowDtl::RefreshDatalist()
{
    QPoint pbase(50,50);   //打印的基点
    int direct=100+10;  //100是DateTimeRangeWidget的高，10是间隔
    Node<DateTimeRangeWidget>* p=datalist->head;
    while(p->next){
        pbase.setY(pbase.y()+direct);
        p->next->data->Reflesh(pbase);
        p=p->next;
    }
}



void dataShowDtl::clearLayout(QLayout *layout)
{
    if (nullptr == layout)
    {
        return;
    }

    QLayoutItem * child = layout->takeAt(0);
    while(child)
    {
        QLayout * subLayout = child->layout();
        if (nullptr == subLayout)
        {
            QWidget *widget = child->widget();
            if (nullptr != widget)
            {
                widget->setParent(nullptr);
                delete widget;
            }
        }
        else
        {
            clearLayout(subLayout);
        }
        delete child;
        child = layout->takeAt(0);
    }

}
