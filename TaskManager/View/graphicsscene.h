#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QWidget>
#include <QGraphicsScene>
class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GraphicsScene(QWidget *parent = nullptr);

signals:

};

#endif // GRAPHICSSCENE_H
