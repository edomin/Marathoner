#include "binding.h"

#include "marathoner/plugin_common.c"
#include "../binding_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Primitive_SDL2_gpu_Lua";
    report->version = MTR_VERSION_PRIMITIVE_SDL2_GPU_LUA;
    report->subsystem = "binding";
    report->prereqsCount = 2;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    report->prereqs[0] = "Primitive_SDL2_gpu";
    report->prereqs[1] = "Script_Lua";
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

MTR_EXPORT void MTR_CALL mtrPluginInit(void)
{
    bool ok;
    ok = true;

    mtrLogWrite_s("Reporting Lua compile-time version:", 3, MTR_LMT_INFO,
     LUA_RELEASE);

    mtrScriptsRegisterFunction = (mtrScriptsRegisterFunctionFunc)mtrFindFunction("Script_Lua",
     "mtrScriptsRegisterFunction");
    if (mtrScriptsRegisterFunction == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrScriptsRegisterFunction");
        ok = false;
    }
    mtrScriptsGetVm = (mtrScriptsGetVmFunc)mtrFindFunction("Script_Lua",
      "mtrScriptsGetVm");
    if (mtrScriptsGetVm == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrScriptsGetVm");
        ok = false;
    }
    else
    {
        mtrVm = mtrScriptsGetVm();
        mtrPrimitiveInit = (mtrPrimitiveInitFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveInit");
        if (mtrPrimitiveInit == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveInit");
            ok = false;
        }
        /* Fill */
        mtrPrimitiveFill_rgb = (mtrPrimitiveFill_rgbFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveFill_rgb");
        if (mtrPrimitiveFill_rgb == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveFill_rgb");
            ok = false;
        }
        mtrPrimitiveFill_rgba = (mtrPrimitiveFill_rgbaFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveFill_rgba");
        if (mtrPrimitiveFill_rgba == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveFill_rgba");
            ok = false;
        }
        mtrPrimitiveFill_c = (mtrPrimitiveFill_cFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveFill_c");
        if (mtrPrimitiveFill_c == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveFill_c");
            ok = false;
        }
        mtrPrimitiveFill_ca = (mtrPrimitiveFill_caFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveFill_ca");
        if (mtrPrimitiveFill_ca == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveFill_ca");
            ok = false;
        }
        /* Pixel */
        mtrPrimitivePixel_rgb_f = (mtrPrimitivePixel_rgb_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitivePixel_rgb_f");
        if (mtrPrimitivePixel_rgb_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitivePixel_rgb_f");
            ok = false;
        }
        mtrPrimitivePixel_rgba_f = (mtrPrimitivePixel_rgba_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitivePixel_rgba_f");
        if (mtrPrimitivePixel_rgba_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitivePixel_rgba_f");
            ok = false;
        }
        mtrPrimitivePixel_c_f = (mtrPrimitivePixel_c_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitivePixel_c_f");
        if (mtrPrimitivePixel_c_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitivePixel_c_f");
            ok = false;
        }
        mtrPrimitivePixel_ca_f = (mtrPrimitivePixel_ca_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitivePixel_ca_f");
        if (mtrPrimitivePixel_ca_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitivePixel_ca_f");
            ok = false;
        }
        /* Line */
        mtrPrimitiveLine_rgb_f = (mtrPrimitiveLine_rgb_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveLine_rgb_f");
        if (mtrPrimitiveLine_rgb_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveLine_rgb_f");
            ok = false;
        }
        mtrPrimitiveLine_rgba_f = (mtrPrimitiveLine_rgba_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveLine_rgba_f");
        if (mtrPrimitiveLine_rgba_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveLine_rgba_f");
            ok = false;
        }
        mtrPrimitiveLine_c_f = (mtrPrimitiveLine_c_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveLine_c_f");
        if (mtrPrimitiveLine_c_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveLine_c_f");
            ok = false;
        }
        mtrPrimitiveLine_ca_f = (mtrPrimitiveLine_ca_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveLine_ca_f");
        if (mtrPrimitiveLine_ca_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveLine_ca_f");
            ok = false;
        }
        /* Arc */
        mtrPrimitiveArc_rgb_f = (mtrPrimitiveArc_rgb_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveArc_rgb_f");
        if (mtrPrimitiveArc_rgb_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveArc_rgb_f");
            ok = false;
        }
        mtrPrimitiveArc_rgba_f = (mtrPrimitiveArc_rgba_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveArc_rgba_f");
        if (mtrPrimitiveArc_rgba_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveArc_rgba_f");
            ok = false;
        }
        mtrPrimitiveArc_c_f = (mtrPrimitiveArc_c_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveArc_c_f");
        if (mtrPrimitiveArc_c_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveArc_c_f");
            ok = false;
        }
        mtrPrimitiveArc_ca_f = (mtrPrimitiveArc_ca_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveArc_ca_f");
        if (mtrPrimitiveArc_ca_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveArc_ca_f");
            ok = false;
        }
        /* SegmentFilled */
        mtrPrimitiveSegmentFilled_rgb_f = (mtrPrimitiveSegmentFilled_rgb_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveSegmentFilled_rgb_f");
        if (mtrPrimitiveSegmentFilled_rgb_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveSegmentFilled_rgb_f");
            ok = false;
        }
        mtrPrimitiveSegmentFilled_rgba_f = (mtrPrimitiveSegmentFilled_rgba_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveSegmentFilled_rgba_f");
        if (mtrPrimitiveSegmentFilled_rgba_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveSegmentFilled_rgba_f");
            ok = false;
        }
        mtrPrimitiveSegmentFilled_c_f = (mtrPrimitiveSegmentFilled_c_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveSegmentFilled_c_f");
        if (mtrPrimitiveSegmentFilled_c_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveSegmentFilled_c_f");
            ok = false;
        }
        mtrPrimitiveSegmentFilled_ca_f = (mtrPrimitiveSegmentFilled_ca_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveSegmentFilled_ca_f");
        if (mtrPrimitiveSegmentFilled_ca_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveSegmentFilled_ca_f");
            ok = false;
        }
        /* Circle */
        mtrPrimitiveCircle_rgb_f = (mtrPrimitiveCircle_rgb_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveCircle_rgb_f");
        if (mtrPrimitiveCircle_rgb_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveCircle_rgb_f");
            ok = false;
        }
        mtrPrimitiveCircle_rgba_f = (mtrPrimitiveCircle_rgba_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveCircle_rgba_f");
        if (mtrPrimitiveCircle_rgba_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveCircle_rgba_f");
            ok = false;
        }
        mtrPrimitiveCircle_c_f = (mtrPrimitiveCircle_c_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveCircle_c_f");
        if (mtrPrimitiveCircle_c_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveCircle_c_f");
            ok = false;
        }
        mtrPrimitiveCircle_ca_f = (mtrPrimitiveCircle_ca_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveCircle_ca_f");
        if (mtrPrimitiveCircle_ca_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveCircle_ca_f");
            ok = false;
        }
        /* CircleFilled */
        mtrPrimitiveCircleFilled_rgb_f = (mtrPrimitiveCircleFilled_rgb_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveCircleFilled_rgb_f");
        if (mtrPrimitiveCircleFilled_rgb_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveCircleFilled_rgb_f");
            ok = false;
        }
        mtrPrimitiveCircleFilled_rgba_f = (mtrPrimitiveCircleFilled_rgba_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveCircleFilled_rgba_f");
        if (mtrPrimitiveCircleFilled_rgba_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveCircleFilled_rgba_f");
            ok = false;
        }
        mtrPrimitiveCircleFilled_c_f = (mtrPrimitiveCircleFilled_c_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveCircleFilled_c_f");
        if (mtrPrimitiveCircleFilled_c_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveCircleFilled_c_f");
            ok = false;
        }
        mtrPrimitiveCircleFilled_ca_f = (mtrPrimitiveCircleFilled_ca_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveCircleFilled_ca_f");
        if (mtrPrimitiveCircleFilled_ca_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveCircleFilled_ca_f");
            ok = false;
        }
        /* Ellipse */
        mtrPrimitiveEllipse_rgb_f = (mtrPrimitiveEllipse_rgb_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveEllipse_rgb_f");
        if (mtrPrimitiveEllipse_rgb_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveEllipse_rgb_f");
            ok = false;
        }
        mtrPrimitiveEllipse_rgba_f = (mtrPrimitiveEllipse_rgba_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveEllipse_rgba_f");
        if (mtrPrimitiveEllipse_rgba_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveEllipse_rgba_f");
            ok = false;
        }
        mtrPrimitiveEllipse_c_f = (mtrPrimitiveEllipse_c_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveEllipse_c_f");
        if (mtrPrimitiveEllipse_c_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveEllipse_c_f");
            ok = false;
        }
        mtrPrimitiveEllipse_ca_f = (mtrPrimitiveEllipse_ca_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveEllipse_ca_f");
        if (mtrPrimitiveEllipse_ca_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveEllipse_ca_f");
            ok = false;
        }
        /* EllipseFilled */
        mtrPrimitiveEllipseFilled_rgb_f = (mtrPrimitiveEllipseFilled_rgb_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveEllipseFilled_rgb_f");
        if (mtrPrimitiveEllipseFilled_rgb_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveEllipseFilled_rgb_f");
            ok = false;
        }
        mtrPrimitiveEllipseFilled_rgba_f = (mtrPrimitiveEllipseFilled_rgba_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveEllipseFilled_rgba_f");
        if (mtrPrimitiveEllipseFilled_rgba_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveEllipseFilled_rgba_f");
            ok = false;
        }
        mtrPrimitiveEllipseFilled_c_f = (mtrPrimitiveEllipseFilled_c_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveEllipseFilled_c_f");
        if (mtrPrimitiveEllipseFilled_c_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveEllipseFilled_c_f");
            ok = false;
        }
        mtrPrimitiveEllipseFilled_ca_f = (mtrPrimitiveEllipseFilled_ca_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveEllipseFilled_ca_f");
        if (mtrPrimitiveEllipseFilled_ca_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveEllipseFilled_ca_f");
            ok = false;
        }
        /* RingSegment */
        mtrPrimitiveRingSegment_rgb_f = (mtrPrimitiveRingSegment_rgb_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRingSegment_rgb_f");
        if (mtrPrimitiveRingSegment_rgb_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRingSegment_rgb_f");
            ok = false;
        }
        mtrPrimitiveRingSegment_rgba_f = (mtrPrimitiveRingSegment_rgba_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRingSegment_rgba_f");
        if (mtrPrimitiveRingSegment_rgba_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRingSegment_rgba_f");
            ok = false;
        }
        mtrPrimitiveRingSegment_c_f = (mtrPrimitiveRingSegment_c_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRingSegment_c_f");
        if (mtrPrimitiveRingSegment_c_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRingSegment_c_f");
            ok = false;
        }
        mtrPrimitiveRingSegment_ca_f = (mtrPrimitiveRingSegment_ca_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRingSegment_ca_f");
        if (mtrPrimitiveRingSegment_ca_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRingSegment_ca_f");
            ok = false;
        }
        /* RingSegmentFilled */
        mtrPrimitiveRingSegmentFilled_rgb_f = (mtrPrimitiveRingSegmentFilled_rgb_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRingSegmentFilled_rgb_f");
        if (mtrPrimitiveRingSegmentFilled_rgb_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRingSegmentFilled_rgb_f");
            ok = false;
        }
        mtrPrimitiveRingSegmentFilled_rgba_f = (mtrPrimitiveRingSegmentFilled_rgba_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRingSegmentFilled_rgba_f");
        if (mtrPrimitiveRingSegmentFilled_rgba_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRingSegmentFilled_rgba_f");
            ok = false;
        }
        mtrPrimitiveRingSegmentFilled_c_f = (mtrPrimitiveRingSegmentFilled_c_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRingSegmentFilled_c_f");
        if (mtrPrimitiveRingSegmentFilled_c_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRingSegmentFilled_c_f");
            ok = false;
        }
        mtrPrimitiveRingSegmentFilled_ca_f = (mtrPrimitiveRingSegmentFilled_ca_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRingSegmentFilled_ca_f");
        if (mtrPrimitiveRingSegmentFilled_ca_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRingSegmentFilled_ca_f");
            ok = false;
        }
        /* Triangle */
        mtrPrimitiveTriangle_rgb_f = (mtrPrimitiveTriangle_rgb_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveTriangle_rgb_f");
        if (mtrPrimitiveTriangle_rgb_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveTriangle_rgb_f");
            ok = false;
        }
        mtrPrimitiveTriangle_rgba_f = (mtrPrimitiveTriangle_rgba_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveTriangle_rgba_f");
        if (mtrPrimitiveTriangle_rgba_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveTriangle_rgba_f");
            ok = false;
        }
        mtrPrimitiveTriangle_c_f = (mtrPrimitiveTriangle_c_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveTriangle_c_f");
        if (mtrPrimitiveTriangle_c_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveTriangle_c_f");
            ok = false;
        }
        mtrPrimitiveTriangle_ca_f = (mtrPrimitiveTriangle_ca_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveTriangle_ca_f");
        if (mtrPrimitiveTriangle_ca_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveTriangle_ca_f");
            ok = false;
        }
        /* TriangleFilled */
        mtrPrimitiveTriangleFilled_rgb_f = (mtrPrimitiveTriangleFilled_rgb_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveTriangleFilled_rgb_f");
        if (mtrPrimitiveTriangleFilled_rgb_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveTriangleFilled_rgb_f");
            ok = false;
        }
        mtrPrimitiveTriangleFilled_rgba_f = (mtrPrimitiveTriangleFilled_rgba_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveTriangleFilled_rgba_f");
        if (mtrPrimitiveTriangleFilled_rgba_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveTriangleFilled_rgba_f");
            ok = false;
        }
        mtrPrimitiveTriangleFilled_c_f = (mtrPrimitiveTriangleFilled_c_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveTriangleFilled_c_f");
        if (mtrPrimitiveTriangleFilled_c_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveTriangleFilled_c_f");
            ok = false;
        }
        mtrPrimitiveTriangleFilled_ca_f = (mtrPrimitiveTriangleFilled_ca_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveTriangleFilled_ca_f");
        if (mtrPrimitiveTriangleFilled_ca_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveTriangleFilled_ca_f");
            ok = false;
        }
        /* Rectangle */
        mtrPrimitiveRectangle_rgb_f = (mtrPrimitiveRectangle_rgb_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRectangle_rgb_f");
        if (mtrPrimitiveRectangle_rgb_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRectangle_rgb_f");
            ok = false;
        }
        mtrPrimitiveRectangle_rgba_f = (mtrPrimitiveRectangle_rgba_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRectangle_rgba_f");
        if (mtrPrimitiveRectangle_rgba_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRectangle_rgba_f");
            ok = false;
        }
        mtrPrimitiveRectangle_c_f = (mtrPrimitiveRectangle_c_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRectangle_c_f");
        if (mtrPrimitiveRectangle_c_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRectangle_c_f");
            ok = false;
        }
        mtrPrimitiveRectangle_ca_f = (mtrPrimitiveRectangle_ca_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRectangle_ca_f");
        if (mtrPrimitiveRectangle_ca_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRectangle_ca_f");
            ok = false;
        }
        /* RectangleFilled */
        mtrPrimitiveRectangleFilled_rgb_f = (mtrPrimitiveRectangleFilled_rgb_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRectangleFilled_rgb_f");
        if (mtrPrimitiveRectangleFilled_rgb_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRectangleFilled_rgb_f");
            ok = false;
        }
        mtrPrimitiveRectangleFilled_rgba_f = (mtrPrimitiveRectangleFilled_rgba_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRectangleFilled_rgba_f");
        if (mtrPrimitiveRectangleFilled_rgba_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRectangleFilled_rgba_f");
            ok = false;
        }
        mtrPrimitiveRectangleFilled_c_f = (mtrPrimitiveRectangleFilled_c_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRectangleFilled_c_f");
        if (mtrPrimitiveRectangleFilled_c_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRectangleFilled_c_f");
            ok = false;
        }
        mtrPrimitiveRectangleFilled_ca_f = (mtrPrimitiveRectangleFilled_ca_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRectangleFilled_ca_f");
        if (mtrPrimitiveRectangleFilled_ca_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRectangleFilled_ca_f");
            ok = false;
        }
        /* RoundedRectangle */
        mtrPrimitiveRoundedRectangle_rgb_f = (mtrPrimitiveRoundedRectangle_rgb_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRoundedRectangle_rgb_f");
        if (mtrPrimitiveRoundedRectangle_rgb_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRoundedRectangle_rgb_f");
            ok = false;
        }
        mtrPrimitiveRoundedRectangle_rgba_f = (mtrPrimitiveRoundedRectangle_rgba_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRoundedRectangle_rgba_f");
        if (mtrPrimitiveRoundedRectangle_rgba_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRoundedRectangle_rgba_f");
            ok = false;
        }
        mtrPrimitiveRoundedRectangle_c_f = (mtrPrimitiveRoundedRectangle_c_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRoundedRectangle_c_f");
        if (mtrPrimitiveRoundedRectangle_c_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRoundedRectangle_c_f");
            ok = false;
        }
        mtrPrimitiveRoundedRectangle_ca_f = (mtrPrimitiveRoundedRectangle_ca_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRoundedRectangle_ca_f");
        if (mtrPrimitiveRoundedRectangle_ca_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRoundedRectangle_ca_f");
            ok = false;
        }
        /* RoundedRectangleFilled */
        mtrPrimitiveRoundedRectangleFilled_rgb_f = (mtrPrimitiveRoundedRectangleFilled_rgb_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRoundedRectangleFilled_rgb_f");
        if (mtrPrimitiveRoundedRectangleFilled_rgb_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRoundedRectangleFilled_rgb_f");
            ok = false;
        }
        mtrPrimitiveRoundedRectangleFilled_rgba_f = (mtrPrimitiveRoundedRectangleFilled_rgba_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRoundedRectangleFilled_rgba_f");
        if (mtrPrimitiveRoundedRectangleFilled_rgba_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRoundedRectangleFilled_rgba_f");
            ok = false;
        }
        mtrPrimitiveRoundedRectangleFilled_c_f = (mtrPrimitiveRoundedRectangleFilled_c_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRoundedRectangleFilled_c_f");
        if (mtrPrimitiveRoundedRectangleFilled_c_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRoundedRectangleFilled_c_f");
            ok = false;
        }
        mtrPrimitiveRoundedRectangleFilled_ca_f = (mtrPrimitiveRoundedRectangleFilled_ca_fFunc)mtrFindFunction("Primitive_SDL2_gpu",
          "mtrPrimitiveRoundedRectangleFilled_ca_f");
        if (mtrPrimitiveRoundedRectangleFilled_ca_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveRoundedRectangleFilled_ca_f");
            ok = false;
        }
        mtrPrimitiveLineBegin_f = (mtrPrimitiveLineBegin_fFunc)mtrFindFunction("Primitive_SDL2",
          "mtrPrimitiveLineBegin_f");
        if (mtrPrimitiveLineBegin_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveLineBegin_f");
            ok = false;
        }
        mtrPrimitiveLineTo_rgb_f = (mtrPrimitiveLineTo_rgb_fFunc)mtrFindFunction("Primitive_SDL2",
          "mtrPrimitiveLineTo_rgb_f");
        if (mtrPrimitiveLineTo_rgb_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveLineTo_rgb_f");
            ok = false;
        }
        mtrPrimitiveLineTo_rgba_f = (mtrPrimitiveLineTo_rgba_fFunc)mtrFindFunction("Primitive_SDL2",
          "mtrPrimitiveLineTo_rgba_f");
        if (mtrPrimitiveLineTo_rgba_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveLineTo_rgba_f");
            ok = false;
        }
        mtrPrimitiveLineTo_c_f = (mtrPrimitiveLineTo_c_fFunc)mtrFindFunction("Primitive_SDL2",
          "mtrPrimitiveLineTo_c_f");
        if (mtrPrimitiveLineTo_c_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveLineTo_c_f");
            ok = false;
        }
        mtrPrimitiveLineTo_ca_f = (mtrPrimitiveLineTo_ca_fFunc)mtrFindFunction("Primitive_SDL2",
          "mtrPrimitiveLineTo_ca_f");
        if (mtrPrimitiveLineTo_ca_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveLineTo_ca_f");
            ok = false;
        }
        mtrPrimitiveLineEnd = (mtrPrimitiveLineEndFunc)mtrFindFunction("Primitive_SDL2",
          "mtrPrimitiveLineEnd");
        if (mtrPrimitiveLineEnd == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrPrimitiveLineEnd");
            ok = false;
        }
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
}
