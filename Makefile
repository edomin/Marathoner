include makefiles/Build.mk

OBJSDIR = $(PLATFORM)/obj
LIBDIR = $(PLATFORM)/lib
BINDIR = $(PLATFORM)/plugin
FADIR = $(PLATFORM)/fa
ifeq ($(PLATFORM), win32)
  RCDIR = $(PLATFORM)/rc
endif
ifeq ($(PLATFORM), win64)
  RCDIR = $(PLATFORM)/rc
endif

SCREEN_SDL2 = screen/sdl2
SCREEN_SDL2_LUA = screen/sdl2_lua
SCREEN_SDL2_SQUIRREL = screen/sdl2_squirrel
SCREEN_SDL2_DUKTAPE = screen/sdl2_duktape
SCREEN_SDL2_GPU = screen/sdl2_gpu
SCREEN_SDL2_GPU_LUA = screen/sdl2_gpu_lua
SCREEN_SDL2_GPU_SQUIRREL = screen/sdl2_gpu_squirrel
SCREEN_SDL2_GPU_DUKTAPE = screen/sdl2_gpu_duktape
TEXTURE_SDL2_IMAGE = texture/sdl2_image
TEXTURE_SDL2_IMAGE_LUA = texture/sdl2_image_lua
TEXTURE_SDL2_IMAGE_SQUIRREL = texture/sdl2_image_squirrel
TEXTURE_SDL2_IMAGE_DUKTAPE = texture/sdl2_image_duktape
TEXTURE_SDL2_GPU = texture/sdl2_gpu
TEXTURE_SDL2_GPU_LUA = texture/sdl2_gpu_lua
TEXTURE_SDL2_GPU_SQUIRREL = texture/sdl2_gpu_squirrel
TEXTURE_SDL2_GPU_DUKTAPE = texture/sdl2_gpu_duktape
PRIMITIVE_SDL2 = primitive/sdl2
PRIMITIVE_SDL2_LUA = primitive/sdl2_lua
PRIMITIVE_SDL2_SQUIRREL = primitive/sdl2_squirrel
PRIMITIVE_SDL2_DUKTAPE = primitive/sdl2_duktape
PRIMITIVE_SDL2_GPU = primitive/sdl2_gpu
PRIMITIVE_SDL2_GPU_LUA = primitive/sdl2_gpu_lua
PRIMITIVE_SDL2_GPU_SQUIRREL = primitive/sdl2_gpu_squirrel
PRIMITIVE_SDL2_GPU_DUKTAPE = primitive/sdl2_gpu_duktape
PRIMITIVE_SDL2_GFX = primitive/sdl2_gfx
PRIMITIVE_SDL2_GFX_LUA = primitive/sdl2_gfx_lua
PRIMITIVE_SDL2_GFX_SQUIRREL = primitive/sdl2_gfx_squirrel
PRIMITIVE_SDL2_GFX_DUKTAPE = primitive/sdl2_gfx_duktape
PNG_LIBPNG = png/libpng
PNG_LIBPNG_LUA = png/libpng_lua
PNG_LIBPNG_SQUIRREL = png/libpng_squirrel
PNG_LIBPNG_DUKTAPE = png/libpng_duktape
TTF_SDL2_TTF = ttf/sdl2_ttf
TTF_SDL2_TTF_LUA = ttf/sdl2_ttf_lua
TTF_SDL2_TTF_SQUIRREL = ttf/sdl2_ttf_squirrel
TTF_SDL2_TTF_DUKTAPE = ttf/sdl2_ttf_duktape
TTF_FREETYPE2 = ttf/freetype2
TTF_FREETYPE2_LUA = ttf/freetype2_lua
TTF_FREETYPE2_SQUIRREL = ttf/freetype2_squirrel
TTF_FREETYPE2_DUKTAPE = ttf/freetype2_duktape
AUDIO_SDL2_MIXER = audio/sdl2_mixer
AUDIO_SDL2_MIXER_LUA = audio/sdl2_mixer_lua
AUDIO_SDL2_MIXER_SQUIRREL = audio/sdl2_mixer_squirrel
AUDIO_SDL2_MIXER_DUKTAPE = audio/sdl2_mixer_duktape
KEYBOARD_SDL2 = keyboard/sdl2
KEYBOARD_SDL2_LUA = keyboard/sdl2_lua
KEYBOARD_SDL2_SQUIRREL = keyboard/sdl2_squirrel
KEYBOARD_SDL2_DUKTAPE = keyboard/sdl2_duktape
MOUSE_SDL2 = mouse/sdl2
MOUSE_SDL2_LUA = mouse/sdl2_lua
MOUSE_SDL2_SQUIRREL = mouse/sdl2_squirrel
MOUSE_SDL2_DUKTAPE = mouse/sdl2_duktape
GAME_CONTROLLER_SDL2 = game_controller/sdl2
GAME_CONTROLLER_SDL2_LUA = game_controller/sdl2_lua
GAME_CONTROLLER_SDL2_SQUIRREL = game_controller/sdl2_squirrel
GAME_CONTROLLER_SDL2_DUKTAPE = game_controller/sdl2_duktape
TIMER_SDL2 = timer/sdl2
TIMER_SDL2_LUA = timer/sdl2_lua
TIMER_SDL2_SQUIRREL = timer/sdl2_squirrel
TIMER_SDL2_DUKTAPE = timer/sdl2_duktape
TIMER_EMSCRIPTEN = timer/emscripten
TIMER_EMSCRIPTEN_LUA = timer/emscripten_lua
TIMER_EMSCRIPTEN_SQUIRREL = timer/emscripten_squirrel
TIMER_EMSCRIPTEN_DUKTAPE = timer/emscripten_duktape
JSON_CJSON = json/cjson
JSON_CJSON_LUA = json/cjson_lua
JSON_CJSON_SQUIRREL = json/cjson_squirrel
JSON_CJSON_DUKTAPE = json/cjson_duktape
UTILS_COLOR = utils/color
UTILS_COLOR_LUA = utils/color_lua
UTILS_COLOR_SQUIRREL = utils/color_squirrel
UTILS_COLOR_DUKTAPE = utils/color_duktape
UTILS_MATH = utils/math
UTILS_MATH_LUA = utils/math_lua
UTILS_MATH_SQUIRREL = utils/math_squirrel
UTILS_MATH_DUKTAPE = utils/math_duktape
SCRIPT_LUA = script/lua
SCRIPT_SQUIRREL = script/squirrel
SCRIPT_DUKTAPE = script/duktape
ABSTRACTION_SPRITE = abstraction/sprite
ABSTRACTION_SPRITE_LUA = abstraction/sprite_lua
ABSTRACTION_SPRITE_SQUIRREL = abstraction/sprite_squirrel
ABSTRACTION_SPRITE_DUKTAPE = abstraction/sprite_duktape
ABSTRACTION_ANIMATED_SPRITE = abstraction/animated_sprite
ABSTRACTION_ANIMATED_SPRITE_LUA = abstraction/animated_sprite_lua
ABSTRACTION_ANIMATED_SPRITE_SQUIRREL = abstraction/animated_sprite_squirrel
ABSTRACTION_ANIMATED_SPRITE_DUKTAPE = abstraction/animated_sprite_duktape
ABSTRACTION_FONT = abstraction/font
ABSTRACTION_FONT_LUA = abstraction/font_lua
ABSTRACTION_FONT_SQUIRREL = abstraction/font_squirrel
ABSTRACTION_FONT_DUKTAPE = abstraction/font_duktape
ABSTRACTION_GUI = abstraction/gui
ABSTRACTION_GUI_LUA = abstraction/gui_lua
ABSTRACTION_GUI_SQUIRREL = abstraction/gui_squirrel
ABSTRACTION_GUI_DUKTAPE = abstraction/gui_duktape
ABSTRACTION_SCENE = abstraction/scene
ABSTRACTION_SCENE_LUA = abstraction/scene_lua
ABSTRACTION_SCENE_SQUIRREL = abstraction/scene_squirrel
ABSTRACTION_SCENE_DUKTAPE = abstraction/scene_duktape

