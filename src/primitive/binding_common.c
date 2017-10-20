#ifndef MTR_PRIMITIVE_BINDING_COMMON_C
#define MTR_PRIMITIVE_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(MTR_SF_PrimitiveFunctionSupported,
 MTR_PrimitiveFunctionSupported)
MTR_SCRIPT_FUNC_B_V(MTR_SF_PrimitiveInit, MTR_PrimitiveInit)
MTR_SCRIPT_FUNC_V_U8t3(MTR_SF_PrimitiveFill_rgb, MTR_PrimitiveFill_rgb)
MTR_SCRIPT_FUNC_V_U8t4(MTR_SF_PrimitiveFill_rgba, MTR_PrimitiveFill_rgba)
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_PrimitiveFill_c, MTR_PrimitiveFill_c)
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_PrimitiveFill_ca, MTR_PrimitiveFill_ca)
MTR_SCRIPT_FUNC_V_F2U8t3(MTR_SF_PrimitivePixel_rgb_f, MTR_PrimitivePixel_rgb_f)
MTR_SCRIPT_FUNC_V_F2U8t4(MTR_SF_PrimitivePixel_rgba_f,
 MTR_PrimitivePixel_rgba_f)
MTR_SCRIPT_FUNC_V_F2U32t1(MTR_SF_PrimitivePixel_c_f, MTR_PrimitivePixel_c_f)
MTR_SCRIPT_FUNC_V_F2U32t1(MTR_SF_PrimitivePixel_ca_f, MTR_PrimitivePixel_ca_f)
MTR_SCRIPT_FUNC_V_F4U8t3(MTR_SF_PrimitiveLine_rgb_f, MTR_PrimitiveLine_rgb_f)
MTR_SCRIPT_FUNC_V_F4U8t4(MTR_SF_PrimitiveLine_rgba_f, MTR_PrimitiveLine_rgba_f)
MTR_SCRIPT_FUNC_V_F4U32t1(MTR_SF_PrimitiveLine_c_f, MTR_PrimitiveLine_c_f)
MTR_SCRIPT_FUNC_V_F4U32t1(MTR_SF_PrimitiveLine_ca_f, MTR_PrimitiveLine_ca_f)
MTR_SCRIPT_FUNC_V_F5U8t3(MTR_SF_PrimitiveArc_rgb_f, MTR_PrimitiveArc_rgb_f)
MTR_SCRIPT_FUNC_V_F5U8t4(MTR_SF_PrimitiveArc_rgba_f, MTR_PrimitiveArc_rgba_f)
MTR_SCRIPT_FUNC_V_F5U32t1(MTR_SF_PrimitiveArc_c_f, MTR_PrimitiveArc_c_f)
MTR_SCRIPT_FUNC_V_F5U32t1(MTR_SF_PrimitiveArc_ca_f, MTR_PrimitiveArc_ca_f)
MTR_SCRIPT_FUNC_V_F5U8t3(MTR_SF_PrimitiveSegmentFilled_rgb_f,
 MTR_PrimitiveSegmentFilled_rgb_f)
MTR_SCRIPT_FUNC_V_F5U8t4(MTR_SF_PrimitiveSegmentFilled_rgba_f,
 MTR_PrimitiveSegmentFilled_rgba_f)
MTR_SCRIPT_FUNC_V_F5U32t1(MTR_SF_PrimitiveSegmentFilled_c_f,
 MTR_PrimitiveSegmentFilled_c_f)
MTR_SCRIPT_FUNC_V_F5U32t1(MTR_SF_PrimitiveSegmentFilled_ca_f,
 MTR_PrimitiveSegmentFilled_ca_f)
MTR_SCRIPT_FUNC_V_F3U8t3(MTR_SF_PrimitiveCircle_rgb_f,
 MTR_PrimitiveCircle_rgb_f)
MTR_SCRIPT_FUNC_V_F3U8t4(MTR_SF_PrimitiveCircle_rgba_f,
 MTR_PrimitiveCircle_rgba_f)
MTR_SCRIPT_FUNC_V_F3U32t1(MTR_SF_PrimitiveCircle_c_f, MTR_PrimitiveCircle_c_f)
MTR_SCRIPT_FUNC_V_F3U32t1(MTR_SF_PrimitiveCircle_ca_f, MTR_PrimitiveCircle_ca_f)
MTR_SCRIPT_FUNC_V_F3U8t3(MTR_SF_PrimitiveCircleFilled_rgb_f,
 MTR_PrimitiveCircleFilled_rgb_f)
