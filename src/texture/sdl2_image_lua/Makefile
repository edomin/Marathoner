include ../../../makefiles/Build.mk

SUBSYSTEM = texture
MODULE = sdl2_image_lua
MODULE_NAME = Texture_SDL2_image_Lua
include ../../../makefiles/Lua_libs.mk
PREREQS = ../binding_common.h ../binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/lua5.3
endif

include ../../../makefiles/Binding.mk
