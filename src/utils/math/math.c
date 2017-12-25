#include "math.h"

#ifdef MTR_MOD_PLUGIN
#include "marathoner/plugin_common.c"

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Utils_math";
    report->version = MTR_VERSION_UTILS_MATH;
    report->subsystem = "utils";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}
#endif

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Math, FA_FUNCTIONS_COUNT)

/*fa MTR_Sin_f yes */
MTR_DCLSPC float MTR_CALL MTR_Sin_f(float num)
{
    return sinf(num * MTR_DEGREE_F);
}

/*fa MTR_Sin_d yes */
MTR_DCLSPC double MTR_CALL MTR_Sin_d(double num)
{
    return sin(num * MTR_DEGREE_D);
}

/* http://lab.polygonal.de/2007/07/18/fast-and-accurate-sinecosine-approximation/ */
/*fa MTR_SinFast_f yes */
MTR_DCLSPC float MTR_CALL MTR_SinFast_f(float num)
{
    float sine;
    float num2 = num;

    if (num2 < 0)
        num2 = 360 - fmodf(-num2 + 180, 360) - 180;
    else
        num2 = fmodf(num2 + 180, 360) - 180;
    num2 = num2 * MTR_DEGREE_F;
    if (num2 < 0)
        sine = num2 * (1.27323954f + 0.405284735f * num2);
    else
        sine = num2*(1.27323954f - 0.405284735f * num2);

    if (sine < 0)
        sine = sine * (-0.225f * (sine + 1.0f) + 1.0f);
    else
        sine = sine * (0.225f * (sine - 1.0f) + 1.0f);
    return sine;
}

/* http://lab.polygonal.de/2007/07/18/fast-and-accurate-sinecosine-approximation/ */
/*fa MTR_SinFast_d yes */
MTR_DCLSPC double MTR_CALL MTR_SinFast_d(double num)
{
    double sine;
    double num2 = num;

    if (num2 < 0)
        num2 = 360 - fmod(-num2 + 180, 360) - 180;
    else
        num2 = fmod(num2 + 180, 360) - 180;
    num2 = num2 * MTR_DEGREE_D;
    if (num2 < 0)
        sine = num2 * (1.27323954 + 0.405284735 * num2);
    else
        sine = num2*(1.27323954 - 0.405284735 * num2);

    if (sine < 0)
        sine = sine * (-0.225 * (sine + 1.0) + 1.0);
    else
        sine = sine * (0.225 * (sine - 1.0) + 1.0);
    return sine;
}

/*fa MTR_Cos_f yes */
MTR_DCLSPC float MTR_CALL MTR_Cos_f(float num)
{
    return cosf(num * MTR_DEGREE_F);
}

/*fa MTR_Cos_d yes */
MTR_DCLSPC double MTR_CALL MTR_Cos_d(double num)
{
    return cos(num * MTR_DEGREE_D);
}

/* http://lab.polygonal.de/2007/07/18/fast-and-accurate-sinecosine-approximation/ */
/*fa MTR_CosFast_f yes */
MTR_DCLSPC float MTR_CALL MTR_CosFast_f(float num)
{
    float num2 = num;

    if (num2 < 0)
        num2 = 360 - fmodf(-num2, 360);
    else
        num2 = fmodf(num2, 360);
    num2 = num2 * MTR_DEGREE_F;
    if (num2 < -3.14159265f)
        num2 += 6.28318531f;
    else
    if (num2 >  3.14159265f)
        num2 -= 6.28318531f;

    num2 += 1.57079632f;
    if (num2 >  3.14159265f)
        num2 -= 6.28318531f;

    if (num2 < 0)
        return (1.27323954f * num2 + 0.405284735f * num2 * num2);

    return (1.27323954f * num2 - 0.405284735f * num2 * num2);
}

/* http://lab.polygonal.de/2007/07/18/fast-and-accurate-sinecosine-approximation/ */
/*fa MTR_CosFast_d yes */
MTR_DCLSPC double MTR_CALL MTR_CosFast_d(double num)
{
    double num2 = num;

    if (num2 < 0)
        num2 = 360 - fmod(-num2, 360);
    else
        num2 = fmod(num2, 360);
    num2 = num2 * MTR_DEGREE_D;
    if (num2 < -3.14159265)
        num2 += 6.28318531;
    else
    if (num2 >  3.14159265)
        num2 -= 6.28318531;

    num2 += 1.57079632;
    if (num2 >  3.14159265)
        num2 -= 6.28318531;

    if (num2 < 0)
        return (1.27323954 * num2 + 0.405284735 * num2 * num2);

    return (1.27323954 * num2 - 0.405284735 * num2 * num2);
}

