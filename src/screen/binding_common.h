#ifndef MTR_SCREEN_BINDING_COMMON
#define MTR_SCREEN_BINDING_COMMON

typedef bool (MTR_CALL * mtrScreenInitFunc)(int, int);
mtrScreenInitFunc mtrScreenInit;

typedef void (MTR_CALL * mtrScreenQuitFunc)(void);
mtrScreenQuitFunc mtrScreenQuit;

typedef void (MTR_CALL * mtrScreenFlipFunc)(void);
mtrScreenFlipFunc mtrScreenFlip;

#endif
