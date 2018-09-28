include ../../../makefiles/Build.mk

ifeq ($(PLATFORM), html5)
  $(error SDL2_gpu-based screen module can not be compiled for html5 platform)
endif
SUBSYSTEM = screen
MODULE = sdl2_gpu
MODULE_NAME = Screen_SDL2_gpu
ifeq ($(PLATFORM), linux_x86_64)
  LIBS = -lSDL2_gpu
else
  ifeq ($(MOD), plugin)
    LIBS = -lSDL2.dll -lSDL2_gpu.dll
  else
    LIBS = -lSDL2_gpu -lopengl32 -lSDL2 -lwinmm -limm32 -lole32 -loleaut32 \
     -lversion -luuid
  endif
endif

ifeq ($(CROSSPLATFORM), yes)
  XINCDIRS = -I$(PREFIX)/include/SDL2
else
  XINCDIRS = -I/usr/include/SDL2
endif

include ../../../makefiles/Subsystem.mk
