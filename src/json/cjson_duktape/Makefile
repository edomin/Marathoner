include ../../../makefiles/Build.mk

SUBSYSTEM = json
MODULE = cjson_duktape
MODULE_NAME = JSON_cJSON_Duktape
ifeq ($(MOD), plugin)
  LIBS = -lduktape.dll
else
  LIBS = -lduktape
endif
PREREQS = ../binding_common.h ../binding_common.c

include ../../../makefiles/Binding.mk
