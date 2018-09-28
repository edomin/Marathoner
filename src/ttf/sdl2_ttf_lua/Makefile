include ../../../makefiles/Build.mk

SUBSYSTEM = ttf
MODULE = sdl2_ttf_lua
MODULE_NAME = TTF_SDL2_ttf_Lua
include ../../../makefiles/Lua_libs.mk
PREREQS = ../binding_common.h ../binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/lua5.3
endif

include ../../../makefiles/Binding.mk
