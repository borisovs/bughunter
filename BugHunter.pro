QT += gui \
    phonon
CONFIG += silent
RESOURCES += resources.qrc
HEADERS += src/startscene.h \
    src/gamescene.h \
    src/graphicsview.h \
    src/bug.h
SOURCES += src/startscene.cpp \
    src/main.cpp \
    src/gamescene.cpp \
    src/graphicsview.cpp \
    src/bug.cpp
