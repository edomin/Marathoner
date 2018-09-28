include ../../../makefiles/Build.mk

SUBSYSTEM = png
MODULE = libpng_lua
MODULE_NAME = PNG_libpng_Lua
include ../../../makefiles/Lua_libs.mk
PREREQS = ../binding_common.h ../binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/lua5.3
endif

include ../../../makefiles/Binding.mk
