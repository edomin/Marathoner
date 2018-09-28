include ../../../makefiles/Build.mk

SUBSYSTEM = script
MODULE = squirrel
MODULE_NAME = Script_Squirrel
ifeq ($(PLATFORM), linux_x86_64)
  ifeq ($(CROSSPLATFORM), yes)
    LIBS = -lsquirrel
  else
    LIBS = -lsquirrel3
    LDFLAGS += -L/usr/lib/x86_64-linux-gnu
  endif
else
  ifeq ($(MOD), plugin)
    LIBS = -lsqstdlib_static -lsquirrel.dll -Wl,-Bstatic -lstdc++
  else
    LIBS = -lsqstdlib_static -lsquirrel_static -lstdc++
  endif
endif
PREREQS = ../common.c ../../../include/marathoner/script_func.h

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/squirrel3
endif

include ../../../makefiles/Subsystem.mk
