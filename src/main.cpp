#include  <QApplication>
#include  <QtGui/QGraphicsView>
#include "startscene.h"

int main (int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsView gv;
    gv.setRenderHint(QPainter::Antialiasing);
    StartScene *scene = new StartScene();

    gv.setScene(scene);
    gv.setSceneRect(0,0, 800, 480);
    gv.show();

    return app.exec();
}
