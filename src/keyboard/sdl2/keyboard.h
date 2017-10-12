#ifndef MTR_KEYBOARD_SDL2_H
#define MTR_KEYBOARD_SDL2_H

#include "SDL2/SDL.h"

#include "fa/Keyboard_SDL2.h"
#include "marathoner/plugin.h"

typedef struct mtrKeyboard_t{
    const uint8_t *currentKeystate;
    uint8_t previousKeystate[SDL_NUM_SCANCODES];
    char utf8char[SDL_TEXTINPUTEVENT_TEXT_SIZE];
} mtrKeyboard_t;

mtrKeyboard_t mtrKeyboard;
static bool mtrKeyboardInited = false;
#define MTR_KEYBOARD_CHECK_IF_NOT_INITED(returnValue) \
    if (!mtrKeyboardInited)                           \
        return returnValue;
#define MTR_KEYBOARD_CHECK_IF_NOT_INITED_WITH_LOG(message, returnValue) \
    if (!mtrKeyboardInited)                                             \
    {                                                                   \
        mtrLogWrite(message ". Keyboard support are not initialized",   \
         1, MTR_LMT_ERROR);                                             \
        return returnValue;                                             \
    }

#endif
