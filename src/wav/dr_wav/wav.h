#ifndef MTR_WAV_DR_WAV_H
#define MTR_WAV_DR_WAV_H

#define DR_WAV_NO_STDIO
#define DR_WAV_IMPLEMENTATION
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeclaration-after-statement"
#pragma GCC diagnostic ignored "-Wcast-qual"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#include "dr_wav.h"
#pragma GCC diagnostic pop

#include "marathoner/plugin.h"
#ifdef MTR_MOD_STATIC
    #define fa faWav
#endif
#include "fa/Wav_dr_wav.h"

static bool  mtrWavInited = false;
MTR_Stdio    MTR_WavStdio;
MTR_StdioExt MTR_WavStdioExt;
mtrPcm_t     mtrWavTempPcm;

#endif
