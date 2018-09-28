include ../../../makefiles/Build.mk

ifeq ($(PLATFORM), html5)
  $(error Binding module for SDL2_gpu-based screen module can not be compiled \
   for html5 platform)
endif
SUBSYSTEM = screen
MODULE = sdl2_gpu_duktape
MODULE_NAME = Screen_SDL2_gpu_Duktape
include ../../../makefiles/Duktape_libs.mk
PREREQS = ../binding_common.h ../binding_common.c

include ../../../makefiles/Binding.mk
