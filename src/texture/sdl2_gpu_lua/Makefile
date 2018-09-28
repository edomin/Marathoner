include ../../../makefiles/Build.mk

ifeq ($(PLATFORM), html5)
  $(error Binding module for SDL2_gpu-based texture module can not be compiled \
   for html5 platform)
endif
SUBSYSTEM = texture
MODULE = sdl2_gpu_lua
MODULE_NAME = Texture_SDL2_gpu_Lua
include ../../../makefiles/Lua_libs.mk
PREREQS = ../binding_common.h ../binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/lua5.3
endif

include ../../../makefiles/Binding.mk
