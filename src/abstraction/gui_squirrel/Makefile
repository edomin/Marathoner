include ../../../makefiles/Build.mk

SUBSYSTEM = abstraction
MODULE = gui_squirrel
MODULE_NAME = Abstraction_gui_Squirrel
include ../../../makefiles/Squirrel_libs.mk
PREREQS = ../gui_binding_common.h ../gui_binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/squirrel3
endif

include ../../../makefiles/Binding.mk
