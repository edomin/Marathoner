#ifndef MTR_KEYBOARD_SDL2
#define MTR_KEYBOARD_SDL2

#define MTR_PLUGIN
#include "marathoner.h"

#include "bool/bool.h"

#include "SDL2/SDL.h"

typedef struct mtrKeyboard_t{
    const uint8_t *currentKeystate;
    uint8_t previousKeystate[SDL_NUM_SCANCODES];
} mtrKeyboard_t;

mtrKeyboard_t mtrKeyboard;
#endif
