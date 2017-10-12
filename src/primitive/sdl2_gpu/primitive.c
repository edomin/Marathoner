#include "primitive.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Primitive, FA_FUNCTIONS_COUNT)

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Primitive_SDL2_gpu";
    report->version = MTR_VERSION_PRIMITIVE_SDL2_GPU;
    report->subsystem = "primitive";
    report->prereqsCount = 1;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    if (report->prereqs == NULL)
    {
        free(report);
        return NULL;
    }
    report->prereqs[0] = "Screen_SDL2_gpu";
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

/*fa mtrPrimitiveInit yes */
MTR_EXPORT bool MTR_CALL mtrPrimitiveInit(void)
{
    SDL_version linked;

    mtrLogWrite("Initializing primitive drawing subsystem", 0, MTR_LMT_INFO);

    mtrLogWrite("Reporting sdl_gpu compile-time version:", 1, MTR_LMT_INFO);
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, SDL_GPU_VERSION_MAJOR);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, SDL_GPU_VERSION_MINOR);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, SDL_GPU_VERSION_PATCH);
    mtrLogWrite("Reporting sdl_gpu linked version:", 1, MTR_LMT_INFO);
    linked = GPU_GetLinkedVersion();
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, linked.major);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, linked.minor);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, linked.patch);

    mtrGetScreen = (mtrGetScreenFunc)mtrFindFunction("Screen_SDL2_gpu",
     "mtrGetScreen");
    if (mtrGetScreen == NULL)
    {
        mtrNotify("Unable to load 'mtrGetScreen' function from 'Screen_SDL2_gpu' module",
         1, MTR_LMT_FATAL);
        return false;
    }
    mtrScreen = mtrGetScreen();
    mtrLineDrawing = false;

    mtrLogWrite("Primitive drawing subsystem initialized", 0, MTR_LMT_INFO);

    mtrPrimitiveInited = true;
    return true;
}

