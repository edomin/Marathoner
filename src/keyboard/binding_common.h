#ifndef MTR_KEYBOARD_BINDING_COMMON_H
#define MTR_KEYBOARD_BINDING_COMMON_H

MTR_FUNC(int, MTR_KeyboardFunctionSupported, const char *);
MTR_FUNC(bool, MTR_KeyboardInit, void);
MTR_FUNC(void, MTR_KeyboardRefresh, void);
MTR_FUNC(bool, MTR_KeyboardPress, int);
MTR_FUNC(bool, MTR_KeyboardRelease, int);
MTR_FUNC(bool, MTR_KeyboardPressed, int);
#ifdef lua_h
MTR_FUNC(void, MTR_KeyboardArrowsGetAxes, int, int, int, int, int *, int *);
#endif
MTR_FUNC(int, MTR_KeyboardArrowsGetHorAxis, int, int);
MTR_FUNC(int, MTR_KeyboardArrowsGetVerAxis, int, int);
MTR_FUNC(char *, MTR_KeyboardInputChar, void);

#endif
