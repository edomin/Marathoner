#ifndef MTR_SCREEN_BINDING_COMMON_H
#define MTR_SCREEN_BINDING_COMMON_H

typedef int (MTR_CALL * MTR_ScreenFunctionSupportedFunc)(const char *);
MTR_ScreenFunctionSupportedFunc MTR_ScreenFunctionSupported;

typedef bool (MTR_CALL * MTR_ScreenInitFunc)(int, int, bool, const char *);
MTR_ScreenInitFunc MTR_ScreenInit;

typedef void (MTR_CALL * MTR_ScreenQuitFunc)(void);
MTR_ScreenQuitFunc MTR_ScreenQuit;

typedef void (MTR_CALL * MTR_ScreenFlipFunc)(void);
MTR_ScreenFlipFunc MTR_ScreenFlip;

#ifdef lua_h
typedef void (MTR_CALL * MTR_ScreenGetSizesFunc)(int *, int *);
MTR_ScreenGetSizesFunc MTR_ScreenGetSizes;
#endif

typedef int (MTR_CALL * MTR_ScreenGetWidthFunc)(void);
MTR_ScreenGetWidthFunc MTR_ScreenGetWidth;

typedef int (MTR_CALL * MTR_ScreenGetHeightFunc)(void);
MTR_ScreenGetHeightFunc MTR_ScreenGetHeight;

typedef bool (MTR_CALL * MTR_ScreenXedFunc)(void);
MTR_ScreenXedFunc MTR_ScreenXed;

#endif
