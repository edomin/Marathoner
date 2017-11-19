SUBSYSTEM = json
MODULE = cjson_squirrel
MODULE_NAME = JSON_cJSON_Squirrel
ifeq ($(MOD), plugin)
  LIBS = -lsquirrel
else
  LIBS = -lsquirrel_static
endif
PREREQS = ../binding_common.h ../binding_common.c

include ../../../makefiles/Binding.mk
