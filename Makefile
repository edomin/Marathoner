OBJSDIR = obj
BINDIR = plugin

SCREEN_SDL_GPU = screen/sdl_gpu
SCREEN_SDL_GPU_LUA52 = screen/sdl_gpu_lua52
TEXTURE_SDL_GPU = texture/sdl_gpu
TEXTURE_SDL_GPU_LUA52 = texture/sdl_gpu_lua52
PRIMITIVE_SDL_GPU = primitive/sdl_gpu
PRIMITIVE_SDL_GPU_LUA52 = primitive/sdl_gpu_lua52
TTF_SDL2_TTF = ttf/sdl2_ttf
TTF_SDL2_TTF_LUA52 = ttf/sdl2_ttf_lua52
KEYBOARD_SDL2 = keyboard/sdl2
KEYBOARD_SDL2_LUA52 = keyboard/sdl2_lua52
MOUSE_SDL2 = mouse/sdl2
MOUSE_SDL2_LUA52 = mouse/sdl2_lua52
GAME_CONTROLLER_SDL2 = game_controller/sdl2
GAME_CONTROLLER_SDL2_LUA52 = game_controller/sdl2_lua52
TIMER_SDL2 = timer/sdl2
TIMER_SDL2_LUA52 = timer/sdl2_lua52
UTILS_COLOR = utils/color
UTILS_COLOR_LUA52 = utils/color_lua52
SCRIPT_LUA52 = script/lua52

all: prebuild
	make -C src/engine
	make -C src/$(SCREEN_SDL_GPU)
	make -C src/$(SCREEN_SDL_GPU_LUA52)
	make -C src/$(TEXTURE_SDL_GPU)
	make -C src/$(TEXTURE_SDL_GPU_LUA52)
	make -C src/$(PRIMITIVE_SDL_GPU)
	make -C src/$(PRIMITIVE_SDL_GPU_LUA52)
	make -C src/$(TTF_SDL2_TTF)
	make -C src/$(TTF_SDL2_TTF_LUA52)
	make -C src/$(KEYBOARD_SDL2)
	make -C src/$(KEYBOARD_SDL2_LUA52)
	make -C src/$(MOUSE_SDL2)
	make -C src/$(MOUSE_SDL2_LUA52)
	make -C src/$(GAME_CONTROLLER_SDL2)
	make -C src/$(GAME_CONTROLLER_SDL2_LUA52)
	make -C src/$(TIMER_SDL2)
	make -C src/$(TIMER_SDL2_LUA52)
	make -C src/$(UTILS_COLOR)
	make -C src/$(UTILS_COLOR_LUA52)
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
