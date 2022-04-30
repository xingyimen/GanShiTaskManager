#include "mainwindow.h"
#include "myjsonobject.h"
#include<QDebug>


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    MyJsonObject example1;

    QStringList THEME,Describe,Start_Time,End_Time,Id,b,c,d,e,f;
    example1.readJson(THEME,Describe,Start_Time,End_Time,Id,b,c,d,e,f);
    qDebug()<<b[1];
    qDebug()<<c[1];
    qDebug()<<d[1];
    qDebug()<<e[1];
    qDebug()<<f[1];
    return a.exec();
}
