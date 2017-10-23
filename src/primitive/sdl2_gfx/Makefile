include ../../../Build.mk

SUBSYSTEM = primitive
MODULE = sdl2_gfx
MODULE_NAME = Primitive_SDL2_gfx
ifeq ($(PLATFORM), win32)
  LIBS = -lSDL2_gfx -lSDL2.dll
endif
ifeq ($(PLATFORM), win64)
  LIBS = -lSDL2_gfx -lSDL2.dll
endif
ifeq ($(PLATFORM), html5)
  LIBS = $(PREFIX)/lib/sdl2.bc $(PREFIX)/lib/gl.bc
endif

include ../../../Subsystem.mk
