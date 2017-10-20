#ifndef MTR_TEXTURE_SDL2_IMAGE_H
#define MTR_TEXTURE_SDL2_IMAGE_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "fa/Texture_SDL2_image.h"
#include "marathoner/plugin.h"

/*
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
*/
typedef struct mtrScreen_t {
    SDL_Window   *screen;
    SDL_Renderer *renderer;
} mtrScreen_t;

typedef struct mtrTexture_t {
    SDL_Texture *texture;
    SDL_Surface *surface; /* pixel data of loaded images can be get from surface
                           * pixel data of images created/copyed in runtime
                           * can be get from texture pixels. It is limitation of
                           * SDL2 API
                           */
    char        *name;
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
        MTR_LogWrite(message ". Texture manager are not initialized",  \
         1, MTR_LMT_ERROR);                                            \
        return returnValue;                                            \
    }

typedef mtrScreen_t *(MTR_CALL * mtrGetScreenFunc)(void);
mtrGetScreenFunc MTR_GetScreen;

MTR_EXPORT void MTR_CALL MTR_TextureFree(uint32_t texNum);

#endif

