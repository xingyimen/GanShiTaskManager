#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLineEdit>
#include <QMessageBox>
#include <QSqlQuery>
#include "mainwindow.h"
#include "register.h"

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    bool createConnection();
private slots:
    void on_btn_login_clicked();
    void on_btn_register_clicked();

private:
    MainWindow* m;
    Ui::login *ui;
};

#endif // LOGIN_H
