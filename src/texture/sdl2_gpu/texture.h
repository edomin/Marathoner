#ifndef MTR_TEXTURE_SDL2_GPU_H
#define MTR_TEXTURE_SDL2_GPU_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_gpu.h"

#include "fa/Texture_SDL2_gpu.h"
#include "marathoner/plugin.h"

#define MTR_BLEND_ZERO                  GPU_FUNC_ZERO
#define MTR_BLEND_ONE                   GPU_FUNC_ONE
#define MTR_BLEND_SRC_COLOR             GPU_FUNC_SRC_COLOR
#define MTR_BLEND_DST_COLOR             GPU_FUNC_DST_COLOR
#define MTR_BLEND_ONE_MINUS_SRC         GPU_FUNC_ONE_MINUS_SRC
#define MTR_BLEND_ONE_MINUS_DST         GPU_FUNC_ONE_MINUS_DST
#define MTR_BLEND_SRC_ALPHA             GPU_FUNC_SRC_ALPHA
#define MTR_BLEND_DST_ALPHA             GPU_FUNC_DST_ALPHA
#define MTR_BLEND_ONE_MINUS_SRC_ALPHA   GPU_FUNC_ONE_MINUS_SRC_ALPHA
#define MTR_BLEND_ONE_MINUS_DST_ALPHA   GPU_FUNC_ONE_MINUS_DST_ALPHA

typedef struct mtrScreen_t {
    GPU_Target* screen;
    GPU_Target* target;
} mtrScreen_t;

typedef struct mtrTexture_t {
    GPU_Image *texture;
    char *name;
} mtrTexture_t;

char              mtrDefaultTextureName[] = "Unnamed_Texture";
mtrScreen_t      *mtrScreen; /* this will imported from screen plugin */
mtrIndexkeeper_t *mtrTextureKeeper;
static bool       mtrTextureInited = false;
#define MTR_TEXTURE_CHECK_IF_NOT_INITED(returnValue) \
    if (!mtrTextureInited)                           \
        return returnValue;
#define MTR_TEXTURE_CHECK_IF_NOT_INITED_WITH_LOG(message, returnValue) \
    if (!mtrTextureInited)                                             \
    {                                                                  \
        mtrLogWrite(message ". Texture manager are not initialized",   \
         1, MTR_LMT_ERROR);                                            \
        return returnValue;                                            \
    }

typedef mtrScreen_t *(MTR_CALL * mtrGetScreenFunc)(void);
mtrGetScreenFunc mtrGetScreen;

#endif
