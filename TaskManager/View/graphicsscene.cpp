#include "graphicsscene.h"
#include "graphicsitem.h"

GraphicsScene::GraphicsScene(QWidget *parent)
    : QGraphicsScene{parent}
{
    GraphicsItem* item = new GraphicsItem();
    this->addItem(item);

}
