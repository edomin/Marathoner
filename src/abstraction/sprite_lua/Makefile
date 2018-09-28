include ../../../makefiles/Build.mk

SUBSYSTEM = abstraction
MODULE = sprite_lua
MODULE_NAME = Abstraction_sprite_Lua
include ../../../makefiles/Lua_libs.mk
PREREQS = ../sprite_binding_common.h ../sprite_binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/lua5.3
endif

include ../../../makefiles/Binding.mk
