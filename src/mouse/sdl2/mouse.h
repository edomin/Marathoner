#ifndef MTR_MOUSE_SDL2_H
#define MTR_MOUSE_SDL2_H

#include "SDL2/SDL.h"

#include "fa/Mouse_SDL2.h"
#include "marathoner/plugin.h"

typedef struct mtrMouse_t{
    int  currentMousestate[5];
    int  previousMousestate[5];
    int  x;
    int  y;
    int  deltaX;
    int  deltaY;
    bool mouseMotion;
    int  relativeWheel;
} mtrMouse_t;

mtrMouse_t mtrMouse;

#endif
