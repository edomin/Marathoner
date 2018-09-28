include ../../../makefiles/Build.mk

SUBSYSTEM = texture
MODULE = sdl2_image_squirrel
MODULE_NAME = Texture_SDL2_image_Squirrel
include ../../../makefiles/Squirrel_libs.mk
PREREQS = ../binding_common.h ../binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/squirrel3
endif

include ../../../makefiles/Binding.mk
