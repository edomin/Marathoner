#include "primitive.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Primitive, FA_FUNCTIONS_COUNT)

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
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

/*fa mtrPrimitiveInit yes */
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
    mtrLineDrawing = false;
    SDL_SetRenderDrawBlendMode(mtrScreen->renderer, SDL_BLENDMODE_BLEND);

    mtrLogWrite("Primitive drawing subsystem initialized", 0, MTR_LMT_INFO);
    return true;
}

/*fa mtrPrimitiveFill_rgb yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveFill_rgb(uint8_t r, uint8_t g,
 uint8_t b)
{
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderClear(mtrScreen->renderer);
}

/*fa mtrPrimitiveFill_rgba yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveFill_rgba(uint8_t r, uint8_t g,
 uint8_t b, uint8_t a)
{
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderClear(mtrScreen->renderer);
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
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderClear(mtrScreen->renderer);
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
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderClear(mtrScreen->renderer);
}

/*fa mtrPrimitivePixel_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitivePixel_rgb_f(float x, float y, uint8_t r,
 uint8_t g, uint8_t b)
{
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderDrawPoint(mtrScreen->renderer, x, y);
}

/*fa mtrPrimitivePixel_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitivePixel_rgba_f(float x, float y, uint8_t r,
 uint8_t g, uint8_t b, uint8_t a)
{
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderDrawPoint(mtrScreen->renderer, x, y);
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
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderDrawPoint(mtrScreen->renderer, x, y);
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
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderDrawPoint(mtrScreen->renderer, x, y);
}

/*fa mtrPrimitiveLine_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLine_rgb_f(float x1, float y1, float x2,
 float y2, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
}

/*fa mtrPrimitiveLine_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLine_rgba_f(float x1, float y1, float x2,
 float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
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
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
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
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
}

/*fa mtrPrimitiveArc_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveArc_rgb_f(float x, float y, float radius,
 float startAngle, float endAngle, uint8_t r, uint8_t g, uint8_t b)
{
    int i;
    float resultX;
    float resultY;
    float currentAngle;
    int segmentsCount;

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
            mtrPrimitiveLineBegin_f(x + resultX, y - resultY);
        else
            mtrPrimitiveLineTo_rgb_f(x + resultX, y - resultY, r, g, b);
    }
    resultX = radius * cosf(endAngle * MTR_PI_180_F);
    resultY = radius * sinf(endAngle * MTR_PI_180_F);
    mtrPrimitiveLineTo_rgb_f(x + resultX, y - resultY, r, g, b);
    mtrPrimitiveLineEnd();
}

/*fa mtrPrimitiveArc_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveArc_rgba_f(float x, float y, float radius,
 float startAngle, float endAngle, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    int i;
    float resultX;
    float resultY;
    float currentAngle;
    int segmentsCount;

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
            mtrPrimitiveLineBegin_f(x + resultX, y - resultY);
        else
            mtrPrimitiveLineTo_rgba_f(x + resultX, y - resultY, r, g, b, a);
    }
    resultX = radius * cosf(endAngle * MTR_PI_180_F);
    resultY = radius * sinf(endAngle * MTR_PI_180_F);
    mtrPrimitiveLineTo_rgba_f(x + resultX, y - resultY, r, g, b, a);
    mtrPrimitiveLineEnd();
}

/*fa mtrPrimitiveArc_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveArc_c_f(float x, float y, float radius,
 float startAngle, float endAngle, uint32_t color)
{
    int i;
    float resultX;
    float resultY;
    float currentAngle;
    int segmentsCount;

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
            mtrPrimitiveLineBegin_f(x + resultX, y - resultY);
        else
            mtrPrimitiveLineTo_c_f(x + resultX, y - resultY, color);
    }
    resultX = radius * cosf(endAngle * MTR_PI_180_F);
    resultY = radius * sinf(endAngle * MTR_PI_180_F);
    mtrPrimitiveLineTo_c_f(x + resultX, y - resultY, color);
    mtrPrimitiveLineEnd();
}

/*fa mtrPrimitiveArc_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveArc_ca_f(float x, float y, float radius,
 float startAngle, float endAngle, uint32_t color)
{
    int i;
    float resultX;
    float resultY;
    float currentAngle;
    int segmentsCount;

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
            mtrPrimitiveLineBegin_f(x + resultX, y - resultY);
        else
            mtrPrimitiveLineTo_ca_f(x + resultX, y - resultY, color);
    }
    resultX = radius * cosf(endAngle * MTR_PI_180_F);
    resultY = radius * sinf(endAngle * MTR_PI_180_F);
    mtrPrimitiveLineTo_ca_f(x + resultX, y - resultY, color);
    mtrPrimitiveLineEnd();
}

/*fa mtrPrimitiveSegmentFilled_rgb_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveSegmentFilled_rgb_f(float x, float y,
 float radius, float startAngle, float endAngle, uint8_t r, uint8_t g,
 uint8_t b)
{
    return;
}

/*fa mtrPrimitiveSegmentFilled_rgba_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveSegmentFilled_rgba_f(float x, float y,
 float radius, float startAngle, float endAngle, uint8_t r, uint8_t g,
 uint8_t b, uint8_t a)
{
    return;
}

/*fa mtrPrimitiveSegmentFilled_c_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveSegmentFilled_c_f(float x, float y,
 float radius, float startAngle, float endAngle, uint32_t color)
{
    return;
}

/*fa mtrPrimitiveSegmentFilled_ca_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveSegmentFilled_ca_f(float x, float y,
 float radius, float startAngle, float endAngle, uint32_t color)
{
    return;
}

/*fa mtrPrimitiveCircle_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircle_rgb_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b)
{
    int i;
    float resultX;
    float resultY;
    float startX;
    float startY;
    float currentAngle;

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
            mtrPrimitiveLineBegin_f(x + resultX, y + resultY);
        else
            mtrPrimitiveLineTo_rgb_f(x + resultX, y + resultY, r, g, b);
    }
    mtrPrimitiveLineTo_rgb_f(x + startX, y + startY, r, g, b);
    mtrPrimitiveLineEnd();
}

/*fa mtrPrimitiveCircle_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircle_rgba_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    int i;
    float resultX;
    float resultY;
    float startX;
    float startY;
    float currentAngle;

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
            mtrPrimitiveLineBegin_f(x + resultX, y + resultY);
        else
            mtrPrimitiveLineTo_rgba_f(x + resultX, y + resultY, r, g, b, a);
    }
    mtrPrimitiveLineTo_rgba_f(x + startX, y + startY, r, g, b, a);
    mtrPrimitiveLineEnd();
}

/*fa mtrPrimitiveCircle_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircle_c_f(float x, float y, float radius,
 uint32_t color)
{
    int i;
    float resultX;
    float resultY;
    float startX;
    float startY;
    float currentAngle;

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
            mtrPrimitiveLineBegin_f(x + resultX, y + resultY);
        else
            mtrPrimitiveLineTo_c_f(x + resultX, y + resultY, color);
    }
    mtrPrimitiveLineTo_c_f(x + startX, y + startY, color);
    mtrPrimitiveLineEnd();
}

/*fa mtrPrimitiveCircle_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircle_ca_f(float x, float y, float radius,
 uint32_t color)
{
    int i;
    float resultX;
    float resultY;
    float startX;
    float startY;
    float currentAngle;

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
            mtrPrimitiveLineBegin_f(x + resultX, y + resultY);
        else
            mtrPrimitiveLineTo_ca_f(x + resultX, y + resultY, color);
    }
    mtrPrimitiveLineTo_ca_f(x + startX, y + startY, color);
    mtrPrimitiveLineEnd();
}

/*fa mtrPrimitiveCircleFilled_rgb_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircleFilled_rgb_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

/*fa mtrPrimitiveCircleFilled_rgba_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircleFilled_rgba_f(float x, float y,
 float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return;
}

/*fa mtrPrimitiveCircleFilled_c_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircleFilled_c_f(float x, float y,
 float radius, uint32_t color)
{
    return;
}

/*fa mtrPrimitiveCircleFilled_ca_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveCircleFilled_ca_f(float x, float y,
 float radius, uint32_t color)
{
    return;
}

/*fa mtrPrimitiveEllipse_rgb_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipse_rgb_f(float x, float y, float rx,
 float ry, float angle, uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

/*fa mtrPrimitiveEllipse_rgba_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipse_rgba_f(float x, float y, float rx,
 float ry, float angle, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return;
}

/*fa mtrPrimitiveEllipse_c_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipse_c_f(float x, float y, float rx,
 float ry, float angle, uint32_t color)
{
    return;
}

/*fa mtrPrimitiveEllipse_ca_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipse_ca_f(float x, float y, float rx,
 float ry, float angle, uint32_t color)
{
    return;
}

/*fa mtrPrimitiveEllipseFilled_rgb_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipseFilled_rgb_f(float x, float y,
 float rx, float ry, float angle, uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

/*fa mtrPrimitiveEllipseFilled_rgba_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipseFilled_rgba_f(float x, float y,
 float rx, float ry, float angle, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    return;
}

/*fa mtrPrimitiveEllipseFilled_c_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipseFilled_c_f(float x, float y,
 float rx, float ry, float angle, uint32_t color)
{
    return;
}

/*fa mtrPrimitiveEllipseFilled_ca_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveEllipseFilled_ca_f(float x, float y,
 float rx, float ry, float angle, uint32_t color)
{
    return;
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
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(mtrScreen->renderer, x2, y2, x3, y3);
    SDL_RenderDrawLine(mtrScreen->renderer, x3, y3, x1, y1);
}

/*fa mtrPrimitiveTriangle_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveTriangle_rgba_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(mtrScreen->renderer, x2, y2, x3, y3);
    SDL_RenderDrawLine(mtrScreen->renderer, x3, y3, x1, y1);
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
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(mtrScreen->renderer, x2, y2, x3, y3);
    SDL_RenderDrawLine(mtrScreen->renderer, x3, y3, x1, y1);
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
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderDrawLine(mtrScreen->renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(mtrScreen->renderer, x2, y2, x3, y3);
    SDL_RenderDrawLine(mtrScreen->renderer, x3, y3, x1, y1);
}

/*fa mtrPrimitiveTriangleFilled_rgb_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveTriangleFilled_rgb_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

/*fa mtrPrimitiveTriangleFilled_rgba_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveTriangleFilled_rgba_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    return;
}

/*fa mtrPrimitiveTriangleFilled_c_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveTriangleFilled_c_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint32_t color)
{
    return;
}

/*fa mtrPrimitiveTriangleFilled_ca_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveTriangleFilled_ca_f(float x1, float y1,
 float x2, float y2, float x3, float y3, uint32_t color)
{
    return;
}

/*fa mtrPrimitiveRectangle_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRectangle_rgb_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Rect rect;

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    rect.x = x1;
    rect.y = y1;
    rect.w = x2 - x1;
    rect.h = y2 - y1;
    SDL_RenderDrawRect(mtrScreen->renderer, &rect);
}

/*fa mtrPrimitiveRectangle_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRectangle_rgba_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Rect rect;

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    rect.x = x1;
    rect.y = y1;
    rect.w = x2 - x1;
    rect.h = y2 - y1;
    SDL_RenderDrawRect(mtrScreen->renderer, &rect);
}

/*fa mtrPrimitiveRectangle_c_f yes */
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
    rect.w = x2 - x1;
    rect.h = y2 - y1;
    SDL_RenderDrawRect(mtrScreen->renderer, &rect);
}

