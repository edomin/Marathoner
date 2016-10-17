#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC(mtrSF_ColorAssembleRGB)
{
    uint8_t  r;
    uint8_t  g;
    uint8_t  b;
    uint32_t rgb;

    MTR_SF_GET_UINT8(r, 1);
    MTR_SF_GET_UINT8(g, 2);
    MTR_SF_GET_UINT8(b, 3);
    rgb = mtrColorAssembleRGB(r, g, b);

    MTR_SF_PUSH_UINT32(rgb);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_ColorAssembleRGBA)
{
    uint8_t  r;
    uint8_t  g;
    uint8_t  b;
    uint8_t  a;
    uint32_t rgba;

    MTR_SF_GET_UINT8(r, 1);
    MTR_SF_GET_UINT8(g, 2);
    MTR_SF_GET_UINT8(b, 3);
    MTR_SF_GET_UINT8(a, 3);
    rgba = mtrColorAssembleRGBA(r, g, b, a);

    MTR_SF_PUSH_UINT32(rgba);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_ColorSplitRGB)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint32_t rgb;

    MTR_SF_GET_UINT32(rgb, 1);
    mtrColorSplitRGB(rgb, &r, &g, &b);

    MTR_SF_PUSH_UINT8(r);
    MTR_SF_PUSH_UINT8(g);
    MTR_SF_PUSH_UINT8(b);

    return 3;
}

MTR_SCRIPT_FUNC(mtrSF_ColorSplitRGBA)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    uint32_t rgba;

    MTR_SF_GET_UINT32(rgba, 1);
    mtrColorSplitRGBA(rgba, &r, &g, &b, &a);

    MTR_SF_PUSH_UINT8(r);
    MTR_SF_PUSH_UINT8(g);
    MTR_SF_PUSH_UINT8(b);
    MTR_SF_PUSH_UINT8(a);

    return 4;
}

MTR_SCRIPT_FUNC(mtrSF_ColorRGBtoRGBA)
{
    uint32_t rgb;
    uint32_t rgba;

    MTR_SF_GET_UINT32(rgb, 1);
    rgba = mtrColorRGBtoRGBA(rgb);

    MTR_SF_PUSH_UINT32(rgba);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_ColorRGBAtoRGB)
{
    uint32_t rgba;
    uint32_t rgb;

    MTR_SF_GET_UINT32(rgba, 1);
    rgb = mtrColorRGBAtoRGB(rgba);

    MTR_SF_PUSH_UINT32(rgb);

    return 1;
}
