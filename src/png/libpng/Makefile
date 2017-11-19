include ../../../makefiles/Build.mk

SUBSYSTEM = png
MODULE = libpng
MODULE_NAME = PNG_libpng
MODULE_H = png_include.h
ifeq ($(MOD), plugin)
  LIBS = -lpng.dll -lz.dll
else
  LIBS = -lpng -lz
endif

include ../../../makefiles/Subsystem.mk
