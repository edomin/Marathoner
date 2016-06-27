#ifndef MTR_PRIMITIVE_SDL_GPU_LUA52
#define MTR_PRIMITIVE_SDL_GPU_LUA52

#define MTR_PLUGIN
#include "marathoner.h"

#include "bool/bool.h"

#include "lua52/lua.h"
#include "lua52/lualib.h"
#include "lua52/lauxlib.h"

lua_State *mtrVm;

typedef lua_State* (__stdcall * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (__stdcall * mtrScriptsRegisterFunctionFunc)(lua_CFunction, char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef bool (__stdcall * mtrPrimitiveInitFunc)(void);
mtrPrimitiveInitFunc mtrPrimitiveInit;

/* Fill */
typedef void (__stdcall * mtrPrimitiveFill_rgbFunc)(uint8_t, uint8_t, uint8_t);
mtrPrimitiveFill_rgbFunc mtrPrimitiveFill_rgb;

typedef void (__stdcall * mtrPrimitiveFill_rgbaFunc)(uint8_t, uint8_t, uint8_t,
 uint8_t);
mtrPrimitiveFill_rgbaFunc mtrPrimitiveFill_rgba;

typedef void (__stdcall * mtrPrimitiveFill_cFunc)(uint32_t);
mtrPrimitiveFill_cFunc mtrPrimitiveFill_c;

typedef void (__stdcall * mtrPrimitiveFill_caFunc)(uint32_t);
mtrPrimitiveFill_caFunc mtrPrimitiveFill_ca;

/* Pixel */
typedef void (__stdcall * mtrPrimitivePixel_rgb_fFunc)(float, float, uint8_t,
 uint8_t, uint8_t);
mtrPrimitivePixel_rgb_fFunc mtrPrimitivePixel_rgb_f;

typedef void (__stdcall * mtrPrimitivePixel_rgba_fFunc)(float, float, uint8_t,
 uint8_t, uint8_t, uint8_t);
mtrPrimitivePixel_rgba_fFunc mtrPrimitivePixel_rgba_f;

typedef void (__stdcall * mtrPrimitivePixel_c_fFunc)(float, float, uint32_t);
mtrPrimitivePixel_c_fFunc mtrPrimitivePixel_c_f;

typedef void (__stdcall * mtrPrimitivePixel_ca_fFunc)(float, float, uint32_t);
mtrPrimitivePixel_ca_fFunc mtrPrimitivePixel_ca_f;

/* Line */
typedef void (__stdcall * mtrPrimitiveLine_rgb_fFunc)(float, float, float, float,
 uint8_t, uint8_t, uint8_t);
mtrPrimitiveLine_rgb_fFunc mtrPrimitiveLine_rgb_f;

typedef void (__stdcall * mtrPrimitiveLine_rgba_fFunc)(float, float, float, float,
 uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveLine_rgba_fFunc mtrPrimitiveLine_rgba_f;

typedef void (__stdcall * mtrPrimitiveLine_c_fFunc)(float, float, float, float,
 uint32_t);
mtrPrimitiveLine_c_fFunc mtrPrimitiveLine_c_f;

typedef void (__stdcall * mtrPrimitiveLine_ca_fFunc)(float, float, float, float,
 uint32_t);
mtrPrimitiveLine_ca_fFunc mtrPrimitiveLine_ca_f;

/* Arc */
typedef void (__stdcall * mtrPrimitiveArc_rgb_fFunc)(float, float, float, float,
 float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveArc_rgb_fFunc mtrPrimitiveArc_rgb_f;

typedef void (__stdcall * mtrPrimitiveArc_rgba_fFunc)(float, float, float, float,
 float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveArc_rgba_fFunc mtrPrimitiveArc_rgba_f;

typedef void (__stdcall * mtrPrimitiveArc_c_fFunc)(float, float, float, float,
 float, uint32_t);
mtrPrimitiveArc_c_fFunc mtrPrimitiveArc_c_f;

typedef void (__stdcall * mtrPrimitiveArc_ca_fFunc)(float, float, float, float,
 float, uint32_t);
mtrPrimitiveArc_ca_fFunc mtrPrimitiveArc_ca_f;

/* SegmentFilled */
typedef void (__stdcall * mtrPrimitiveSegmentFilled_rgb_fFunc)(float, float,
 float, float, float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveSegmentFilled_rgb_fFunc mtrPrimitiveSegmentFilled_rgb_f;

typedef void (__stdcall * mtrPrimitiveSegmentFilled_rgba_fFunc)(float, float,
 float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveSegmentFilled_rgba_fFunc mtrPrimitiveSegmentFilled_rgba_f;

typedef void (__stdcall * mtrPrimitiveSegmentFilled_c_fFunc)(float, float,
 float, float, float, uint32_t);
mtrPrimitiveSegmentFilled_c_fFunc mtrPrimitiveSegmentFilled_c_f;

typedef void (__stdcall * mtrPrimitiveSegmentFilled_ca_fFunc)(float, float, float,
 float, float, uint32_t);
mtrPrimitiveSegmentFilled_ca_fFunc mtrPrimitiveSegmentFilled_ca_f;

/* Circle */
typedef void (__stdcall * mtrPrimitiveCircle_rgb_fFunc)(float, float, float,
 uint8_t, uint8_t, uint8_t);
mtrPrimitiveCircle_rgb_fFunc mtrPrimitiveCircle_rgb_f;

typedef void (__stdcall * mtrPrimitiveCircle_rgba_fFunc)(float, float, float,
 uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveCircle_rgba_fFunc mtrPrimitiveCircle_rgba_f;

typedef void (__stdcall * mtrPrimitiveCircle_c_fFunc)(float, float, float,
 uint32_t);
mtrPrimitiveCircle_c_fFunc mtrPrimitiveCircle_c_f;

typedef void (__stdcall * mtrPrimitiveCircle_ca_fFunc)(float, float, float,
 uint32_t);
mtrPrimitiveCircle_ca_fFunc mtrPrimitiveCircle_ca_f;

/* CircleFilled */
typedef void (__stdcall * mtrPrimitiveCircleFilled_rgb_fFunc)(float, float, float,
 uint8_t, uint8_t, uint8_t);
mtrPrimitiveCircleFilled_rgb_fFunc mtrPrimitiveCircleFilled_rgb_f;

typedef void (__stdcall * mtrPrimitiveCircleFilled_rgba_fFunc)(float, float,
 float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveCircleFilled_rgba_fFunc mtrPrimitiveCircleFilled_rgba_f;

typedef void (__stdcall * mtrPrimitiveCircleFilled_c_fFunc)(float, float, float,
 uint32_t);
mtrPrimitiveCircleFilled_c_fFunc mtrPrimitiveCircleFilled_c_f;

typedef void (__stdcall * mtrPrimitiveCircleFilled_ca_fFunc)(float, float, float,
 uint32_t);
mtrPrimitiveCircleFilled_ca_fFunc mtrPrimitiveCircleFilled_ca_f;

/* Ellipse */
typedef void (__stdcall * mtrPrimitiveEllipse_rgb_fFunc)(float, float, float,
 float, float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveEllipse_rgb_fFunc mtrPrimitiveEllipse_rgb_f;

typedef void (__stdcall * mtrPrimitiveEllipse_rgba_fFunc)(float, float, float,
 float, float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveEllipse_rgba_fFunc mtrPrimitiveEllipse_rgba_f;

typedef void (__stdcall * mtrPrimitiveEllipse_c_fFunc)(float, float, float,
 float, float, uint32_t);
mtrPrimitiveEllipse_c_fFunc mtrPrimitiveEllipse_c_f;

typedef void (__stdcall * mtrPrimitiveEllipse_ca_fFunc)(float, float, float,
 float, float, uint32_t);
mtrPrimitiveEllipse_ca_fFunc mtrPrimitiveEllipse_ca_f;

/* EllipseFilled */
typedef void (__stdcall * mtrPrimitiveEllipseFilled_rgb_fFunc)(float, float,
 float, float, float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveEllipseFilled_rgb_fFunc mtrPrimitiveEllipseFilled_rgb_f;

typedef void (__stdcall * mtrPrimitiveEllipseFilled_rgba_fFunc)(float, float,
 float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveEllipseFilled_rgba_fFunc mtrPrimitiveEllipseFilled_rgba_f;

typedef void (__stdcall * mtrPrimitiveEllipseFilled_c_fFunc)(float, float, float,
 float, float, uint32_t);
mtrPrimitiveEllipseFilled_c_fFunc mtrPrimitiveEllipseFilled_c_f;

typedef void (__stdcall * mtrPrimitiveEllipseFilled_ca_fFunc)(float, float, float,
 float, float, uint32_t);
mtrPrimitiveEllipseFilled_ca_fFunc mtrPrimitiveEllipseFilled_ca_f;

/* RingSegment */
typedef void (__stdcall * mtrPrimitiveRingSegment_rgb_fFunc)(float, float,
 float, float, float, float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRingSegment_rgb_fFunc mtrPrimitiveRingSegment_rgb_f;

typedef void (__stdcall * mtrPrimitiveRingSegment_rgba_fFunc)(float, float,
 float, float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRingSegment_rgba_fFunc mtrPrimitiveRingSegment_rgba_f;

typedef void (__stdcall * mtrPrimitiveRingSegment_c_fFunc)(float, float, float,
 float, float, float, uint32_t);
mtrPrimitiveRingSegment_c_fFunc mtrPrimitiveRingSegment_c_f;

typedef void (__stdcall * mtrPrimitiveRingSegment_ca_fFunc)(float, float, float,
 float, float, float, uint32_t);
mtrPrimitiveRingSegment_ca_fFunc mtrPrimitiveRingSegment_ca_f;

/* RingSegmentFilled */
typedef void (__stdcall * mtrPrimitiveRingSegmentFilled_rgb_fFunc)(float, float,
 float, float, float, float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRingSegmentFilled_rgb_fFunc mtrPrimitiveRingSegmentFilled_rgb_f;

typedef void (__stdcall * mtrPrimitiveRingSegmentFilled_rgba_fFunc)(float, float,
 float, float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRingSegmentFilled_rgba_fFunc mtrPrimitiveRingSegmentFilled_rgba_f;

typedef void (__stdcall * mtrPrimitiveRingSegmentFilled_c_fFunc)(float, float,
 float, float, float, float, uint32_t);
mtrPrimitiveRingSegmentFilled_c_fFunc mtrPrimitiveRingSegmentFilled_c_f;

typedef void (__stdcall * mtrPrimitiveRingSegmentFilled_ca_fFunc)(float, float,
 float, float, float, float, uint32_t);
mtrPrimitiveRingSegmentFilled_ca_fFunc mtrPrimitiveRingSegmentFilled_ca_f;

/* Triangle */
typedef void (__stdcall * mtrPrimitiveTriangle_rgb_fFunc)(float, float, float,
 float, float, float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveTriangle_rgb_fFunc mtrPrimitiveTriangle_rgb_f;

typedef void (__stdcall * mtrPrimitiveTriangle_rgba_fFunc)(float, float, float,
 float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveTriangle_rgba_fFunc mtrPrimitiveTriangle_rgba_f;

typedef void (__stdcall * mtrPrimitiveTriangle_c_fFunc)(float, float, float,
 float, float, float, uint32_t);
mtrPrimitiveTriangle_c_fFunc mtrPrimitiveTriangle_c_f;

typedef void (__stdcall * mtrPrimitiveTriangle_ca_fFunc)(float, float, float,
 float, float, float, uint32_t);
mtrPrimitiveTriangle_ca_fFunc mtrPrimitiveTriangle_ca_f;

/* TriangleFilled */
typedef void (__stdcall * mtrPrimitiveTriangleFilled_rgb_fFunc)(float, float,
 float, float, float, float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveTriangleFilled_rgb_fFunc mtrPrimitiveTriangleFilled_rgb_f;

typedef void (__stdcall * mtrPrimitiveTriangleFilled_rgba_fFunc)(float, float,
 float, float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveTriangleFilled_rgba_fFunc mtrPrimitiveTriangleFilled_rgba_f;

typedef void (__stdcall * mtrPrimitiveTriangleFilled_c_fFunc)(float, float,
 float, float, float, float, uint32_t);
mtrPrimitiveTriangleFilled_c_fFunc mtrPrimitiveTriangleFilled_c_f;

typedef void (__stdcall * mtrPrimitiveTriangleFilled_ca_fFunc)(float, float,
 float, float, float, float, uint32_t);
mtrPrimitiveTriangleFilled_ca_fFunc mtrPrimitiveTriangleFilled_ca_f;

/* Rectangle */
typedef void (__stdcall * mtrPrimitiveRectangle_rgb_fFunc)(float, float, float,
 float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRectangle_rgb_fFunc mtrPrimitiveRectangle_rgb_f;

typedef void (__stdcall * mtrPrimitiveRectangle_rgba_fFunc)(float, float, float,
 float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRectangle_rgba_fFunc mtrPrimitiveRectangle_rgba_f;

typedef void (__stdcall * mtrPrimitiveRectangle_c_fFunc)(float, float, float,
 float, uint32_t);
mtrPrimitiveRectangle_c_fFunc mtrPrimitiveRectangle_c_f;

typedef void (__stdcall * mtrPrimitiveRectangle_ca_fFunc)(float, float, float,
 float, uint32_t);
mtrPrimitiveRectangle_ca_fFunc mtrPrimitiveRectangle_ca_f;

/* RectangleFilled */
typedef void (__stdcall * mtrPrimitiveRectangleFilled_rgb_fFunc)(float, float,
 float, float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRectangleFilled_rgb_fFunc mtrPrimitiveRectangleFilled_rgb_f;

typedef void (__stdcall * mtrPrimitiveRectangleFilled_rgba_fFunc)(float, float,
 float, float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRectangleFilled_rgba_fFunc mtrPrimitiveRectangleFilled_rgba_f;

typedef void (__stdcall * mtrPrimitiveRectangleFilled_c_fFunc)(float, float,
 float, float, uint32_t);
mtrPrimitiveRectangleFilled_c_fFunc mtrPrimitiveRectangleFilled_c_f;

typedef void (__stdcall * mtrPrimitiveRectangleFilled_ca_fFunc)(float, float,
 float, float, uint32_t);
mtrPrimitiveRectangleFilled_ca_fFunc mtrPrimitiveRectangleFilled_ca_f;

/* RoundedRectangle */
typedef void (__stdcall * mtrPrimitiveRoundedRectangle_rgb_fFunc)(float, float,
 float, float, float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRoundedRectangle_rgb_fFunc mtrPrimitiveRoundedRectangle_rgb_f;

typedef void (__stdcall * mtrPrimitiveRoundedRectangle_rgba_fFunc)(float, float,
 float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRoundedRectangle_rgba_fFunc mtrPrimitiveRoundedRectangle_rgba_f;

typedef void (__stdcall * mtrPrimitiveRoundedRectangle_c_fFunc)(float, float,
 float, float, float, uint32_t);
mtrPrimitiveRoundedRectangle_c_fFunc mtrPrimitiveRoundedRectangle_c_f;

typedef void (__stdcall * mtrPrimitiveRoundedRectangle_ca_fFunc)(float, float,
 float, float, float, uint32_t);
mtrPrimitiveRoundedRectangle_ca_fFunc mtrPrimitiveRoundedRectangle_ca_f;

/* RoundedRectangleFilled */
typedef void (__stdcall * mtrPrimitiveRoundedRectangleFilled_rgb_fFunc)(float,
 float, float, float, float, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRoundedRectangleFilled_rgb_fFunc mtrPrimitiveRoundedRectangleFilled_rgb_f;

typedef void (__stdcall * mtrPrimitiveRoundedRectangleFilled_rgba_fFunc)(float,
 float, float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
mtrPrimitiveRoundedRectangleFilled_rgba_fFunc mtrPrimitiveRoundedRectangleFilled_rgba_f;

typedef void (__stdcall * mtrPrimitiveRoundedRectangleFilled_c_fFunc)(float,
 float, float, float, float, uint32_t);
mtrPrimitiveRoundedRectangleFilled_c_fFunc mtrPrimitiveRoundedRectangleFilled_c_f;

typedef void (__stdcall * mtrPrimitiveRoundedRectangleFilled_ca_fFunc)(float,
 float, float, float, float, uint32_t);
mtrPrimitiveRoundedRectangleFilled_ca_fFunc mtrPrimitiveRoundedRectangleFilled_ca_f;

int mtrSF_PrimitiveInit(lua_State* l);

int mtrSF_PrimitiveFill_rgb(lua_State* l);
int mtrSF_PrimitiveFill_rgba(lua_State* l);
int mtrSF_PrimitiveFill_c(lua_State* l);
int mtrSF_PrimitiveFill_ca(lua_State* l);

int mtrSF_PrimitivePixel_rgb_f(lua_State* l);
int mtrSF_PrimitivePixel_rgba_f(lua_State* l);
int mtrSF_PrimitivePixel_c_f(lua_State* l);
int mtrSF_PrimitivePixel_ca_f(lua_State* l);

int mtrSF_PrimitiveLine_rgb_f(lua_State* l);
int mtrSF_PrimitiveLine_rgba_f(lua_State* l);
int mtrSF_PrimitiveLine_c_f(lua_State* l);
int mtrSF_PrimitiveLine_ca_f(lua_State* l);

int mtrSF_PrimitiveArc_rgb_f(lua_State* l);
int mtrSF_PrimitiveArc_rgba_f(lua_State* l);
int mtrSF_PrimitiveArc_c_f(lua_State* l);
int mtrSF_PrimitiveArc_ca_f(lua_State* l);

int mtrSF_PrimitiveSegmentFilled_rgb_f(lua_State* l);
int mtrSF_PrimitiveSegmentFilled_rgba_f(lua_State* l);
int mtrSF_PrimitiveSegmentFilled_c_f(lua_State* l);
int mtrSF_PrimitiveSegmentFilled_ca_f(lua_State* l);

int mtrSF_PrimitiveCircle_rgb_f(lua_State* l);
int mtrSF_PrimitiveCircle_rgba_f(lua_State* l);
int mtrSF_PrimitiveCircle_c_f(lua_State* l);
int mtrSF_PrimitiveCircle_ca_f(lua_State* l);

int mtrSF_PrimitiveCircleFilled_rgb_f(lua_State* l);
int mtrSF_PrimitiveCircleFilled_rgba_f(lua_State* l);
int mtrSF_PrimitiveCircleFilled_c_f(lua_State* l);
int mtrSF_PrimitiveCircleFilled_ca_f(lua_State* l);

int mtrSF_PrimitiveEllipse_rgb_f(lua_State* l);
int mtrSF_PrimitiveEllipse_rgba_f(lua_State* l);
int mtrSF_PrimitiveEllipse_c_f(lua_State* l);
int mtrSF_PrimitiveEllipse_ca_f(lua_State* l);

int mtrSF_PrimitiveEllipseFilled_rgb_f(lua_State* l);
int mtrSF_PrimitiveEllipseFilled_rgba_f(lua_State* l);
int mtrSF_PrimitiveEllipseFilled_c_f(lua_State* l);
int mtrSF_PrimitiveEllipseFilled_ca_f(lua_State* l);

int mtrSF_PrimitiveRingSegment_rgb_f(lua_State* l);
int mtrSF_PrimitiveRingSegment_rgba_f(lua_State* l);
int mtrSF_PrimitiveRingSegment_c_f(lua_State* l);
int mtrSF_PrimitiveRingSegment_ca_f(lua_State* l);

int mtrSF_PrimitiveRingSegmentFilled_rgb_f(lua_State* l);
int mtrSF_PrimitiveRingSegmentFilled_rgba_f(lua_State* l);
int mtrSF_PrimitiveRingSegmentFilled_c_f(lua_State* l);
int mtrSF_PrimitiveRingSegmentFilled_ca_f(lua_State* l);

int mtrSF_PrimitiveTriangle_rgb_f(lua_State* l);
int mtrSF_PrimitiveTriangle_rgba_f(lua_State* l);
int mtrSF_PrimitiveTriangle_c_f(lua_State* l);
int mtrSF_PrimitiveTriangle_ca_f(lua_State* l);

int mtrSF_PrimitiveTriangleFilled_rgb_f(lua_State* l);
int mtrSF_PrimitiveTriangleFilled_rgba_f(lua_State* l);
int mtrSF_PrimitiveTriangleFilled_c_f(lua_State* l);
int mtrSF_PrimitiveTriangleFilled_ca_f(lua_State* l);

int mtrSF_PrimitiveRectangle_rgb_f(lua_State* l);
int mtrSF_PrimitiveRectangle_rgba_f(lua_State* l);
int mtrSF_PrimitiveRectangle_c_f(lua_State* l);
int mtrSF_PrimitiveRectangle_ca_f(lua_State* l);

int mtrSF_PrimitiveRectangleFilled_rgb_f(lua_State* l);
int mtrSF_PrimitiveRectangleFilled_rgba_f(lua_State* l);
int mtrSF_PrimitiveRectangleFilled_c_f(lua_State* l);
int mtrSF_PrimitiveRectangleFilled_ca_f(lua_State* l);

int mtrSF_PrimitiveRoundedRectangle_rgb_f(lua_State* l);
int mtrSF_PrimitiveRoundedRectangle_rgba_f(lua_State* l);
int mtrSF_PrimitiveRoundedRectangle_c_f(lua_State* l);
int mtrSF_PrimitiveRoundedRectangle_ca_f(lua_State* l);

int mtrSF_PrimitiveRoundedRectangleFilled_rgb_f(lua_State* l);
int mtrSF_PrimitiveRoundedRectangleFilled_rgba_f(lua_State* l);
int mtrSF_PrimitiveRoundedRectangleFilled_c_f(lua_State* l);
int mtrSF_PrimitiveRoundedRectangleFilled_ca_f(lua_State* l);

#endif