/*fa mtrPrimitiveRectangle_ca_f yes */
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
    rect.w = x2 - x1;
    rect.h = y2 - y1;
    SDL_RenderDrawRect(mtrScreen->renderer, &rect);
}

/*fa mtrPrimitiveRectangleFilled_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRectangleFilled_rgb_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Rect rect;

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    rect.x = x1;
    rect.y = y1;
    rect.w = x2 - x1;
    rect.h = y2 - y1;
    SDL_RenderFillRect(mtrScreen->renderer, &rect);
}

/*fa mtrPrimitiveRectangleFilled_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRectangleFilled_rgba_f(float x1, float y1,
 float x2, float y2, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_Rect rect;

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    rect.x = x1;
    rect.y = y1;
    rect.w = x2 - x1;
    rect.h = y2 - y1;
    SDL_RenderFillRect(mtrScreen->renderer, &rect);
}

/*fa mtrPrimitiveRectangleFilled_c_f yes */
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
    rect.w = x2 - x1;
    rect.h = y2 - y1;
    SDL_RenderFillRect(mtrScreen->renderer, &rect);
}

/*fa mtrPrimitiveRectangleFilled_ca_f yes */
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
    rect.w = x2 - x1;
    rect.h = y2 - y1;
    SDL_RenderFillRect(mtrScreen->renderer, &rect);
}