/*fa MTR_Tan_f yes */
MTR_DCLSPC float MTR_CALL MTR_Tan_f(float num)
{
    return tanf(num * MTR_DEGREE_F);
}

/*fa MTR_Tan_d yes */
MTR_DCLSPC double MTR_CALL MTR_Tan_d(double num)
{
    return tan(num * MTR_DEGREE_D);
}

/*fa MTR_TanFast_f yes */
MTR_DCLSPC float MTR_CALL MTR_TanFast_f(float num)
{
    return tanf(num * MTR_DEGREE_F);
}

/*fa MTR_TanFast_d yes */
MTR_DCLSPC double MTR_CALL MTR_TanFast_d(double num)
{
    return tan(num * MTR_DEGREE_D);
}

/*fa MTR_Cot_f yes */
MTR_DCLSPC float MTR_CALL MTR_Cot_f(float num)
{
    return 1.0f / tanf(num * MTR_DEGREE_F);
}

/*fa MTR_Cot_d yes */
MTR_DCLSPC double MTR_CALL MTR_Cot_d(double num)
{
    return 1.0 / tan(num * MTR_DEGREE_D);
}

/*fa MTR_CotFast_f yes */
MTR_DCLSPC float MTR_CALL MTR_CotFast_f(float num)
{
    return 1.0f / tanf(num * MTR_DEGREE_F);
}

/*fa MTR_CotFast_d yes */
MTR_DCLSPC double MTR_CALL MTR_CotFast_d(double num)
{
    return 1.0 / tan(num * MTR_DEGREE_D);
}

/*fa MTR_Asin_f yes */
MTR_DCLSPC float MTR_CALL MTR_Asin_f(float num)
{
    return asinf(num) * MTR_RADIAN_F;
}

/*fa MTR_Asin_d yes */
MTR_DCLSPC double MTR_CALL MTR_Asin_d(double num)
{
    return asin(num) * MTR_RADIAN_D;
}

/*fa MTR_AsinFast_f yes */
MTR_DCLSPC float MTR_CALL MTR_AsinFast_f(float num)
{
    return asinf(num) * MTR_RADIAN_F;
}

/*fa MTR_AsinFast_d yes */
MTR_DCLSPC double MTR_CALL MTR_AsinFast_d(double num)
{
    return asin(num) * MTR_RADIAN_D;
}

/*fa MTR_Acos_f yes */
MTR_DCLSPC float MTR_CALL MTR_Acos_f(float num)
{
    return acosf(num) * MTR_RADIAN_F;
}

/*fa MTR_Acos_d yes */
MTR_DCLSPC double MTR_CALL MTR_Acos_d(double num)
{
    return acos(num) * MTR_RADIAN_D;
}

/*fa MTR_AcosFast_f yes */
MTR_DCLSPC float MTR_CALL MTR_AcosFast_f(float num)
{
    return acosf(num) * MTR_RADIAN_F;
}

/*fa MTR_AcosFast_d yes */
MTR_DCLSPC double MTR_CALL MTR_AcosFast_d(double num)
{
    return acos(num) * MTR_RADIAN_D;
}

/*fa MTR_Atan_f yes */
MTR_DCLSPC float MTR_CALL MTR_Atan_f(float num)
{
    return atanf(num) * MTR_RADIAN_F;
}

/*fa MTR_Atan_d yes */
MTR_DCLSPC double MTR_CALL MTR_Atan_d(double num)
{
    return atan(num) * MTR_RADIAN_D;
}

/*fa MTR_AtanFast_f yes */
MTR_DCLSPC float MTR_CALL MTR_AtanFast_f(float num)
{
    return atanf(num) * MTR_RADIAN_F;
}

/*fa MTR_AtanFast_d yes */
MTR_DCLSPC double MTR_CALL MTR_AtanFast_d(double num)
{
    return atan(num) * MTR_RADIAN_D;
}

/*fa MTR_Acot_f yes */
MTR_DCLSPC float MTR_CALL MTR_Acot_f(float num)
{
    return atanf(1 / num) * MTR_RADIAN_F;
}

