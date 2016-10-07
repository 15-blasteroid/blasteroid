TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    blast.c \
    asteroid.c \
    text.c \
    spaceship.c \
    blasteroids.c \
    end.c

HEADERS += \
    version1.h

LIBS += -L/usr/lib -lallegro -lallegro_primitives -lm -lallegro_font -lallegro_ttf -lallegro_image
