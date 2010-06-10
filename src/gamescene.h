#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
class Bug;

class GameScene : public QGraphicsScene
{
public:
    GameScene(QObject *parent = 0, int level = 50, int value = 50);
    QRectF sceneRect () const;
    QRectF fieldRect () const;
    QRectF infoRect () const;
private:
    void playMusic();
    void loadBugs();
    void rotateBugs();
    QList <Bug *> m_list;
    int m_level;
    int m_value;
};

#endif // GAMESCENE_H
