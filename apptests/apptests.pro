include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
QT += core gui

#googletest files
HEADERS += \
        serializingtest.h \

SOURCES += \
        main.cpp \

#application files
SOURCES += \
        $$PWD/../application/Serializing/dataserializer.cpp \

HEADERS += \
        $$PWD/../application/Serializing/data.h \
        $$PWD/../application/Serializing/dataserializer.h \

INCLUDEPATH += $$PWD/../application
