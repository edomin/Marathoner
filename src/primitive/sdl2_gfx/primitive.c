#include "primitive.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Primitive, FA_FUNCTIONS_COUNT)

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
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

/*fa mtrPrimitiveInit yes */
MTR_EXPORT bool MTR_CALL mtrPrimitiveInit(void)
{
    mtrLogWrite("Initializing primitive drawing subsystem", 0, MTR_LMT_INFO);

    mtrLogWrite("Reporting SDL_gfx compile-time version:", 1, MTR_LMT_INFO);
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, SDL2_GFXPRIMITIVES_MAJOR);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, SDL2_GFXPRIMITIVES_MINOR);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, SDL2_GFXPRIMITIVES_MICRO);

    mtrGetScreen = (mtrGetScreenFunc)mtrFindFunction("Screen_SDL2",
     "mtrGetScreen");
    if (mtrGetScreen == NULL)
    {
        mtrNotify("Unable to load 'mtrGetScreen' function from 'Screen_SDL2' "
         "module", 1, MTR_LMT_FATAL);
        return false;
    }
    mtrScreen = mtrGetScreen();
    mtrLineDrawing = false;

    SDL_GetRendererOutputSize(mtrScreen->renderer, &screenWidth, &screenHeight);

    mtrLogWrite("Primitive drawing subsystem initialized", 0, MTR_LMT_INFO);
    return true;
}

