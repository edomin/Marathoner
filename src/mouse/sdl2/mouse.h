#ifndef MTR_MOUSE_SDL2
#define MTR_MOUSE_SDL2

#define MTR_PLUGIN
#include "marathoner.h"

#include <stdbool.h>

#include "SDL2/SDL.h"

typedef struct mtrMouse_t{
    uint8_t  currentMousestate[5];
    uint8_t  previousMousestate[5];
    int16_t x;
    int16_t y;
    int16_t previousX;
    int16_t previousY;
    int8_t  relativeWheel;
} mtrMouse_t;

mtrMouse_t mtrMouse;

#define MTR_MOUSE_LEFT   SDL_BUTTON_LEFT
#define MTR_MOUSE_RIGHT  SDL_BUTTON_RIGHT
#define MTR_MOUSE_MIDDLE SDL_BUTTON_MIDDLE
#define MTR_MOUSE_X1     SDL_BUTTON_X1
#define MTR_MOUSE_X2     SDL_BUTTON_X2

#endif

