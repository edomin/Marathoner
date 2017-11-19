SUBSYSTEM = primitive
MODULE = sdl2_duktape
MODULE_NAME = Primitive_SDL2_Duktape
ifeq ($(MOD), plugin)
  LIBS = -lduktape.dll
else
  LIBS = -lduktape
endif
PREREQS = ../binding_common.h ../binding_common.c

include ../../../makefiles/Binding.mk
