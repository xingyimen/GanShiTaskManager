#ifndef ADDPOMODORO_H
#define ADDPOMODORO_H

#include <QWidget>

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
protected:
    virtual void mousePressEvent(QMouseEvent *event);
private:
    Ui::AddPomodoro *ui;
};

#endif // ADDPOMODORO_H
