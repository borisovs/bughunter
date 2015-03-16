#include <QPainter>
#include <QTimer>
#include <QFontMetrics>
#include "messagebox.h"

MessageBox::MessageBox(Type state, QGraphicsItem *parent) :
    QGraphicsObject(parent), m_state(state), m_infoString(QString())
{
    QTimer::singleShot(5000, this, SLOT(stop()));
}

QRectF MessageBox::boundingRect() const
{
    return QRectF(0, 0, 600, 200);
}

void MessageBox::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    //draw  button
    QLinearGradient grad(QPointF(boundingRect().center().x(), 0), QPointF(boundingRect().center().x(), boundingRect().bottom()));
    grad.setColorAt(0, QColor(100, 100, 100, 200));
    grad.setColorAt(1, QColor(50, 50, 50, 100));

    painter->setPen(Qt::gray);
    painter->setBrush(grad);
    painter->drawRoundRect(boundingRect(), 5, 15);

    painter->setPen(Qt::yellow);
    painter->setFont(QFont("Arial", 12, QFont::Bold));

    QFontMetrics fm(painter->font());

    switch(m_state) {
    case Winner:{
            painter->drawText(QRectF(0, 0, boundingRect().topRight().x(), fm.height()), Qt::AlignCenter , tr("Congratulate you win!"));
            painter->setFont(QFont("Arial", 24, QFont::Bold));
            painter->drawText(boundingRect(), Qt::AlignCenter , m_infoString);
            break;
       }

    case Looser: {
            painter->drawText(QRectF(0, 0, boundingRect().topRight().x(), fm.height()), Qt::AlignCenter , tr("Sorry, you lose!"));
            painter->setFont(QFont("Arial", 24, QFont::Bold));
            painter->drawText(boundingRect(), Qt::AlignCenter , m_infoString);
            break;
        }
    };

    painter->restore();
}


void MessageBox::stop()
{
    emit stopGame();
}

void MessageBox::setMessage(const QString &str)
{
    m_infoString = str;
    update();
}
