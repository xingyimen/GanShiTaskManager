#include "login.h"
#include "ui_login.h"


extern User_sql mysql;
int user_id;
extern QSqlDatabase database;

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->lineEdit_pwd->setEchoMode(QLineEdit::Password);
    ui->lineEdit_name->setPlaceholderText("账号");
    ui->lineEdit_pwd->setPlaceholderText("密码");
    setWindowTitle("干事");
    if(!mysql.connect_mysql(database))  QMessageBox::information(this,"警告","驱动加载失败！",QMessageBox::Ok);
    connect(ui->pushButton_login,SIGNAL(clicked()),this,SLOT(on_btn_login_clicked()));
    connect(ui->pushButton_register,SIGNAL(clicked()),this,SLOT(on_btn_register_clicked()));
    //createConnection();
}

login::~login()
{
    delete ui;
}


void login::on_btn_login_clicked()
{
    QString username = ui->lineEdit_name->text();
    QString password = ui->lineEdit_pwd->text();

    if(username == "" ||password == ""){
        QMessageBox::information(this,"警告","输入不能为空",QMessageBox::Ok);
    }else{

        QSqlQuery query(database);
        QString sql_s="SELECT id FROM tomato.users where username='"+username+"' and password='"+password+"';";
        query.exec(sql_s);
//        query.prepare("select username,password from users where username=:username and password = :password ");
//        query.bindValue(":username", username);
//        query.bindValue(":password", password);
//        query.exec();
        if(!query.next())
        {
            //结果集为空
            //执行某操作
            QMessageBox::information(this,"警告","用户名或密码错误！",QMessageBox::Ok);
        }
        else
        {
            QMessageBox::information(this,"提醒","登录成功！",QMessageBox::Ok);
            user_id=query.value("id").toInt();
            qDebug()<<"用户ID："<<user_id;
            MainWindow *m = new MainWindow;
            m->show();
            this->close();
        }
    }

//    QSqlQuery query(database);
//    QString sql_s="SELECT id FROM tomato.users where username='"+name+"' and password='"+passwd+"';";
//    if(!query.exec(sql_s))
//    {
//        qDebug()<<"登录失败,请重新输入用户名和密码"<<database.lastError();
//        return 0;
//    }
//    else
//    {
//        query.next();
//        int id=query.value("id").toInt();
//        qDebug()<<"登录成功"<<"用户id为"<<id;
//        return id;
//    }

}

void login::on_btn_register_clicked()
{
    Register *r = new Register;
    r->show();
}

//bool login::createConnection()
//{
//    //测试用例：连接mysql数据库，做一个基本的sql语句操作

//    //1、对qt下数据库的驱动进行遍历查看
//    QStringList drivers = QSqlDatabase::drivers();
//    foreach (QString driver, drivers) {
//        qDebug()<<drivers;

//    }

//    //2、打开数据库过程
//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//    //数据库连接的信息进行配置
//    db.setHostName("localhost");//设置主机名（数据库所在电脑的名称）
//    db.setDatabaseName("medical_system");//设置数据库名称
//    db.setUserName("root");
//    db.setPassword("123456");
//    //db.setPort(3306);//因为是本机，该段代码可省略

//    if(!db.open()){
//        //打开失败的情况
//        qDebug()<<"Failed to connect";

//        //实际情况下我们应该使用图形化窗口提示打开失败
//        QMessageBox::critical(0,"无法打开数据库","无法创建",QMessageBox::Yes);
//        return false;
//    }

//    return true;


//}


