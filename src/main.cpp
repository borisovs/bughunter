#include  <QApplication>
#include  "graphicsview.h"
#include "startscene.h"

int main (int argc, char *argv[])
{
    QApplication app(argc, argv);

    GraphicsView gv;

    gv.show();

    return app.exec();
}
