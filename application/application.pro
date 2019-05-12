TEMPLATE = app
CONFIG += c++17
CONFIG -= app_bundle
QT += core

SOURCES += \
        Serializing/dataserializer.cpp \
    Serializing/fstreamfilereaderstrategy.cpp \
    Serializing/qdatastreamfilereaderstrategy.cpp \
        main.cpp \

HEADERS += \
    Serializing/data.h \
    Serializing/dataserializer.h \ \
    Serializing/filereader.h \
    Serializing/fstreamfilereaderstrategy.h \
    Serializing/qdatastreamfilereaderstrategy.h
