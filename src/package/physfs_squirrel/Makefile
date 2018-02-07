include ../../../makefiles/Build.mk

SUBSYSTEM = package
MODULE = physfs_squirrel
MODULE_NAME = Package_PhysFS_Squirrel
ifeq ($(MOD), plugin)
  LIBS = -lsquirrel.dll
else
  LIBS = -lsquirrel_static
endif
PREREQS = ../binding_common.h ../binding_common.c

include ../../../makefiles/Binding.mk
