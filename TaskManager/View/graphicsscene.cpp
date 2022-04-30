#include "graphicsscene.h"
#include "graphicsitem.h"


GraphicsScene::GraphicsScene(QWidget *parent)
    : QGraphicsScene{parent}
{



    GraphicsItem* item1 = new GraphicsItem(GraphicsItem::Rect,GraphicsItem::Blue,"C++");
    GraphicsItem* item2 = new GraphicsItem(GraphicsItem::Rect,GraphicsItem::Blue,"JAVA");
    this->addItem(item1);
    this->addItem(item2);



     /*********测试代码***********/
    //深度优先遍历（组内能否加Layout?对右侧孩子节点进行layout）
    /*
     * 1、首先获得第一个节点，new后打印
     * 2、if(sibling==NULL)  在第一个节点右边200的距离打印第二个
     * 3、DDD




    */




}

