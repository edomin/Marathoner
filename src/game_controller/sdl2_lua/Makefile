include ../../../makefiles/Build.mk

SUBSYSTEM = game_controller
MODULE = sdl2_lua
MODULE_NAME = Game_Controller_SDL2_Lua
include ../../../makefiles/Lua_libs.mk
PREREQS = ../binding_common.h ../binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/lua5.3
endif

include ../../../makefiles/Binding.mk
