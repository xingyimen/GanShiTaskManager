#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonValue>
#include<QtDebug>
#include<QFile>
#include<QString>
#include<QCoreApplication>
#include<QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QJsonDocument doc;
    if(doc.isEmpty())
    {
        qDebug()<<"json doucument id empty";
    }
    if(doc.isNull())
    {
        qDebug()<<"json doucument id null";
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