/*fa MTR_Acot_d yes */
MTR_DCLSPC double MTR_CALL MTR_Acot_d(double num)
{
    return atan(1 / num) * MTR_RADIAN_D;
}

/*fa MTR_AcotFast_f yes */
MTR_DCLSPC float MTR_CALL MTR_AcotFast_f(float num)
{
    return atanf(1 / num) * MTR_RADIAN_F;
}

/*fa MTR_AcotFast_d yes */
MTR_DCLSPC double MTR_CALL MTR_AcotFast_d(double num)
{
    return atan(1 / num) * MTR_RADIAN_D;
}

/*fa MTR_Loge_f yes */
MTR_DCLSPC float MTR_CALL MTR_Loge_f(float num)
{
    return logf(num);
}

/*fa MTR_Loge_d yes */
MTR_DCLSPC double MTR_CALL MTR_Loge_d(double num)
{
    return log(num);
}

/*fa MTR_LogeFast_f yes */
MTR_DCLSPC float MTR_CALL MTR_LogeFast_f(float num)
{
    return logf(num);
}

/*fa MTR_LogeFast_d yes */
MTR_DCLSPC double MTR_CALL MTR_LogeFast_d(double num)
{
    return log(num);
}

/*fa MTR_Log10_f yes */
MTR_DCLSPC float MTR_CALL MTR_Log10_f(float num)
{
    return log10f(num);
}

/*fa MTR_Log10_d yes */
MTR_DCLSPC double MTR_CALL MTR_Log10_d(double num)
{
    return log10(num);
}

/*fa MTR_Log10Fast_f yes */
MTR_DCLSPC float MTR_CALL MTR_Log10Fast_f(float num)
{
    return log10f(num);
}

/*fa MTR_Log10Fast_d yes */
MTR_DCLSPC double MTR_CALL MTR_Log10Fast_d(double num)
{
    return log10(num);
}

/*fa MTR_Log2_f yes */
MTR_DCLSPC float MTR_CALL MTR_Log2_f(float num)
{
    return log2f(num);
}

/*fa MTR_Log2_d yes */
MTR_DCLSPC double MTR_CALL MTR_Log2_d(double num)
{
    return log2(num);
}

/*fa MTR_Log2Fast_f yes */
MTR_DCLSPC float MTR_CALL MTR_Log2Fast_f(float num)
{
    return log2f(num);
}

/*fa MTR_Log2Fast_d yes */
MTR_DCLSPC double MTR_CALL MTR_Log2Fast_d(double num)
{
    return log2(num);
}

/*fa MTR_Log_f yes */
MTR_DCLSPC float MTR_CALL MTR_Log_f(float num, float base)
{
    return log2f(num) / log2f(base);
}

/*fa MTR_Log_d yes */
MTR_DCLSPC double MTR_CALL MTR_Log_d(double num, double base)
{
    return log2(num) / log2(base);
}

/*fa MTR_LogFast_f yes */
MTR_DCLSPC float MTR_CALL MTR_LogFast_f(float num, float base)
{
    return log2f(num) / log2f(base);
}

/*fa MTR_LogFast_d yes */
MTR_DCLSPC double MTR_CALL MTR_LogFast_d(double num, double base)
{
    return log2(num) / log2(base);
}

/*fa MTR_Pow_f yes */
MTR_DCLSPC float MTR_CALL MTR_Pow_f(float base, float power)
{
    return powf(base, power);
}

/*fa MTR_Pow_d yes */
MTR_DCLSPC double MTR_CALL MTR_Pow_d(double base, double power)
{
    return pow(base, power);
}

/*fa MTR_PowFast_f yes */
MTR_DCLSPC float MTR_CALL MTR_PowFast_f(float base, float power)
{
    return powf(base, power);
}

/*fa MTR_PowFast_d yes */
MTR_DCLSPC double MTR_CALL MTR_PowFast_d(double base, double power)
{
    return pow(base, power);
}

/*fa MTR_Sqrt_f yes */
MTR_DCLSPC float MTR_CALL MTR_Sqrt_f(float num)
{
    return sqrtf(num);
}

/*fa MTR_Sqrt_d yes */
MTR_DCLSPC double MTR_CALL MTR_Sqrt_d(double num)
{
    return sqrt(num);
}

/*fa MTR_SqrtFast_f yes */
MTR_DCLSPC float MTR_CALL MTR_SqrtFast_f(float num)
{
    return sqrtf(num);
}

