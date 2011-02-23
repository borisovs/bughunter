#include <QPainter>
#include <QPixmap>
#include "bug.h"
#include <cmath>

Bug::Bug(QGraphicsItem *parent) :
    QGraphicsObject(parent)
{
    int i = 0;
    QMap<int, QPixmap> map;
    map.insert(++i, QPixmap(":/bugs/resources/bug.png"));
    map.insert(++i, QPixmap(":/bugs/resources/bugclop.png"));
    map.insert(++i, QPixmap(":/bugs/resources/fly.png"));
    map.insert(++i, QPixmap(":/bugs/resources/ladybug.png"));

    m_pixmap = map.value(1 + rand()%4, QPixmap());

    setTransformOriginPoint(boundingRect().center());
    setAngle(rand() % 360);
}

void Bug::setAngle(qreal angle)
{
    setRotation(angle);
}

qreal Bug::angle() const
{
    return rotation();
}

QRectF Bug::boundingRect() const
{
    return QRectF (0, 0, 32, 32);
}

void Bug::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
     painter->drawPixmap(0, 0,  m_pixmap);
}


void Bug::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void Bug::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}

void Bug::notify()
{
    emit rotateFinished();
}
