SUBSYSTEM = primitive
MODULE = sdl2_gfx_duktape
MODULE_NAME = Primitive_SDL2_gfx_Duktape
ifeq ($(MOD), plugin)
  LIBS = -lduktape.dll
else
  LIBS = -lduktape
endif
PREREQS = ../binding_common.h ../binding_common.c

include ../../../makefiles/Binding.mk
