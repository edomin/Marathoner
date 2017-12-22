include ../../../makefiles/Build.mk

SUBSYSTEM = audio
MODULE = sdl2_mixer_squirrel
MODULE_NAME = Audio_SDL2_mixer_Squirrel
ifeq ($(MOD), plugin)
  LIBS = -lsquirrel.dll
else
  LIBS = -lsquirrel_static
endif
PREREQS = ../binding_common.h ../binding_common.c ../common.h

include ../../../makefiles/Binding.mk
