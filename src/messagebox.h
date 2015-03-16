#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QGraphicsObject>

class MessageBox : public QGraphicsObject
{
    Q_OBJECT
public:
    enum Type {
        Winner = 0,
        Looser =1
    };

    explicit MessageBox(Type , QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setMessage(const QString &);

signals:
    void stopGame();
public slots:
    void stop();
private:
    Type m_state;
    QString m_infoString;
};

#endif // MESSAGEBOX_H
