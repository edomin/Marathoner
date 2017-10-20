#include "game_controller.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(GameController, FA_FUNCTIONS_COUNT)

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
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

int MTR_EnableController(int index)
{
    mtrGameController_t *gameController;
    bool                 ok;
    int                  i;
    int                  freeIndex;

    MTR_LogWrite_s("Controller found:", 1, MTR_LMT_INFO,
     SDL_JoystickNameForIndex(index));
    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrGameControllerKeeper);
    gameController = IK_GET_DATA(mtrGameController_t *, mtrGameControllerKeeper,
     freeIndex);
    gameController->name = SDL_JoystickNameForIndex(index);

    gameController->gameController = SDL_JoystickOpen(index);
    if(gameController->gameController == NULL)
    {
        MTR_LogWrite_s("Unable to open controller for use:", 1,
         MTR_LMT_WARNING, gameController->name);
        MTR_IndexkeeperFreeIndex(mtrGameControllerKeeper, freeIndex);
        return 0;
    }
    MTR_LogWrite_s("Initialising controller:", 1, MTR_LMT_INFO,
     gameController->name);

    gameController->buttonsCount = SDL_JoystickNumButtons(
     gameController->gameController);
    gameController->axesCount = SDL_JoystickNumAxes(
     gameController->gameController);
    gameController->trackballsCount = SDL_JoystickNumBalls(
     gameController->gameController);
    gameController->povHatsCount = SDL_JoystickNumHats(
     gameController->gameController);

    MTR_LogWrite_i("Buttons found:", 2, MTR_LMT_INFO,
     gameController->buttonsCount);
    MTR_LogWrite_i("Axes found:", 2, MTR_LMT_INFO,
     gameController->axesCount);
    MTR_LogWrite_i("Trackballs found:", 2, MTR_LMT_INFO,
     gameController->trackballsCount);
    MTR_LogWrite_i("POV hats found:", 2, MTR_LMT_INFO,
     gameController->povHatsCount);

    if (gameController->buttonsCount > 0)
    {
        ok = true;
        gameController->currentButtonState = malloc(
         sizeof(bool *) * gameController->buttonsCount);
        if (gameController->currentButtonState == NULL)
        {
            MTR_LogWrite_i("Unable to allocate memory for current buttons' "
             "state of controller", 2, MTR_LMT_WARNING, index);
            MTR_LogWrite_i("Buttons of this controller will not be processed",
             2, MTR_LMT_NOTE, index);
            ok = false;
        }
        if (ok)
        {
            gameController->previousButtonState = malloc(
             sizeof(bool *) * gameController->buttonsCount);
            if (gameController->previousButtonState == NULL)
            {
                MTR_LogWrite_i("Unable to allocate memory for previous "
                 "buttons' state of controller", 2, MTR_LMT_WARNING, index);
                MTR_LogWrite_i(
                 "Buttons of this controller will not be processed", 2,
                 MTR_LMT_NOTE, index);
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
        gameController->currentAxis = malloc(
         sizeof(int16_t *) * gameController->axesCount);
        if (gameController->currentAxis == NULL)
        {
            MTR_LogWrite_i("Unable to allocate memory for current axes' state "
             "of controller", 2, MTR_LMT_WARNING, index);
            MTR_LogWrite_i("Axes of this controller will not be processed", 2,
             MTR_LMT_NOTE, index);
            ok = false;
        }
        if (ok)
        {
            gameController->previousAxis = malloc(
             sizeof(int16_t *) * gameController->axesCount);
            if (gameController->previousAxis == NULL)
            {
                MTR_LogWrite_i("Unable to allocate memory for previous axes' "
                 "state of controller", 2, MTR_LMT_WARNING, index);
                MTR_LogWrite_i("Axes of this controller will not be processed",
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
        gameController->trackballDelta = malloc(
         sizeof(mtrTrackballDelta_t *) * gameController->trackballsCount);
        if (gameController->trackballDelta == NULL)
        {
            MTR_LogWrite_i("Unable to allocate memory for trackballs' state "
             "of controller", 2, MTR_LMT_WARNING, index);
            MTR_LogWrite_i("Trackballs of this controller will not be processed",
             2, MTR_LMT_NOTE, index);
            gameController->trackballsCount = 0;
        }
    }

    if (gameController->povHatsCount > 0)
    {
        gameController->povHat = malloc(
         sizeof(uint8_t *) * gameController->povHatsCount);
        if (gameController->povHat == NULL)
        {
            MTR_LogWrite_i("Unable to allocate memory for current POV hats' "
             "state of controller", 2, MTR_LMT_WARNING, index);
            MTR_LogWrite_i("POV hats of this controller will not be processed",
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

    MTR_LogWrite("Controller initialised:", 1, MTR_LMT_INFO);

    return freeIndex;
}

void MTR_DisableController(int controllerNum)
{
    mtrGameController_t *gameController;

    if (MTR_IndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        return;

    gameController = IK_GET_DATA(mtrGameController_t *,
     mtrGameControllerKeeper, controllerNum);
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

    MTR_IndexkeeperFreeIndex(mtrGameControllerKeeper, controllerNum);
}

/*fa MTR_GameControllerInit yes */
MTR_DCLSPC bool MTR_CALL MTR_GameControllerInit(void)
{
    SDL_version             compiled;
    SDL_version             linked;
    int                     i;

    MTR_LogWrite("Initializing game controller support", 0, MTR_LMT_INFO);

    MTR_LogWrite("Reporting SDL compile-time version:", 1, MTR_LMT_INFO);
    SDL_VERSION(&compiled);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, compiled.major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, compiled.minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, compiled.patch);
    MTR_LogWrite("Reporting SDL linked version:", 1, MTR_LMT_INFO);
    SDL_GetVersion(&linked);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, linked.major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, linked.minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, linked.patch);

    mtrGameControllerKeeper = (mtrIndexkeeper_t *)MTR_IndexkeeperCreate(
     MTR_IKDM_SMALL, 32, sizeof(mtrGameController_t));
    if (mtrGameControllerKeeper == NULL)
    {
        MTR_Notify("Unable to create Game Controller Keeper", 1, MTR_LMT_ERROR);
        MTR_Notify("Game Controller Support not initialized", 1, MTR_LMT_ERROR);
        return false;
    }
    else
        MTR_LogWrite("Game Controller Keeper created", 0, MTR_LMT_INFO);

    if(SDL_WasInit(SDL_INIT_EVENTS) == 0)
    {
        if (SDL_InitSubSystem(SDL_INIT_EVENTS) == 0)
            MTR_LogWrite("SDL events subsystem initialized", 1, MTR_LMT_INFO);
        else
        {
             MTR_Notify("Unable to initialize SDL events subsystem", 1,
              MTR_LMT_ERROR);
              return false;
        }
    }
    else
        MTR_LogWrite("SDL events subsystem already initialized", 1,
         MTR_LMT_INFO);

    if(SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
    {
        if (SDL_InitSubSystem(SDL_INIT_JOYSTICK) == 0)
            MTR_LogWrite("SDL joystick subsystem initialized", 1, MTR_LMT_INFO);
        else
        {
             MTR_Notify("Unable to initialize SDL joystick subsystem", 1,
              MTR_LMT_ERROR);
              return false;
        }
    }
    else
        MTR_LogWrite("SDL joystick subsystem already initialized", 1,
         MTR_LMT_INFO);

    mtrGameControllersCount = SDL_NumJoysticks();
    if(mtrGameControllersCount < 1)
        MTR_LogWrite("Connected controllers not found", 1, MTR_LMT_INFO);

    for (i = 0; i < mtrGameControllersCount; i++)
    {
        MTR_EnableController(i);
    }

    MTR_LogWrite("Game Controller support initialized", 0, MTR_LMT_INFO);

    mtrGameControllerInited = true;
    return true;
}

/*fa MTR_GameControllerQuit yes */
MTR_DCLSPC void MTR_CALL MTR_GameControllerQuit(void)
{
    uint32_t i;
    MTR_GAME_CONTROLLER_CHECK_IF_NOT_INITED_WITH_LOG(
     "Unable to disable game contoller support",);

    MTR_LogWrite("Disabling game controller support", 0, MTR_LMT_INFO);
    for (i = 1; i <= mtrGameControllerKeeper->reservedData; i++)
    {
        if (!MTR_IndexkeeperIndexIsEmpty(mtrGameControllerKeeper, i))
        {
            MTR_DisableController(i);
        }
    }
    MTR_IndexkeeperDestroy(mtrGameControllerKeeper);
    MTR_LogWrite("Game controller support disabled", 0, MTR_LMT_INFO);
}

/*fa MTR_GameControllerRefresh yes */
MTR_DCLSPC void MTR_CALL MTR_GameControllerRefresh(void)
{
    unsigned int         i;
    int                  j;
    mtrGameController_t *gameController;
    MTR_GAME_CONTROLLER_CHECK_IF_NOT_INITED();

    SDL_JoystickUpdate();
    for (i = 0; i < mtrGameControllerKeeper->reservedData; i++)
    {
        if (!MTR_IndexkeeperIndexIsEmpty(mtrGameControllerKeeper, i))
        {
            gameController = IK_GET_DATA(mtrGameController_t *,
             mtrGameControllerKeeper, i);

            /* Проверка, что контроллер всё ещё подключен */
            if (!SDL_JoystickGetAttached(gameController->gameController))
            {
                MTR_LogWrite_s("Lost controller:", 0, MTR_LMT_INFO,
                 gameController->name);
                MTR_DisableController(i);
                mtrGameControllersCount--;
                continue;
            }

            for (j = 0; j < gameController->buttonsCount; j++)
            {
                gameController->previousButtonState[j] = gameController->currentButtonState[j];
                if (SDL_JoystickGetButton(gameController->gameController, j) ==
                 1)
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
                gameController->currentAxis[j] = SDL_JoystickGetAxis(
                 gameController->gameController, j);
            }
            for (j = 0; j < gameController->trackballsCount; j++)
                SDL_JoystickGetBall(gameController->gameController, j,
                 &gameController->trackballDelta[j].dx,
                 &gameController->trackballDelta[j].dy);
            for (j = 0; j < gameController->povHatsCount; j++)
            {
                gameController->povHat[j] = SDL_JoystickGetHat(
                 gameController->gameController, j);
            }
        }
    }

    /* Проверка, не подключили ли новых контроллеров */
    if (SDL_NumJoysticks() > mtrGameControllersCount)
    {
        if (MTR_EnableController(mtrGameControllersCount + 1) > 0)
            mtrGameControllersCount++;
    }
}

/*fa MTR_GameControllerButtonPress yes */
MTR_DCLSPC bool MTR_CALL MTR_GameControllerButtonPress(int controllerNum,
 int button)
{
    mtrGameController_t *gameController;
    MTR_GAME_CONTROLLER_CHECK_IF_NOT_INITED(false);

    gameController = IK_GET_DATA(mtrGameController_t *,
     mtrGameControllerKeeper, controllerNum);
    if (!MTR_IndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
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

/*fa MTR_GameControllerButtonRelease yes */
MTR_DCLSPC bool MTR_CALL MTR_GameControllerButtonRelease(int controllerNum,
 int button)
{
    mtrGameController_t *gameController;
    MTR_GAME_CONTROLLER_CHECK_IF_NOT_INITED(false);

    gameController = IK_GET_DATA(mtrGameController_t *,
     mtrGameControllerKeeper, controllerNum);
    if (!MTR_IndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
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

/*fa MTR_GameControllerButtonPressed yes */
MTR_DCLSPC bool MTR_CALL MTR_GameControllerButtonPressed(int controllerNum,
 int button)
{
    mtrGameController_t *gameController;
    MTR_GAME_CONTROLLER_CHECK_IF_NOT_INITED(false);

    gameController = IK_GET_DATA(mtrGameController_t *,
     mtrGameControllerKeeper, controllerNum);
    if (!MTR_IndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        if (button < gameController->buttonsCount)
            return gameController->currentButtonState[button];
        else
            return false;
    else
        return false;
}

/*fa MTR_GameControllerGetAxis yes */
MTR_DCLSPC int16_t MTR_CALL MTR_GameControllerGetAxis(int controllerNum,
 int axisNum)
{
    mtrGameController_t *gameController;
    MTR_GAME_CONTROLLER_CHECK_IF_NOT_INITED(0);

    gameController = IK_GET_DATA(mtrGameController_t *,
     mtrGameControllerKeeper, controllerNum);
    if (!MTR_IndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        if (axisNum < gameController->axesCount)
            return gameController->currentAxis[axisNum];
        else
            return 0;
    else
        return 0;
}

/*fa MTR_GameControllerGetAxis_f yes */
MTR_DCLSPC float MTR_CALL MTR_GameControllerGetAxis_f(int controllerNum,
 int axisNum)
{
    mtrGameController_t *gameController;
    MTR_GAME_CONTROLLER_CHECK_IF_NOT_INITED(0.0f);

    gameController = IK_GET_DATA(mtrGameController_t *,
     mtrGameControllerKeeper, controllerNum);
    if (!MTR_IndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        if (axisNum < gameController->axesCount)
            if (gameController->currentAxis[axisNum] > 0)
                return ((float)gameController->currentAxis[axisNum] /
                 (float)(INT16_MAX));
            else
                return ((float)gameController->currentAxis[axisNum] /
                 (float)(-INT16_MIN));
        else
            return 0.0f;
    else
        return 0.0f;
}

/*fa MTR_GameControllerGetAxisDelta yes */
MTR_DCLSPC int MTR_CALL MTR_GameControllerGetAxisDelta(int controllerNum,
 int axisNum)
{
    mtrGameController_t *gameController;
    MTR_GAME_CONTROLLER_CHECK_IF_NOT_INITED(0);

    gameController = IK_GET_DATA(mtrGameController_t *,
     mtrGameControllerKeeper, controllerNum);
    if (!MTR_IndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        if (axisNum < gameController->axesCount)
            return gameController->currentAxis[axisNum] -
             gameController->previousAxis[axisNum];
        else
            return 0;
    else
        return 0;
}

/*fa MTR_GameControllerGetAxisDelta_f yes */
MTR_DCLSPC float MTR_CALL MTR_GameControllerGetAxisDelta_f(int controllerNum,
 int axisNum)
{
    mtrGameController_t *gameController;
    MTR_GAME_CONTROLLER_CHECK_IF_NOT_INITED(0.0f);

    gameController = IK_GET_DATA(mtrGameController_t *,
     mtrGameControllerKeeper, controllerNum);
    if (!MTR_IndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        if (axisNum < gameController->axesCount)
            return (float)(gameController->currentAxis[axisNum] -
             gameController->previousAxis[axisNum]) / (float)(INT16_MAX);
        else
            return 0.0f;
    else
        return 0.0f;
}

/*fa MTR_GameControllerGetTrackballDeltaX yes */
MTR_DCLSPC int MTR_CALL MTR_GameControllerGetTrackballDeltaX(int controllerNum,
 int trackballNum)
{
    mtrGameController_t *gameController;
    MTR_GAME_CONTROLLER_CHECK_IF_NOT_INITED(0);

    gameController = IK_GET_DATA(mtrGameController_t *,
     mtrGameControllerKeeper, controllerNum);
    if (!MTR_IndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        if (trackballNum < gameController->trackballsCount)
            return gameController->trackballDelta[trackballNum].dx;
        else
            return 0;
    else
        return 0;
}

/*fa MTR_GameControllerGetTrackballDeltaY yes */
MTR_DCLSPC int MTR_CALL MTR_GameControllerGetTrackballDeltaY(int controllerNum,
 int trackballNum)
{
    mtrGameController_t *gameController;
    MTR_GAME_CONTROLLER_CHECK_IF_NOT_INITED(0);

    gameController = IK_GET_DATA(mtrGameController_t *,
     mtrGameControllerKeeper, controllerNum);
    if (!MTR_IndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        if (trackballNum < gameController->trackballsCount)
            return gameController->trackballDelta[trackballNum].dy;
        else
            return 0;
    else
        return 0;
}

/*fa MTR_GameControllerGetTrackballDeltaXY yes */
MTR_DCLSPC void MTR_CALL MTR_GameControllerGetTrackballDeltaXY(int controllerNum,
 int trackballNum, int *deltaX, int *deltaY)
{
    mtrGameController_t *gameController;

    if (!mtrGameControllerInited)
    {
        *deltaX = 0;
        *deltaY = 0;
        return;
    }

    gameController = IK_GET_DATA(mtrGameController_t *,
     mtrGameControllerKeeper, controllerNum);
    if (!MTR_IndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
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

/*fa MTR_GameControllerGetPovHat yes */
MTR_DCLSPC uint8_t MTR_CALL MTR_GameControllerGetPovHat(int controllerNum,
 int povHatNum)
{
    mtrGameController_t *gameController;
    MTR_GAME_CONTROLLER_CHECK_IF_NOT_INITED(0U);

    gameController = IK_GET_DATA(mtrGameController_t *,
     mtrGameControllerKeeper, controllerNum);
    if (!MTR_IndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        if (povHatNum < gameController->povHatsCount)
            return gameController->povHat[povHatNum];
        else
            return 0U;
    else
        return 0U;
}

/*fa MTR_GameControllerGetPovHatHorizontal yes */
MTR_DCLSPC int MTR_CALL MTR_GameControllerGetPovHatHorizontal(int controllerNum,
 int povHatNum)
{
    mtrGameController_t *gameController;
    MTR_GAME_CONTROLLER_CHECK_IF_NOT_INITED(0);

    gameController = IK_GET_DATA(mtrGameController_t *,
     mtrGameControllerKeeper, controllerNum);

    if (MTR_IndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        return 0;

    if (povHatNum >= gameController->povHatsCount)
        return 0;

    if (
     (gameController->povHat[povHatNum] & MTR_POVHAT_LEFT) == MTR_POVHAT_LEFT)
        return -1;
    else if (
     (gameController->povHat[povHatNum] & MTR_POVHAT_RIGHT) == MTR_POVHAT_RIGHT)
        return 1;

    return 0;
}

/*fa MTR_GameControllerGetPovHatVertical yes */
MTR_DCLSPC int MTR_CALL MTR_GameControllerGetPovHatVertical(int controllerNum,
 int povHatNum)
{
    mtrGameController_t *gameController;
    MTR_GAME_CONTROLLER_CHECK_IF_NOT_INITED(0);

    gameController = IK_GET_DATA(mtrGameController_t *,
     mtrGameControllerKeeper, controllerNum);

    if (MTR_IndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        return 0;

    if (povHatNum >= gameController->povHatsCount)
        return 0;

    if ((gameController->povHat[povHatNum] & MTR_POVHAT_UP) == MTR_POVHAT_UP)
        return -1;
    else if (
     (gameController->povHat[povHatNum] & MTR_POVHAT_DOWN) == MTR_POVHAT_DOWN)
        return 1;

    return 0;
}

/*fa MTR_GameControllerGetPovHatAxes yes */
MTR_DCLSPC void MTR_CALL MTR_GameControllerGetPovHatAxes(int controllerNum,
 int povHatNum, int *vertical, int *horizontal)
{
    mtrGameController_t *gameController;

    *horizontal = 0;
    *vertical = 0;

    MTR_GAME_CONTROLLER_CHECK_IF_NOT_INITED();

    gameController = IK_GET_DATA(mtrGameController_t *,
     mtrGameControllerKeeper, controllerNum);

    if (MTR_IndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        return;

    if (povHatNum >= gameController->povHatsCount)
        return;

    if (
     (gameController->povHat[povHatNum] & MTR_POVHAT_LEFT) == MTR_POVHAT_LEFT)
        *horizontal = -1;
    else if (
     (gameController->povHat[povHatNum] & MTR_POVHAT_RIGHT) == MTR_POVHAT_RIGHT)
        *horizontal = 1;
    else
        *horizontal = 0;

    if ((gameController->povHat[povHatNum] & MTR_POVHAT_UP) == MTR_POVHAT_UP)
        *vertical = -1;
    else if (
     (gameController->povHat[povHatNum] & MTR_POVHAT_DOWN) == MTR_POVHAT_DOWN)
        *vertical = 1;
    else
        *vertical = 0;
}

/*fa MTR_GameControllerGetButtonsCount yes */
MTR_DCLSPC int MTR_CALL MTR_GameControllerGetButtonsCount(int controllerNum)
{
    mtrGameController_t *gameController;
    MTR_GAME_CONTROLLER_CHECK_IF_NOT_INITED(0);

    gameController = IK_GET_DATA(mtrGameController_t *,
     mtrGameControllerKeeper, controllerNum);
    if (!MTR_IndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        return gameController->buttonsCount;
    else
        return 0;
}

/*fa MTR_GameControllerGetAxesCount yes */
MTR_DCLSPC int MTR_CALL MTR_GameControllerGetAxesCount(int controllerNum)
{
    mtrGameController_t *gameController;
    MTR_GAME_CONTROLLER_CHECK_IF_NOT_INITED(0);

    gameController = IK_GET_DATA(mtrGameController_t *,
     mtrGameControllerKeeper, controllerNum);
    if (!MTR_IndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        return gameController->axesCount;
    else
        return 0;
}

/*fa MTR_GameControllerGetTrackballsCount yes */
MTR_DCLSPC int MTR_CALL MTR_GameControllerGetTrackballsCount(int controllerNum)
{
    mtrGameController_t *gameController;
    MTR_GAME_CONTROLLER_CHECK_IF_NOT_INITED(0);

    gameController = IK_GET_DATA(mtrGameController_t *,
     mtrGameControllerKeeper, controllerNum);
    if (!MTR_IndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        return gameController->trackballsCount;
    else
        return 0;
}

/*fa MTR_GameControllerGetPowHatsCount yes */
MTR_DCLSPC int MTR_CALL MTR_GameControllerGetPowHatsCount(int controllerNum)
{
    mtrGameController_t *gameController;
    MTR_GAME_CONTROLLER_CHECK_IF_NOT_INITED(0);

    gameController = IK_GET_DATA(mtrGameController_t *,
     mtrGameControllerKeeper, controllerNum);
    if (!MTR_IndexkeeperIndexIsEmpty(mtrGameControllerKeeper, controllerNum))
        return gameController->povHatsCount;
    else
        return 0;
}
