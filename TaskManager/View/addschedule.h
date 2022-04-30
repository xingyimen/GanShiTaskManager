#ifndef ADDSCHEDULE_H
#define ADDSCHEDULE_H

#include <QWidget>

namespace Ui {
class AddSchedule;
}

class AddSchedule : public QWidget
{
    Q_OBJECT

public:
    explicit AddSchedule(QWidget *parent = nullptr);
    ~AddSchedule();
    //打开番茄钟
    void OpenPomodoro();
protected:
    virtual void mousePressEvent(QMouseEvent *event);
private:
    Ui::AddSchedule *ui;
};

#endif // ADDSCHEDULE_H
