#include "register.h"
#include "ui_register.h"

extern int user_id;
extern QSqlDatabase database;

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_btn_logon_clicked()));
    ui->lineEdit_username->setPlaceholderText("账户");
    ui->lineEdit_pwd->setPlaceholderText("密码");
    ui->lineEdit_mail->setPlaceholderText("E-mail");
}

Register::~Register()
{
    delete ui;
}

void Register::on_btn_logon_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_pwd->text();
    QString mail = ui->lineEdit_mail->text();

    QSqlQuery query;
    query.prepare("select username from users where username=:username");
    query.bindValue(":username", username);
    query.exec();
    if(query.next())
    {

        QMessageBox::information(this,"警告","用户名已存在！",QMessageBox::Ok);

    }
    else
    {
        query.prepare("insert into users(username,password,email)"
                      "values(:username,:password,:email)");
        query.bindValue(":username", username);
        query.bindValue(":password",password);
        query.bindValue(":email", mail);
        query.exec();
        QMessageBox::information(this,"警告","注册成功！",QMessageBox::Ok);
        this->close();
    }
//    QSqlQuery query(database);
//    QString sql_s="insert into users(id,username,password) values(NULL,'"+name+"','"+passwd+"');";
//    if(!query.exec(sql_s))
//    {
//        qDebug()<<"插入错误"<<"用户名已存在";
//        return;
//    }
//    else
//    {
//        qDebug()<<"插入成功";
//    }
}
