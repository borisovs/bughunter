#ifndef STARTVIEW_H
#define STARTVIEW_H

#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsObject>
#include <QtGui/QGraphicsSceneMouseEvent>

class StartScene : public QGraphicsScene
{
public:
    StartScene(QObject *parent = 0);
    QRectF sceneRect () const;
private:
    void loadData();
};

class ProgressBar: public QGraphicsObject
{
//    Q_OBJECT
public:
    ProgressBar(QGraphicsObject *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
protected:
   void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
   void mousePressEvent(QGraphicsSceneMouseEvent *event);
//   void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
//  void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
//private slots:

private:
   void setData(QPoint);
   QPoint loadData();
   QPoint m_pos;

};

#endif // STARTVIEW_H
