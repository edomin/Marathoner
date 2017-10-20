#include "primitive.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Primitive, FA_FUNCTIONS_COUNT)

MTR_EXPORT mtrReport* MTR_CALL MTR_CreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Primitive_SDL2_gfx";
    report->version = MTR_VERSION_PRIMITIVE_SDL2_GFX;
    report->subsystem = "primitive";
    report->prereqsCount = 1;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    if (report->prereqs == NULL)
    {
        free(report);
        return NULL;
    }
    report->prereqs[0] = "Screen_SDL2";
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

/*fa MTR_PrimitiveInit yes */
MTR_EXPORT bool MTR_CALL MTR_PrimitiveInit(void)
{
    MTR_LogWrite("Initializing primitive drawing subsystem", 0, MTR_LMT_INFO);

    MTR_LogWrite("Reporting SDL_gfx compile-time version:", 1, MTR_LMT_INFO);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, SDL2_GFXPRIMITIVES_MAJOR);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, SDL2_GFXPRIMITIVES_MINOR);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, SDL2_GFXPRIMITIVES_MICRO);

    MTR_GetScreen = (mtrGetScreenFunc)MTR_FindFunction("Screen_SDL2",
     "MTR_GetScreen");
    if (MTR_GetScreen == NULL)
    {
        MTR_Notify("Unable to load 'mtrGetScreen' function from 'Screen_SDL2' "
         "module", 1, MTR_LMT_FATAL);
        return false;
    }
    mtrScreen = MTR_GetScreen();
    mtrLineDrawing = false;

    SDL_GetRendererOutputSize(mtrScreen->renderer, &screenWidth, &screenHeight);

    MTR_LogWrite("Primitive drawing subsystem initialized", 0, MTR_LMT_INFO);

    mtrPrimitiveInited = true;
    return true;
}

