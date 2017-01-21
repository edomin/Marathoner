#ifndef MTR_TIMER_BINDING_COMMON_H
#define MTR_TIMER_BINDING_COMMON_H

typedef bool (MTR_CALL * mtrTimerInitFunc)(void);
mtrTimerInitFunc mtrTimerInit;

typedef void (MTR_CALL * mtrTimerStartFunc)(void);
mtrTimerStartFunc mtrTimerStart;

typedef int (MTR_CALL * mtrTimerDelayFunc)(int);
mtrTimerDelayFunc mtrTimerDelay;

typedef int (MTR_CALL * mtrTimerDelayForFPSFunc)(int);
mtrTimerDelayForFPSFunc mtrTimerDelayForFPS;

typedef float (MTR_CALL * mtrTimerDelayForFPS_fFunc)(float);
mtrTimerDelayForFPS_fFunc mtrTimerDelayForFPS_f;

#endif
