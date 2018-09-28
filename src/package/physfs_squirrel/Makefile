include ../../../makefiles/Build.mk

SUBSYSTEM = package
MODULE = physfs_squirrel
MODULE_NAME = Package_PhysFS_Squirrel
include ../../../makefiles/Squirrel_libs.mk
PREREQS = ../binding_common.h ../binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/squirrel3
endif

include ../../../makefiles/Binding.mk
