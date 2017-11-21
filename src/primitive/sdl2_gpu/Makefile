SUBSYSTEM = primitive
MODULE = sdl2_gpu
MODULE_NAME = Primitive_SDL2_gpu
ifeq ($(MOD), plugin)
  LIBS = -lSDL2_gpu.dll
else
  LIBS = -lSDL2_gpu -lopengl32
endif

XINCDIRS = -I$(PREFIX)/include/SDL2

include ../../../makefiles/Subsystem.mk
