#ifndef MTR_PRIMITIVE_BINDING_COMMON_C
#define MTR_PRIMITIVE_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC(mtrSF_PrimitiveInit)
{
    bool success;

    success = mtrPrimitiveInit();

    MTR_SF_PUSH_BOOL(success);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveFill_rgb)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;

    MTR_SF_GET_UINT8(r, 1);
    MTR_SF_GET_UINT8(g, 2);
    MTR_SF_GET_UINT8(b, 3);
    mtrPrimitiveFill_rgb(r, g, b);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveFill_rgba)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    MTR_SF_GET_UINT8(r, 1);
    MTR_SF_GET_UINT8(g, 2);
    MTR_SF_GET_UINT8(b, 3);
    MTR_SF_GET_UINT8(a, 4);
    mtrPrimitiveFill_rgba(r, g, b, a);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveFill_c)
{
    uint32_t color;

    MTR_SF_GET_UINT32(color, 1);
    mtrPrimitiveFill_c(color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveFill_ca)
{
    uint32_t color;

    MTR_SF_GET_UINT32(color, 1);
    mtrPrimitiveFill_ca(color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitivePixel_rgb_f)
{
    float   x;
    float   y;
    uint8_t r;
    uint8_t g;
    uint8_t b;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_UINT8(r, 3);
    MTR_SF_GET_UINT8(g, 4);
    MTR_SF_GET_UINT8(b, 5);
    mtrPrimitivePixel_rgb_f(x, y, r, g, b);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitivePixel_rgba_f)
{
    float   x;
    float   y;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_UINT8(r, 3);
    MTR_SF_GET_UINT8(g, 4);
    MTR_SF_GET_UINT8(b, 5);
    MTR_SF_GET_UINT8(a, 6);
    mtrPrimitivePixel_rgba_f(x, y, r, g, b, a);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitivePixel_c_f)
{
    float    x;
    float    y;
    uint32_t color;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_UINT32(color, 3);
    mtrPrimitivePixel_c_f(x, y, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitivePixel_ca_f)
{
    float    x;
    float    y;
    uint32_t color;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_UINT32(color, 3);
    mtrPrimitivePixel_ca_f(x, y, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveLine_rgb_f)
{
    float   x1;
    float   y1;
    float   x2;
    float   y2;
    uint8_t r;
    uint8_t g;
    uint8_t b;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_UINT8(r, 5);
    MTR_SF_GET_UINT8(g, 6);
    MTR_SF_GET_UINT8(b, 7);
    mtrPrimitiveLine_rgb_f(x1, y1, x2, y2, r, g, b);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveLine_rgba_f)
{
    float   x1;
    float   y1;
    float   x2;
    float   y2;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_UINT8(r, 5);
    MTR_SF_GET_UINT8(g, 6);
    MTR_SF_GET_UINT8(b, 7);
    MTR_SF_GET_UINT8(a, 8);
    mtrPrimitiveLine_rgba_f(x1, y1, x2, y2, r, g, b, a);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveLine_c_f)
{
    float    x1;
    float    y1;
    float    x2;
    float    y2;
    uint32_t color;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_UINT32(color, 5);
    mtrPrimitiveLine_c_f(x1, y1, x2, y2, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveLine_ca_f)
{
    float    x1;
    float    y1;
    float    x2;
    float    y2;
    uint32_t color;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_UINT32(color, 5);
    mtrPrimitiveLine_ca_f(x1, y1, x2, y2, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveArc_rgb_f)
{
    float   x;
    float   y;
    float   radius;
    float   startAngle;
    float   endAngle;
    uint8_t r;
    uint8_t g;
    uint8_t b;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(radius, 3);
    MTR_SF_GET_SINGLE(startAngle, 4);
    MTR_SF_GET_SINGLE(endAngle, 5);
    MTR_SF_GET_UINT8(r, 6);
    MTR_SF_GET_UINT8(g, 7);
    MTR_SF_GET_UINT8(b, 8);
    mtrPrimitiveArc_rgb_f(x, y, radius, startAngle, endAngle, r, g, b);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveArc_rgba_f)
{
    float   x;
    float   y;
    float   radius;
    float   startAngle;
    float   endAngle;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(radius, 3);
    MTR_SF_GET_SINGLE(startAngle, 4);
    MTR_SF_GET_SINGLE(endAngle, 5);
    MTR_SF_GET_UINT8(r, 6);
    MTR_SF_GET_UINT8(g, 7);
    MTR_SF_GET_UINT8(b, 8);
    MTR_SF_GET_UINT8(a, 9);
    mtrPrimitiveArc_rgba_f(x, y, radius, startAngle, endAngle, r, g, b, a);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveArc_c_f)
{
    float    x;
    float    y;
    float    radius;
    float    startAngle;
    float    endAngle;
    uint32_t color;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(radius, 3);
    MTR_SF_GET_SINGLE(startAngle, 4);
    MTR_SF_GET_SINGLE(endAngle, 5);
    MTR_SF_GET_UINT32(color, 6);
    mtrPrimitiveArc_c_f(x, y, radius, startAngle, endAngle, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveArc_ca_f)
{
    float    x;
    float    y;
    float    radius;
    float    startAngle;
    float    endAngle;
    uint32_t color;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(radius, 3);
    MTR_SF_GET_SINGLE(startAngle, 4);
    MTR_SF_GET_SINGLE(endAngle, 5);
    MTR_SF_GET_UINT32(color, 6);
    mtrPrimitiveArc_ca_f(x, y, radius, startAngle, endAngle, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveSegmentFilled_rgb_f)
{
    float   x;
    float   y;
    float   radius;
    float   startAngle;
    float   endAngle;
    uint8_t r;
    uint8_t g;
    uint8_t b;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(radius, 3);
    MTR_SF_GET_SINGLE(startAngle, 4);
    MTR_SF_GET_SINGLE(endAngle, 5);
    MTR_SF_GET_UINT8(r, 6);
    MTR_SF_GET_UINT8(g, 7);
    MTR_SF_GET_UINT8(b, 8);
    mtrPrimitiveSegmentFilled_rgb_f(x, y, radius, startAngle, endAngle, r, g,
     b);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveSegmentFilled_rgba_f)
{
    float   x;
    float   y;
    float   radius;
    float   startAngle;
    float   endAngle;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(radius, 3);
    MTR_SF_GET_SINGLE(startAngle, 4);
    MTR_SF_GET_SINGLE(endAngle, 5);
    MTR_SF_GET_UINT8(r, 6);
    MTR_SF_GET_UINT8(g, 7);
    MTR_SF_GET_UINT8(b, 8);
    MTR_SF_GET_UINT8(a, 9);
    mtrPrimitiveSegmentFilled_rgba_f(x, y, radius, startAngle, endAngle, r, g,
     b, a);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveSegmentFilled_c_f)
{
    float    x;
    float    y;
    float    radius;
    float    startAngle;
    float    endAngle;
    uint32_t color;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(radius, 3);
    MTR_SF_GET_SINGLE(startAngle, 4);
    MTR_SF_GET_SINGLE(endAngle, 5);
    MTR_SF_GET_UINT32(color, 6);
    mtrPrimitiveSegmentFilled_c_f(x, y, radius, startAngle, endAngle, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveSegmentFilled_ca_f)
{
    float    x;
    float    y;
    float    radius;
    float    startAngle;
    float    endAngle;
    uint32_t color;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(radius, 3);
    MTR_SF_GET_SINGLE(startAngle, 4);
    MTR_SF_GET_SINGLE(endAngle, 5);
    MTR_SF_GET_UINT32(color, 6);
    mtrPrimitiveSegmentFilled_ca_f(x, y, radius, startAngle, endAngle, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveCircle_rgb_f)
{
    float   x;
    float   y;
    float   radius;
    uint8_t r;
    uint8_t g;
    uint8_t b;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(radius, 3);
    MTR_SF_GET_UINT8(r, 4);
    MTR_SF_GET_UINT8(g, 5);
    MTR_SF_GET_UINT8(b, 6);
    mtrPrimitiveCircle_rgb_f(x, y, radius, r, g, b);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveCircle_rgba_f)
{
    float   x;
    float   y;
    float   radius;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(radius, 3);
    MTR_SF_GET_UINT8(r, 4);
    MTR_SF_GET_UINT8(g, 5);
    MTR_SF_GET_UINT8(b, 6);
    MTR_SF_GET_UINT8(a, 7);
    mtrPrimitiveCircle_rgba_f(x, y, radius, r, g, b, a);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveCircle_c_f)
{
    float    x;
    float    y;
    float    radius;
    uint32_t color;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(radius, 3);
    MTR_SF_GET_UINT32(color, 4);
    mtrPrimitiveCircle_c_f(x, y, radius, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveCircle_ca_f)
{
    float    x;
    float    y;
    float    radius;
    uint32_t color;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(radius, 3);
    MTR_SF_GET_UINT32(color, 4);
    mtrPrimitiveCircle_ca_f(x, y, radius, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveCircleFilled_rgb_f)
{
    float   x;
    float   y;
    float   radius;
    uint8_t r;
    uint8_t g;
    uint8_t b;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(radius, 3);
    MTR_SF_GET_UINT8(r, 4);
    MTR_SF_GET_UINT8(g, 5);
    MTR_SF_GET_UINT8(b, 6);
    mtrPrimitiveCircleFilled_rgb_f(x, y, radius, r, g, b);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveCircleFilled_rgba_f)
{
    float   x;
    float   y;
    float   radius;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(radius, 3);
    MTR_SF_GET_UINT8(r, 4);
    MTR_SF_GET_UINT8(g, 5);
    MTR_SF_GET_UINT8(b, 6);
    MTR_SF_GET_UINT8(a, 7);
    mtrPrimitiveCircleFilled_rgba_f(x, y, radius, r, g, b, a);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveCircleFilled_c_f)
{
    float    x;
    float    y;
    float    radius;
    uint32_t color;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(radius, 3);
    MTR_SF_GET_UINT32(color, 4);
    mtrPrimitiveCircleFilled_c_f(x, y, radius, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveCircleFilled_ca_f)
{
    float    x;
    float    y;
    float    radius;
    uint32_t color;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(radius, 3);
    MTR_SF_GET_UINT32(color, 4);
    mtrPrimitiveCircleFilled_ca_f(x, y, radius, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveEllipse_rgb_f)
{
    float   x;
    float   y;
    float   rx;
    float   ry;
    float   angle;
    uint8_t r;
    uint8_t g;
    uint8_t b;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(rx, 3);
    MTR_SF_GET_SINGLE(ry, 4);
    MTR_SF_GET_SINGLE(angle, 5);
    MTR_SF_GET_UINT8(r, 6);
    MTR_SF_GET_UINT8(g, 7);
    MTR_SF_GET_UINT8(b, 8);
    mtrPrimitiveEllipse_rgb_f(x, y, rx, ry, angle, r, g, b);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveEllipse_rgba_f)
{
    float   x;
    float   y;
    float   rx;
    float   ry;
    float   angle;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(rx, 3);
    MTR_SF_GET_SINGLE(ry, 4);
    MTR_SF_GET_SINGLE(angle, 5);
    MTR_SF_GET_UINT8(r, 6);
    MTR_SF_GET_UINT8(g, 7);
    MTR_SF_GET_UINT8(b, 8);
    MTR_SF_GET_UINT8(a, 9);
    mtrPrimitiveEllipse_rgba_f(x, y, rx, ry, angle, r, g, b, a);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveEllipse_c_f)
{
    float    x;
    float    y;
    float    rx;
    float    ry;
    float    angle;
    uint32_t color;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(rx, 3);
    MTR_SF_GET_SINGLE(ry, 4);
    MTR_SF_GET_SINGLE(angle, 5);
    MTR_SF_GET_UINT32(color, 6);
    mtrPrimitiveEllipse_c_f(x, y, rx, ry, angle, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveEllipse_ca_f)
{
    float    x;
    float    y;
    float    rx;
    float    ry;
    float    angle;
    uint32_t color;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(rx, 3);
    MTR_SF_GET_SINGLE(ry, 4);
    MTR_SF_GET_SINGLE(angle, 5);
    MTR_SF_GET_UINT32(color, 6);
    mtrPrimitiveEllipse_ca_f(x, y, rx, ry, angle, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveEllipseFilled_rgb_f)
{
    float   x;
    float   y;
    float   rx;
    float   ry;
    float   angle;
    uint8_t r;
    uint8_t g;
    uint8_t b;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(rx, 3);
    MTR_SF_GET_SINGLE(ry, 4);
    MTR_SF_GET_SINGLE(angle, 5);
    MTR_SF_GET_UINT8(r, 6);
    MTR_SF_GET_UINT8(g, 7);
    MTR_SF_GET_UINT8(b, 8);
    mtrPrimitiveEllipseFilled_rgb_f(x, y, rx, ry, angle, r, g, b);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveEllipseFilled_rgba_f)
{
    float   x;
    float   y;
    float   rx;
    float   ry;
    float   angle;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(rx, 3);
    MTR_SF_GET_SINGLE(ry, 4);
    MTR_SF_GET_SINGLE(angle, 5);
    MTR_SF_GET_UINT8(r, 6);
    MTR_SF_GET_UINT8(g, 7);
    MTR_SF_GET_UINT8(b, 8);
    MTR_SF_GET_UINT8(a, 9);
    mtrPrimitiveEllipseFilled_rgba_f(x, y, rx, ry, angle, r, g, b, a);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveEllipseFilled_c_f)
{
    float    x;
    float    y;
    float    rx;
    float    ry;
    float    angle;
    uint32_t color;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(rx, 3);
    MTR_SF_GET_SINGLE(ry, 4);
    MTR_SF_GET_SINGLE(angle, 5);
    MTR_SF_GET_UINT32(color, 6);
    mtrPrimitiveEllipseFilled_c_f(x, y, rx, ry, angle, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveEllipseFilled_ca_f)
{
    float    x;
    float    y;
    float    rx;
    float    ry;
    float    angle;
    uint32_t color;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(rx, 3);
    MTR_SF_GET_SINGLE(ry, 4);
    MTR_SF_GET_SINGLE(angle, 5);
    MTR_SF_GET_UINT32(color, 6);
    mtrPrimitiveEllipseFilled_ca_f(x, y, rx, ry, angle, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRingSegment_rgb_f)
{
    float   x;
    float   y;
    float   innerRadius;
    float   outerRadius;
    float   startAngle;
    float   endAngle;
    uint8_t r;
    uint8_t g;
    uint8_t b;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(innerRadius, 3);
    MTR_SF_GET_SINGLE(outerRadius, 4);
    MTR_SF_GET_SINGLE(startAngle, 5);
    MTR_SF_GET_SINGLE(endAngle, 6);
    MTR_SF_GET_UINT8(r, 7);
    MTR_SF_GET_UINT8(g, 8);
    MTR_SF_GET_UINT8(b, 9);
    mtrPrimitiveRingSegment_rgb_f(x, y, innerRadius, outerRadius, startAngle,
     endAngle, r, g, b);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRingSegment_rgba_f)
{
    float   x;
    float   y;
    float   innerRadius;
    float   outerRadius;
    float   startAngle;
    float   endAngle;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(innerRadius, 3);
    MTR_SF_GET_SINGLE(outerRadius, 4);
    MTR_SF_GET_SINGLE(startAngle, 5);
    MTR_SF_GET_SINGLE(endAngle, 6);
    MTR_SF_GET_UINT8(r, 7);
    MTR_SF_GET_UINT8(g, 8);
    MTR_SF_GET_UINT8(b, 9);
    MTR_SF_GET_UINT8(a, 10);
    mtrPrimitiveRingSegment_rgba_f(x, y, innerRadius, outerRadius, startAngle,
     endAngle, r, g, b, a);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRingSegment_c_f)
{
    float    x;
    float    y;
    float    innerRadius;
    float    outerRadius;
    float    startAngle;
    float    endAngle;
    uint32_t color;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(innerRadius, 3);
    MTR_SF_GET_SINGLE(outerRadius, 4);
    MTR_SF_GET_SINGLE(startAngle, 5);
    MTR_SF_GET_SINGLE(endAngle, 6);
    MTR_SF_GET_UINT32(color, 7);
    mtrPrimitiveRingSegment_c_f(x, y, innerRadius, outerRadius, startAngle,
     endAngle, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRingSegment_ca_f)
{
    float    x;
    float    y;
    float    innerRadius;
    float    outerRadius;
    float    startAngle;
    float    endAngle;
    uint32_t color;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(innerRadius, 3);
    MTR_SF_GET_SINGLE(outerRadius, 4);
    MTR_SF_GET_SINGLE(startAngle, 5);
    MTR_SF_GET_SINGLE(endAngle, 6);
    MTR_SF_GET_UINT32(color, 7);
    mtrPrimitiveRingSegment_ca_f(x, y, innerRadius, outerRadius, startAngle,
     endAngle, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRingSegmentFilled_rgb_f)
{
    float   x;
    float   y;
    float   innerRadius;
    float   outerRadius;
    float   startAngle;
    float   endAngle;
    uint8_t r;
    uint8_t g;
    uint8_t b;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(innerRadius, 3);
    MTR_SF_GET_SINGLE(outerRadius, 4);
    MTR_SF_GET_SINGLE(startAngle, 5);
    MTR_SF_GET_SINGLE(endAngle, 6);
    MTR_SF_GET_UINT8(r, 7);
    MTR_SF_GET_UINT8(g, 8);
    MTR_SF_GET_UINT8(b, 9);
    mtrPrimitiveRingSegmentFilled_rgb_f(x, y, innerRadius, outerRadius,
     startAngle, endAngle, r, g, b);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRingSegmentFilled_rgba_f)
{
    float   x;
    float   y;
    float   innerRadius;
    float   outerRadius;
    float   startAngle;
    float   endAngle;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(innerRadius, 3);
    MTR_SF_GET_SINGLE(outerRadius, 4);
    MTR_SF_GET_SINGLE(startAngle, 5);
    MTR_SF_GET_SINGLE(endAngle, 6);
    MTR_SF_GET_UINT8(r, 7);
    MTR_SF_GET_UINT8(g, 8);
    MTR_SF_GET_UINT8(b, 9);
    MTR_SF_GET_UINT8(a, 10);
    mtrPrimitiveRingSegmentFilled_rgba_f(x, y, innerRadius, outerRadius,
     startAngle, endAngle, r, g, b, a);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRingSegmentFilled_c_f)
{
    float    x;
    float    y;
    float    innerRadius;
    float    outerRadius;
    float    startAngle;
    float    endAngle;
    uint32_t color;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(innerRadius, 3);
    MTR_SF_GET_SINGLE(outerRadius, 4);
    MTR_SF_GET_SINGLE(startAngle, 5);
    MTR_SF_GET_SINGLE(endAngle, 6);
    MTR_SF_GET_UINT32(color, 7);
    mtrPrimitiveRingSegmentFilled_c_f(x, y, innerRadius, outerRadius,
     startAngle, endAngle, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRingSegmentFilled_ca_f)
{
    float    x;
    float    y;
    float    innerRadius;
    float    outerRadius;
    float    startAngle;
    float    endAngle;
    uint32_t color;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_SINGLE(innerRadius, 3);
    MTR_SF_GET_SINGLE(outerRadius, 4);
    MTR_SF_GET_SINGLE(startAngle, 5);
    MTR_SF_GET_SINGLE(endAngle, 6);
    MTR_SF_GET_UINT32(color, 7);
    mtrPrimitiveRingSegmentFilled_ca_f(x, y, innerRadius, outerRadius,
     startAngle, endAngle, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveTriangle_rgb_f)
{
    float   x1;
    float   y1;
    float   x2;
    float   y2;
    float   x3;
    float   y3;
    uint8_t r;
    uint8_t g;
    uint8_t b;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_SINGLE(x3, 5);
    MTR_SF_GET_SINGLE(y3, 6);
    MTR_SF_GET_UINT8(r, 7);
    MTR_SF_GET_UINT8(g, 8);
    MTR_SF_GET_UINT8(b, 9);
    mtrPrimitiveTriangle_rgb_f(x1, y1, x2, y2, x3, y3, r, g, b);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveTriangle_rgba_f)
{
    float   x1;
    float   y1;
    float   x2;
    float   y2;
    float   x3;
    float   y3;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_SINGLE(x3, 5);
    MTR_SF_GET_SINGLE(y3, 6);
    MTR_SF_GET_UINT8(r, 7);
    MTR_SF_GET_UINT8(g, 8);
    MTR_SF_GET_UINT8(b, 9);
    MTR_SF_GET_UINT8(a, 10);
    mtrPrimitiveTriangle_rgba_f(x1, y1, x2, y2, x3, y3, r, g, b, a);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveTriangle_c_f)
{
    float    x1;
    float    y1;
    float    x2;
    float    y2;
    float    x3;
    float    y3;
    uint32_t color;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_SINGLE(x3, 5);
    MTR_SF_GET_SINGLE(y3, 6);
    MTR_SF_GET_UINT32(color, 7);
    mtrPrimitiveTriangle_c_f(x1, y1, x2, y2, x3, y3, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveTriangle_ca_f)
{
    float    x1;
    float    y1;
    float    x2;
    float    y2;
    float    x3;
    float    y3;
    uint32_t color;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_SINGLE(x3, 5);
    MTR_SF_GET_SINGLE(y3, 6);
    MTR_SF_GET_UINT32(color, 7);
    mtrPrimitiveTriangle_ca_f(x1, y1, x2, y2, x3, y3, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveTriangleFilled_rgb_f)
{
    float   x1;
    float   y1;
    float   x2;
    float   y2;
    float   x3;
    float   y3;
    uint8_t r;
    uint8_t g;
    uint8_t b;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_SINGLE(x3, 5);
    MTR_SF_GET_SINGLE(y3, 6);
    MTR_SF_GET_UINT8(r, 7);
    MTR_SF_GET_UINT8(g, 8);
    MTR_SF_GET_UINT8(b, 9);
    mtrPrimitiveTriangleFilled_rgb_f(x1, y1, x2, y2, x3, y3, r, g, b);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveTriangleFilled_rgba_f)
{
    float   x1;
    float   y1;
    float   x2;
    float   y2;
    float   x3;
    float   y3;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_SINGLE(x3, 5);
    MTR_SF_GET_SINGLE(y3, 6);
    MTR_SF_GET_UINT8(r, 7);
    MTR_SF_GET_UINT8(g, 8);
    MTR_SF_GET_UINT8(b, 9);
    MTR_SF_GET_UINT8(a, 10);
    mtrPrimitiveTriangleFilled_rgba_f(x1, y1, x2, y2, x3, y3, r, g, b, a);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveTriangleFilled_c_f)
{
    float    x1;
    float    y1;
    float    x2;
    float    y2;
    float    x3;
    float    y3;
    uint32_t color;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_SINGLE(x3, 5);
    MTR_SF_GET_SINGLE(y3, 6);
    MTR_SF_GET_UINT32(color, 7);
    mtrPrimitiveTriangleFilled_c_f(x1, y1, x2, y2, x3, y3, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveTriangleFilled_ca_f)
{
    float    x1;
    float    y1;
    float    x2;
    float    y2;
    float    x3;
    float    y3;
    uint32_t color;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_SINGLE(x3, 5);
    MTR_SF_GET_SINGLE(y3, 6);
    MTR_SF_GET_UINT32(color, 7);
    mtrPrimitiveTriangleFilled_ca_f(x1, y1, x2, y2, x3, y3, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRectangle_rgb_f)
{
    float   x1;
    float   y1;
    float   x2;
    float   y2;
    uint8_t r;
    uint8_t g;
    uint8_t b;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_UINT8(r, 5);
    MTR_SF_GET_UINT8(g, 6);
    MTR_SF_GET_UINT8(b, 7);
    mtrPrimitiveRectangle_rgb_f(x1, y1, x2, y2, r, g, b);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRectangle_rgba_f)
{
    float   x1;
    float   y1;
    float   x2;
    float   y2;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_UINT8(r, 5);
    MTR_SF_GET_UINT8(g, 6);
    MTR_SF_GET_UINT8(b, 7);
    MTR_SF_GET_UINT8(a, 8);
    mtrPrimitiveRectangle_rgba_f(x1, y1, x2, y2, r, g, b, a);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRectangle_c_f)
{
    float    x1;
    float    y1;
    float    x2;
    float    y2;
    uint32_t color;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_UINT32(color, 5);
    mtrPrimitiveRectangle_c_f(x1, y1, x2, y2, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRectangle_ca_f)
{
    float    x1;
    float    y1;
    float    x2;
    float    y2;
    uint32_t color;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_UINT32(color, 5);
    mtrPrimitiveRectangle_ca_f(x1, y1, x2, y2, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRectangleFilled_rgb_f)
{
    float   x1;
    float   y1;
    float   x2;
    float   y2;
    uint8_t r;
    uint8_t g;
    uint8_t b;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_UINT8(r, 5);
    MTR_SF_GET_UINT8(g, 6);
    MTR_SF_GET_UINT8(b, 7);
    mtrPrimitiveRectangleFilled_rgb_f(x1, y1, x2, y2, r, g, b);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRectangleFilled_rgba_f)
{
    float   x1;
    float   y1;
    float   x2;
    float   y2;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_UINT8(r, 5);
    MTR_SF_GET_UINT8(g, 6);
    MTR_SF_GET_UINT8(b, 7);
    MTR_SF_GET_UINT8(a, 8);
    mtrPrimitiveRectangleFilled_rgba_f(x1, y1, x2, y2, r, g, b, a);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRectangleFilled_c_f)
{
    float    x1;
    float    y1;
    float    x2;
    float    y2;
    uint32_t color;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_UINT32(color, 5);
    mtrPrimitiveRectangleFilled_c_f(x1, y1, x2, y2, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRectangleFilled_ca_f)
{
    float    x1;
    float    y1;
    float    x2;
    float    y2;
    uint32_t color;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_UINT32(color, 5);
    mtrPrimitiveRectangleFilled_ca_f(x1, y1, x2, y2, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRoundedRectangle_rgb_f)
{
    float   x1;
    float   y1;
    float   x2;
    float   y2;
    float   radius;
    uint8_t r;
    uint8_t g;
    uint8_t b;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_SINGLE(radius, 5);
    MTR_SF_GET_UINT8(r, 6);
    MTR_SF_GET_UINT8(g, 7);
    MTR_SF_GET_UINT8(b, 8);
    mtrPrimitiveRoundedRectangle_rgb_f(x1, y1, x2, y2, radius, r, g, b);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRoundedRectangle_rgba_f)
{
    float   x1;
    float   y1;
    float   x2;
    float   y2;
    float   radius;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_SINGLE(radius, 5);
    MTR_SF_GET_UINT8(r, 6);
    MTR_SF_GET_UINT8(g, 7);
    MTR_SF_GET_UINT8(b, 8);
    MTR_SF_GET_UINT8(a, 9);
    mtrPrimitiveRoundedRectangle_rgba_f(x1, y1, x2, y2, radius, r, g, b, a);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRoundedRectangle_c_f)
{
    float    x1;
    float    y1;
    float    x2;
    float    y2;
    float    radius;
    uint32_t color;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_SINGLE(radius, 5);
    MTR_SF_GET_UINT32(color, 6);
    mtrPrimitiveRoundedRectangle_c_f(x1, y1, x2, y2, radius, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRoundedRectangle_ca_f)
{
    float    x1;
    float    y1;
    float    x2;
    float    y2;
    float    radius;
    uint32_t color;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_SINGLE(radius, 5);
    MTR_SF_GET_UINT32(color, 6);
    mtrPrimitiveRoundedRectangle_ca_f(x1, y1, x2, y2, radius, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRoundedRectangleFilled_rgb_f)
{
    float   x1;
    float   y1;
    float   x2;
    float   y2;
    float   radius;
    uint8_t r;
    uint8_t g;
    uint8_t b;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_SINGLE(radius, 5);
    MTR_SF_GET_UINT8(r, 6);
    MTR_SF_GET_UINT8(g, 7);
    MTR_SF_GET_UINT8(b, 8);
    mtrPrimitiveRoundedRectangleFilled_rgb_f(x1, y1, x2, y2, radius, r, g, b);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRoundedRectangleFilled_rgba_f)
{
    float   x1;
    float   y1;
    float   x2;
    float   y2;
    float   radius;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_SINGLE(radius, 5);
    MTR_SF_GET_UINT8(r, 6);
    MTR_SF_GET_UINT8(g, 7);
    MTR_SF_GET_UINT8(b, 8);
    MTR_SF_GET_UINT8(a, 9);
    mtrPrimitiveRoundedRectangleFilled_rgba_f(x1, y1, x2, y2, radius, r, g, b,
     a);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRoundedRectangleFilled_c_f)
{
    float    x1;
    float    y1;
    float    x2;
    float    y2;
    float    radius;
    uint32_t color;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_SINGLE(radius, 5);
    MTR_SF_GET_UINT32(color, 6);
    mtrPrimitiveRoundedRectangleFilled_c_f(x1, y1, x2, y2, radius, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveRoundedRectangleFilled_ca_f)
{
    float    x1;
    float    y1;
    float    x2;
    float    y2;
    float    radius;
    uint32_t color;

    MTR_SF_GET_SINGLE(x1, 1);
    MTR_SF_GET_SINGLE(y1, 2);
    MTR_SF_GET_SINGLE(x2, 3);
    MTR_SF_GET_SINGLE(y2, 4);
    MTR_SF_GET_SINGLE(radius, 5);
    MTR_SF_GET_UINT32(color, 6);
    mtrPrimitiveRoundedRectangleFilled_ca_f(x1, y1, x2, y2, radius, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveLineBegin_f)
{
    float x;
    float y;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    mtrPrimitiveLineBegin_f(x, y);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveLineTo_rgb_f)
{
    float x;
    float y;
    uint8_t r;
    uint8_t g;
    uint8_t b;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_UINT8(r, 3);
    MTR_SF_GET_UINT8(g, 4);
    MTR_SF_GET_UINT8(b, 5);
    mtrPrimitiveLineTo_rgb_f(x, y, r, g, b);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveLineTo_rgba_f)
{
    float x;
    float y;
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_UINT8(r, 3);
    MTR_SF_GET_UINT8(g, 4);
    MTR_SF_GET_UINT8(b, 5);
    MTR_SF_GET_UINT8(a, 6);
    mtrPrimitiveLineTo_rgba_f(x, y, r, g, b, a);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveLineTo_c_f)
{
    float x;
    float y;
    uint32_t color;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_UINT32(color, 3);
    mtrPrimitiveLineTo_c_f(x, y, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveLineTo_ca_f)
{
    float x;
    float y;
    uint32_t color;

    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    MTR_SF_GET_UINT32(color, 3);
    mtrPrimitiveLineTo_ca_f(x, y, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_PrimitiveLineEnd)
{
    mtrPrimitiveLineEnd();

    return 0;
}

void mtrScriptsRegisterAll(void)
{
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();

    MTR_FIND_FUNCTION(mtrPrimitiveInit, MTR_SOURCE_MODULE);

    /* Fill */
    MTR_FIND_FUNCTION(mtrPrimitiveFill_rgb, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveFill_rgba, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveFill_c, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveFill_ca, MTR_SOURCE_MODULE);

    /* Pixel */
    MTR_FIND_FUNCTION(mtrPrimitivePixel_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitivePixel_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitivePixel_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitivePixel_ca_f, MTR_SOURCE_MODULE);

    /* Line */
    MTR_FIND_FUNCTION(mtrPrimitiveLine_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveLine_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveLine_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveLine_ca_f, MTR_SOURCE_MODULE);

    /* Arc */
    MTR_FIND_FUNCTION(mtrPrimitiveArc_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveArc_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveArc_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveArc_ca_f, MTR_SOURCE_MODULE);

    /* SegmentFilled */
    MTR_FIND_FUNCTION(mtrPrimitiveSegmentFilled_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveSegmentFilled_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveSegmentFilled_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveSegmentFilled_ca_f, MTR_SOURCE_MODULE);

    /* Circle */
    MTR_FIND_FUNCTION(mtrPrimitiveCircle_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveCircle_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveCircle_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveCircle_ca_f, MTR_SOURCE_MODULE);

    /* CircleFilled */
    MTR_FIND_FUNCTION(mtrPrimitiveCircleFilled_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveCircleFilled_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveCircleFilled_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveCircleFilled_ca_f, MTR_SOURCE_MODULE);

    /* Ellipse */
    MTR_FIND_FUNCTION(mtrPrimitiveEllipse_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveEllipse_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveEllipse_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveEllipse_ca_f, MTR_SOURCE_MODULE);

    /* EllipseFilled */
    MTR_FIND_FUNCTION(mtrPrimitiveEllipseFilled_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveEllipseFilled_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveEllipseFilled_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveEllipseFilled_ca_f, MTR_SOURCE_MODULE);

    /* RingSegment */
    MTR_FIND_FUNCTION(mtrPrimitiveRingSegment_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRingSegment_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRingSegment_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRingSegment_ca_f, MTR_SOURCE_MODULE);

    /* RingSegmentFilled */
    MTR_FIND_FUNCTION(mtrPrimitiveRingSegmentFilled_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRingSegmentFilled_rgba_f,
     MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRingSegmentFilled_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRingSegmentFilled_ca_f, MTR_SOURCE_MODULE);

    /* Triangle */
    MTR_FIND_FUNCTION(mtrPrimitiveTriangle_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveTriangle_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveTriangle_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveTriangle_ca_f, MTR_SOURCE_MODULE);

    /* TriangleFilled */
    MTR_FIND_FUNCTION(mtrPrimitiveTriangleFilled_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveTriangleFilled_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveTriangleFilled_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveTriangleFilled_ca_f, MTR_SOURCE_MODULE);

    /* Rectangle */
    MTR_FIND_FUNCTION(mtrPrimitiveRectangle_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRectangle_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRectangle_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRectangle_ca_f, MTR_SOURCE_MODULE);

    /* RectangleFilled */
    MTR_FIND_FUNCTION(mtrPrimitiveRectangleFilled_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRectangleFilled_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRectangleFilled_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRectangleFilled_ca_f, MTR_SOURCE_MODULE);

    /* RoundedRectangle */
    MTR_FIND_FUNCTION(mtrPrimitiveRoundedRectangle_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRoundedRectangle_rgba_f,
     MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRoundedRectangle_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRoundedRectangle_ca_f, MTR_SOURCE_MODULE);

    /* RoundedRectangleFilled */
    MTR_FIND_FUNCTION(mtrPrimitiveRoundedRectangleFilled_rgb_f,
     MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRoundedRectangleFilled_rgba_f,
     MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRoundedRectangleFilled_c_f,
     MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveRoundedRectangleFilled_ca_f,
     MTR_SOURCE_MODULE);

    /* Stroke Line */
    MTR_FIND_FUNCTION(mtrPrimitiveLineBegin_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveLineTo_rgb_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveLineTo_rgba_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveLineTo_c_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveLineTo_ca_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrPrimitiveLineEnd, MTR_SOURCE_MODULE);

    if (ok)
    {
        mtrScriptsRegisterFunction(mtrSF_PrimitiveInit, "PrimitiveInit");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveFill_rgb,
         "PrimitiveFill_rgb");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveFill_rgba,
         "PrimitiveFill_rgba");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveFill_c,
         "PrimitiveFill_c");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveFill_ca,
         "PrimitiveFill_ca");

        mtrScriptsRegisterFunction(mtrSF_PrimitivePixel_rgb_f,
         "PrimitivePixel_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitivePixel_rgba_f,
         "PrimitivePixel_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitivePixel_c_f,
         "PrimitivePixel_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitivePixel_ca_f,
         "PrimitivePixel_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveLine_rgb_f,
         "PrimitiveLine_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveLine_rgba_f,
         "PrimitiveLine_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveLine_c_f,
         "PrimitiveLine_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveLine_ca_f,
         "PrimitiveLine_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveArc_rgb_f,
         "PrimitiveArc_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveArc_rgba_f,
         "PrimitiveArc_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveArc_c_f,
         "PrimitiveArc_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveArc_ca_f,
         "PrimitiveArc_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveSegmentFilled_rgb_f,
         "PrimitiveSegmentFilled_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveSegmentFilled_rgba_f,
         "PrimitiveSegmentFilled_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveSegmentFilled_c_f,
         "PrimitiveSegmentFilled_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveSegmentFilled_ca_f,
         "PrimitiveSegmentFilled_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveCircle_rgb_f,
         "PrimitiveCircle_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveCircle_rgba_f,
         "PrimitiveCircle_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveCircle_c_f,
         "PrimitiveCircle_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveCircle_ca_f,
         "PrimitiveCircle_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveCircleFilled_rgb_f,
         "PrimitiveCircleFilled_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveCircleFilled_rgba_f,
         "PrimitiveCircleFilled_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveCircleFilled_c_f,
         "PrimitiveCircleFilled_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveCircleFilled_ca_f,
         "PrimitiveCircleFilled_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveEllipse_rgb_f,
         "PrimitiveEllipse_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveEllipse_rgba_f,
         "PrimitiveEllipse_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveEllipse_c_f,
         "PrimitiveEllipse_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveEllipse_ca_f,
         "PrimitiveEllipse_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveEllipseFilled_rgb_f,
         "PrimitiveEllipseFilled_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveEllipseFilled_rgba_f,
         "PrimitiveEllipseFilled_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveEllipseFilled_c_f,
         "PrimitiveEllipseFilled_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveEllipseFilled_ca_f,
         "PrimitiveEllipseFilled_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveRingSegment_rgb_f,
         "PrimitiveRingSegment_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRingSegment_rgba_f,
         "PrimitiveRingSegment_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRingSegment_c_f,
         "PrimitiveRingSegment_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRingSegment_ca_f,
         "PrimitiveRingSegment_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveRingSegmentFilled_rgb_f,
         "PrimitiveRingSegmentFilled_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRingSegmentFilled_rgba_f,
         "PrimitiveRingSegmentFilled_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRingSegmentFilled_c_f,
         "PrimitiveRingSegmentFilled_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRingSegmentFilled_ca_f,
         "PrimitiveRingSegmentFilled_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveTriangle_rgb_f,
         "PrimitiveTriangle_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveTriangle_rgba_f,
         "PrimitiveTriangle_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveTriangle_c_f,
         "PrimitiveTriangle_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveTriangle_ca_f,
         "PrimitiveTriangle_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveTriangleFilled_rgb_f,
         "PrimitiveTriangleFilled_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveTriangleFilled_rgba_f,
         "PrimitiveTriangleFilled_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveTriangleFilled_c_f,
         "PrimitiveTriangleFilled_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveTriangleFilled_ca_f,
         "PrimitiveTriangleFilled_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveRectangle_rgb_f,
         "PrimitiveRectangle_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRectangle_rgba_f,
         "PrimitiveRectangle_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRectangle_c_f,
         "PrimitiveRectangle_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRectangle_ca_f,
         "PrimitiveRectangle_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveRectangleFilled_rgb_f,
         "PrimitiveRectangleFilled_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRectangleFilled_rgba_f,
         "PrimitiveRectangleFilled_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRectangleFilled_c_f,
         "PrimitiveRectangleFilled_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRectangleFilled_ca_f,
         "PrimitiveRectangleFilled_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveRoundedRectangle_rgb_f,
         "PrimitiveRoundedRectangle_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRoundedRectangle_rgba_f,
         "PrimitiveRoundedRectangle_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRoundedRectangle_c_f,
         "PrimitiveRoundedRectangle_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRoundedRectangle_ca_f,
         "PrimitiveRoundedRectangle_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveRoundedRectangleFilled_rgb_f,
         "PrimitiveRoundedRectangleFilled_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRoundedRectangleFilled_rgba_f,
         "PrimitiveRoundedRectangleFilled_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRoundedRectangleFilled_c_f,
         "PrimitiveRoundedRectangleFilled_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveRoundedRectangleFilled_ca_f,
         "PrimitiveRoundedRectangleFilled_ca_f");

        mtrScriptsRegisterFunction(mtrSF_PrimitiveLineBegin_f,
         "PrimitiveLineBegin_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveLineTo_rgb_f,
         "PrimitiveLineTo_rgb_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveLineTo_rgba_f,
         "PrimitiveLineTo_rgba_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveLineTo_c_f,
         "PrimitiveLineTo_c_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveLineTo_ca_f,
         "PrimitiveLineTo_ca_f");
        mtrScriptsRegisterFunction(mtrSF_PrimitiveLineEnd,
         "PrimitiveLineEnd");
    }
    else
    {
        mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
    }
}

#endif
