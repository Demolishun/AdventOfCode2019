QT += quick

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        day01.cpp \
        day02.cpp \
        day03.cpp \
        day04.cpp \
        day05.cpp \
        day06.cpp \
        day07.cpp \
        day08.cpp \
        day09.cpp \
        day10.cpp \
        day11.cpp \
        day12.cpp \
        day13.cpp \
        main.cpp \
        utils.cpp

RESOURCES += qml.qrc \
    data.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    day01.h \
    day02.h \
    day03.h \
    day04.h \
    day05.h \
    day06.h \
    day07.h \
    day08.h \
    day09.h \
    day10.h \
    day11.h \
    day12.h \
    day13.h \
    utils.h

DISTFILES +=
