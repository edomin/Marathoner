#ifndef MTR_GAME_CONTROLLER_SDL2_H
#define MTR_GAME_CONTROLLER_SDL2_H

#include "SDL2/SDL.h"

#include "fa/Game_Controller_SDL2.h"
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
    const char          *name; /* Added for Controller Keeper */
} mtrGameController_t;

int                  mtrGameControllersCount;
mtrGameController_t *mtrGameController;
mtrIndexkeeper_t *mtrGameControllerKeeper;
static bool mtrGameControllerInited = false;
#define MTR_GAME_CONTROLLER_CHECK_IF_NOT_INITED(returnValue) \
    if (!mtrGameControllerInited)                            \
        return returnValue;
#define MTR_GAME_CONTROLLER_CHECK_IF_NOT_INITED_WITH_LOG(message, returnValue) \
    if (!mtrGameControllerInited)                                              \
    {                                                                          \
        mtrLogWrite(message ". game controller support are not initialized",   \
         1, MTR_LMT_ERROR);                                                    \
        return returnValue;                                                    \
    }

#endif


