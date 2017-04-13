include Build.mk

OBJSDIR = obj
LIBDIR = lib
BINDIR = plugin
RCDIR = rc

SCREEN_SDL2 = screen/sdl2
SCREEN_SDL2_LUA = screen/sdl2_lua
SCREEN_SDL2_SQUIRREL = screen/sdl2_squirrel
SCREEN_SDL2_GPU = screen/sdl2_gpu
SCREEN_SDL2_GPU_LUA = screen/sdl2_gpu_lua
SCREEN_SDL2_GPU_SQUIRREL = screen/sdl2_gpu_squirrel
TEXTURE_SDL2_IMAGE = texture/sdl2_image
TEXTURE_SDL2_IMAGE_LUA = texture/sdl2_image_lua
TEXTURE_SDL2_IMAGE_SQUIRREL = texture/sdl2_image_squirrel
TEXTURE_SDL2_GPU = texture/sdl2_gpu
TEXTURE_SDL2_GPU_LUA = texture/sdl2_gpu_lua
TEXTURE_SDL2_GPU_SQUIRREL = texture/sdl2_gpu_squirrel
PRIMITIVE_SDL2 = primitive/sdl2
PRIMITIVE_SDL2_LUA = primitive/sdl2_lua
PRIMITIVE_SDL2_SQUIRREL = primitive/sdl2_squirrel
PRIMITIVE_SDL2_GPU = primitive/sdl2_gpu
PRIMITIVE_SDL2_GPU_LUA = primitive/sdl2_gpu_lua
PRIMITIVE_SDL2_GPU_SQUIRREL = primitive/sdl2_gpu_squirrel
PRIMITIVE_SDL2_GFX = primitive/sdl2_gfx
PRIMITIVE_SDL2_GFX_LUA = primitive/sdl2_gfx_lua
PRIMITIVE_SDL2_GFX_SQUIRREL = primitive/sdl2_gfx_squirrel
TTF_SDL2_TTF = ttf/sdl2_ttf
TTF_SDL2_TTF_LUA = ttf/sdl2_ttf_lua
TTF_SDL2_TTF_SQUIRREL = ttf/sdl2_ttf_squirrel
AUDIO_SDL2_MIXER = audio/sdl2_mixer
AUDIO_SDL2_MIXER_LUA = audio/sdl2_mixer_lua
AUDIO_SDL2_MIXER_SQUIRREL = audio/sdl2_mixer_squirrel
KEYBOARD_SDL2 = keyboard/sdl2
KEYBOARD_SDL2_LUA = keyboard/sdl2_lua
KEYBOARD_SDL2_SQUIRREL = keyboard/sdl2_squirrel
MOUSE_SDL2 = mouse/sdl2
MOUSE_SDL2_LUA = mouse/sdl2_lua
MOUSE_SDL2_SQUIRREL = mouse/sdl2_squirrel
GAME_CONTROLLER_SDL2 = game_controller/sdl2
GAME_CONTROLLER_SDL2_LUA = game_controller/sdl2_lua
GAME_CONTROLLER_SDL2_SQUIRREL = game_controller/sdl2_squirrel
TIMER_SDL2 = timer/sdl2
TIMER_SDL2_LUA = timer/sdl2_lua
TIMER_SDL2_SQUIRREL = timer/sdl2_squirrel
UTILS_COLOR = utils/color
UTILS_COLOR_LUA = utils/color_lua
UTILS_COLOR_SQUIRREL = utils/color_squirrel
SCRIPT_LUA = script/lua
SCRIPT_SQUIRREL = script/squirrel
ABSTRACTION_SPRITE = abstraction/sprite
ABSTRACTION_SPRITE_LUA = abstraction/sprite_lua
ABSTRACTION_SPRITE_SQUIRREL = abstraction/sprite_squirrel
ABSTRACTION_FONT = abstraction/font
ABSTRACTION_FONT_LUA = abstraction/font_lua
ABSTRACTION_FONT_SQUIRREL = abstraction/font_squirrel
ABSTRACTION_GUI = abstraction/gui
ABSTRACTION_GUI_LUA = abstraction/gui_lua
ABSTRACTION_GUI_SQUIRREL = abstraction/gui_squirrel

all: $(PLATFORM)

