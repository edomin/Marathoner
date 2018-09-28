include ../../../makefiles/Build.mk

SUBSYSTEM = abstraction
MODULE = font_squirrel
MODULE_NAME = Abstraction_font_Squirrel
include ../../../makefiles/Squirrel_libs.mk
PREREQS = ../font_binding_common.h ../font_binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/squirrel3
endif

include ../../../makefiles/Binding.mk
