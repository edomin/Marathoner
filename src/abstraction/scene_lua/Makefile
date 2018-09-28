include ../../../makefiles/Build.mk

SUBSYSTEM = abstraction
MODULE = scene_lua
MODULE_NAME = Abstraction_scene_Lua
include ../../../makefiles/Lua_libs.mk
PREREQS = ../scene_binding_common.h ../scene_binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/lua5.3
endif

include ../../../makefiles/Binding.mk
