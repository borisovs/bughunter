#include <QApplication>
#include <QDir>
#include "gamescene.h"
#include <phonon/mediaobject.h>
#include <phonon/audiooutput.h>
#include <QtDebug>

GameScene::GameScene(QObject *parent, int level, int value)
    :QGraphicsScene(parent), m_level(level), m_value(value)
{
    setBackgroundBrush(QBrush(QPixmap(":/background/resources/grass.png")));
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
