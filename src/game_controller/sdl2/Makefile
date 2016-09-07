include ../../../Build.mk

SUBSYSTEM = game_controller
MODULE = sdl2
MODULE_NAME = Game_Controller_SDL2
ifeq ($(PLATFORM), win32)
  LIBS = -lSDL2.dll
endif
ifeq ($(PLATFORM), html5)
  LIBS = $(PREFIX)/lib/sdl2.bc $(PREFIX)/lib/gl.bc
endif

include ../../../Subsystem.mk


