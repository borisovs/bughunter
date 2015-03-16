QT += core gui
MOBILITY = multimedia

#**************
TARGET = bughunter
#CONFIG += meegotouch
TEMPLATE = app
target.path=/usr/local/bin
INSTALLS=target
#DISTFILES += audio/kill.wav \
 #              audio/shot.wav \
  #             audio/music.mp3
#**************

CONFIG += silent mobility
RESOURCES += resources.qrc
HEADERS += src/startscene.h \
    src/gamescene.h \
    src/graphicsview.h \
    src/bug.h \
    src/infoitem.h \
    src/messagebox.h \
    src/smoke.h
SOURCES += src/startscene.cpp \
    src/main.cpp \
    src/gamescene.cpp \
    src/graphicsview.cpp \
    src/bug.cpp \
    src/infoitem.cpp \
    src/messagebox.cpp \
    src/smoke.cpp
OTHER_FILES += audio/kill.wav \
               audio/shot.wav \
               audio/music.mp3
