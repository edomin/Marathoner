include ../../../makefiles/Build.mk

SUBSYSTEM = ttf
MODULE = freetype2_squirrel
MODULE_NAME = TTF_FreeType2_Squirrel
include ../../../makefiles/Squirrel_libs.mk
PREREQS = ../binding_common.h ../binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/squirrel3
endif

include ../../../makefiles/Binding.mk
