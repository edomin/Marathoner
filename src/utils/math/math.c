#include "math.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Math, FA_FUNCTIONS_COUNT)

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

/*fa mtrSin_f yes */
MTR_EXPORT float MTR_CALL mtrSin_f(float num)
{
    return sinf(num * MTR_DEGREE_F);
}

/*fa mtrSin_d yes */
MTR_EXPORT double MTR_CALL mtrSin_d(double num)
{
    return sin(num * MTR_DEGREE_D);
}

/* http://lab.polygonal.de/2007/07/18/fast-and-accurate-sinecosine-approximation/ */
/*fa mtrSinFast_f yes */
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
/*fa mtrSinFast_d yes */
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

/*fa mtrCos_f yes */
MTR_EXPORT float MTR_CALL mtrCos_f(float num)
{
    return cosf(num * MTR_DEGREE_F);
}

/*fa mtrCos_d yes */
MTR_EXPORT double MTR_CALL mtrCos_d(double num)
{
    return cos(num * MTR_DEGREE_D);
}

/* http://lab.polygonal.de/2007/07/18/fast-and-accurate-sinecosine-approximation/ */
/*fa mtrCosFast_f yes */
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
/*fa mtrCosFast_d yes */
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

/*fa mtrTan_f yes */
MTR_EXPORT float MTR_CALL mtrTan_f(float num)
{
    return tanf(num * MTR_DEGREE_F);
}

/*fa mtrTan_d yes */
MTR_EXPORT double MTR_CALL mtrTan_d(double num)
{
    return tan(num * MTR_DEGREE_D);
}

/*fa mtrTanFast_f yes */
MTR_EXPORT float MTR_CALL mtrTanFast_f(float num)
{
    return tanf(num * MTR_DEGREE_F);
}

/*fa mtrTanFast_d yes */
MTR_EXPORT double MTR_CALL mtrTanFast_d(double num)
{
    return tan(num * MTR_DEGREE_D);
}

/*fa mtrAsin_f yes */
MTR_EXPORT float MTR_CALL mtrAsin_f(float num)
{
    return asinf(num) * MTR_RADIAN_F;
}

/*fa mtrAsin_d yes */
MTR_EXPORT double MTR_CALL mtrAsin_d(double num)
{
    return asin(num) * MTR_RADIAN_D;
}

/*fa mtrAsinFast_f yes */
MTR_EXPORT float MTR_CALL mtrAsinFast_f(float num)
{
    return asinf(num) * MTR_RADIAN_F;
}

/*fa mtrAsinFast_d yes */
MTR_EXPORT double MTR_CALL mtrAsinFast_d(double num)
{
    return asin(num) * MTR_RADIAN_D;
}

/*fa mtrAcos_f yes */
MTR_EXPORT float MTR_CALL mtrAcos_f(float num)
{
    return acosf(num) * MTR_RADIAN_F;
}

/*fa mtrAcos_d yes */
MTR_EXPORT double MTR_CALL mtrAcos_d(double num)
{
    return acos(num) * MTR_RADIAN_D;
}

/*fa mtrAcosFast_f yes */
MTR_EXPORT float MTR_CALL mtrAcosFast_f(float num)
{
    return acosf(num) * MTR_RADIAN_F;
}

/*fa mtrAcosFast_d yes */
MTR_EXPORT double MTR_CALL mtrAcosFast_d(double num)
{
    return acos(num) * MTR_RADIAN_D;
}

/*fa mtrAtan_f yes */
MTR_EXPORT float MTR_CALL mtrAtan_f(float num)
{
    return atanf(num) * MTR_RADIAN_F;
}

/*fa mtrAtan_d yes */
MTR_EXPORT double MTR_CALL mtrAtan_d(double num)
{
    return atan(num) * MTR_RADIAN_D;
}

/*fa mtrAtanFast_f yes */
MTR_EXPORT float MTR_CALL mtrAtanFast_f(float num)
{
    return atanf(num) * MTR_RADIAN_F;
}

