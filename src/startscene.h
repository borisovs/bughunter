#ifndef STARTVIEW_H
#define STARTVIEW_H

#include <QGraphicsScene>

class StartScene : public QGraphicsScene
{
public:
    StartScene(QObject *parent = 0);
    QRectF sceneRect () const;
};

#endif // STARTVIEW_H
