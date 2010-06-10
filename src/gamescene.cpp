#include <QApplication>
#include <QDir>
#include <QList>
#include <QPropertyAnimation>
#include <QGraphicsSceneMouseEvent>
#include "gamescene.h"
#include <phonon/audiooutput.h>
#include <QtDebug>
#include "bug.h"

GameScene::GameScene(QObject *parent, int level, int value)
    :QGraphicsScene(parent), m_level(level), m_value(value)
{
    setBackgroundBrush(QBrush(QPixmap(":/background/resources/grass.png")));
    loadBugs();
    playMusic();
    shot = Phonon::createPlayer(Phonon::MusicCategory, Phonon::MediaSource(qApp->applicationDirPath() + QDir::separator()+ "audio" +QDir::separator()+ "shot.wav"));
    kill = Phonon::createPlayer(Phonon::MusicCategory, Phonon::MediaSource(qApp->applicationDirPath() + QDir::separator()+ "audio" +QDir::separator()+ "kill.wav"));
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

    Phonon::MediaObject *music = new Phonon::MediaObject(this);
    music->setCurrentSource(Phonon::MediaSource(qApp->applicationDirPath() + QDir::separator()+ "audio" +QDir::separator()+ "music.mp3"));

    Phonon::AudioOutput *audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    Phonon::Path path = Phonon::createPath(music, audioOutput);

    audioOutput->setVolume(qreal(m_value));

    music->play();

    qDebug()<<audioOutput->volume();



}

void GameScene::loadBugs()
{
    for (int i = 0; i <= m_level; ++i){
        m_list.insert(i, new Bug());
    }

    QList<Bug *>::iterator it = m_list.begin();
    while (it != m_list.end()){
        Bug *bug = *it;
        addItem(bug);

           int x = rand()% static_cast<int>(fieldRect().width() );
           int y = rand()% static_cast<int>(fieldRect().height() );

           if (x >= fieldRect().width() - bug->boundingRect().width())
               x-=32;
           if (y >= fieldRect().height() - bug->boundingRect().height() )
               y-=32;
           if  (y < 36)
               y= 36;


        bug->setPos(x , y) ;

        ++it;
    }

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
            removeItem(itemAt(event->scenePos()));
         } else {
            shot->play();
            shot->seek(0);
        }

        qDebug()<<event->scenePos();

}

void GameScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}
