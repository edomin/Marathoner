include ../../../makefiles/Build.mk

SUBSYSTEM = abstraction
MODULE = scene_duktape
MODULE_NAME = Abstraction_scene_Duktape
ifeq ($(MOD), plugin)
  LIBS = -lduktape.dll
else
  LIBS = -lduktape
endif
PREREQS = ../scene_binding_common.h ../scene_binding_common.c

include ../../../makefiles/Binding.mk
