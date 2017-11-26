include ../../../makefiles/Build.mk

SUBSYSTEM = script
MODULE = squirrel
MODULE_NAME = Script_Squirrel
ifeq ($(MOD), plugin)
  LIBS = -lsqstdlib_static -lsquirrel -lstdc++
else
  LIBS = -lsqstdlib_static -lsquirrel_static -lstdc++
endif
PREREQS = ../common.c ../../../include/marathoner/script_func.h

include ../../../makefiles/Subsystem.mk
