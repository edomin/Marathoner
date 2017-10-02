-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(PrimitiveInit, "mtrPrimitiveInit",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveFill_rgb, "mtrPrimitiveFill_rgb",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveFill_rgba, "mtrPrimitiveFill_rgba",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveFill_c, "mtrPrimitiveFill_c",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveFill_ca, "mtrPrimitiveFill_ca",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitivePixel_rgb_f, "mtrPrimitivePixel_rgb_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitivePixel_rgba_f, "mtrPrimitivePixel_rgba_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitivePixel_c_f, "mtrPrimitivePixel_c_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitivePixel_ca_f, "mtrPrimitivePixel_ca_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveLine_rgb_f, "mtrPrimitiveLine_rgb_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveLine_rgba_f, "mtrPrimitiveLine_rgba_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveLine_c_f, "mtrPrimitiveLine_c_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveLine_ca_f, "mtrPrimitiveLine_ca_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveArc_rgb_f, "mtrPrimitiveArc_rgb_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveArc_rgba_f, "mtrPrimitiveArc_rgba_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveArc_c_f, "mtrPrimitiveArc_c_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveArc_ca_f, "mtrPrimitiveArc_ca_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveSegmentFilled_rgb_f,
 "mtrPrimitiveSegmentFilled_rgb_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveSegmentFilled_rgba_f,
 "mtrPrimitiveSegmentFilled_rgba_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveSegmentFilled_c_f,
 "mtrPrimitiveSegmentFilled_c_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveSegmentFilled_ca_f,
 "mtrPrimitiveSegmentFilled_ca_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveCircle_rgb_f, "mtrPrimitiveCircle_rgb_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveCircle_rgba_f, "mtrPrimitiveCircle_rgba_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveCircle_c_f, "mtrPrimitiveCircle_c_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveCircle_ca_f, "mtrPrimitiveCircle_ca_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveCircleFilled_rgb_f,
 "mtrPrimitiveCircleFilled_rgb_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveCircleFilled_rgba_f,
 "mtrPrimitiveCircleFilled_rgba_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveCircleFilled_c_f, "mtrPrimitiveCircleFilled_c_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveCircleFilled_ca_f,
 "mtrPrimitiveCircleFilled_ca_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveEllipse_rgb_f, "mtrPrimitiveEllipse_rgb_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveEllipse_rgba_f, "mtrPrimitiveEllipse_rgba_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveEllipse_c_f, "mtrPrimitiveEllipse_c_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveEllipse_ca_f, "mtrPrimitiveEllipse_ca_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveEllipseFilled_rgb_f,
 "mtrPrimitiveEllipseFilled_rgb_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveEllipseFilled_rgba_f,
 "mtrPrimitiveEllipseFilled_rgba_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveEllipseFilled_c_f,
 "mtrPrimitiveEllipseFilled_c_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveEllipseFilled_ca_f,
 "mtrPrimitiveEllipseFilled_ca_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRingSegment_rgb_f,
 "mtrPrimitiveRingSegment_rgb_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRingSegment_rgba_f,
 "mtrPrimitiveRingSegment_rgba_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRingSegment_c_f, "mtrPrimitiveRingSegment_c_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRingSegment_ca_f, "mtrPrimitiveRingSegment_ca_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRingSegmentFilled_rgb_f,
 "mtrPrimitiveRingSegmentFilled_rgb_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRingSegmentFilled_rgba_f,
 "mtrPrimitiveRingSegmentFilled_rgba_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRingSegmentFilled_c_f,
 "mtrPrimitiveRingSegmentFilled_c_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRingSegmentFilled_ca_f,
 "mtrPrimitiveRingSegmentFilled_ca_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveTriangle_rgb_f, "mtrPrimitiveTriangle_rgb_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveTriangle_rgba_f, "mtrPrimitiveTriangle_rgba_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveTriangle_c_f, "mtrPrimitiveTriangle_c_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveTriangle_ca_f, "mtrPrimitiveTriangle_ca_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveTriangleFilled_rgb_f,
 "mtrPrimitiveTriangleFilled_rgb_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveTriangleFilled_rgba_f,
 "mtrPrimitiveTriangleFilled_rgba_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveTriangleFilled_c_f,
 "mtrPrimitiveTriangleFilled_c_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveTriangleFilled_ca_f,
 "mtrPrimitiveTriangleFilled_ca_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRectangle_rgb_f, "mtrPrimitiveRectangle_rgb_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRectangle_rgba_f, "mtrPrimitiveRectangle_rgba_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRectangle_c_f, "mtrPrimitiveRectangle_c_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRectangle_ca_f, "mtrPrimitiveRectangle_ca_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRectangleFilled_rgb_f,
 "mtrPrimitiveRectangleFilled_rgb_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRectangleFilled_rgba_f,
 "mtrPrimitiveRectangleFilled_rgba_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRectangleFilled_c_f,
 "mtrPrimitiveRectangleFilled_c_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRectangleFilled_ca_f,
 "mtrPrimitiveRectangleFilled_ca_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRoundedRectangle_rgb_f,
 "mtrPrimitiveRoundedRectangle_rgb_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRoundedRectangle_rgba_f,
 "mtrPrimitiveRoundedRectangle_rgba_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRoundedRectangle_c_f,
 "mtrPrimitiveRoundedRectangle_c_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRoundedRectangle_ca_f,
 "mtrPrimitiveRoundedRectangle_ca_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRoundedRectangleFilled_rgb_f,
 "mtrPrimitiveRoundedRectangleFilled_rgb_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRoundedRectangleFilled_rgba_f,
 "mtrPrimitiveRoundedRectangleFilled_rgba_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRoundedRectangleFilled_c_f,
 "mtrPrimitiveRoundedRectangleFilled_c_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRoundedRectangleFilled_ca_f,
 "mtrPrimitiveRoundedRectangleFilled_ca_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveLineBegin_f, "mtrPrimitiveLineBegin_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveLineTo_rgb_f, "mtrPrimitiveLineTo_rgb_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveLineTo_rgba_f, "mtrPrimitiveLineTo_rgba_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveLineTo_c_f, "mtrPrimitiveLineTo_c_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveLineTo_ca_f, "mtrPrimitiveLineTo_ca_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveLineEnd, "mtrPrimitiveLineEnd",
 PrimitiveFunctionSupported);
