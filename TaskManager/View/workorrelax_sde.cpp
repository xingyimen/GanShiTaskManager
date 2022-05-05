#include "workorrelax_sde.h"
#include "ui_workorrelax_sde.h"

workOrrelax_sde::workOrrelax_sde(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::workOrrelax_sde)
{
    ui->setupUi(this);
    ui->label->setAlignment(Qt::AlignHCenter);
    ui->lcdNumber->display("00:00");
    timer=new QTimer();
    //timer->setInterval(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimeout()));
    timer->setInterval(1000);
    timer->start();
    connect(ui->pushButton_stop,SIGNAL(clicked()),this,SLOT(onRelaxShowTime()));
    ui->label_pp->setAlignment(Qt::AlignHCenter);
    ui->label_pp->setText("");
    connect(ui->pushButton_pause,SIGNAL(clicked()),this,SLOT(pauseTimer()));
    //onShowTime(25,"haha");

}

workOrrelax_sde::~workOrrelax_sde()
{
    delete ui;
}

void workOrrelax_sde::onShowTime(int minu,int relaxmin, QString theme_text)
{
    ui->label->setText(theme_text);
    minute = minu;
    second = 0;
    QString s_minute = QString::number(minute) + ":00";
    relaxminute = relaxmin;
    ui->label_pp->setText(QStringLiteral("专注中"));
    ui->lcdNumber->display(s_minute);
}

void workOrrelax_sde::onRelaxShowTime()
{
    QString s_minute = QString::number(relaxminute) + ":00";
    minute = relaxminute;
    second = 0;
    disconnect(timer,SIGNAL(timeout()),this,SLOT(onTimeout()));
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimeout()));
    if(ui->label_pp->text() == "休息中")
    {
        emit closedown();
        this->close();
    }
    if(ui->label_pp->text() == "专注中")
    {
        ui->label_pp->setText(QStringLiteral("休息中"));
        ui->lcdNumber->display(s_minute);
    }
}

void workOrrelax_sde::pauseTimer()
{
    if(ui->pushButton_pause->text() == "暂停")
    {
        timer->stop();
        ui->pushButton_pause->setText(QStringLiteral("继续"));
        return;
    }
    if(ui->pushButton_pause->text() == "继续")
    {
        timer->start();
        ui->pushButton_pause->setText(QStringLiteral("暂停"));
        return;
    }
}

void workOrrelax_sde::onTimeout(){
    QString s_minute=QString::number(minute);
    QString s_second=QString::number(second);
    if (s_minute.length()==1)   s_minute="0"+s_minute;
    if(s_second.length()==1)    s_second="0"+s_second;
    QString disp=s_minute+":"+s_second;
    ui->lcdNumber->display(disp);
    //QTime time = QTime::currentTime();
    //lcd->display(time.toString("mm:ss"));
    if((minute!=0)|(second!=0)){
        if(second==0){
            second=59;
            minute--;}
        else
            second--;
    }
    else
    {
        this->close();
    }
}
