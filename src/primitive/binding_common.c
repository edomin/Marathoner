#include "marathoner/script_func.h"

int mtrSF_PrimitiveInit(lua_State* l)
{
    bool success;

    success = mtrPrimitiveInit();

    MTR_SF_PUSH_BOOL(success);

    return 1;
}

int mtrSF_PrimitiveFill_rgb(lua_State* l)
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

int mtrSF_PrimitiveFill_rgba(lua_State* l)
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

int mtrSF_PrimitiveFill_c(lua_State* l)
{
    uint32_t color;

    MTR_SF_GET_UINT32(color, 1);
    mtrPrimitiveFill_c(color);

    return 0;
}

int mtrSF_PrimitiveFill_ca(lua_State* l)
{
    uint32_t color;

    MTR_SF_GET_UINT32(color, 1);
    mtrPrimitiveFill_ca(color);

    return 0;
}

int mtrSF_PrimitivePixel_rgb_f(lua_State* l)
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

int mtrSF_PrimitivePixel_rgba_f(lua_State* l)
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

int mtrSF_PrimitivePixel_c_f(lua_State* l)
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

int mtrSF_PrimitivePixel_ca_f(lua_State* l)
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

int mtrSF_PrimitiveLine_rgb_f(lua_State* l)
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

int mtrSF_PrimitiveLine_rgba_f(lua_State* l)
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

int mtrSF_PrimitiveLine_c_f(lua_State* l)
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

int mtrSF_PrimitiveLine_ca_f(lua_State* l)
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

int mtrSF_PrimitiveArc_rgb_f(lua_State* l)
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

int mtrSF_PrimitiveArc_rgba_f(lua_State* l)
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

int mtrSF_PrimitiveArc_c_f(lua_State* l)
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

int mtrSF_PrimitiveArc_ca_f(lua_State* l)
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

int mtrSF_PrimitiveSegmentFilled_rgb_f(lua_State* l)
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

int mtrSF_PrimitiveSegmentFilled_rgba_f(lua_State* l)
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

int mtrSF_PrimitiveSegmentFilled_c_f(lua_State* l)
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

int mtrSF_PrimitiveSegmentFilled_ca_f(lua_State* l)
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

int mtrSF_PrimitiveCircle_rgb_f(lua_State* l)
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

int mtrSF_PrimitiveCircle_rgba_f(lua_State* l)
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

int mtrSF_PrimitiveCircle_c_f(lua_State* l)
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

int mtrSF_PrimitiveCircle_ca_f(lua_State* l)
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

int mtrSF_PrimitiveCircleFilled_rgb_f(lua_State* l)
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

int mtrSF_PrimitiveCircleFilled_rgba_f(lua_State* l)
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

int mtrSF_PrimitiveCircleFilled_c_f(lua_State* l)
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

int mtrSF_PrimitiveCircleFilled_ca_f(lua_State* l)
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

int mtrSF_PrimitiveEllipse_rgb_f(lua_State* l)
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

int mtrSF_PrimitiveEllipse_rgba_f(lua_State* l)
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

int mtrSF_PrimitiveEllipse_c_f(lua_State* l)
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

int mtrSF_PrimitiveEllipse_ca_f(lua_State* l)
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

int mtrSF_PrimitiveEllipseFilled_rgb_f(lua_State* l)
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

int mtrSF_PrimitiveEllipseFilled_rgba_f(lua_State* l)
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

int mtrSF_PrimitiveEllipseFilled_c_f(lua_State* l)
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

int mtrSF_PrimitiveEllipseFilled_ca_f(lua_State* l)
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

int mtrSF_PrimitiveRingSegment_rgb_f(lua_State* l)
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

int mtrSF_PrimitiveRingSegment_rgba_f(lua_State* l)
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

int mtrSF_PrimitiveRingSegment_c_f(lua_State* l)
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

int mtrSF_PrimitiveRingSegment_ca_f(lua_State* l)
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

int mtrSF_PrimitiveRingSegmentFilled_rgb_f(lua_State* l)
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

int mtrSF_PrimitiveRingSegmentFilled_rgba_f(lua_State* l)
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

int mtrSF_PrimitiveRingSegmentFilled_c_f(lua_State* l)
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

int mtrSF_PrimitiveRingSegmentFilled_ca_f(lua_State* l)
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

int mtrSF_PrimitiveTriangle_rgb_f(lua_State* l)
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

int mtrSF_PrimitiveTriangle_rgba_f(lua_State* l)
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

int mtrSF_PrimitiveTriangle_c_f(lua_State* l)
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

int mtrSF_PrimitiveTriangle_ca_f(lua_State* l)
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

int mtrSF_PrimitiveTriangleFilled_rgb_f(lua_State* l)
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

int mtrSF_PrimitiveTriangleFilled_rgba_f(lua_State* l)
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

int mtrSF_PrimitiveTriangleFilled_c_f(lua_State* l)
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

int mtrSF_PrimitiveTriangleFilled_ca_f(lua_State* l)
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

int mtrSF_PrimitiveRectangle_rgb_f(lua_State* l)
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

int mtrSF_PrimitiveRectangle_rgba_f(lua_State* l)
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

int mtrSF_PrimitiveRectangle_c_f(lua_State* l)
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

int mtrSF_PrimitiveRectangle_ca_f(lua_State* l)
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

int mtrSF_PrimitiveRectangleFilled_rgb_f(lua_State* l)
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

int mtrSF_PrimitiveRectangleFilled_rgba_f(lua_State* l)
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

int mtrSF_PrimitiveRectangleFilled_c_f(lua_State* l)
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

int mtrSF_PrimitiveRectangleFilled_ca_f(lua_State* l)
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

int mtrSF_PrimitiveRoundedRectangle_rgb_f(lua_State* l)
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

int mtrSF_PrimitiveRoundedRectangle_rgba_f(lua_State* l)
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

int mtrSF_PrimitiveRoundedRectangle_c_f(lua_State* l)
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

int mtrSF_PrimitiveRoundedRectangle_ca_f(lua_State* l)
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

int mtrSF_PrimitiveRoundedRectangleFilled_rgb_f(lua_State* l)
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

int mtrSF_PrimitiveRoundedRectangleFilled_rgba_f(lua_State* l)
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

int mtrSF_PrimitiveRoundedRectangleFilled_c_f(lua_State* l)
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

int mtrSF_PrimitiveRoundedRectangleFilled_ca_f(lua_State* l)
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

int mtrSF_PrimitiveLineBegin_f(lua_State* l)
{
    float x;
    float y;
    
    MTR_SF_GET_SINGLE(x, 1);
    MTR_SF_GET_SINGLE(y, 2);
    mtrPrimitiveLineBegin_f(x, y);
    
    return 0;
}

int mtrSF_PrimitiveLineTo_rgb_f(lua_State* l)
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

int mtrSF_PrimitiveLineTo_rgba_f(lua_State* l)
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

int mtrSF_PrimitiveLineTo_c_f(lua_State* l)
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

int mtrSF_PrimitiveLineTo_ca_f(lua_State* l)
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

int mtrSF_PrimitiveLineEnd(lua_State* l)
{
    mtrPrimitiveLineEnd();
    
    return 0;
}