MTR_SCRIPT_FUNC_V_F3U8t4(MTR_SF_PrimitiveCircleFilled_rgba_f,
 MTR_PrimitiveCircleFilled_rgba_f)
MTR_SCRIPT_FUNC_V_F3U32t1(MTR_SF_PrimitiveCircleFilled_c_f,
 MTR_PrimitiveCircleFilled_c_f)
MTR_SCRIPT_FUNC_V_F3U32t1(MTR_SF_PrimitiveCircleFilled_ca_f,
 MTR_PrimitiveCircleFilled_ca_f)
MTR_SCRIPT_FUNC_V_F5U8t3(MTR_SF_PrimitiveEllipse_rgb_f,
 MTR_PrimitiveEllipse_rgb_f)
MTR_SCRIPT_FUNC_V_F5U8t4(MTR_SF_PrimitiveEllipse_rgba_f,
 MTR_PrimitiveEllipse_rgba_f)
MTR_SCRIPT_FUNC_V_F5U32t1(MTR_SF_PrimitiveEllipse_c_f, MTR_PrimitiveEllipse_c_f)
MTR_SCRIPT_FUNC_V_F5U32t1(MTR_SF_PrimitiveEllipse_ca_f,
 MTR_PrimitiveEllipse_ca_f)
MTR_SCRIPT_FUNC_V_F5U8t3(MTR_SF_PrimitiveEllipseFilled_rgb_f,
 MTR_PrimitiveEllipseFilled_rgb_f)
MTR_SCRIPT_FUNC_V_F5U8t4(MTR_SF_PrimitiveEllipseFilled_rgba_f,
 MTR_PrimitiveEllipseFilled_rgba_f)
MTR_SCRIPT_FUNC_V_F5U32t1(MTR_SF_PrimitiveEllipseFilled_c_f,
 MTR_PrimitiveEllipseFilled_c_f)
MTR_SCRIPT_FUNC_V_F5U32t1(MTR_SF_PrimitiveEllipseFilled_ca_f,
 MTR_PrimitiveEllipseFilled_ca_f)
MTR_SCRIPT_FUNC_V_F6U8t3(MTR_SF_PrimitiveRingSegment_rgb_f,
 MTR_PrimitiveRingSegment_rgb_f)
MTR_SCRIPT_FUNC_V_F6U8t4(MTR_SF_PrimitiveRingSegment_rgba_f,
 MTR_PrimitiveRingSegment_rgba_f)
MTR_SCRIPT_FUNC_V_F6U32t1(MTR_SF_PrimitiveRingSegment_c_f,
 MTR_PrimitiveRingSegment_c_f)
MTR_SCRIPT_FUNC_V_F6U32t1(MTR_SF_PrimitiveRingSegment_ca_f,
 MTR_PrimitiveRingSegment_ca_f)
MTR_SCRIPT_FUNC_V_F6U8t3(MTR_SF_PrimitiveRingSegmentFilled_rgb_f,
 MTR_PrimitiveRingSegmentFilled_rgb_f)
MTR_SCRIPT_FUNC_V_F6U8t4(MTR_SF_PrimitiveRingSegmentFilled_rgba_f,
 MTR_PrimitiveRingSegmentFilled_rgba_f)
MTR_SCRIPT_FUNC_V_F6U32t1(MTR_SF_PrimitiveRingSegmentFilled_c_f,
 MTR_PrimitiveRingSegmentFilled_c_f)
MTR_SCRIPT_FUNC_V_F6U32t1(MTR_SF_PrimitiveRingSegmentFilled_ca_f,
 MTR_PrimitiveRingSegmentFilled_ca_f)
MTR_SCRIPT_FUNC_V_F6U8t3(MTR_SF_PrimitiveTriangle_rgb_f,
 MTR_PrimitiveTriangle_rgb_f)
MTR_SCRIPT_FUNC_V_F6U8t4(MTR_SF_PrimitiveTriangle_rgba_f,
 MTR_PrimitiveTriangle_rgba_f)
