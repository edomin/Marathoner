#include "primitive.h"

#include "plugin_common.c"

__declspec(dllexport) mtrReport* __stdcall mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Primitive_sdl_gpu";
    report->prereqsCount = 1;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    report->prereqs[0] = "Screen_sdl_gpu";
    return report;
}

__declspec(dllexport) bool __stdcall mtrPrimitiveInit(void)
{
    mtrLogWrite("Initializing primitive drawing subsystem", 0, MTR_LMT_INFO);

    mtrGetScreen = (mtrGetScreenFunc)mtrFindFunction("Screen_sdl_gpu", "mtrGetScreen");
    if (mtrGetScreen == NULL)
    {
        mtrNotify("Unable to load 'mtrGetScreen' function from 'Screen_sdl_gpu' module",
         1, MTR_LMT_FATAL);
        return false;
    }
    mtrScreen = mtrGetScreen();

    mtrLogWrite("Primitive drawing subsystem initialized", 0, MTR_LMT_INFO);
    return true;
}

__declspec(dllexport) void __stdcall mtrPrimitiveFill_rgb(uint8_t r, uint8_t g,
 uint8_t b)
{
    GPU_ClearRGB(mtrScreen->screen, r, g, b);
}

__declspec(dllexport) void __stdcall mtrPrimitiveFill_rgba(uint8_t r, uint8_t g,
 uint8_t b, uint8_t a)
{
    GPU_ClearRGBA(mtrScreen->screen, r, g, b, a);
}

__declspec(dllexport) void __stdcall mtrPrimitiveFill_c(uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    GPU_ClearRGB(mtrScreen->screen, r, g, b);
}

__declspec(dllexport) void __stdcall mtrPrimitiveFill_ca(uint32_t color)
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
    GPU_ClearRGBA(mtrScreen->screen, r, g, b, a);
}

