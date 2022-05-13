#ifndef DATASHOWDTL_H
#define DATASHOWDTL_H

#include <QWidget>
#include <QCalendarWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QGridLayout>
#include "datetimerangewidget.h"
#include "user_sql.h"

#include <QGraphicsScene>

namespace Ui {
class dataShowDtl;
}

class dataShowDtl : public QWidget
{
    Q_OBJECT

public:
    explicit dataShowDtl(QWidget *parent = nullptr);
    ~dataShowDtl();
    void addForm(std::string name,QDateTime date ,QTime start_time, QTime finish_time);
    void RefreshDatalist();
    void clearLayout(QLayout *layout);

private slots:
    void showTimeslots();
    void setDate();
    void setUiDate(QDate);
signals:

protected:
     virtual void mousePressEvent(QMouseEvent *event);

private:
    QCalendarWidget* CalendWnd;
    DateTimeRangeWidget* dateWnd;
    QGridLayout *layoutG;
    QVBoxLayout *layoutV;
    User_sql* userSql;
    //QSqlDatabase database;
    QSqlQuery query;
    Ui::dataShowDtl *ui;


    QGraphicsScene* dataScene;
};

#endif // DATASHOWDTL_H
