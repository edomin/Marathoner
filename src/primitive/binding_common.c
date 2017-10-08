#ifndef MTR_PRIMITIVE_BINDING_COMMON_C
#define MTR_PRIMITIVE_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(mtrSF_PrimitiveFunctionSupported,
 mtrPrimitiveFunctionSupported)
MTR_SCRIPT_FUNC_B_V(mtrSF_PrimitiveInit, mtrPrimitiveInit)
MTR_SCRIPT_FUNC_V_U8t3(mtrSF_PrimitiveFill_rgb, mtrPrimitiveFill_rgb)
MTR_SCRIPT_FUNC_V_U8t4(mtrSF_PrimitiveFill_rgba, mtrPrimitiveFill_rgba)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_PrimitiveFill_c, mtrPrimitiveFill_c)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_PrimitiveFill_ca, mtrPrimitiveFill_ca)
MTR_SCRIPT_FUNC_V_F2U8t3(mtrSF_PrimitivePixel_rgb_f, mtrPrimitivePixel_rgb_f)
MTR_SCRIPT_FUNC_V_F2U8t4(mtrSF_PrimitivePixel_rgba_f, mtrPrimitivePixel_rgba_f)
MTR_SCRIPT_FUNC_V_F2U32t1(mtrSF_PrimitivePixel_c_f, mtrPrimitivePixel_c_f)
MTR_SCRIPT_FUNC_V_F2U32t1(mtrSF_PrimitivePixel_ca_f, mtrPrimitivePixel_ca_f)
MTR_SCRIPT_FUNC_V_F4U8t3(mtrSF_PrimitiveLine_rgb_f, mtrPrimitiveLine_rgb_f)
MTR_SCRIPT_FUNC_V_F4U8t4(mtrSF_PrimitiveLine_rgba_f, mtrPrimitiveLine_rgba_f)
MTR_SCRIPT_FUNC_V_F4U32t1(mtrSF_PrimitiveLine_c_f, mtrPrimitiveLine_c_f)
MTR_SCRIPT_FUNC_V_F4U32t1(mtrSF_PrimitiveLine_ca_f, mtrPrimitiveLine_ca_f)
MTR_SCRIPT_FUNC_V_F5U8t3(mtrSF_PrimitiveArc_rgb_f, mtrPrimitiveArc_rgb_f)
MTR_SCRIPT_FUNC_V_F5U8t4(mtrSF_PrimitiveArc_rgba_f, mtrPrimitiveArc_rgba_f)
MTR_SCRIPT_FUNC_V_F5U32t1(mtrSF_PrimitiveArc_c_f, mtrPrimitiveArc_c_f)
MTR_SCRIPT_FUNC_V_F5U32t1(mtrSF_PrimitiveArc_ca_f, mtrPrimitiveArc_ca_f)
MTR_SCRIPT_FUNC_V_F5U8t3(mtrSF_PrimitiveSegmentFilled_rgb_f,
 mtrPrimitiveSegmentFilled_rgb_f)
MTR_SCRIPT_FUNC_V_F5U8t4(mtrSF_PrimitiveSegmentFilled_rgba_f,
 mtrPrimitiveSegmentFilled_rgba_f)
MTR_SCRIPT_FUNC_V_F5U32t1(mtrSF_PrimitiveSegmentFilled_c_f,
 mtrPrimitiveSegmentFilled_c_f)
MTR_SCRIPT_FUNC_V_F5U32t1(mtrSF_PrimitiveSegmentFilled_ca_f,
 mtrPrimitiveSegmentFilled_ca_f)
MTR_SCRIPT_FUNC_V_F3U8t3(mtrSF_PrimitiveCircle_rgb_f, mtrPrimitiveCircle_rgb_f)
MTR_SCRIPT_FUNC_V_F3U8t4(mtrSF_PrimitiveCircle_rgba_f,
 mtrPrimitiveCircle_rgba_f)
MTR_SCRIPT_FUNC_V_F3U32t1(mtrSF_PrimitiveCircle_c_f, mtrPrimitiveCircle_c_f)
MTR_SCRIPT_FUNC_V_F3U32t1(mtrSF_PrimitiveCircle_ca_f, mtrPrimitiveCircle_ca_f)
MTR_SCRIPT_FUNC_V_F3U8t3(mtrSF_PrimitiveCircleFilled_rgb_f,
 mtrPrimitiveCircleFilled_rgb_f)
MTR_SCRIPT_FUNC_V_F3U8t4(mtrSF_PrimitiveCircleFilled_rgba_f,
 mtrPrimitiveCircleFilled_rgba_f)
