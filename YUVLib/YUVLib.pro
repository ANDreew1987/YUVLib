#-------------------------------------------------
#
# Project created by QtCreator 2017-07-08T14:03:03
#
#-------------------------------------------------

QT       -= core gui

TARGET = YUVLib
TEMPLATE = lib
CONFIG += staticlib

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
    source/Converters/YUVAVXConverter.cpp \
    source/Converters/YUVSTDConverter.cpp \
    source/Frames/YUV420Frame.cpp \
    source/Frames/YUYV422Frame.cpp \
    source/YUVBitmap.cpp \
    source/YUVConverter.cpp \
    source/YUVFrame.cpp \
    source/YUVReader.cpp \
    source/YUVWriter.cpp

INCLUDEPATH += include

HEADERS += \
    include/Converters/YUVAVXConverter.hpp \
    include/Converters/YUVSTDConverter.hpp \
    include/Frames/YUV420Frame.hpp \
    include/Frames/YUYV422Frame.hpp \
    include/YUVBitmap.hpp \
    include/YUVColorSpaces.hpp \
    include/YUVConverter.hpp \
    include/YUVFormats.hpp \
    include/YUVFrame.hpp \
    include/YUVLib.hpp \
    include/YUVLibConfig.hpp \
    include/YUVReader.hpp \
    include/YUVWriter.hpp
unix {
    target.path = /usr/lib
    INSTALLS += target
}
