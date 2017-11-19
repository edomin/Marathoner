MODULES = src/$(SCREEN_SDL2) \
 src/$(SCREEN_SDL2_LUA) \
 src/$(TEXTURE_SDL2_IMAGE) \
 src/$(TEXTURE_SDL2_IMAGE_LUA) \
 src/$(PRIMITIVE_SDL2) \
 src/$(PRIMITIVE_SDL2_LUA) \
 src/$(PNG_LIBPNG) \
 src/$(PNG_LIBPNG_LUA) \
 src/$(TTF_SDL2_TTF) \
 src/$(TTF_SDL2_TTF_LUA) \
 src/$(AUDIO_SDL2_MIXER) \
 src/$(AUDIO_SDL2_MIXER_LUA) \
 src/$(KEYBOARD_SDL2) \
 src/$(KEYBOARD_SDL2_LUA) \
 src/$(MOUSE_SDL2) \
 src/$(MOUSE_SDL2_LUA) \
 src/$(GAME_CONTROLLER_SDL2) \
 src/$(GAME_CONTROLLER_SDL2_LUA) \
 src/$(TIMER_SDL2) \
 src/$(TIMER_SDL2_LUA) \
 src/$(JSON_CJSON) \
 src/$(JSON_CJSON_LUA) \
 src/$(UTILS_COLOR) \
 src/$(UTILS_COLOR_LUA) \
 src/$(UTILS_MATH) \
 src/$(UTILS_MATH_LUA) \
 src/$(ABSTRACTION_SPRITE) \
 src/$(ABSTRACTION_SPRITE_LUA) \
 src/$(ABSTRACTION_FONT) \
 src/$(ABSTRACTION_FONT_LUA) \
 src/$(ABSTRACTION_GUI) \
 src/$(ABSTRACTION_GUI_LUA) \
 src/$(SCRIPT_LUA)

all: $(PLATFORM) $(BIF) $(MODULES) engine_monolythic

src/%: FORCE
	make -j$(CORES) -C $@ PREFIX=$(PREFIX)

engine_monolythic:
	make -j$(CORES) -C src/core PREFIX=$(PREFIX)

FORCE:
