#include "color.h"

#include "marathoner/plugin_common.c"

MRT_EXPORT mtrReport* MRT_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Utils_color";
    report->version = MTR_VERSION_UTILS_COLOR;
    report->prereqsCount = 0;
    report->prereqs = NULL;
    return report;
}

MRT_EXPORT uint32_t MRT_CALL mtrColorAssembleRGB(uint8_t r, uint8_t g,
 uint8_t b)
{
    return ((uint32_t)r << 16) + ((uint32_t)g << 8) + b;
}

MRT_EXPORT uint32_t MRT_CALL mtrColorAssembleRGBA(uint8_t r, uint8_t g,
 uint8_t b, uint8_t a)
{
    return ((uint32_t)r << 24) + ((uint32_t)g << 16) + ((uint32_t)b << 8) + a;
}

MRT_EXPORT void MRT_CALL mtrColorSplitRGB(uint32_t rgb, uint8_t *r, uint8_t *g,
 uint8_t *b)
{
    *r = (uint8_t)(rgb >> 16);
    *g = (uint8_t)((rgb >> 8) - ((uint32_t)(*r) << 8));
    *b = (uint8_t)(rgb - ((uint32_t)(*r) << 16) - ((uint32_t)(*g) << 8));
}

MRT_EXPORT void MRT_CALL mtrColorSplitRGBA(uint32_t rgba, uint8_t *r,
 uint8_t *g, uint8_t *b, uint8_t *a)
{
    *r = (uint8_t)(rgba >> 24);
    *g = (uint8_t)((rgba >> 16) - ((uint32_t)(*r) << 8));
    *b = (uint8_t)((rgba >> 8) - ((uint32_t)(*r) << 16) - ((uint32_t)(*g) << 8));
    *a = (uint8_t)(rgba  - ((uint32_t)(*r) << 24) - ((uint32_t)(*g) << 16) -
     ((uint32_t)(*b) << 8));
}

MRT_EXPORT uint32_t MRT_CALL mtrColorRGBtoRGBA(uint32_t rgb)
{
    return (rgb << 8) + 0xFF;
}

MRT_EXPORT uint32_t MRT_CALL mtrColorRGBAtoRGB(uint32_t rgba)
{
    return rgba >> 8;
}

/* For COLORREF colors builded with RGB macro */
uint32_t mtrColorBGRtoRGB(uint32_t bgr)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    b = (uint8_t)(bgr >> 16);
    g = (uint8_t)((bgr >> 8) - ((uint32_t)b << 8));
    r = (uint8_t)(bgr - ((uint32_t)b << 16) - ((uint32_t)g << 8));

    return ((uint32_t)r << 16) + ((uint32_t)g << 8) + b;
}
