#include "color.h"

#include "marathoner/plugin_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Utils_color";
    report->version = MTR_VERSION_UTILS_COLOR;
    report->subsystem = "utils";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

MTR_EXPORT uint32_t MTR_CALL mtrColorAssembleRGB(uint8_t r, uint8_t g,
 uint8_t b)
{
    return ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
}

MTR_EXPORT uint32_t MTR_CALL mtrColorAssembleRGBA(uint8_t r, uint8_t g,
 uint8_t b, uint8_t a)
{
    return ((uint32_t)r << 24) | ((uint32_t)g << 16) | ((uint32_t)b << 8) | a;
}

MTR_EXPORT void MTR_CALL mtrColorSplitRGB(uint32_t rgb, uint8_t *r, uint8_t *g,
 uint8_t *b)
{
    *r = (uint8_t)((rgb & 0xFF0000) > 16);
    *g = (uint8_t)((rgb & 0x00FF00) > 8);
    *b = (uint8_t)(rgb & 0x0000FF);
}

MTR_EXPORT uint8_t MTR_CALL mtrColorRGBGetR(uint32_t rgb)
{
    return (rgb & 0xFF0000) >> 16;
}

MTR_EXPORT uint8_t MTR_CALL mtrColorRGBGetG(uint32_t rgb)
{
    return (rgb & 0x00FF00) >> 8;
}

MTR_EXPORT uint8_t MTR_CALL mtrColorRGBGetB(uint32_t rgb)
{
    return (rgb & 0x0000FF);
}

MTR_EXPORT uint32_t MTR_CALL mtrColorRGBSetR(uint32_t rgb, uint8_t r)
{
    return (rgb & 0x00FFFF) | (r << 16);
}

MTR_EXPORT uint32_t MTR_CALL mtrColorRGBSetG(uint32_t rgb, uint8_t g)
{
    return (rgb & 0xFF00FF) | (g << 8);
}

MTR_EXPORT uint32_t MTR_CALL mtrColorRGBSetB(uint32_t rgb, uint8_t b)
{
    return (rgb & 0xFFFF00) | b;
}

MTR_EXPORT void MTR_CALL mtrColorSplitRGBA(uint32_t rgba, uint8_t *r,
 uint8_t *g, uint8_t *b, uint8_t *a)
{
    *r = (uint8_t)((rgba & 0xFF000000) >> 24);
    *g = (uint8_t)((rgba & 0x00FF0000) >> 16);
    *b = (uint8_t)((rgba & 0x0000FF00) >> 8);
    *a = (uint8_t)(rgba & 0x000000FF);
}

MTR_EXPORT uint8_t MTR_CALL mtrColorRGBAGetR(uint32_t rgba)
{
    return (rgba & 0xFF000000) >> 24;
}

MTR_EXPORT uint8_t MTR_CALL mtrColorRGBAGetG(uint32_t rgba)
{
    return (rgba & 0x00FF0000) >> 16;
}

MTR_EXPORT uint8_t MTR_CALL mtrColorRGBAGetB(uint32_t rgba)
{
    return (rgba & 0x0000FF00) >> 8;
}

MTR_EXPORT uint8_t MTR_CALL mtrColorRGBAGetA(uint32_t rgba)
{
    return (rgba & 0x00000FF);
}

MTR_EXPORT uint32_t MTR_CALL mtrColorRGBASetR(uint32_t rgba, uint8_t r)
{
    return (rgba & 0x00FFFFFF) | (r << 24);
}

MTR_EXPORT uint32_t MTR_CALL mtrColorRGBASetG(uint32_t rgba, uint8_t g)
{
    return (rgba & 0xFF00FFFF) | (g << 16);
}

MTR_EXPORT uint32_t MTR_CALL mtrColorRGBASetB(uint32_t rgba, uint8_t b)
{
    return (rgba & 0xFFFF00FF) | (b << 8);
}

MTR_EXPORT uint32_t MTR_CALL mtrColorRGBASetA(uint32_t rgba, uint8_t a)
{
    return (rgba & 0xFFFFFF00) | a;
}

MTR_EXPORT uint32_t MTR_CALL mtrColorRGBtoRGBA(uint32_t rgb)
{
    return (rgb << 8) | 0x000000FF;
}

MTR_EXPORT uint32_t MTR_CALL mtrColorRGBAtoRGB(uint32_t rgba)
{
    return rgba >> 8;
}