/*fa mtrPrimitiveRoundedRectangle_rgb_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangle_rgb_f(float x1, float y1,
 float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b)
{
    mtrPrimitiveLine_rgb_f(x1 + radius, y1, x2 - radius, y1, r, g, b);
    mtrPrimitiveLine_rgb_f(x1 + radius, y2, x2 - radius, y2, r, g, b);
    mtrPrimitiveLine_rgb_f(x1, y1 + radius, x1, y2 - radius, r, g, b);
    mtrPrimitiveLine_rgb_f(x2, y1 + radius, x2, y2 - radius, r, g, b);

    mtrPrimitiveArc_rgb_f(x1 + radius, y1 + radius, radius, 90, 180, r, g, b);
    mtrPrimitiveArc_rgb_f(x1 + radius, y2 - radius, radius, 180, 270, r, g, b);
    mtrPrimitiveArc_rgb_f(x2 - radius, y1 + radius, radius, 0, 90, r, g, b);
    mtrPrimitiveArc_rgb_f(x2 - radius, y2 - radius, radius, 270, 360, r, g, b);
}

/*fa mtrPrimitiveRoundedRectangle_rgba_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangle_rgba_f(float x1, float y1,
 float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    mtrPrimitiveLine_rgba_f(x1 + radius, y1, x2 - radius, y1, r, g, b, a);
    mtrPrimitiveLine_rgba_f(x1 + radius, y2, x2 - radius, y2, r, g, b, a);
    mtrPrimitiveLine_rgba_f(x1, y1 + radius, x1, y2 - radius, r, g, b, a);
    mtrPrimitiveLine_rgba_f(x2, y1 + radius, x2, y2 - radius, r, g, b, a);

    mtrPrimitiveArc_rgba_f(x1 + radius, y1 + radius, radius, 90, 180, r, g, b,
     a);
    mtrPrimitiveArc_rgba_f(x1 + radius, y2 - radius, radius, 180, 270, r, g, b,
     a);
    mtrPrimitiveArc_rgba_f(x2 - radius, y1 + radius, radius, 0, 90, r, g, b, a);
    mtrPrimitiveArc_rgba_f(x2 - radius, y2 - radius, radius, 270, 360, r, g, b,
     a);
}

/*fa mtrPrimitiveRoundedRectangle_c_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangle_c_f(float x1, float y1,
 float x2, float y2, float radius, uint32_t color)
{
    mtrPrimitiveLine_c_f(x1 + radius, y1, x2 - radius, y1, color);
    mtrPrimitiveLine_c_f(x1 + radius, y2, x2 - radius, y2, color);
    mtrPrimitiveLine_c_f(x1, y1 + radius, x1, y2 - radius, color);
    mtrPrimitiveLine_c_f(x2, y1 + radius, x2, y2 - radius, color);

    mtrPrimitiveArc_c_f(x1 + radius, y1 + radius, radius, 90, 180, color);
    mtrPrimitiveArc_c_f(x1 + radius, y2 - radius, radius, 180, 270, color);
    mtrPrimitiveArc_c_f(x2 - radius, y1 + radius, radius, 0, 90, color);
    mtrPrimitiveArc_c_f(x2 - radius, y2 - radius, radius, 270, 360, color);
}

/*fa mtrPrimitiveRoundedRectangle_ca_f yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangle_ca_f(float x1, float y1,
 float x2, float y2, float radius, uint32_t color)
{
    mtrPrimitiveLine_ca_f(x1 + radius, y1, x2 - radius, y1, color);
    mtrPrimitiveLine_ca_f(x1 + radius, y2, x2 - radius, y2, color);
    mtrPrimitiveLine_ca_f(x1, y1 + radius, x1, y2 - radius, color);
    mtrPrimitiveLine_ca_f(x2, y1 + radius, x2, y2 - radius, color);

    mtrPrimitiveArc_ca_f(x1 + radius, y1 + radius, radius, 90, 180, color);
    mtrPrimitiveArc_ca_f(x1 + radius, y2 - radius, radius, 180, 270, color);
    mtrPrimitiveArc_ca_f(x2 - radius, y1 + radius, radius, 0, 90, color);
    mtrPrimitiveArc_ca_f(x2 - radius, y2 - radius, radius, 270, 360, color);
}

/*fa mtrPrimitiveRoundedRectangleFilled_rgb_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangleFilled_rgb_f(float x1,
 float y1, float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b)
{
    return;
}

/*fa mtrPrimitiveRoundedRectangleFilled_rgba_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangleFilled_rgba_f(float x1,
 float y1, float x2, float y2, float radius, uint8_t r, uint8_t g, uint8_t b,
 uint8_t a)
{
    return;
}

/*fa mtrPrimitiveRoundedRectangleFilled_c_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangleFilled_c_f(float x1,
 float y1, float x2, float y2, float radius, uint32_t color)
{
    return;
}

/*fa mtrPrimitiveRoundedRectangleFilled_ca_f dummy */
MTR_EXPORT void MTR_CALL mtrPrimitiveRoundedRectangleFilled_ca_f(float x1,
 float y1, float x2, float y2, float radius, uint32_t color)
{
    return;
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

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderDrawLine(mtrScreen->renderer, mtrLinePointX_f, mtrLinePointY_f,
     x, y);
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

    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderDrawLine(mtrScreen->renderer, mtrLinePointX_f, mtrLinePointY_f,
     x, y);
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

    if (!mtrLineDrawing)
    {
        mtrPrimitiveLineBegin_f(x, y);
        return;
    }

    r = (uint8_t)(color >> 16);
    g = (uint8_t)((color >> 8) - ((uint32_t)r << 8));
    b = (uint8_t)(color - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, 0xFF);
    SDL_RenderDrawLine(mtrScreen->renderer, mtrLinePointX_f, mtrLinePointY_f,
     x, y);
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

    if (!mtrLineDrawing)
    {
        mtrPrimitiveLineBegin_f(x, y);
        return;
    }

    r = (uint8_t)(color >> 24);
    g = (uint8_t)((color >> 16) - ((uint32_t)r << 8));
    b = (uint8_t)((color >> 8) - ((uint32_t)r << 16) - ((uint32_t)g << 8));
    a = (uint8_t)(color  - ((uint32_t)r << 24) - ((uint32_t)g << 16) -
     ((uint32_t)b << 8));
    SDL_SetRenderDrawColor(mtrScreen->renderer, r, g, b, a);
    SDL_RenderDrawLine(mtrScreen->renderer, mtrLinePointX_f, mtrLinePointY_f,
     x, y);
    mtrLinePointX_f = x;
    mtrLinePointY_f = y;
}

/*fa mtrPrimitiveLineEnd yes */
MTR_EXPORT void MTR_CALL mtrPrimitiveLineEnd(void)
{
    mtrLineDrawing = false;
}
