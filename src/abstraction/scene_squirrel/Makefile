include ../../../makefiles/Build.mk

SUBSYSTEM = abstraction
MODULE = scene_squirrel
MODULE_NAME = Abstraction_scene_Squirrel
ifeq ($(MOD), plugin)
  LIBS = -lsquirrel.dll
else
  LIBS = -lsquirrel_static
endif
PREREQS = ../scene_binding_common.h ../scene_binding_common.c

include ../../../makefiles/Binding.mk
