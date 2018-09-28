include ../../../makefiles/Build.mk

SUBSYSTEM = abstraction
MODULE = scene_squirrel
MODULE_NAME = Abstraction_scene_Squirrel
include ../../../makefiles/Squirrel_libs.mk
PREREQS = ../scene_binding_common.h ../scene_binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/squirrel3
endif

include ../../../makefiles/Binding.mk
