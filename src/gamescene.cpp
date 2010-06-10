#include <QApplication>
#include <QDir>
#include <QList>
#include <QPropertyAnimation>
#include "gamescene.h"
#include <phonon/mediaobject.h>
#include <phonon/audiooutput.h>
#include <QtDebug>
#include "bug.h"

GameScene::GameScene(QObject *parent, int level, int value)
    :QGraphicsScene(parent), m_level(level), m_value(value)
{
    setBackgroundBrush(QBrush(QPixmap(":/background/resources/grass.png")));
    loadBugs();
    playMusic();
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
        bug->setPos(rand()% static_cast<int>(sceneRect().width()),  rand()% static_cast<int>(sceneRect().height()));

          rotateBugs();

        ++it;
    }

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
//       anim->setLoopCount(-1);

       ++it;
   }


}