/*fa MTR_SqrtFast_d yes */
MTR_DCLSPC double MTR_CALL MTR_SqrtFast_d(double num)
{
    return sqrt(num);
}

/*fa MTR_Cbrt_f yes */
MTR_DCLSPC float MTR_CALL MTR_Cbrt_f(float num)
{
    return cbrtf(num);
}

/*fa MTR_Cbrt_d yes */
MTR_DCLSPC double MTR_CALL MTR_Cbrt_d(double num)
{
    return cbrt(num);
}

/*fa MTR_CbrtFast_f yes */
MTR_DCLSPC float MTR_CALL MTR_CbrtFast_f(float num)
{
    return cbrtf(num);
}

/*fa MTR_CbrtFast_d yes */
MTR_DCLSPC double MTR_CALL MTR_CbrtFast_d(double num)
{
    return cbrt(num);
}

/*fa MTR_Hypot_f yes */
MTR_DCLSPC float MTR_CALL MTR_Hypot_f(float x, float y)
{
    return hypotf(x, y);
}

/*fa MTR_Hypot_d yes */
MTR_DCLSPC double MTR_CALL MTR_Hypot_d(double x, double y)
{
    return hypot(x, y);
}

/*fa MTR_HypotFast_f yes */
MTR_DCLSPC float MTR_CALL MTR_HypotFast_f(float x, float y)
{
    float dx = fabsf(x);
    float dy = fabsf(y);

    return (0.5f * (dx + dy + fmaxf(dx, dy)));
}

/*fa MTR_HypotFast_d yes */
MTR_DCLSPC double MTR_CALL MTR_HypotFast_d(double x, double y)
{
    double dx = fabs(x);
    double dy = fabs(y);

    return (0.5 * (dx + dy + fmax(dx, dy)));
}

/*fa MTR_Angle_f yes */
MTR_DCLSPC float MTR_CALL MTR_Angle_f(float x, float y)
{
    float dir;

    dir = acosf(x / sqrtf(powf(-x, 2.0f) + powf(-y, 2.0f)));
    if (y > 0.0f)
        dir = MTR_2PI_F - dir;

    return dir * MTR_RADIAN_F;
}

/*fa MTR_Angle_d yes */
MTR_DCLSPC double MTR_CALL MTR_Angle_d(double x, double y)
{
    double dir;

    dir = acos(x / sqrt(pow(-x, 2.0) + pow(-y, 2.0)));
    if (y > 0.0)
        dir = MTR_2PI_D - dir;

    return dir * MTR_RADIAN_D;
}

/*fa MTR_AngleFast_f yes */
MTR_DCLSPC float MTR_CALL MTR_AngleFast_f(float x, float y)
{
    float dir;

    dir = acosf(x / sqrtf(powf(-x, 2.0f) + powf(-y, 2.0f)));
    if (y > 0.0f)
        dir = MTR_2PI_F - dir;

    return dir * MTR_RADIAN_F;
}

/*fa MTR_AngleFast_d yes */
MTR_DCLSPC double MTR_CALL MTR_AngleFast_d(double x, double y)
{
    double dir;

    dir = acos(x / sqrt(pow(-x, 2.0) + pow(-y, 2.0)));
    if (y > 0.0)
        dir = MTR_2PI_D - dir;

    return dir * MTR_RADIAN_D;
}

/*fa MTR_Vecx_f yes */
MTR_DCLSPC float MTR_CALL MTR_Vecx_f(float length, float dir)
{
    return (-(length * cosf((float)M_PI - dir * MTR_DEGREE_F)));
}

/*fa MTR_Vecx_d yes */
MTR_DCLSPC double MTR_CALL MTR_Vecx_d(double length, double dir)
{
    return (-(length * cos(M_PI - dir * MTR_DEGREE_D)));
}

/*fa MTR_VecxFast_f yes */
MTR_DCLSPC float MTR_CALL MTR_VecxFast_f(float length, float dir)
{
    return (-(length * cosf((float)M_PI - dir * MTR_DEGREE_F)));
}

/*fa MTR_VecxFast_d yes */
MTR_DCLSPC double MTR_CALL MTR_VecxFast_d(double length, double dir)
{
    return (-(length * cos(M_PI - dir * MTR_DEGREE_D)));
}

