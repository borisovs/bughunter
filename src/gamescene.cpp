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
    Phonon::MediaObject *music =
             Phonon::createPlayer(Phonon::MusicCategory,
                                  Phonon::MediaSource(qApp->applicationDirPath() + QDir::separator()+ "audio" +QDir::separator()+ "music.mp3"));
    qDebug()<< music->currentSource().fileName();
    music->play();


}
