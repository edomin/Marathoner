include ../../../makefiles/Build.mk

SUBSYSTEM = abstraction
MODULE = font_lua
MODULE_NAME = Abstraction_font_Lua
include ../../../makefiles/Lua_libs.mk
PREREQS = ../font_binding_common.h ../font_binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/lua5.3
endif

include ../../../makefiles/Binding.mk
