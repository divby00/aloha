TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_LIBDIR = /usr/lib/x86_64-linux-gnu
OBJECTS_DIR = src/obj
LIBS += -lallegro_audio -lallegro_image -lallegro_physfs -lallegro -llua5.2
SOURCES += src/main.c
OTHER_FILES += \
    lua/example01.lua
