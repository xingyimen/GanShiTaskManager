#include "mainwindow.h"
#include "ui_mainwindow.h"

MyTime GetTime(){
    QTime current_time=QTime::currentTime();
    return MyTime(current_time.hour(), current_time.minute(), current_time.second());
}
MyDate GetDate(){
    QDate current_date=QDate::currentDate();
    return MyDate(current_date.year(),current_date.month(), current_date.day());
}

extern QWidget* mainwid_p=nullptr;

/*全局变量Quadrant的链表*/
extern Linklist<QuadrantItem>* qualist=new Linklist<QuadrantItem>();
/*全局变量ScheItem的链表*/
extern Linklist<ScheItem>* schelist=new Linklist<ScheItem>();
/*全局变量WorkTree的链表*/
extern Linklist<WorkItem>* worklist=new Linklist<WorkItem>();


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainwid_p=this;
    Init();
}

void MainWindow::Init()
{
    //背景设置
    setStyleSheet("background-color : rgb(244, 244, 244)");
    //按钮设置
    ui->schedulebtn->setCheckable(true);
    ui->workflowbtn->setCheckable(true);
    ui->quadrantbtn->setCheckable(true);
    ui->datagrambtn->setCheckable(true);
    ui->setbtn->setCheckable(true);
    //按钮操作
    connect(ui->schedulebtn,&QToolButton::clicked,[=](){
        ui->stackedWidget->setCurrentWidget(ui->schedule);
        ui->schedulebtn->setChecked(true);
        ui->workflowbtn->setChecked(false);
        ui->quadrantbtn->setChecked(false);
        ui->datagrambtn->setChecked(false);
        ui->setbtn->setChecked(false);
        this->RefreshSchedule();
    });
    connect(ui->workflowbtn,&QToolButton::clicked,[=](){
        ui->stackedWidget->setCurrentWidget(ui->workflow);
        ui->schedulebtn->setChecked(false);
        ui->workflowbtn->setChecked(true);
        ui->quadrantbtn->setChecked(false);
        ui->datagrambtn->setChecked(false);
        ui->setbtn->setChecked(false);
        this->RefreshWorkTree();
    });
    connect(ui->quadrantbtn,&QToolButton::clicked,[=](){
        ui->stackedWidget->setCurrentWidget(ui->quadrant);
        ui->schedulebtn->setChecked(false);
        ui->workflowbtn->setChecked(false);
        ui->quadrantbtn->setChecked(true);
        ui->datagrambtn->setChecked(false);
        ui->setbtn->setChecked(false);
        this->RefreshQuadrant();
    });
    connect(ui->datagrambtn,&QToolButton::clicked,[=](){
        ui->stackedWidget->setCurrentWidget(ui->datagram);
        ui->schedulebtn->setChecked(false);
        ui->workflowbtn->setChecked(false);
        ui->quadrantbtn->setChecked(false);
        ui->datagrambtn->setChecked(true);
        ui->setbtn->setChecked(false);
    });
    connect(ui->setbtn,&QToolButton::clicked,[=](){
        ui->stackedWidget->setCurrentWidget(ui->set);
        ui->schedulebtn->setChecked(false);
        ui->workflowbtn->setChecked(false);
        ui->quadrantbtn->setChecked(false);
        ui->datagrambtn->setChecked(false);
        ui->setbtn->setChecked(true);
    });
    //设置默认页面
    ui->schedulebtn->setChecked(true);
    ui->stackedWidget->setCurrentWidget(ui->schedule);
    //设置界面按钮
    connect(ui->exit,&QToolButton::clicked,[=](){exit(0);});
    /**********添加任务**********/
    //添加番茄钟
    connect(ui->pomodorobtn,&QToolButton::clicked,[=](){
        AddPomodoro* pomodoro=new AddPomodoro(this);
        pomodoro->show();
    });
    //添加日程
    connect(ui->sche_addbtn,&QToolButton::clicked,this,&MainWindow::AddSchedule);
    //添加任务树
    connect(ui->work_addbtn,&QToolButton::clicked,this,&MainWindow::AddWorkTree);
    workScene = new QGraphicsScene(this);
    ui->WorkgraphicsView->setScene(workScene);






    //添加四象限：安装过滤器
    ui->gridding->installEventFilter(this);

//   QString theme;
//   QString describe;
//   QString start_time;
//   QString end_time;
//   QString id;

//    ScheduleDao item;
//    item.theme="C++Java";
//    item.describe="描述";
//    item.id="004";
//    item.start_time="2022-5-4";
//    item.end_time="2022-5-5";
//    MyJsonObject dao;

//    dao.writeJson(item);
//    QStringList theme,describe,start_time,end_time,id,a,b,c,d,e;
//    MyJsonObject test;
//    test.readJson(theme,describe,start_time,end_time,id,a,b,c,d,e);
//    for(int i=0;i<=1;i++){
//        qDebug()<<a[i];
//        qDebug()<<b[i];
//        qDebug()<<c[i];
//        qDebug()<<d[i];
//        qDebug()<<e[i];
//    }

    connect(ui->datagrambtn,SIGNAL(&QToolButton::clicked),this,SLOT(on_datagrambtn_clicked()));
    ui->label_4->setMinimumSize(481,51);
    layout = new QVBoxLayout(ui->stackedWidget->widget(3));
    layout->addWidget(ui->label_4);
    //增加按钮
    button_ptr = new QPushButton(QStringLiteral("详细信息"),ui->stackedWidget->widget(3));
    button_dayChart = new QPushButton(QStringLiteral("日视图"),this);
    button_monChart = new QPushButton(QStringLiteral("月视图"),this);
    button_yearChart = new QPushButton(QStringLiteral("年视图"),this);
    button_ptr->setMinimumHeight(51);
    button_dayChart->setMinimumHeight(51);
    button_monChart->setMinimumHeight(51);
    button_yearChart->setMinimumHeight(51);
    button_ptr->setStyleSheet(
                "QPushButton{border: 1px solid gray;background-color: white;border-radius:15px;font:20px;font-family: Segoe UI;}"
                "QPushButton:hover{background-color: rgb(181, 225, 250);}"
                "QPushButton:pressed{background-color:rgb(250, 225, 250);}");
    button_dayChart->setStyleSheet(
                "QPushButton{border: 1px solid gray;background-color: white;border-radius:15px;font:20px;font-family: Segoe UI;}"
                "QPushButton:hover{background-color: rgb(181, 225, 250);}"
                "QPushButton:pressed{background-color:rgb(250, 225, 250);}");
    button_monChart->setStyleSheet(
                "QPushButton{border: 1px solid gray;background-color: white;border-radius:15px;font:20px;font-family: Segoe UI;}"
                "QPushButton:hover{background-color: rgb(181, 225, 250);}"
                "QPushButton:pressed{background-color:rgb(250, 225, 250);}");
    button_yearChart->setStyleSheet(
                "QPushButton{border: 1px solid gray;background-color: white;border-radius:15px;font:20px;font-family: Segoe UI;}"
                "QPushButton:hover{background-color: rgb(181, 225, 250);}"
                "QPushButton:pressed{background-color:rgb(250, 225, 250);}");
    layoutH = new QHBoxLayout();
    layoutH->addWidget(button_dayChart);
    layoutH->addWidget(button_monChart);
    layoutH->addWidget(button_yearChart);
    layout->addLayout(layoutH);
    connect(button_ptr,SIGNAL(clicked()),this,SLOT(on_button_ptr_clicked()));
}



MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_datagrambtn_clicked()
{
    QPieSeries *series = new QPieSeries();
        series->append("Jane", 1);
        series->append("Joe", 2);
        series->append("Andy", 3);
        series->append("Barbara", 4);
        series->append("Axel", 5);

        QPieSlice *slice = series->slices().at(1);
        slice->setExploded();
        slice->setLabelVisible();
        slice->setPen(QPen(Qt::darkGreen, 2));
        slice->setBrush(Qt::green);

        QPieSlice *slice0 = series->slices().at(0);
        slice0->setExploded();
        slice0->setLabelVisible();
        slice0->setPen(QPen(Qt::darkGreen, 2));
        slice0->setBrush(Qt::green);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Simple piechart example");
        //chart->legend()->hide();
        chart->series().at(0)->setName(QString("Jane"));
        chart->legend()->markers().at(0)->setVisible(true);

        chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        setAutoFillBackground(true);
        //connect(series, SIGNAL(hovered(bool, int, QBarSet*)), this, SLOT(sltTooltip(bool, int, QBarSet*)));
        int cc = ui->stackedWidget->widget(3)->layout()->count();
        qDebug()<<cc;
        if(cc == 4)
        {
            return;
        }
        else
        {
            // 添加图表视图到布局
            layout->addWidget(chartView);
            layout->addWidget(button_ptr);
            ui->stackedWidget->widget(3)->setLayout(layout);
            this->show();
        }

}

