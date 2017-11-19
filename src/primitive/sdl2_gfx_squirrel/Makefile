SUBSYSTEM = primitive
MODULE = sdl2_gfx_squirrel
MODULE_NAME = Primitive_SDL2_gfx_Squirrel
ifeq ($(MOD), plugin)
  LIBS = -lsquirrel
else
  LIBS = -lsquirrel_static
endif
PREREQS = ../binding_common.h ../binding_common.c

include ../../../makefiles/Binding.mk
