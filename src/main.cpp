#include <QApplication>
#include <QIcon>
#include  "graphicsview.h"
#include "startscene.h"

int main (int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/bugs/resources/ladybug.png"));
    app.setApplicationName(QString("BugHunter"));
    GraphicsView gv;

    gv.show();

    return app.exec();
}