/*fa mtrPrimitiveFill_rgb yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveFill_rgb(uint8_t r, uint8_t g, uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_ClearRGB(mtrScreen->target, r, g, b);
}

/*fa mtrPrimitiveFill_rgba yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveFill_rgba(uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_ClearRGBA(mtrScreen->target, r, g, b, a);
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
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_ClearRGB(mtrScreen->target, r, g, b);
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
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_ClearRGBA(mtrScreen->target, r, g, b, a);
}

/*fa mtrPrimitivePixel_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitivePixel_rgb_f(float x, float y, uint8_t r,
 uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_RGB_TO_SDL_COLOR(sdl_color, r, g, b);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Pixel(mtrScreen->target, x, y, sdl_color);
}

/*fa mtrPrimitivePixel_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitivePixel_rgba_f(float x, float y, uint8_t r,
 uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_RGBA_TO_SDL_COLOR(sdl_color, r, g, b, a);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Pixel(mtrScreen->target, x, y, sdl_color);
}

/*fa mtrPrimitivePixel_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitivePixel_c_f(float x, float y, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR24_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Pixel(mtrScreen->target, x, y, sdl_color);
}

/*fa mtrPrimitivePixel_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitivePixel_ca_f(float x, float y,
 uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR32_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Pixel(mtrScreen->target, x, y, sdl_color);
}

/*fa mtrPrimitiveLine_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLine_rgb_f(float x1, float y1, float x2,
 float y2, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_RGB_TO_SDL_COLOR(sdl_color, r, g, b);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Line(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa mtrPrimitiveLine_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLine_rgba_f(float x1, float y1, float x2,
 float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_RGBA_TO_SDL_COLOR(sdl_color, r, g, b, a);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Line(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa mtrPrimitiveLine_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLine_c_f(float x1, float y1, float x2,
 float y2, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR24_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Line(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa mtrPrimitiveLine_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLine_ca_f(float x1, float y1, float x2,
 float y2, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR32_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Line(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa mtrPrimitiveArc_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveArc_rgb_f(float x, float y, float radius,
 float startAngle, float endAngle, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_RGB_TO_SDL_COLOR(sdl_color, r, g, b);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Arc(mtrScreen->target, x, y, radius, -endAngle, -startAngle, sdl_color);
}

/*fa mtrPrimitiveArc_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveArc_rgba_f(float x, float y, float radius,
 float startAngle, float endAngle, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_RGBA_TO_SDL_COLOR(sdl_color, r, g, b, a);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Arc(mtrScreen->target, x, y, radius, -endAngle, -startAngle, sdl_color);
}

/*fa mtrPrimitiveArc_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveArc_c_f(float x, float y, float radius,
 float startAngle, float endAngle, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR24_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Arc(mtrScreen->target, x, y, radius, -endAngle, -startAngle, sdl_color);
}

/*fa mtrPrimitiveArc_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveArc_ca_f(float x, float y, float radius,
 float startAngle, float endAngle, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR32_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Arc(mtrScreen->target, x, y, radius, -endAngle, -startAngle, sdl_color);
}

/*fa mtrPrimitiveSegmentFilled_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveSegmentFilled_rgb_f(float x, float y,
 float radius, float startAngle, float endAngle, uint8_t r, uint8_t g,
 uint8_t b)
{
    SDL_Color sdl_color;
    MTR_RGB_TO_SDL_COLOR(sdl_color, r, g, b);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_ArcFilled(mtrScreen->target, x, y, radius, -endAngle, -startAngle,
     sdl_color);
}

/*fa mtrPrimitiveSegmentFilled_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveSegmentFilled_rgba_f(float x, float y,
 float radius, float startAngle, float endAngle, uint8_t r, uint8_t g,
 uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_RGBA_TO_SDL_COLOR(sdl_color, r, g, b, a);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_ArcFilled(mtrScreen->target, x, y, radius, -endAngle, -startAngle,
     sdl_color);
}

/*fa mtrPrimitiveSegmentFilled_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveSegmentFilled_c_f(float x, float y,
 float radius, float startAngle, float endAngle, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR24_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_ArcFilled(mtrScreen->target, x, y, radius, -endAngle, -startAngle,
     sdl_color);
}

/*fa mtrPrimitiveSegmentFilled_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveSegmentFilled_ca_f(float x, float y,
 float radius, float startAngle, float endAngle, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR32_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_ArcFilled(mtrScreen->target, x, y, radius, -endAngle, -startAngle,
     sdl_color);
}

/*fa mtrPrimitiveCircle_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircle_rgb_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_RGB_TO_SDL_COLOR(sdl_color, r, g, b);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Circle(mtrScreen->target, x, y, radius, sdl_color);
}

/*fa mtrPrimitiveCircle_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircle_rgba_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_RGBA_TO_SDL_COLOR(sdl_color, r, g, b, a);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Circle(mtrScreen->target, x, y, radius, sdl_color);
}

/*fa mtrPrimitiveCircle_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircle_c_f(float x, float y, float radius,
 uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR24_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Circle(mtrScreen->target, x, y, radius, sdl_color);
}

/*fa mtrPrimitiveCircle_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircle_ca_f(float x, float y, float radius,
 uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR32_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Circle(mtrScreen->target, x, y, radius, sdl_color);
}

/*fa mtrPrimitiveCircleFilled_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircleFilled_rgb_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_RGB_TO_SDL_COLOR(sdl_color, r, g, b);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_CircleFilled(mtrScreen->target, x, y, radius, sdl_color);
}

/*fa mtrPrimitiveCircleFilled_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircleFilled_rgba_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_RGBA_TO_SDL_COLOR(sdl_color, r, g, b, a);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_CircleFilled(mtrScreen->target, x, y, radius, sdl_color);
}

/*fa mtrPrimitiveCircleFilled_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircleFilled_c_f(float x, float y,
 float radius, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR24_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_CircleFilled(mtrScreen->target, x, y, radius, sdl_color);
}

/*fa mtrPrimitiveCircleFilled_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircleFilled_ca_f(float x, float y,
 float radius, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR32_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_CircleFilled(mtrScreen->target, x, y, radius, sdl_color);
}

/*fa mtrPrimitiveEllipse_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipse_rgb_f(float x, float y, float rx,
 float ry, float angle, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_RGB_TO_SDL_COLOR(sdl_color, r, g, b);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Ellipse(mtrScreen->target, x, y, rx, ry, -angle, sdl_color);
}

/*fa mtrPrimitiveEllipse_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipse_rgba_f(float x, float y, float rx,
 float ry, float angle, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_RGBA_TO_SDL_COLOR(sdl_color, r, g, b, a);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Ellipse(mtrScreen->target, x, y, rx, ry, -angle, sdl_color);
}

/*fa mtrPrimitiveEllipse_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipse_c_f(float x, float y, float rx,
 float ry, float angle, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR24_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Ellipse(mtrScreen->target, x, y, rx, ry, -angle, sdl_color);
}

/*fa mtrPrimitiveEllipse_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipse_ca_f(float x, float y, float rx,
 float ry, float angle, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR32_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Ellipse(mtrScreen->target, x, y, rx, ry, -angle, sdl_color);
}

/*fa mtrPrimitiveEllipseFilled_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipseFilled_rgb_f(float x, float y,
 float rx, float ry, float angle, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_RGB_TO_SDL_COLOR(sdl_color, r, g, b);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_EllipseFilled(mtrScreen->target, x, y, rx, ry, -angle, sdl_color);
}

/*fa mtrPrimitiveEllipseFilled_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipseFilled_rgba_f(float x, float y,
 float rx, float ry, float angle, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_RGBA_TO_SDL_COLOR(sdl_color, r, g, b, a);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_EllipseFilled(mtrScreen->target, x, y, rx, ry, -angle, sdl_color);
}

/*fa mtrPrimitiveEllipseFilled_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipseFilled_c_f(float x, float y,
 float rx, float ry, float angle, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR24_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_EllipseFilled(mtrScreen->target, x, y, rx, ry, -angle, sdl_color);
}

/*fa mtrPrimitiveEllipseFilled_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipseFilled_ca_f(float x, float y,
 float rx, float ry, float angle, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR32_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_EllipseFilled(mtrScreen->target, x, y, rx, ry, -angle, sdl_color);
}

/*fa mtrPrimitiveRingSegment_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegment_rgb_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_RGB_TO_SDL_COLOR(sdl_color, r, g, b);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Sector(mtrScreen->target, x, y, innerRadius, outerRadius, -endAngle,
     -startAngle, sdl_color);
}

/*fa mtrPrimitiveRingSegment_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegment_rgba_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_RGBA_TO_SDL_COLOR(sdl_color, r, g, b, a);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Sector(mtrScreen->target, x, y, innerRadius, outerRadius, -endAngle,
     -startAngle, sdl_color);
}

/*fa mtrPrimitiveRingSegment_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegment_c_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR24_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Sector(mtrScreen->target, x, y, innerRadius, outerRadius, -endAngle,
     -startAngle, sdl_color);
}

/*fa mtrPrimitiveRingSegment_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegment_ca_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR32_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Sector(mtrScreen->target, x, y, innerRadius, outerRadius, -endAngle,
     -startAngle, sdl_color);
}

/*fa mtrPrimitiveRingSegmentFilled_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegmentFilled_rgb_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_RGB_TO_SDL_COLOR(sdl_color, r, g, b);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_SectorFilled(mtrScreen->target, x, y, innerRadius, outerRadius,
     -endAngle, -startAngle, sdl_color);
}

/*fa mtrPrimitiveRingSegmentFilled_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegmentFilled_rgba_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_RGBA_TO_SDL_COLOR(sdl_color, r, g, b, a);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_SectorFilled(mtrScreen->target, x, y, innerRadius, outerRadius,
     -endAngle, -startAngle, sdl_color);
}

/*fa mtrPrimitiveRingSegmentFilled_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegmentFilled_c_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR24_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_SectorFilled(mtrScreen->target, x, y, innerRadius, outerRadius,
     -endAngle, -startAngle, sdl_color);
}

/*fa mtrPrimitiveRingSegmentFilled_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegmentFilled_ca_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR32_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_SectorFilled(mtrScreen->target, x, y, innerRadius, outerRadius,
     -endAngle, -startAngle, sdl_color);
}

/*fa mtrPrimitiveTriangle_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveTriangle_rgb_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_RGB_TO_SDL_COLOR(sdl_color, r, g, b);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Tri(mtrScreen->target, x1, y1, x2, y2, x3, y3, sdl_color);
}

/*fa mtrPrimitiveTriangle_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveTriangle_rgba_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    SDL_Color sdl_color;
    MTR_RGBA_TO_SDL_COLOR(sdl_color, r, g, b, a);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Tri(mtrScreen->target, x1, y1, x2, y2, x3, y3, sdl_color);
}

/*fa mtrPrimitiveTriangle_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveTriangle_c_f(float x1, float y1, float x2,
 float y2, float x3, float y3, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR24_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Tri(mtrScreen->target, x1, y1, x2, y2, x3, y3, sdl_color);
}

/*fa mtrPrimitiveTriangle_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveTriangle_ca_f(float x1, float y1, float x2,
 float y2, float x3, float y3, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR32_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Tri(mtrScreen->target, x1, y1, x2, y2, x3, y3, sdl_color);
}

/*fa mtrPrimitiveTriangleFilled_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveTriangleFilled_rgb_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_RGB_TO_SDL_COLOR(sdl_color, r, g, b);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_TriFilled(mtrScreen->target, x1, y1, x2, y2, x3, y3, sdl_color);
}

/*fa mtrPrimitiveTriangleFilled_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveTriangleFilled_rgba_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    SDL_Color sdl_color;
    MTR_RGBA_TO_SDL_COLOR(sdl_color, r, g, b, a);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_TriFilled(mtrScreen->target, x1, y1, x2, y2, x3, y3, sdl_color);
}

/*fa mtrPrimitiveTriangleFilled_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveTriangleFilled_c_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR24_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_TriFilled(mtrScreen->target, x1, y1, x2, y2, x3, y3, sdl_color);
}

/*fa mtrPrimitiveTriangleFilled_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveTriangleFilled_ca_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR32_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_TriFilled(mtrScreen->target, x1, y1, x2, y2, x3, y3, sdl_color);
}

/*fa mtrPrimitiveRectangle_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRectangle_rgb_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_RGB_TO_SDL_COLOR(sdl_color, r, g, b);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Rectangle(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa mtrPrimitiveRectangle_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRectangle_rgba_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_RGBA_TO_SDL_COLOR(sdl_color, r, g, b, a);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Rectangle(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa mtrPrimitiveRectangle_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRectangle_c_f(float x1, float y1, float x2,
 float y2, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR24_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Rectangle(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa mtrPrimitiveRectangle_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRectangle_ca_f(float x1, float y1,
 float x2, float y2, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR32_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_Rectangle(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa mtrPrimitiveRectangleFilled_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRectangleFilled_rgb_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_RGB_TO_SDL_COLOR(sdl_color, r, g, b);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_RectangleFilled(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa mtrPrimitiveRectangleFilled_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRectangleFilled_rgba_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_RGBA_TO_SDL_COLOR(sdl_color, r, g, b, a);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_RectangleFilled(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa mtrPrimitiveRectangleFilled_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRectangleFilled_c_f(float x1, float y1,
 float x2, float y2, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR24_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_RectangleFilled(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa mtrPrimitiveRectangleFilled_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRectangleFilled_ca_f(float x1, float y1,
 float x2, float y2, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR32_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_RectangleFilled(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa mtrPrimitiveRoundedRectangle_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangle_rgb_f(float x1, float y1,
 float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_RGB_TO_SDL_COLOR(sdl_color, r, g, b);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_RectangleRound(mtrScreen->target, x1, y1, x2, y2, radius, sdl_color);
}

/*fa mtrPrimitiveRoundedRectangle_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangle_rgba_f(float x1, float y1,
 float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_RGBA_TO_SDL_COLOR(sdl_color, r, g, b, a);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_RectangleRound(mtrScreen->target, x1, y1, x2, y2, radius, sdl_color);
}

/*fa mtrPrimitiveRoundedRectangle_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangle_c_f(float x1, float y1,
 float x2, float y2, float radius, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR24_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_RectangleRound(mtrScreen->target, x1, y1, x2, y2, radius, sdl_color);
}

/*fa mtrPrimitiveRoundedRectangle_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangle_ca_f(float x1, float y1,
 float x2, float y2, float radius, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR32_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_RectangleRound(mtrScreen->target, x1, y1, x2, y2, radius, sdl_color);
}

/*fa mtrPrimitiveRoundedRectangleFilled_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangleFilled_rgb_f(float x1,
 float y1, float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_RGB_TO_SDL_COLOR(sdl_color, r, g, b);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_RectangleRoundFilled(mtrScreen->target, x1, y1, x2, y2, radius,
     sdl_color);
}

/*fa mtrPrimitiveRoundedRectangleFilled_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangleFilled_rgba_f(float x1,
 float y1, float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    SDL_Color sdl_color;
    MTR_RGBA_TO_SDL_COLOR(sdl_color, r, g, b, a);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_RectangleRoundFilled(mtrScreen->target, x1, y1, x2, y2, radius,
     sdl_color);
}

/*fa mtrPrimitiveRoundedRectangleFilled_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangleFilled_c_f(float x1,
 float y1, float x2, float y2, float radius, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR24_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_RectangleRoundFilled(mtrScreen->target, x1, y1, x2, y2, radius,
     sdl_color);
}

/*fa mtrPrimitiveRoundedRectangleFilled_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangleFilled_ca_f(float x1,
 float y1, float x2, float y2, float radius, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_COLOR32_TO_SDL_COLOR(sdl_color, color);
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_RectangleRoundFilled(mtrScreen->target, x1, y1, x2, y2, radius,
     sdl_color);
}

/*fa mtrPrimitiveLineBegin_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLineBegin_f(float x, float y)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
    mtrLineDrawing = true;
}

/*fa mtrPrimitiveLineTo_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLineTo_rgb_f(float x, float y, uint8_t r,
 uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    if (!mtrLineDrawing)
    {
        mtrPrimitiveLineBegin_f(x, y);
        return;
    }

    MTR_RGB_TO_SDL_COLOR(sdl_color, r, g, b);
    GPU_Line(mtrScreen->target, mtrLinePointX_f, mtrLinePointY_f, x, y,
     sdl_color);
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa mtrPrimitiveLineTo_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLineTo_rgba_f(float x, float y, uint8_t r,
 uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    if (!mtrLineDrawing)
    {
        mtrPrimitiveLineBegin_f(x, y);
        return;
    }

    MTR_RGBA_TO_SDL_COLOR(sdl_color, r, g, b, a);
    GPU_Line(mtrScreen->target, mtrLinePointX_f, mtrLinePointY_f, x, y,
     sdl_color);
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa mtrPrimitiveLineTo_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLineTo_c_f(float x, float y,
 uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    if (!mtrLineDrawing)
    {
        mtrPrimitiveLineBegin_f(x, y);
        return;
    }

    MTR_COLOR24_TO_SDL_COLOR(sdl_color, color);
    GPU_Line(mtrScreen->target, mtrLinePointX_f, mtrLinePointY_f, x, y,
     sdl_color);
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa mtrPrimitiveLineTo_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLineTo_ca_f(float x, float y,
 uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    if (!mtrLineDrawing)
    {
        mtrPrimitiveLineBegin_f(x, y);
        return;
    }

    MTR_COLOR32_TO_SDL_COLOR(sdl_color, color);
    GPU_Line(mtrScreen->target, mtrLinePointX_f, mtrLinePointY_f, x, y,
     sdl_color);
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa mtrPrimitiveLineEnd yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLineEnd(void)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    mtrLineDrawing = false;
}
