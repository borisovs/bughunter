#ifndef BUG_H
#define BUG_H

#include <QGraphicsObject>

class Bug : public QGraphicsObject
{
    Q_OBJECT
    Q_PROPERTY (qreal angle READ angle WRITE setAngle )
public:
    explicit Bug(QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
//signals:
//
public slots:
    void setAngle(qreal);
    qreal angle() const;
private:
    QPixmap m_pixmap;
    int m_angle;
};

#endif // BUG_H
