#include "game_controller.h"

#include "marathoner/plugin_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Game_Controller_SDL2";
    report->version = MTR_VERSION_GAME_CONTROLLER_SDL2;
    report->subsystem = "game_controller";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

int mtrEnableController(int index)
{
    mtrGameController_t *gameController;
    bool                 ok;
    int                  i;
    int                  freeIndex;

    mtrLogWrite_s("Controller found:", 1, MTR_LMT_INFO,
     SDL_JoystickNameForIndex(index));
    freeIndex = mtrIndexkeeperGetFreeIndex(mtrGameControllerKeeper);
    gameController = IK_GET_DATA(mtrGameController_t *, mtrGameControllerKeeper, freeIndex);
    gameController->name = SDL_JoystickNameForIndex(index);

    gameController->gameController = SDL_JoystickOpen(index);
    if(gameController->gameController == NULL)
    {
        mtrLogWrite_s("Unable to open controller for use:", 1,
         MTR_LMT_WARNING, gameController->name);
        mtrIndexkeeperFreeIndex(mtrGameControllerKeeper, freeIndex);
        return 0;
    }
    mtrLogWrite_s("Initialising controller:", 1, MTR_LMT_INFO, gameController->name);

    gameController->buttonsCount = SDL_JoystickNumButtons(gameController->gameController);
    gameController->axesCount = SDL_JoystickNumAxes(gameController->gameController);
    gameController->trackballsCount = SDL_JoystickNumBalls(gameController->gameController);
    gameController->povHatsCount = SDL_JoystickNumHats(gameController->gameController);

    mtrLogWrite_i("Buttons found:", 2, MTR_LMT_INFO,
     gameController->buttonsCount);
    mtrLogWrite_i("Axes found:", 2, MTR_LMT_INFO,
     gameController->axesCount);
    mtrLogWrite_i("Trackballs found:", 2, MTR_LMT_INFO,
     gameController->trackballsCount);
    mtrLogWrite_i("POV hats found:", 2, MTR_LMT_INFO,
     gameController->povHatsCount);

    if (gameController->buttonsCount > 0)
    {
        ok = true;
        gameController->currentButtonState = malloc(sizeof(bool *) * gameController->buttonsCount);
        if (gameController->currentButtonState == NULL)
        {
            mtrLogWrite_i("Unable to allocate memory for current buttons' state of controller",
             2, MTR_LMT_WARNING, index);
            mtrLogWrite_i("Buttons of this controller will not processing",
             2, MTR_LMT_NOTE, index);
            ok = false;
        }
        if (ok)
        {
            gameController->previousButtonState = malloc(sizeof(bool *) * gameController->buttonsCount);
            if (gameController->previousButtonState == NULL)
            {
                mtrLogWrite_i("Unable to allocate memory for previous buttons' state of controller",
                 2, MTR_LMT_WARNING, index);
                mtrLogWrite_i("Buttons of this controller will not processing",
                 2, MTR_LMT_NOTE, index);
                ok = false;
                free(gameController->currentButtonState);
            }
        }

        if (!ok)
            gameController->buttonsCount = 0;
    }

    if (gameController->axesCount > 0)
    {
        ok = true;
        gameController->currentAxis = malloc(sizeof(int16_t *) * gameController->axesCount);
        if (gameController->currentAxis == NULL)
        {
            mtrLogWrite_i("Unable to allocate memory for current axes' state of controller",
             2, MTR_LMT_WARNING, index);
            mtrLogWrite_i("Axes of this controller will not processing",
             2, MTR_LMT_NOTE, index);
            ok = false;
        }
        if (ok)
        {
            gameController->previousAxis = malloc(sizeof(int16_t *) * gameController->axesCount);
            if (gameController->previousAxis == NULL)
            {
                mtrLogWrite_i("Unable to allocate memory for previous axes' state of controller",
                 2, MTR_LMT_WARNING, index);
                mtrLogWrite_i("Axes of this controller will not processing",
                 2, MTR_LMT_NOTE, index);
                ok = false;
                free(gameController->currentAxis);
            }
        }

        if (!ok)
            gameController->axesCount = 0;
    }

    if (gameController->trackballsCount > 0)
    {
        gameController->trackballDelta = malloc(sizeof(mtrTrackballDelta_t *) * gameController->trackballsCount);
        if (gameController->trackballDelta == NULL)
        {
            mtrLogWrite_i("Unable to allocate memory for trackballs' state of controller",
             2, MTR_LMT_WARNING, index);
            mtrLogWrite_i("Trackballs of this controller will not processing",
             2, MTR_LMT_NOTE, index);
            gameController->trackballsCount = 0;
        }
    }

    if (gameController->povHatsCount > 0)
    {
        gameController->povHat = malloc(sizeof(uint8_t *) * gameController->povHatsCount);
        if (gameController->povHat == NULL)
        {
            mtrLogWrite_i("Unable to allocate memory for current POV hats' state of controller",
             2, MTR_LMT_WARNING, index);
            mtrLogWrite_i("POV hats of this controller will not processing",
             2, MTR_LMT_NOTE, index);
            gameController->povHatsCount = 0;
        }
    }

    for (i = 0; i < gameController->buttonsCount; i++)
    {
        gameController->currentButtonState[i] = false;
        gameController->previousButtonState[i] = false;
    }
    for (i = 0; i < gameController->axesCount; i++)
    {
        gameController->currentAxis[i] = 0;
        gameController->previousAxis[i] = 0;
    }
    for (i = 0; i < gameController->trackballsCount; i++)
    {
        gameController->trackballDelta[i].dx = 0;
        gameController->trackballDelta[i].dy = 0;
    }
    for (i = 0; i < gameController->povHatsCount; i++)
        gameController->povHat[i] = MTR_POVHAT_CENTER;

    mtrLogWrite("Controller initialised:", 1, MTR_LMT_INFO);

    return freeIndex;
}

