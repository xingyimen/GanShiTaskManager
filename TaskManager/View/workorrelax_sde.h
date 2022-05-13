#ifndef WORKORRELAX_SDE_H
#define WORKORRELAX_SDE_H

#include <QWidget>
#include <QLCDNumber>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTimer>
#include <QTime>
#include "user_sql.h"

namespace Ui {
class workOrrelax_sde;
}

class workOrrelax_sde : public QWidget
{
    Q_OBJECT

public:
    explicit workOrrelax_sde(QWidget *parent = nullptr);
    ~workOrrelax_sde();
    void onShowTime(int minute, int relaxminute,QString theme_text);
    int relaxminute;
signals:
    void closedown();

public slots:
    void onTimeout();
    void onRelaxShowTime();
    void pauseTimer();
private:
    QTimer *timer;
    int minute=25,second=0;
    QVBoxLayout *layout;
    QPushButton *startbutton;
    QString stratTime;
    QString endTime;
    QString endDate;
    QString theme_textMain;
private:
    Ui::workOrrelax_sde *ui;
};

#endif // WORKORRELAX_SDE_H
