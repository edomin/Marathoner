OBJSDIR = obj
BINDIR = plugin

#GENERAL_SDL2 = general/sdl2
#SCREEN_SDL2 = screen/sdl2
SCREEN_SDL_GPU = screen/sdl_gpu
SCREEN_SDL_GPU_LUA52 = screen/sdl_gpu_lua52
SCRIPT_LUA52 = script/lua52

all: prebuild
	make -C src/engine
#	make -C src/$(GENERAL_SDL2)
#	make -C src/$(SCREEN_SDL2)
	make -C src/$(SCREEN_SDL_GPU)
	make -C src/$(SCREEN_SDL_GPU_LUA52)
	make -C src/$(SCRIPT_LUA52)

prebuild:
	-mkdir $(OBJSDIR)
	-mkdir $(BINDIR)

engine: prebuild
	make -C src/engine

clean:
	-rm -f -r $(OBJSDIR)
	-rm -f -r $(BINDIR)
	-rm -f -r marathoner.exe

remake: clean all

.PHONY: engine prebuild remake clean all
