#-------------------------------------------------
#
# Project created by QtCreator 2017-07-08T14:03:34
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Player
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        MainWindow.cpp \
    ChangeParams.cpp \
    GLWidget.cpp

HEADERS += \
        MainWindow.h \
    ChangeParams.h \
    GLWidget.h

FORMS += \
        MainWindow.ui \
    ChangeParams.ui

win32:LIBS += -lopengl32 -lglu32

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../YUVLib/release/ -lYUVLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../YUVLib/debug/ -lYUVLib
else:unix: LIBS += -L$$OUT_PWD/../YUVLib/ -lYUVLib

INCLUDEPATH += $$PWD/../YUVLib/include
DEPENDPATH += $$PWD/../YUVLib/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../YUVLib/release/libYUVLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../YUVLib/debug/libYUVLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../YUVLib/release/YUVLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../YUVLib/debug/YUVLib.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../YUVLib/libYUVLib.a
