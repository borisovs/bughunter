#include <QApplication>
#include <QDir>
#include <QList>
#include <QPropertyAnimation>
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <QTimer>
#include <QGraphicsEffect>
#include <phonon/audiooutput.h>
#include <QCursor>
#include <QGraphicsPixmapItem>
#include <cmath>
#include "gamescene.h"
#include "bug.h"
#include "infoitem.h"
#include "messagebox.h"


GameScene::GameScene(QObject *parent, int level, int value)
    :QGraphicsScene(parent), m_level(level), m_value(value), m_bugCount(0), m_score(0), m_time(118)
{
    setBackgroundBrush(QBrush(QPixmap(":/background/resources/grass.png")));
    loadBugs();
    playMusic();
    loadInfo();

    shot = Phonon::createPlayer(Phonon::MusicCategory, Phonon::MediaSource(qApp->applicationDirPath() + QDir::separator()+ "audio" +QDir::separator()+ "shot.wav"));
    kill = Phonon::createPlayer(Phonon::MusicCategory, Phonon::MediaSource(qApp->applicationDirPath() + QDir::separator()+ "audio" +QDir::separator()+ "kill.wav"));

    m_gameTimer = new QTimer(parent);
    m_gameTimer->setInterval(1000);
    connect(m_gameTimer, SIGNAL(timeout()), this, SLOT (updateTimer()));
    m_gameTimer->start();

    connect(this, SIGNAL(letDel(QPointF)), this, SLOT(removeBug(QPointF)));

    QCursor m_cur(QPixmap(":/bugs/resources/cursor.png"));
    QApplication::setOverrideCursor(m_cur);

}


QRectF GameScene::sceneRect() const
{
    return QRectF(0, 0, 800, 480);

}

QRectF GameScene::infoRect() const
{
    return QRectF(0, 0, sceneRect().width(), 20);
}

QRectF GameScene::fieldRect() const
{
    return QRectF (0, infoRect().height(), sceneRect().width(), sceneRect().height());
}

void GameScene::playMusic()
{

    music = new Phonon::MediaObject(this);
    music->setCurrentSource(Phonon::MediaSource(qApp->applicationDirPath() + QDir::separator()+ "audio" +QDir::separator()+ "music.mp3"));

    Phonon::AudioOutput *audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    Phonon::Path path = Phonon::createPath(music, audioOutput);

    audioOutput->setVolume(qreal(m_value));

    music->play();

}

void GameScene::loadBugs()
{
    for (int i = 0; i < m_level; ++i){
        m_list.insert(i, new Bug());
    }


    QList<Bug *>::iterator it = m_list.begin();
    while (it != m_list.end()){

        int x = 16 + rand()% static_cast<int>(750 );

        int y = 50 + rand()% static_cast<int>(330);

        addItem(*it);
        (*it)->setPos(x , y);

        ++it;
    }

    m_bugCount = m_list.count();
    rotateBugs();
}

void GameScene::rotateBugs()
{
    QList<Bug *>::iterator it = m_list.begin();
    while (it != m_list.end()){

        QPropertyAnimation *anim= new QPropertyAnimation(*it, "angle");
        anim->setStartValue((*it)->rotation());
        anim->setEndValue(360 + (*it)->rotation());
        anim->setDuration(5000);
        anim->start();
        anim->setLoopCount(1);

        ++it;
    }

moveBugs();

}

void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if (itemAt(event->scenePos()) && (itemAt(event->scenePos()) != info)) {
        shot->play();
        shot->seek(0);
        if (m_bugCount > 0 && (itemAt(event->scenePos()) != info)) {
            removeBug(event->scenePos());
        }

    } else {
        shot->play();
        shot->seek(0);
    }
}

void GameScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}


void GameScene::updateInfo()
{
    info->setTime(QString(tr("Remained time: ")) + QString::number(m_time));
    info->setScore(QString(tr("Scores: ")) + QString::number(m_score * 10));
    info->setBugs(QString(tr("Bugs count: ")) + QString::number(m_bugCount));
}


void GameScene::removeBug(const QPointF &point)
{
    if (m_set.contains(static_cast<Smoke *>(itemAt(point))))
        return;

    removeItem (itemAt(point));



    smoke = new Smoke;
    addItem(smoke);
    smoke->setPos(point.x() - (smoke->boundingRect().width()/2), point.y() - (smoke->boundingRect().height()/2));
    smoke->show();
    m_set.insert(smoke);



    QTimer::singleShot(100, smoke, SLOT(deleteLater()));




    --m_bugCount;
    ++m_score;

    updateInfo();

    if (m_bugCount ==0 ) {
        m_gameTimer->stop();
        MessageBox *message = new MessageBox(MessageBox::Winner);
        message->setMessage(QString(tr("You score is:  ")+QString::number(m_score * 10)));
        addItem(message);
        message->setPos(sceneRect().center().x()- message->boundingRect().width()/2, sceneRect().center().y()- message->boundingRect().height()/2);
        connect(message, SIGNAL(stopGame()), SLOT(finish()));
    }

}

void GameScene::loadInfo()
{
    info = new InfoItem;
    addItem(info);
    info->setPos(infoRect().topLeft().x(), infoRect().topLeft().y());

    updateInfo();
}

void GameScene::updateTimer()
{
    if (m_time == 0){
        m_gameTimer->stop();
        MessageBox *message = new MessageBox(MessageBox::Looser);
        message->setMessage(QString(tr("You score is:  ")+QString::number(m_score * 10)));
        addItem(message);
        message->setPos(sceneRect().center().x()- message->boundingRect().width()/2, sceneRect().center().y()- message->boundingRect().height()/2);
        connect(message, SIGNAL(stopGame()), SLOT(finish()));
    } else {

        --m_time;

    }
    updateInfo();

}

void GameScene::finish()
{

    music->stop();
    m_list.clear();
    emit gameFinished();
}


void GameScene::moveBugs()
{
    QList<Bug *>::iterator it = m_list.begin();
    while (it != m_list.end()){

        QPropertyAnimation *m_move= new QPropertyAnimation(*it, "pos");
        m_move->setStartValue((*it)->pos());
        m_move->setEndValue(QPointF( (*it)->pos().x() - 50 , (*it)->pos().y() - 50) );
        m_move->setDuration(3000);
        m_move->start();
        m_move->setLoopCount(1000);

        ++it;
    }
}
