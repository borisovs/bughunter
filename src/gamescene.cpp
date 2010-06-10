#include <QApplication>
#include <QDir>
#include <QList>
#include <QPropertyAnimation>
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <QTimer>
#include "gamescene.h"
#include <phonon/audiooutput.h>
#include <QtDebug>
#include "bug.h"
#include "infoitem.h"

GameScene::GameScene(QObject *parent, int level, int value)
    :QGraphicsScene(parent), m_level(level), m_value(value), m_bugCount(0), m_score(0), m_time(10)
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

    qDebug()<<m_list.count();

    QList<Bug *>::iterator it = m_list.begin();
    while (it != m_list.end()){

           addItem(*it);

           int x = rand()% static_cast<int>(fieldRect().width() );
           int y = rand()% static_cast<int>(fieldRect().height() );

           if (x >= fieldRect().width() - (*it)->boundingRect().width())
               x-=32;
           if (y >= fieldRect().height() - (*it)->boundingRect().height() )
               y-=32;
           if  (y < 36)
               y= 36;

           qDebug()<< x << y;

        (*it)->setPos(QPointF(x , y)) ;
        Bug *bug = *it;
        bug->setVisible(true);

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
      anim->setLoopCount(-1);

       ++it;
   }

}

void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

         if (itemAt(event->scenePos())) {
            kill->play();
            kill->seek(0);
            removeBug(event->scenePos());
         } else {
            shot->play();
            shot->seek(0);
        }

        qDebug()<<event->scenePos();

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

    removeItem(itemAt(point));


    --m_bugCount;
    ++m_score;

    updateInfo();
    if (m_bugCount ==0 ) {
        m_gameTimer->stop();
        QMessageBox::information(0, "BugHunter", QString(tr("Congratulate you win!\n You score is:  ")+QString::number(m_score * 10)));
        music->stop();
        m_list.clear();
        emit gameFinished();
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
        QMessageBox::information(0, "BugHunter", QString(tr("Sorry, you lose!\n You score is:  ")+QString::number(m_score * 10)));
        music->stop();
        m_list.clear();
        emit gameFinished();
    }
    --m_time;

    updateInfo();

}