MTR_SCRIPT_FUNC_V_F6U32t1(MTR_SF_PrimitiveTriangle_c_f,
 MTR_PrimitiveTriangle_c_f)
MTR_SCRIPT_FUNC_V_F6U32t1(MTR_SF_PrimitiveTriangle_ca_f,
 MTR_PrimitiveTriangle_ca_f)
MTR_SCRIPT_FUNC_V_F6U8t3(MTR_SF_PrimitiveTriangleFilled_rgb_f,
 MTR_PrimitiveTriangleFilled_rgb_f)
MTR_SCRIPT_FUNC_V_F6U8t4(MTR_SF_PrimitiveTriangleFilled_rgba_f,
 MTR_PrimitiveTriangleFilled_rgba_f)
MTR_SCRIPT_FUNC_V_F6U32t1(MTR_SF_PrimitiveTriangleFilled_c_f,
 MTR_PrimitiveTriangleFilled_c_f)
MTR_SCRIPT_FUNC_V_F6U32t1(MTR_SF_PrimitiveTriangleFilled_ca_f,
 MTR_PrimitiveTriangleFilled_ca_f)
MTR_SCRIPT_FUNC_V_F4U8t3(MTR_SF_PrimitiveRectangle_rgb_f,
 MTR_PrimitiveRectangle_rgb_f)
MTR_SCRIPT_FUNC_V_F4U8t4(MTR_SF_PrimitiveRectangle_rgba_f,
 MTR_PrimitiveRectangle_rgba_f)
MTR_SCRIPT_FUNC_V_F4U32t1(MTR_SF_PrimitiveRectangle_c_f,
 MTR_PrimitiveRectangle_c_f)
MTR_SCRIPT_FUNC_V_F4U32t1(MTR_SF_PrimitiveRectangle_ca_f,
 MTR_PrimitiveRectangle_ca_f)
MTR_SCRIPT_FUNC_V_F4U8t3(MTR_SF_PrimitiveRectangleFilled_rgb_f,
 MTR_PrimitiveRectangleFilled_rgb_f)
MTR_SCRIPT_FUNC_V_F4U8t4(MTR_SF_PrimitiveRectangleFilled_rgba_f,
 MTR_PrimitiveRectangleFilled_rgba_f)
MTR_SCRIPT_FUNC_V_F4U32t1(MTR_SF_PrimitiveRectangleFilled_c_f,
 MTR_PrimitiveRectangleFilled_c_f)
MTR_SCRIPT_FUNC_V_F4U32t1(MTR_SF_PrimitiveRectangleFilled_ca_f,
 MTR_PrimitiveRectangleFilled_ca_f)
MTR_SCRIPT_FUNC_V_F5U8t3(MTR_SF_PrimitiveRoundedRectangle_rgb_f,
 MTR_PrimitiveRoundedRectangle_rgb_f)
MTR_SCRIPT_FUNC_V_F5U8t4(MTR_SF_PrimitiveRoundedRectangle_rgba_f,
 MTR_PrimitiveRoundedRectangle_rgba_f)
MTR_SCRIPT_FUNC_V_F5U32t1(MTR_SF_PrimitiveRoundedRectangle_c_f,
 MTR_PrimitiveRoundedRectangle_c_f)
MTR_SCRIPT_FUNC_V_F5U32t1(MTR_SF_PrimitiveRoundedRectangle_ca_f,
 MTR_PrimitiveRoundedRectangle_ca_f)
MTR_SCRIPT_FUNC_V_F5U8t3(MTR_SF_PrimitiveRoundedRectangleFilled_rgb_f,
 MTR_PrimitiveRoundedRectangleFilled_rgb_f)
MTR_SCRIPT_FUNC_V_F5U8t4(MTR_SF_PrimitiveRoundedRectangleFilled_rgba_f,
 MTR_PrimitiveRoundedRectangleFilled_rgba_f)
MTR_SCRIPT_FUNC_V_F5U32t1(MTR_SF_PrimitiveRoundedRectangleFilled_c_f,
 MTR_PrimitiveRoundedRectangleFilled_c_f)
MTR_SCRIPT_FUNC_V_F5U32t1(MTR_SF_PrimitiveRoundedRectangleFilled_ca_f,
 MTR_PrimitiveRoundedRectangleFilled_ca_f)
