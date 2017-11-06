#include "color.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Color, FA_FUNCTIONS_COUNT)

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
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

/*fa MTR_ColorRgbAssemble yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_ColorRgbAssemble(uint8_t r, uint8_t g,
 uint8_t b)
{
    return ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
}

/*fa MTR_ColorRgbaAssemble yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_ColorRgbaAssemble(uint8_t r, uint8_t g,
 uint8_t b, uint8_t a)
{
    return ((uint32_t)r << 24) | ((uint32_t)g << 16) | ((uint32_t)b << 8) | a;
}

/*fa MTR_ColorRgbSplit yes */
MTR_DCLSPC void MTR_CALL MTR_ColorRgbSplit(uint32_t rgb, uint8_t *r, uint8_t *g,
 uint8_t *b)
{
    *r = (uint8_t)((rgb & 0xFF0000) >> 16);
    *g = (uint8_t)((rgb & 0x00FF00) >> 8);
    *b = (uint8_t)(rgb & 0x0000FF);
}

/*fa MTR_ColorRgbGetRed yes */
MTR_DCLSPC uint8_t MTR_CALL MTR_ColorRgbGetRed(uint32_t rgb)
{
    return (rgb & 0xFF0000) >> 16;
}

/*fa MTR_ColorRgbGetGreen yes */
MTR_DCLSPC uint8_t MTR_CALL MTR_ColorRgbGetGreen(uint32_t rgb)
{
    return (rgb & 0x00FF00) >> 8;
}

/*fa MTR_ColorRgbGetBlue yes */
MTR_DCLSPC uint8_t MTR_CALL MTR_ColorRgbGetBlue(uint32_t rgb)
{
    return (rgb & 0x0000FF);
}

/*fa MTR_ColorRgbSetRed yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_ColorRgbSetRed(uint32_t rgb, uint8_t r)
{
    return (rgb & 0x00FFFF) | (r << 16);
}

/*fa MTR_ColorRgbSetGreen yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_ColorRgbSetGreen(uint32_t rgb, uint8_t g)
{
    return (rgb & 0xFF00FF) | (g << 8);
}

/*fa MTR_ColorRgbSetBlue yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_ColorRgbSetBlue(uint32_t rgb, uint8_t b)
{
    return (rgb & 0xFFFF00) | b;
}

/*fa MTR_ColorRgbaSplit yes */
MTR_DCLSPC void MTR_CALL MTR_ColorRgbaSplit(uint32_t rgba, uint8_t *r,
 uint8_t *g, uint8_t *b, uint8_t *a)
{
    *r = (uint8_t)((rgba & 0xFF000000) >> 24);
    *g = (uint8_t)((rgba & 0x00FF0000) >> 16);
    *b = (uint8_t)((rgba & 0x0000FF00) >> 8);
    *a = (uint8_t)(rgba & 0x000000FF);
}

/*fa MTR_ColorRgbaGetRed yes */
MTR_DCLSPC uint8_t MTR_CALL MTR_ColorRgbaGetRed(uint32_t rgba)
{
    return (rgba & 0xFF000000) >> 24;
}

/*fa MTR_ColorRgbaGetGreen yes */
MTR_DCLSPC uint8_t MTR_CALL MTR_ColorRgbaGetGreen(uint32_t rgba)
{
    return (rgba & 0x00FF0000) >> 16;
}

/*fa MTR_ColorRgbaGetBlue yes */
MTR_DCLSPC uint8_t MTR_CALL MTR_ColorRgbaGetBlue(uint32_t rgba)
{
    return (rgba & 0x0000FF00) >> 8;
}

/*fa MTR_ColorRgbaGetAlpha yes */
MTR_DCLSPC uint8_t MTR_CALL MTR_ColorRgbaGetAlpha(uint32_t rgba)
{
    return (rgba & 0x00000FF);
}

/*fa MTR_ColorRgbaSetRed yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_ColorRgbaSetRed(uint32_t rgba, uint8_t r)
{
    return (rgba & 0x00FFFFFF) | (r << 24);
}

/*fa MTR_ColorRgbaSetGreen yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_ColorRgbaSetGreen(uint32_t rgba, uint8_t g)
{
    return (rgba & 0xFF00FFFF) | (g << 16);
}

/*fa MTR_ColorRgbaSetBlue yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_ColorRgbaSetBlue(uint32_t rgba, uint8_t b)
{
    return (rgba & 0xFFFF00FF) | (b << 8);
}

/*fa MTR_ColorRgbaSetAlpha yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_ColorRgbaSetAlpha(uint32_t rgba, uint8_t a)
{
    return (rgba & 0xFFFFFF00) | a;
}

/*fa MTR_ColorRgbToRgba yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_ColorRgbToRgba(uint32_t rgb)
{
    return (rgb << 8) | 0x000000FF;
}

/*fa MTR_ColorRgbaToRgb yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_ColorRgbaToRgb(uint32_t rgba)
{
    return rgba >> 8;
}
