include ../../../makefiles/Build.mk

ifeq ($(PLATFORM), html5)
  $(error SDL2_gpu-based primitive module can not be compiled for html5 \
   platform)
endif
SUBSYSTEM = primitive
MODULE = sdl2_gpu
MODULE_NAME = Primitive_SDL2_gpu
ifeq ($(PLATFORM), linux_x86_64)
  LIBS = -lSDL2_gpu
else
  ifeq ($(MOD), plugin)
    LIBS = -lSDL2_gpu.dll
  else
    LIBS = -lSDL2_gpu -lopengl32
  endif
endif

ifeq ($(CROSSPLATFORM), yes)
  XINCDIRS = -I$(PREFIX)/include/SDL2
else
  XINCDIRS = -I/usr/include/SDL2
endif

include ../../../makefiles/Subsystem.mk
