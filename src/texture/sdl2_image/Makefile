include ../../../makefiles/Build.mk

SUBSYSTEM = texture
MODULE = sdl2_image
MODULE_NAME = Texture_SDL2_image
ifeq ($(PLATFORM), win32)
  ifeq ($(MOD), plugin)
    LIBS = -lSDL2.dll -lSDL2_image.dll
  else
    LIBS = -lSDL2_image -lSDL2 -lwinmm -limm32 -lole32 -loleaut32 -lversion \
     -luuid -ltiff -llzma -ljpeg -lwebp
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
  CEXFLAGS = -s USE_SDL=2 -s USE_SDL_IMAGE=2 \
   -s SDL2_IMAGE_FORMATS="['bmp','gif','lbm','pcx','png','pnm','tga','xcf','xpm','xv']"
  LIBS = -s USE_SDL_IMAGE=2 -s USE_SDL=2 \
   -s SDL2_IMAGE_FORMATS=\"[\'bmp\',\'gif\',\'lbm\',\'pcx\',\'png\',\'pnm\',\'tga\',\'xcf\',\'xpm\',\'xv\']\" \
   -s USE_LIBPNG=1 -s USE_ZLIB=1
endif

include ../../../makefiles/Subsystem.mk
