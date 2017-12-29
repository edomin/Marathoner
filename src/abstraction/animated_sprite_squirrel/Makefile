include ../../../makefiles/Build.mk

SUBSYSTEM = abstraction
MODULE = animated_sprite_squirrel
MODULE_NAME = Abstraction_animated_sprite_Squirrel
ifeq ($(MOD), plugin)
  LIBS = -lsquirrel.dll
else
  LIBS = -lsquirrel_static
endif
PREREQS = ../sprite_binding_common.h ../sprite_binding_common.c

include ../../../makefiles/Binding.mk
