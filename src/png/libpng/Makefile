include ../../../makefiles/Build.mk

SUBSYSTEM = png
MODULE = libpng
MODULE_NAME = PNG_libpng
MODULE_H = png_include.h
ifeq ($(PLATFORM), win32)
  ifeq ($(MOD), plugin)
    LIBS = -lpng.dll -lz.dll
  else
    LIBS = -lpng -lz
  endif
endif
ifeq ($(PLATFORM), win64)
  ifeq ($(MOD), plugin)
    LIBS = -lpng.dll -lz.dll
  else
    LIBS = -lpng -lz
  endif
endif
ifeq ($(PLATFORM), linux_x86_64)
  LIBS = -lpng
endif
ifeq ($(PLATFORM), html5)
  CEXFLAGS = -s USE_LIBPNG=1 -s USE_ZLIB=1
  LIBS = -s USE_LIBPNG=1 -s USE_ZLIB=1
endif

include ../../../makefiles/Subsystem.mk
