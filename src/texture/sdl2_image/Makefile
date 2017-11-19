include ../../../makefiles/Build.mk

SUBSYSTEM = texture
MODULE = sdl2_image
MODULE_NAME = Texture_SDL2_image
ifeq ($(PLATFORM), win32)
  ifeq ($(MOD), plugin)
    LIBS = -lSDL2.dll -lSDL2_image.dll
  else
    LIBS = -lSDL2_image -lSDL2 -lwinmm -limm32 -lole32 -loleaut32 -lversion \
     -luuid -ltiff -ljpeg -lwebp
  endif
endif
ifeq ($(PLATFORM), win64)
  ifeq ($(MOD), plugin)
    LIBS = -lSDL2.dll -lSDL2_image.dll
  else
    LIBS = -lSDL2_image -lSDL2 -lwinmm -limm32 -lole32 -loleaut32 -lversion \
     -luuid -ltiff -ljpeg -lwebp
  endif
endif
ifeq ($(PLATFORM), html5)
  LIBS = $(PREFIX)/lib/sdl2-image-bmp-gif-lbm-pcx-png-pnm-tga-xcf-xpm-xv.bc \
   $(PREFIX)/lib/libpng.bc \
   $(PREFIX)/lib/zlib.bc \
   $(PREFIX)/lib/sdl2.bc \
   $(PREFIX)/lib/gl.bc
endif

include ../../../makefiles/Subsystem.mk
