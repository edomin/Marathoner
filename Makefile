CC = mingw32-gcc
LD = mingw32-gcc
OBJSDIR = obj
BINDIR = plugin

#GENERAL_SDL2 = general/sdl2
#SCREEN_SDL2 = screen/sdl2
SCREEN_SDL_GPU = screen/sdl_gpu

all: prebuild
	make -C src/engine
#	make -C src/$(GENERAL_SDL2)
#	make -C src/$(SCREEN_SDL2)
	make -C src/$(SCREEN_SDL_GPU)

prebuild:
	-mkdir $(OBJSDIR)
	-mkdir $(BINDIR)

clean:
	-rm -f -r $(OBJSDIR)
	-rm -f -r $(BINDIR)
	-rm -f -r marathoner.exe

.PHONY:
