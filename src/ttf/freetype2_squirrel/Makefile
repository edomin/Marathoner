include ../../../makefiles/Build.mk

SUBSYSTEM = ttf
MODULE = freetype2_squirrel
MODULE_NAME = TTF_FreeType2_Squirrel
ifeq ($(MOD), plugin)
  LIBS = -lsquirrel.dll
else
  LIBS = -lsquirrel_static
endif
PREREQS = ../binding_common.h ../binding_common.c

include ../../../makefiles/Binding.mk
