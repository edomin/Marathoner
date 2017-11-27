include ../../../makefiles/Build.mk

SUBSYSTEM = ttf
MODULE = freetype2
MODULE_NAME = TTF_FreeType2
ifeq ($(PLATFORM), win32)
  ifeq ($(MOD), plugin)
    LIBS = -lfreetype
  else
    LIBS = -lfreetype
  endif
endif
ifeq ($(PLATFORM), win64)
  ifeq ($(MOD), plugin)
    LIBS = -lfreetype -lpng.dll -lz.dll -lbz2
  else
    LIBS = -lfreetype -lpng -lz -lbz2
  endif
endif
ifeq ($(PLATFORM), html5)
  CEXFLAGS = -s USE_FREETYPE=2
  LIBS = -s USE_FREETYPE=2
endif

XINCDIRS = -I$(PREFIX)/include/freetype2

include ../../../makefiles/Subsystem.mk
