include ../../../makefiles/Build.mk

ifneq ($(PLATFORM), html5)
  $(error Binding for Emscripten-based timer module can not be compiled for \
   $(PLATFORM) platform)
endif
SUBSYSTEM = timer
MODULE = emscripten_duktape
MODULE_NAME = Timer_Emscripten_Duktape
PREREQS = ../binding_common.h ../binding_common.c

include ../../../makefiles/Binding.mk
