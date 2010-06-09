#include "gamescene.h"

GameScene::GameScene(QObject *parent )
    :QGraphicsScene(parent)
{
    setBackgroundBrush(QBrush(QPixmap(":/background/resources/grass.png")));
}


QRectF GameScene::sceneRect() const
{
    return QRectF(0, 0, 800, 480);

}


