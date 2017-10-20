#ifndef MTR_PRIMITIVE_BINDING_COMMON_H
#define MTR_PRIMITIVE_BINDING_COMMON_H

typedef int (MTR_CALL * MTR_PrimitiveFunctionSupportedFunc)(const char *);
MTR_PrimitiveFunctionSupportedFunc MTR_PrimitiveFunctionSupported;

typedef bool (MTR_CALL * MTR_PrimitiveInitFunc)(void);
MTR_PrimitiveInitFunc MTR_PrimitiveInit;

/* Fill */
typedef void (MTR_CALL * MTR_PrimitiveFill_rgbFunc)(uint8_t, uint8_t, uint8_t);
MTR_PrimitiveFill_rgbFunc MTR_PrimitiveFill_rgb;

typedef void (MTR_CALL * MTR_PrimitiveFill_rgbaFunc)(uint8_t, uint8_t, uint8_t,
 uint8_t);
MTR_PrimitiveFill_rgbaFunc MTR_PrimitiveFill_rgba;

typedef void (MTR_CALL * MTR_PrimitiveFill_cFunc)(uint32_t);
MTR_PrimitiveFill_cFunc MTR_PrimitiveFill_c;

typedef void (MTR_CALL * MTR_PrimitiveFill_caFunc)(uint32_t);
MTR_PrimitiveFill_caFunc MTR_PrimitiveFill_ca;

/* Pixel */
typedef void (MTR_CALL * MTR_PrimitivePixel_rgb_fFunc)(float, float, uint8_t,
 uint8_t, uint8_t);
MTR_PrimitivePixel_rgb_fFunc MTR_PrimitivePixel_rgb_f;

typedef void (MTR_CALL * MTR_PrimitivePixel_rgba_fFunc)(float, float, uint8_t,
 uint8_t, uint8_t, uint8_t);
MTR_PrimitivePixel_rgba_fFunc MTR_PrimitivePixel_rgba_f;

typedef void (MTR_CALL * MTR_PrimitivePixel_c_fFunc)(float, float, uint32_t);
MTR_PrimitivePixel_c_fFunc MTR_PrimitivePixel_c_f;

typedef void (MTR_CALL * MTR_PrimitivePixel_ca_fFunc)(float, float, uint32_t);
MTR_PrimitivePixel_ca_fFunc MTR_PrimitivePixel_ca_f;

