include ../../../makefiles/Build.mk

SUBSYSTEM = primitive
MODULE = sdl2_gfx_lua
MODULE_NAME = Primitive_SDL2_gfx_Lua
include ../../../makefiles/Lua_libs.mk
PREREQS = ../binding_common.h ../binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/lua5.3
endif

include ../../../makefiles/Binding.mk
