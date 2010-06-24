QT += gui \
    phonon
CONFIG += silent
RESOURCES += resources.qrc
HEADERS += src/startscene.h \
    src/gamescene.h \
    src/graphicsview.h \
    src/bug.h \
    src/infoitem.h \
    src/messagebox.h
SOURCES += src/startscene.cpp \
    src/main.cpp \
    src/gamescene.cpp \
    src/graphicsview.cpp \
    src/bug.cpp \
    src/infoitem.cpp \
    src/messagebox.cpp
