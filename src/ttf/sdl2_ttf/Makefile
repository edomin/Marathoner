include ../../../Build.mk

SUBSYSTEM = ttf
MODULE = sdl2_ttf
MODULE_NAME = TTF_SDL2_ttf
ifeq ($(PLATFORM), win32)
  LIBS = -lSDL2_ttf.dll -lSDL2.dll
endif
ifeq ($(PLATFORM), html5)
  LIBS = $(PREFIX)/lib/sdl2-ttf.bc
endif
PREREQS = ../common.h

include ../../../Subsystem.mk

