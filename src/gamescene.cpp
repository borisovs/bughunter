#include <QApplication>
#include <QDir>
#include "gamescene.h"
#include <phonon/mediaobject.h>
#include <phonon/audiooutput.h>
#include <QtDebug>

GameScene::GameScene(QObject *parent )
    :QGraphicsScene(parent)
{
    setBackgroundBrush(QBrush(QPixmap(":/background/resources/grass.png")));
    playMusic();
}


QRectF GameScene::sceneRect() const
{
    return QRectF(0, 0, 800, 480);

}


void GameScene::playMusic()
{
    Phonon::MediaObject *music =
             Phonon::createPlayer(Phonon::MusicCategory,
                                  Phonon::MediaSource(qApp->applicationDirPath() + QDir::separator()+ "audio" +QDir::separator()+ "music.mp3"));
    qDebug()<< music->currentSource().fileName();
    music->play();


}