void MainWindow::on_button_ptr_clicked()
{
//    QMessageBox msg;
//    msg.setText(QStringLiteral("test"));
//    msg.exec();
    dataShowdtl = new dataShowDtl(this);
    dataShowdtl->show();

}


int MainWindow::paintPie(QString cbuff,int itemCount)
{
    QPieSeries *series = new QPieSeries();
        series->append("Jane", 1);
        series->append("Joe", 2);
        series->append("Andy", 3);
        series->append("Barbara", 4);
        series->append("Axel", 5);

        QPieSlice *slice = series->slices().at(1);
        slice->setExploded();
        slice->setLabelVisible();
        slice->setPen(QPen(Qt::darkGreen, 2));
        slice->setBrush(Qt::green);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Simple piechart example");
        chart->legend()->hide();

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        setAutoFillBackground(true);

        int cc = ui->stackedWidget->widget(3)->layout()->count();
        if(cc == 2)
        {
            return 0;
        }
        else
        {
            // 添加图表视图到布局
            layout->addWidget(chartView);
            ui->stackedWidget->widget(3)->setLayout(layout);
            this->show();
        }
}


/*四象限展示*/
/*鼠标点击gridding弹出添加任务的对话框*/
bool MainWindow::eventFilter(QObject* watched, QEvent* event )
{
    if(watched==ui->gridding)
    {
        if (event->type() == QEvent::MouseButtonPress){
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            //网格侧边距为25，网格范围x(25,425) y(25,425)
            if(mouseEvent->x()>25&&mouseEvent->x()<425&&mouseEvent->y()>25&&mouseEvent->y()<425){
                int click_x = (mouseEvent->x()-25)/50;
                int click_y = (mouseEvent->y()-25)/50;
                qDebug()<<"emergency="<<click_x;
                qDebug()<<"importance="<<click_y;
                /**弹出添加Quadrant窗口**/
                AddQuadrant(click_x,click_y);
            }
            return true;  //处理结束返回true,也就是过滤掉了这个事件
        }
        else {
            return false; //其他事件还是要继续处理，所以返回 false
        }
    }
    else
    {
        return QMainWindow::eventFilter(watched, event);
    }
}



