#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>

class MenuWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MenuWidget(QWidget *parent = nullptr);
    void RefreshScheitem(/*链表*/);
    void RefreshWorkflow(/*链表*/);
    void RefreshQuadrant(/*链表*/);
    void RefreshDatagram(/*比率*/);
signals:

};

#endif // MENUWIDGET_H
