#ifndef ADDQUADRANT_H
#define ADDQUADRANT_H

#include <QWidget>

namespace Ui {
class AddQuadrant;
}

class AddQuadrant : public QWidget
{
    Q_OBJECT

public:
    explicit AddQuadrant(int click_x,int click_y,QWidget *parent = nullptr);
    ~AddQuadrant();
    void NewQuadrantItem(int emergency,int importance);
protected:
    virtual void mousePressEvent(QMouseEvent *event);


private:
    Ui::AddQuadrant *ui;
};

#endif // ADDQUADRANT_H
