include ../../../makefiles/Build.mk

SUBSYSTEM = keyboard
MODULE = sdl2_squirrel
MODULE_NAME = Keyboard_SDL2_Squirrel
include ../../../makefiles/Squirrel_libs.mk
PREREQS = ../binding_common.h ../binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/squirrel3
endif

include ../../../makefiles/Binding.mk
