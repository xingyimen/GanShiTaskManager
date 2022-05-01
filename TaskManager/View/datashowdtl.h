#ifndef DATASHOWDTL_H
#define DATASHOWDTL_H

#include <QWidget>
#include <QCalendarWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QGridLayout>
#include "datetimerangewidget.h"

namespace Ui {
class dataShowDtl;
}

class dataShowDtl : public QWidget
{
    Q_OBJECT

public:
    explicit dataShowDtl(QWidget *parent = nullptr);
    ~dataShowDtl();
    void addForm();

private slots:
    void showTimeslots();
    void setDate();
signals:

protected:
     virtual void mousePressEvent(QMouseEvent *event);

private:
    QCalendarWidget* CalendWnd;
    DateTimeRangeWidget* dateWnd;
    QGridLayout *layoutG;
    QVBoxLayout *layoutV;
    Ui::dataShowDtl *ui;
};

#endif // DATASHOWDTL_H
