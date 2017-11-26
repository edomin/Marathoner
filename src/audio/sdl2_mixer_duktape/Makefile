include ../../../makefiles/Build.mk

SUBSYSTEM = audio
MODULE = sdl2_mixer_duktape
MODULE_NAME = Audio_SDL2_mixer_Duktape
ifeq ($(MOD), plugin)
  LIBS = -lduktape.dll
else
  LIBS = -lduktape
endif
PREREQS = ../binding_common.h ../binding_common.c ../common.h

include ../../../makefiles/Binding.mk