ifeq ($(MOD), plugin)
all: $(PLATFORM)
endif
ifeq ($(MOD), static)
include makefiles/Monolythic.mk
endif

fagen:
	make -j$(CORES) -C src/_build_utils/fagen HOST_BUILD=yes

plugins: prebuild
ifeq ($(MOD), plugin)
	make -j$(CORES) -C src/$(SCREEN_SDL2_GPU) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(SCREEN_SDL2_GPU_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(SCREEN_SDL2_GPU_SQUIRREL) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(SCREEN_SDL2_GPU_DUKTAPE) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(SCREEN_SDL2) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(SCREEN_SDL2_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(SCREEN_SDL2_SQUIRREL) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(SCREEN_SDL2_DUKTAPE) PREFIX=$(PREFIX)

	make -j$(CORES) -C src/$(TEXTURE_SDL2_GPU) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(TEXTURE_SDL2_GPU_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(TEXTURE_SDL2_GPU_SQUIRREL) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(TEXTURE_SDL2_GPU_DUKTAPE) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(TEXTURE_SDL2_IMAGE) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(TEXTURE_SDL2_IMAGE_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(TEXTURE_SDL2_IMAGE_SQUIRREL) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(TEXTURE_SDL2_IMAGE_DUKTAPE) PREFIX=$(PREFIX)

	make -j$(CORES) -C src/$(PRIMITIVE_SDL2_GPU) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(PRIMITIVE_SDL2_GPU_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(PRIMITIVE_SDL2_GPU_SQUIRREL) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(PRIMITIVE_SDL2_GPU_DUKTAPE) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(PRIMITIVE_SDL2) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(PRIMITIVE_SDL2_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(PRIMITIVE_SDL2_SQUIRREL) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(PRIMITIVE_SDL2_DUKTAPE) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(PRIMITIVE_SDL2_GFX) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(PRIMITIVE_SDL2_GFX_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(PRIMITIVE_SDL2_GFX_SQUIRREL) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(PRIMITIVE_SDL2_GFX_DUKTAPE) PREFIX=$(PREFIX)

	make -j$(CORES) -C src/$(PNG_LIBPNG) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(PNG_LIBPNG_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(PNG_LIBPNG_SQUIRREL) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(PNG_LIBPNG_DUKTAPE) PREFIX=$(PREFIX)

	make -j$(CORES) -C src/$(TTF_SDL2_TTF) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(TTF_SDL2_TTF_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(TTF_SDL2_TTF_SQUIRREL) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(TTF_SDL2_TTF_DUKTAPE) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(TTF_FREETYPE2) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(TTF_FREETYPE2_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(TTF_FREETYPE2_SQUIRREL) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(TTF_FREETYPE2_DUKTAPE) PREFIX=$(PREFIX)

	make -j$(CORES) -C src/$(AUDIO_SDL2_MIXER) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(AUDIO_SDL2_MIXER_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(AUDIO_SDL2_MIXER_SQUIRREL) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(AUDIO_SDL2_MIXER_DUKTAPE) PREFIX=$(PREFIX)

	make -j$(CORES) -C src/$(KEYBOARD_SDL2) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(KEYBOARD_SDL2_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(KEYBOARD_SDL2_SQUIRREL) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(KEYBOARD_SDL2_DUKTAPE) PREFIX=$(PREFIX)

	make -j$(CORES) -C src/$(MOUSE_SDL2) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(MOUSE_SDL2_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(MOUSE_SDL2_SQUIRREL) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(MOUSE_SDL2_DUKTAPE) PREFIX=$(PREFIX)

	make -j$(CORES) -C src/$(GAME_CONTROLLER_SDL2) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(GAME_CONTROLLER_SDL2_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(GAME_CONTROLLER_SDL2_SQUIRREL) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(GAME_CONTROLLER_SDL2_DUKTAPE) PREFIX=$(PREFIX)

	make -j$(CORES) -C src/$(TIMER_SDL2) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(TIMER_SDL2_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(TIMER_SDL2_SQUIRREL) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(TIMER_SDL2_DUKTAPE) PREFIX=$(PREFIX)

	make -j$(CORES) -C src/$(JSON_CJSON) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(JSON_CJSON_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(JSON_CJSON_SQUIRREL) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(JSON_CJSON_DUKTAPE) PREFIX=$(PREFIX)

	make -j$(CORES) -C src/$(UTILS_COLOR) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(UTILS_COLOR_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(UTILS_COLOR_SQUIRREL) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(UTILS_COLOR_DUKTAPE) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(UTILS_MATH) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(UTILS_MATH_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(UTILS_MATH_SQUIRREL) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(UTILS_MATH_DUKTAPE) PREFIX=$(PREFIX)

	make -j$(CORES) -C src/$(SCRIPT_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(SCRIPT_SQUIRREL) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(SCRIPT_DUKTAPE) PREFIX=$(PREFIX)

	make -j$(CORES) -C src/$(ABSTRACTION_SPRITE) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(ABSTRACTION_SPRITE_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(ABSTRACTION_SPRITE_SQUIRREL) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(ABSTRACTION_SPRITE_DUKTAPE) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(ABSTRACTION_ANIMATED_SPRITE) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(ABSTRACTION_ANIMATED_SPRITE_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(ABSTRACTION_ANIMATED_SPRITE_SQUIRREL) \
	 PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(ABSTRACTION_ANIMATED_SPRITE_DUKTAPE) \
	 PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(ABSTRACTION_FONT) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(ABSTRACTION_FONT_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(ABSTRACTION_FONT_SQUIRREL) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(ABSTRACTION_FONT_DUKTAPE) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(ABSTRACTION_GUI) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(ABSTRACTION_GUI_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(ABSTRACTION_GUI_SQUIRREL) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(ABSTRACTION_GUI_DUKTAPE) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(ABSTRACTION_SCENE) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(ABSTRACTION_SCENE_LUA) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(ABSTRACTION_SCENE_SQUIRREL) PREFIX=$(PREFIX)
	make -j$(CORES) -C src/$(ABSTRACTION_SCENE_DUKTAPE) PREFIX=$(PREFIX)
endif

engine:
ifeq ($(MOD), plugin)
	make -j$(CORES) -C src/core PREFIX=$(PREFIX)
endif

windows_common: prebuild
	make -j$(CORES) -C src/_build_utils/rcgen PREFIX=$(PREFIX)

win32: prebuild windows_common fagen plugins engine

win64: prebuild windows_common fagen plugins engine

html5: prebuild fagen

prebuild:
	-mkdir $(PLATFORM)
	-mkdir $(OBJSDIR)
	-mkdir $(LIBDIR)
	-mkdir $(FADIR)
ifeq ($(PLATFORM), win32)
	-mkdir $(BINDIR)
	-mkdir $(RCDIR)
endif
ifeq ($(PLATFORM), win64)
	-mkdir $(BINDIR)
	-mkdir $(RCDIR)
endif
ifeq ($(MOD), static)
	-mkdir $(PLATFORM)/binding_init_func
	-mkdir $(PLATFORM)/binding_init_func_call
endif

clean:
	-rm -f -r $(OBJSDIR)
	-rm -f -r $(LIBDIR)
	-rm -f -r $(FADIR)
	-rm -f -r $(HOST)/fagen.exe
	-rm -f -r $(HOST)/obj/fagen.o
	-rm -f -r $(PLATFORM)/marathoner.exe
ifeq ($(PLATFORM), win32)
	-rm -f -r $(BINDIR)
	-rm -f -r $(RCDIR)
	-rm -f -r $(PLATFORM)/rcgen.exe
	-rm -f -r $(PLATFORM)/Launcher.exe
endif
ifeq ($(PLATFORM), win64)
	-rm -f -r $(BINDIR)
	-rm -f -r $(RCDIR)
	-rm -f -r $(PLATFORM)/rcgen.exe
	-rm -f -r $(PLATFORM)/Launcher.exe
endif
ifeq ($(PLATFORM), html5)
	-rm -f -r $(PLATFORM)/marathoner.html
	-rm -f -r $(PLATFORM)/marathoner.js
endif
ifeq ($(MOD), static)
	-rm -f -r $(PLATFORM)/binding_init_func
	-rm -f -r $(PLATFORM)/binding_init_func_call
	-rm -f $(PLATFORM)/obj/objs.txt
endif

remake: clean all

.PHONY: prebuild common windows_common remake clean all win32 win64
