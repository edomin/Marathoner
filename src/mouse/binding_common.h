#ifndef MTR_MOUSE_BINDING_COMMON_H
#define MTR_MOUSE_BINDING_COMMON_H

MTR_FUNC(int, MTR_MouseFunctionSupported, const char *);
MTR_FUNC(bool, MTR_MouseInit, void);
MTR_FUNC(void, MTR_MouseRefresh, void);
MTR_FUNC(bool, MTR_MousePress, int);
MTR_FUNC(bool, MTR_MouseRelease, int);
MTR_FUNC(bool, MTR_MousePressed, int);
MTR_FUNC(int, MTR_MouseGetWheelRelative, void);
MTR_FUNC(bool, MTR_MouseMoving, void);
MTR_FUNC(int, MTR_MouseGetX, void);
MTR_FUNC(int, MTR_MouseGetY, void);
#ifdef lua_h
MTR_FUNC(void, MTR_MouseGetXY, int *, int *);
#endif
MTR_FUNC(int, MTR_MouseGetDeltaX, void);
MTR_FUNC(int, MTR_MouseGetDeltaY, void);
#ifdef lua_h
MTR_FUNC(void, MTR_MouseGetDeltaXY, int *, int *);
#endif

#endif