void mtrDisableController(int controllerNum)
{
    mtrGameController_t *gameController;

    if (mtrIndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        return;

    gameController = IK_GET_DATA(mtrGameController_t *, mtrGameControllerKeeper, controllerNum);
    SDL_JoystickClose(gameController->gameController);
    if (gameController->buttonsCount > 0)
    {
        free(gameController->currentButtonState);
        free(gameController->previousButtonState);
    }
    if (gameController->axesCount > 0)
    {
        free(gameController->currentAxis);
        free(gameController->previousAxis);
    }
    if (gameController->trackballsCount > 0)
    {
        free(gameController->trackballDelta);
    }
    if (gameController->povHatsCount > 0)
    {
        free(gameController->povHat);
    }
    free(mtrGameController);

    mtrIndexkeeperFreeIndex(mtrGameControllerKeeper, controllerNum);
}

MTR_EXPORT bool MTR_CALL mtrGameControllerInit(void)
{
    SDL_version             compiled;
    SDL_version             linked;
    int                     i;

    mtrLogWrite("Initializing game controller support", 0, MTR_LMT_INFO);

    mtrLogWrite("Reporting SDL compile-time version:", 1, MTR_LMT_INFO);
    SDL_VERSION(&compiled);
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, compiled.major);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, compiled.minor);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, compiled.patch);
    mtrLogWrite("Reporting SDL linked version:", 1, MTR_LMT_INFO);
    SDL_GetVersion(&linked);
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, linked.major);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, linked.minor);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, linked.patch);

    mtrGameControllerKeeper = (mtrIndexkeeper_t *)mtrIndexkeeperCreate(MTR_IKDM_SMALL,
     32, sizeof(mtrGameController_t));
    if (mtrGameControllerKeeper == NULL)
    {
        mtrNotify("Unable to create Game Controller Keeper", 1, MTR_LMT_ERROR);
        mtrNotify("Game Controller Support not initialized", 1, MTR_LMT_ERROR);
        return false;
    }
    else
        mtrLogWrite("Game Controller Keeper created", 0, MTR_LMT_INFO);

    if(SDL_WasInit(SDL_INIT_EVENTS) == 0)
    {
        if (SDL_InitSubSystem(SDL_INIT_EVENTS) == 0)
            mtrLogWrite("SDL events subsystem initialized", 1, MTR_LMT_INFO);
        else
        {
             mtrNotify("Unable to initialize SDL events subsystem", 1,
              MTR_LMT_ERROR);
              return false;
        }
    }
    else
        mtrLogWrite("SDL events subsystem already initialized", 1,
         MTR_LMT_INFO);

    if(SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
    {
        if (SDL_InitSubSystem(SDL_INIT_JOYSTICK) == 0)
            mtrLogWrite("SDL joystick subsystem initialized", 1, MTR_LMT_INFO);
        else
        {
             mtrNotify("Unable to initialize SDL joystick subsystem", 1,
              MTR_LMT_ERROR);
              return false;
        }
    }
    else
        mtrLogWrite("SDL joystick subsystem already initialized", 1,
         MTR_LMT_INFO);

    mtrGameControllersCount = SDL_NumJoysticks();
    if(mtrGameControllersCount < 1)
        mtrLogWrite("Connected controllers not found", 1, MTR_LMT_INFO);

    for (i = 0; i < mtrGameControllersCount; i++)
    {
        mtrEnableController(i);
    }

    mtrLogWrite("Game Controller support initialized", 0, MTR_LMT_INFO);
    return true;
}

