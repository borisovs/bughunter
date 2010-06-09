#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>

class GameScene : public QGraphicsScene
{
public:
    GameScene(QObject *parent = 0, int level = 50, int value = 50);
    QRectF sceneRect () const;
    QRectF fieldRect () const;
    QRectF infoRect () const;
private:
    void playMusic();
    int m_level;
    int m_value;
};

#endif // GAMESCENE_H