win32: prebuild
	make -C src/platform_specific/windows PREFIX=$(PREFIX)

	make -C src/$(SCREEN_SDL2_GPU) PREFIX=$(PREFIX)
	make -C src/$(SCREEN_SDL2_GPU_LUA) PREFIX=$(PREFIX)
	make -C src/$(SCREEN_SDL2_GPU_SQUIRREL) PREFIX=$(PREFIX)
	make -C src/$(TEXTURE_SDL2_GPU) PREFIX=$(PREFIX)
	make -C src/$(TEXTURE_SDL2_GPU_LUA) PREFIX=$(PREFIX)
	make -C src/$(TEXTURE_SDL2_GPU_SQUIRREL) PREFIX=$(PREFIX)
	make -C src/$(PRIMITIVE_SDL2_GPU) PREFIX=$(PREFIX)
	make -C src/$(PRIMITIVE_SDL2_GPU_LUA) PREFIX=$(PREFIX)
	make -C src/$(PRIMITIVE_SDL2_GPU_SQUIRREL) PREFIX=$(PREFIX)

	make -C src/$(SCREEN_SDL2) PREFIX=$(PREFIX)
	make -C src/$(SCREEN_SDL2_LUA) PREFIX=$(PREFIX)
	make -C src/$(SCREEN_SDL2_SQUIRREL) PREFIX=$(PREFIX)
	make -C src/$(TEXTURE_SDL2_IMAGE) PREFIX=$(PREFIX)
	make -C src/$(TEXTURE_SDL2_IMAGE_LUA) PREFIX=$(PREFIX)
	make -C src/$(TEXTURE_SDL2_IMAGE_SQUIRREL) PREFIX=$(PREFIX)
	make -C src/$(PRIMITIVE_SDL2) PREFIX=$(PREFIX)
	make -C src/$(PRIMITIVE_SDL2_LUA) PREFIX=$(PREFIX)
	make -C src/$(PRIMITIVE_SDL2_SQUIRREL) PREFIX=$(PREFIX)
	make -C src/$(PRIMITIVE_SDL2_GFX) PREFIX=$(PREFIX)
	make -C src/$(PRIMITIVE_SDL2_GFX_LUA) PREFIX=$(PREFIX)
	make -C src/$(PRIMITIVE_SDL2_GFX_SQUIRREL) PREFIX=$(PREFIX)

	make -C src/$(TTF_SDL2_TTF) PREFIX=$(PREFIX)
	make -C src/$(TTF_SDL2_TTF_LUA) PREFIX=$(PREFIX)
	make -C src/$(TTF_SDL2_TTF_SQUIRREL) PREFIX=$(PREFIX)
	make -C src/$(AUDIO_SDL2_MIXER) PREFIX=$(PREFIX)
	make -C src/$(AUDIO_SDL2_MIXER_LUA) PREFIX=$(PREFIX)
	make -C src/$(AUDIO_SDL2_MIXER_SQUIRREL) PREFIX=$(PREFIX)
	make -C src/$(KEYBOARD_SDL2) PREFIX=$(PREFIX)
	make -C src/$(KEYBOARD_SDL2_LUA) PREFIX=$(PREFIX)
	make -C src/$(KEYBOARD_SDL2_SQUIRREL) PREFIX=$(PREFIX)
	make -C src/$(MOUSE_SDL2) PREFIX=$(PREFIX)
	make -C src/$(MOUSE_SDL2_LUA) PREFIX=$(PREFIX)
	make -C src/$(MOUSE_SDL2_SQUIRREL) PREFIX=$(PREFIX)
	make -C src/$(GAME_CONTROLLER_SDL2) PREFIX=$(PREFIX)
	make -C src/$(GAME_CONTROLLER_SDL2_LUA) PREFIX=$(PREFIX)
	make -C src/$(GAME_CONTROLLER_SDL2_SQUIRREL) PREFIX=$(PREFIX)
	make -C src/$(TIMER_SDL2) PREFIX=$(PREFIX)
	make -C src/$(TIMER_SDL2_LUA) PREFIX=$(PREFIX)
	make -C src/$(TIMER_SDL2_SQUIRREL) PREFIX=$(PREFIX)
	make -C src/$(UTILS_COLOR) PREFIX=$(PREFIX)
	make -C src/$(UTILS_COLOR_LUA) PREFIX=$(PREFIX)
	make -C src/$(UTILS_COLOR_SQUIRREL) PREFIX=$(PREFIX)
	make -C src/$(SCRIPT_LUA) PREFIX=$(PREFIX)
	make -C src/$(SCRIPT_SQUIRREL) PREFIX=$(PREFIX)
	make -C src/$(ABSTRACTION_SPRITE) PREFIX=$(PREFIX)
	make -C src/$(ABSTRACTION_SPRITE_LUA) PREFIX=$(PREFIX)
	make -C src/$(ABSTRACTION_SPRITE_SQUIRREL) PREFIX=$(PREFIX)
	make -C src/$(ABSTRACTION_FONT) PREFIX=$(PREFIX)
	make -C src/$(ABSTRACTION_FONT_LUA) PREFIX=$(PREFIX)
	make -C src/$(ABSTRACTION_FONT_SQUIRREL) PREFIX=$(PREFIX)
	make -C src/$(ABSTRACTION_GUI) PREFIX=$(PREFIX)
	make -C src/$(ABSTRACTION_GUI_LUA) PREFIX=$(PREFIX)
	make -C src/$(ABSTRACTION_GUI_SQUIRREL) PREFIX=$(PREFIX)
	make -C src/core PREFIX=$(PREFIX)

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
	make -C src/core PREFIX=$(PREFIX)

prebuild:
	-mkdir $(OBJSDIR)
	-mkdir $(LIBDIR)
	-mkdir $(BINDIR)
ifeq ($(PLATFORM), win32)
	-mkdir $(RCDIR)
endif

clean:
	-rm -f -r $(OBJSDIR)
	-rm -f -r $(LIBDIR)
	-rm -f -r $(BINDIR)
	-rm -f -r $(RCDIR)
	-rm -f -r marathoner.exe
	-rm -f -r marathoner.html
	-rm -f -r marathoner.js
ifeq ($(PLATFORM), win32)
	-rm -f -r rcgen.exe
endif

remake: clean all

.PHONY: prebuild remake clean all
