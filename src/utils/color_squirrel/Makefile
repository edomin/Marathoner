include ../../../makefiles/Build.mk

SUBSYSTEM = utils
MODULE = color_squirrel
MODULE_NAME = Utils_color_Squirrel
include ../../../makefiles/Squirrel_libs.mk
PREREQS = ../color_binding_common.h ../color_binding_common.c ../color_common.h

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/squirrel3
endif

include ../../../makefiles/Binding.mk
