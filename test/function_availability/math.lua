-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(Sin_f, "MTR_Sin_f", MathFunctionSupported);
fa.FunctionSupported(Sin_d, "MTR_Sin_d", MathFunctionSupported);
fa.FunctionSupported(SinFast_f, "MTR_SinFast_f", MathFunctionSupported);
fa.FunctionSupported(SinFast_d, "MTR_SinFast_d", MathFunctionSupported);
fa.FunctionSupported(Cos_f, "MTR_Cos_f", MathFunctionSupported);
fa.FunctionSupported(Cos_d, "MTR_Cos_d", MathFunctionSupported);
fa.FunctionSupported(CosFast_f, "MTR_CosFast_f", MathFunctionSupported);
fa.FunctionSupported(CosFast_d, "MTR_CosFast_d", MathFunctionSupported);
fa.FunctionSupported(Tan_f, "MTR_Tan_f", MathFunctionSupported);
fa.FunctionSupported(Tan_d, "MTR_Tan_d", MathFunctionSupported);
fa.FunctionSupported(TanFast_f, "MTR_TanFast_f", MathFunctionSupported);
fa.FunctionSupported(TanFast_d, "MTR_TanFast_d", MathFunctionSupported);
fa.FunctionSupported(Cot_f, "MTR_Cot_f", MathFunctionSupported);
fa.FunctionSupported(Cot_d, "MTR_Cot_d", MathFunctionSupported);
fa.FunctionSupported(CotFast_f, "MTR_CotFast_f", MathFunctionSupported);
fa.FunctionSupported(CotFast_d, "MTR_CotFast_d", MathFunctionSupported);
fa.FunctionSupported(Asin_f, "MTR_Asin_f", MathFunctionSupported);
fa.FunctionSupported(Asin_d, "MTR_Asin_d", MathFunctionSupported);
fa.FunctionSupported(AsinFast_f, "MTR_AsinFast_f", MathFunctionSupported);
fa.FunctionSupported(AsinFast_d, "MTR_AsinFast_d", MathFunctionSupported);
fa.FunctionSupported(Acos_f, "MTR_Acos_f", MathFunctionSupported);
fa.FunctionSupported(Acos_f, "MTR_Acos_f", MathFunctionSupported);
fa.FunctionSupported(AcosFast_f, "MTR_AcosFast_f", MathFunctionSupported);
fa.FunctionSupported(AcosFast_d, "MTR_AcosFast_d", MathFunctionSupported);
fa.FunctionSupported(Atan_f, "MTR_Atan_f", MathFunctionSupported);
fa.FunctionSupported(Atan_d, "MTR_Atan_d", MathFunctionSupported);
fa.FunctionSupported(AtanFast_f, "MTR_AtanFast_f", MathFunctionSupported);
fa.FunctionSupported(AtanFast_d, "MTR_AtanFast_d", MathFunctionSupported);
fa.FunctionSupported(Acot_f, "MTR_Acot_f", MathFunctionSupported);
fa.FunctionSupported(Acot_d, "MTR_Acot_d", MathFunctionSupported);
fa.FunctionSupported(AcotFast_f, "MTR_AcotFast_f", MathFunctionSupported);
fa.FunctionSupported(AcotFast_d, "MTR_AcotFast_d", MathFunctionSupported);
fa.FunctionSupported(Loge_f, "MTR_Loge_f", MathFunctionSupported);
fa.FunctionSupported(Loge_d, "MTR_Loge_d", MathFunctionSupported);
fa.FunctionSupported(LogeFast_f, "MTR_LogeFast_f", MathFunctionSupported);
fa.FunctionSupported(LogeFast_d, "MTR_LogeFast_d", MathFunctionSupported);
fa.FunctionSupported(Log10_f, "MTR_Log10_f", MathFunctionSupported);
fa.FunctionSupported(Log10_d, "MTR_Log10_d", MathFunctionSupported);
fa.FunctionSupported(Log10Fast_f, "MTR_Log10Fast_f", MathFunctionSupported);
fa.FunctionSupported(Log10Fast_d, "MTR_Log10Fast_d", MathFunctionSupported);
fa.FunctionSupported(Log2_f, "MTR_Log2_f", MathFunctionSupported);
fa.FunctionSupported(Log2_d, "MTR_Log2_d", MathFunctionSupported);
fa.FunctionSupported(Log2Fast_f, "MTR_Log2Fast_f", MathFunctionSupported);
fa.FunctionSupported(Log2Fast_d, "MTR_Log2Fast_d", MathFunctionSupported);
fa.FunctionSupported(Log_f, "MTR_Log_f", MathFunctionSupported);
fa.FunctionSupported(Log_d, "MTR_Log_d", MathFunctionSupported);
fa.FunctionSupported(LogFast_f, "MTR_LogFast_f", MathFunctionSupported);
fa.FunctionSupported(LogFast_d, "MTR_LogFast_d", MathFunctionSupported);
fa.FunctionSupported(Pow_f, "MTR_Pow_f", MathFunctionSupported);
fa.FunctionSupported(Pow_d, "MTR_Pow_d", MathFunctionSupported);
fa.FunctionSupported(PowFast_f, "MTR_PowFast_f", MathFunctionSupported);
fa.FunctionSupported(PowFast_d, "MTR_PowFast_d", MathFunctionSupported);
fa.FunctionSupported(Sqrt_f, "MTR_Sqrt_f", MathFunctionSupported);
fa.FunctionSupported(Sqrt_d, "MTR_Sqrt_d", MathFunctionSupported);
fa.FunctionSupported(SqrtFast_f, "MTR_SqrtFast_f", MathFunctionSupported);
fa.FunctionSupported(SqrtFast_d, "MTR_SqrtFast_d", MathFunctionSupported);
fa.FunctionSupported(Cbrt_f, "MTR_Cbrt_f", MathFunctionSupported);
fa.FunctionSupported(Cbrt_d, "MTR_Cbrt_d", MathFunctionSupported);
fa.FunctionSupported(CbrtFast_f, "MTR_CbrtFast_f", MathFunctionSupported);
fa.FunctionSupported(CbrtFast_d, "MTR_CbrtFast_d", MathFunctionSupported);
fa.FunctionSupported(Hypot_f, "MTR_Hypot_f", MathFunctionSupported);
fa.FunctionSupported(Hypot_d, "MTR_Hypot_d", MathFunctionSupported);
fa.FunctionSupported(HypotFast_f, "MTR_HypotFast_f", MathFunctionSupported);
fa.FunctionSupported(HypotFast_d, "MTR_HypotFast_d", MathFunctionSupported);
fa.FunctionSupported(Angle_f, "MTR_Angle_f", MathFunctionSupported);
fa.FunctionSupported(Angle_d, "MTR_Angle_d", MathFunctionSupported);
fa.FunctionSupported(AngleFast_f, "MTR_AngleFast_f", MathFunctionSupported);
fa.FunctionSupported(AngleFast_d, "MTR_AngleFast_d", MathFunctionSupported);
fa.FunctionSupported(Vecx_f, "MTR_Vecx_f", MathFunctionSupported);
fa.FunctionSupported(Vecx_d, "MTR_Vecx_d", MathFunctionSupported);
fa.FunctionSupported(VecxFast_f, "MTR_VecxFast_f", MathFunctionSupported);
fa.FunctionSupported(VecxFast_d, "MTR_VecxFast_d", MathFunctionSupported);
fa.FunctionSupported(Vecy_f, "MTR_Vecy_f", MathFunctionSupported);
fa.FunctionSupported(Vecy_d, "MTR_Vecy_d", MathFunctionSupported);
fa.FunctionSupported(VecyFast_f, "MTR_VecyFast_f", MathFunctionSupported);
fa.FunctionSupported(VecyFast_d, "MTR_VecyFast_d", MathFunctionSupported);
fa.FunctionSupported(Vecxy_f, "MTR_Vecxy_f", MathFunctionSupported);
fa.FunctionSupported(Vecxy_d, "MTR_Vecxy_d", MathFunctionSupported);
fa.FunctionSupported(VecxyFast_f, "MTR_VecxyFast_f", MathFunctionSupported);
fa.FunctionSupported(VecxyFast_d, "MTR_VecxyFast_d", MathFunctionSupported);
fa.FunctionSupported(Rand, "MTR_Rand", MathFunctionSupported);
fa.FunctionSupported(RandRange, "MTR_RandRange", MathFunctionSupported);
fa.FunctionSupported(RandSeed, "MTR_RandSeed", MathFunctionSupported);
fa.FunctionSupported(RandSeedByTime, "MTR_RandSeedByTime",
 MathFunctionSupported);
