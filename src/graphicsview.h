#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
class GameScene;
class StartScene;

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    GraphicsView(QWidget * parent = 0);
private slots:
    void startGame(int level, int music);
    void gameFinished();
private:
    StartScene *scene ;
    GameScene *game;
};

#endif // GRAPHICSVIEW_H
