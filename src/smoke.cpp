#include <QPainter>
#include <QPixmap>
#include "smoke.h"

Smoke::Smoke(QGraphicsItem *parent) :
    QGraphicsObject(parent)
{
    m_pixmap = QPixmap(":/background/resources/smoke.png");
    setObjectName(QString ("smoke"));
}

QRectF Smoke::boundingRect() const
{
    return m_pixmap.rect();
}

void Smoke::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, m_pixmap);

}

