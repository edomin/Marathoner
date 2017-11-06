#ifndef MTR_KEYBOARD_BINDING_COMMON_H
#define MTR_KEYBOARD_BINDING_COMMON_H

typedef int (MTR_CALL * MTR_KeyboardFunctionSupportedFunc)(const char *);
MTR_KeyboardFunctionSupportedFunc MTR_KeyboardFunctionSupported;

typedef bool (MTR_CALL * MTR_KeyboardInitFunc)(void);
MTR_KeyboardInitFunc MTR_KeyboardInit;

typedef void (MTR_CALL * MTR_KeyboardRefreshFunc)(void);
MTR_KeyboardRefreshFunc MTR_KeyboardRefresh;

typedef bool (MTR_CALL * MTR_KeyboardPressFunc)(int);
MTR_KeyboardPressFunc MTR_KeyboardPress;

typedef bool (MTR_CALL * MTR_KeyboardReleaseFunc)(int);
MTR_KeyboardReleaseFunc MTR_KeyboardRelease;

typedef bool (MTR_CALL * MTR_KeyboardPressedFunc)(int);
MTR_KeyboardPressedFunc MTR_KeyboardPressed;

#ifdef lua_h
typedef void (MTR_CALL * MTR_KeyboardArrowsGetAxesFunc)(int, int, int, int,
 int *, int *);
MTR_KeyboardArrowsGetAxesFunc MTR_KeyboardArrowsGetAxes;
#endif

typedef int (MTR_CALL * MTR_KeyboardArrowsGetHorAxisFunc)(int, int);
MTR_KeyboardArrowsGetHorAxisFunc MTR_KeyboardArrowsGetHorAxis;

typedef int (MTR_CALL * MTR_KeyboardArrowsGetVerAxisFunc)(int, int);
MTR_KeyboardArrowsGetVerAxisFunc MTR_KeyboardArrowsGetVerAxis;

typedef char *(MTR_CALL * MTR_KeyboardInputCharFunc)(void);
MTR_KeyboardInputCharFunc MTR_KeyboardInputChar;

#endif
