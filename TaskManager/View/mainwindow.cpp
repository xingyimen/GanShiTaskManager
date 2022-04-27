#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menuwidget.h"
#include <QDebug>
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