__declspec(dllexport) void __stdcall mtrPrimitivePixel_rgb_f(float x, float y,
 uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = 0xFF;
    GPU_Pixel(mtrScreen->screen, x, y, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitivePixel_rgba_f(float x, float y,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = a;
    GPU_Pixel(mtrScreen->screen, x, y, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitivePixel_c_f(float x, float y,
 uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 16);
    sdl_color.g = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)(color - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = 0xFF;
    GPU_Pixel(mtrScreen->screen, x, y, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitivePixel_ca_f(float x, float y,
 uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 24);
    sdl_color.g = (uint8_t)((color >> 16) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = (uint8_t)(color - ((uint32_t)sdl_color.r << 24) -
     ((uint32_t)sdl_color.g << 16) - ((uint32_t)sdl_color.b << 8));
    GPU_Pixel(mtrScreen->screen, x, y, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveLine_rgb_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = 0xFF;
    GPU_Line(mtrScreen->screen, x1, y1, x2, y2, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveLine_rgba_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = a;
    GPU_Line(mtrScreen->screen, x1, y1, x2, y2, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveLine_c_f(float x1, float y1,
 float x2, float y2, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 16);
    sdl_color.g = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)(color - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = 0xFF;
    GPU_Line(mtrScreen->screen, x1, y1, x2, y2, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveLine_ca_f(float x1, float y1,
 float x2, float y2, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 24);
    sdl_color.g = (uint8_t)((color >> 16) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = (uint8_t)(color - ((uint32_t)sdl_color.r << 24) -
     ((uint32_t)sdl_color.g << 16) - ((uint32_t)sdl_color.b << 8));
    GPU_Line(mtrScreen->screen, x1, y1, x2, y2, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveArc_rgb_f(float x, float y,
 float radius, float startAngle, float endAngle, uint8_t r, uint8_t g,
 uint8_t b)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = 0xFF;
    GPU_Arc(mtrScreen->screen, x, y, radius, -endAngle, -startAngle, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveArc_rgba_f(float x, float y,
 float radius, float startAngle, float endAngle, uint8_t r, uint8_t g,
 uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = a;
    GPU_Arc(mtrScreen->screen, x, y, radius, -endAngle, -startAngle, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveArc_c_f(float x, float y,
 float radius, float startAngle, float endAngle, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 16);
    sdl_color.g = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)(color - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = 0xFF;
    GPU_Arc(mtrScreen->screen, x, y, radius, -endAngle, -startAngle, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveArc_ca_f(float x, float y,
 float radius, float startAngle, float endAngle, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 24);
    sdl_color.g = (uint8_t)((color >> 16) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = (uint8_t)(color - ((uint32_t)sdl_color.r << 24) -
     ((uint32_t)sdl_color.g << 16) - ((uint32_t)sdl_color.b << 8));
    GPU_Arc(mtrScreen->screen, x, y, radius, -endAngle, -startAngle, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveSegmentFilled_rgb_f(float x,
 float y, float radius, float startAngle, float endAngle, uint8_t r, uint8_t g,
 uint8_t b)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = 0xFF;
    GPU_ArcFilled(mtrScreen->screen, x, y, radius, -endAngle, -startAngle,
     sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveSegmentFilled_rgba_f(float x,
 float y, float radius, float startAngle, float endAngle, uint8_t r, uint8_t g,
 uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = a;
    GPU_ArcFilled(mtrScreen->screen, x, y, radius, -endAngle, -startAngle,
     sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveSegmentFilled_c_f(float x,
 float y, float radius, float startAngle, float endAngle, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 16);
    sdl_color.g = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)(color - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = 0xFF;
    GPU_ArcFilled(mtrScreen->screen, x, y, radius, -endAngle, -startAngle,
     sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveSegmentFilled_ca_f(float x,
 float y, float radius, float startAngle, float endAngle, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 24);
    sdl_color.g = (uint8_t)((color >> 16) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = (uint8_t)(color - ((uint32_t)sdl_color.r << 24) -
     ((uint32_t)sdl_color.g << 16) - ((uint32_t)sdl_color.b << 8));
    GPU_ArcFilled(mtrScreen->screen, x, y, radius, -endAngle, -startAngle,
     sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveCircle_rgb_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = 0xFF;
    GPU_Circle(mtrScreen->screen, x, y, radius, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveCircle_rgba_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = a;
    GPU_Circle(mtrScreen->screen, x, y, radius, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveCircle_c_f(float x, float y,
 float radius, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 16);
    sdl_color.g = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)(color - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = 0xFF;
    GPU_Circle(mtrScreen->screen, x, y, radius, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveCircle_ca_f(float x, float y,
 float radius, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 24);
    sdl_color.g = (uint8_t)((color >> 16) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = (uint8_t)(color - ((uint32_t)sdl_color.r << 24) -
     ((uint32_t)sdl_color.g << 16) - ((uint32_t)sdl_color.b << 8));
    GPU_Circle(mtrScreen->screen, x, y, radius, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveCircleFilled_rgb_f(float x,
 float y, float radius, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = 0xFF;
    GPU_CircleFilled(mtrScreen->screen, x, y, radius, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveCircleFilled_rgba_f(float x,
 float y, float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = a;
    GPU_CircleFilled(mtrScreen->screen, x, y, radius, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveCircleFilled_c_f(float x,
 float y, float radius, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 16);
    sdl_color.g = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)(color - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = 0xFF;
    GPU_CircleFilled(mtrScreen->screen, x, y, radius, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveCircleFilled_ca_f(float x,
 float y, float radius, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 24);
    sdl_color.g = (uint8_t)((color >> 16) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = (uint8_t)(color - ((uint32_t)sdl_color.r << 24) -
     ((uint32_t)sdl_color.g << 16) - ((uint32_t)sdl_color.b << 8));
    GPU_CircleFilled(mtrScreen->screen, x, y, radius, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveEllipse_rgb_f(float x,
 float y, float rx, float ry, float angle, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = 0xFF;
    GPU_Ellipse(mtrScreen->screen, x, y, rx, ry, -angle, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveEllipse_rgba_f(float x,
 float y, float rx, float ry, float angle, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = a;
    GPU_Ellipse(mtrScreen->screen, x, y, rx, ry, -angle, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveEllipse_c_f(float x,
 float y, float rx, float ry, float angle, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 16);
    sdl_color.g = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)(color - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = 0xFF;
    GPU_Ellipse(mtrScreen->screen, x, y, rx, ry, -angle, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveEllipse_ca_f(float x,
 float y, float rx, float ry, float angle, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 24);
    sdl_color.g = (uint8_t)((color >> 16) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = (uint8_t)(color - ((uint32_t)sdl_color.r << 24) -
     ((uint32_t)sdl_color.g << 16) - ((uint32_t)sdl_color.b << 8));
    GPU_Ellipse(mtrScreen->screen, x, y, rx, ry, -angle, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveEllipseFilled_rgb_f(float x,
 float y, float rx, float ry, float angle, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = 0xFF;
    GPU_EllipseFilled(mtrScreen->screen, x, y, rx, ry, -angle, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveEllipseFilled_rgba_f(float x,
 float y, float rx, float ry, float angle, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = a;
    GPU_EllipseFilled(mtrScreen->screen, x, y, rx, ry, -angle, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveEllipseFilled_c_f(float x,
 float y, float rx, float ry, float angle, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 16);
    sdl_color.g = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)(color - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = 0xFF;
    GPU_EllipseFilled(mtrScreen->screen, x, y, rx, ry, -angle, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveEllipseFilled_ca_f(float x,
 float y, float rx, float ry, float angle, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 24);
    sdl_color.g = (uint8_t)((color >> 16) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = (uint8_t)(color - ((uint32_t)sdl_color.r << 24) -
     ((uint32_t)sdl_color.g << 16) - ((uint32_t)sdl_color.b << 8));
    GPU_EllipseFilled(mtrScreen->screen, x, y, rx, ry, -angle, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRingSegment_rgb_f(float x,
 float y, float innerRadius, float outerRadius, float startAngle,
 float endAngle, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = 0xFF;
    GPU_Sector(mtrScreen->screen, x, y, innerRadius, outerRadius, -endAngle,
     -startAngle, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRingSegment_rgba_f(float x,
 float y, float innerRadius, float outerRadius, float startAngle,
 float endAngle, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = a;
    GPU_Sector(mtrScreen->screen, x, y, innerRadius, outerRadius, -endAngle,
     -startAngle, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRingSegment_c_f(float x,
 float y, float innerRadius, float outerRadius, float startAngle,
 float endAngle, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 16);
    sdl_color.g = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)(color - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = 0xFF;
    GPU_Sector(mtrScreen->screen, x, y, innerRadius, outerRadius, -endAngle,
     -startAngle, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRingSegment_ca_f(float x,
 float y, float innerRadius, float outerRadius, float startAngle,
 float endAngle, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 24);
    sdl_color.g = (uint8_t)((color >> 16) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = (uint8_t)(color - ((uint32_t)sdl_color.r << 24) -
     ((uint32_t)sdl_color.g << 16) - ((uint32_t)sdl_color.b << 8));
    GPU_Sector(mtrScreen->screen, x, y, innerRadius, outerRadius, -endAngle,
     -startAngle, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRingSegmentFilled_rgb_f(float x,
 float y, float innerRadius, float outerRadius, float startAngle,
 float endAngle, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = 0xFF;
    GPU_SectorFilled(mtrScreen->screen, x, y, innerRadius, outerRadius,
     -endAngle, -startAngle, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRingSegmentFilled_rgba_f(float x,
 float y, float innerRadius, float outerRadius, float startAngle,
 float endAngle, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = a;
    GPU_SectorFilled(mtrScreen->screen, x, y, innerRadius, outerRadius,
     -endAngle, -startAngle, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRingSegmentFilled_c_f(float x,
 float y, float innerRadius, float outerRadius, float startAngle,
 float endAngle, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 16);
    sdl_color.g = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)(color - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = 0xFF;
    GPU_SectorFilled(mtrScreen->screen, x, y, innerRadius, outerRadius,
     -endAngle, -startAngle, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRingSegmentFilled_ca_f(float x,
 float y, float innerRadius, float outerRadius, float startAngle,
 float endAngle, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 24);
    sdl_color.g = (uint8_t)((color >> 16) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = (uint8_t)(color - ((uint32_t)sdl_color.r << 24) -
     ((uint32_t)sdl_color.g << 16) - ((uint32_t)sdl_color.b << 8));
    GPU_SectorFilled(mtrScreen->screen, x, y, innerRadius, outerRadius,
     -endAngle, -startAngle, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveTriangle_rgb_f(float x1,
 float y1, float x2, float y2, float x3, float y3, uint8_t r, uint8_t g,
 uint8_t b)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = 0xFF;
    GPU_Tri(mtrScreen->screen, x1, y1, x2, y2, x3, y3, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveTriangle_rgba_f(float x1,
 float y1, float x2, float y2, float x3, float y3, uint8_t r, uint8_t g,
 uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = a;
    GPU_Tri(mtrScreen->screen, x1, y1, x2, y2, x3, y3, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveTriangle_c_f(float x1,
 float y1, float x2, float y2, float x3, float y3, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 16);
    sdl_color.g = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)(color - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = 0xFF;
    GPU_Tri(mtrScreen->screen, x1, y1, x2, y2, x3, y3, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveTriangle_ca_f(float x1,
 float y1, float x2, float y2, float x3, float y3, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 24);
    sdl_color.g = (uint8_t)((color >> 16) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = (uint8_t)(color - ((uint32_t)sdl_color.r << 24) -
     ((uint32_t)sdl_color.g << 16) - ((uint32_t)sdl_color.b << 8));
    GPU_Tri(mtrScreen->screen, x1, y1, x2, y2, x3, y3, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveTriangleFilled_rgb_f(float x1,
 float y1, float x2, float y2, float x3, float y3, uint8_t r, uint8_t g,
 uint8_t b)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = 0xFF;
    GPU_TriFilled(mtrScreen->screen, x1, y1, x2, y2, x3, y3, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveTriangleFilled_rgba_f(float x1,
 float y1, float x2, float y2, float x3, float y3, uint8_t r, uint8_t g,
 uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = a;
    GPU_TriFilled(mtrScreen->screen, x1, y1, x2, y2, x3, y3, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveTriangleFilled_c_f(float x1,
 float y1, float x2, float y2, float x3, float y3, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 16);
    sdl_color.g = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)(color - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = 0xFF;
    GPU_TriFilled(mtrScreen->screen, x1, y1, x2, y2, x3, y3, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveTriangleFilled_ca_f(float x1,
 float y1, float x2, float y2, float x3, float y3, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 24);
    sdl_color.g = (uint8_t)((color >> 16) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = (uint8_t)(color - ((uint32_t)sdl_color.r << 24) -
     ((uint32_t)sdl_color.g << 16) - ((uint32_t)sdl_color.b << 8));
    GPU_TriFilled(mtrScreen->screen, x1, y1, x2, y2, x3, y3, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRectangle_rgb_f(float x1,
 float y1, float x2, float y2, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = 0xFF;
    GPU_Rectangle(mtrScreen->screen, x1, y1, x2, y2, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRectangle_rgba_f(float x1,
 float y1, float x2, float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = a;
    GPU_Rectangle(mtrScreen->screen, x1, y1, x2, y2, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRectangle_c_f(float x1,
 float y1, float x2, float y2, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 16);
    sdl_color.g = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)(color - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = 0xFF;
    GPU_Rectangle(mtrScreen->screen, x1, y1, x2, y2, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRectangle_ca_f(float x1,
 float y1, float x2, float y2, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 24);
    sdl_color.g = (uint8_t)((color >> 16) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = (uint8_t)(color - ((uint32_t)sdl_color.r << 24) -
     ((uint32_t)sdl_color.g << 16) - ((uint32_t)sdl_color.b << 8));
    GPU_Rectangle(mtrScreen->screen, x1, y1, x2, y2, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRectangleFilled_rgb_f(float x1,
 float y1, float x2, float y2, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = 0xFF;
    GPU_RectangleFilled(mtrScreen->screen, x1, y1, x2, y2, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRectangleFilled_rgba_f(float x1,
 float y1, float x2, float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = a;
    GPU_RectangleFilled(mtrScreen->screen, x1, y1, x2, y2, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRectangleFilled_c_f(float x1,
 float y1, float x2, float y2, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 16);
    sdl_color.g = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)(color - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = 0xFF;
    GPU_RectangleFilled(mtrScreen->screen, x1, y1, x2, y2, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRectangleFilled_ca_f(float x1,
 float y1, float x2, float y2, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 24);
    sdl_color.g = (uint8_t)((color >> 16) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = (uint8_t)(color - ((uint32_t)sdl_color.r << 24) -
     ((uint32_t)sdl_color.g << 16) - ((uint32_t)sdl_color.b << 8));
    GPU_RectangleFilled(mtrScreen->screen, x1, y1, x2, y2, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRoundedRectangle_rgb_f(float x1,
 float y1, float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = 0xFF;
    GPU_RectangleRound(mtrScreen->screen, x1, y1, x2, y2, radius, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRoundedRectangle_rgba_f(float x1,
 float y1, float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = a;
    GPU_RectangleRound(mtrScreen->screen, x1, y1, x2, y2, radius, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRoundedRectangle_c_f(float x1,
 float y1, float x2, float y2, float radius, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 16);
    sdl_color.g = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)(color - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = 0xFF;
    GPU_RectangleRound(mtrScreen->screen, x1, y1, x2, y2, radius, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRoundedRectangle_ca_f(float x1,
 float y1, float x2, float y2, float radius, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 24);
    sdl_color.g = (uint8_t)((color >> 16) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = (uint8_t)(color - ((uint32_t)sdl_color.r << 24) -
     ((uint32_t)sdl_color.g << 16) - ((uint32_t)sdl_color.b << 8));
    GPU_RectangleRound(mtrScreen->screen, x1, y1, x2, y2, radius, sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRoundedRectangleFilled_rgb_f(float x1,
 float y1, float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = 0xFF;
    GPU_RectangleRoundFilled(mtrScreen->screen, x1, y1, x2, y2, radius,
     sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRoundedRectangleFilled_rgba_f(float x1,
 float y1, float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    SDL_Color sdl_color;
    sdl_color.r = r;
    sdl_color.g = g;
    sdl_color.b = b;
    sdl_color.a = a;
    GPU_RectangleRoundFilled(mtrScreen->screen, x1, y1, x2, y2, radius,
     sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRoundedRectangleFilled_c_f(float x1,
 float y1, float x2, float y2, float radius, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 16);
    sdl_color.g = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)(color - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = 0xFF;
    GPU_RectangleRoundFilled(mtrScreen->screen, x1, y1, x2, y2, radius,
     sdl_color);
}

__declspec(dllexport) void __stdcall mtrPrimitiveRoundedRectangleFilled_ca_f(float x1,
 float y1, float x2, float y2, float radius, uint32_t color)
{
    SDL_Color sdl_color;
    sdl_color.r = (uint8_t)(color >> 24);
    sdl_color.g = (uint8_t)((color >> 16) - ((uint32_t)sdl_color.r << 8));
    sdl_color.b = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 16) -
     ((uint32_t)sdl_color.g << 8));
    sdl_color.a = (uint8_t)(color - ((uint32_t)sdl_color.r << 24) -
     ((uint32_t)sdl_color.g << 16) - ((uint32_t)sdl_color.b << 8));
    GPU_RectangleRoundFilled(mtrScreen->screen, x1, y1, x2, y2, radius,
     sdl_color);
}
