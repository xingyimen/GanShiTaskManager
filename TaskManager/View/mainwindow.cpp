#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menuwidget.h"
#include <QDebug>
#include "addschedule.h"
#include "addpomodoro.h"
#include <QMouseEvent>
#include "addquadrant.h"
#include "myjsonobject.h"   //数据存储
#include <QStringList>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
        ui->schedule->RefreshScheitem();
        ui->schedulebtn->setChecked(true);
        ui->workflowbtn->setChecked(false);
        ui->quadrantbtn->setChecked(false);
        ui->datagrambtn->setChecked(false);
        ui->setbtn->setChecked(false);
    });
    connect(ui->workflowbtn,&QToolButton::clicked,[=](){
        ui->stackedWidget->setCurrentWidget(ui->workflow);
        ui->schedulebtn->setChecked(false);
        ui->workflowbtn->setChecked(true);
        ui->quadrantbtn->setChecked(false);
        ui->datagrambtn->setChecked(false);
        ui->setbtn->setChecked(false);
    });
    connect(ui->quadrantbtn,&QToolButton::clicked,[=](){
        ui->stackedWidget->setCurrentWidget(ui->quadrant);
        ui->schedulebtn->setChecked(false);
        ui->workflowbtn->setChecked(false);
        ui->quadrantbtn->setChecked(true);
        ui->datagrambtn->setChecked(false);
        ui->setbtn->setChecked(false);
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

    /**********添加任务**********/
    //添加番茄钟
    connect(ui->pomodorobtn,&QToolButton::clicked,[=](){
        AddPomodoro* pomodoro=new AddPomodoro(this);
        pomodoro->show();
    });
    //添加日程
    connect(ui->sche_addbtn,&QToolButton::clicked,[=](){
        AddSchedule* schedule=new AddSchedule(this);
        schedule->show();
    });
    //添加四象限
    //安装过滤器
    ui->gridding->installEventFilter(this);



//   QString theme;
//   QString describe;
//   QString start_time;
//   QString end_time;
//   QString id;

   QStringList theme,describe,start_time,end_time,id,a,b,c,d,e;




    MyJsonObject test;
    test.readJson(theme,describe,start_time,end_time,id,a,b,c,d,e);
    for(int i=0;i<=1;i++){
        qDebug()<<a[i];
        qDebug()<<b[i];
        qDebug()<<c[i];
        qDebug()<<d[i];
        qDebug()<<e[i];
    }













}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::eventFilter(QObject* watched, QEvent* event ){
    if(watched==ui->gridding){
        if (event->type() == QEvent::MouseButtonPress){
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            //网格侧边距为25，网格范围x(25,425) y(25,425)
            if(mouseEvent->x()>25&&mouseEvent->x()<425&&mouseEvent->y()>25&&mouseEvent->y()<425){
                int click_x = (mouseEvent->x()-25)/50;
                int click_y = (mouseEvent->y()-25)/50;
                qDebug()<<"emergency="<<click_x;
                qDebug()<<"importance="<<click_y;
                AddQuadrant* qw=new AddQuadrant(click_x,click_y,this);
                qw->show();
            }
            return true;  //处理结束返回true,也就是过滤掉了这个事件
        }
        else {
            return false; //其他事件还是要继续处理，所以返回 false
        }
    }
    else{
        return QMainWindow::eventFilter(watched, event);
    }
}



void MainWindow::InsertQuadrant(){

}

