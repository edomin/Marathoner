include ../../../makefiles/Build.mk

SUBSYSTEM = ttf
MODULE = sdl2_ttf_duktape
MODULE_NAME = TTF_SDL2_ttf_Duktape
ifeq ($(MOD), plugin)
  LIBS = -lduktape.dll
else
  LIBS = -lduktape
endif
PREREQS = ../binding_common.h ../binding_common.c

include ../../../makefiles/Binding.mk
