include ../../../makefiles/Build.mk

SUBSYSTEM = primitive
MODULE = sdl2_gfx_squirrel
MODULE_NAME = Primitive_SDL2_gfx_Squirrel
include ../../../makefiles/Squirrel_libs.mk
PREREQS = ../binding_common.h ../binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/squirrel3
endif

include ../../../makefiles/Binding.mk
