include ../../../Build.mk

SUBSYSTEM = texture
MODULE = sdl2_image
MODULE_NAME = Texture_SDL2_image
ifeq ($(PLATFORM), win32)
  LIBS = -lSDL2_image.dll -lSDL2.dll
endif
ifeq ($(PLATFORM), win64)
  LIBS = -lSDL2_image.dll -lSDL2.dll
endif
ifeq ($(PLATFORM), html5)
  LIBS = $(PREFIX)/lib/sdl2-image-bmp-gif-lbm-pcx-png-pnm-tga-xcf-xpm-xv.bc \
   $(PREFIX)/lib/libpng.bc \
   $(PREFIX)/lib/zlib.bc \
   $(PREFIX)/lib/sdl2.bc \
   $(PREFIX)/lib/gl.bc
endif

include ../../../Subsystem.mk
