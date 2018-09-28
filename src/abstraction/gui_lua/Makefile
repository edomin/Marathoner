include ../../../makefiles/Build.mk

SUBSYSTEM = abstraction
MODULE = gui_lua
MODULE_NAME = Abstraction_gui_Lua
include ../../../makefiles/Lua_libs.mk
PREREQS = ../gui_binding_common.h ../gui_binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/lua5.3
endif

include ../../../makefiles/Binding.mk
