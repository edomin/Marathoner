SUBSYSTEM = texture
MODULE = sdl2_gpu
MODULE_NAME = Texture_SDL2_gpu
ifeq ($(MOD), plugin)
  LIBS = -lSDL2.dll -lSDL2_gpu.dll
else
  LIBS = -lSDL2_gpu -lopengl32 -lSDL2 -lwinmm -limm32 -lole32 -loleaut32 \
   -lversion -luuid
endif

XINCDIRS = -I$(PREFIX)/include/SDL2

include ../../../makefiles/Subsystem.mk
