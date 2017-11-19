#ifndef MTR_PRIMITIVE_SDL2_GPU_H
#define MTR_PRIMITIVE_SDL2_GPU_H

#ifdef __MINGW64__
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wswitch-default"
#endif
#include "SDL2/SDL_gpu.h"
#ifdef __MINGW64__
    #pragma GCC diagnostic pop
#endif

#include "marathoner/plugin.h"
#ifdef MTR_MOD_STATIC
    #define fa faPrimitive
#endif
#include "fa/Primitive_SDL2_gpu.h"

typedef struct mtrScreen_t {
    GPU_Target* screen;
    GPU_Target* target;
} mtrScreen_t;

MTR_EXTERN mtrScreen_t *mtrScreen; /* this will imported from screen plugin */
float                   mtrLinePointX_f;
float                   mtrLinePointY_f;
bool                    mtrLineDrawing;
static bool             mtrPrimitiveInited = false;
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

MTR_FUNC(mtrScreen_t *, MTR_GetScreen, void);

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

static inline void MTR_RgbToSdlColor(uint8_t r, uint8_t g, uint8_t b,
 SDL_Color *sdlColor)
{
    sdlColor->r = r;
    sdlColor->g = g;
    sdlColor->b = b;
    sdlColor->a = 0xFFU;
}

static inline void MTR_RgbaToSdlColor(uint8_t r, uint8_t g, uint8_t b,
 uint8_t a, SDL_Color *sdlColor)
{
    sdlColor->r = r;
    sdlColor->g = g;
    sdlColor->b = b;
    sdlColor->a = a;
}

static inline void MTR_Color24ToSdlColor(uint32_t color, SDL_Color *sdlColor)
{
    sdlColor->r = color >> 16U;
    sdlColor->g = (color & 0x00FF00U) >> 8U;
    sdlColor->b = color & 0x0000FFU;
    sdlColor->a = 0xFFU;
}

static inline void MTR_Color32ToSdlColor(uint32_t color, SDL_Color *sdlColor)
{
    sdlColor->r = color >> 24U;
    sdlColor->g = (color & 0x00FF0000U) >> 16U;
    sdlColor->b = (color & 0x0000FF00U) >> 8U;
    sdlColor->a = color & 0x000000FFU;
}

#endif