/*fa mtrAtanFast_d yes */
MTR_EXPORT double MTR_CALL mtrAtanFast_d(double num)
{
    return atan(num) * MTR_RADIAN_D;
}

/*fa mtrLoge_f yes */
MTR_EXPORT float MTR_CALL mtrLoge_f(float num)
{
    return logf(num);
}

/*fa mtrLoge_d yes */
MTR_EXPORT double MTR_CALL mtrLoge_d(double num)
{
    return log(num);
}

/*fa mtrLogeFast_f yes */
MTR_EXPORT float MTR_CALL mtrLogeFast_f(float num)
{
    return logf(num);
}

/*fa mtrLogeFast_d yes */
MTR_EXPORT double MTR_CALL mtrLogeFast_d(double num)
{
    return log(num);
}

/*fa mtrLog10_f yes */
MTR_EXPORT float MTR_CALL mtrLog10_f(float num)
{
    return log10f(num);
}

/*fa mtrLog10_d yes */
MTR_EXPORT double MTR_CALL mtrLog10_d(double num)
{
    return log10(num);
}

/*fa mtrLog10Fast_f yes */
MTR_EXPORT float MTR_CALL mtrLog10Fast_f(float num)
{
    return log10f(num);
}

/*fa mtrLog10Fast_d yes */
MTR_EXPORT double MTR_CALL mtrLog10Fast_d(double num)
{
    return log10(num);
}

/*fa mtrLog2_f yes */
MTR_EXPORT float MTR_CALL mtrLog2_f(float num)
{
    return log2f(num);
}

/*fa mtrLog2_d yes */
MTR_EXPORT double MTR_CALL mtrLog2_d(double num)
{
    return log2(num);
}

/*fa mtrLog2Fast_f yes */
MTR_EXPORT float MTR_CALL mtrLog2Fast_f(float num)
{
    return log2f(num);
}

/*fa mtrLog2Fast_d yes */
MTR_EXPORT double MTR_CALL mtrLog2Fast_d(double num)
{
    return log2(num);
}

/*fa mtrLog_f yes */
MTR_EXPORT float MTR_CALL mtrLog_f(float num, float base)
{
    return log2f(num) / log2f(base);
}

/*fa mtrLog_d yes */
MTR_EXPORT double MTR_CALL mtrLog_d(double num, double base)
{
    return log2(num) / log2(base);
}

/*fa mtrLogFast_f yes */
MTR_EXPORT float MTR_CALL mtrLogFast_f(float num, float base)
{
    return log2f(num) / log2f(base);
}

/*fa mtrLogFast_d yes */
MTR_EXPORT double MTR_CALL mtrLogFast_d(double num, double base)
{
    return log2(num) / log2(base);
}

/*fa mtrPow_f yes */
MTR_EXPORT float MTR_CALL mtrPow_f(float base, float power)
{
    return powf(base, power);
}

/*fa mtrPow_d yes */
MTR_EXPORT double MTR_CALL mtrPow_d(double base, double power)
{
    return pow(base, power);
}

/*fa mtrPowFast_f yes */
MTR_EXPORT float MTR_CALL mtrPowFast_f(float base, float power)
{
    return powf(base, power);
}

/*fa mtrPowFast_d yes */
MTR_EXPORT double MTR_CALL mtrPowFast_d(double base, double power)
{
    return pow(base, power);
}

/*fa mtrSqrt_f yes */
MTR_EXPORT float MTR_CALL mtrSqrt_f(float num)
{
    return sqrtf(num);
}

/*fa mtrSqrt_d yes */
MTR_EXPORT double MTR_CALL mtrSqrt_d(double num)
{
    return sqrt(num);
}

/*fa mtrSqrtFast_f yes */
MTR_EXPORT float MTR_CALL mtrSqrtFast_f(float num)
{
    return sqrtf(num);
}

/*fa mtrSqrtFast_d yes */
MTR_EXPORT double MTR_CALL mtrSqrtFast_d(double num)
{
    return sqrt(num);
}

/*fa mtrCbrt_f yes */
MTR_EXPORT float MTR_CALL mtrCbrt_f(float num)
{
    return cbrtf(num);
}

