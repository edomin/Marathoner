SUBSYSTEM = timer
MODULE = sdl2_squirrel
MODULE_NAME = Timer_SDL2_Squirrel
ifeq ($(MOD), plugin)
  LIBS = -lsquirrel
else
  LIBS = -lsquirrel_static
endif
PREREQS = ../binding_common.h ../binding_common.c

include ../../../makefiles/Binding.mk
