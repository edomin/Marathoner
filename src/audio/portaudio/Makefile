include ../../../makefiles/Build.mk

SUBSYSTEM = audio
MODULE = portaudio
MODULE_NAME = Audio_PortAudio
ifeq ($(PLATFORM), win32)
  LIBS = -lportaudio.dll
endif
ifeq ($(PLATFORM), win64)
  LIBS = -lportaudio_static
endif
ifeq ($(PLATFORM), linux_x86_64)
  LIBS = -lportaudio
endif
PREREQS = ../common.h

include ../../../makefiles/Subsystem.mk
