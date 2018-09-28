#ifndef MTR_OGG_LIBVORBISFILE_H
#define MTR_OGG_LIBVORBISFILE_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#ifdef __MINGW32__
    #pragma GCC diagnostic ignored "-Werror"
#endif
#include "vorbis/vorbisfile.h"
#pragma GCC diagnostic pop

#include "marathoner/plugin.h"
#ifdef MTR_MOD_STATIC
    #define fa faOgg
#endif
#include "fa/OGG_libvorbisfile.h"

static bool  mtrOggInited = false;
MTR_Stdio    MTR_OggStdio;
MTR_StdioExt MTR_OggStdioExt;
ov_callbacks mtrOggCallbacks;
mtrPcm_t     mtrOggTempPcm;

#endif
