#ifndef MTR_UTILS_MATH_BINDING_COMMON_H
#define MTR_UTILS_MATH_BINDING_COMMON_H

typedef int (MTR_CALL * MTR_MathFunctionSupportedFunc)(const char *);
MTR_MathFunctionSupportedFunc MTR_MathFunctionSupported;

typedef float (MTR_CALL * MTR_Sin_fFunc)(float);
MTR_Sin_fFunc MTR_Sin_f;

typedef double (MTR_CALL * MTR_Sin_dFunc)(double);
MTR_Sin_dFunc MTR_Sin_d;

typedef float (MTR_CALL * MTR_SinFast_fFunc)(float);
MTR_SinFast_fFunc MTR_SinFast_f;

typedef double (MTR_CALL * MTR_SinFast_dFunc)(double);
MTR_SinFast_dFunc MTR_SinFast_d;

typedef float (MTR_CALL * MTR_Cos_fFunc)(float);
MTR_Cos_fFunc MTR_Cos_f;

typedef double (MTR_CALL * MTR_Cos_dFunc)(double);
MTR_Cos_dFunc MTR_Cos_d;

typedef float (MTR_CALL * MTR_CosFast_fFunc)(float);
MTR_CosFast_fFunc MTR_CosFast_f;

typedef double (MTR_CALL * MTR_CosFast_dFunc)(double);
MTR_CosFast_dFunc MTR_CosFast_d;

typedef float (MTR_CALL * MTR_Tan_fFunc)(float);
MTR_Tan_fFunc MTR_Tan_f;

typedef double (MTR_CALL * MTR_Tan_dFunc)(double);
MTR_Tan_dFunc MTR_Tan_d;

typedef float (MTR_CALL * MTR_TanFast_fFunc)(float);
MTR_TanFast_fFunc MTR_TanFast_f;

typedef double (MTR_CALL * MTR_TanFast_dFunc)(double);
MTR_TanFast_dFunc MTR_TanFast_d;

typedef float (MTR_CALL * MTR_Asin_fFunc)(float);
MTR_Asin_fFunc MTR_Asin_f;

typedef double (MTR_CALL * MTR_Asin_dFunc)(double);
MTR_Asin_dFunc MTR_Asin_d;

typedef float (MTR_CALL * MTR_AsinFast_fFunc)(float);
MTR_AsinFast_fFunc MTR_AsinFast_f;

typedef double (MTR_CALL * MTR_AsinFast_dFunc)(double);
MTR_AsinFast_dFunc MTR_AsinFast_d;

typedef float (MTR_CALL * MTR_Acos_fFunc)(float);
MTR_Acos_fFunc MTR_Acos_f;

typedef double (MTR_CALL * MTR_Acos_dFunc)(double);
MTR_Acos_dFunc MTR_Acos_d;

typedef float (MTR_CALL * MTR_AcosFast_fFunc)(float);
MTR_AcosFast_fFunc MTR_AcosFast_f;

typedef double (MTR_CALL * MTR_AcosFast_dFunc)(double);
MTR_AcosFast_dFunc MTR_AcosFast_d;

typedef float (MTR_CALL * MTR_Atan_fFunc)(float);
MTR_Atan_fFunc MTR_Atan_f;

typedef double (MTR_CALL * MTR_Atan_dFunc)(double);
MTR_Atan_dFunc MTR_Atan_d;

typedef float (MTR_CALL * MTR_AtanFast_fFunc)(float);
MTR_AtanFast_fFunc MTR_AtanFast_f;

typedef double (MTR_CALL * MTR_AtanFast_dFunc)(double);
MTR_AtanFast_dFunc MTR_AtanFast_d;

typedef float (MTR_CALL * MTR_Loge_fFunc)(float);
MTR_Loge_fFunc MTR_Loge_f;

typedef double (MTR_CALL * MTR_Loge_dFunc)(double);
MTR_Loge_dFunc MTR_Loge_d;

