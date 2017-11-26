include ../../../makefiles/Build.mk

SUBSYSTEM = abstraction
MODULE = sprite_squirrel
MODULE_NAME = Abstraction_sprite_Squirrel
ifeq ($(MOD), plugin)
  LIBS = -lsquirrel
else
  LIBS = -lsquirrel_static
endif
PREREQS = ../sprite_binding_common.h ../sprite_binding_common.c

include ../../../makefiles/Binding.mk
