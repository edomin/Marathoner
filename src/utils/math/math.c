#include "math.h"

#include "marathoner/plugin_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
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

MTR_EXPORT float MTR_CALL mtrSin_f(float num)
{
    return sinf(num * MTR_DEGREE_F);
}

MTR_EXPORT double MTR_CALL mtrSin_d(double num)
{
    return sin(num * MTR_DEGREE_D);
}

/* http://lab.polygonal.de/2007/07/18/fast-and-accurate-sinecosine-approximation/ */
MTR_EXPORT float MTR_CALL mtrSinFast_f(float num)
{
    float sine;
    float num2 = num * MTR_DEGREE_F;
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
MTR_EXPORT double MTR_CALL mtrSinFast_d(double num)
{
    double sine;
    double num2 = num * MTR_DEGREE_D;
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

MTR_EXPORT float MTR_CALL mtrCos_f(float num)
{
    return cosf(num * MTR_DEGREE_F);
}

MTR_EXPORT double MTR_CALL mtrCos_d(double num)
{
    return cos(num * MTR_DEGREE_D);
}

/* http://lab.polygonal.de/2007/07/18/fast-and-accurate-sinecosine-approximation/ */
MTR_EXPORT float MTR_CALL mtrCosFast_f(float num)
{
    float num2 = num * MTR_DEGREE_F;

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
MTR_EXPORT double MTR_CALL mtrCosFast_d(double num)
{
    double num2 = num * MTR_DEGREE_D;

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

MTR_EXPORT float MTR_CALL mtrTan_f(float num)
{
    return tanf(num * MTR_DEGREE_F);
}

MTR_EXPORT double MTR_CALL mtrTan_d(double num)
{
    return tan(num * MTR_DEGREE_D);
}

MTR_EXPORT float MTR_CALL mtrTanFast_f(float num)
{
    return tanf(num * MTR_DEGREE_F);
}

MTR_EXPORT double MTR_CALL mtrTanFast_d(double num)
{
    return tan(num * MTR_DEGREE_D);
}

MTR_EXPORT float MTR_CALL mtrAsin_f(float num)
{
    return asinf(num) * MTR_RADIAN_F;
}

MTR_EXPORT double MTR_CALL mtrAsin_d(double num)
{
    return asin(num) * MTR_RADIAN_D;
}

MTR_EXPORT float MTR_CALL mtrAsinFast_f(float num)
{
    return asinf(num) * MTR_RADIAN_F;
}

MTR_EXPORT double MTR_CALL mtrAsinFast_d(double num)
{
    return asin(num) * MTR_RADIAN_D;
}

MTR_EXPORT float MTR_CALL mtrAcos_f(float num)
{
    return acosf(num) * MTR_RADIAN_F;
}

MTR_EXPORT double MTR_CALL mtrAcos_d(double num)
{
    return acos(num) * MTR_RADIAN_D;
}

MTR_EXPORT float MTR_CALL mtrAcosFast_f(float num)
{
    return acosf(num) * MTR_RADIAN_F;
}

MTR_EXPORT double MTR_CALL mtrAcosFast_d(double num)
{
    return acos(num) * MTR_RADIAN_D;
}

MTR_EXPORT float MTR_CALL mtrAtan_f(float num)
{
    return atanf(num) * MTR_RADIAN_F;
}

MTR_EXPORT double MTR_CALL mtrAtan_d(double num)
{
    return atan(num) * MTR_RADIAN_D;
}

MTR_EXPORT float MTR_CALL mtrAtanFast_f(float num)
{
    return atanf(num) * MTR_RADIAN_F;
}

MTR_EXPORT double MTR_CALL mtrAtanFast_d(double num)
{
    return atan(num) * MTR_RADIAN_D;
}

MTR_EXPORT float MTR_CALL mtrLoge_f(float num)
{
    return logf(num);
}

MTR_EXPORT double MTR_CALL mtrLoge_d(double num)
{
    return log(num);
}

MTR_EXPORT float MTR_CALL mtrLogeFast_f(float num)
{
    return logf(num);
}

MTR_EXPORT double MTR_CALL mtrLogeFast_d(double num)
{
    return log(num);
}

MTR_EXPORT float MTR_CALL mtrLog10_f(float num)
{
    return log10f(num);
}

MTR_EXPORT double MTR_CALL mtrLog10_d(double num)
{
    return log10(num);
}

MTR_EXPORT float MTR_CALL mtrLog10Fast_f(float num)
{
    return log10f(num);
}

MTR_EXPORT double MTR_CALL mtrLog10Fast_d(double num)
{
    return log10(num);
}

MTR_EXPORT float MTR_CALL mtrLog2_f(float num)
{
    return log2f(num);
}

MTR_EXPORT double MTR_CALL mtrLog2_d(double num)
{
    return log2(num);
}

MTR_EXPORT float MTR_CALL mtrLog2Fast_f(float num)
{
    return log2f(num);
}

MTR_EXPORT double MTR_CALL mtrLog2Fast_d(double num)
{
    return log2(num);
}

MTR_EXPORT float MTR_CALL mtrLog_f(float num, float base)
{
    return log2f(num) / log2f(base);
}

MTR_EXPORT double MTR_CALL mtrLog_d(double num, double base)
{
    return log2(num) / log2(base);
}

MTR_EXPORT float MTR_CALL mtrLogFast_f(float num, float base)
{
    return log2f(num) / log2f(base);
}

MTR_EXPORT double MTR_CALL mtrLogFast_d(double num, double base)
{
    return log2(num) / log2(base);
}

MTR_EXPORT float MTR_CALL mtrPow_f(float base, float power)
{
    return powf(base, power);
}

MTR_EXPORT double MTR_CALL mtrPow_d(double base, double power)
{
    return pow(base, power);
}

MTR_EXPORT float MTR_CALL mtrPowFast_f(float base, float power)
{
    return powf(base, power);
}

MTR_EXPORT double MTR_CALL mtrPowFast_d(double base, double power)
{
    return pow(base, power);
}

MTR_EXPORT float MTR_CALL mtrSqrt_f(float num)
{
    return sqrtf(num);
}

MTR_EXPORT double MTR_CALL mtrSqrt_d(double num)
{
    return sqrt(num);
}

MTR_EXPORT float MTR_CALL mtrSqrtFast_f(float num)
{
    return sqrtf(num);
}

MTR_EXPORT double MTR_CALL mtrSqrtFast_d(double num)
{
    return sqrt(num);
}

MTR_EXPORT float MTR_CALL mtrCbrt_f(float num)
{
    return cbrtf(num);
}

MTR_EXPORT double MTR_CALL mtrCbrt_d(double num)
{
    return cbrt(num);
}

MTR_EXPORT float MTR_CALL mtrCbrtFast_f(float num)
{
    return cbrtf(num);
}

MTR_EXPORT double MTR_CALL mtrCbrtFast_d(double num)
{
    return cbrt(num);
}

MTR_EXPORT float MTR_CALL mtrHypot_f(float x, float y)
{
    return hypotf(x, y);
}

MTR_EXPORT double MTR_CALL mtrHypot_d(double x, double y)
{
    return hypot(x, y);
}

MTR_EXPORT float MTR_CALL mtrHypotFast_f(float x, float y)
{
    float dx = fabsf(x);
    float dy = fabsf(y);

    return (0.5f * (dx + dy + fmaxf(dx, dy)));
}

MTR_EXPORT double MTR_CALL mtrHypotFast_d(double x, double y)
{
    double dx = fabs(x);
    double dy = fabs(y);

    return (0.5 * (dx + dy + fmax(dx, dy)));
}

MTR_EXPORT float MTR_CALL mtrAngle_f(float x, float y)
{
    float dir;

    dir = acosf(x / sqrtf(powf(-x, 2.0f) + powf(-y, 2.0f)));
    if (y > 0.0f)
        dir = MTR_2PI_F - dir;

    return dir * MTR_RADIAN_F;
}

MTR_EXPORT double MTR_CALL mtrAngle_d(double x, double y)
{
    double dir;

    dir = acos(x / sqrt(pow(-x, 2.0) + pow(-y, 2.0)));
    if (y > 0.0)
        dir = MTR_2PI_D - dir;

    return dir * MTR_RADIAN_D;
}

MTR_EXPORT float MTR_CALL mtrAngleFast_f(float x, float y)
{
    float dir;

    dir = acosf(x / sqrtf(powf(-x, 2.0f) + powf(-y, 2.0f)));
    if (y > 0.0f)
        dir = MTR_2PI_F - dir;

    return dir * MTR_RADIAN_F;
}

MTR_EXPORT double MTR_CALL mtrAngleFast_d(double x, double y)
{
    double dir;

    dir = acos(x / sqrt(pow(-x, 2.0) + pow(-y, 2.0)));
    if (y > 0.0)
        dir = MTR_2PI_D - dir;

    return dir * MTR_RADIAN_D;
}

MTR_EXPORT float MTR_CALL mtrVecx_f(float length, float dir)
{
    return (-(length * cosf((float)M_PI - dir * MTR_DEGREE_F)));
}

MTR_EXPORT double MTR_CALL mtrVecx_d(double length, double dir)
{
    return (-(length * cos(M_PI - dir * MTR_DEGREE_D)));
}

MTR_EXPORT float MTR_CALL mtrVecxFast_f(float length, float dir)
{
    return (-(length * cosf((float)M_PI - dir * MTR_DEGREE_F)));
}

MTR_EXPORT double MTR_CALL mtrVecxFast_d(double length, double dir)
{
    return (-(length * cos(M_PI - dir * MTR_DEGREE_D)));
}

MTR_EXPORT float MTR_CALL mtrVecy_f(float length, float dir)
{
    return (-(length * sinf((float)M_PI - dir * MTR_DEGREE_F)));
}

MTR_EXPORT double MTR_CALL mtrVecy_d(double length, double dir)
{
    return (-(length * sin(M_PI - dir * MTR_DEGREE_D)));
}

MTR_EXPORT float MTR_CALL mtrVecyFast_f(float length, float dir)
{
    return (-(length * sinf((float)M_PI - dir * MTR_DEGREE_F)));
}

MTR_EXPORT double MTR_CALL mtrVecyFast_d(double length, double dir)
{
    return (-(length * sin(M_PI - dir * MTR_DEGREE_D)));
}

MTR_EXPORT void MTR_CALL mtrVecxy_f(float length, float dir, float *x, float *y)
{
    *x = -(length * cosf((float)M_PI - dir * MTR_DEGREE_F));
    *y = -(length * sinf((float)M_PI - dir * MTR_DEGREE_F));
}

MTR_EXPORT void MTR_CALL mtrVecxy_d(double length, double dir, double *x,
 double *y)
{
    *x = -(length * cos(M_PI - dir * MTR_DEGREE_D));
    *y = -(length * sin(M_PI - dir * MTR_DEGREE_D));
}

MTR_EXPORT void MTR_CALL mtrVecxyFast_f(float length, float dir, float *x,
 float *y)
{
    *x = -(length * cosf((float)M_PI - dir * MTR_DEGREE_F));
    *y = -(length * sinf((float)M_PI - dir * MTR_DEGREE_F));
}

MTR_EXPORT void MTR_CALL mtrVecxyFast_d(double length, double dir, double *x,
 double *y)
{
    *x = -(length * cos(M_PI - dir * MTR_DEGREE_D));
    *y = -(length * sin(M_PI - dir * MTR_DEGREE_D));
}

MTR_EXPORT int MTR_CALL mtrRand(int value)
{
    if (value < 0)
        return -(rand() % (-value + 1));

    return rand() % (value + 1);
}

MTR_EXPORT int MTR_CALL mtrRandRange(int min, int max)
{
    if (min > max)
        return (rand() % (min - max + 1)) + max;

    return (rand() % (max - min + 1)) + min;
}

MTR_EXPORT void MTR_CALL mtrRandSeed(unsigned int seed)
{
    srand(seed);
}

MTR_EXPORT void MTR_CALL mtrRandSeedByTime(void)
{
    srand(time(NULL));
}

MTR_EXPORT int MTR_CALL mtrAbs(int num)
{
    return abs(num);
}

MTR_EXPORT long int MTR_CALL mtrAbs_l(long int num)
{
    return labs(num);
}

MTR_EXPORT long long int MTR_CALL mtrAbs_ll(long long int num)
{
    return llabs(num);
}

MTR_EXPORT float MTR_CALL mtrAbs_f(float num)
{
    return fabsf(num);
}

MTR_EXPORT double MTR_CALL mtrAbs_d(double num)
{
    return fabs(num);
}

MTR_EXPORT int MTR_CALL mtrSign(int num)
{
    return ((num > 0) ? 1 : ((num < 0) ? -1 : 0));
}

MTR_EXPORT long int MTR_CALL mtrSign_l(long int num)
{
    return ((num > 0) ? 1L : ((num < 0) ? -1L : 0L));
}

MTR_EXPORT long long int MTR_CALL mtrSign_ll(long long int num)
{
    return ((num > 0) ? 1LL : ((num < 0) ? -1LL : 0LL));
}

MTR_EXPORT float MTR_CALL mtrSign_f(float num)
{
    return copysignf(1.0f, num);
}

MTR_EXPORT double MTR_CALL mtrSign_d(double num)
{
    return copysign(1.0, num);
}

MTR_EXPORT float MTR_CALL mtrRound_f(float num)
{
    return truncf(num);
}

MTR_EXPORT double MTR_CALL mtrRound_d(double num)
{
    return trunc(num);
}

MTR_EXPORT float MTR_CALL mtrFloor_f(float num)
{
    return floorf(num);
}

MTR_EXPORT double MTR_CALL mtrFloor_d(double num)
{
    return floor(num);
}

MTR_EXPORT float MTR_CALL mtrCeil_f(float num)
{
    return ceilf(num);
}

MTR_EXPORT double MTR_CALL mtrCeil_d(double num)
{
    return ceil(num);
}

MTR_EXPORT int MTR_CALL mtrMod(int num, int denom)
{
    div_t result = div(num, denom);
    return result.rem;
}

MTR_EXPORT long int MTR_CALL mtrMod_l(long int num, long int denom)
{
    ldiv_t result = ldiv(num, denom);
    return result.rem;
}

MTR_EXPORT long long int MTR_CALL mtrMod_ll(long long int num,
 long long int denom)
{
    lldiv_t result = lldiv(num, denom);
    return result.rem;
}

MTR_EXPORT float MTR_CALL mtrMod_f(float num, float denom)
{
    return fmodf(num, denom);
}

MTR_EXPORT double MTR_CALL mtrMod_d(double num, double denom)
{
    return fmod(num, denom);
}

MTR_EXPORT int MTR_CALL mtrMin(int num1, int num2)
{
    return ((num1 < num2) ? num1 : num2);
}

MTR_EXPORT long int MTR_CALL mtrMin_l(long int num1, long int num2)
{
    return ((num1 < num2) ? num1 : num2);
}

MTR_EXPORT long long int MTR_CALL mtrMin_ll(long long int num1,
 long long int num2)
{
    return ((num1 < num2) ? num1 : num2);
}

MTR_EXPORT float MTR_CALL mtrMin_f(float num1, float num2)
{
    return fminf(num1, num2);
}

MTR_EXPORT double MTR_CALL mtrMin_d(double num1, double num2)
{
    return fmin(num1, num2);
}

MTR_EXPORT int MTR_CALL mtrMax(int num1, int num2)
{
    return ((num1 > num2) ? num1 : num2);
}

MTR_EXPORT long int MTR_CALL mtrMax_l(long int num1, long int num2)
{
    return ((num1 > num2) ? num1 : num2);
}

MTR_EXPORT long long int MTR_CALL mtrMax_ll(long long int num1,
 long long int num2)
{
    return ((num1 > num2) ? num1 : num2);
}

MTR_EXPORT float MTR_CALL mtrMax_f(float num1, float num2)
{
    return fmaxf(num1, num2);
}

MTR_EXPORT double MTR_CALL mtrMax_d(double num1, double num2)
{
    return fmax(num1, num2);
}
