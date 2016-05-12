OBJSDIR = obj
BINDIR = plugin

#GENERAL_SDL2 = general/sdl2
#SCREEN_SDL2 = screen/sdl2
SCREEN_SDL_GPU = screen/sdl_gpu
SCRIPT_LUA52 = script/lua52

all: prebuild
	make -C src/engine
#	make -C src/$(GENERAL_SDL2)
#	make -C src/$(SCREEN_SDL2)
	make -C src/$(SCREEN_SDL_GPU)
	make -C src/$(SCRIPT_LUA52)

prebuild:
	-mkdir $(OBJSDIR)
	-mkdir $(BINDIR)

clean:
	-rm -f -r $(OBJSDIR)
	-rm -f -r $(BINDIR)
	-rm -f -r marathoner.exe

.PHONY:
