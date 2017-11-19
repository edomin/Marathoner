#ifndef MTR_TIMER_BINDING_COMMON_H
#define MTR_TIMER_BINDING_COMMON_H

MTR_FUNC(int, MTR_TimerFunctionSupported, const char *);
MTR_FUNC(bool, MTR_TimerInit, void);
MTR_FUNC(void, MTR_TimerStart, void);
MTR_FUNC(int, MTR_TimerDelay, int);
MTR_FUNC(int, MTR_TimerDelayForFPS, int);
MTR_FUNC(float, MTR_TimerDelayForFPS_f, float);

#endif
