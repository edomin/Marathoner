include ../../../makefiles/Build.mk

SUBSYSTEM = utils
MODULE = color_duktape
MODULE_NAME = Utils_color_Duktape
ifeq ($(MOD), plugin)
  LIBS = -lduktape.dll
else
  LIBS = -lduktape
endif
PREREQS = ../color_binding_common.h ../color_binding_common.c ../color_common.h

include ../../../makefiles/Binding.mk
