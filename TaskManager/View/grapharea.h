#ifndef GRAPHAREA_H
#define GRAPHAREA_H

#include <QScrollArea>
class GraphArea : public QScrollArea
{
    Q_OBJECT
public:
    explicit GraphArea(QWidget *parent = nullptr);
    ~GraphArea();
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动事件
private:
    QScrollBar * hbra;
    QScrollBar * vbra;
signals:

};

#endif // GRAPHAREA_H
