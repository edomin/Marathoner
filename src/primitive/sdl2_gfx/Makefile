include ../../../makefiles/Build.mk

SUBSYSTEM = primitive
MODULE = sdl2_gfx
MODULE_NAME = Primitive_SDL2_gfx
ifeq ($(PLATFORM), win32)
  ifeq ($(MOD), plugin)
    LIBS = -lSDL2_gfx -lSDL2.dll
  else
    LIBS = -lSDL2_gfx -lSDL2 -lwinmm -limm32 -lole32 -loleaut32 -lversion -luuid
  endif
endif
ifeq ($(PLATFORM), win64)
  ifeq ($(MOD), plugin)
    LIBS = -lSDL2_gfx -lSDL2.dll
  else
    LIBS = -lSDL2_gfx -lSDL2 -lwinmm -limm32 -lole32 -loleaut32 -lversion -luuid
  endif
endif
ifeq ($(PLATFORM), html5)
  LIBS = $(PREFIX)/lib/sdl2.bc $(PREFIX)/lib/gl.bc
endif

include ../../../makefiles/Subsystem.mk
