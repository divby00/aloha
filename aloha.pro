TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_LIBDIR = /usr/lib/x86_64-linux-gnu
OBJECTS_DIR = src/obj
LIBS += -lallegro_audio -lallegro_image -lallegro_physfs -lallegro
SOURCES += src/lua-5.3.0/lapi.c\
    src/lua-5.3.0/lauxlib.c\
    src/lua-5.3.0/lbaselib.c\
    src/lua-5.3.0/lbitlib.c\
    src/lua-5.3.0/lcode.c\
    src/lua-5.3.0/lcorolib.c\
    src/lua-5.3.0/lctype.c\
    src/lua-5.3.0/ldblib.c\
    src/lua-5.3.0/ldebug.c\
    src/lua-5.3.0/ldo.c\
    src/lua-5.3.0/ldump.c\
    src/lua-5.3.0/lfunc.c\
    src/lua-5.3.0/lgc.c\
    src/lua-5.3.0/linit.c\
    src/lua-5.3.0/liolib.c\
    src/lua-5.3.0/llex.c\
    src/lua-5.3.0/lmathlib.c\
    src/lua-5.3.0/lmem.c\
    src/lua-5.3.0/loadlib.c\
    src/lua-5.3.0/lobject.c\
    src/lua-5.3.0/lopcodes.c\
    src/lua-5.3.0/loslib.c\
    src/lua-5.3.0/lparser.c\
    src/lua-5.3.0/lstate.c\
    src/lua-5.3.0/lstring.c\
    src/lua-5.3.0/lstrlib.c\
    src/lua-5.3.0/ltable.c\
    src/lua-5.3.0/ltablib.c\
    src/lua-5.3.0/ltm.c\
    src/lua-5.3.0/lundump.c\
    src/lua-5.3.0/lutf8lib.c\
    src/lua-5.3.0/lvm.c\
    src/lua-5.3.0/lzio.c\
    src/main.c\
    src/al5_modules/system.c \
    src/al5_modules/configuration.c \
    src/al5_modules/display.c

OTHER_FILES += \
    lua/test.lua \
    lua/example01.lua

HEADERS += \
    src/al5_modules/system.h \
    src/aloha/defs.h \
    src/al5_modules/configuration.h \
    src/al5_modules/display.h
