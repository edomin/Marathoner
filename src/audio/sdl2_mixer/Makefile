include ../../../Build.mk

SUBSYSTEM = audio
MODULE = sdl2_mixer
MODULE_NAME = Audio_SDL2_mixer
ifeq ($(PLATFORM), win32)
  LIBS = -lSDL2_mixer.dll -lSDL2.dll
endif
ifeq ($(PLATFORM), html5)
  LIBS = -lSDL2_mixer -s USE_SDL=2
endif

include ../../../Subsystem.mk


