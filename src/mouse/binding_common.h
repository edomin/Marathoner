#ifndef MTR_MOUSE_BINDING_COMMON_H
#define MTR_MOUSE_BINDING_COMMON_H

typedef int (MTR_CALL * MTR_MouseFunctionSupportedFunc)(const char *);
MTR_MouseFunctionSupportedFunc MTR_MouseFunctionSupported;

typedef bool (MTR_CALL * MTR_MouseInitFunc)(void);
MTR_MouseInitFunc MTR_MouseInit;

typedef void (MTR_CALL * MTR_MouseRefreshFunc)(void);
MTR_MouseRefreshFunc MTR_MouseRefresh;

typedef bool (MTR_CALL * MTR_MousePressFunc)(int);
MTR_MousePressFunc MTR_MousePress;

typedef bool (MTR_CALL * MTR_MouseReleaseFunc)(int);
MTR_MouseReleaseFunc MTR_MouseRelease;

typedef bool (MTR_CALL * MTR_MousePressedFunc)(int);
MTR_MousePressedFunc MTR_MousePressed;

typedef int (MTR_CALL * MTR_MouseGetWheelRelativeFunc)(void);
MTR_MouseGetWheelRelativeFunc MTR_MouseGetWheelRelative;

typedef bool (MTR_CALL * MTR_MouseMovingFunc)(void);
MTR_MouseMovingFunc MTR_MouseMoving;

typedef int (MTR_CALL * MTR_MouseGetXFunc)(void);
MTR_MouseGetXFunc MTR_MouseGetX;

typedef int (MTR_CALL * MTR_MouseGetYFunc)(void);
MTR_MouseGetYFunc MTR_MouseGetY;

#ifdef lua_h
typedef void (MTR_CALL * MTR_MouseGetXYFunc)(int *, int *);
MTR_MouseGetXYFunc MTR_MouseGetXY;
#endif

typedef int (MTR_CALL * MTR_MouseGetDeltaXFunc)(void);
MTR_MouseGetDeltaXFunc MTR_MouseGetDeltaX;

typedef int (MTR_CALL * MTR_MouseGetDeltaYFunc)(void);
MTR_MouseGetDeltaYFunc MTR_MouseGetDeltaY;

#ifdef lua_h
typedef void (MTR_CALL * MTR_MouseGetDeltaXYFunc)(int *, int *);
MTR_MouseGetDeltaXYFunc MTR_MouseGetDeltaXY;
#endif

#endif
