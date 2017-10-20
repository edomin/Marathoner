#ifndef MTR_PRIMITIVE_SDL2_H
#define MTR_PRIMITIVE_SDL2_H

#include "SDL2/SDL.h"

#include "fa/Primitive_SDL2.h"
#include "marathoner/plugin.h"

#define MTR_ARC_SEGMENTS_COUNT 32
#define MTR_PI_180_F 0.01745329f

typedef struct mtrScreen_t {
    SDL_Window   *screen;
    SDL_Renderer *renderer;
} mtrScreen_t;

mtrScreen_t *mtrScreen; /* this will imported from screen plugin */
float        mtrLinePointX_f;
float        mtrLinePointY_f;
bool         mtrLineDrawing;
static bool  mtrPrimitiveInited = false;
#define MTR_PRIMITIVE_CHECK_IF_NOT_INITED(returnValue) \
    if (!mtrPrimitiveInited)                           \
        return returnValue;
#define MTR_PRIMITIVE_CHECK_IF_NOT_INITED_WITH_LOG(message, returnValue) \
    if (!mtrPrimitiveInited)                                             \
    {                                                                    \
        MTR_LogWrite(                                                    \
         message ". Primitive drawing subsystem are not initialized", 1, \
         MTR_LMT_ERROR);                                                 \
        return returnValue;                                              \
    }

typedef mtrScreen_t *(MTR_CALL * mtrGetScreenFunc)(void);
mtrGetScreenFunc MTR_GetScreen;

static inline void MTR_Color24ToRgb(uint32_t color, uint8_t *r, uint8_t *g,
 uint8_t *b)
{
    *r = color >> 16U;
    *g = (color & 0x00FF00U) >> 8U;
    *b = color & 0x0000FFU;
}

static inline void MTR_Color32ToRgba(uint32_t color, uint8_t *r, uint8_t *g,
 uint8_t *b, uint8_t *a)
{
    *r = color >> 24U;
    *g = (color & 0x00FF0000U) >> 16U;
    *b = (color & 0x0000FF00U) >> 8U;
    *a = color & 0x000000FFU;
}

MTR_DCLSPC void MTR_CALL MTR_PrimitiveLineBegin_f(float, float);
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLineTo_rgb_f(float, float, uint8_t,
 uint8_t, uint8_t);
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLineTo_rgba_f(float, float, uint8_t,
 uint8_t, uint8_t, uint8_t);
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLineTo_c_f(float, float, uint32_t);
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLineTo_ca_f(float, float, uint32_t);
MTR_DCLSPC void MTR_CALL MTR_PrimitiveLineEnd(void);

#endif

