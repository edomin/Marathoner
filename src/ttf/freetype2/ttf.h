#ifndef MTR_TTF_FREETYPE2_H
#define MTR_TTF_FREETYPE2_H

#include <string.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <freetype/ftbitmap.h>

#include "marathoner/plugin.h"
#ifdef MTR_MOD_STATIC
    #define fa faTtf
#endif
#include "fa/TTF_FreeType2.h"

typedef struct mtrTtfFace_t {
    FT_Face face;
} mtrTtfFace_t;

typedef struct mtrTtf_t {
    int           facesCount;
    mtrTtfFace_t *face;
    int           currentFace;
    char         *name;
    int           width;
    int           height;
} mtrTtf_t;

char              mtrDefaultTTFName[] = "Unnamed_TTF";
mtrIndexkeeper_t *mtrTtfKeeper;
FT_Library        mtrFtLibrary;
FT_Error          mtrFtError;
mtrPixels_t      *tempPixels;
static bool       mtrTtfInited = false;
#define MTR_TTF_CHECK_IF_NOT_INITED(returnValue) \
    if (!mtrTtfInited)                           \
        return returnValue;
#define MTR_TTF_CHECK_IF_NOT_INITED_WITH_LOG(message, returnValue)     \
    if (!mtrTtfInited)                                                 \
    {                                                                  \
        MTR_LogWrite(message ". TTF font manager are not initialized", \
         1, MTR_LMT_ERROR);                                            \
        return returnValue;                                            \
    }

#endif
