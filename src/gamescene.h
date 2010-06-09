#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>

class GameScene : public QGraphicsScene
{
public:
    GameScene(QObject *parent = 0);
    QRectF sceneRect () const;
    QRectF fieldRect () const;
    QRectF infoRect () const;
private:
    void playMusic();
};

#endif // GAMESCENE_H
