#include "primitive.h"

#include "marathoner/plugin_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Primitive_SDL2";
    report->version = MTR_VERSION_PRIMITIVE_SDL2;
    report->prereqsCount = 1;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    report->prereqs[0] = "Screen_SDL2";
    return report;
}

MTR_EXPORT bool MTR_CALL mtrPrimitiveInit(void)
{
    SDL_version compiled;
    SDL_version sdlLinked;

    mtrLogWrite("Initializing primitive drawing subsystem", 0, MTR_LMT_INFO);

    mtrLogWrite("Reporting SDL compile-time version:", 1, MTR_LMT_INFO);
    SDL_VERSION(&compiled);
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, compiled.major);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, compiled.minor);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, compiled.patch);
    mtrLogWrite("Reporting SDL linked version:", 1, MTR_LMT_INFO);
    SDL_GetVersion(&sdlLinked);
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, sdlLinked.major);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, sdlLinked.minor);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, sdlLinked.patch);

    mtrGetScreen = (mtrGetScreenFunc)mtrFindFunction("Screen_SDL2",
     "mtrGetScreen");
    if (mtrGetScreen == NULL)
    {
        mtrNotify("Unable to load 'mtrGetScreen' function from 'Screen_SDL2' module",
         1, MTR_LMT_FATAL);
        return false;
    }
    mtrScreen = mtrGetScreen();

    mtrLogWrite("Primitive drawing subsystem initialized", 0, MTR_LMT_INFO);
    return true;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveFill_rgb(uint8_t r, uint8_t g,
 uint8_t b)
{
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderClear(mtrScreen->renderer);
}

MTR_EXPORT void MTR_CALL mtrPrimitiveFill_rgba(uint8_t r, uint8_t g,
 uint8_t b, uint8_t a)
{
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderClear(mtrScreen->renderer);
}

MTR_EXPORT void MTR_CALL mtrPrimitiveFill_c(uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderClear(mtrScreen->renderer);
}

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
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderClear(mtrScreen->renderer);
}

MTR_EXPORT void MTR_CALL mtrPrimitivePixel_rgb_f(float x, float y, uint8_t r,
 uint8_t g, uint8_t b)
{
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderDrawPoint(mtrScreen->renderer, x, y);
}

MTR_EXPORT void MTR_CALL mtrPrimitivePixel_rgba_f(float x, float y, uint8_t r,
 uint8_t g, uint8_t b, uint8_t a)
{
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderDrawPoint(mtrScreen->renderer, x, y);
}

MTR_EXPORT void MTR_CALL mtrPrimitivePixel_c_f(float x, float y, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderDrawPoint(mtrScreen->renderer, x, y);
}

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
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderDrawPoint(mtrScreen->renderer, x, y);
}

MTR_EXPORT void MTR_CALL mtrPrimitiveLine_rgb_f(float x1, float y1, float x2,
 float y2, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
}

MTR_EXPORT void MTR_CALL mtrPrimitiveLine_rgba_f(float x1, float y1, float x2,
 float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
}

MTR_EXPORT void MTR_CALL mtrPrimitiveLine_c_f(float x1, float y1, float x2,
 float y2, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
}

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
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
}

