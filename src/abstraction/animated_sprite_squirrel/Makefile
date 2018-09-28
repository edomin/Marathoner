include ../../../makefiles/Build.mk

SUBSYSTEM = abstraction
MODULE = animated_sprite_squirrel
MODULE_NAME = Abstraction_animated_sprite_Squirrel
include ../../../makefiles/Squirrel_libs.mk
PREREQS = ../sprite_binding_common.h ../sprite_binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/squirrel3
endif

include ../../../makefiles/Binding.mk