MTR_EXPORT void MTR_CALL mtrGameControllerQuit(void)
{
    uint32_t i;

    mtrLogWrite("Disabling game controller support", 0, MTR_LMT_INFO);
    for (i = 1; i <= mtrGameControllerKeeper->reservedData; i++)
    {
        if (!mtrIndexkeeperIndexIsEmpty(mtrGameControllerKeeper, i))
        {
            mtrDisableController(i);
        }
    }
    mtrIndexkeeperDestroy(mtrGameControllerKeeper);
    mtrLogWrite("Game controller support disabled", 0, MTR_LMT_INFO);
}

MTR_EXPORT void MTR_CALL mtrGameControllerRefresh(void)
{
    unsigned int         i;
    int                  j;
    mtrGameController_t *gameController;

    SDL_JoystickUpdate();
    for (i = 0; i < mtrGameControllerKeeper->reservedData; i++)
    {
        if (!mtrIndexkeeperIndexIsEmpty(mtrGameControllerKeeper, i))
        {
            gameController = IK_GET_DATA(mtrGameController_t *, mtrGameControllerKeeper, i);

            /* Проверка, что контроллер всё ещё подключен */
            if (!SDL_JoystickGetAttached(gameController->gameController))
            {
                mtrLogWrite_s("Missing controller:", 0, MTR_LMT_INFO, gameController->name);
                mtrDisableController(i);
                mtrGameControllersCount--;
                continue;
            }

            for (j = 0; j < gameController->buttonsCount; j++)
            {
                gameController->previousButtonState[j] = gameController->currentButtonState[j];
                if (SDL_JoystickGetButton(gameController->gameController, j) == 1)
                {
                    gameController->currentButtonState[j] = true;
                }
                else
                {
                    gameController->currentButtonState[j] = false;
                }
            }
            for (j = 0; j < gameController->axesCount; j++)
            {
                gameController->previousAxis[j] = gameController->currentAxis[j];
                gameController->currentAxis[j] = SDL_JoystickGetAxis(gameController->gameController, j);
            }
            for (j = 0; j < gameController->trackballsCount; j++)
                SDL_JoystickGetBall(gameController->gameController, j,
                 &gameController->trackballDelta[j].dx,
                 &gameController->trackballDelta[j].dy);
            for (j = 0; j < gameController->povHatsCount; j++)
            {
                gameController->povHat[j] = SDL_JoystickGetHat(gameController->gameController, j);
            }
        }
    }

    /* Проверка, не подключили ли новых контроллеров */
    if (SDL_NumJoysticks() > mtrGameControllersCount)
    {
        if (mtrEnableController(mtrGameControllersCount + 1) > 0)
            mtrGameControllersCount++;
    }
}

