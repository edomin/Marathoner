#ifndef MTR_PRIMITIVE_BINDING_COMMON_H
#define MTR_PRIMITIVE_BINDING_COMMON_H

typedef int (MTR_CALL * mtrPrimitiveFunctionSupportedFunc)(const char *);
mtrPrimitiveFunctionSupportedFunc mtrPrimitiveFunctionSupported;

typedef bool (MTR_CALL * mtrPrimitiveInitFunc)(void);
mtrPrimitiveInitFunc mtrPrimitiveInit;

/* Fill */
typedef void (MTR_CALL * mtrPrimitiveFill_rgbFunc)(uint8_t, uint8_t, uint8_t);
mtrPrimitiveFill_rgbFunc mtrPrimitiveFill_rgb;

typedef void (MTR_CALL * mtrPrimitiveFill_rgbaFunc)(uint8_t, uint8_t, uint8_t,
 uint8_t);
mtrPrimitiveFill_rgbaFunc mtrPrimitiveFill_rgba;

typedef void (MTR_CALL * mtrPrimitiveFill_cFunc)(uint32_t);
mtrPrimitiveFill_cFunc mtrPrimitiveFill_c;

typedef void (MTR_CALL * mtrPrimitiveFill_caFunc)(uint32_t);
mtrPrimitiveFill_caFunc mtrPrimitiveFill_ca;

/* Pixel */
typedef void (MTR_CALL * mtrPrimitivePixel_rgb_fFunc)(float, float, uint8_t,
 uint8_t, uint8_t);
mtrPrimitivePixel_rgb_fFunc mtrPrimitivePixel_rgb_f;

typedef void (MTR_CALL * mtrPrimitivePixel_rgba_fFunc)(float, float, uint8_t,
 uint8_t, uint8_t, uint8_t);
mtrPrimitivePixel_rgba_fFunc mtrPrimitivePixel_rgba_f;

typedef void (MTR_CALL * mtrPrimitivePixel_c_fFunc)(float, float, uint32_t);
mtrPrimitivePixel_c_fFunc mtrPrimitivePixel_c_f;

typedef void (MTR_CALL * mtrPrimitivePixel_ca_fFunc)(float, float, uint32_t);
mtrPrimitivePixel_ca_fFunc mtrPrimitivePixel_ca_f;

/* Line */
typedef void (MTR_CALL * mtrPrimitiveLine_rgb_fFunc)(float, float, float, float,
 uint8_t, uint8_t, uint8_t);
mtrPrimitiveLine_rgb_fFunc mtrPrimitiveLine_rgb_f;

typedef void (MTR_CALL * mtrPrimitiveLine_rgba_fFunc)(float, float, float, float,
 uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveLine_rgba_fFunc mtrPrimitiveLine_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveLine_c_fFunc)(float, float, float, float,
 uint32_t);
mtrPrimitiveLine_c_fFunc mtrPrimitiveLine_c_f;

typedef void (MTR_CALL * mtrPrimitiveLine_ca_fFunc)(float, float, float, float,
 uint32_t);
mtrPrimitiveLine_ca_fFunc mtrPrimitiveLine_ca_f;

