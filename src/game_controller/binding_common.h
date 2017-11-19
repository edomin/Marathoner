#ifndef MTR_GAME_CONTROLLER_BINDING_COMMON_H
#define MTR_GAME_CONTROLLER_BINDING_COMMON_H

MTR_FUNC(int, MTR_GameControllerFunctionSupported, const char *);
MTR_FUNC(bool, MTR_GameControllerInit, void);
MTR_FUNC(void, MTR_GameControllerQuit, void);
MTR_FUNC(void, MTR_GameControllerRefresh, void);
MTR_FUNC(bool, MTR_GameControllerButtonPress, int, int);
MTR_FUNC(bool, MTR_GameControllerButtonRelease, int, int);
MTR_FUNC(bool, MTR_GameControllerButtonPressed, int, int);
MTR_FUNC(int16_t, MTR_GameControllerGetAxis, int, int);
MTR_FUNC(float, MTR_GameControllerGetAxis_f, int, int);
MTR_FUNC(int, MTR_GameControllerGetAxisDelta, int, int);
MTR_FUNC(float, MTR_GameControllerGetAxisDelta_f, int, int);
MTR_FUNC(int, MTR_GameControllerGetTrackballDeltaX, int, int);
MTR_FUNC(int, MTR_GameControllerGetTrackballDeltaY, int, int);
#ifdef lua_h
MTR_FUNC(void, MTR_GameControllerGetTrackballDeltaXY, int, int, int *, int *);
#endif
MTR_FUNC(uint8_t, MTR_GameControllerGetPovHat, int, int);
MTR_FUNC(int, MTR_GameControllerGetPovHatHorizontal, int, int);
MTR_FUNC(int, MTR_GameControllerGetPovHatVertical, int, int);
MTR_FUNC(void, MTR_GameControllerGetPovHatAxes, int, int, int *, int *);
MTR_FUNC(int, MTR_GameControllerGetButtonsCount, int);
MTR_FUNC(int, MTR_GameControllerGetAxesCount, int);
MTR_FUNC(int, MTR_GameControllerGetTrackballsCount, int);
MTR_FUNC(int, MTR_GameControllerGetPowHatsCount, int);

#endif
