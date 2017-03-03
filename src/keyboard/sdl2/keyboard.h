#ifndef MTR_KEYBOARD_SDL2_H
#define MTR_KEYBOARD_SDL2_H

#include "SDL2/SDL.h"

#include "marathoner/plugin.h"

typedef struct mtrKeyboard_t{
    const uint8_t *currentKeystate;
    uint8_t previousKeystate[SDL_NUM_SCANCODES];
    char utf8char[SDL_TEXTINPUTEVENT_TEXT_SIZE];
} mtrKeyboard_t;

mtrKeyboard_t mtrKeyboard;

#endif
