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
     -luuid -lfreetype -lpng -lz -lbz2
  endif
endif
ifeq ($(PLATFORM), linux_x86_64)
  LIBS = -lSDL2_ttf
endif
ifeq ($(PLATFORM), html5)
  CEXFLAGS = -s USE_SDL=2 -s USE_SDL_TTF=2
  LIBS = -s USE_SDL=2 -s USE_SDL_TTF=2 -s USE_FREETYPE=2
endif

include ../../../makefiles/Subsystem.mk
