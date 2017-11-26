#ifndef MTR_PNG_LIBPNG_H
#define MTR_PNG_LIBPNG_H

#include <string.h>

#include "zlib.h"
#include "png.h"

#include "marathoner/plugin.h"
#ifdef MTR_MOD_STATIC
    #define fa faPng
#endif
#include "fa/PNG_libpng.h"

#define MTR_PNG_DEFAULT_DISPLAY_GAMMA 2.2
#define MTR_PNG_DEFAULT_IMAGE_GAMMA 0.45455

static bool  mtrPngInited = false;
mtrPixels_t *tempPixels;

#endif

