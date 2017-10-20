#ifndef MTR_TIMER_BINDING_COMMON_H
#define MTR_TIMER_BINDING_COMMON_H

typedef int (MTR_CALL * MTR_TimerFunctionSupportedFunc)(const char *);
MTR_TimerFunctionSupportedFunc MTR_TimerFunctionSupported;

typedef bool (MTR_CALL * MTR_TimerInitFunc)(void);
MTR_TimerInitFunc MTR_TimerInit;

typedef void (MTR_CALL * MTR_TimerStartFunc)(void);
MTR_TimerStartFunc MTR_TimerStart;

typedef int (MTR_CALL * MTR_TimerDelayFunc)(int);
MTR_TimerDelayFunc MTR_TimerDelay;

typedef int (MTR_CALL * MTR_TimerDelayForFPSFunc)(int);
MTR_TimerDelayForFPSFunc MTR_TimerDelayForFPS;

typedef float (MTR_CALL * MTR_TimerDelayForFPS_fFunc)(float);
MTR_TimerDelayForFPS_fFunc MTR_TimerDelayForFPS_f;

#endif
