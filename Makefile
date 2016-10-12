include Build.mk

OBJSDIR = obj
LIBDIR = lib
BINDIR = plugin

SCREEN_SDL2 = screen/sdl2
SCREEN_SDL2_LUA52 = screen/sdl2_lua52
SCREEN_SDL_GPU = screen/sdl_gpu
SCREEN_SDL_GPU_LUA52 = screen/sdl_gpu_lua52
TEXTURE_SDL2_IMAGE = texture/sdl2_image
TEXTURE_SDL2_IMAGE_LUA52 = texture/sdl2_image_lua52
TEXTURE_SDL_GPU = texture/sdl_gpu
TEXTURE_SDL_GPU_LUA52 = texture/sdl_gpu_lua52
PRIMITIVE_SDL2 = primitive/sdl2
PRIMITIVE_SDL2_LUA52 = primitive/sdl2_lua52
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

all: $(PLATFORM)

win32: prebuild
	make -C src/$(SCREEN_SDL_GPU) PREFIX=$(PREFIX)
	make -C src/$(SCREEN_SDL_GPU_LUA52) PREFIX=$(PREFIX)
	make -C src/$(TEXTURE_SDL_GPU) PREFIX=$(PREFIX)
	make -C src/$(TEXTURE_SDL_GPU_LUA52) PREFIX=$(PREFIX)
	make -C src/$(PRIMITIVE_SDL_GPU) PREFIX=$(PREFIX)
	make -C src/$(PRIMITIVE_SDL_GPU_LUA52) PREFIX=$(PREFIX)

	make -C src/$(SCREEN_SDL2) PREFIX=$(PREFIX)
	make -C src/$(SCREEN_SDL2_LUA52) PREFIX=$(PREFIX)
	make -C src/$(TEXTURE_SDL2_IMAGE) PREFIX=$(PREFIX)
	make -C src/$(TEXTURE_SDL2_IMAGE_LUA52) PREFIX=$(PREFIX)
	make -C src/$(PRIMITIVE_SDL2) PREFIX=$(PREFIX)
	make -C src/$(PRIMITIVE_SDL2_LUA52) PREFIX=$(PREFIX)

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
	make -C src/engine PREFIX=$(PREFIX)

html5: prebuild
	make -C src/$(SCREEN_SDL2) PREFIX=$(PREFIX)
	make -C src/$(SCREEN_SDL2_LUA52) PREFIX=$(PREFIX)
	make -C src/$(TEXTURE_SDL2_IMAGE) PREFIX=$(PREFIX)
	make -C src/$(TEXTURE_SDL2_IMAGE_LUA52) PREFIX=$(PREFIX)
	make -C src/$(PRIMITIVE_SDL2) PREFIX=$(PREFIX)
	make -C src/$(PRIMITIVE_SDL2_LUA52) PREFIX=$(PREFIX)
	make -C src/$(TTF_SDL2_TTF) PREFIX=$(PREFIX)
	make -C src/$(TTF_SDL2_TTF_LUA52) PREFIX=$(PREFIX)
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
	make -C src/engine PREFIX=$(PREFIX)

prebuild:
	-mkdir $(OBJSDIR)
	-mkdir $(LIBDIR)
	-mkdir $(BINDIR)

clean:
	-rm -f -r $(OBJSDIR)
	-rm -f -r $(LIBDIR)
	-rm -f -r $(BINDIR)
	-rm -f -r marathoner.exe
	-rm -f -r marathoner.html
	-rm -f -r marathoner.js

remake: clean all

.PHONY: engine prebuild remake clean all
