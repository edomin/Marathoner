include ../../../makefiles/Build.mk

SUBSYSTEM = ttf
MODULE = freetype2_duktape
MODULE_NAME = TTF_FreeType2_Duktape
ifeq ($(MOD), plugin)
  LIBS = -lduktape.dll
else
  LIBS = -lduktape
endif
PREREQS = ../binding_common.h ../binding_common.c

include ../../../makefiles/Binding.mk
