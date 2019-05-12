include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++17
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
        $$PWD/../application/Serializing/qdatastreamfilereaderstrategy.cpp \
        $$PWD/../application/Serializing/fstreamfilereaderstrategy.cpp \

HEADERS += \
        $$PWD/../application/Serializing/data.h \
        $$PWD/../application/Serializing/dataserializer.h \
        $$PWD/../application/Serializing/qdatastreamfilereaderstrategy.h \
        $$PWD/../application/Serializing/fstreamfilereaderstrategy.h \

INCLUDEPATH += $$PWD/../application
