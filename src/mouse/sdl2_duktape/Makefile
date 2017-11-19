SUBSYSTEM = mouse
MODULE = sdl2_duktape
MODULE_NAME = Mouse_SDL2_Duktape
ifeq ($(MOD), plugin)
  LIBS = -lduktape.dll
else
  LIBS = -lduktape
endif
PREREQS = ../binding_common.h ../binding_common.c

include ../../../makefiles/Binding.mk
