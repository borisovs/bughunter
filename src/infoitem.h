#ifndef INFOITEM_H
#define INFOITEM_H

#include <QGraphicsObject>

class InfoItem : public QGraphicsObject
{
Q_OBJECT
public:
    explicit InfoItem(QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
signals:

public slots:
    void setTime(QString);
    void setScore(QString);
    void setBugs(QString);

private:
    QString m_time;
    QString m_score;
    QString m_bugs;
};

#endif // INFOITEM_H