MTR_EXPORT void MTR_CALL mtrPrimitiveArc_rgb_f(float x, float y, float radius,
 float startAngle, float endAngle, uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveArc_rgba_f(float x, float y, float radius,
 float startAngle, float endAngle, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveArc_c_f(float x, float y, float radius,
 float startAngle, float endAngle, uint32_t color)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveArc_ca_f(float x, float y, float radius,
 float startAngle, float endAngle, uint32_t color)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveSegmentFilled_rgb_f(float x, float y,
 float radius, float startAngle, float endAngle, uint8_t r, uint8_t g,
 uint8_t b)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveSegmentFilled_rgba_f(float x, float y,
 float radius, float startAngle, float endAngle, uint8_t r, uint8_t g,
 uint8_t b, uint8_t a)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveSegmentFilled_c_f(float x, float y,
 float radius, float startAngle, float endAngle, uint32_t color)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveSegmentFilled_ca_f(float x, float y,
 float radius, float startAngle, float endAngle, uint32_t color)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveCircle_rgb_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveCircle_rgba_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveCircle_c_f(float x, float y, float radius,
 uint32_t color)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveCircle_ca_f(float x, float y, float radius,
 uint32_t color)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveCircleFilled_rgb_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveCircleFilled_rgba_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveCircleFilled_c_f(float x, float y,
 float radius, uint32_t color)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveCircleFilled_ca_f(float x, float y,
 float radius, uint32_t color)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveEllipse_rgb_f(float x, float y, float rx,
 float ry, float angle, uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveEllipse_rgba_f(float x, float y, float rx,
 float ry, float angle, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveEllipse_c_f(float x, float y, float rx,
 float ry, float angle, uint32_t color)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveEllipse_ca_f(float x, float y, float rx,
 float ry, float angle, uint32_t color)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveEllipseFilled_rgb_f(float x, float y,
 float rx, float ry, float angle, uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveEllipseFilled_rgba_f(float x, float y,
 float rx, float ry, float angle, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveEllipseFilled_c_f(float x, float y,
 float rx, float ry, float angle, uint32_t color)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveEllipseFilled_ca_f(float x, float y,
 float rx, float ry, float angle, uint32_t color)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegment_rgb_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegment_rgba_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegment_c_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegment_ca_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegmentFilled_rgb_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegmentFilled_rgba_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegmentFilled_c_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRingSegmentFilled_ca_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveTriangle_rgb_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(mtrScreen->renderer, x2, y2, x3, y3);
    SDL_RenderDrawLine(mtrScreen->renderer, x3, y3, x1, y1);
}

MTR_EXPORT void MTR_CALL mtrPrimitiveTriangle_rgba_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(mtrScreen->renderer, x2, y2, x3, y3);
    SDL_RenderDrawLine(mtrScreen->renderer, x3, y3, x1, y1);
}

MTR_EXPORT void MTR_CALL mtrPrimitiveTriangle_c_f(float x1, float y1, float x2,
 float y2, float x3, float y3, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(mtrScreen->renderer, x2, y2, x3, y3);
    SDL_RenderDrawLine(mtrScreen->renderer, x3, y3, x1, y1);
}

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
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(mtrScreen->renderer, x2, y2, x3, y3);
    SDL_RenderDrawLine(mtrScreen->renderer, x3, y3, x1, y1);
}

MTR_EXPORT void MTR_CALL mtrPrimitiveTriangleFilled_rgb_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveTriangleFilled_rgba_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveTriangleFilled_c_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint32_t color)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveTriangleFilled_ca_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint32_t color)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRectangle_rgb_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Rect rect;

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    rect.x = x1;
    rect.y = y1;
    rect.w = x2;
    rect.h = y2;
    SDL_RenderDrawRect(mtrScreen->renderer, &rect);
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRectangle_rgba_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Rect rect;

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    rect.x = x1;
    rect.y = y1;
    rect.w = x2;
    rect.h = y2;
    SDL_RenderDrawRect(mtrScreen->renderer, &rect);
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRectangle_c_f(float x1, float y1, float x2,
 float y2, uint32_t color)
{
    SDL_Rect rect;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    rect.x = x1;
    rect.y = y1;
    rect.w = x2;
    rect.h = y2;
    SDL_RenderDrawRect(mtrScreen->renderer, &rect);
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRectangle_ca_f(float x1, float y1,
 float x2, float y2, uint32_t color)
{
    SDL_Rect rect;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    r = (uint8_t)(color >> 24);
    g = (uint8_t)((color >> 16) - ((uint32_t)r << 8));
    b = (uint8_t)((color >> 8) - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    a = (uint8_t)(color  - ((uint32_t)r << 24) - ((uint32_t)g << 16) -
     ((uint32_t)b << 8));
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    rect.x = x1;
    rect.y = y1;
    rect.w = x2;
    rect.h = y2;
    SDL_RenderDrawRect(mtrScreen->renderer, &rect);
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRectangleFilled_rgb_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Rect rect;

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    rect.x = x1;
    rect.y = y1;
    rect.w = x2;
    rect.h = y2;
    SDL_RenderFillRect(mtrScreen->renderer, &rect);
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRectangleFilled_rgba_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Rect rect;

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    rect.x = x1;
    rect.y = y1;
    rect.w = x2;
    rect.h = y2;
    SDL_RenderFillRect(mtrScreen->renderer, &rect);
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRectangleFilled_c_f(float x1, float y1,
 float x2, float y2, uint32_t color)
{
    SDL_Rect rect;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    rect.x = x1;
    rect.y = y1;
    rect.w = x2;
    rect.h = y2;
    SDL_RenderFillRect(mtrScreen->renderer, &rect);
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRectangleFilled_ca_f(float x1, float y1,
 float x2, float y2, uint32_t color)
{
    SDL_Rect rect;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    r = (uint8_t)(color >> 24);
    g = (uint8_t)((color >> 16) - ((uint32_t)r << 8));
    b = (uint8_t)((color >> 8) - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    a = (uint8_t)(color  - ((uint32_t)r << 24) - ((uint32_t)g << 16) -
     ((uint32_t)b << 8));
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    rect.x = x1;
    rect.y = y1;
    rect.w = x2;
    rect.h = y2;
    SDL_RenderFillRect(mtrScreen->renderer, &rect);
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangle_rgb_f(float x1, float y1,
 float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangle_rgba_f(float x1, float y1,
 float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangle_c_f(float x1, float y1,
 float x2, float y2, float radius, uint32_t color)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangle_ca_f(float x1, float y1,
 float x2, float y2, float radius, uint32_t color)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangleFilled_rgb_f(float x1,
 float y1, float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangleFilled_rgba_f(float x1,
 float y1, float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangleFilled_c_f(float x1,
 float y1, float x2, float y2, float radius, uint32_t color)
{
    return;
}

MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangleFilled_ca_f(float x1,
 float y1, float x2, float y2, float radius, uint32_t color)
{
    return;
}
