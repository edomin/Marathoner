#ifndef MTR_UTILS_MATH_BINDING_COMMON_C
#define MTR_UTILS_MATH_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC(mtrSF_Sin_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrSin_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Sin_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrSin_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_SinFast_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrSinFast_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_SinFast_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrSinFast_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Cos_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrCos_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Cos_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrCos_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_CosFast_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrCosFast_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_CosFast_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrCosFast_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Tan_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrTan_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Tan_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrTan_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_TanFast_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrTanFast_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_TanFast_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrTanFast_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Asin_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrAsin_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Asin_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrAsin_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_AsinFast_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrAsinFast_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_AsinFast_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrAsinFast_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Acos_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrAcos_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Acos_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrAcos_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_AcosFast_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrAcosFast_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_AcosFast_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrAcosFast_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Atan_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrAtan_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Atan_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrAtan_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_AtanFast_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrAtanFast_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_AtanFast_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrAtanFast_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Loge_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrLoge_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Loge_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrLoge_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_LogeFast_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrLogeFast_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_LogeFast_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrLogeFast_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Log10_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrLog10_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Log10_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrLog10_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Log10Fast_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrLog10Fast_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Log10Fast_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrLog10Fast_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Log2_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrLog2_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Log2_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrLog2_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Log2Fast_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrLog2Fast_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Log2Fast_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrLog2Fast_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Pow_f)
{
    float base;
    float power;
    float result;

    MTR_SF_GET_SINGLE(base, 1);
    MTR_SF_GET_SINGLE(power, 2);
    result = mtrPow_f(base, power);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Pow_d)
{
    double base;
    double power;
    double result;

    MTR_SF_GET_DOUBLE(base, 1);
    MTR_SF_GET_DOUBLE(power, 2);
    result = mtrPow_d(base, power);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_PowFast_f)
{
    float base;
    float power;
    float result;

    MTR_SF_GET_SINGLE(base, 1);
    MTR_SF_GET_SINGLE(power, 2);
    result = mtrPowFast_f(base, power);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_PowFast_d)
{
    double base;
    double power;
    double result;

    MTR_SF_GET_DOUBLE(base, 1);
    MTR_SF_GET_DOUBLE(power, 2);
    result = mtrPowFast_d(base, power);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Sqrt_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrSqrt_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Sqrt_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrSqrt_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_SqrtFast_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrSqrtFast_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_SqrtFast_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrSqrtFast_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Cbrt_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrCbrt_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Cbrt_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrCbrt_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_CbrtFast_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrCbrtFast_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_CbrtFast_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrCbrtFast_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Hypot_f)
{
    float x;
    float y;
    float result;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    result = mtrHypot_f(x, y);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Hypot_d)
{
    double x;
    double y;
    double result;

    MTR_SF_GET_DOUBLE(x, 1);
    MTR_SF_GET_DOUBLE(y, 2);
    result = mtrHypot_d(x, y);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_HypotFast_f)
{
    float x;
    float y;
    float result;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    result = mtrHypotFast_f(x, y);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_HypotFast_d)
{
    double x;
    double y;
    double result;

    MTR_SF_GET_DOUBLE(x, 1);
    MTR_SF_GET_DOUBLE(y, 2);
    result = mtrHypotFast_d(x, y);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Angle_f)
{
    float x;
    float y;
    float result;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    result = mtrAngle_f(x, y);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Angle_d)
{
    double x;
    double y;
    double result;

    MTR_SF_GET_DOUBLE(x, 1);
    MTR_SF_GET_DOUBLE(y, 2);
    result = mtrAngle_d(x, y);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_AngleFast_f)
{
    float x;
    float y;
    float result;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    result = mtrAngleFast_f(x, y);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_AngleFast_d)
{
    double x;
    double y;
    double result;

    MTR_SF_GET_DOUBLE(x, 1);
    MTR_SF_GET_DOUBLE(y, 2);
    result = mtrAngleFast_d(x, y);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Vecx_f)
{
    float length;
    float dir;
    float result;

    MTR_SF_GET_SINGLE(length, 1);
    MTR_SF_GET_SINGLE(dir, 2);
    result = mtrVecx_f(length, dir);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Vecx_d)
{
    double length;
    double dir;
    double result;

    MTR_SF_GET_DOUBLE(length, 1);
    MTR_SF_GET_DOUBLE(dir, 2);
    result = mtrVecx_d(length, dir);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_VecxFast_f)
{
    float length;
    float dir;
    float result;

    MTR_SF_GET_SINGLE(length, 1);
    MTR_SF_GET_SINGLE(dir, 2);
    result = mtrVecxFast_f(length, dir);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_VecxFast_d)
{
    double length;
    double dir;
    double result;

    MTR_SF_GET_DOUBLE(length, 1);
    MTR_SF_GET_DOUBLE(dir, 2);
    result = mtrVecxFast_d(length, dir);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Vecy_f)
{
    float length;
    float dir;
    float result;

    MTR_SF_GET_SINGLE(length, 1);
    MTR_SF_GET_SINGLE(dir, 2);
    result = mtrVecy_f(length, dir);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Vecy_d)
{
    double length;
    double dir;
    double result;

    MTR_SF_GET_DOUBLE(length, 1);
    MTR_SF_GET_DOUBLE(dir, 2);
    result = mtrVecy_d(length, dir);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_VecyFast_f)
{
    float length;
    float dir;
    float result;

    MTR_SF_GET_SINGLE(length, 1);
    MTR_SF_GET_SINGLE(dir, 2);
    result = mtrVecyFast_f(length, dir);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_VecyFast_d)
{
    double length;
    double dir;
    double result;

    MTR_SF_GET_DOUBLE(length, 1);
    MTR_SF_GET_DOUBLE(dir, 2);
    result = mtrVecyFast_d(length, dir);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

#ifndef _SQUIRREL_H_
MTR_SCRIPT_FUNC(mtrSF_Vecxy_f)
{
    float length;
    float dir;
    float x;
    float y;

    MTR_SF_GET_SINGLE(length, 1);
    MTR_SF_GET_SINGLE(dir, 2);
    mtrVecxy_f(length, dir, &x, &y);

    MTR_SF_PUSH_SINGLE(x);
    MTR_SF_PUSH_SINGLE(y);

    return 2;
}

MTR_SCRIPT_FUNC(mtrSF_Vecxy_d)
{
    double length;
    double dir;
    double x;
    double y;

    MTR_SF_GET_DOUBLE(length, 1);
    MTR_SF_GET_DOUBLE(dir, 2);
    mtrVecxy_d(length, dir, &x, &y);

    MTR_SF_PUSH_DOUBLE(x);
    MTR_SF_PUSH_DOUBLE(y);

    return 2;
}

MTR_SCRIPT_FUNC(mtrSF_VecxyFast_f)
{
    float length;
    float dir;
    float x;
    float y;

    MTR_SF_GET_SINGLE(length, 1);
    MTR_SF_GET_SINGLE(dir, 2);
    mtrVecxyFast_f(length, dir, &x, &y);

    MTR_SF_PUSH_SINGLE(x);
    MTR_SF_PUSH_SINGLE(y);

    return 2;
}

MTR_SCRIPT_FUNC(mtrSF_VecxyFast_d)
{
    double length;
    double dir;
    double x;
    double y;

    MTR_SF_GET_DOUBLE(length, 1);
    MTR_SF_GET_DOUBLE(dir, 2);
    mtrVecxyFast_d(length, dir, &x, &y);

    MTR_SF_PUSH_DOUBLE(x);
    MTR_SF_PUSH_DOUBLE(y);

    return 2;
}
#endif

MTR_SCRIPT_FUNC(mtrSF_Rand)
{
    int num;
    int result;

    MTR_SF_GET_INT(num, 1);
    result = mtrRand(num);

    MTR_SF_PUSH_INT(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_RandRange)
{
    int min;
    int max;
    int result;

    MTR_SF_GET_INT(min, 1);
    MTR_SF_GET_INT(max, 2);
    result = mtrRandRange(min, max);

    MTR_SF_PUSH_INT(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_RandSeed)
{
    unsigned int num;

    MTR_SF_GET_UINT(num, 1);
    mtrRandSeed(num);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_RandSeedByTime)
{
    mtrRandSeedByTime();

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_Abs)
{
    int num;
    int result;

    MTR_SF_GET_INT(num, 1);
    result = mtrAbs(num);

    MTR_SF_PUSH_INT(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Abs_l)
{
    long int num;
    long int result;

    MTR_SF_GET_LINT(num, 1);
    result = mtrAbs_l(num);

    MTR_SF_PUSH_LINT(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Abs_ll)
{
    long long int num;
    long long int result;

    MTR_SF_GET_LLINT(num, 1);
    result = mtrAbs_ll(num);

    MTR_SF_PUSH_LLINT(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Abs_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrAbs_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Abs_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrAbs_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Sign)
{
    int num;
    int result;

    MTR_SF_GET_INT(num, 1);
    result = mtrSign(num);

    MTR_SF_PUSH_INT(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Sign_l)
{
    long int num;
    long int result;

    MTR_SF_GET_LINT(num, 1);
    result = mtrSign_l(num);

    MTR_SF_PUSH_LINT(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Sign_ll)
{
    long long int num;
    long long int result;

    MTR_SF_GET_LLINT(num, 1);
    result = mtrSign_ll(num);

    MTR_SF_PUSH_LLINT(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Sign_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrSign_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Sign_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrSign_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Round_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrRound_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Round_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrRound_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Floor_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrFloor_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Floor_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrFloor_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Ceil_f)
{
    float num;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    result = mtrCeil_f(num);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Ceil_d)
{
    double num;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    result = mtrCeil_d(num);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Mod)
{
    int num;
    int denom;
    int result;

    MTR_SF_GET_INT(num, 1);
    MTR_SF_GET_INT(denom, 2);
    result = mtrMod(num, denom);

    MTR_SF_PUSH_INT(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Mod_l)
{
    long int num;
    long int denom;
    long int result;

    MTR_SF_GET_LINT(num, 1);
    MTR_SF_GET_LINT(denom, 2);
    result = mtrMod_l(num, denom);

    MTR_SF_PUSH_LINT(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Mod_ll)
{
    long long int num;
    long long int denom;
    long long int result;

    MTR_SF_GET_LLINT(num, 1);
    MTR_SF_GET_LLINT(denom, 2);
    result = mtrMod_ll(num, denom);

    MTR_SF_PUSH_LLINT(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Mod_f)
{
    float num;
    float denom;
    float result;

    MTR_SF_GET_SINGLE(num, 1);
    MTR_SF_GET_SINGLE(denom, 2);
    result = mtrMod_f(num, denom);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Mod_d)
{
    double num;
    double denom;
    double result;

    MTR_SF_GET_DOUBLE(num, 1);
    MTR_SF_GET_DOUBLE(denom, 2);
    result = mtrMod_d(num, denom);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Min)
{
    int num1;
    int num2;
    int result;

    MTR_SF_GET_INT(num1, 1);
    MTR_SF_GET_INT(num2, 2);
    result = mtrMin(num1, num2);

    MTR_SF_PUSH_INT(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Min_l)
{
    long int num1;
    long int num2;
    long int result;

    MTR_SF_GET_LINT(num1, 1);
    MTR_SF_GET_LINT(num2, 2);
    result = mtrMin_l(num1, num2);

    MTR_SF_PUSH_LINT(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Min_ll)
{
    long long int num1;
    long long int num2;
    long long int result;

    MTR_SF_GET_LLINT(num1, 1);
    MTR_SF_GET_LLINT(num2, 2);
    result = mtrMin_ll(num1, num2);

    MTR_SF_PUSH_LLINT(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Min_f)
{
    float num1;
    float num2;
    float result;

    MTR_SF_GET_SINGLE(num1, 1);
    MTR_SF_GET_SINGLE(num2, 2);
    result = mtrMin_f(num1, num2);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Min_d)
{
    double num1;
    double num2;
    double result;

    MTR_SF_GET_DOUBLE(num1, 1);
    MTR_SF_GET_DOUBLE(num2, 2);
    result = mtrMin_d(num1, num2);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Max)
{
    int num1;
    int num2;
    int result;

    MTR_SF_GET_INT(num1, 1);
    MTR_SF_GET_INT(num2, 2);
    result = mtrMax(num1, num2);

    MTR_SF_PUSH_INT(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Max_l)
{
    long int num1;
    long int num2;
    long int result;

    MTR_SF_GET_LINT(num1, 1);
    MTR_SF_GET_LINT(num2, 2);
    result = mtrMax_l(num1, num2);

    MTR_SF_PUSH_LINT(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Max_ll)
{
    long long int num1;
    long long int num2;
    long long int result;

    MTR_SF_GET_LLINT(num1, 1);
    MTR_SF_GET_LLINT(num2, 2);
    result = mtrMax_ll(num1, num2);

    MTR_SF_PUSH_LLINT(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Max_f)
{
    float num1;
    float num2;
    float result;

    MTR_SF_GET_SINGLE(num1, 1);
    MTR_SF_GET_SINGLE(num2, 2);
    result = mtrMax_f(num1, num2);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Max_d)
{
    double num1;
    double num2;
    double result;

    MTR_SF_GET_DOUBLE(num1, 1);
    MTR_SF_GET_DOUBLE(num2, 2);
    result = mtrMax_d(num1, num2);

    MTR_SF_PUSH_DOUBLE(result);

    return 1;
}

void mtrScriptsRegisterAll(void)
{
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();

    MTR_FIND_FUNCTION(mtrSin_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrSin_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrSinFast_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrSinFast_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrCos_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrCos_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrCosFast_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrCosFast_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrTan_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrTan_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrTanFast_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrTanFast_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrAsin_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrAsin_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrAsinFast_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrAsinFast_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrAcos_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrAcos_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrAcosFast_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrAcosFast_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrAtan_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrAtan_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrAtanFast_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrAtanFast_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrLoge_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrLoge_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrLogeFast_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrLogeFast_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrLog10_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrLog10_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrLog10Fast_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrLog10Fast_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrLog2_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrLog2_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrLog2Fast_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrLog2Fast_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrPow_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrPow_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrPowFast_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrPowFast_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrSqrt_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrSqrt_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrSqrtFast_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrSqrtFast_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrCbrt_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrCbrt_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrCbrtFast_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrCbrtFast_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrHypot_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrHypot_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrHypotFast_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrHypotFast_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrAngle_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrAngle_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrAngleFast_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrAngleFast_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrVecx_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrVecx_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrVecxFast_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrVecxFast_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrVecy_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrVecy_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrVecyFast_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrVecyFast_d, "Utils_math");
    #ifndef _SQUIRREL_H_
    MTR_FIND_FUNCTION(mtrVecxy_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrVecxy_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrVecxyFast_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrVecxyFast_d, "Utils_math");
    #endif
    MTR_FIND_FUNCTION(mtrRand, "Utils_math");
    MTR_FIND_FUNCTION(mtrRandRange, "Utils_math");
    MTR_FIND_FUNCTION(mtrRandSeed, "Utils_math");
    MTR_FIND_FUNCTION(mtrRandSeedByTime, "Utils_math");
    MTR_FIND_FUNCTION(mtrAbs, "Utils_math");
    MTR_FIND_FUNCTION(mtrAbs_l, "Utils_math");
    MTR_FIND_FUNCTION(mtrAbs_ll, "Utils_math");
    MTR_FIND_FUNCTION(mtrAbs_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrAbs_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrSign, "Utils_math");
    MTR_FIND_FUNCTION(mtrSign_l, "Utils_math");
    MTR_FIND_FUNCTION(mtrSign_ll, "Utils_math");
    MTR_FIND_FUNCTION(mtrSign_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrSign_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrRound_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrRound_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrFloor_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrFloor_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrCeil_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrCeil_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrMod, "Utils_math");
    MTR_FIND_FUNCTION(mtrMod_l, "Utils_math");
    MTR_FIND_FUNCTION(mtrMod_ll, "Utils_math");
    MTR_FIND_FUNCTION(mtrMod_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrMod_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrMin, "Utils_math");
    MTR_FIND_FUNCTION(mtrMin_l, "Utils_math");
    MTR_FIND_FUNCTION(mtrMin_ll, "Utils_math");
    MTR_FIND_FUNCTION(mtrMin_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrMin_d, "Utils_math");
    MTR_FIND_FUNCTION(mtrMax, "Utils_math");
    MTR_FIND_FUNCTION(mtrMax_l, "Utils_math");
    MTR_FIND_FUNCTION(mtrMax_ll, "Utils_math");
    MTR_FIND_FUNCTION(mtrMax_f, "Utils_math");
    MTR_FIND_FUNCTION(mtrMax_d, "Utils_math");

    if (ok)
    {
        mtrScriptsRegisterFunction(mtrSF_Sin_f, "Sin_f");
        mtrScriptsRegisterFunction(mtrSF_Sin_d, "Sin_d");
        mtrScriptsRegisterFunction(mtrSF_SinFast_f, "SinFast_f");
        mtrScriptsRegisterFunction(mtrSF_SinFast_d, "SinFast_d");
        mtrScriptsRegisterFunction(mtrSF_Cos_f, "Cos_f");
        mtrScriptsRegisterFunction(mtrSF_Cos_d, "Cos_d");
        mtrScriptsRegisterFunction(mtrSF_CosFast_f, "CosFast_f");
        mtrScriptsRegisterFunction(mtrSF_CosFast_d, "CosFast_d");
        mtrScriptsRegisterFunction(mtrSF_Tan_f, "Tan_f");
        mtrScriptsRegisterFunction(mtrSF_Tan_d, "Tan_d");
        mtrScriptsRegisterFunction(mtrSF_TanFast_f, "TanFast_f");
        mtrScriptsRegisterFunction(mtrSF_TanFast_d, "TanFast_d");
        mtrScriptsRegisterFunction(mtrSF_Asin_f, "Asin_f");
        mtrScriptsRegisterFunction(mtrSF_Asin_d, "Asin_d");
        mtrScriptsRegisterFunction(mtrSF_AsinFast_f, "AsinFast_f");
        mtrScriptsRegisterFunction(mtrSF_AsinFast_d, "AsinFast_d");
        mtrScriptsRegisterFunction(mtrSF_Acos_f, "Acos_f");
        mtrScriptsRegisterFunction(mtrSF_Acos_d, "Acos_d");
        mtrScriptsRegisterFunction(mtrSF_AcosFast_f, "AcosFast_f");
        mtrScriptsRegisterFunction(mtrSF_AcosFast_d, "AcosFast_d");
        mtrScriptsRegisterFunction(mtrSF_Atan_f, "Atan_f");
        mtrScriptsRegisterFunction(mtrSF_Atan_d, "Atan_d");
        mtrScriptsRegisterFunction(mtrSF_AtanFast_f, "AtanFast_f");
        mtrScriptsRegisterFunction(mtrSF_AtanFast_d, "AtanFast_d");
        mtrScriptsRegisterFunction(mtrSF_Loge_f, "Loge_f");
        mtrScriptsRegisterFunction(mtrSF_Loge_d, "Loge_d");
        mtrScriptsRegisterFunction(mtrSF_LogeFast_f, "LogeFast_f");
        mtrScriptsRegisterFunction(mtrSF_LogeFast_d, "LogeFast_d");
        mtrScriptsRegisterFunction(mtrSF_Log10_f, "Log10_f");
        mtrScriptsRegisterFunction(mtrSF_Log10_d, "Log10_d");
        mtrScriptsRegisterFunction(mtrSF_Log10Fast_f, "Log10Fast_f");
        mtrScriptsRegisterFunction(mtrSF_Log10Fast_d, "Log10Fast_d");
        mtrScriptsRegisterFunction(mtrSF_Log2_f, "Log2_f");
        mtrScriptsRegisterFunction(mtrSF_Log2_d, "Log2_d");
        mtrScriptsRegisterFunction(mtrSF_Log2Fast_f, "Log2Fast_f");
        mtrScriptsRegisterFunction(mtrSF_Log2Fast_d, "Log2Fast_d");
        mtrScriptsRegisterFunction(mtrSF_Pow_f, "Pow_f");
        mtrScriptsRegisterFunction(mtrSF_Pow_d, "Pow_d");
        mtrScriptsRegisterFunction(mtrSF_PowFast_f, "PowFast_f");
        mtrScriptsRegisterFunction(mtrSF_PowFast_d, "PowFast_d");
        mtrScriptsRegisterFunction(mtrSF_Sqrt_f, "Sqrt_f");
        mtrScriptsRegisterFunction(mtrSF_Sqrt_d, "Sqrt_d");
        mtrScriptsRegisterFunction(mtrSF_SqrtFast_f, "SqrtFast_f");
        mtrScriptsRegisterFunction(mtrSF_SqrtFast_d, "SqrtFast_d");
        mtrScriptsRegisterFunction(mtrSF_Cbrt_f, "Cbrt_f");
        mtrScriptsRegisterFunction(mtrSF_Cbrt_d, "Cbrt_d");
        mtrScriptsRegisterFunction(mtrSF_CbrtFast_f, "CbrtFast_f");
        mtrScriptsRegisterFunction(mtrSF_CbrtFast_d, "CbrtFast_d");
        mtrScriptsRegisterFunction(mtrSF_Hypot_f, "Hypot_f");
        mtrScriptsRegisterFunction(mtrSF_Hypot_d, "Hypot_d");
        mtrScriptsRegisterFunction(mtrSF_HypotFast_f, "HypotFast_f");
        mtrScriptsRegisterFunction(mtrSF_HypotFast_d, "HypotFast_d");
        mtrScriptsRegisterFunction(mtrSF_Angle_f, "Angle_f");
        mtrScriptsRegisterFunction(mtrSF_Angle_d, "Angle_d");
        mtrScriptsRegisterFunction(mtrSF_AngleFast_f, "AngleFast_f");
        mtrScriptsRegisterFunction(mtrSF_AngleFast_d, "AngleFast_d");
        mtrScriptsRegisterFunction(mtrSF_Vecx_f, "Vecx_f");
        mtrScriptsRegisterFunction(mtrSF_Vecx_d, "Vecx_d");
        mtrScriptsRegisterFunction(mtrSF_VecxFast_f, "VecxFast_f");
        mtrScriptsRegisterFunction(mtrSF_VecxFast_d, "VecxFast_d");
        mtrScriptsRegisterFunction(mtrSF_Vecy_f, "Vecy_f");
        mtrScriptsRegisterFunction(mtrSF_Vecy_d, "Vecy_d");
        mtrScriptsRegisterFunction(mtrSF_VecyFast_f, "VecyFast_f");
        mtrScriptsRegisterFunction(mtrSF_VecyFast_d, "VecyFast_d");
        #ifndef _SQUIRREL_H_
        mtrScriptsRegisterFunction(mtrSF_Vecxy_f, "Vecxy_f");
        mtrScriptsRegisterFunction(mtrSF_Vecxy_d, "Vecxy_d");
        mtrScriptsRegisterFunction(mtrSF_VecxyFast_f, "VecxyFast_f");
        mtrScriptsRegisterFunction(mtrSF_VecxyFast_d, "VecxyFast_d");
        #endif
        mtrScriptsRegisterFunction(mtrSF_Rand, "Rand");
        mtrScriptsRegisterFunction(mtrSF_RandRange, "RandRange");
        mtrScriptsRegisterFunction(mtrSF_RandSeed, "RandSeed");
        mtrScriptsRegisterFunction(mtrSF_RandSeedByTime, "RandSeedByTime");
        mtrScriptsRegisterFunction(mtrSF_Abs, "Abs");
        mtrScriptsRegisterFunction(mtrSF_Abs_l, "Abs_l");
        mtrScriptsRegisterFunction(mtrSF_Abs_ll, "Abs_ll");
        mtrScriptsRegisterFunction(mtrSF_Abs_f, "Abs_f");
        mtrScriptsRegisterFunction(mtrSF_Abs_d, "Abs_d");
        mtrScriptsRegisterFunction(mtrSF_Sign, "Sign");
        mtrScriptsRegisterFunction(mtrSF_Sign_l, "Sign_l");
        mtrScriptsRegisterFunction(mtrSF_Sign_ll, "Sign_ll");
        mtrScriptsRegisterFunction(mtrSF_Sign_f, "Sign_f");
        mtrScriptsRegisterFunction(mtrSF_Sign_d, "Sign_d");
        mtrScriptsRegisterFunction(mtrSF_Round_f, "Round_f");
        mtrScriptsRegisterFunction(mtrSF_Round_d, "Round_d");
        mtrScriptsRegisterFunction(mtrSF_Floor_f, "Floor_f");
        mtrScriptsRegisterFunction(mtrSF_Floor_d, "Floor_d");
        mtrScriptsRegisterFunction(mtrSF_Ceil_f, "Ceil_f");
        mtrScriptsRegisterFunction(mtrSF_Ceil_d, "Ceil_d");
        mtrScriptsRegisterFunction(mtrSF_Mod, "Mod");
        mtrScriptsRegisterFunction(mtrSF_Mod_l, "Mod_l");
        mtrScriptsRegisterFunction(mtrSF_Mod_ll, "Mod_ll");
        mtrScriptsRegisterFunction(mtrSF_Mod_f, "Mod_f");
        mtrScriptsRegisterFunction(mtrSF_Mod_d, "Mod_d");
        mtrScriptsRegisterFunction(mtrSF_Min, "Min");
        mtrScriptsRegisterFunction(mtrSF_Min_l, "Min_l");
        mtrScriptsRegisterFunction(mtrSF_Min_ll, "Min_ll");
        mtrScriptsRegisterFunction(mtrSF_Min_f, "Min_f");
        mtrScriptsRegisterFunction(mtrSF_Min_d, "Min_d");
        mtrScriptsRegisterFunction(mtrSF_Max, "Max");
        mtrScriptsRegisterFunction(mtrSF_Max_l, "Max_l");
        mtrScriptsRegisterFunction(mtrSF_Max_ll, "Max_ll");
        mtrScriptsRegisterFunction(mtrSF_Max_f, "Max_f");
        mtrScriptsRegisterFunction(mtrSF_Max_d, "Max_d");
    }
    else
    {
        mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
    }
}

#endif