typedef float (MTR_CALL * MTR_LogeFast_fFunc)(float);
MTR_LogeFast_fFunc MTR_LogeFast_f;

typedef double (MTR_CALL * MTR_LogeFast_dFunc)(double);
MTR_LogeFast_dFunc MTR_LogeFast_d;

typedef float (MTR_CALL * MTR_Log10_fFunc)(float);
MTR_Log10_fFunc MTR_Log10_f;

typedef double (MTR_CALL * MTR_Log10_dFunc)(double);
MTR_Log10_dFunc MTR_Log10_d;

typedef float (MTR_CALL * MTR_Log10Fast_fFunc)(float);
MTR_Log10Fast_fFunc MTR_Log10Fast_f;

typedef double (MTR_CALL * MTR_Log10Fast_dFunc)(double);
MTR_Log10Fast_dFunc MTR_Log10Fast_d;

typedef float (MTR_CALL * MTR_Log2_fFunc)(float);
MTR_Log2_fFunc MTR_Log2_f;

typedef double (MTR_CALL * MTR_Log2_dFunc)(double);
MTR_Log2_dFunc MTR_Log2_d;

typedef float (MTR_CALL * MTR_Log2Fast_fFunc)(float);
MTR_Log2Fast_fFunc MTR_Log2Fast_f;

typedef double (MTR_CALL * MTR_Log2Fast_dFunc)(double);
MTR_Log2Fast_dFunc MTR_Log2Fast_d;

typedef float (MTR_CALL * MTR_Log_fFunc)(float, float);
MTR_Log_fFunc MTR_Log_f;

typedef double (MTR_CALL * MTR_Log_dFunc)(double, double);
MTR_Log_dFunc MTR_Log_d;

typedef float (MTR_CALL * MTR_LogFast_fFunc)(float, float);
MTR_LogFast_fFunc MTR_LogFast_f;

typedef double (MTR_CALL * MTR_LogFast_dFunc)(double, double);
MTR_LogFast_dFunc MTR_LogFast_d;

typedef float (MTR_CALL * MTR_Pow_fFunc)(float, float);
MTR_Pow_fFunc MTR_Pow_f;

typedef double (MTR_CALL * MTR_Pow_dFunc)(double, double);
MTR_Pow_dFunc MTR_Pow_d;

typedef float (MTR_CALL * MTR_PowFast_fFunc)(float, float);
MTR_PowFast_fFunc MTR_PowFast_f;

typedef double (MTR_CALL * MTR_PowFast_dFunc)(double, double);
MTR_PowFast_dFunc MTR_PowFast_d;

typedef float (MTR_CALL * MTR_Sqrt_fFunc)(float);
MTR_Sqrt_fFunc MTR_Sqrt_f;

typedef double (MTR_CALL * MTR_Sqrt_dFunc)(double);
MTR_Sqrt_dFunc MTR_Sqrt_d;

typedef float (MTR_CALL * MTR_SqrtFast_fFunc)(float);
MTR_SqrtFast_fFunc MTR_SqrtFast_f;

typedef double (MTR_CALL * MTR_SqrtFast_dFunc)(double);
MTR_SqrtFast_dFunc MTR_SqrtFast_d;

typedef float (MTR_CALL * MTR_Cbrt_fFunc)(float);
MTR_Cbrt_fFunc MTR_Cbrt_f;

typedef double (MTR_CALL * MTR_Cbrt_dFunc)(double);
MTR_Cbrt_dFunc MTR_Cbrt_d;

typedef float (MTR_CALL * MTR_CbrtFast_fFunc)(float);
MTR_CbrtFast_fFunc MTR_CbrtFast_f;

typedef double (MTR_CALL * MTR_CbrtFast_dFunc)(double);
MTR_CbrtFast_dFunc MTR_CbrtFast_d;