MTR_EXPORT bool MTR_CALL mtrGameControllerButtonPress(int controllerNum,
 int button)
{
    mtrGameController_t *gameController;

    gameController = IK_GET_DATA(mtrGameController_t *, mtrGameControllerKeeper, controllerNum);
    if (!mtrIndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        if (button < gameController->buttonsCount)
            if ((gameController->currentButtonState[button]) &&
             !(gameController->previousButtonState[button]))
                return true;
            else
                return false;
        else
            return false;
    else
        return false;
}

MTR_EXPORT bool MTR_CALL mtrGameControllerButtonRelease(int controllerNum,
 int button)
{
    mtrGameController_t *gameController;

    gameController = IK_GET_DATA(mtrGameController_t *, mtrGameControllerKeeper, controllerNum);
    if (!mtrIndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        if (button < gameController->buttonsCount)
            if (!(gameController->currentButtonState[button]) &&
             (gameController->previousButtonState[button]))
                return true;
            else
                return false;
        else
            return false;
    else
        return false;
}

MTR_EXPORT bool MTR_CALL mtrGameControllerButtonPressed(int controllerNum,
 int button)
{
    mtrGameController_t *gameController;

    gameController = IK_GET_DATA(mtrGameController_t *, mtrGameControllerKeeper, controllerNum);
    if (!mtrIndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        if (button < gameController->buttonsCount)
            return gameController->currentButtonState[button];
        else
            return false;
    else
        return false;
}

MTR_EXPORT int16_t MTR_CALL mtrGameControllerGetAxis(int controllerNum,
 int axisNum)
{
    mtrGameController_t *gameController;

    gameController = IK_GET_DATA(mtrGameController_t *, mtrGameControllerKeeper, controllerNum);
    if (!mtrIndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        if (axisNum < gameController->axesCount)
            return gameController->currentAxis[axisNum];
        else
            return 0;
    else
        return 0;
}

MTR_EXPORT float MTR_CALL mtrGameControllerGetAxis_f(int controllerNum,
 int axisNum)
{
    mtrGameController_t *gameController;

    gameController = IK_GET_DATA(mtrGameController_t *, mtrGameControllerKeeper, controllerNum);
    if (!mtrIndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        if (axisNum < gameController->axesCount)
            if (gameController->currentAxis[axisNum] > 0)
                return ((float)gameController->currentAxis[axisNum] / (float)(INT16_MAX));
            else
                return ((float)gameController->currentAxis[axisNum] / (float)(-INT16_MIN));
        else
            return 0.0f;
    else
        return 0.0f;
}

MTR_EXPORT int MTR_CALL mtrGameControllerGetAxisDelta(int controllerNum,
 int axisNum)
{
    mtrGameController_t *gameController;

    gameController = IK_GET_DATA(mtrGameController_t *, mtrGameControllerKeeper, controllerNum);
    if (!mtrIndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        if (axisNum < gameController->axesCount)
            return gameController->currentAxis[axisNum] -
             gameController->previousAxis[axisNum];
        else
            return 0;
    else
        return 0;
}

MTR_EXPORT float MTR_CALL mtrGameControllerGetAxisDelta_f(int controllerNum,
 int axisNum)
{
    mtrGameController_t *gameController;

    gameController = IK_GET_DATA(mtrGameController_t *, mtrGameControllerKeeper, controllerNum);
    if (!mtrIndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        if (axisNum < gameController->axesCount)
            return (float)(gameController->currentAxis[axisNum] -
             gameController->previousAxis[axisNum]) / (float)(INT16_MAX);
        else
            return 0.0f;
    else
        return 0.0f;
}

MTR_EXPORT int MTR_CALL mtrGameControllerGetTrackballDeltaX(int controllerNum,
 int trackballNum)
{
    mtrGameController_t *gameController;

    gameController = IK_GET_DATA(mtrGameController_t *, mtrGameControllerKeeper, controllerNum);
    if (!mtrIndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        if (trackballNum < gameController->trackballsCount)
            return gameController->trackballDelta[trackballNum].dx;
        else
            return 0;
    else
        return 0;
}

MTR_EXPORT int MTR_CALL mtrGameControllerGetTrackballDeltaY(int controllerNum,
 int trackballNum)
{
    mtrGameController_t *gameController;

    gameController = IK_GET_DATA(mtrGameController_t *, mtrGameControllerKeeper, controllerNum);
    if (!mtrIndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        if (trackballNum < gameController->trackballsCount)
            return gameController->trackballDelta[trackballNum].dy;
        else
            return 0;
    else
        return 0;
}

MTR_EXPORT void MTR_CALL mtrGameControllerGetTrackballDeltaXY(int controllerNum,
 int trackballNum, int *deltaX, int *deltaY)
{
    mtrGameController_t *gameController;

    gameController = IK_GET_DATA(mtrGameController_t *, mtrGameControllerKeeper, controllerNum);
    if (!mtrIndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        if (trackballNum < gameController->trackballsCount)
        {
            *deltaX = gameController->trackballDelta[trackballNum].dx;
            *deltaY = gameController->trackballDelta[trackballNum].dy;
        }
        else
        {
            *deltaX = 0;
            *deltaY = 0;
        }
    else
    {
        *deltaX = 0;
        *deltaY = 0;
    }
}

MTR_EXPORT uint8_t MTR_CALL mtrGameControllerGetPovHat(int controllerNum,
 int povHatNum)
{
    mtrGameController_t *gameController;

    gameController = IK_GET_DATA(mtrGameController_t *, mtrGameControllerKeeper, controllerNum);
    if (!mtrIndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        if (povHatNum < gameController->povHatsCount)
            return gameController->povHat[povHatNum];
        else
            return 0;
    else
        return 0;
}
