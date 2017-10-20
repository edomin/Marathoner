#ifndef MTR_GAME_CONTROLLER_BINDING_COMMON_H
#define MTR_GAME_CONTROLLER_BINDING_COMMON_H

typedef int (MTR_CALL * MTR_GameControllerFunctionSupportedFunc)(const char *);
MTR_GameControllerFunctionSupportedFunc MTR_GameControllerFunctionSupported;

typedef bool (MTR_CALL * MTR_GameControllerInitFunc)(void);
MTR_GameControllerInitFunc MTR_GameControllerInit;

typedef void (MTR_CALL * MTR_GameControllerQuitFunc)(void);
MTR_GameControllerQuitFunc MTR_GameControllerQuit;

typedef void (MTR_CALL * MTR_GameControllerRefreshFunc)(void);
MTR_GameControllerRefreshFunc MTR_GameControllerRefresh;

typedef bool (MTR_CALL * MTR_GameControllerButtonPressFunc)(int, int);
MTR_GameControllerButtonPressFunc MTR_GameControllerButtonPress;

typedef bool (MTR_CALL * MTR_GameControllerButtonReleaseFunc)(int, int);
MTR_GameControllerButtonReleaseFunc MTR_GameControllerButtonRelease;

typedef bool (MTR_CALL * MTR_GameControllerButtonPressedFunc)(int, int);
MTR_GameControllerButtonPressedFunc MTR_GameControllerButtonPressed;

typedef int16_t (MTR_CALL * MTR_GameControllerGetAxisFunc)(int, int);
MTR_GameControllerGetAxisFunc MTR_GameControllerGetAxis;

typedef float (MTR_CALL * MTR_GameControllerGetAxis_fFunc)(int, int);
MTR_GameControllerGetAxis_fFunc MTR_GameControllerGetAxis_f;

typedef int (MTR_CALL * MTR_GameControllerGetAxisDeltaFunc)(int, int);
MTR_GameControllerGetAxisDeltaFunc MTR_GameControllerGetAxisDelta;

typedef float (MTR_CALL * MTR_GameControllerGetAxisDelta_fFunc)(int, int);
MTR_GameControllerGetAxisDelta_fFunc MTR_GameControllerGetAxisDelta_f;

typedef int (MTR_CALL * MTR_GameControllerGetTrackballDeltaXFunc)(int, int);
MTR_GameControllerGetTrackballDeltaXFunc MTR_GameControllerGetTrackballDeltaX;

typedef int (MTR_CALL * MTR_GameControllerGetTrackballDeltaYFunc)(int, int);
MTR_GameControllerGetTrackballDeltaYFunc MTR_GameControllerGetTrackballDeltaY;

#ifdef lua_h
typedef void (MTR_CALL * MTR_GameControllerGetTrackballDeltaXYFunc)(int, int,
 int *, int *);
MTR_GameControllerGetTrackballDeltaXYFunc MTR_GameControllerGetTrackballDeltaXY;
#endif

typedef uint8_t (MTR_CALL * MTR_GameControllerGetPovHatFunc)(int, int);
MTR_GameControllerGetPovHatFunc MTR_GameControllerGetPovHat;

typedef int (MTR_CALL * MTR_GameControllerGetPovHatHorizontalFunc)(int, int);
MTR_GameControllerGetPovHatHorizontalFunc MTR_GameControllerGetPovHatHorizontal;

typedef int (MTR_CALL * MTR_GameControllerGetPovHatVerticalFunc)(int, int);
MTR_GameControllerGetPovHatVerticalFunc MTR_GameControllerGetPovHatVertical;

typedef void (MTR_CALL * MTR_GameControllerGetPovHatAxesFunc)(int, int, int *,
 int *);
MTR_GameControllerGetPovHatAxesFunc MTR_GameControllerGetPovHatAxes;

typedef int (MTR_CALL * MTR_GameControllerGetButtonsCountFunc)(int);
MTR_GameControllerGetButtonsCountFunc MTR_GameControllerGetButtonsCount;

typedef int (MTR_CALL * MTR_GameControllerGetAxesCountFunc)(int);
MTR_GameControllerGetAxesCountFunc MTR_GameControllerGetAxesCount;

typedef int (MTR_CALL * MTR_GameControllerGetTrackballsCountFunc)(int);
MTR_GameControllerGetTrackballsCountFunc MTR_GameControllerGetTrackballsCount;

typedef int (MTR_CALL * MTR_GameControllerGetPowHatsCountFunc)(int);
MTR_GameControllerGetPowHatsCountFunc MTR_GameControllerGetPowHatsCount;

#endif
