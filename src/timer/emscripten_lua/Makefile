include ../../../makefiles/Build.mk

ifneq ($(PLATFORM), html5)
  $(error Binding for Emscripten-based timer module can not be compiled for \
   $(PLATFORM) platform)
endif
SUBSYSTEM = timer
MODULE = emscripten_lua
MODULE_NAME = Timer_Emscripten_Lua
include ../../../makefiles/Lua_libs.mk
PREREQS = ../binding_common.h ../binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/lua5.3
endif

include ../../../makefiles/Binding.mk
