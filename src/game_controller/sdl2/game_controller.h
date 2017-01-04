#ifndef MTR_GAME_CONTROLLER_SDL2
#define MTR_GAME_CONTROLLER_SDL2

#include "SDL2/SDL.h"

#include "marathoner/plugin.h"
#include "../common.h"

typedef struct mtrTrackballDelta_t{
    int dx;
    int dy;
}mtrTrackballDelta_t;

typedef struct mtrGameController_t{
    SDL_Joystick        *gameController;
    bool                *currentButtonState;
    bool                *previousButtonState;
    int16_t             *currentAxis;
    int16_t             *previousAxis;
    mtrTrackballDelta_t *trackballDelta;
    uint8_t             *povHat;
    int                  buttonsCount;
    int                  axesCount;
    int                  trackballsCount;
    int                  povHatsCount;
} mtrGameController_t;

int                  mtrGameControllersCount;
mtrGameController_t *mtrGameController;

#endif


