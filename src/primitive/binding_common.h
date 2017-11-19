#ifndef MTR_PRIMITIVE_BINDING_COMMON_H
#define MTR_PRIMITIVE_BINDING_COMMON_H

MTR_FUNC(int, MTR_PrimitiveFunctionSupported, const char *);
MTR_FUNC(bool, MTR_PrimitiveInit, void);

/* Fill */
MTR_FUNC(void, MTR_PrimitiveFill_rgb, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveFill_rgba, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveFill_c, uint32_t);
MTR_FUNC(void, MTR_PrimitiveFill_ca, uint32_t);

/* Pixel */
MTR_FUNC(void, MTR_PrimitivePixel_rgb_f, float, float, uint8_t, uint8_t,
 uint8_t);
MTR_FUNC(void, MTR_PrimitivePixel_rgba_f, float, float, uint8_t, uint8_t,
 uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitivePixel_c_f, float, float, uint32_t);
MTR_FUNC(void, MTR_PrimitivePixel_ca_f, float, float, uint32_t);

/* Line */
MTR_FUNC(void, MTR_PrimitiveLine_rgb_f, float, float, float, float, uint8_t,
 uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveLine_rgba_f, float, float, float, float, uint8_t,
 uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveLine_c_f, float, float, float, float, uint32_t);
MTR_FUNC(void, MTR_PrimitiveLine_ca_f, float, float, float, float, uint32_t);

/* Arc */
MTR_FUNC(void, MTR_PrimitiveArc_rgb_f, float, float, float, float, float,
 uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveArc_rgba_f, float, float, float, float, float,
 uint8_t, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveArc_c_f, float, float, float, float, float,
 uint32_t);
MTR_FUNC(void, MTR_PrimitiveArc_ca_f, float, float, float, float, float,
 uint32_t);

/* SegmentFilled */
MTR_FUNC(void, MTR_PrimitiveSegmentFilled_rgb_f, float, float, float, float,
 float, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveSegmentFilled_rgba_f, float, float, float, float,
 float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveSegmentFilled_c_f, float, float, float, float,
 float, uint32_t);
MTR_FUNC(void, MTR_PrimitiveSegmentFilled_ca_f, float, float, float, float,
 float, uint32_t);

/* Circle */
MTR_FUNC(void, MTR_PrimitiveCircle_rgb_f, float, float, float, uint8_t, uint8_t,
 uint8_t);
MTR_FUNC(void, MTR_PrimitiveCircle_rgba_f, float, float, float, uint8_t,
 uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveCircle_c_f, float, float, float, uint32_t);
MTR_FUNC(void, MTR_PrimitiveCircle_ca_f, float, float, float, uint32_t);

/* CircleFilled */
MTR_FUNC(void, MTR_PrimitiveCircleFilled_rgb_f, float, float, float, uint8_t,
 uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveCircleFilled_rgba_f, float, float, float, uint8_t,
 uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveCircleFilled_c_f, float, float, float, uint32_t);
MTR_FUNC(void, MTR_PrimitiveCircleFilled_ca_f, float, float, float, uint32_t);

/* Ellipse */
MTR_FUNC(void, MTR_PrimitiveEllipse_rgb_f, float, float, float, float, float,
 uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveEllipse_rgba_f, float, float, float, float, float,
 uint8_t, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveEllipse_c_f, float, float, float, float, float,
 uint32_t);
MTR_FUNC(void, MTR_PrimitiveEllipse_ca_f, float, float, float, float, float,
 uint32_t);

/* EllipseFilled */
MTR_FUNC(void, MTR_PrimitiveEllipseFilled_rgb_f, float, float, float, float,
 float, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveEllipseFilled_rgba_f, float, float, float, float,
 float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveEllipseFilled_c_f, float, float, float, float,
 float, uint32_t);
MTR_FUNC(void, MTR_PrimitiveEllipseFilled_ca_f, float, float, float, float,
 float, uint32_t);

/* RingSegment */
MTR_FUNC(void, MTR_PrimitiveRingSegment_rgb_f, float, float, float, float,
 float, float, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveRingSegment_rgba_f, float, float, float, float,
 float, float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveRingSegment_c_f, float, float, float, float, float,
 float, uint32_t);
