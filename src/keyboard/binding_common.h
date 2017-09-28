#ifndef MTR_KEYBOARD_BINDING_COMMON_H
#define MTR_KEYBOARD_BINDING_COMMON_H

typedef int (MTR_CALL * mtrKeyboardFunctionSupportedFunc)(const char *);
mtrKeyboardFunctionSupportedFunc mtrKeyboardFunctionSupported;

typedef bool (MTR_CALL * mtrKeyboardInitFunc)(void);
mtrKeyboardInitFunc mtrKeyboardInit;

typedef void (MTR_CALL * mtrKeyboardRefreshFunc)(void);
mtrKeyboardRefreshFunc mtrKeyboardRefresh;

typedef bool (MTR_CALL * mtrKeyboardPressFunc)(int);
mtrKeyboardPressFunc mtrKeyboardPress;

typedef bool (MTR_CALL * mtrKeyboardReleaseFunc)(int);
mtrKeyboardReleaseFunc mtrKeyboardRelease;

typedef bool (MTR_CALL * mtrKeyboardPressedFunc)(int);
mtrKeyboardPressedFunc mtrKeyboardPressed;

typedef char *(MTR_CALL * mtrKeyboardInputCharFunc)(void);
mtrKeyboardInputCharFunc mtrKeyboardInputChar;

#endif
