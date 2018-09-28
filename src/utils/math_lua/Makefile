include ../../../makefiles/Build.mk

SUBSYSTEM = utils
MODULE = math_lua
MODULE_NAME = Utils_math_Lua
include ../../../makefiles/Lua_libs.mk
PREREQS = ../math_binding_common.h ../math_binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/lua5.3
endif

include ../../../makefiles/Binding.mk
