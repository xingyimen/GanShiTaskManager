#include "quadrantitem.h"
#include "ui_quadrantitem.h"
#include <QDebug>
#include "mytime.h"
#include "mask.h"
#include <QLineEdit>
#include <QLabel>
#include <QDateTimeEdit>
extern QWidget* mainwid_p;
/*全局变量Quadrant的链表*/
extern Linklist<QuadrantItem>* qualist;
QuadrantItem::QuadrantItem(int x, int y, QDateTime dt,QString name, QString description,QWidget *parent) :
    QWidget(parent),Quadrant(x,
                             y,
                             MyDate(dt.date().year(),dt.date().month(),dt.date().day()),
                             MyTime(dt.time().hour(),dt.time().minute()),
                             name.toStdString().c_str(),
                             description.toStdString().c_str()),
    ui(new Ui::QuadrantItem)
{

    ui->setupUi(this);  
    ui->qua_item->setText(return_name().c_str());
    show();
    connect(ui->qua_item,&QPushButton::clicked,this,&QuadrantItem::Check);


}

QuadrantItem::~QuadrantItem()
{
    qDebug()<<"析构QuadrantItem";
    delete ui;
}

void QuadrantItem::Reflesh(){
   move(25+(return_rol()*50),25+(return_col()*50));
}

void QuadrantItem::Check(){
    /*遮罩*/
    Mask* mask=new Mask(mainwid_p);
    /*Quadrant窗口*/
    QWidget* deleQua = new QWidget(mask);
    deleQua->setFixedSize(310,200);
    deleQua->move(80,250);
    deleQua->setStyleSheet("QWidget{background-color: white;border: 1px solid gray;border-radius:30px;font-family: Segoe UI;}");
    deleQua->show();
    mask->setRect(deleQua->geometry());
    /*输入标题*/
    QLineEdit* name = new QLineEdit(deleQua);
    name->setFixedSize(100,50);
    name->move(40,30);
    name->setStyleSheet("QLineEdit{font:25px;border:1px solid white;background-color:white;}");
    name->setReadOnly(true);
    name->setText(this->return_name().c_str());
    name->show();
    /*输入描述*/
    QLineEdit* text = new QLineEdit(deleQua);
    text->setFixedSize(140,20);
    text->setReadOnly(true);
    text->move(40,110);
    text->setStyleSheet("QLineEdit{border:1px solid white;background-color:white;}");
    text->setText(this->return_description().c_str());
    text->show();
    /*截止时间*/
    QLabel* label=new QLabel(deleQua);
    label->setFixedSize(60,20);
    label->move(40,80);
    label->setStyleSheet("QLabel{background-color: white;border-color:white;}");
    label->setText("截止时间：");
    label->show();
    QDateTimeEdit* edit = new QDateTimeEdit(deleQua);
    edit->setFixedSize(110,20);
    edit->move(100,80);
    edit->setStyleSheet("QDateTimeEdit{border:0px solid white;background-color:white;}"
                        "QDateTimeEdit::up-button{border-color:white;}"
                        "QDateTimeEdit::down-button{border-color:white;}"
                        );
    edit->setReadOnly(true);
    edit->setDate(QDate(this->return_enddate().year,this->return_enddate().month,this->return_enddate().day));
    edit->setTime(QTime(this->return_endtime().hour,this->return_endtime().minute));
    edit->show();
    /*删除按钮*/
    QPushButton* deletebtn = new QPushButton(deleQua);
    deletebtn->setFixedSize(100,35);
    deletebtn->move(110,150);
    deletebtn->setText("删除");
    deletebtn->setStyleSheet("QPushButton{border: 1px solid gray;background-color: white;border-radius:15px;font:12px; font-family: Segoe UI;}"
                           "QPushButton:pressed{background-color: gray;}");
    deletebtn->show();
    connect(deletebtn,&QPushButton::clicked,[=](){

        qualist->DeleteData(this);   //从链表删除改节点
        mask->~Mask();
    });
}


