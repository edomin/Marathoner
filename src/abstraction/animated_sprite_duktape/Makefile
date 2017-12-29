include ../../../makefiles/Build.mk

SUBSYSTEM = abstraction
MODULE = animated_sprite_duktape
MODULE_NAME = Abstraction_animated_sprite_Duktape
ifeq ($(MOD), plugin)
  LIBS = -lduktape.dll
else
  LIBS = -lduktape
endif
PREREQS = ../animated_sprite_binding_common.h \
 ../animated_sprite_binding_common.c

include ../../../makefiles/Binding.mk