/**创建添加Quadrant的窗口**/
void MainWindow::AddQuadrant(int click_x,int click_y)
{
    /*遮罩*/
    Mask* mask=new Mask(this);
    /*添加Quadrant窗口*/
    QWidget* addQua = new QWidget(mask);
    addQua->setFixedSize(310,200);
    addQua->move(80,250);
    addQua->setStyleSheet("QWidget{background-color: white;border: 1px solid gray;border-radius:30px;font-family: Segoe UI;}");
    addQua->show();
    mask->setRect(addQua->geometry());
    /*输入标题*/
    QLineEdit* name = new QLineEdit(addQua);
    name->setFixedSize(100,21);
    name->move(30,30);
    name->setStyleSheet("QLineEdit{border:1px solid white;border-bottom-color:gray;background-color:white;}");
    name->show();
    name->setPlaceholderText("输入专注事项");
    /*从工作流导入*/
    QPushButton* workbtn = new QPushButton(addQua);
    workbtn->setFixedSize(75,40);
    workbtn->move(210,20);
    workbtn->setText("工作流");
    workbtn->setStyleSheet("QPushButton{border: 1px solid gray;background-color: white;border-radius:15px;font:12px; font-family: Segoe UI;}"
                           "QPushButton:pressed{background-color: gray;}");
    workbtn->show();

    /*截止时间*/
    QLabel* label=new QLabel(addQua);
    label->setFixedSize(60,20);
    label->move(30,60);
    label->setStyleSheet("QLabel{background-color: white;border-color:white;}");
    label->setText("截止时间：");
    label->show();
    QDateTimeEdit* edit = new QDateTimeEdit(addQua);
    edit->setFixedSize(110,20);
    edit->move(90,60);
    edit->setStyleSheet("QDateTimeEdit{border:0px solid white;background-color:white;}");
    edit->show();
    connect(edit,&QDateTimeEdit::timeChanged,[=](){
        QDateTime dt=edit->dateTime();
        if(edit->time().hour()==23&&edit->time().minute()==59){
            dt.setDate(edit->dateTime().date().addDays(1));
            dt.setTime(QTime(0,0));
            edit->setDateTime(dt);
        }
    });
    QDateTime current=QDateTime::currentDateTime();
    current=current.addDays(8-(click_x+1));
    current=current.addSecs(60);

    edit->setDateTimeRange(current,current.addDays(1));
    /*输入描述*/
    QLineEdit* text = new QLineEdit(addQua);
    text->setFixedSize(260,20);
    text->setPlaceholderText("具体描述");
    text->move(30,110);
    text->setStyleSheet("QLineEdit{border:1px solid white;border-bottom-color: gray;background-color:white;}");
    text->show();
    /*完成按钮*/
    QPushButton* finishbtn = new QPushButton(addQua);
    finishbtn->setFixedSize(100,35);
    finishbtn->move(110,150);
    finishbtn->setText("完成");
    finishbtn->setStyleSheet("QPushButton{border: 1px solid gray;background-color: white;border-radius:15px;font:12px; font-family: Segoe UI;}"
                           "QPushButton:pressed{background-color: gray;}");
    finishbtn->show();
    connect(finishbtn,&QPushButton::clicked,[=](){
        //创建Quadrant节点并放入链表
        QuadrantItem* pdata=new QuadrantItem(click_x,click_y,current,name->displayText(),text->displayText(),ui->gridding);
        qualist->InsertDataAtHead(pdata);
        //刷新窗口
        this->RefreshQuadrant();
        //析构添加节点的窗口
        mask->~Mask();
    });
    //从工作流中选择
//    connect(workbtn,&QPushButton::clicked,[=](){
//        name->
//    });
}
/**创建添加Schedule的窗口**/
void MainWindow::AddSchedule()
{
    /*遮罩*/
    Mask* mask=new Mask(this);
    /*添加Schedule窗口*/
    QWidget* addSche = new QWidget(mask);
    addSche->setFixedSize(320,170);
    addSche->move(80,210);
    addSche->setStyleSheet("QWidget{background-color: white;border: 1px solid gray;border-radius:30px;font-family: Segoe UI;}");
    addSche->show();
    mask->setRect(addSche->geometry());
    /*输入标题*/
    QLineEdit* name = new QLineEdit(addSche);
    name->setFixedSize(100,20);
    name->move(40,30);
    name->setStyleSheet("QLineEdit{border:1px solid white;border-bottom-color:gray;background-color:white;}");
    name->show();
    name->setPlaceholderText("添加日程");
    /*从工作流导入*/
    QPushButton* workbtn = new QPushButton(addSche);
    workbtn->setFixedSize(110,40);
    workbtn->move(190,30);
    workbtn->setText("从工作流中选取");
    workbtn->setStyleSheet("QPushButton{border: 1px solid gray;background-color: white;border-radius:15px;font:12px; font-family: Segoe UI;}"
                           "QPushButton:pressed{background-color: gray;}");
    workbtn->show();
    /*输入描述*/
    QLineEdit* text = new QLineEdit(addSche);
    text->setFixedSize(140,20);
    text->setPlaceholderText("具体描述");
    text->move(40,60);
    text->setStyleSheet("QLineEdit{border:1px solid white;border-bottom-color: gray;background-color:white;}");
    text->show();
    /*时间label*/
    QLabel* label=new QLabel(addSche);
    label->setFixedSize(110,20);
    label->move(40,90);
    label->setStyleSheet("QLabel{background-color: white;border-color:white;}");
    label->setText("时间:");
    label->show();
    /*~*/
    QLabel* label2=new QLabel(addSche);
    label2->setFixedSize(15,20);
    label2->move(130,90);
    label2->setStyleSheet("QLabel{background-color: white;border-color:white;}");
    label2->setText("~");
    label2->show();
    /*开始时间*/
    QTimeEdit* starttime = new QTimeEdit(addSche);
    starttime->setFixedSize(50,20);
    starttime->move(80,90);
    starttime->setStyleSheet("QTimeEdit{border:1px solid white;background-color:white;border-bottom-color: gray;font:15px; }");
//                             "QTimeEdit::up-button{background-color:white;}"
//                             "QTimeEdit::down-button{background-color:white;}"
    starttime->show();
    /*结束时间*/
    QTimeEdit* endtime = new QTimeEdit(addSche);
    endtime->setFixedSize(50,20);
    endtime->move(150,90);
    endtime->setStyleSheet("QTimeEdit{border:1px solid white;background-color:white;border-bottom-color: gray;font:15px; }");
//                             "QTimeEdit::up-button{border-color:white;background-color:black;}"
//                             "QTimeEdit::down-button{border-color:white;background-color:black;}"
    endtime->show();
    /*完成按钮*/
    QPushButton* finishbtn = new QPushButton(addSche);
    finishbtn->setFixedSize(100,35);
    finishbtn->move(110,120);
    finishbtn->setText("完成");
    finishbtn->setStyleSheet("QPushButton{border: 1px solid gray;background-color: white;border-radius:15px;font:12px; font-family: Segoe UI;}"
                           "QPushButton:pressed{background-color: gray;}");
    finishbtn->show();
    connect(finishbtn,&QPushButton::clicked,[=](){
        //创建ScheItem节点并放入链表
        ScheItem* pdata=new ScheItem(name->displayText(),text->displayText(),starttime->time(),endtime->time(),ui->ScheScrollAreaWidgetContents);
        schelist->InsertDataAtRear(pdata);
        //刷新窗口
        this->RefreshSchedule();
        //析构添加节点的窗口
        mask->~Mask();
    });
}
/**创建添加WorkTree的窗口**/
void MainWindow::AddWorkTree()
{
    /*遮罩*/
    Mask* mask=new Mask(this);
    /*添加WorkTree窗口*/
    QWidget* addWork = new QWidget(mask);
    addWork->setFixedSize(260,130);
    addWork->move(110,260);
    addWork->setStyleSheet("QWidget{background-color: white;border: 1px solid gray;border-radius:30px;font-family: Segoe UI;}");
    addWork->show();
    mask->setRect(addWork->geometry());
    /*输入标题*/
    QLineEdit* name = new QLineEdit(addWork);
    name->setFixedSize(100,21);
    name->move(30,30);
    name->setStyleSheet("QLineEdit{border:1px solid white;border-bottom-color:gray;background-color:white;}");
    name->show();
    name->setPlaceholderText("创建任务树");
    /*完成按钮*/
    QPushButton* finishbtn = new QPushButton(addWork);
    finishbtn->setFixedSize(100,35);
    finishbtn->move(80,80);
    finishbtn->setText("完成");
    finishbtn->setStyleSheet("QPushButton{border: 1px solid gray;background-color: white;border-radius:15px;font:12px; font-family: Segoe UI;}"
                           "QPushButton:pressed{background-color: gray;}");
    finishbtn->show();
    connect(finishbtn,&QPushButton::clicked,[=](){
        //创建WorkTree节点并放入链表
        WorkItem* pdata=new WorkItem(name->displayText());
        workScene->addWidget(pdata);
        worklist->InsertDataAtRear(pdata);
        //刷新窗口
        this->RefreshWorkTree();
        //析构添加节点的窗口
        mask->~Mask();
    });
}