MTR_SCRIPT_FUNC_V_F2(MTR_SF_PrimitiveLineBegin_f, MTR_PrimitiveLineBegin_f)
MTR_SCRIPT_FUNC_V_F2U8t3(MTR_SF_PrimitiveLineTo_rgb_f,
 MTR_PrimitiveLineTo_rgb_f)
MTR_SCRIPT_FUNC_V_F2U8t4(MTR_SF_PrimitiveLineTo_rgba_f,
 MTR_PrimitiveLineTo_rgba_f)
MTR_SCRIPT_FUNC_V_F2U32t1(MTR_SF_PrimitiveLineTo_c_f, MTR_PrimitiveLineTo_c_f)
MTR_SCRIPT_FUNC_V_F2U32t1(MTR_SF_PrimitiveLineTo_ca_f, MTR_PrimitiveLineTo_ca_f)
MTR_SCRIPT_FUNC_V_V(MTR_SF_PrimitiveLineEnd, MTR_PrimitiveLineEnd)

void MTR_ScriptsRegisterAll(void)
{
    mtrVm = MTR_ScriptsGetVm();

    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveFunctionSupported);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveInit);

    /* Fill */
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveFill_rgb);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveFill_rgba);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveFill_c);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveFill_ca);

    /* Pixel */
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitivePixel_rgb_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitivePixel_rgba_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitivePixel_c_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitivePixel_ca_f);

    /* Line */
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveLine_rgb_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveLine_rgba_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveLine_c_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveLine_ca_f);

    /* Arc */
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveArc_rgb_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveArc_rgba_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveArc_c_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveArc_ca_f);

    /* SegmentFilled */
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveSegmentFilled_rgb_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveSegmentFilled_rgba_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveSegmentFilled_c_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveSegmentFilled_ca_f);

    /* Circle */
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveCircle_rgb_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveCircle_rgba_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveCircle_c_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveCircle_ca_f);

    /* CircleFilled */
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveCircleFilled_rgb_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveCircleFilled_rgba_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveCircleFilled_c_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveCircleFilled_ca_f);

    /* Ellipse */
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveEllipse_rgb_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveEllipse_rgba_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveEllipse_c_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveEllipse_ca_f);

    /* EllipseFilled */
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveEllipseFilled_rgb_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveEllipseFilled_rgba_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveEllipseFilled_c_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveEllipseFilled_ca_f);

    /* RingSegment */
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveRingSegment_rgb_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveRingSegment_rgba_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveRingSegment_c_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveRingSegment_ca_f);

    /* RingSegmentFilled */
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE,
     PrimitiveRingSegmentFilled_rgb_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE,
     PrimitiveRingSegmentFilled_rgba_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE,
     PrimitiveRingSegmentFilled_c_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE,
     PrimitiveRingSegmentFilled_ca_f);

    /* Triangle */
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveTriangle_rgb_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveTriangle_rgba_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveTriangle_c_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveTriangle_ca_f);

    /* TriangleFilled */
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveTriangleFilled_rgb_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE,
     PrimitiveTriangleFilled_rgba_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveTriangleFilled_c_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveTriangleFilled_ca_f);

    /* Rectangle */
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveRectangle_rgb_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveRectangle_rgba_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveRectangle_c_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveRectangle_ca_f);

    /* RectangleFilled */
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE,
     PrimitiveRectangleFilled_rgb_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE,
     PrimitiveRectangleFilled_rgba_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveRectangleFilled_c_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveRectangleFilled_ca_f);

    /* RoundedRectangle */
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE,
     PrimitiveRoundedRectangle_rgb_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE,
     PrimitiveRoundedRectangle_rgba_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveRoundedRectangle_c_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE,
     PrimitiveRoundedRectangle_ca_f);

    /* RoundedRectangleFilled */
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE,
     PrimitiveRoundedRectangleFilled_rgb_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE,
     PrimitiveRoundedRectangleFilled_rgba_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE,
     PrimitiveRoundedRectangleFilled_c_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE,
     PrimitiveRoundedRectangleFilled_ca_f);

    /* Stroke Line */
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveLineBegin_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveLineTo_rgb_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveLineTo_rgba_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveLineTo_c_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveLineTo_ca_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PrimitiveLineEnd);
}

#endif
