#ifndef MTR_TTF_SDL2_TTF_H
#define MTR_TTF_SDL2_TTF_H

#include "SDL2/SDL_ttf.h"

#include "fa/TTF_SDL2_ttf.h"
#include "marathoner/plugin.h"
#include "../common.h"

typedef struct mtrTtf_t {
    TTF_Font *font;
    char     *name;
} mtrTtf_t;

char              mtrDefaultTTFName[] = "Unnamed_TTF";
mtrIndexkeeper_t *mtrTtfKeeper;
SDL_Surface      *tempSurface;
mtrPixels_t      *tempPixels;
static bool       mtrTtfInited = false;
#define MTR_TTF_CHECK_IF_NOT_INITED(returnValue) \
    if (!mtrTtfInited)                           \
        return returnValue;
#define MTR_TTF_CHECK_IF_NOT_INITED_WITH_LOG(message, returnValue)    \
    if (!mtrTtfInited)                                                \
    {                                                                 \
        mtrLogWrite(message ". TTF font manager are not initialized", \
         1, MTR_LMT_ERROR);                                           \
        return returnValue;                                           \
    }

#endif
