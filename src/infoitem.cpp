#include <QPainter>
#include "infoitem.h"

InfoItem::InfoItem(QGraphicsItem *parent) :
        QGraphicsObject(parent), m_time(QString()), m_score(QString()), m_bugs(QString())
{
}

QRectF InfoItem::boundingRect() const
{
    return QRectF(0,0, 800, 20);
}

void InfoItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::yellow);
    painter->setFont(QFont("Arial", 12, QFont::Bold));

    painter->drawText(boundingRect(), Qt::AlignLeft | Qt::AlignVCenter, m_time);

    painter->drawText(boundingRect(), Qt::AlignCenter | Qt::AlignVCenter, m_score);

    painter->drawText(boundingRect(), Qt::AlignRight | Qt::AlignVCenter, m_bugs);

}


void InfoItem::setTime(QString str)
{
    m_time = str;
    update();
}

void InfoItem::setScore(QString str)
{
    m_score= str;
    update();
}

void InfoItem::setBugs(QString str)
{
    m_bugs= str;
    update();
}
