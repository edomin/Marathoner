-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(PrimitiveInit, "MTR_PrimitiveInit",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveFill_rgb, "MTR_PrimitiveFill_rgb",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveFill_rgba, "MTR_PrimitiveFill_rgba",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveFill_c, "MTR_PrimitiveFill_c",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveFill_ca, "MTR_PrimitiveFill_ca",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitivePixel_rgb_f, "MTR_PrimitivePixel_rgb_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitivePixel_rgba_f, "MTR_PrimitivePixel_rgba_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitivePixel_c_f, "MTR_PrimitivePixel_c_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitivePixel_ca_f, "MTR_PrimitivePixel_ca_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveLine_rgb_f, "MTR_PrimitiveLine_rgb_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveLine_rgba_f, "MTR_PrimitiveLine_rgba_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveLine_c_f, "MTR_PrimitiveLine_c_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveLine_ca_f, "MTR_PrimitiveLine_ca_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveArc_rgb_f, "MTR_PrimitiveArc_rgb_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveArc_rgba_f, "MTR_PrimitiveArc_rgba_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveArc_c_f, "MTR_PrimitiveArc_c_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveArc_ca_f, "MTR_PrimitiveArc_ca_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveSegmentFilled_rgb_f,
 "MTR_PrimitiveSegmentFilled_rgb_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveSegmentFilled_rgba_f,
 "MTR_PrimitiveSegmentFilled_rgba_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveSegmentFilled_c_f,
 "MTR_PrimitiveSegmentFilled_c_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveSegmentFilled_ca_f,
 "MTR_PrimitiveSegmentFilled_ca_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveCircle_rgb_f, "MTR_PrimitiveCircle_rgb_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveCircle_rgba_f, "MTR_PrimitiveCircle_rgba_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveCircle_c_f, "MTR_PrimitiveCircle_c_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveCircle_ca_f, "MTR_PrimitiveCircle_ca_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveCircleFilled_rgb_f,
 "MTR_PrimitiveCircleFilled_rgb_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveCircleFilled_rgba_f,
 "MTR_PrimitiveCircleFilled_rgba_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveCircleFilled_c_f, "MTR_PrimitiveCircleFilled_c_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveCircleFilled_ca_f,
 "MTR_PrimitiveCircleFilled_ca_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveEllipse_rgb_f, "MTR_PrimitiveEllipse_rgb_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveEllipse_rgba_f, "MTR_PrimitiveEllipse_rgba_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveEllipse_c_f, "MTR_PrimitiveEllipse_c_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveEllipse_ca_f, "MTR_PrimitiveEllipse_ca_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveEllipseFilled_rgb_f,
 "MTR_PrimitiveEllipseFilled_rgb_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveEllipseFilled_rgba_f,
 "MTR_PrimitiveEllipseFilled_rgba_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveEllipseFilled_c_f,
 "MTR_PrimitiveEllipseFilled_c_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveEllipseFilled_ca_f,
 "MTR_PrimitiveEllipseFilled_ca_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRingSegment_rgb_f,
 "MTR_PrimitiveRingSegment_rgb_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRingSegment_rgba_f,
 "MTR_PrimitiveRingSegment_rgba_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRingSegment_c_f, "MTR_PrimitiveRingSegment_c_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRingSegment_ca_f, "MTR_PrimitiveRingSegment_ca_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRingSegmentFilled_rgb_f,
 "MTR_PrimitiveRingSegmentFilled_rgb_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRingSegmentFilled_rgba_f,
 "MTR_PrimitiveRingSegmentFilled_rgba_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRingSegmentFilled_c_f,
 "MTR_PrimitiveRingSegmentFilled_c_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRingSegmentFilled_ca_f,
 "MTR_PrimitiveRingSegmentFilled_ca_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveTriangle_rgb_f, "MTR_PrimitiveTriangle_rgb_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveTriangle_rgba_f, "MTR_PrimitiveTriangle_rgba_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveTriangle_c_f, "MTR_PrimitiveTriangle_c_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveTriangle_ca_f, "MTR_PrimitiveTriangle_ca_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveTriangleFilled_rgb_f,
 "MTR_PrimitiveTriangleFilled_rgb_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveTriangleFilled_rgba_f,
 "MTR_PrimitiveTriangleFilled_rgba_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveTriangleFilled_c_f,
 "MTR_PrimitiveTriangleFilled_c_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveTriangleFilled_ca_f,
 "MTR_PrimitiveTriangleFilled_ca_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRectangle_rgb_f, "MTR_PrimitiveRectangle_rgb_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRectangle_rgba_f, "MTR_PrimitiveRectangle_rgba_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRectangle_c_f, "MTR_PrimitiveRectangle_c_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRectangle_ca_f, "MTR_PrimitiveRectangle_ca_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRectangleFilled_rgb_f,
 "MTR_PrimitiveRectangleFilled_rgb_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRectangleFilled_rgba_f,
 "MTR_PrimitiveRectangleFilled_rgba_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRectangleFilled_c_f,
 "MTR_PrimitiveRectangleFilled_c_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRectangleFilled_ca_f,
 "MTR_PrimitiveRectangleFilled_ca_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRoundedRectangle_rgb_f,
 "MTR_PrimitiveRoundedRectangle_rgb_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRoundedRectangle_rgba_f,
 "MTR_PrimitiveRoundedRectangle_rgba_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRoundedRectangle_c_f,
 "MTR_PrimitiveRoundedRectangle_c_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRoundedRectangle_ca_f,
 "MTR_PrimitiveRoundedRectangle_ca_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRoundedRectangleFilled_rgb_f,
 "MTR_PrimitiveRoundedRectangleFilled_rgb_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRoundedRectangleFilled_rgba_f,
 "MTR_PrimitiveRoundedRectangleFilled_rgba_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRoundedRectangleFilled_c_f,
 "MTR_PrimitiveRoundedRectangleFilled_c_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveRoundedRectangleFilled_ca_f,
 "MTR_PrimitiveRoundedRectangleFilled_ca_f", PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveLineBegin_f, "MTR_PrimitiveLineBegin_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveLineTo_rgb_f, "MTR_PrimitiveLineTo_rgb_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveLineTo_rgba_f, "MTR_PrimitiveLineTo_rgba_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveLineTo_c_f, "MTR_PrimitiveLineTo_c_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveLineTo_ca_f, "MTR_PrimitiveLineTo_ca_f",
 PrimitiveFunctionSupported);
fa.FunctionSupported(PrimitiveLineEnd, "MTR_PrimitiveLineEnd",
 PrimitiveFunctionSupported);
