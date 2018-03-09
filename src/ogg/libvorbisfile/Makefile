include ../../../makefiles/Build.mk

SUBSYSTEM = ogg
MODULE = libvorbisfile
MODULE_NAME = OGG_libvorbisfile
ifeq ($(PLATFORM), win32)
  ifeq ($(MOD), plugin)
    LIBS = -lvorbisfile.dll -lvorbis.dll
  else
    LIBS = -lvorbisfile -lvorbis -logg
  endif
endif
ifeq ($(PLATFORM), win64)
  ifeq ($(MOD), plugin)
    LIBS = -lvorbisfile.dll
  else
    LIBS = -lvorbisfile -lvorbis -logg
  endif
endif
ifeq ($(PLATFORM), html5)
  LIBS = -s USE_VORBIS=1 -s USE_OGG=1
endif

include ../../../makefiles/Subsystem.mk
