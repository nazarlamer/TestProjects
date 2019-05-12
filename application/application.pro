TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += core

SOURCES += \
        Serializing/dataserializer.cpp \
        main.cpp \

HEADERS += \
    Serializing/data.h \
    Serializing/dataserializer.h \
