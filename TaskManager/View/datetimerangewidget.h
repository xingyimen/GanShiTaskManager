#ifndef DATETIMERANGEWIDGET_H
#define DATETIMERANGEWIDGET_H

#include <QWidget>
#include <QTime>
#include "mytime.h"
#include "datalist.h"

namespace Ui {
class DateTimeRangeWidget;
}

class DateTimeRangeWidget : public QWidget,public DataList
{
    Q_OBJECT

public:
    explicit DateTimeRangeWidget(std::string name,QDateTime date ,QTime start_time, QTime finish_time,QWidget *parent = nullptr);
    ~DateTimeRangeWidget();
    void Reflesh(QPoint point);
signals:
    void signal_dateTime(const QString& strDate);
    void signal_cancel();

private:
    void initPage();

    Ui::DateTimeRangeWidget *ui;
};

#endif // DATETIMERANGEWIDGET_H
