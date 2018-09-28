#ifndef MTR_VERSION_H
#define MTR_VERSION_H

#define MTR_VERSION_MARATHONER                           0x000400U /* inc minor */

#define MTR_VERSION_LAUNCHER                             0x000100U /* inc minor */

#define MTR_VERSION_SCREEN_SDL2                          0x000400U /* inc minor */
#define MTR_VERSION_SCREEN_SDL2_LUA                      0x000300U /* inc minor */
#define MTR_VERSION_SCREEN_SDL2_SQUIRREL                 0x000200U /* inc minor */
#define MTR_VERSION_SCREEN_SDL2_DUKTAPE                  0x000200U /* inc minor */
#define MTR_VERSION_SCREEN_SDL2_GPU                      0x000400U /* inc minor */
#define MTR_VERSION_SCREEN_SDL2_GPU_LUA                  0x000300U /* inc minor */
#define MTR_VERSION_SCREEN_SDL2_GPU_SQUIRREL             0x000200U /* inc minor */
#define MTR_VERSION_SCREEN_SDL2_GPU_DUKTAPE              0x000200U /* inc minor */

#define MTR_VERSION_TEXTURE_SDL2_IMAGE                   0x000400U /* inc minor */
#define MTR_VERSION_TEXTURE_SDL2_IMAGE_LUA               0x000300U /* inc minor */
#define MTR_VERSION_TEXTURE_SDL2_IMAGE_SQUIRREL          0x000200U /* inc minor */
#define MTR_VERSION_TEXTURE_SDL2_IMAGE_DUKTAPE           0x000200U /* inc minor */
#define MTR_VERSION_TEXTURE_SDL2_GPU                     0x000400U /* inc minor */
#define MTR_VERSION_TEXTURE_SDL2_GPU_LUA                 0x000300U /* inc minor */
#define MTR_VERSION_TEXTURE_SDL2_GPU_SQUIRREL            0x000200U /* inc minor */
#define MTR_VERSION_TEXTURE_SDL2_GPU_DUKTAPE             0x000200U /* inc minor */

#define MTR_VERSION_PRIMITIVE_SDL2                       0x000300U /* not incremented */
#define MTR_VERSION_PRIMITIVE_SDL2_LUA                   0x000200U /* not incremented */
#define MTR_VERSION_PRIMITIVE_SDL2_SQUIRREL              0x000100U /* not incremented */
#define MTR_VERSION_PRIMITIVE_SDL2_DUKTAPE               0x000100U /* not incremented */
#define MTR_VERSION_PRIMITIVE_SDL2_GFX                   0x000100U /* not incremented */
#define MTR_VERSION_PRIMITIVE_SDL2_GFX_LUA               0x000100U /* not incremented */
#define MTR_VERSION_PRIMITIVE_SDL2_GFX_SQUIRREL          0x000100U /* not incremented */
#define MTR_VERSION_PRIMITIVE_SDL2_GFX_DUKTAPE           0x000100U /* not incremented */
#define MTR_VERSION_PRIMITIVE_SDL2_GPU                   0x000200U /* not incremented */
#define MTR_VERSION_PRIMITIVE_SDL2_GPU_LUA               0x000200U /* not incremented */
#define MTR_VERSION_PRIMITIVE_SDL2_GPU_SQUIRREL          0x000100U /* not incremented */
#define MTR_VERSION_PRIMITIVE_SDL2_GPU_DUKTAPE           0x000100U /* not incremented */

#define MTR_VERSION_AUDIO_SDL2_MIXER                     0x000301U /* inc patch */
#define MTR_VERSION_AUDIO_SDL2_MIXER_LUA                 0x000201U /* not incremented */
#define MTR_VERSION_AUDIO_SDL2_MIXER_SQUIRREL            0x000101U /* not incremented */
#define MTR_VERSION_AUDIO_SDL2_MIXER_DUKTAPE             0x000101U /* not incremented */
#define MTR_VERSION_AUDIO_PORTAUDIO                      0x000000U /* initial */
#define MTR_VERSION_AUDIO_PORTAUDIO_LUA                  0x000000U /* initial */
#define MTR_VERSION_AUDIO_PORTAUDIO_SQUIRREL             0x000000U /* initial */
#define MTR_VERSION_AUDIO_PORTAUDIO_DUKTAPE              0x000000U /* initial */

