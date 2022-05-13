#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include <QButtonGroup>
#include <QMessageBox>
#include <QRegExp>
#include <QSqlQuery>

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_btn_logon_clicked();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