MTR_FUNC(void, MTR_PrimitiveRingSegment_ca_f, float, float, float, float, float,
 float, uint32_t);

/* RingSegmentFilled */
MTR_FUNC(void, MTR_PrimitiveRingSegmentFilled_rgb_f, float, float, float, float,
 float, float, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveRingSegmentFilled_rgba_f, float, float, float,
 float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveRingSegmentFilled_c_f, float, float, float, float,
 float, float, uint32_t);
MTR_FUNC(void, MTR_PrimitiveRingSegmentFilled_ca_f, float, float, float, float,
 float, float, uint32_t);

/* Triangle */
MTR_FUNC(void, MTR_PrimitiveTriangle_rgb_f, float, float, float, float, float,
 float, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveTriangle_rgba_f, float, float, float, float, float,
 float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveTriangle_c_f, float, float, float, float, float,
 float, uint32_t);
MTR_FUNC(void, MTR_PrimitiveTriangle_ca_f, float, float, float, float, float,
 float, uint32_t);

/* TriangleFilled */
MTR_FUNC(void, MTR_PrimitiveTriangleFilled_rgb_f, float, float, float, float,
 float, float, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveTriangleFilled_rgba_f, float, float, float, float,
 float, float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveTriangleFilled_c_f, float, float, float, float,
 float, float, uint32_t);
MTR_FUNC(void, MTR_PrimitiveTriangleFilled_ca_f, float, float, float, float,
 float, float, uint32_t);

/* Rectangle */
MTR_FUNC(void, MTR_PrimitiveRectangle_rgb_f, float, float, float, float,
 uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveRectangle_rgba_f, float, float, float, float,
 uint8_t, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveRectangle_c_f, float, float, float, float,
 uint32_t);
MTR_FUNC(void, MTR_PrimitiveRectangle_ca_f, float, float, float, float,
 uint32_t);

/* RectangleFilled */
MTR_FUNC(void, MTR_PrimitiveRectangleFilled_rgb_f, float, float, float, float,
 uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveRectangleFilled_rgba_f, float, float, float, float,
 uint8_t, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveRectangleFilled_c_f, float, float, float, float,
 uint32_t);
MTR_FUNC(void, MTR_PrimitiveRectangleFilled_ca_f, float, float, float, float,
 uint32_t);

/* RoundedRectangle */
MTR_FUNC(void, MTR_PrimitiveRoundedRectangle_rgb_f, float, float, float, float,
 float, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveRoundedRectangle_rgba_f, float, float, float, float,
 float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveRoundedRectangle_c_f, float, float, float, float,
 float, uint32_t);
MTR_FUNC(void, MTR_PrimitiveRoundedRectangle_ca_f, float, float, float, float,
 float, uint32_t);

/* RoundedRectangleFilled */
MTR_FUNC(void, MTR_PrimitiveRoundedRectangleFilled_rgb_f, float, float, float,
 float, float, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveRoundedRectangleFilled_rgba_f, float, float, float,
 float, float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveRoundedRectangleFilled_c_f, float, float, float,
 float, float, uint32_t);
MTR_FUNC(void, MTR_PrimitiveRoundedRectangleFilled_ca_f, float, float, float,
 float, float, uint32_t);

/* LineBegin, LineTo, LineEnd */
MTR_FUNC(void, MTR_PrimitiveLineBegin_f, float, float);
MTR_FUNC(void, MTR_PrimitiveLineTo_rgb_f, float, float, uint8_t, uint8_t,
 uint8_t);
MTR_FUNC(void, MTR_PrimitiveLineTo_rgba_f, float, float, uint8_t, uint8_t,
 uint8_t, uint8_t);
MTR_FUNC(void, MTR_PrimitiveLineTo_c_f, float, float, uint32_t);
MTR_FUNC(void, MTR_PrimitiveLineTo_ca_f, float, float, uint32_t);
MTR_FUNC(void, MTR_PrimitiveLineEnd, void);

#endif
