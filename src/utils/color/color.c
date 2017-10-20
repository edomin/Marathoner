#include "color.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Color, FA_FUNCTIONS_COUNT)

MTR_EXPORT mtrReport* MTR_CALL MTR_CreateReport(void)
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

/*fa MTR_ColorAssembleRGB yes */
MTR_EXPORT uint32_t MTR_CALL MTR_ColorAssembleRGB(uint8_t r, uint8_t g,
 uint8_t b)
{
    return ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
}

/*fa MTR_ColorAssembleRGBA yes */
MTR_EXPORT uint32_t MTR_CALL MTR_ColorAssembleRGBA(uint8_t r, uint8_t g,
 uint8_t b, uint8_t a)
{
    return ((uint32_t)r << 24) | ((uint32_t)g << 16) | ((uint32_t)b << 8) | a;
}

/*fa MTR_ColorSplitRGB yes */
MTR_EXPORT void MTR_CALL MTR_ColorSplitRGB(uint32_t rgb, uint8_t *r, uint8_t *g,
 uint8_t *b)
{
    *r = (uint8_t)((rgb & 0xFF0000) >> 16);
    *g = (uint8_t)((rgb & 0x00FF00) >> 8);
    *b = (uint8_t)(rgb & 0x0000FF);
}

/*fa MTR_ColorRGBGetR yes */
MTR_EXPORT uint8_t MTR_CALL MTR_ColorRGBGetR(uint32_t rgb)
{
    return (rgb & 0xFF0000) >> 16;
}

/*fa MTR_ColorRGBGetG yes */
MTR_EXPORT uint8_t MTR_CALL MTR_ColorRGBGetG(uint32_t rgb)
{
    return (rgb & 0x00FF00) >> 8;
}

/*fa MTR_ColorRGBGetB yes */
MTR_EXPORT uint8_t MTR_CALL MTR_ColorRGBGetB(uint32_t rgb)
{
    return (rgb & 0x0000FF);
}

/*fa MTR_ColorRGBSetR yes */
MTR_EXPORT uint32_t MTR_CALL MTR_ColorRGBSetR(uint32_t rgb, uint8_t r)
{
    return (rgb & 0x00FFFF) | (r << 16);
}

/*fa MTR_ColorRGBSetG yes */
MTR_EXPORT uint32_t MTR_CALL MTR_ColorRGBSetG(uint32_t rgb, uint8_t g)
{
    return (rgb & 0xFF00FF) | (g << 8);
}

/*fa MTR_ColorRGBSetB yes */
MTR_EXPORT uint32_t MTR_CALL MTR_ColorRGBSetB(uint32_t rgb, uint8_t b)
{
    return (rgb & 0xFFFF00) | b;
}

/*fa MTR_ColorSplitRGBA yes */
MTR_EXPORT void MTR_CALL MTR_ColorSplitRGBA(uint32_t rgba, uint8_t *r,
 uint8_t *g, uint8_t *b, uint8_t *a)
{
    *r = (uint8_t)((rgba & 0xFF000000) >> 24);
    *g = (uint8_t)((rgba & 0x00FF0000) >> 16);
    *b = (uint8_t)((rgba & 0x0000FF00) >> 8);
    *a = (uint8_t)(rgba & 0x000000FF);
}

/*fa MTR_ColorRGBAGetR yes */
MTR_EXPORT uint8_t MTR_CALL MTR_ColorRGBAGetR(uint32_t rgba)
{
    return (rgba & 0xFF000000) >> 24;
}

/*fa MTR_ColorRGBAGetG yes */
MTR_EXPORT uint8_t MTR_CALL MTR_ColorRGBAGetG(uint32_t rgba)
{
    return (rgba & 0x00FF0000) >> 16;
}

/*fa MTR_ColorRGBAGetB yes */
MTR_EXPORT uint8_t MTR_CALL MTR_ColorRGBAGetB(uint32_t rgba)
{
    return (rgba & 0x0000FF00) >> 8;
}

/*fa MTR_ColorRGBAGetA yes */
MTR_EXPORT uint8_t MTR_CALL MTR_ColorRGBAGetA(uint32_t rgba)
{
    return (rgba & 0x00000FF);
}

/*fa MTR_ColorRGBASetR yes */
MTR_EXPORT uint32_t MTR_CALL MTR_ColorRGBASetR(uint32_t rgba, uint8_t r)
{
    return (rgba & 0x00FFFFFF) | (r << 24);
}

/*fa MTR_ColorRGBASetG yes */
MTR_EXPORT uint32_t MTR_CALL MTR_ColorRGBASetG(uint32_t rgba, uint8_t g)
{
    return (rgba & 0xFF00FFFF) | (g << 16);
}

/*fa MTR_ColorRGBASetB yes */
MTR_EXPORT uint32_t MTR_CALL MTR_ColorRGBASetB(uint32_t rgba, uint8_t b)
{
    return (rgba & 0xFFFF00FF) | (b << 8);
}

/*fa MTR_ColorRGBASetA yes */
MTR_EXPORT uint32_t MTR_CALL MTR_ColorRGBASetA(uint32_t rgba, uint8_t a)
{
    return (rgba & 0xFFFFFF00) | a;
}

/*fa MTR_ColorRGBtoRGBA yes */
MTR_EXPORT uint32_t MTR_CALL MTR_ColorRGBtoRGBA(uint32_t rgb)
{
    return (rgb << 8) | 0x000000FF;
}

/*fa MTR_ColorRGBAtoRGB yes */
MTR_EXPORT uint32_t MTR_CALL MTR_ColorRGBAtoRGB(uint32_t rgba)
{
    return rgba >> 8;
}
