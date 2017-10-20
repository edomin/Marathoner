#include "primitive.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Primitive, FA_FUNCTIONS_COUNT)

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Primitive_SDL2";
    report->version = MTR_VERSION_PRIMITIVE_SDL2;
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
MTR_DCLSPC bool MTR_CALL MTR_PrimitiveInit(void)
{
    SDL_version compiled;
    SDL_version sdlLinked;

    MTR_LogWrite("Initializing primitive drawing subsystem", 0, MTR_LMT_INFO);

    MTR_LogWrite("Reporting SDL compile-time version:", 1, MTR_LMT_INFO);
    SDL_VERSION(&compiled);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, compiled.major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, compiled.minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, compiled.patch);
    MTR_LogWrite("Reporting SDL linked version:", 1, MTR_LMT_INFO);
    SDL_GetVersion(&sdlLinked);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, sdlLinked.major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, sdlLinked.minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, sdlLinked.patch);

    MTR_GetScreen = (mtrGetScreenFunc)MTR_FindFunction("Screen_SDL2",
     "MTR_GetScreen");
    if (MTR_GetScreen == NULL)
    {
        MTR_Notify("Unable to load 'mtrGetScreen' function from 'Screen_SDL2' module",
         1, MTR_LMT_FATAL);
        return false;
    }
    mtrScreen = MTR_GetScreen();
    mtrLineDrawing = false;
    SDL_SetRenderDrawBlendMode(mtrScreen->renderer, SDL_BLENDMODE_BLEND);

    MTR_LogWrite("Primitive drawing subsystem initialized", 0, MTR_LMT_INFO);

    mtrPrimitiveInited = true;
    return true;
}