/*fa MTR_PrimitiveFill_rgb yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveFill_rgb(uint8_t r, uint8_t g,
 uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    boxRGBA(mtrScreen->renderer, 0, 0, screenWidth, screenHeight, r, g, b,
     0xFF);
}

/*fa MTR_PrimitiveFill_rgba yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveFill_rgba(uint8_t r, uint8_t g,
 uint8_t b, uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    boxRGBA(mtrScreen->renderer, 0, 0, screenWidth, screenHeight, r, g, b, a);
}

/*fa MTR_PrimitiveFill_c yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveFill_c(uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToRgb(color, &r, &g, &b);
    boxRGBA(mtrScreen->renderer, 0, 0, screenWidth, screenHeight, r, g, b,
     0xFF);
}

/*fa MTR_PrimitiveFill_ca yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveFill_ca(uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToRgba(color, &r, &g, &b, &a);
    boxRGBA(mtrScreen->renderer, 0, 0, screenWidth, screenHeight, r, g, b, a);
}

/*fa MTR_PrimitivePixel_rgb_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitivePixel_rgb_f(float x, float y, uint8_t r,
 uint8_t g, uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    pixelRGBA(mtrScreen->renderer, x, y, r, g, b, 0xFF);
}

/*fa MTR_PrimitivePixel_rgba_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitivePixel_rgba_f(float x, float y, uint8_t r,
 uint8_t g, uint8_t b, uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    pixelRGBA(mtrScreen->renderer, x, y, r, g, b, a);
}

/*fa MTR_PrimitivePixel_c_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitivePixel_c_f(float x, float y, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToRgb(color, &r, &g, &b);
    pixelRGBA(mtrScreen->renderer, x, y, r, g, b, 0xFF);
}

/*fa MTR_PrimitivePixel_ca_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitivePixel_ca_f(float x, float y,
 uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToRgba(color, &r, &g, &b, &a);
    pixelRGBA(mtrScreen->renderer, x, y, r, g, b, a);
}

/*fa MTR_PrimitiveLine_rgb_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveLine_rgb_f(float x1, float y1, float x2,
 float y2, uint8_t r, uint8_t g, uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    lineRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, 0xFF);
}

/*fa MTR_PrimitiveLine_rgba_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveLine_rgba_f(float x1, float y1, float x2,
 float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    lineRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, a);
}

/*fa MTR_PrimitiveLine_c_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveLine_c_f(float x1, float y1, float x2,
 float y2, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToRgb(color, &r, &g, &b);
    lineRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, 0xFF);
}

/*fa MTR_PrimitiveLine_ca_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveLine_ca_f(float x1, float y1, float x2,
 float y2, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToRgba(color, &r, &g, &b, &a);
    lineRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, a);
}

/*fa MTR_PrimitiveArc_rgb_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveArc_rgb_f(float x, float y, float radius,
 float startAngle, float endAngle, uint8_t r, uint8_t g, uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    arcRGBA(mtrScreen->renderer, x, y, radius, -endAngle, -startAngle, r, g, b,
     0xFF);
}

/*fa MTR_PrimitiveArc_rgba_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveArc_rgba_f(float x, float y, float radius,
 float startAngle, float endAngle, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    arcRGBA(mtrScreen->renderer, x, y, radius, -endAngle, -startAngle, r, g, b,
     a);
}

/*fa MTR_PrimitiveArc_c_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveArc_c_f(float x, float y, float radius,
 float startAngle, float endAngle, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToRgb(color, &r, &g, &b);
    arcRGBA(mtrScreen->renderer, x, y, radius, -endAngle, -startAngle, r, g, b,
     0xFF);
}

/*fa MTR_PrimitiveArc_ca_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveArc_ca_f(float x, float y, float radius,
 float startAngle, float endAngle, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToRgba(color, &r, &g, &b, &a);
    arcRGBA(mtrScreen->renderer, x, y, radius, -endAngle, -startAngle, r, g, b,
     a);
}

/*fa MTR_PrimitiveSegmentFilled_rgb_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveSegmentFilled_rgb_f(float x, float y,
 float radius, float startAngle, float endAngle, uint8_t r, uint8_t g,
 uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    filledPieRGBA(mtrScreen->renderer, x, y, radius, -endAngle, -startAngle, r,
     g, b, 0xFF);
}

/*fa MTR_PrimitiveSegmentFilled_rgba_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveSegmentFilled_rgba_f(float x, float y,
 float radius, float startAngle, float endAngle, uint8_t r, uint8_t g,
 uint8_t b, uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    filledPieRGBA(mtrScreen->renderer, x, y, radius, -endAngle, -startAngle, r,
     g, b, a);
}

/*fa MTR_PrimitiveSegmentFilled_c_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveSegmentFilled_c_f(float x, float y,
 float radius, float startAngle, float endAngle, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToRgb(color, &r, &g, &b);
    filledPieRGBA(mtrScreen->renderer, x, y, radius, -endAngle, -startAngle, r,
     g, b, 0xFF);
}

/*fa MTR_PrimitiveSegmentFilled_ca_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveSegmentFilled_ca_f(float x, float y,
 float radius, float startAngle, float endAngle, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToRgba(color, &r, &g, &b, &a);
    filledPieRGBA(mtrScreen->renderer, x, y, radius, -endAngle, -startAngle, r,
     g, b, a);
}

/*fa MTR_PrimitiveCircle_rgb_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveCircle_rgb_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    circleRGBA(mtrScreen->renderer, x, y, radius, r, g, b, 0xFF);
}

/*fa MTR_PrimitiveCircle_rgba_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveCircle_rgba_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    circleRGBA(mtrScreen->renderer, x, y, radius, r, g, b, a);
}

/*fa MTR_PrimitiveCircle_c_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveCircle_c_f(float x, float y, float radius,
 uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToRgb(color, &r, &g, &b);
    circleRGBA(mtrScreen->renderer, x, y, radius, r, g, b, 0xFF);
}

/*fa MTR_PrimitiveCircle_ca_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveCircle_ca_f(float x, float y, float radius,
 uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToRgba(color, &r, &g, &b, &a);
    circleRGBA(mtrScreen->renderer, x, y, radius, r, g, b, a);
}

/*fa MTR_PrimitiveCircleFilled_rgb_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveCircleFilled_rgb_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    filledCircleRGBA(mtrScreen->renderer, x, y, radius, r, g, b, 0xFF);
}

/*fa MTR_PrimitiveCircleFilled_rgba_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveCircleFilled_rgba_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    filledCircleRGBA(mtrScreen->renderer, x, y, radius, r, g, b, a);
}

/*fa MTR_PrimitiveCircleFilled_c_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveCircleFilled_c_f(float x, float y,
 float radius, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToRgb(color, &r, &g, &b);
    filledCircleRGBA(mtrScreen->renderer, x, y, radius, r, g, b, 0xFF);
}

/*fa MTR_PrimitiveCircleFilled_ca_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveCircleFilled_ca_f(float x, float y,
 float radius, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToRgba(color, &r, &g, &b, &a);
    filledCircleRGBA(mtrScreen->renderer, x, y, radius, r, g, b, a);
}

/*fa MTR_PrimitiveEllipse_rgb_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveEllipse_rgb_f(float x, float y, float rx,
 float ry, float angle, uint8_t r, uint8_t g, uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    ellipseRGBA(mtrScreen->renderer, x, y, rx, ry, r, g, b, 0xFF);
}

/*fa MTR_PrimitiveEllipse_rgba_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveEllipse_rgba_f(float x, float y, float rx,
 float ry, float angle, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    ellipseRGBA(mtrScreen->renderer, x, y, rx, ry, r, g, b, a);
}

/*fa MTR_PrimitiveEllipse_c_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveEllipse_c_f(float x, float y, float rx,
 float ry, float angle, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToRgb(color, &r, &g, &b);
    ellipseRGBA(mtrScreen->renderer, x, y, rx, ry, r, g, b, 0xFF);
}

/*fa MTR_PrimitiveEllipse_ca_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveEllipse_ca_f(float x, float y, float rx,
 float ry, float angle, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToRgba(color, &r, &g, &b, &a);
    ellipseRGBA(mtrScreen->renderer, x, y, rx, ry, r, g, b, a);
}

/*fa MTR_PrimitiveEllipseFilled_rgb_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveEllipseFilled_rgb_f(float x, float y,
 float rx, float ry, float angle, uint8_t r, uint8_t g, uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    filledEllipseRGBA(mtrScreen->renderer, x, y, rx, ry, r, g, b, 0xFF);
}

/*fa MTR_PrimitiveEllipseFilled_rgba_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveEllipseFilled_rgba_f(float x, float y,
 float rx, float ry, float angle, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    filledEllipseRGBA(mtrScreen->renderer, x, y, rx, ry, r, g, b, a);
}

/*fa MTR_PrimitiveEllipseFilled_c_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveEllipseFilled_c_f(float x, float y,
 float rx, float ry, float angle, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToRgb(color, &r, &g, &b);
    filledEllipseRGBA(mtrScreen->renderer, x, y, rx, ry, r, g, b, 0xFF);
}

/*fa MTR_PrimitiveEllipseFilled_ca_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveEllipseFilled_ca_f(float x, float y,
 float rx, float ry, float angle, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToRgba(color, &r, &g, &b, &a);
    filledEllipseRGBA(mtrScreen->renderer, x, y, rx, ry, r, g, b, a);
}

/*fa MTR_PrimitiveRingSegment_rgb_f dummy */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRingSegment_rgb_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

