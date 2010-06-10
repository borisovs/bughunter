#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <phonon/mediaobject.h>
class Bug;
class InfoItem;

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
signals:
        void gameFinished();
private:
    void playMusic();
    void loadBugs();
    void removeBug(const QPointF &point);
    void rotateBugs();
    void loadInfo();
    QList <Bug *> m_list;
    int m_level;
    int m_value;
    Phonon::MediaObject *shot;
    Phonon::MediaObject *kill;
   Phonon::MediaObject *music;
    InfoItem *info;
    int m_bugCount;
    int m_score;
    int m_time;
    QTimer *m_gameTimer;
};

#endif // GAMESCENE_H
