#include "datashowdtl.h"
#include "ui_datashowdtl.h"

dataShowDtl::dataShowDtl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dataShowDtl)
{
    ui->setupUi(this);
    this->setFixedSize(480,740); //设置窗体固定大小
    this->move(0,0);
    this->setStyleSheet("background-color : rgb(244, 244, 244);");
    //setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    CalendWnd = new QCalendarWidget(this);
    CalendWnd->setHidden(true);
    connect(ui->toolButton_date,SIGNAL(clicked()),this,SLOT(showTimeslots()));
    //CalendWnd = new QCalendarWidget();
    //时间控件点击事件
    connect(CalendWnd,SIGNAL(activated(QDate)),this,SLOT(setDate()));

    //CalendWnd->setHidden(true);
    ui->dateEdit->setDisplayFormat("yyyy-MM-dd");
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
    CalendWnd->setFocusPolicy(Qt::NoFocus);
    QFont font("黑体", 12);
    ui->dateEdit->setFont(font);
    ui->dateEdit->setStyleSheet(QString("QDateEdit{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, "
                                            "stop:0 rgba(250, 250, 250, 255), "
                                            "stop:0.5 rgba(240, 240, 240, 255), "
                                            "stop:1 rgba(230, 230, 230, 255));"
                                            "border: 1px solid rgb(200, 200, 200);"
                                            "border-radius: 4px;"
                                            "padding-left:%2px;}"
                                            "QDateEdit::drop-down{width:%1px;border-image: url(:/menu/res/drop-down-arrow.png);}")
                                        .arg(35).arg(10));
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




}

dataShowDtl::~dataShowDtl()
{
    delete ui;
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
    qDebug()<<str;

    addForm();
}

void dataShowDtl::addForm()
{
    CalendWnd->setHidden(true);
    dateWnd = new DateTimeRangeWidget();
    ui->verticalLayout_3->addWidget(dateWnd);

}
