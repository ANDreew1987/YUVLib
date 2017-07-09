TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Convert.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../YUVLib/release/ -lYUVLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../YUVLib/debug/ -lYUVLib
else:unix: LIBS += -L$$OUT_PWD/../../YUVLib/ -lYUVLib

INCLUDEPATH += $$PWD/../../YUVLib/include
DEPENDPATH += $$PWD/../../YUVLib/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../YUVLib/release/libYUVLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../YUVLib/debug/libYUVLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../YUVLib/release/YUVLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../YUVLib/debug/YUVLib.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../YUVLib/libYUVLib.a
