include ../../../makefiles/Build.mk

ifeq ($(PLATFORM), html5)
  $(error Binding module for SDL2_gpu-based texture module can not be compiled \
   for html5 platform)
endif
SUBSYSTEM = texture
MODULE = sdl2_gpu_duktape
MODULE_NAME = Texture_SDL2_gpu_Duktape
include ../../../makefiles/Duktape_libs.mk
PREREQS = ../binding_common.h ../binding_common.c

include ../../../makefiles/Binding.mk