/*fa MTR_Vecy_f yes */
MTR_DCLSPC float MTR_CALL MTR_Vecy_f(float length, float dir)
{
    return (-(length * sinf((float)M_PI - dir * MTR_DEGREE_F)));
}

/*fa MTR_Vecy_d yes */
MTR_DCLSPC double MTR_CALL MTR_Vecy_d(double length, double dir)
{
    return (-(length * sin(M_PI - dir * MTR_DEGREE_D)));
}

/*fa MTR_VecyFast_f yes */
MTR_DCLSPC float MTR_CALL MTR_VecyFast_f(float length, float dir)
{
    return (-(length * sinf((float)M_PI - dir * MTR_DEGREE_F)));
}

/*fa MTR_VecyFast_d yes */
MTR_DCLSPC double MTR_CALL MTR_VecyFast_d(double length, double dir)
{
    return (-(length * sin(M_PI - dir * MTR_DEGREE_D)));
}

/*fa MTR_Vecxy_f yes */
MTR_DCLSPC void MTR_CALL MTR_Vecxy_f(float length, float dir, float *x, float *y)
{
    *x = -(length * cosf((float)M_PI - dir * MTR_DEGREE_F));
    *y = -(length * sinf((float)M_PI - dir * MTR_DEGREE_F));
}

/*fa MTR_Vecxy_d yes */
MTR_DCLSPC void MTR_CALL MTR_Vecxy_d(double length, double dir, double *x,
 double *y)
{
    *x = -(length * cos(M_PI - dir * MTR_DEGREE_D));
    *y = -(length * sin(M_PI - dir * MTR_DEGREE_D));
}

/*fa MTR_VecxyFast_f yes */
MTR_DCLSPC void MTR_CALL MTR_VecxyFast_f(float length, float dir, float *x,
 float *y)
{
    *x = -(length * cosf((float)M_PI - dir * MTR_DEGREE_F));
    *y = -(length * sinf((float)M_PI - dir * MTR_DEGREE_F));
}

/*fa MTR_VecxyFast_d yes */
MTR_DCLSPC void MTR_CALL MTR_VecxyFast_d(double length, double dir, double *x,
 double *y)
{
    *x = -(length * cos(M_PI - dir * MTR_DEGREE_D));
    *y = -(length * sin(M_PI - dir * MTR_DEGREE_D));
}

/*fa MTR_Rand yes */
MTR_DCLSPC int MTR_CALL MTR_Rand(int value)
{
    if (value < 0)
        return -(rand() % (-value + 1));

    return rand() % (value + 1);
}

/*fa MTR_RandRange yes */
MTR_DCLSPC int MTR_CALL MTR_RandRange(int min, int max)
{
    if (min > max)
        return (rand() % (min - max + 1)) + max;

    return (rand() % (max - min + 1)) + min;
}

/*fa MTR_RandSeed yes */
MTR_DCLSPC void MTR_CALL MTR_RandSeed(unsigned int seed)
{
    srand(seed);
}

/*fa MTR_RandSeedByTime yes */
MTR_DCLSPC void MTR_CALL MTR_RandSeedByTime(void)
{
    srand(time(NULL));
}

/*fa MTR_Abs yes */
MTR_DCLSPC int MTR_CALL MTR_Abs(int num)
{
    return abs(num);
}

/*fa MTR_Abs_l yes */
MTR_DCLSPC long int MTR_CALL MTR_Abs_l(long int num)
{
    return labs(num);
}

/*fa MTR_Abs_ll yes */
MTR_DCLSPC long long int MTR_CALL MTR_Abs_ll(long long int num)
{
    return llabs(num);
}

/*fa MTR_Abs_f yes */
MTR_DCLSPC float MTR_CALL MTR_Abs_f(float num)
{
    return fabsf(num);
}

/*fa MTR_Abs_d yes */
MTR_DCLSPC double MTR_CALL MTR_Abs_d(double num)
{
    return fabs(num);
}

/*fa MTR_Sign yes */
MTR_DCLSPC int MTR_CALL MTR_Sign(int num)
{
    return ((num > 0) ? 1 : ((num < 0) ? -1 : 0));
}

/*fa MTR_Sign_l yes */
MTR_DCLSPC long int MTR_CALL MTR_Sign_l(long int num)
{
    return ((num > 0) ? 1L : ((num < 0) ? -1L : 0L));
}

