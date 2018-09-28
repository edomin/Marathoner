include ../../../makefiles/Build.mk

SUBSYSTEM = utils
MODULE = color_lua
MODULE_NAME = Utils_color_Lua
include ../../../makefiles/Lua_libs.mk
PREREQS = ../color_binding_common.h ../color_binding_common.c \
 ../color_common.h

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/lua5.3
endif

include ../../../makefiles/Binding.mk
