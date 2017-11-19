include ../../../makefiles/Build.mk

SUBSYSTEM = audio
MODULE = sdl2_mixer
MODULE_NAME = Audio_SDL2_mixer
ifeq ($(PLATFORM), win32)
  ifeq ($(MOD), plugin)
    LIBS = -lSDL2_mixer.dll -lSDL2.dll
  else
    LIBS = -lSDL2_mixer -lSDL2 -lwinmm -limm32 -lole32 -loleaut32 -lversion \
     -luuid -lvorbisfile -lFLAC -lmodplug.dll -lsmpeg2 -lvorbis -logg -lstdc++
  endif
endif
ifeq ($(PLATFORM), win64)
  ifeq ($(MOD), plugin)
    LIBS = -lSDL2_mixer.dll -lSDL2.dll
  else
    LIBS = -lSDL2_mixer -lSDL2 -lwinmm -limm32 -lole32 -loleaut32 -lversion \
     -luuid -lvorbisfile -lFLAC -lmodplug.dll -lsmpeg2 -lvorbis -logg -lstdc++
  endif
endif
ifeq ($(PLATFORM), html5)
  LIBS = -lSDL2_mixer -s USE_SDL=2
endif
PREREQS = ../common.h

include ../../../makefiles/Subsystem.mk


