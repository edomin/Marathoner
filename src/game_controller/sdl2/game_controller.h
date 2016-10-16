#ifndef MTR_GAME_CONTROLLER_SDL2
#define MTR_GAME_CONTROLLER_SDL2

#include "SDL2/SDL.h"

#include "marathoner/plugin.h"

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

#define MTR_POVHAT_CENTER       SDL_HAT_CENTERED
#define MTR_POVHAT_UP           SDL_HAT_UP
#define MTR_POVHAT_DOWN         SDL_HAT_DOWN
#define MTR_POVHAT_LEFT         SDL_HAT_LEFT
#define MTR_POVHAT_RIGHT        SDL_HAT_RIGHT
#define MTR_POVHAT_UP_LEFT      SDL_HAT_LEFTUP
#define MTR_POVHAT_UP_RIGHT     SDL_HAT_RIGHTUP
#define MTR_POVHAT_DOWN_LEFT    SDL_HAT_LEFTDOWN
#define MTR_POVHAT_DOWN_RIGHT   SDL_HAT_RIGHTDOWN

#endif


