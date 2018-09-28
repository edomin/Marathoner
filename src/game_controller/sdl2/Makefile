include ../../../makefiles/Build.mk

SUBSYSTEM = game_controller
MODULE = sdl2
MODULE_NAME = Game_Controller_SDL2
ifeq ($(PLATFORM), win32)
  ifeq ($(MOD), plugin)
    LIBS = -lSDL2.dll
  else
    LIBS = -lSDL2 -lwinmm -limm32 -lole32 -loleaut32 -lversion -luuid
  endif
endif
ifeq ($(PLATFORM), win64)
  ifeq ($(MOD), plugin)
    LIBS = -lSDL2.dll
  else
    LIBS = -lSDL2 -lwinmm -limm32 -lole32 -loleaut32 -lversion -luuid
  endif
endif
ifeq ($(PLATFORM), linux_x86_64)
  LIBS = -lSDL2
endif
ifeq ($(PLATFORM), html5)
  CEXFLAGS = -s USE_SDL=2
  LIBS = -s USE_SDL=2
endif

include ../../../makefiles/Subsystem.mk