/*fa mtrPrimitiveFill_rgb yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveFill_rgb(uint8_t r, uint8_t g,
 uint8_t b)
{
    boxRGBA(mtrScreen->renderer, 0, 0, screenWidth, screenHeight, r, g, b,
     0xFF);
}

/*fa mtrPrimitiveFill_rgba yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveFill_rgba(uint8_t r, uint8_t g,
 uint8_t b, uint8_t a)
{
    boxRGBA(mtrScreen->renderer, 0, 0, screenWidth, screenHeight, r, g, b, a);
}

/*fa mtrPrimitiveFill_c yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveFill_c(uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));

    boxRGBA(mtrScreen->renderer, 0, 0, screenWidth, screenHeight, r, g, b,
     0xFF);
}

/*fa mtrPrimitiveFill_ca yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveFill_ca(uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    r = (uint8_t)(color >> 24);
    g = (uint8_t)((color >> 16) - ((uint32_t)r << 8));
    b = (uint8_t)((color >> 8) - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    a = (uint8_t)(color  - ((uint32_t)r << 24) - ((uint32_t)g << 16) -
     ((uint32_t)b << 8));

    boxRGBA(mtrScreen->renderer, 0, 0, screenWidth, screenHeight, r, g, b, a);
}

/*fa mtrPrimitivePixel_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitivePixel_rgb_f(float x, float y, uint8_t r,
 uint8_t g, uint8_t b)
{
    pixelRGBA(mtrScreen->renderer, x, y, r, g, b, 0xFF);
}

/*fa mtrPrimitivePixel_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitivePixel_rgba_f(float x, float y, uint8_t r,
 uint8_t g, uint8_t b, uint8_t a)
{
    pixelRGBA(mtrScreen->renderer, x, y, r, g, b, a);
}

/*fa mtrPrimitivePixel_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitivePixel_c_f(float x, float y, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));

    pixelRGBA(mtrScreen->renderer, x, y, r, g, b, 0xFF);
}

/*fa mtrPrimitivePixel_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitivePixel_ca_f(float x, float y,
 uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    r = (uint8_t)(color >> 24);
    g = (uint8_t)((color >> 16) - ((uint32_t)r << 8));
    b = (uint8_t)((color >> 8) - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    a = (uint8_t)(color  - ((uint32_t)r << 24) - ((uint32_t)g << 16) -
     ((uint32_t)b << 8));

    pixelRGBA(mtrScreen->renderer, x, y, r, g, b, a);
}

/*fa mtrPrimitiveLine_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLine_rgb_f(float x1, float y1, float x2,
 float y2, uint8_t r, uint8_t g, uint8_t b)
{
    lineRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, 0xFF);
}

/*fa mtrPrimitiveLine_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLine_rgba_f(float x1, float y1, float x2,
 float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    lineRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, a);
}

/*fa mtrPrimitiveLine_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLine_c_f(float x1, float y1, float x2,
 float y2, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));

    lineRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, 0xFF);
}

/*fa mtrPrimitiveLine_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLine_ca_f(float x1, float y1, float x2,
 float y2, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    r = (uint8_t)(color >> 24);
    g = (uint8_t)((color >> 16) - ((uint32_t)r << 8));
    b = (uint8_t)((color >> 8) - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    a = (uint8_t)(color  - ((uint32_t)r << 24) - ((uint32_t)g << 16) -
     ((uint32_t)b << 8));

    lineRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, a);
}

/*fa mtrPrimitiveArc_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveArc_rgb_f(float x, float y, float radius,
 float startAngle, float endAngle, uint8_t r, uint8_t g, uint8_t b)
{
    arcRGBA(mtrScreen->renderer, x, y, radius, -endAngle, -startAngle, r, g, b,
     0xFF);
}

/*fa mtrPrimitiveArc_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveArc_rgba_f(float x, float y, float radius,
 float startAngle, float endAngle, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    arcRGBA(mtrScreen->renderer, x, y, radius, -endAngle, -startAngle, r, g, b,
     a);
}

/*fa mtrPrimitiveArc_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveArc_c_f(float x, float y, float radius,
 float startAngle, float endAngle, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));

    arcRGBA(mtrScreen->renderer, x, y, radius, -endAngle, -startAngle, r, g, b,
     0xFF);
}

/*fa mtrPrimitiveArc_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveArc_ca_f(float x, float y, float radius,
 float startAngle, float endAngle, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    r = (uint8_t)(color >> 24);
    g = (uint8_t)((color >> 16) - ((uint32_t)r << 8));
    b = (uint8_t)((color >> 8) - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    a = (uint8_t)(color  - ((uint32_t)r << 24) - ((uint32_t)g << 16) -
     ((uint32_t)b << 8));

    arcRGBA(mtrScreen->renderer, x, y, radius, -endAngle, -startAngle, r, g, b,
     a);
}

/*fa mtrPrimitiveSegmentFilled_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveSegmentFilled_rgb_f(float x, float y,
 float radius, float startAngle, float endAngle, uint8_t r, uint8_t g,
 uint8_t b)
{
    filledPieRGBA(mtrScreen->renderer, x, y, radius, -endAngle, -startAngle, r,
     g, b, 0xFF);
}

/*fa mtrPrimitiveSegmentFilled_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveSegmentFilled_rgba_f(float x, float y,
 float radius, float startAngle, float endAngle, uint8_t r, uint8_t g,
 uint8_t b, uint8_t a)
{
    filledPieRGBA(mtrScreen->renderer, x, y, radius, -endAngle, -startAngle, r,
     g, b, a);
}

/*fa mtrPrimitiveSegmentFilled_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveSegmentFilled_c_f(float x, float y,
 float radius, float startAngle, float endAngle, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));

    filledPieRGBA(mtrScreen->renderer, x, y, radius, -endAngle, -startAngle, r,
     g, b, 0xFF);
}

/*fa mtrPrimitiveSegmentFilled_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveSegmentFilled_ca_f(float x, float y,
 float radius, float startAngle, float endAngle, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    r = (uint8_t)(color >> 24);
    g = (uint8_t)((color >> 16) - ((uint32_t)r << 8));
    b = (uint8_t)((color >> 8) - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    a = (uint8_t)(color  - ((uint32_t)r << 24) - ((uint32_t)g << 16) -
     ((uint32_t)b << 8));

    filledPieRGBA(mtrScreen->renderer, x, y, radius, -endAngle, -startAngle, r,
     g, b, a);
}

/*fa mtrPrimitiveCircle_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircle_rgb_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b)
{
    circleRGBA(mtrScreen->renderer, x, y, radius, r, g, b, 0xFF);
}

/*fa mtrPrimitiveCircle_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircle_rgba_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    circleRGBA(mtrScreen->renderer, x, y, radius, r, g, b, a);
}

/*fa mtrPrimitiveCircle_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircle_c_f(float x, float y, float radius,
 uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));

    circleRGBA(mtrScreen->renderer, x, y, radius, r, g, b, 0xFF);
}

/*fa mtrPrimitiveCircle_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircle_ca_f(float x, float y, float radius,
 uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    r = (uint8_t)(color >> 24);
    g = (uint8_t)((color >> 16) - ((uint32_t)r << 8));
    b = (uint8_t)((color >> 8) - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    a = (uint8_t)(color  - ((uint32_t)r << 24) - ((uint32_t)g << 16) -
     ((uint32_t)b << 8));

    circleRGBA(mtrScreen->renderer, x, y, radius, r, g, b, a);
}

/*fa mtrPrimitiveCircleFilled_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircleFilled_rgb_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b)
{
    filledCircleRGBA(mtrScreen->renderer, x, y, radius, r, g, b, 0xFF);
}

/*fa mtrPrimitiveCircleFilled_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircleFilled_rgba_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    filledCircleRGBA(mtrScreen->renderer, x, y, radius, r, g, b, a);
}

/*fa mtrPrimitiveCircleFilled_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircleFilled_c_f(float x, float y,
 float radius, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));

    filledCircleRGBA(mtrScreen->renderer, x, y, radius, r, g, b, 0xFF);
}

/*fa mtrPrimitiveCircleFilled_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircleFilled_ca_f(float x, float y,
 float radius, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    r = (uint8_t)(color >> 24);
    g = (uint8_t)((color >> 16) - ((uint32_t)r << 8));
    b = (uint8_t)((color >> 8) - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    a = (uint8_t)(color  - ((uint32_t)r << 24) - ((uint32_t)g << 16) -
     ((uint32_t)b << 8));

    filledCircleRGBA(mtrScreen->renderer, x, y, radius, r, g, b, a);
}

/*fa mtrPrimitiveEllipse_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipse_rgb_f(float x, float y, float rx,
 float ry, float angle, uint8_t r, uint8_t g, uint8_t b)
{
    ellipseRGBA(mtrScreen->renderer, x, y, rx, ry, r, g, b, 0xFF);
}

/*fa mtrPrimitiveEllipse_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipse_rgba_f(float x, float y, float rx,
 float ry, float angle, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    ellipseRGBA(mtrScreen->renderer, x, y, rx, ry, r, g, b, a);
}

/*fa mtrPrimitiveEllipse_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipse_c_f(float x, float y, float rx,
 float ry, float angle, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));

    ellipseRGBA(mtrScreen->renderer, x, y, rx, ry, r, g, b, 0xFF);
}

/*fa mtrPrimitiveEllipse_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipse_ca_f(float x, float y, float rx,
 float ry, float angle, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    r = (uint8_t)(color >> 24);
    g = (uint8_t)((color >> 16) - ((uint32_t)r << 8));
    b = (uint8_t)((color >> 8) - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    a = (uint8_t)(color  - ((uint32_t)r << 24) - ((uint32_t)g << 16) -
     ((uint32_t)b << 8));

    ellipseRGBA(mtrScreen->renderer, x, y, rx, ry, r, g, b, a);
}

/*fa mtrPrimitiveEllipseFilled_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipseFilled_rgb_f(float x, float y,
 float rx, float ry, float angle, uint8_t r, uint8_t g, uint8_t b)
{
    filledEllipseRGBA(mtrScreen->renderer, x, y, rx, ry, r, g, b, 0xFF);
}

/*fa mtrPrimitiveEllipseFilled_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipseFilled_rgba_f(float x, float y,
 float rx, float ry, float angle, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    filledEllipseRGBA(mtrScreen->renderer, x, y, rx, ry, r, g, b, a);
}

/*fa mtrPrimitiveEllipseFilled_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipseFilled_c_f(float x, float y,
 float rx, float ry, float angle, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));

    filledEllipseRGBA(mtrScreen->renderer, x, y, rx, ry, r, g, b, 0xFF);
}

/*fa mtrPrimitiveEllipseFilled_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipseFilled_ca_f(float x, float y,
 float rx, float ry, float angle, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    r = (uint8_t)(color >> 24);
    g = (uint8_t)((color >> 16) - ((uint32_t)r << 8));
    b = (uint8_t)((color >> 8) - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    a = (uint8_t)(color  - ((uint32_t)r << 24) - ((uint32_t)g << 16) -
     ((uint32_t)b << 8));

    filledEllipseRGBA(mtrScreen->renderer, x, y, rx, ry, r, g, b, a);
}

/*fa mtrPrimitiveRingSegment_rgb_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegment_rgb_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

/*fa mtrPrimitiveRingSegment_rgba_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegment_rgba_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return;
}

/*fa mtrPrimitiveRingSegment_c_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegment_c_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    return;
}

/*fa mtrPrimitiveRingSegment_ca_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegment_ca_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    return;
}

/*fa mtrPrimitiveRingSegmentFilled_rgb_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegmentFilled_rgb_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

/*fa mtrPrimitiveRingSegmentFilled_rgba_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegmentFilled_rgba_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return;
}

/*fa mtrPrimitiveRingSegmentFilled_c_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegmentFilled_c_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    return;
}

/*fa mtrPrimitiveRingSegmentFilled_ca_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegmentFilled_ca_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    return;
}

/*fa mtrPrimitiveTriangle_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveTriangle_rgb_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b)
{
    trigonRGBA(mtrScreen->renderer, x1, y1, x2, y2, x3, y3, r, g, b, 0xFF);
}

/*fa mtrPrimitiveTriangle_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveTriangle_rgba_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    trigonRGBA(mtrScreen->renderer, x1, y1, x2, y2, x3, y3, r, g, b, a);
}

/*fa mtrPrimitiveTriangle_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveTriangle_c_f(float x1, float y1, float x2,
 float y2, float x3, float y3, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));

    trigonRGBA(mtrScreen->renderer, x1, y1, x2, y2, x3, y3, r, g, b, 0xFF);
}

/*fa mtrPrimitiveTriangle_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveTriangle_ca_f(float x1, float y1, float x2,
 float y2, float x3, float y3, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    r = (uint8_t)(color >> 24);
    g = (uint8_t)((color >> 16) - ((uint32_t)r << 8));
    b = (uint8_t)((color >> 8) - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    a = (uint8_t)(color  - ((uint32_t)r << 24) - ((uint32_t)g << 16) -
     ((uint32_t)b << 8));

    trigonRGBA(mtrScreen->renderer, x1, y1, x2, y2, x3, y3, r, g, b, a);
}

/*fa mtrPrimitiveTriangleFilled_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveTriangleFilled_rgb_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b)
{
    filledTrigonRGBA(mtrScreen->renderer, x1, y1, x2, y2, x3, y3, r, g, b,
     0xFF);
}

/*fa mtrPrimitiveTriangleFilled_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveTriangleFilled_rgba_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    filledTrigonRGBA(mtrScreen->renderer, x1, y1, x2, y2, x3, y3, r, g, b, a);
}

/*fa mtrPrimitiveTriangleFilled_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveTriangleFilled_c_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));

    filledTrigonRGBA(mtrScreen->renderer, x1, y1, x2, y2, x3, y3, r, g, b,
     0xFF);
}

/*fa mtrPrimitiveTriangleFilled_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveTriangleFilled_ca_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    r = (uint8_t)(color >> 24);
    g = (uint8_t)((color >> 16) - ((uint32_t)r << 8));
    b = (uint8_t)((color >> 8) - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    a = (uint8_t)(color  - ((uint32_t)r << 24) - ((uint32_t)g << 16) -
     ((uint32_t)b << 8));

    filledTrigonRGBA(mtrScreen->renderer, x1, y1, x2, y2, x3, y3, r, g, b, a);
}

/*fa mtrPrimitiveRectangle_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRectangle_rgb_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b)
{
    rectangleRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, 0xFF);
}

/*fa mtrPrimitiveRectangle_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRectangle_rgba_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    rectangleRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, a);
}

/*fa mtrPrimitiveRectangle_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRectangle_c_f(float x1, float y1, float x2,
 float y2, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));

    rectangleRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, 0xFF);
}

/*fa mtrPrimitiveRectangle_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRectangle_ca_f(float x1, float y1,
 float x2, float y2, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    r = (uint8_t)(color >> 24);
    g = (uint8_t)((color >> 16) - ((uint32_t)r << 8));
    b = (uint8_t)((color >> 8) - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    a = (uint8_t)(color  - ((uint32_t)r << 24) - ((uint32_t)g << 16) -
     ((uint32_t)b << 8));

    rectangleRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, a);
}

/*fa mtrPrimitiveRectangleFilled_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRectangleFilled_rgb_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b)
{
    boxRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, 0xFF);
}

/*fa mtrPrimitiveRectangleFilled_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRectangleFilled_rgba_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    boxRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, a);
}

/*fa mtrPrimitiveRectangleFilled_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRectangleFilled_c_f(float x1, float y1,
 float x2, float y2, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));

    boxRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, 0xFF);
}

/*fa mtrPrimitiveRectangleFilled_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRectangleFilled_ca_f(float x1, float y1,
 float x2, float y2, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    r = (uint8_t)(color >> 24);
    g = (uint8_t)((color >> 16) - ((uint32_t)r << 8));
    b = (uint8_t)((color >> 8) - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    a = (uint8_t)(color  - ((uint32_t)r << 24) - ((uint32_t)g << 16) -
     ((uint32_t)b << 8));

    boxRGBA(mtrScreen->renderer, x1, y1, x2, y2, r, g, b, a);
}

/*fa mtrPrimitiveRoundedRectangle_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangle_rgb_f(float x1, float y1,
 float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b)
{
    roundedRectangleRGBA(mtrScreen->renderer, x1, y1, x2, y2, radius, r, g, b,
     0xFF);
}

/*fa mtrPrimitiveRoundedRectangle_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangle_rgba_f(float x1, float y1,
 float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    roundedRectangleRGBA(mtrScreen->renderer, x1, y1, x2, y2, radius, r, g, b,
     a);
}

/*fa mtrPrimitiveRoundedRectangle_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangle_c_f(float x1, float y1,
 float x2, float y2, float radius, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));

    roundedRectangleRGBA(mtrScreen->renderer, x1, y1, x2, y2, radius, r, g, b,
     0xFF);
}

/*fa mtrPrimitiveRoundedRectangle_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangle_ca_f(float x1, float y1,
 float x2, float y2, float radius, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    r = (uint8_t)(color >> 24);
    g = (uint8_t)((color >> 16) - ((uint32_t)r << 8));
    b = (uint8_t)((color >> 8) - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    a = (uint8_t)(color  - ((uint32_t)r << 24) - ((uint32_t)g << 16) -
     ((uint32_t)b << 8));

    roundedRectangleRGBA(mtrScreen->renderer, x1, y1, x2, y2, radius, r, g, b,
     a);
}

/*fa mtrPrimitiveRoundedRectangleFilled_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangleFilled_rgb_f(float x1,
 float y1, float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b)
{
    roundedBoxRGBA(mtrScreen->renderer, x1, y1, x2, y2, radius, r, g, b, 0xFF);
}

/*fa mtrPrimitiveRoundedRectangleFilled_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangleFilled_rgba_f(float x1,
 float y1, float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    roundedBoxRGBA(mtrScreen->renderer, x1, y1, x2, y2, radius, r, g, b, a);
}

/*fa mtrPrimitiveRoundedRectangleFilled_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangleFilled_c_f(float x1,
 float y1, float x2, float y2, float radius, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));

    roundedBoxRGBA(mtrScreen->renderer, x1, y1, x2, y2, radius, r, g, b, 0xFF);
}

/*fa mtrPrimitiveRoundedRectangleFilled_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangleFilled_ca_f(float x1,
 float y1, float x2, float y2, float radius, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    r = (uint8_t)(color >> 24);
    g = (uint8_t)((color >> 16) - ((uint32_t)r << 8));
    b = (uint8_t)((color >> 8) - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    a = (uint8_t)(color  - ((uint32_t)r << 24) - ((uint32_t)g << 16) -
     ((uint32_t)b << 8));

    roundedBoxRGBA(mtrScreen->renderer, x1, y1, x2, y2, radius, r, g, b, a);
}

/*fa mtrPrimitiveLineBegin_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLineBegin_f(float x, float y)
{
    mtrLineDrawing = true;
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa mtrPrimitiveLineTo_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLineTo_rgb_f(float x, float y,
 uint8_t r, uint8_t g, uint8_t b)
{
    if (!mtrLineDrawing)
    {
        mtrPrimitiveLineBegin_f(x, y);
        return;
    }

    lineRGBA(mtrScreen->renderer, mtrLinePointX_f, mtrLinePointY_f, x, y, r, g,
     b, 0xFF);
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa mtrPrimitiveLineTo_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLineTo_rgba_f(float x, float y,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    if (!mtrLineDrawing)
    {
        mtrPrimitiveLineBegin_f(x, y);
        return;
    }

    lineRGBA(mtrScreen->renderer, mtrLinePointX_f, mtrLinePointY_f, x, y, r, g,
     b, a);
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa mtrPrimitiveLineTo_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLineTo_c_f(float x, float y,
 uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));

    if (!mtrLineDrawing)
    {
        mtrPrimitiveLineBegin_f(x, y);
        return;
    }

    lineRGBA(mtrScreen->renderer, mtrLinePointX_f, mtrLinePointY_f, x, y, r, g,
     b, 0xFF);
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa mtrPrimitiveLineTo_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLineTo_ca_f(float x, float y,
 uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    r = (uint8_t)(color >> 24);
    g = (uint8_t)((color >> 16) - ((uint32_t)r << 8));
    b = (uint8_t)((color >> 8) - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    a = (uint8_t)(color  - ((uint32_t)r << 24) - ((uint32_t)g << 16) -
     ((uint32_t)b << 8));

    if (!mtrLineDrawing)
    {
        mtrPrimitiveLineBegin_f(x, y);
        return;
    }

    lineRGBA(mtrScreen->renderer, mtrLinePointX_f, mtrLinePointY_f, x, y, r, g,
     b, a);
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa mtrPrimitiveLineEnd yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLineEnd(void)
{
    mtrLineDrawing = false;
}
