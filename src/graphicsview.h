#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    GraphicsView(QWidget * parent = 0);
private slots:
    void startGame(int level, int music);
};

#endif // GRAPHICSVIEW_H
