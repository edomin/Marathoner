#ifndef MTR_PRIMITIVE_BINDING_COMMON_C
#define MTR_PRIMITIVE_BINDING_COMMON_C

#include "marathoner/script_func.h"

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
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();

    MTR_FIND_FUNCTION(mtrPrimitiveInit, MTR_SOURCE_MODULE);

    /* Fill */
    MTR_FIND_FUNCTION(mtrPrimitiveFill_rgb, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveFill_rgba, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveFill_c, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveFill_ca, MTR_SOURCE_MODULE);

    /* Pixel */
    MTR_FIND_FUNCTION(mtrPrimitivePixel_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitivePixel_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitivePixel_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitivePixel_ca_f, MTR_SOURCE_MODULE);

    /* Line */
    MTR_FIND_FUNCTION(mtrPrimitiveLine_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveLine_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveLine_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveLine_ca_f, MTR_SOURCE_MODULE);

    /* Arc */
    MTR_FIND_FUNCTION(mtrPrimitiveArc_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveArc_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveArc_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveArc_ca_f, MTR_SOURCE_MODULE);

    /* SegmentFilled */
    MTR_FIND_FUNCTION(mtrPrimitiveSegmentFilled_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveSegmentFilled_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveSegmentFilled_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveSegmentFilled_ca_f, MTR_SOURCE_MODULE);

    /* Circle */
    MTR_FIND_FUNCTION(mtrPrimitiveCircle_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveCircle_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveCircle_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveCircle_ca_f, MTR_SOURCE_MODULE);

    /* CircleFilled */
    MTR_FIND_FUNCTION(mtrPrimitiveCircleFilled_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveCircleFilled_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveCircleFilled_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveCircleFilled_ca_f, MTR_SOURCE_MODULE);

    /* Ellipse */
    MTR_FIND_FUNCTION(mtrPrimitiveEllipse_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveEllipse_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveEllipse_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveEllipse_ca_f, MTR_SOURCE_MODULE);

    /* EllipseFilled */
    MTR_FIND_FUNCTION(mtrPrimitiveEllipseFilled_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveEllipseFilled_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveEllipseFilled_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveEllipseFilled_ca_f, MTR_SOURCE_MODULE);

    /* RingSegment */
    MTR_FIND_FUNCTION(mtrPrimitiveRingSegment_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRingSegment_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRingSegment_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRingSegment_ca_f, MTR_SOURCE_MODULE);

    /* RingSegmentFilled */
    MTR_FIND_FUNCTION(mtrPrimitiveRingSegmentFilled_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRingSegmentFilled_rgba_f,
     MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRingSegmentFilled_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRingSegmentFilled_ca_f, MTR_SOURCE_MODULE);

    /* Triangle */
    MTR_FIND_FUNCTION(mtrPrimitiveTriangle_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveTriangle_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveTriangle_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveTriangle_ca_f, MTR_SOURCE_MODULE);

    /* TriangleFilled */
    MTR_FIND_FUNCTION(mtrPrimitiveTriangleFilled_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveTriangleFilled_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveTriangleFilled_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveTriangleFilled_ca_f, MTR_SOURCE_MODULE);

    /* Rectangle */
    MTR_FIND_FUNCTION(mtrPrimitiveRectangle_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRectangle_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRectangle_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRectangle_ca_f, MTR_SOURCE_MODULE);

    /* RectangleFilled */
    MTR_FIND_FUNCTION(mtrPrimitiveRectangleFilled_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRectangleFilled_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRectangleFilled_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRectangleFilled_ca_f, MTR_SOURCE_MODULE);

    /* RoundedRectangle */
    MTR_FIND_FUNCTION(mtrPrimitiveRoundedRectangle_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRoundedRectangle_rgba_f,
     MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRoundedRectangle_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRoundedRectangle_ca_f, MTR_SOURCE_MODULE);

    /* RoundedRectangleFilled */
    MTR_FIND_FUNCTION(mtrPrimitiveRoundedRectangleFilled_rgb_f,
     MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRoundedRectangleFilled_rgba_f,
     MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRoundedRectangleFilled_c_f,
     MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRoundedRectangleFilled_ca_f,
     MTR_SOURCE_MODULE);

    /* Stroke Line */
    MTR_FIND_FUNCTION(mtrPrimitiveLineBegin_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveLineTo_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveLineTo_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveLineTo_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveLineTo_ca_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveLineEnd, MTR_SOURCE_MODULE);

    if (ok)
    {
        mtrScriptsRegisterFunction(mtrSF_PrimitiveInit, "PrimitiveInit");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveFill_rgb,
         "PrimitiveFill_rgb");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveFill_rgba,
         "PrimitiveFill_rgba");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveFill_c,
         "PrimitiveFill_c");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveFill_ca,
         "PrimitiveFill_ca");

        mtrScriptsRegisterFunction(mtrSF_PrimitivePixel_rgb_f,
         "PrimitivePixel_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitivePixel_rgba_f,
         "PrimitivePixel_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitivePixel_c_f,
         "PrimitivePixel_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitivePixel_ca_f,
         "PrimitivePixel_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveLine_rgb_f,
         "PrimitiveLine_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveLine_rgba_f,
         "PrimitiveLine_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveLine_c_f,
         "PrimitiveLine_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveLine_ca_f,
         "PrimitiveLine_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveArc_rgb_f,
         "PrimitiveArc_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveArc_rgba_f,
         "PrimitiveArc_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveArc_c_f,
         "PrimitiveArc_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveArc_ca_f,
         "PrimitiveArc_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveSegmentFilled_rgb_f,
         "PrimitiveSegmentFilled_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveSegmentFilled_rgba_f,
         "PrimitiveSegmentFilled_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveSegmentFilled_c_f,
         "PrimitiveSegmentFilled_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveSegmentFilled_ca_f,
         "PrimitiveSegmentFilled_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveCircle_rgb_f,
         "PrimitiveCircle_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveCircle_rgba_f,
         "PrimitiveCircle_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveCircle_c_f,
         "PrimitiveCircle_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveCircle_ca_f,
         "PrimitiveCircle_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveCircleFilled_rgb_f,
         "PrimitiveCircleFilled_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveCircleFilled_rgba_f,
         "PrimitiveCircleFilled_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveCircleFilled_c_f,
         "PrimitiveCircleFilled_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveCircleFilled_ca_f,
         "PrimitiveCircleFilled_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveEllipse_rgb_f,
         "PrimitiveEllipse_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveEllipse_rgba_f,
         "PrimitiveEllipse_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveEllipse_c_f,
         "PrimitiveEllipse_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveEllipse_ca_f,
         "PrimitiveEllipse_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveEllipseFilled_rgb_f,
         "PrimitiveEllipseFilled_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveEllipseFilled_rgba_f,
         "PrimitiveEllipseFilled_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveEllipseFilled_c_f,
         "PrimitiveEllipseFilled_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveEllipseFilled_ca_f,
         "PrimitiveEllipseFilled_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveRingSegment_rgb_f,
         "PrimitiveRingSegment_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRingSegment_rgba_f,
         "PrimitiveRingSegment_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRingSegment_c_f,
         "PrimitiveRingSegment_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRingSegment_ca_f,
         "PrimitiveRingSegment_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveRingSegmentFilled_rgb_f,
         "PrimitiveRingSegmentFilled_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRingSegmentFilled_rgba_f,
         "PrimitiveRingSegmentFilled_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRingSegmentFilled_c_f,
         "PrimitiveRingSegmentFilled_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRingSegmentFilled_ca_f,
         "PrimitiveRingSegmentFilled_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveTriangle_rgb_f,
         "PrimitiveTriangle_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveTriangle_rgba_f,
         "PrimitiveTriangle_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveTriangle_c_f,
         "PrimitiveTriangle_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveTriangle_ca_f,
         "PrimitiveTriangle_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveTriangleFilled_rgb_f,
         "PrimitiveTriangleFilled_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveTriangleFilled_rgba_f,
         "PrimitiveTriangleFilled_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveTriangleFilled_c_f,
         "PrimitiveTriangleFilled_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveTriangleFilled_ca_f,
         "PrimitiveTriangleFilled_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveRectangle_rgb_f,
         "PrimitiveRectangle_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRectangle_rgba_f,
         "PrimitiveRectangle_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRectangle_c_f,
         "PrimitiveRectangle_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRectangle_ca_f,
         "PrimitiveRectangle_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveRectangleFilled_rgb_f,
         "PrimitiveRectangleFilled_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRectangleFilled_rgba_f,
         "PrimitiveRectangleFilled_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRectangleFilled_c_f,
         "PrimitiveRectangleFilled_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRectangleFilled_ca_f,
         "PrimitiveRectangleFilled_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveRoundedRectangle_rgb_f,
         "PrimitiveRoundedRectangle_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRoundedRectangle_rgba_f,
         "PrimitiveRoundedRectangle_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRoundedRectangle_c_f,
         "PrimitiveRoundedRectangle_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRoundedRectangle_ca_f,
         "PrimitiveRoundedRectangle_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveRoundedRectangleFilled_rgb_f,
         "PrimitiveRoundedRectangleFilled_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRoundedRectangleFilled_rgba_f,
         "PrimitiveRoundedRectangleFilled_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRoundedRectangleFilled_c_f,
         "PrimitiveRoundedRectangleFilled_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRoundedRectangleFilled_ca_f,
         "PrimitiveRoundedRectangleFilled_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveLineBegin_f,
         "PrimitiveLineBegin_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveLineTo_rgb_f,
         "PrimitiveLineTo_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveLineTo_rgba_f,
         "PrimitiveLineTo_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveLineTo_c_f,
         "PrimitiveLineTo_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveLineTo_ca_f,
         "PrimitiveLineTo_ca_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveLineEnd,
         "PrimitiveLineEnd");
    }
    else
    {
        mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
    }
}

#endif