MTR_SCRIPT_FUNC_V_F3U32t1(mtrSF_PrimitiveCircleFilled_c_f,
 mtrPrimitiveCircleFilled_c_f)
MTR_SCRIPT_FUNC_V_F3U32t1(mtrSF_PrimitiveCircleFilled_ca_f,
 mtrPrimitiveCircleFilled_ca_f)
MTR_SCRIPT_FUNC_V_F5U8t3(mtrSF_PrimitiveEllipse_rgb_f,
 mtrPrimitiveEllipse_rgb_f)
MTR_SCRIPT_FUNC_V_F5U8t4(mtrSF_PrimitiveEllipse_rgba_f,
 mtrPrimitiveEllipse_rgba_f)
MTR_SCRIPT_FUNC_V_F5U32t1(mtrSF_PrimitiveEllipse_c_f, mtrPrimitiveEllipse_c_f)
MTR_SCRIPT_FUNC_V_F5U32t1(mtrSF_PrimitiveEllipse_ca_f, mtrPrimitiveEllipse_ca_f)
MTR_SCRIPT_FUNC_V_F5U8t3(mtrSF_PrimitiveEllipseFilled_rgb_f,
 mtrPrimitiveEllipseFilled_rgb_f)
MTR_SCRIPT_FUNC_V_F5U8t4(mtrSF_PrimitiveEllipseFilled_rgba_f,
 mtrPrimitiveEllipseFilled_rgba_f)
MTR_SCRIPT_FUNC_V_F5U32t1(mtrSF_PrimitiveEllipseFilled_c_f,
 mtrPrimitiveEllipseFilled_c_f)
MTR_SCRIPT_FUNC_V_F5U32t1(mtrSF_PrimitiveEllipseFilled_ca_f,
 mtrPrimitiveEllipseFilled_ca_f)
MTR_SCRIPT_FUNC_V_F6U8t3(mtrSF_PrimitiveRingSegment_rgb_f,
 mtrPrimitiveRingSegment_rgb_f)
MTR_SCRIPT_FUNC_V_F6U8t4(mtrSF_PrimitiveRingSegment_rgba_f,
 mtrPrimitiveRingSegment_rgba_f)
MTR_SCRIPT_FUNC_V_F6U32t1(mtrSF_PrimitiveRingSegment_c_f,
 mtrPrimitiveRingSegment_c_f)
MTR_SCRIPT_FUNC_V_F6U32t1(mtrSF_PrimitiveRingSegment_ca_f,
 mtrPrimitiveRingSegment_ca_f)
MTR_SCRIPT_FUNC_V_F6U8t3(mtrSF_PrimitiveRingSegmentFilled_rgb_f,
 mtrPrimitiveRingSegmentFilled_rgb_f)
MTR_SCRIPT_FUNC_V_F6U8t4(mtrSF_PrimitiveRingSegmentFilled_rgba_f,
 mtrPrimitiveRingSegmentFilled_rgba_f)
MTR_SCRIPT_FUNC_V_F6U32t1(mtrSF_PrimitiveRingSegmentFilled_c_f,
 mtrPrimitiveRingSegmentFilled_c_f)
MTR_SCRIPT_FUNC_V_F6U32t1(mtrSF_PrimitiveRingSegmentFilled_ca_f,
 mtrPrimitiveRingSegmentFilled_ca_f)
MTR_SCRIPT_FUNC_V_F6U8t3(mtrSF_PrimitiveTriangle_rgb_f,
 mtrPrimitiveTriangle_rgb_f)
MTR_SCRIPT_FUNC_V_F6U8t4(mtrSF_PrimitiveTriangle_rgba_f,
 mtrPrimitiveTriangle_rgba_f)
MTR_SCRIPT_FUNC_V_F6U32t1(mtrSF_PrimitiveTriangle_c_f, mtrPrimitiveTriangle_c_f)
MTR_SCRIPT_FUNC_V_F6U32t1(mtrSF_PrimitiveTriangle_ca_f,
 mtrPrimitiveTriangle_ca_f)
MTR_SCRIPT_FUNC_V_F6U8t3(mtrSF_PrimitiveTriangleFilled_rgb_f,
 mtrPrimitiveTriangleFilled_rgb_f)
MTR_SCRIPT_FUNC_V_F6U8t4(mtrSF_PrimitiveTriangleFilled_rgba_f,
 mtrPrimitiveTriangleFilled_rgba_f)