fa.FunctionSupported(Abs, "MTR_Abs", MathFunctionSupported);
fa.FunctionSupported(Abs_l, "MTR_Abs_l", MathFunctionSupported);
fa.FunctionSupported(Abs_ll, "MTR_Abs_ll", MathFunctionSupported);
fa.FunctionSupported(Abs_f, "MTR_Abs_f", MathFunctionSupported);
fa.FunctionSupported(Abs_d, "MTR_Abs_d", MathFunctionSupported);
fa.FunctionSupported(Sign, "MTR_Sign", MathFunctionSupported);
fa.FunctionSupported(Sign_l, "MTR_Sign_l", MathFunctionSupported);
fa.FunctionSupported(Sign_ll, "MTR_Sign_ll", MathFunctionSupported);
fa.FunctionSupported(Sign_f, "MTR_Sign_f", MathFunctionSupported);
fa.FunctionSupported(Sign_d, "MTR_Sign_d", MathFunctionSupported);
fa.FunctionSupported(Round_f, "MTR_Round_f", MathFunctionSupported);
fa.FunctionSupported(Round_d, "MTR_Round_d", MathFunctionSupported);
fa.FunctionSupported(Floor_f, "MTR_Floor_f", MathFunctionSupported);
fa.FunctionSupported(Floor_d, "MTR_Floor_d", MathFunctionSupported);
fa.FunctionSupported(Ceil_f, "MTR_Ceil_f", MathFunctionSupported);
fa.FunctionSupported(Ceil_d, "MTR_Ceil_d", MathFunctionSupported);
fa.FunctionSupported(Mod, "MTR_Mod", MathFunctionSupported);
fa.FunctionSupported(Mod_l, "MTR_Mod_l", MathFunctionSupported);
fa.FunctionSupported(Mod_ll, "MTR_Mod_ll", MathFunctionSupported);
fa.FunctionSupported(Mod_d, "MTR_Mod_d", MathFunctionSupported);
fa.FunctionSupported(Min, "MTR_Min", MathFunctionSupported);
fa.FunctionSupported(Min_l, "MTR_Min_l", MathFunctionSupported);
fa.FunctionSupported(Min_ll, "MTR_Min_ll", MathFunctionSupported);
fa.FunctionSupported(Min_f, "MTR_Min_f", MathFunctionSupported);
fa.FunctionSupported(Min_d, "MTR_Min_d", MathFunctionSupported);
fa.FunctionSupported(Max, "MTR_Max", MathFunctionSupported);
fa.FunctionSupported(Max_l, "MTR_Max_l", MathFunctionSupported);
fa.FunctionSupported(Max_ll, "MTR_Max_ll", MathFunctionSupported);
fa.FunctionSupported(Max_f, "MTR_Max_f", MathFunctionSupported);
fa.FunctionSupported(Max_d, "MTR_Max_d", MathFunctionSupported);