#define MTR_VERSION_KEYBOARD_SDL2                        0x000300U /* not incremented */
#define MTR_VERSION_KEYBOARD_SDL2_LUA                    0x000201U /* not incremented */
#define MTR_VERSION_KEYBOARD_SDL2_SQUIRREL               0x000101U /* not incremented */
#define MTR_VERSION_KEYBOARD_SDL2_DUKTAPE                0x000101U /* not incremented */

#define MTR_VERSION_MOUSE_SDL2                           0x000300U /* not incremented */
#define MTR_VERSION_MOUSE_SDL2_LUA                       0x000201U /* not incremented */
#define MTR_VERSION_MOUSE_SDL2_SQUIRREL                  0x000101U /* not incremented */
#define MTR_VERSION_MOUSE_SDL2_DUKTAPE                   0x000101U /* not incremented */

#define MTR_VERSION_GAME_CONTROLLER_SDL2                 0x000301U /* not incremented */
#define MTR_VERSION_GAME_CONTROLLER_SDL2_LUA             0x000200U /* not incremented */
#define MTR_VERSION_GAME_CONTROLLER_SDL2_SQUIRREL        0x000100U /* not incremented */
#define MTR_VERSION_GAME_CONTROLLER_SDL2_DUKTAPE         0x000100U /* not incremented */

#define MTR_VERSION_JSON_CJSON                           0x000100U /* not incremented */
#define MTR_VERSION_JSON_CJSON_LUA                       0x000100U /* not incremented */
#define MTR_VERSION_JSON_CJSON_SQUIRREL                  0x000100U /* not incremented */
#define MTR_VERSION_JSON_CJSON_DUKTAPE                   0x000100U /* not incremented */

#define MTR_VERSION_PNG_LIBPNG                           0x000001U /* inc patch */
#define MTR_VERSION_PNG_LIBPNG_LUA                       0x000000U /* not incremented */
#define MTR_VERSION_PNG_LIBPNG_SQUIRREL                  0x000000U /* not incremented */
#define MTR_VERSION_PNG_LIBPNG_DUKTAPE                   0x000001U /* inc patch */

#define MTR_VERSION_SCRIPT_LUA                           0x000300U /* not incremented */
#define MTR_VERSION_SCRIPT_SQUIRREL                      0x000200U /* not incremented */
#define MTR_VERSION_SCRIPT_DUKTAPE                       0x000100U /* not incremented */

#define MTR_VERSION_TIMER_SDL2                           0x000200U /* not incremented */
#define MTR_VERSION_TIMER_SDL2_LUA                       0x000200U /* not incremented */
#define MTR_VERSION_TIMER_SDL2_SQUIRREL                  0x000100U /* not incremented */
#define MTR_VERSION_TIMER_SDL2_DUKTAPE                   0x000100U /* not incremented */
#define MTR_VERSION_TIMER_EMSCRIPTEN                     0x000000U /* not incremented */
#define MTR_VERSION_TIMER_EMSCRIPTEN_LUA                 0x000000U /* not incremented */
#define MTR_VERSION_TIMER_EMSCRIPTEN_SQUIRREL            0x000000U /* not incremented */
#define MTR_VERSION_TIMER_EMSCRIPTEN_DUKTAPE             0x000000U /* not incremented */

#define MTR_VERSION_TTF_SDL2_TTF                         0x000300U /* inc minor */
#define MTR_VERSION_TTF_SDL2_TTF_LUA                     0x000300U /* inc minor */
#define MTR_VERSION_TTF_SDL2_TTF_SQUIRREL                0x000200U /* inc minor */
#define MTR_VERSION_TTF_SDL2_TTF_DUKTAPE                 0x000200U /* inc minor */
#define MTR_VERSION_TTF_FREETYPE2                        0x000100U /* inc minor */
#define MTR_VERSION_TTF_FREETYPE2_LUA                    0x000100U /* inc minor */
#define MTR_VERSION_TTF_FREETYPE2_SQUIRREL               0x000100U /* inc minor */
#define MTR_VERSION_TTF_FREETYPE2_DUKTAPE                0x000100U /* inc minor */

