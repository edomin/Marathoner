include ../../../makefiles/Build.mk

SUBSYSTEM = ttf
MODULE = sdl2_ttf_squirrel
MODULE_NAME = TTF_SDL2_ttf_Squirrel
include ../../../makefiles/Squirrel_libs.mk
PREREQS = ../binding_common.h ../binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/squirrel3
endif

include ../../../makefiles/Binding.mk
