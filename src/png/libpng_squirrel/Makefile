include ../../../makefiles/Build.mk

SUBSYSTEM = png
MODULE = libpng_squirrel
MODULE_NAME = PNG_libpng_Squirrel
ifeq ($(MOD), plugin)
  LIBS = -lsquirrel.dll
else
  LIBS = -lsquirrel_static
endif
PREREQS = ../binding_common.h ../binding_common.c

include ../../../makefiles/Binding.mk
