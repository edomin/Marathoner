#include "primitive.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Primitive, FA_FUNCTIONS_COUNT)

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
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

/*fa MTR_PrimitiveInit yes */
MTR_DCLSPC bool MTR_CALL MTR_PrimitiveInit(void)
{
    SDL_version linked;

    MTR_LogWrite("Initializing primitive drawing subsystem", 0, MTR_LMT_INFO);

    MTR_LogWrite("Reporting sdl_gpu compile-time version:", 1, MTR_LMT_INFO);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, SDL_GPU_VERSION_MAJOR);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, SDL_GPU_VERSION_MINOR);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, SDL_GPU_VERSION_PATCH);
    MTR_LogWrite("Reporting sdl_gpu linked version:", 1, MTR_LMT_INFO);
    linked = GPU_GetLinkedVersion();
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, linked.major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, linked.minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, linked.patch);

    MTR_GetScreen = (mtrGetScreenFunc)MTR_FindFunction("Screen_SDL2_gpu",
     "MTR_GetScreen");
    if (MTR_GetScreen == NULL)
    {
        MTR_Notify(
         "Unable to load 'mtrGetScreen' function from 'Screen_SDL2_gpu' module",
         1, MTR_LMT_FATAL);
        return false;
    }
    mtrScreen = MTR_GetScreen();
    mtrLineDrawing = false;

    MTR_LogWrite("Primitive drawing subsystem initialized", 0, MTR_LMT_INFO);

    mtrPrimitiveInited = true;
    return true;
}

