QT       += core gui serialport quick network core


# Include widgets for Qt versions older than 5.0
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Use C++17 standard
CONFIG += c++17

# Disable deprecated APIs
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

# List source files
SOURCES += \
    ConexaoArduino.cpp \
    JsonMensagens.cpp \
    TFTPMensagens.cpp \
    main.cpp \
    GraficaConexaoArduino.cpp

# List header files
HEADERS += \
    ConexaoArduino.h \
    GraficaConexaoArduino.h \
    JsonMensagens.h \
    TFTPMensagens.h

# Set installation path based on the target platform
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
