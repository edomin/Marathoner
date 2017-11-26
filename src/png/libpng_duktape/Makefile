include ../../../makefiles/Build.mk

SUBSYSTEM = png
MODULE = libpng_duktape
MODULE_NAME = PNG_libpng_Duktape
ifeq ($(MOD), plugin)
  LIBS = -lduktape.dll
else
  LIBS = -lduktape
endif
PREREQS = ../binding_common.h ../binding_common.c

include ../../../makefiles/Binding.mk
