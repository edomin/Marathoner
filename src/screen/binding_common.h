#ifndef MTR_SCREEN_BINDING_COMMON_H
#define MTR_SCREEN_BINDING_COMMON_H

typedef bool (MTR_CALL * mtrScreenInitFunc)(int, int, bool, const char *);
mtrScreenInitFunc mtrScreenInit;

typedef void (MTR_CALL * mtrScreenQuitFunc)(void);
mtrScreenQuitFunc mtrScreenQuit;

typedef void (MTR_CALL * mtrScreenFlipFunc)(void);
mtrScreenFlipFunc mtrScreenFlip;

#ifdef lua_h
typedef void (MTR_CALL * mtrScreenGetSizesFunc)(int *, int *);
mtrScreenGetSizesFunc mtrScreenGetSizes;
#endif

typedef int (MTR_CALL * mtrScreenGetWidthFunc)(void);
mtrScreenGetWidthFunc mtrScreenGetWidth;

typedef int (MTR_CALL * mtrScreenGetHeightFunc)(void);
mtrScreenGetHeightFunc mtrScreenGetHeight;

typedef bool (MTR_CALL * mtrScreenXedFunc)(void);
mtrScreenXedFunc mtrScreenXed;

#endif
