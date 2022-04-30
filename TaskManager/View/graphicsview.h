#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QWidget>
#include <QGraphicsView>
class GraphicsView : public QGraphicsView
{
    Q_OBJECT
private:
    qreal m_scalnum;
public:
    explicit GraphicsView(QWidget *parent = nullptr);
    void wheelEvent(QWheelEvent *event);

signals:

};

#endif // GRAPHICSVIEW_H
