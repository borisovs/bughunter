#include "startscene.h"

StartScene::StartScene(QObject *parent)
    :QGraphicsScene(parent)
{
}

QRectF StartScene::sceneRect() const
{
    return QRectF(0, 0, 800, 480);

}
