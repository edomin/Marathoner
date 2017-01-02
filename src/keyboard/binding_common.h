#ifndef MTR_GAME_CONTROLLER_BINDING_COMMON
#define MTR_GAME_CONTROLLER_BINDING_COMMON

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

#endif