/* Arc */
typedef void (MTR_CALL * mtrPrimitiveArc_rgb_fFunc)(float, float, float, float,
 float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveArc_rgb_fFunc mtrPrimitiveArc_rgb_f;

typedef void (MTR_CALL * mtrPrimitiveArc_rgba_fFunc)(float, float, float, float,
 float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveArc_rgba_fFunc mtrPrimitiveArc_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveArc_c_fFunc)(float, float, float, float,
 float, uint32_t);
mtrPrimitiveArc_c_fFunc mtrPrimitiveArc_c_f;

typedef void (MTR_CALL * mtrPrimitiveArc_ca_fFunc)(float, float, float, float,
 float, uint32_t);
mtrPrimitiveArc_ca_fFunc mtrPrimitiveArc_ca_f;

/* SegmentFilled */
typedef void (MTR_CALL * mtrPrimitiveSegmentFilled_rgb_fFunc)(float, float,
 float, float, float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveSegmentFilled_rgb_fFunc mtrPrimitiveSegmentFilled_rgb_f;

typedef void (MTR_CALL * mtrPrimitiveSegmentFilled_rgba_fFunc)(float, float,
 float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveSegmentFilled_rgba_fFunc mtrPrimitiveSegmentFilled_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveSegmentFilled_c_fFunc)(float, float,
 float, float, float, uint32_t);
mtrPrimitiveSegmentFilled_c_fFunc mtrPrimitiveSegmentFilled_c_f;

typedef void (MTR_CALL * mtrPrimitiveSegmentFilled_ca_fFunc)(float, float, float,
 float, float, uint32_t);
mtrPrimitiveSegmentFilled_ca_fFunc mtrPrimitiveSegmentFilled_ca_f;

/* Circle */
typedef void (MTR_CALL * mtrPrimitiveCircle_rgb_fFunc)(float, float, float,
 uint8_t, uint8_t, uint8_t);
mtrPrimitiveCircle_rgb_fFunc mtrPrimitiveCircle_rgb_f;

typedef void (MTR_CALL * mtrPrimitiveCircle_rgba_fFunc)(float, float, float,
 uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveCircle_rgba_fFunc mtrPrimitiveCircle_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveCircle_c_fFunc)(float, float, float,
 uint32_t);
mtrPrimitiveCircle_c_fFunc mtrPrimitiveCircle_c_f;

typedef void (MTR_CALL * mtrPrimitiveCircle_ca_fFunc)(float, float, float,
 uint32_t);
mtrPrimitiveCircle_ca_fFunc mtrPrimitiveCircle_ca_f;

/* CircleFilled */
typedef void (MTR_CALL * mtrPrimitiveCircleFilled_rgb_fFunc)(float, float, float,
 uint8_t, uint8_t, uint8_t);
mtrPrimitiveCircleFilled_rgb_fFunc mtrPrimitiveCircleFilled_rgb_f;

typedef void (MTR_CALL * mtrPrimitiveCircleFilled_rgba_fFunc)(float, float,
 float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveCircleFilled_rgba_fFunc mtrPrimitiveCircleFilled_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveCircleFilled_c_fFunc)(float, float, float,
 uint32_t);
mtrPrimitiveCircleFilled_c_fFunc mtrPrimitiveCircleFilled_c_f;

typedef void (MTR_CALL * mtrPrimitiveCircleFilled_ca_fFunc)(float, float, float,
 uint32_t);
mtrPrimitiveCircleFilled_ca_fFunc mtrPrimitiveCircleFilled_ca_f;

/* Ellipse */
typedef void (MTR_CALL * mtrPrimitiveEllipse_rgb_fFunc)(float, float, float,
 float, float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveEllipse_rgb_fFunc mtrPrimitiveEllipse_rgb_f;

typedef void (MTR_CALL * mtrPrimitiveEllipse_rgba_fFunc)(float, float, float,
 float, float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveEllipse_rgba_fFunc mtrPrimitiveEllipse_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveEllipse_c_fFunc)(float, float, float,
 float, float, uint32_t);
mtrPrimitiveEllipse_c_fFunc mtrPrimitiveEllipse_c_f;

typedef void (MTR_CALL * mtrPrimitiveEllipse_ca_fFunc)(float, float, float,
 float, float, uint32_t);
mtrPrimitiveEllipse_ca_fFunc mtrPrimitiveEllipse_ca_f;

/* EllipseFilled */
typedef void (MTR_CALL * mtrPrimitiveEllipseFilled_rgb_fFunc)(float, float,
 float, float, float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveEllipseFilled_rgb_fFunc mtrPrimitiveEllipseFilled_rgb_f;

typedef void (MTR_CALL * mtrPrimitiveEllipseFilled_rgba_fFunc)(float, float,
 float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveEllipseFilled_rgba_fFunc mtrPrimitiveEllipseFilled_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveEllipseFilled_c_fFunc)(float, float, float,
 float, float, uint32_t);
mtrPrimitiveEllipseFilled_c_fFunc mtrPrimitiveEllipseFilled_c_f;

typedef void (MTR_CALL * mtrPrimitiveEllipseFilled_ca_fFunc)(float, float, float,
 float, float, uint32_t);
mtrPrimitiveEllipseFilled_ca_fFunc mtrPrimitiveEllipseFilled_ca_f;

/* RingSegment */
typedef void (MTR_CALL * mtrPrimitiveRingSegment_rgb_fFunc)(float, float,
 float, float, float, float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRingSegment_rgb_fFunc mtrPrimitiveRingSegment_rgb_f;

typedef void (MTR_CALL * mtrPrimitiveRingSegment_rgba_fFunc)(float, float,
 float, float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRingSegment_rgba_fFunc mtrPrimitiveRingSegment_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveRingSegment_c_fFunc)(float, float, float,
 float, float, float, uint32_t);
mtrPrimitiveRingSegment_c_fFunc mtrPrimitiveRingSegment_c_f;

typedef void (MTR_CALL * mtrPrimitiveRingSegment_ca_fFunc)(float, float, float,
 float, float, float, uint32_t);
mtrPrimitiveRingSegment_ca_fFunc mtrPrimitiveRingSegment_ca_f;

/* RingSegmentFilled */
typedef void (MTR_CALL * mtrPrimitiveRingSegmentFilled_rgb_fFunc)(float, float,
 float, float, float, float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRingSegmentFilled_rgb_fFunc mtrPrimitiveRingSegmentFilled_rgb_f;

typedef void (MTR_CALL * mtrPrimitiveRingSegmentFilled_rgba_fFunc)(float, float,
 float, float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRingSegmentFilled_rgba_fFunc mtrPrimitiveRingSegmentFilled_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveRingSegmentFilled_c_fFunc)(float, float,
 float, float, float, float, uint32_t);
mtrPrimitiveRingSegmentFilled_c_fFunc mtrPrimitiveRingSegmentFilled_c_f;

typedef void (MTR_CALL * mtrPrimitiveRingSegmentFilled_ca_fFunc)(float, float,
 float, float, float, float, uint32_t);
mtrPrimitiveRingSegmentFilled_ca_fFunc mtrPrimitiveRingSegmentFilled_ca_f;

/* Triangle */
typedef void (MTR_CALL * mtrPrimitiveTriangle_rgb_fFunc)(float, float, float,
 float, float, float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveTriangle_rgb_fFunc mtrPrimitiveTriangle_rgb_f;

typedef void (MTR_CALL * mtrPrimitiveTriangle_rgba_fFunc)(float, float, float,
 float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveTriangle_rgba_fFunc mtrPrimitiveTriangle_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveTriangle_c_fFunc)(float, float, float,
 float, float, float, uint32_t);
mtrPrimitiveTriangle_c_fFunc mtrPrimitiveTriangle_c_f;

typedef void (MTR_CALL * mtrPrimitiveTriangle_ca_fFunc)(float, float, float,
 float, float, float, uint32_t);
mtrPrimitiveTriangle_ca_fFunc mtrPrimitiveTriangle_ca_f;

/* TriangleFilled */
typedef void (MTR_CALL * mtrPrimitiveTriangleFilled_rgb_fFunc)(float, float,
 float, float, float, float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveTriangleFilled_rgb_fFunc mtrPrimitiveTriangleFilled_rgb_f;

typedef void (MTR_CALL * mtrPrimitiveTriangleFilled_rgba_fFunc)(float, float,
 float, float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveTriangleFilled_rgba_fFunc mtrPrimitiveTriangleFilled_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveTriangleFilled_c_fFunc)(float, float,
 float, float, float, float, uint32_t);
mtrPrimitiveTriangleFilled_c_fFunc mtrPrimitiveTriangleFilled_c_f;

typedef void (MTR_CALL * mtrPrimitiveTriangleFilled_ca_fFunc)(float, float,
 float, float, float, float, uint32_t);
mtrPrimitiveTriangleFilled_ca_fFunc mtrPrimitiveTriangleFilled_ca_f;

/* Rectangle */
typedef void (MTR_CALL * mtrPrimitiveRectangle_rgb_fFunc)(float, float, float,
 float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRectangle_rgb_fFunc mtrPrimitiveRectangle_rgb_f;

typedef void (MTR_CALL * mtrPrimitiveRectangle_rgba_fFunc)(float, float, float,
 float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRectangle_rgba_fFunc mtrPrimitiveRectangle_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveRectangle_c_fFunc)(float, float, float,
 float, uint32_t);
mtrPrimitiveRectangle_c_fFunc mtrPrimitiveRectangle_c_f;

typedef void (MTR_CALL * mtrPrimitiveRectangle_ca_fFunc)(float, float, float,
 float, uint32_t);
mtrPrimitiveRectangle_ca_fFunc mtrPrimitiveRectangle_ca_f;

/* RectangleFilled */
typedef void (MTR_CALL * mtrPrimitiveRectangleFilled_rgb_fFunc)(float, float,
 float, float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRectangleFilled_rgb_fFunc mtrPrimitiveRectangleFilled_rgb_f;

typedef void (MTR_CALL * mtrPrimitiveRectangleFilled_rgba_fFunc)(float, float,
 float, float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRectangleFilled_rgba_fFunc mtrPrimitiveRectangleFilled_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveRectangleFilled_c_fFunc)(float, float,
 float, float, uint32_t);
mtrPrimitiveRectangleFilled_c_fFunc mtrPrimitiveRectangleFilled_c_f;

typedef void (MTR_CALL * mtrPrimitiveRectangleFilled_ca_fFunc)(float, float,
 float, float, uint32_t);
mtrPrimitiveRectangleFilled_ca_fFunc mtrPrimitiveRectangleFilled_ca_f;

/* RoundedRectangle */
typedef void (MTR_CALL * mtrPrimitiveRoundedRectangle_rgb_fFunc)(float, float,
 float, float, float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRoundedRectangle_rgb_fFunc mtrPrimitiveRoundedRectangle_rgb_f;

typedef void (MTR_CALL * mtrPrimitiveRoundedRectangle_rgba_fFunc)(float, float,
 float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRoundedRectangle_rgba_fFunc mtrPrimitiveRoundedRectangle_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveRoundedRectangle_c_fFunc)(float, float,
 float, float, float, uint32_t);
mtrPrimitiveRoundedRectangle_c_fFunc mtrPrimitiveRoundedRectangle_c_f;

typedef void (MTR_CALL * mtrPrimitiveRoundedRectangle_ca_fFunc)(float, float,
 float, float, float, uint32_t);
mtrPrimitiveRoundedRectangle_ca_fFunc mtrPrimitiveRoundedRectangle_ca_f;

/* RoundedRectangleFilled */
typedef void (MTR_CALL * mtrPrimitiveRoundedRectangleFilled_rgb_fFunc)(float,
 float, float, float, float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRoundedRectangleFilled_rgb_fFunc mtrPrimitiveRoundedRectangleFilled_rgb_f;

typedef void (MTR_CALL * mtrPrimitiveRoundedRectangleFilled_rgba_fFunc)(float,
 float, float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRoundedRectangleFilled_rgba_fFunc mtrPrimitiveRoundedRectangleFilled_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveRoundedRectangleFilled_c_fFunc)(float,
 float, float, float, float, uint32_t);
mtrPrimitiveRoundedRectangleFilled_c_fFunc mtrPrimitiveRoundedRectangleFilled_c_f;

typedef void (MTR_CALL * mtrPrimitiveRoundedRectangleFilled_ca_fFunc)(float,
 float, float, float, float, uint32_t);
mtrPrimitiveRoundedRectangleFilled_ca_fFunc mtrPrimitiveRoundedRectangleFilled_ca_f;

/* LineBegin, LineTo, LineEnd */
typedef void (MTR_CALL * mtrPrimitiveLineBegin_fFunc)(float, float);
mtrPrimitiveLineBegin_fFunc mtrPrimitiveLineBegin_f;

typedef void (MTR_CALL * mtrPrimitiveLineTo_rgb_fFunc)(float, float, uint8_t,
 uint8_t, uint8_t);
mtrPrimitiveLineTo_rgb_fFunc mtrPrimitiveLineTo_rgb_f;

typedef void (MTR_CALL * mtrPrimitiveLineTo_rgba_fFunc)(float, float, uint8_t,
 uint8_t, uint8_t, uint8_t);
mtrPrimitiveLineTo_rgba_fFunc mtrPrimitiveLineTo_rgba_f;

typedef void (MTR_CALL * mtrPrimitiveLineTo_c_fFunc)(float, float, uint32_t);
mtrPrimitiveLineTo_c_fFunc mtrPrimitiveLineTo_c_f;

typedef void (MTR_CALL * mtrPrimitiveLineTo_ca_fFunc)(float, float, uint32_t);
mtrPrimitiveLineTo_ca_fFunc mtrPrimitiveLineTo_ca_f;

typedef void (MTR_CALL * mtrPrimitiveLineEndFunc)(void);
mtrPrimitiveLineEndFunc mtrPrimitiveLineEnd;

#endif
