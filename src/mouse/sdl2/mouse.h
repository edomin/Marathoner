#ifndef MTR_MOUSE_SDL2
#define MTR_MOUSE_SDL2

#include "SDL2/SDL.h"

#include "marathoner/plugin.h"

typedef struct mtrMouse_t{
    int currentMousestate[5];
    int previousMousestate[5];
    int x;
    int y;
    int previousX;
    int previousY;
    int  relativeWheel;
} mtrMouse_t;

mtrMouse_t mtrMouse;

#define MTR_MOUSE_LEFT   SDL_BUTTON_LEFT
#define MTR_MOUSE_RIGHT  SDL_BUTTON_RIGHT
#define MTR_MOUSE_MIDDLE SDL_BUTTON_MIDDLE
#define MTR_MOUSE_X1     SDL_BUTTON_X1
#define MTR_MOUSE_X2     SDL_BUTTON_X2

#endif

