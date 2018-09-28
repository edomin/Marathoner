include ../../../makefiles/Build.mk

SUBSYSTEM = audio
MODULE = portaudio_squirrel
MODULE_NAME = Audio_PortAudio_Squirrel
include ../../../makefiles/Squirrel_libs.mk
PREREQS = ../binding_common.h ../binding_common.c ../common.h

ifeq ($(CROSSPLATFORM), no)
  XINCDIRS = -I/usr/include/squirrel3
endif

include ../../../makefiles/Binding.mk
