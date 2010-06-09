#ifndef STARTVIEW_H
#define STARTVIEW_H

#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsObject>
#include <QtGui/QGraphicsSceneMouseEvent>

class StartScene : public QGraphicsScene
{
    Q_OBJECT
public:
    StartScene(QObject *parent = 0);
    QRectF sceneRect () const;
signals:
    void game();
    void exit();
//private slots:
//    void startGame();
private:
    void loadData();
};

class ProgressBar: public QGraphicsObject
{
//    Q_OBJECT
public:
    ProgressBar(QGraphicsObject *parent = 0, QString str = QString());
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
   QString m_cap;

};


class Button: public QGraphicsObject
{
    Q_OBJECT
public:
    Button(QGraphicsObject *parent = 0, bool pressed = false);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
protected:
   void mousePressEvent(QGraphicsSceneMouseEvent *event);
   void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
signals:
   void clicked();
private:
   bool isPressed;

};

class ButtonQ: public QGraphicsObject
{
    Q_OBJECT
public:
    ButtonQ(QGraphicsObject *parent = 0, bool pressed = false);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
protected:
   void mousePressEvent(QGraphicsSceneMouseEvent *event);
   void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
signals:
   void clicked();
private:
   bool isPressed;

};

#endif // STARTVIEW_H
