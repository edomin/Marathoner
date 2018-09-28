include ../../../makefiles/Build.mk

SUBSYSTEM = ttf
MODULE = freetype2_lua
MODULE_NAME = TTF_FreeType2_Lua
include ../../../makefiles/Lua_libs.mk
PREREQS = ../binding_common.h ../binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/lua5.3
endif

include ../../../makefiles/Binding.mk