/*fa MTR_PrimitiveFill_rgb yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveFill_rgb(uint8_t r, uint8_t g, uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_ClearRGB(mtrScreen->target, r, g, b);
}

/*fa MTR_PrimitiveFill_rgba yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveFill_rgba(uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    GPU_ClearRGBA(mtrScreen->target, r, g, b, a);
}

/*fa MTR_PrimitiveFill_c yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveFill_c(uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToRgb(color, &r, &g, &b);
    GPU_ClearRGB(mtrScreen->target, r, g, b);
}

/*fa MTR_PrimitiveFill_ca yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveFill_ca(uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToRgba(color, &r, &g, &b, &a);
    GPU_ClearRGBA(mtrScreen->target, r, g, b, a);
}

/*fa MTR_PrimitivePixel_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitivePixel_rgb_f(float x, float y, uint8_t r,
 uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbToSdlColor(r, g, b, &sdl_color);
    GPU_Pixel(mtrScreen->target, x, y, sdl_color);
}

/*fa MTR_PrimitivePixel_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitivePixel_rgba_f(float x, float y, uint8_t r,
 uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbaToSdlColor(r, g, b, a, &sdl_color);
    GPU_Pixel(mtrScreen->target, x, y, sdl_color);
}

/*fa MTR_PrimitivePixel_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitivePixel_c_f(float x, float y, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToSdlColor(color, &sdl_color);
    GPU_Pixel(mtrScreen->target, x, y, sdl_color);
}

/*fa MTR_PrimitivePixel_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitivePixel_ca_f(float x, float y,
 uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToSdlColor(color, &sdl_color);
    GPU_Pixel(mtrScreen->target, x, y, sdl_color);
}

/*fa MTR_PrimitiveLine_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLine_rgb_f(float x1, float y1, float x2,
 float y2, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbToSdlColor(r, g, b, &sdl_color);
    GPU_Line(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa MTR_PrimitiveLine_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLine_rgba_f(float x1, float y1, float x2,
 float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbaToSdlColor(r, g, b, a, &sdl_color);
    GPU_Line(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa MTR_PrimitiveLine_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLine_c_f(float x1, float y1, float x2,
 float y2, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToSdlColor(color, &sdl_color);
    GPU_Line(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa MTR_PrimitiveLine_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLine_ca_f(float x1, float y1, float x2,
 float y2, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToSdlColor(color, &sdl_color);
    GPU_Line(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa MTR_PrimitiveArc_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveArc_rgb_f(float x, float y, float radius,
 float startAngle, float endAngle, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbToSdlColor(r, g, b, &sdl_color);
    GPU_Arc(mtrScreen->target, x, y, radius, -endAngle, -startAngle, sdl_color);
}

/*fa MTR_PrimitiveArc_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveArc_rgba_f(float x, float y, float radius,
 float startAngle, float endAngle, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbaToSdlColor(r, g, b, a, &sdl_color);
    GPU_Arc(mtrScreen->target, x, y, radius, -endAngle, -startAngle, sdl_color);
}

/*fa MTR_PrimitiveArc_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveArc_c_f(float x, float y, float radius,
 float startAngle, float endAngle, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToSdlColor(color, &sdl_color);
    GPU_Arc(mtrScreen->target, x, y, radius, -endAngle, -startAngle, sdl_color);
}

/*fa MTR_PrimitiveArc_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveArc_ca_f(float x, float y, float radius,
 float startAngle, float endAngle, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToSdlColor(color, &sdl_color);
    GPU_Arc(mtrScreen->target, x, y, radius, -endAngle, -startAngle, sdl_color);
}

/*fa MTR_PrimitiveSegmentFilled_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveSegmentFilled_rgb_f(float x, float y,
 float radius, float startAngle, float endAngle, uint8_t r, uint8_t g,
 uint8_t b)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbToSdlColor(r, g, b, &sdl_color);
    GPU_ArcFilled(mtrScreen->target, x, y, radius, -endAngle, -startAngle,
     sdl_color);
}

/*fa MTR_PrimitiveSegmentFilled_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveSegmentFilled_rgba_f(float x, float y,
 float radius, float startAngle, float endAngle, uint8_t r, uint8_t g,
 uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbaToSdlColor(r, g, b, a, &sdl_color);
    GPU_ArcFilled(mtrScreen->target, x, y, radius, -endAngle, -startAngle,
     sdl_color);
}

/*fa MTR_PrimitiveSegmentFilled_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveSegmentFilled_c_f(float x, float y,
 float radius, float startAngle, float endAngle, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToSdlColor(color, &sdl_color);
    GPU_ArcFilled(mtrScreen->target, x, y, radius, -endAngle, -startAngle,
     sdl_color);
}

/*fa MTR_PrimitiveSegmentFilled_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveSegmentFilled_ca_f(float x, float y,
 float radius, float startAngle, float endAngle, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToSdlColor(color, &sdl_color);
    GPU_ArcFilled(mtrScreen->target, x, y, radius, -endAngle, -startAngle,
     sdl_color);
}

/*fa MTR_PrimitiveCircle_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveCircle_rgb_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbToSdlColor(r, g, b, &sdl_color);
    GPU_Circle(mtrScreen->target, x, y, radius, sdl_color);
}

/*fa MTR_PrimitiveCircle_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveCircle_rgba_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbaToSdlColor(r, g, b, a, &sdl_color);
    GPU_Circle(mtrScreen->target, x, y, radius, sdl_color);
}

/*fa MTR_PrimitiveCircle_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveCircle_c_f(float x, float y, float radius,
 uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToSdlColor(color, &sdl_color);
    GPU_Circle(mtrScreen->target, x, y, radius, sdl_color);
}

/*fa MTR_PrimitiveCircle_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveCircle_ca_f(float x, float y, float radius,
 uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToSdlColor(color, &sdl_color);
    GPU_Circle(mtrScreen->target, x, y, radius, sdl_color);
}

/*fa MTR_PrimitiveCircleFilled_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveCircleFilled_rgb_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbToSdlColor(r, g, b, &sdl_color);
    GPU_CircleFilled(mtrScreen->target, x, y, radius, sdl_color);
}

/*fa MTR_PrimitiveCircleFilled_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveCircleFilled_rgba_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbaToSdlColor(r, g, b, a, &sdl_color);
    GPU_CircleFilled(mtrScreen->target, x, y, radius, sdl_color);
}

/*fa MTR_PrimitiveCircleFilled_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveCircleFilled_c_f(float x, float y,
 float radius, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToSdlColor(color, &sdl_color);
    GPU_CircleFilled(mtrScreen->target, x, y, radius, sdl_color);
}

/*fa MTR_PrimitiveCircleFilled_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveCircleFilled_ca_f(float x, float y,
 float radius, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToSdlColor(color, &sdl_color);
    GPU_CircleFilled(mtrScreen->target, x, y, radius, sdl_color);
}

/*fa MTR_PrimitiveEllipse_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveEllipse_rgb_f(float x, float y, float rx,
 float ry, float angle, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbToSdlColor(r, g, b, &sdl_color);
    GPU_Ellipse(mtrScreen->target, x, y, rx, ry, -angle, sdl_color);
}

/*fa MTR_PrimitiveEllipse_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveEllipse_rgba_f(float x, float y, float rx,
 float ry, float angle, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbaToSdlColor(r, g, b, a, &sdl_color);
    GPU_Ellipse(mtrScreen->target, x, y, rx, ry, -angle, sdl_color);
}

/*fa MTR_PrimitiveEllipse_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveEllipse_c_f(float x, float y, float rx,
 float ry, float angle, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToSdlColor(color, &sdl_color);
    GPU_Ellipse(mtrScreen->target, x, y, rx, ry, -angle, sdl_color);
}

/*fa MTR_PrimitiveEllipse_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveEllipse_ca_f(float x, float y, float rx,
 float ry, float angle, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToSdlColor(color, &sdl_color);
    GPU_Ellipse(mtrScreen->target, x, y, rx, ry, -angle, sdl_color);
}

/*fa MTR_PrimitiveEllipseFilled_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveEllipseFilled_rgb_f(float x, float y,
 float rx, float ry, float angle, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbToSdlColor(r, g, b, &sdl_color);
    GPU_EllipseFilled(mtrScreen->target, x, y, rx, ry, -angle, sdl_color);
}

/*fa MTR_PrimitiveEllipseFilled_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveEllipseFilled_rgba_f(float x, float y,
 float rx, float ry, float angle, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbaToSdlColor(r, g, b, a, &sdl_color);
    GPU_EllipseFilled(mtrScreen->target, x, y, rx, ry, -angle, sdl_color);
}

/*fa MTR_PrimitiveEllipseFilled_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveEllipseFilled_c_f(float x, float y,
 float rx, float ry, float angle, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToSdlColor(color, &sdl_color);
    GPU_EllipseFilled(mtrScreen->target, x, y, rx, ry, -angle, sdl_color);
}

/*fa MTR_PrimitiveEllipseFilled_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveEllipseFilled_ca_f(float x, float y,
 float rx, float ry, float angle, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToSdlColor(color, &sdl_color);
    GPU_EllipseFilled(mtrScreen->target, x, y, rx, ry, -angle, sdl_color);
}

/*fa MTR_PrimitiveRingSegment_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRingSegment_rgb_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbToSdlColor(r, g, b, &sdl_color);
    GPU_Sector(mtrScreen->target, x, y, innerRadius, outerRadius, -endAngle,
     -startAngle, sdl_color);
}

/*fa MTR_PrimitiveRingSegment_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRingSegment_rgba_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbaToSdlColor(r, g, b, a, &sdl_color);
    GPU_Sector(mtrScreen->target, x, y, innerRadius, outerRadius, -endAngle,
     -startAngle, sdl_color);
}

/*fa MTR_PrimitiveRingSegment_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRingSegment_c_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToSdlColor(color, &sdl_color);
    GPU_Sector(mtrScreen->target, x, y, innerRadius, outerRadius, -endAngle,
     -startAngle, sdl_color);
}

/*fa MTR_PrimitiveRingSegment_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRingSegment_ca_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToSdlColor(color, &sdl_color);
    GPU_Sector(mtrScreen->target, x, y, innerRadius, outerRadius, -endAngle,
     -startAngle, sdl_color);
}

/*fa MTR_PrimitiveRingSegmentFilled_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRingSegmentFilled_rgb_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbToSdlColor(r, g, b, &sdl_color);
    GPU_SectorFilled(mtrScreen->target, x, y, innerRadius, outerRadius,
     -endAngle, -startAngle, sdl_color);
}

/*fa MTR_PrimitiveRingSegmentFilled_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRingSegmentFilled_rgba_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbaToSdlColor(r, g, b, a, &sdl_color);
    GPU_SectorFilled(mtrScreen->target, x, y, innerRadius, outerRadius,
     -endAngle, -startAngle, sdl_color);
}

/*fa MTR_PrimitiveRingSegmentFilled_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRingSegmentFilled_c_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToSdlColor(color, &sdl_color);
    GPU_SectorFilled(mtrScreen->target, x, y, innerRadius, outerRadius,
     -endAngle, -startAngle, sdl_color);
}

/*fa MTR_PrimitiveRingSegmentFilled_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRingSegmentFilled_ca_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToSdlColor(color, &sdl_color);
    GPU_SectorFilled(mtrScreen->target, x, y, innerRadius, outerRadius,
     -endAngle, -startAngle, sdl_color);
}

/*fa MTR_PrimitiveTriangle_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveTriangle_rgb_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbToSdlColor(r, g, b, &sdl_color);
    GPU_Tri(mtrScreen->target, x1, y1, x2, y2, x3, y3, sdl_color);
}

/*fa MTR_PrimitiveTriangle_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveTriangle_rgba_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbaToSdlColor(r, g, b, a, &sdl_color);
    GPU_Tri(mtrScreen->target, x1, y1, x2, y2, x3, y3, sdl_color);
}

/*fa MTR_PrimitiveTriangle_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveTriangle_c_f(float x1, float y1, float x2,
 float y2, float x3, float y3, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToSdlColor(color, &sdl_color);
    GPU_Tri(mtrScreen->target, x1, y1, x2, y2, x3, y3, sdl_color);
}

/*fa MTR_PrimitiveTriangle_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveTriangle_ca_f(float x1, float y1, float x2,
 float y2, float x3, float y3, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToSdlColor(color, &sdl_color);
    GPU_Tri(mtrScreen->target, x1, y1, x2, y2, x3, y3, sdl_color);
}

/*fa MTR_PrimitiveTriangleFilled_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveTriangleFilled_rgb_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbToSdlColor(r, g, b, &sdl_color);
    GPU_TriFilled(mtrScreen->target, x1, y1, x2, y2, x3, y3, sdl_color);
}

/*fa MTR_PrimitiveTriangleFilled_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveTriangleFilled_rgba_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbaToSdlColor(r, g, b, a, &sdl_color);
    GPU_TriFilled(mtrScreen->target, x1, y1, x2, y2, x3, y3, sdl_color);
}

/*fa MTR_PrimitiveTriangleFilled_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveTriangleFilled_c_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToSdlColor(color, &sdl_color);
    GPU_TriFilled(mtrScreen->target, x1, y1, x2, y2, x3, y3, sdl_color);
}

/*fa MTR_PrimitiveTriangleFilled_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveTriangleFilled_ca_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToSdlColor(color, &sdl_color);
    GPU_TriFilled(mtrScreen->target, x1, y1, x2, y2, x3, y3, sdl_color);
}

/*fa MTR_PrimitiveRectangle_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRectangle_rgb_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbToSdlColor(r, g, b, &sdl_color);
    GPU_Rectangle(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa MTR_PrimitiveRectangle_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRectangle_rgba_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbaToSdlColor(r, g, b, a, &sdl_color);
    GPU_Rectangle(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa MTR_PrimitiveRectangle_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRectangle_c_f(float x1, float y1, float x2,
 float y2, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToSdlColor(color, &sdl_color);
    GPU_Rectangle(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa MTR_PrimitiveRectangle_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRectangle_ca_f(float x1, float y1,
 float x2, float y2, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToSdlColor(color, &sdl_color);
    GPU_Rectangle(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa MTR_PrimitiveRectangleFilled_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRectangleFilled_rgb_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbToSdlColor(r, g, b, &sdl_color);
    GPU_RectangleFilled(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa MTR_PrimitiveRectangleFilled_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRectangleFilled_rgba_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbaToSdlColor(r, g, b, a, &sdl_color);
    GPU_RectangleFilled(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa MTR_PrimitiveRectangleFilled_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRectangleFilled_c_f(float x1, float y1,
 float x2, float y2, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToSdlColor(color, &sdl_color);
    GPU_RectangleFilled(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa MTR_PrimitiveRectangleFilled_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRectangleFilled_ca_f(float x1, float y1,
 float x2, float y2, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToSdlColor(color, &sdl_color);
    GPU_RectangleFilled(mtrScreen->target, x1, y1, x2, y2, sdl_color);
}

/*fa MTR_PrimitiveRoundedRectangle_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRoundedRectangle_rgb_f(float x1, float y1,
 float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbToSdlColor(r, g, b, &sdl_color);
    GPU_RectangleRound(mtrScreen->target, x1, y1, x2, y2, radius, sdl_color);
}

/*fa MTR_PrimitiveRoundedRectangle_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRoundedRectangle_rgba_f(float x1, float y1,
 float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbaToSdlColor(r, g, b, a, &sdl_color);
    GPU_RectangleRound(mtrScreen->target, x1, y1, x2, y2, radius, sdl_color);
}

/*fa MTR_PrimitiveRoundedRectangle_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRoundedRectangle_c_f(float x1, float y1,
 float x2, float y2, float radius, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToSdlColor(color, &sdl_color);
    GPU_RectangleRound(mtrScreen->target, x1, y1, x2, y2, radius, sdl_color);
}

/*fa MTR_PrimitiveRoundedRectangle_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRoundedRectangle_ca_f(float x1, float y1,
 float x2, float y2, float radius, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToSdlColor(color, &sdl_color);
    GPU_RectangleRound(mtrScreen->target, x1, y1, x2, y2, radius, sdl_color);
}

/*fa MTR_PrimitiveRoundedRectangleFilled_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRoundedRectangleFilled_rgb_f(float x1,
 float y1, float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbToSdlColor(r, g, b, &sdl_color);
    GPU_RectangleRoundFilled(mtrScreen->target, x1, y1, x2, y2, radius,
     sdl_color);
}

/*fa MTR_PrimitiveRoundedRectangleFilled_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRoundedRectangleFilled_rgba_f(float x1,
 float y1, float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_RgbaToSdlColor(r, g, b, a, &sdl_color);
    GPU_RectangleRoundFilled(mtrScreen->target, x1, y1, x2, y2, radius,
     sdl_color);
}

/*fa MTR_PrimitiveRoundedRectangleFilled_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRoundedRectangleFilled_c_f(float x1,
 float y1, float x2, float y2, float radius, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToSdlColor(color, &sdl_color);
    GPU_RectangleRoundFilled(mtrScreen->target, x1, y1, x2, y2, radius,
     sdl_color);
}

/*fa MTR_PrimitiveRoundedRectangleFilled_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRoundedRectangleFilled_ca_f(float x1,
 float y1, float x2, float y2, float radius, uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToSdlColor(color, &sdl_color);
    GPU_RectangleRoundFilled(mtrScreen->target, x1, y1, x2, y2, radius,
     sdl_color);
}

/*fa MTR_PrimitiveLineBegin_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLineBegin_f(float x, float y)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
    mtrLineDrawing = true;
}

/*fa MTR_PrimitiveLineTo_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLineTo_rgb_f(float x, float y, uint8_t r,
 uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    if (!mtrLineDrawing)
    {
        MTR_PrimitiveLineBegin_f(x, y);
        return;
    }

    MTR_RgbToSdlColor(r, g, b, &sdl_color);
    GPU_Line(mtrScreen->target, mtrLinePointX_f, mtrLinePointY_f, x, y,
     sdl_color);
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa MTR_PrimitiveLineTo_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLineTo_rgba_f(float x, float y, uint8_t r,
 uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    if (!mtrLineDrawing)
    {
        MTR_PrimitiveLineBegin_f(x, y);
        return;
    }

    MTR_RgbaToSdlColor(r, g, b, a, &sdl_color);
    GPU_Line(mtrScreen->target, mtrLinePointX_f, mtrLinePointY_f, x, y,
     sdl_color);
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa MTR_PrimitiveLineTo_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLineTo_c_f(float x, float y,
 uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    if (!mtrLineDrawing)
    {
        MTR_PrimitiveLineBegin_f(x, y);
        return;
    }

    MTR_Color24ToSdlColor(color, &sdl_color);
    GPU_Line(mtrScreen->target, mtrLinePointX_f, mtrLinePointY_f, x, y,
     sdl_color);
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa MTR_PrimitiveLineTo_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLineTo_ca_f(float x, float y,
 uint32_t color)
{
    SDL_Color sdl_color;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    if (!mtrLineDrawing)
    {
        MTR_PrimitiveLineBegin_f(x, y);
        return;
    }

    MTR_Color32ToSdlColor(color, &sdl_color);
    GPU_Line(mtrScreen->target, mtrLinePointX_f, mtrLinePointY_f, x, y,
     sdl_color);
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa MTR_PrimitiveLineEnd yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLineEnd(void)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    mtrLineDrawing = false;
}
