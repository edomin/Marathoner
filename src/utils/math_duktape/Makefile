SUBSYSTEM = utils
MODULE = math_duktape
MODULE_NAME = Utils_math_Duktape
ifeq ($(MOD), plugin)
  LIBS = -lduktape.dll
else
  LIBS = -lduktape
endif
PREREQS = ../math_binding_common.h ../math_binding_common.c

include ../../../makefiles/Binding.mk
