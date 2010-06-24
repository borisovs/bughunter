#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QGraphicsObject>

class MessageBox : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit MessageBox(QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:

};

#endif // MESSAGEBOX_H
