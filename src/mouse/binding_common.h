#ifndef MTR_MOUSE_BINDING_COMMON_H
#define MTR_MOUSE_BINDING_COMMON_H

typedef bool (MTR_CALL * mtrMouseInitFunc)(void);
mtrMouseInitFunc mtrMouseInit;

typedef void (MTR_CALL * mtrMouseRefreshFunc)(void);
mtrMouseRefreshFunc mtrMouseRefresh;

typedef bool (MTR_CALL * mtrMousePressFunc)(int);
mtrMousePressFunc mtrMousePress;

typedef bool (MTR_CALL * mtrMouseReleaseFunc)(int);
mtrMouseReleaseFunc mtrMouseRelease;

typedef bool (MTR_CALL * mtrMousePressedFunc)(int);
mtrMousePressedFunc mtrMousePressed;

typedef int (MTR_CALL * mtrMouseGetWheelRelativeFunc)(void);
mtrMouseGetWheelRelativeFunc mtrMouseGetWheelRelative;

typedef bool (MTR_CALL * mtrMouseMovingFunc)(void);
mtrMouseMovingFunc mtrMouseMoving;

typedef int (MTR_CALL * mtrMouseGetXFunc)(void);
mtrMouseGetXFunc mtrMouseGetX;

typedef int (MTR_CALL * mtrMouseGetYFunc)(void);
mtrMouseGetYFunc mtrMouseGetY;

#ifdef lua_h
typedef void (MTR_CALL * mtrMouseGetXYFunc)(int *, int *);
mtrMouseGetXYFunc mtrMouseGetXY;
#endif

typedef int (MTR_CALL * mtrMouseGetDeltaXFunc)(void);
mtrMouseGetDeltaXFunc mtrMouseGetDeltaX;

typedef int (MTR_CALL * mtrMouseGetDeltaYFunc)(void);
mtrMouseGetDeltaYFunc mtrMouseGetDeltaY;

#ifdef lua_h
typedef void (MTR_CALL * mtrMouseGetDeltaXYFunc)(int *, int *);
mtrMouseGetDeltaXYFunc mtrMouseGetDeltaXY;
#endif

#endif
