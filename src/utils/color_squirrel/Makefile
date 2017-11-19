SUBSYSTEM = utils
MODULE = color_squirrel
MODULE_NAME = Utils_color_Squirrel
ifeq ($(MOD), plugin)
  LIBS = -lsquirrel
else
  LIBS = -lsquirrel_static
endif
PREREQS = ../color_binding_common.h ../color_binding_common.c ../color_common.h

include ../../../makefiles/Binding.mk
