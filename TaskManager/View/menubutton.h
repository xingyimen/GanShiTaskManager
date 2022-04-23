#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QWidget>
#include <QToolButton>
class MenuButton : public QToolButton
{
    Q_OBJECT
public:
    explicit MenuButton(QWidget *parent = nullptr);

signals:


};

#endif // MENUBUTTON_H
