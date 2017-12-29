include ../../../makefiles/Build.mk

SUBSYSTEM = abstraction
MODULE = sprite_duktape
MODULE_NAME = Abstraction_sprite_Duktape
ifeq ($(MOD), plugin)
  LIBS = -lduktape.dll
else
  LIBS = -lduktape
endif
PREREQS = ../sprite_binding_common.h ../sprite_binding_common.c

include ../../../makefiles/Binding.mk