/* Line */
typedef void (MTR_CALL * MTR_PrimitiveLine_rgb_fFunc)(float, float, float,
 float, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveLine_rgb_fFunc MTR_PrimitiveLine_rgb_f;

typedef void (MTR_CALL * MTR_PrimitiveLine_rgba_fFunc)(float, float, float,
 float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveLine_rgba_fFunc MTR_PrimitiveLine_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveLine_c_fFunc)(float, float, float, float,
 uint32_t);
MTR_PrimitiveLine_c_fFunc MTR_PrimitiveLine_c_f;

typedef void (MTR_CALL * MTR_PrimitiveLine_ca_fFunc)(float, float, float, float,
 uint32_t);
MTR_PrimitiveLine_ca_fFunc MTR_PrimitiveLine_ca_f;

/* Arc */
typedef void (MTR_CALL * MTR_PrimitiveArc_rgb_fFunc)(float, float, float, float,
 float, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveArc_rgb_fFunc MTR_PrimitiveArc_rgb_f;

typedef void (MTR_CALL * MTR_PrimitiveArc_rgba_fFunc)(float, float, float,
 float, float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveArc_rgba_fFunc MTR_PrimitiveArc_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveArc_c_fFunc)(float, float, float, float,
 float, uint32_t);
MTR_PrimitiveArc_c_fFunc MTR_PrimitiveArc_c_f;

typedef void (MTR_CALL * MTR_PrimitiveArc_ca_fFunc)(float, float, float, float,
 float, uint32_t);
MTR_PrimitiveArc_ca_fFunc MTR_PrimitiveArc_ca_f;

/* SegmentFilled */
typedef void (MTR_CALL * MTR_PrimitiveSegmentFilled_rgb_fFunc)(float, float,
 float, float, float, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveSegmentFilled_rgb_fFunc MTR_PrimitiveSegmentFilled_rgb_f;

typedef void (MTR_CALL * MTR_PrimitiveSegmentFilled_rgba_fFunc)(float, float,
 float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveSegmentFilled_rgba_fFunc MTR_PrimitiveSegmentFilled_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveSegmentFilled_c_fFunc)(float, float,
 float, float, float, uint32_t);
MTR_PrimitiveSegmentFilled_c_fFunc MTR_PrimitiveSegmentFilled_c_f;

typedef void (MTR_CALL * MTR_PrimitiveSegmentFilled_ca_fFunc)(float, float,
 float, float, float, uint32_t);
MTR_PrimitiveSegmentFilled_ca_fFunc MTR_PrimitiveSegmentFilled_ca_f;

/* Circle */
typedef void (MTR_CALL * MTR_PrimitiveCircle_rgb_fFunc)(float, float, float,
 uint8_t, uint8_t, uint8_t);
MTR_PrimitiveCircle_rgb_fFunc MTR_PrimitiveCircle_rgb_f;

typedef void (MTR_CALL * MTR_PrimitiveCircle_rgba_fFunc)(float, float, float,
 uint8_t, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveCircle_rgba_fFunc MTR_PrimitiveCircle_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveCircle_c_fFunc)(float, float, float,
 uint32_t);
MTR_PrimitiveCircle_c_fFunc MTR_PrimitiveCircle_c_f;

typedef void (MTR_CALL * MTR_PrimitiveCircle_ca_fFunc)(float, float, float,
 uint32_t);
MTR_PrimitiveCircle_ca_fFunc MTR_PrimitiveCircle_ca_f;

/* CircleFilled */
typedef void (MTR_CALL * MTR_PrimitiveCircleFilled_rgb_fFunc)(float, float,
 float, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveCircleFilled_rgb_fFunc MTR_PrimitiveCircleFilled_rgb_f;

typedef void (MTR_CALL * MTR_PrimitiveCircleFilled_rgba_fFunc)(float, float,
 float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveCircleFilled_rgba_fFunc MTR_PrimitiveCircleFilled_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveCircleFilled_c_fFunc)(float, float, float,
 uint32_t);
MTR_PrimitiveCircleFilled_c_fFunc MTR_PrimitiveCircleFilled_c_f;

typedef void (MTR_CALL * MTR_PrimitiveCircleFilled_ca_fFunc)(float, float,
 float, uint32_t);
MTR_PrimitiveCircleFilled_ca_fFunc MTR_PrimitiveCircleFilled_ca_f;

/* Ellipse */
typedef void (MTR_CALL * MTR_PrimitiveEllipse_rgb_fFunc)(float, float, float,
 float, float, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveEllipse_rgb_fFunc MTR_PrimitiveEllipse_rgb_f;

typedef void (MTR_CALL * MTR_PrimitiveEllipse_rgba_fFunc)(float, float, float,
 float, float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveEllipse_rgba_fFunc MTR_PrimitiveEllipse_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveEllipse_c_fFunc)(float, float, float,
 float, float, uint32_t);
MTR_PrimitiveEllipse_c_fFunc MTR_PrimitiveEllipse_c_f;

typedef void (MTR_CALL * MTR_PrimitiveEllipse_ca_fFunc)(float, float, float,
 float, float, uint32_t);
MTR_PrimitiveEllipse_ca_fFunc MTR_PrimitiveEllipse_ca_f;

/* EllipseFilled */
typedef void (MTR_CALL * MTR_PrimitiveEllipseFilled_rgb_fFunc)(float, float,
 float, float, float, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveEllipseFilled_rgb_fFunc MTR_PrimitiveEllipseFilled_rgb_f;

typedef void (MTR_CALL * MTR_PrimitiveEllipseFilled_rgba_fFunc)(float, float,
 float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveEllipseFilled_rgba_fFunc MTR_PrimitiveEllipseFilled_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveEllipseFilled_c_fFunc)(float, float,
 float, float, float, uint32_t);
MTR_PrimitiveEllipseFilled_c_fFunc MTR_PrimitiveEllipseFilled_c_f;

typedef void (MTR_CALL * MTR_PrimitiveEllipseFilled_ca_fFunc)(float, float,
 float, float, float, uint32_t);
MTR_PrimitiveEllipseFilled_ca_fFunc MTR_PrimitiveEllipseFilled_ca_f;

/* RingSegment */
typedef void (MTR_CALL * MTR_PrimitiveRingSegment_rgb_fFunc)(float, float,
 float, float, float, float, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveRingSegment_rgb_fFunc MTR_PrimitiveRingSegment_rgb_f;

typedef void (MTR_CALL * MTR_PrimitiveRingSegment_rgba_fFunc)(float, float,
 float, float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveRingSegment_rgba_fFunc MTR_PrimitiveRingSegment_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveRingSegment_c_fFunc)(float, float, float,
 float, float, float, uint32_t);
MTR_PrimitiveRingSegment_c_fFunc MTR_PrimitiveRingSegment_c_f;

typedef void (MTR_CALL * MTR_PrimitiveRingSegment_ca_fFunc)(float, float, float,
 float, float, float, uint32_t);
MTR_PrimitiveRingSegment_ca_fFunc MTR_PrimitiveRingSegment_ca_f;

/* RingSegmentFilled */
typedef void (MTR_CALL * MTR_PrimitiveRingSegmentFilled_rgb_fFunc)(float, float,
 float, float, float, float, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveRingSegmentFilled_rgb_fFunc MTR_PrimitiveRingSegmentFilled_rgb_f;

typedef void (MTR_CALL * MTR_PrimitiveRingSegmentFilled_rgba_fFunc)(float,
 float, float, float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveRingSegmentFilled_rgba_fFunc MTR_PrimitiveRingSegmentFilled_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveRingSegmentFilled_c_fFunc)(float, float,
 float, float, float, float, uint32_t);
MTR_PrimitiveRingSegmentFilled_c_fFunc MTR_PrimitiveRingSegmentFilled_c_f;

typedef void (MTR_CALL * MTR_PrimitiveRingSegmentFilled_ca_fFunc)(float, float,
 float, float, float, float, uint32_t);
MTR_PrimitiveRingSegmentFilled_ca_fFunc MTR_PrimitiveRingSegmentFilled_ca_f;

/* Triangle */
typedef void (MTR_CALL * MTR_PrimitiveTriangle_rgb_fFunc)(float, float, float,
 float, float, float, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveTriangle_rgb_fFunc MTR_PrimitiveTriangle_rgb_f;

typedef void (MTR_CALL * MTR_PrimitiveTriangle_rgba_fFunc)(float, float, float,
 float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveTriangle_rgba_fFunc MTR_PrimitiveTriangle_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveTriangle_c_fFunc)(float, float, float,
 float, float, float, uint32_t);
MTR_PrimitiveTriangle_c_fFunc MTR_PrimitiveTriangle_c_f;

typedef void (MTR_CALL * MTR_PrimitiveTriangle_ca_fFunc)(float, float, float,
 float, float, float, uint32_t);
MTR_PrimitiveTriangle_ca_fFunc MTR_PrimitiveTriangle_ca_f;

/* TriangleFilled */
typedef void (MTR_CALL * MTR_PrimitiveTriangleFilled_rgb_fFunc)(float, float,
 float, float, float, float, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveTriangleFilled_rgb_fFunc MTR_PrimitiveTriangleFilled_rgb_f;

typedef void (MTR_CALL * MTR_PrimitiveTriangleFilled_rgba_fFunc)(float, float,
 float, float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveTriangleFilled_rgba_fFunc MTR_PrimitiveTriangleFilled_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveTriangleFilled_c_fFunc)(float, float,
 float, float, float, float, uint32_t);
MTR_PrimitiveTriangleFilled_c_fFunc MTR_PrimitiveTriangleFilled_c_f;

typedef void (MTR_CALL * MTR_PrimitiveTriangleFilled_ca_fFunc)(float, float,
 float, float, float, float, uint32_t);
MTR_PrimitiveTriangleFilled_ca_fFunc MTR_PrimitiveTriangleFilled_ca_f;

/* Rectangle */
typedef void (MTR_CALL * MTR_PrimitiveRectangle_rgb_fFunc)(float, float, float,
 float, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveRectangle_rgb_fFunc MTR_PrimitiveRectangle_rgb_f;

typedef void (MTR_CALL * MTR_PrimitiveRectangle_rgba_fFunc)(float, float, float,
 float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveRectangle_rgba_fFunc MTR_PrimitiveRectangle_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveRectangle_c_fFunc)(float, float, float,
 float, uint32_t);
MTR_PrimitiveRectangle_c_fFunc MTR_PrimitiveRectangle_c_f;

typedef void (MTR_CALL * MTR_PrimitiveRectangle_ca_fFunc)(float, float, float,
 float, uint32_t);
MTR_PrimitiveRectangle_ca_fFunc MTR_PrimitiveRectangle_ca_f;

/* RectangleFilled */
typedef void (MTR_CALL * MTR_PrimitiveRectangleFilled_rgb_fFunc)(float, float,
 float, float, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveRectangleFilled_rgb_fFunc MTR_PrimitiveRectangleFilled_rgb_f;

typedef void (MTR_CALL * MTR_PrimitiveRectangleFilled_rgba_fFunc)(float, float,
 float, float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveRectangleFilled_rgba_fFunc MTR_PrimitiveRectangleFilled_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveRectangleFilled_c_fFunc)(float, float,
 float, float, uint32_t);
MTR_PrimitiveRectangleFilled_c_fFunc MTR_PrimitiveRectangleFilled_c_f;

typedef void (MTR_CALL * MTR_PrimitiveRectangleFilled_ca_fFunc)(float, float,
 float, float, uint32_t);
MTR_PrimitiveRectangleFilled_ca_fFunc MTR_PrimitiveRectangleFilled_ca_f;

/* RoundedRectangle */
typedef void (MTR_CALL * MTR_PrimitiveRoundedRectangle_rgb_fFunc)(float, float,
 float, float, float, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveRoundedRectangle_rgb_fFunc MTR_PrimitiveRoundedRectangle_rgb_f;

typedef void (MTR_CALL * MTR_PrimitiveRoundedRectangle_rgba_fFunc)(float, float,
 float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveRoundedRectangle_rgba_fFunc MTR_PrimitiveRoundedRectangle_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveRoundedRectangle_c_fFunc)(float, float,
 float, float, float, uint32_t);
MTR_PrimitiveRoundedRectangle_c_fFunc MTR_PrimitiveRoundedRectangle_c_f;

typedef void (MTR_CALL * MTR_PrimitiveRoundedRectangle_ca_fFunc)(float, float,
 float, float, float, uint32_t);
MTR_PrimitiveRoundedRectangle_ca_fFunc MTR_PrimitiveRoundedRectangle_ca_f;

/* RoundedRectangleFilled */
typedef void (MTR_CALL * MTR_PrimitiveRoundedRectangleFilled_rgb_fFunc)(float,
 float, float, float, float, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveRoundedRectangleFilled_rgb_fFunc MTR_PrimitiveRoundedRectangleFilled_rgb_f;

typedef void (MTR_CALL * MTR_PrimitiveRoundedRectangleFilled_rgba_fFunc)(float,
 float, float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
MTR_PrimitiveRoundedRectangleFilled_rgba_fFunc MTR_PrimitiveRoundedRectangleFilled_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveRoundedRectangleFilled_c_fFunc)(float,
 float, float, float, float, uint32_t);
MTR_PrimitiveRoundedRectangleFilled_c_fFunc MTR_PrimitiveRoundedRectangleFilled_c_f;

typedef void (MTR_CALL * MTR_PrimitiveRoundedRectangleFilled_ca_fFunc)(float,
 float, float, float, float, uint32_t);
MTR_PrimitiveRoundedRectangleFilled_ca_fFunc MTR_PrimitiveRoundedRectangleFilled_ca_f;

/* LineBegin, LineTo, LineEnd */
typedef void (MTR_CALL * MTR_PrimitiveLineBegin_fFunc)(float, float);
MTR_PrimitiveLineBegin_fFunc MTR_PrimitiveLineBegin_f;

typedef void (MTR_CALL * MTR_PrimitiveLineTo_rgb_fFunc)(float, float, uint8_t,
 uint8_t, uint8_t);
MTR_PrimitiveLineTo_rgb_fFunc MTR_PrimitiveLineTo_rgb_f;

typedef void (MTR_CALL * MTR_PrimitiveLineTo_rgba_fFunc)(float, float, uint8_t,
 uint8_t, uint8_t, uint8_t);
MTR_PrimitiveLineTo_rgba_fFunc MTR_PrimitiveLineTo_rgba_f;

typedef void (MTR_CALL * MTR_PrimitiveLineTo_c_fFunc)(float, float, uint32_t);
MTR_PrimitiveLineTo_c_fFunc MTR_PrimitiveLineTo_c_f;

typedef void (MTR_CALL * MTR_PrimitiveLineTo_ca_fFunc)(float, float, uint32_t);
MTR_PrimitiveLineTo_ca_fFunc MTR_PrimitiveLineTo_ca_f;

typedef void (MTR_CALL * MTR_PrimitiveLineEndFunc)(void);
MTR_PrimitiveLineEndFunc MTR_PrimitiveLineEnd;

#endif
