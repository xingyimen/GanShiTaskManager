#ifndef DATETIMERANGEWIDGET_H
#define DATETIMERANGEWIDGET_H

#include <QWidget>

namespace Ui {
class DateTimeRangeWidget;
}

class DateTimeRangeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DateTimeRangeWidget(QWidget *parent = nullptr);
    ~DateTimeRangeWidget();
signals:
    void signal_dateTime(const QString& strDate);
    void signal_cancel();

private:
    void initPage();
    Ui::DateTimeRangeWidget *ui;
};

#endif // DATETIMERANGEWIDGET_H