/*fa MTR_PrimitiveFill_rgb yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveFill_rgb(uint8_t r, uint8_t g,
 uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderClear(mtrScreen->renderer);
}

/*fa MTR_PrimitiveFill_rgba yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveFill_rgba(uint8_t r, uint8_t g,
 uint8_t b, uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderClear(mtrScreen->renderer);
}

/*fa MTR_PrimitiveFill_c yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveFill_c(uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToRgb(color, &r, &g, &b);
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderClear(mtrScreen->renderer);
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
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderClear(mtrScreen->renderer);
}

/*fa MTR_PrimitivePixel_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitivePixel_rgb_f(float x, float y, uint8_t r,
 uint8_t g, uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderDrawPoint(mtrScreen->renderer, x, y);
}

/*fa MTR_PrimitivePixel_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitivePixel_rgba_f(float x, float y, uint8_t r,
 uint8_t g, uint8_t b, uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderDrawPoint(mtrScreen->renderer, x, y);
}

/*fa MTR_PrimitivePixel_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitivePixel_c_f(float x, float y, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToRgb(color, &r, &g, &b);
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderDrawPoint(mtrScreen->renderer, x, y);
}

/*fa MTR_PrimitivePixel_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitivePixel_ca_f(float x, float y,
 uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToRgba(color, &r, &g, &b, &a);
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderDrawPoint(mtrScreen->renderer, x, y);
}

/*fa MTR_PrimitiveLine_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLine_rgb_f(float x1, float y1, float x2,
 float y2, uint8_t r, uint8_t g, uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
}

/*fa MTR_PrimitiveLine_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLine_rgba_f(float x1, float y1, float x2,
 float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
}

/*fa MTR_PrimitiveLine_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLine_c_f(float x1, float y1, float x2,
 float y2, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToRgb(color, &r, &g, &b);
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
}

/*fa MTR_PrimitiveLine_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLine_ca_f(float x1, float y1, float x2,
 float y2, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToRgba(color, &r, &g, &b, &a);
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
}

/*fa MTR_PrimitiveArc_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveArc_rgb_f(float x, float y, float radius,
 float startAngle, float endAngle, uint8_t r, uint8_t g, uint8_t b)
{
    int   i;
    float resultX;
    float resultY;
    float currentAngle;
    int   segmentsCount;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    segmentsCount = fabs(endAngle - startAngle) / 360 * MTR_ARC_SEGMENTS_COUNT;

    currentAngle = (startAngle * MTR_PI_180_F);
    for (i = 0; i < segmentsCount; i++)
    {
        if (i != 0)
            currentAngle = (startAngle + (endAngle - startAngle) /
             segmentsCount * i) * MTR_PI_180_F;
        else
            currentAngle = startAngle * MTR_PI_180_F;
        resultX = radius * cosf(currentAngle);
        resultY = radius * sinf(currentAngle);
        if (i == 0)
            MTR_PrimitiveLineBegin_f(x + resultX, y - resultY);
        else
            MTR_PrimitiveLineTo_rgb_f(x + resultX, y - resultY, r, g, b);
    }
    resultX = radius * cosf(endAngle * MTR_PI_180_F);
    resultY = radius * sinf(endAngle * MTR_PI_180_F);
    MTR_PrimitiveLineTo_rgb_f(x + resultX, y - resultY, r, g, b);
    MTR_PrimitiveLineEnd();
}

/*fa MTR_PrimitiveArc_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveArc_rgba_f(float x, float y, float radius,
 float startAngle, float endAngle, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    int   i;
    float resultX;
    float resultY;
    float currentAngle;
    int   segmentsCount;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    segmentsCount = fabs(endAngle - startAngle) / 360 * MTR_ARC_SEGMENTS_COUNT;

    currentAngle = (startAngle * MTR_PI_180_F);
    for (i = 0; i < segmentsCount; i++)
    {
        if (i != 0)
            currentAngle = (startAngle + (endAngle - startAngle) /
             segmentsCount * i) * MTR_PI_180_F;
        else
            currentAngle = startAngle * MTR_PI_180_F;
        resultX = radius * cosf(currentAngle);
        resultY = radius * sinf(currentAngle);
        if (i == 0)
            MTR_PrimitiveLineBegin_f(x + resultX, y - resultY);
        else
            MTR_PrimitiveLineTo_rgba_f(x + resultX, y - resultY, r, g, b, a);
    }
    resultX = radius * cosf(endAngle * MTR_PI_180_F);
    resultY = radius * sinf(endAngle * MTR_PI_180_F);
    MTR_PrimitiveLineTo_rgba_f(x + resultX, y - resultY, r, g, b, a);
    MTR_PrimitiveLineEnd();
}

/*fa MTR_PrimitiveArc_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveArc_c_f(float x, float y, float radius,
 float startAngle, float endAngle, uint32_t color)
{
    int   i;
    float resultX;
    float resultY;
    float currentAngle;
    int   segmentsCount;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    segmentsCount = fabs(endAngle - startAngle) / 360 * MTR_ARC_SEGMENTS_COUNT;

    currentAngle = (startAngle * MTR_PI_180_F);
    for (i = 0; i < segmentsCount; i++)
    {
        if (i != 0)
            currentAngle = (startAngle + (endAngle - startAngle) /
             segmentsCount * i) * MTR_PI_180_F;
        else
            currentAngle = startAngle * MTR_PI_180_F;
        resultX = radius * cosf(currentAngle);
        resultY = radius * sinf(currentAngle);
        if (i == 0)
            MTR_PrimitiveLineBegin_f(x + resultX, y - resultY);
        else
            MTR_PrimitiveLineTo_c_f(x + resultX, y - resultY, color);
    }
    resultX = radius * cosf(endAngle * MTR_PI_180_F);
    resultY = radius * sinf(endAngle * MTR_PI_180_F);
    MTR_PrimitiveLineTo_c_f(x + resultX, y - resultY, color);
    MTR_PrimitiveLineEnd();
}

/*fa MTR_PrimitiveArc_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveArc_ca_f(float x, float y, float radius,
 float startAngle, float endAngle, uint32_t color)
{
    int   i;
    float resultX;
    float resultY;
    float currentAngle;
    int   segmentsCount;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    segmentsCount = fabs(endAngle - startAngle) / 360 * MTR_ARC_SEGMENTS_COUNT;

    currentAngle = (startAngle * MTR_PI_180_F);
    for (i = 0; i < segmentsCount; i++)
    {
        if (i != 0)
            currentAngle = (startAngle + (endAngle - startAngle) /
             segmentsCount * i) * MTR_PI_180_F;
        else
            currentAngle = startAngle * MTR_PI_180_F;
        resultX = radius * cosf(currentAngle);
        resultY = radius * sinf(currentAngle);
        if (i == 0)
            MTR_PrimitiveLineBegin_f(x + resultX, y - resultY);
        else
            MTR_PrimitiveLineTo_ca_f(x + resultX, y - resultY, color);
    }
    resultX = radius * cosf(endAngle * MTR_PI_180_F);
    resultY = radius * sinf(endAngle * MTR_PI_180_F);
    MTR_PrimitiveLineTo_ca_f(x + resultX, y - resultY, color);
    MTR_PrimitiveLineEnd();
}

/*fa MTR_PrimitiveSegmentFilled_rgb_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveSegmentFilled_rgb_f(float x, float y,
 float radius, float startAngle, float endAngle, uint8_t r, uint8_t g,
 uint8_t b)
{
    return;
}

/*fa MTR_PrimitiveSegmentFilled_rgba_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveSegmentFilled_rgba_f(float x, float y,
 float radius, float startAngle, float endAngle, uint8_t r, uint8_t g,
 uint8_t b, uint8_t a)
{
    return;
}

/*fa MTR_PrimitiveSegmentFilled_c_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveSegmentFilled_c_f(float x, float y,
 float radius, float startAngle, float endAngle, uint32_t color)
{
    return;
}

/*fa MTR_PrimitiveSegmentFilled_ca_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveSegmentFilled_ca_f(float x, float y,
 float radius, float startAngle, float endAngle, uint32_t color)
{
    return;
}

/*fa MTR_PrimitiveCircle_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveCircle_rgb_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b)
{
    int   i;
    float resultX;
    float resultY;
    float startX;
    float startY;
    float currentAngle;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    currentAngle = 0.0f;
    startX = radius * cosf((float)M_PI * 2);
    startY = radius * sinf((float)M_PI * 2);
    for (i = 0; i < MTR_ARC_SEGMENTS_COUNT; i++)
    {
        if (i != 0)
            currentAngle = ((float)M_PI * 2) / MTR_ARC_SEGMENTS_COUNT * i;
        else
            currentAngle = 0.0f;
        resultX = radius * cosf(currentAngle);
        resultY = radius * sinf(currentAngle);
        if (i == 0)
            MTR_PrimitiveLineBegin_f(x + resultX, y + resultY);
        else
            MTR_PrimitiveLineTo_rgb_f(x + resultX, y + resultY, r, g, b);
    }
    MTR_PrimitiveLineTo_rgb_f(x + startX, y + startY, r, g, b);
    MTR_PrimitiveLineEnd();
}

/*fa MTR_PrimitiveCircle_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveCircle_rgba_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    int   i;
    float resultX;
    float resultY;
    float startX;
    float startY;
    float currentAngle;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    currentAngle = 0.0f;
    startX = radius * cosf((float)M_PI * 2);
    startY = radius * sinf((float)M_PI * 2);
    for (i = 0; i < MTR_ARC_SEGMENTS_COUNT; i++)
    {
        if (i != 0)
            currentAngle = ((float)M_PI * 2) / MTR_ARC_SEGMENTS_COUNT * i;
        else
            currentAngle = 0.0f;
        resultX = radius * cosf(currentAngle);
        resultY = radius * sinf(currentAngle);
        if (i == 0)
            MTR_PrimitiveLineBegin_f(x + resultX, y + resultY);
        else
            MTR_PrimitiveLineTo_rgba_f(x + resultX, y + resultY, r, g, b, a);
    }
    MTR_PrimitiveLineTo_rgba_f(x + startX, y + startY, r, g, b, a);
    MTR_PrimitiveLineEnd();
}

/*fa MTR_PrimitiveCircle_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveCircle_c_f(float x, float y, float radius,
 uint32_t color)
{
    int   i;
    float resultX;
    float resultY;
    float startX;
    float startY;
    float currentAngle;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    currentAngle = 0.0f;
    startX = radius * cosf((float)M_PI * 2);
    startY = radius * sinf((float)M_PI * 2);
    for (i = 0; i < MTR_ARC_SEGMENTS_COUNT; i++)
    {
        if (i != 0)
            currentAngle = ((float)M_PI * 2) / MTR_ARC_SEGMENTS_COUNT * i;
        else
            currentAngle = 0.0f;
        resultX = radius * cosf(currentAngle);
        resultY = radius * sinf(currentAngle);
        if (i == 0)
            MTR_PrimitiveLineBegin_f(x + resultX, y + resultY);
        else
            MTR_PrimitiveLineTo_c_f(x + resultX, y + resultY, color);
    }
    MTR_PrimitiveLineTo_c_f(x + startX, y + startY, color);
    MTR_PrimitiveLineEnd();
}

/*fa MTR_PrimitiveCircle_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveCircle_ca_f(float x, float y, float radius,
 uint32_t color)
{
    int   i;
    float resultX;
    float resultY;
    float startX;
    float startY;
    float currentAngle;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    currentAngle = 0.0f;
    startX = radius * cosf((float)M_PI * 2);
    startY = radius * sinf((float)M_PI * 2);
    for (i = 0; i < MTR_ARC_SEGMENTS_COUNT; i++)
    {
        if (i != 0)
            currentAngle = ((float)M_PI * 2) / MTR_ARC_SEGMENTS_COUNT * i;
        else
            currentAngle = 0.0f;
        resultX = radius * cosf(currentAngle);
        resultY = radius * sinf(currentAngle);
        if (i == 0)
            MTR_PrimitiveLineBegin_f(x + resultX, y + resultY);
        else
            MTR_PrimitiveLineTo_ca_f(x + resultX, y + resultY, color);
    }
    MTR_PrimitiveLineTo_ca_f(x + startX, y + startY, color);
    MTR_PrimitiveLineEnd();
}

/*fa MTR_PrimitiveCircleFilled_rgb_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveCircleFilled_rgb_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

/*fa MTR_PrimitiveCircleFilled_rgba_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveCircleFilled_rgba_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return;
}

/*fa MTR_PrimitiveCircleFilled_c_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveCircleFilled_c_f(float x, float y,
 float radius, uint32_t color)
{
    return;
}

/*fa MTR_PrimitiveCircleFilled_ca_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveCircleFilled_ca_f(float x, float y,
 float radius, uint32_t color)
{
    return;
}

/*fa MTR_PrimitiveEllipse_rgb_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveEllipse_rgb_f(float x, float y, float rx,
 float ry, float angle, uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

/*fa MTR_PrimitiveEllipse_rgba_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveEllipse_rgba_f(float x, float y, float rx,
 float ry, float angle, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return;
}

/*fa MTR_PrimitiveEllipse_c_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveEllipse_c_f(float x, float y, float rx,
 float ry, float angle, uint32_t color)
{
    return;
}

/*fa MTR_PrimitiveEllipse_ca_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveEllipse_ca_f(float x, float y, float rx,
 float ry, float angle, uint32_t color)
{
    return;
}

/*fa MTR_PrimitiveEllipseFilled_rgb_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveEllipseFilled_rgb_f(float x, float y,
 float rx, float ry, float angle, uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

/*fa MTR_PrimitiveEllipseFilled_rgba_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveEllipseFilled_rgba_f(float x, float y,
 float rx, float ry, float angle, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return;
}

/*fa MTR_PrimitiveEllipseFilled_c_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveEllipseFilled_c_f(float x, float y,
 float rx, float ry, float angle, uint32_t color)
{
    return;
}

/*fa MTR_PrimitiveEllipseFilled_ca_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveEllipseFilled_ca_f(float x, float y,
 float rx, float ry, float angle, uint32_t color)
{
    return;
}

/*fa MTR_PrimitiveRingSegment_rgb_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRingSegment_rgb_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

/*fa MTR_PrimitiveRingSegment_rgba_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRingSegment_rgba_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return;
}

/*fa MTR_PrimitiveRingSegment_c_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRingSegment_c_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    return;
}

/*fa MTR_PrimitiveRingSegment_ca_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRingSegment_ca_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    return;
}

/*fa MTR_PrimitiveRingSegmentFilled_rgb_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRingSegmentFilled_rgb_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

/*fa MTR_PrimitiveRingSegmentFilled_rgba_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRingSegmentFilled_rgba_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return;
}

/*fa MTR_PrimitiveRingSegmentFilled_c_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRingSegmentFilled_c_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    return;
}

/*fa MTR_PrimitiveRingSegmentFilled_ca_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRingSegmentFilled_ca_f(float x, float y,
 float innerRadius, float outerRadius, float startAngle, float endAngle,
 uint32_t color)
{
    return;
}

/*fa MTR_PrimitiveTriangle_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveTriangle_rgb_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(mtrScreen->renderer, x2, y2, x3, y3);
    SDL_RenderDrawLine(mtrScreen->renderer, x3, y3, x1, y1);
}

/*fa MTR_PrimitiveTriangle_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveTriangle_rgba_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(mtrScreen->renderer, x2, y2, x3, y3);
    SDL_RenderDrawLine(mtrScreen->renderer, x3, y3, x1, y1);
}

/*fa MTR_PrimitiveTriangle_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveTriangle_c_f(float x1, float y1, float x2,
 float y2, float x3, float y3, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToRgb(color, &r, &g, &b);
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(mtrScreen->renderer, x2, y2, x3, y3);
    SDL_RenderDrawLine(mtrScreen->renderer, x3, y3, x1, y1);
}

/*fa MTR_PrimitiveTriangle_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveTriangle_ca_f(float x1, float y1, float x2,
 float y2, float x3, float y3, uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToRgba(color, &r, &g, &b, &a);
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(mtrScreen->renderer, x2, y2, x3, y3);
    SDL_RenderDrawLine(mtrScreen->renderer, x3, y3, x1, y1);
}

/*fa MTR_PrimitiveTriangleFilled_rgb_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveTriangleFilled_rgb_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

/*fa MTR_PrimitiveTriangleFilled_rgba_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveTriangleFilled_rgba_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    return;
}

/*fa MTR_PrimitiveTriangleFilled_c_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveTriangleFilled_c_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint32_t color)
{
    return;
}

/*fa MTR_PrimitiveTriangleFilled_ca_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveTriangleFilled_ca_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint32_t color)
{
    return;
}

/*fa MTR_PrimitiveRectangle_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRectangle_rgb_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Rect rect;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    rect.x = x1;
    rect.y = y1;
    rect.w = x2 - x1 + 1;
    rect.h = y2 - y1 + 1;
    SDL_RenderDrawRect(mtrScreen->renderer, &rect);
}

/*fa MTR_PrimitiveRectangle_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRectangle_rgba_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Rect rect;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    rect.x = x1;
    rect.y = y1;
    rect.w = x2 - x1 + 1;
    rect.h = y2 - y1 + 1;
    SDL_RenderDrawRect(mtrScreen->renderer, &rect);
}

/*fa MTR_PrimitiveRectangle_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRectangle_c_f(float x1, float y1, float x2,
 float y2, uint32_t color)
{
    SDL_Rect rect;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToRgb(color, &r, &g, &b);
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    rect.x = x1;
    rect.y = y1;
    rect.w = x2 - x1 + 1;
    rect.h = y2 - y1 + 1;
    SDL_RenderDrawRect(mtrScreen->renderer, &rect);
}

/*fa MTR_PrimitiveRectangle_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRectangle_ca_f(float x1, float y1,
 float x2, float y2, uint32_t color)
{
    SDL_Rect rect;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToRgba(color, &r, &g, &b, &a);
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    rect.x = x1;
    rect.y = y1;
    rect.w = x2 - x1 + 1;
    rect.h = y2 - y1 + 1;
    SDL_RenderDrawRect(mtrScreen->renderer, &rect);
}

/*fa MTR_PrimitiveRectangleFilled_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRectangleFilled_rgb_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Rect rect;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    rect.x = x1;
    rect.y = y1;
    rect.w = x2 - x1 + 1;
    rect.h = y2 - y1 + 1;
    SDL_RenderFillRect(mtrScreen->renderer, &rect);
}

/*fa MTR_PrimitiveRectangleFilled_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRectangleFilled_rgba_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Rect rect;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    rect.x = x1;
    rect.y = y1;
    rect.w = x2 - x1 + 1;
    rect.h = y2 - y1 + 1;
    SDL_RenderFillRect(mtrScreen->renderer, &rect);
}

/*fa MTR_PrimitiveRectangleFilled_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRectangleFilled_c_f(float x1, float y1,
 float x2, float y2, uint32_t color)
{
    SDL_Rect rect;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color24ToRgb(color, &r, &g, &b);
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    rect.x = x1;
    rect.y = y1;
    rect.w = x2 - x1 + 1;
    rect.h = y2 - y1 + 1;
    SDL_RenderFillRect(mtrScreen->renderer, &rect);
}

/*fa MTR_PrimitiveRectangleFilled_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRectangleFilled_ca_f(float x1, float y1,
 float x2, float y2, uint32_t color)
{
    SDL_Rect rect;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_Color32ToRgba(color, &r, &g, &b, &a);
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    rect.x = x1;
    rect.y = y1;
    rect.w = x2 - x1 + 1;
    rect.h = y2 - y1 + 1;
    SDL_RenderFillRect(mtrScreen->renderer, &rect);
}

/*fa MTR_PrimitiveRoundedRectangle_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRoundedRectangle_rgb_f(float x1, float y1,
 float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_PrimitiveLine_rgb_f(x1 + radius, y1, x2 - radius, y1, r, g, b);
    MTR_PrimitiveLine_rgb_f(x1 + radius, y2, x2 - radius, y2, r, g, b);
    MTR_PrimitiveLine_rgb_f(x1, y1 + radius, x1, y2 - radius, r, g, b);
    MTR_PrimitiveLine_rgb_f(x2, y1 + radius, x2, y2 - radius, r, g, b);

    MTR_PrimitiveArc_rgb_f(x1 + radius, y1 + radius, radius, 90, 180, r, g, b);
    MTR_PrimitiveArc_rgb_f(x1 + radius, y2 - radius, radius, 180, 270, r, g, b);
    MTR_PrimitiveArc_rgb_f(x2 - radius, y1 + radius, radius, 0, 90, r, g, b);
    MTR_PrimitiveArc_rgb_f(x2 - radius, y2 - radius, radius, 270, 360, r, g, b);
}

/*fa MTR_PrimitiveRoundedRectangle_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRoundedRectangle_rgba_f(float x1, float y1,
 float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_PrimitiveLine_rgba_f(x1 + radius, y1, x2 - radius, y1, r, g, b, a);
    MTR_PrimitiveLine_rgba_f(x1 + radius, y2, x2 - radius, y2, r, g, b, a);
    MTR_PrimitiveLine_rgba_f(x1, y1 + radius, x1, y2 - radius, r, g, b, a);
    MTR_PrimitiveLine_rgba_f(x2, y1 + radius, x2, y2 - radius, r, g, b, a);

    MTR_PrimitiveArc_rgba_f(x1 + radius, y1 + radius, radius, 90, 180, r, g, b,
     a);
    MTR_PrimitiveArc_rgba_f(x1 + radius, y2 - radius, radius, 180, 270, r, g, b,
     a);
    MTR_PrimitiveArc_rgba_f(x2 - radius, y1 + radius, radius, 0, 90, r, g, b,
     a);
    MTR_PrimitiveArc_rgba_f(x2 - radius, y2 - radius, radius, 270, 360, r, g, b,
     a);
}

/*fa MTR_PrimitiveRoundedRectangle_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRoundedRectangle_c_f(float x1, float y1,
 float x2, float y2, float radius, uint32_t color)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_PrimitiveLine_c_f(x1 + radius, y1, x2 - radius, y1, color);
    MTR_PrimitiveLine_c_f(x1 + radius, y2, x2 - radius, y2, color);
    MTR_PrimitiveLine_c_f(x1, y1 + radius, x1, y2 - radius, color);
    MTR_PrimitiveLine_c_f(x2, y1 + radius, x2, y2 - radius, color);

    MTR_PrimitiveArc_c_f(x1 + radius, y1 + radius, radius, 90, 180, color);
    MTR_PrimitiveArc_c_f(x1 + radius, y2 - radius, radius, 180, 270, color);
    MTR_PrimitiveArc_c_f(x2 - radius, y1 + radius, radius, 0, 90, color);
    MTR_PrimitiveArc_c_f(x2 - radius, y2 - radius, radius, 270, 360, color);
}

/*fa MTR_PrimitiveRoundedRectangle_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRoundedRectangle_ca_f(float x1, float y1,
 float x2, float y2, float radius, uint32_t color)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    MTR_PrimitiveLine_ca_f(x1 + radius, y1, x2 - radius, y1, color);
    MTR_PrimitiveLine_ca_f(x1 + radius, y2, x2 - radius, y2, color);
    MTR_PrimitiveLine_ca_f(x1, y1 + radius, x1, y2 - radius, color);
    MTR_PrimitiveLine_ca_f(x2, y1 + radius, x2, y2 - radius, color);

    MTR_PrimitiveArc_ca_f(x1 + radius, y1 + radius, radius, 90, 180, color);
    MTR_PrimitiveArc_ca_f(x1 + radius, y2 - radius, radius, 180, 270, color);
    MTR_PrimitiveArc_ca_f(x2 - radius, y1 + radius, radius, 0, 90, color);
    MTR_PrimitiveArc_ca_f(x2 - radius, y2 - radius, radius, 270, 360, color);
}

/*fa MTR_PrimitiveRoundedRectangleFilled_rgb_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRoundedRectangleFilled_rgb_f(float x1,
 float y1, float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

/*fa MTR_PrimitiveRoundedRectangleFilled_rgba_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRoundedRectangleFilled_rgba_f(float x1,
 float y1, float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    return;
}

/*fa MTR_PrimitiveRoundedRectangleFilled_c_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRoundedRectangleFilled_c_f(float x1,
 float y1, float x2, float y2, float radius, uint32_t color)
{
    return;
}

/*fa MTR_PrimitiveRoundedRectangleFilled_ca_f dummy */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveRoundedRectangleFilled_ca_f(float x1,
 float y1, float x2, float y2, float radius, uint32_t color)
{
    return;
}

