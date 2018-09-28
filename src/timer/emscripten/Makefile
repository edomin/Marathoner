include ../../../makefiles/Build.mk

ifneq ($(PLATFORM), html5)
  $(error Emscripten-based timer module can not be compiled for $(PLATFORM) \
   platform)
endif
SUBSYSTEM = timer
MODULE = emscripten
MODULE_NAME = Timer_Emscripten
LIBS = -s EMTERPRETIFY_WHITELIST=\'[\"_MTR_TimerDelay\"]\'

include ../../../makefiles/Subsystem.mk