/*fa mtrCbrt_d yes */
MTR_EXPORT double MTR_CALL mtrCbrt_d(double num)
{
    return cbrt(num);
}

/*fa mtrCbrtFast_f yes */
MTR_EXPORT float MTR_CALL mtrCbrtFast_f(float num)
{
    return cbrtf(num);
}

/*fa mtrCbrtFast_d yes */
MTR_EXPORT double MTR_CALL mtrCbrtFast_d(double num)
{
    return cbrt(num);
}

/*fa mtrHypot_f yes */
MTR_EXPORT float MTR_CALL mtrHypot_f(float x, float y)
{
    return hypotf(x, y);
}

/*fa mtrHypot_d yes */
MTR_EXPORT double MTR_CALL mtrHypot_d(double x, double y)
{
    return hypot(x, y);
}

/*fa mtrHypotFast_f yes */
MTR_EXPORT float MTR_CALL mtrHypotFast_f(float x, float y)
{
    float dx = fabsf(x);
    float dy = fabsf(y);

    return (0.5f * (dx + dy + fmaxf(dx, dy)));
}

/*fa mtrHypotFast_d yes */
MTR_EXPORT double MTR_CALL mtrHypotFast_d(double x, double y)
{
    double dx = fabs(x);
    double dy = fabs(y);

    return (0.5 * (dx + dy + fmax(dx, dy)));
}

/*fa mtrAngle_f yes */
MTR_EXPORT float MTR_CALL mtrAngle_f(float x, float y)
{
    float dir;

    dir = acosf(x / sqrtf(powf(-x, 2.0f) + powf(-y, 2.0f)));
    if (y > 0.0f)
        dir = MTR_2PI_F - dir;

    return dir * MTR_RADIAN_F;
}

/*fa mtrAngle_d yes */
MTR_EXPORT double MTR_CALL mtrAngle_d(double x, double y)
{
    double dir;

    dir = acos(x / sqrt(pow(-x, 2.0) + pow(-y, 2.0)));
    if (y > 0.0)
        dir = MTR_2PI_D - dir;

    return dir * MTR_RADIAN_D;
}

/*fa mtrAngleFast_f yes */
MTR_EXPORT float MTR_CALL mtrAngleFast_f(float x, float y)
{
    float dir;

    dir = acosf(x / sqrtf(powf(-x, 2.0f) + powf(-y, 2.0f)));
    if (y > 0.0f)
        dir = MTR_2PI_F - dir;

    return dir * MTR_RADIAN_F;
}

/*fa mtrAngleFast_d yes */
MTR_EXPORT double MTR_CALL mtrAngleFast_d(double x, double y)
{
    double dir;

    dir = acos(x / sqrt(pow(-x, 2.0) + pow(-y, 2.0)));
    if (y > 0.0)
        dir = MTR_2PI_D - dir;

    return dir * MTR_RADIAN_D;
}

/*fa mtrVecx_f yes */
MTR_EXPORT float MTR_CALL mtrVecx_f(float length, float dir)
{
    return (-(length * cosf((float)M_PI - dir * MTR_DEGREE_F)));
}

/*fa mtrVecx_d yes */
MTR_EXPORT double MTR_CALL mtrVecx_d(double length, double dir)
{
    return (-(length * cos(M_PI - dir * MTR_DEGREE_D)));
}

/*fa mtrVecxFast_f yes */
MTR_EXPORT float MTR_CALL mtrVecxFast_f(float length, float dir)
{
    return (-(length * cosf((float)M_PI - dir * MTR_DEGREE_F)));
}

/*fa mtrVecxFast_d yes */
MTR_EXPORT double MTR_CALL mtrVecxFast_d(double length, double dir)
{
    return (-(length * cos(M_PI - dir * MTR_DEGREE_D)));
}

/*fa mtrVecy_f yes */
MTR_EXPORT float MTR_CALL mtrVecy_f(float length, float dir)
{
    return (-(length * sinf((float)M_PI - dir * MTR_DEGREE_F)));
}

