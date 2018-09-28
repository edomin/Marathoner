include ../../../makefiles/Build.mk

SUBSYSTEM = script
MODULE = lua
MODULE_NAME = Script_Lua
include ../../../makefiles/Lua_libs.mk
PREREQS = ../common.c ../../../include/marathoner/script_func.h
SCRIPT = yes

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/lua5.3
endif

include ../../../makefiles/Subsystem.mk
