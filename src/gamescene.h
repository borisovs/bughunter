#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <phonon/mediaobject.h>
class Bug;

class GameScene : public QGraphicsScene
{
public:
    GameScene(QObject *parent = 0, int level = 50, int value = 50);
    QRectF sceneRect () const;
    QRectF fieldRect () const;
    QRectF infoRect () const;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    void playMusic();
    void loadBugs();
    void rotateBugs();
    QList <Bug *> m_list;
    int m_level;
    int m_value;
    Phonon::MediaObject *shot;
};

#endif // GAMESCENE_H
