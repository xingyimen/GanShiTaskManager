#include "datetimerangewidget.h"
#include "ui_datetimerangewidget.h"
#include "mytime.h"

DateTimeRangeWidget::DateTimeRangeWidget(std::string name,QDateTime date ,QTime start_time, QTime finish_time,QWidget *parent) :
    QWidget(parent), DataList(name,
                              MyDate(date.date().year(),date.date().month(),date.date().day()),
                              MyTime(start_time.hour(),start_time.minute(),start_time.second()),
                              MyTime(finish_time.hour(),finish_time.minute(),finish_time.second())),	//构造函数
    ui(new Ui::DateTimeRangeWidget)
{
    ui->setupUi(this);
    int width = this->geometry().width();
    int height = this->geometry().height();
    this->setFixedSize(width,height); //设置窗体固定大小
    /*设置文字样式*/
    QFont ft;
    ft.setPointSize(15);
    ft.setFamily("Segoe UI");
    ui->label_starttime->setFont(ft);
    ui->label_endtime->setFont(ft);
    ui->label_text->setFont(ft);
    ft.setPointSize(10);
    //ui->starttime->setDisplayFormat("HH:mm");
    //ui->endtime->setDisplayFormat("HH:mm");
    /*初始化数据*/
    ui->label_text->setText(this->getname().c_str());
    ui->label_starttime->setText((QTime(this->getstarttime().hour,this->getstarttime().minute).toString("hh:mm")));
    ui->label_endtime->setText(QTime(this->getendtime().hour,this->getendtime().minute).toString("hh:mm"));

}

DateTimeRangeWidget::~DateTimeRangeWidget()
{
    delete ui;
    qDebug()<<"删除DateTimeRangeWidget";
}

void DateTimeRangeWidget::Reflesh(QPoint point){
    move(point);
    show();
}
void DateTimeRangeWidget::initPage()
{
//    connect(ui->btnYes, &QPushButton::clicked, this, [this] {

//        QString start = ui->wdgStart->datetime();
//        QString end = ui->wdgEnd->datetime();

//        emit signal_dateTime(QString("%1 - %2").arg(start).arg(end));
//    });

//    connect(ui->btnCancel, &QPushButton::clicked, this, [this] {
//        emit signal_cancel();
//    });

//    QDateTime date = QDateTime::currentDateTime();
//    ui->wdgStart->setDateTime(date.addDays(-7).toString("yyyy-MM-dd hh:mm:ss"));
}
