#include  <QApplication>
#include  <QtGui/QGraphicsView>
#include "startscene.h"

int main (int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsView gv;

    StartScene *scene = new StartScene();

    gv.setScene(scene);
    gv.show();

    return app.exec();
}
