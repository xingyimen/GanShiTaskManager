#include "mainwindow.h"
#include "user_sql.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QtSql>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include "login.h"


QSqlDatabase database;
User_sql mysql;

int main(int argc, char *argv[])
{
    QApplication::addLibraryPath("./plugins");
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

    //连接到远程数据库
    mysql.connect_mysql(database);

    //MainWindow w;
    //登录窗口
    login w;
    w.show();
    return a.exec();
}
