include ../../../makefiles/Build.mk

ifneq ($(PLATFORM), html5)
  $(error Binding for Emscripten-based timer module can not be compiled for \
   $(PLATFORM) platform)
endif
SUBSYSTEM = timer
MODULE = emscripten_squirrel
MODULE_NAME = Timer_Emscripten_Squirrel
PREREQS = ../binding_common.h ../binding_common.c

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/squirrel3
endif

include ../../../makefiles/Binding.mk
