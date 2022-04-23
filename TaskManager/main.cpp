#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QtSql>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "TaskManager_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    //登录窗口





    //检查驱动
//    qDebug() << QSqlDatabase::drivers();
//    //连接远程数据库
//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("124.223.188.73");
//    db.setUserName("root");
//    db.setPassword("Yintama2002");
//    db.setDatabaseName("player");

//    if(!db.open()){
//        qDebug()<< "连接失败";
//    }
//    else{
//        qDebug()<< "连接成功";
//    }


    MainWindow w;
    w.show();
    return a.exec();
}