typedef float (MTR_CALL * MTR_Hypot_fFunc)(float, float);
MTR_Hypot_fFunc MTR_Hypot_f;

typedef double (MTR_CALL * MTR_Hypot_dFunc)(double, double);
MTR_Hypot_dFunc MTR_Hypot_d;

typedef float (MTR_CALL * MTR_HypotFast_fFunc)(float, float);
MTR_HypotFast_fFunc MTR_HypotFast_f;

typedef double (MTR_CALL * MTR_HypotFast_dFunc)(double, double);
MTR_HypotFast_dFunc MTR_HypotFast_d;

typedef float (MTR_CALL * MTR_Angle_fFunc)(float, float);
MTR_Angle_fFunc MTR_Angle_f;

typedef double (MTR_CALL * MTR_Angle_dFunc)(double, double);
MTR_Angle_dFunc MTR_Angle_d;

typedef float (MTR_CALL * MTR_AngleFast_fFunc)(float, float);
MTR_AngleFast_fFunc MTR_AngleFast_f;

typedef double (MTR_CALL * MTR_AngleFast_dFunc)(double, double);
MTR_AngleFast_dFunc MTR_AngleFast_d;

typedef float (MTR_CALL * MTR_Vecx_fFunc)(float, float);
MTR_Vecx_fFunc MTR_Vecx_f;

typedef double (MTR_CALL * MTR_Vecx_dFunc)(double, double);
MTR_Vecx_dFunc MTR_Vecx_d;

typedef float (MTR_CALL * MTR_VecxFast_fFunc)(float, float);
MTR_VecxFast_fFunc MTR_VecxFast_f;

typedef double (MTR_CALL * MTR_VecxFast_dFunc)(double, double);
MTR_VecxFast_dFunc MTR_VecxFast_d;

typedef float (MTR_CALL * MTR_Vecy_fFunc)(float, float);
MTR_Vecy_fFunc MTR_Vecy_f;

typedef double (MTR_CALL * MTR_Vecy_dFunc)(double, double);
MTR_Vecy_dFunc MTR_Vecy_d;

typedef float (MTR_CALL * MTR_VecyFast_fFunc)(float, float);
MTR_VecyFast_fFunc MTR_VecyFast_f;

typedef double (MTR_CALL * MTR_VecyFast_dFunc)(double, double);
MTR_VecyFast_dFunc MTR_VecyFast_d;

#ifdef lua_h
typedef void (MTR_CALL * MTR_Vecxy_fFunc)(float, float, float *, float *);
MTR_Vecxy_fFunc MTR_Vecxy_f;

typedef void (MTR_CALL * MTR_Vecxy_dFunc)(double, double, double *, double *);
MTR_Vecxy_dFunc MTR_Vecxy_d;

typedef void (MTR_CALL * MTR_VecxyFast_fFunc)(float, float, float *, float *);
MTR_VecxyFast_fFunc MTR_VecxyFast_f;

typedef void (MTR_CALL * MTR_VecxyFast_dFunc)(double, double, double *,
 double *);
MTR_VecxyFast_dFunc MTR_VecxyFast_d;
#endif

typedef int (MTR_CALL * MTR_RandFunc)(int);
MTR_RandFunc MTR_Rand;

typedef int (MTR_CALL * MTR_RandRangeFunc)(int, int);
MTR_RandRangeFunc MTR_RandRange;

typedef void (MTR_CALL * MTR_RandSeedFunc)(unsigned int);
MTR_RandSeedFunc MTR_RandSeed;

typedef void (MTR_CALL * MTR_RandSeedByTimeFunc)(void);
MTR_RandSeedByTimeFunc MTR_RandSeedByTime;

typedef int (MTR_CALL * MTR_AbsFunc)(int);
MTR_AbsFunc MTR_Abs;

typedef long int (MTR_CALL * MTR_Abs_lFunc)(long int);
MTR_Abs_lFunc MTR_Abs_l;

