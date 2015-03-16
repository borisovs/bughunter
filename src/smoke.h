#ifndef SMOKE_H
#define SMOKE_H

#include <QGraphicsObject>
class QPixmap;

class Smoke : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit Smoke(QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public slots:
private:
     QPixmap m_pixmap;
};

#endif // SMOKE_H
