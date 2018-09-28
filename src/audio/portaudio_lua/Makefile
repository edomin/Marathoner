include ../../../makefiles/Build.mk

SUBSYSTEM = audio
MODULE = portaudio_lua
MODULE_NAME = Audio_PortAudio_Lua
include ../../../makefiles/Lua_libs.mk
PREREQS = ../binding_common.h ../binding_common.c ../common.h

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/lua5.3
endif

include ../../../makefiles/Binding.mk
