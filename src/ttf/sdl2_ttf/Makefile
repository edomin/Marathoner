include ../../../makefiles/Build.mk

SUBSYSTEM = ttf
MODULE = sdl2_ttf
MODULE_NAME = TTF_SDL2_ttf
ifeq ($(PLATFORM), win32)
  ifeq ($(MOD), plugin)
    LIBS = -lSDL2_ttf.dll -lSDL2.dll
  else
    LIBS = -lSDL2_ttf -lSDL2 -lwinmm -limm32 -lole32 -loleaut32 -lversion \
     -luuid -lfreetype
  endif
endif
ifeq ($(PLATFORM), win64)
  ifeq ($(MOD), plugin)
    LIBS = -lSDL2_ttf.dll -lSDL2.dll
  else
    LIBS = -lSDL2_ttf -lSDL2 -lwinmm -limm32 -lole32 -loleaut32 -lversion \
     -luuid -lfreetype -lbz2
  endif
endif
ifeq ($(PLATFORM), html5)
  LIBS = $(PREFIX)/lib/sdl2-ttf.bc
endif

include ../../../makefiles/Subsystem.mk
