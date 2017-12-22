include ../../../makefiles/Build.mk

SUBSYSTEM = primitive
MODULE = sdl2_squirrel
MODULE_NAME = Primitive_SDL2_Squirrel
ifeq ($(MOD), plugin)
  LIBS = -lsquirrel.dll
else
  LIBS = -lsquirrel_static
endif
PREREQS = ../binding_common.h ../binding_common.c

include ../../../makefiles/Binding.mk