MTR_SCRIPT_FUNC_V_F6U32t1(mtrSF_PrimitiveTriangleFilled_c_f,
 mtrPrimitiveTriangleFilled_c_f)
MTR_SCRIPT_FUNC_V_F6U32t1(mtrSF_PrimitiveTriangleFilled_ca_f,
 mtrPrimitiveTriangleFilled_ca_f)
MTR_SCRIPT_FUNC_V_F4U8t3(mtrSF_PrimitiveRectangle_rgb_f,
 mtrPrimitiveRectangle_rgb_f)
MTR_SCRIPT_FUNC_V_F4U8t4(mtrSF_PrimitiveRectangle_rgba_f,
 mtrPrimitiveRectangle_rgba_f)
MTR_SCRIPT_FUNC_V_F4U32t1(mtrSF_PrimitiveRectangle_c_f,
 mtrPrimitiveRectangle_c_f)
MTR_SCRIPT_FUNC_V_F4U32t1(mtrSF_PrimitiveRectangle_ca_f,
 mtrPrimitiveRectangle_ca_f)
MTR_SCRIPT_FUNC_V_F4U8t3(mtrSF_PrimitiveRectangleFilled_rgb_f,
 mtrPrimitiveRectangleFilled_rgb_f)
MTR_SCRIPT_FUNC_V_F4U8t4(mtrSF_PrimitiveRectangleFilled_rgba_f,
 mtrPrimitiveRectangleFilled_rgba_f)
MTR_SCRIPT_FUNC_V_F4U32t1(mtrSF_PrimitiveRectangleFilled_c_f,
 mtrPrimitiveRectangleFilled_c_f)
MTR_SCRIPT_FUNC_V_F4U32t1(mtrSF_PrimitiveRectangleFilled_ca_f,
 mtrPrimitiveRectangleFilled_ca_f)
MTR_SCRIPT_FUNC_V_F5U8t3(mtrSF_PrimitiveRoundedRectangle_rgb_f,
 mtrPrimitiveRoundedRectangle_rgb_f)
MTR_SCRIPT_FUNC_V_F5U8t4(mtrSF_PrimitiveRoundedRectangle_rgba_f,
 mtrPrimitiveRoundedRectangle_rgba_f)
MTR_SCRIPT_FUNC_V_F5U32t1(mtrSF_PrimitiveRoundedRectangle_c_f,
 mtrPrimitiveRoundedRectangle_c_f)
MTR_SCRIPT_FUNC_V_F5U32t1(mtrSF_PrimitiveRoundedRectangle_ca_f,
 mtrPrimitiveRoundedRectangle_ca_f)
MTR_SCRIPT_FUNC_V_F5U8t3(mtrSF_PrimitiveRoundedRectangleFilled_rgb_f,
 mtrPrimitiveRoundedRectangleFilled_rgb_f)
MTR_SCRIPT_FUNC_V_F5U8t4(mtrSF_PrimitiveRoundedRectangleFilled_rgba_f,
 mtrPrimitiveRoundedRectangleFilled_rgba_f)
MTR_SCRIPT_FUNC_V_F5U32t1(mtrSF_PrimitiveRoundedRectangleFilled_c_f,
 mtrPrimitiveRoundedRectangleFilled_c_f)
MTR_SCRIPT_FUNC_V_F5U32t1(mtrSF_PrimitiveRoundedRectangleFilled_ca_f,
 mtrPrimitiveRoundedRectangleFilled_ca_f)
MTR_SCRIPT_FUNC_V_F2(mtrSF_PrimitiveLineBegin_f, mtrPrimitiveLineBegin_f)
MTR_SCRIPT_FUNC_V_F2U8t3(mtrSF_PrimitiveLineTo_rgb_f, mtrPrimitiveLineTo_rgb_f)
MTR_SCRIPT_FUNC_V_F2U8t4(mtrSF_PrimitiveLineTo_rgba_f,
 mtrPrimitiveLineTo_rgba_f)
MTR_SCRIPT_FUNC_V_F2U32t1(mtrSF_PrimitiveLineTo_c_f, mtrPrimitiveLineTo_c_f)
MTR_SCRIPT_FUNC_V_F2U32t1(mtrSF_PrimitiveLineTo_ca_f, mtrPrimitiveLineTo_ca_f)
MTR_SCRIPT_FUNC_V_V(mtrSF_PrimitiveLineEnd, mtrPrimitiveLineEnd)

void mtrScriptsRegisterAll(void)
{
    mtrVm = mtrScriptsGetVm();

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
