include ../../../makefiles/Build.mk

SUBSYSTEM = script
MODULE = duktape
MODULE_NAME = Script_Duktape
ifeq ($(PLATFORM), linux_x86_64)
  LIBS = -lduk_module_node -lduktape
else
  ifeq ($(MOD), plugin)
    LIBS = -lduk_module_node -lduktape.dll
  else
    LIBS = -lduk_module_node -lduktape
  endif
endif
PREREQS = ../common.c ../../../include/marathoner/script_func.h

include ../../../makefiles/Subsystem.mk
