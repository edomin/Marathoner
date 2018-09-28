include ../../../makefiles/Build.mk

SUBSYSTEM = audio
MODULE = sdl2_mixer_lua
MODULE_NAME = Audio_SDL2_mixer_Lua
include ../../../makefiles/Lua_libs.mk
PREREQS = ../binding_common.h ../binding_common.c ../common.h

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/lua5.3
endif

include ../../../makefiles/Binding.mk
