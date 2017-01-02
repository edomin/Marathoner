#ifndef MTR_GAME_CONTROLLER_BINDING_COMMON
#define MTR_GAME_CONTROLLER_BINDING_COMMON

typedef bool (MTR_CALL * mtrGameControllerInitFunc)(void);
mtrGameControllerInitFunc mtrGameControllerInit;

typedef void (MTR_CALL * mtrGameControllerQuitFunc)(void);
mtrGameControllerQuitFunc mtrGameControllerQuit;

typedef void (MTR_CALL * mtrGameControllerRefreshFunc)(void);
mtrGameControllerRefreshFunc mtrGameControllerRefresh;

typedef bool (MTR_CALL * mtrGameControllerButtonPressFunc)(int, int);
mtrGameControllerButtonPressFunc mtrGameControllerButtonPress;

typedef bool (MTR_CALL * mtrGameControllerButtonReleaseFunc)(int, int);
mtrGameControllerButtonReleaseFunc mtrGameControllerButtonRelease;

typedef bool (MTR_CALL * mtrGameControllerButtonPressedFunc)(int, int);
mtrGameControllerButtonPressedFunc mtrGameControllerButtonPressed;

typedef int16_t (MTR_CALL * mtrGameControllerGetAxisFunc)(int, int);
mtrGameControllerGetAxisFunc mtrGameControllerGetAxis;

typedef float (MTR_CALL * mtrGameControllerGetAxis_fFunc)(int, int);
mtrGameControllerGetAxis_fFunc mtrGameControllerGetAxis_f;

typedef int (MTR_CALL * mtrGameControllerGetAxisDeltaFunc)(int, int);
mtrGameControllerGetAxisDeltaFunc mtrGameControllerGetAxisDelta;

typedef float (MTR_CALL * mtrGameControllerGetAxisDelta_fFunc)(int, int);
mtrGameControllerGetAxisDelta_fFunc mtrGameControllerGetAxisDelta_f;

typedef int (MTR_CALL * mtrGameControllerGetTrackballDeltaXFunc)(int, int);
mtrGameControllerGetTrackballDeltaXFunc mtrGameControllerGetTrackballDeltaX;

typedef int (MTR_CALL * mtrGameControllerGetTrackballDeltaYFunc)(int, int);
mtrGameControllerGetTrackballDeltaYFunc mtrGameControllerGetTrackballDeltaY;

typedef void (MTR_CALL * mtrGameControllerGetTrackballDeltaXYFunc)(int, int,
 int *, int *);
mtrGameControllerGetTrackballDeltaXYFunc mtrGameControllerGetTrackballDeltaXY;

typedef uint8_t (MTR_CALL * mtrGameControllerGetPovHatFunc)(int, int);
mtrGameControllerGetPovHatFunc mtrGameControllerGetPovHat;

#endif