#define MTR_VERSION_OGG_LIBVORBISFILE                    0x000001U /* inc minor */

#define MTR_VERSION_WAV_DR_WAV                           0x000001U /* inc minor */

#define MTR_VERSION_PACKAGE_PHYSFS                       0x000000U /* initial */
#define MTR_VERSION_PACKAGE_PHYSFS_LUA                   0x000000U /* initial */
#define MTR_VERSION_PACKAGE_PHYSFS_SQUIRREL              0x000000U /* initial */
#define MTR_VERSION_PACKAGE_PHYSFS_DUKTAPE               0x000000U /* initial */

#define MTR_VERSION_UTILS_COLOR                          0x000300U /* not incremented */
#define MTR_VERSION_UTILS_COLOR_LUA                      0x000200U /* not incremented */
#define MTR_VERSION_UTILS_COLOR_SQUIRREL                 0x000100U /* not incremented */
#define MTR_VERSION_UTILS_COLOR_DUKTAPE                  0x000100U /* not incremented */

#define MTR_VERSION_UTILS_MATH                           0x000200U /* inc minor */
#define MTR_VERSION_UTILS_MATH_LUA                       0x000200U /* inc minor */
#define MTR_VERSION_UTILS_MATH_SQUIRREL                  0x000200U /* inc minor */
#define MTR_VERSION_UTILS_MATH_DUKTAPE                   0x000200U /* inc minor */

#define MTR_VERSION_ABSTRACTION_SPRITE                   0x000300U /* inc minor */
#define MTR_VERSION_ABSTRACTION_SPRITE_LUA               0x000200U /* inc minor */
#define MTR_VERSION_ABSTRACTION_SPRITE_SQUIRREL          0x000200U /* inc minor */
#define MTR_VERSION_ABSTRACTION_SPRITE_DUKTAPE           0x000200U /* inc minor */

#define MTR_VERSION_ABSTRACTION_ANIMATED_SPRITE          0x000000U /* initial */
#define MTR_VERSION_ABSTRACTION_ANIMATED_SPRITE_LUA      0x000000U /* initial */
#define MTR_VERSION_ABSTRACTION_ANIMATED_SPRITE_SQUIRREL 0x000000U /* initial */
#define MTR_VERSION_ABSTRACTION_ANIMATED_SPRITE_DUKTAPE  0x000000U /* initial */

#define MTR_VERSION_ABSTRACTION_FONT                     0x000301U /* inc patch */
#define MTR_VERSION_ABSTRACTION_FONT_LUA                 0x000201U /* not incremented */
#define MTR_VERSION_ABSTRACTION_FONT_SQUIRREL            0x000201U /* not incremented */
#define MTR_VERSION_ABSTRACTION_FONT_DUKTAPE             0x000101U /* not incremented */

#define MTR_VERSION_ABSTRACTION_GUI                      0x000201U /* inc patch */
#define MTR_VERSION_ABSTRACTION_GUI_LUA                  0x000100U /* not incremented */
#define MTR_VERSION_ABSTRACTION_GUI_SQUIRREL             0x000100U /* not incremented */
#define MTR_VERSION_ABSTRACTION_GUI_DUKTAPE              0x000100U /* not incremented */

#define MTR_VERSION_ABSTRACTION_SCENE                    0x000000U /* initial */
#define MTR_VERSION_ABSTRACTION_SCENE_LUA                0x000000U /* initial */
#define MTR_VERSION_ABSTRACTION_SCENE_SQUIRREL           0x000000U /* initial */
#define MTR_VERSION_ABSTRACTION_SCENE_DUKTAPE            0x000000U /* initial */

#endif
