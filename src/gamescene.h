#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QSet>

#include "smoke.h"

class Bug;
class InfoItem;
class QMediaPlayer;

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GameScene(QObject *parent = 0, int level = 50, int value = 50);
    QRectF sceneRect () const;
    QRectF fieldRect () const;
    QRectF infoRect () const;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private slots:
        void updateInfo();
        void updateTimer();
        void finish();
        void removeBug(const QPointF &point);
        void moveBugs();
        void rotateBugs();
signals:
        void gameFinished();
private:
    void playMusic();
    void loadBugs();
//    void removeBug(const QPointF &point);
    void loadInfo();
    QPointF getNextPos(Bug *) const;
    QPointF getCurPos(Bug *) const;
    QList <Bug *> m_list;
    int m_level;
    int m_value;
    QMediaPlayer *shot;
    QMediaPlayer *kill;
    QMediaPlayer *music;
    InfoItem *info;
    int m_bugCount;
    int m_score;
    int m_time;
    QTimer *m_gameTimer;
    QVector<QPointF> m_points;
    Smoke *smoke;
    QSet<Smoke *> m_set;
};

#endif // GAMESCENE_H