/*fa MTR_Sign_ll yes */
MTR_DCLSPC long long int MTR_CALL MTR_Sign_ll(long long int num)
{
    return ((num > 0) ? 1LL : ((num < 0) ? -1LL : 0LL));
}

/*fa MTR_Sign_f partial */
MTR_DCLSPC float MTR_CALL MTR_Sign_f(float num)
{
    return copysignf(1.0f, num);
}

/*fa MTR_Sign_d partial */
MTR_DCLSPC double MTR_CALL MTR_Sign_d(double num)
{
    return copysign(1.0, num);
}

/*fa MTR_Round_f yes */
MTR_DCLSPC float MTR_CALL MTR_Round_f(float num)
{
    return truncf(num);
}

/*fa MTR_Round_d yes */
MTR_DCLSPC double MTR_CALL MTR_Round_d(double num)
{
    return trunc(num);
}

/*fa MTR_Floor_f yes */
MTR_DCLSPC float MTR_CALL MTR_Floor_f(float num)
{
    return floorf(num);
}

/*fa MTR_Floor_d yes */
MTR_DCLSPC double MTR_CALL MTR_Floor_d(double num)
{
    return floor(num);
}

/*fa MTR_Ceil_f yes */
MTR_DCLSPC float MTR_CALL MTR_Ceil_f(float num)
{
    return ceilf(num);
}

/*fa MTR_Ceil_d yes */
MTR_DCLSPC double MTR_CALL MTR_Ceil_d(double num)
{
    return ceil(num);
}

/*fa MTR_Mod yes */
MTR_DCLSPC int MTR_CALL MTR_Mod(int num, int denom)
{
    div_t result = div(num, denom);
    return result.rem;
}

/*fa MTR_Mod_l yes */
MTR_DCLSPC long int MTR_CALL MTR_Mod_l(long int num, long int denom)
{
    ldiv_t result = ldiv(num, denom);
    return result.rem;
}

/*fa MTR_Mod_ll yes */
MTR_DCLSPC long long int MTR_CALL MTR_Mod_ll(long long int num,
 long long int denom)
{
    lldiv_t result = lldiv(num, denom);
    return result.rem;
}

/*fa MTR_Mod_f yes */
MTR_DCLSPC float MTR_CALL MTR_Mod_f(float num, float denom)
{
    return fmodf(num, denom);
}

/*fa MTR_Mod_d yes */
MTR_DCLSPC double MTR_CALL MTR_Mod_d(double num, double denom)
{
    return fmod(num, denom);
}

/*fa MTR_Min yes */
MTR_DCLSPC int MTR_CALL MTR_Min(int num1, int num2)
{
    return ((num1 < num2) ? num1 : num2);
}

/*fa MTR_Min_l yes */
MTR_DCLSPC long int MTR_CALL MTR_Min_l(long int num1, long int num2)
{
    return ((num1 < num2) ? num1 : num2);
}

/*fa MTR_Min_ll yes */
MTR_DCLSPC long long int MTR_CALL MTR_Min_ll(long long int num1,
 long long int num2)
{
    return ((num1 < num2) ? num1 : num2);
}

/*fa MTR_Min_f yes */
MTR_DCLSPC float MTR_CALL MTR_Min_f(float num1, float num2)
{
    return fminf(num1, num2);
}

/*fa MTR_Min_d yes */
MTR_DCLSPC double MTR_CALL MTR_Min_d(double num1, double num2)
{
    return fmin(num1, num2);
}

/*fa MTR_Max yes */
MTR_DCLSPC int MTR_CALL MTR_Max(int num1, int num2)
{
    return ((num1 > num2) ? num1 : num2);
}

/*fa MTR_Max_l yes */
MTR_DCLSPC long int MTR_CALL MTR_Max_l(long int num1, long int num2)
{
    return ((num1 > num2) ? num1 : num2);
}

/*fa MTR_Max_ll yes */
MTR_DCLSPC long long int MTR_CALL MTR_Max_ll(long long int num1,
 long long int num2)
{
    return ((num1 > num2) ? num1 : num2);
}

/*fa MTR_Max_f yes */
MTR_DCLSPC float MTR_CALL MTR_Max_f(float num1, float num2)
{
    return fmaxf(num1, num2);
}

/*fa MTR_Max_d yes */
MTR_DCLSPC double MTR_CALL MTR_Max_d(double num1, double num2)
{
    return fmax(num1, num2);
}