/*fa MTR_PrimitiveLineBegin_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLineBegin_f(float x, float y)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    mtrLineDrawing = true;
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa MTR_PrimitiveLineTo_rgb_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLineTo_rgb_f(float x, float y,
 uint8_t r, uint8_t g, uint8_t b)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    if (!mtrLineDrawing)
    {
        MTR_PrimitiveLineBegin_f(x, y);
        return;
    }

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderDrawLine(mtrScreen->renderer, mtrLinePointX_f, mtrLinePointY_f,
     x, y);
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa MTR_PrimitiveLineTo_rgba_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLineTo_rgba_f(float x, float y,
 uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    if (!mtrLineDrawing)
    {
        MTR_PrimitiveLineBegin_f(x, y);
        return;
    }

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderDrawLine(mtrScreen->renderer, mtrLinePointX_f, mtrLinePointY_f,
     x, y);
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa MTR_PrimitiveLineTo_c_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLineTo_c_f(float x, float y,
 uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    if (!mtrLineDrawing)
    {
        MTR_PrimitiveLineBegin_f(x, y);
        return;
    }

    MTR_Color24ToRgb(color, &r, &g, &b);
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderDrawLine(mtrScreen->renderer, mtrLinePointX_f, mtrLinePointY_f,
     x, y);
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa MTR_PrimitiveLineTo_ca_f yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLineTo_ca_f(float x, float y,
 uint32_t color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    if (!mtrLineDrawing)
    {
        MTR_PrimitiveLineBegin_f(x, y);
        return;
    }

    MTR_Color32ToRgba(color, &r, &g, &b, &a);
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderDrawLine(mtrScreen->renderer, mtrLinePointX_f, mtrLinePointY_f,
     x, y);
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa MTR_PrimitiveLineEnd yes */
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLineEnd(void)
{
    MTR_PRIMITIVE_CHECK_IF_NOT_INITED();

    mtrLineDrawing = false;
}
