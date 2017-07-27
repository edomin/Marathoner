#ifndef MTR_SCREEN_BINDING_COMMON_H
#define MTR_SCREEN_BINDING_COMMON_H

typedef bool (MTR_CALL * mtrScreenInitFunc)(int, int, bool, const char *);
mtrScreenInitFunc mtrScreenInit;

typedef void (MTR_CALL * mtrScreenQuitFunc)(void);
mtrScreenQuitFunc mtrScreenQuit;

typedef void (MTR_CALL * mtrScreenFlipFunc)(void);
mtrScreenFlipFunc mtrScreenFlip;

#endif
