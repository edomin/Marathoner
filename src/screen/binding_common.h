#ifndef MTR_SCREEN_BINDING_COMMON_H
#define MTR_SCREEN_BINDING_COMMON_H

MTR_FUNC(int, MTR_ScreenFunctionSupported, const char *);
MTR_FUNC(bool, MTR_ScreenInit, int, int, bool, const char *);
MTR_FUNC(void, MTR_ScreenQuit, void);
MTR_FUNC(void, MTR_ScreenFlip, void);
#ifdef lua_h
MTR_FUNC(void, MTR_ScreenGetSizes, int *, int *);
#endif
MTR_FUNC(int, MTR_ScreenGetWidth, void);
MTR_FUNC(int, MTR_ScreenGetHeight, void);
MTR_FUNC(bool, MTR_ScreenXed, void);
MTR_FUNC(int, MTR_ScreenGetDesktopWidth, void);
MTR_FUNC(int, MTR_ScreenGetDesktopHeight, void);
MTR_FUNC(void, MTR_ScreenGetDesktopSizes, int *, int *);

#endif
