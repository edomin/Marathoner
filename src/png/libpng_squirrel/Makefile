include ../../../makefiles/Build.mk

SUBSYSTEM = png
MODULE = libpng_squirrel
MODULE_NAME = PNG_libpng_Squirrel
include ../../../makefiles/Squirrel_libs.mk
PREREQS = ../binding_common.h ../binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/squirrel3
endif

include ../../../makefiles/Binding.mk
