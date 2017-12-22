include ../../../makefiles/Build.mk

SUBSYSTEM = utils
MODULE = math_squirrel
MODULE_NAME = Utils_math_Squirrel
ifeq ($(MOD), plugin)
  LIBS = -lsquirrel.dll
else
  LIBS = -lsquirrel_static
endif
PREREQS = ../math_binding_common.h ../math_binding_common.c

include ../../../makefiles/Binding.mk