/*四象限的刷新*/
void MainWindow::RefreshQuadrant()
{
    Node<QuadrantItem>* p=qualist->head;
    while(p->next){
        if(p->next->data->Quadrant::update()) {
            p->next->data->close();
            qualist->DeleteElement(p->next);   //从链表删除改节点
        }
        else{
            p->next->data->Reflesh();   //更新该节点打印位置
            p=p->next;
        }
    }
}
/*日程的刷新*/
void MainWindow::RefreshSchedule()
{
    QPoint* pbase=new QPoint(50,50);   //打印的基点
    int direct=110+20;  //110是ScheItem的高，20是间隔
    int i=0;
    Node<ScheItem>* p=schelist->head;
    while(p->next){
        pbase->setY(pbase->y()+direct*i);
        p->next->data->Reflesh(pbase);
        p=p->next;
        ++i;
    }
}
/*工作流的刷新*/
void MainWindow::RefreshWorkTree()
{  
    QPoint pbase(30,50);   //打印的基点
    int direct=110+20;  //110是WorkItem的高，20是间隔
    Node<WorkItem>* p=worklist->head;
    while(p->next){
        pbase.setY(pbase.y());
        p->next->data->Reflesh(pbase);
        pbase.setY(pbase.y()+direct);
        p=p->next;
    }
}
