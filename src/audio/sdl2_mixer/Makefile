include ../../../makefiles/Build.mk

SUBSYSTEM = audio
MODULE = sdl2_mixer
MODULE_NAME = Audio_SDL2_mixer
ifeq ($(PLATFORM), win32)
  ifeq ($(MOD), plugin)
    LIBS = -lSDL2_mixer.dll -lSDL2.dll -Wl,-Bstatic -lstdc++
  else
    LIBS = -lSDL2_mixer -lsmpeg2.dll -lSDL2 -lwinmm -limm32 -lole32 -loleaut32 \
     -lversion -luuid -lvorbisfile -lFLAC -lmodplug.dll -lvorbis -logg -lstdc++
  endif
endif
ifeq ($(PLATFORM), win64)
  ifeq ($(MOD), plugin)
    LIBS = -lSDL2_mixer.dll -lSDL2.dll -Wl,-Bstatic -lstdc++
  else
    LIBS = -lSDL2_mixer -lsmpeg2.dll -lSDL2 -lwinmm -limm32 -lole32 -loleaut32 \
     -lversion -luuid -lvorbisfile -lFLAC -lmodplug.dll -lvorbis -logg -lstdc++
  endif
endif
ifeq ($(PLATFORM), html5)
  CEXFLAGS = -s USE_SDL=2
  LIBS = -lSDL2_mixer -s USE_SDL=2 -s USE_VORBIS=1 -s USE_OGG=1 -lFLAC -lmodplug
endif
PREREQS = ../common.h

include ../../../makefiles/Subsystem.mk