/*fa mtrVecy_d yes */
MTR_EXPORT double MTR_CALL mtrVecy_d(double length, double dir)
{
    return (-(length * sin(M_PI - dir * MTR_DEGREE_D)));
}

/*fa mtrVecyFast_f yes */
MTR_EXPORT float MTR_CALL mtrVecyFast_f(float length, float dir)
{
    return (-(length * sinf((float)M_PI - dir * MTR_DEGREE_F)));
}

/*fa mtrVecyFast_d yes */
MTR_EXPORT double MTR_CALL mtrVecyFast_d(double length, double dir)
{
    return (-(length * sin(M_PI - dir * MTR_DEGREE_D)));
}

/*fa mtrVecxy_f yes */
MTR_EXPORT void MTR_CALL mtrVecxy_f(float length, float dir, float *x, float *y)
{
    *x = -(length * cosf((float)M_PI - dir * MTR_DEGREE_F));
    *y = -(length * sinf((float)M_PI - dir * MTR_DEGREE_F));
}

/*fa mtrVecxy_d yes */
MTR_EXPORT void MTR_CALL mtrVecxy_d(double length, double dir, double *x,
 double *y)
{
    *x = -(length * cos(M_PI - dir * MTR_DEGREE_D));
    *y = -(length * sin(M_PI - dir * MTR_DEGREE_D));
}

/*fa mtrVecxyFast_f yes */
MTR_EXPORT void MTR_CALL mtrVecxyFast_f(float length, float dir, float *x,
 float *y)
{
    *x = -(length * cosf((float)M_PI - dir * MTR_DEGREE_F));
    *y = -(length * sinf((float)M_PI - dir * MTR_DEGREE_F));
}

/*fa mtrVecxyFast_d yes */
MTR_EXPORT void MTR_CALL mtrVecxyFast_d(double length, double dir, double *x,
 double *y)
{
    *x = -(length * cos(M_PI - dir * MTR_DEGREE_D));
    *y = -(length * sin(M_PI - dir * MTR_DEGREE_D));
}

/*fa mtrRand yes */
MTR_EXPORT int MTR_CALL mtrRand(int value)
{
    if (value < 0)
        return -(rand() % (-value + 1));

    return rand() % (value + 1);
}

/*fa mtrRandRange yes */
MTR_EXPORT int MTR_CALL mtrRandRange(int min, int max)
{
    if (min > max)
        return (rand() % (min - max + 1)) + max;

    return (rand() % (max - min + 1)) + min;
}

/*fa mtrRandSeed yes */
MTR_EXPORT void MTR_CALL mtrRandSeed(unsigned int seed)
{
    srand(seed);
}

/*fa mtrRandSeedByTime yes */
MTR_EXPORT void MTR_CALL mtrRandSeedByTime(void)
{
    srand(time(NULL));
}

/*fa mtrAbs yes */
MTR_EXPORT int MTR_CALL mtrAbs(int num)
{
    return abs(num);
}

/*fa mtrAbs_l yes */
MTR_EXPORT long int MTR_CALL mtrAbs_l(long int num)
{
    return labs(num);
}

/*fa mtrAbs_ll yes */
MTR_EXPORT long long int MTR_CALL mtrAbs_ll(long long int num)
{
    return llabs(num);
}

/*fa mtrAbs_f yes */
MTR_EXPORT float MTR_CALL mtrAbs_f(float num)
{
    return fabsf(num);
}

/*fa mtrAbs_d yes */
MTR_EXPORT double MTR_CALL mtrAbs_d(double num)
{
    return fabs(num);
}

/*fa mtrSign yes */
MTR_EXPORT int MTR_CALL mtrSign(int num)
{
    return ((num > 0) ? 1 : ((num < 0) ? -1 : 0));
}

/*fa mtrSign_l yes */
MTR_EXPORT long int MTR_CALL mtrSign_l(long int num)
{
    return ((num > 0) ? 1L : ((num < 0) ? -1L : 0L));
}

/*fa mtrSign_ll yes */
MTR_EXPORT long long int MTR_CALL mtrSign_ll(long long int num)
{
    return ((num > 0) ? 1LL : ((num < 0) ? -1LL : 0LL));
}

