#include "scheitem.h"
#include "ui_scheitem.h"

extern Linklist<ScheItem>* schelist;
extern QWidget* mainwid_p;
ScheItem::ScheItem(QString q_title, QString q_description,QTime q_starttime,QTime q_endtime,QWidget *parent) :
    QWidget(parent),Schedule(q_title.toStdString(), q_description.toStdString(), MyTime(q_starttime.hour(),q_starttime.minute(),q_starttime.second()), MyTime(q_endtime.hour(),q_endtime.minute(),q_endtime.second())),
    ui(new Ui::ScheItem)
{
    ui->setupUi(this);
    /*设置样式表*/
    ui->widget->setStyleSheet("QWidget#widget{background-color:white;border:1px solid gray;border-radius:30px;}");
    /*设置只读*/
    ui->title->setReadOnly(true);
    ui->description->setReadOnly(true);
    ui->starttime->setReadOnly(true);
    ui->endtime->setReadOnly(true);
    /*设置文字样式*/
    QFont ft;
    ft.setPointSize(18);
    ft.setFamily("黑体");
    ui->starttime->setFont(ft);
    ui->endtime->setFont(ft);
    ui->title->setFont(ft);
    ft.setPointSize(10);
    ft.setFamily("Arial");
    ui->description->setFont(ft);
    ui->description->setTextColor(QColor(130,130,130));
    ui->starttime->setDisplayFormat("HH:mm");
    ui->endtime->setDisplayFormat("HH:mm");
    /*初始化数据*/
    ui->title->setText(this->getname().c_str());
    ui->description->setText(this->getdescription().c_str());
    ui->starttime->setTime(QTime(this->getstarttime().hour,this->getstarttime().minute));
    ui->endtime->setTime(QTime(this->getendtime().hour,this->getendtime().minute));
}
ScheItem::ScheItem(ScheduleDao* item,QWidget *parent):
    QWidget(parent),Schedule(item),ui(new Ui::ScheItem)
{
    ui->setupUi(this);
    /*设置样式表*/
    ui->widget->setStyleSheet("QWidget#widget{background-color:white;border:1px solid gray;border-radius:30px;}");
    /*设置只读*/
    ui->title->setReadOnly(true);
    ui->description->setReadOnly(true);
    ui->starttime->setReadOnly(true);
    ui->endtime->setReadOnly(true);
    /*设置文字样式*/
    QFont ft;
    ft.setPointSize(18);
    ft.setFamily("黑体");
    ui->starttime->setFont(ft);
    ui->endtime->setFont(ft);
    ui->title->setFont(ft);
    ft.setPointSize(10);
    ft.setFamily("Arial");
    ui->description->setFont(ft);
    ui->description->setTextColor(QColor(130,130,130));
    ui->starttime->setDisplayFormat("HH:mm");
    ui->endtime->setDisplayFormat("HH:mm");
    /*初始化数据*/
    ui->title->setText(this->getname().c_str());
    ui->description->setText(this->getdescription().c_str());
    ui->starttime->setTime(QTime(this->getstarttime().hour,this->getstarttime().minute));
    ui->endtime->setTime(QTime(this->getendtime().hour,this->getendtime().minute));

}
ScheItem::~ScheItem()
{
    delete ui;
}
void ScheItem::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton) this->Check();
}
void ScheItem::Reflesh(QPoint point){
    move(point);
    qDebug()<<"reflesh";
    show();
}

void ScheItem::Check(){
    /*遮罩*/
    Mask* mask=new Mask(mainwid_p);
    /*Schedule窗口*/
    QWidget* deleSche = new QWidget(mask);
    deleSche->setFixedSize(320,170);
    deleSche->move(80,210);
    deleSche->setStyleSheet("QWidget{background-color: white;border: 1px solid gray;border-radius:30px;font-family: Segoe UI;}");
    deleSche->show();
    mask->setRect(deleSche->geometry());
    /*输入标题*/
    QLineEdit* name = new QLineEdit(deleSche);
    name->setFixedSize(100,30);
    name->move(40,20);
    name->setStyleSheet("QLineEdit{font:25px;border:1px solid white;background-color:white;font-family: Segoe UI;}");
    name->setReadOnly(true);
    name->setText(this->getname().c_str());
    name->show();
    /*输入描述*/
    QLineEdit* text = new QLineEdit(deleSche);
    text->setFixedSize(140,20);
    text->setReadOnly(true);
    text->move(40,60);
    text->setStyleSheet("QLineEdit{border:1px solid white;background-color:white;font-family: Segoe UI;}");
    text->setText(this->getdescription().c_str());
    text->show();
    /*时间label*/
    QLabel* label=new QLabel(deleSche);
    label->setFixedSize(110,20);
    label->move(40,90);
    label->setStyleSheet("QLabel{background-color: white;border-color:white;font-family: Segoe UI;}");
    label->setText("时间：");
    label->show();
    /*~*/
    QLabel* label2=new QLabel(deleSche);
    label2->setFixedSize(15,20);
    label2->move(140,90);
    label2->setStyleSheet("QLabel{background-color: white;border-color:white;font-family: Segoe UI;}");
    label2->setText("~");
    label2->show();
    /*开始时间*/
    QTimeEdit* starttime = new QTimeEdit(deleSche);
    starttime->setFixedSize(60,20);
    starttime->move(80,90);
    starttime->setStyleSheet("QTimeEdit{border-color:white;font:15px; font-family: Segoe UI;}"
                             "QTimeEdit::up-button{border-color:white;}"
                             "QTimeEdit::down-button{border-color:white;}");
    starttime->setReadOnly(true);
    starttime->setTime(QTime(this->getstarttime().hour,this->getstarttime().minute));
    starttime->show();
    /*结束时间*/
    QTimeEdit* endtime = new QTimeEdit(deleSche);
    endtime->setFixedSize(60,20);
    endtime->move(160,90);
    endtime->setReadOnly(true);
    endtime->setStyleSheet("QTimeEdit{border-color:white;font:15px; font-family: Segoe UI;}"
                           "QTimeEdit::up-button{border-color:white}"
                           "QTimeEdit::down-button{border-color:white}");
    endtime->setTime(QTime(this->getendtime().hour,this->getendtime().minute));
    endtime->show();
    /*删除按钮*/
    QPushButton* deletebtn = new QPushButton(deleSche);
    deletebtn->setFixedSize(100,35);
    deletebtn->move(110,120);
    deletebtn->setText("删除");
    deletebtn->setStyleSheet("QPushButton{border: 1px solid gray;background-color: white;border-radius:15px;font:12px; font-family: Segoe UI;}"
                           "QPushButton:pressed{background-color: gray;}");
    deletebtn->show();
    connect(deletebtn,&QPushButton::clicked,[=](){
        schelist->DeleteData(this);   //从链表删除改节点
        QPoint pbase(50,50);   //打印的基点
        int direct=110+20;  //110是ScheItem的高，20是间隔
        Node<ScheItem>* p=schelist->head;
        while(p->next){
            pbase.setY(pbase.y());
            p->next->data->Reflesh(pbase);
            pbase.setY(pbase.y()+direct);
            p=p->next;
        }
        mask->~Mask();
    });
}
