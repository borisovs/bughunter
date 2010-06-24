#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QGraphicsObject>

class MessageBox : public QGraphicsObject
{
    Q_OBJECT
public:
    enum Type {
        Winner,
        Looser
    };

    explicit MessageBox(Type , QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
    void stopGame();
public slots:
    void stop();
private:
    Type m_state;
};

#endif // MESSAGEBOX_H
