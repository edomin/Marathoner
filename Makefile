include Build.mk

OBJSDIR = obj
LIBDIR = lib
BINDIR = plugin

SCREEN_SDL2 = screen/sdl2
SCREEN_SDL2_LUA = screen/sdl2_lua
SCREEN_SDL2_GPU = screen/sdl2_gpu
SCREEN_SDL2_GPU_LUA = screen/sdl2_gpu_lua
TEXTURE_SDL2_IMAGE = texture/sdl2_image
TEXTURE_SDL2_IMAGE_LUA = texture/sdl2_image_lua
TEXTURE_SDL2_GPU = texture/sdl2_gpu
TEXTURE_SDL2_GPU_LUA = texture/sdl2_gpu_lua
PRIMITIVE_SDL2 = primitive/sdl2
PRIMITIVE_SDL2_LUA = primitive/sdl2_lua
PRIMITIVE_SDL2_GPU = primitive/sdl2_gpu
PRIMITIVE_SDL2_GPU_LUA = primitive/sdl2_gpu_lua
TTF_SDL2_TTF = ttf/sdl2_ttf
TTF_SDL2_TTF_LUA = ttf/sdl2_ttf_lua
AUDIO_SDL2_MIXER = audio/sdl2_mixer
AUDIO_SDL2_MIXER_LUA = audio/sdl2_mixer_lua
KEYBOARD_SDL2 = keyboard/sdl2
KEYBOARD_SDL2_LUA = keyboard/sdl2_lua
MOUSE_SDL2 = mouse/sdl2
MOUSE_SDL2_LUA = mouse/sdl2_lua
GAME_CONTROLLER_SDL2 = game_controller/sdl2
GAME_CONTROLLER_SDL2_LUA = game_controller/sdl2_lua
TIMER_SDL2 = timer/sdl2
TIMER_SDL2_LUA = timer/sdl2_lua
UTILS_COLOR = utils/color
UTILS_COLOR_LUA = utils/color_lua
SCRIPT_LUA = script/lua

all: $(PLATFORM)

win32: prebuild
	make -C src/$(SCREEN_SDL2_GPU) PREFIX=$(PREFIX)
	make -C src/$(SCREEN_SDL2_GPU_LUA) PREFIX=$(PREFIX)
	make -C src/$(TEXTURE_SDL2_GPU) PREFIX=$(PREFIX)
	make -C src/$(TEXTURE_SDL2_GPU_LUA) PREFIX=$(PREFIX)
	make -C src/$(PRIMITIVE_SDL2_GPU) PREFIX=$(PREFIX)
	make -C src/$(PRIMITIVE_SDL2_GPU_LUA) PREFIX=$(PREFIX)

	make -C src/$(SCREEN_SDL2) PREFIX=$(PREFIX)
	make -C src/$(SCREEN_SDL2_LUA) PREFIX=$(PREFIX)
	make -C src/$(TEXTURE_SDL2_IMAGE) PREFIX=$(PREFIX)
	make -C src/$(TEXTURE_SDL2_IMAGE_LUA) PREFIX=$(PREFIX)
	make -C src/$(PRIMITIVE_SDL2) PREFIX=$(PREFIX)
	make -C src/$(PRIMITIVE_SDL2_LUA) PREFIX=$(PREFIX)

	make -C src/$(TTF_SDL2_TTF) PREFIX=$(PREFIX)
	make -C src/$(TTF_SDL2_TTF_LUA) PREFIX=$(PREFIX)
	make -C src/$(AUDIO_SDL2_MIXER) PREFIX=$(PREFIX)
	make -C src/$(AUDIO_SDL2_MIXER_LUA) PREFIX=$(PREFIX)
	make -C src/$(KEYBOARD_SDL2) PREFIX=$(PREFIX)
	make -C src/$(KEYBOARD_SDL2_LUA) PREFIX=$(PREFIX)
	make -C src/$(MOUSE_SDL2) PREFIX=$(PREFIX)
	make -C src/$(MOUSE_SDL2_LUA) PREFIX=$(PREFIX)
	make -C src/$(GAME_CONTROLLER_SDL2) PREFIX=$(PREFIX)
	make -C src/$(GAME_CONTROLLER_SDL2_LUA) PREFIX=$(PREFIX)
	make -C src/$(TIMER_SDL2) PREFIX=$(PREFIX)
	make -C src/$(TIMER_SDL2_LUA) PREFIX=$(PREFIX)
	make -C src/$(UTILS_COLOR) PREFIX=$(PREFIX)
	make -C src/$(UTILS_COLOR_LUA) PREFIX=$(PREFIX)
	make -C src/$(SCRIPT_LUA) PREFIX=$(PREFIX)
	make -C src/engine PREFIX=$(PREFIX)

html5: prebuild
	make -C src/$(SCREEN_SDL2) PREFIX=$(PREFIX)
	make -C src/$(SCREEN_SDL2_LUA) PREFIX=$(PREFIX)
	make -C src/$(TEXTURE_SDL2_IMAGE) PREFIX=$(PREFIX)
	make -C src/$(TEXTURE_SDL2_IMAGE_LUA) PREFIX=$(PREFIX)
	make -C src/$(PRIMITIVE_SDL2) PREFIX=$(PREFIX)
	make -C src/$(PRIMITIVE_SDL2_LUA) PREFIX=$(PREFIX)
	make -C src/$(TTF_SDL2_TTF) PREFIX=$(PREFIX)
	make -C src/$(TTF_SDL2_TTF_LUA) PREFIX=$(PREFIX)
	make -C src/$(KEYBOARD_SDL2) PREFIX=$(PREFIX)
	make -C src/$(KEYBOARD_SDL2_LUA) PREFIX=$(PREFIX)
	make -C src/$(MOUSE_SDL2) PREFIX=$(PREFIX)
	make -C src/$(MOUSE_SDL2_LUA) PREFIX=$(PREFIX)
	make -C src/$(GAME_CONTROLLER_SDL2) PREFIX=$(PREFIX)
	make -C src/$(GAME_CONTROLLER_SDL2_LUA) PREFIX=$(PREFIX)
	make -C src/$(TIMER_SDL2) PREFIX=$(PREFIX)
	make -C src/$(TIMER_SDL2_LUA) PREFIX=$(PREFIX)
	make -C src/$(UTILS_COLOR) PREFIX=$(PREFIX)
	make -C src/$(UTILS_COLOR_LUA) PREFIX=$(PREFIX)
	make -C src/$(SCRIPT_LUA) PREFIX=$(PREFIX)
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
