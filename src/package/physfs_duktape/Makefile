include ../../../makefiles/Build.mk

SUBSYSTEM = package
MODULE = physfs_duktape
MODULE_NAME = Package_PhysFS_Duktape
ifeq ($(MOD), plugin)
  LIBS = -lduktape.dll
else
  LIBS = -lduktape
endif
PREREQS = ../binding_common.h ../binding_common.c

include ../../../makefiles/Binding.mk
