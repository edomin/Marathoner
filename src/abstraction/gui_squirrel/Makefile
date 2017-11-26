include ../../../makefiles/Build.mk

SUBSYSTEM = abstraction
MODULE = gui_squirrel
MODULE_NAME = Abstraction_gui_Squirrel
ifeq ($(MOD), plugin)
  LIBS = -lsquirrel
else
  LIBS = -lsquirrel_static
endif
PREREQS = ../gui_binding_common.h ../gui_binding_common.c

include ../../../makefiles/Binding.mk