/*fa mtrSign_f partial */
MTR_EXPORT float MTR_CALL mtrSign_f(float num)
{
    return copysignf(1.0f, num);
}

/*fa mtrSign_d partial */
MTR_EXPORT double MTR_CALL mtrSign_d(double num)
{
    return copysign(1.0, num);
}

/*fa mtrRound_f yes */
MTR_EXPORT float MTR_CALL mtrRound_f(float num)
{
    return truncf(num);
}

/*fa mtrRound_d yes */
MTR_EXPORT double MTR_CALL mtrRound_d(double num)
{
    return trunc(num);
}

/*fa mtrFloor_f yes */
MTR_EXPORT float MTR_CALL mtrFloor_f(float num)
{
    return floorf(num);
}

/*fa mtrFloor_d yes */
MTR_EXPORT double MTR_CALL mtrFloor_d(double num)
{
    return floor(num);
}

/*fa mtrCeil_f yes */
MTR_EXPORT float MTR_CALL mtrCeil_f(float num)
{
    return ceilf(num);
}

/*fa mtrCeil_d yes */
MTR_EXPORT double MTR_CALL mtrCeil_d(double num)
{
    return ceil(num);
}

/*fa mtrMod yes */
MTR_EXPORT int MTR_CALL mtrMod(int num, int denom)
{
    div_t result = div(num, denom);
    return result.rem;
}

/*fa mtrMod_l yes */
MTR_EXPORT long int MTR_CALL mtrMod_l(long int num, long int denom)
{
    ldiv_t result = ldiv(num, denom);
    return result.rem;
}

/*fa mtrMod_ll yes */
MTR_EXPORT long long int MTR_CALL mtrMod_ll(long long int num,
 long long int denom)
{
    lldiv_t result = lldiv(num, denom);
    return result.rem;
}

/*fa mtrMod_f yes */
MTR_EXPORT float MTR_CALL mtrMod_f(float num, float denom)
{
    return fmodf(num, denom);
}

/*fa mtrMod_d yes */
MTR_EXPORT double MTR_CALL mtrMod_d(double num, double denom)
{
    return fmod(num, denom);
}

/*fa mtrMin yes */
MTR_EXPORT int MTR_CALL mtrMin(int num1, int num2)
{
    return ((num1 < num2) ? num1 : num2);
}

/*fa mtrMin_l yes */
MTR_EXPORT long int MTR_CALL mtrMin_l(long int num1, long int num2)
{
    return ((num1 < num2) ? num1 : num2);
}

/*fa mtrMin_ll yes */
MTR_EXPORT long long int MTR_CALL mtrMin_ll(long long int num1,
 long long int num2)
{
    return ((num1 < num2) ? num1 : num2);
}

/*fa mtrMin_f yes */
MTR_EXPORT float MTR_CALL mtrMin_f(float num1, float num2)
{
    return fminf(num1, num2);
}

/*fa mtrMin_d yes */
MTR_EXPORT double MTR_CALL mtrMin_d(double num1, double num2)
{
    return fmin(num1, num2);
}

/*fa mtrMax yes */
MTR_EXPORT int MTR_CALL mtrMax(int num1, int num2)
{
    return ((num1 > num2) ? num1 : num2);
}

/*fa mtrMax_l yes */
MTR_EXPORT long int MTR_CALL mtrMax_l(long int num1, long int num2)
{
    return ((num1 > num2) ? num1 : num2);
}

/*fa mtrMax_ll yes */
MTR_EXPORT long long int MTR_CALL mtrMax_ll(long long int num1,
 long long int num2)
{
    return ((num1 > num2) ? num1 : num2);
}

/*fa mtrMax_f yes */
MTR_EXPORT float MTR_CALL mtrMax_f(float num1, float num2)
{
    return fmaxf(num1, num2);
}

/*fa mtrMax_d yes */
MTR_EXPORT double MTR_CALL mtrMax_d(double num1, double num2)
{
    return fmax(num1, num2);
}
