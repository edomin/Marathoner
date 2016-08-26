PREFIX = /usr/local/mingw32

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
AUDIO_SDL2_MIXER = audio/sdl2_mixer
AUDIO_SDL2_MIXER_LUA52 = audio/sdl2_mixer_lua52
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
	make -C src/engine PREFIX=$(PREFIX)
	make -C src/$(SCREEN_SDL_GPU) PREFIX=$(PREFIX)
	make -C src/$(SCREEN_SDL_GPU_LUA52) PREFIX=$(PREFIX)
	make -C src/$(TEXTURE_SDL_GPU) PREFIX=$(PREFIX)
	make -C src/$(TEXTURE_SDL_GPU_LUA52) PREFIX=$(PREFIX)
	make -C src/$(PRIMITIVE_SDL_GPU) PREFIX=$(PREFIX)
	make -C src/$(PRIMITIVE_SDL_GPU_LUA52) PREFIX=$(PREFIX)
	make -C src/$(TTF_SDL2_TTF) PREFIX=$(PREFIX)
	make -C src/$(TTF_SDL2_TTF_LUA52) PREFIX=$(PREFIX)
	make -C src/$(AUDIO_SDL2_MIXER) PREFIX=$(PREFIX)
	make -C src/$(AUDIO_SDL2_MIXER_LUA52) PREFIX=$(PREFIX)
	make -C src/$(KEYBOARD_SDL2) PREFIX=$(PREFIX)
	make -C src/$(KEYBOARD_SDL2_LUA52) PREFIX=$(PREFIX)
	make -C src/$(MOUSE_SDL2) PREFIX=$(PREFIX)
	make -C src/$(MOUSE_SDL2_LUA52) PREFIX=$(PREFIX)
	make -C src/$(GAME_CONTROLLER_SDL2) PREFIX=$(PREFIX)
	make -C src/$(GAME_CONTROLLER_SDL2_LUA52) PREFIX=$(PREFIX)
	make -C src/$(TIMER_SDL2) PREFIX=$(PREFIX)
	make -C src/$(TIMER_SDL2_LUA52) PREFIX=$(PREFIX)
	make -C src/$(UTILS_COLOR) PREFIX=$(PREFIX)
	make -C src/$(UTILS_COLOR_LUA52) PREFIX=$(PREFIX)
	make -C src/$(SCRIPT_LUA52) PREFIX=$(PREFIX)

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