typedef long long int (MTR_CALL * MTR_Abs_llFunc)(long long int);
MTR_Abs_llFunc MTR_Abs_ll;

typedef float (MTR_CALL * MTR_Abs_fFunc)(float);
MTR_Abs_fFunc MTR_Abs_f;

typedef double (MTR_CALL * MTR_Abs_dFunc)(double);
MTR_Abs_dFunc MTR_Abs_d;

typedef int (MTR_CALL * MTR_SignFunc)(int);
MTR_SignFunc MTR_Sign;

typedef long int (MTR_CALL * MTR_Sign_lFunc)(long int);
MTR_Sign_lFunc MTR_Sign_l;

typedef long long int (MTR_CALL * MTR_Sign_llFunc)(long long int);
MTR_Sign_llFunc MTR_Sign_ll;

typedef float (MTR_CALL * MTR_Sign_fFunc)(float);
MTR_Sign_fFunc MTR_Sign_f;

typedef double (MTR_CALL * MTR_Sign_dFunc)(double);
MTR_Sign_dFunc MTR_Sign_d;

typedef float (MTR_CALL * MTR_Round_fFunc)(float);
MTR_Round_fFunc MTR_Round_f;

typedef double (MTR_CALL * MTR_Round_dFunc)(double);
MTR_Round_dFunc MTR_Round_d;

typedef float (MTR_CALL * MTR_Floor_fFunc)(float);
MTR_Floor_fFunc MTR_Floor_f;

typedef double (MTR_CALL * MTR_Floor_dFunc)(double);
MTR_Floor_dFunc MTR_Floor_d;

typedef float (MTR_CALL * MTR_Ceil_fFunc)(float);
MTR_Ceil_fFunc MTR_Ceil_f;

typedef double (MTR_CALL * MTR_Ceil_dFunc)(double);
MTR_Ceil_dFunc MTR_Ceil_d;

typedef int (MTR_CALL * MTR_ModFunc)(int, int);
MTR_ModFunc MTR_Mod;

typedef long int (MTR_CALL * MTR_Mod_lFunc)(long int, long int);
MTR_Mod_lFunc MTR_Mod_l;

typedef long long int (MTR_CALL * MTR_Mod_llFunc)(long long int, long long int);
MTR_Mod_llFunc MTR_Mod_ll;

typedef float (MTR_CALL * MTR_Mod_fFunc)(float, float);
MTR_Mod_fFunc MTR_Mod_f;

typedef double (MTR_CALL * MTR_Mod_dFunc)(double, double);
MTR_Mod_dFunc MTR_Mod_d;

typedef int (MTR_CALL * MTR_MinFunc)(int, int);
MTR_MinFunc MTR_Min;

typedef long int (MTR_CALL * MTR_Min_lFunc)(long int, long int);
MTR_Min_lFunc MTR_Min_l;

typedef long long int (MTR_CALL * MTR_Min_llFunc)(long long int, long long int);
MTR_Min_llFunc MTR_Min_ll;

typedef float (MTR_CALL * MTR_Min_fFunc)(float, float);
MTR_Min_fFunc MTR_Min_f;

typedef double (MTR_CALL * MTR_Min_dFunc)(double, double);
MTR_Min_dFunc MTR_Min_d;

typedef int (MTR_CALL * MTR_MaxFunc)(int, int);
MTR_MaxFunc MTR_Max;

typedef long int (MTR_CALL * MTR_Max_lFunc)(long int, long int);
MTR_Max_lFunc MTR_Max_l;

typedef long long int (MTR_CALL * MTR_Max_llFunc)(long long int, long long int);
MTR_Max_llFunc MTR_Max_ll;

typedef float (MTR_CALL * MTR_Max_fFunc)(float, float);
MTR_Max_fFunc MTR_Max_f;

typedef double (MTR_CALL * MTR_Max_dFunc)(double, double);
MTR_Max_dFunc MTR_Max_d;

#endif
