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

MTR_EXPORT bool MTR_CALL mtrGameControllerInit(void)
{
    SDL_version compiled;
    SDL_version linked;
    int         i;
    int         j;
    bool        ok;

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

    if(SDL_WasInit(SDL_INIT_EVENTS) == 0)
        if (SDL_InitSubSystem(SDL_INIT_EVENTS) == 0)
            mtrLogWrite("SDL events subsystem initialized", 1, MTR_LMT_INFO);
        else
        {
             mtrNotify("Unable to initialize SDL events subsystem", 1,
              MTR_LMT_ERROR);
              return false;
        }
    else
        mtrLogWrite("SDL events subsystem already initialized", 1,
         MTR_LMT_INFO);

    if(SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
        if (SDL_InitSubSystem(SDL_INIT_JOYSTICK) == 0)
            mtrLogWrite("SDL joystick subsystem initialized", 1, MTR_LMT_INFO);
        else
        {
             mtrNotify("Unable to initialize SDL joystick subsystem", 1,
              MTR_LMT_ERROR);
              return false;
        }
    else
        mtrLogWrite("SDL joystick subsystem already initialized", 1,
         MTR_LMT_INFO);

    mtrGameControllersCount = SDL_NumJoysticks();
    if(mtrGameControllersCount < 1)
        mtrLogWrite("Connected controllers not found", 1, MTR_LMT_INFO);

    for (i = 0; i < mtrGameControllersCount; i++)
    {
        mtrLogWrite_s("Controller found:", 1, MTR_LMT_INFO,
         (char *)SDL_JoystickNameForIndex(i));
    }
    if (mtrGameControllersCount > 0)
    {
        mtrGameController = malloc(sizeof(mtrGameController_t) * mtrGameControllersCount);
        if (mtrGameController == NULL)
        {
            mtrNotify("Unable to allocate memory for game controllers' structures",
             1, MTR_LMT_ERROR);
            return false;
        }
    }
    for(i = 0; i < mtrGameControllersCount; i++)
    {
        mtrGameController[i].gameController = SDL_JoystickOpen(i);
        if(mtrGameController[i].gameController == NULL)
        {
            mtrLogWrite_i("Unable to open controller for use", 1,
             MTR_LMT_WARNING, i);
            mtrGameController[i].buttonsCount = 0;
            mtrGameController[i].axesCount = 0;
            mtrGameController[i].trackballsCount = 0;
            mtrGameController[i].povHatsCount = 0;
            continue;
        }
        mtrLogWrite_i("Initialising controller:", 1, MTR_LMT_INFO, i);

        mtrGameController[i].buttonsCount = SDL_JoystickNumButtons(mtrGameController[i].gameController);
        mtrGameController[i].axesCount = SDL_JoystickNumAxes(mtrGameController[i].gameController);
        mtrGameController[i].trackballsCount = SDL_JoystickNumBalls(mtrGameController[i].gameController);
        mtrGameController[i].povHatsCount = SDL_JoystickNumHats(mtrGameController[i].gameController);

        mtrLogWrite_i("Buttons found:", 2, MTR_LMT_INFO,
         mtrGameController[i].buttonsCount);
        mtrLogWrite_i("Axes found:", 2, MTR_LMT_INFO,
         mtrGameController[i].axesCount);
        mtrLogWrite_i("Trackballs found:", 2, MTR_LMT_INFO,
         mtrGameController[i].trackballsCount);
        mtrLogWrite_i("POV hats found:", 2, MTR_LMT_INFO,
         mtrGameController[i].povHatsCount);

        if (mtrGameController[i].buttonsCount > 0)
        {
            ok = true;
            mtrGameController[i].currentButtonState = malloc(sizeof(bool *) * mtrGameController[i].buttonsCount);
            if (mtrGameController[i].currentButtonState == NULL)
            {
                mtrLogWrite_i("Unable to allocate memory for current buttons' state of controller",
                 2, MTR_LMT_WARNING, i);
                ok = false;
            }
            if (ok)
            {
                mtrGameController[i].previousButtonState = malloc(sizeof(bool *) * mtrGameController[i].buttonsCount);
                if (mtrGameController[i].previousButtonState == NULL)
                {
                    mtrLogWrite_i("Unable to allocate memory for previous buttons' state of controller",
                     2, MTR_LMT_WARNING, i);
                    ok = false;
                    free(mtrGameController[i].currentButtonState);
                }
            }

            if (!ok)
                mtrGameController[i].buttonsCount = 0;
        }

        if (mtrGameController[i].axesCount > 0)
        {
            ok = true;
            mtrGameController[i].currentAxis = malloc(sizeof(int16_t *) * mtrGameController[i].axesCount);
            if (mtrGameController[i].currentAxis == NULL)
            {
                mtrLogWrite_i("Unable to allocate memory for current axes' state of controller",
                 2, MTR_LMT_WARNING, i);
                ok = false;
            }
            if (ok)
            {
                mtrGameController[i].previousAxis = malloc(sizeof(int16_t *) * mtrGameController[i].axesCount);
                if (mtrGameController[i].previousAxis == NULL)
                {
                    mtrLogWrite_i("Unable to allocate memory for previous axes' state of controller",
                     2, MTR_LMT_WARNING, i);
                    ok = false;
                    free(mtrGameController[i].currentAxis);
                }
            }

            if (!ok)
                mtrGameController[i].axesCount = 0;
        }

        if (mtrGameController[i].trackballsCount > 0)
        {
            mtrGameController[i].trackballDelta = malloc(sizeof(mtrTrackballDelta_t *) * mtrGameController[i].trackballsCount);
            if (mtrGameController[i].trackballDelta == NULL)
            {
                mtrLogWrite_i("Unable to allocate memory for trackballs' state of controller",
                 2, MTR_LMT_WARNING, i);
                mtrGameController[i].trackballsCount = 0;
            }
        }

        if (mtrGameController[i].povHatsCount > 0)
        {
            mtrGameController[i].povHat = malloc(sizeof(uint8_t *) * mtrGameController[i].povHatsCount);
            if (mtrGameController[i].povHat == NULL)
            {
                mtrLogWrite_i("Unable to allocate memory for current POV hats' state of controller",
                 2, MTR_LMT_WARNING, i);
                mtrGameController[i].povHatsCount = 0;
            }
        }

        for (j = 0; j < mtrGameController[i].buttonsCount; j++)
        {
            mtrGameController[i].currentButtonState[j] = false;
            mtrGameController[i].previousButtonState[j] = false;
        }
        for (j = 0; j < mtrGameController[i].axesCount; j++)
        {
            mtrGameController[i].currentAxis[j] = 0;
            mtrGameController[i].previousAxis[j] = 0;
        }
        for (j = 0; j < mtrGameController[i].trackballsCount; j++)
        {
            mtrGameController[i].trackballDelta[j].dx = 0;
            mtrGameController[i].trackballDelta[j].dy = 0;
        }
        for (j = 0; j < mtrGameController[i].povHatsCount; j++)
            mtrGameController[i].povHat[j] = 0;

        mtrLogWrite("Controller initialised:", 1, MTR_LMT_INFO);
    }

    mtrLogWrite("Game Controller support initialized", 0, MTR_LMT_INFO);
    return true;
}

MTR_EXPORT void MTR_CALL mtrGameControllerQuit(void)
{
    uint8_t i;
    mtrLogWrite("Disabling game controller support", 0, MTR_LMT_INFO);
    for (i = 0; i < mtrGameControllersCount; i++)
    {
        SDL_JoystickClose(mtrGameController[i].gameController);
        if (mtrGameController[i].buttonsCount > 0)
        {
            free(mtrGameController[i].currentButtonState);
            free(mtrGameController[i].previousButtonState);
        }
        if (mtrGameController[i].axesCount > 0)
        {
            free(mtrGameController[i].currentAxis);
            free(mtrGameController[i].previousAxis);
        }
        if (mtrGameController[i].trackballsCount > 0)
        {
            free(mtrGameController[i].trackballDelta);
        }
        if (mtrGameController[i].povHatsCount > 0)
        {
            free(mtrGameController[i].povHat);
        }
        free(mtrGameController);
    }
    mtrLogWrite("Game controller support disabled", 0, MTR_LMT_INFO);
}

MTR_EXPORT void MTR_CALL mtrGameControllerRefresh(void)
{
    int i;
    int j;
    SDL_JoystickUpdate();
    for (i = 0; i < mtrGameControllersCount; i++)
    {
        for (j = 0; j < mtrGameController[i].buttonsCount; j++)
        {
            mtrGameController[i].previousButtonState[j] = mtrGameController[i].currentButtonState[j];
            if (SDL_JoystickGetButton(mtrGameController[i].gameController, j) == 1)
            {
                mtrGameController[i].currentButtonState[j] = true;
            }
            else
            {
                mtrGameController[i].currentButtonState[j] = false;
            }
        }
        for (j = 0; j < mtrGameController[i].axesCount; j++)
        {
            mtrGameController[i].previousAxis[j] = mtrGameController[i].currentAxis[j];
            mtrGameController[i].currentAxis[j] = SDL_JoystickGetAxis(mtrGameController[i].gameController, j);
        }
        for (j = 0; j < mtrGameController[i].trackballsCount; j++)
            SDL_JoystickGetBall(mtrGameController[i].gameController, j,
             &mtrGameController[i].trackballDelta[j].dx,
             &mtrGameController[i].trackballDelta[j].dy);
        for (j = 0; j < mtrGameController[i].povHatsCount; j++)
        {
            mtrGameController[i].povHat[j] = SDL_JoystickGetHat(mtrGameController[i].gameController, j);
        }
    }
}

MTR_EXPORT bool MTR_CALL mtrGameControllerButtonPress(int controllerNum,
 int button)
{
    if (mtrGameControllersCount > controllerNum)
        if (button < mtrGameController[controllerNum].buttonsCount)
            if ((mtrGameController[controllerNum].currentButtonState[button]) &&
             !(mtrGameController[controllerNum].previousButtonState[button]))
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
    if (mtrGameControllersCount > controllerNum)
        if (button < mtrGameController[controllerNum].buttonsCount)
            if (!(mtrGameController[controllerNum].currentButtonState[button]) &&
             (mtrGameController[controllerNum].previousButtonState[button]))
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
    if (mtrGameControllersCount > controllerNum)
        if (button < mtrGameController[controllerNum].buttonsCount)
            return mtrGameController[controllerNum].currentButtonState[button];
        else
            return false;
    else
        return false;
}

MTR_EXPORT int16_t MTR_CALL mtrGameControllerGetAxis(int controllerNum,
 int axisNum)
{
    if (mtrGameControllersCount > controllerNum)
        if (axisNum < mtrGameController[controllerNum].axesCount)
            return mtrGameController[controllerNum].currentAxis[axisNum];
        else
            return 0;
    else
        return 0;
}

MTR_EXPORT float MTR_CALL mtrGameControllerGetAxis_f(int controllerNum,
 int axisNum)
{
    if (mtrGameControllersCount > controllerNum)
        if (axisNum < mtrGameController[controllerNum].axesCount)
            if (mtrGameController[controllerNum].currentAxis[axisNum] > 0)
                return ((float)mtrGameController[controllerNum].currentAxis[axisNum] / (float)(INT16_MAX));
            else
                return ((float)mtrGameController[controllerNum].currentAxis[axisNum] / (float)(-INT16_MIN));
        else
            return 0.0f;
    else
        return 0.0f;
}

MTR_EXPORT int MTR_CALL mtrGameControllerGetAxisDelta(int controllerNum,
 int axisNum)
{
    if (mtrGameControllersCount > controllerNum)
        if (axisNum < mtrGameController[controllerNum].axesCount)
            return mtrGameController[controllerNum].currentAxis[axisNum] -
             mtrGameController[controllerNum].previousAxis[axisNum];
        else
            return 0;
    else
        return 0;
}

MTR_EXPORT float MTR_CALL mtrGameControllerGetAxisDelta_f(int controllerNum,
 int axisNum)
{
    if (mtrGameControllersCount > controllerNum)
        if (axisNum < mtrGameController[controllerNum].axesCount)
            return (float)(mtrGameController[controllerNum].currentAxis[axisNum] -
             mtrGameController[controllerNum].previousAxis[axisNum]) / (float)(INT16_MAX);
        else
            return 0.0f;
    else
        return 0.0f;
}

MTR_EXPORT int MTR_CALL mtrGameControllerGetTrackballDeltaX(int controllerNum,
 int trackballNum)
{
    if (mtrGameControllersCount > controllerNum)
        if (trackballNum < mtrGameController[controllerNum].trackballsCount)
            return mtrGameController[controllerNum].trackballDelta[trackballNum].dx;
        else
            return 0;
    else
        return 0;
}

MTR_EXPORT int MTR_CALL mtrGameControllerGetTrackballDeltaY(int controllerNum,
 int trackballNum)
{
    if (mtrGameControllersCount > controllerNum)
        if (trackballNum < mtrGameController[controllerNum].trackballsCount)
            return mtrGameController[controllerNum].trackballDelta[trackballNum].dy;
        else
            return 0;
    else
        return 0;
}

MTR_EXPORT void MTR_CALL mtrGameControllerGetTrackballDeltaXY(int controllerNum,
 int trackballNum, int *deltaX, int *deltaY)
{
    if (mtrGameControllersCount > controllerNum)
        if (trackballNum < mtrGameController[controllerNum].trackballsCount)
        {
            *deltaX = mtrGameController[controllerNum].trackballDelta[trackballNum].dx;
            *deltaY = mtrGameController[controllerNum].trackballDelta[trackballNum].dy;
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
    if (mtrGameControllersCount > controllerNum)
        if (povHatNum < mtrGameController[controllerNum].povHatsCount)
            return mtrGameController[controllerNum].povHat[povHatNum];
        else
            return 0;
    else
        return 0;
}
