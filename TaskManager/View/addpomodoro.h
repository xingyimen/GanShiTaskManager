#ifndef ADDPOMODORO_H
#define ADDPOMODORO_H

#include <QWidget>
#include "workorrelax_sde.h"

namespace Ui {
class AddPomodoro;
}

class AddPomodoro : public QWidget
{
    Q_OBJECT

public:
    explicit AddPomodoro(QWidget *parent = nullptr);
    ~AddPomodoro();
    //打开番茄钟
    void OpenPomodoro();
public slots:
    void closepom();

private slots:
    void btn_begin();
protected:
    virtual void mousePressEvent(QMouseEvent *event);
private:
    workOrrelax_sde* workOrrelax;
    bool b_mouseEve;
    Ui::AddPomodoro *ui;
};

#endif // ADDPOMODORO_H
