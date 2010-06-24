#include <QPainter>
#include <QTimer>
#include "messagebox.h"

MessageBox::MessageBox(Type state, QGraphicsItem *parent) :
    QGraphicsObject(parent), m_state(state)
{
    QTimer::singleShot(5000, this, SLOT(stop()));
}

QRectF MessageBox::boundingRect() const
{
    return QRectF(0, 0, 300, 50);
}

void MessageBox::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    //draw  button
    QLinearGradient grad(QPointF(boundingRect().center().x(), 0), QPointF(boundingRect().center().x(), boundingRect().bottom()));
    grad.setColorAt(0, QColor(100, 100, 100));
    grad.setColorAt(1, QColor(50, 50, 50));

    painter->setPen(Qt::gray);
    painter->setBrush(grad);
    painter->drawRoundRect(boundingRect(), 5, 15);
    painter->restore();
}


void MessageBox::stop()
{
    emit stopGame();
}
