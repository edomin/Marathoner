include ../../../makefiles/Build.mk

SUBSYSTEM = abstraction
MODULE = font_duktape
MODULE_NAME = Abstraction_font_Duktape
ifeq ($(MOD), plugin)
  LIBS = -lduktape.dll
else
  LIBS = -lduktape
endif
PREREQS = ../font_binding_common.h ../font_binding_common.c

include ../../../makefiles/Binding.mk
