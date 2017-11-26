include ../../../makefiles/Build.mk

SUBSYSTEM = primitive
MODULE = sdl2_gpu_squirrel
MODULE_NAME = Primitive_SDL2_gpu_Squirrel
ifeq ($(MOD), plugin)
  LIBS = -lsquirrel
else
  LIBS = -lsquirrel_static
endif
PREREQS = ../binding_common.h ../binding_common.c

include ../../../makefiles/Binding.mk
