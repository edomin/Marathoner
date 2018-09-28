include ../../../makefiles/Build.mk

SUBSYSTEM = utils
MODULE = math_squirrel
MODULE_NAME = Utils_math_Squirrel
include ../../../makefiles/Squirrel_libs.mk
PREREQS = ../math_binding_common.h ../math_binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/squirrel3
endif

include ../../../makefiles/Binding.mk