/*fa MTR_PrimitiveRingSegment_rgba_f dummy */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRingSegment_rgba_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return;
}

/*fa MTR_PrimitiveRingSegment_c_f dummy */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRingSegment_c_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    return;
}

/*fa MTR_PrimitiveRingSegment_ca_f dummy */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRingSegment_ca_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    return;
}

/*fa MTR_PrimitiveRingSegmentFilled_rgb_f dummy */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRingSegmentFilled_rgb_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

/*fa MTR_PrimitiveRingSegmentFilled_rgba_f dummy */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRingSegmentFilled_rgba_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return;
}

/*fa MTR_PrimitiveRingSegmentFilled_c_f dummy */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRingSegmentFilled_c_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    return;
}

/*fa MTR_PrimitiveRingSegmentFilled_ca_f dummy */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRingSegmentFilled_ca_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    return;
}

/*fa MTR_PrimitiveTriangle_rgb_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveTriangle_rgb_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    trigonRGBA(mtrScreen->renderer, x1, y1, x2, y2, x3, y3, r, g, b, 0xFF);
}

/*fa MTR_PrimitiveTriangle_rgba_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveTriangle_rgba_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    trigonRGBA(mtrScreen->renderer, x1, y1, x2, y2, x3, y3, r, g, b, a);
}

/*fa MTR_PrimitiveTriangle_c_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveTriangle_c_f(float x1, float y1, float x2,
 float y2, float x3, float y3, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToRgb(color, &r, &g, &b);
    trigonRGBA(mtrScreen->renderer, x1, y1, x2, y2, x3, y3, r, g, b, 0xFF);
}

/*fa MTR_PrimitiveTriangle_ca_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveTriangle_ca_f(float x1, float y1, float x2,
 float y2, float x3, float y3, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToRgba(color, &r, &g, &b, &a);
    trigonRGBA(mtrScreen->renderer, x1, y1, x2, y2, x3, y3, r, g, b, a);
}

/*fa MTR_PrimitiveTriangleFilled_rgb_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveTriangleFilled_rgb_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    filledTrigonRGBA(mtrScreen->renderer, x1, y1, x2, y2, x3, y3, r, g, b,
     0xFF);
}

/*fa MTR_PrimitiveTriangleFilled_rgba_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveTriangleFilled_rgba_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    filledTrigonRGBA(mtrScreen->renderer, x1, y1, x2, y2, x3, y3, r, g, b, a);
}

/*fa MTR_PrimitiveTriangleFilled_c_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveTriangleFilled_c_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToRgb(color, &r, &g, &b);
    filledTrigonRGBA(mtrScreen->renderer, x1, y1, x2, y2, x3, y3, r, g, b,
     0xFF);
}

/*fa MTR_PrimitiveTriangleFilled_ca_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveTriangleFilled_ca_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToRgba(color, &r, &g, &b, &a);
    filledTrigonRGBA(mtrScreen->renderer, x1, y1, x2, y2, x3, y3, r, g, b, a);
}

/*fa MTR_PrimitiveRectangle_rgb_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRectangle_rgb_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    rectangleRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, 0xFF);
}

/*fa MTR_PrimitiveRectangle_rgba_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRectangle_rgba_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    rectangleRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, a);
}

/*fa MTR_PrimitiveRectangle_c_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRectangle_c_f(float x1, float y1, float x2,
 float y2, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToRgb(color, &r, &g, &b);
    rectangleRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, 0xFF);
}

/*fa MTR_PrimitiveRectangle_ca_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRectangle_ca_f(float x1, float y1,
 float x2, float y2, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToRgba(color, &r, &g, &b, &a);
    rectangleRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, a);
}

/*fa MTR_PrimitiveRectangleFilled_rgb_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRectangleFilled_rgb_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    boxRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, 0xFF);
}

/*fa MTR_PrimitiveRectangleFilled_rgba_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRectangleFilled_rgba_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    boxRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, a);
}

/*fa MTR_PrimitiveRectangleFilled_c_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRectangleFilled_c_f(float x1, float y1,
 float x2, float y2, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToRgb(color, &r, &g, &b);
    boxRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, 0xFF);
}

/*fa MTR_PrimitiveRectangleFilled_ca_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRectangleFilled_ca_f(float x1, float y1,
 float x2, float y2, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToRgba(color, &r, &g, &b, &a);
    boxRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, a);
}

/*fa MTR_PrimitiveRoundedRectangle_rgb_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRoundedRectangle_rgb_f(float x1, float y1,
 float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    roundedRectangleRGBA(mtrScreen->renderer, x1, y1, x2, y2, radius, r, g, b,
     0xFF);
}

/*fa MTR_PrimitiveRoundedRectangle_rgba_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRoundedRectangle_rgba_f(float x1, float y1,
 float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    roundedRectangleRGBA(mtrScreen->renderer, x1, y1, x2, y2, radius, r, g, b,
     a);
}

/*fa MTR_PrimitiveRoundedRectangle_c_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRoundedRectangle_c_f(float x1, float y1,
 float x2, float y2, float radius, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToRgb(color, &r, &g, &b);
    roundedRectangleRGBA(mtrScreen->renderer, x1, y1, x2, y2, radius, r, g, b,
     0xFF);
}

/*fa MTR_PrimitiveRoundedRectangle_ca_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRoundedRectangle_ca_f(float x1, float y1,
 float x2, float y2, float radius, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToRgba(color, &r, &g, &b, &a);
    roundedRectangleRGBA(mtrScreen->renderer, x1, y1, x2, y2, radius, r, g, b,
     a);
}

/*fa MTR_PrimitiveRoundedRectangleFilled_rgb_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRoundedRectangleFilled_rgb_f(float x1,
 float y1, float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    roundedBoxRGBA(mtrScreen->renderer, x1, y1, x2, y2, radius, r, g, b, 0xFF);
}

/*fa MTR_PrimitiveRoundedRectangleFilled_rgba_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRoundedRectangleFilled_rgba_f(float x1,
 float y1, float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    roundedBoxRGBA(mtrScreen->renderer, x1, y1, x2, y2, radius, r, g, b, a);
}

/*fa MTR_PrimitiveRoundedRectangleFilled_c_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRoundedRectangleFilled_c_f(float x1,
 float y1, float x2, float y2, float radius, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToRgb(color, &r, &g, &b);
    roundedBoxRGBA(mtrScreen->renderer, x1, y1, x2, y2, radius, r, g, b, 0xFF);
}

/*fa MTR_PrimitiveRoundedRectangleFilled_ca_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveRoundedRectangleFilled_ca_f(float x1,
 float y1, float x2, float y2, float radius, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToRgba(color, &r, &g, &b, &a);
    roundedBoxRGBA(mtrScreen->renderer, x1, y1, x2, y2, radius, r, g, b, a);
}

/*fa MTR_PrimitiveLineBegin_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveLineBegin_f(float x, float y)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    mtrLineDrawing = true;
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa MTR_PrimitiveLineTo_rgb_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveLineTo_rgb_f(float x, float y,
 uint8_t r, uint8_t g, uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    if (!mtrLineDrawing)
    {
        MTR_PrimitiveLineBegin_f(x, y);
        return;
    }

    lineRGBA(mtrScreen->renderer, mtrLinePointX_f, mtrLinePointY_f, x, y, r, g,
     b, 0xFF);
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa MTR_PrimitiveLineTo_rgba_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveLineTo_rgba_f(float x, float y,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    if (!mtrLineDrawing)
    {
        MTR_PrimitiveLineBegin_f(x, y);
        return;
    }

    lineRGBA(mtrScreen->renderer, mtrLinePointX_f, mtrLinePointY_f, x, y, r, g,
     b, a);
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa MTR_PrimitiveLineTo_c_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveLineTo_c_f(float x, float y,
 uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToRgb(color, &r, &g, &b);

    if (!mtrLineDrawing)
    {
        MTR_PrimitiveLineBegin_f(x, y);
        return;
    }

    lineRGBA(mtrScreen->renderer, mtrLinePointX_f, mtrLinePointY_f, x, y, r, g,
     b, 0xFF);
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa MTR_PrimitiveLineTo_ca_f yes */
MTR_EXPORT void MTR_CALL MTR_PrimitiveLineTo_ca_f(float x, float y,
 uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToRgba(color, &r, &g, &b, &a);

    if (!mtrLineDrawing)
    {
        MTR_PrimitiveLineBegin_f(x, y);
        return;
    }

    lineRGBA(mtrScreen->renderer, mtrLinePointX_f, mtrLinePointY_f, x, y, r, g,
     b, a);
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa MTR_PrimitiveLineEnd yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLineEnd(void)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    mtrLineDrawing = false;
}
