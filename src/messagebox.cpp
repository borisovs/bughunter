#include "messagebox.h"

MessageBox::MessageBox(QGraphicsItem *parent) :
    QGraphicsObject(parent)
{
}

QRectF MessageBox::boundingRect() const
{
    return QRectF(0, 0, 300, 50);
}

void MessageBox::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //
}
